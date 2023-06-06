// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/HypsometricSetting.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/TerrainLayers.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_FloodInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFloodDelegate);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_FloodInstance : public AActor
{
	GENERATED_BODY()
	
public:	
	ASuperMap_FloodInstance();
	~ASuperMap_FloodInstance();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void BuildFlood(bool bFlood);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SelectLayer(FName strLayerName);

	//! \brief 淹没速度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetSpeed(float fSpeed);

	//! \brief 设置当前高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetCurrentHeight(float currentHeight);

	//! \brief 当前高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	float GetCurrentHeight();

	//! \brief 最高高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	float GetMaxHeight();

	//! \brief 最低高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	float GetMinHeight();

	//! \brief 设置最高高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetMaxHeight(float maxHeight);

	//! \brief 设置最低高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetMinHeight(float minHeight);

	//! \brief 设置颜色表
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetColorTable(FString strColorTableName);

	//! \brief 设置分析播放与暂停判断
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetPlayState();

	//! \brief 获取分析播放与暂停状态
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	bool GetPlayState();

	//! \brief 清除图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void ClearLayer(float minHeight);

	//! \brief 获取文件夹下的颜色表文件路径
	//! \return 获取颜色表存储路径
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	TArray<FString> GetColorTableFiles();

public:
	UPROPERTY(BlueprintAssignable)
	FFloodDelegate CallFlood;

private:
	//! \brief 解析颜色表
	UTexture2D* ParseColorSctu(FString& strColorTableName);

	//! \brief 解析颜色表
	void ParseColorSctu(FString& strColorTableName, TArray<Gamefloat>& arrValue, TArray<Gameint>& arrColor);

	//! \brief 表示color的16进制组成的字符串转int	
	Gameint ColorStringToInt(FString str);
private:

	Gamefloat m_fMaxHeight;

	Gamefloat m_fMinHeight;

	Gamefloat m_fCurrentHeight;

	Gamebool m_bPlay;

	Gamefloat m_fSpeed;

	FString m_strFileColorTable;

	SuperMapSDK::UnrealEngine::Core::HypsometricSetting* m_pHypsometricSetting;

	TerrainLayers* m_pTerrainLayers;

	Layer3DS3MFile* m_pLayer3DS3MFile;
};
