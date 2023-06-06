#include "Graphics3D/GameComponent.h"
#include "Graphics3D/GameConvertor.h"
#include "Graphics3D/GameObjectManager.h"
#include "Algorithm3D/MathEngine.h"
#include "Graphics3D/GameTextureManager.h"
#include "Component/SuperMap_MeshComponentInterface.h"
#include "Graphics3D/GameInstanceEntity.h"
#include "Core/Scene.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Base3D/StatsGroupDefine.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
namespace SuperMapSDK
{
	GameComponent::GameComponent(Gamelong nName, Gamelong nParentName, Gameint nSceneManagerType)
	{
		m_nNodeName = nName;
		m_nParentNodeName = nParentName;
		m_enSceneManagerType = MathEngine::ConvertToSceneManagerType(nSceneManagerType);
		m_pGameEntity = nullptr;
		m_pSceneNode = nullptr;
		m_bSupport = true;
		m_enDataType = DataType::ModelCache;
		m_pSelectionMaterial = nullptr;
		m_pRectSelectMaterial = nullptr;
		m_pCurrentListNode = nullptr;
	}

	GameComponent::~GameComponent()
	{
		m_pGameEntity = nullptr;

		if (m_pSceneNode != nullptr)
		{
			m_pSceneNode->ReleaseMeshComponent();
			if (m_pSceneNode->IsRegistered())
			{
				m_pSceneNode->UnregisterComponent();
			}

			m_pSceneNode->DestroyPhysicsState();
			m_pSceneNode->DestroyComponent();
			m_pSceneNode->ConditionalBeginDestroy();
		}

		m_pCurrentListNode = nullptr;
		for (Gameint i = 0; i < m_vecUESubMeshMaterial.Num(); i++)
		{
			delete m_vecUESubMeshMaterial[i];
			m_vecUESubMeshMaterial[i] = nullptr;
		}
		m_vecUESubMeshMaterial.Empty();
		m_vecGameMaterial.Empty();
		m_pSelectionMaterial = nullptr;
		m_pRectSelectMaterial = nullptr;
	}

	void GameComponent::InitializeCallbackHandle()
	{
		CreateSceneNodeFunction		createSceneNode = CreateSceneNode;
		DestroySceneNodeFunction	destroySceneNode = DestroySceneNode;
		SetObjectMatrixFunction		setObjectMatrix = SetUGCObjectMatrix;
		SetVisibleFunction			setVisible = SetVisible;
		SetSceneNodeVisibleFunction setSceneNodeVisible = SetNodeVisible;
		AttachEntityFunction		attachEntity = AttachEntity;
		GetGameObjectFunction		getGameObject = GetGameObject;
		GetOrCreateRootSceneNodeFunction getOrCreateRootSceneNode = GetOrCreateRootSceneNode;
		DestroyRootSceneNodeFunction destroyRootSceneNode = DestroyRootSceneNode;
		CreateChildSceneNodeFunction createChildSceneNode = CreateChildSceneNode;

		if (_InitSceneNodeCallbackHandle != nullptr)
		{
			_InitSceneNodeCallbackHandle((Gamevoid*)createSceneNode, (Gamevoid*)destroySceneNode, (Gamevoid*)setVisible, (Gamevoid*)setSceneNodeVisible,
				(Gamevoid*)setObjectMatrix, (Gamevoid*)attachEntity, (Gamevoid*)getGameObject, (Gamevoid*)getOrCreateRootSceneNode, (void*)destroyRootSceneNode,
				(Gamevoid*)createChildSceneNode);
		}
	}

