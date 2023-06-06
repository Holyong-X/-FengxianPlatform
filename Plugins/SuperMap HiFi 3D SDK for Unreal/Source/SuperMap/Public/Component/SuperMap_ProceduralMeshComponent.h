// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "ProceduralMeshComponent.h"
#include "Core/ROCache.h"
#include "Data/Matrix4d.h"
#include "Core/RealspaceDLL.h"
#include "SuperMap_ProceduralMeshComponent.generated.h"

using namespace SuperMapSDK::UnrealEngine::Data;

class UMaterialInterface;
class FMyProceduralMeshSceneProxy;
/**
 *
 */
UCLASS()
class SUPERMAP_API USuperMap_ProceduralMeshComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()

public:
	USuperMap_ProceduralMeshComponent(const FObjectInitializer& ObjectInitializer);

	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;

	//! \brief 创建程序化网格
	//! \param pDataVertex [in] 顶点包
	//! \param pDataIndice [in] 顶点索引
	Gamevoid CreateProceduralMesh(
		SuperMapSDK::DataVertex* pDataVertex, 
		SuperMapSDK::DataIndice* pDataIndice,
		UMaterialInterface* pMat);

	//! \brief 设置节点名字
	//! \param strName [in] 节点名字
	Gamevoid SetName(FName strName);

	//! \brief 获取节点名字
	//! \return 
	FName GetName();

	//! \brief 绘制类型
	//! \param nType [in] 绘制类型
	Gamevoid SetDrawType(Gameint nType);

	//! \brief 刷新是否组件碰撞
	//! \param bEnable [in] 更新
	Gamevoid UpdateComponentCollision(Gamebool bEnable);

	//! \brief 设置是否可见
	//! \param bVisible [in] 是否可见
	Gamevoid SetInternalVisibity(Gamebool bVisible);

	//! \brief 设置是否所属图层是否可见
	//! \param bVisible [in] 是否可见
	Gamevoid SetLayerVisibity(Gamebool bVisible);

	//! \brief 获取图层可见性
	//! \return 图层可见性
	Gamebool GetLayerVisibity();

	//! \brief 删除所有的section
	Gamevoid Clear();

	//! \brief 设置是否创建碰撞网格体
	//! \param bCollision [in] 是否碰撞
	Gamevoid SetCollision(Gamebool bCollision);

	//! \brief 设置材质
	//! \param pMat [in] 材质
	Gamevoid SetCustomMaterial(UMaterialInterface* pMat);

	//! \brief 获取材质
	//! \return 材质
	UMaterialInterface* GetCustomMaterial();

	//! \brief 获取LocalToWorld
	//! \return 矩阵
	Matrix4d GetLocalToWorld();
private:

	//! \brief 是否创建碰撞网格体
	Gamebool m_bCollision;

	//! \brief 绘制方式
	Gameint m_nDrawType;

	//! \brief 本身节点的可见性
	Gamebool m_bVisible;

	//! \brief 所属图层的可见性
	Gamebool m_bVisibleLayer;

	//! \brief 节点名字
	FName m_strName;

	//! \brief 渲染节点
	FMyProceduralMeshSceneProxy* m_pSceneProxy;

	//! \brief 渲染材质
	UMaterialInterface* m_pMaterial;

	//! \brief LocalToWorld
	Matrix4d m_matDoubleLocalToWorld;

	friend class FMyProceduralMeshSceneProxy;
};
