// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "ControlUE/RealspaceView.h"
#include "Data/GeoLine3D.h"
#include "Data/GeoModel3D.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_ViewShedInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FViewShedDelegate);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ViewShedInstance : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	

	ASuperMap_ViewShedInstance();
	~ASuperMap_ViewShedInstance();
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

public:

	//! \brief �Ƿ���������
	//! \param bclip [in] true��ʼ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewShedInstance")
	void SetIsViewShed(bool bViewShed);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewShedInstance")
	FString GetViewerPosition();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewShedInstance")
	bool IsShowViewerPosition();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewShedInstance")
	void SetViewShedVisibleBody(bool bVisible);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewShedInstance")
	void SetViewShedHiddenBody(bool bVisible);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewShedInstance")
	void SetViewShedGeoLine(bool bVisible);

public:
	UPROPERTY(BlueprintAssignable)
	FViewShedDelegate CallViewShed;

private:
	//! \brief ��������
	FName m_strAnalyst3DName;

	//! \brief �Ƿ���з���
	bool m_bViewShed;

	//! \brief ��������������
	int m_nMouseLeftDown;

	bool m_bIsShowViewerPosition;

	//! /brief 
	GeoLine3D* m_pGeoLine3D;

	//! /brief 
	GeoModel3D* m_pVisibleGeoModel;

	//! /brief 
	GeoModel3D* m_pHiddenGeoModel;
};
