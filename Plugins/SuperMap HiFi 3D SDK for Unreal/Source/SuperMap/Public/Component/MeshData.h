#pragma once

#include "CoreMinimal.h"
#include "Data/Matrix4d.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameStruct.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK;

//! \brief 碰撞检测网格数据
struct FSMMeshCollisionData
{
public:
	//! \brief 顶点坐标数据
	Gamefloat* m_pPos;
	Gameint m_nPosCount;
	Gameint m_nPosDim;

	//! \brief 顶点索引数据
	Gameuint* m_pIndex;
	Gameushort* m_pShortIndex;
	Gameint m_nIndexCount;

	// 是否顶点压缩了
	Gamebool m_bCompressed;

	FSMMeshCollisionData()
	{
		m_pPos = nullptr;
		m_nPosCount = 0;
		m_nPosDim = 3;

		m_pIndex = nullptr;
		m_pShortIndex = nullptr;
		m_nIndexCount = 0;
		m_bCompressed = false;
	}

	~FSMMeshCollisionData()
	{
		if (m_pPos != nullptr)
		{
			FMemory::Free(m_pPos);
			m_pPos = nullptr;
		}

		if (m_pIndex != nullptr)
		{
			FMemory::Free(m_pIndex);
			m_pIndex = nullptr;
		}

		if (m_pShortIndex != nullptr)
		{
			FMemory::Free(m_pShortIndex);
			m_pShortIndex = nullptr;
		}

		m_nPosCount = 0;
		m_nPosDim = 3;
		m_nIndexCount = 0;
	}

	Gamebool IsValid()
	{
		if (m_pPos == nullptr || (m_pIndex == nullptr && m_pShortIndex == nullptr))
		{
			return false;
		}
		// TODO
		if (m_bCompressed)
		{
			return false;
		}
		return true;
	}
};

struct FSMMesh
{
	//! \brief 顶点数据包
	DataVertex* m_pDataVertex;

	//! \brief 顶点索引包
	TArray<DataIndice*> m_arrDataIndex;

	//! \brief 纹理矩阵
	Matrix4d m_matTex;

	//! \brief 纹理大小
	Gameint m_nTextureWidth;
	Gameint m_nTextureHeight;

	//! \brief 更新子骨架信息偏移量
	Gameint m_nSubMeshInfoOffset;

	Gamebool m_bCopyVertex;

	//! \brief BoundingBox
	GameBoundingBox m_GameBoundingBox;

	//! \brief 实例化对象个数
	Gameint m_nIntanceSize;

	//! \brief 每个实例化对象的信息长度
	Gameint m_nSizeInFloatPerInstance;

	//! \brief 实例化信息buffer
	Gamevoid* m_pInstanceBuffer;

public:

	FSMMesh()
	{
		m_pDataVertex = nullptr;
		m_nTextureWidth = 0;
		m_nTextureHeight = 0;
		m_nSubMeshInfoOffset = 0;
		m_bCopyVertex = false;
		m_nIntanceSize = 0;
		m_nSizeInFloatPerInstance = 0;
		m_pInstanceBuffer = nullptr;
	}

	Gamebool isValid()
	{
		if (m_pDataVertex == nullptr || m_arrDataIndex.Num() == 0)
		{
			return false;
		}

		return true;
	}

	const Gamebool isValid() const
	{
		if (m_pDataVertex == nullptr || m_arrDataIndex.Num() == 0)
		{
			return false;
		}

		return true;
	}
};