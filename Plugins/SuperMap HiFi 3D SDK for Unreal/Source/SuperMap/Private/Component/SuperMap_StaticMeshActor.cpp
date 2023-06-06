// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SuperMap_StaticMeshActor.h"
#include "Data/DataSource.h"
#include "Data/Dataset.h"
#include "Core/Layer3DDatasetModel.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Core;

ASuperMap_StaticMeshActor::ASuperMap_StaticMeshActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RealspaceDLL::LoadAllAPI();
	m_bSelected = false;
}

Gamebool ASuperMap_StaticMeshActor::ShouldTickIfViewportsOnly() const
{
	return true;
}

Gamevoid ASuperMap_StaticMeshActor::QueryAttritute()
{
	DataSource* pDataSource = new DataSource();
	pDataSource->Open(m_strDataSourceName);

	Dataset* pDataset = pDataSource->GetDataset(m_strDatasetName);
	Gameint nID = FCString::Atoi(*m_strSMID);
	// Ù–‘÷µ
	TArray<FString> strFileValue = pDataset->QueryAttributeById(nID);
	// Ù–‘◊÷∂Œ
	TArray<FieldInfo> arrFieldInfo;
	pDataset->GetFieldInfos(arrFieldInfo);

	for (Gameint n = 0; n < arrFieldInfo.Num(); n++)
	{
		AttributeQuery.Add(arrFieldInfo[n].m_strName,strFileValue[n]);
	}
	pDataSource->Close();
}

Gamevoid ASuperMap_StaticMeshActor::Tick(Gamefloat DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bSelected && GetWorld()->WorldType == EWorldType::PIE)
	{
		AttributeQuery.Empty();
		QueryAttritute();
		m_bSelected = false;
		return;
	}

#if WITH_EDITOR	
	if (IsSelectedInEditor() && AttributeQuery.Num() == 0)
	{
		QueryAttritute();
	}
	else if(!IsSelectedInEditor() && AttributeQuery.Num() > 0)
	{
		AttributeQuery.Empty();
	}
#endif
}

Gamevoid ASuperMap_StaticMeshActor::UDB_ModelSave()
{
	DataSource dataSource = DataSource();
	dataSource.Open(m_strDataSourceName);
	Dataset* pDataset = dataSource.GetDataset(m_strDatasetName);
	if (pDataset->GetType() == DatasetType::DT_Model)
	{
#if WITH_EDITOR
		Layer3DDatasetModel datasetMode;
		datasetMode.SetDataset(pDataset);
		datasetMode.SetWorld(GetWorld());
		datasetMode.ToJson();
#endif
	}
}