#include "Graphics3D/GameEntityManager.h"
#include "Async/Async.h"
#include "Base3D/CommonDefine.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Core;

namespace SuperMapSDK
{
	GameEntityManager* GameEntityManager::m_pEntityManager = nullptr;
	GameEntityManager::GameEntityManager()
	{

	}

	GameEntityManager::~GameEntityManager()
	{
		m_mapEntitys.Empty();
		m_mapStaticMeshs.Empty();
	}

	GameEntityManager* GameEntityManager::GetSingleton()
	{
		if (m_pEntityManager == nullptr)
		{
			m_pEntityManager = new GameEntityManager();
		}

		return m_pEntityManager;
	}

	void GameEntityManager::DestorySingleton()
	{
		if (m_pEntityManager != nullptr)
		{
			delete m_pEntityManager;
			m_pEntityManager = nullptr;
		}
	}

	void GameEntityManager::RemoveStaticMesh(FString strStaticMeshName)
	{
		Gamebool bHas = m_mapStaticMeshs.Contains(strStaticMeshName);
		if (bHas)
		{
			TKeyValuePair<UStaticMesh*, Gameint>& pair = m_mapStaticMeshs[strStaticMeshName];

			Gameint nRefCount = pair.Value - 1;
			pair.Value = nRefCount;
			if (nRefCount == 0)
			{
				m_mapStaticMeshs.Remove(strStaticMeshName);
			}
		}
	}

	void GameEntityManager::SetWorld(UWorld* pWorld)
	{
		m_pWorld = pWorld;
	}

	UWorld* GameEntityManager::GetWorld()
	{
		return m_pWorld;
	}

	TMap<FString, TKeyValuePair<UStaticMesh*, Gameint> >& GameEntityManager::GetStaticMeshMaps()
	{
		return m_mapStaticMeshs;
	}

	void GameEntityManager::CreateInstanceEntity(Gamelong& nEntityHandle, GameInstanceEntity* & pInstanceEntity)
	{
		GameInstanceEntity* pGameEntity = new GameInstanceEntity;
		void* pVoidGameEntity = (void*)pGameEntity;
		nEntityHandle = _CalHashCode(pVoidGameEntity);
		pGameEntity->SetEntityName(nEntityHandle);
		pInstanceEntity = pGameEntity;
		m_mapEntitys.Add(nEntityHandle, pGameEntity);
	}

	void* GameEntityManager::CreateEntity()
	{
		GameEntity* pGameEntity = new GameEntity;
		void* pVoidGameEntity = (void*)pGameEntity;
		Gamelong nEntityHandle = _CalHashCode(pVoidGameEntity);
		pGameEntity->SetEntityName(nEntityHandle);
		m_mapEntitys.Add(nEntityHandle , pGameEntity);

		return pVoidGameEntity;
	}

	void GameEntityManager::Remove(void* pEntityHandle)
	{
		// 异步卸载
		GameEntityBase* pGameEntityBase = (GameEntityBase*)pEntityHandle;
		Gamelong nEntityHandle = pGameEntityBase->GetEntityName();
		if (pGameEntityBase->IsCanAsync())
		{
			GameEntity* pGameEntity = (GameEntity*)pGameEntityBase;
			auto result = Async<>(EAsyncExecution::ThreadPool, [pGameEntity]() {
				GameEntity* pTempGameEntity = pGameEntity;
				while (pGameEntity != nullptr &&
					(!pGameEntity->GetAsyncLoading() ||
						!pGameEntity->IsUpdateGPU())) {
				}

				delete pTempGameEntity;
				});
		}
		else
		{
			delete pGameEntityBase;
		}
		m_mapEntitys.Remove(nEntityHandle);
	}

	GameEntityBase* GameEntityManager::GetEntity(Gamelong nEntityHandle)
	{
		Gamebool bHas = m_mapEntitys.Contains(nEntityHandle);
		if (bHas)
		{
			return m_mapEntitys[nEntityHandle];
		}

		return nullptr;
	}

	Gamebool GameEntityManager::IsMeshInitialGPU(void* pEntityHandle)
	{
		// 在编辑模式下不用异步
		if (m_pWorld->WorldType == EWorldType::Editor || !m_bEnableAsync)
		{
			return true;
		}

		GameEntityBase* pGameEntity = (GameEntityBase*)pEntityHandle;
		if (pGameEntity->GetDataVertexPackage() != nullptr && pGameEntity->GetIndexPackageCount() == 0)
		{
			return true;
		}

		Gamebool bInitial = pGameEntity->IsInitialGPU();
		return bInitial;
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif