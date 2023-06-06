// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/Layer3D.h"
#include "Data/GeoRegion3D.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"
#include "SuperMap_FlattenInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::Core;

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_FlattenInstance : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_FlattenInstance();
	~ASuperMap_FlattenInstance();

	//! \brief 是否倾斜压平
	//! \param bflatten [in] true开始
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlattenInstance")
	void SetIsFlatten(bool bflatten, FName strLayerName);

	// Web 云渲染接口相关
	//! \brief 设置倾斜压平的位置
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlattenInstance")
	void AddFlattenRegion(TArray<FVector> arrPos, FString Tag);

	//! \brief 设置是否使用云渲染
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlattenInstance")
	void SetUseWeb(bool bUseWithoutWeb);

	//! \brief 解析面数组
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlattenInstance")
	TArray<FVector> GetJsonArrayStringValue(FString Descriptor, FString FieldName);

private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	void DrawFlatten();
private:

	//! \brief 是否进行压平
	Gamebool m_bFlatten;

	Gamebool m_bWithoutWeb;

	Gamebool m_bButtonRightDown;

	Gameint m_nMouseLeftDown;

	Layer3DS3MFile* m_pLayer3DS3MFile;

	SuperMapSDK::UnrealEngine::Data::GeoRegion3D* m_pGeoRegion3D;

	TArray<Vector3d> m_listPosition;

	TArray<FVector> m_listDrawPosition;

	ASuperMap_ROEntityActor *m_pROEntityActor;

};
