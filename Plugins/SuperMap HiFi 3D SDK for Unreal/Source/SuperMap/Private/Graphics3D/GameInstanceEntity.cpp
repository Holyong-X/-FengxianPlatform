#include "Graphics3D/GameInstanceEntity.h"
#include "Graphics3D/GameConvertor.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameComponent.h"
#include "Graphics3D/GameMaterialManager.h"
#include "Graphics3D/GameEntityManager.h"
#include "Base3D/StatsGroupDefine.h"

namespace SuperMapSDK
{
	GameInstanceEntity::GameInstanceEntity():GameEntityBase()
	{
		m_pStaticMesh = nullptr;
		m_nInstanceSize = 0;
		m_nSizeInFloatPerInstance = 0;
		m_pValue = nullptr;
	}

	GameInstanceEntity::~GameInstanceEntity()
	{
		GameEntityManager::GetSingleton()->RemoveStaticMesh(m_strEntityMeshName);

		// 因为实例化对象底层没释放创建的材质，所以这里释放
		for(int i = 0; i < m_vecGameMaterial.Num(); i++)
		{
			GameMaterialManager::GetSingleton()->RemoveGameMaterial(m_vecGameMaterial[i]);
		}
		m_vecGameMaterial.Empty();
	}

	void GameInstanceEntity::InitializeCallbackHandle()
	{
		InstanceCallbackHandleCollector collector;
		collector.createInstanceEntity = (void*)CreateInstanceEntity;
		collector.destroyInstanceMesh = (void*)DestroyInstanceEntity;
		collector.getInstanceMeshAttachComponent = (void*)GetInstanceMeshAttachComponent;
		collector.writeInstanceBuffer = (void*)WriteInstanceBuffer;
		collector.setInstanceBoundingBox = (void*)SetInstanceBoundingBox;
		collector.updateInstanceVertexColor = (void*)SetInstanceVertexColor;

		if (_InitInstanceMeshCallbackHandle != nullptr)
		{
			_InitInstanceMeshCallbackHandle((void*)&collector);
		}
	}

	void GameInstanceEntity::SetEntityMeshName(FString strEntityMeshName)
	{
		m_strEntityMeshName = strEntityMeshName;
	}

	FString GameInstanceEntity::GetEntityMeshName()
	{
		return m_strEntityMeshName;
	}

	void GameInstanceEntity::SetStaticMesh(UStaticMesh* pStaticMesh)
	{
		m_pStaticMesh = pStaticMesh;
	}

	UStaticMesh* GameInstanceEntity::GetStaticMesh()
	{
		return m_pStaticMesh;
	}

	Gamebool GameInstanceEntity::IsInitialGPU()
	{
		return true;
	}

	EntityType GameInstanceEntity::Type()
	{
		return ET_INSTANCE;
	}

	void GameInstanceEntity::AddGameMaterial(GameMaterial* pGameMaterial)
	{
		m_vecGameMaterial.Add(pGameMaterial);
	}

	void* CreateInstanceEntity(void* pSceneNodeHandle, void* pDataVertexPackage, void* pArrIndexPackages, void* pArrMaterialParams, Gameint nSubMeshCount, Gamechar* strMeshName)
	{
		STATS_SM_CREATEINSTANCEENTITY

		GameComponent* pGameComponent = (GameComponent*)pSceneNodeHandle;
		if (pGameComponent == nullptr)
		{
			return nullptr;
		}
		Gamelong nSceneNodeHandle = pGameComponent->GetNodeName();
		GameDataVertexPackage* pGameDataVertexPackage = (GameDataVertexPackage*)pDataVertexPackage;
		GameIndexPackage** pArrGameIndexPackages = (GameIndexPackage**)pArrIndexPackages;
		GameMaterialParam** pArrGameMaterialParams = (GameMaterialParam**)pArrMaterialParams;
				
		if (pGameDataVertexPackage == nullptr || pArrGameIndexPackages == nullptr||
			pArrGameMaterialParams == nullptr || nSubMeshCount <= 0)
		{
			return 0;
		}

		GameInstanceEntity* pGameInstanceEntity = nullptr;
		Gamelong nEntityHandle = 0;
		GameEntityManager::GetSingleton()->CreateInstanceEntity(nEntityHandle, pGameInstanceEntity);
		pGameComponent->SetEntity(pGameInstanceEntity);
		pGameInstanceEntity->SetSceneNodeName(nSceneNodeHandle);

		for(int i = 0; i < nSubMeshCount; i++)
		{
			GameMaterial* pGameMaterial = (GameMaterial*)GameMaterialManager::GetSingleton()->CreateGameMaterial(pArrGameMaterialParams[i]);
			pGameMaterial->InitMaterial();

			if (pGameMaterial == nullptr || pGameMaterial->GetMID() == nullptr)
			{
				pGameComponent->SetSupport(false);
			}
			else
			{
				pGameComponent->AddGameMaterial(pGameMaterial);
				pGameInstanceEntity->AddGameMaterial(pGameMaterial);
			}
		}

		// 放在这里是因为此时GameComponent才创建好材质，图层会用到材质
		SuperMapSDK::UnrealEngine::Core::Scene* pScene = (SuperMapSDK::UnrealEngine::Core::Scene*)GameObjectManager::GetSingleton()->GetScene();
		pScene->AddNativeGameComponent(pGameComponent);

		// 设置骨架名字
		FString strUEMeshName = UTF8_TO_TCHAR(strMeshName);
		pGameInstanceEntity->SetEntityMeshName(strUEMeshName);

		// 转换骨架
		DataVertex* pDataVertex = new DataVertex;
		GameConvertor::GameDataVertexPackageToDataVertex(pGameDataVertexPackage, pDataVertex);
		pGameInstanceEntity->SetDataVertexPackage(pDataVertex);

		// 现在先只支持一重索引和材质
		if(nSubMeshCount > 0)
		{
			// 转换索引
			DataIndice* pDataIndice = new DataIndice;
			GameConvertor::GameIndexPackageToDataIndice(pArrGameIndexPackages[0], pDataIndice);
			pGameInstanceEntity->AddIndexPackage(pDataIndice);
					
			// 材质没用
		}

		UStaticMesh* pStaticMesh = nullptr;

		Gameint nIndex = strUEMeshName.Find(TEXT("StaticMesh"));
		// 外挂模型的情况
		if (nIndex != INDEX_NONE)
		{
			strUEMeshName.RemoveAt(0, nIndex);

			TMap<FString, TKeyValuePair<UStaticMesh*, Gameint> >& mapStaticMeshs = GameEntityManager::GetSingleton()->GetStaticMeshMaps();
			Gamebool bHas = mapStaticMeshs.Contains(strUEMeshName);
			if (bHas)
			{
				TKeyValuePair<UStaticMesh*, Gameint>& pair = mapStaticMeshs[strUEMeshName];
				pStaticMesh = pair.Key;
				pair.Value++;
			}
			else
			{
				pStaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *strUEMeshName));

				if (pStaticMesh != nullptr)
				{
					TKeyValuePair<UStaticMesh*, int32> pairInfo;
					pairInfo.Key = pStaticMesh;
					pairInfo.Value = 1;

					mapStaticMeshs.Add(strUEMeshName, pairInfo);
				}
			}

