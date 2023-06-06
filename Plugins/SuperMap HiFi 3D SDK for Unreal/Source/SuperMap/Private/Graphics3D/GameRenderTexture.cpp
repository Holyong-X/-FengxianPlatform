#include "Graphics3D/GameRenderTexture.h"
#include "Graphics3D/GameRenderTextureManager.h"
#include "Graphics3D/GameCamera.h"
#include "Graphics3D/GameComponent.h"
#include "Component/SuperMap_CaptureSceneActor.h"
#include "Render/TextureRenderer.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Graphics3D/GameConvertor.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameMaterialManager.h"
#include "Component/SuperMap_MeshSceneProxy.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Render;
namespace SuperMapSDK
{
	GameRenderTexture::GameRenderTexture(Gamelong nTextureName, FString strSceneName, SceneManagerType sceneManagerType, int32 nWidth, int32 nHeight, int32 nFormat)
	{
		m_pRenderTarget      = nullptr;
		m_pFlattenRenderTarget = nullptr;
		m_pAlphaRenderTarget = nullptr;
		m_pSelectRenderTarget = nullptr;
		m_pGameCamera  = nullptr;
		m_nTextureName = nTextureName;
		m_strSceneName = strSceneName;
		m_eSceneManagerType = sceneManagerType;
		m_nWidth  = nWidth;
		m_nHeight = nHeight;

		m_pRenderTarget = NewObject<UTextureRenderTarget2D>();
		// TODO 没考虑外面传进来的PixelFormat
#if PLATFORM_LINUX
		m_pRenderTarget->RenderTargetFormat = RTF_RGBA16f;
#else
		m_pRenderTarget->RenderTargetFormat = RTF_RGBA32f;
#endif
		m_nPixelFormat = GameConvertor::ToPixelFormat(nFormat);

		if (m_nPixelFormat == IPF_RGBA)
		{
			m_pRenderTarget->RenderTargetFormat = RTF_RGBA8;
		}

		if (sceneManagerType == REAL_TIME_ELEVATION_S3M)
		{
			m_pRenderTarget->Filter = TF_Nearest;
		}
		else
		{
			m_pRenderTarget->Filter = TF_Bilinear;
		}

		m_pRenderTarget->ClearColor = FLinearColor::Black;
		m_pRenderTarget->InitAutoFormat(nWidth, nHeight);
		m_pRenderTarget->AddToRoot();
		m_nHandle = nTextureName;
	}

	GameRenderTexture::~GameRenderTexture()
	{
		if (m_pAlphaRenderTarget != nullptr)
		{
			m_pAlphaRenderTarget->RemoveFromRoot();
			m_pAlphaRenderTarget = nullptr;
		}

		if (m_pSelectRenderTarget != nullptr)
		{
			m_pSelectRenderTarget->RemoveFromRoot();
			m_pSelectRenderTarget = nullptr;
		}
		
		if (m_pFlattenRenderTarget != nullptr)
		{
			m_pFlattenRenderTarget->RemoveFromRoot();
			m_pFlattenRenderTarget = nullptr;
		}

		if (m_pRenderTarget != nullptr)
		{
			m_pRenderTarget->RemoveFromRoot();
			m_pRenderTarget = nullptr;
		}

		if (m_pGameCamera != nullptr)
		{
			GameCameraManager::GetSingleton()->Remove(m_pGameCamera->GetHandle());
		}
		m_pGameCamera = nullptr;

		m_mapGameComponent.Empty();
	}

	void GameRenderTexture::CreateRenderTarget(UTextureRenderTarget2D* &pRenderTarget)
	{
		pRenderTarget = NewObject<UTextureRenderTarget2D>();
#if PLATFORM_LINUX
		pRenderTarget->RenderTargetFormat = RTF_RGBA16f;
#else
		pRenderTarget->RenderTargetFormat = RTF_RGBA32f;
#endif
		if (m_nPixelFormat == IPF_RGBA)
		{
			pRenderTarget->RenderTargetFormat = RTF_RGBA8;
		}

		if (m_eSceneManagerType == REAL_TIME_ELEVATION_S3M)
		{
			pRenderTarget->Filter = TF_Nearest;
		}
		else
		{
			pRenderTarget->Filter = TF_Bilinear;
		}

		pRenderTarget->ClearColor = FLinearColor::Black;
		pRenderTarget->InitAutoFormat(m_nWidth, m_nHeight);
		pRenderTarget->AddToRoot();
	}

