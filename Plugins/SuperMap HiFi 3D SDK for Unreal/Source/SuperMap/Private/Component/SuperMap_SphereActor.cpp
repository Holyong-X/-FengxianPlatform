// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SuperMap_SphereActor.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/PlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
using namespace SuperMapSDK;

// Sets default values
ASuperMap_SphereActor::ASuperMap_SphereActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Root Sphere"));
	SetRootComponent(SphereComponent);
	SphereComponent->InitSphereRadius(2.f);
	SphereComponent->SetMobility(EComponentMobility::Movable);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//SphereComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);


	m_pSphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshSphere");

	m_pSphereMesh->SetupAttachment(SphereComponent);

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

	if (MeshAsset.Object != nullptr)
	{
		m_pSphereMesh->SetStaticMesh(MeshAsset.Object);
		m_pSphereMesh->SetRelativeLocation(FVector(0, 0, 0));
	}

	m_pSphereMesh->OnBeginCursorOver.AddDynamic(this, &ASuperMap_SphereActor::MouseBeginOverEvent);
	m_pSphereMesh->OnEndCursorOver.AddDynamic(this, &ASuperMap_SphereActor::MouseEndOverEvent);

	pMat = nullptr;
	m_bSetParam = false;
	m_index = -1;
	m_MeasureIndex = -1;
}


ASuperMap_SphereActor::~ASuperMap_SphereActor()
{
	if (pMat != nullptr)
	{
		pMat->RemoveFromRoot();
		pMat = nullptr;
	}
}

// Called when the game starts or when spawned
void ASuperMap_SphereActor::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PC = UGameplayStatics::GetPlayerController(this->GetWorld(), 0);
	if (PC)
	{
		PC->bEnableMouseOverEvents = true;
	}
	m_pSphereMesh->RegisterComponent();
}

// Called every frame
void ASuperMap_SphereActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bSetParam)
	{
		SetActorLocation(m_vLocation);
		SetActorRotation(FRotator(0, 0, 0));
		if (m_type == ESuperMap_Sphere::BarriedPoint_SightLine)
		{
			m_pSphereMesh->SetWorldScale3D(m_vScale / 2.);
		}
		else
		{
			m_pSphereMesh->SetWorldScale3D(m_vScale);
		}
		m_bSetParam = false;
	}
}

void ASuperMap_SphereActor::InitSphere(FRotator Rotation, FVector Location, FVector Scale)
{
	m_vRotation = Rotation;
	m_vLocation = Location;
	m_vScale = Scale;
	m_bSetParam = true;
}

void ASuperMap_SphereActor::MouseBeginOverEvent(UPrimitiveComponent* Component)
{
	m_pSphereMesh->SetWorldScale3D(m_vScale * 2);
}


void ASuperMap_SphereActor::MouseEndOverEvent(UPrimitiveComponent* Component)
{
	m_pSphereMesh->SetWorldScale3D(m_vScale);
}

void ASuperMap_SphereActor::SetSphereType(ESuperMap_Sphere type)
{
	m_type = type;
	if (type == ESuperMap_Sphere::BarriedPoint_SightLine || type == ESuperMap_Sphere::Point_Measure)
	{
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_BARRIERSPHERERENDER_MAT);
		if (pMat != nullptr)
		{
			pMat->ClearParameterValues();
			pMat = nullptr;
		}
		pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		pMat->AddToRoot();
		m_pSphereMesh->SetMaterial(0, pMat);
		
	}
	else if (type == ESuperMap_Sphere::ViewerPoint_SightLine)
	{
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_VIEWSPHERERENDER_MAT);
		if (pMat != nullptr)
		{
			pMat->ClearParameterValues();
			pMat = nullptr;
		}
		pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		pMat->AddToRoot();
		m_pSphereMesh->SetMaterial(0, pMat);
	}
	else
	{
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_SPHERERENDER_MAT);
		if (pMat != nullptr)
		{
			pMat->ClearParameterValues();
			pMat = nullptr;
		}
		pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		pMat->AddToRoot();
		m_pSphereMesh->SetMaterial(0, pMat);
	}
}

ESuperMap_Sphere ASuperMap_SphereActor::GetSphereType()
{
	return m_type;
}

void ASuperMap_SphereActor::SetSphereIndex(Gameint index)
{
	m_index = index;
}

Gameint ASuperMap_SphereActor::GetSphereIndex()
{
	return m_index;
}

void ASuperMap_SphereActor::SetSphereMeasureIndex(Gameint index)
{
	m_MeasureIndex = index;
}


Gameint  ASuperMap_SphereActor::GetSphereMeasureIndex()
{
	return m_MeasureIndex;
}