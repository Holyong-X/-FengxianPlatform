#include "Core/Layer3DDatasetVectorRegion.h"
#include "Data/GeoRegion3D.h"
#include "Component/SuperMap_CustomVectorActor.h"
#include "Graphics3D/GameObjectManager.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK;

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Layer3DDatasetVectorRegion::Layer3DDatasetVectorRegion() :Layer3DDatasetVector()
			{
			}

			Layer3DDatasetVectorRegion::Layer3DDatasetVectorRegion(FName strLayerName, Layer3DType eLayerType):
				Layer3DDatasetVector(strLayerName, eLayerType)
			{

			}

			Layer3DDatasetVectorRegion::~Layer3DDatasetVectorRegion()
			{
				
			}

			void Layer3DDatasetVectorRegion::GetVertexInfo(TArray<Data::Geometry*> arrGeometrys, TArray<int32>& arrIndexs, TArray<FVector>& arrPos)
			{
				Gameint nPrePtsNum = 0;
				for (Gameint nGeometry = 0; nGeometry < arrGeometrys.Num(); nGeometry++)
				{
					GeoRegion3D* pGeoRegion3D = (GeoRegion3D*)(arrGeometrys[nGeometry]);
					if (pGeoRegion3D == nullptr)
					{
						continue;
					}

					pGeoRegion3D->GetTriangleIndices(arrIndexs, nPrePtsNum);

					pGeoRegion3D->GetPoints(arrPos);
					nPrePtsNum += pGeoRegion3D->GetPointCount();
				}
			}

			void Layer3DDatasetVectorRegion::GetVertexInfo(TArray<Data::Geometry*> arrGeometrys, TArray<int32>& arrIndexs, TArray<Vector3d>& arrPos)
			{
				Gameint nPrePtsNum = 0;
				for (Gameint nGeometry = 0; nGeometry < arrGeometrys.Num(); nGeometry++)
				{
					GeoRegion3D* pGeoRegion3D = (GeoRegion3D*)(arrGeometrys[nGeometry]);
					if (pGeoRegion3D == nullptr)
					{
						continue;
					}

					pGeoRegion3D->GetTriangleIndices(arrIndexs, nPrePtsNum);

					pGeoRegion3D->GetPoints(arrPos);
					nPrePtsNum += pGeoRegion3D->GetPointCount();
				}
			}
			
			bool Layer3DDatasetVectorRegion::BuildStyle(UWorld* pWorld)
			{
				m_bInitial = true;
				if (m_pRenderActor)
				{
					m_pRenderActor->Flush();
				}

				//2查询条件置风格
				TMap<FString, AssetStyle*> mapAssetStyles = GetUEAssetStyle()->GetAssetStyles();
				if (mapAssetStyles.Num() > 0)
				{
					for (auto It : mapAssetStyles)
					{
						
						FString string = It.Key;
						AssetStyle* pAssetStyle = It.Value;

						TArray<Data::Geometry*> arrGeometrys = m_pDataset->QueryBySql(string);

						if (GetUEAssetStyle()->GetMode() == UEAssetStyle::Mode::ASSET_MATERIAL)
						{
							TArray<int32> arrIndexs;//索引
							TArray<Vector3d> arrPos;//顶点
							GetVertexInfo(arrGeometrys, arrIndexs, arrPos);
							pAssetStyle->BuildStyle(arrPos, arrIndexs);
						}
						else
						{
							TArray<FVector> arrLocations;
							for (int32 nGeometry = 0; nGeometry < arrGeometrys.Num(); nGeometry++)
							{
								GeoRegion3D* pGeoRegion3D = (GeoRegion3D*)(arrGeometrys[nGeometry]);
								if (pGeoRegion3D == nullptr)
								{
									continue;
								}

								pGeoRegion3D->GetSubdivisionPoints(arrLocations, pAssetStyle->GetStyleParam().m_fDistance);
							}

							pAssetStyle->BuildSubdivisionStyle(arrLocations);
						}


					}

					return true;
				}

				//3图层设置风格
				if (m_Geometrys.Num() == 0)
				{
					m_Geometrys = m_pDataset->Query();
				}
			
				if (m_Geometrys.Num() == 0 || m_pAssetStyle == nullptr)
				{
					return false;
				}

				if (GetUEAssetStyle()->GetMode() == UEAssetStyle::Mode::ASSET_MATERIAL)
				{
					TArray<int32> arrIndexs;//索引
					TArray<FVector> arrPos;//顶点
					GetVertexInfo(m_Geometrys, arrIndexs, arrPos);
					return m_pAssetStyle->BuildStyle(arrPos, arrIndexs);
				}

				TArray<FVector> arrLocations;
				for (int32 nGeometry = 0; nGeometry < m_Geometrys.Num(); nGeometry++)
				{
					GeoRegion3D* pGeoRegion3D = (GeoRegion3D*)(m_Geometrys[nGeometry]);
					if (pGeoRegion3D == nullptr)
					{
						continue;
					}

					pGeoRegion3D->GetSubdivisionPoints(arrLocations, m_pAssetStyle->GetStyleParam().m_fDistance);
				}

				return m_pAssetStyle->BuildSubdivisionStyle(arrLocations);
			}

			DatasetType Layer3DDatasetVectorRegion::GetType()
			{
				return DatasetType::DT_REGION;
			}

			void Layer3DDatasetVectorRegion::Render(UWorld* pWorld)
			{
				if (!m_bInitial)
				{
					if (m_pRenderActor == nullptr)
					{
						m_pRenderActor = pWorld->SpawnActor<ASuperMap_CustomVectorActor>();
						GameObjectManager::GetSingleton()->GetVectorActors().Add(m_pRenderActor);
					}

					if (m_Geometrys.Num() == 0)
					{
						m_Geometrys = m_pDataset->Query();
					}

					TArray<GeoRegion3D*> arrRegions;
					for (int32 nGeometry = 0; nGeometry < m_Geometrys.Num(); nGeometry++)
					{
						GeoRegion3D* pGeoRegion3D = (GeoRegion3D*)(m_Geometrys[nGeometry]);
						arrRegions.Add(pGeoRegion3D);
					}

					m_pRenderActor->DrawRegions(arrRegions);

					m_bInitial = true;
				}
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif