// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "ControlUE/RealspaceView.h"
#include "SpatialAnalyst3D/MultiViewShed3D.h"
#include "SpatialAnalyst3D/ViewShed.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_MultiViewShed3DInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAddViewShed3DDelegate);
UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_MultiViewShed3DInstance : public AActor, public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	

	ASuperMap_MultiViewShed3DInstance();
	~ASuperMap_MultiViewShed3DInstance();
	virtual void Tick(float DeltaTime) override;
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	void Release();

	void ExecuteBroadcast();
public:
	//! \brief 是否启动多可视域分析
	//! \param bclip [in] true开始
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MultiViewShed3DInstance")
	void BuildMultiViewShed3D(bool bMultiViewShed3D);

	//! \brief 添加可视域分析
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MultiViewShed3DInstance")
	void AddViewShed3D(FString viewshedName);

	//! \brief 添加可视域分析
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MultiViewShed3DInstance")
	void RemoveViewShed3D(FString viewshedName);
public:
	//蓝图触发事件
	UPROPERTY(BlueprintAssignable)
	FAddViewShed3DDelegate CallAddViewShed3D;
private:
	Gamebool m_bMultiViewShed3D;

	MultiViewShed3D* m_pMultiViewShed3D;

	ViewShed* m_pViewShed;

	 TMap<FString ,ViewShed*> m_mapViewShed;

	Gameint m_nMouseLeftDown;
protected:

	virtual void BeginPlay() override;

};
