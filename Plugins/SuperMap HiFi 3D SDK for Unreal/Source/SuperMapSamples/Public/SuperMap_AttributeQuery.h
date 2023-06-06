// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/Layer3DDatasetModel.h"
#include "Component/SuperMap_StaticMeshActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_AttributeQuery.generated.h"

using namespace SuperMapSDK::UnrealEngine::Core;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAttributeQueryDelegate);

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FAttributeInfos {

	GENERATED_BODY()

	//! \brief 查询属性字段
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ASuperMap_AttributeQuery")
	FString m_strFileInfo;

	//! \brief 查询属性值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ASuperMap_AttributeQuery")
	FString m_strFileValue;

};

void CallbackFunc_AttributeQuery(void* pActor, void* pSelectLayerHandle, Gameint nSelectID);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_AttributeQuery : public AActor
{
	GENERATED_BODY()
public:
	ASuperMap_AttributeQuery();
	~ASuperMap_AttributeQuery();

public:

	//! \brief 是否查询属性
	//! \param selectionInfos [in] true 表示进行属性查询
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_AttributeQuery")
	void IsSelectionInfos(bool selectionInfos);

	//! \brief 是否查询属性id是否相同
	//! \return true 与上次查询模型相同不刷新数值
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_AttributeQuery")
	bool IsGetSelectionInfos();

	//! \brief 获取属性查询信息
	//! \return 返回属性表
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_AttributeQuery")
	TArray<FAttributeInfos> GetSelectionInfos();

	//! \brief 获取模型数据集属性查询信息
	//! \return 返回属性表
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_AttributeQuery")
	TArray<FAttributeInfos> GetDatasetModelSelectionInfos();

	//! \brief 是否查询属性id是否相同
	//! \return true 与上次查询模型不相同刷新数值
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_AttributeQuery")
	bool IsGetDatasetModelSelectionInfos();

	//! \brief 返回查询属性id
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_AttributeQuery")
	int GetSelectionID();

	//云渲染接口
	//! \brief 通过ID获取属性
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_AttributeQuery")
	TArray<FAttributeInfos> GetSelectionInfosByID(FName strLayerName, int nID);

	UFUNCTION(BlueprintCallable, Category = "ASuperMap_AttributeQuery")
	void SetUseWeb(bool bUse);

	//! \brief 获取是否查询属性
	Gamebool GetbSelectionInfos();

	//! \brief 执行多播
	void ExecuteBroadcast();

	//! \brief 设置选中图层句柄与对象ID
	void SetSelectInfo(void* pSelectLayerHandle, Gameint nSelectID);
private:

	 void GetSelectionInfosFromDatasetModel(Layer3DDatasetModel* pLayerDatasetModel, int nID, TArray<FAttributeInfos> & attributeInfos);

	 void GetSelectionInfosFromS3MFile(Layer3DS3MFile* pLayerS3M, int nID, TArray<FAttributeInfos> & attributeInfos);

public:
	UPROPERTY(BlueprintAssignable)
	FAttributeQueryDelegate CallAttributeQuery;

private:
	//! \brief 是否进行属性查询
	bool m_bSelectionInfos;

	//! \brief 选中的模型数据集对象
	ASuperMap_StaticMeshActor* m_pStaticMeshActor;

	//! \brief 上一次点击模型ID
	Gameint m_nLastId;

	//! \brief 判断是否重复点击同一模型
	Gamebool m_bIsSelected;

	//! \brief 是否是云渲染使用
	Gamebool m_bUseWeb;

	//! \brief 选中图层句柄与对象ID
	void* m_pSelectLayerHandle;
	Gameint m_nSelectID;
};
