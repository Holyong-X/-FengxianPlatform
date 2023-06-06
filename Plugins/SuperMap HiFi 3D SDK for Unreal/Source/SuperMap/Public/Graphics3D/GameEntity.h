#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameStruct.h"
#include "Graphics3D/GameMaterial.h"
#include "Graphics3D/GameEntityBase.h"
#include "Component/SuperMap_VertexBuffer.h"
#include "Component/SuperMap_CustomVertexBuffer.h"

class UMaterialInterface;
class USuperMap_MeshComponent;
namespace SuperMapSDK
{
	//! \brief 创建Entity网格
	typedef void*(*CreateEntityFunction)();

	//! \brief 销毁Entity
	typedef void(*DestroyEntityFunction)(void* pMeshHandle);

	//! \brief 设置数据包
	typedef void (*SetVertexDataPackageFunction)(void* pMeshHandle, GameDataVertexPackage* pVertexDataPackage);

	//! \brief 设置共享数据包
	typedef void(*SetVertexDataPackageSharedBufferFunction)(void* pMeshHandle, void* pGameVertexDataPackage, Gameint nOffset, UGVertexDataStateSet nState);
	
	//! \brief 设置索引包
	typedef void(*CreateSubMeshFunction)(void* pMeshHandle, GameIndexPackage* pIndexPackage);

	//! \brief 获取挂接的Component
	typedef void*(*GetAttachComponentFunction)(void* pMeshHandle);

	//! \brief 挂接材质
	typedef Gamebool(*AddMaterialFunction)(void* pMeshHandle, void* nMaterialHandle);

	//! \brief 添加及移除材质
	typedef Gamebool(*SubtractMaterialFunction)(void* pMeshHandle, void* nMaterialHandle);

	typedef Gamebool(*AppendMaterialFunction)(void* pMeshHandle, void* nMaterialHandle);


	//! \brief 设置渲染状态
	typedef Gamelong(*SetRenderStateFunction)(void* pMeshHandle, UGRenderStateSet nRenderState);

	//! \brief 设置边框线
	typedef void(*SetBoundingBoxFunction)(void* pMeshHandle, void* pBoundBox);

	//! \brief 清除所有子网格
	typedef void(*RemoveAllSubMeshFunction)(void* pMeshHandle, Gamebool bReleaseMaterial);

	//! \brief 判断是否骨架上床显卡
	typedef Gamebool(*IsMeshInitialGPUFunction)(void* pMeshHandle);

	//! \brief 添加子网格材质
	typedef void(*AddSubMeshMaterialFunction)(void* pMeshHandle, char* strMaterialName);

	//! \brief 添加子网格
	typedef void(*UpdateSubMeshesFunction)(Gamevoid* pMeshHandle, Gamevoid** pGameIndexPackages, Gameint nCount);

	//! \brief 创建实体对象
	void* CreateEntity();

	//! \brief 销毁实体对象
	void DestroyEntity(void* pMeshHandle);

	//! \brief 设置数据包
	void SetVertexDataPackage(void* pMeshHandle, GameDataVertexPackage* pVertexDataPackage);

	//! \brief 设置共享数据包
	void SetVertexDataPackageSharedBuffer(void* pMeshHandle, void* pGameVertexDataPackage, Gameint nOffset, UGVertexDataStateSet nState);

	//! \brief 设置索引包
	void CreateSubMesh(void* pMeshHandle, GameIndexPackage* pIndexPackage);

	//! \brief 添加索引材质
	void AddSubMeshMaterial(void* pMeshHandle, char* strMaterialName);

	//! \brief 添加子网格索引
	void UpdateSubMeshes(Gamevoid* pMeshHandle, Gamevoid** pIndexPackages, Gameint nCount);

	//! \brief 获取挂接的场景节点
	void* GetAttachComponent(void* pMeshHandle);

	//! \brief 创建材质
	Gamebool AddMaterial(void* pMeshHandle, void* pMaterialHandle);

	//! \brief 添加及移除材质
	Gamebool SubtractMaterial(void* pMeshHandle, void* pMaterialHandle);

	Gamebool AppendMaterial(void* pMeshHandle, void* pMaterialHandle);


	//! \brief 设置渲染状态
	Gamelong SetRenderState(void* pMeshHandle, UGRenderStateSet nRenderState);

	//! \brief 设置边框线
	void SetBoundingBox(void* pMeshHandle, void* pBoundBox);

	//! \brief 清除所有子网格
	void RemoveAllSubMesh(void* pMeshHandle, Gamebool bReleaseMaterial);

	//! \brief 骨架是否上传显卡
	Gamebool IsMeshInitialGPU(void* pMeshHandle);


	struct GameUpdateMesh
	{
	public:
		DataVertex* m_pUpdateDataVertex;
		Gameint m_nUpdateOffset;
		UGVertexDataStateSet m_nUpdateState;

		GameUpdateMesh()
		{
			m_pUpdateDataVertex = nullptr;
			m_nUpdateOffset = 0;
			m_nUpdateState = VST_ALL;
		}
	};

	class GameComponent;
	class SUPERMAP_API GameEntity : public GameEntityBase
	{
	public:
		GameEntity();
		virtual ~GameEntity();

	public:
		//! \brief 初始化回掉函数
		static void InitializeCallbackHandle();

		//! \brief 异步上传
		void AsyncUploadEntity();

		//! \brief 异步更新
		void AsyncUpdateEntity(DataVertex* pDataVertex, Gameint nOffset, UGVertexDataStateSet nState);

		//! \brief 创建碰撞网格数据
		void CreateCollisionData();

		//! \brief 获取碰撞检测
		FSMMeshCollisionData* GetCollisionData();

		//! \brief 设置碰撞检测
		void SetCollisionData(FSMMeshCollisionData* pCollisionData);

		//! \brief 设置异步完成
		void SetAsyncLoading(Gamebool bAsyncLoading);

		//! \brief 获取异步是否完成
		Gamebool GetAsyncLoading();

		//! \brief 设置更新的骨架
		Gamevoid SetAsyncUpdateMesh(DataVertex* pDataVertex, Gameint nOffset, UGVertexDataStateSet nState);

		//! \brief 是否有更新
		Gamebool IsNeedUpdate();

		//! \brief 获取更新的骨架（外部释放）
		TArray<GameUpdateMesh*>& GetUpdateMesh();

		//! \brief 实体包类型
		virtual EntityType Type();
	private:
		//! \brief 碰撞检测网格
		FSMMeshCollisionData* m_pSMMeshCollisionData;

		//! \brief 是否异步
		Gamebool m_bAsyncLoading;

		//! \brief 安全
		Gamebool m_bReleaseBuffer;

		//! \brief 异步更新骨架
		TArray<GameUpdateMesh*> m_arrUpdateMeshs;
	};
}