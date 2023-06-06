// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SuperMap_TextActor.h"

// Sets default values
ASuperMap_TextActor::ASuperMap_TextActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRender"));
	m_TextRender->SetHorizontalAlignment(EHTA_Left);
	
	m_bSetParam = false;
}

// Called when the game starts or when spawned
Gamevoid ASuperMap_TextActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
Gamevoid ASuperMap_TextActor::Tick(Gamefloat DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bSetParam)
	{	
		m_TextRender->SetRelativeRotation(RealspaceView::GetSingleton()->GetCameraControl()->m_vCameraRotator);
		m_TextRender->SetRelativeLocation(m_vLocation);
		Gamefloat ratio = FVector::DistSquared(RealspaceView::GetSingleton()->GetCameraControl()->m_vCameraLocation.ToFVector(), m_vLocation) / 1000000000.f;
		ratio = ratio < 2 ? ratio : 2;
		ratio = ratio > 0.6 ? ratio : 0.6;
		m_TextRender->SetWorldSize(m_WorldSize * ratio);
		m_TextRender->SetTextRenderColor(m_Color);
		m_TextRender->SetText(m_Text);
	}
	this->AddActorLocalRotation(FRotator(0.f, -180.f, 0.f));
}

Gamevoid ASuperMap_TextActor::SetParam(FVector Location, Gamefloat WorldSize, FColor Color, FText Text)
{
	m_vPriLocation = m_vLocation + FVector(ROCacheManager::m_vecWorldOrigin);
	m_vLocation = Location;
	m_WorldSize = WorldSize;
	m_Color = Color;
	m_Text = Text;
	m_bSetParam = true;
}

Gamevoid ASuperMap_TextActor::UpdateWorldOrigin()
{
	m_vLocation = m_vPriLocation - FVector(ROCacheManager::m_vecWorldOrigin);
	m_bSetParam = true;
}
