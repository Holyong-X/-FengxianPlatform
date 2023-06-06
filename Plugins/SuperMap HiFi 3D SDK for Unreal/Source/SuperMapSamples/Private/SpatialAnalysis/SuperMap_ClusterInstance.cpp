
#include "SpatialAnalysis/SuperMap_ClusterInstance.h"
#include "Data/GeoPoint3D.h"
#include "Algorithm3D/MathEngine.h"
PRAGMA_DISABLE_OPTIMIZATION
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
ASuperMap_ClusterInstance::ASuperMap_ClusterInstance()
{
	PrimaryActorTick.bCanEverTick = true;
	m_bCluster = false;
	m_arrLayer3DDatasetVector.Empty();
	m_mapLayerArrPoints.Empty();
}

ASuperMap_ClusterInstance::~ASuperMap_ClusterInstance()
{
	m_bCluster = false;
	m_mapClusteredEntities.Empty();
	m_arrLayer3DDatasetVector.Empty();
	m_mapLayerArrPoints.Empty();
}

void ASuperMap_ClusterInstance::Cluster_Build()
{
	if (m_bCluster)
	{
		m_strAnalyst3DName = "Cluster";
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			delete pAnalyst3D;
			mapAnalyst.erase(m_strAnalyst3DName);
		}
		Cluster* pCluster = new Cluster(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
		mapAnalyst[m_strAnalyst3DName] = pCluster;
		pCluster->SetClusterEventFunc(this, OnClusterEventCallBack);
	}
	else if(!m_bCluster && m_strAnalyst3DName == "Cluster")
	{
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			pAnalyst3D->Clear();
			delete pAnalyst3D;
			pAnalyst3D = NULL;
			mapAnalyst.erase(m_strAnalyst3DName);
		}
		m_strAnalyst3DName = FName();

		for (int i = 0; i < m_arrLayer3DDatasetVector.Num(); i++)
		{
			m_arrLayer3DDatasetVector[i]->SetIsVisible(true);
		}
		m_arrLayer3DDatasetVector.Empty();
		CallGetScreenPos.Broadcast();
	}
}

TArray<FVector2D> ASuperMap_ClusterInstance::Cluster_GetScreenPosition(FString path)
{
	TArray<FVector2D> result;
	if (m_mapClusteredEntities.Contains(path))
	{
		for (int i = 0; i < m_mapClusteredEntities[path].Num(); i++)
		{
			result.Add(m_mapClusteredEntities[path][i].m_vScreenPosition);
		}
	}
	return result;
}

void ASuperMap_ClusterInstance::Cluster_SetGeoPosition()
{
	if (m_bCluster)
	{
		TMap<FString, TArray<Vector3d>> mapArrPos;
		for (TMap<FString, TMap<FString, TArray<Vector3d>>>::TConstIterator itor1 = m_mapLayerArrPoints.CreateConstIterator(); itor1; ++itor1)
		{
			TMap<FString, TArray<Vector3d>> mapPos = itor1->Value;
			for (TMap<FString, TArray<Vector3d>>::TConstIterator itor2 = mapPos.CreateConstIterator(); itor2; ++itor2)
			{
				mapArrPos.Add(itor2->Key, itor2->Value);
			}
		}
		Cluster* pCluster = (Cluster*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pCluster->SetGeoPositions(mapArrPos);
	}
}

TArray<FString> ASuperMap_ClusterInstance::GetRelatedLabelPath()
{
	TArray<FString> arrPath;
	for (TMap<FString, TArray<ClusteredEntities>>::TConstIterator itor = m_mapClusteredEntities.CreateConstIterator(); itor; ++itor)
	{
		arrPath.Add(itor->Key);
	}
	return arrPath;
}

void ASuperMap_ClusterInstance::Cluster_SetPixelRange(int pixelRange)
{
	if (m_bCluster)
	{
		Cluster* pCluster = (Cluster*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pCluster->SetPixelRange(pixelRange);
	}
}

int ASuperMap_ClusterInstance::Cluster_GetPixelRange()
{
	if (m_bCluster)
	{
		Cluster* pCluster = (Cluster*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		return pCluster->GetPixelRange();
	}
	return 80;
}

void ASuperMap_ClusterInstance::SetClusterEnable(bool bEnble)
{
	if (m_bCluster)
	{
		Cluster* pCluster = (Cluster*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pCluster->IsEnable(bEnble);
	}
}

bool ASuperMap_ClusterInstance::GetClusterEnable()
{
	if (m_bCluster)
	{
		Cluster* pCluster = (Cluster*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		return pCluster->GetIsEnable();
	}
	return true;
}

void ASuperMap_ClusterInstance::SetMinimumClusterSize(int minimumClusterSize)
{
	if (m_bCluster)
	{
		Cluster* pCluster = (Cluster*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pCluster->SetMinimumClusterSize(minimumClusterSize);
	}
}

int ASuperMap_ClusterInstance::GetMinimumClusterSize()
{
	if (m_bCluster)
	{
		Cluster* pCluster = (Cluster*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		return pCluster->GetMinimumClusterSize();
	}
	return 3;
}

void ASuperMap_ClusterInstance::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASuperMap_ClusterInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void OnClusterEventCallBack(void* pActor, TMap<FString, TArray<ClusteredEntities>> info)
{
	ASuperMap_ClusterInstance* pClusterActor = (ASuperMap_ClusterInstance*)pActor;
	pClusterActor->m_mapClusteredEntities = info;
	pClusterActor->CallGetScreenPos.Broadcast();
}

void ASuperMap_ClusterInstance::QueryPointBySql(FString LayerName, FString dataset, FString styleField, TArray<FString> strSql, TArray<FString> strPath)
{
	if (m_mapLayerArrPoints.Contains(LayerName))
	{
		m_mapLayerArrPoints.Remove(LayerName);
	}
	FString leftS, rightS;
	dataset.Split("@", &leftS, &rightS);
	DataSource dataSource = SuperMapSDK::UnrealEngine::Data::DataSource();
	Gamebool result = dataSource.Open(rightS);
	if (result)
	{
		Dataset* pDataset = dataSource.GetDataset(leftS);
		if (pDataset->GetType() != DT_POINT)
		{
			dataSource.Close();
			return;
		}
		for (int i = 0; i < strSql.Num(); i++)
		{
			FString sql = styleField + TEXT(" = \"") + strSql[i] + TEXT("\"");
			TArray<Geometry*> geometrys = pDataset->QueryBySql(sql);
			TArray<Vector3d> posv3d;
			for (int j = 0; j < geometrys.Num(); j++)
			{
				GeoPoint3D* pGeoPoint3D = (GeoPoint3D*)(geometrys[j]);
				if (pGeoPoint3D != nullptr)
				{
					Vector3d vPos = pGeoPoint3D->GetPosition();
					posv3d.Add(vPos);
				}
			}
			m_mapPoints.Add(strPath[i], posv3d);
		}
		Layer3DDatasetVectorPoint* pLayer3DDatasetVectorPoint = (Layer3DDatasetVectorPoint*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(LayerName));
		pLayer3DDatasetVectorPoint->SetIsVisible(false);
		m_mapLayerArrPoints.Add(LayerName, m_mapPoints);
		if (!m_bCluster)
		{
			m_bCluster = true;
			Cluster_Build();
		}
	}
}

void ASuperMap_ClusterInstance::RemoveLayer(FString LayerName)
{
	if (m_mapLayerArrPoints.Contains(LayerName))
	{
		m_mapLayerArrPoints.Remove(LayerName);
		Layer3DDatasetVectorPoint* pLayer3DDatasetVectorPoint = (Layer3DDatasetVectorPoint*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(LayerName));
		pLayer3DDatasetVectorPoint->SetIsVisible(true);
	}
	if (m_mapLayerArrPoints.Num() == 0)
	{
		m_bCluster = false;
		Cluster_Build();
	}
}

PRAGMA_ENABLE_OPTIMIZATION