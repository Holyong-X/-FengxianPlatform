// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "ControlUE/RealspaceView.h"
#include "Data/Vector3d.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/MaterialDefine.h"
#include "SuperMap_ProfileInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FProfileTextureDelegate);

void CallbackFunc_ProfileInstance(void* pActor);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ProfileInstance : public AActor, public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_ProfileInstance();
	~ASuperMap_ProfileInstance();
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	void DrawLine(Vector3d vPos);

	void Realse();
public:
	//! \brief 是否剖面分析
	//! \param bclip [in] true开始
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProfileInstance")
	void BuildProfile(bool bProfile);

	//! \brief 获取剖面分析图
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProfileInstance")
	UTexture2D* GetImageData();

	//! \brief 获取剖面图高度
	//! \brief X为最大高度，Y为最小高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ProfileInstance")
	FVector2D GetHeightPosition();

	//! \brief 回调出发事件
	UPROPERTY(BlueprintAssignable)
	FProfileTextureDelegate CallProfileTexture;

	//! \brief 执行多播
	void ExecuteBroadcast();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
private:

	Gamebool m_bProfile;
	//! \brief 起始点
	Vector3d m_vStarPoint;
	//! \brief 终止点
	Vector3d m_vEndPoint;
	//! \brief 实时绘制线
	ASuperMap_ROEntityActor* m_pROEntityActor;
	//! \brief 绘制点
	Vector3d m_DrawFlatStartPoint;

	Vector3d m_DrawFlatEndPoint;

	Vector3d a;

	Vector3d b;

	Gameint m_nMouseLeftDown;

	FName m_strAnalyst3DName;
};
