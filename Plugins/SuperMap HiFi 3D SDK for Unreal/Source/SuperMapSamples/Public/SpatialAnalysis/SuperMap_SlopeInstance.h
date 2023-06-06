// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/SlopeSetting.h"
#include "Core/TerrainLayers.h"
#include "Base3D/CommonDefine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_SlopeInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::Core;

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_SlopeInstance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuperMap_SlopeInstance();
	~ASuperMap_SlopeInstance();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//! \brief 是否执行坡度坡向分析
	//! \return true为开始执行坡度坡向分析
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void BuildSlope(bool SlopeEnable);

	//! \brief 设置显示模式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void DisplayModeChanged(int nDisplayMode);

	//! \brief 设置坡向箭头是否运动
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void SetArrowMove(bool isMove);
	
	//! \brief 设置颜色表
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void SetColorTable(FString strColorTableName);

	//! \brief 设置最小可见值
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void SetMinVisibleValue(float minValue);

	//! \brief 设置最大可见值
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void SetMaxVisibleValue(float maxValue);

	//! \brief 清除图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void EndSlope();

	//! \brief 获取文件夹下的颜色表文件路径
	//! \return 获取颜色表存储路径
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	TArray<FString> GetColorTableFiles();

private:
	//! \brief 解析颜色表
	UTexture2D* ParseColorSctu(FString& strColorTableName);

	//! \brief 解析颜色表
	void ParseColorSctu(FString& strColorTableName, TArray<Gamefloat>& arrValue, TArray<Gameint>& arrColor);

	//! \brief 表示color的16进制组成的字符串转int	
	Gameint ColorStringToInt(FString str);

private:
	//! \brief 是否开启坡度坡向分析
	Gamebool m_bSlopeEnable;

	TerrainLayers* m_pTerrainLayers;

	SlopeSetting* m_pSlopeSetting;

	FString m_strFileColorTable;
};