	SceneManagerType GameRenderTexture::GetSceneManagerType()
	{
		return m_eSceneManagerType;
	}

	void GameRenderTexture::AddGameComponent(GameComponent* pGameComponent)
	{
		m_mapGameComponent.Add(pGameComponent->GetNodeName(), pGameComponent);
	}

	void GameRenderTexture::RemoveGameComponent(GameComponent* pGameComponent)
	{
		m_mapGameComponent.Remove(pGameComponent->GetNodeName());
	}

	void* GameRenderTexture::GetFrameBuffer(int32 nXOffset, int32 nYOffset, int32 nWidth, int32 nHeight, int32& nBufferSize)
	{
		if (m_pRenderTarget == nullptr)
		{
			return nullptr;
		}

		// 获取buffer
		FTextureRenderTargetResource* pRTResource = m_pRenderTarget->GameThread_GetRenderTargetResource();

		if (m_nPixelFormat == IPF_RGBA)
		{
			FReadSurfaceDataFlags rsdf(RCM_MinMax);
			rsdf.SetLinearToGamma(false);

			TArray<FColor> arrColorRGBABuffer;
			arrColorRGBABuffer.AddUninitialized(nWidth * nHeight);

			FIntRect rect(nXOffset, nYOffset, nXOffset + nWidth, nYOffset + nHeight);
			pRTResource->ReadPixels(arrColorRGBABuffer, rsdf, rect);

			Gameint nSize = arrColorRGBABuffer.Num();
			Gameuint8* pBuffer = new Gameuint8[nSize * 4];
			for (Gameint nBuffer = 0; nBuffer < arrColorRGBABuffer.Num(); nBuffer++)
			{
				FColor& color = arrColorRGBABuffer[nBuffer];

				pBuffer[nBuffer * 4 + 0] = color.B;
				pBuffer[nBuffer * 4 + 1] = color.G;
				pBuffer[nBuffer * 4 + 2] = color.R;
				pBuffer[nBuffer * 4 + 3] = 255 - color.A;
			}

			if (m_pAlphaRenderTarget != nullptr)
			{
				FTextureRenderTargetResource* pAlphaRTResource = m_pAlphaRenderTarget->GameThread_GetRenderTargetResource();

				TArray<FColor> arrAlphaBuffer;
				arrAlphaBuffer.AddUninitialized(nWidth * nHeight);

				pAlphaRTResource->ReadPixels(arrAlphaBuffer, rsdf, rect);
			
				for (Gameint nBuffer = 0; nBuffer < arrAlphaBuffer.Num(); nBuffer++)
				{
					FColor& color = arrAlphaBuffer[nBuffer];
					pBuffer[nBuffer * 4 + 3] = color.R;
				}
			}

			if (m_pSelectRenderTarget != nullptr)
			{
				FTextureRenderTargetResource* pSelectRTResource = m_pSelectRenderTarget->GameThread_GetRenderTargetResource();

				TArray<FColor> arrSelectBuffer;
				arrSelectBuffer.AddUninitialized(nWidth * nHeight);

				pSelectRTResource->ReadPixels(arrSelectBuffer, rsdf, rect);

				for (Gameint nBuffer = 0; nBuffer < arrSelectBuffer.Num(); nBuffer++)
				{
					FColor& color = arrSelectBuffer[nBuffer];
					pBuffer[nBuffer * 4 + 3] = color.R;
				}
			}

			nBufferSize = nSize * 4;

			return (void*)pBuffer;
		}

		FReadSurfaceDataFlags rsdf(RCM_MinMax, CubeFace_MAX);
		rsdf.SetLinearToGamma(false);

#if PLATFORM_LINUX
		TArray<FFloat16Color> arrDepthBuffer;
		arrDepthBuffer.AddUninitialized(m_pRenderTarget->GetSurfaceWidth()* m_pRenderTarget->GetSurfaceHeight());
		pRTResource->ReadFloat16Pixels(arrDepthBuffer);

		int32 nSize = nWidth * nHeight;
		float* pBuffer = new float[nSize];
		int nBuffer = 0;
		for (int iHeight = nYOffset; iHeight < nYOffset + nHeight; iHeight++)
		{
			for (int iWidth = nXOffset; iWidth < nXOffset + nWidth; iWidth++)
			{
				FFloat16Color& color = arrDepthBuffer[iHeight*m_pRenderTarget->GetSurfaceWidth()+iWidth];

				float fDepth = color.R + color.G / 255.0f + color.B / 65025.0f + color.A / 16581375.0f;
				if (FMath::Abs(fDepth) < 10e-6)
				{
					fDepth = 9999;
				}
				else
				{
					fDepth = 2 * fDepth - 1;
				}
				pBuffer[nBuffer] = fDepth;
				nBuffer++;
			}
		}
#else
		TArray<FLinearColor> arrDepthBuffer;
		arrDepthBuffer.AddUninitialized(nWidth * nHeight);

		FIntRect rect(nXOffset, nYOffset, nXOffset + nWidth, nYOffset + nHeight);
		pRTResource->ReadLinearColorPixels(arrDepthBuffer, rsdf, rect);

		int32 nSize = arrDepthBuffer.Num();
		float* pBuffer = new float[nSize];
		for (int32 nBuffer = 0; nBuffer < arrDepthBuffer.Num(); nBuffer++)
		{
			FLinearColor& color = arrDepthBuffer[nBuffer];

			float fDepth = color.R + color.G / 255.0f + color.B / 65025.0f + color.A / 16581375.0f;
			if (FMath::Abs(fDepth) < 10e-6)
			{
				fDepth = 9999;
			}
			else
			{
				fDepth = 2 * fDepth - 1;
			}
			pBuffer[nBuffer] = fDepth;
		}
#endif
		nBufferSize = nSize * sizeof(float);

		return (void*)pBuffer;
	}

