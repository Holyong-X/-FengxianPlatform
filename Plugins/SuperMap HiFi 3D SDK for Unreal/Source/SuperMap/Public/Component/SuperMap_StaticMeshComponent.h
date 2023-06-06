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

	//! \brief ������̬����
	Gamevoid CreateMesh(const FSMMesh & meshData, Gamebool bCollision);

	//! \brief ���ýڵ�����
	//! \param strName [in] �ڵ�����
	Gamevoid SetName(FName strName);

	//! \brief ��ȡ�ڵ�����
	//! \return 
	FName GetName();

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
	Gamebool GetInternalVisibility();

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

	//! \brief ����Tranfrom
	Gamevoid UpdateTransform(Vector3d vOffset, FTransform & transform);

private:
	//! \brief ������̬������Ⱦ����
	Gamevoid CreateStaticMeshRenderData(const FSMMesh & meshData, StaticMeshRenderData & smrd);

	Gamevoid ComputeBoundingSphere(const FSMMesh& meshData, FBoxSphereBounds& boundingBoxAndSphere);

	//! \brief ��ѹ
	Gamevoid DecodeDataPackage(const FSMMesh & meshData);
private:
	//! \brief �ڵ�����
	FName m_strName;

	//! \brief �����ڵ�Ŀɼ���
	Gamebool m_bVisible;

	//! \brief ����ͼ��Ŀɼ���
	Gamebool m_bVisibleLayer;

	//! \brief ����ͼ���Ƿ���Ⱦ
	Gamebool m_bRender;

	//! \brief ��Ⱦ����
	UMaterialInterface* m_pMaterial;

	//! \brief ԭʼ�Ĵ�ģ�;ֲ�����ϵ��ECEF����ϵ�ı任����
	Matrix4d m_matLocalToECEF;

	//! \brief �Ƿ�������ײ���
	Gamebool m_bCollision;

	//! \brief �Ƿ������ӵ���ײ���
	Gamebool m_bUseComplexAsSimpleCollision;

#if PHYSICS_INTERFACE_PHYSX
	IPhysXCooking* m_pPhysXCooking;
#endif

	//! \brief ���Ʒ�ʽ
	EPrimitiveType m_eDrawType;
};