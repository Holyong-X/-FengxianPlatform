// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/Matrix4d.h"
#include "Core/ROCacheManager.h"
#include "Core/RealspaceDLL.h"
#include "Graphics3D/GameStruct.h"
#include "SuperMap_ROEntityActor.generated.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK;

class USMMesh;
class USuperMap_ProceduralMeshComponent;
class USuperMap_LineMeshComponent;
class USuperMap_MeshComponent;

UCLASS()
class SUPERMAP_API ASuperMap_ROEntityActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASuperMap_ROEntityActor();
	~ASuperMap_ROEntityActor();

	//! 创建程序化网格
	Gamevoid CreateProceduralMesh(
		SuperMapSDK::DataVertex* pDataVertex,
		SuperMapSDK::DataIndice* pDataIndice,
		UMaterialInterface* pMat);

	// 创建程序化网格
	Gamevoid CreateProceduralMesh(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs, const Matrix4d& objectMatrix);

	// 创建程序化网格
	Gamevoid CreateProceduralMesh(SuperMapSDK::DataVertex* pDataVertex, TArray<SM_SubMesh>& arrSubMeshs);

	// 创建程序化网格
	Gamevoid CreateProceduralMesh(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs );

	// 创建程序化网格
	Gamevoid CreateLineMeshComponent(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs);
	
	//! \brief 清除所用网格
	Gamevoid ClearMesh();

	//! \brief 是否开启检测碰撞
	Gamevoid SetCollision(Gamebool bEable);

	//! \brief 获取是否检测碰撞
	Gamebool GetCollision();

	//! \brief 每帧调用
	virtual Gamevoid Tick(Gamefloat DeltaTime) override;

	//! \brief 设置LocalToWorld
	Gamevoid SetLocalToWorld(Matrix4d & mat);

	//! \brief 获取LocalToWorld
	Matrix4d GetLocalToWorld();

	//! \brief 设置程序网格体
	Gamevoid SetProceduralMeshComponent(USuperMap_ProceduralMeshComponent* pProceduralMeshComponent);

	//! \brief 获取程序网格体
	USuperMap_ProceduralMeshComponent* GetProceduralMeshComponent();

	//! \brief 获取材质
	UMaterialInterface* GetMaterial();

	//! \brief 设置材质
	Gamevoid SetMaterial(UMaterialInterface* pMaterial);

	//! \brief 设置绘制类型
	Gamevoid SetDrawType(Gameint m_nDrawType);

	//! \brief 设置是否是网格节点
	Gamevoid SetIsMeshNode(Gamebool bMeshNode);

	//! \brief 获取网格节点
	Gamebool GetIsMeshNode();

	//! \brief 设置世界原点
	Gamevoid SetWorldOrigin(FIntVector & vIntOrigin);

	//! \brief 获取世界原点
	FIntVector GetWorldOrigin();

	//! \brief 设置EntityNodeName
	Gamevoid SetName(FName strName);

	//! \brief 获取EntityNodeName
	FName GetName();

	//! \brief 设置图层可见性
	Gamevoid SetVisibleLayer(Gamebool bVisible);

	//! \brief 获取图层可见性
	Gamebool GetVisibleLayer();

	//! \brief 设置为隐藏对象
	Gamevoid SetIsSceneHiddenObject(Gamebool bHiddenObject);

	//! \brief 更新世界原点
	Gamevoid UpdateWorldOrigin();
protected:
	//! \brief 当游戏场景运行或者创建（Spawn）的时候调用
	virtual Gamevoid BeginPlay() override;

	//! \brief 世界坐标的偏移
	virtual Gamevoid ApplyWorldOffset(const FVector& InOffset, Gamebool bWorldShift);

private:
	//! \brief 是否是网格节点
	Gamebool m_bIsMeshNode;

	//! \brief 世界的偏移矩阵
	FIntVector m_vecWorldOffset;

	//! \brief 程序化网格体
	USuperMap_ProceduralMeshComponent* m_pProceduralMeshCom;

	//! \brief 线类型网格组件
	USuperMap_LineMeshComponent* m_pLineMeshCom;

	//! \brief 材质
	UMaterialInterface* m_pMaterial;

	//! \brief Name
	FName m_strName;

	//! \brief 绘制类型
	Gameint m_nDrawType;

	//! \brief 是否碰撞检测
	Gamebool m_bCollision;

	//! \brief 图层可见
	Gamebool m_bVisibleLayer;

	//! \brief LocalToWorld
	Matrix4d m_matDoubleLocalToWorld;

	//! \brief 隐藏列表中的位置
	Gameint m_nHiddenIndex;

	//! \brief 绘制线参数
	TArray<SM_Vertex> m_arrLineVtxs;
	TArray<SM_SubMesh> m_arrLineSubMeshs;
};
