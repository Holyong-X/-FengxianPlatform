// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"
#include "SuperMap_SphereActor.generated.h"

UENUM()
enum class ESuperMap_Sphere : uint8
{
	ViewerPoint_SightLine = 0,
	TargetPoint_SightLine = 1,
	BarriedPoint_SightLine = 2,
	Point_Measure = 3
};


UCLASS()
class SUPERMAP_API ASuperMap_SphereActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuperMap_SphereActor();
	~ASuperMap_SphereActor();

protected:
	// Called when the game starts or when spawned
	virtual Gamevoid BeginPlay() override;

public:	
	// Called every frame
	virtual Gamevoid Tick(Gamefloat DeltaTime) override;

public:
	Gamevoid InitSphere(FRotator Rotation, FVector Location, FVector Scale);

	UFUNCTION()
	void MouseBeginOverEvent(UPrimitiveComponent* Component);

	UFUNCTION()
	void MouseEndOverEvent(UPrimitiveComponent* Component);

	//! \brief 设置参考球类型
	Gamevoid SetSphereType(ESuperMap_Sphere type);

	//! \brief 获取参考球类型
	ESuperMap_Sphere GetSphereType();

	//! \brief 设置参考球序号
	Gamevoid SetSphereIndex(Gameint index);

	//! \brief 获取参考球序号
	Gameint GetSphereIndex();

	//! \brief 设置参考球量算序号
	Gamevoid SetSphereMeasureIndex(Gameint index);

	//! \brief 获取参考球量算序号
	Gameint GetSphereMeasureIndex();

public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* m_pSphereMesh;

private:
	FRotator m_vRotation;

	FVector m_vLocation;

	FVector m_vScale;

	Gamebool m_bSetParam;
	
	ESuperMap_Sphere m_type;

	Gameint m_index;

	Gameint m_MeasureIndex;

	UMaterialInstanceDynamic* pMat;
};
