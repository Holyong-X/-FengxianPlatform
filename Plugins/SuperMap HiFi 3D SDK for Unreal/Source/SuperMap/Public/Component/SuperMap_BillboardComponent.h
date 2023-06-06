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
	//! \brief ��������
	//! \param meshData [in] ԭʼ����
	//! \param pMat [in] ʹ�õĲ���
	//! \param bCollision [in] �Ƿ񴴽���ײ��
	Gamevoid CreateMesh(const FSMMesh& meshData, Gamebool bCollision);

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

	//! \brief ����Second����
	//! \param pMat [in] ����
	Gamevoid SetCustomSecondMaterial(UMaterialInterface* pMat);

	//! \brief ��ȡ����
	//! \return ����
	UMaterialInterface* GetCustomSecondMaterial();

	//! \brief ��ȡLocalToWorld
	//! \return ����
	Matrix4d GetLocalToWorld();

	//! brief ����Transform
	Gamevoid UpdateTransform(Vector3d vOffset, FTransform & transform);

	//! \brief ��������
	Gamevoid SetBillboardParam(Gameint nBaseSizeX, Gameint nBaseSizeY, Matrix4d matTexcoord);
	Gamevoid SetTexture(UTexture2D* pTexture);

	//! \brief ���ôӾֲ�����ϵת����ECEF����ľ���
	//! \return ����
	Gamevoid SetLocalToECEF(const Matrix4d& mat);

	//! \brief ��ȡ�Ӿֲ�����ϵת����ECEF����ľ���
	//! \return ����
	Matrix4d GetLocalToECEF();

private:

	//! \brief �ڵ�����
	FName m_strName;

	//! \brief ����ͼ��Ŀɼ���
	Gamebool m_bVisibleLayer;

	//! \brief �����ڵ�Ŀɼ���
	Gamebool m_bVisible;

	//! \brief ��Ⱦ����
	UMaterialInterface* m_pMaterial;

	//! \brief Second��Ⱦ����
	UMaterialInterface* m_pSecondMaterial;

	//! \brief LocalToWorld
	Matrix4d m_matDoubleLocalToWorld;

	//! \brief ������任����δ�������ŵģ�ԭʼ�Ĵ�ģ�;ֲ�����ϵ��ECEF����ϵ�ı任����
	Matrix4d m_matLocalToECEF;

	//! \brief BillboardComponents
	TArray<USuperMap_MaterialBillboardComponent*> m_arrBillboardComponents;

	//! \brief ����Ļ�����С
	Gameint m_nBaseSizeX;
	Gameint m_nBaseSizeY;

	//! \biref �������
	Matrix4d m_matTexcoord;
};