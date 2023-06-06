#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Component/MeshData.h"
#include "Component/SuperMap_MeshComponent.h"
#include "Component/SuperMap_StaticMeshComponent.h"
#include "Component/CustomRealRasterMesh.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEnum.h"
#include "Graphics3D/GameEntity.h"
#include "Core/RealspaceDLL.h"
#include "SuperMap_MeshComponentInterface.generated.h"

using namespace SuperMapSDK;

enum ComponentType
{
	CustomNone,
	CustomMeshComponent,
	CustomStaticMeshComponent,
	CustomInstancedStaticMeshComponent,
	CustomBillboardComponent,
	CustomRealTimeRaster,
	CustomEdgeLineComponent,
	CustomPolyLineComponent
};

// 这个类为不同类型的Mesh提供一个共同的外部接口，他实际是一个USceneComponent，持有UMeshComponent
UCLASS()
class USuperMap_MeshComponentInterface : public USceneComponent
{
	GENERATED_BODY()
public:
	USuperMap_MeshComponentInterface();
	virtual ~USuperMap_MeshComponentInterface();

	//! \brief 创建网格
	Gamevoid CreateMesh(GameEntity* pGameEntity, Gamebool bCollision);

	//! \brief 创建网格
	//! \param meshData [in] 原始数据
	//! \param pMat [in] 使用的材质
	//! \param bCollision [in] 是否创建碰撞体
	Gamevoid CreateMesh(const FSMMesh& meshData, Gamebool bCollision);

	//! \brief 更新网格信息
	Gamevoid UpdateMesh(const FSMMesh & meshData, UGVertexDataStateSet nState);

	//! \brief 实例化数据的顶点颜色
	Gamevoid UpdateInstanceVertexColor(Gameuint nColor, TArray<uint32>& arrIds);

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

	//! \brief 设置从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Gamevoid SetLocalToECEF(const Matrix4d& mat);

	//! \brief 获取从局部坐标系转换到ECEF坐标的矩阵
	//! \return 矩阵
	Matrix4d GetLocalToECEF();
	
	//! \brief 创建MeshComponent
	Gamevoid CreateMeshComponent(ComponentType eComType, AActor* pActor);
	Gamevoid CreateMeshComponent(ComponentType eComType);
	UPrimitiveComponent* GetMeshComponent();
	
	CustomRealRasterMesh* GetRealRasterMesh();

	Gamevoid ReleaseMeshComponent();

	//! \brief 获取挂接的纯SceneComponent类型子节点，不包含meshComponent子节点
	TArray<USceneComponent*> GetAttachSceneComponentChildren();

	//! \brief 设置StaticMesh
	Gamevoid SetCustomStaticMesh(FString strStaticMeshName, UStaticMesh* pStaticMesh);

	//! \brief 获取组件类型
	ComponentType GetComponentType();

	//! brief 更新Transform
	Gamevoid UpdateTransfrom(Vector3d vOffset);

	//! \brief 设置纹理
	Gamevoid SetBillboardParam(Gameint nBaseSizeX, Gameint nBaseSizeY, Matrix4d matTexcoord);
	Gamevoid SetTexture(UTexture2D* pTexture2D);

	//! \brief 对应的实际材质名称
	FString GetRealMaterialName();
	Gamevoid SetRealMaterialName(FString strRealMaterialName);

	//! \brief 对应的实际材质名称
	FString GetLayerName();
	Gamevoid SetLayerName(FString strLayerName);

	//! \brief 对应的分屏显隐
	Gamevoid SetVisibleInViewport(Gameint nIndex, Gamebool bVisible);
	Gamebool GetVisibleInViewport(Gameint nIndex);

	//! \brief 添加索引
	Gamevoid UpdateSubMeshes(TArray<DataIndice*>& m_arrIndexs, TArray<FSuperMapMaterialInterfaceCollection>& arrMaterialCollection);

	//! \brief 添加一个材质集合（包含同一个材质的各种形态）
	Gamevoid AddMaterialCollection(const FSuperMapMaterialInterfaceCollection& materialCollection);

	//! \brief 删除最后一个材质集合
	Gamevoid RemoveLastMaterialCollection(const FSuperMapMaterialInterfaceCollection& lastMaterialCollection);


	Gamevoid AddMaterialInterface(UMaterialInterface* pMaterial);

	Gamevoid RemoveMaterialInterface(UMaterialInterface* pMaterial);

	//! \brief 获取原始材质
	Gamevoid GetAllCustomMaterials(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief 获取选择材质
	Gamevoid GetAllSelectionMaterials(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief 获取多视口材质
	Gamevoid GetAllMaterialsInViewport(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief 获取材质使用标志
	Gamevoid SetUseMaterialFlag(UseMaterialFlag enUseMaterialFlag);
	UseMaterialFlag GetUseMaterialFlag();

	//! \brief 获取是否反向剔除
	Gamevoid SetReverseCulling(Gamebool bReverseCulling);
private:
	UPrimitiveComponent* m_pMeshComponent;
	Gamebool m_bStatic;

	ComponentType m_eComponentType;

	CustomRealRasterMesh* m_pCustomRealRasterMesh;

	//! \brief 对象变换矩阵
	Matrix4d m_localToECEF;

	UseMaterialFlag m_enUseMaterialFlag;

	//! \brief 节点显隐
	Gamebool m_bInternalVisibility;

	//! \brief 多视口显隐
	Gamebool m_bVisibleInViewport[2];


	Gamebool m_bLayerVisible;

	//! \brief 是否反向剔除
	Gamebool m_bReverseCulling;

	FString m_strLayerName;
};