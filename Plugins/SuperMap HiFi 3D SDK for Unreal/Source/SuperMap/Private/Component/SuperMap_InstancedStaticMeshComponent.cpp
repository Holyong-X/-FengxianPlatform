#include "Component/SuperMap_InstancedStaticMeshComponent.h"
#include "Base3D/CommonDefine.h"
#include "Core/ROCacheManager.h"
#include <map>
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
USuperMap_InstancedStaticMeshComponent::USuperMap_InstancedStaticMeshComponent()
{
	m_bVisible = true;
	m_bVisibleLayer = true;
	m_bUseComplexAsSimpleCollision = true;
	m_bCollision = false;
	m_pMaterial = nullptr;
}

USuperMap_InstancedStaticMeshComponent::~USuperMap_InstancedStaticMeshComponent()
{
	std::map<FString, std::pair<UStaticMesh*, Gameint> > &mapStaticMeshs = ROCacheManager::GetSingleton()->GetStaticMeshs();
	std::map<FString, std::pair<UStaticMesh*, Gameint> >::iterator itor = mapStaticMeshs.find(m_strStaticMeshName);
	if (itor != mapStaticMeshs.end())
	{
		Gameint nRefCount = itor->second.second;

		if (nRefCount == 0)
		{
			mapStaticMeshs.erase(m_strStaticMeshName);
		}
	}
}

Gamevoid USuperMap_InstancedStaticMeshComponent::SetLocalToECEF(const Matrix4d& mat)
{
	m_matLocalToECEF = mat;
}

Matrix4d USuperMap_InstancedStaticMeshComponent::GetLocalToECEF()
{
	return m_matLocalToECEF;
}

Gamevoid USuperMap_InstancedStaticMeshComponent::CreateMesh(const FSMMesh & meshData, Gamebool bCollision)
{
	if (meshData.m_pDataVertex == nullptr)
	{
		return;
	}

	if (meshData.m_nIntanceSize == 0 || meshData.m_pInstanceBuffer == nullptr)
	{
		return;
	}

	// 找到所有的矩阵
	Matrix4d matWorldView = m_matLocalToECEF;
	matWorldView[3][0] *= CM_TO_M;
	matWorldView[3][1] *= CM_TO_M;
	matWorldView[3][2] *= CM_TO_M;

	Gameint nSizeInFloatPerInstance = meshData.m_nSizeInFloatPerInstance;
	Matrix4d mat;
	// 取矩阵
	for (Gameint n = 0; n < meshData.m_nIntanceSize; n++)
	{
		Gamefloat* pValue = (Gamefloat*)meshData.m_pInstanceBuffer + (n * nSizeInFloatPerInstance);

		for (Gameint i = 0; i < 3; i++)
		{
			for (Gameint j = 0; j < 4; j++)
			{
				mat[j][i] = *pValue++;
			}
		}

		Matrix4d matIndent;

		matIndent[0][0] = 0;
		matIndent[1][0] = 1;
		matIndent[1][1] = 0;
		matIndent[0][1] = 1;

		mat = matIndent * mat * matIndent;

		mat = mat * matWorldView;

		m_arrInstanceMatrix.Add(mat);

		mat[3][0] *= M_TO_CM;
		mat[3][1] *= M_TO_CM;
		mat[3][2] *= M_TO_CM;

		FTransform trans;
		Georeference::TransformECEFToUERelative(mat, trans);

		AddInstanceWorldSpace(trans);
	}

	if (meshData.m_pInstanceBuffer != nullptr)
	{
		FMemory::Free(meshData.m_pInstanceBuffer);
	}
}

Gamevoid USuperMap_InstancedStaticMeshComponent::SetName(FName strName)
{
	m_strName = strName;
}

FName USuperMap_InstancedStaticMeshComponent::GetName()
{
	return m_strName;
}

Gamevoid USuperMap_InstancedStaticMeshComponent::SetLayerVisibility(Gamebool bIsVisible)
{
	m_bVisibleLayer = bIsVisible;
	SetVisibility(bIsVisible, false);
}

Gamebool USuperMap_InstancedStaticMeshComponent::GetLayerVisibility()
{
	return m_bVisibleLayer;
}

Gamevoid USuperMap_InstancedStaticMeshComponent::SetInternalVisibility(Gamebool bIsVisible)
{
	m_bVisible = bIsVisible;
	SetVisibility(bIsVisible, false);
}

Gamebool USuperMap_InstancedStaticMeshComponent::GetInternalVisibility()
{
	return m_bVisible;
}

Gamevoid USuperMap_InstancedStaticMeshComponent::SetCustomMaterial(UMaterialInterface* pMat)
{
	m_pMaterial = pMat;
}

UMaterialInterface* USuperMap_InstancedStaticMeshComponent::GetCustomMaterial()
{
	return m_pMaterial;
}

Matrix4d USuperMap_InstancedStaticMeshComponent::GetLocalToWorld()
{
	return m_matDoubleLocalToWorld;
}

Gamevoid USuperMap_InstancedStaticMeshComponent::SetCustomStaticMesh(FString strStaticMeshName, UStaticMesh* pStaticMesh)
{
	SetStaticMesh(pStaticMesh);

	m_strStaticMeshName = strStaticMeshName;
}

Gamevoid USuperMap_InstancedStaticMeshComponent::BatchUpdateTransform(Vector3d vOffset)
{
	ClearInstances();
	Gameint nCount = m_arrInstanceMatrix.Num();
	for (Gameint n = 0; n < nCount; n++ )
	{
		Matrix4d mat = m_arrInstanceMatrix[n];
		
		mat[3][0] *= M_TO_CM;
		mat[3][1] *= M_TO_CM;
		mat[3][2] *= M_TO_CM;

		FTransform trans;
		Georeference::TransformECEFToUERelative(mat, trans);

		AddInstanceWorldSpace(trans);
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif