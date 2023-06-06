// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "ProceduralMeshComponent.h"
#include "Core/ROCache.h"
#include "Data/Matrix4d.h"
#include "Core/RealspaceDLL.h"
#include "SuperMap_ProceduralMeshComponent.generated.h"

using namespace SuperMapSDK::UnrealEngine::Data;

class UMaterialInterface;
class FMyProceduralMeshSceneProxy;
/**
 *
 */
UCLASS()
class SUPERMAP_API USuperMap_ProceduralMeshComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()

public:
	USuperMap_ProceduralMeshComponent(const FObjectInitializer& ObjectInitializer);

	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;

	//! \brief ������������
	//! \param pDataVertex [in] �����
	//! \param pDataIndice [in] ��������
	Gamevoid CreateProceduralMesh(
		SuperMapSDK::DataVertex* pDataVertex, 
		SuperMapSDK::DataIndice* pDataIndice,
		UMaterialInterface* pMat);

	//! \brief ���ýڵ�����
	//! \param strName [in] �ڵ�����
	Gamevoid SetName(FName strName);

	//! \brief ��ȡ�ڵ�����
	//! \return 
	FName GetName();

	//! \brief ��������
	//! \param nType [in] ��������
	Gamevoid SetDrawType(Gameint nType);

	//! \brief ˢ���Ƿ������ײ
	//! \param bEnable [in] ����
	Gamevoid UpdateComponentCollision(Gamebool bEnable);

	//! \brief �����Ƿ�ɼ�
	//! \param bVisible [in] �Ƿ�ɼ�
	Gamevoid SetInternalVisibity(Gamebool bVisible);

	//! \brief �����Ƿ�����ͼ���Ƿ�ɼ�
	//! \param bVisible [in] �Ƿ�ɼ�
	Gamevoid SetLayerVisibity(Gamebool bVisible);

	//! \brief ��ȡͼ��ɼ���
	//! \return ͼ��ɼ���
	Gamebool GetLayerVisibity();

	//! \brief ɾ�����е�section
	Gamevoid Clear();

	//! \brief �����Ƿ񴴽���ײ������
	//! \param bCollision [in] �Ƿ���ײ
	Gamevoid SetCollision(Gamebool bCollision);

	//! \brief ���ò���
	//! \param pMat [in] ����
	Gamevoid SetCustomMaterial(UMaterialInterface* pMat);

	//! \brief ��ȡ����
	//! \return ����
	UMaterialInterface* GetCustomMaterial();

	//! \brief ��ȡLocalToWorld
	//! \return ����
	Matrix4d GetLocalToWorld();
private:

	//! \brief �Ƿ񴴽���ײ������
	Gamebool m_bCollision;

	//! \brief ���Ʒ�ʽ
	Gameint m_nDrawType;

	//! \brief ����ڵ�Ŀɼ���
	Gamebool m_bVisible;

	//! \brief ����ͼ��Ŀɼ���
	Gamebool m_bVisibleLayer;

	//! \brief �ڵ�����
	FName m_strName;

	//! \brief ��Ⱦ�ڵ�
	FMyProceduralMeshSceneProxy* m_pSceneProxy;

	//! \brief ��Ⱦ����
	UMaterialInterface* m_pMaterial;

	//! \brief LocalToWorld
	Matrix4d m_matDoubleLocalToWorld;

	friend class FMyProceduralMeshSceneProxy;
};
