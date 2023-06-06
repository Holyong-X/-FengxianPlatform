// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Data/Matrix4d.h"
#include "Components/MeshComponent.h"
#include "Core/ROCache.h"
#include "Component/MeshData.h"
#include "Graphics3D/GameEnum.h"
#include "Graphics3D/GameEntity.h"
#include "Interfaces/Interface_CollisionDataProvider.h"
#include "SuperMap_PolyLineMeshComponent.generated.h"

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK;

class FSuperMapPolyLineMeshSceneProxy;

/**
 *
 */
UCLASS()
class SUPERMAP_API USuperMap_PolyLineMeshComponent : public UMeshComponent, public IInterface_CollisionDataProvider
{
	GENERATED_BODY()

public:
	USuperMap_PolyLineMeshComponent(const FObjectInitializer& ObjectInitializer);

	//! \brief 创建网格
	Gamevoid CreateMesh(GameEntity* pGameEntity, Gamebool bCollision);

	//! \brief 创建网格
	//! \param meshData [in] 网格数据
	Gamevoid CreateMesh(const FSMMesh& meshData, Gamebool bCollision);

	//! \brief 更新本地Bounds
	//! \param meshData [in] 网格数据
	Gamevoid UpdateLocalBounds(const FSMMesh& meshData);

	//! \brief 设置是否所属图层是否可见
	//! \param bVisible [in] 是否可见
	Gamevoid SetLayerVisibility(Gamebool bIsVisible);

	//! \brief 获取图层可见性
	//! \return 图层可见性
	Gamebool GetLayerVisibility() const;

	//! \brief 设置图层渲染
	Gamevoid SetRender(Gamebool bIsRender);

	//! \brief 获取图层是否渲染
	Gamebool GetRender();

	//! \brief 设置节点可见性
	//! \param bVisible [in] 可见性
	Gamevoid SetInternalVisibility(Gamebool bIsVisible);

	//! \brief 获取节点可见性
	//! \param bVisible [in] 可见性
	Gamebool GetInternalVisibility() const;

	//! \brief 更新网格
	//! \param meshData [in] 网格数据
	Gamevoid UpdateMesh(const FSMMesh& meshData, UGVertexDataStateSet nState);

	//! \brief 更新实例化顶点颜色
	Gamevoid UpdateInstanceVertexColor(Gameuint nColor, TArray<Gameuint>& arrIds);

	//! \brief 绘制类型
	//! \param nType [in] 绘制类型
	Gamevoid SetDrawType(Gameint nType);

	//! \brief 更新索引
	Gamevoid UpdateSubMeshes(TArray<DataIndice*>& arrIndices, TArray<FSuperMapMaterialInterfaceCollection>& arrMaterialCollection);

	//! \brief 添加一个材质集合（包含同一个材质的各种形态）
	Gamevoid AddMaterialCollection(const FSuperMapMaterialInterfaceCollection& materialCollection);

	//! \brief 删除最后一个材质集合
	Gamevoid RemoveLastMaterialCollection(const FSuperMapMaterialInterfaceCollection& materialCollection);

	//! \brief MeshComponent Interface
	virtual Gamevoid SetMaterial(Gameint ElementIndex, UMaterialInterface* Material) override;

	//! \brief 获取所有原始材质
	Gamevoid GetAllCustomMaterials(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief 获取所有选择材质
	Gamevoid GetAllSelectionMaterials(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief 获取所有多视口材质
	Gamevoid GetAllMaterialsInViewport(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief 设置从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Gamevoid SetLocalToECEF(const Matrix4d& mat);

	//! \brief 获取从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Matrix4d GetLocalToECEF();

	//! \brief 设置节点名字
	//! \param strName [in] 节点名字
	Gamevoid SetName(FName strName);

	//! \brief 获取节点名字
	//! \return 
	FName GetName();

	//! \brief 更新Tranfrom
	Gamevoid UpdateTransform(Vector3d vOffset, FTransform& transform);

	virtual class UBodySetup* GetBodySetup() override;

	//! \brief 对应的实际材质名称
	FString GetRealMaterialName();
	Gamevoid SetRealMaterialName(FString strRealMaterialName);

	//! \brief 对应的实际材质名称
	FString GetLayerName();
	Gamevoid SetLayerName(FString strLayerName);

	//! \brief 对应的分屏显隐
	Gamevoid SetVisibleInViewport(Gameint nIndex, Gamebool bVisible);
	Gamebool GetVisibleInViewport(Gameint nIndex);

	//! \brief 设置渲染使用的材质类型
	Gamevoid SetUseMaterialFlag(UseMaterialFlag enUseMaterialFlag);

	//! \brief 设置/获取 反向剔除
	Gamevoid SetReverseCulling(Gamebool bReverseCulling);
	Gamebool GetReverseCulling() const;
private:

	//~ Begin Interface_CollisionDataProvider Interface
	virtual Gamebool GetPhysicsTriMeshData(struct FTriMeshCollisionData* CollisionData, Gamebool InUseAllTriData) override;
	virtual Gamebool ContainsPhysicsTriMeshData(Gamebool InUseAllTriData) const override;
	virtual Gamebool WantsNegXTriMesh() override { return false; }
	//~ End Interface_CollisionDataProvider Interface

	//! \brief 计算localbounds
	Gamevoid CalLocalBound(const FSMMesh& smMesh);

	Gamevoid FinishPhysicsAsyncCook(Gamebool bSuccess, UBodySetup* FinishedBodySetup);
	UBodySetup* CreateBodySetupHelper();

	// USceneComponent
	FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;

	// UPrimitiveComponent
	FPrimitiveSceneProxy* CreateSceneProxy() override;
	Gameint GetNumMaterials() const override;

	FBoxSphereBounds m_LocalBounds;
	FSMMesh m_MeshData;

	//! \brief 是否开启复杂的碰撞检测
	Gamebool m_bUseComplexAsSimpleCollision;

	//! \brief 碰撞检测属性
	UBodySetup* m_pBodySetup;

	//! \brief 碰撞网格
	FSMMeshCollisionData m_CollisionData;

	//! \brief 所属图层的可见性
	Gamebool m_bVisibleLayer;

	//! \brief 所属图层是否渲染
	Gamebool m_bRender;

	//! \brief 所属节点的可见性
	Gamebool m_bVisible;

	//! \brief 节点名字
	FName m_strName;

	//! \brief 绘制方式
	Gameint m_nDrawType;

	//! \brief 渲染节点
	FSuperMapPolyLineMeshSceneProxy* m_pSceneProxy;

	//! \brief 渲染材质
	TArray<FSuperMapMaterialInterfaceCollection> m_arrMaterialCollection;

	//! \brief 所有的材质数
	Gameint m_nMaterialNum;

	//! \brief 设置材质名称
	__int64 m_nMaterialName;

	//! \brief 经过轴变换，但未经过缩放的，原始的从模型局部坐标系到ECEF坐标系的变换矩阵
	Matrix4d m_matLocalToECEF;

	//! \brief 实际材质名称
	FString m_strRealMaterialName;

	//! \brief 图层名称
	FString m_strLayerName;

	//! \brief 先支持2屏
	Gamebool m_bVisibleInViewport[2];

	//! \brief 是否初始化
	Gamebool m_bInitial;

	//! \brief 更新材质列表
	TArray<UMaterialInterface*> m_arrUsedMaterials;

	//! \brief 是否反向剔除
	Gamebool m_bReverseCulling;
};
