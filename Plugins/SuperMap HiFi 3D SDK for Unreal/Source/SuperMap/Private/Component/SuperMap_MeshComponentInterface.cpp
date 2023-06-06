#include "Component/SuperMap_MeshComponentInterface.h"
#include "Component/SuperMap_InstancedStaticMeshComponent.h"
#include "Component/SuperMap_StaticMeshComponent.h"
#include "Component/SuperMap_MeshComponent.h"
#include "Component/SuperMap_LineMeshComponent.h"
#include "Component/SuperMap_BillboardComponent.h"
#include "Component/SuperMap_PolyLineMeshComponent.h"
#include "Core/Georeference.h"
#include "Graphics3D/GameLifetime.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Core;

USuperMap_MeshComponentInterface::USuperMap_MeshComponentInterface()
{
	m_bStatic               = false;
	m_pMeshComponent        = nullptr;
	m_eComponentType        = CustomMeshComponent;
	m_pCustomRealRasterMesh = nullptr;
	m_enUseMaterialFlag = UseMaterialFlag::UMF_NORMAL;
	m_bInternalVisibility	= true;
	m_bVisibleInViewport[0] = true;
	m_bVisibleInViewport[1] = true;
	m_strLayerName = "";
	m_bLayerVisible = true;
	m_bReverseCulling = false;
}

USuperMap_MeshComponentInterface::~USuperMap_MeshComponentInterface()
{
}

void USuperMap_MeshComponentInterface::UpdateInstanceVertexColor(Gameuint nColor, TArray<uint32>& arrIds)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->UpdateInstanceVertexColor(nColor, arrIds);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->UpdateInstanceVertexColor(nColor, arrIds);
		break;
	default:
		break;
	}
}

//! \brief 更新网格信息
void USuperMap_MeshComponentInterface::UpdateMesh(const FSMMesh & meshData, UGVertexDataStateSet nState)
{
	if(m_pMeshComponent == nullptr && m_pCustomRealRasterMesh == nullptr)
	{
		return;
	}
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent*       pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;
	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->UpdateMesh(meshData, nState);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->UpdateMesh(meshData, nState);
		break;
	case CustomStaticMeshComponent:
	case CustomInstancedStaticMeshComponent:
	case CustomBillboardComponent:
	case CustomEdgeLineComponent:
		break;
	case CustomRealTimeRaster:
		m_pCustomRealRasterMesh->UpdateMesh(meshData, nState);
		break;
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::CreateMesh(GameEntity* pGameEntity, Gamebool bCollision)
{
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent*       pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshCom = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;
	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetLayerVisibility(m_bLayerVisible);
		pMeshCom->SetInternalVisibility(m_bInternalVisibility);
		pMeshCom->CreateMesh(pGameEntity, bCollision);
		pMeshCom->SetVisibleInViewport(0, m_bVisibleInViewport[0]);
		pMeshCom->SetVisibleInViewport(1, m_bVisibleInViewport[1]);
		break;
	case CustomEdgeLineComponent:
		pLineMeshCom = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		pLineMeshCom->SetLayerVisibility(m_bLayerVisible);
		pLineMeshCom->SetInternalVisibility(m_bInternalVisibility);
		pLineMeshCom->CreateEdgeLineMesh(pGameEntity, bCollision);
		pLineMeshCom->SetVisibleInViewport(0, m_bVisibleInViewport[0]);
		pLineMeshCom->SetVisibleInViewport(1, m_bVisibleInViewport[1]);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->SetLayerVisibility(m_bLayerVisible);
		pPolyLineMeshComponent->SetInternalVisibility(m_bInternalVisibility);
		pPolyLineMeshComponent->CreateMesh(pGameEntity, bCollision);
		pPolyLineMeshComponent->SetVisibleInViewport(0, m_bVisibleInViewport[0]);
		pPolyLineMeshComponent->SetVisibleInViewport(1, m_bVisibleInViewport[1]);
		break;
	case CustomStaticMeshComponent:
		break;
	case CustomInstancedStaticMeshComponent:
		break;
	case CustomBillboardComponent:
		break;
	case CustomRealTimeRaster:
		break;
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::CreateMesh(const FSMMesh& meshData, Gamebool bCollision)
{
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent*       pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;
	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->CreateMesh(meshData, bCollision);
		pMeshCom->SetVisibleInViewport(0, m_bVisibleInViewport[0]);
		pMeshCom->SetVisibleInViewport(1, m_bVisibleInViewport[1]);
		pMeshCom->SetLayerVisibility(m_bLayerVisible);
		break;
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		pLineMeshComponent->CreateEdgeLineMesh(meshData, bCollision);
		pLineMeshComponent->SetVisibleInViewport(0, m_bVisibleInViewport[0]);
		pLineMeshComponent->SetVisibleInViewport(1, m_bVisibleInViewport[1]);
		pLineMeshComponent->SetLayerVisibility(m_bLayerVisible);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->CreateMesh(meshData, bCollision);
		pPolyLineMeshComponent->SetVisibleInViewport(0, m_bVisibleInViewport[0]);
		pPolyLineMeshComponent->SetVisibleInViewport(1, m_bVisibleInViewport[1]);
		pPolyLineMeshComponent->SetLayerVisibility(m_bLayerVisible);
		break;
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		pStaticMeshCom->CreateMesh(meshData, bCollision);
		// 静态网格要先创建碰撞体再注册
		m_pMeshComponent->RegisterComponent();
		break;
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshComponent = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		pInstancedStaticMeshComponent->CreateMesh(meshData, bCollision);
		m_pMeshComponent->RegisterComponent();
		break;
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		pBillboardComponent->CreateMesh(meshData, bCollision);
		break;
	case CustomRealTimeRaster: 
		m_pCustomRealRasterMesh->CreateMesh(meshData);
		break;
	default:
		break;
	}
};

void USuperMap_MeshComponentInterface::SetName(FName strName)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetName(strName);
		break;
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		pLineMeshComponent->SetName(strName);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->SetName(strName);
		break;
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		pStaticMeshCom->SetName(strName);
		break;
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshComponent = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		pInstancedStaticMeshComponent->SetName(strName);
		break;
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		pBillboardComponent->SetName(strName);
		break;
	case CustomRealTimeRaster:
		m_pCustomRealRasterMesh->SetName(strName);
		break;
	default:
		break;
	}
};

FName USuperMap_MeshComponentInterface::GetName()
{ 
	if (m_pMeshComponent == nullptr)
	{
		return TEXT("");
	}
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;
	
	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		return pMeshCom->GetName();
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		return pLineMeshComponent->GetName();
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		return pPolyLineMeshComponent->GetName();
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		return pStaticMeshCom->GetName();
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshComponent = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		return pInstancedStaticMeshComponent->GetName();
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		return pBillboardComponent->GetName();
	case CustomRealTimeRaster:
		return m_pCustomRealRasterMesh->GetName();
	default:
		return FName();
		break;
	}
};

void USuperMap_MeshComponentInterface::SetLayerVisibility(Gamebool bIsVisible)
{
	m_bLayerVisible = bIsVisible;
	if (m_pCustomRealRasterMesh != nullptr)
	{
		m_pCustomRealRasterMesh->SetLayerVisibility(bIsVisible);
	}

	if (m_pMeshComponent == nullptr)
	{
		return;
	}
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetLayerVisibility(bIsVisible);
		break;
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		pLineMeshComponent->SetLayerVisibility(bIsVisible);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->SetLayerVisibility(bIsVisible);
		break;
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		pStaticMeshCom->SetLayerVisibility(bIsVisible);
		break;
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshComponent = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		pInstancedStaticMeshComponent->SetLayerVisibility(bIsVisible);
		break;
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		pBillboardComponent->SetLayerVisibility(bIsVisible);
		break;
	default:
		break;
	}
}

Gamebool USuperMap_MeshComponentInterface::GetLayerVisibility()
{ 

	return m_bLayerVisible;

	
};

void USuperMap_MeshComponentInterface::SetRender(Gamebool bIsRender)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetRender(bIsRender);
		break;
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		pLineMeshComponent->SetRender(bIsRender);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->SetRender(bIsRender);
		break;
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		pStaticMeshCom->SetRender(bIsRender);
		break;
	case CustomInstancedStaticMeshComponent:
	case CustomBillboardComponent:
	default:
		break;
	}
}

Gamebool USuperMap_MeshComponentInterface::GetRender()
{
	if (m_pMeshComponent == nullptr)
	{
		return false;
	}
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		return pMeshCom->GetRender();
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		return pLineMeshComponent->GetRender();
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		return pPolyLineMeshComponent->GetRender();
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		return pStaticMeshCom->GetRender();
	case CustomInstancedStaticMeshComponent:
	case CustomBillboardComponent:
	default:
		return false;
		break;
	}
}

void USuperMap_MeshComponentInterface::SetVisibleInViewport(Gameint nIndex, Gamebool bIsVisible)
{
	m_bVisibleInViewport[nIndex] = bIsVisible;
	if (m_pMeshComponent == nullptr)
	{
		return;
	}
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetVisibleInViewport(nIndex, bIsVisible);
		break;
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		pLineMeshComponent->SetVisibleInViewport(nIndex, bIsVisible);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->SetVisibleInViewport(nIndex, bIsVisible);
		break;
	case CustomStaticMeshComponent:
		break;
	case CustomInstancedStaticMeshComponent:
		break;
	case CustomBillboardComponent:
		break;
	default:
		break;
	}
}

Gamebool USuperMap_MeshComponentInterface::GetVisibleInViewport(Gameint nIndex)
{
	if (m_pMeshComponent == nullptr)
	{
		return false;
	}
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		return pMeshCom->GetVisibleInViewport(nIndex);
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		return pLineMeshComponent->GetVisibleInViewport(nIndex);
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		return pPolyLineMeshComponent->GetVisibleInViewport(nIndex);
	case CustomStaticMeshComponent:
	case CustomInstancedStaticMeshComponent:
	case CustomBillboardComponent:
	default:
		return false;
		break;
	}
}

void USuperMap_MeshComponentInterface::UpdateSubMeshes(TArray<DataIndice*>& arrIndices, TArray<FSuperMapMaterialInterfaceCollection>& arrMaterialCollection)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->UpdateSubMeshes(arrIndices, arrMaterialCollection);
		break;
	case CustomEdgeLineComponent:
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->UpdateSubMeshes(arrIndices, arrMaterialCollection);
		break;
	case CustomStaticMeshComponent:
		break;
	case CustomInstancedStaticMeshComponent:
		break;
	case CustomBillboardComponent:
		break;
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::SetInternalVisibility(Gamebool bIsVisible)
{
	m_bInternalVisibility = bIsVisible;
	if (m_pMeshComponent == nullptr)
	{
		return;
	}
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetInternalVisibility(bIsVisible);
		break;
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		pLineMeshComponent->SetInternalVisibility(bIsVisible);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->SetInternalVisibility(bIsVisible);
		break;
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		pStaticMeshCom->SetInternalVisibility(bIsVisible);
		break;
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshComponent = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		pInstancedStaticMeshComponent->SetInternalVisibility(bIsVisible);
		break;
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		pBillboardComponent->SetInternalVisibility(bIsVisible);
		break;
	default:
		break;
	}

};

Gamebool USuperMap_MeshComponentInterface::GetInternalVisibility()
{ 
	return m_bInternalVisibility;
};

Matrix4d USuperMap_MeshComponentInterface::GetLocalToECEF()
{
	if (m_pMeshComponent == nullptr)
	{
		return Matrix4d::IDENTITY;
	}

	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		return pMeshCom->GetLocalToECEF();
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		return pLineMeshComponent->GetLocalToECEF();
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		return pPolyLineMeshComponent->GetLocalToECEF();
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		return pStaticMeshCom->GetLocalToECEF();
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshComponent = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		return pInstancedStaticMeshComponent->GetLocalToECEF();
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		return pInstancedStaticMeshComponent->GetLocalToECEF();
	default:
		break;
	}

	return Matrix4d::IDENTITY;
}

void USuperMap_MeshComponentInterface::SetLocalToECEF(const Matrix4d& mat)
{
	m_localToECEF = mat;

	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetLocalToECEF(mat);
		break;
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		pLineMeshComponent->SetLocalToECEF(mat);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->SetLocalToECEF(mat);
		break;
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		pStaticMeshCom->SetLocalToECEF(mat);
		break;
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshComponent = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		pInstancedStaticMeshComponent->SetLocalToECEF(mat);
		break;
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		pBillboardComponent->SetLocalToECEF(mat);
		break;
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::SetBillboardParam(Gameint nBaseSizeX, Gameint nBaseSizeY, Matrix4d matTexcoord)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	USuperMap_BillboardComponent* pBillboardComponent = nullptr;
	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		break;
	case CustomStaticMeshComponent:
		break;
	case CustomInstancedStaticMeshComponent:
		break;
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		pBillboardComponent->SetBillboardParam(nBaseSizeX, nBaseSizeY, matTexcoord);
		break;
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::SetTexture(UTexture2D* pTexture2D)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	USuperMap_BillboardComponent* pBillboardComponent = nullptr;
	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		break;
	case CustomStaticMeshComponent:
		break;
	case CustomInstancedStaticMeshComponent:
		break;
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		pBillboardComponent->SetTexture(pTexture2D);
		break;
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::CreateMeshComponent(ComponentType eComType, AActor* pActor)
{
	m_eComponentType = eComType;
	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		m_pMeshComponent = NewObject<USuperMap_MeshComponent>(pActor);
		break;
	case CustomEdgeLineComponent:
		m_pMeshComponent = NewObject<USuperMap_LineMeshComponent>(pActor);
		break;
	case CustomPolyLineComponent:
		m_pMeshComponent = NewObject<USuperMap_PolyLineMeshComponent>(pActor);
		break;
	case CustomStaticMeshComponent:
		m_pMeshComponent = NewObject<USuperMap_StaticMeshComponent>(pActor);
		break;
	case CustomInstancedStaticMeshComponent:
		m_pMeshComponent = NewObject<USuperMap_InstancedStaticMeshComponent>(pActor);
		break;
	case CustomBillboardComponent:
		m_pMeshComponent = NewObject<USuperMap_BillboardComponent>(pActor);
		break;
	case CustomRealTimeRaster:
		m_pCustomRealRasterMesh = new CustomRealRasterMesh();
		break;
	default:
		break;
	}

	if (m_pMeshComponent != nullptr)
	{
		m_pMeshComponent->SetMobility(EComponentMobility::Type::Movable);
		m_pMeshComponent->SetFlags(RF_Transient | RF_DuplicateTransient | RF_TextExportTransient);
		m_pMeshComponent->RegisterComponent();

		FAttachmentTransformRules transformRules(EAttachmentRule::KeepRelative, true);
		m_pMeshComponent->AttachToComponent(this, transformRules);

		SetLocalToECEF(m_localToECEF);
	}
}

void USuperMap_MeshComponentInterface::CreateMeshComponent(ComponentType eComType)
{
	m_pMeshComponent = NewObject<USuperMap_MeshComponent>(this);
	m_pMeshComponent->RegisterComponent();

	if (m_pMeshComponent != nullptr)
	{
		FAttachmentTransformRules transformRules(EAttachmentRule::KeepRelative, true);
		m_pMeshComponent->AttachToComponent(this, transformRules);
	}
}

UPrimitiveComponent* USuperMap_MeshComponentInterface::GetMeshComponent()
{
	return m_pMeshComponent;
}

CustomRealRasterMesh* USuperMap_MeshComponentInterface::GetRealRasterMesh()
{
	return m_pCustomRealRasterMesh;
}

void USuperMap_MeshComponentInterface::ReleaseMeshComponent()
{
	if (m_pCustomRealRasterMesh != nullptr)
	{
		delete m_pCustomRealRasterMesh;
		m_pCustomRealRasterMesh = nullptr;
	}
	
	if (m_pMeshComponent == nullptr)
	{
		return;
	}


	if (m_eComponentType == CustomStaticMeshComponent)
	{
		USuperMap_StaticMeshComponent* pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		UStaticMesh* pStaticMesh = pStaticMeshCom->GetStaticMesh();
		if (pStaticMesh)
		{
			if (pStaticMesh->GetBodySetup())
			{
				GameLifetime::Destory(pStaticMesh->GetBodySetup());
			}

			GameLifetime::Destory(pStaticMesh);
			pStaticMeshCom->SetStaticMesh(nullptr);
		}
	}

	if (m_pMeshComponent->IsRegistered())
	{
		m_pMeshComponent->UnregisterComponent();
	}

	m_pMeshComponent->DestroyPhysicsState();
	m_pMeshComponent->DestroyComponent();
	m_pMeshComponent->ConditionalBeginDestroy();
	m_pMeshComponent = nullptr;
}

TArray<USceneComponent*> USuperMap_MeshComponentInterface::GetAttachSceneComponentChildren()
{
	TArray<USceneComponent*> arrChilds = GetAttachChildren();
	Gameint nChildCount = arrChilds.Num();
	TArray<USceneComponent*> result;
	for (Gameint i = 0; i < nChildCount; i++)
	{
		USceneComponent* pSceneComponent = arrChilds[i];
		if (m_pMeshComponent != nullptr && pSceneComponent == m_pMeshComponent)
		{
			continue;
		}
		result.Add(pSceneComponent);
	}
	return result;
}

void USuperMap_MeshComponentInterface::SetCustomStaticMesh(FString strStaticMeshName, UStaticMesh* pStaticMesh)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshCom = nullptr;
	switch (m_eComponentType)
	{
	case CustomMeshComponent:		
		break;
	case CustomStaticMeshComponent:
		break;
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshCom = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		pInstancedStaticMeshCom->SetCustomStaticMesh(strStaticMeshName, pStaticMesh);
		break;
	default:
		break;
	}
}

ComponentType USuperMap_MeshComponentInterface::GetComponentType()
{
	return m_eComponentType;
}

void USuperMap_MeshComponentInterface::UpdateTransfrom(Vector3d vOffset)
{
	FTransform transformUpdate;
	Georeference::TransformECEFToUERelative(m_localToECEF , transformUpdate);

	if (m_pMeshComponent == nullptr)
	{
		if (m_eComponentType != CustomInstancedStaticMeshComponent)
		{
			SetWorldTransform(transformUpdate);
		}
		return;
	}

	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshCom = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
	case CustomEdgeLineComponent:
	case CustomPolyLineComponent:
		SetWorldTransform(transformUpdate);
		break;
	case CustomStaticMeshComponent:
		SetWorldTransform(transformUpdate);
		break;
	case CustomInstancedStaticMeshComponent:
		SetWorldTransform(transformUpdate);
		pInstancedStaticMeshCom = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		pInstancedStaticMeshCom->BatchUpdateTransform(vOffset);
		break;
	case CustomBillboardComponent:
		SetWorldTransform(transformUpdate);
		break;
	default:
		break;
	}
}

FString USuperMap_MeshComponentInterface::GetRealMaterialName()
{
	if (m_pMeshComponent == nullptr)
	{
		return TEXT("");
	}
	FString strRealMaterialName;
	if (m_eComponentType == CustomMeshComponent)
	{
		USuperMap_MeshComponent* pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		strRealMaterialName = pMeshCom->GetRealMaterialName();
	}

	return strRealMaterialName;
}

void USuperMap_MeshComponentInterface::SetRealMaterialName(FString strRealMaterialName)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	if (m_eComponentType == CustomMeshComponent)
	{
		USuperMap_MeshComponent* pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetRealMaterialName(strRealMaterialName);
	}
}

FString USuperMap_MeshComponentInterface::GetLayerName()
{
	return m_strLayerName;
}

void USuperMap_MeshComponentInterface::SetLayerName(FString strLayerName)
{
	m_strLayerName = strLayerName;
	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	if (m_eComponentType == CustomMeshComponent)
	{
		USuperMap_MeshComponent* pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetLayerName(strLayerName);
	}
}

