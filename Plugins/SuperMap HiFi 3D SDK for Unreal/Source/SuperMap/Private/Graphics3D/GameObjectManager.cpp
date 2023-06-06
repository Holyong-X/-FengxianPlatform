#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameEntityManager.h"
#include "Graphics3D/GameRenderTextureManager.h"
#include "Core/Scene.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Component/SuperMap_OcclusionVolumeComponent.h"
#include "Async/Async.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	GameObjectManager* GameObjectManager::m_pGameObjectManager = nullptr;
	GameObjectManager::GameObjectManager()
	{
		m_pRootNode = nullptr;
		m_pScene = nullptr;
		m_pWorld = nullptr;
		m_bEnableCollision = false;
		m_pHead = nullptr;
		m_pTail = nullptr;
	}

	GameObjectManager::~GameObjectManager()
	{
		for (TMap<Gamelong, GameOcclusionVolume*>::TConstIterator It = m_mapOcclusionVolumes.CreateConstIterator(); It; ++It)
		{
			delete It->Value;
		}

		for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapGameComponents.CreateConstIterator(); It; ++It)
		{
			delete It->Value;
		}

		if (m_pHead != nullptr)
		{
			if (m_pHead->m_pNext == nullptr)
			{
				delete m_pHead;
			}
			else
			{
				while (m_pHead->m_pNext != nullptr)
				{
					GameObjectListNode* pListNode = m_pHead;

					m_pHead = m_pHead->m_pNext;
					m_pHead->m_pPrev = nullptr;

					delete pListNode;
				}

				if (m_pHead != nullptr)
				{
					delete m_pHead;
				}
			}
		}
		if (m_pRootNode != nullptr)
		{
			m_pRootNode->Destroy();
			m_pRootNode = nullptr;
		}
		m_pHead = nullptr;
		m_pTail = nullptr;
		m_mapGameComponents.Empty();
		m_mapRenderGameComponents.Empty();
		m_mapSceneRootComponent.Empty();
		m_mapInstancedActors.Empty();
		m_mapUnInitialComponents.Empty();
		m_mapSplineActors.Empty();
		m_arrVectorActors.Empty();
		m_arrLineMeshActors.Empty();
		m_arrTextActors.Empty();
		m_arrSceneHiddenActors.Empty();
	}

	void* GameObjectManager::CreateOcclusionVolume(Gamelong nIDName)
	{
		Gamebool bHas = m_mapOcclusionVolumes.Contains(nIDName);
		if (!bHas)
		{
			USuperMap_OcclusionVolumeComponent* pComponent = NewObject<USuperMap_OcclusionVolumeComponent>(m_pRootNode);
			pComponent->RegisterComponent();
			GameOcclusionVolume* pOcclusionVolume = new GameOcclusionVolume(nIDName, pComponent);
			m_mapOcclusionVolumes.Add(nIDName, pOcclusionVolume);
		}
		
		return nullptr;
	}

	void GameObjectManager::DestroyOcclusionVolume(void* pOcclusionVolumeHandle)
	{
		GameOcclusionVolume* pOcclusionVolume = (GameOcclusionVolume*)pOcclusionVolumeHandle;
		Gamelong nIDName = pOcclusionVolume->GetIDName();
		if (pOcclusionVolume)
		{
			delete pOcclusionVolume;
			pOcclusionVolume = nullptr;
		}
		m_mapOcclusionVolumes.Remove(nIDName);
	}

	void GameObjectManager::DestorySingleton()
	{
		if (m_pGameObjectManager != nullptr)
		{
			delete m_pGameObjectManager;
			m_pGameObjectManager = nullptr;
		}
	}

	GameObjectManager* GameObjectManager::GetSingleton()
	{
		if (m_pGameObjectManager == NULL)
		{
			m_pGameObjectManager = new GameObjectManager();
		}

		return m_pGameObjectManager;
	}

	void GameObjectManager::SetWorld(UWorld* pWorld)
	{
		m_pWorld = pWorld;
	}

	UWorld* GameObjectManager::GetWorld()
	{
		return m_pWorld;
	}

	void GameObjectManager::SetScene(void* pScene)
	{
		m_pScene = pScene;
	}

	void* GameObjectManager::GetScene()
	{
		return m_pScene;
	}

	GameComponent* GameObjectManager::GetGameComponent(Gamelong nSceneNodeHandle)
	{
		Gamebool bHas = m_mapGameComponents.Contains(nSceneNodeHandle);
		if (bHas)
		{
			return m_mapGameComponents[nSceneNodeHandle];
		}

		return nullptr;
	}

	USuperMap_MeshComponentInterface* GameObjectManager::CreateComponent(FName& name)
	{
		if (m_pWorld == NULL || m_pRootNode == nullptr)
		{
			return NULL;
		}

		USuperMap_MeshComponentInterface* pMeshInterface = NewObject<USuperMap_MeshComponentInterface>(m_pRootNode);
		pMeshInterface->SetMobility(EComponentMobility::Type::Movable);
		pMeshInterface->SetFlags(RF_Transient | RF_DuplicateTransient | RF_TextExportTransient);
		pMeshInterface->RegisterComponent();
		pMeshInterface->SetName(name);
		return pMeshInterface;
	}

	void* GameObjectManager::GetOrCreateRootSceneNode(Gamechar* strSceneName, Gameint nSceneManagerType)
	{
		Gamelong nHashCodeName = _CalHashCodeByChar(strSceneName);

		// 创建一个根节点的Actor
		if (m_pRootNode == nullptr)
		{
			m_pRootNode = m_pWorld->SpawnActor<ASuperMap_ROEntityActor>();
			m_pRootNode->Tags.Add(TEXT("SUPERMAP"));
		}

		// 创建一个根节点的组件
		FName strName(strSceneName);
		FString strSName = strName.ToString();

		Gamebool bContains = m_mapSceneRootComponent.Contains(strSName);
		if (!bContains)
		{
			USuperMap_MeshComponentInterface* pRootMeshComponent = CreateComponent(strName);
			GameComponent* pGameComponent = new GameComponent(nHashCodeName, 0, nSceneManagerType);
			pGameComponent->SetSceneNode(pRootMeshComponent);
			pGameComponent->SetSceneName(strSName);

			m_mapGameComponents.Add(nHashCodeName, pGameComponent);
			m_mapSceneRootComponent.Add(strSName, pGameComponent);

			return (void*)pGameComponent;
		}
		else
		{
			return (void*)m_mapSceneRootComponent[strSName];
		}
	}

	void GameObjectManager::DestroySceneNode(void* pSceneNodeHandle)
	{
		GameComponent* pGameComponent = (GameComponent*)pSceneNodeHandle;
		if (pGameComponent == nullptr)
		{
			return;
		}
		SuperMapSDK::UnrealEngine::Core::Scene* pScene = (SuperMapSDK::UnrealEngine::Core::Scene*)m_pScene;
		pScene->RemoveNativeGameComponent(pGameComponent);

		FString strSceneName = pGameComponent->GetSceneName();
		if (pGameComponent->GetSceneManagerType() == REAL_TIME_ELEVATION_S3M || 
			pGameComponent->GetSceneManagerType() == REAL_TIME_RASTER ||
			strSceneName.Find(TEXT("_SpatialQuery")) != -1)
		{
			GameRenderTextureManager::GetSingleton()->RemoveGameComponent(pGameComponent);
		}

		RemoveUnitialComponent(pGameComponent);

		Gamelong nSceneNodeHandle = pGameComponent->GetNodeName();
		m_mapGameComponents.Remove(nSceneNodeHandle);
		m_mapRenderGameComponents.Remove(nSceneNodeHandle);
		m_mapUnInitialComponents.Remove(nSceneNodeHandle);

		delete pGameComponent;
	}

	void GameObjectManager::SetObjectMatrix(void* pSceneNodeHandle, Gamedouble* pMatrix)
	{
		GameComponent* pGameComponent = (GameComponent*)pSceneNodeHandle;
		if (pGameComponent == nullptr)
		{
			return;
		}
		pGameComponent->SetObjectMatrix(pMatrix);
	}

	void GameObjectManager::SetVisible(void* pSceneNodeHandle, Gamebool bVisible)
	{
		GameComponent* pGameComponent = (GameComponent*)pSceneNodeHandle;
		pGameComponent->SetObjectVisible(bVisible);
	}

	void GameObjectManager::SetSceneNodeVisible(void* pSceneNodeHandle, Gamebool bVisible)
	{
		GameComponent* pGameComponent = (GameComponent*)pSceneNodeHandle;
		pGameComponent->SetSceneNodeVisible(bVisible);
	}

	Gamebool GameObjectManager::AttachEntity(void* pSceneNodeHandle, void* pMeshHandle)
	{
		GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
		GameComponent* pComponent = (GameComponent*)pSceneNodeHandle;
		if (pGameEntity != nullptr && pComponent != nullptr)
		{
			pComponent->SetEntity(pGameEntity);

			Gamelong nSceneNodeHandle = pComponent->GetNodeName();
			m_mapRenderGameComponents.Add(nSceneNodeHandle, pComponent);
			return true;
		}

		return false;
	}

	void* GameObjectManager::CreateChildSceneNode(void* pParentNodeHandle, Gamelong nSceneNodeName, Gameint nSceneManagerType)
	{
		GameComponent* pGameComponent = (GameComponent*)pParentNodeHandle;
		if (pGameComponent == nullptr)
		{
			return nullptr;
		}

		USuperMap_MeshComponentInterface* pParent = pGameComponent->GetSceneNode();

		Gamelong nParentNodeHandle = pGameComponent->GetNodeName();

		FName strName;
		USuperMap_MeshComponentInterface* pComponent = CreateComponent(strName);
		if (pParent != nullptr)
		{
			FAttachmentTransformRules transformRules(EAttachmentRule::KeepRelative, true);
			pComponent->AttachToComponent(pParent, transformRules);

			pComponent->SetLayerVisibility(pParent->GetLayerVisibility());
		}

		FString strSceneName = pGameComponent->GetSceneName();

		GameComponent* pNewGameComponent = new GameComponent(nSceneNodeName, nParentNodeHandle, nSceneManagerType);
		pNewGameComponent->SetSceneNode(pComponent);
		pNewGameComponent->SetSceneName(strSceneName);
		m_mapGameComponents.Add(nSceneNodeName, pNewGameComponent);

		// TODO 目前仅支持这个场景类型的对象实时栅格化
		if (pNewGameComponent->GetSceneManagerType() == REAL_TIME_ELEVATION_S3M ||
			pNewGameComponent->GetSceneManagerType() == REAL_TIME_RASTER ||
			pGameComponent->GetSceneManagerType() == REAL_TIME_RASTER ||
			strSceneName.Find(TEXT("_SpatialQuery")) != -1)
		{
			GameRenderTextureManager::GetSingleton()->AddGameComponent(pNewGameComponent);
		}

		return (void*)pNewGameComponent;
	}

	void GameObjectManager::UpdateWorldOrigin(Vector3d vOrigin)
	{
		for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapRenderGameComponents.CreateConstIterator(); It; ++It)
		{
			GameComponent* pGameComponent = It->Value;
			if (pGameComponent != nullptr)
			{
				pGameComponent->UpdateWorldOrigin(vOrigin);
			}
		}
	}

	TMap<Gamelong, GameComponent*>& GameObjectManager::GetRenderGameComponent()
	{
		return m_mapRenderGameComponents;
	}

	TMap<Gamelong, GameComponent*>& GameObjectManager::GetAllGameComponent()
	{
		return m_mapGameComponents;
	}

	TMap<uint32, ASuperMap_InstancedActor*>& GameObjectManager::GetInstancedActors()
	{
		return m_mapInstancedActors;
	}

	TMap<uint32, ASuperMap_SplineActor*>& GameObjectManager::GetSplineActors()
	{
		return m_mapSplineActors;
	}

	TArray<ASuperMap_CustomVectorActor*>& GameObjectManager::GetVectorActors()
	{
		return m_arrVectorActors;
	}

	TArray<ASuperMap_ROEntityActor*>& GameObjectManager::GetLineMeshActors()
	{
		return m_arrLineMeshActors;
	}

	TArray<ASuperMap_TextActor*>& GameObjectManager::GetTextActors()
	{
		return m_arrTextActors;
	}

	TArray<AActor*> & GameObjectManager::GetSceneHiddenActors()
	{
		return m_arrSceneHiddenActors;
	}
		
	GameObjectListNode* GameObjectManager::GetUnInitialListNode()
	{
		return m_pHead;
	}

	void GameObjectManager::AddUnitialComponent(GameComponent* pGameComponent)
	{
		if (m_pHead == nullptr && m_pTail == nullptr)
		{
			m_pHead = new GameObjectListNode;
			m_pTail = m_pHead;

			m_pHead->m_pGameComponent = pGameComponent;
			pGameComponent->SetListNode(m_pHead);
			m_pHead->m_pNext = m_pTail;
			m_pTail->m_pPrev = m_pHead;
			return;
		}

		GameObjectListNode* pCurrent = new GameObjectListNode;
		pCurrent->m_pGameComponent = pGameComponent;
		m_pTail->m_pNext = pCurrent;
		pCurrent->m_pPrev = m_pTail;
		pGameComponent->SetListNode(pCurrent);
		m_pTail = pCurrent;
	}

	void GameObjectManager::RemoveUnitialComponent(GameComponent* pGameComponent)
	{
		GameObjectListNode* pListNode = pGameComponent->GetListNode();

		if (pListNode == nullptr)
		{
			return;
		}

		if (pListNode == m_pHead)
		{
			if (m_pHead == m_pTail)
			{
				m_pHead = nullptr;
				m_pTail = nullptr;
			}
			else
			{
				m_pHead = m_pHead->m_pNext;
				if (m_pHead != nullptr)
				{
					m_pHead->m_pPrev = nullptr;
				}
			}
		}
		else if (pListNode == m_pTail)
		{
			m_pTail = m_pTail->m_pPrev;
			if (m_pTail != nullptr)
			{
				m_pTail->m_pNext = nullptr;
			}	
		}
		else
		{
			pListNode->m_pPrev->m_pNext = pListNode->m_pNext;
			pListNode->m_pNext->m_pPrev = pListNode->m_pPrev;
		}

		pGameComponent->SetListNode(nullptr);

		delete pListNode;
	}

	void GameObjectManager::SetEnableCollision(Gamebool bEnable)
	{
		m_bEnableCollision = bEnable;
	}

	Gamebool GameObjectManager::IsEnableCollision()
	{
		return m_bEnableCollision;
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif