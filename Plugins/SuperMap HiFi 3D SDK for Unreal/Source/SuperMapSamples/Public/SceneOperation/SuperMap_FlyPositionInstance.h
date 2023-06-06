// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ControlUE/RealspaceView.h"
#include "Core/Scene.h"
#include "Core/CameraState.h"
#include "Base3D/CommonDefine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_FlyPositionInstance.generated.h"

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_FlyPositionInstance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuperMap_FlyPositionInstance();
	~ASuperMap_FlyPositionInstance();
public:	
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void LaunchFlyPosition();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetFlyTime(float dDuration);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetFlyPositionParams(float fLongitude, float fLatitude, float fAltitude,
		float fPitch, float fHeading, float fRoll);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetFlyPositionParamsFromCamera(FVector vCameraLocation, FRotator vCameraRotator);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void DestroyFlyPosition();
private:
	CameraState* m_pCameraState;

	int m_nFlyTime;
};
