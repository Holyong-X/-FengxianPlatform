// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/GeoBox.h"
#include "Render/DrawBox.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/Layer3D.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Core/ClipMode.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"
#include "SuperMap_ClipBoxInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Render;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FClipboxDelegate);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ClipBoxInstance : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()

public:
	ASuperMap_ClipBoxInstance();
	~ASuperMap_ClipBoxInstance();
public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();
public:
	//! \brief 是否裁剪
	//! \param bclip [in] true开始裁剪
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetIsClip(bool bclip);

	//! \brief 设置裁剪方式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetClipBoxMode(int mode);

	//! \brief 设置显示方式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetClipMode(int mode);

	//! \brief 设置透明度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetClipOpacity(float opacity);

	//! \brief 设置中心点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetClipCenter(FVector vPos);

	//! \brief 获取中心点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	FVector GetClipCenter();

	//! \brief 设置长度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetClipLength(float length);

	//! \brief 设置宽度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetClipWidth(float width);

	//! \brief 设置高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetClipHeight(float height);

	//! \brief 设置底面高程
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetClipCenterZ(float height);

	//! \brief 获取底面高程
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	float GetClipCenterZ();

	//! \brief 获取长度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	float GetClipLength();

	//! \brief 获取宽度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	float GetClipWidth();

	//! \brief 获取高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	float GetClipHeight();


	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SelectLayer3D(FName nLayer);

	//! \brief 是否绘制好box
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	bool GetbDrawBox();

	//! \brief 
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetbDrawBox(bool bBox);

	//云渲染会使用
	//! \brief 
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void ClipGeoBox();
	//! \brief 
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ClipBoxInstance")
	void SetIsWebUI(bool bWebUI);

public:
	UPROPERTY(BlueprintAssignable)
	FClipboxDelegate CallClipBox;

private:
	Gamedouble GetLengthFromVector(Vector3d start, Vector3d end);

	void ChangeClipBox();

	void CalculateClipBoxParam(Vector3d vPos);

	void DrawLine(Vector3d vPos);

	void DrawFace(Vector3d vPos);

	void DrawFace();
private:
	Gamebool m_bUpdateClipValue;

	Gamebool m_bUseWebUI;

	Gamebool m_bDrawBox;

	Gameint m_nClipBoxMode;

	Gamebool m_bClip;

	Gameint m_nMouseLeftDown;

	Gamebool m_bEndDraw;

	//! \brief 当前图层
	Layer3DS3MFile* m_pLayer3DS3MFile;

	//! \brief 起始点
	Vector3d m_vStart;

	//! \brief 终止点
	Vector3d m_vEnd;

	//! \brief 中心点
	Vector3d m_vCenter;

	//! \brief 宽
	Gamedouble m_dWidth;

	//! \brief 长
	Gamedouble m_dLength;

	//! \brief 高
	Gamedouble m_dHeight;

	//! \brief 3个点
	TArray<Vector3d> m_vPosition;

	//! \brief 裁剪Box
	GeoBox* m_pGeoBox;

	//! \brief 绘制的点
	Vector3d m_vFirstPoint;
	Vector3d m_vSecondPoint;
	Vector3d m_vThridPoint;

	//! \brief Box裁剪模式
	BoxClipPart m_eBoxClipMode;

	//! \brief 设置透明度
	Gamefloat m_fOpacity;

	//! \brief 实时绘制线
	ASuperMap_ROEntityActor* m_pROEntityActor;

	//! \brief 实时绘制面
	ASuperMap_ROEntityActor* m_pROEntityActor_Face;
};
