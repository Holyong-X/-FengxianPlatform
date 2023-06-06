// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SuperMap_GeoreferenceComponent.h"
#include "Engine/World.h"
#include "Core/Scene.h"
#include "Base3D/CommonDefine.h"
#include "ControlUE/RealspaceView.h"
#include "Core/Georeference.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
USuperMap_GeoreferenceComponent::USuperMap_GeoreferenceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	Longitude = 0.0;
	Latitude = 0.0;
	Height = 0.0;

	m_dOriginLongitude = 0.0;
	m_dOriginLatitude = 0.0;
	m_dOriginHeight = 0.0;
	m_vLastGeoreferenceOrigin.X = Georeference::m_dLongitude;
	m_vLastGeoreferenceOrigin.Y = Georeference::m_dLatitude;
	m_vLastGeoreferenceOrigin.Z = Georeference::m_dAltitude;
}

Gamevoid USuperMap_GeoreferenceComponent::LongitudeLatitudeToUE()
{
	FVector vPosition = FVector(Longitude, Latitude, Height);
	FTransform transform;
	transform = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->LongitudeLatitudeToUE(vPosition);
	FVector location = transform.GetLocation();
	FQuat rotation = transform.GetRotation();
	this->SetRelativeLocation(FVector(0, 0, 0));
	this->GetAttachParent()->SetRelativeLocation(location);
	this->GetAttachParent()->SetRelativeRotation(rotation);
}

void USuperMap_GeoreferenceComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USuperMap_GeoreferenceComponent::TickComponent(Gamefloat DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (Longitude != m_dOriginLongitude
		|| Latitude != m_dOriginLatitude
		|| Height != m_dOriginHeight
		|| Georeference::m_dLongitude != m_vLastGeoreferenceOrigin.X
		|| Georeference::m_dLatitude != m_vLastGeoreferenceOrigin.Y
		|| Georeference::m_dAltitude != m_vLastGeoreferenceOrigin.Z)
	{
		LongitudeLatitudeToUE();
		m_dOriginLongitude = Longitude;
		m_dOriginLatitude = Latitude;
		m_dOriginHeight = Height;
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif
