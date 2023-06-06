#include "Graphics3D/GameRenderTextureManager.h"
#include "Graphics3D/GameEnum.h"
#include "Graphics3D/GameComponent.h"
#include "Graphics3D/GameRenderTexture.h"
#include "Algorithm3D/MathEngine.h"
#include "Base3D/StatsGroupDefine.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Render/TextureRenderer.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Render;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
namespace SuperMapSDK
{
	void* CreateRenderTexture(int32 mode, Gamelong nTextureName, char* strSceneName, int32 nWidth, int32 nHeight, int32 nFormat)
	{
		STATS_SM_CREATERENDERTEXTURE

		SceneManagerType eSceneManagerType = SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::ConvertToSceneManagerType(mode);
		// TODO: 底层创建的没用到的实时栅格化纹理不创建，以免浪费资源。如果支持新的实时栅格化类型场景需要放开
		if (eSceneManagerType == REAL_TIME_ELEVATION 
			|| eSceneManagerType == REAL_TIME_ELEVATION_NORMAL 
			|| eSceneManagerType == REAL_TIME_ELEVATION_RULER
			|| eSceneManagerType == REAL_TIME_RASTER_OCEAN)
		{
			return nullptr;
		}
		
		FName strSceneNodeName(strSceneName);
		void* pRenderTextureHandle = GameRenderTextureManager::GetSingleton()->Create(nTextureName, strSceneNodeName.ToString(), eSceneManagerType, nWidth, nHeight, nFormat);
		return pRenderTextureHandle;
	}

	void DestroyRenderTexture(void* pRenderTextureHandle)
	{
		STATS_SM_DESTROYRENDERTEXTURE

		GameRenderTextureManager::GetSingleton()->Remove(pRenderTextureHandle);
	}

	void DeleteFrameBuffer(void* pBuffer)
	{
		STATS_SM_DETELEFRAMEBUFFER

		if (pBuffer != nullptr)
		{
			delete (char*)pBuffer;
		}
	}

	void* GetFrameBuffer(void* pRenderTextureHandle, int32 nXOffset, int32 nYOffset, int32 nWidth, int32 nHeight, int32& nBufferSize)
	{
		STATS_SM_GETFRAMEBUFFER

		GameRenderTexture* pGameRenderTexture = (GameRenderTexture*)pRenderTextureHandle;
		if (pGameRenderTexture == nullptr)
		{
			return nullptr;
		}
		return pGameRenderTexture->GetFrameBuffer(nXOffset, nYOffset, nWidth, nHeight, nBufferSize);
	}

	void UpdateScene(void* pRenderTextureHandle)
	{
		STATS_SM_UPDATESCENE

		GameRenderTexture* pGameRenderTexture = (GameRenderTexture*)pRenderTextureHandle;
		if (pGameRenderTexture == nullptr)
		{
			return;
		}
		pGameRenderTexture->UpdateScene();
	}

	void* GetCamera(void* pRenderTextureHandle)
	{
		STATS_SM_GETCAMERA

		GameRenderTexture* pGameRenderTexture = (GameRenderTexture*)pRenderTextureHandle;
		if (pGameRenderTexture == nullptr)
		{
			return nullptr;
		}
		return pGameRenderTexture->GetCameraHandle();
	}

	void SetRenderDepth(void* pRenderTextureHandle, Gamebool bEnable)
	{
		STATS_SM_SETRENDERDEPTH
		// TO DO
	}

