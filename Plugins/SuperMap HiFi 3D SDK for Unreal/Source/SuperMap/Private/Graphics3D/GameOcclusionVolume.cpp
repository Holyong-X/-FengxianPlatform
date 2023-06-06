#include "Graphics3D/GameOcclusionVolume.h"
#include "Graphics3D/GameObjectManager.h"
namespace SuperMapSDK
{
	GameOcclusionVolume::GameOcclusionVolume(Gamelong nIDName, USuperMap_OcclusionVolumeComponent* pComponent)
	{
		m_nIDName = nIDName;
		m_pOcclusionVolumeComponent = pComponent;
	}

	GameOcclusionVolume::~GameOcclusionVolume()
	{

	}

	void GameOcclusionVolume::InitializeCallbackHandle()
	{
		CreateOcclusionVolumeFunction createOcclusionVolume = CreateOcclusionVolume;
	}

	void GameOcclusionVolume::SetBBox(FBox& box)
	{
		if (m_pOcclusionVolumeComponent)
		{
			m_pOcclusionVolumeComponent->SetBoundingBox(box);
		}
	}

	Gamevoid SetOVBoundingBox(Gamevoid* pOcclusionVolumeHandle, Gamevoid* pBoundBox)
	{
		GameOcclusionVolume* pOcclusionVolume = (GameOcclusionVolume*)pOcclusionVolumeHandle;
		if (pOcclusionVolume)
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

			FVector vMin = FVector(boundBox.m_vMin.x, boundBox.m_vMin.y, boundBox.m_vMin.z);
			FVector vMax = FVector(boundBox.m_vMax.x, boundBox.m_vMax.y, boundBox.m_vMax.z);
			
			FBox box(vMin, vMax);
			pOcclusionVolume->SetBBox(box);
		}
	}

	Gamelong GameOcclusionVolume::GetIDName()
	{
		return m_nIDName;
	}

	Gamevoid* CreateOcclusionVolume(Gamelong strIDName)
	{
		
		return GameObjectManager::GetSingleton()->CreateOcclusionVolume(strIDName);
	}

	Gamevoid DestroyOcclusionVolume(Gamevoid* pOcclusionVolumeHandle)
	{
		return GameObjectManager::GetSingleton()->DestroyOcclusionVolume(pOcclusionVolumeHandle);
	}
}