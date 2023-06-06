// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Data/Vector3d.h"
#include "Runtime/Engine/Classes/Components/SplineComponent.h"
#include "Runtime/Engine/Classes/Components/SplineMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_SplineActor.generated.h"


UCLASS()
class SUPERMAP_API ASuperMap_SplineActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASuperMap_SplineActor();
	~ASuperMap_SplineActor();

	Gamevoid CreateSplineMesh(const TArray<TArray<Vector3d>>& pts);

	Gamevoid SetSplineStaticMesh(UStaticMesh* pStaticMesh);

	Gamevoid SetInitPoints(TArray<TArray<Vector3d>> pts);

	Gamevoid UpdateWorldOrigin();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_SplineActor")
	UStaticMesh* m_pSplineStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_SplineActor")
	USplineComponent* m_pSpline;
protected:
	virtual Gamevoid BeginPlay() override;

private:

	Gamevoid CreateSplineMeshComponent(USplineComponent* pSpline);

	TArray<TArray<Vector3d>> m_arrInitPoints;

	TArray<USplineMeshComponent*> m_pSplineMeshs;
public:	
	virtual Gamevoid Tick(float DeltaTime) override;

};
