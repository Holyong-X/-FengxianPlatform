// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneOperation/SuperMap_ObjectOperation.h"
#include "ControlUE/RealspaceView.h"

// Sets default values
ASuperMap_ObjectOperation::ASuperMap_ObjectOperation()
{
	PrimaryActorTick.bCanEverTick = true;
	m_StaticMeshActor = nullptr;
	m_vPosition = FVector(0, 0, 0);
}

ASuperMap_ObjectOperation::~ASuperMap_ObjectOperation()
{
	FName strAnalyst3DName = "ObjectOperation";
	std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find(strAnalyst3DName);
	if (itorMouseControl != m_mapMouseControl.end())
	{
		m_mapMouseControl.erase(strAnalyst3DName);
	}
}

void ASuperMap_ObjectOperation::BuildObjectOperation(bool bReplace)
{
	FName strAnalyst3DName = "ObjectOperation";
	if (bReplace)
	{
		m_mapMouseControl[strAnalyst3DName] = this;
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(Null);
	}
	else
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(PanSelect);
		std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find(strAnalyst3DName);
		if (itorMouseControl != m_mapMouseControl.end())
		{
			m_mapMouseControl.erase(strAnalyst3DName);
		}
	}
}

AStaticMeshActor* ASuperMap_ObjectOperation::GetStaticMeshActor()
{
	return m_StaticMeshActor;
}

void ASuperMap_ObjectOperation::MouseLeftButtonDown()
{
	FVector vMouse;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
	FHitResult hitResult;
	RealspaceView::GetSingleton()->GetCameraControl()->LineTrace(vMouse.X, vMouse.Y, hitResult);

	SelectedInfo materialInfo;
	materialInfo.m_pMatInstanceDynamic = nullptr;
	UPrimitiveComponent* pComponent = hitResult.GetComponent();

	if (pComponent != nullptr)
	{
		AActor* pActor = pComponent->GetOwner();
		if (pActor->ActorHasTag(TEXT("SUPERMAPSTATICMESH")))
		{
			m_StaticMeshActor = (AStaticMeshActor*)pActor;

			CallEvent.Broadcast();
		}
	}
}

void ASuperMap_ObjectOperation::MouseRightButtonDown()
{
	FVector vMouse;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
	Vector3d vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
	m_vPosition = vPos.ToFVector();
	CallGetPosition.Broadcast();
}

void ASuperMap_ObjectOperation::MouseRealTimeAnchor()
{

}

FVector ASuperMap_ObjectOperation::GetPosition()
{
	return m_vPosition;
}

void ASuperMap_ObjectOperation::ToJson()
{

}

void ASuperMap_ObjectOperation::FromJson()
{

}

void ASuperMap_ObjectOperation::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASuperMap_ObjectOperation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

