// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_SkylineInstance.generated.h"

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_SkylineInstance : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_SkylineInstance();
	~ASuperMap_SkylineInstance();

private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();
public:	

	//! \brief 天际线分析
	//! \param bclip [in] true开始
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetIsSkyline(bool bskyline);

	//! \brief 设置线颜色
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetSkylineColor(FColor color);

	//! \brief 设置俯仰角
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetViewerPitch(float pitch);

	//! \brief 设置/获取视线的水平方向,北向为0
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetViewerDirection(float direction);

	//! \brief 设置获取天际线半径
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetRadius(float dRadius);

	//! \brief 添加闭合拉升体
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SetSkylineSectorBody(float fHeight);

	//! \brief 获取障碍建筑
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SkylineInstance")
	void SkylineGetObjectIDs(bool isLight);

	//! \breif 是否显示二维线
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_SkylineInstance")
	bool m_bSkyline2D;

	//! \breif 获取二维线点
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_SkylineInstance")
	TArray<FVector2D> m_arrPoint2Ds;
private:

	//! \brief 运行天际线
	void BuildSkyline();

	//! \brief 获取二维天际线
	void GetSkyline2D();

	bool m_bSkyline;

	FName m_strAnalyst3DName;
	//! \brief 视线方向
	float m_dDirection;
	//! \brief 俯仰角
	float m_dPitch;
	//！ \brief 天际线半径
	float m_dRadius;
	//！ \brief 天际线颜色
	FColor m_cColor;
	//！ \brief 障碍图层及建筑的id
	TMap<Gameint, TArray<Gameint>> m_mapLayerIds;
};
