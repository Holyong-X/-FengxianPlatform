// Fill out your copyright notice in the Description page of Project Settings.

#include "Component/SuperMap_LineMeshComponent.h"
#include "Component/SuperMap_LineMeshSceneProxy.h"
#include "PhysicsEngine/BodySetup.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"
#include "Graphics3D/GameConvertor.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK;
USuperMap_LineMeshComponent::USuperMap_LineMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	m_bVisible                     = true;
	m_pSceneProxy                  = nullptr;
	m_pMaterial                    = nullptr;
	m_bInitial                     = false;
}

FBoxSphereBounds USuperMap_LineMeshComponent::CalcBounds(const FTransform& LocalToWorld) const
{
	FBoxSphereBounds Ret = m_LocalBounds.TransformBy(LocalToWorld);

	Ret.BoxExtent    *= BoundsScale;
	Ret.SphereRadius *= BoundsScale;

	return Ret;
}

Gamevoid USuperMap_LineMeshComponent::CreateEdgeLineMesh(GameEntity* pGameEntity, Gamebool bCollision)
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


Gamevoid USuperMap_LineMeshComponent::CreateEdgeLineMesh(const FSMMesh& smMesh, Gamebool bCollision)
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

Gamevoid USuperMap_LineMeshComponent::CreateSimpleLineMesh(TArray<SM_Vertex>& arrVtxs, TArray<SM_SubMesh>& arrSubMeshs)
{
	m_arrLineVertex = arrVtxs;
	m_arrLineSubMesh = arrSubMeshs;
	FBox localBounds;

	localBounds.Init();
	int32 num = m_arrLineVertex.Num();
	for (Gameint i = 0; i < num; i++)
	{
		localBounds += m_arrLineVertex[i].Position;
	}

	m_LocalBounds = localBounds.IsValid ? FBoxSphereBounds(localBounds) :
		FBoxSphereBounds(FVector(0, 0, 0), FVector(0, 0, 0), 0); // fallback to reset box sphere bounds

	if (m_pSceneProxy != nullptr)
	{
		m_pSceneProxy->UpdateMesh(m_arrLineVertex, m_arrLineSubMesh);
	}

	m_bInitial = true;

	UpdateBounds();
	MarkRenderTransformDirty();
}

Gamevoid USuperMap_LineMeshComponent::SetLocalToECEF(const Matrix4d& mat)
{
	m_matLocalToECEF = mat;
}

Matrix4d USuperMap_LineMeshComponent::GetLocalToECEF()
{
	return m_matLocalToECEF;
}

Gamevoid USuperMap_LineMeshComponent::UpdateLocalBounds(const FSMMesh & smMesh)
{
	CalLocalBound(smMesh);
	UpdateBounds();
	MarkRenderTransformDirty();
}

Gamevoid USuperMap_LineMeshComponent::CalLocalBound(const FSMMesh & smMesh)
{
	FBox localBounds;

	localBounds.Init();

	if ((smMesh.m_GameBoundingBox.m_vMax.x - smMesh.m_GameBoundingBox.m_vMin.x) >= 0 &&
		(smMesh.m_GameBoundingBox.m_vMax.y - smMesh.m_GameBoundingBox.m_vMin.y) >= 0 &&
		(smMesh.m_GameBoundingBox.m_vMax.z - smMesh.m_GameBoundingBox.m_vMin.z) >= 0 )
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

FPrimitiveSceneProxy* USuperMap_LineMeshComponent::CreateSceneProxy()
{
	if (!m_bInitial)
	{
		return nullptr;
	}

	if (m_arrLineVertex.Num() > 0)
	{
		m_pSceneProxy = new FSuperMapLineMeshSceneProxy(this, m_MeshData);
		m_pSceneProxy->UpdateMesh(m_arrLineVertex, m_arrLineSubMesh);
		return m_pSceneProxy;
	}
	else
	{
		if (!m_MeshData.isValid())
		{
			return nullptr;
		}
		m_pSceneProxy = new FSuperMapLineMeshSceneProxy(this, m_MeshData);
		SetVisibleInViewport(0, m_bVisibleInViewport[0]);
		SetVisibleInViewport(1, m_bVisibleInViewport[1]);
		return m_pSceneProxy;
	}

	return nullptr;
}

Gamevoid USuperMap_LineMeshComponent::SetLayerVisibility(Gamebool bIsVisible)
{
	m_bVisibleLayer = bIsVisible;

	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		Gamebool isVisible = bIsVisible;
		FSuperMapLineMeshSceneProxy* pSceneProxy = (FSuperMapLineMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetLayerVisibity)
			([pSceneProxy, isVisible](FRHICommandListImmediate& RHICmdList)
				{
					pSceneProxy->SetVisibleLayer_RenderThread(isVisible);
				});
	}
}

Gamebool USuperMap_LineMeshComponent::GetLayerVisibility()
{
	return m_bVisibleLayer;
}

Gamevoid USuperMap_LineMeshComponent::SetVisibleInViewport(Gameint nIndex, Gamebool bIsVisible)
{
	m_bVisibleInViewport[nIndex] = bIsVisible;
	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		Gamebool isVisible = bIsVisible;
		Gameint index = nIndex;
		FSuperMapLineMeshSceneProxy* pSceneProxy = (FSuperMapLineMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetLayerVisibity)
			([pSceneProxy, isVisible, index](FRHICommandListImmediate& RHICmdList)
				{
					pSceneProxy->SetVisibleInViewport_RenderThread(index, isVisible);
				});
	}
}

Gamebool USuperMap_LineMeshComponent::GetVisibleInViewport(Gameint nIndex)
{
	return m_bVisibleInViewport[nIndex];
}

Gamevoid USuperMap_LineMeshComponent::SetRender(Gamebool bIsRender)
{
	m_bRender = bIsRender;
}

Gamebool USuperMap_LineMeshComponent::GetRender()
{
	return m_bRender;
}

Gamevoid USuperMap_LineMeshComponent::SetInternalVisibility(Gamebool bIsVisible)
{
	m_bVisible = bIsVisible;

	if (m_pSceneProxy && !IsRenderStateDirty())
	{
		Gamebool isVisible = bIsVisible;
		FSuperMapLineMeshSceneProxy* pSceneProxy = (FSuperMapLineMeshSceneProxy*)m_pSceneProxy;
		ENQUEUE_RENDER_COMMAND(FRenderMeshSetLayerVisibity)
			([pSceneProxy, isVisible](FRHICommandListImmediate& RHICmdList)
			{
				pSceneProxy->SetInternalVisibility_RenderThread(isVisible);
			});
	}
}

Gamebool USuperMap_LineMeshComponent::GetInternalVisibility() const
{
	return m_bVisible;
}

Gamevoid USuperMap_LineMeshComponent::SetCustomMaterial(UMaterialInterface* pMat)
{
	if (pMat == nullptr)
	{
		return;
	}
	SetMaterial(0, pMat);
	m_pMaterial = pMat;
}

UMaterialInterface* USuperMap_LineMeshComponent::GetCustomMaterial()
{
	return m_pMaterial;
}

int32 USuperMap_LineMeshComponent::GetNumMaterials() const
{
	Gameint nCount = 0;
	if (m_pMaterial != nullptr)
	{
		nCount++;
	}

	return nCount;
}

Gamevoid USuperMap_LineMeshComponent::SetName(FName strName)
{
	m_strName = strName;
}

FName USuperMap_LineMeshComponent::GetName()
{
	return m_strName;
}

Gamevoid USuperMap_LineMeshComponent::UpdateTransform(Vector3d vOffset , FTransform & transform)
{
	Georeference::TransformECEFToUERelative(m_matLocalToECEF, transform);
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif