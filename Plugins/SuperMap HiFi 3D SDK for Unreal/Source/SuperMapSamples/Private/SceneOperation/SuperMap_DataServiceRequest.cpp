// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneOperation/SuperMap_DataServiceRequest.h"

ASuperMap_DataServiceRequest::ASuperMap_DataServiceRequest()
{
 	PrimaryActorTick.bCanEverTick = true;
	m_pDataServiceRequest = nullptr;
	m_bDataServiceRequest = false;
}

ASuperMap_DataServiceRequest::~ASuperMap_DataServiceRequest()
{
	if (m_pDataServiceRequest != nullptr)
	{
		delete m_pDataServiceRequest;
		m_pDataServiceRequest = nullptr;
	}
}

void ASuperMap_DataServiceRequest::BuildDataServiceRequest(bool bDataServiceRequest)
{
	m_bDataServiceRequest = bDataServiceRequest;
	if (m_pDataServiceRequest != nullptr)
	{
		delete m_pDataServiceRequest;
		m_pDataServiceRequest = nullptr;
	}
	if (m_bDataServiceRequest)
	{
		m_mapMouseControl["DataServiceRequest"] = this;
		m_pDataServiceRequest = new DataServiceRequest();
		m_pDataServiceRequest->CallFunc_DataServiceRequest(this, CallbackFunc_DataServiceRequest);
	}
	else if(!m_bDataServiceRequest)
	{
		std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find("DataServiceRequest");
		if (itorMouseControl != m_mapMouseControl.end())
		{
			m_mapMouseControl.erase(itorMouseControl->first);
		}
	}
}

void ASuperMap_DataServiceRequest::SetBottomAltitudeFiledName(FString strBottomAltitude)
{
	if (strBottomAltitude.IsEmpty())
	{
		return;
	}
	if (m_bDataServiceRequest)
	{
		m_pDataServiceRequest->SetBottomAltitudeFiledName(strBottomAltitude);
	}
}

void ASuperMap_DataServiceRequest::SetExtendHeightFiledName(FString strExtendHeight)
{
	if (strExtendHeight.IsEmpty())
	{
		return;
	}
	if (m_bDataServiceRequest)
	{
		m_pDataServiceRequest->SetExtendHeightFiledName(strExtendHeight);
	}
}

void ASuperMap_DataServiceRequest::SetIServiceData(FString strUrlServer, FString strDataSourceName, FString strDatasetName)
{
	if (strUrlServer.IsEmpty() || strDataSourceName.IsEmpty() || strDatasetName.IsEmpty())
	{
		return;
	}
	if (m_bDataServiceRequest)
	{
		m_pDataServiceRequest->SetIServiceData(strUrlServer, strDataSourceName, strDatasetName);
	}
}

TArray<FDataServiceRequestInfos> ASuperMap_DataServiceRequest::GetSelectAttribute()
{
	TArray<FDataServiceRequestInfos> result;
	if (m_bDataServiceRequest)
	{
		TMap<FString, FString> mapAttribute = m_pDataServiceRequest->GetSelectAttribute();
		for (TMap<FString, FString>::TConstIterator itorAttribute = mapAttribute.CreateConstIterator(); itorAttribute; ++itorAttribute)
		{
			FDataServiceRequestInfos attribute;
			attribute.m_strFileInfo = itorAttribute->Key;
			attribute.m_strFileValue = itorAttribute->Value;
			result.Add(attribute);
		}
	}
	return result;
}

void ASuperMap_DataServiceRequest::MouseLeftButtonDown()
{
	if (m_bDataServiceRequest)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		m_pDataServiceRequest->SelecteServiceRequest(vMouse);
	}
}

void ASuperMap_DataServiceRequest::MouseRightButtonDown()
{

}

void ASuperMap_DataServiceRequest::MouseRealTimeAnchor()
{

}

void ASuperMap_DataServiceRequest::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASuperMap_DataServiceRequest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASuperMap_DataServiceRequest::ExecuteBroadcast()
{
	if (CallDataServiceRequest.IsBound())
	{
		CallDataServiceRequest.Broadcast();
	}
}

void CallbackFunc_DataServiceRequest(void* pActor)
{
	if (pActor == nullptr)
	{
		return;
	}
	ASuperMap_DataServiceRequest* DSActor = (ASuperMap_DataServiceRequest*)pActor;
	DSActor->ExecuteBroadcast();
}

