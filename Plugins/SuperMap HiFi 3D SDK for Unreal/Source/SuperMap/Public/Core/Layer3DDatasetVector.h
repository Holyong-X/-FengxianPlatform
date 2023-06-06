#pragma once

#include "CoreMinimal.h"
#include "Core/Layer3D.h"
#include "Data/Dataset.h"
#include "Data/Geometry.h"
#include "AssetStyle.h"
#include <vector>

class UWorld;
class UStaticMesh;
class ASuperMap_InstancedActor;
class ASuperMap_CustomVectorActor;

using namespace SuperMapSDK::UnrealEngine::Data;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Layer3DDatasetVector : public Layer3D
			{
			public:
				Layer3DDatasetVector();
				Layer3DDatasetVector(FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DDatasetVector();

			public:
				//! \brief �������
				virtual bool BuildStyle(UWorld* pWorld);

				void SetAssetStyle(AssetStyle* pAssetStyle);

				AssetStyle* GetAssetStyle();

				void SetAssetStyleField(FString strAssetStyleField);

				FString GetAssetStyleField();

				//! \brief ��ȡ���ݼ����ͣ�������
				virtual DatasetType GetType();

				//! \brief �����±��ȡ�����������
				Data::Geometry* GetGeometry(int32 nIndex);

				void SetDataset(Data::Dataset* pDataset);

				//! \brief ������ݼ��� Geometry
				void SetGeometrys(const TArray<Data::Geometry*>& arrGeometrys);

				TArray<Data::Geometry*> GetGeometrys() const;

				//! \brief ������ݼ�������
				void SetGeoAttributes(const TArray<TMap<FString, FString>>& mapGeoAttributes);

				TArray<TMap<FString, FString >> GetGeoAttributes() const;

				//�����滻
				virtual bool MaterialReplace(UWorld* pWorld, FString meshPath);

				//! \brief ��Ⱦ����
				virtual void Render(UWorld* pWorld) {}

				//! \brief ��ȡ�Ƿ�ɼ���
				virtual bool GetIsVisible() { return m_bIsVisible; }

				//! \brief ���ÿɼ���
				virtual void SetIsVisible(bool bVisible); 
			protected:
				
				//! \brief ����������
				TArray<Data::Geometry*> m_Geometrys;

				TArray<TMap<FString, FString>> m_GeoAttributes;

				Data::Dataset* m_pDataset;

				//! \brief ͼ��ķ��
				AssetStyle* m_pAssetStyle;

				//! \brief �������Ա���ֶ�ֵ���÷��
				FString m_strAssetStyleField;

				//! \brief ��Ⱦʸ������
				ASuperMap_CustomVectorActor* m_pRenderActor;
			};

		}
	}
}