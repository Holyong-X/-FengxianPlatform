#include "Core/Layer3DDatasetVectorLine.h"
#include "Data/GeoLine3D.h"
#include "UObject/ConstructorHelpers.h"
#include "Algorithm3D/MathEngine.h"
#include "ControlUE/CameraControl.h"
#include "Base3D/CommonDefine.h"
#include "Core/ROCacheManager.h"
#include "Graphics3D/GameObjectManager.h"
#include "Component/SuperMap_CustomVectorActor.h"

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::ControlUE;
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
			Layer3DDatasetVectorLine::Layer3DDatasetVectorLine() :Layer3DDatasetVector()
			{
			}

			Layer3DDatasetVectorLine::Layer3DDatasetVectorLine(FName strLayerName, Layer3DType eLayerType):
				Layer3DDatasetVector(strLayerName, eLayerType)
			{

			}

			Layer3DDatasetVectorLine::~Layer3DDatasetVectorLine()
			{
				
			}
			
			bool Layer3DDatasetVectorLine::BuildStyle(UWorld* pWorld)
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

						TArray<FVector> arrLocations;
						for (int32 nGeometry = 0; nGeometry < arrGeometrys.Num(); nGeometry++)
						{
							GeoLine3D* pGeoLine3D = (GeoLine3D*)(arrGeometrys[nGeometry]);
							if (pGeoLine3D == nullptr)
							{
								continue;
							}

							pGeoLine3D->GetSubdivisionPoints(arrLocations, 10.0);
						}

						StyleParam styleParam;
						styleParam.m_strAssetResoureName = TEXT("img");
						styleParam.m_strAssetResourePath = arrValues[i];

						AssetStyle* pAssetStyle = new AssetStyle(pWorld);
						pAssetStyle->SetStyleParam(styleParam);


						pAssetStyle->BuildSubdivisionStyle(arrLocations);
					}

					return true;
				}

				TMap<FString, AssetStyle*> mapAssetStyles = GetUEAssetStyle()->GetAssetStyles();
				if (mapAssetStyles.Num() > 0)
				{
					
					for (auto It : mapAssetStyles)
					{
						
						FString string = It.Key;
						AssetStyle* pAssetStyle = It.Value;

						TArray<Data::Geometry*> arrGeometrys = m_pDataset->QueryBySql(string);

						if (GetUEAssetStyle()->GetMode() == UEAssetStyle::Mode::ASSET_LOFT)
						{
							TArray<TArray<Vector3d>> pts;
							for (int i = 0; i < arrGeometrys.Num(); i++)
							{
								TArray<Vector3d> linePoints;
								GeoLine3D* pGeoLine3D = (GeoLine3D*)(arrGeometrys[i]);
								pGeoLine3D->GetPoints(linePoints);
								pts.Add(linePoints);
							}
							pAssetStyle->BuildStyle(pts);
						}
						else
						{
							TArray<FVector> arrLocations;
							for (int32 nGeometry = 0; nGeometry < arrGeometrys.Num(); nGeometry++)
							{
								GeoLine3D* pGeoLine3D = (GeoLine3D*)(arrGeometrys[nGeometry]);
								if (pGeoLine3D == nullptr)
								{
									continue;
								}

								pGeoLine3D->GetSubdivisionPoints(arrLocations, pAssetStyle->GetStyleParam().m_fDistance);
							}

							pAssetStyle->BuildSubdivisionStyle(arrLocations);
						}
					}
					return true;
				}


				if (m_Geometrys.Num() == 0)
				{
					m_Geometrys = m_pDataset->Query();
				}
			
				if (m_Geometrys.Num() == 0 || m_pAssetStyle == nullptr)
				{
					return false;
				}

				TArray<FVector> arrLocations;
				for (int32 nGeometry = 0 ; nGeometry < m_Geometrys.Num(); nGeometry++)
				{
					GeoLine3D* pGeoLine3D = (GeoLine3D*)(m_Geometrys[nGeometry]);
					if (pGeoLine3D == nullptr)
					{
						continue;
					}

					pGeoLine3D->GetSubdivisionPoints(arrLocations, m_pAssetStyle->GetStyleParam().m_fDistance);
				}

				return m_pAssetStyle->BuildSubdivisionStyle(arrLocations);
			}

			DatasetType Layer3DDatasetVectorLine::GetType()
			{
				return DatasetType::DT_LINE;
			}

			void Layer3DDatasetVectorLine::Render(UWorld* pWorld)
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

					TArray<GeoLine3D*> arrLines;
					for (int32 nGeometry = 0; nGeometry < m_Geometrys.Num(); nGeometry++)
					{
						GeoLine3D* pGeoLine3D = (GeoLine3D*)(m_Geometrys[nGeometry]);
						arrLines.Add(pGeoLine3D);
					}

					m_pRenderActor->DrawLines(arrLines);

					m_bInitial = true;
				}
			}
		}
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif