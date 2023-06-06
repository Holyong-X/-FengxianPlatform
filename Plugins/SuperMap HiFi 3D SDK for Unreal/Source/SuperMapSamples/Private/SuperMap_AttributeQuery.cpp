// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperMap_AttributeQuery.h"
#include "Core/SceneEditorWnd.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::ControlUE;
ASuperMap_AttributeQuery::ASuperMap_AttributeQuery()
{
	m_bSelectionInfos = false;
	m_pStaticMeshActor = nullptr;
	m_nLastId = -1;
	m_bIsSelected = true;
	m_bUseWeb = false;
	m_pSelectLayerHandle = nullptr;
	m_nSelectID = -1;
}

ASuperMap_AttributeQuery::~ASuperMap_AttributeQuery()
{
}

void ASuperMap_AttributeQuery::IsSelectionInfos(bool selectionInfos)
{
	m_bSelectionInfos = selectionInfos;
	if (m_bSelectionInfos)
	{
		AttributeSelectEvent QAEvent = CallbackFunc_AttributeQuery;
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->CallFunc_AttributeQuery(this, QAEvent);
	}
}

bool ASuperMap_AttributeQuery::IsGetSelectionInfos()
{
	return m_bIsSelected;
}

void ASuperMap_AttributeQuery::SetUseWeb(bool bUse)
{
	m_bUseWeb = bUse;
}

TArray<FAttributeInfos> ASuperMap_AttributeQuery::GetSelectionInfos()
{
	TArray<FAttributeInfos> attributeInfos;
	if (m_bSelectionInfos)
	{
		Gameint nID = m_nSelectID;
		if (nID == m_nLastId && !m_bUseWeb)
		{
			m_bIsSelected = true;
			return attributeInfos;
		}
		m_bIsSelected = false;
		m_nLastId = nID;
		if (attributeInfos.Num() > 0)
		{
			attributeInfos.Empty();
		}
		Layer3D* pLayer = (Layer3D*)m_pSelectLayerHandle;
		if (pLayer != nullptr && pLayer->Type() == Layer3DType::S3M)
		{
			Layer3DS3MFile* pLayerS3M = (Layer3DS3MFile*)pLayer;
			GetSelectionInfosFromS3MFile(pLayerS3M, nID, attributeInfos);
		}
		else if (pLayer != nullptr && pLayer->Type() == Layer3DType::DatasetModel)
		{
			Layer3DDatasetModel* pLayerDatasetModel = (Layer3DDatasetModel*)pLayer;
			GetSelectionInfosFromDatasetModel(pLayerDatasetModel, nID, attributeInfos);
		}
	}
	return attributeInfos;
}

TArray<FAttributeInfos> ASuperMap_AttributeQuery::GetSelectionInfosByID(FName strLayerName, int nID)
{
	TArray<FAttributeInfos> attributeInfos;
	if (m_bSelectionInfos)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName) != nullptr)
		{
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName)->Type() == S3M)
			{
				Layer3DS3MFile* pLayerS3M = (Layer3DS3MFile*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName);
				std::vector<FString> names = pLayerS3M->GetFieldInfos();
				std::vector<FString> values = pLayerS3M->GetAllFieldValues(nID);
				if (attributeInfos.Num() > 0)
				{
					attributeInfos.Empty();
				}
				for (int i = 0; i < values.size(); i++)
				{
					FAttributeInfos fileSelection;
					fileSelection.m_strFileInfo = names[i];
					fileSelection.m_strFileValue = values[i];
					attributeInfos.Emplace(fileSelection);
				}
				pLayerS3M = nullptr;
			}
		}
	}
	return attributeInfos;
}

bool ASuperMap_AttributeQuery::IsGetDatasetModelSelectionInfos()
{
	AActor* pSelection = RealspaceView::GetSingleton()->GetSelectedActor();
	if (pSelection == nullptr)
	{
		return false;
	}
	ASuperMap_StaticMeshActor* pStaticMeshActor = Cast<ASuperMap_StaticMeshActor>(pSelection);
	if (m_pStaticMeshActor == nullptr)
	{
		m_pStaticMeshActor = pStaticMeshActor;
		return true;
	}

	if (pStaticMeshActor->m_strSMID != "" && pStaticMeshActor->m_strSMID == m_pStaticMeshActor->m_strSMID)
	{
		return false;
	}
	else
	{
		m_pStaticMeshActor = pStaticMeshActor;
		return true;
	}
	return false;
}

TArray<FAttributeInfos> ASuperMap_AttributeQuery::GetDatasetModelSelectionInfos()
{
	TArray<FAttributeInfos> attributeInfos;
	if (m_bSelectionInfos)
	{
		DataSource* pDataSource = new DataSource();
		pDataSource->Open(m_pStaticMeshActor->m_strDataSourceName);

		Dataset* pDataset = pDataSource->GetDataset(m_pStaticMeshActor->m_strDatasetName);
		int32 nID = FCString::Atoi(*(m_pStaticMeshActor->m_strSMID));
		//属性值
		TArray<FString> strFileValue = pDataset->QueryAttributeById(nID);
		//属性字段
		TArray<FieldInfo> arrFieldInfo;
		pDataset->GetFieldInfos(arrFieldInfo);

		if (attributeInfos.Num() > 0)
		{
			attributeInfos.Empty();
		}

		for (int32 n = 0; n < arrFieldInfo.Num(); n++)
		{
			FAttributeInfos fileSelection;
			fileSelection.m_strFileInfo = arrFieldInfo[n].m_strName;
			fileSelection.m_strFileValue = strFileValue[n];
			attributeInfos.Emplace(fileSelection);
		}
		pDataSource->Close();
	}
	return attributeInfos;
}

void ASuperMap_AttributeQuery::GetSelectionInfosFromDatasetModel(Layer3DDatasetModel* pLayerDatasetModel, int nID, TArray<FAttributeInfos> & attributeInfos)
{
	Dataset* pDataset = pLayerDatasetModel->GetDataset();
	if (pDataset == nullptr)
	{
		return;
	}
	//属性值
	TArray<FString> strFileValue = pDataset->QueryAttributeById(nID);
	//属性字段
	TArray<FieldInfo> arrFieldInfo;
	pDataset->GetFieldInfos(arrFieldInfo);
	for (int32 i = 0; i < arrFieldInfo.Num(); i++)
	{
		FAttributeInfos fileSelection;
		fileSelection.m_strFileInfo = arrFieldInfo[i].m_strName;
		fileSelection.m_strFileValue = strFileValue[i];
		attributeInfos.Emplace(fileSelection);
	}
}

void ASuperMap_AttributeQuery::GetSelectionInfosFromS3MFile(Layer3DS3MFile* pLayerS3M, int nID, TArray<FAttributeInfos> & attributeInfos)
{
	std::vector<FString> names = pLayerS3M->GetFieldInfos(nID);
	std::vector<FString> values = pLayerS3M->GetAllFieldValues(nID);
	for (int i = 0; i < values.size(); i++)
	{
		FAttributeInfos fileSelection;
		fileSelection.m_strFileInfo = names[i];
		fileSelection.m_strFileValue = values[i];
		attributeInfos.Emplace(fileSelection);
	}
}

Gamebool ASuperMap_AttributeQuery::GetbSelectionInfos()
{
	return m_bSelectionInfos;
}

int ASuperMap_AttributeQuery::GetSelectionID()
{
	return m_nLastId;
}

void ASuperMap_AttributeQuery::ExecuteBroadcast()
{
	if (CallAttributeQuery.IsBound())
	{
		CallAttributeQuery.Broadcast();
	}
}

void ASuperMap_AttributeQuery::SetSelectInfo(void* pSelectLayerHandle, Gameint nSelectID)
{
	m_pSelectLayerHandle = pSelectLayerHandle;
	m_nSelectID = nSelectID;
}

void CallbackFunc_AttributeQuery(void* pActor, void* pSelectLayerHandle, Gameint nSelectID)
{
	if (pActor == nullptr)
	{
		return;
	}
	ASuperMap_AttributeQuery* pAttributeQuery = (ASuperMap_AttributeQuery*)pActor;
	pAttributeQuery->SetSelectInfo(pSelectLayerHandle, nSelectID);
	if (pAttributeQuery->GetbSelectionInfos())
	{
		pAttributeQuery->ExecuteBroadcast();
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif