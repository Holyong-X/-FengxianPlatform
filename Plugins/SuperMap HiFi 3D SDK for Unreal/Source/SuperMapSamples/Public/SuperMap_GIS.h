// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_GIS.generated.h"

UCLASS(BlueprintType, Blueprintable)
class SUPERMAPSAMPLES_API ASuperMap_GIS : public AActor
{
	GENERATED_BODY()

public:
	ASuperMap_GIS();
	~ASuperMap_GIS();
public:

	//! \brief 设置图层LOD层级
	//! \param value [in] 层级
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetLODRangeScale(float value);

	//! \brief 获取图层LOD层级
	//! \return 
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	float GetLODRangeScale();

	//! \brief 设置无效区域
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetShowInvalidation(bool bShow);

	//! \brief 定位到指定图层
	//! \param layerName [in] 图层名称
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void EnsureVisible(FName layerName);

	//! \brief 飞行到指定图层
	//! \param layerName [in] 图层名称
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void FlyToLayer(FName layerName);

	//! \brief 设置图层信息
	//! \param strLayerName [in] 图层名
	//! \param isSelection [in] true 打开
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetLayerInfos(FName strLayerName);

	//! \brief 隐藏图层
	//! \param layerName [in] 图层名称
	//! \param isvisible [in] true显示图层
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetIsVisible(FName layerName, bool isvisible);

	//! \brief  获取是否可见性
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	bool GetIsVisible();
	
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	bool GetLayerIsVisible(FString layerName);

	//! \brief 获取图层中心点
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	FVector GetLayerCenterPoint(FName layerName);

	//! \brief 设置图层偏移
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetConstantPolygonOffset(FName strLayerName, float fOffset);

	//! \brief 设置图层偏移
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	float GetConstantPolygonOffset(FName strLayerName);

	//! \brief 设置裙边
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetSkirt(bool bSetSkirt);
	
	//! \brief 获取裙边设置状态
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	bool GetSkirt();

	//! \brief 设置裙边高度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetSkirtHeight(float fheight);

	//! \brief 设置分屏显影
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetVisibleInViewport(FName strName, int nIndex, bool visible);

	//! \brief 获取分屏显影
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	bool GetVisibleInViewport(FName strName, int nIndex);

	//! \brief 设置分屏相机视野
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetMultiViewportMode(int nScreenMode);

	//! \brief 设置地形夸张
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetTerrainExaggeration(float fValue);

	//! \brief 获取地形夸张数值
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	float GetTerrainExaggeration();

	//! \brief 设置对象可见性
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetObjectsVisible(FName LayerName, TArray<int> nIds, bool bVisible);

	//! \breif 解析字段（云渲染 设置对象显隐相关）
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	TArray<int> GetJsonArrayStringValue(FString Descriptor);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetSelectStyle(FName strName, FVector4 color);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	FVector4 GetSelectStyle(FName strName);

	//! \breif 设置图层的缩放
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetLayerMarker3DScale(FName strName, FVector vScale);

	//! \breif 获取图层的缩放
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	FVector GetLayerMarker3DScale(FName strName);

	//! \breif 设置图层的旋转
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetLayerMarker3DRotate(FName strName, FVector vRotate);

	//! \breif 获取图层的旋转
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	FVector GetLayerMarker3DRotate(FName strName);

	//! \breif 设置图层的平移
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetLayerMarker3DTranslation(FName strName, FVector vTranslation);

	//! \breif 获取图层的平移
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	FVector GetLayerMarker3DTranslation(FName strName);

	//! \brief 设置图层最远可见距离
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetLayerMaxObjectVisibleDistance(FName strName, float fValue);

	//! \brief 设置图层最近可见距离
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetLayerMinObjectVisibleDistance(FName strName, float fValue);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	float GetLayerMaxObjectVisibleDistance(FName strName);

	//! \brief 设置图层对象颜色
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetObjectsColor(FName strName, TArray<int> ids, FVector4 color);

	//! \brief 还原图层对象设置的颜色
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void ResetObjectsColor(FName strName);

	//! \brief 加载数据模式
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetLoadingPriority(FName strName, int type);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	int GetLoadingPriority(FName strName);

	//! \brief 设置影像图层透明度
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	void SetImageLayerOpaqueRate(FName layerName, float value);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	float GetImageLayerOpaqueRate(FName layerName);

	//! \brief 获取缓存图层Type
	UFUNCTION(BlueprintCallable, Category = "SuperMap_GIS")
	int GetLayer3DType(FName layerName);
public:
	//! \brief 图层名称
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_GIS")
	FName m_strLayerName;
private:

	Rectangle2D GetLayerBounds(FName layerName, float& height);
private:

	//! \brief 是否显隐
	Gamebool m_bIsVisible;
};