	ComponentType GameComponent::MakeComponentType()
	{
		if (!m_bSupport)
		{
			return CustomNone;
		}

		UWorld* pWorld = GameObjectManager::GetSingleton()->GetWorld();
		ComponentType eComponentType = CustomMeshComponent;
		if (pWorld->WorldType == EWorldType::Editor)
		{
			eComponentType = CustomStaticMeshComponent;
		}

		// TODO 目前只支持这个场景类型的作为实时栅格化对象
		if (m_enSceneManagerType == REAL_TIME_ELEVATION_S3M || m_enSceneManagerType == REAL_TIME_RASTER)
		{
			eComponentType = CustomRealTimeRaster;
		}
		
		if (m_vecGameMaterial.Num() > 0)
		{
			GameMaterial*  pGameMaterial = m_vecGameMaterial[0];
			if (pGameMaterial != nullptr)
			{
				FString strShaderName = UTF8_TO_TCHAR(pGameMaterial->GetMaterialParam()->m_strShaderName);
				if (strShaderName.Compare("Custom/Billboard") == 0)
				{
					eComponentType = CustomBillboardComponent;
				}
				else if (strShaderName.Compare("Custom/ModelEdge") == 0)
				{
					eComponentType = CustomEdgeLineComponent;
				}
				else if (strShaderName.Compare("Custom/PolylineCache") == 0)
				{
					eComponentType = CustomPolyLineComponent;
				}
			}
		}
		return eComponentType;
	}

