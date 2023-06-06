#pragma once

#include "CoreMinimal.h"
#include "Data/Matrix4d.h"
#include "Components/MeshComponent.h"
#include "Component/SuperMap_MaterialBillboardComponent.h"
#include "Core/ROCache.h"
#include "Component/MeshData.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_BillboardComponent.generated.h"

using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Data;

UCLASS()
class SUPERMAP_API USuperMap_BillboardComponent : public UMeshComponent
{
	GENERATED_BODY()

public:
	USuperMap_BillboardComponent();
	//! \brief 创建网格
	//! \param meshData [in] 原始数据
	//! \param pMat [in] 使用的材质
	//! \param bCollision [in] 是否创建碰撞体
	Gamevoid CreateMesh(const FSMMesh& meshData, Gamebool bCollision);

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

	//! \brief 设置Second材质
	//! \param pMat [in] 材质
	Gamevoid SetCustomSecondMaterial(UMaterialInterface* pMat);

	//! \brief 获取材质
	//! \return 材质
	UMaterialInterface* GetCustomSecondMaterial();

	//! \brief 获取LocalToWorld
	//! \return 矩阵
	Matrix4d GetLocalToWorld();

	//! brief 更新Transform
	Gamevoid UpdateTransform(Vector3d vOffset, FTransform & transform);

	//! \brief 设置纹理
	Gamevoid SetBillboardParam(Gameint nBaseSizeX, Gameint nBaseSizeY, Matrix4d matTexcoord);
	Gamevoid SetTexture(UTexture2D* pTexture);

	//! \brief 设置从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Gamevoid SetLocalToECEF(const Matrix4d& mat);

	//! \brief 获取从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Matrix4d GetLocalToECEF();

private:

	//! \brief 节点名字
	FName m_strName;

	//! \brief 所属图层的可见性
	Gamebool m_bVisibleLayer;

	//! \brief 所属节点的可见性
	Gamebool m_bVisible;

	//! \brief 渲染材质
	UMaterialInterface* m_pMaterial;

	//! \brief Second渲染材质
	UMaterialInterface* m_pSecondMaterial;

	//! \brief LocalToWorld
	Matrix4d m_matDoubleLocalToWorld;

	//! \brief 经过轴变换，但未经过缩放的，原始的从模型局部坐标系到ECEF坐标系的变换矩阵
	Matrix4d m_matLocalToECEF;

	//! \brief BillboardComponents
	TArray<USuperMap_MaterialBillboardComponent*> m_arrBillboardComponents;

	//! \brief 纹理的基础大小
	Gameint m_nBaseSizeX;
	Gameint m_nBaseSizeY;

	//! \biref 纹理矩阵
	Matrix4d m_matTexcoord;
};