#pragma once
//===============================================
// 渲染对象管理器
//===============================================

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameComponent.h"
#include "Graphics3D/GameOcclusionVolume.h"
#include "Engine/World.h"
#include "Component/SuperMap_InstancedActor.h"
#include "Component/SuperMap_CustomVectorActor.h"
#include "Component/SuperMap_SplineActor.h"
#include "Component/SuperMap_TextActor.h"
class ASuperMap_ROEntityActor;
class ASuperMap_SplineActor;
namespace SuperMapSDK
{
	//class SuperMapSDK::UnrealEngine::Core::Scene;

	class SUPERMAP_API GameObjectManager
	{
	public:
		GameObjectManager();
		~GameObjectManager();

	public:
		//! \brief 获取单例类
		static GameObjectManager* GetSingleton();

		//! \brief 创建遮挡体
		void* CreateOcclusionVolume(Gamelong nIDName);

		//! \brief 删除遮挡体
		void DestroyOcclusionVolume(void* pOcclusionVolumeHandle);

		//! \brief 销毁单例类
		static void DestorySingleton();

		//! \brief 创建或者获取根节点
		void* GetOrCreateRootSceneNode(Gamechar* strSceneName, Gameint nSceneManagerType);

		//! \brief 删除场景节点
		void DestroySceneNode(void* pSceneNodeHandle);

		//! \brief 设置对象矩阵
		void SetObjectMatrix(void* pSceneNodeHandle, Gamedouble* pMatrix);

		//! \brief 设置可见性
		void SetVisible(void* pSceneNodeHandle, Gamebool bVisible);


		void SetSceneNodeVisible(void* pSceneNodeHandle, Gamebool bVisible);

		//! \brief 挂接场景节点
		Gamebool AttachEntity(void* pSceneNodeHandle, void* pMeshHandle);

		//! \brief 创建子节点
		void* CreateChildSceneNode(void* pParentNodeHandle, Gamelong nSceneNodeName, Gameint nSceneManagerType);

		//! \brief 设置场景对象
		void SetWorld(UWorld* pWorld);
		UWorld* GetWorld();

		//! \brief 设置场景对象
		void SetScene(void* pScene);
		void* GetScene();

		//! \brief 获取场景节点
		GameComponent* GetGameComponent(Gamelong nSceneNodeHandle);

		//! \brief 更新世界动态原点
		void UpdateWorldOrigin(Vector3d vOrigin);

		//! \brief 获取所有的渲染节点
		TMap<Gamelong, GameComponent*>& GetAllGameComponent();

		//! \brief 获取有实体网格的渲染节点
		TMap<Gamelong, GameComponent*>& GetRenderGameComponent();

		//! \brief 获取实例化对象
		TMap<uint32, ASuperMap_InstancedActor*>& GetInstancedActors();

		//! \brief 获取实例化管线
		TMap<uint32, ASuperMap_SplineActor*>& GetSplineActors();

		//! \brief 获取矢量
		TArray<ASuperMap_CustomVectorActor*>& GetVectorActors();

		//! \brief 获取ROEntity_Line对象
		TArray<ASuperMap_ROEntityActor*>& GetLineMeshActors();

		//! \brief 获取文字对象
		TArray<ASuperMap_TextActor*>& GetTextActors();

		//! \brief 获取场景隐藏对象
		TArray<AActor*> & GetSceneHiddenActors();

		//! \brief 获取未初始化的组件对象
		GameObjectListNode* GetUnInitialListNode();

		//! \brief 添加未初始化的组件对象
		void AddUnitialComponent(GameComponent* pGameComponent);

		//! \brief 删除未初始化的组件对象
		void RemoveUnitialComponent(GameComponent* pGameComponent);

		//! \brief 设置是否开启碰撞网格
		void SetEnableCollision(Gamebool bEnable);

		//! \brief 是否开启碰撞网格
		Gamebool IsEnableCollision();
	private:
		//! \brief 创建场景节点
		USuperMap_MeshComponentInterface* CreateComponent(FName& name);

	private:
		//! \brief 场景对象
		void* m_pScene;

		//! \brief 世界场景对象
		UWorld* m_pWorld;

		//! \brief 游戏对象管理器
		static GameObjectManager* m_pGameObjectManager;

		//! \brief 所有节点对象管理
		TMap<Gamelong, GameComponent*> m_mapGameComponents;

		//! \brief 渲染节点对象管理
		TMap<Gamelong, GameComponent*> m_mapRenderGameComponents;

		//! \brief 场景总根节点
		ASuperMap_ROEntityActor* m_pRootNode;

		//! \brief 场景组件根节点
		TMap<FString, GameComponent*> m_mapSceneRootComponent;

		//! \brief 管理实例化对象
		TMap<uint32, ASuperMap_InstancedActor*> m_mapInstancedActors;

		//! \brief 管理实例化管线
		TMap<uint32, ASuperMap_SplineActor*> m_mapSplineActors;

		//! \brief 管理点线面
		TArray<ASuperMap_CustomVectorActor*> m_arrVectorActors;

		//! \brief 管理ROEntity_Line对象
		TArray<ASuperMap_ROEntityActor*> m_arrLineMeshActors;

		//! \brief 管理文字渲染对象
		TArray<ASuperMap_TextActor*> m_arrTextActors;

		//! \brief 遮挡体对象
		TMap<Gamelong, GameOcclusionVolume*> m_mapOcclusionVolumes;

		//! \brief 是否开启碰撞检测
		Gamebool m_bEnableCollision;

		//! \brief 需要初始化节点的组件
		TMap<Gamelong, GameComponent*> m_mapUnInitialComponents;

		GameObjectListNode* m_pHead;
		GameObjectListNode* m_pTail;

		//! \brief 场景深度不输出的对象
		TArray<AActor*> m_arrSceneHiddenActors;
	};
}
