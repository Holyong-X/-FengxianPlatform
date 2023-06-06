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
#include "SuperMap_MeshComponent.generated.h"

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK;

class FSuperMapMeshSceneProxy;

/**
 *
 */
UCLASS()
class SUPERMAP_API USuperMap_MeshComponent : public UMeshComponent , public IInterface_CollisionDataProvider
{
	GENERATED_BODY()

public:
	USuperMap_MeshComponent(const FObjectInitializer& ObjectInitializer);

	//! \brief ��������
	Gamevoid CreateMesh(GameEntity* pGameEntity, Gamebool bCollision);

	//! \brief ��������
	//! \param meshData [in] ��������
	Gamevoid CreateMesh(const FSMMesh & meshData, Gamebool bCollision);

	//! \brief ���±���Bounds
	//! \param meshData [in] ��������
	Gamevoid UpdateLocalBounds(const FSMMesh & meshData);

	//! \brief �����Ƿ�����ͼ���Ƿ�ɼ�
	//! \param bVisible [in] �Ƿ�ɼ�
	Gamevoid SetLayerVisibility(Gamebool bIsVisible);

	//! \brief ��ȡͼ��ɼ���
	//! \return ͼ��ɼ���
	Gamebool GetLayerVisibility() const;

	//! \brief ����ͼ����Ⱦ
	Gamevoid SetRender(Gamebool bIsRender);

	//! \brief ��ȡͼ���Ƿ���Ⱦ
	Gamebool GetRender();

	//! \brief ���ýڵ�ɼ���
	//! \param bVisible [in] �ɼ���
	Gamevoid SetInternalVisibility(Gamebool bIsVisible);

	//! \brief ��ȡ�ڵ�ɼ���
	//! \param bVisible [in] �ɼ���
	Gamebool GetInternalVisibility() const;

	//! \brief ��������
	//! \param meshData [in] ��������
	Gamevoid UpdateMesh(const FSMMesh & meshData , UGVertexDataStateSet nState);

	//! \brief ����ʵ����������ɫ
	Gamevoid UpdateInstanceVertexColor(Gameuint nColor, TArray<uint32>& arrIds);

	//! \brief ��������
	//! \param nType [in] ��������
	Gamevoid SetDrawType(Gameint nType);
	
	//! \brief ��������
	Gamevoid UpdateSubMeshes(TArray<DataIndice*>& arrIndices, TArray<FSuperMapMaterialInterfaceCollection>& arrMaterialCollection);

	//! \brief ���һ�����ʼ��ϣ�����ͬһ�����ʵĸ�����̬��
	Gamevoid AddMaterialCollection(const FSuperMapMaterialInterfaceCollection& materialCollection);
	
	//! \brief ɾ�����һ�����ʼ���
	Gamevoid RemoveLastMaterialCollection(const FSuperMapMaterialInterfaceCollection& materialCollection);


	Gamevoid AddMaterialInterface(UMaterialInterface* pMaterial);

	Gamevoid RemoveMaterialInterface(UMaterialInterface* pMaterial);


	//! \brief MeshComponent Interface
	virtual Gamevoid SetMaterial(Gameint ElementIndex, UMaterialInterface* Material) override;

