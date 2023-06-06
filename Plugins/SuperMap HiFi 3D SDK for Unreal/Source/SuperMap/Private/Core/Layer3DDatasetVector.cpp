#include "Core/Layer3DDatasetVector.h"
#include "Component/SuperMap_CustomVectorActor.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Layer3DDatasetVector::Layer3DDatasetVector():Layer3D()
			{
				m_pDataset      = nullptr;
				m_pAssetStyle   = nullptr;
				m_pRenderActor = nullptr;
				m_bInitial      = false; 
			}

			Layer3DDatasetVector::Layer3DDatasetVector(FName strLayerName, Layer3DType eLayerType):
				Layer3D(strLayerName, eLayerType)
			{
				m_pDataset = nullptr;
				m_pAssetStyle = nullptr;
				m_pRenderActor = nullptr;
				m_bInitial = false;
			}

			Layer3DDatasetVector::~Layer3DDatasetVector()
			{
				if (m_pAssetStyle != nullptr)
				{
					delete m_pAssetStyle;
					m_pAssetStyle = nullptr;
				}

				for( int geo = 0; geo < m_Geometrys.Num(); geo ++)
				{
					delete m_Geometrys[geo];
					m_Geometrys[geo] = nullptr;
				}
				m_Geometrys.Empty();

				if (m_pRenderActor)
				{
					m_pRenderActor->Destroy();
					m_pRenderActor = nullptr;
				}


				m_pDataset = nullptr;
			}

			void Layer3DDatasetVector::SetAssetStyle(AssetStyle* pAssetStyle)
			{
				if (m_pAssetStyle != nullptr)
				{
					delete m_pAssetStyle;
					m_pAssetStyle = nullptr;
				}
				m_pAssetStyle = pAssetStyle;
			}

			AssetStyle* Layer3DDatasetVector::GetAssetStyle()
			{
				return m_pAssetStyle;
			}

			void Layer3DDatasetVector::SetAssetStyleField(FString strAssetStyleField)
			{
				m_strAssetStyleField = strAssetStyleField;
			}

			FString Layer3DDatasetVector::GetAssetStyleField()
			{
				return m_strAssetStyleField;
			}

			Data::Geometry* Layer3DDatasetVector::GetGeometry(int32 nIndex)
			{
				if (nIndex < 0 || nIndex > m_Geometrys.Num())
				{
					return nullptr;
				}

				return m_Geometrys[nIndex];
			}

			void Layer3DDatasetVector::SetDataset(Dataset* pDataset)
			{
				m_pDataset = pDataset;
			}

			bool Layer3DDatasetVector::BuildStyle(UWorld* pWorld)
			{
				return true;
			}

			DatasetType Layer3DDatasetVector::GetType()
			{
				return m_pDataset->GetType();
			}

			void Layer3DDatasetVector::SetGeometrys(const TArray<Data::Geometry*>& arrGeometrys)
			{
				if (m_Geometrys.Num() > 0)
				{
					m_Geometrys.Empty();
				}
				m_Geometrys = arrGeometrys;
			}

			TArray<Data::Geometry*> Layer3DDatasetVector::GetGeometrys() const
			{
				return m_Geometrys;
			}

			void Layer3DDatasetVector::SetGeoAttributes(const TArray<TMap<FString, FString>>& mapGeoAttributes)
			{
				if (m_GeoAttributes.Num() > 0)
				{
					m_GeoAttributes.Empty();
				}
				m_GeoAttributes = mapGeoAttributes;
			}

			void Layer3DDatasetVector::SetIsVisible(bool bVisible)
			{
				m_bIsVisible = bVisible;
				if (m_pRenderActor != nullptr)
				{
					m_pRenderActor->SetActorHiddenInGame(!bVisible);
				}
			}

			TArray<TMap<FString, FString>> Layer3DDatasetVector::GetGeoAttributes() const
			{
				return m_GeoAttributes;
			}

			bool Layer3DDatasetVector::MaterialReplace(UWorld* pWorld, FString meshPath)
			{
				return true;
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif