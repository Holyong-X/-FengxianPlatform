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

	//! ������������
	Gamevoid CreateProceduralMesh(
		SuperMapSDK::DataVertex* pDataVertex,
		SuperMapSDK::DataIndice* pDataIndice,
		UMaterialInterface* pMat);

	// ������������
	Gamevoid CreateProceduralMesh(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs, const Matrix4d& objectMatrix);

	// ������������
	Gamevoid CreateProceduralMesh(SuperMapSDK::DataVertex* pDataVertex, TArray<SM_SubMesh>& arrSubMeshs);

	// ������������
	Gamevoid CreateProceduralMesh(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs );

	// ������������
	Gamevoid CreateLineMeshComponent(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs);
	
	//! \brief �����������
	Gamevoid ClearMesh();

	//! \brief �Ƿ��������ײ
	Gamevoid SetCollision(Gamebool bEable);

	//! \brief ��ȡ�Ƿ�����ײ
	Gamebool GetCollision();

	//! \brief ÿ֡����
	virtual Gamevoid Tick(Gamefloat DeltaTime) override;

	//! \brief ����LocalToWorld
	Gamevoid SetLocalToWorld(Matrix4d & mat);

	//! \brief ��ȡLocalToWorld
	Matrix4d GetLocalToWorld();

	//! \brief ���ó���������
	Gamevoid SetProceduralMeshComponent(USuperMap_ProceduralMeshComponent* pProceduralMeshComponent);

	//! \brief ��ȡ����������
	USuperMap_ProceduralMeshComponent* GetProceduralMeshComponent();

	//! \brief ��ȡ����
	UMaterialInterface* GetMaterial();

	//! \brief ���ò���
	Gamevoid SetMaterial(UMaterialInterface* pMaterial);

	//! \brief ���û�������
	Gamevoid SetDrawType(Gameint m_nDrawType);

	//! \brief �����Ƿ�������ڵ�
	Gamevoid SetIsMeshNode(Gamebool bMeshNode);

	//! \brief ��ȡ����ڵ�
	Gamebool GetIsMeshNode();

	//! \brief ��������ԭ��
	Gamevoid SetWorldOrigin(FIntVector & vIntOrigin);

	//! \brief ��ȡ����ԭ��
	FIntVector GetWorldOrigin();

	//! \brief ����EntityNodeName
	Gamevoid SetName(FName strName);

	//! \brief ��ȡEntityNodeName
	FName GetName();

	//! \brief ����ͼ��ɼ���
	Gamevoid SetVisibleLayer(Gamebool bVisible);

	//! \brief ��ȡͼ��ɼ���
	Gamebool GetVisibleLayer();

	//! \brief ����Ϊ���ض���
	Gamevoid SetIsSceneHiddenObject(Gamebool bHiddenObject);

	//! \brief ��������ԭ��
	Gamevoid UpdateWorldOrigin();
protected:
	//! \brief ����Ϸ�������л��ߴ�����Spawn����ʱ�����
	virtual Gamevoid BeginPlay() override;

	//! \brief ���������ƫ��
	virtual Gamevoid ApplyWorldOffset(const FVector& InOffset, Gamebool bWorldShift);

private:
	//! \brief �Ƿ�������ڵ�
	Gamebool m_bIsMeshNode;

	//! \brief �����ƫ�ƾ���
	FIntVector m_vecWorldOffset;

	//! \brief ����������
	USuperMap_ProceduralMeshComponent* m_pProceduralMeshCom;

	//! \brief �������������
	USuperMap_LineMeshComponent* m_pLineMeshCom;

	//! \brief ����
	UMaterialInterface* m_pMaterial;

	//! \brief Name
	FName m_strName;

	//! \brief ��������
	Gameint m_nDrawType;

	//! \brief �Ƿ���ײ���
	Gamebool m_bCollision;

	//! \brief ͼ��ɼ�
	Gamebool m_bVisibleLayer;

	//! \brief LocalToWorld
	Matrix4d m_matDoubleLocalToWorld;

	//! \brief �����б��е�λ��
	Gameint m_nHiddenIndex;

	//! \brief �����߲���
	TArray<SM_Vertex> m_arrLineVtxs;
	TArray<SM_SubMesh> m_arrLineSubMeshs;
};
