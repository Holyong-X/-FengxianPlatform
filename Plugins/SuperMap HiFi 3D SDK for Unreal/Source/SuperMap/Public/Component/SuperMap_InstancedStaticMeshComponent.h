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

	//! \brief ��ȡLocalToWorld
	//! \return ����
	Matrix4d GetLocalToWorld();

	//! \brief ����StaticMesh
	Gamevoid SetCustomStaticMesh(FString strStaticMeshName, UStaticMesh* pStaticMesh);

	//! \brief ����Transform
	Gamevoid BatchUpdateTransform(Vector3d vOffset);

	//! \brief ���ôӾֲ�����ϵת����ECEF����ľ���
	//! \return ����
	Gamevoid SetLocalToECEF(const Matrix4d& mat);

	//! \brief ��ȡ�Ӿֲ�����ϵת����ECEF����ľ���
	//! \return ����
	Matrix4d GetLocalToECEF();
private:
	//! \brief �ڵ�����
	FName m_strName;

	//! \brief �����ڵ�Ŀɼ���
	Gamebool m_bVisible;

	//! \brief ����ͼ��Ŀɼ���
	Gamebool m_bVisibleLayer;

	//! \brief ��Ⱦ����
	UMaterialInterface* m_pMaterial;

	//! \brief LocalToWorld
	Matrix4d m_matDoubleLocalToWorld;

	//! \brief ������任����δ�������ŵģ�ԭʼ�Ĵ�ģ�;ֲ�����ϵ��ECEF����ϵ�ı任����
	Matrix4d m_matLocalToECEF;

	//! \brief �Ƿ�������ײ���
	Gamebool m_bCollision;

	//! \brief �Ƿ������ӵ���ײ���
	Gamebool m_bUseComplexAsSimpleCollision;

	//! \brief ��̬���������
	FString m_strStaticMeshName;

	//! \brief Instance����ľ���
	TArray<Matrix4d> m_arrInstanceMatrix;
};