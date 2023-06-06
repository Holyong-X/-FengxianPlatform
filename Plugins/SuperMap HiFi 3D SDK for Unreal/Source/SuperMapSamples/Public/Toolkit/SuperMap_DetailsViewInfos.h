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
	//! brief  材质替换UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UMaterialInterface* m_ReplaceMaterial;

	//! brief  图层替换UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UMaterialInterface* m_ReplaceLayerMaterial;

	//! brief  资产替换UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UStaticMesh* m_ReplaceStaticMesh;

	//! brief  侧面开挖纹理UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UMaterialInterface* m_ExcavationSideMaterial;

	//! brief  底面开挖纹理UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DetailsViewInfos")
	UMaterialInterface* m_ExcavationTopMaterial;

	//! brief  设置纹理的UV缩放
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DetailsViewInfos")
	void SetMaterialUVTiling(FString LayerName, FString OriMaterialName, FVector4 UVOffsetAndScale);
};
