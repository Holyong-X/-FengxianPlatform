#include "Graphics3D/GameEntity.h"
#include "Graphics3D/GameEntityManager.h"
#include "Graphics3D/GameMaterialManager.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameConvertor.h"
#include "Graphics3D/GameComponent.h"
#include "Materials/MaterialInterface.h"
#include "Core/Scene.h"
#include "Async/Async.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/StatsGroupDefine.h"
#include "Component/SuperMap_LineVertexBuffer.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	
	GameEntity::GameEntity()
	{
		m_pSMMeshCollisionData = nullptr;
		m_bAsyncLoading = false;
		m_bReleaseBuffer = true;
	}

	GameEntity::~GameEntity()
	{
		Gameint nCount = m_arrUpdateMeshs.Num();

		for (Gameint i = 0; i < nCount; i++)
		{
			GameUpdateMesh* pUpdateMesh = m_arrUpdateMeshs[i];

			if (pUpdateMesh->m_pUpdateDataVertex != nullptr)
			{
				delete pUpdateMesh->m_pUpdateDataVertex;
				pUpdateMesh->m_pUpdateDataVertex = nullptr;
			}

			delete pUpdateMesh;
		}

		m_arrUpdateMeshs.Empty();

		if (m_pSMMeshCollisionData != nullptr)
		{
			delete m_pSMMeshCollisionData;
			m_pSMMeshCollisionData = nullptr;
		}

		
	}

	void GameEntity::InitializeCallbackHandle()
	{
		CreateEntityFunction createEntity = CreateEntity;
		DestroyEntityFunction destroyEntity = DestroyEntity;
		SetVertexDataPackageFunction setVertexDataPackage = SetVertexDataPackage;
		SetVertexDataPackageSharedBufferFunction setVertexDataPackageSharedBuffer = SetVertexDataPackageSharedBuffer;
		CreateSubMeshFunction createSubMesh = CreateSubMesh;
		GetAttachComponentFunction getAttachComponent = GetAttachComponent;
		AddMaterialFunction	addMaterial = AddMaterial;
		AppendMaterialFunction appendMaterial = AppendMaterial;
		SubtractMaterialFunction subtractMaterial = SubtractMaterial;
		SetRenderStateFunction setRenderState = SetRenderState;
		SetBoundingBoxFunction setBoundingBox = SetBoundingBox;
		RemoveAllSubMeshFunction removeAllSubMesh = RemoveAllSubMesh;
		IsMeshInitialGPUFunction isMeshInitialGPU = IsMeshInitialGPU;
		AddSubMeshMaterialFunction addSubMeshMaterial = AddSubMeshMaterial;
		UpdateSubMeshesFunction updateSubMeshes = UpdateSubMeshes;

		if (_InitEntityCallbackHandle != nullptr)
		{
			_InitEntityCallbackHandle((void*)createEntity, (void*)destroyEntity, (void*)setVertexDataPackage, (void*)setVertexDataPackageSharedBuffer,
				(void*)createSubMesh, (void*)getAttachComponent, (void*)addMaterial, (void*)appendMaterial, (void*)subtractMaterial, (void*)setRenderState, (void*)setBoundingBox, (void*)removeAllSubMesh, (void*)isMeshInitialGPU,
				(void*)addSubMeshMaterial,(void*)updateSubMeshes);
		}
	}

	void GameEntity::CreateCollisionData()
	{
		if (!IsValid())
		{
			return;
		}

		m_pSMMeshCollisionData = new FSMMeshCollisionData;

		DataVertex* pDataVertex = GetDataVertexPackage();
		DataIndice* pDataIndex = GetIndexPackageByIndex(0);
		if (pDataIndex == nullptr || pDataVertex == nullptr)
		{
			return;
		}
		if (pDataIndex->m_nOperationType == PT_PointList ||
			pDataIndex->m_nOperationType == PT_LineList)
		{
			return;
		}

		if (pDataVertex->m_Pos != nullptr)
		{
			m_pSMMeshCollisionData->m_nPosCount = pDataVertex->m_nPosCount;
			m_pSMMeshCollisionData->m_nPosDim = pDataVertex->m_nPosDim;
			int32 nPosSize = m_pSMMeshCollisionData->m_nPosCount * m_pSMMeshCollisionData->m_nPosDim;

			bool compress = GameConvertor::HasCompressOptions(pDataVertex->m_nCompressType, VertexCompressOptions::SVC_Vertex);

			m_pSMMeshCollisionData->m_pPos = (Gamefloat*)FMemory::Malloc(nPosSize * sizeof(Gamefloat));
			if (compress)
			{
				for (Gameint i = 0; i < pDataVertex->m_nPosCount; i++)
				{
					for (Gameint j = 0; j < pDataVertex->m_nPosDim; j++)
					{
						float encodeVal = ((Gameushort*)pDataVertex->m_Pos)[i * pDataVertex->m_nPosDim + j];
						m_pSMMeshCollisionData->m_pPos[i * pDataVertex->m_nPosDim + j] = encodeVal * pDataVertex->m_fVertCompressConstant + pDataVertex->m_vMinVerticesValue[j];
					}
				}
			}
			else
			{
				FMemory::Memcpy(m_pSMMeshCollisionData->m_pPos, pDataVertex->m_Pos, nPosSize * sizeof(Gamefloat));
			}
		}

		if (pDataIndex != nullptr)
		{
			m_pSMMeshCollisionData->m_nIndexCount = pDataIndex->m_nIndexCount;
			if (pDataIndex->m_Index != nullptr)
			{
				m_pSMMeshCollisionData->m_pIndex = (Gameuint*)FMemory::Malloc(m_pSMMeshCollisionData->m_nIndexCount * sizeof(Gameuint));
				FMemory::Memcpy(m_pSMMeshCollisionData->m_pIndex, pDataIndex->m_Index, m_pSMMeshCollisionData->m_nIndexCount * sizeof(Gameuint));
			}
			else if (pDataIndex->m_shortIndex != nullptr)
			{
				m_pSMMeshCollisionData->m_pShortIndex = (Gameushort*)FMemory::Malloc(m_pSMMeshCollisionData->m_nIndexCount * sizeof(Gameushort));
				FMemory::Memcpy(m_pSMMeshCollisionData->m_pShortIndex, pDataIndex->m_shortIndex, m_pSMMeshCollisionData->m_nIndexCount * sizeof(Gameushort));
			}
		}
	}

	void GameEntity::AsyncUploadEntity()
	{
		STATS_SM_ASYNCUPLOADENTITY
		m_bAsyncLoading = false;
		auto result = Async<>(EAsyncExecution::ThreadPool, [& , this]() {
			Gamebool bOpenCrash = GameObjectManager::GetSingleton()->IsEnableCollision();
			if (bOpenCrash)
			{
				this->CreateCollisionData();
			}
			this->SetAsyncLoading(true);
		});
	}

	void GameEntity::AsyncUpdateEntity(DataVertex* pDataVertex, Gameint nOffset, UGVertexDataStateSet nState)
	{
		m_bUpdateGPU = false;
		auto result = Async<>(EAsyncExecution::ThreadPool, [&, this, pDataVertex, nOffset, nState]() {
			this->SetIsUpdateGPU(true);
		});
	}

	FSMMeshCollisionData* GameEntity::GetCollisionData()
	{
		return m_pSMMeshCollisionData;
	}

	void GameEntity::SetCollisionData(FSMMeshCollisionData* pCollisionData)
	{
		if (m_pSMMeshCollisionData != nullptr && pCollisionData == nullptr)
		{
			m_pSMMeshCollisionData->m_pIndex = nullptr;
			m_pSMMeshCollisionData->m_pPos = nullptr;
			m_pSMMeshCollisionData->m_pShortIndex = nullptr;
		}

		m_pSMMeshCollisionData = pCollisionData;
	}

	void GameEntity::SetAsyncLoading(Gamebool bAsyncLoading)
	{
		m_bAsyncLoading = bAsyncLoading;
	}

	Gamebool GameEntity::GetAsyncLoading()
	{
		return m_bAsyncLoading;
	}

	EntityType GameEntity::Type()
	{
		return ET_NORMAL;
	}

	Gamevoid GameEntity::SetAsyncUpdateMesh(DataVertex* pDataVertex, Gameint nOffset, UGVertexDataStateSet nState)
	{
		GameUpdateMesh* pMeshStuct = new GameUpdateMesh;

		pMeshStuct->m_pUpdateDataVertex = pDataVertex;
		pMeshStuct->m_nUpdateState      = nState;
		pMeshStuct->m_nUpdateOffset     = nOffset;

		m_arrUpdateMeshs.Add(pMeshStuct);
	}

	Gamebool GameEntity::IsNeedUpdate()
	{
		return (m_arrUpdateMeshs.Num() > 0);
	}

	TArray<GameUpdateMesh*>& GameEntity::GetUpdateMesh()
	{
		return m_arrUpdateMeshs;
	}

	void* CreateEntity()
	{
		STATS_SM_CREATEENTITY

		return GameEntityManager::GetSingleton()->CreateEntity();
	}

	void DestroyEntity(void* pMeshHandle)
	{
		STATS_SM_DESTROYENTITY

		GameEntityManager::GetSingleton()->Remove(pMeshHandle);
	}

	void SetVertexDataPackage(void* pMeshHandle, GameDataVertexPackage* pVertexDataPackage)
	{
		STATS_SM_SETVERTEXDATAPACKAGE

		if (pVertexDataPackage == nullptr)
		{
			return;
		}

		GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
		if (pGameEntity != nullptr)
		{
			DataVertex* pDataVertex = new DataVertex;
			GameConvertor::GameDataVertexPackageToDataVertex(pVertexDataPackage, pDataVertex);

			pGameEntity->SetDataVertexPackage(pDataVertex);
		}
	}

	void SetVertexDataPackageSharedBuffer(void* pMeshHandle, void* pGameVertexDataPackage, Gameint nOffset, UGVertexDataStateSet nState)
	{
		STATS_SM_SETVERTEXDATAPACKAGESHAREDBUFFER

		if (nState == VST_VertexColor || nState == VST_Vertex || nState == VST_CUSTOM0)
		{
			if (pGameVertexDataPackage == nullptr)
			{
				return;
			}

			GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
			if (pGameEntity != nullptr)
			{
				DataVertex* pDataVertex = new DataVertex;
				GameDataVertexPackage* pVP = (GameDataVertexPackage*)pGameVertexDataPackage;
				GameConvertor::GameDataVertexPackageToDataVertex(pVP, pDataVertex);
				
				//! \brief 如果是异步，就等待更新
				if (pGameEntity->IsCanAsync() && !pGameEntity->IsInitialGPU())
				{
					pGameEntity->SetAsyncUpdateMesh(pDataVertex, nOffset, nState);
				}
				else
				{
					pGameEntity->GetGameComponent()->UpdateMesh(pDataVertex, nOffset, nState);
				}
			}
		}

	}

	void CreateSubMesh(void* pMeshHandle, GameIndexPackage* pIndexPackage)
	{
		STATS_SM_CREATESUBMESH

		if (pIndexPackage == nullptr)
		{
			return;
		}

		GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
		if (pGameEntity != nullptr)
		{
			DataIndice* pDataIndex = new DataIndice;
			GameConvertor::GameIndexPackageToDataIndice(pIndexPackage, pDataIndex);

			pGameEntity->AddIndexPackage(pDataIndex);

			ComponentType eType = pGameEntity->GetGameComponent()->GetComponentType();
			Gamebool bCanAsync = (((eType == CustomMeshComponent || eType == CustomEdgeLineComponent || eType == CustomPolyLineComponent) ? true : false) && m_bEnableAsync);
			// 如果空间查询创建的RO对象不走异步
			FString strSceneName = pGameEntity->GetGameComponent()->GetSceneName();
			if (strSceneName.Find(TEXT("_SpatialQuery")) != -1)
			{
				bCanAsync = false;
			}
			
			pGameEntity->SetCanAsync(bCanAsync);
			if (bCanAsync)
			{
				if (pGameEntity->IsValid())
				{
					pGameEntity->AsyncUploadEntity();
					
					GameComponent* pGameComponent = pGameEntity->GetGameComponent();
					GameObjectManager::GetSingleton()->AddUnitialComponent(pGameComponent);
				
				}	
			}
			else
			{
				pGameEntity->GetGameComponent()->InitMesh();
			}
		}
	}

	void AddSubMeshMaterial(void* pMeshHandle, char* strMaterialName)
	{
		GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
		if (pGameEntity == nullptr)
		{
			return;
		}

		GameComponent* pGameComponent = pGameEntity->GetGameComponent();
		if (pGameComponent == nullptr)
		{
			return;
		}

		FString strMatName = UTF8_TO_TCHAR(strMaterialName);
		if (strMatName.IsEmpty())
		{
			return;
		}

		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *strMatName);
		if (pMaterialInterface == nullptr)
		{
			return;
		}

		GameMaterial* pGameMaterial = new GameMaterial();

		// 创建材质
		
		UMaterialInstanceDynamic* pMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		pMID->AddToRoot();
		pGameMaterial->SetMID(pMID);

		FSuperMapMaterialInterfaceCollection materialCollection;
		materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, pMID);

		pGameComponent->AddUESubMeshMaterial(pGameMaterial);
		if (pGameEntity->IsInitialGPU())
		{
			// 渲染节点初始化完成之后调用
			pGameComponent->GetSceneNode()->AddMaterialCollection(materialCollection);
		}
		
	}

	void UpdateSubMeshes(Gamevoid* pMeshHandle, Gamevoid** pIndexPackages, Gameint nCount)
	{
		GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
		if (pGameEntity == nullptr)
		{
			return;
		}

		GameComponent* pGameComponent = pGameEntity->GetGameComponent();
		if (pGameComponent == nullptr)
		{
			return;
		}

		if(nCount == 1)
		{
			pGameComponent->RemoveUESubMeshMaterial();
		}

		Gameint nIndexCount = pGameEntity->GetIndexPackageCount();
		pGameEntity->RemoveIndexPackage(0, nIndexCount);

		TArray<DataIndice*> arrIndices;
		for (Gameint i = 0; i < nCount; i++)
		{
			DataIndice* pDataIndex = new DataIndice;
			GameIndexPackage* pGameIndex = (GameIndexPackage*)pIndexPackages[i];
			if (pGameIndex == nullptr)
			{
				arrIndices.Add(nullptr);
				pGameEntity->AddIndexPackage(nullptr);
				continue;
			}

			GameConvertor::GameIndexPackageToDataIndice(pGameIndex, pDataIndex);

			if (!pGameEntity->IsInitialGPU())
			{
				pGameEntity->AddIndexPackage(pDataIndex);
			}
			else
			{
				pGameEntity->AddIndexPackage(nullptr);
			}

			arrIndices.Add(pDataIndex);
		}

		if (pGameEntity->IsInitialGPU())
		{
			pGameComponent->UpdateSubMeshes(arrIndices);
		}
		
	}

	void* GetAttachComponent(void* pMeshHandle)
	{
		STATS_SM_GETATTACHCOMPONENT

		GameEntityBase* pGameEntity = (GameEntityBase*)pMeshHandle;
		if (pGameEntity != nullptr)
		{
			return pGameEntity->GetGameComponent();
		}

		return nullptr;
	}

	Gamebool AddMaterial(void* pMeshHandle, void* pMaterialHandle)
	{
		STATS_SM_ADDMATERIAL

		GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
		if (pGameEntity == nullptr)
		{
			return false;
		}

		GameComponent* pGameComponent = pGameEntity->GetGameComponent();
		FString strSceneName = pGameComponent->GetSceneName();
		Gamebool bCanAsync = true;
		if (strSceneName.Find(TEXT("_SpatialQuery")) != -1)
		{
			bCanAsync = false;
		}

		// materialHandle为0表示没有shader,因为没有shader，所以材质没被创建，这些不是上层支持的可渲染对象
		if (pMaterialHandle == nullptr)
		{
			pGameComponent->SetSupport(false);
			return false;
		}

		GameMaterial* pGameMaterial = (GameMaterial*)pMaterialHandle;

		// 是否是编辑模式
		Gamebool bEditorMode = GameEntityManager::GetSingleton()->GetWorld()->WorldType == EWorldType::Editor ? true : false;

		// 如果是在异步的情况下，MID会先不创建
		if (bCanAsync && !bEditorMode && SuperMapSDK::m_bEnableAsync && pGameMaterial != nullptr)
		{
			if (pGameMaterial->GetMaterialParam()->m_strShaderName == nullptr)
			{
				pGameComponent->SetSupport(false);
			}
			else
			{
				pGameComponent->AddGameMaterialForAsync(pGameMaterial);
			}
			
		}
		else
		{
			if (pGameMaterial != nullptr)
			{
				pGameMaterial->InitMaterial();
			}

			if (pGameMaterial == nullptr || pGameMaterial->GetMID() == nullptr)
			{
				if (pGameComponent->GetSceneManagerType() != REAL_TIME_ELEVATION_S3M)
				{
					pGameComponent->SetSupport(false);
				}
			}
			else
			{
				pGameComponent->AddGameMaterial(pGameMaterial);
				// 放在这里是因为此时GameComponent才创建好材质，图层会用到材质
				SuperMapSDK::UnrealEngine::Core::Scene* pScene = (SuperMapSDK::UnrealEngine::Core::Scene*)GameObjectManager::GetSingleton()->GetScene();
				pScene->AddNativeGameComponent(pGameComponent);
			}
		}
		return true;
	}

	Gamebool AppendMaterial(void* pMeshHandle, void* pMaterialHandle)
	{
		STATS_SM_ADDMATERIAL

		GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
		GameMaterial* pGameMaterial = (GameMaterial*)pMaterialHandle;
		if (pGameEntity == nullptr || pGameMaterial == nullptr)
		{
			return false;
		}

		GameComponent* pGameComponent = pGameEntity->GetGameComponent();

		pGameComponent->AddGameMaterial(pGameMaterial);

		USuperMap_MeshComponentInterface* pSceneNode = pGameComponent->GetSceneNode();

		pGameMaterial->InitMaterial();

		FSuperMapMaterialInterfaceCollection materialCollection;
		materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, pGameMaterial->GetMID());
		//materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, pGameMaterial->GetViewportMID());
		pSceneNode->AddMaterialCollection(materialCollection);

		pSceneNode->AddMaterialInterface(pGameMaterial->GetMID());

		return true;
	}

	Gamebool SubtractMaterial(void* pMeshHandle, void* pMaterialHandle)
	{
		STATS_SM_ADDMATERIAL

		GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
		GameMaterial* pGameMaterial = (GameMaterial*)pMaterialHandle;
		if (pGameEntity == nullptr || pGameMaterial == nullptr)
		{
			return false;
		}

		GameComponent* pGameComponent = pGameEntity->GetGameComponent();
	
		pGameComponent->RemoveGameMaterial(pGameMaterial);


		USuperMap_MeshComponentInterface* pSceneNode = pGameComponent->GetSceneNode();

		FSuperMapMaterialInterfaceCollection materialCollection;
		materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, pGameMaterial->GetMID());
		//materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, pGameMaterial->GetViewportMID());

		pSceneNode->RemoveLastMaterialCollection(materialCollection);


		pSceneNode->RemoveMaterialInterface(pGameMaterial->GetMID());

		return true;
	}

	Gamelong SetRenderState(void* pMeshHandle, UGRenderStateSet nRenderState)
	{
		STATS_SM_SETRENDERSTATE

		return 0;
	}

	void SetBoundingBox(void* pMeshHandle, void* pBoundBox)
	{
		STATS_SM_SETBOUNDINGBOX

		// TO DO
		GameEntity* pGameEntity = (GameEntity*)pMeshHandle;
		if (pGameEntity != nullptr)
		{
			GameBoundingBox* pGameBoundBox = (GameBoundingBox*)pBoundBox;

			GameBoundingBox boundBox = *pGameBoundBox;

			Swap(boundBox.m_vMin.x, boundBox.m_vMin.y);
			Swap(boundBox.m_vMax.x, boundBox.m_vMax.y);

			boundBox.m_vMin.x *= M_TO_CM;
			boundBox.m_vMin.y *= M_TO_CM;
			boundBox.m_vMin.z *= M_TO_CM;

			boundBox.m_vMax.x *= M_TO_CM;
			boundBox.m_vMax.y *= M_TO_CM;
			boundBox.m_vMax.z *= M_TO_CM;

			pGameEntity->SetBBox(boundBox);

		}
	}

	void RemoveAllSubMesh(void* pEntityHandle, Gamebool bReleaseMaterial)
	{
		STATS_SM_REMOVEALLMESH
		// TO DO
	}

	Gamebool IsMeshInitialGPU(void* pEntityHandle)
	{
		STATS_SM_ISMESHINITIALGPU

		return GameEntityManager::GetSingleton()->IsMeshInitialGPU(pEntityHandle);
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif