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

// �����Ϊ��ͬ���͵�Mesh�ṩһ����ͬ���ⲿ�ӿڣ���ʵ����һ��USceneComponent������UMeshComponent
UCLASS()
class USuperMap_MeshComponentInterface : public USceneComponent
{
	GENERATED_BODY()
public:
	USuperMap_MeshComponentInterface();
	virtual ~USuperMap_MeshComponentInterface();

	//! \brief ��������
	Gamevoid CreateMesh(GameEntity* pGameEntity, Gamebool bCollision);

	//! \brief ��������
	//! \param meshData [in] ԭʼ����
	//! \param pMat [in] ʹ�õĲ���
	//! \param bCollision [in] �Ƿ񴴽���ײ��
	Gamevoid CreateMesh(const FSMMesh& meshData, Gamebool bCollision);

	//! \brief ����������Ϣ
	Gamevoid UpdateMesh(const FSMMesh & meshData, UGVertexDataStateSet nState);

	//! \brief ʵ�������ݵĶ�����ɫ
	Gamevoid UpdateInstanceVertexColor(Gameuint nColor, TArray<uint32>& arrIds);

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

	//! \brief ���ôӾֲ�����ϵת����ECEF����ľ���
	//! \return ����
	Gamevoid SetLocalToECEF(const Matrix4d& mat);

	//! \brief ��ȡ�Ӿֲ�����ϵת����ECEF����ľ���
	//! \return ����
	Matrix4d GetLocalToECEF();
	
	//! \brief ����MeshComponent
	Gamevoid CreateMeshComponent(ComponentType eComType, AActor* pActor);
	Gamevoid CreateMeshComponent(ComponentType eComType);
	UPrimitiveComponent* GetMeshComponent();
	
	CustomRealRasterMesh* GetRealRasterMesh();

	Gamevoid ReleaseMeshComponent();

	//! \brief ��ȡ�ҽӵĴ�SceneComponent�����ӽڵ㣬������meshComponent�ӽڵ�
	TArray<USceneComponent*> GetAttachSceneComponentChildren();

	//! \brief ����StaticMesh
	Gamevoid SetCustomStaticMesh(FString strStaticMeshName, UStaticMesh* pStaticMesh);

	//! \brief ��ȡ�������
	ComponentType GetComponentType();

	//! brief ����Transform
	Gamevoid UpdateTransfrom(Vector3d vOffset);

	//! \brief ��������
	Gamevoid SetBillboardParam(Gameint nBaseSizeX, Gameint nBaseSizeY, Matrix4d matTexcoord);
	Gamevoid SetTexture(UTexture2D* pTexture2D);

	//! \brief ��Ӧ��ʵ�ʲ�������
	FString GetRealMaterialName();
	Gamevoid SetRealMaterialName(FString strRealMaterialName);

	//! \brief ��Ӧ��ʵ�ʲ�������
	FString GetLayerName();
	Gamevoid SetLayerName(FString strLayerName);

	//! \brief ��Ӧ�ķ�������
	Gamevoid SetVisibleInViewport(Gameint nIndex, Gamebool bVisible);
	Gamebool GetVisibleInViewport(Gameint nIndex);

	//! \brief �������
	Gamevoid UpdateSubMeshes(TArray<DataIndice*>& m_arrIndexs, TArray<FSuperMapMaterialInterfaceCollection>& arrMaterialCollection);

	//! \brief ���һ�����ʼ��ϣ�����ͬһ�����ʵĸ�����̬��
	Gamevoid AddMaterialCollection(const FSuperMapMaterialInterfaceCollection& materialCollection);

	//! \brief ɾ�����һ�����ʼ���
	Gamevoid RemoveLastMaterialCollection(const FSuperMapMaterialInterfaceCollection& lastMaterialCollection);


	Gamevoid AddMaterialInterface(UMaterialInterface* pMaterial);

	Gamevoid RemoveMaterialInterface(UMaterialInterface* pMaterial);

	//! \brief ��ȡԭʼ����
	Gamevoid GetAllCustomMaterials(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief ��ȡѡ�����
	Gamevoid GetAllSelectionMaterials(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief ��ȡ���ӿڲ���
	Gamevoid GetAllMaterialsInViewport(TArray<UMaterialInterface*>& arrOutMaterials);

	//! \brief ��ȡ����ʹ�ñ�־
	Gamevoid SetUseMaterialFlag(UseMaterialFlag enUseMaterialFlag);
	UseMaterialFlag GetUseMaterialFlag();

	//! \brief ��ȡ�Ƿ����޳�
	Gamevoid SetReverseCulling(Gamebool bReverseCulling);
private:
	UPrimitiveComponent* m_pMeshComponent;
	Gamebool m_bStatic;

	ComponentType m_eComponentType;

	CustomRealRasterMesh* m_pCustomRealRasterMesh;

	//! \brief ����任����
	Matrix4d m_localToECEF;

	UseMaterialFlag m_enUseMaterialFlag;

	//! \brief �ڵ�����
	Gamebool m_bInternalVisibility;

	//! \brief ���ӿ�����
	Gamebool m_bVisibleInViewport[2];


	Gamebool m_bLayerVisible;

	//! \brief �Ƿ����޳�
	Gamebool m_bReverseCulling;

	FString m_strLayerName;
};