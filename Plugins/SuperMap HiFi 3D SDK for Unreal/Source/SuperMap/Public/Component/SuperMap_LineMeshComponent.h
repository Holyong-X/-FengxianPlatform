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

	//! \brief ��������
	Gamevoid CreateEdgeLineMesh(GameEntity* pGameEntity, Gamebool bCollision);

	//! \brief ��������
	//! \param meshData [in] ��������
	Gamevoid CreateEdgeLineMesh(const FSMMesh& meshData, Gamebool bCollision);

	//! \brief ��������
	//! \param meshData [in] ��������
	Gamevoid CreateSimpleLineMesh(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs);

	//! \brief ���±���Bounds
	//! \param meshData [in] ��������
	Gamevoid UpdateLocalBounds(const FSMMesh & meshData);

	//! \brief �����Ƿ�����ͼ���Ƿ�ɼ�
	//! \param bVisible [in] �Ƿ�ɼ�
	Gamevoid SetLayerVisibility(Gamebool bIsVisible);

	//! \brief ��ȡͼ��ɼ���
	//! \return ͼ��ɼ���
	Gamebool GetLayerVisibility();

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

	//! \brief ���ò���
	//! \param pMat [in] ����
	Gamevoid SetCustomMaterial(UMaterialInterface* pMat);

	//! \brief ��ȡ����
	//! \return ����
	UMaterialInterface* GetCustomMaterial();

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

	//! \brief ��Ӧ��ʵ�ʲ�������
	//FString GetRealMaterialName();
	//Gamevoid SetRealMaterialName(FString strRealMaterialName);

	//! \brief ��Ӧ�ķ�������
	Gamevoid SetVisibleInViewport(Gameint nIndex, Gamebool bVisible);
	Gamebool GetVisibleInViewport(Gameint nIndex);

private:
	//! \brief ����localbounds
	Gamevoid CalLocalBound(const FSMMesh& smMesh);

	// USceneComponent
	FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;

	// UPrimitiveComponent
	FPrimitiveSceneProxy* CreateSceneProxy() override;
	Gameint GetNumMaterials() const override;

	FBoxSphereBounds m_LocalBounds;

	//! \brief ����ͼ��Ŀɼ���
	Gamebool m_bVisibleLayer;

	//! \brief ����ͼ���Ƿ���Ⱦ
	Gamebool m_bRender;

	//! \brief �����ڵ�Ŀɼ���
	Gamebool m_bVisible;

	//! \brief �ڵ�����
	FName m_strName;

	FSuperMapLineMeshSceneProxy* m_pSceneProxy;

	//! \brief ��Ⱦ����
	UMaterialInterface* m_pMaterial;

	//! \brief ������任����δ�������ŵģ�ԭʼ�Ĵ�ģ�;ֲ�����ϵ��ECEF����ϵ�ı任����
	Matrix4d m_matLocalToECEF;

	//! \brief ��֧��2��
	Gamebool m_bVisibleInViewport[2];

	//! \brief �Ƿ��ʼ��
	Gamebool m_bInitial;

	FSMMesh m_MeshData;

	TArray<SM_Vertex> m_arrLineVertex;
	TArray<SM_SubMesh> m_arrLineSubMesh;

};
