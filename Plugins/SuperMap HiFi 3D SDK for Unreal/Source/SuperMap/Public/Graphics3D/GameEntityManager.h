#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEntity.h"
#include "Graphics3D/GameInstanceEntity.h"
#include "Engine/World.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	class SUPERMAP_API GameEntityManager
	{
	public:
		GameEntityManager();
		~GameEntityManager();

	public:
		//! \brief 获取单例类
		static GameEntityManager* GetSingleton();

		//! \brief 销毁单例类
		static void DestorySingleton();

		//! \brief 创建实体网格
		void* CreateEntity();

		//! \brief 删除实体网格
		void Remove(void* pEntityHandle);

		//! \brief 获取实体网格
		GameEntityBase* GetEntity(Gamelong nEntityHandle);

		//! \brief 创建实例化网格体
		void CreateInstanceEntity(Gamelong& nEntityHandle, GameInstanceEntity* & pInstanceEntity);

		//! \brief 获取静态网格映射表
		TMap<FString, TKeyValuePair<UStaticMesh*, Gameint> >& GetStaticMeshMaps();

		//! \brief 删除静态网格
		void RemoveStaticMesh(FString strStaticMeshName);

		//! \brief 骨架是否上传显卡
		Gamebool IsMeshInitialGPU(void* pEntityHandle);

		//! \brief 设置场景对象
		void SetWorld(UWorld* pWorld);

		//! \brief 获取场景对象
		UWorld* GetWorld();
	private:
		//! \brief 单键类指针
		static GameEntityManager* m_pEntityManager;

		//! \brief Entity表
		TMap<Gamelong, GameEntityBase*> m_mapEntitys;

		//! \brief StaticMesh表
		TMap<FString, TKeyValuePair<UStaticMesh*, Gameint> > m_mapStaticMeshs;

		//! \brief 世界场景对象
		UWorld* m_pWorld;
	};
}