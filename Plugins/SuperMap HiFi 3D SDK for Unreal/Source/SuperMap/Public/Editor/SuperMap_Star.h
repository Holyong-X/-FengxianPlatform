// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_Star.generated.h"

class USuperMap_ProceduralMeshComponent;

UCLASS()
class SUPERMAP_API ASuperMap_Star : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASuperMap_Star();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// 创建随机数的顶点包
	void InitialRandomStar();

	// 经纬度到笛卡尔坐标
	FVector SphericalToCartesian(float fLon, float fLat, float fAlt);
public:
	//UPROPERTY()
	USuperMap_ProceduralMeshComponent* m_pMesh;
};