			pGameInstanceEntity->SetStaticMesh(pStaticMesh);
		}

		TMap<Gamelong, GameComponent*>& mapRenderGameComponents = GameObjectManager::GetSingleton()->GetRenderGameComponent();
		mapRenderGameComponents.Add(nSceneNodeHandle, pGameComponent);

		return (void*)pGameInstanceEntity;
	}

	void* GetInstanceMeshAttachComponent(void* pEntityHandle)
	{
		STATS_SM_GETINSTANCEMESHATTACHCOMPONENT

		GameInstanceEntity* pGameEntity = (GameInstanceEntity*)pEntityHandle;
		if (pGameEntity != nullptr)
		{
			return (void*)pGameEntity->GetGameComponent();
		}

		return nullptr;
	}

	void WriteInstanceBuffer(void* pEntityHandle, Gameint nInstanceSize, Gameint nSizeInFloatPerInstance, void* pValue)
	{
		STATS_SM_WRITEINSTANCEBUFFER

		GameInstanceEntity* pGameEntity = (GameInstanceEntity*)pEntityHandle;
		if (pGameEntity == nullptr)
		{
			return;
		}

		Gamebool bAsync = false;
		TArray<GameMaterial*>& arrMaterials = pGameEntity->GetGameComponent()->GetAllGameMaterial();
		for (Gameint i = 0; i < arrMaterials.Num(); i++)
		{
			GameMaterial* pGameMaterial = arrMaterials[i];
			if (pGameMaterial && pGameMaterial->GetNumUnsetTexture() > 0)
			{
				bAsync = true;
				break;
			}
		}
		if (bAsync)
		{
			pGameEntity->m_nInstanceSize = nInstanceSize;
			pGameEntity->m_nSizeInFloatPerInstance = nSizeInFloatPerInstance;
			pGameEntity->m_pValue = FMemory::Malloc(sizeof(Gamefloat) * nInstanceSize * nSizeInFloatPerInstance);
			FMemory::Memcpy(pGameEntity->m_pValue, pValue, sizeof(Gamefloat) * nInstanceSize * nSizeInFloatPerInstance);

			GameComponent* pGameComponent = pGameEntity->GetGameComponent();
			GameObjectManager::GetSingleton()->AddUnitialComponent(pGameComponent);
		}
		else
		{
			pGameEntity->GetGameComponent()->InitInstanceMesh(nInstanceSize, nSizeInFloatPerInstance, pValue);
		}
	}

	void SetInstanceVertexColor(void* pEntityHandle, Gameuint nColor, Gameuint nInstanceSize, Gameushort* pInstanceIds)
	{
		GameInstanceEntity* pGameEntity = (GameInstanceEntity*)pEntityHandle;
		if (pGameEntity == nullptr)
		{
			return;
		}
		TArray<uint32> arrIds;
		for(Gameuint i = 0; i < nInstanceSize; i++)
		{
			arrIds.Add(pInstanceIds[i]);
		}
		pGameEntity->GetGameComponent()->UpdateInstanceVertexColor(nColor, arrIds);
	}

	void DestroyInstanceEntity(void* pEntityHandle)
	{
		STATS_SM_DESTROYINSTANCEENTITY

		GameEntityManager::GetSingleton()->Remove(pEntityHandle);
	}

	void SetInstanceBoundingBox(void* pEntityHandle, void* pBoundBox)
	{
		STATS_SM_SETINSTANCEBOUNDINGBOX
		
		GameInstanceEntity* pGameEntity = (GameInstanceEntity*)pEntityHandle;
		if (pGameEntity == nullptr)
		{
			return;
		}
		GameBoundingBox* pGameBoundBox = (GameBoundingBox*)pBoundBox;

		GameBoundingBox boundBox = *pGameBoundBox;

		Swap(boundBox.m_vMin.x, boundBox.m_vMin.y);
		Swap(boundBox.m_vMax.x, boundBox.m_vMax.y);

		boundBox.m_vMin.x *= M_TO_CM;
		boundBox.m_vMin.y *= M_TO_CM ;
		boundBox.m_vMin.z *= M_TO_CM;

		boundBox.m_vMax.x *= M_TO_CM;
		boundBox.m_vMax.y *= M_TO_CM;
		boundBox.m_vMax.z *= M_TO_CM;

		pGameEntity->SetBBox(boundBox);
	}
}