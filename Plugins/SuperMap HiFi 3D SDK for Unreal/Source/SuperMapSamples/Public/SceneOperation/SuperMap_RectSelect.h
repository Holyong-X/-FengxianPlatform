// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/SceneEditorWnd.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_RectSelect.generated.h"

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_RectSelect : public AActor
{
	GENERATED_BODY()
	
public:	
	ASuperMap_RectSelect();
	~ASuperMap_RectSelect();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
public:	
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_RectSelect")
	void BuildRectSelect(bool bRectSelect);
};
