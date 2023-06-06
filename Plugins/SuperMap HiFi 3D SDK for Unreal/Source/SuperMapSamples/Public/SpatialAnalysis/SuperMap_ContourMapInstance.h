// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Core/TerrainLayers.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_ContourMapInstance.generated.h"

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ContourMapInstance : public AActor
{
	GENERATED_BODY()

public:
	ASuperMap_ContourMapInstance();
	~ASuperMap_ContourMapInstance();
public:
	//! \brief 是否等值线分析
	//! \return true为开始执行等值线分析
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	void BuildContourMap(bool ContourMapEnable);

	//! \brief 初始化等值线分析数值
	//! \param nDisplayMode [in] 1、等值面 2、等值线 3、混合模式
	//! \param fCeil [in] 分析高度值
	//! \param fFloor [in] 分析高度值
	//! \param fMax [in] 可见高度值
	//! \param fMin [in] 可见高度值
	//! \param fContourInterval [in] 间距
	//! \param strColorTableName [in] 对应颜色表路径
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	void InitialContourMap(int nDisplayMode, float fCeil, float fFloor, float fMax, float fMin, float fContourInterval,
		FString strColorTableName);

	//! \brief 设置分析模式
	//! \param nDisplayMode [in] 1、等值面 2、等值线 3、混合模式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	void DisplayModeChanged(int nDisplayMode);

	//! \brief 设置等值线分析最高高度
	//! \param fCeil [in] 高度值
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	void CeilModeChanged(float fCeil);

	//! \brief 设置等值线分析最大可见值
	//! \param fMax [in] 高度值
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	void MaxVisibleValueChanged(float fMax);

	//! \brief 设置等值线分析最小可见值
	//! \param fMin [in] 高度值
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	void MinVisibleValueChanged(float fMin);

	//! \brief 设置等值线分析最低高度
	//! \param fFloor [in] 高度值
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	void FloorModeChanged(float fFloor);

	//! \brief 设置等值线间距
	//! \param fContourInterval [in] 间距
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	void ContourIntervalModeChanged(float fContourInterval);

	//! \brief 设置等值线分析颜色表
	//! \param strColorTableName [in] 对应颜色表路径
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	void ColorTableChanged(FString strColorTableName);

	//! \brief 获取文件夹下的颜色表文件路径
	//! \return 获取颜色表存储路径
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	TArray<FString> GetColorTableFiles();

	//! \brief 获取地形最低值
	//! \return 返回高度值
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	float GetMinHeight();

	//! \brief 获取地形最高值
	//! \return 返回高度值
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ContourMapInstance")
	float GetMaxHeight();
private:

	//! \brief 启动分析
	void Build();

	//! \brief 获取颜色表
	UTexture2D* GetColorMap(FString strColorTableName);

	//! \brief 解析颜色表
	UTexture2D* ParseColorSctu(FString& strColorTableName);

	//! \brief 解析颜色表
	void ParseColorSctu(FString& strColorTableName, TArray<Gamefloat>& arrValue, TArray<Gameint>& arrColor);

	//! \brief 表示color的16进制组成的字符串转int	
	Gameint ColorStringToInt(FString str);
private:

	//! \brief 分析名字
	FName m_strAnalyst3DName;

	//! \brief 是否开启等高线分析
	Gamebool m_bContourMapEnable;

	//! \brief 等值线分析
	HypsometricSetting* m_pHypsometricSetting;

	//! \brief TerrainLayers指针
	TerrainLayers* m_pTerrainLayers;
};
