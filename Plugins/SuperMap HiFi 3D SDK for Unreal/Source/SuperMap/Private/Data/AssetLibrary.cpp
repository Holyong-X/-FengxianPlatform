#include "Data/AssetLibrary.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			AssetLibrary* AssetLibrary::m_pAssetLibrary = NULL;

			AssetLibrary::AssetLibrary()
			{

			}

			AssetLibrary::~AssetLibrary()
			{
				m_UEAssetLibrary.m_mapMaterialAsset.Empty();
				m_UEAssetLibrary.m_mapPluginModelAsset.Empty();
				m_UEAssetLibrary.m_mapS3MLayersMaterialAsset.Empty();
				m_pAssetLibrary = NULL;
			}

			AssetLibrary* AssetLibrary::GetSingleton()
			{
				if (m_pAssetLibrary == NULL)
				{
					m_pAssetLibrary = new AssetLibrary();
				}
				return m_pAssetLibrary;
			}

			void AssetLibrary::DestroySingleton()
			{
				if (m_pAssetLibrary != NULL)
				{
					delete m_pAssetLibrary;
					m_pAssetLibrary = NULL;
				}
			}

			Gamebool AssetLibrary::LoadAutomaticMatchingMaterials(FString strPath, FString strName)
			{
				TMap<FString, FString> mapValue;
				GetHomologousAsset(strPath, strName, mapValue);
				if (mapValue.Num() > 0)
				{
					for (auto It : mapValue)
					{
						m_UEAssetLibrary.m_mapMaterialAsset.Add(It.Key, It.Value);
					}
				}
				return true;
			}

			Gamebool AssetLibrary::LoadAutomaticMatchingPluginModel(FString strPath, FString strName)
			{
				TMap<FString, FString> mapValue;
				GetHomologousAsset(strPath, strName, mapValue);
				if (mapValue.Num() > 0)
				{
					for (auto It : mapValue)
					{
						m_UEAssetLibrary.m_mapPluginModelAsset.Add(It.Key, It.Value);
					}
				}
				return true;
			}

			Gamebool AssetLibrary::LoadAutomaticMatchingS3MMaterial(FString strPath)
			{
				TMap<FName, TMap<FString, FString>> mapValue;
				GetHomologousAsset(strPath, mapValue);
				if (mapValue.Num() > 0)
				{
					for (auto It : mapValue)
					{
						m_UEAssetLibrary.m_mapS3MLayersMaterialAsset.Add(It.Key, It.Value);
					}
				}
				return true;
			}

			Gamebool AssetLibrary::GetHomologousAsset(FString strPath, FString strName, TMap<FString, FString>& mapValue)
			{
				JsonFile* jsonFile = new JsonFile();
				JsonFile* jsonDataInfos = nullptr;
				jsonFile->LoadFromStdFile(strPath);
				Gamebool bResult = jsonFile->GetValue(strName, jsonDataInfos);
				if (!bResult)
				{
					delete jsonFile;
					jsonFile = nullptr;
					return false;
				}
				JsonFile* jsonDataInfo = jsonDataInfos->GetAt(0);
				if (jsonDataInfo == nullptr)
				{
					delete jsonDataInfos;
					jsonDataInfos = nullptr;
					delete jsonFile;
					jsonFile = nullptr;
					return false;
				}
				TArray<FString> arrKeys = jsonDataInfo->GetAllKeys();
				for (int n = 0; n < arrKeys.Num(); n++)
				{
					FString strValue = "";
					jsonDataInfo->GetValue(arrKeys[n], strValue);
					mapValue.Add(arrKeys[n], strValue);
				}
				delete jsonDataInfos;
				jsonDataInfos = nullptr;
				delete jsonFile;
				jsonFile = nullptr;
				
				return true;
			}

			Gamebool AssetLibrary::GetHomologousAsset(FString strPath, TMap<FName, TMap<FString, FString>>& mapValue)
			{
				JsonFile* jsonFile = new JsonFile();
				JsonFile* jsonScenes = nullptr;
				jsonFile->LoadFromStdFile(strPath);
				jsonFile->GetValue(FString("Scenes"), jsonScenes);
				if (jsonScenes == nullptr)
				{
					delete jsonFile;
					jsonFile = nullptr;
					return false;
				}
				Gameint nScenesCount = jsonScenes->GetArraySize();
				for (int i = 0; i < nScenesCount; i++)
				{
					JsonFile* jsonScene = jsonScenes->GetAt(i);
					if (jsonScene == nullptr)
					{
						continue;
					}
					JsonFile* jsonLayers = nullptr;
					jsonScene->GetValue(FString("Layers"), jsonLayers);
					if (jsonLayers == nullptr)
					{
						delete jsonScene;
						jsonScene = nullptr;
						continue;
					}
					Gameint nLayersCount = jsonLayers->GetArraySize();
					for (int j = 0; j < nLayersCount; j++)
					{
						JsonFile* jsonLayer = jsonLayers->GetAt(j);
						if (jsonLayer == nullptr)
						{
							continue;
						}
						FString layerName;
						jsonLayer->GetValue(FString("LayerName"), layerName);
						JsonFile* jsonMaterials = nullptr;
						jsonLayer->GetValue(FString("Materials"), jsonMaterials);
						if (jsonMaterials == nullptr)
						{
							delete jsonLayer;
							jsonLayer = nullptr;
							continue;
						}
						JsonFile* jsonMaterialMap = nullptr;
						jsonMaterials->GetValue(FString("MaterialMap"), jsonMaterialMap);
						if (jsonMaterialMap == nullptr)
						{
							delete jsonLayer;
							jsonLayer = nullptr;
							delete jsonMaterials;
							jsonMaterials = nullptr;
							continue;
						}
						Gameint nMaterialMapCount = jsonMaterialMap->GetArraySize();
						TMap<FString, FString> mapMaterialNameChanges;
						for (int m = 0; m < nMaterialMapCount; m++)
						{
							JsonFile* jsonMaterial = jsonMaterialMap->GetAt(m);
							if (jsonMaterial == nullptr)
							{
								continue;
							}
							FString strAssociateMaterial;
							FString strOriginalMaterial;
							jsonMaterial->GetValue(FString("AssociateMaterial"), strAssociateMaterial);
							jsonMaterial->GetValue(FString("OriginalMaterial"), strOriginalMaterial);
							mapMaterialNameChanges.Add(strOriginalMaterial, strAssociateMaterial);
							delete jsonMaterial;
							jsonMaterial = nullptr;
						}

						delete jsonMaterialMap;
						jsonMaterialMap = nullptr;
						delete jsonMaterials;
						jsonMaterials = nullptr;
						delete jsonLayer;
						jsonLayer = nullptr;
						mapValue.Add(FName(*layerName), mapMaterialNameChanges);
					}
					delete jsonLayers;
					jsonLayers = nullptr;
					delete jsonScene;
					jsonScene = nullptr;
				}
				delete jsonScenes;
				jsonScenes = nullptr;
				delete jsonFile;
				jsonFile = nullptr;
				return true;
			}

			UEAssetLibrary& AssetLibrary::GetUEAssetLibrary()
			{
				return m_UEAssetLibrary;
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif