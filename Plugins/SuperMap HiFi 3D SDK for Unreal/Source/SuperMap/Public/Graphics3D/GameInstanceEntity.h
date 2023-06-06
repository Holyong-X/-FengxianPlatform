#pragma once

#include "CoreMinimal.h"
#include "Graphics3D/GameEntityBase.h"
#include "Core/RealspaceDLL.h"

class UStaticMesh;

namespace SuperMapSDK
{
	//! \brief 创建实例化实体对象
	typedef void*(*CreateInstanceEntityFunction)(void* pSceneNodeHandle, void* pDataVertexPackage, void* pArrIndexPackages, void* pArrMaterialParams, Gameint nSubMeshCount, Gamechar* strMeshName);

	//! \brief 获取实体对象渲染节点
	typedef void*(*GetInstanceMeshAttachComponentFunction)(void* pEntityHandle);

	//! \brief 写实例化信息
	typedef void (*WriteInstanceBufferFunction)(void* pEntityHandle, Gameint nIntanceSize, Gameint nSizeInFloatPerInstance, void* pValue);

	//! \brief 删除实例化对象
	typedef void(*DestroyInstanceEntityFunction)(void* pEntityHandle);

	//! \brief 设置包围盒
	typedef void(*SetInstanceBoundingBoxFunction)(void* pEntityHandle, void* pBoundBox);

	//! \brief 修改顶点颜色
	typedef void(*UpdateInstanceVertexColorHandleFunction)(void* pEntityHandle, Gameuint nColor, Gameuint nInstanceSize, Gameushort* pInstanceIds);

	//! \brief 创建实例化实体
	void* CreateInstanceEntity(void* pSceneNodeHandle, void* pDataVertexPackage, void* pArrIndexPackages , void* pArrMaterialParams, Gameint nSubMeshCount, Gamechar* strMeshName);

	//! \brief 获取实体对象
	void* GetInstanceMeshAttachComponent(void* pEntityHandle);

	//! \brief 写实例化信息
	void WriteInstanceBuffer(void* pEntityHandle, Gameint nIntanceSize, Gameint nSizeInFloatPerInstance, void* pValue);

	//! \brief 修改实例化的顶点颜色
	void SetInstanceVertexColor(void* pEntityHandle, Gameuint nColor, Gameuint nInstanceSize, Gameushort* pInstanceIds);

	//! \brief 删除实体对象
	void DestroyInstanceEntity(void* pEntityHandle);

	//! \brief 设置包围盒
	void SetInstanceBoundingBox(void* pEntityHandle, void* pBoundBox);

	class SUPERMAP_API GameInstanceEntity : public GameEntityBase
	{
	public:
		GameInstanceEntity();
		virtual ~GameInstanceEntity();

	public:
		//! \brief 初始化回掉函数
		static void InitializeCallbackHandle();

		//! \brief 设置实体网格名字
		void SetEntityMeshName(FString strEntityMeshName);

		//! \brief 获取实体网格名字
		FString GetEntityMeshName();

		//! \brief 设置静态网格
		void SetStaticMesh(UStaticMesh* pStaticMesh);

		//! \brief 获取静态网格
		UStaticMesh* GetStaticMesh();

		//! \brief Mesh是否上传显卡
		virtual Gamebool IsInitialGPU();

		void AddGameMaterial(GameMaterial* pGameMaterial);

		//! \brief 实体包类型
		virtual EntityType Type();
	private:
		//! \brief 骨架名字
		FString m_strEntityMeshName;

		//! \brief 静态网格
		UStaticMesh* m_pStaticMesh;

		//! \brief 使用的材质
		TArray<GameMaterial*> m_vecGameMaterial;
	public:
		//! \brief 实例化信息
		Gameint m_nInstanceSize;
		Gameint m_nSizeInFloatPerInstance;
		Gamevoid* m_pValue;
	};
}