#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#if !SM_FOR_UE_FIVE_1
#include "IPhysXCookingModule.h"
#endif
#include "Component/MeshData.h"
#include "Data/Matrix4d.h"
#include "Interfaces/Interface_CollisionDataProvider.h"
#include "SuperMap_StaticMeshComponent.generated.h"

using namespace SuperMapSDK::UnrealEngine::Data;

class UMaterialInterface;
class FStaticMeshRenderData;

struct StaticMeshRenderData
{
public:
	FStaticMeshRenderData* m_pRenderData;

#if PHYSICS_INTERFACE_PHYSX
	PxTriangleMesh* pCollisionMesh;
#else
	TSharedPtr<Chaos::FTriangleMeshImplicitObject, ESPMode::ThreadSafe>
		pCollisionMesh;
#endif
};


UCLASS()
class SUPERMAP_API USuperMap_StaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	USuperMap_StaticMeshComponent();
	virtual ~USuperMap_StaticMeshComponent();

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

	//! \brief 设置图层渲染
	Gamevoid SetRender(Gamebool bIsRender);

	//! \brief 获取图层是否渲染
	Gamebool GetRender();

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

	//! \brief 设置从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Gamevoid SetLocalToECEF(const Matrix4d& mat);

	//! \brief 获取从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Matrix4d GetLocalToECEF();

	//! \brief 更新Tranfrom
	Gamevoid UpdateTransform(Vector3d vOffset, FTransform & transform);

private:
	//! \brief 创建静态网格渲染对象
	Gamevoid CreateStaticMeshRenderData(const FSMMesh & meshData, StaticMeshRenderData & smrd);

	Gamevoid ComputeBoundingSphere(const FSMMesh& meshData, FBoxSphereBounds& boundingBoxAndSphere);

	//! \brief 解压
	Gamevoid DecodeDataPackage(const FSMMesh & meshData);
private:
	//! \brief 节点名字
	FName m_strName;

	//! \brief 所属节点的可见性
	Gamebool m_bVisible;

	//! \brief 所属图层的可见性
	Gamebool m_bVisibleLayer;

	//! \brief 所属图层是否渲染
	Gamebool m_bRender;

	//! \brief 渲染材质
	UMaterialInterface* m_pMaterial;

	//! \brief 原始的从模型局部坐标系到ECEF坐标系的变换矩阵
	Matrix4d m_matLocalToECEF;

	//! \brief 是否启动碰撞检测
	Gamebool m_bCollision;

	//! \brief 是否开启复杂的碰撞检测
	Gamebool m_bUseComplexAsSimpleCollision;

#if PHYSICS_INTERFACE_PHYSX
	IPhysXCooking* m_pPhysXCooking;
#endif

	//! \brief 绘制方式
	EPrimitiveType m_eDrawType;
};