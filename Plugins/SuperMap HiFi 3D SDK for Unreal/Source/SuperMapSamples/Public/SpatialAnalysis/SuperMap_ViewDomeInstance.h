// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "ControlUE/RealspaceView.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_ViewDomeInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FViewDemoDelegate);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ViewDomeInstance : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	

	ASuperMap_ViewDomeInstance();
	~ASuperMap_ViewDomeInstance();
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();
public:	
	//! \brief 是否开敞度分析
	//! \param bclip [in] true开始
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void BuildViewDome(bool bViewDome);

	//! \brief 设置开敞度的显示模式（线，填充，合）
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void SetViewDomeDisplayStyle(int type);

	//! \brief 获取开敞度的显示模式（线，填充，合）
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	int GetViewDomeDisplayStyle();

	//! \brief 设置开敞度的结果类型（显示可视、不可视部分）
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void SetViewDomeType(int type);

	//! \brief 获取开敞度的结果类型（显示可视、不可视部分）
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	int GetViewDomeType();

	//! \brief 设置可视距离属性
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void SetViewDomeDistance(float fDistance);

	//! \brief 获取可视距离属性
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	float GetViewDomeDistance();

	//! \brief 设置视点位置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void SetViewerPosition(FVector pos);

	//! \brief 获取视点位置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	FVector GetViewerPosition();

public:
	UPROPERTY(BlueprintAssignable)
	FViewDemoDelegate EventViewDemo;

private:
	//! \brief 分析名字
	FName m_strAnalyst3DName;

	//! \brief 是否进行分析
	Gamebool m_bViewDome;

	Gameint m_nDisplayStyle;

	Gameint m_nDomeType;

	Gamefloat m_fDistance;

	FVector4 m_vColor;

	//! \brief 鼠标左键按键次数
	Gameint m_nMouseLeftDown;
};