	void ClearFramebuffer(void* pRenderTextureHandle, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA)
	{
		STATS_SM_CLEARFRAMEBUFFER
		//TO DO
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	GameRenderTextureManager* GameRenderTextureManager::m_pGameTextureManager = nullptr;
	GameRenderTextureManager::GameRenderTextureManager()
	{

	}

	GameRenderTextureManager::~GameRenderTextureManager()
	{
		Clear();
	}

	void GameRenderTextureManager::Clear()
	{
		for (TMap<Gamelong, GameRenderTexture*>::TConstIterator It = m_mapTextures.CreateConstIterator(); It; ++It)
		{
			delete It->Value;
		}

		m_mapTextures.Empty();
	}

	void GameRenderTextureManager::DestorySingleton()
	{
		if (m_pGameTextureManager != nullptr)
		{
			delete[] m_pGameTextureManager;
			m_pGameTextureManager = nullptr;
		}
	}

	GameRenderTextureManager* GameRenderTextureManager::GetSingleton()
	{
		if (m_pGameTextureManager == nullptr)
		{
			m_pGameTextureManager = new GameRenderTextureManager();
		}

		return m_pGameTextureManager;
	}

	void GameRenderTextureManager::AddGameComponent(GameComponent* pGameComponent)
	{
		FString strSceneName1 = pGameComponent->GetSceneName();
		for (TMap<Gamelong, GameRenderTexture*>::TConstIterator It = m_mapTextures.CreateConstIterator(); It; ++It)
		{
			GameRenderTexture* pGameRenderTexture = It->Value;
			FString strSceneName2 = pGameRenderTexture->GetSceneName();
			if (pGameComponent->GetSceneManagerType() == pGameRenderTexture->GetSceneManagerType() ||
				strSceneName1.Compare(strSceneName2) == 0)
			{
				pGameRenderTexture->AddGameComponent(pGameComponent);
			}
		}

		m_mapGameComponent.Add(pGameComponent->GetNodeName(), pGameComponent);
	}

	void GameRenderTextureManager::RemoveGameComponent(GameComponent* pGameComponent)
	{
		FString strSceneName1 = pGameComponent->GetSceneName();
		for (TMap<Gamelong, GameRenderTexture*>::TConstIterator It = m_mapTextures.CreateConstIterator(); It; ++It)
		{
			GameRenderTexture* pGameRenderTexture = It->Value;
			FString strSceneName2 = pGameRenderTexture->GetSceneName();
			if (pGameComponent->GetSceneManagerType() == pGameRenderTexture->GetSceneManagerType() ||
				strSceneName1.Compare(strSceneName2) == 0)
			{
				pGameRenderTexture->RemoveGameComponent(pGameComponent);
			}
		}

		m_mapGameComponent.Remove(pGameComponent->GetNodeName());
	}

	void* GameRenderTextureManager::Create(Gamelong nTextureName, FString strSceneName, SceneManagerType sceneManagerType, int32 nWidth, int32 nHeight, int32 nFormat)
	{
		GameRenderTexture* pGameRenderTexture = new GameRenderTexture(nTextureName, strSceneName, sceneManagerType, nWidth, nHeight, nFormat);
		Gamelong nRenderTextureHandle = pGameRenderTexture->GetHandle();
		m_mapTextures.Add(nRenderTextureHandle, pGameRenderTexture);
		return (void*)pGameRenderTexture;
	}

	void GameRenderTextureManager::Remove(void* pRenderTextureHandle)
	{
		GameRenderTexture* pGameRenderTexture = (GameRenderTexture*)pRenderTextureHandle;
		if (pGameRenderTexture == nullptr)
		{
			return;
		}
		Gamelong nRenderTextureHandle = pGameRenderTexture->GetHandle();
		delete pGameRenderTexture;
		pGameRenderTexture = nullptr;
		m_mapTextures.Remove(nRenderTextureHandle);
	}

	GameRenderTexture* GameRenderTextureManager::Get(Gamelong nRenderTextureHandle)
	{
		Gamebool bHas = m_mapTextures.Contains(nRenderTextureHandle);
		if (bHas)
		{
			return m_mapTextures[nRenderTextureHandle];
		}
		return nullptr;
	}


	void GameRenderTextureManager::RealtimeRasterVector(UTextureRenderTarget2D* pRenderTarget, FVector4 transform, Gamebool bSecondColor)
	{
		TArray<CustomRealRasterMesh*> meshes;
		TArray<CustomRealRasterMesh*> overlayMeshs;
		TArray<Gamelong> overlayImage;
		TArray<FVector4> overlayTransform;
		TArray<Matrix4d> objectTransform;
		for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapGameComponent.CreateConstIterator(); It; ++It)
		{
			GameComponent* pGameComponent = It->Value;
			USuperMap_MeshComponentInterface* pMeshComponentInterface = pGameComponent->GetSceneNode();
			if (pMeshComponentInterface == nullptr || !pMeshComponentInterface->GetInternalVisibility())
			{
				continue;
			}

			CustomRealRasterMesh* pCustomRealRasterMesh = pMeshComponentInterface->GetRealRasterMesh();
			if (pCustomRealRasterMesh == nullptr || !pCustomRealRasterMesh->GetLayerVisibility())
			{
				continue;
			}

			if (pGameComponent->GetAllGameMaterial().Num() == 0)
			{
				continue;
			}

			FString strShaderName = UTF8_TO_TCHAR(pGameComponent->GetAllGameMaterial()[0]->GetMaterialParam()->m_strShaderName);
			
			
			if (strShaderName.Compare("Custom/ModelCache") == 0 || strShaderName.Compare("Custom/Model") == 0)
			{
				Matrix4d objectMatrix = pGameComponent->GetObjectUGCMatrix();
				meshes.Add(pCustomRealRasterMesh);
				objectTransform.Add(objectMatrix);
			}
			else if (strShaderName.Compare("Custom/OverlayImage") == 0)
			{
				overlayMeshs.Add(pCustomRealRasterMesh);

				Gamelong textureName = pGameComponent->GetAllGameMaterial()[0]->GetMaterialParam()->m_pTextureNames[0];
				overlayImage.Add(textureName);

				Matrix4d mat = pGameComponent->GetObjectUGCMatrix();
				FVector vTrans= mat.GetTrans().ToFVector();
				FVector4 vTranslation = FVector4(vTrans.X, vTrans.Y, vTrans.Z, 1.0);

				overlayTransform.Add(vTranslation);
			}
		}

		if (meshes.Num() > 0)
		{
			TextureRenderer::DrawRealtimeRasterVector(meshes, transform, objectTransform, pRenderTarget, bSecondColor);
		}

		if (overlayMeshs.Num() > 0)
		{
			TextureRenderer::DrawRealtimeRasterVectorWithTexture(overlayMeshs, transform, overlayTransform, TArray<Matrix4d>(), overlayImage, pRenderTarget);
		}
	}

