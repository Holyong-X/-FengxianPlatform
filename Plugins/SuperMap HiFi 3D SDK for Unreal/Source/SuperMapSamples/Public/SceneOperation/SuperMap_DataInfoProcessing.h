// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_DataInfoProcessing.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActorDelegate);

void OnDataInfoProcessingCallBack(void* pActor);

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FPostProcessingInfo
{
	GENERATED_BODY()

	//! \brief 是否启动后处理
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	bool IsPostProcessingInfo;
	//! \brief 屏幕空间反射 强度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SSRIntensity;
	//! \brief 屏幕空间反射 质量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SSRQuality;
	//! \brief 屏幕空间反射 最大粗糙度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SSRMaxRoughness;
	//! \brief 环境光遮挡 强度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float AOIntensity;
	//! \brief 环境光遮挡 半径
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float AORadius;
	//! \brief 动态模糊 强度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float DFAmount;
	//! \brief 动态模糊 最大
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float DFMax;
	//! \brief 景深 焦距
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float FocalDistance;
	//! \brief 景深 深度模糊
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float DepthBlurKm;
	//! \brief 景深 深度模糊半径
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float DepthBlurRadius;
	//! \brief 泛光 强度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float BloomIntensity;
	//! \brief 泛光 阈值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float BloomThreshold;
};

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FWeatherInfo
{
	GENERATED_BODY()

	//! \brief 是否启动天气
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	bool IsWeather;
	//! \brief 雨雪放置位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	FVector m_vWeatherPsition;
	//! \brief 天气(0:Sun 1:Cloudly 2:Rain 3:Snow)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	int WeatherType;
	//! \brief 材质湿度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float Wetness;
	//! \brief 积雪覆盖
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SnowCoverage;
	//! \brief 体积云覆盖
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float Cloudiness;
	//! \brief 雨雪粒子量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SpawnRate;
};

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FSceneInfo
{
	GENERATED_BODY()
	//! \brief 是否启用场景数据
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	bool m_bIsScene;
	//! \brief 时间
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	FDateTime m_tSunTime;
	//! \brief 时区
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float m_fTimeZone;
};

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_DataInfoProcessing : public AActor
{
	GENERATED_BODY()
	
public:	
	ASuperMap_DataInfoProcessing();
	~ASuperMap_DataInfoProcessing();

	//! \brief 执行多播
	void ExecuteBroadcast();

	//! \brief 保存后处理数据
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	void SetPostProcessingInfo(FPostProcessingInfo postProcessingInfo);

	//! \brief 获取后处理数据
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	FPostProcessingInfo GetPostProcessingInfo();

	//! \brief 保存雨雪数据
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	void SetWeatherInfo(FWeatherInfo weatherInfo);

	//! \brief 获取雨雪数据
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	FWeatherInfo GetWeatherInfo();

	//! \brief 保存场景数据
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	void SetSceneInfo(FDateTime dateTime, float dateTimeZone);

	//! \brief 获取场景数据
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	FSceneInfo GetSceneInfo();
public:
	UPROPERTY(BlueprintAssignable)
	FActorDelegate CallEvent;
};
