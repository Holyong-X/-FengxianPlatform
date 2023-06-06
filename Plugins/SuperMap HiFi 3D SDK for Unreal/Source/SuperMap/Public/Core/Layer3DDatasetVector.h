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
				//! \brief 构建风格
				virtual bool BuildStyle(UWorld* pWorld);

				void SetAssetStyle(AssetStyle* pAssetStyle);

				AssetStyle* GetAssetStyle();

				void SetAssetStyleField(FString strAssetStyleField);

				FString GetAssetStyleField();

				//! \brief 获取数据集类型：点线面
				virtual DatasetType GetType();

				//! \brief 根据下标获取集合体的数据
				Data::Geometry* GetGeometry(int32 nIndex);

				void SetDataset(Data::Dataset* pDataset);

				//! \brief 添加数据集的 Geometry
				void SetGeometrys(const TArray<Data::Geometry*>& arrGeometrys);

				TArray<Data::Geometry*> GetGeometrys() const;

				//! \brief 添加数据集的属性
				void SetGeoAttributes(const TArray<TMap<FString, FString>>& mapGeoAttributes);

				TArray<TMap<FString, FString >> GetGeoAttributes() const;

				//材质替换
				virtual bool MaterialReplace(UWorld* pWorld, FString meshPath);

				//! \brief 渲染数据
				virtual void Render(UWorld* pWorld) {}

				//! \brief 获取是否可见性
				virtual bool GetIsVisible() { return m_bIsVisible; }

				//! \brief 设置可见性
				virtual void SetIsVisible(bool bVisible); 
			protected:
				
				//! \brief 集合体数据
				TArray<Data::Geometry*> m_Geometrys;

				TArray<TMap<FString, FString>> m_GeoAttributes;

				Data::Dataset* m_pDataset;

				//! \brief 图层的风格
				AssetStyle* m_pAssetStyle;

				//! \brief 根据属性表的字段值设置风格
				FString m_strAssetStyleField;

				//! \brief 渲染矢量数据
				ASuperMap_CustomVectorActor* m_pRenderActor;
			};

		}
	}
}