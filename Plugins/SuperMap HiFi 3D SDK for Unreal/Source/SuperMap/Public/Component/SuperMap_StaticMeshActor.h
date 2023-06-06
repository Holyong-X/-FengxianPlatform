// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Engine/StaticMeshActor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Core/RealspaceDLL.h"
#include "SuperMap_StaticMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class SUPERMAP_API ASuperMap_StaticMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	ASuperMap_StaticMeshActor();
public:
	//! \brief 实例化静态网格组件
	UPROPERTY(Category = StaticMeshActor, EditAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Mesh,Rendering,Physics,Components|StaticMesh", AllowPrivateAccess = "true"))
	TArray<UInstancedStaticMeshComponent*> InstancedStaticMeshComponents;

	//! \brief 静态网格组件
	UPROPERTY(Category = StaticMeshActor, EditAnywhere , BlueprintReadOnly, meta = (ExposeFunctionCategories = "Mesh,Rendering,Physics,Components|StaticMesh", AllowPrivateAccess = "true"))
	TArray<UStaticMeshComponent*> StaticMeshComponents;
	
	//! \brief 静态网格组件矩阵
	UPROPERTY(Category = StaticMeshActor, EditAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Mesh,Rendering,Physics,Components|StaticMesh", AllowPrivateAccess = "true"))
	TArray<FMatrix> m_arrMatrixs;

	//! \brief 材质
	UPROPERTY(Category = StaticMeshActor, EditAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Model Material", AllowPrivateAccess = "true"))
	TMap<FString, UMaterialInstanceConstant*> m_mapMaterials;

	//! \brief 数据源名称
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StaticMeshActor)
	FString m_strDataSourceName;

	//! \brief 数据集名称
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StaticMeshActor)
	FString m_strDatasetName;

	//! \brief 数据集对象ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StaticMeshActor)
	FString m_strSMID;

	//! \brief 属性
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "属性查询")
	TMap<FString, FString> AttributeQuery;

	UFUNCTION(BlueprintCallable, CallInEditor, Category = StaticMeshActor)
	void UDB_ModelSave();

	//! \brief 是否被选中
	Gamebool m_bSelected;
protected:
	virtual Gamebool ShouldTickIfViewportsOnly() const override;

	//! \brief 查询接口
	Gamevoid QueryAttritute();

public:
	// Called every frame
	virtual Gamevoid Tick(Gamefloat DeltaTime) override;
};
