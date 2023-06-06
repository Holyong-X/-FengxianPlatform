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
	//! brief  设置飞行时间
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetDuration(float dDuration);

	//! brief  获取飞行时间
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	float GetDuration();

	//! brief  设置飞行速率
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetPlayRate(float dPlayRate);

	//! brief  获取飞行速率
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetFlyStatus(int nStatus);

	//! brief  获取飞行状态
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int GetFlyStatus();

	//! brief  返回飞行路线数量；错误为-1
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int LaunchFly(FString FlyFile);

	//! brief  设置飞行循环
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetEnableLoopFly(bool bEnableLoop);

	//! brief  选择飞行线路
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetCurrentRoute(int nIndex);

	//! brief  设置飞行转向模式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetFlyTurningMode(int nMode);

	//! brief  获取飞行线路名
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	FString GetRouteName(int nIndex);

	//! brief  设置飞行线路名
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetRouteName(FString name, int nIndex);

	//! brief 新建路线
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void CreateRoute(FString RouteName);

	//! brief 保存路线
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SaveRoute(FString FileName, FString FilePath);

	//! brief 添加站点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void AddRouteStop(FString RouteStopName);

	//! brief 删除站点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void DeleteRouteStop(FString RouteStopName);

	//! brief 设置摄像机为指定索引站点的摄像机状态
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetRouteStop(int nIndex);

	//! brief  获取当前飞行时所在的站点位置（仅飞行和暂停时有效）
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int GetRouteStop();

	//! brief  获取当前飞行路线站点数量
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int GetNumOfRouteStops();

	//! brief  获取飞行线路站点名
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	FString GetRouteStopName(int nIndex);

	//! brief  获取站点相机参数信息
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	FRouteStopCameraInfo GetRouteStopCameraParam(FString RouteStopName);

	//! brief 设置站点相机参数信息
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetRouteStopCameraParam(FString RouteStopName, FRouteStopCameraInfo info);

	//! brief  获取路线索引
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	int GetCurrentRouteIndex();

	//! brief  设置是否锁定俯仰视角
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	void SetCurrentRouteHeadingFixed(bool bSet);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlyManagerInstance")
	bool IsCurrentRouteHeadingFixed();

	//! brief  设置是否锁定倾斜视角
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
	//! brief  是否初始化FlyManager参数
	Gamebool m_bFlyInit;

	//! brief  飞行循环
	Gamebool m_bEnableLoopFly;

	//! brief  线路索引
	Gameint m_nRouteIndex;

	//! brief 飞行转向模式
	FlyTurningMode m_nTurningMode;

	//! brief  飞行速率
	Gamedouble m_dPlayRate;

	//! brief  是否处于飞行状态
	Gamebool m_bFly;

	//! brief  飞行站点相机参数
	FRouteStopCameraInfo m_StopCameraInfo;
};
