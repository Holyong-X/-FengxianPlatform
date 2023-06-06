#include "Core/Layer3DDatasetVectorPoint.h"
#include "Data/GeoPoint3D.h"
#include "Engine/World.h"
#include "Component/SuperMap_CustomVectorActor.h"
#include "ControlUE/CameraControl.h"
#include "Algorithm3D/MathEngine.h"
#include "Graphics3D/GameObjectManager.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Layer3DDatasetVectorPoint::Layer3DDatasetVectorPoint():Layer3DDatasetVector()
			{
			}

			Layer3DDatasetVectorPoint::Layer3DDatasetVectorPoint(FName strLayerName, Layer3DType eLayerType):
				Layer3DDatasetVector(strLayerName, eLayerType)
			{

			}

			Layer3DDatasetVectorPoint::~Layer3DDatasetVectorPoint()
			{
				
			}
			
			bool Layer3DDatasetVectorPoint::BuildStyle(UWorld* pWorld)
			{
				m_bInitial = true;
				if (m_pRenderActor)
				{
					m_pRenderActor->Flush();
				}

				if (!m_strAssetStyleField.IsEmpty())
				{
					TArray<FString> arrValues = m_pDataset->QueryField(m_strAssetStyleField);

					for (int32 i = 0; i < arrValues.Num(); i++)
					{
						FString strSql = m_strAssetStyleField + TEXT(" = \"") + arrValues[i] + TEXT("\"");

						TArray<Data::Geometry*> arrGeometrys = m_pDataset->QueryBySql(strSql);

						TArray<Vector3d> arrLocations;
						for (int32 nGeometry = 0; nGeometry < arrGeometrys.Num(); nGeometry++)
						{
							GeoPoint3D* pGeoPoint3D = (GeoPoint3D*)(arrGeometrys[nGeometry]);
							if (pGeoPoint3D == nullptr)
							{
								continue;
							}

							arrLocations.Add(pGeoPoint3D->GetPoint3D());
						}

						StyleParam styleParam;
						styleParam.m_strAssetResoureName = TEXT("img");
						styleParam.m_strAssetResourePath = arrValues[i];

						AssetStyle* pAssetStyle = new AssetStyle(pWorld);
						pAssetStyle->SetStyleParam(styleParam);


						m_bInitial = pAssetStyle->BuildStyle(arrLocations);
					}

					return true;
				}


				TMap<FString, AssetStyle*> mapAssetStyles = GetUEAssetStyle()->GetAssetStyles();
				if (mapAssetStyles.Num() > 0)
				{
					Gameint nSuccessCount = 0;
					for (auto It : mapAssetStyles)
					{
						FString string = It.Key;
						AssetStyle* pAssetStyle = It.Value;

						TArray<Data::Geometry*> arrGeometrys = m_pDataset->QueryBySql(string);
						
						TArray<Vector3d> arrLocations;
						for (int32 nGeometry = 0; nGeometry < arrGeometrys.Num(); nGeometry++)
						{
							GeoPoint3D* pGeoPoint3D = (GeoPoint3D*)(arrGeometrys[nGeometry]);
							if (pGeoPoint3D == nullptr)
							{
								continue;
							}

							arrLocations.Add(pGeoPoint3D->GetPoint3D());
						}

						if (pAssetStyle->BuildStyle(arrLocations))
						{
							nSuccessCount++;
						}
					}
					if (nSuccessCount > 0)
					{
						m_bInitial = true;
					}
					else
					{
						m_bInitial = false;
					}
					return true;
				}


				if (m_Geometrys.Num() == 0)
				{
					m_Geometrys = m_pDataset->Query();
				}
			
				if (m_Geometrys.Num() == 0 || m_pAssetStyle == nullptr)
				{
					m_bInitial = false;
					return false;
				}

				TArray<Vector3d> arrLocations;
				for (int32 nGeometry = 0 ; nGeometry < m_Geometrys.Num(); nGeometry++)
				{
					GeoPoint3D* pGeoPoint3D = (GeoPoint3D*)(m_Geometrys[nGeometry]);
					if (pGeoPoint3D == nullptr)
					{
						continue;
					}

					arrLocations.Add(pGeoPoint3D->GetPoint3D());
				}
				m_bInitial = m_pAssetStyle->BuildStyle(arrLocations);
				return m_bInitial;
			}

			DatasetType Layer3DDatasetVectorPoint::GetType()
			{
				return DatasetType::DT_POINT;
			}

			void Layer3DDatasetVectorPoint::Render(UWorld* pWorld)
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
					
					TArray<GeoPoint3D*> arrPoints;
					for (int32 nGeometry = 0; nGeometry < m_Geometrys.Num(); nGeometry++)
					{
						GeoPoint3D* pGeoPoint3D = (GeoPoint3D*)(m_Geometrys[nGeometry]);
						arrPoints.Add(pGeoPoint3D);
					}

					m_pRenderActor->DrawPoints(arrPoints);

					m_bInitial = true;
				}
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif