// Fill out your copyright notice in the Description page of Project Settings.

#include "Component/SuperMap_PolyLineMeshComponent.h"
#include "Component/SuperMap_PolyLineMeshSceneProxy.h"
#include "Component/SuperMap_LineMeshSceneProxy.h"
#include "Component/SuperMap_MeshSceneProxy.h"
#include "PhysicsEngine/BodySetup.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"
#include "Graphics3D/GameConvertor.h"
#include "Core/Georeference.h"
#if !SM_FOR_UE_25
#include "Rendering/StaticLightingSystemInterface.h"
#endif
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK;
USuperMap_PolyLineMeshComponent::USuperMap_PolyLineMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	m_nDrawType = 0;
	m_bVisible = true;
	m_bUseComplexAsSimpleCollision = true;
	m_bVisibleLayer = true;
	m_bVisibleInViewport[0] = true;
	m_bVisibleInViewport[1] = true;
	m_pBodySetup = nullptr;
	m_pSceneProxy = nullptr;
	m_bInitial = false;
	m_nMaterialNum = 0;
	m_bReverseCulling = false;
}

FBoxSphereBounds USuperMap_PolyLineMeshComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	FBoxSphereBounds Ret = m_LocalBounds.TransformBy(LocalToWorld);

	Ret.BoxExtent *= BoundsScale;
	Ret.SphereRadius *= BoundsScale;

	return Ret;
}


Gamevoid USuperMap_PolyLineMeshComponent::CreateMesh(GameEntity* pGameEntity, Gamebool bCollision)
{
	if (pGameEntity == nullptr)
	{
		return;
	}

	m_MeshData.m_pDataVertex = pGameEntity->GetDataVertexPackage();
	m_MeshData.m_arrDataIndex.SetNum(pGameEntity->GetIndexPackageCount());
	for (Gameint i = 0; i < pGameEntity->GetIndexPackageCount(); i++)
	{
		m_MeshData.m_arrDataIndex[i] = pGameEntity->GetIndexPackageByIndex(i);
		pGameEntity->SetIndexPackageByIndex(i, nullptr);
	}
	pGameEntity->SetDataVertexPackage(nullptr);

	GameBoundingBox bbox = pGameEntity->GetBBox();

	FBox localBounds;
	localBounds.Init();
	if ((bbox.m_vMax.x - bbox.m_vMin.x) >= 0 &&
		(bbox.m_vMax.y - bbox.m_vMin.y) >= 0 &&
		(bbox.m_vMax.z - bbox.m_vMin.z) >= 0)
	{
		FVector vVertex;
		vVertex.X = bbox.m_vMax.x;
		vVertex.Y = bbox.m_vMax.y;
		vVertex.Z = bbox.m_vMax.z;

		localBounds += vVertex;

		vVertex.X = bbox.m_vMin.x;
		vVertex.Y = bbox.m_vMin.y;
		vVertex.Z = bbox.m_vMin.z;

		localBounds += vVertex;
	}


	m_LocalBounds = localBounds;

	pGameEntity->SetCollisionData(nullptr);

	m_bInitial = true;

	UpdateBounds();
	MarkRenderTransformDirty();
	MarkRenderStateDirty();
}


Gamevoid USuperMap_PolyLineMeshComponent::CreateMesh(const FSMMesh& smMesh, bool bCollision)
{
	if (!smMesh.isValid())
	{
		return;
	}

	m_MeshData = smMesh;

	m_bInitial = true;

	UpdateLocalBounds(smMesh);
	MarkRenderStateDirty();
}

Gamevoid USuperMap_PolyLineMeshComponent::UpdateSubMeshes(TArray<DataIndice*>& arrIndices, TArray<FSuperMapMaterialInterfaceCollection>& arrMaterialCollection)
{
	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		FSuperMapMeshSceneProxy* pSceneProxy = (FSuperMapMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshUpdateSubMeshes)
			([pSceneProxy, arrIndices, arrMaterialCollection](FRHICommandListImmediate& RHICmdList)
		{
			pSceneProxy->UpdateSubMesh_RenderThread(arrIndices, arrMaterialCollection);
		});

		UpdateBounds();
		MarkRenderTransformDirty();
	}
}

Gamevoid USuperMap_PolyLineMeshComponent::SetMaterial(Gameint ElementIndex, UMaterialInterface* Material)
{
	Gamebool bUpdateRenderState = (m_pSceneProxy ? false : true);

	if (ElementIndex >= 0)
	{
		if (OverrideMaterials.IsValidIndex(ElementIndex) && (OverrideMaterials[ElementIndex] == Material))
		{
			// Do nothing, the material is already set
		}
		else
		{
			// Grow the array if the new index is too large
			if (OverrideMaterials.Num() <= ElementIndex)
			{
				OverrideMaterials.AddZeroed(ElementIndex + 1 - OverrideMaterials.Num());
			}

			// Check if we are setting a dynamic instance of the original material, or replacing a nullptr material  (if not we should dirty the material parameter name cache)
			if (Material != nullptr)
			{
				UMaterialInstanceDynamic* DynamicMaterial = Cast<UMaterialInstanceDynamic>(Material);
				if (!((DynamicMaterial != nullptr && DynamicMaterial->Parent == OverrideMaterials[ElementIndex]) || OverrideMaterials[ElementIndex] == nullptr))
				{
					// Mark cached material parameter names dirty
					MarkCachedMaterialParameterNameIndicesDirty();
				}
			}

			// Set the material and invalidate things
			OverrideMaterials[ElementIndex] = Material;

			if (bUpdateRenderState)
			{
				MarkRenderStateDirty();
			}

			if (Material)
			{
				Material->AddToCluster(this, true);
			}

			FBodyInstance* BodyInst = GetBodyInstance();
			if (BodyInst && BodyInst->IsValidBodyInstance())
			{
				BodyInst->UpdatePhysicalMaterials();
			}

#if WITH_EDITOR && !SM_FOR_UE_25
			FStaticLightingSystemInterface::OnPrimitiveComponentUnregistered.Broadcast(this);
			if (HasValidSettingsForStaticLighting(false))
			{
				FStaticLightingSystemInterface::OnPrimitiveComponentRegistered.Broadcast(this);
			}
#endif
		}
	}
}


Gamevoid USuperMap_PolyLineMeshComponent::AddMaterialCollection(const FSuperMapMaterialInterfaceCollection& materialCollection)
{
	Gameint nIndex = m_arrMaterialCollection.Num();
	m_arrMaterialCollection.Add(materialCollection);

	auto pMat = materialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL);
	if (pMat != nullptr)
	{
		SetMaterial(m_nMaterialNum++, pMat);
		m_arrUsedMaterials.Add(pMat);
	}
	auto pSelectionMat = materialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION);
	if (pSelectionMat != nullptr)
	{
		SetMaterial(m_nMaterialNum++, pSelectionMat);
		m_arrUsedMaterials.Add(pSelectionMat);
	}
	auto pRectSelectionMat = materialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION);
	if (pRectSelectionMat != nullptr)
	{
		SetMaterial(m_nMaterialNum++, pRectSelectionMat);
		m_arrUsedMaterials.Add(pRectSelectionMat);
	}
	// 0视口共用的UMF_NORMAL材质，只考虑有两个视口的情况
	auto pViewportMat = materialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT);
	if (pViewportMat != nullptr)
	{
		SetMaterial(m_nMaterialNum++, pViewportMat);
		m_arrUsedMaterials.Add(pViewportMat);
	}

	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		TArray<UMaterialInterface*>& arrUsedMaterials = m_arrUsedMaterials;
		FSuperMapMeshSceneProxy* pSceneProxy = (FSuperMapMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FUsedMaterialUpdate)
			([pSceneProxy, arrUsedMaterials](FRHICommandListImmediate& RHICmdList)
		{
			pSceneProxy->UpdateUsedMaterial_RenderThread(arrUsedMaterials);
		});
	}
}

Gamevoid USuperMap_PolyLineMeshComponent::RemoveLastMaterialCollection(const FSuperMapMaterialInterfaceCollection& materialCollection)
{
	Gameint nIndex = m_arrMaterialCollection.Num() - 1;
	m_arrMaterialCollection.RemoveAt(nIndex);

	Gameint nCount = 0;
	auto pViewportMat = materialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT);
	if (pViewportMat != nullptr)
	{
		SetMaterial(--m_nMaterialNum, nullptr);
		nCount++;
	}
	auto pRectSelectionMat = materialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_RECT_SELECTION);
	if (pRectSelectionMat != nullptr)
	{
		SetMaterial(--m_nMaterialNum, nullptr);
		nCount++;
	}
	auto pSelectionMat = materialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION);
	if (pSelectionMat != nullptr)
	{
		SetMaterial(--m_nMaterialNum, nullptr);
		nCount++;
	}

	auto pMat = materialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL);
	if (pMat != nullptr)
	{
		SetMaterial(--m_nMaterialNum, nullptr);
		nCount++;
	}

	m_arrUsedMaterials.RemoveAt(m_nMaterialNum, nCount);

	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		TArray<UMaterialInterface*>& arrUsedMaterials = m_arrUsedMaterials;
		FSuperMapMeshSceneProxy* pSceneProxy = (FSuperMapMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FUsedMaterialUpdate)
			([pSceneProxy, arrUsedMaterials](FRHICommandListImmediate& RHICmdList)
		{
			pSceneProxy->UpdateUsedMaterial_RenderThread(arrUsedMaterials);
		});
	}
}

Gamevoid USuperMap_PolyLineMeshComponent::GetAllCustomMaterials(TArray<UMaterialInterface*>& arrOutMaterials)
{
	for (Gameint i = 0; i < m_arrMaterialCollection.Num(); i++)
	{
		arrOutMaterials.Add(m_arrMaterialCollection[i].GetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL));
	}
}

Gamevoid USuperMap_PolyLineMeshComponent::GetAllSelectionMaterials(TArray<UMaterialInterface*>& arrOutMaterials)
{
	for (Gameint i = 0; i < m_arrMaterialCollection.Num(); i++)
	{
		UMaterialInterface* pMat = m_arrMaterialCollection[i].GetMaterialByUseFlag(UseMaterialFlag::UMF_SELECTION);
		if (pMat == nullptr)
		{
			continue;
		}
		arrOutMaterials.Add(pMat);
	}
}

Gamevoid USuperMap_PolyLineMeshComponent::GetAllMaterialsInViewport(TArray<UMaterialInterface*>& arrOutMaterials)
{
	for (Gameint i = 0; i < m_arrMaterialCollection.Num(); i++)
	{
		UMaterialInterface* pMat = m_arrMaterialCollection[i].GetMaterialByUseFlag(UseMaterialFlag::UMF_VIEWPORT);
		if (pMat == nullptr)
		{
			continue;
		}
		arrOutMaterials.Add(pMat);
	}
}

Gamevoid USuperMap_PolyLineMeshComponent::SetLocalToECEF(const Matrix4d& mat)
{
	m_matLocalToECEF = mat;
}

Matrix4d USuperMap_PolyLineMeshComponent::GetLocalToECEF()
{
	return m_matLocalToECEF;
}

Gamevoid USuperMap_PolyLineMeshComponent::SetUseMaterialFlag(UseMaterialFlag enUseMaterialFlag)
{
	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		UseMaterialFlag tempUseMaterialFlag = enUseMaterialFlag;
		FSuperMapMeshSceneProxy* pSceneProxy = (FSuperMapMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetUseMaterialFlag)
			([pSceneProxy, tempUseMaterialFlag](FRHICommandListImmediate& RHICmdList)
		{
			pSceneProxy->SetUseMaterialFlag_RenderThread(tempUseMaterialFlag);
		});
	}
}

Gamevoid USuperMap_PolyLineMeshComponent::SetLayerVisibility(bool bIsVisible)
{
	m_bVisibleLayer = bIsVisible;

	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		bool isVisible = bIsVisible;
		FSuperMapMeshSceneProxy* pSceneProxy = (FSuperMapMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetLayerVisibity)
			([pSceneProxy, isVisible](FRHICommandListImmediate& RHICmdList)
		{
			pSceneProxy->SetVisibleLayer_RenderThread(isVisible);
		});
	}
}

bool USuperMap_PolyLineMeshComponent::GetLayerVisibility() const
{
	return m_bVisibleLayer;
}

Gamevoid USuperMap_PolyLineMeshComponent::SetVisibleInViewport(Gameint nIndex, bool bIsVisible)
{
	m_bVisibleInViewport[nIndex] = bIsVisible;
	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		bool isVisible = bIsVisible;
		Gameint index = nIndex;
		FSuperMapMeshSceneProxy* pSceneProxy = (FSuperMapMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetLayerVisibity)
			([pSceneProxy, isVisible, index](FRHICommandListImmediate& RHICmdList)
		{
			pSceneProxy->SetVisibleInViewport_RenderThread(index, isVisible);
		});
	}
}

bool USuperMap_PolyLineMeshComponent::GetVisibleInViewport(Gameint nIndex)
{
	return m_bVisibleInViewport[nIndex];
}

Gamevoid USuperMap_PolyLineMeshComponent::SetRender(bool bIsRender)
{
	m_bRender = bIsRender;

	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		bool isRender = bIsRender;
		FSuperMapMeshSceneProxy* pSceneProxy = (FSuperMapMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetLayerVisibity)
			([pSceneProxy, isRender](FRHICommandListImmediate& RHICmdList)
		{
			pSceneProxy->SetRender_RenderThread(isRender);
		});
	}
}

bool USuperMap_PolyLineMeshComponent::GetRender()
{
	return m_bRender;
}

Gamevoid USuperMap_PolyLineMeshComponent::UpdateLocalBounds(const FSMMesh& smMesh)
{
	CalLocalBound(smMesh);
	UpdateBounds();
	MarkRenderTransformDirty();
}

Gamevoid USuperMap_PolyLineMeshComponent::SetDrawType(Gameint nType)
{
	m_nDrawType = nType;
}

UBodySetup* USuperMap_PolyLineMeshComponent::GetBodySetup()
{
	return m_pBodySetup;
}

Gamevoid USuperMap_PolyLineMeshComponent::CalLocalBound(const FSMMesh& smMesh)
{
	FBox localBounds;

	localBounds.Init();

	if ((smMesh.m_GameBoundingBox.m_vMax.x - smMesh.m_GameBoundingBox.m_vMin.x) >= 0 &&
		(smMesh.m_GameBoundingBox.m_vMax.y - smMesh.m_GameBoundingBox.m_vMin.y) >= 0 &&
		(smMesh.m_GameBoundingBox.m_vMax.z - smMesh.m_GameBoundingBox.m_vMin.z) >= 0)
	{
		FVector vVertex;
		vVertex.X = smMesh.m_GameBoundingBox.m_vMax.x;
		vVertex.Y = smMesh.m_GameBoundingBox.m_vMax.y;
		vVertex.Z = smMesh.m_GameBoundingBox.m_vMax.z;

		localBounds += vVertex;

		vVertex.X = smMesh.m_GameBoundingBox.m_vMin.x;
		vVertex.Y = smMesh.m_GameBoundingBox.m_vMin.y;
		vVertex.Z = smMesh.m_GameBoundingBox.m_vMin.z;

		localBounds += vVertex;

	}
	else
	{
		Gameint nDim = smMesh.m_pDataVertex->m_nPosDim;

		for (Gameint i = 0; i < smMesh.m_pDataVertex->m_nPosCount; ++i)
		{
			FVector vertex;
			vertex.Y = smMesh.m_pDataVertex->m_Pos[nDim * i + 0] * M_TO_CM;
			vertex.X = smMesh.m_pDataVertex->m_Pos[nDim * i + 1] * M_TO_CM;
			vertex.Z = smMesh.m_pDataVertex->m_Pos[nDim * i + 2] * M_TO_CM;
			localBounds += vertex;
		}
	}

	m_LocalBounds = localBounds.IsValid ? FBoxSphereBounds(localBounds) :
		FBoxSphereBounds(FVector(0, 0, 0), FVector(0, 0, 0), 0); // fallback to reset box sphere bounds

}

Gamevoid USuperMap_PolyLineMeshComponent::UpdateMesh(const FSMMesh& smMesh, UGVertexDataStateSet nState)
{
	if (nState == VST_VertexColor)
	{
		if (m_pSceneProxy && !IsRenderStateDirty())
		{
			FSuperMapMeshSceneProxy* proxy = (FSuperMapMeshSceneProxy*)m_pSceneProxy;
			ENQUEUE_RENDER_COMMAND(FRenderMeshUpdate)
				([proxy, smMesh](FRHICommandListImmediate& RHICmdList) {
				proxy->UpdateVertexColor_RenderThread(smMesh);
			});
		}
		else
		{
			if (m_MeshData.m_pDataVertex != nullptr && m_MeshData.m_pDataVertex->m_PosColor != nullptr)
			{
				// 替换颜色
				FMemory::Memcpy(m_MeshData.m_pDataVertex->m_PosColor + smMesh.m_nSubMeshInfoOffset,
					smMesh.m_pDataVertex->m_PosColor, sizeof(Gameuint) * smMesh.m_pDataVertex->m_nColorCount);
			}
		}

		UpdateBounds();
		MarkRenderTransformDirty();
	}
	else
	{
		if (m_pSceneProxy && !IsRenderStateDirty())
		{
			// 更新Bound
			CalLocalBound(smMesh);
			FSuperMapMeshSceneProxy* proxy = (FSuperMapMeshSceneProxy*)m_pSceneProxy;
			ENQUEUE_RENDER_COMMAND(FRenderMeshUpdate)
				([proxy, smMesh](FRHICommandListImmediate& RHICmdList) {
				proxy->UpdateMesh_RenderThread(smMesh);
			});

			UpdateBounds();
			MarkRenderTransformDirty();

		}
		else
		{
			m_MeshData = smMesh;
			UpdateLocalBounds(smMesh);
		}
	}
}

Gamebool USuperMap_PolyLineMeshComponent::GetReverseCulling() const
{
	return m_bReverseCulling;
}

Gamevoid USuperMap_PolyLineMeshComponent::SetReverseCulling(Gamebool bReverseCulling)
{
	m_bReverseCulling = bReverseCulling;
	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		FSuperMapPolyLineMeshSceneProxy* proxy = (FSuperMapPolyLineMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetInternalVisibility)
			([proxy, bReverseCulling](FRHICommandListImmediate& RHICmdList) {
			proxy->SetReverseCulling_RenderThread(bReverseCulling);
		});
	}
}

Gamevoid USuperMap_PolyLineMeshComponent::UpdateInstanceVertexColor(Gameuint nColor, TArray<Gameuint>& arrIds)
{
	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		FSuperMapPolyLineMeshSceneProxy* proxy = (FSuperMapPolyLineMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshUpdate)
			([proxy, nColor, arrIds](FRHICommandListImmediate& RHICmdList) {
			proxy->UpdateInstanceVertexColor_RenderThread(nColor, arrIds);
		});

		UpdateBounds();
		MarkRenderTransformDirty();
	}
}

FPrimitiveSceneProxy* USuperMap_PolyLineMeshComponent::CreateSceneProxy()
{
	if (!m_bInitial)
	{
		return nullptr;
	}

	if (!m_MeshData.isValid())
	{
		return nullptr;
	}

	if (m_pBodySetup)
	{
		if (!m_bVisible)
		{
			BodyInstance.UpdateBodyScale(FVector::ZeroVector);
		}
	}

	m_pSceneProxy = new FSuperMapPolyLineMeshSceneProxy(this, m_MeshData, m_arrMaterialCollection);
	SetVisibleInViewport(0, m_bVisibleInViewport[0]);
	SetVisibleInViewport(1, m_bVisibleInViewport[1]);
	return m_pSceneProxy;
}

Gamevoid USuperMap_PolyLineMeshComponent::SetInternalVisibility(bool bIsVisible)
{
	m_bVisible = bIsVisible;

	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		if (m_pBodySetup)
		{
			if (m_bVisible)
			{
				BodyInstance.UpdateBodyScale(FVector::OneVector);
			}
			else
			{
				BodyInstance.UpdateBodyScale(FVector::ZeroVector);
			}
		}

		bool isVisible = bIsVisible;
		FSuperMapPolyLineMeshSceneProxy* proxy = (FSuperMapPolyLineMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetInternalVisibility)
			([proxy, isVisible](FRHICommandListImmediate& RHICmdList) {
			proxy->SetInternalVisibility_RenderThread(isVisible);
		});
	}
}

bool USuperMap_PolyLineMeshComponent::GetInternalVisibility() const
{
	return m_bVisible;
}

Gameint USuperMap_PolyLineMeshComponent::GetNumMaterials() const
{
	return m_nMaterialNum;
}

bool USuperMap_PolyLineMeshComponent::GetPhysicsTriMeshData(struct FTriMeshCollisionData* CollisionData, bool InUseAllTriData)
{
	if (!m_CollisionData.IsValid())
	{
		return false;
	}

	if (m_CollisionData.m_pPos != nullptr)
	{
		// 设置顶点
		Gameint nPosDim = m_CollisionData.m_nPosDim;
		for (Gameint i = 0; i < m_CollisionData.m_nPosCount; i++)
		{
			FVector vertices;
			vertices.Y = m_CollisionData.m_pPos[i * nPosDim + 0] * M_TO_CM;
			vertices.X = m_CollisionData.m_pPos[i * nPosDim + 1] * M_TO_CM;
			vertices.Z = m_CollisionData.m_pPos[i * nPosDim + 2] * M_TO_CM;
			CollisionData->Vertices.Add(GameVector3(vertices));
		}
	}

	if (m_CollisionData.m_nIndexCount > 0)
	{
		Gameint nNumIndices = m_CollisionData.m_nIndexCount;
		for (Gameint i = 0; i < m_CollisionData.m_nIndexCount; i += 3)
		{
			FTriIndices Triangle;
			if (m_CollisionData.m_pIndex != nullptr)
			{
				Triangle.v0 = m_CollisionData.m_pIndex[i + 0];
				Triangle.v1 = m_CollisionData.m_pIndex[i + 1];
				Triangle.v2 = m_CollisionData.m_pIndex[i + 2];
			}
			else if (m_CollisionData.m_pShortIndex != nullptr)
			{
				Triangle.v0 = m_CollisionData.m_pShortIndex[i + 0];
				Triangle.v1 = m_CollisionData.m_pShortIndex[i + 1];
				Triangle.v2 = m_CollisionData.m_pShortIndex[i + 2];

			}

			CollisionData->Indices.Add(Triangle);
			CollisionData->MaterialIndices.Add(0);
		}
	}

	CollisionData->bFlipNormals = true;
	CollisionData->bDeformableMesh = true;
	CollisionData->bFastCook = true;

	return true;
}

bool USuperMap_PolyLineMeshComponent::ContainsPhysicsTriMeshData(bool InUseAllTriData) const
{
	return m_pBodySetup ? true : false;
}

UBodySetup* USuperMap_PolyLineMeshComponent::CreateBodySetupHelper()
{
	UBodySetup* NewBodySetup = NewObject<UBodySetup>(this, NAME_None, (IsTemplate() ? RF_Public : RF_NoFlags));
	NewBodySetup->BodySetupGuid = FGuid::NewGuid();

	NewBodySetup->bGenerateMirroredCollision = false;
	NewBodySetup->bDoubleSidedGeometry = true;
	NewBodySetup->CollisionTraceFlag = m_bUseComplexAsSimpleCollision ? CTF_UseComplexAsSimple : CTF_UseDefault;

	return NewBodySetup;
}

Gamevoid USuperMap_PolyLineMeshComponent::FinishPhysicsAsyncCook(bool bSuccess, UBodySetup* FinishedBodySetup)
{
	if (bSuccess)
	{
		RecreatePhysicsState();
	}
}

Gamevoid USuperMap_PolyLineMeshComponent::SetName(FName strName)
{
	m_strName = strName;
}

FName USuperMap_PolyLineMeshComponent::GetName()
{
	return m_strName;
}

Gamevoid USuperMap_PolyLineMeshComponent::UpdateTransform(Vector3d vOffset, FTransform& transform)
{
	Georeference::TransformECEFToUERelative(m_matLocalToECEF, transform);
}

FString USuperMap_PolyLineMeshComponent::GetRealMaterialName()
{
	return m_strRealMaterialName;
}

Gamevoid USuperMap_PolyLineMeshComponent::SetRealMaterialName(FString strRealMaterialName)
{
	m_strRealMaterialName = strRealMaterialName;
}

FString USuperMap_PolyLineMeshComponent::GetLayerName()
{
	return m_strLayerName;
}

Gamevoid USuperMap_PolyLineMeshComponent::SetLayerName(FString strLayerName)
{
	m_strLayerName = strLayerName;
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif