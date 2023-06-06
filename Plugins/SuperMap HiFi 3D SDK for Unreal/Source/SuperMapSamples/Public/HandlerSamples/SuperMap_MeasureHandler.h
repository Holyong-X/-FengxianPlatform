// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/TerrainLayers.h"
#include "Core/SceneEditorWnd.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_MeasureHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLayerDeleteDelegate);

void OnLayerDeleteCallBack(void* pActor);
UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_MeasureHandler : public AActor
{
	GENERATED_BODY()
	
public:	

	ASuperMap_MeasureHandler();
	~ASuperMap_MeasureHandler();
public:	

	//! \brief 是否量算
	//! \param bclip [in] true开始
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	void SetIsMeasureHandler(bool bmeasureHandler);

	//! \brief 选择量算方式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	void SetMeasureAction(int mode);

	//! \brief 获得结果
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	float GetMeasureResult();

	//! \brief 开启等高线
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	void HypsometricSetting(bool IsHyp, FName strLayerName);

	//! \brief 获取当前状态
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	bool GetCurrentState();

	//! \brief 图层删除后的回调
	void LayerDeleteEvent();
private:
	//! \brief 三维图层分层设色显示为None
	void Layer3DS3MFileInitSetting(SuperMapSDK::UnrealEngine::Core::HypsometricSetting* pHypsometricSetting, Layer3DS3MFile* pLayer3DS3MFile);

	//! \brief 地形图层分层设色显示为None
	void TerrainLayersInitSetting(SuperMapSDK::UnrealEngine::Core::HypsometricSetting* pHypsometricSetting, TerrainLayers* pTerrainLayers);

private:

	//! \brief 是否进行量算
	Gamebool m_bMeasureHandler;

	Gameint m_nMeasureAction;

	Gamedouble m_dResult;

	Gamebool m_bState;

	TerrainLayers* m_pTerrainLayers;

	Layer3DS3MFile* m_pLayer3DS3MFile;
};
