// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ControlUE/CameraControl.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_SwipeInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::ControlUE;

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_SwipeInstance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuperMap_SwipeInstance();

	//! \brief ���þ���
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SwipeInstance")
	void SetSwipe(FName strLayerName, bool bSelected);

	//! \brief ��ȡͼ���Ƿ����
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SwipeInstance")
	bool GetSwipeEnabled(FName strLayerName);

	//��\brief �����Ϸ�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SwipeInstance")
	void SetSwipeTop(float top);

	//��\brief �����·�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SwipeInstance")
	void SetSwipeBottom(float bottom);

	//��\brief �����Ҳ�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SwipeInstance")
	void SetSwipeRight(float right);

	//��\brief �������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SwipeInstance")
	void SetSwipeLeft(float left);

private:
	Gamefloat m_fTop;
	Gamefloat m_fBottom;
	Gamefloat m_fLeft;
	Gamefloat m_fRight;
};