	void GameRenderTexture::RenderObjectWithSpatialQuery()
	{
		ASuperMap_CaptureSceneActor* pCaptureSceneActor = m_pGameCamera->GetCaptureSceneActor();

		if (m_strSceneName.Find(TEXT("_SpatialQuery")) != -1)
		{
			// 空间查询的绘制对象,只绘制当前场景下的对象
			TArray<UPrimitiveComponent*> arrComponents;
			TMap<Gamelong, GameComponent*>::TRangedForIterator itor = m_mapGameComponent.begin();
			while (itor != m_mapGameComponent.end())
			{
				GameComponent* pGameComponent = itor->Value;
				TArray<GameMaterial*>& arrMaterials = pGameComponent->GetAllGameMaterial();
				Gamebool bReverseCulling = true;
				if (arrMaterials.Num() > 0)
				{
					GameMaterial* pGameMaterial = arrMaterials[0];
					bReverseCulling = pGameMaterial->GetCullingMode() == CULL_ANTICLOCKWISE ? true : false;
				}
				pGameComponent->GetSceneNode()->SetReverseCulling(bReverseCulling);
				arrComponents.Add(pGameComponent->GetSceneNode()->GetMeshComponent());

				++itor;
			}

			pCaptureSceneActor->SetShowOnlyComponentList(arrComponents);
		}
	}

	void GameRenderTexture::UpdateScene()
	{
		if (m_eSceneManagerType == REAL_TIME_ELEVATION_S3M)
		{
			RealtimeRasterFlattenRegion();

			RealtimeRasterExcavationRegion();
		}
		else if (m_eSceneManagerType == REAL_TIME_RASTER)
		{
			RealtimeRaster();
		}
		else if (m_eSceneManagerType == DRAW3D)
		{
			if (m_pGameCamera == nullptr)
			{
				return;
			}

			ASuperMap_CaptureSceneActor* pCaptureSceneActor = m_pGameCamera->GetCaptureSceneActor();

			RenderObjectWithSpatialQuery();

			TArray<AActor*> & m_arrHidderActors =GameObjectManager::GetSingleton()->GetSceneHiddenActors();
			Gameint nCount = m_arrHidderActors.Num();
			if (nCount > 0)
			{
				pCaptureSceneActor->SetHidderActors(m_arrHidderActors);
			}

			if (m_nPixelFormat == IPF_RGBA)
			{
				pCaptureSceneActor->SetCaptureSource(SCS_BaseColor);
			}
			else
			{
				pCaptureSceneActor->SetCaptureSource(SCS_DeviceDepth);
			}
			pCaptureSceneActor->SetRenderTarget(m_pRenderTarget);
			pCaptureSceneActor->CaptureScene();
		}
		else if (m_eSceneManagerType == DRAW_SPATIALQUERY)
		{
			// 两张纹理
			m_pGameCamera->UpdateShowObject(m_eSceneManagerType, true, false);
			ASuperMap_CaptureSceneActor* pCaptureSceneActor = m_pGameCamera->GetCaptureSceneActor();
			pCaptureSceneActor->SetCaptureSource(SCS_SceneColorHDR);
			pCaptureSceneActor->SetRenderTarget(m_pRenderTarget);
			pCaptureSceneActor->CaptureScene();

			if (m_pAlphaRenderTarget == nullptr)
			{
				CreateRenderTarget(m_pAlphaRenderTarget);
			}

			m_pGameCamera->UpdateShowObject(m_eSceneManagerType, true, true);
			pCaptureSceneActor->SetRenderTarget(m_pAlphaRenderTarget);
			pCaptureSceneActor->CaptureScene();

			m_pGameCamera->UpdateShowObject(m_eSceneManagerType, false, false);
		}
		else if (m_eSceneManagerType == DRAW_SELECTION)
		{
			if (m_pGameCamera == nullptr)
			{
				return;
			}
			SetShaderParameterForSelection(true, false);
			ASuperMap_CaptureSceneActor* pCaptureSceneActor = m_pGameCamera->GetCaptureSceneActor();
			pCaptureSceneActor->SetCaptureSource(SCS_SceneColorHDR);
			pCaptureSceneActor->SetRenderTarget(m_pRenderTarget);
			pCaptureSceneActor->CaptureScene();
			if (m_pSelectRenderTarget == nullptr)
			{
				CreateRenderTarget(m_pSelectRenderTarget);
			}
			SetShaderParameterForSelection(true, true);
			pCaptureSceneActor->SetRenderTarget(m_pSelectRenderTarget);
			pCaptureSceneActor->CaptureScene();
			SetShaderParameterForSelection(false, false);
		}
	}

