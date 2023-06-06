#pragma once

#include "CoreMinimal.h"
#include "Data/Matrix4d.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameStruct.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK;

//! \brief ��ײ�����������
struct FSMMeshCollisionData
{
public:
	//! \brief ������������
	Gamefloat* m_pPos;
	Gameint m_nPosCount;
	Gameint m_nPosDim;

	//! \brief ������������
	Gameuint* m_pIndex;
	Gameushort* m_pShortIndex;
	Gameint m_nIndexCount;

	// �Ƿ񶥵�ѹ����
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
	//! \brief �������ݰ�
	DataVertex* m_pDataVertex;

	//! \brief ����������
	TArray<DataIndice*> m_arrDataIndex;

	//! \brief �������
	Matrix4d m_matTex;

	//! \brief �����С
	Gameint m_nTextureWidth;
	Gameint m_nTextureHeight;

	//! \brief �����ӹǼ���Ϣƫ����
	Gameint m_nSubMeshInfoOffset;

	Gamebool m_bCopyVertex;

	//! \brief BoundingBox
	GameBoundingBox m_GameBoundingBox;

	//! \brief ʵ�����������
	Gameint m_nIntanceSize;

	//! \brief ÿ��ʵ�����������Ϣ����
	Gameint m_nSizeInFloatPerInstance;

	//! \brief ʵ������Ϣbuffer
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