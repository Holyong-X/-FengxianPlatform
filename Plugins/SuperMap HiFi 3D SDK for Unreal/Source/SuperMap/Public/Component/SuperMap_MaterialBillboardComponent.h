// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Components/MaterialBillboardComponent.h"
#include "SuperMap_MaterialBillboardComponent.generated.h"

UCLASS()
class SUPERMAP_API USuperMap_MaterialBillboardComponent : public UMaterialBillboardComponent
{
	GENERATED_BODY()

public:
	USuperMap_MaterialBillboardComponent(const FObjectInitializer& ObjectInitializer);

	//! \brief …Ë÷√Œ∆¿Ì◊¯±Í
	void SetUV(Gamefloat fMinU, Gamefloat fMinV, Gamefloat fMaxU, Gamefloat fMaxV);

public:
	Gamefloat m_fMinU;
	Gamefloat m_fMinV;
	Gamefloat m_fMaxU;
	Gamefloat m_fMaxV;

public:
	//~ Begin UPrimitiveComponent Interface
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	//~ End UPrimitiveComponent Interface
};