	void GameRenderTexture::SetShaderParameterForSelection(Gamebool bRenderToSelectionTexture, Gamebool bRenderAlpha)
	{
		Gamefloat fRenderMode = bRenderToSelectionTexture ? 1.0f : 0.0f;
		Gamefloat fSelectLevel = bRenderAlpha ? 1.0f : 0.0f;

		ENQUEUE_RENDER_COMMAND(FSetUseMaterial)
			([bRenderToSelectionTexture](FRHICommandListImmediate& RHICmdList) {
			FSuperMapMeshSceneProxy::SetSceneUseMaterialFlag_RenderThread((bRenderToSelectionTexture ? UseMaterialFlag::UMF_SELECTION : UseMaterialFlag::UMF_NORMAL));
		});
		FName strName = TEXT("SelectLevel");
		GameMaterialManager::GetSingleton()->SetMatFloatShareParam(strName, fSelectLevel);
	}

	FString GameRenderTexture::GetSceneName()
	{
		return m_strSceneName;
	}

	void GameRenderTexture::RealtimeRasterFlattenRegion()
	{
		// 获取骨架包
		TArray<FTextureVertex> Vertexs;
		TArray<uint32> Indices;

		uint32 nOffset = 0;

		for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapGameComponent.CreateConstIterator(); It; ++It)
		{
			GameComponent* pGameComponent = It->Value;
			USuperMap_MeshComponentInterface* pMeshComponentInterface = pGameComponent->GetSceneNode();
			if (pMeshComponentInterface == nullptr)
			{
				continue;
			}
			
			CustomRealRasterMesh* pCustomRealRasterMesh = pMeshComponentInterface->GetRealRasterMesh();
			if (pCustomRealRasterMesh == nullptr)
			{
				continue;
			}

			FSMMesh& mesh = pCustomRealRasterMesh->GetMesh();

			int32 nPosCount = mesh.m_pDataVertex->m_nPosCount;
			int32 nPosDim = mesh.m_pDataVertex->m_nPosDim;

			int32 nTexDim = mesh.m_pDataVertex->m_nTexCoordDim;

			for (int32 i = 0; i < nPosCount; i++)
			{
				GameVector4 vPosition;
				vPosition.X = mesh.m_pDataVertex->m_Pos[i * nPosDim + 1];
				vPosition.Y = mesh.m_pDataVertex->m_Pos[i * nPosDim + 0];
				vPosition.Z = 0.0;
				vPosition.W = 1.0;

				GameVector2 vUV;
				vUV.X = mesh.m_pDataVertex->m_Pos[i * nPosDim + 2] * M_TO_CM;
				vUV.Y = 0.0;

				FTextureVertex texVertex;
				texVertex.Position = vPosition;
				texVertex.UV = vUV;

				Vertexs.Add(texVertex);
			}

			int32 nIndexCount = mesh.m_arrDataIndex[0]->m_nIndexCount;
			for (int32 i = 0; i < nIndexCount; i++)
			{
				uint32 nIndex = 0;
				if (mesh.m_arrDataIndex[0]->m_Index != nullptr)
				{
					nIndex = mesh.m_arrDataIndex[0]->m_Index[i] + nOffset;
				}
				else if (mesh.m_arrDataIndex[0]->m_shortIndex != nullptr)
				{
					nIndex = mesh.m_arrDataIndex[0]->m_shortIndex[i] + nOffset;
				}

				Indices.Add(nIndex);
			}

			nOffset += Vertexs.Num();
		}

