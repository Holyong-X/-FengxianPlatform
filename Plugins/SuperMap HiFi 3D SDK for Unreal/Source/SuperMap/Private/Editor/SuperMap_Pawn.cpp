// Fill out your copyright notice in the Description page of Project Settings.


#include "Editor/SuperMap_Pawn.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/Engine.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
ASuperMap_Pawn::ASuperMap_Pawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}
// Called when the game starts or when spawned
void ASuperMap_Pawn::BeginPlay()
{
	Super::BeginPlay();
	BaseEyeHeight = 0.0f;
}

// Called every frame
void ASuperMap_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


