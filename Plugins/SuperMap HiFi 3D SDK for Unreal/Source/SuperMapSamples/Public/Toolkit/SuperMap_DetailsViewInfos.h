// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_DetailsViewInfos.generated.h"

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_DetailsViewInfos : public AActor
{
	GENERATED_BODY()
	
public:	
	ASuperMap_DetailsViewInfos();

public:
	//! brief  �����滻UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UMaterialInterface* m_ReplaceMaterial;

	//! brief  ͼ���滻UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UMaterialInterface* m_ReplaceLayerMaterial;

	//! brief  �ʲ��滻UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UStaticMesh* m_ReplaceStaticMesh;

	//! brief  ���濪������UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UMaterialInterface* m_ExcavationSideMaterial;

	//! brief  ���濪������UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UMaterialInterface* m_ExcavationTopMaterial;

	//! brief  ���������UV����
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DetailsViewInfos")
	void SetMaterialUVTiling(FString LayerName, FString OriMaterialName, FVector4 UVOffsetAndScale);
};