	//! \brief ��ȡ����ԭʼ����
	Gamevoid GetAllCustomMaterials(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief ��ȡ����ѡ�����
	Gamevoid GetAllSelectionMaterials(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief ��ȡ���ж��ӿڲ���
	Gamevoid GetAllMaterialsInViewport(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief ���ôӾֲ�����ϵת����ECEF����ľ���
	//! \return ����
	Gamevoid SetLocalToECEF(const Matrix4d& mat);

	//! \brief ��ȡ�Ӿֲ�����ϵת����ECEF����ľ���
	//! \return ����
	Matrix4d GetLocalToECEF();

	//! \brief ���ýڵ�����
	//! \param strName [in] �ڵ�����
	Gamevoid SetName(FName strName);

	//! \brief ��ȡ�ڵ�����
	//! \return 
	FName GetName();

	//! \brief ����Tranfrom
	Gamevoid UpdateTransform(Vector3d vOffset, FTransform & transform);

	virtual class UBodySetup* GetBodySetup() override;

	//! \brief ��Ӧ��ʵ�ʲ�������
	FString GetRealMaterialName();
	Gamevoid SetRealMaterialName(FString strRealMaterialName);

	//! \brief ��Ӧ��ʵ�ʲ�������
	FString GetLayerName();
	Gamevoid SetLayerName(FString strLayerName);

	//! \brief ��Ӧ�ķ�������
	Gamevoid SetVisibleInViewport(Gameint nIndex, Gamebool bVisible);
	Gamebool GetVisibleInViewport(Gameint nIndex);

	//! \brief ������Ⱦʹ�õĲ�������
	Gamevoid SetUseMaterialFlag(UseMaterialFlag enUseMaterialFlag);

	//! \brief ����/��ȡ �����޳�
	Gamevoid SetReverseCulling(Gamebool bReverseCulling);
	Gamebool GetReverseCulling() const;
private:

	//~ Begin Interface_CollisionDataProvider Interface
	virtual Gamebool GetPhysicsTriMeshData(struct FTriMeshCollisionData* CollisionData, Gamebool InUseAllTriData) override;
	virtual Gamebool ContainsPhysicsTriMeshData(Gamebool InUseAllTriData) const override;
	virtual Gamebool WantsNegXTriMesh() override { return false; }
	//~ End Interface_CollisionDataProvider Interface

	//! \brief ������ײ����
	Gamevoid UpdateCollider();
	Gamevoid CreateCollisionData();
	Gamevoid ClearCollider();

	//! \brief ����localbounds
	Gamevoid CalLocalBound(const FSMMesh & smMesh);

	Gamevoid FinishPhysicsAsyncCook(Gamebool bSuccess, UBodySetup* FinishedBodySetup);
	UBodySetup* CreateBodySetupHelper();

	// USceneComponent
	FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;

	// UPrimitiveComponent
	FPrimitiveSceneProxy* CreateSceneProxy() override;
	Gameint GetNumMaterials() const override;

	FBoxSphereBounds m_LocalBounds;
	FSMMesh m_MeshData;

	//! \brief �Ƿ������ӵ���ײ���
	Gamebool m_bUseComplexAsSimpleCollision;

	//! \brief ��ײ�������
	UBodySetup* m_pBodySetup;

	//! \brief ��ײ����
	FSMMeshCollisionData m_CollisionData;

	//! \brief ����ͼ��Ŀɼ���
	Gamebool m_bVisibleLayer;

	//! \brief ����ͼ���Ƿ���Ⱦ
	Gamebool m_bRender;

	//! \brief �����ڵ�Ŀɼ���
	Gamebool m_bVisible;

	//! \brief �ڵ�����
	FName m_strName;

	//! \brief ���Ʒ�ʽ
	Gameint m_nDrawType;

	//! \brief ��Ⱦ�ڵ�
	FSuperMapMeshSceneProxy* m_pSceneProxy;

	//! \brief ��Ⱦ����
	TArray<FSuperMapMaterialInterfaceCollection> m_arrMaterialCollection;

	//! \brief ���еĲ�����
	Gameint m_nMaterialNum;

	//! \brief ���ò�������
	Gamelong m_nMaterialName;

	//! \brief ������任����δ�������ŵģ�ԭʼ�Ĵ�ģ�;ֲ�����ϵ��ECEF����ϵ�ı任����
	Matrix4d m_matLocalToECEF;
	
	//! \brief ʵ�ʲ�������
	FString m_strRealMaterialName;

	//! \brief ͼ������
	FString m_strLayerName;

	//! \brief ��֧��2��
	Gamebool m_bVisibleInViewport[2];

	//! \brief �Ƿ��ʼ��
	Gamebool m_bInitial;

	//! \brief ���²����б�
	TArray<UMaterialInterface*> m_arrUsedMaterials;

	//! \brief �Ƿ����޳�
	Gamebool m_bReverseCulling;
};