		if (Vertexs.Num() > 0 && Indices.Num() > 0)
		{
			if (m_pFlattenRenderTarget == nullptr)
			{
				CreateRenderTarget(m_pFlattenRenderTarget);
			}
			m_pFlattenRenderTarget->UpdateResourceImmediate(true);
			TextureRenderer::DrawRegionByGlobalShader(Vertexs, Indices, m_pFlattenRenderTarget);
		}
	}

	void GameRenderTexture::RealtimeRasterExcavationRegion()
	{
		//栅格化矢量
		Gamedouble dWidth, dHeight;
		m_pGameCamera->GetOrthoWindow(dWidth, dHeight);

		Gamedouble dx, dy, dz;
		m_pGameCamera->GetUGCPosition(dx, dy, dz);

		Vector4d transform(dx, dy, dWidth, dHeight);

		if (m_pRenderTarget != nullptr)
		{
			m_pRenderTarget->ClearColor = FLinearColor(1, 1, 1, 1);
			m_pRenderTarget->UpdateResourceImmediate();
		}
		GameRenderTextureManager::GetSingleton()->RealtimeRasterExcavationRegion(m_pRenderTarget, transform);
	}

	void GameRenderTexture::RealtimeRaster()
	{
		//影像栅格化
		TArray<CustomRealRasterMesh*> arrImageRasterMesh;
		TArray<FVector4> arrImageTransforms;
		TArray<Gamelong> arrImageTextureNames;

		for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapGameComponent.CreateConstIterator(); It; ++It)
		{
			GameComponent* pGameComponent = It->Value;
			USuperMap_MeshComponentInterface* pMeshComponentInterface = pGameComponent->GetSceneNode();
			if (pMeshComponentInterface == nullptr)
			{
				continue;
			}

			CustomRealRasterMesh* pCustomRealRasterMesh = pMeshComponentInterface->GetRealRasterMesh();
			if (pCustomRealRasterMesh == nullptr)
			{
				continue;
			}

			if (pGameComponent->GetAllGameMaterial().Num() == 0)
			{
				continue;
			}

			FString strShaderName = UTF8_TO_TCHAR(pGameComponent->GetAllGameMaterial()[0]->GetMaterialParam()->m_strShaderName);

			if (strShaderName.Compare("Custom/TextureTransparen") == 0)
			{//影像
				Gamedouble* texTransform = pGameComponent->GetAllGameMaterial()[0]->GetMaterialParam()->m_pTexTransforms[0];

				FVector4 transform;
				//缩放
				transform.X = texTransform[0];
				transform.Y = texTransform[5];
				//平移
				transform.Z = texTransform[12];
				transform.W = texTransform[13];

				Gamelong textureName = pGameComponent->GetAllGameMaterial()[0]->GetMaterialParam()->m_pTextureNames[0];

				arrImageRasterMesh.Add(pCustomRealRasterMesh);

				arrImageTransforms.Add(transform);
				arrImageTextureNames.Add(textureName);
			}
		}

		if (arrImageRasterMesh.Num() > 0)
		{
			RealtimeRasterImage(arrImageRasterMesh, arrImageTransforms, arrImageTextureNames);
		}




		//栅格化矢量
		Gamedouble dWidth, dHeight;
		m_pGameCamera->GetOrthoWindow(dWidth, dHeight);

		Gamedouble dx, dy, dz;
		m_pGameCamera->GetUGCPosition(dx, dy, dz);

		FVector4 transform(dx, dy, dWidth, dHeight);

		GameRenderTextureManager::GetSingleton()->RealtimeRasterVector(m_pRenderTarget, transform);

	}

	void GameRenderTexture::RealtimeRasterImage(TArray<CustomRealRasterMesh*> arrRasterMesh, TArray<FVector4> transforms, TArray<Gamelong> textureNames)
	{
		// 获取骨架包
		TArray<TArray<FTextureVertex> > Vertexs;
		TArray<TArray<uint32> > Indices;



		TArray<FVector4> colors;

		TMap<int32, uint32> order;

		float fR, fG, fB, fA;


		for(int32 n = 0; n<arrRasterMesh.Num(); n++)
		{
			FSMMesh& mesh = arrRasterMesh[n]->GetMesh();

			int32 nPosCount = mesh.m_pDataVertex->m_nPosCount;


			int32 nPosDim = mesh.m_pDataVertex->m_nPosDim;

			int32 nTexDim = mesh.m_pDataVertex->m_nTexCoordDim;

			TArray<FTextureVertex> Vertex;
			for (int32 i = 0; i < nPosCount; i++)
			{
				GameVector4 vPosition;
				vPosition.X = mesh.m_pDataVertex->m_Pos[i * nPosDim + 0];
				vPosition.Y = mesh.m_pDataVertex->m_Pos[i * nPosDim + 1];
				vPosition.Z = mesh.m_pDataVertex->m_Pos[i * nPosDim + 2];
				vPosition.W = 1.0;

				GameVector2 vUV;
				vUV.X = mesh.m_pDataVertex->m_TexCoord[i * nTexDim];
				vUV.Y = mesh.m_pDataVertex->m_TexCoord[i * nTexDim + 1];

				FTextureVertex texVertex;
				texVertex.Position = vPosition;
				texVertex.UV = vUV;

				Vertex.Add(texVertex);

				if (i == 0)
				{
					fR = 1.0;
					fG = 1.0;
					fB = 1.0;
					fA = 1.0;

					if (mesh.m_pDataVertex->m_PosColor)
					{
						SuperMapSDK::UnrealEngine::Core::_IDRGBA(mesh.m_pDataVertex->m_PosColor[i], fR, fG, fB, fA);
					}

					colors.Add(FVector4(fR, fG, fB, fA));

					order.Add(Vertexs.Num(),vPosition.Z);
				}
			}
			Vertexs.Add(Vertex);

			TArray<uint32> Indice;
			int32 nIndexCount = mesh.m_arrDataIndex[0]->m_nIndexCount;
			for (int32 i = 0; i < nIndexCount; i++)
			{
				uint32 nIndex = 0;
				if (mesh.m_arrDataIndex[0]->m_Index != nullptr)
				{
					nIndex = mesh.m_arrDataIndex[0]->m_Index[i];
				}
				else if (mesh.m_arrDataIndex[0]->m_shortIndex != nullptr)
				{
					nIndex = mesh.m_arrDataIndex[0]->m_shortIndex[i];
				}

				Indice.Add(nIndex);
			}
			Indices.Add(Indice);
		}


		order.ValueSort([](int32 A, int32 B)
		{
			return A < B; // sort keys in reverse
		});

		TArray<uint32> orders;
		for (TMap<int32, uint32>::TConstIterator ItOrder = order.CreateConstIterator(); ItOrder; ++ItOrder)
		{
			orders.Add(ItOrder->Key);
		}

		if (Vertexs.Num() > 0 && Indices.Num() > 0)
		{
			m_pRenderTarget->UpdateResourceImmediate(true);
			TextureRenderer::DrawRealtimeRaster(Vertexs, Indices, transforms, textureNames, colors, orders, m_pRenderTarget);
		}

	}

	Gamelong GameRenderTexture::GetHandle()
	{
		return m_nHandle;
	}

	void* GameRenderTexture::GetCameraHandle()
	{
		if (m_pGameCamera == nullptr) 
		{
			if (m_eSceneManagerType == SceneManagerType::DRAW3D ||
				m_eSceneManagerType == SceneManagerType::DRAW_SPATIALQUERY ||
				m_eSceneManagerType == SceneManagerType::DRAW_SELECTION)
			{
				m_pGameCamera = GameCameraManager::GetSingleton()->Create(true);
			}
			else
			{
				m_pGameCamera = GameCameraManager::GetSingleton()->Create(false);
			}	
		}
		return (void*)m_pGameCamera;
	}

	UTextureRenderTarget2D* GameRenderTexture::GetRenderTarget()
	{
		return m_pRenderTarget;
	}

	UTextureRenderTarget2D* GameRenderTexture::GetFlattenRenderTarget()
	{
		return m_pFlattenRenderTarget;
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif