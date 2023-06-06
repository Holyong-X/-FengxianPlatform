// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Data/Matrix4d.h"
#include "Components/MeshComponent.h"
#include "Component/MeshData.h"
#include "Graphics3D/GameEnum.h"
#include "Graphics3D/GameEntity.h"
#include "SuperMap_LineMeshComponent.generated.h"

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK;

class FSuperMapLineMeshSceneProxy;
class FSuperMapLineVertexBuffer;

/**
 *
 */
UCLASS()
class SUPERMAP_API USuperMap_LineMeshComponent : public UMeshComponent
{
	GENERATED_BODY()

public:
	USuperMap_LineMeshComponent(const FObjectInitializer& ObjectInitializer);

	//! \brief 创建网格
	Gamevoid CreateEdgeLineMesh(GameEntity* pGameEntity, Gamebool bCollision);

	//! \brief 创建网格
	//! \param meshData [in] 网格数据
	Gamevoid CreateEdgeLineMesh(const FSMMesh& meshData, Gamebool bCollision);

	//! \brief 创建网格
	//! \param meshData [in] 网格数据
	Gamevoid CreateSimpleLineMesh(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs);

	//! \brief 更新本地Bounds
	//! \param meshData [in] 网格数据
	Gamevoid UpdateLocalBounds(const FSMMesh & meshData);

	//! \brief 设置是否所属图层是否可见
	//! \param bVisible [in] 是否可见
	Gamevoid SetLayerVisibility(Gamebool bIsVisible);

	//! \brief 获取图层可见性
	//! \return 图层可见性
	Gamebool GetLayerVisibility();

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

	//! \brief 设置材质
	//! \param pMat [in] 材质
	Gamevoid SetCustomMaterial(UMaterialInterface* pMat);

	//! \brief 获取材质
	//! \return 材质
	UMaterialInterface* GetCustomMaterial();

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
	Gamevoid UpdateTransform(Vector3d vOffset, FTransform & transform);

	//! \brief 对应的实际材质名称
	//FString GetRealMaterialName();
	//Gamevoid SetRealMaterialName(FString strRealMaterialName);

	//! \brief 对应的分屏显隐
	Gamevoid SetVisibleInViewport(Gameint nIndex, Gamebool bVisible);
	Gamebool GetVisibleInViewport(Gameint nIndex);

private:
	//! \brief 计算localbounds
	Gamevoid CalLocalBound(const FSMMesh& smMesh);

	// USceneComponent
	FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;

	// UPrimitiveComponent
	FPrimitiveSceneProxy* CreateSceneProxy() override;
	Gameint GetNumMaterials() const override;

	FBoxSphereBounds m_LocalBounds;

	//! \brief 所属图层的可见性
	Gamebool m_bVisibleLayer;

	//! \brief 所属图层是否渲染
	Gamebool m_bRender;

	//! \brief 所属节点的可见性
	Gamebool m_bVisible;

	//! \brief 节点名字
	FName m_strName;

	FSuperMapLineMeshSceneProxy* m_pSceneProxy;

	//! \brief 渲染材质
	UMaterialInterface* m_pMaterial;

	//! \brief 经过轴变换，但未经过缩放的，原始的从模型局部坐标系到ECEF坐标系的变换矩阵
	Matrix4d m_matLocalToECEF;

	//! \brief 先支持2屏
	Gamebool m_bVisibleInViewport[2];

	//! \brief 是否初始化
	Gamebool m_bInitial;

	FSMMesh m_MeshData;

	TArray<SM_Vertex> m_arrLineVertex;
	TArray<SM_SubMesh> m_arrLineSubMesh;

};
