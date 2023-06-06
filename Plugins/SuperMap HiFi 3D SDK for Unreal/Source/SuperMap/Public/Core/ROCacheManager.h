#pragma once

#include <map>
#include <vector>
#include <string>
#include <queue>
#include "CoreMinimal.h"
#include "ROCache.h"
#include "SceneType.h"
#include "Core/Layer3DInfo.h"
#include "Data/Matrix4d.h"
#include "Runtime/Core/Public/PixelFormat.h"
#include "Render/CustomRenderTargetInfo.h"
#include "Graphics3D/GameStruct.h"
#include "Core/RealspaceDLL.h"

class AActor;
class USuperMap_MeshComponent;
class ASuperMap_ROEntityActor;
class UTexture2D;
class UMaterialInterface;
class UMaterialInstanceDynamic;
class UMaterialInstanceConstant;
class UWorld;
class USuperMap_MeshComponentInterface;
class UStaticMesh;
class ASuperMap_InstancedActor;
class UTextureRenderTarget2D;
class ASuperMap_CaptureSceneActor;

using namespace SuperMapSDK::UnrealEngine::Render;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class Scene;

			struct UEROMaterial
			{
				__int64 m_nTextureHashCode;
				__int64 m_nTextureHashCode1;
				__int64 m_nTextureHashCode2;
				__int64 m_nTextureHashCode3;
				UMaterialInstanceDynamic*  m_pMaterialInstanceDynamic;
				UMaterialInstanceConstant* m_pMaterialInstanceConstant;
				bool  m_bCollision;
				bool  m_bNeedSecondMaterial;
				int32 m_nBatchTexIndex;
				bool m_bIsPBR;

				int32 m_nTextureNormalIndex;

				// PBR�����������
				int32 m_nBaseTextureIndex;
				int32 m_nMetallicTextureIndex;
				int32 m_nEmissiveTextureIndex;
				int32 m_nNormalTextureIndex;
				int32 m_nOcclusionTextureIndex;

				SuperMapSDK::UnrealEngine::Data::Matrix4d m_matTex;

				//ԭʼ��������
				FString m_strName;
			};

			struct UEROCacheNode
			{
				RONode***       pAddNodes = NULL;
				RONode***		pUpdateNodes = NULL;
				ROEmptyNode***  pDeleteNodes = NULL;

				ROMaterial***   pAddMaterials = NULL;
				ROMaterial***   pUpdateMaterials = NULL;
				__int64***		pDeleteMaterials = NULL;

				ROTexture***    pAddTextures = NULL;
				ROTexture***    pUpdateTextures = NULL;
				__int64***		pDeleteTextures = NULL;

				int nAddCount = 0;
				int nUpdateCount = 0;
				int nDeleteCount = 0;

				int nAddMaterial = 0;
				int nUpdateMaterial = 0;
				int nDeleteMaterial = 0;

				int nAddTexture = 0;
				int nDeleteTexture = 0;
				int nUpdateTexture = 0;
			};

			class SUPERMAP_API ROCacheManager
			{
			public:
				ROCacheManager();
				~ROCacheManager();

			public:
				static FIntVector m_vecWorldOrigin;
				static SceneType m_eSceneType;
				static FLinearColor m_vID;
				static FVector m_vPlaneOffset;
			public:
				static ROCacheManager* GetSingleton();

				static void Destroy();
				//! \brief ������Ⱦ����
				void DynamicGameObject();

				//! \brief ������Ⱦ����
				void DynamicGameObjectForData();

				//! \brief �����߳���
				void SetCriticalSection(FCriticalSection* pCriticalSection);

				//! \breif �ͷ��ڴ���Ⱦ����
				void Release();

				//! \brief ���ó���������
				void SetWorld(UWorld* pWorld);

				//! \brief ���ó���������
				void SetSceneOpt(Scene* pScene);

				//! \brief ��ȡȫ������Ⱦ�ڵ�
				std::map<std::string, USuperMap_MeshComponentInterface*> & GetRenderQueue();
				
				//! \brief ��ȡͼ�����Ⱦ���ڵ�
				std::map<std::string, USuperMap_MeshComponentInterface*> & GetRootQueue();

				//! \brief ��ȡʵʱդ�񻯵Ľڵ�
				std::map<std::string, USuperMap_MeshComponentInterface*> & GetRealTimeRasterRenderQueue();

				//! \brief ��ȡ���ڵ�
				ASuperMap_ROEntityActor* GetRootNode();

				//! \brief ��ȡ�����Ⱦ����
				UMaterialInstanceDynamic* GetDepthMaterial();

				//! \brief ��ȡColorTable����
				std::map<FString, UTexture2D*> & GetColorTableManager();

				//! \brief ��ȡLayerInfo
				std::map<FString, Layer3DMaterialInfo*>& GetLayerInfo();

				//! \brief ��ȡLayerInfo
				std::map<FString, ObjectMaterialInfo*>& GetObjectInfo();

				//! \brief ��ȡ��̬�������
				std::map<FString, std::pair<UStaticMesh*, int32> >& GetStaticMeshs();

				//! \brief ��ȡʵ��������
				std::map<uint32, ASuperMap_InstancedActor*>& GetInstancedActors();

				//! \brief ��ȡ��ȾĿ��
				std::map<int32, CustomRenderTargetInfo*>& GetTextureRenderTarget2D();

				//! \brief ��ȡ�������
				ASuperMap_CaptureSceneActor* GetAnaystActor();

				//! \brief ���������������Ӳ���Ⱦ�Ķ���
				void AddHiddenActorForAnaystActor(AActor* pHiddenActor);
			private:
				//! \brief ������������
				ASuperMap_ROEntityActor* CreateActor(FName & name);

				//! \brief ��Ӳ���
				void AddMaterial(ROMaterial*** & pAddMaterial, int32 nCount);

				//! \brief ���²���
				void UpdateMaterial(ROMaterial*** & pUpdateMaterial, int32 nCount);

				//! \brief ɾ������
				void DeleteMaterial(__int64*** & pDeleteMaterial, int32 nCount);

				//! \brief �������
				void AddTextures(ROTexture*** & pAddTexture, int32 nCount);

				//! \brief ɾ������
				void DeleteTextures(__int64*** & pDeleteTexture, int32 nCount);

				//! \brief ת������
				void ToTex2D(DataTexture* pDataTexture);

				//===================================================================================
				//! \brief ���ӽڵ�
				void AddGameObjectForComponent(RONode*** & pAddNodes, int Count);
				void CreateMesh(RONode* pRONode, ROEntity* pROEntity, USuperMap_MeshComponentInterface* pSceneNode, DataVertex* pDataVertex, DataIndice* pDataIndice, bool bCopyVertex = false);

				//! \brief ���½ڵ�
				void UpdateGameObjectForComponent(RONode*** & pUpdateNodes, int nCount);

				//! \brief ɾ���ڵ�
				void DeleteGameObjectForComponent(ROEmptyNode*** & pDeleteNodes, int nCount);

				//! \brief ɾ���ڵ�
				void DestroyNodeForComponent(USuperMap_MeshComponentInterface* pEntityNode);

				//! \brief ���������ڵ�
				USuperMap_MeshComponentInterface* CreateGameObjectForComponent(RONode* pNode);

				//! \brief �������
				USuperMap_MeshComponentInterface* CreateComponent(FName& name, RONode* pNode);

				//! \brief ����ͼ��ɼ���
				void SetLayerVisibleForComponent(USuperMap_MeshComponentInterface* pComponent, bool bVisible);
				//===================================================================================

				//! \brief ����MipMap�Ĳ���
				void CalMipMap(int nWidth, int nHeight, int nTextureSize, TextureType nFormat, std::map<int, int> & mapMipMaps , EPixelFormat pixelFormat);

				//! \brief ����Buffer�Ĵ�С
				int CalTextureSize(int nWidth, int nHeight, TextureType nFormat);

				//! \brief ת����������
				void GetTextureType(int nFormat, TextureType &texType);

				//! \brief ���÷�������
				void UpdateAnalyst(UMaterialInstanceDynamic* pMD);

				//! \brief ���²���
				void UpdateTex2D(DataTexture* pDataUpdateTexture);

				//! \brief �������
				void UpdateTexRegion(UTexture2D* pTex2D, uint8* pByte, int32 nOffset , int32 nOffsetX, int32 nOffsetY, int32 nWidth, int32 nHeight ,
					bool bIsData, int32 nNum, int32 nMipIndex);

				//! \brief ���ò���
				void UseLayerMaterial(UMaterialInstanceDynamic* &pMD , UEROMaterial* & pMat, FString strParentName);

				//! \brief ����ѹƽ
				void UpdateLayerInfo(UMaterialInstanceDynamic* &pMD,FString strParentName, USuperMap_MeshComponentInterface* pComponent);

				//! \brief ������û����
				void UpdateFlood(UMaterialInstanceDynamic* &pMD);

				//! \brief �����¶�����
				void UpdateSlope(UMaterialInstanceDynamic* &pMD);

				//! \brief �����������
				void SetTextureMatrix(UMaterialInstanceDynamic* pMID, float* pTexMat, FString strTex);

				//! \brief �����������
				void CreateMID(bool bIsPBR, FString strShaderName, UMaterialInstanceDynamic* & pMID);
			
				//! \brief �Ƿ���Ҫ�����ڶ��ز���
				bool IsNeedCreateSecondMaterial(FString strShaderName);

				//! \brief ��������SecondColor�Ĳ���
				void CreateSelectionMaterial(USuperMap_MeshComponentInterface* pComponent, UMaterialInterface* pMI);
				
				//! \brief ��ӵ����ʵ�����������
				void AddInstancedMeshComponent(RONode* pRONode, USuperMap_MeshComponentInterface* pComponent);

				//! \brief ����PBR�������
				void SetPBRTextureParam(UEROMaterial* pMaterial, FName & strTexture,int32 nTexCount);
				void SetPBRMaterialParam(UMaterialInstanceDynamic* pMID, ROMaterial* pMaterial);
		private:

				//! \brief ������ָ��
				static ROCacheManager* m_pROCacheManager;

				//! \brief �������ڵ�
				ASuperMap_ROEntityActor* m_pRootNode;

				//! \brief ����������ڵ�
				USuperMap_MeshComponentInterface* m_pRootComponent;

				//! \brief �������ڵ�����
				std::string m_strRoot;

				//! \brief ��Ⱦ����
				std::map<std::string, USuperMap_MeshComponentInterface*> m_mapRenderQueue;

				//! \brief ���ʶ���
				std::map<__int64, UEROMaterial*> m_mapMaterialManager;

				//! \brief �������
				std::map<__int64, UTexture2D*> m_mapTextureManager;

				//! \brief ͼ�������Ϣ
				std::map<FString, Layer3DMaterialInfo*> m_mapLayerInfo;

				//! \brief ͼ����������Ϣ
				std::map<FString, ObjectMaterialInfo*> m_mapObjectInfo;

				//! \brief ���ڵ������
				std::map<std::string, USuperMap_MeshComponentInterface*> m_mapRootNode;

				//! \brief ColorTable����
				std::map<FString, UTexture2D*> m_mapColorTableManager;

				//! \brief UGC API �Ƿ��ʼ���ɹ�
				bool m_bAPIInitial;

				//! \brief �õ�����������
				UWorld* m_pWorld;

				//! \brief �������
				UMaterialInstanceDynamic* m_pDepthMaterial;

				//! \brief ��������
				Scene* m_pScene;

				//! \brief ��¼��Ҫ����Ϊ���ɼ��Ľڵ�����
				std::map<std::string, std::string> m_mapInvisibleNodeNames;

				//! \brief UGC����һ֡�Ķ���
				std::queue<UEROCacheNode*> m_qROCacheNode;

				//! \brief �߳���
				FCriticalSection* m_pCriticalSection;

				//! \brief ����̬���������
				std::map<FString, std::pair<UStaticMesh*, int32> > m_mapStaticMeshs;

				//! \brief ����ʵ��������
				std::map<uint32, ASuperMap_InstancedActor*> m_mapInstancedActors;

				//! \brief ����RenderTarget����
				std::map<int32, CustomRenderTargetInfo*> m_mapTextureRenderTarget2D;

				//! \brief ����դ�񻯳�������Ⱦ����
				std::map<std::string , USuperMap_MeshComponentInterface*> m_mapRealTimeRasterRenderQueue;
				
				//! \brief �������
				ASuperMap_CaptureSceneActor* m_pCapureSceneActor;
			};
		}
	}
}