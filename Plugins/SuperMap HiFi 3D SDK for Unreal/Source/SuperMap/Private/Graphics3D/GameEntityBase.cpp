#include "Graphics3D/GameEntityBase.h"

namespace SuperMapSDK
{
	GameEntityBase::GameEntityBase()
	{
		m_pDataVertex = nullptr;
		m_nParentSceneNodeName = 0;
		m_pGameComponent = nullptr;
		m_bInitialGPU = false;
		m_bUpdateGPU = true;
		m_bCanAsync = false;
		m_nEntityName = 0;
	}

	GameEntityBase::~GameEntityBase()
	{
		if (m_pDataVertex != nullptr)
		{
			delete m_pDataVertex;
			m_pDataVertex = nullptr;
		}

		if (m_arrDataIndices.Num() > 0)
		{
			for (Gameint n = 0; n < m_arrDataIndices.Num(); n++)
			{
				DataIndice* pDataIndice = m_arrDataIndices[n];
				if (pDataIndice != nullptr)
				{
					delete pDataIndice;
					pDataIndice = nullptr;
				}
			}
					
			m_arrDataIndices.Empty();
		}

		m_pGameComponent = nullptr;
	}

	void GameEntityBase::SetDataVertexPackage(DataVertex* pDataVertex)
	{
		m_pDataVertex = pDataVertex;
	}

	DataVertex* GameEntityBase::GetDataVertexPackage()
	{
		return m_pDataVertex;
	}

	void GameEntityBase::SetEntityName(Gamelong nEntityName)
	{
		m_nEntityName = nEntityName;
	}

	Gamelong GameEntityBase::GetEntityName()
	{
		return m_nEntityName;
	}

	Gamelong GameEntityBase::GetSceneNodeName()
	{
		return m_nParentSceneNodeName;
	}

	void GameEntityBase::SetSceneNodeName(Gamelong nSceneNodeHandle)
	{
		m_nParentSceneNodeName = nSceneNodeHandle;
	}

	void GameEntityBase::SetGameComponent(GameComponent* pGameComponent)
	{
		m_pGameComponent = pGameComponent;
	}

	GameComponent* GameEntityBase::GetGameComponent()
	{
		return m_pGameComponent;
	}

	void GameEntityBase::AddIndexPackage(DataIndice* pDataIndice)
	{
		m_arrDataIndices.Add(pDataIndice);
	}

	void GameEntityBase::SetIndexPackages(TArray<DataIndice*>& arrDataIndices)
	{
		Gameint nCount = arrDataIndices.Num();
		for (Gameint n = 0; n < nCount; n++)
		{
			m_arrDataIndices[n] = arrDataIndices[n];
		}
	}

	DataIndice* GameEntityBase::GetIndexPackageByIndex(Gameint nIndex)
	{
		if (nIndex < 0 || (m_arrDataIndices.Num()-1) < nIndex)
		{
			return nullptr;
		}

		return m_arrDataIndices[nIndex];
	}

	void GameEntityBase::SetIndexPackageByIndex(Gameint nIndex, DataIndice* pDataIndice)
	{
		if (nIndex < 0 || (m_arrDataIndices.Num() - 1) < nIndex)
		{
			return;
		}

		m_arrDataIndices[nIndex] = pDataIndice;
	}

	TArray<DataIndice*>& GameEntityBase::GetIndexPackages()
	{
		return m_arrDataIndices;
	}

	Gameint GameEntityBase::GetIndexPackageCount()
	{
		return m_arrDataIndices.Num();
	}

	void GameEntityBase::RemoveIndexPackage(Gameint nIndex, Gameint nCount)
	{
		Gameint nSize = nIndex + nCount;
		if (nSize > m_arrDataIndices.Num())
		{
			return;
		}
		for (Gameint n = nIndex; n < nSize; n++)
		{
			DataIndice* pDataIndice = m_arrDataIndices[n];
			if (pDataIndice != nullptr)
			{
				delete pDataIndice;
				pDataIndice = nullptr;
			}
		}

		m_arrDataIndices.RemoveAt(nIndex, nCount);
	}

	Gamebool GameEntityBase::IsValid()
	{
		if (m_pDataVertex == nullptr 
			|| m_pDataVertex->m_nPosCount == 0
			|| m_arrDataIndices.Num() == 0)
		{
			return false;
		}

		return true;
	}

	void GameEntityBase::SetBBox(GameBoundingBox& box)
	{
		m_GameBoundingBox.m_vMin = box.m_vMin;
		m_GameBoundingBox.m_vMax = box.m_vMax;
	}

	GameBoundingBox GameEntityBase::GetBBox()
	{
		return m_GameBoundingBox;
	}

	void GameEntityBase::SetIsInitialGPU(Gamebool bInitialGPU)
	{
		m_bInitialGPU = bInitialGPU;
	}

	Gamebool GameEntityBase::IsInitialGPU()
	{
		return m_bInitialGPU;
	}

	//! \brief 设置是否初始化
	void GameEntityBase::SetIsUpdateGPU(Gamebool bUpdateGPU)
	{
		m_bUpdateGPU = bUpdateGPU;
	}

	//! \brief 获取是否初始化
	Gamebool GameEntityBase::IsUpdateGPU()
	{
		return m_bUpdateGPU;
	}

	void GameEntityBase::SetCanAsync(Gamebool bCanAsync)
	{
		m_bCanAsync = bCanAsync;
	}

	Gamebool GameEntityBase::IsCanAsync()
	{
		return m_bCanAsync;
	}

	EntityType GameEntityBase::Type()
	{
		return ET_NONE;
	}
}