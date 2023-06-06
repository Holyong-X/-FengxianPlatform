#include "Graphics3D/GameMaterial.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Algorithm3D/MathEngine.h"
#include "Data/Matrix4d.h"
#include "Graphics3D/GameTextureManager.h"
#include "Graphics3D/GameRenderTextureManager.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameRenderTexture.h"
#include "Engine/Texture2D.h"
#include "Core/Scene.h"
#include "Core/ROCacheManager.h"
#include "SpatialAnalyst3D/ViewShed.h"
#include "SpatialAnalyst3D/ProjectionImage.h"
#include "SpatialAnalyst3D/ViewDome.h"
#include "SpatialAnalyst3D/MultiViewShed3D.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/SlopeSetting.h"
#include "Core/TerrainLayers.h"
#include "Core/Layer3Ds.h"
#include "Graphics3D/GameMaterialManager.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameLifetime.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;

namespace SuperMapSDK
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	FSuperMapMaterialInterfaceCollection::FSuperMapMaterialInterfaceCollection()
	{
	}

	FSuperMapMaterialInterfaceCollection::~FSuperMapMaterialInterfaceCollection()
	{
		m_mapMaterialByFlag.Empty();
		//m_mapMaterialByViewIndex.Empty();
	}

	void FSuperMapMaterialInterfaceCollection::SetMaterialByUseFlag(UseMaterialFlag useFlag, UMaterialInterface* pMaterialInterface)
	{
		if (pMaterialInterface == nullptr)
		{
			return;
		}
		m_mapMaterialByFlag.Add(useFlag, pMaterialInterface);
	}

	UMaterialInterface* FSuperMapMaterialInterfaceCollection::GetMaterialByUseFlag(UseMaterialFlag useFlag) const
	{
		Gamebool bHas = m_mapMaterialByFlag.Contains(useFlag);
		if (bHas)
		{
			return m_mapMaterialByFlag[useFlag];
		}
		return nullptr;
	}

	void FSuperMapMaterialInterfaceCollection::SetMacros(GameMaterialParam* pMaterialParam)
	{
		if (pMaterialParam != nullptr)
		{
			for (Gameint i = 0; i < pMaterialParam->m_nMacroCount; i++)
			{
				FString strMacro = UTF8_TO_TCHAR(pMaterialParam->m_setMacro[i]);
				if (strMacro == TEXT("MultiTemporalWeight"))
				{
					m_matMacros.m_bMultiTemporalWeight = true;
				}
			}
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	GameMaterial::GameMaterial()
	{
		m_pMaterialParam = nullptr;
		m_pMID           = nullptr;
		m_pViewportMID   = nullptr;
		m_pMIC           = nullptr;
		m_pSelectionMaterial  = nullptr;
		m_pRectSelectMaterial = nullptr;
		m_enDataType          = DataType::ModelCache;
		m_bInitial            = false;
		m_eCullingMode        = CULL_NONE;
	}

	GameMaterial::GameMaterial(GameMaterialParam* pMaterialParam)
	{
		m_pMaterialParam = new GameMaterialParam;
		m_pMaterialParam->Copy(pMaterialParam);
		m_pMID = nullptr;
		m_pViewportMID = nullptr;
		m_pMIC = nullptr;
		m_pSelectionMaterial = nullptr;
		m_pRectSelectMaterial = nullptr;
		m_enDataType = DataType::ModelCache;
		m_bInitial = false;
	}

	GameMaterial::~GameMaterial()
	{
		if (m_pMaterialParam != nullptr)
		{
			delete m_pMaterialParam;
			m_pMaterialParam = nullptr;
		}

		if (m_pMID != nullptr)
		{
			m_pMID->RemoveFromRoot();
			GameLifetime::Destory(m_pMID);
		}

		if (m_pViewportMID != nullptr)
		{
			m_pViewportMID->RemoveFromRoot();
			GameLifetime::Destory(m_pViewportMID);
		}

		if (m_pMIC != nullptr)
		{
			m_pMIC->RemoveFromRoot();
			GameLifetime::Destory(m_pMIC);
		}

		if (m_pSelectionMaterial != nullptr)
		{
			m_pSelectionMaterial->RemoveFromRoot();
			GameLifetime::Destory(m_pSelectionMaterial);
		}

		if (m_pRectSelectMaterial != nullptr)
		{
			m_pRectSelectMaterial->RemoveFromRoot();
			GameLifetime::Destory(m_pRectSelectMaterial);
		}
	}

	void GameMaterial::CreateMID(bool bIsPBR, FString strShaderName)
	{
		FString strMaterialName = "";
		// 是否参与GPU的分析
		bool bGPUAnalyst = false;
		if (strShaderName.Compare("Custom/Model") == 0)
		{
			// 倾斜摄影
			strMaterialName = SM_OBLIQUEPHOTOGRAPHY_MAT;
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/Globe") == 0)
		{
			// 地形
			strMaterialName = SM_TERRAIN_MAT;
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/PointCloud") == 0)
		{
			// 点云
			strMaterialName = SM_POINTCLOUD_MAT;
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/ModelCache") == 0)
		{
			// 精模
			if (bIsPBR)
			{
				strMaterialName = SM_MODELPBR_MAT;
			}
			else
			{
				strMaterialName = SM_MODEL_MAT;
			}
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/ModelCacheTransparent") == 0)
		{
			// 透明精模
			if (bIsPBR)
			{
				strMaterialName = SM_MODELTRANSPARENTPBR_MAT;
			}
			else
			{
				strMaterialName = SM_MODELTRANSPARENT_MAT;
			}
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/NewModelCache") == 0)
		{
			// S3MBlock
			strMaterialName = SM_MODELBLOCK_MAT;
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/NewModelCacheTransparent") == 0)
		{
			// S3MBlock 透明
			strMaterialName = SM_MODELBLOCKTRANSPARENT_MAT;
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/Billboard") == 0)
		{
			// Billboard (KML专题图)
			strMaterialName = SM_BILLBOARD_MAT;
		}
		else if (strShaderName.Compare("Custom/ModelPro") == 0)
		{
			// 数据集图层
			if (bIsPBR)
			{
				strMaterialName = SM_MODELPROPBR_MAT;
			}
			else
			{
				strMaterialName = SM_MODELPRO_MAT;
			}
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/CommonNoTexture") == 0 ||
			strShaderName.Compare("Custom/TextureTransparen") == 0)
		{
			// 1. 不带纹理的几何体绘制，多用于跟踪图层对象的绘制
			// 2. 实时栅格矢量面的绘制
			strMaterialName = SM_GEORENDER_MAT;
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/CommonOneTexture") == 0)
		{
			// 1. 带纹理的几何体绘制，多用于跟踪图层对象的绘制
			// 2. 实时栅格影像
			strMaterialName = SM_GEO_TEX_RENDER_MAT;
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/ViewDome") == 0)
		{
			// 绘制开敞度对象
			strMaterialName = SM_VIEWDOMERENDER_MAT;
			bGPUAnalyst = true;
		}
		else if (strShaderName.Compare("Custom/ModelEdge") == 0)
		{
			// 模型边框线
			strMaterialName = SM_MODELEDGE_MAT;
		}
		else if (strShaderName.Compare("Custom/InstancePipe") == 0)
		{
			// 实例化管线
			strMaterialName = SM_INSTANCEPIPE_MAT;
		}
		else if (strShaderName.Compare("Custom/ModelInstance") == 0)
		{
			// 模型实例化
			strMaterialName = SM_MODELINSTANCE_MAT;
		}
		else if (strShaderName.Compare("Custom/CommonNoTextureNoDoubleSide") == 0)
		{
			// 1. 不带纹理的几何体单面绘制，多用于跟踪图层对象的绘制
			strMaterialName = SM_GEO_NODOUBLESIDE_RENDER_MAT;
		}
		else if (strShaderName.Compare("Custom/PolylineCache") == 0)
		{
			// 绘制宽线
			strMaterialName = SM_POLYLINE_MAT;
		}
		else if (strShaderName.Compare("Custom/ModifyRegion") == 0)
		{
			strMaterialName = SM_MODIFYREGION_MAT;
		}

		if (!strMaterialName.IsEmpty())
		{
			UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *strMaterialName);
			m_pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		}
		if (bGPUAnalyst)
		{
			UpdateAnalyst(m_pMID);
		}
	}
	void GameMaterial::UpdateMaterialParam()
	{
		m_enDataType = (DataType)m_pMaterialParam->m_nDataType;
		Gameint nTexCount = 0;
		Gameint nBatchIndex = 0;
		Gameint nRenderTexCount = 0;
		// 暂时先只支持4重纹理
		Gameuint nTextureCount = m_pMaterialParam->m_nTextureCount > 4 ? 4 : m_pMaterialParam->m_nTextureCount;
		for (Gameuint i = 0; i < nTextureCount; i++)
		{
			FString strMatName = "TexOne";
			if (i == 1)
			{
				strMatName = "TexTwo";
			}
			else if (i == 2)
			{
				strMatName = "TexThree";
			}
			else if (i == 3)
			{
				strMatName = "TexFour";
			}

			// 设置纹理矩阵
			MathEngine::SetShaderMatrixParamter(m_pMID, Matrix4d(m_pMaterialParam->m_pTexTransforms[i]), strMatName);

			FName strName = "TextureParam";
			if (i == 1)
			{
				strName = "TextureParam1";
			}
			else if (i == 2)
			{
				strName = "TextureParam2";
			}
			else if (i == 3)
			{
				strName = "TextureParam3";
			}

			// 设置纹理
			Gamelong nTextureHandle = m_pMaterialParam->m_pTextureNames[i];
			GameTexture* pGameTexture = GameTextureManager::GetSingleton()->GetTexture(nTextureHandle);
			if (pGameTexture != nullptr)
			{
				UTexture2D* pTexture2D = pGameTexture->GetTexture2D();

				if (m_pMaterialParam->m_pPBRParam != nullptr)
				{
					SetPBRTextureParam(m_pMaterialParam->m_pPBRParam, strName, nTexCount);
				}

				if (nBatchIndex == m_pMaterialParam->m_nBatchTextureIndex)
				{
					strName = "BatchTexture";

					pTexture2D->Filter = TF_Nearest;
					pTexture2D->SRGB = 0;
				}
				else
				{
					nTexCount++;
				}
				
				if(pGameTexture->GetInitialAndUpdateGPU())
				{
					m_pMID->SetTextureParameterValue(strName, pTexture2D);
				}
				else
				{
					AddMaterialTextureParam(strName, pGameTexture);
				}

				if (i == 0)
				{
					FLinearColor texonesize;
					texonesize.R = pGameTexture->GetWidth();
					texonesize.G = pGameTexture->GetHeight();
					
					m_pMID->SetVectorParameterValue(TEXT("TexOneSize"), texonesize);
				}

			}
			else
			{
				GameRenderTexture* pGameRenderTexture = GameRenderTextureManager::GetSingleton()->Get(nTextureHandle);

				if (pGameRenderTexture != nullptr)
				{
					UTexture* pTexture = (UTexture*)pGameRenderTexture->GetRenderTarget();

					//pTexture->Filter = TF_Bilinear;
					//pTexture->SRGB = 0;


					//pTexture->AddressX = TextureAddress::TA_Clamp;
					//pTexture->AddressY = TextureAddress::TA_Clamp;

					nTexCount++;
					nRenderTexCount++;
					
					m_pMID->SetTextureParameterValue(strName, pTexture);
				}
				else
				{
					m_pMID->SetTextureParameterValue(strName, nullptr);
				}

			}

			nBatchIndex++;
		}


		if (m_pMaterialParam->m_nBatchTextureIndex != -1)
		{
			m_pMID->SetScalarParameterValue(TEXT("nBatchTexture"), 1.0);
		}
		for (Gameint i = 0; i < m_pMaterialParam->m_nMacroCount; i++)
		{
			FString strMacro = UTF8_TO_TCHAR(m_pMaterialParam->m_setMacro[i]);
			if (strMacro == TEXT("TEXTURE_ATLAS"))
			{
				m_pMID->SetScalarParameterValue(TEXT("bTextureAtlas"), 1.0);
				break;
			}
		}

		m_pMID->SetScalarParameterValue(TEXT("TexCount"), nTexCount);

		m_pMID->SetScalarParameterValue(TEXT("RenderTexCount"), nRenderTexCount);

		// 设置PBR材质参数
		SetPBRMaterialParam(m_pMID);
		m_pMID->SetVectorParameterValue(FName("ID"), UnrealEngine::Core::ROCacheManager::m_vID);

		// 设置材质颜色
		m_pMID->SetVectorParameterValue(FName("MaterialColor"), FLinearColor(m_pMaterialParam->m_diffuse.x, m_pMaterialParam->m_diffuse.y, m_pMaterialParam->m_diffuse.z, m_pMaterialParam->m_diffuse.w));
		
		// 单面渲染类型
		m_eCullingMode = m_pMaterialParam->m_eCullingMode;
	}

	void GameMaterial::CreateSelectionMaterial(UMaterialInterface* pColorMaterial)
	{
		// 创建选择使用的材质
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_IDRENDER_MAT);
		m_pSelectionMaterial = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		m_pSelectionMaterial->CopyMaterialUniformParameters(pColorMaterial);
		m_pSelectionMaterial->AddToRoot();
	}

	void GameMaterial::CreateRectSelectMaterial(UMaterialInterface* pRectSelectMaterial)
	{
		// 创建选择使用的材质
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_SPATIALQUERY_MAT);
		m_pRectSelectMaterial = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		m_pRectSelectMaterial->AddToRoot();
	}

	void GameMaterial::InitMID()
	{
		FString strMaterialRealName = UTF8_TO_TCHAR(m_pMaterialParam->m_strMaterialName);

		UMaterialInterface* pMIC = NULL;
		if (strMaterialRealName.Find(TEXT("Material'/")) != INDEX_NONE ||
			strMaterialRealName.Find(TEXT("MaterialInstanceConstant'/")) != INDEX_NONE)
		{
			Gameint nIndex = 0;
			if (strMaterialRealName.FindLastChar(TCHAR('_'), nIndex))
			{
				Gameint nStrCount = strMaterialRealName.Len() - nIndex;
				strMaterialRealName.RemoveAt(nIndex, nStrCount);
			}

			if (strMaterialRealName.Len() < 200)
			{
				pMIC = LoadObject<UMaterialInterface>(nullptr, *strMaterialRealName);
			}
		}

		FString strShaderName = UTF8_TO_TCHAR(m_pMaterialParam->m_strShaderName);
		Gamebool bIsPBR = false;
		if (pMIC != nullptr)
		{
			m_pMID = UMaterialInstanceDynamic::Create(pMIC, nullptr);
			pMIC = nullptr;

			// 替换材质也参与GPU 分析
			UpdateAnalyst(m_pMID);
		}
		else
		{
			if (m_pMaterialParam->m_pPBRParam != nullptr)
			{
				bIsPBR = true;
			}
			CreateMID(bIsPBR, strShaderName);
		}
	}
	
	void GameMaterial::InitMaterial()
	{
		if (m_bInitial)
		{
			return;
		}
		m_bInitial = true;

		// 创建材质
		InitMID();

		if (m_pMID != nullptr)
		{
			m_pMID->AddToRoot();

			UpdateMaterialParam();

			FString strShaderName = UTF8_TO_TCHAR(m_pMaterialParam->m_strShaderName);
			if (IsNeedCreateSelectionMaterial(strShaderName))
			{
				CreateSelectionMaterial(m_pMID);
			}

			if (IsNeedCreateRectSelectMaterial(strShaderName))
			{
				CreateRectSelectMaterial(m_pMID);
			}
		}
	}

	CullingMode GameMaterial::GetCullingMode()
	{
		return m_eCullingMode;
	}

	UMaterialInstanceDynamic* GameMaterial::GetMID()
	{
		return m_pMID;
	}

	UMaterialInstanceDynamic* GameMaterial::GetViewportMID()
	{
		if (m_pViewportMID != nullptr)
		{
			m_pViewportMID->RemoveFromRoot();
			GameLifetime::Destory(m_pViewportMID);
			m_pViewportMID = nullptr;
		}

		if (!GameMaterialManager::GetSingleton()->GetIsCreateMaterialInViewport())
		{
			return  nullptr;
		}
		if (m_pMID == nullptr)
		{
			return nullptr;
		}
		m_pViewportMID = UMaterialInstanceDynamic::Create(m_pMID->Parent, nullptr);
		m_pViewportMID->CopyMaterialUniformParameters(m_pMID);
		UpdateViewportMID(m_pViewportMID);
		return m_pViewportMID;
	}

	void GameMaterial::SetMID(UMaterialInstanceDynamic* pMID)
	{
		if (m_pMID != nullptr)
		{
			m_pMID->RemoveFromRoot();
			GameLifetime::Destory(m_pMID);
			m_pMID = nullptr;
		}

		m_pMID = pMID;
	}

	void GameMaterial::UpdateViewportMID(UMaterialInstanceDynamic* pMID)
	{
		if (pMID == nullptr)
		{
			return;
		}
		SuperMapSDK::UnrealEngine::Core::Scene* pScene = (SuperMapSDK::UnrealEngine::Core::Scene*)GameObjectManager::GetSingleton()->GetScene();
		if (pScene == nullptr)
		{
			return;
		}

		std::map<FName, Analyst3D*>& mapAnalyst3D = pScene->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst3D.begin();
		while (itor != mapAnalyst3D.end())
		{
			if (itor->second->GetAnalyzeMode() == View_Shed)
			{
				ViewShed* pViewShed = ((ViewShed*)(itor->second));
				if (pViewShed != nullptr)
				{
					pMID->SetScalarParameterValue(FName("Enable"), 0);
				}
			}
			else if (itor->second->GetAnalyzeMode() == Projection_Image)
			{
				ProjectionImage* pProjectionImage = ((ProjectionImage*)(itor->second));
				if (pProjectionImage != nullptr)
				{
					pMID->SetScalarParameterValue(FName("EnableProjection"), 0);
				}
			}

			itor++;
		}

		//清空OSGB图层
		Layer3Ds* pLayer3Ds = pScene->GetLayer3Ds();
		int32 nLayer3D = pLayer3Ds->Count();
		for (int32 n = 0; n < nLayer3D; n++)
		{
			Layer3D* pLayer3D = pLayer3Ds->GetAt(n);
			if (pLayer3D->Type() == Layer3DType::S3M)
			{
				Layer3DS3MFile* pLayer3S3MFile = (Layer3DS3MFile*)pLayer3D;

				S3MEffectShaderParamters flattenParam = pLayer3S3MFile->GetS3MEffectParam();
				HypsometricSetting* pHypsometricSetting = pLayer3S3MFile->GetHypsometricSetting();
				if (flattenParam.m_pS3MEffectTexture != nullptr)
				{
					pMID->SetScalarParameterValue(TEXT("RegionCount"), 0);
					pMID->SetScalarParameterValue(TEXT("ExcavationRegionCount"), 0);
				}
				//分层设色
				if (pHypsometricSetting != nullptr)
				{
					pMID->SetScalarParameterValue(FName("DisplayMode"), 0);
				}

				pMID->SetScalarParameterValue(FName("ClipPlaneCount"), 0);
			}
		}

		// 清空淹没、坡度坡向分析
		int nCount = pScene->GetTerrainLayers()->Count();
		if (nCount > 0)
		{
			TerrainLayers* pTerrainLayers = pScene->GetTerrainLayers();
			HypsometricSetting* pHypsometricSetting = pTerrainLayers->GetHypsometricSetting();
			if (pHypsometricSetting != nullptr)
			{
				pMID->SetScalarParameterValue(FName("DisplayMode"), 0);
			}

			SlopeSetting* pSlopeSetting = pTerrainLayers->GetSlopeSetting();
			if (pSlopeSetting != nullptr)
			{
				pMID->SetScalarParameterValue(FName("SlopeDisplayMode"), 0);
			}
		}
	}

	UMaterialInstanceDynamic* GameMaterial::GetSelectionMaterial()
	{
		return m_pSelectionMaterial;
	}

	UMaterialInstanceDynamic* GameMaterial::GetRectSelectMaterial()
	{
		return m_pRectSelectMaterial;
	}

	FString GameMaterial::GetMaterialOrginName()
	{
		FString strMaterialName = TEXT("");
		if (m_pMaterialParam != nullptr)
		{
			strMaterialName = UTF8_TO_TCHAR(m_pMaterialParam->m_strMaterialName);
		}
		
		return strMaterialName;
	}

	GameMaterialParam* GameMaterial::GetMaterialParam()
	{
		return m_pMaterialParam;
	}

	void GameMaterial::UpdateMaterial(GameMaterialParam* pMaterialParam)
	{
		if (m_pMaterialParam != nullptr)
		{
			delete m_pMaterialParam;
			m_pMaterialParam = nullptr;
		}

		m_pMaterialParam = new GameMaterialParam;
		m_pMaterialParam->Copy(pMaterialParam);

		if (m_pMID != nullptr)
		{
			UpdateMaterialParam();
			if (m_pViewportMID != nullptr)
			{
				m_pViewportMID->CopyMaterialUniformParameters(m_pMID);
				UpdateViewportMID(m_pViewportMID);
			}
		}

	}

	void GameMaterial::UpdateRectMaterial(GameMaterialParam* pMaterialParam)
	{
		if (m_pRectSelectMaterial != nullptr)
		{
			Gameuint nTextureCount = pMaterialParam->m_nTextureCount > 4 ? 4 : pMaterialParam->m_nTextureCount;
			for (Gameuint i = 0; i < nTextureCount; i++)
			{
				FName strName = "SQColorTexture";
				if (i == 1)
				{
					strName = "SQFrontDepth";
				}
				else if (i == 2)
				{
					strName = "SQBackDepth";
				}

				// 设置纹理
				Gamelong nTextureHandle = pMaterialParam->m_pTextureNames[i];
				GameRenderTexture* pGameRenderTexture = GameRenderTextureManager::GetSingleton()->Get(nTextureHandle);

				if (pGameRenderTexture != nullptr)
				{
					UTextureRenderTarget2D* pTexture = pGameRenderTexture->GetRenderTarget();
					m_pRectSelectMaterial->SetTextureParameterValue(strName, pTexture);
				}
				else
				{
					m_pRectSelectMaterial->SetTextureParameterValue(strName, nullptr);
				}
			}
		}
	}

	void GameMaterial::UpdateAnalyst(UMaterialInstanceDynamic* pMD)
	{
		if (pMD == nullptr)
		{
			return;
		}

		SuperMapSDK::UnrealEngine::Core::Scene* pScene = (SuperMapSDK::UnrealEngine::Core::Scene*)GameObjectManager::GetSingleton()->GetScene();
		if (pScene == nullptr)
		{
			return;
		}

		std::map<FName, Analyst3D*>& mapAnalyst3D = pScene->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst3D.begin();
		while (itor != mapAnalyst3D.end())
		{
			if (itor->second->GetAnalyzeMode() == View_Shed)
			{
				UnrealEngine::SpatialAnalyst3D::ViewShed* pViewShed = ((UnrealEngine::SpatialAnalyst3D::ViewShed*)(itor->second));
				if (pViewShed != nullptr)
				{
					pViewShed->UpdateUniformsForMaterial(pMD, true);
				}
			}
			else if (itor->second->GetAnalyzeMode() == Projection_Image)
			{
				UnrealEngine::SpatialAnalyst3D::ProjectionImage* pProjectionImage = ((UnrealEngine::SpatialAnalyst3D::ProjectionImage*)(itor->second));
				if (pProjectionImage != nullptr)
				{
					pProjectionImage->UpdateUniformsForMaterial(pMD, true);
				}
			}
			else if (itor->second->GetAnalyzeMode() == View_Dome)
			{
				UnrealEngine::SpatialAnalyst3D::ViewDome* pViewDome = ((UnrealEngine::SpatialAnalyst3D::ViewDome*)(itor->second));
				if (pViewDome != nullptr)
				{
					pViewDome->UpdateUniformsForMaterial(pMD, true);
				}
			}
			else if (itor->second->GetAnalyzeMode() == Multi_ViewShed3D)
			{
				UnrealEngine::SpatialAnalyst3D::MultiViewShed3D* pMultiViewShed3D = ((UnrealEngine::SpatialAnalyst3D::MultiViewShed3D*)(itor->second));
				if (pMultiViewShed3D != nullptr)
				{
					pMultiViewShed3D->UpdateUniformsForMaterial(pMD, true);
				}
			}
			// TODO 其它分析功能

			itor++;
		}
	}

	void GameMaterial::SetPBRTextureParam(GamePBRParam* pPBRParam, FName & strTexture, int32 nTexCount)
	{
		if (pPBRParam == nullptr)
		{
			return;
		}

		// 基础纹理
		if (pPBRParam->m_pPBRMetallicRough != nullptr && pPBRParam->m_pPBRMetallicRough->m_nBaseColorTextureIndex == nTexCount)
		{
			strTexture = TEXT("BaseTexture");
		}// 自发光纹理
		else if (pPBRParam->m_nEmissiveTextureIndex == nTexCount)
		{
			strTexture = TEXT("EmissiveTexture");
		}// 法线纹理
		else if (pPBRParam->m_nNormalTextureIndex == nTexCount)
		{
			strTexture = TEXT("NormalTexture");
		}// 金属纹理
		else if (pPBRParam->m_pPBRMetallicRough != nullptr && pPBRParam->m_pPBRMetallicRough->m_nMetallicRoughnessTextureIndex == nTexCount)
		{
			strTexture = TEXT("MetallicTexture");
		}// 遮挡纹理
		else if (pPBRParam->m_nOcclusionTextureIndex == nTexCount)
		{
			strTexture = TEXT("OcclusionTexture");
		}// 掩膜纹理
		else if (pPBRParam->m_nMaskTextureIndex == nTexCount)
		{
			strTexture = TEXT("MaskTexture");
		}
	}

	void GameMaterial::SetPBRMaterialParam(UMaterialInstanceDynamic* pMID)
	{
		if (pMID == nullptr || m_pMaterialParam == nullptr || m_pMaterialParam->m_pPBRParam == nullptr)
		{
			return;
		}

		for (Gameint i = 0; i < m_pMaterialParam->m_nMacroCount; i++)
		{
			FString strMacro = UTF8_TO_TCHAR(m_pMaterialParam->m_setMacro[i]);
			if (strMacro == TEXT("USE_BatchPBR"))
			{
				pMID->SetScalarParameterValue(TEXT("batchPBR"), 1.0);
			}
		}

		pMID->SetScalarParameterValue(TEXT("NormalTexcoordIndex"), m_pMaterialParam->m_pPBRParam->m_nNormalTextureCoordIndex);
		pMID->SetScalarParameterValue(TEXT("NormalTextureIndex"), m_pMaterialParam->m_pPBRParam->m_nNormalTextureIndex);

		pMID->SetScalarParameterValue(TEXT("EmissiveTextureIndex"), m_pMaterialParam->m_pPBRParam->m_nEmissiveTextureIndex);
		pMID->SetScalarParameterValue(TEXT("EmissiveTexcoordIndex"), m_pMaterialParam->m_pPBRParam->m_nEmissiveTextureCoordIndex);

		pMID->SetScalarParameterValue(TEXT("OcclusionTexcoordIndex"), m_pMaterialParam->m_pPBRParam->m_nOcclusionTextureCoordIndex);
		pMID->SetScalarParameterValue(TEXT("OcclusionTextureIndex"), m_pMaterialParam->m_pPBRParam->m_nOcclusionTextureIndex);

		FVector vEmissiveFactor;
		vEmissiveFactor.X = m_pMaterialParam->m_pPBRParam->m_vec3EmissiveFactor.x;
		vEmissiveFactor.Y = m_pMaterialParam->m_pPBRParam->m_vec3EmissiveFactor.y;
		vEmissiveFactor.Z = m_pMaterialParam->m_pPBRParam->m_vec3EmissiveFactor.z;
		pMID->SetVectorParameterValue(TEXT("EmissiveFactor"), vEmissiveFactor);

		pMID->SetScalarParameterValue(TEXT("NormalTextureScale"), m_pMaterialParam->m_pPBRParam->m_fNormalTextureScale);
		pMID->SetScalarParameterValue(TEXT("OcclusionTextureStrength"), m_pMaterialParam->m_pPBRParam->m_fOcclusionTextureStrength);

		if (m_pMaterialParam->m_pPBRParam->m_AlphaMode == AlphaMode::PBRAM_MASK)
		{
			pMID->SetScalarParameterValue(TEXT("AlphaCutoff"), m_pMaterialParam->m_pPBRParam->m_fAlphaCutoff);
		}

		pMID->SetScalarParameterValue(TEXT("MaskTexcoordIndex"), m_pMaterialParam->m_pPBRParam->m_nMaskTextureCoordIndex);
		pMID->SetScalarParameterValue(TEXT("MaskTextureIndex"), m_pMaterialParam->m_pPBRParam->m_nMaskTextureIndex);

		{
			// 自发光动画
			float fOffsetSpeedU = m_pMaterialParam->m_pPBRParam->m_EmissiveTextureMotion.m_OffsetMotion.m_fSpeedU;
			float fOffsetSpeedV = m_pMaterialParam->m_pPBRParam->m_EmissiveTextureMotion.m_OffsetMotion.m_fSpeedV;
			float fOffsetPeriod = m_pMaterialParam->m_pPBRParam->m_EmissiveTextureMotion.m_OffsetMotion.m_fPeriod;

			float fTilingSpeedU = m_pMaterialParam->m_pPBRParam->m_EmissiveTextureMotion.m_TilingMotion.m_fSpeedU;
			float fTilingSpeedV = m_pMaterialParam->m_pPBRParam->m_EmissiveTextureMotion.m_TilingMotion.m_fSpeedV;
			float fTilingPeriod = m_pMaterialParam->m_pPBRParam->m_EmissiveTextureMotion.m_TilingMotion.m_fPeriod;

			pMID->SetVectorParameterValue(TEXT("EmissionOffsetMotion"), FLinearColor(fOffsetSpeedU, fOffsetSpeedV, fOffsetPeriod, 1.0f));
			pMID->SetVectorParameterValue(TEXT("EmissionTilingMotion"), FLinearColor(fTilingSpeedU, fTilingSpeedV, fTilingPeriod, 1.0f));

			if (fOffsetPeriod > 0.0 || fTilingPeriod > 0.0)
			{
				pMID->SetScalarParameterValue(TEXT("emissionColorMotion"), 1.0);
			}
		}

		if (m_pMaterialParam->m_pPBRParam->m_pPBRMetallicRough != nullptr)
		{
			GamePBRMetallicRough* pPBRMetallicRough = m_pMaterialParam->m_pPBRParam->m_pPBRMetallicRough;

			FLinearColor vBaseFactor;
			vBaseFactor.R = pPBRMetallicRough->m_vec4BaseColor.x;
			vBaseFactor.G = pPBRMetallicRough->m_vec4BaseColor.y;
			vBaseFactor.B = pPBRMetallicRough->m_vec4BaseColor.z;
			vBaseFactor.A = pPBRMetallicRough->m_vec4BaseColor.w;
			pMID->SetVectorParameterValue(TEXT("BaseFactor"), vBaseFactor);
			pMID->SetScalarParameterValue(TEXT("BaseTextureIndex"), pPBRMetallicRough->m_nBaseColorTextureIndex);
			pMID->SetScalarParameterValue(TEXT("BaseTexcoordIndex"), pPBRMetallicRough->m_nBaseColorTextureCoordIndex);
			pMID->SetScalarParameterValue(TEXT("MetallicTextureIndex"), pPBRMetallicRough->m_nMetallicRoughnessTextureIndex);
			pMID->SetScalarParameterValue(TEXT("MetallicTextcoordIndex"), pPBRMetallicRough->m_nMetallicRoughnessTextureCoordIndex);
			pMID->SetScalarParameterValue(TEXT("MetallicFactor"), pPBRMetallicRough->m_fMetallicFactor);
			pMID->SetScalarParameterValue(TEXT("RoughnessFactor"), pPBRMetallicRough->m_fRoughnessFactor);

			{
				// 基色动画
				float fBaseColorOffsetSpeedU = pPBRMetallicRough->m_BaseColorTextureMotion.m_OffsetMotion.m_fSpeedU;
				float fBaseColorOffsetSpeedV = pPBRMetallicRough->m_BaseColorTextureMotion.m_OffsetMotion.m_fSpeedV;
				float fBaseColorOffsetPeriod = pPBRMetallicRough->m_BaseColorTextureMotion.m_OffsetMotion.m_fPeriod;

				float fBaseColorTilingSpeedU = pPBRMetallicRough->m_BaseColorTextureMotion.m_TilingMotion.m_fSpeedU;
				float fBaseColorTilingSpeedV = pPBRMetallicRough->m_BaseColorTextureMotion.m_TilingMotion.m_fSpeedV;
				float fBaseColorTilingPeriod   = pPBRMetallicRough->m_BaseColorTextureMotion.m_TilingMotion.m_fPeriod;

				pMID->SetVectorParameterValue(TEXT("BaseColorOffsetMotion"), FLinearColor(fBaseColorOffsetSpeedU, fBaseColorOffsetSpeedV, fBaseColorOffsetPeriod, 1.0f));
				pMID->SetVectorParameterValue(TEXT("BaseColorTilingMotion"), FLinearColor(fBaseColorTilingSpeedU, fBaseColorTilingSpeedV, fBaseColorTilingPeriod, 1.0f));

				if (fBaseColorOffsetPeriod > 0.0 || fBaseColorTilingPeriod > 0.0)
				{
					pMID->SetScalarParameterValue(TEXT("baseColorMotion"), 1.0);
				}
			}
		}
	}

	DataType GameMaterial::GetDataType()
	{
		return m_enDataType;
	}

	bool GameMaterial::IsNeedCreateSelectionMaterial(FString strShaderName)
	{
		if (strShaderName.Compare("Custom/ModelCache") == 0 ||
			strShaderName.Compare("Custom/ModelCacheTransparent") == 0 ||
			strShaderName.Compare("Custom/NewModelCache") == 0 ||
			strShaderName.Compare("Custom/NewModelCacheTransparent") == 0 ||
			strShaderName.Compare("Custom/ModelPro") == 0 ||
			strShaderName.Compare("Custom/InstancePipe") == 0)
		{
			return true;
		}

		return false;
	}

	Gamebool GameMaterial::IsNeedCreateRectSelectMaterial(FString strShaderName)
	{
		if (strShaderName.Compare("Custom/ModelCache") == 0 ||
			strShaderName.Compare("Custom/ModelCacheTransparent") == 0 ||
			strShaderName.Compare("Custom/NewModelCache") == 0 ||
			strShaderName.Compare("Custom/NewModelCacheTransparent") == 0 ||
			strShaderName.Compare("Custom/ModelPro") == 0 ||
			strShaderName.Compare("Custom/InstancePipe") == 0)
		{
			return true;
		}

		return false;
	}

	void GameMaterial::SetMaterialIntParam(Gamechar* strParamName, Gameint nValue)
	{
		if (!m_bInitial)
		{
			AddMaterialIntParam(strParamName, nValue);
		}
		if (m_pMID == nullptr)
		{
			return;
		}

		m_pMID->SetScalarParameterValue(strParamName, nValue);
	}

	void GameMaterial::SetMaterialfloatParam(Gamechar* strParamName, Gamefloat nValue)
	{
		if (!m_bInitial)
		{
			AddMaterialFloatParam(strParamName, nValue);
		}
		if (m_pMID == nullptr)
		{
			return;
		}

		m_pMID->SetScalarParameterValue(strParamName, nValue);
	}

	void GameMaterial::SetMaterialVector3dParam(Gamechar* strParamName, GameVec3d vGameVec3d)
	{

	}

	void GameMaterial::SetMaterialVector4dParam(Gamechar* strParamName, GameVec4d vGameVec4d)
	{
		if (!m_bInitial)
		{
			AddMaterialVec4dParam(strParamName, vGameVec4d);
		}
		if (m_pMID == nullptr)
		{
			return;
		}

		FLinearColor cValue = FLinearColor(vGameVec4d.x, vGameVec4d.y, vGameVec4d.z, vGameVec4d.w);
		m_pMID->SetVectorParameterValue(strParamName, cValue);
	
		FString strParam = UTF8_TO_TCHAR(strParamName);
		if (m_pRectSelectMaterial != nullptr && strParam.Compare("rectBound") == 0)
		{
			m_pRectSelectMaterial->SetVectorParameterValue(strParamName, cValue);
		}
	}

	void GameMaterial::SetMaterialMatrix4dParam(Gamechar* strParamName, void* pValue)
	{
		if (!m_bInitial)
		{
			AddMaterialMatrix4dParam(strParamName, pValue);
		}
		if (m_pMID == nullptr)
		{
			return;
		}
		double* pDoubleMatrix = (double*)pValue;
		// 这里没做任何变换，需要在底层把矩阵变换好
		Matrix4d dMatrix(pDoubleMatrix);
		MathEngine::SetShaderMatrixParamter(m_pMID, dMatrix, strParamName);
	}

	void GameMaterial::SetMaterialTextureParam(Gamechar* strParamName, Gameint nTexIndex)
	{
		if (!m_bInitial)
		{
			if (m_pMaterialParam->m_nTextureCount == 0)
			{
				return;
			}
			Gamelong nHandle = m_pMaterialParam->m_pTextureNames[nTexIndex];
			GameTexture* pGameTex = GameTextureManager::GetSingleton()->GetTexture(nHandle);
			if (pGameTex != nullptr)
			{
				AddMaterialTextureParam(strParamName, pGameTex);
			}
			else
			{
				SuperMapSDK::GameRenderTexture* pGameRenderTex = GameRenderTextureManager::GetSingleton()->Get(nHandle);

				if (pGameRenderTex != nullptr)
				{
					AddMaterialRenderTextureParam(strParamName, pGameRenderTex);
				}
			}

		}
		if (nTexIndex >= (Gameint)m_pMaterialParam->m_nTextureCount)
		{
			return;
		}

		if (m_pMID == nullptr)
		{
			m_mapSetTextureIndex.Add(strParamName, nTexIndex);
			return;
		}

		// 设置纹理
		Gamelong nTextureHandle = m_pMaterialParam->m_pTextureNames[nTexIndex];
		GameTexture* pGameTexture = GameTextureManager::GetSingleton()->GetTexture(nTextureHandle);
		if (pGameTexture != nullptr)
		{
			UTexture2D* pTexture2D = pGameTexture->GetTexture2D();
			if (pTexture2D != nullptr)
			{
				m_pMID->SetTextureParameterValue(strParamName, pTexture2D);
				if (m_pViewportMID != nullptr)
				{
					m_pViewportMID->SetTextureParameterValue(strParamName, pTexture2D);
				}
			}
			FString strParam = UTF8_TO_TCHAR(strParamName);
			if (strParam.Compare("markerImage") == 0)
			{
				// 设置纹理矩阵
				MathEngine::SetShaderMatrixParamter(m_pMID, Matrix4d(m_pMaterialParam->m_pTexTransforms[nTexIndex]), "markerImageTexTransform");
			}
		}
		else
		{
			GameRenderTexture* pGameRenderTexture = GameRenderTextureManager::GetSingleton()->Get(nTextureHandle);
			if (pGameRenderTexture != nullptr)
			{
				UTexture* pTexture2D = (UTexture*)pGameRenderTexture->GetRenderTarget();
				if (pTexture2D != nullptr)
				{
					m_pMID->SetTextureParameterValue(strParamName, pTexture2D);
					if (m_pViewportMID != nullptr)
					{
						m_pViewportMID->SetTextureParameterValue(strParamName, pTexture2D);
					}
				}
				FString strParam = UTF8_TO_TCHAR(strParamName);
				if (strParam.Compare("markerImage") == 0)
				{
					// 设置纹理矩阵
					MathEngine::SetShaderMatrixParamter(m_pMID, Matrix4d(m_pMaterialParam->m_pTexTransforms[nTexIndex]), "markerImageTexTransform");
				}
			}
		}
		return;
	}

	void GameMaterial::AddMaterialIntParam(FName name, Gameint value)
	{
		m_mapSetMaterialInt.Add(name, value);
	}

	void GameMaterial::AddMaterialFloatParam(FName name, Gamefloat value)
	{
		m_mapSetMaterialFloat.Add(name, value);
	}

	void GameMaterial::AddMaterialMatrix4dParam(FName name, void* value)
	{
		m_mapSetMaterialMatrix4d.Add(name, value);
	}

	void GameMaterial::AddMaterialTextureParam(FName name, GameTexture* pTexture)
	{
		m_mapSetMaterialTextures.Add(name, pTexture);
	}

	void GameMaterial::AddMaterialRenderTextureParam(FName name, GameRenderTexture* pTexture)
	{
		m_mapSetMaterialRenderTextures.Add(name, pTexture);
	}

	void GameMaterial::AddMaterialVec4dParam(FName name, GameVec4d vec)
	{
		m_mapSetMaterialVec4d.Add(name, vec);
	}

	Gameint GameMaterial::GetNumUnsetTexture()
	{
		return m_mapSetMaterialTextures.Num() + m_mapSetMaterialRenderTextures.Num();
	}
	
	void GameMaterial::UpdateTextureParam()
	{
		if (m_pMID == nullptr)
		{
			return;
		}
		//GameTexture
		TArray<FName> arrRemoves;
		for (auto& It : m_mapSetMaterialTextures)
		{
			GameTexture* pGameTexture = It.Value;
			if (pGameTexture != nullptr && pGameTexture->GetInitialAndUpdateGPU())
			{
				m_pMID->SetTextureParameterValue(It.Key, pGameTexture->GetTexture2D());
				FName strKey = It.Key;
				arrRemoves.Add(strKey);
			}
		}

		Gameint nCount = arrRemoves.Num();
		if (nCount == m_mapSetMaterialTextures.Num())
		{
			m_mapSetMaterialTextures.Empty();
		}
		else
		{
			for (Gameint i = 0; i < nCount; i++)
			{
				m_mapSetMaterialTextures.Remove(arrRemoves[i]);
			}
		}


		arrRemoves.Empty();
		for (auto& It : m_mapSetMaterialRenderTextures)
		{
			GameRenderTexture* pGameTexture = It.Value;
			if (pGameTexture != nullptr)
			{
				m_pMID->SetTextureParameterValue(It.Key, pGameTexture->GetRenderTarget());
				FName strKey = It.Key;
				arrRemoves.Add(strKey);
			}
		}

		nCount = arrRemoves.Num();
		if (nCount == m_mapSetMaterialRenderTextures.Num())
		{
			m_mapSetMaterialRenderTextures.Empty();
		}
		else
		{
			for (Gameint i = 0; i < nCount; i++)
			{
				m_mapSetMaterialRenderTextures.Remove(arrRemoves[i]);
			}
		}
	}

	void GameMaterial::UpdateShaderParam()
	{
		if (m_pMID == nullptr)
		{
			return;
		}

		//异步情况下需要后设置纹理 --gaofeng
		for (TMap<FName, Gameint>::TConstIterator It = m_mapSetTextureIndex.CreateConstIterator(); It; ++It)
		{
			FName strTexName = It->Key;
			Gameint nTexIndex = It->Value;

			// 设置纹理
			Gamelong nTextureHandle = m_pMaterialParam->m_pTextureNames[nTexIndex];
			GameTexture* pGameTexture = GameTextureManager::GetSingleton()->GetTexture(nTextureHandle);
			if (pGameTexture != nullptr)
			{
				UTexture2D* pTexture2D = pGameTexture->GetTexture2D();
				if (pTexture2D != nullptr)
				{
					m_pMID->SetTextureParameterValue(strTexName, pTexture2D);
					if (m_pViewportMID != nullptr)
					{
						m_pViewportMID->SetTextureParameterValue(strTexName, pTexture2D);
					}
				}

				if (strTexName.Compare("markerImage") == 0)
				{
					// 设置纹理矩阵
					MathEngine::SetShaderMatrixParamter(m_pMID, Matrix4d(m_pMaterialParam->m_pTexTransforms[nTexIndex]), "markerImageTexTransform");
				}
			}

		}
		m_mapSetTextureIndex.Reset();

		//int
		for (auto& ItInt : m_mapSetMaterialInt)
		{
			m_pMID->SetScalarParameterValue(ItInt.Key, ItInt.Value);
		}
		m_mapSetMaterialInt.Empty();
		// float
		for (auto& ItFloat : m_mapSetMaterialFloat)
		{
			m_pMID->SetScalarParameterValue(ItFloat.Key, ItFloat.Value);
		}
		m_mapSetMaterialFloat.Empty();
		// matrix4d
		for (auto& ItMatrix4d : m_mapSetMaterialMatrix4d)
		{
			double* pDoubleMatrix = (double*)ItMatrix4d.Value;
			Matrix4d dMatrix(pDoubleMatrix);
			MathEngine::SetShaderMatrixParamter(m_pMID, dMatrix, (ItMatrix4d.Key).ToString());
		}
		m_mapSetMaterialMatrix4d.Empty();
		//Vec4d
		for (auto& ItVec4d : m_mapSetMaterialVec4d)
		{
			GameVec4d vGameVec4d = ItVec4d.Value;
			FLinearColor cValue = FLinearColor(vGameVec4d.x, vGameVec4d.y, vGameVec4d.z, vGameVec4d.w);
			m_pMID->SetVectorParameterValue(ItVec4d.Key, cValue);
		}
		m_mapSetMaterialVec4d.Empty();
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif