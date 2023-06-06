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

				// PBR材质纹理参数
				int32 m_nBaseTextureIndex;
				int32 m_nMetallicTextureIndex;
				int32 m_nEmissiveTextureIndex;
				int32 m_nNormalTextureIndex;
				int32 m_nOcclusionTextureIndex;

				SuperMapSDK::UnrealEngine::Data::Matrix4d m_matTex;

				//原始材质名称
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
				//! \brief 更新渲染对象
				void DynamicGameObject();

				//! \brief 更新渲染对象
				void DynamicGameObjectForData();

				//! \brief 设置线程锁
				void SetCriticalSection(FCriticalSection* pCriticalSection);

				//! \breif 释放内存渲染对象
				void Release();

				//! \brief 设置场景管理器
				void SetWorld(UWorld* pWorld);

				//! \brief 设置场景操作类
				void SetSceneOpt(Scene* pScene);

				//! \brief 获取全部的渲染节点
				std::map<std::string, USuperMap_MeshComponentInterface*> & GetRenderQueue();
				
				//! \brief 获取图层的渲染根节点
				std::map<std::string, USuperMap_MeshComponentInterface*> & GetRootQueue();

				//! \brief 获取实时栅格化的节点
				std::map<std::string, USuperMap_MeshComponentInterface*> & GetRealTimeRasterRenderQueue();

				//! \brief 获取根节点
				ASuperMap_ROEntityActor* GetRootNode();

				//! \brief 获取深度渲染材质
				UMaterialInstanceDynamic* GetDepthMaterial();

				//! \brief 获取ColorTable队列
				std::map<FString, UTexture2D*> & GetColorTableManager();

				//! \brief 获取LayerInfo
				std::map<FString, Layer3DMaterialInfo*>& GetLayerInfo();

				//! \brief 获取LayerInfo
				std::map<FString, ObjectMaterialInfo*>& GetObjectInfo();

				//! \brief 获取静态网格队列
				std::map<FString, std::pair<UStaticMesh*, int32> >& GetStaticMeshs();

				//! \brief 获取实例化对象
				std::map<uint32, ASuperMap_InstancedActor*>& GetInstancedActors();

				//! \brief 获取渲染目标
				std::map<int32, CustomRenderTargetInfo*>& GetTextureRenderTarget2D();

				//! \brief 获取分析相机
				ASuperMap_CaptureSceneActor* GetAnaystActor();

				//! \brief 往分析相机里面添加不渲染的东西
				void AddHiddenActorForAnaystActor(AActor* pHiddenActor);
			private:
				//! \brief 创建场景对象
				ASuperMap_ROEntityActor* CreateActor(FName & name);

				//! \brief 添加材质
				void AddMaterial(ROMaterial*** & pAddMaterial, int32 nCount);

				//! \brief 更新材质
				void UpdateMaterial(ROMaterial*** & pUpdateMaterial, int32 nCount);

				//! \brief 删除材质
				void DeleteMaterial(__int64*** & pDeleteMaterial, int32 nCount);

				//! \brief 添加纹理
				void AddTextures(ROTexture*** & pAddTexture, int32 nCount);

				//! \brief 删除纹理
				void DeleteTextures(__int64*** & pDeleteTexture, int32 nCount);

				//! \brief 转换纹理
				void ToTex2D(DataTexture* pDataTexture);

				//===================================================================================
				//! \brief 增加节点
				void AddGameObjectForComponent(RONode*** & pAddNodes, int Count);
				void CreateMesh(RONode* pRONode, ROEntity* pROEntity, USuperMap_MeshComponentInterface* pSceneNode, DataVertex* pDataVertex, DataIndice* pDataIndice, bool bCopyVertex = false);

				//! \brief 更新节点
				void UpdateGameObjectForComponent(RONode*** & pUpdateNodes, int nCount);

				//! \brief 删除节点
				void DeleteGameObjectForComponent(ROEmptyNode*** & pDeleteNodes, int nCount);

				//! \brief 删除节点
				void DestroyNodeForComponent(USuperMap_MeshComponentInterface* pEntityNode);

				//! \brief 创建场景节点
				USuperMap_MeshComponentInterface* CreateGameObjectForComponent(RONode* pNode);

				//! \brief 创建组件
				USuperMap_MeshComponentInterface* CreateComponent(FName& name, RONode* pNode);

				//! \brief 设置图层可见性
				void SetLayerVisibleForComponent(USuperMap_MeshComponentInterface* pComponent, bool bVisible);
				//===================================================================================

				//! \brief 计算MipMap的层数
				void CalMipMap(int nWidth, int nHeight, int nTextureSize, TextureType nFormat, std::map<int, int> & mapMipMaps , EPixelFormat pixelFormat);

				//! \brief 计算Buffer的大小
				int CalTextureSize(int nWidth, int nHeight, TextureType nFormat);

				//! \brief 转换纹理类型
				void GetTextureType(int nFormat, TextureType &texType);

				//! \brief 设置分析功能
				void UpdateAnalyst(UMaterialInstanceDynamic* pMD);

				//! \brief 更新材质
				void UpdateTex2D(DataTexture* pDataUpdateTexture);

				//! \brief 纹理更新
				void UpdateTexRegion(UTexture2D* pTex2D, uint8* pByte, int32 nOffset , int32 nOffsetX, int32 nOffsetY, int32 nWidth, int32 nHeight ,
					bool bIsData, int32 nNum, int32 nMipIndex);

				//! \brief 设置材质
				void UseLayerMaterial(UMaterialInstanceDynamic* &pMD , UEROMaterial* & pMat, FString strParentName);

				//! \brief 更新压平
				void UpdateLayerInfo(UMaterialInstanceDynamic* &pMD,FString strParentName, USuperMap_MeshComponentInterface* pComponent);

				//! \brief 更新淹没分析
				void UpdateFlood(UMaterialInstanceDynamic* &pMD);

				//! \brief 更新坡度坡向
				void UpdateSlope(UMaterialInstanceDynamic* &pMD);

				//! \brief 设置纹理矩阵
				void SetTextureMatrix(UMaterialInstanceDynamic* pMID, float* pTexMat, FString strTex);

				//! \brief 设置纹理矩阵
				void CreateMID(bool bIsPBR, FString strShaderName, UMaterialInstanceDynamic* & pMID);
			
				//! \brief 是否需要创建第二重材质
				bool IsNeedCreateSecondMaterial(FString strShaderName);

				//! \brief 创建绘制SecondColor的材质
				void CreateSelectionMaterial(USuperMap_MeshComponentInterface* pComponent, UMaterialInterface* pMI);
				
				//! \brief 添加点外挂实例化对象组件
				void AddInstancedMeshComponent(RONode* pRONode, USuperMap_MeshComponentInterface* pComponent);

				//! \brief 设置PBR纹理参数
				void SetPBRTextureParam(UEROMaterial* pMaterial, FName & strTexture,int32 nTexCount);
				void SetPBRMaterialParam(UMaterialInstanceDynamic* pMID, ROMaterial* pMaterial);
		private:

				//! \brief 单键类指针
				static ROCacheManager* m_pROCacheManager;

				//! \brief 场景根节点
				ASuperMap_ROEntityActor* m_pRootNode;

				//! \brief 场景组件根节点
				USuperMap_MeshComponentInterface* m_pRootComponent;

				//! \brief 场景根节点名称
				std::string m_strRoot;

				//! \brief 渲染队列
				std::map<std::string, USuperMap_MeshComponentInterface*> m_mapRenderQueue;

				//! \brief 材质队列
				std::map<__int64, UEROMaterial*> m_mapMaterialManager;

				//! \brief 纹理队列
				std::map<__int64, UTexture2D*> m_mapTextureManager;

				//! \brief 图层材质信息
				std::map<FString, Layer3DMaterialInfo*> m_mapLayerInfo;

				//! \brief 图层对象材质信息
				std::map<FString, ObjectMaterialInfo*> m_mapObjectInfo;

				//! \brief 根节点管理器
				std::map<std::string, USuperMap_MeshComponentInterface*> m_mapRootNode;

				//! \brief ColorTable队列
				std::map<FString, UTexture2D*> m_mapColorTableManager;

				//! \brief UGC API 是否初始化成功
				bool m_bAPIInitial;

				//! \brief 得到场景管理器
				UWorld* m_pWorld;

				//! \brief 深度纹理
				UMaterialInstanceDynamic* m_pDepthMaterial;

				//! \brief 场景操作
				Scene* m_pScene;

				//! \brief 记录需要设置为不可见的节点名字
				std::map<std::string, std::string> m_mapInvisibleNodeNames;

				//! \brief UGC完整一帧的队列
				std::queue<UEROCacheNode*> m_qROCacheNode;

				//! \brief 线程锁
				FCriticalSection* m_pCriticalSection;

				//! \brief 管理静态网格体队列
				std::map<FString, std::pair<UStaticMesh*, int32> > m_mapStaticMeshs;

				//! \brief 管理实例化对象
				std::map<uint32, ASuperMap_InstancedActor*> m_mapInstancedActors;

				//! \brief 管理RenderTarget对象
				std::map<int32, CustomRenderTargetInfo*> m_mapTextureRenderTarget2D;

				//! \brief 管理栅格化场景的渲染队列
				std::map<std::string , USuperMap_MeshComponentInterface*> m_mapRealTimeRasterRenderQueue;
				
				//! \brief 分析相机
				ASuperMap_CaptureSceneActor* m_pCapureSceneActor;
			};
		}
	}
}