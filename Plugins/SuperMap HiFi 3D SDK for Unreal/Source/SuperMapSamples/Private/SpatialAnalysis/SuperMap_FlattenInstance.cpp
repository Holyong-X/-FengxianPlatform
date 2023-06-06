// Fill out your copyright notice in the Description page of Project Settings.

#include "SpatialAnalysis/SuperMap_FlattenInstance.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK;

// Sets default values
ASuperMap_FlattenInstance::ASuperMap_FlattenInstance()
{
	m_nMouseLeftDown   = 0;
	m_bFlatten         = false;
	m_bButtonRightDown = false;
	m_pLayer3DS3MFile = nullptr;
	m_bWithoutWeb = true;
}

ASuperMap_FlattenInstance::~ASuperMap_FlattenInstance()
{

}

void ASuperMap_FlattenInstance::SetIsFlatten(bool bflatten, FName strLayerName)
{
	m_bFlatten = bflatten;
	if (bflatten)
	{
		Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName);
		if (pLayer3D == nullptr || pLayer3D->Type() != Layer3DType::S3M)
		{
			m_bFlatten = false;
			return;
		}
		if (m_listPosition.Num() > 0)
		{
			m_listPosition.Empty();
		}
		if (m_listDrawPosition.Num() > 0)
		{
			m_listDrawPosition.Empty();
		}
		if (m_pLayer3DS3MFile != nullptr)
		{
			m_pLayer3DS3MFile->ClearFlattenRegion();

			m_pLayer3DS3MFile = nullptr;

			m_pGeoRegion3D = nullptr;

			m_pROEntityActor->Destroy(false, false);
			m_pROEntityActor = nullptr;
		}

		m_nMouseLeftDown = 0;
		FName strInstanceName = "Flatten";
		m_mapMouseControl[strInstanceName] = this;

		m_pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
		m_pGeoRegion3D = new SuperMapSDK::UnrealEngine::Data::GeoRegion3D();
		m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
		m_bButtonRightDown = false;
	}
	else if (!bflatten)
	{
		if (m_pLayer3DS3MFile != nullptr)
		{
			m_pLayer3DS3MFile->ClearFlattenRegion();

			m_pLayer3DS3MFile = nullptr;

			m_pGeoRegion3D = nullptr;

			m_pROEntityActor->Destroy(false, false);
			m_pROEntityActor = nullptr;

			m_bButtonRightDown = false;
		}
		std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find("Flatten");
		if (itorMouseControl != m_mapMouseControl.end())
		{
			m_mapMouseControl.erase(itorMouseControl->first);
		}
	}
}

void ASuperMap_FlattenInstance::MouseLeftButtonDown()
{
	if (m_bFlatten && !m_bButtonRightDown && m_bWithoutWeb)
	{
		m_nMouseLeftDown++;
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos,vDrawPos;
		vDrawPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
		{
			vPos = vDrawPos +FVector(GetWorld()->OriginLocation);
			vPos = vPos.ToUGCVector();
		}
		else
		{
			vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
		}
		m_listPosition.Add(vPos);
		m_listDrawPosition.Add(vDrawPos.ToFVector());
	}
}

void ASuperMap_FlattenInstance::MouseRightButtonDown()
{
	if (m_bFlatten && !m_bButtonRightDown && m_nMouseLeftDown > 2 && m_bWithoutWeb)
	{
		m_listPosition.RemoveAt(m_listPosition.Num() - 1);
		m_listDrawPosition.RemoveAt(m_listDrawPosition.Num() - 1);
		m_pGeoRegion3D->SetPoints(m_listPosition);
		m_pLayer3DS3MFile->AddFlattenRegion(m_pGeoRegion3D,TEXT("Flatten"));
		DrawFlatten();
		m_bButtonRightDown = true;
	}
}

void ASuperMap_FlattenInstance::SetUseWeb(bool bUseWithoutWeb)
{
	m_bWithoutWeb = bUseWithoutWeb;
}

void ASuperMap_FlattenInstance::AddFlattenRegion(TArray<FVector> arrPos, FString Tag)
{
	if (m_bFlatten)
	{
		TArray<Vector3d> arrvPos;
		for (Gameint i = 0; i < arrPos.Num(); i++)
		{
			arrvPos.Add(Vector3d(arrPos[i]));
		}
		m_pGeoRegion3D->SetPoints(arrvPos);
		m_pLayer3DS3MFile->AddFlattenRegion(m_pGeoRegion3D, Tag);
	}
}

TArray<FVector> ASuperMap_FlattenInstance::GetJsonArrayStringValue(FString Descriptor, FString FieldName)
{
	TArray<FVector> arrVPos;
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Descriptor);

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
	{
		TSharedPtr<FJsonValue> arguments = JsonObject->TryGetField(TEXT("arguments"));
		if (arguments.IsValid())
		{
			TSharedPtr<FJsonValue> geometry = arguments->AsObject()->TryGetField(TEXT("geometry"));
			if (geometry.IsValid())
			{
				const TArray<TSharedPtr<FJsonValue>>* arrValue;
				if (geometry->AsObject()->TryGetArrayField(FieldName, arrValue))
				{
					FVector vPos;
					for (int i = 0; i < (*arrValue).Num(); i++)
					{

						FString str_x = (*arrValue)[i]->AsObject()->GetStringField(TEXT("x"));
						vPos.X = FCString::Atof(*str_x);
						FString str_y = (*arrValue)[i]->AsObject()->GetStringField(TEXT("y"));
						vPos.Y = FCString::Atof(*str_y);
						FString str_z = (*arrValue)[i]->AsObject()->GetStringField(TEXT("z"));
						vPos.Z = FCString::Atof(*str_z);
						arrVPos.Emplace(vPos);
					}
				}
			}
		}
	}
	return arrVPos;
}

void ASuperMap_FlattenInstance::MouseRealTimeAnchor()
{
	if (m_bFlatten && !m_bButtonRightDown && m_nMouseLeftDown > 0 && m_bWithoutWeb)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos,vDrawPos;
		vDrawPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
		{
			vPos = vDrawPos +FVector(GetWorld()->OriginLocation);
			vPos = vPos.ToUGCVector();
		}
		else
		{
			vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
		}
		if (m_listPosition.Num() <= m_nMouseLeftDown)
		{
			m_listPosition.Add(vPos);
			m_listDrawPosition.Add(vDrawPos.ToFVector());
		}
		if (m_listPosition.Num() > 0)
		{
			m_listPosition[m_listPosition.Num() - 1] = vPos;
			m_listDrawPosition[m_listDrawPosition.Num() - 1] = vDrawPos.ToFVector();
		}
		DrawFlatten();
	}
}

void ASuperMap_FlattenInstance::DrawFlatten()
{
	TArray<SM_Vertex> arrVtxs;//顶点
	for (Gameint i = 0; i < m_listDrawPosition.Num(); i++)
	{
		SM_Vertex point;
		point.Position = m_listDrawPosition[i];
		point.Color = FColor::Yellow;
		arrVtxs.Add(point);
	}
	
	TArray<SM_SubMesh> arrSubMeshs;//mesh
	SM_SubMesh subMesh;
	
	if (m_pROEntityActor->GetMaterial() == nullptr)
	{
		static UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		subMesh.m_pMaterialInterface = pMat;
		m_pROEntityActor->SetMaterial(pMat);
	}
	
	TArray<Gameint> arrIndexs;//索引
	
	for (Gameint j = 0; j < m_listDrawPosition.Num() - 1; j++)
	{
		arrIndexs.Add(j);
		arrIndexs.Add(j + 1);
	}
	arrIndexs.Add(m_listDrawPosition.Num() - 1);
	arrIndexs.Add(0);
	
	subMesh.IndexBuffer = arrIndexs;
	arrSubMeshs.Add(subMesh);
	
	m_pROEntityActor->SetDrawType(2);//0三角、2线
	m_pROEntityActor->CreateLineMeshComponent(arrVtxs, arrSubMeshs);
}