#pragma once
#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEntity.h"
#include "Graphics3D/GameEnum.h"
#include "Graphics3D/GameEntityBase.h"
#include "Graphics3D/GameStruct.h"
#include "Component/SuperMap_MeshComponentInterface.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	//! \brief 创建场景节点 
	typedef void*(*CreateSceneNodeFunction)();

	//! \brief 销毁场景节点
	typedef void(*DestroySceneNodeFunction)(void* pSceneNodeHandle);

	//! \brief 设置矩阵
	typedef void(*SetObjectMatrixFunction)(void* pSceneNodeHandle, Gamedouble* pMatrix);

	//! \brief 设置可见性
	typedef void(*SetVisibleFunction)(void* pSceneNodeHandle, bool bIsVisible);

	typedef void(*SetSceneNodeVisibleFunction)(void* pSceneNodeHandle, bool bIsVisible);
	
	//! \brief 挂接实体对象
	typedef Gamebool(*AttachEntityFunction)(void* pSceneNodeHandle, void* pMeshHandle);

	//! \brief 获取场景节点
	typedef void*(*GetGameObjectFunction)(Gamelong nSceneNodeName);

	//! \brief 创建场景根节点
	typedef void*(*GetOrCreateRootSceneNodeFunction)(Gamechar* strSceneName, Gameint nSceneManagerType);

	//! \brief 销毁场景根节点
	typedef void(*DestroyRootSceneNodeFunction)(void* pSceneNodeHandle);

	//! \brief 创建子场景节点
	typedef void*(*CreateChildSceneNodeFunction)(void* pParentNodeHandle, Gamelong nSceneNodeName, Gameint nSceneManagerType);

	//! \brief 创建场景节点
	void* CreateSceneNode();

	//! \brief 销毁场景节点
	void DestroySceneNode(void* pSceneNodeHandle);

	//! \brief 设置矩阵
	void SetUGCObjectMatrix(void* pSceneNodeHandle, Gamedouble* pMatrix);

	//! \brief 设置可见性
	void SetVisible(void* pSceneNodeHandle, Gamebool bVisible);

	void SetNodeVisible(void* pSceneNodeHandle, Gamebool bVisible);

	//! \brief 挂接实体网格
	Gamebool AttachEntity(void* pSceneNodeHandle, void* pMeshHandle);

	//! \brief 
	void* GetGameObject(Gamelong nSceneNodeName);

	//! \brief 获取或者创建场景根节点
	void* GetOrCreateRootSceneNode(Gamechar* strSceneName, Gameint nSceneManagerType);

	//! \brief 销毁场景节点
	void DestroyRootSceneNode(void* pSceneNodeHandle);

	//! \brief 创建子场景节点
	void* CreateChildSceneNode(void* pParentNodeHandle, Gamelong nSceneNodeName, Gameint nSceneManagerType);
	
	//! \brief 创建对象链表节点
	class GameObjectListNode
	{

	public:
		GameObjectListNode()
		{
			m_pPrev = nullptr;
			m_pNext = nullptr;
			m_pGameComponent = nullptr;
		}

		//! \brief 上一个指针
		GameObjectListNode* m_pPrev;

		//! \brief  下一个指针
		GameObjectListNode* m_pNext;

		//! \brief  当前指针
		GameComponent* m_pGameComponent;
	};

	class GameMaterial;
	class SUPERMAP_API GameComponent
	{
	public:
		GameComponent(Gamelong nName, Gamelong nParentName, Gameint nSceneManagerType);
		~GameComponent();
	public:
		//! \brief 初始化回掉函数
		static void InitializeCallbackHandle();

		//! \brief 获取实体数据包
		GameEntityBase* GetEntity();

		//! \brief 设置实体数据包
		void SetEntity(GameEntityBase* pGameEntity);

		//! \brief 设置场景渲染节点
		void SetSceneNode(USuperMap_MeshComponentInterface* pSceneNode);

		//! \brief 获取场景渲染节点
		USuperMap_MeshComponentInterface* GetSceneNode();

		//! \brief 设置矩阵
		void SetObjectMatrix(Gamedouble* pDoubleMat);

		//! \brief 获取原始UGC矩阵
		Matrix4d GetObjectUGCMatrix();

		//! \brief 设置可见性
		void SetObjectVisible(Gamebool bVisible);

		void SetSceneNodeVisible(Gamebool bVisible);

		//! \brief 挂载节点的名字
		Gamelong GetNodeName();

		//! \brief 父GameComponent的名字
		Gamelong GetParentNodeName();

		//! \brief 获取场景类型
		SceneManagerType GetSceneManagerType();

		//! \brief 获取数据类型
		DataType GetDataType();

		//! \brief 更新骨架
		void UpdateMesh(DataVertex* pDataVertex , Gameint nOffset,UGVertexDataStateSet nState);

		//! \brief 更新实例化对象的顶点颜色
		void UpdateInstanceVertexColor(Gameuint nColor, TArray<uint32>& arrIds);

		//! \brief 异步填充骨架
		void AsyncMesh();

		//! \brief 填充骨架
		void InitMesh();

		//! \brief 填充实体化网格
		void InitInstanceMesh(Gameint nIntanceSize, Gameint nSizeInFloatPerInstance, void* pValue);

		//! \brief 更新动态原点
		void UpdateWorldOrigin(Vector3d vOrigin);

		//! \brief 更新子网格
		void UpdateSubMeshes(TArray<DataIndice*> & arrIndices);

		//! \brief 添加UE的子网格材质
		void AddUESubMeshMaterial(GameMaterial* pGameMaterial);

		void SetSupport(Gamebool bValue);
		Gamebool IsSupport();

		//! \brief 添加材质
		void AddGameMaterialForAsync(GameMaterial* pGameMaterial);
		void UpdateMaterialForAsync(GameMaterial* pGameMaterial);

		void AddGameMaterial(GameMaterial* pGameMaterial);
		TArray<GameMaterial*>& GetAllGameMaterial();

		void RemoveGameMaterial(GameMaterial* pGameMaterial);

		//! \brief 设置图层名称
		void SetLayerName(FString strLayerName);
		FString GetLayerName();

		//! \brief 获取框选
		UMaterialInstanceDynamic* GetRectSelectMaterial();

		//! \brief 获取组件类型
		ComponentType GetComponentType();

		//! \brief 设置链表Node
		void SetListNode(GameObjectListNode* pNode);

		//! \brief 获取链表Node
		GameObjectListNode* GetListNode();

		//! \brief 删除UE 子网格材质
		void RemoveUESubMeshMaterial();

		//! \brief 设置渲染场景名字
		void SetSceneName(FString strSceneName);

		//! \brief 获取渲染场景名字
		FString GetSceneName();
	private:
		//! \brief 设置可见性
		void SetVisibleForAllChildren(Gamebool bVisible, Gamebool bSetByParent, USuperMap_MeshComponentInterface* pSceneNode);
	
		//! \brief 判断组件类型
		ComponentType MakeComponentType();

		//! \brief 初始化BillboardMesh
		void InitBillboardMesh();

		//! \brief 是否开启碰撞检测
		Gamebool IsOpenCrash();
	private:
		//! \brief 渲染场景名字
		FString m_strSceneName;

		//! \brief GameComponent的名字
		Gamelong m_nNodeName;

		//! \brief 父GameComponent的名字
		Gamelong m_nParentNodeName;

		//! \brief GameComponent所在的场景类型
		SceneManagerType m_enSceneManagerType;

		//! \brief 场景节点
		USuperMap_MeshComponentInterface* m_pSceneNode;

		//! \brief 实体对象数据包
		GameEntityBase* m_pGameEntity;

		//! \brief 对象变换矩阵
		Matrix4d m_localToECEF;
		//! \brief 原始矩阵
		Matrix4d m_matUGCLocalToECEF;

		//! \brief 是否是上层支持渲染的对象类型
		Gamebool m_bSupport;

		//! \brief 原始材质参数
		TArray<GameMaterial*> m_vecGameMaterial;

		//! \brief UE子材质参数
		TArray<GameMaterial*> m_vecUESubMeshMaterial;

		//! \brief 使用的选择材质
		UMaterialInstanceDynamic* m_pSelectionMaterial;

		//! \brief 使用的框选材质
		UMaterialInstanceDynamic* m_pRectSelectMaterial;

		//! \brief 数据类型
		DataType m_enDataType;

		//! \brief 图层名
		FString m_strLayerName;

		//! \brief 当前组件的链表Node
		GameObjectListNode* m_pCurrentListNode;
	};
}