void USuperMap_MeshComponentInterface::RemoveLastMaterialCollection(const FSuperMapMaterialInterfaceCollection& lastMaterialCollection)
{
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->RemoveLastMaterialCollection(lastMaterialCollection);
		break;
	case CustomEdgeLineComponent:
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->RemoveLastMaterialCollection(lastMaterialCollection);
		break;
	case CustomStaticMeshComponent:
		break;
	case CustomInstancedStaticMeshComponent:
		break;
	case CustomBillboardComponent:
		break;
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::AddMaterialCollection(const FSuperMapMaterialInterfaceCollection& materialCollection)
{
	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	UMaterialInterface* pCustomMaterial = materialCollection.GetMaterialByUseFlag(UseMaterialFlag::UMF_NORMAL);

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->AddMaterialCollection(materialCollection);
		break;
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		pLineMeshComponent->SetCustomMaterial(pCustomMaterial);
		break;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->AddMaterialCollection(materialCollection);
		break;
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		pStaticMeshCom->SetCustomMaterial(pCustomMaterial);
		break;
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshComponent = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		pInstancedStaticMeshComponent->SetCustomMaterial(pCustomMaterial);
		break;
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		pBillboardComponent->SetCustomMaterial(pCustomMaterial);
		break;
	default:
		break;
	}
}
void USuperMap_MeshComponentInterface::AddMaterialInterface(UMaterialInterface* pMaterial)
{
	USuperMap_MeshComponent* pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
	pMeshCom->AddMaterialInterface(pMaterial);
}
void USuperMap_MeshComponentInterface::RemoveMaterialInterface(UMaterialInterface* pMaterial)
{
	USuperMap_MeshComponent* pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
	pMeshCom->RemoveMaterialInterface(pMaterial);
}
void USuperMap_MeshComponentInterface::GetAllCustomMaterials(TArray<UMaterialInterface*>& arrOutMaterials)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	USuperMap_StaticMeshComponent* pStaticMeshCom = nullptr;
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;
	USuperMap_LineMeshComponent* pLineMeshComponent = nullptr;
	USuperMap_InstancedStaticMeshComponent* pInstancedStaticMeshComponent = nullptr;
	USuperMap_BillboardComponent* pBillboardComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->GetAllCustomMaterials(arrOutMaterials);
		break;;
	case CustomEdgeLineComponent:
		pLineMeshComponent = static_cast<USuperMap_LineMeshComponent*>(m_pMeshComponent);
		arrOutMaterials.Add(pLineMeshComponent->GetCustomMaterial());
		break;;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->GetAllCustomMaterials(arrOutMaterials);
		break;
	case CustomStaticMeshComponent:
		pStaticMeshCom = static_cast<USuperMap_StaticMeshComponent*>(m_pMeshComponent);
		arrOutMaterials.Add(pStaticMeshCom->GetCustomMaterial());
		break;;
	case CustomInstancedStaticMeshComponent:
		pInstancedStaticMeshComponent = static_cast<USuperMap_InstancedStaticMeshComponent*>(m_pMeshComponent);
		arrOutMaterials.Add(pStaticMeshCom->GetCustomMaterial());
		break;;
	case CustomBillboardComponent:
		pBillboardComponent = static_cast<USuperMap_BillboardComponent*>(m_pMeshComponent);
		arrOutMaterials.Add(pBillboardComponent->GetCustomMaterial());
		break;;
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::GetAllSelectionMaterials(TArray<UMaterialInterface*>& arrOutMaterials)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->GetAllSelectionMaterials(arrOutMaterials);
		break;;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->GetAllSelectionMaterials(arrOutMaterials);
		break;
	case CustomEdgeLineComponent:
	case CustomStaticMeshComponent:
	case CustomInstancedStaticMeshComponent:
	case CustomBillboardComponent:
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::GetAllMaterialsInViewport(TArray<UMaterialInterface*>& arrOutMaterials)
{
	if (m_pMeshComponent == nullptr)
	{
		return;
	}
	USuperMap_MeshComponent* pMeshCom = nullptr;
	USuperMap_PolyLineMeshComponent* pPolyLineMeshComponent = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->GetAllMaterialsInViewport(arrOutMaterials);
		break;;
	case CustomPolyLineComponent:
		pPolyLineMeshComponent = static_cast<USuperMap_PolyLineMeshComponent*>(m_pMeshComponent);
		pPolyLineMeshComponent->GetAllMaterialsInViewport(arrOutMaterials);
		break;
	case CustomEdgeLineComponent:
	case CustomStaticMeshComponent:
	case CustomInstancedStaticMeshComponent:
	case CustomBillboardComponent:
	default:
		break;
	}
}

void USuperMap_MeshComponentInterface::SetUseMaterialFlag(UseMaterialFlag enUseMaterialFlag)
{
	m_enUseMaterialFlag = enUseMaterialFlag;

	if (m_pMeshComponent == nullptr)
	{
		return;
	}

	if (m_eComponentType == CustomMeshComponent)
	{
		USuperMap_MeshComponent* pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetUseMaterialFlag(enUseMaterialFlag);
	}
}

void USuperMap_MeshComponentInterface::SetReverseCulling(Gamebool bReverseCulling)
{
	m_bReverseCulling = bReverseCulling;

	if (m_pMeshComponent == nullptr)
	{
		return;
	}
	USuperMap_MeshComponent* pMeshCom = nullptr;

	switch (m_eComponentType)
	{
	case CustomMeshComponent:
		pMeshCom = static_cast<USuperMap_MeshComponent*>(m_pMeshComponent);
		pMeshCom->SetReverseCulling(bReverseCulling);
		break;;
	case CustomEdgeLineComponent:
	case CustomStaticMeshComponent:
	case CustomInstancedStaticMeshComponent:
	case CustomBillboardComponent:
	default:
		break;
	}
}

UseMaterialFlag USuperMap_MeshComponentInterface::GetUseMaterialFlag()
{
	return m_enUseMaterialFlag;
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif