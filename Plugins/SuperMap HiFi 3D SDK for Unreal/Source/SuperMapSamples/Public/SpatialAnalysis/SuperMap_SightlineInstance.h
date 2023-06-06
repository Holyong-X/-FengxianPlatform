// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Component/SuperMap_SphereActor.h"
#include "Base3D/CommonDefine.h"
#include "Algorithm3D/MathEngine.h"
#include "SuperMap_SightlineInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSightlineDelegate);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_SightlineInstance : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:
	ASuperMap_SightlineInstance();
	~ASuperMap_SightlineInstance();

protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	//! \brief 是否视通分析
	//! \param bclip [in] true开始
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SightlineInstance")
	void SetIsSightline(bool bsightline);

	//! \brief 获取观察点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SightlineInstance")
	FString GetViewerPosition();

	//! \brief 是否显示观察点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SightlineInstance")
	bool IsShowViewerPosition();

public:
	UPROPERTY(BlueprintAssignable)
	FSightlineDelegate CallSightline;

private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	Vector3d TransformMousePosition(FVector vMouse);

	void SpawnSphere();

	//! \breif 生成参考球（观察点、目标点）
	void SpawnarrRefSphere(TArray<FVector> arrPositions);

	//! \breif 生成障碍球
	void SpawnarrBarriedSphere(TArray<FVector> arrBarrierPoint);

	void ClearRefSphere();

	void ClearBarriedSphere();

private:

	//! \brief 分析名字
	FName m_strAnalyst3DName;

	//! \brief 是否进行分析
	Gamebool m_bSightline;

	//! \brief 鼠标左键按键次数
	Gameint m_nMouseLeftDown;

	//! \brief 鼠标右键是否按下
	Gamebool m_bMouseRightDown;

	Gamebool m_bIsShowViewerPosition;

	//! \brief 观察点位置
	FVector m_vViewerPosition;

	//! \brief 参考球原先Index
	Gameint m_nOldIndex;

	//! \brief 是否可编辑参考球
	Gamebool m_bEditSphere;

	//! \brief 参考球是否已点选
	Gamebool m_bSelectSphere;

	//! \brief UE参考球对象
	TArray<ASuperMap_SphereActor*> m_arrRefSphereActor;

	//! \brief UE障碍球对象
	TArray<ASuperMap_SphereActor*> m_arrBarriedSphereActor;

	//! \brief 鼠标点
	FVector m_vMouse;

};
