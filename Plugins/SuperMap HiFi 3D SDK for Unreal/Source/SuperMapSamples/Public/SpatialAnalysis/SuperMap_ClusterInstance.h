// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "ControlUE/RealspaceView.h"
#include "SpatialAnalyst3D/Cluster.h"
#include "Algorithm3D/MathEngine.h"
#include "Base3D/CommonDefine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_ClusterInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FClusterDelegate);

using namespace SuperMapSDK::UnrealEngine;
using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;

void OnClusterEventCallBack(void* pActor, TMap<FString, TArray<ClusteredEntities>> info);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ClusterInstance : public AActor
{
	GENERATED_BODY()
	
public:	

	ASuperMap_ClusterInstance();
	~ASuperMap_ClusterInstance();
public:
	UPROPERTY(BlueprintAssignable)
	FClusterDelegate CallGetScreenPos;
	//! \brief 启动点外挂图标
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	void Cluster_Build();
	//! \brief 获取图片路径对应的屏幕坐标点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	TArray<FVector2D> Cluster_GetScreenPosition(FString path);
	//! \brief 
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	void Cluster_SetGeoPosition();

	//! \brief 设置避让距离
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	void Cluster_SetPixelRange(int pixelRange);
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	int Cluster_GetPixelRange();

	//! \brief 是否避让
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	void SetClusterEnable(bool bEnble);
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	bool GetClusterEnable();

	//! \brief 最小可聚类数
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	void SetMinimumClusterSize(int minimumClusterSize);
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	int GetMinimumClusterSize();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	TArray<FString> GetRelatedLabelPath();

	//=====================================================================
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	void QueryPointBySql(FString LayerName, FString dataset, FString styleField, TArray<FString> strSql, TArray<FString> strPath);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClusterInstance")
	void RemoveLayer(FString LayerName);
private:


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	TMap<FString, TArray<ClusteredEntities>> m_mapClusteredEntities;
private:
	bool m_bCluster;

	FName m_strAnalyst3DName;

	TMap<FString, TArray<Vector3d>> m_mapPoints;

	TMap<FString, TMap<FString, TArray<Vector3d>>> m_mapLayerArrPoints;

	TArray<Layer3DDatasetVector*> m_arrLayer3DDatasetVector;
};
