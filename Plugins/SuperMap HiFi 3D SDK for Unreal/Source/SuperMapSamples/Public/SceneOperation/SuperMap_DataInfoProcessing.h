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

	//! \brief �Ƿ���������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	bool IsPostProcessingInfo;
	//! \brief ��Ļ�ռ䷴�� ǿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SSRIntensity;
	//! \brief ��Ļ�ռ䷴�� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SSRQuality;
	//! \brief ��Ļ�ռ䷴�� ���ֲڶ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SSRMaxRoughness;
	//! \brief �������ڵ� ǿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float AOIntensity;
	//! \brief �������ڵ� �뾶
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float AORadius;
	//! \brief ��̬ģ�� ǿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float DFAmount;
	//! \brief ��̬ģ�� ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float DFMax;
	//! \brief ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float FocalDistance;
	//! \brief ���� ���ģ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float DepthBlurKm;
	//! \brief ���� ���ģ���뾶
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float DepthBlurRadius;
	//! \brief ���� ǿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float BloomIntensity;
	//! \brief ���� ��ֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float BloomThreshold;
};

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FWeatherInfo
{
	GENERATED_BODY()

	//! \brief �Ƿ���������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	bool IsWeather;
	//! \brief ��ѩ����λ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	FVector m_vWeatherPsition;
	//! \brief ����(0:Sun 1:Cloudly 2:Rain 3:Snow)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	int WeatherType;
	//! \brief ����ʪ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float Wetness;
	//! \brief ��ѩ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SnowCoverage;
	//! \brief ����Ƹ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float Cloudiness;
	//! \brief ��ѩ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	float SpawnRate;
};

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FSceneInfo
{
	GENERATED_BODY()
	//! \brief �Ƿ����ó�������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	bool m_bIsScene;
	//! \brief ʱ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_DataInfoProcessing")
	FDateTime m_tSunTime;
	//! \brief ʱ��
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

	//! \brief ִ�жಥ
	void ExecuteBroadcast();

	//! \brief �����������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	void SetPostProcessingInfo(FPostProcessingInfo postProcessingInfo);

	//! \brief ��ȡ��������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	FPostProcessingInfo GetPostProcessingInfo();

	//! \brief ������ѩ����
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	void SetWeatherInfo(FWeatherInfo weatherInfo);

	//! \brief ��ȡ��ѩ����
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	FWeatherInfo GetWeatherInfo();

	//! \brief ���泡������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	void SetSceneInfo(FDateTime dateTime, float dateTimeZone);

	//! \brief ��ȡ��������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_DataInfoProcessing")
	FSceneInfo GetSceneInfo();
public:
	UPROPERTY(BlueprintAssignable)
	FActorDelegate CallEvent;
};
