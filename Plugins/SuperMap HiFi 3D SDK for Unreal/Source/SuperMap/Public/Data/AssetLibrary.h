#pragma once

#include "CoreMinimal.h"
#include "Data/JsonFile.h"
#include "Base3D/CommonDefine.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			struct UEAssetLibrary
			{
			public:

				//! \brief 数据集资产
				TMap<FString, FString> m_mapMaterialAsset;

				//! \brief 点外挂资产
				TMap<FString, FString> m_mapPluginModelAsset;

				//! \brief S3M材质替换资产
				TMap<FName, TMap<FString, FString>> m_mapS3MLayersMaterialAsset;
			};

			class SUPERMAP_API AssetLibrary
			{
			public:
				AssetLibrary();
				~AssetLibrary();

				//! \brief 获取AssetLibrary单例
				static AssetLibrary* GetSingleton();

				//! \brief 清除AssetLibrary
				void DestroySingleton();

				//! \brief 获取资产映射表
				UEAssetLibrary& GetUEAssetLibrary();

				//! \brief 资产映射表导入
				//! \brief strPath JSon路径
				//! \brief strName JSon数组Key值
				Gamebool LoadAutomaticMatchingMaterials(FString strPath, FString strName);
				
				Gamebool LoadAutomaticMatchingPluginModel(FString strPath, FString strName);

				//! \brief 资产映射表导入
				//! \brief strPath JSon路径
				Gamebool LoadAutomaticMatchingS3MMaterial(FString strPath);
			private:

				Gamebool GetHomologousAsset(FString strPath, FString strName, TMap<FString, FString>& mapValue);

				Gamebool GetHomologousAsset(FString strPath, TMap<FName, TMap<FString, FString>>& mapValue);
			private:

				//! \brief 资产映射表
				UEAssetLibrary m_UEAssetLibrary;

				static AssetLibrary* m_pAssetLibrary;
			};
		}
	}
}