	void GameRenderTextureManager::RealtimeRasterExcavationRegion(UTextureRenderTarget2D* pRenderTarget, Vector4d transform)
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
			if (pCustomRealRasterMesh == nullptr || !pCustomRealRasterMesh->GetLayerVisibility())
			{
				continue;
			}

			if (pGameComponent->GetAllGameMaterial().Num() == 0)
			{
				continue;
			}

			FString strShaderName = UTF8_TO_TCHAR(pGameComponent->GetAllGameMaterial()[0]->GetMaterialParam()->m_strShaderName);

			if (strShaderName.Compare("Custom/RasterRegion") == 0)
			{
				Matrix4d mat = pGameComponent->GetObjectUGCMatrix();
				Vector3d vTrans = mat.GetTrans();
				Vector3d vScale = mat.GetScale();

				FSMMesh& mesh = pCustomRealRasterMesh->GetMesh();

				int32 nPosCount = mesh.m_pDataVertex->m_nPosCount;
				int32 nPosDim = mesh.m_pDataVertex->m_nPosDim;

				int32 nTexDim = mesh.m_pDataVertex->m_nTexCoordDim;

				for (int32 i = 0; i < nPosCount; i++)
				{
					Gamedouble x = mesh.m_pDataVertex->m_Pos[i * nPosDim + 0] * vScale.X + vTrans.X; 
					Gamedouble y = mesh.m_pDataVertex->m_Pos[i * nPosDim + 1] * vScale.Y + vTrans.Y;

					GameVector4 vPosition;
					vPosition.X = (x - transform.X) / (transform.Z) + 0.5;
					vPosition.Y = (y - transform.Y) / (transform.W) + 0.5;
					vPosition.Z = 0.0;
					vPosition.W = 1.0;

					FTextureVertex texVertex;

					texVertex.Position = vPosition;

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
		}

		if (Vertexs.Num() > 0 && Indices.Num() > 0)
		{
			pRenderTarget->UpdateResourceImmediate(true);
			TextureRenderer::DrawRegionByGlobalShader(Vertexs, Indices, pRenderTarget);
		}

	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif