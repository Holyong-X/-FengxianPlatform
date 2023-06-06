#include "SpatialAnalyst3D/Cluster.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameRenderTexture.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/ROCache.h"
#include "Component/SuperMap_MeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Algorithm3D/KdTree.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst3D
		{
			Cluster::Cluster(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl) : Analyst3D(pWorld, pScene, pCameraControl)
			{
				m_bEnable = true;
				m_eAnalyzeMode = Core::Cluster_Analyze;
				m_vlastCameraLocation = FVector(0, 0, 0);
				m_vlastCameraRotator = FRotator(0, 0, 0);
				m_nPixelRange = 80;
				m_nMinimumClusterSize = 3;
			}

			Cluster::~Cluster()
			{
				Release();
			}

			void Cluster::SetPixelRange(Gameint pixelRange)
			{
				m_nPixelRange = pixelRange;
			}

			Gameint Cluster::GetPixelRange()
			{
				return m_nPixelRange;
			}

			void Cluster::SetMinimumClusterSize(Gameint minimumClusterSize)
			{
				m_nMinimumClusterSize = minimumClusterSize;
			}

			Gameint Cluster::GetMinimumClusterSize()
			{
				return m_nMinimumClusterSize;
			}

			void Cluster::IsEnable(Gamebool bEnable)
			{
				m_bEnable = bEnable;
			}

			Gamebool Cluster::GetIsEnable()
			{
				return m_bEnable;
			}
			void Cluster::SetGeoPositions(const TMap<FString, TArray<Vector3d>>& mapGeoPos)
			{
				if (m_mapGeoPositions.Num() > 0)
				{
					m_mapGeoPositions.Empty();
				}
				m_mapGeoPositions = mapGeoPos;
			}

			void Cluster::DoBuild()
			{
				
			}

			void Cluster::DoClear()
			{

			}

			void Cluster::Render()
			{
				FVector vCameraLocation;
				FRotator vCameraRotator;
				m_pCameraControl->GetCameraLocationAndRotation(vCameraLocation, vCameraRotator);
				if(m_vlastCameraLocation == vCameraLocation && m_vlastCameraRotator == vCameraRotator)
				{
					return;
				}
				m_vlastCameraLocation = vCameraLocation;
				m_vlastCameraRotator = vCameraRotator;
				DoCluster();
			}

			void Cluster::DoCluster()
			{
				if (m_mapGeoPositions.Num() == 0)
				{
					return;
				}
				m_mapClusteredEntities.Empty();
				TArray<Vector3d> kdTreeV3d;
				TArray<ClusteredEntity> clusteredEntity;
				TArray<Gameint> layerPointCount;
				TArray<FString> strPaths;
				Gameint nLayerPointCount = 0;
				for (auto& item : m_mapGeoPositions)
				{
					for (Gameint i = 0; i < item.Value.Num(); i++)
					{
						Vector3d globePos = item.Value[i];
						ClusteredEntity entity;
						if (GetScreenSpacePosition(globePos, entity))
						{
							nLayerPointCount++;
							entity.m_nIndex = i;
							clusteredEntity.Add(entity);
							kdTreeV3d.Add(Vector3d(entity.m_vScreenPosition.X, entity.m_vScreenPosition.Y, 0));
						}
					}
					layerPointCount.Add(nLayerPointCount);
					strPaths.Add(item.Key);
				}
				TMap<Gameint, ClusteredEntities> arrClusteredEntities;
				if (!m_bEnable)
				{
					// 不聚类情况，后续支持自定义专题图的话替换掉
					for (int enty = 0; enty < clusteredEntity.Num(); enty++)
					{
						ClusteredEntities collection;
						collection.m_vScreenPosition = clusteredEntity[enty].m_vScreenPosition;
						collection.m_vUnrealWorldPosition = clusteredEntity[enty].m_vUnrealWorldPosition;
						collection.m_Entities.Add(clusteredEntity[enty]);
						arrClusteredEntities.Add(enty, collection);
					}
				}
				else
				{
					KdTree kdTree = KdTree(kdTreeV3d);
					for (int j = 0; j < clusteredEntity.Num(); j++)
					{
						if (clusteredEntity[j].m_bCluster)
						{
							continue;
						}
						ClusteredEntities collection;
						collection.m_vScreenPosition = clusteredEntity[j].m_vScreenPosition;
						collection.m_vUnrealWorldPosition = clusteredEntity[j].m_vUnrealWorldPosition;
						Vector3d screenPos = kdTreeV3d[j];
						Gameint nPointSearch;
						TArray<Gameint> nIndexArray;
						TArray<Gamedouble> dDistanceArray;
						kdTree.SearchKdTreeDis(screenPos, m_nPixelRange, nPointSearch, nIndexArray, dDistanceArray);
						if (nIndexArray.Num() <= m_nMinimumClusterSize)
						{
							continue;
						}
						clusteredEntity[j].m_bCluster = true;
						for (int index = 0; index < nIndexArray.Num(); index++)
						{
							clusteredEntity[nIndexArray[index]].m_bCluster = true;
							collection.m_Entities.Add(clusteredEntity[index]);
						}
						arrClusteredEntities.Add(j, collection);
					}
					for (int n = 0; n < clusteredEntity.Num(); n++)
					{
						if (clusteredEntity[n].m_bCluster)
						{
							continue;
						}
						ClusteredEntities collection;
						collection.m_vScreenPosition = clusteredEntity[n].m_vScreenPosition;
						collection.m_vUnrealWorldPosition = clusteredEntity[n].m_vUnrealWorldPosition;
						clusteredEntity[n].m_bCluster = true;
						collection.m_Entities.Add(clusteredEntity[n]);
						arrClusteredEntities.Add(n, collection);
					}
				}
				
				for (int pathIndex = 0; pathIndex < strPaths.Num(); pathIndex++)
				{
					TArray<ClusteredEntities> clusEntities;
					for (TMap<Gameint, ClusteredEntities>::TConstIterator itor = arrClusteredEntities.CreateConstIterator(); itor; ++itor)
					{
						if (itor->Key < layerPointCount[pathIndex])
						{
							clusEntities.Add(itor->Value);
							arrClusteredEntities.Remove(itor->Key);
						}
					}
					m_mapClusteredEntities.Add(strPaths[pathIndex], clusEntities);
				}
				m_ClusterEvent.Event(m_ClusterEvent.m_pActor, m_mapClusteredEntities);
			}

			//! \brief 释放
			void Cluster::Release()
			{
				if (m_mapGeoPositions.Num() > 0)
				{
					m_mapGeoPositions.Empty();
				}
			}

			Gamebool Cluster::GetScreenSpacePosition(Vector3d& geoPos, ClusteredEntity& clusteredEntity)
			{
				Gamebool bVaild = false;
				FVector worldPos = geoPos.ToFVector();
				if (m_pScene->GetSceneType() == SceneType::Globe || m_pScene->GetSceneType() == SceneType::Ellipsoid_WGS84)
				{
					FTransform trans = m_pScene->LongitudeLatitudeToUE(worldPos, false);
					worldPos = trans.GetLocation();
				}
				FVector2D ScreenLocation = FVector2D(-1, -1);
				APlayerController* pPlayerController = m_pWorld->GetFirstPlayerController();
				UGameplayStatics::ProjectWorldToScreen(pPlayerController, worldPos, ScreenLocation, false);
				Gameint nWidth = m_pWorld->GetGameViewport()->Viewport->GetSizeXY().X;
				Gameint nHeight = m_pWorld->GetGameViewport()->Viewport->GetSizeXY().Y;
				if(ScreenLocation.X > 0 && ScreenLocation.X < nWidth && ScreenLocation.Y > 0 && ScreenLocation.Y < nHeight)
				{
					bVaild = true;
				}
				clusteredEntity.m_bCluster = false;
				clusteredEntity.m_vScreenPosition = ScreenLocation;
				clusteredEntity.m_vUnrealWorldPosition = worldPos;
				return bVaild;
			}

			void Cluster::SetClusterEventFunc(void* pActor, ClusterEvent infoEvent)
			{
				m_ClusterEvent.m_pActor = pActor;
				m_ClusterEvent.Event = infoEvent;
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif