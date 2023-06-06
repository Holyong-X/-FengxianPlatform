#pragma once

#include "CoreMinimal.h"
#include "Component/MeshData.h"
#include "Data/Matrix4d.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "SuperMap_InstancedStaticMeshComponent.generated.h"

using namespace SuperMapSDK::UnrealEngine::Data;

UCLASS()
class SUPERMAP_API USuperMap_InstancedStaticMeshComponent : public UInstancedStaticMeshComponent
{
	GENERATED_BODY()

public:
	USuperMap_InstancedStaticMeshComponent();
	virtual ~USuperMap_InstancedStaticMeshComponent();

	//! \brief 创建静态网格
	Gamevoid CreateMesh(const FSMMesh & meshData, Gamebool bCollision);

	//! \brief 设置节点名字
	//! \param strName [in] 节点名字
	Gamevoid SetName(FName strName);

	//! \brief 获取节点名字
	//! \return 
	FName GetName();

	//! \brief 设置是否所属图层是否可见
	//! \param bVisible [in] 是否可见
	Gamevoid SetLayerVisibility(Gamebool bIsVisible);

	//! \brief 获取图层可见性
	//! \return 图层可见性
	Gamebool GetLayerVisibility();

	//! \brief 设置节点可见性
	//! \param bVisible [in] 可见性
	Gamevoid SetInternalVisibility(Gamebool bIsVisible);

	//! \brief 获取节点可见性
	//! \param bVisible [in] 可见性
	Gamebool GetInternalVisibility();

	//! \brief 设置材质
	//! \param pMat [in] 材质
	Gamevoid SetCustomMaterial(UMaterialInterface* pMat);

	//! \brief 获取材质
	//! \return 材质
	UMaterialInterface* GetCustomMaterial();

	//! \brief 获取LocalToWorld
	//! \return 矩阵
	Matrix4d GetLocalToWorld();

	//! \brief 设置StaticMesh
	Gamevoid SetCustomStaticMesh(FString strStaticMeshName, UStaticMesh* pStaticMesh);

	//! \brief 更新Transform
	Gamevoid BatchUpdateTransform(Vector3d vOffset);

	//! \brief 设置从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Gamevoid SetLocalToECEF(const Matrix4d& mat);

	//! \brief 获取从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Matrix4d GetLocalToECEF();
private:
	//! \brief 节点名字
	FName m_strName;

	//! \brief 所属节点的可见性
	Gamebool m_bVisible;

	//! \brief 所属图层的可见性
	Gamebool m_bVisibleLayer;

	//! \brief 渲染材质
	UMaterialInterface* m_pMaterial;

	//! \brief LocalToWorld
	Matrix4d m_matDoubleLocalToWorld;

	//! \brief 经过轴变换，但未经过缩放的，原始的从模型局部坐标系到ECEF坐标系的变换矩阵
	Matrix4d m_matLocalToECEF;

	//! \brief 是否启动碰撞检测
	Gamebool m_bCollision;

	//! \brief 是否开启复杂的碰撞检测
	Gamebool m_bUseComplexAsSimpleCollision;

	//! \brief 静态网格的名字
	FString m_strStaticMeshName;

	//! \brief Instance对象的矩阵
	TArray<Matrix4d> m_arrInstanceMatrix;
};