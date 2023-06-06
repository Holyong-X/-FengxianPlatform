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

				//! \brief ���ݼ��ʲ�
				TMap<FString, FString> m_mapMaterialAsset;

				//! \brief ������ʲ�
				TMap<FString, FString> m_mapPluginModelAsset;

				//! \brief S3M�����滻�ʲ�
				TMap<FName, TMap<FString, FString>> m_mapS3MLayersMaterialAsset;
			};

			class SUPERMAP_API AssetLibrary
			{
			public:
				AssetLibrary();
				~AssetLibrary();

				//! \brief ��ȡAssetLibrary����
				static AssetLibrary* GetSingleton();

				//! \brief ���AssetLibrary
				void DestroySingleton();

				//! \brief ��ȡ�ʲ�ӳ���
				UEAssetLibrary& GetUEAssetLibrary();

				//! \brief �ʲ�ӳ�����
				//! \brief strPath JSon·��
				//! \brief strName JSon����Keyֵ
				Gamebool LoadAutomaticMatchingMaterials(FString strPath, FString strName);
				
				Gamebool LoadAutomaticMatchingPluginModel(FString strPath, FString strName);

				//! \brief �ʲ�ӳ�����
				//! \brief strPath JSon·��
				Gamebool LoadAutomaticMatchingS3MMaterial(FString strPath);
			private:

				Gamebool GetHomologousAsset(FString strPath, FString strName, TMap<FString, FString>& mapValue);

				Gamebool GetHomologousAsset(FString strPath, TMap<FName, TMap<FString, FString>>& mapValue);
			private:

				//! \brief �ʲ�ӳ���
				UEAssetLibrary m_UEAssetLibrary;

				static AssetLibrary* m_pAssetLibrary;
			};
		}
	}
}