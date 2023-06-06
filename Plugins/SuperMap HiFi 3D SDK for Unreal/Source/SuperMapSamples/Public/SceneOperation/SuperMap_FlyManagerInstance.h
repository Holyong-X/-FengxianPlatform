// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ControlUE/RealspaceView.h"
#include "Core/Scene.h"
#include "Core/FlyManager.h"
#include "Base3D/CommonDefine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_FlyManagerInstance.generated.h"

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FRouteStopCameraInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_FlyManagerInstance")
	float fLon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_FlyManagerInstance")
	float fLat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_FlyManagerInstance")
	float fAltitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_FlyManagerInstance")
	float fTilt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_FlyManagerInstance")
	float fHeading;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_FlyManagerInstance")
	float fRoll;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_FlyManagerInstance")
	float fDuration;
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFlyManagerDelegate);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_FlyManagerInstance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuperMap_FlyManagerInstance();
	~ASuperMap_FlyManagerInstance();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//! brief  ���÷���ʱ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetDuration(float dDuration);

	//! brief  ��ȡ����ʱ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	float GetDuration();

	//! brief  ���÷�������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetPlayRate(float dPlayRate);

	//! brief  ��ȡ��������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetFlyStatus(int nStatus);

	//! brief  ��ȡ����״̬
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int GetFlyStatus();

	//! brief  ���ط���·������������Ϊ-1
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int LaunchFly(FString FlyFile);

	//! brief  ���÷���ѭ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetEnableLoopFly(bool bEnableLoop);

	//! brief  ѡ�������·
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetCurrentRoute(int nIndex);

	//! brief  ���÷���ת��ģʽ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetFlyTurningMode(int nMode);

	//! brief  ��ȡ������·��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	FString GetRouteName(int nIndex);

	//! brief  ���÷�����·��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetRouteName(FString name, int nIndex);

	//! brief �½�·��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void CreateRoute(FString RouteName);

	//! brief ����·��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SaveRoute(FString FileName, FString FilePath);

	//! brief ���վ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void AddRouteStop(FString RouteStopName);

	//! brief ɾ��վ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void DeleteRouteStop(FString RouteStopName);

	//! brief ���������Ϊָ������վ��������״̬
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetRouteStop(int nIndex);

	//! brief  ��ȡ��ǰ����ʱ���ڵ�վ��λ�ã������к���ͣʱ��Ч��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int GetRouteStop();

	//! brief  ��ȡ��ǰ����·��վ������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int GetNumOfRouteStops();

	//! brief  ��ȡ������·վ����
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	FString GetRouteStopName(int nIndex);

	//! brief  ��ȡվ�����������Ϣ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	FRouteStopCameraInfo GetRouteStopCameraParam(FString RouteStopName);

	//! brief ����վ�����������Ϣ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetRouteStopCameraParam(FString RouteStopName, FRouteStopCameraInfo info);

	//! brief  ��ȡ·������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int GetCurrentRouteIndex();

	//! brief  �����Ƿ����������ӽ�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetCurrentRouteHeadingFixed(bool bSet);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	bool IsCurrentRouteHeadingFixed();

	//! brief  �����Ƿ�������б�ӽ�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetCurrentRouteTiltFixed(bool bSet);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	bool IsCurrentRouteTiltFixed();

private:
	void FixRotationOfCamera();

	bool IsFixedRotationOfCamera();

public:
	UPROPERTY(BlueprintAssignable)
	FFlyManagerDelegate CallFlyManagerEvent;

private:
	//! brief  �Ƿ��ʼ��FlyManager����
	Gamebool m_bFlyInit;

	//! brief  ����ѭ��
	Gamebool m_bEnableLoopFly;

	//! brief  ��·����
	Gameint m_nRouteIndex;

	//! brief ����ת��ģʽ
	FlyTurningMode m_nTurningMode;

	//! brief  ��������
	Gamedouble m_dPlayRate;

	//! brief  �Ƿ��ڷ���״̬
	Gamebool m_bFly;

	//! brief  ����վ���������
	FRouteStopCameraInfo m_StopCameraInfo;
};
