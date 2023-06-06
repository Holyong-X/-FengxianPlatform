#pragma once

#include "CoreMinimal.h"
#include "Core/Layer3D.h"
#include "Core/ROCache.h"
#include "Data/DataSource.h"
#include "Data/Dataset.h"
#include "Render/RenderModel3D.h"
#include "StaticMeshDescription/Public/StaticMeshAttributes.h"
#include "MeshDescription/Public/MeshDescription.h"
#include <map>
#include "Core/RealspaceDLL.h"

class ASuperMap_StaticMeshActor;
class UStaticMeshComponent;
class UStaticMesh;
class UWorld;
class UMaterial;
class UMaterialInstanceConstant;
class UMaterialInstanceDynamic;
class UTexture2D;

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Render;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Layer3DDatasetModel : public Layer3D
			{
			public:
				Layer3DDatasetModel();
				Layer3DDatasetModel(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DDatasetModel();

			public:
				//! \brief ���ͼ�����Ⱦ����
				virtual void AddNativeGameComponent(GameComponent* pGameComponent);

				//! \brief �Ƴ�ͼ�����Ⱦ����
				virtual void RemoveNativeGameComponent(GameComponent* pGameComponent);

				//! \brief �������ݼ�
				//! \param pDataset [in] ���ݼ�
				void SetDataset(Dataset* pDataset);

				//! \brief ��ȡģ�����ݼ�
				Dataset* GetDataset();
			private:
				//! \brief �����������
				void UpdateObjectMaterialInfo(GameMaterial* pGameMaterial);

				void UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent);

				//! \brief �������ƻ�ȡ��Ӧ�ʲ�
				FString GetHomologousAsset(FString strKey);
			#if WITH_EDITOR
			public:
				//! \brief ����UE�ĳ���������
				void SetWorld(UWorld* pWorld);

				//! \brief ��ͼ��
				//! \return 
				bool Open();

				//! \brief ���ɲ��ʶ�Ӧ���ļ�
				void ToJson();

				//! \brief ���ò���� ƽ��ʹ��
				virtual void SetOriginalPosition(FVector vPos);

			private:

				//! \brief ����ModelPatch
				//! \param pActor  [in] �����Ķ���
				//! \param pPatchs [in] ModelPatch
				//! \param nPatch  [in] ModelPatch����
				void AddStaticMeshFromModelPatch(ASuperMap_StaticMeshActor* pActor, DataSetPatch*** pPatchs, int32 nPatch);

				//! \brief ����ModelGeode
				//! \param pActor  [in] �����Ķ���
				//! \param pGeodes [in] ModelGeode
				//! \param nGeode  [in] ModelGeode����
				void AddStaticMeshFormModelGeode(ASuperMap_StaticMeshActor* pActor, DataSetGeode*** pGeodes, int32 nGeode);

				//! \brief ��Ӷ���
				//! \param pGeometry [in] ����
				void AddStaticMeshActor(DataSetGeometry* pGeometry);
				
				//! \brief ������̬����
				//! \param pActor           [in] �����Ķ���
				//! \param strSkeletonName  [in] �Ǽܵ�����
				//! \param pDataVertex		[in] �Ǽ����ݰ�
				//! \param pDataIndice		[in] ������
				//! \param nDataIndice		[in] ����������
				UStaticMesh* CreateStaticMesh(ASuperMap_StaticMeshActor* pActor, FName strSkeletonName, DataVertex* pDataVertex, DataIndice*** pDataIndice, uint32 nIndiceCount);

				//! \brief �����������
				//! \param pStaticMeshComponent [in] ���
				//! \param matLocaToWorld		[in] �任����
				void SetComponentMatrix(UStaticMeshComponent* pStaticMeshComponent, Matrix4d matLocalToWorld);

				//! \brief ������̬�������
				//! \brief pStaticMesh     [in] ��̬����
				//! \brief matLocalToWorld [in] ����
				UStaticMeshComponent* CreateStaticMeshComponent(UObject* pOuter, UStaticMesh* pStaticMesh, Matrix4d matLocaToWorld);
			#endif
			private:

				//! \brief �����
				FVector m_vPosition;

				//! \brief UE�ĳ���������
				UWorld* m_pWorld; 

				//! \brief ���ݼ�
				Dataset* m_pDataset;

				//! \brief ��ʱ���ʹ�����
				std::map<__int64, std::pair<FName, UMaterialInstanceConstant*> >  m_mapMaterial;

				//! \brief ��ʱ���������
				std::map<__int64, UTexture2D*>  m_mapTexture;

				//! \brief ��ʱ��ʵ�����Ǽܹ�����
				std::map<FName, DataSetSkeleton*> m_mapSkeleton;

				//! \brief ��ʱʵ�����Ǽܹ�����
				std::map<FName, std::pair<DataSetInstanceSkeleton* , UStaticMesh*> > m_mapInstanceSkeleton;

				//! \brief ��ʱʵ�������ʻ�����
				std::map<FName, std::pair<FName, UMaterialInstanceConstant*> > m_mapInstanceMaterial;
			};

		}
	}
}