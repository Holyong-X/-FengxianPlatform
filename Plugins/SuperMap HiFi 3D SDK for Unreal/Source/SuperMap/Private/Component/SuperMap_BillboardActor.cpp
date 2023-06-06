// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/SuperMap_BillboardActor.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ASuperMap_BillboardActor::ASuperMap_BillboardActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* pSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	m_pTextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRender"));
	m_pTextRender->SetupAttachment(pSceneRoot);
	m_pTextRender->SetTextRenderColor(FColor::Black);
	m_pTextRender->SetWorldSize(26);
	m_pTextRender->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	m_pTextRender->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextCenter);
	
	m_pBackground = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Background"));
	m_pBackground->SetupAttachment(m_pTextRender);
	m_pBackground->SetRelativeLocation(FVector(-1, 0, 0));
	m_pBackground->SetRelativeRotation(FRotator(-90, 0, 0));
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Plane.Plane'"));
	if (MeshAsset.Object != nullptr)
	{
		m_pBackground->SetStaticMesh(MeshAsset.Object);
	}

	static UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_BILLBOARDRENDER_MAT);
	m_pBackground->SetMaterial(0, pMaterialInterface);
	m_pBackground->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	m_strInfo.GetEmpty();
	m_bShow = false;
	m_nMaxLength = 0;
	m_nMaxWidth = 0;
	m_vScale = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void ASuperMap_BillboardActor::BeginPlay()
{
	Super::BeginPlay();
	m_pTextRender->RegisterComponent();
	m_pBackground->RegisterComponent();
}

// Called every frame
void ASuperMap_BillboardActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_bShow)
	{
		FVector Location;
		FRotator Rotation;
		GetWorld()->GetFirstPlayerController()->GetActorEyesViewPoint(Location, Rotation);
		Gamefloat ratio = FVector::DistSquared(Location, GetActorLocation()) / 1000000000.f;
		ratio = ratio < 30 ? 30 : ratio;
		ratio = ratio > 500 ? 500 : ratio;
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
		{
			this->SetActorRotation(FRotator(0, Rotation.Yaw, Rotation.Roll));
		}
		else
		{
			this->SetActorRotation(Rotation);
		}
		
		AddActorLocalRotation(FRotator(0, -180, 0));
		
		m_pTextRender->SetWorldSize(26 * ratio);
		m_pBackground->SetWorldScale3D(ratio * m_vScale);
	}
}

void ASuperMap_BillboardActor::SetContentStr(FString Str)
{
	m_strInfo = FText::FromString(Str);
	m_pTextRender->SetText(m_strInfo);
	m_vScale = FVector(0.3, Str.Len() * 0.12, 1);
	m_pBackground->SetRelativeScale3D(m_vScale);
	m_bShow = true;
}

void ASuperMap_BillboardActor::SetContentArrStr(TArray<FString> arrStr)
{
	m_nMaxWidth = arrStr.Num();
	FString Info;
	for (int i = 0; i < arrStr.Num(); ++i)
	{
		FString tmp = arrStr[i].Append(TEXT("<br>"));
		Info.Append(tmp);
		m_nMaxLength = m_nMaxLength > arrStr[i].Len() ? m_nMaxLength : arrStr[i].Len();
	}
	m_strInfo = FText::FromString(Info);
	m_pTextRender->SetText(m_strInfo);
	m_strInfo.GetEmpty();
	m_vScale = FVector(m_nMaxWidth * 0.3, m_nMaxLength * 0.12, 1);
	m_pBackground->SetRelativeScale3D(m_vScale);
	m_bShow = true;
}

void ASuperMap_BillboardActor::SetGeoLocation(FVector vPos)
{
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
	{
		SetActorLocation(vPos);

	}
	else
	{
		SetActorLocation(MathEngine::SphericalToCartesian_GeoOrigin(vPos));
	}
}

