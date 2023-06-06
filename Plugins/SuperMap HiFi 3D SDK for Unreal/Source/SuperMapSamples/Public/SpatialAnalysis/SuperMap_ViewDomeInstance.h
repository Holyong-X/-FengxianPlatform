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
	//! \brief �Ƿ񿪳��ȷ���
	//! \param bclip [in] true��ʼ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void BuildViewDome(bool bViewDome);

	//! \brief ���ÿ����ȵ���ʾģʽ���ߣ���䣬�ϣ�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void SetViewDomeDisplayStyle(int type);

	//! \brief ��ȡ�����ȵ���ʾģʽ���ߣ���䣬�ϣ�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	int GetViewDomeDisplayStyle();

	//! \brief ���ÿ����ȵĽ�����ͣ���ʾ���ӡ������Ӳ��֣�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void SetViewDomeType(int type);

	//! \brief ��ȡ�����ȵĽ�����ͣ���ʾ���ӡ������Ӳ��֣�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	int GetViewDomeType();

	//! \brief ���ÿ��Ӿ�������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void SetViewDomeDistance(float fDistance);

	//! \brief ��ȡ���Ӿ�������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	float GetViewDomeDistance();

	//! \brief �����ӵ�λ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	void SetViewerPosition(FVector pos);

	//! \brief ��ȡ�ӵ�λ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ViewDomeInstance")
	FVector GetViewerPosition();

public:
	UPROPERTY(BlueprintAssignable)
	FViewDemoDelegate EventViewDemo;

private:
	//! \brief ��������
	FName m_strAnalyst3DName;

	//! \brief �Ƿ���з���
	Gamebool m_bViewDome;

	Gameint m_nDisplayStyle;

	Gameint m_nDomeType;

	Gamefloat m_fDistance;

	FVector4 m_vColor;

	//! \brief ��������������
	Gameint m_nMouseLeftDown;
};
