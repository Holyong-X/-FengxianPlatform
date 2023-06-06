#include "Core/TerrainLayers.h"
#include "Core/TerrainLayer.h"
#include "Core/Public/Misc/Paths.h"
#include "Core/Scene.h"
#include "Component/SuperMap_MeshComponent.h"
#include "Core/ROCacheManager.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Graphics3D/GameObjectManager.h"
#include "Algorithm3D/MathEngine.h"

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

#if PLATFORM_LINUX
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			TerrainLayers::TerrainLayers()
			{
				m_pScene = nullptr;
				m_pHypsometricSetting = nullptr;
				m_pModifyTerrainSetting = nullptr;
				m_bUpdateHypsometricSetting = false;
				m_pSlopeSetting = nullptr;
				m_bUpdateSlopeSetting = false;
				m_fSumTime = 0.0;
			}

			TerrainLayers::TerrainLayers(Scene* pScene)
			{
				m_pScene = pScene;
				m_pHypsometricSetting = nullptr;
				m_pModifyTerrainSetting = nullptr;
				m_bUpdateHypsometricSetting = false;
				m_pSlopeSetting = nullptr;
				m_bUpdateSlopeSetting = false;
				m_fSumTime = 0.0;
			}

			TerrainLayers::~TerrainLayers()
			{
				m_pScene = nullptr;
				Clear();

				if (m_pHypsometricSetting != nullptr)
				{
					m_pHypsometricSetting->SetDisplayMode(NONE);
					UpdateHypsometricSetting();
					delete m_pHypsometricSetting;
					m_pHypsometricSetting = nullptr;
				}
				if (m_pModifyTerrainSetting != nullptr)
				{
					delete m_pModifyTerrainSetting;
					m_pModifyTerrainSetting = nullptr;
				}
				m_bUpdateHypsometricSetting = false;

				if (m_pSlopeSetting != nullptr)
				{
					m_pSlopeSetting->SetDisplaySytle(SlopeSetting::DisplayMode::NONE);
					UpdateSlopeSetting();
					delete m_pSlopeSetting;
					m_pSlopeSetting = nullptr;
				}
				m_bUpdateSlopeSetting = false;

				m_mapNativeGameComponent.Empty();
			}

			void TerrainLayers::Clear()
			{
				for (int32 i = 0; i < m_terrain3Ds.Num(); i++)
				{
					TerrainLayer* pTerrainLayer = m_terrain3Ds[i];
					if (pTerrainLayer != nullptr)
					{
						delete pTerrainLayer;
						pTerrainLayer = nullptr;
					}
				}

				if (m_pModifyTerrainSetting != nullptr)
				{
					delete m_pModifyTerrainSetting;
					m_pModifyTerrainSetting = nullptr;
				}

				m_terrain3Ds.Empty();
			}

			int32 TerrainLayers::Count()
			{
				return m_terrain3Ds.Num();
			}

			TerrainLayer* TerrainLayers::Add(FString strUrl, FString strLayerName)
			{
				const TCHAR* cUrl = *strUrl;
				ANSICHAR* ccUrl = TCHAR_TO_UTF8(cUrl);

				const TCHAR* cLayerName = *strLayerName;
				ANSICHAR* ccLayerName = TCHAR_TO_UTF8(cLayerName);
				FName strName(strLayerName);
				TerrainLayer* pTerrainLayer = NULL;
				if (_AddWebTerrain != nullptr)
				{
					bool result = _AddWebTerrain(ccUrl, ccLayerName);
					if (result)
					{
						pTerrainLayer = new TerrainLayer(strName);
						m_terrain3Ds.Add(pTerrainLayer);
					}
				}
				return pTerrainLayer;
			}

			TerrainLayer* TerrainLayers::Add(FString strFile, bool bAddToHead)
			{
				ANSICHAR* cc;
				MathEngine::FStringToANSIChar(strFile, cc);

				FString strString = strFile;
				FName strName(*strString);
				TerrainLayer* pTerrainLayer = NULL;
				if (_AddTerrainLayer != nullptr)
				{
					bool result = _AddTerrainLayer(cc);
					if (result)
					{
						pTerrainLayer = new TerrainLayer(strName);
						m_terrain3Ds.Add(pTerrainLayer);
					}
				}

				return pTerrainLayer;
			}

			TerrainLayer* TerrainLayers::Add(FString strUrl, FString strLayerName, TerrainLayerType eLayerType)
			{
				const TCHAR* cUrl = *strUrl;
				ANSICHAR* ccUrl = TCHAR_TO_UTF8(cUrl);

				const TCHAR* cLayerName = *strLayerName;
				ANSICHAR* ccLayerName = TCHAR_TO_UTF8(cLayerName);

				FName strName(ccLayerName);
				TerrainLayer* pTerrainLayer = new TerrainLayer(strName);

				if (eLayerType == STK)
				{
					if (_AddSTK != nullptr)
					{
						m_terrain3Ds.Add(pTerrainLayer);
						_AddSTK(ccUrl, ccLayerName);
					}
				}
				else if (eLayerType == TIANDITU)
				{
					if (_AddTiandituTerrain != nullptr)
					{
						m_terrain3Ds.Add(pTerrainLayer);
						_AddTiandituTerrain(ccUrl, ccLayerName);
					}
				}
				return pTerrainLayer;
			}

			TerrainLayer* TerrainLayers::GetAt(int32 index)
			{
				if (index >= m_terrain3Ds.Num())
				{
					return nullptr;
				}
				return m_terrain3Ds[index];
			}

			TerrainLayer*  TerrainLayers::GetAt(FName strLayerName)
			{
				int32 nCount = m_terrain3Ds.Num();
				for (int32 i = 0; i < nCount; i++)
				{
					TerrainLayer* pTerrainLayer = m_terrain3Ds[i];

					FString strOriLayerName = pTerrainLayer->GetName().ToString();
					strOriLayerName = FPaths::GetBaseFilename(strOriLayerName);
					FName strOriName(*strOriLayerName);
					if (strOriName == strLayerName)
					{
						return pTerrainLayer;
					}
				}

				return nullptr;
			}

			bool TerrainLayers::Remove(int Index)
			{
				m_terrain3Ds.RemoveAt(Index);
				return _RemoveTerrainLayers(Index);
			}

			void TerrainLayers::Render()
			{
				if (m_bUpdateHypsometricSetting)
				{
					UpdateHypsometricSetting();
				}
				if (m_bUpdateSlopeSetting)
				{
					UpdateSlopeSetting();
				}

				UpdateDynamicSlopeParam();
			}

			void TerrainLayers::SetHypsometricSetting(HypsometricSetting* pHypsometricSetting)
			{
				if (m_pHypsometricSetting == nullptr)
				{
					m_pHypsometricSetting = new HypsometricSetting();
				}
				m_pHypsometricSetting->SetAnalysisMode(pHypsometricSetting->GetAnalysisMode());
				m_pHypsometricSetting->SetDisplayMode(pHypsometricSetting->GetDisplayMode());
				m_pHypsometricSetting->SetLineColor(pHypsometricSetting->GetLineColor());
				m_pHypsometricSetting->SetLinesInterval(pHypsometricSetting->GetLinesInterval());
				m_pHypsometricSetting->SetColorTableMaxKey(pHypsometricSetting->GetColorTableMaxKey());
				m_pHypsometricSetting->SetColorTableMinKey(pHypsometricSetting->GetColorTableMinKey());
				m_pHypsometricSetting->SetMaxVisibleValue(pHypsometricSetting->GetMaxVisibleValue());
				m_pHypsometricSetting->SetMinVisibleValue(pHypsometricSetting->GetMinVisibleValue());
				m_pHypsometricSetting->SetColorTableTexture(pHypsometricSetting->GetColorTableTexture());
				m_bUpdateHypsometricSetting = true;
			}

			HypsometricSetting* TerrainLayers::GetHypsometricSetting()
			{
				return m_pHypsometricSetting;
			}

			void TerrainLayers::ClearHypsometricSetting()
			{
				if (m_pHypsometricSetting != nullptr)
				{
					m_pHypsometricSetting->SetDisplayMode(NONE);
					UpdateHypsometricSetting();
					delete m_pHypsometricSetting;
				}
				m_pHypsometricSetting = nullptr;
			}

			void TerrainLayers::UpdateHypsometricSetting()
			{
				if (m_pHypsometricSetting == nullptr)
				{
					return;
				}

				for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapNativeGameComponent.CreateConstIterator(); It; ++It)
				{
					GameComponent* pGameComponent = It->Value;
					if (pGameComponent != nullptr)
					{
						TArray<UMaterialInterface*> arrCustomMaterials;
						pGameComponent->GetSceneNode()->GetAllCustomMaterials(arrCustomMaterials);
						for (int materialIndex = 0; materialIndex < arrCustomMaterials.Num(); materialIndex++)
						{
							UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)arrCustomMaterials[materialIndex];
							UpdateHypsometricSettingShaderForOneMaterial(pMat);
						}
					}
						
				}
				m_bUpdateHypsometricSetting = false;
			}

			void TerrainLayers::UpdateHypsometricSettingShaderForOneMaterial(UMaterialInstanceDynamic* pMat)
			{
				if (pMat == nullptr)
				{
					return;
				}
				pMat->SetScalarParameterValue(FName("HypsometricSettingMode"), int(m_pHypsometricSetting->GetAnalysisMode()));
				pMat->SetScalarParameterValue(FName("DisplayMode"), int(m_pHypsometricSetting->GetDisplayMode()));
				pMat->SetVectorParameterValue(FName("LineColor"), FLinearColor(m_pHypsometricSetting->GetLineColor()));
				pMat->SetScalarParameterValue(FName("LinesInterval"), m_pHypsometricSetting->GetLinesInterval());
				pMat->SetScalarParameterValue(FName("ColorTableMinKey"), m_pHypsometricSetting->GetColorTableMinKey());
				pMat->SetScalarParameterValue(FName("ColorTableMaxKey"), m_pHypsometricSetting->GetColorTableMaxKey());
				pMat->SetScalarParameterValue(FName("MinVisibleValue"), m_pHypsometricSetting->GetMinVisibleValue());
				pMat->SetScalarParameterValue(FName("MaxVisibleValue"), m_pHypsometricSetting->GetMaxVisibleValue());
				pMat->SetTextureParameterValue(FName("HypsometricSettingTexture"), m_pHypsometricSetting->GetColorTableTexture());
			}

			void TerrainLayers::SetSlopeSetting(SlopeSetting* pSlopeSetting)
			{
				if (m_pSlopeSetting == nullptr)
				{
					m_pSlopeSetting = new SlopeSetting(*pSlopeSetting);
				}
				else
				{
					*m_pSlopeSetting = *pSlopeSetting;
				}
				m_bUpdateSlopeSetting = true;
			}

			SlopeSetting* TerrainLayers::GetSlopeSetting()
			{
				return m_pSlopeSetting;
			}

			void TerrainLayers::ClearSlopeSetting()
			{
				if (m_pSlopeSetting != nullptr)
				{
					m_pSlopeSetting->SetDisplaySytle(SlopeSetting::DisplayMode::NONE);
					UpdateSlopeSetting();
					delete m_pSlopeSetting;
				}
				m_pSlopeSetting = nullptr;
			}

			void TerrainLayers::UpdateSlopeSetting()
			{
				if (m_pSlopeSetting == nullptr)
				{
					return;
				}

				m_pSlopeSetting->UpdateShaderParams(m_SlopeMapShaderParams);

				for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapNativeGameComponent.CreateConstIterator(); It; ++It)
				{
					GameComponent* pGameComponent = It->Value;
					if (pGameComponent != nullptr)
					{
						TArray<UMaterialInterface*> arrCustomMaterials;
						pGameComponent->GetSceneNode()->GetAllCustomMaterials(arrCustomMaterials);
						for (int materialIndex = 0; materialIndex < arrCustomMaterials.Num(); materialIndex++)
						{
							UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)arrCustomMaterials[materialIndex];
							if (pMat)
							{
								UpdateSlopeShaderForOneMaterial(pMat);
							}
						}
					}
				}
				m_bUpdateSlopeSetting = false;
			}

			void TerrainLayers::UpdateSlopeShaderForOneMaterial(UMaterialInstanceDynamic* pMat)
			{
				pMat->SetScalarParameterValue(FName("SlopeDisplayMode"), m_SlopeMapShaderParams.SlopeDisplayMode);
				pMat->SetScalarParameterValue(FName("SlopeFloorAngle"), m_SlopeMapShaderParams.SlopeFloorAngle);
				pMat->SetScalarParameterValue(FName("SlopeCeilAngle"), m_SlopeMapShaderParams.SlopeCeilAngle);
				pMat->SetScalarParameterValue(FName("SlopeMinVisibleSlope"), m_SlopeMapShaderParams.SlopeMinVisibleSlope);
				pMat->SetScalarParameterValue(FName("SlopeMaxVisibleSlope"), m_SlopeMapShaderParams.SlopeMaxVisibleSlope);
				pMat->SetTextureParameterValue(FName("SlopeColorTexture"), m_SlopeMapShaderParams.SlopeColorTexture);
				if (m_SlopeMapShaderParams.SlopeArrowTexture != nullptr)
				{
					pMat->SetTextureParameterValue(FName("SlopeArrowTexture"), m_SlopeMapShaderParams.SlopeArrowTexture);
				}
				pMat->SetScalarParameterValue(FName("SlopeArrowsMove"), m_SlopeMapShaderParams.SlopeArrowsMove);
			}

			void TerrainLayers::UpdateDynamicSlopeParam()
			{
				if (m_pSlopeSetting == nullptr)
				{
					return;
				}

				float fSlopeTimeVal = 0.0;
				if (m_pSlopeSetting->IsArrowMove())
				{
					if (m_fSumTime >= 1000)
					{
						m_fSumTime = 0.0;
					}
					m_fSumTime += 0.02;
					float fModValue = fmod(m_fSumTime, 3.0);
					fSlopeTimeVal = fModValue / 3.0;
				}
				else
				{
					m_fSumTime = 0.0f;
				}

				m_SlopeMapShaderParams.SlopeTopLevel = _TerrainLayer_GetTopLevel();

				for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapNativeGameComponent.CreateConstIterator(); It; ++It)
				{
					GameComponent* pGameComponent = It->Value;
					if (pGameComponent != nullptr)
					{
						TArray<UMaterialInterface*> arrCustomMaterials;
						pGameComponent->GetSceneNode()->GetAllCustomMaterials(arrCustomMaterials);
						for (int materialIndex = 0; materialIndex < arrCustomMaterials.Num(); materialIndex++)
						{
							UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)arrCustomMaterials[materialIndex];
							if (pMat)
							{
								pMat->SetScalarParameterValue(FName("SlopeTopLevel"), m_SlopeMapShaderParams.SlopeTopLevel);
								pMat->SetScalarParameterValue(FName("SlopeTimeVal"), fSlopeTimeVal);
							}
						}
					}
				}
			}

			void TerrainLayers::AddNativeGameComponent(GameComponent* pGameComponent)
			{
				m_mapNativeGameComponent.Add(pGameComponent->GetNodeName(), pGameComponent);
				UpdateShaderForOneNativeGameComponent(pGameComponent);
			}

			void TerrainLayers::RemoveNativeGameComponent(GameComponent* pGameComponent)
			{
				m_mapNativeGameComponent.Remove(pGameComponent->GetNodeName());
			}

			TArray<TerrainLayer*>& TerrainLayers::GetTerrainLayer3Ds()
			{
				return m_terrain3Ds;
			}

			void TerrainLayers::UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent)
			{
				TArray<GameMaterial*>& listGameMaterial = pGameComponent->GetAllGameMaterial();
				for (int i = 0; i < listGameMaterial.Num(); i++)
				{
					GameMaterial* pGameMaterial = listGameMaterial[i];
					if (pGameMaterial == nullptr)
					{
						continue;
					}

					UMaterialInstanceDynamic* pMat = pGameMaterial->GetMID();
					if (m_pSlopeSetting != nullptr)
					{
						UpdateSlopeShaderForOneMaterial(pMat);
					}

					if (m_pHypsometricSetting != nullptr)
					{
						UpdateHypsometricSettingShaderForOneMaterial(pMat);
					}
					pGameMaterial->UpdateShaderParam();
				}
			}

			ModifyTerrainSetting* TerrainLayers::GetModifyTerrainSetting()
			{
				if (m_pModifyTerrainSetting == nullptr)
				{
					void* pModifyTerrainSetting = nullptr;
					_GetModifyTerrainSetting(pModifyTerrainSetting);
					m_pModifyTerrainSetting = new ModifyTerrainSetting(pModifyTerrainSetting);
				}
				return m_pModifyTerrainSetting;
			}
		}
	}
}
#if PLATFORM_LINUX
PRAGMA_DISABLE_OPTIMIZATION
#endif