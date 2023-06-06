// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Core/Layer3DS3MFile.h"
#include "Base3D/MaterialDefine.h"
#include "Data/GeoRegion3D.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_ExcavationInstance.generated.h"

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ExcavationInstance : public AActor, public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_ExcavationInstance();
	~ASuperMap_ExcavationInstance();

	virtual void Tick(float DeltaTime) override;

public:

	//! \brief 是否开挖
	//! \param bflatten [in] true开始
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void BuildExcavation(bool bExcavation);

	//! \brief 添加新的开挖面
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void AddExcavationRegion();

	//! \brief 开挖方式（0 内 1 外）
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetModifyRegionMode(int type);

	//! \brief 开挖图层
	//! true Terreain
	//! false S3M
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SelectLayer(FName strLayerName, bool IsSelect);

	//! \brief 清除
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void ClearModifyRegion();

	//! \brief 设置是否使用云渲染
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetUseWeb(bool bUseWithoutWeb);

	//! \brief 解析面数组
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	TArray<FVector> GetJsonArrayStringValue(FString Descriptor, FString FieldName);

	// Web 云渲染接口相关
	//! \brief 设置倾斜压平的位置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void AddWebExcavationRegion(TArray<FVector> arrPos, FString Tag);

	//! \brief 开挖深度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetExtendHeight(float height);

	//! \brief 侧面纹理
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetSideTexture(FString filePath);

	//! \brief 底面纹理
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetTopTexture(FString filePath);

	//! \brief 插值数
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetInterpolatoryCount(int nCount);

	//! \brief 是否贴图
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void IsChartlet(bool bChartlet);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetTopMaterialPath(FString filePath);
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetSideMaterialPath(FString filePath);
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	//! \brief 绘制线框
	void DrawFace();

	//! \brief 设置贴图风格
	void SetStyle(GeoRegion3D* pGeoRegion3D);

	//! \brief 绘制侧面纹理
	void DrawSideFace(GeoRegion3D* geoRegion3D);

	void DrawTopFace(GeoRegion3D* geoRegion3D);

	//! \brief 图片转Texture2D
	UTexture2D* GetTexture2DFromDiskFile(FString FilePath);

	//! \brief 算法线
	Vector3d GetNormalVectior(Vector3d v1, Vector3d v2, Vector3d v3);

protected:
	virtual void BeginPlay() override;

private:
	//! \brief 是否进行开挖
	Gamebool m_bExcavation;
	//! \brief 开挖面
	TArray<GeoRegion3D*> m_arrGeoRegion3Ds;
	//! \brief 开挖面的UGC点
	TArray<Vector3d> m_listPosition;
	//! \brief 当前开挖面的绘制点
	TArray<FVector> m_listDrawPosition;
	//! \brief 开挖方式
	Gameint m_nModifyRegionMode;

	TMap<FName, Layer3DS3MFile*> m_mapLayer3DS3MFiles;

	ASuperMap_ROEntityActor* m_pROEntityActor;

	ASuperMap_ROEntityActor* m_pTopFaceROEntityActor;

	Gameint m_nMouseLeftDown;

	Gamebool m_bButtonRightDown;

	Gamebool m_bButtonLeftDown;

	Gamebool m_bIsTerrainLayer;

	Gamebool m_bWithoutWeb;

	Gamefloat m_fExtendHeight;
	FString m_strSideTexture;
	UTexture2D* m_pSideTexture;
	FString m_strTopTexture;
	Gameint m_nInterpolatoryCount;
	Gamebool m_bChartlet;

	FString m_strSideMaterialPath;
	FString m_strTopMaterialPath;
};
