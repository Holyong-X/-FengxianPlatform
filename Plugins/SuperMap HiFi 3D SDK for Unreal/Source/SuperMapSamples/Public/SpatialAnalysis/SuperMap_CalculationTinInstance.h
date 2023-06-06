// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "ControlUE/RealspaceView.h"
#include "Core/HypsometricSetting.h"
#include "Data/Vector3d.h"
#include "Data/Vector2d.h"
#include "SpatialAnalyst/CalculationTerrain.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/MaterialDefine.h"
#include "SuperMap_CalculationTinInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst;
using namespace SuperMapSDK::UnrealEngine::Core;
UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_CalculationTinInstance : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_CalculationTinInstance();
	~ASuperMap_CalculationTinInstance();
public:
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_CalculationTinInstance")
	void BuildCalculationTin(bool bCalculationTin);

	UFUNCTION(BlueprintCallable, Category = "ASuperMap_CalculationTinInstance")
	bool CalculateResult();

	//! \brief  获取填方体积
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_CalculationTinInstance")
	float GetFillVolume();

	//! \brief  获取挖方体积
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_CalculationTinInstance")
	float GetCutVolume();

	//! \brief  获取填方面积
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_CalculationTinInstance")
	float GetFillArea();

	//! \brief  获取挖方面积
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_CalculationTinInstance")
	float GetCutArea();

	//! \brief 获取未填挖
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_CalculationTinInstance")
	float GetNoChangeArea();

	//! \brief 设置采样距离
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_CalculationTinInstance")
	void SetDperPixel(float fDperPixel);

	//! \brief 设置附加高度
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_CalculationTinInstance")
	void SetBaseAltitude(float fBaseAltitude);
protected:
	virtual void BeginPlay() override;

private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	void DrawFace();

	void Realse();

	void Excavation(GeoRegion3D* PGeoRegion3D);

	void DrawSideFace();

	Vector3d GetNormalVectior(Vector3d v1, Vector3d v2, Vector3d v3);
public:	
	virtual void Tick(float DeltaTime) override;
private:
	Gamebool m_bCalculationTin;

	Gamebool m_bButtonRightDown;

	Gameint m_nMouseLeftDown;

	TArray<Vector2d> m_listPosition;

	TArray<Vector3d> m_listPosition3D;

	TArray<FVector> m_listDrawPosition;

	ASuperMap_ROEntityActor* m_pROEntityActor;

	CalculationTerrain* m_pCalculationTerrain;

	ModifyTerrainObject* m_pModifyTerrainObject;

	float m_fDperPixel;

	float m_fBaseAltitude;

	GeoRegion3D* m_pGeoRegion3D;

	Gamebool m_bExcavation;

	Gamebool m_bGetResult;
};
