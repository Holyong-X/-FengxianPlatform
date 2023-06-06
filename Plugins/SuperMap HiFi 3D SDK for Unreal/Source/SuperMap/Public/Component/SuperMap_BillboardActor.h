// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "ControlUE/CameraControl.h"
#include "ControlUE/RealspaceView.h"
#include "Algorithm3D/MathEngine.h"
#include "Components/SceneComponent.h"
#include "SuperMap_BillboardActor.generated.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

UCLASS()
class SUPERMAP_API ASuperMap_BillboardActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuperMap_BillboardActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "SuperMap_BillboardActor")
	void SetContentArrStr(TArray<FString> arrStr);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_BillboardActor")
	void SetContentStr(FString Str);

	// 设置布告板经纬位置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_BillboardActor")
	void SetGeoLocation(FVector vPos);

public:
	UPROPERTY(EditAnyWhere)
	UTextRenderComponent* m_pTextRender;

	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent* m_pBackground;

private:
	FText m_strInfo;

	Gamebool m_bShow;

	Gameint m_nMaxLength;

	Gameint m_nMaxWidth;

	FVector m_vScale;
};