	void GameComponent::InitBillboardMesh()
	{
		if (m_vecGameMaterial.Num() > 0)
		{
			GameMaterial*      pGameMaterial = m_vecGameMaterial[0];
			GameMaterialParam* pGameMaterialParam = pGameMaterial->GetMaterialParam();
			if (pGameMaterialParam != nullptr && pGameMaterialParam->m_nTextureCount > 0)
			{
				Gamelong nTextureHandle = pGameMaterialParam->m_pTextureNames[0];
				UTexture2D* pTexture2D = GameTextureManager::GetSingleton()->GetTexture(nTextureHandle)->GetTexture2D();

				if (pTexture2D != nullptr)
				{
					FSMMesh smMesh;
					smMesh.m_pDataVertex = m_pGameEntity->GetDataVertexPackage();
					if (m_pGameEntity->GetIndexPackageCount() > 0)
					{
						smMesh.m_arrDataIndex.Add(m_pGameEntity->GetIndexPackageByIndex(0));
					}

					Gameint nTextureWidth  = pTexture2D->GetSizeX();
					Gameint nTextureHeight = pTexture2D->GetSizeY();
					Matrix4d matTex = Matrix4d(pGameMaterialParam->m_pTexTransforms[0]);
					m_pSceneNode->SetBillboardParam(nTextureWidth, nTextureHeight, matTex);

					FSuperMapMaterialInterfaceCollection materialCollection;
					materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, pGameMaterial->GetMID());
					materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, pGameMaterial->GetViewportMID());
					m_pSceneNode->AddMaterialCollection(materialCollection);
					m_pSceneNode->CreateMesh(smMesh, false);
					m_pSceneNode->SetTexture(pTexture2D);
				}

			}
		}
	}

	void GameComponent::UpdateMesh(DataVertex* pDataVertex, Gameint nOffset, UGVertexDataStateSet nState)
	{
		if (nState == VST_VertexColor || nState == VST_Vertex || nState == VST_CUSTOM0)
		{
			FSMMesh smMesh;
			smMesh.m_pDataVertex = pDataVertex;
			smMesh.m_nSubMeshInfoOffset = nOffset;
			m_pSceneNode->UpdateMesh(smMesh, nState);
		}
	}

	void GameComponent::AsyncMesh()
	{
		if (!m_bSupport)
		{
			return;
		}

		ComponentType eComponentType = MakeComponentType();
		m_pSceneNode->CreateMeshComponent(eComponentType, m_pSceneNode->GetOwner());

		if (m_vecGameMaterial.Num() > 0)
		{
			for (int i = 0; i < m_vecGameMaterial.Num(); i++)
			{
				FSuperMapMaterialInterfaceCollection materialCollection;
				materialCollection.SetMacros(m_vecGameMaterial[i]->GetMaterialParam());

				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, m_vecGameMaterial[i]->GetMID());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION, m_vecGameMaterial[i]->GetSelectionMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION, m_vecGameMaterial[i]->GetRectSelectMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, m_vecGameMaterial[i]->GetViewportMID());
				m_pSceneNode->AddMaterialCollection(materialCollection);
			}

			for (int i = 0; i < m_vecUESubMeshMaterial.Num(); i++)
			{
				FSuperMapMaterialInterfaceCollection materialCollection;
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, m_vecUESubMeshMaterial[i]->GetMID());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION, m_vecUESubMeshMaterial[i]->GetSelectionMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION, m_vecUESubMeshMaterial[i]->GetRectSelectMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, m_vecUESubMeshMaterial[i]->GetViewportMID());
				m_pSceneNode->AddMaterialCollection(materialCollection);
			}

			m_pSceneNode->SetLayerName(m_strLayerName);
			FString materialName = UTF8_TO_TCHAR(m_vecGameMaterial[0]->GetMaterialParam()->m_strMaterialName);
			m_pSceneNode->SetRealMaterialName(materialName);
		}

		Gamebool bOpenCrash = GameObjectManager::GetSingleton()->IsEnableCollision();
		if (bOpenCrash)
		{
			bOpenCrash = IsOpenCrash();
		}

		GameEntity* pGameEntity = (GameEntity*)m_pGameEntity;

		if (pGameEntity->IsNeedUpdate())
		{
			TArray<GameUpdateMesh*> & arrUpdates = pGameEntity->GetUpdateMesh();
			DataVertex* pDataVertexPackage = pGameEntity->GetDataVertexPackage();
			Gameint nCount = arrUpdates.Num();
			for (Gameint i = 0; i < nCount; i++)
			{
				GameUpdateMesh* pGameUpdate = arrUpdates[i];
				if (pGameUpdate->m_pUpdateDataVertex != nullptr&& pGameUpdate->m_pUpdateDataVertex->m_PosColor != nullptr && pDataVertexPackage != nullptr && pDataVertexPackage->m_PosColor != nullptr)
				{
					// 替换颜色
					FMemory::Memcpy(pDataVertexPackage->m_PosColor + pGameUpdate->m_nUpdateOffset,
						pGameUpdate->m_pUpdateDataVertex->m_PosColor, sizeof(Gameuint) * pGameUpdate->m_pUpdateDataVertex->m_nColorCount);
				}
				if (pGameUpdate->m_pUpdateDataVertex != nullptr && pGameUpdate->m_pUpdateDataVertex->m_Pos != nullptr &&
					pDataVertexPackage != nullptr && pDataVertexPackage->m_Pos != nullptr)
				{
					// 替换顶点
					FMemory::Memcpy(pDataVertexPackage->m_Pos + pGameUpdate->m_nUpdateOffset,
						pGameUpdate->m_pUpdateDataVertex->m_Pos, sizeof(Gameuint) * pGameUpdate->m_pUpdateDataVertex->m_nPosCount * pGameUpdate->m_pUpdateDataVertex->m_nPosDim);
				}

				if (pGameUpdate->m_pUpdateDataVertex != nullptr && pDataVertexPackage != nullptr && pGameUpdate->m_pUpdateDataVertex->m_nVertexAttCount > 0)
				{
					if (pDataVertexPackage->m_nVertexAttCount > 0)
					{
						for (Gameint n = 0; n < pDataVertexPackage->m_vecVertexAttribute.Num(); n++)
						{
							pDataVertexPackage->m_vecVertexAttribute[n].Release(false);
						}
						pDataVertexPackage->m_vecVertexAttribute.Empty();
					}

					Gameint nVertexAttCount = pGameUpdate->m_pUpdateDataVertex->m_vecVertexAttribute.Num();
					pDataVertexPackage->m_bHasVertexWeight = pGameUpdate->m_pUpdateDataVertex->m_bHasVertexWeight;
					pDataVertexPackage->m_nVertexAttCount = pGameUpdate->m_pUpdateDataVertex->m_nVertexAttCount;
					for (Gameint n = 0; n < nVertexAttCount; n++)
					{

						pDataVertexPackage->m_vecVertexAttribute.Add(pGameUpdate->m_pUpdateDataVertex->m_vecVertexAttribute[n]);
					}

					pGameUpdate->m_pUpdateDataVertex->m_vecVertexAttribute.Empty();
				}
				delete pGameUpdate->m_pUpdateDataVertex;
				delete pGameUpdate;
			}
			
			arrUpdates.Empty();
		}

		m_pSceneNode->CreateMesh(pGameEntity, bOpenCrash);

		m_pGameEntity->SetIsInitialGPU(true);
	}

	void GameComponent::RemoveUESubMeshMaterial()
	{
		Gameint nSize = m_vecUESubMeshMaterial.Num();
		for (Gameint i = nSize-1; i >= 0; i--)
		{
			GameMaterial* pGameMaterial = m_vecUESubMeshMaterial[i];
			if (pGameMaterial)
			{
				if (m_pSceneNode)
				{
					FSuperMapMaterialInterfaceCollection materialCollection;
					materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, pGameMaterial->GetMID());
					materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION, pGameMaterial->GetSelectionMaterial());
					materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION, pGameMaterial->GetRectSelectMaterial());
					materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, pGameMaterial->GetViewportMID());

					m_pSceneNode->RemoveLastMaterialCollection(materialCollection);
				}

				delete pGameMaterial;
				pGameMaterial = nullptr;
			}
		}

		m_vecUESubMeshMaterial.RemoveAt(0, nSize);
	}

	void GameComponent::InitMesh()
	{
		if (!m_bSupport || !m_pGameEntity->IsValid())
		{
			return;
		}

		ComponentType eComponentType = MakeComponentType();
		
		m_pSceneNode->CreateMeshComponent(eComponentType, m_pSceneNode->GetOwner());

		if (eComponentType == CustomBillboardComponent)
		{
			// 初始化billboard组件
			InitBillboardMesh();
			return;
		}

		FSMMesh smMesh;
		smMesh.m_pDataVertex = m_pGameEntity->GetDataVertexPackage();
		smMesh.m_GameBoundingBox = m_pGameEntity->GetBBox();
		smMesh.m_arrDataIndex.SetNum(m_pGameEntity->GetIndexPackageCount());
		for (int i = 0; i < m_pGameEntity->GetIndexPackageCount(); i++)
		{
			smMesh.m_arrDataIndex[i] = m_pGameEntity->GetIndexPackageByIndex(i);
		}

		// 当实体对象填完显卡时会自动释放（仅限组件为CustomMeshComponent）
		if (eComponentType == CustomMeshComponent || eComponentType == CustomEdgeLineComponent || eComponentType == CustomPolyLineComponent)
		{
			m_pGameEntity->SetDataVertexPackage(nullptr);
			for (int i = 0; i < m_pGameEntity->GetIndexPackageCount(); i++)
			{
				m_pGameEntity->SetIndexPackageByIndex(i, nullptr);
			}
		}

		if (m_vecGameMaterial.Num() > 0)
		{
			for (int i = 0; i < m_vecGameMaterial.Num(); i++)
			{
				FSuperMapMaterialInterfaceCollection materialCollection;
				materialCollection.SetMacros(m_vecGameMaterial[i]->GetMaterialParam());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, m_vecGameMaterial[i]->GetMID());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION, m_vecGameMaterial[i]->GetSelectionMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION, m_vecGameMaterial[i]->GetRectSelectMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, m_vecGameMaterial[i]->GetViewportMID());
				m_pSceneNode->AddMaterialCollection(materialCollection);
			}

			for (int i = 0; i < m_vecUESubMeshMaterial.Num(); i++)
			{
				FSuperMapMaterialInterfaceCollection materialCollection;
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, m_vecUESubMeshMaterial[i]->GetMID());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION, m_vecUESubMeshMaterial[i]->GetSelectionMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION, m_vecUESubMeshMaterial[i]->GetRectSelectMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, m_vecUESubMeshMaterial[i]->GetViewportMID());
				m_pSceneNode->AddMaterialCollection(materialCollection);
			}

			m_pSceneNode->SetLayerName(m_strLayerName);
			FString materialName = UTF8_TO_TCHAR(m_vecGameMaterial[0]->GetMaterialParam()->m_strMaterialName);
			m_pSceneNode->SetRealMaterialName(materialName);
		}

		Gamebool bOpenCrash = GameObjectManager::GetSingleton()->IsEnableCollision();
		if (bOpenCrash)
		{
			bOpenCrash = IsOpenCrash();
		}
		
		m_pSceneNode->CreateMesh(smMesh, bOpenCrash);
		m_pGameEntity->SetIsInitialGPU(true);
	}

	void GameComponent::InitInstanceMesh(Gameint nInstanceSize, Gameint nSizeInFloatPerInstance, void* pValue)
	{
		if (!m_bSupport)
		{
			return;
		}

		GameInstanceEntity* pInstanceEntity = (GameInstanceEntity*)m_pGameEntity;
		UStaticMesh* pStaticMesh = pInstanceEntity->GetStaticMesh();
		ComponentType eComponentType;
		// 非外挂实例化
		if (pStaticMesh == nullptr)
		{
			eComponentType = CustomMeshComponent;
		}
		else
		{
			eComponentType = CustomInstancedStaticMeshComponent;
		}
		
		m_pSceneNode->CreateMeshComponent(eComponentType, m_pSceneNode->GetOwner());

		if (eComponentType == CustomInstancedStaticMeshComponent)
		{
			FString strMeshName = pInstanceEntity->GetEntityMeshName();
			m_pSceneNode->SetCustomStaticMesh(strMeshName, pStaticMesh);
		}

		if (m_vecGameMaterial.Num() > 0)
		{
			for (int i = 0; i < m_vecGameMaterial.Num(); i++)
			{
				FSuperMapMaterialInterfaceCollection materialCollection;
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, m_vecGameMaterial[i]->GetMID());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION, m_vecGameMaterial[i]->GetSelectionMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION, m_vecGameMaterial[i]->GetRectSelectMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, m_vecGameMaterial[i]->GetViewportMID());
				m_pSceneNode->AddMaterialCollection(materialCollection);
			}

			m_pSceneNode->SetLayerName(m_strLayerName);
			FString materialName = UTF8_TO_TCHAR(m_vecGameMaterial[0]->GetMaterialParam()->m_strMaterialName);
			m_pSceneNode->SetRealMaterialName(materialName);
		}

		FSMMesh smMesh;
		smMesh.m_GameBoundingBox = m_pGameEntity->GetBBox();
		smMesh.m_pDataVertex = m_pGameEntity->GetDataVertexPackage();
		smMesh.m_arrDataIndex.SetNum(m_pGameEntity->GetIndexPackageCount());
		for (int i = 0; i < m_pGameEntity->GetIndexPackageCount(); i++)
		{
			smMesh.m_arrDataIndex[i] = m_pGameEntity->GetIndexPackageByIndex(i);
		}
		
		// 复制一下底层的实例化数据内存，因为底层的内存存在对齐问题，直接传显卡会出错
		smMesh.m_nIntanceSize = nInstanceSize;
		smMesh.m_nSizeInFloatPerInstance = nSizeInFloatPerInstance;
		smMesh.m_pInstanceBuffer = FMemory::Malloc(sizeof(Gamefloat) * nInstanceSize * nSizeInFloatPerInstance);
		FMemory::Memcpy(smMesh.m_pInstanceBuffer, pValue, sizeof(Gamefloat) * nInstanceSize * nSizeInFloatPerInstance);

		m_pSceneNode->CreateMesh(smMesh, false);

		// 当实体对象填完显卡时会自动释放（仅限组件为CustomMeshComponent）
		if (eComponentType == CustomMeshComponent)
		{
			m_pGameEntity->SetDataVertexPackage(nullptr);
			for (int i = 0; i < m_pGameEntity->GetIndexPackageCount(); i++)
			{
				m_pGameEntity->SetIndexPackageByIndex(i, nullptr);
			}
		}

		m_pGameEntity->SetIsInitialGPU(true);

		if (pInstanceEntity->m_pValue != nullptr)
		{
			FMemory::Free(pInstanceEntity->m_pValue);
			pInstanceEntity->m_pValue = nullptr;
			pInstanceEntity->m_nInstanceSize = 0;
			pInstanceEntity->m_nSizeInFloatPerInstance = 0;
		}
	}

	void GameComponent::UpdateInstanceVertexColor(Gameuint nColor, TArray<uint32>& arrIds)
	{
		m_pSceneNode->UpdateInstanceVertexColor(nColor, arrIds);
	}

	void GameComponent::SetObjectMatrix(Gamedouble* pDoubleObjectMat)
	{
		if (pDoubleObjectMat == nullptr)
		{
			return;
		}
		m_matUGCLocalToECEF = Matrix4d(pDoubleObjectMat);
		m_localToECEF = MathEngine::UGCMatrixPtrToUEMatrix4d(pDoubleObjectMat);
		
		if (m_pSceneNode != nullptr)
		{
			m_pSceneNode->SetLocalToECEF(m_localToECEF);

			FTransform trans;
			Georeference::TransformECEFToUERelative(m_localToECEF, trans);
			m_pSceneNode->SetWorldTransform(trans);
		}
	}

	Matrix4d GameComponent::GetObjectUGCMatrix()
	{
		return m_matUGCLocalToECEF;
	}

	void GameComponent::SetObjectVisible(Gamebool bVisible)
	{
		SetVisibleForAllChildren(bVisible, false, m_pSceneNode);
	}

	void GameComponent::SetVisibleForAllChildren(Gamebool bVisible, Gamebool bSetByParent, USuperMap_MeshComponentInterface* pSceneNode)
	{
		TArray<USceneComponent*> arrChilds = pSceneNode->GetAttachSceneComponentChildren();
		int nChildCount = arrChilds.Num();
		if (bSetByParent && nChildCount > 0)
		{
			for (int i = 0; i < nChildCount; i++)
			{
				USceneComponent* pSceneComponent = arrChilds[i];
				if (pSceneComponent == nullptr)
				{
					continue;
				}
				USuperMap_MeshComponentInterface* pMeshComponentInterface = (USuperMap_MeshComponentInterface*)pSceneComponent;
				if (pMeshComponentInterface != nullptr)
				{
					pMeshComponentInterface->SetInternalVisibility(bVisible);
				}
			}
			return;
		}

		if (bSetByParent)
		{
			UWorld* pWorld = GameObjectManager::GetSingleton()->GetWorld();
			if (pWorld->WorldType == EWorldType::Editor)
			{
				return;
			}
			pSceneNode->SetLayerVisibility(bVisible);
		}
		else
		{
			if (pSceneNode->GetInternalVisibility() == bVisible)
			{
				return;
			}
			pSceneNode->SetInternalVisibility(bVisible);
		}
		for (int i = 0; i < nChildCount; i++)
		{
			USceneComponent* pSceneComponent = arrChilds[i];
			if (pSceneComponent == nullptr)
			{
				continue;
			}
			USuperMap_MeshComponentInterface* pMeshComponentInterface = (USuperMap_MeshComponentInterface*)pSceneComponent;
			if (pMeshComponentInterface != nullptr)
			{
				SetVisibleForAllChildren(bVisible, true, pMeshComponentInterface);
			}
		}
	}


	void GameComponent::SetSceneNodeVisible(Gamebool bVisible)
	{
		if (m_pSceneNode->GetLayerVisibility() == bVisible)
		{
			return;
		}
		m_pSceneNode->SetLayerVisibility(bVisible);



		// 遍历所有节点
		TArray<USceneComponent*> arrChilds = m_pSceneNode->GetAttachSceneComponentChildren();
		int nChildCount = arrChilds.Num();
		for (int i = 0; i < nChildCount; i++)
		{
			USceneComponent* pSceneComponent = arrChilds[i];
			if (pSceneComponent == nullptr)
			{
				continue;
			}
			USuperMap_MeshComponentInterface* pMeshComponentInterface = (USuperMap_MeshComponentInterface*)pSceneComponent;
			if (pMeshComponentInterface != nullptr)
			{
				SetVisibleForAllChildren(bVisible, true, pMeshComponentInterface);
			}
		}
	}

	void GameComponent::SetEntity(GameEntityBase* pGameEntity)
	{
		m_pGameEntity = pGameEntity;
		pGameEntity->SetGameComponent(this);
		pGameEntity->SetSceneNodeName(m_nNodeName);
	}

	Gamelong GameComponent::GetNodeName()
	{
		return m_nNodeName;
	}

	void GameComponent::UpdateWorldOrigin(Vector3d vOrigin)
	{
		m_pSceneNode->UpdateTransfrom(vOrigin);
	}

	void GameComponent::AddUESubMeshMaterial(GameMaterial* pGameMaterial)
	{
		m_vecUESubMeshMaterial.Add(pGameMaterial);
	}

	void GameComponent::UpdateSubMeshes(TArray<DataIndice*>& arrIndices)
	{
		if (m_pSceneNode)
		{
			TArray<FSuperMapMaterialInterfaceCollection> arrMaterialCollection;
			for (Gameint i = 0; i < m_vecGameMaterial.Num(); i++)
			{
				FSuperMapMaterialInterfaceCollection materialCollection;
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, m_vecGameMaterial[i]->GetMID());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION, m_vecGameMaterial[i]->GetSelectionMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION, m_vecGameMaterial[i]->GetRectSelectMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, m_vecGameMaterial[i]->GetViewportMID());
				arrMaterialCollection.Add(materialCollection);
			}

			for (Gameint i = 0; i < m_vecUESubMeshMaterial.Num(); i++)
			{
				FSuperMapMaterialInterfaceCollection materialCollection;
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL, m_vecUESubMeshMaterial[i]->GetMID());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION, m_vecUESubMeshMaterial[i]->GetSelectionMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION, m_vecUESubMeshMaterial[i]->GetRectSelectMaterial());
				materialCollection.SetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT, m_vecUESubMeshMaterial[i]->GetViewportMID());
				arrMaterialCollection.Add(materialCollection);
			}
			

			m_pSceneNode->UpdateSubMeshes(arrIndices, arrMaterialCollection);
		}
	}

	GameEntityBase* GameComponent::GetEntity()
	{
		return m_pGameEntity;
	}

	void GameComponent::SetSceneNode(USuperMap_MeshComponentInterface* pSceneNode)
	{
		m_pSceneNode = pSceneNode;
	}

	USuperMap_MeshComponentInterface* GameComponent::GetSceneNode()
	{
		return m_pSceneNode;
	}

	void GameComponent::SetSupport(Gamebool bValue)
	{
		m_bSupport = bValue;
	}

	Gamebool GameComponent::IsSupport()
	{
		return m_bSupport;
	}

	void GameComponent::AddGameMaterialForAsync(GameMaterial* pGameMaterial)
	{
		m_vecGameMaterial.Add(pGameMaterial);
	}

	void GameComponent::UpdateMaterialForAsync(GameMaterial* pGameMaterial)
	{
		if (pGameMaterial->GetMID() == nullptr)
		{
			m_bSupport = false;
		}

		m_pSelectionMaterial = pGameMaterial->GetSelectionMaterial();
		m_pRectSelectMaterial = pGameMaterial->GetRectSelectMaterial();
		m_enDataType = pGameMaterial->GetDataType();
	}

	void GameComponent::AddGameMaterial(GameMaterial* pGameMaterial)
	{
		m_vecGameMaterial.Add(pGameMaterial);
		m_pSelectionMaterial = pGameMaterial->GetSelectionMaterial();
		m_pRectSelectMaterial = pGameMaterial->GetRectSelectMaterial();
		m_enDataType = pGameMaterial->GetDataType();
	}

	void GameComponent::RemoveGameMaterial(GameMaterial* pGameMaterial)
	{
		m_vecGameMaterial.Remove(pGameMaterial);
	}

	TArray<GameMaterial*>& GameComponent::GetAllGameMaterial()
	{
		return m_vecGameMaterial;
	}

	Gamelong GameComponent::GetParentNodeName()
	{
		return m_nParentNodeName;
	}

	SceneManagerType GameComponent::GetSceneManagerType()
	{
		return m_enSceneManagerType;
	}

	DataType GameComponent::GetDataType()
	{
		return m_enDataType;
	}

	void GameComponent::SetLayerName(FString strLayerName)
	{
		m_strLayerName = strLayerName;
	}

	FString GameComponent::GetLayerName()
	{
		return m_strLayerName;
	}

	void GameComponent::SetSceneName(FString strSceneName)
	{
		m_strSceneName = strSceneName;
	}

	FString GameComponent::GetSceneName()
	{
		return m_strSceneName;
	}

	UMaterialInstanceDynamic* GameComponent::GetRectSelectMaterial()
	{
		return m_pRectSelectMaterial;
	}

	ComponentType GameComponent::GetComponentType()
	{
		return MakeComponentType();
	}

	void GameComponent::SetListNode(GameObjectListNode* pNode)
	{
		m_pCurrentListNode = pNode;
	}

	GameObjectListNode* GameComponent::GetListNode()
	{
		return m_pCurrentListNode;
	}

	Gamebool GameComponent::IsOpenCrash()
	{
		if (m_vecGameMaterial.Num() > 0)
		{
			GameMaterial*  pGameMaterial = m_vecGameMaterial[0];
			if (pGameMaterial != nullptr)
			{
				UMaterialInstanceDynamic* pMID = pGameMaterial->GetMID();
				SuperMapSDK::UnrealEngine::Core::Scene* pScene = (SuperMapSDK::UnrealEngine::Core::Scene*)GameObjectManager::GetSingleton()->GetScene();

				if (pMID == nullptr)
				{
					return false;
				}
				if (pMID->GetBaseMaterial() == nullptr)
				{
					return false;
				}
				if ((pMID->GetBaseMaterial()->GetName() == TEXT("SM_Terrain") ||
					pMID->GetBaseMaterial()->GetName() == TEXT("Global")) &&
					(pScene->GetSceneType() == SceneType::Globe ||
					 pScene->GetSceneType() == SceneType::Ellipsoid_WGS84))
				{
					return false;
				}
			}
		}
		return true;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void* CreateSceneNode()
	{
		return nullptr;
	}

	void DestroySceneNode(void* pSceneNodeHandle)
	{
		STATS_SM_DESTROYSCENENODE

		GameObjectManager::GetSingleton()->DestroySceneNode(pSceneNodeHandle);
	}

	void SetUGCObjectMatrix(void* pSceneNodeHandle, Gamedouble* pMatrix)
	{
		STATS_SM_SETUGCOBJECTMATRIX

		GameObjectManager::GetSingleton()->SetObjectMatrix(pSceneNodeHandle, pMatrix);
	}

	void SetVisible(void* pSceneNodeHandle, Gamebool bVisible)
	{
		STATS_SM_SETVISIBLE

		GameObjectManager::GetSingleton()->SetVisible(pSceneNodeHandle, bVisible);
	}


	void SetNodeVisible(void* pSceneNodeHandle, Gamebool bVisible)
	{
		STATS_SM_SETVISIBLE

		GameObjectManager::GetSingleton()->SetSceneNodeVisible(pSceneNodeHandle, bVisible);
	}

	Gamebool AttachEntity(void* pSceneNodeHandle, void* pMeshHandle)
	{
		STATS_SM_ATTACHENTITY

		return GameObjectManager::GetSingleton()->AttachEntity(pSceneNodeHandle, pMeshHandle);
	}

	void* GetGameObject(Gamelong nSceneNodeName)
	{
		STATS_SM_GETGAMEOBJECT

		GameComponent* pGameComponent = GameObjectManager::GetSingleton()->GetGameComponent(nSceneNodeName);
		if (pGameComponent == nullptr)
		{
			return 0;
		}
		return (void*)pGameComponent;
	}

	void* GetOrCreateRootSceneNode(Gamechar* strSceneName, Gameint nSceneManagerType)
	{
		STATS_SM_GETORCREATEROOTSCENENODE

		return GameObjectManager::GetSingleton()->GetOrCreateRootSceneNode(strSceneName, nSceneManagerType);
	}

	void DestroyRootSceneNode(void* pSceneNodeHandle)
	{
		STATS_SM_DESTROYROOTSCENENODE
		// TODO
	}

	void* CreateChildSceneNode(void* pParentNodeHandle, Gamelong nSceneNodeName, Gameint nSceneManagerType)
	{
		STATS_SM_CREATECHILDSCENENODE

		return GameObjectManager::GetSingleton()->CreateChildSceneNode(pParentNodeHandle, nSceneNodeName, nSceneManagerType);
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif