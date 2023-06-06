#include "Graphics3D/GameStruct.h"
#include "Graphics3D/GameConvertor.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Core;

namespace SuperMapSDK
{
	void VertexAttribute::Release(bool bUseUGCMem)
	{
		m_nVertexAttDataCount = 0;
		m_nVertexAttDataDimension = 0;
		if (m_pVertexAttData != nullptr)
		{
			if (bUseUGCMem)
			{
				float* pFloat = (float*)m_pVertexAttData;
				_FreeUGFloat(pFloat);
			}
			else
			{
				FMemory::Free(m_pVertexAttData);
			}
		}
		m_pVertexAttData = nullptr;
	}

	void VertexAttribute::Init(GameDataVertexPackage*& pGameDataVertex, int nIndex)
	{
		if (pGameDataVertex->m_vecVertexAttData[nIndex] == nullptr)
		{
			m_pVertexAttData = nullptr;
			return;
		}
		m_nVertexAttDataCount = pGameDataVertex->m_vecVertexAttDataCount[nIndex];
		m_nVertexAttDataDimension = pGameDataVertex->m_vecVertexAttDataDimension[nIndex];
		VertexAttributeType vType = (VertexAttributeType)pGameDataVertex->m_vecVertexAttDataType[nIndex];
		m_enVertexAttDataType = vType;
		if (pGameDataVertex->m_bCanBeReleased)
		{
			m_pVertexAttData = pGameDataVertex->m_vecVertexAttData[nIndex];
			pGameDataVertex->m_vecVertexAttData[nIndex] = nullptr;
		}
		else
		{
			uint32 nValueByteSize = GameConvertor::GetByteSizeByVertexAttributeType(vType);
			uint32 byteSize = m_nVertexAttDataCount * m_nVertexAttDataDimension * nValueByteSize;
			m_pVertexAttData = FMemory::Malloc(byteSize);
			FMemory::Memcpy(m_pVertexAttData, pGameDataVertex->m_vecVertexAttData[nIndex], byteSize);
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	DataVertex::~DataVertex()
	{
		if (m_Pos != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGFloat(m_Pos);
			}
			else
			{
				FMemory::Free(m_Pos);
			}
			m_Pos = nullptr;
		}

		if (m_Normal != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGFloat(m_Normal);
			}
			else
			{
				FMemory::Free(m_Normal);
			}
			m_Normal = nullptr;
		}

		if (m_Tangent != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGFloat(m_Tangent);
			}
			else
			{
				FMemory::Free(m_Tangent);
			}
			m_Tangent = nullptr;
		}

		if (m_PosColor != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGUint(m_PosColor);
			}
			else
			{
				FMemory::Free(m_PosColor);
			}
			m_PosColor = nullptr;
		}

		if (m_PosSceondColor != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGUint(m_PosSceondColor);
			}
			else
			{
				FMemory::Free(m_PosSceondColor);
			}
			m_PosSceondColor = nullptr;
		}

		if (m_TexCoord != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGFloat(m_TexCoord);
			}
			else
			{
				FMemory::Free(m_TexCoord);
			}
			m_TexCoord = nullptr;
		}

		if (m_TexCoord1 != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGFloat(m_TexCoord1);
			}
			else
			{
				FMemory::Free(m_TexCoord1);
			}
			m_TexCoord1 = nullptr;
		}

		if (m_TexCoord2 != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGFloat(m_TexCoord2);
			}
			else
			{
				FMemory::Free(m_TexCoord2);
			}
			m_TexCoord2 = nullptr;
		}

		if (m_TexCoord3 != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGFloat(m_TexCoord3);
			}
			else
			{
				FMemory::Free(m_TexCoord3);
			}
			m_TexCoord3 = nullptr;
		}

		
		for (int i = 0; i < m_vecVertexAttribute.Num(); i++)
		{
			m_vecVertexAttribute[i].Release(m_bUGMemory);
		}
	}

	DataVertex* DataVertex::Copy()
	{
		DataVertex* pDataVertex = new DataVertex();

		pDataVertex->m_bUGMemory = false;
		// 顶点
		pDataVertex->m_nPosCount = m_nPosCount;
		pDataVertex->m_nPosDim = m_nPosDim;
		pDataVertex->m_Pos = nullptr;
		if (m_Pos != nullptr)
		{
			pDataVertex->m_Pos = (Gamefloat*)FMemory::Malloc(sizeof(Gamefloat) * m_nPosCount * m_nPosDim);
			memcpy(pDataVertex->m_Pos, m_Pos, sizeof(Gamefloat) * m_nPosCount * m_nPosDim);
		}


		// 法线
		pDataVertex->m_nNormalCount = m_nNormalCount;
		pDataVertex->m_nNormalDim = m_nNormalDim;
		pDataVertex->m_Normal = nullptr;
		if (m_Normal != nullptr)
		{
			pDataVertex->m_Normal = (Gamefloat*)FMemory::Malloc(sizeof(Gamefloat) * m_nNormalCount * m_nNormalDim);
			memcpy(pDataVertex->m_Normal, m_Normal, sizeof(Gamefloat) * m_nNormalCount * m_nNormalDim);
		}


		// 顶点颜色
		pDataVertex->m_nColorCount = m_nColorCount;
		pDataVertex->m_PosColor = nullptr;
		if (m_PosColor != nullptr)
		{
			pDataVertex->m_PosColor = (Gameuint*)FMemory::Malloc(sizeof(Gameuint) * m_nColorCount);
			memcpy(pDataVertex->m_PosColor, m_PosColor, sizeof(Gameuint) * m_nColorCount);
		}


		// SecondColor
		pDataVertex->m_nSecondColorCount = m_nSecondColorCount;
		pDataVertex->m_PosSceondColor = nullptr;
		if (m_PosSceondColor != nullptr)
		{
			pDataVertex->m_PosSceondColor = (Gameuint*)FMemory::Malloc(sizeof(Gameuint) * m_nSecondColorCount);
			memcpy(pDataVertex->m_PosSceondColor, m_PosSceondColor, sizeof(Gameuint) * m_nSecondColorCount);
		}


		// 纹理坐标(先只考虑一层纹理)
		pDataVertex->m_nTexCoordCount = m_nTexCoordCount;
		pDataVertex->m_nTexCoordDim = m_nTexCoordDim;
		pDataVertex->m_TexCoord = nullptr;
		if (m_TexCoord != nullptr)
		{
			pDataVertex->m_TexCoord = (Gamefloat*)FMemory::Malloc(sizeof(Gamefloat) * m_nTexCoordCount * m_nTexCoordDim);
			memcpy(pDataVertex->m_TexCoord, m_TexCoord, sizeof(Gamefloat) * m_nTexCoordCount * m_nTexCoordDim);
		}


		// 纹理坐标
		pDataVertex->m_nTexCoordCount1 = m_nTexCoordCount1;
		pDataVertex->m_nTexCoordDim1 = m_nTexCoordDim1;
		pDataVertex->m_TexCoord1 = nullptr;
		if (m_TexCoord1 != nullptr)
		{
			pDataVertex->m_TexCoord1 = (Gamefloat*)FMemory::Malloc(sizeof(Gamefloat) * m_nTexCoordCount1 * m_nTexCoordDim1);
			memcpy(pDataVertex->m_TexCoord1, m_TexCoord1, sizeof(float) * m_nTexCoordCount1 * m_nTexCoordDim1);
		}


		//-------实例化信息------------
		pDataVertex->m_nTexCoordCount2 = m_nTexCoordCount2;
		pDataVertex->m_nTexCoordDim2 = m_nTexCoordDim2;
		pDataVertex->m_TexCoord2 = nullptr;
		if (m_TexCoord2 != nullptr)
		{
			pDataVertex->m_TexCoord2 = (Gamefloat*)FMemory::Malloc(sizeof(Gamefloat) * m_nTexCoordCount2 * m_nTexCoordDim2);
			memcpy(pDataVertex->m_TexCoord2, m_TexCoord2, sizeof(float) * m_nTexCoordCount2 * m_nTexCoordDim2);
		}

		pDataVertex->m_nTexCoordCount3 = m_nTexCoordCount3;
		pDataVertex->m_nTexCoordDim3 = m_nTexCoordDim3;
		pDataVertex->m_TexCoord3 = nullptr;
		if (m_TexCoord3 != nullptr)
		{
			pDataVertex->m_TexCoord3 = (Gamefloat*)FMemory::Malloc(sizeof(Gamefloat) * m_nTexCoordCount3 * m_nTexCoordDim3);
			memcpy(pDataVertex->m_TexCoord3, m_TexCoord3, sizeof(float) * m_nTexCoordCount3 * m_nTexCoordDim3);
		}

		//-----------------------------

		// 模型变换矩阵
		pDataVertex->m_ObjectMat = (Gamefloat*)FMemory::Malloc(sizeof(Gamefloat) * 16);
		memcpy(pDataVertex->m_ObjectMat, m_ObjectMat, sizeof(Gamefloat) * 16);

		// 高精度模型矩阵
		pDataVertex->m_doubleObjectMat = (Gamedouble*)FMemory::Malloc(sizeof(Gamedouble) * 16);
		memcpy(pDataVertex->m_doubleObjectMat, m_doubleObjectMat, sizeof(Gamedouble) * 16);

		//------------------------------
		// 压缩
		pDataVertex->m_nCompressType = m_nCompressType;

		// 压缩
		pDataVertex->m_fVertCompressConstant = m_fVertCompressConstant;

		//------------------------------

		//! \brief 顶点混合权重,目前当做BatchID使用，前端设置，并不存储到数据中
		pDataVertex->m_pBlendWeights = nullptr;
		pDataVertex->m_nBlendWeightsCount = m_nBlendWeightsCount;

		return pDataVertex;
	}

	int DataVertex::GetIndexOfTexMatrixInVertexAttData()
	{
		if (m_vecVertexAttribute.Num() == 0)
		{
			return -1;
		}
		// 第一个自定义属性存的w位，如果没存w位则第一个存的就是纹理矩阵
		if (m_bHasVertexWeight)
		{
			return m_vecVertexAttribute.Num() > 1 ? 1 : -1;
		}
		else
		{
			return m_vecVertexAttribute.Num() > 0 ? 0 : -1;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	DataIndice::~DataIndice() 
	{
		if (m_Index != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGUint(m_Index);
			}
			else
			{
				FMemory::Free(m_Index);
			}
			m_Index = nullptr;
		}

		if (m_shortIndex != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUGUshort(m_shortIndex);
			}
			else
			{
				FMemory::Free(m_shortIndex);
			}
			m_shortIndex = nullptr;
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	GamePBRMetallicRough::GamePBRMetallicRough()
	{

	}

	GamePBRMetallicRough::GamePBRMetallicRough(const GamePBRMetallicRough& other)
	{
		m_vec4BaseColor = other.m_vec4BaseColor;
		m_nBaseColorTextureIndex = other.m_nBaseColorTextureIndex;
		m_nBaseColorTextureCoordIndex = other.m_nBaseColorTextureCoordIndex;
		m_BaseColorTextureMotion = other.m_BaseColorTextureMotion;
		m_nMetallicRoughnessTextureIndex = other.m_nMetallicRoughnessTextureIndex;
		m_nMetallicRoughnessTextureCoordIndex = other.m_nMetallicRoughnessTextureCoordIndex;
		m_fMetallicFactor = other.m_fMetallicFactor;
		m_fRoughnessFactor = other.m_fRoughnessFactor;
	}

	GamePBRMetallicRough::~GamePBRMetallicRough()
	{

	}

	GamePBRSpecularGlossy::GamePBRSpecularGlossy()
	{

	}

	GamePBRSpecularGlossy::~GamePBRSpecularGlossy()
	{

	}

	GamePBRParam::GamePBRParam()
	{
		m_pPBRMetallicRough = nullptr;
		m_pPBRSpecularGlossy = nullptr;
	}

	GamePBRParam::GamePBRParam(const GamePBRParam& other)
	{
		m_vec3EmissiveFactor = other.m_vec3EmissiveFactor;
		m_nEmissiveTextureIndex = other.m_nEmissiveTextureIndex;
		m_nEmissiveTextureCoordIndex = other.m_nEmissiveTextureCoordIndex;
		m_EmissiveTextureMotion = other.m_EmissiveTextureMotion;
		m_nNormalTextureIndex = other.m_nNormalTextureIndex;
		m_nNormalTextureCoordIndex = other.m_nNormalTextureCoordIndex;
		m_fNormalTextureScale = other.m_fNormalTextureScale;
		m_nOcclusionTextureIndex = other.m_nOcclusionTextureIndex;
		m_nOcclusionTextureCoordIndex = other.m_nOcclusionTextureCoordIndex;
		m_fOcclusionTextureStrength = other.m_fOcclusionTextureStrength;
		m_AlphaMode = other.m_AlphaMode;
		m_fAlphaCutoff = other.m_fAlphaCutoff;
		m_bDoubleSided = other.m_bDoubleSided;
		m_nMaskTextureIndex = other.m_nMaskTextureIndex;
		m_nMaskTextureCoordIndex = other.m_nMaskTextureCoordIndex;
		m_pPBRMetallicRough = nullptr;
		if (other.m_pPBRMetallicRough != nullptr)
		{
			m_pPBRMetallicRough = new GamePBRMetallicRough(*(other.m_pPBRMetallicRough));
		}
		m_pPBRSpecularGlossy = nullptr;//暂不支持
	}

	GamePBRParam::~GamePBRParam()
	{
		if (m_pPBRMetallicRough != nullptr)
		{
			delete m_pPBRMetallicRough;
			m_pPBRMetallicRough = nullptr;
		}
	}

	GameMaterialParam::GameMaterialParam()
	{
		m_strMaterialName = nullptr;
		m_strShaderName = nullptr;
		m_pTextureNames = nullptr;
		m_pTexTransforms = nullptr;
		m_pPBRParam = nullptr;
	}

	GameMaterialParam::~GameMaterialParam()
	{
		if (m_strShaderName != nullptr)
		{
			_FreeByte(m_strShaderName);
		}

		if (m_strMaterialName != nullptr)
		{
			_FreeByte(m_strMaterialName);
		}

		if (m_pTexTransforms != nullptr)
		{
			_FreeDoubleArray(m_pTexTransforms, m_nTextureCount);
		}

		if (m_pTextureNames != nullptr)
		{
			_FreeLong(m_pTextureNames);
		}

		if (m_setMacro != nullptr)
		{
			_FreeCharPointerArray(m_setMacro, m_nMacroCount);
			m_setMacro = nullptr;
		}

		if (m_pPBRParam != nullptr)
		{
			delete m_pPBRParam;
			m_pPBRParam = nullptr;
		}
	}

	void GameMaterialParam::Copy(GameMaterialParam* pMaterialParam)
	{
		m_nMaterialName = pMaterialParam->m_nMaterialName;
		m_strShaderName = pMaterialParam->m_strShaderName;
		pMaterialParam->m_strShaderName = nullptr;
		m_strMaterialName = pMaterialParam->m_strMaterialName;
		pMaterialParam->m_strMaterialName = nullptr;
		m_nTextureCount = pMaterialParam->m_nTextureCount;
		m_pTextureNames = pMaterialParam->m_pTextureNames;
		pMaterialParam->m_pTextureNames = nullptr;
		m_pTexTransforms = pMaterialParam->m_pTexTransforms;
		pMaterialParam->m_pTexTransforms = nullptr;
		m_nDataType = pMaterialParam->m_nDataType;
		m_nBatchTextureIndex = pMaterialParam->m_nBatchTextureIndex;
		m_diffuse = pMaterialParam->m_diffuse;
		m_pPBRParam = nullptr;
		if (pMaterialParam->m_pPBRParam != nullptr)
		{
			m_pPBRParam = new GamePBRParam(*pMaterialParam->m_pPBRParam);
		}
		m_setMacro = pMaterialParam->m_setMacro;
		pMaterialParam->m_setMacro = nullptr;
		m_nMacroCount = pMaterialParam->m_nMacroCount;
		m_nState = pMaterialParam->m_nState;
		m_eCullingMode = pMaterialParam->m_eCullingMode;
	}

	GameDataVertexPackage::GameDataVertexPackage()
	{

	}

	GameDataVertexPackage::~GameDataVertexPackage()
	{

	}

	GameIndexPackage::GameIndexPackage()
	{

	}

	GameIndexPackage::~GameIndexPackage()
	{

	}

	GameBoundingBox::GameBoundingBox()
	{
		m_vMin.x = 0.0f;
		m_vMin.y = 0.0f;
		m_vMin.z = 0.0f;

		m_vMax.x = 0.0f;
		m_vMax.y = 0.0f;
		m_vMax.z = 0.0f;

	}

	GameBoundingBox::~GameBoundingBox()
	{

	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	GameTexture2DInfo::GameTexture2DInfo() :
		m_nOffsetX(0),
		m_nOffsetY(0),
		m_nWidth(0),
		m_nHeight(0),
		m_nSizeInByte(0),
		m_pByte(nullptr),
		m_nFormat(0),
		m_nEPixelFormat(PF_Unknown),
		m_nCompressType(0),
		m_bUGMemory(false),
		m_bSRGB(true)
	{
	}

	GameTexture2DInfo::~GameTexture2DInfo()
	{
		if (m_pByte != nullptr)
		{
			if (m_bUGMemory)
			{
				_FreeUChar(m_pByte);
			}
			else
			{
				FMemory::Free(m_pByte);
			}
		}
		m_pByte = nullptr;
		
	}

	void GameTexture2DInfo::SetTextureData(Gameuchar*& pByte, Gameuint nSizeInByte, bool bCopy)
	{
		if (bCopy)
		{
			if (nSizeInByte > 0)
			{
				Gameuint8* pDataBuffer = (Gameuint8*)FMemory::Malloc(nSizeInByte);
				FMemory::Memcpy(pDataBuffer, pByte, nSizeInByte);
				m_pByte = pDataBuffer;
			}
		}
		else
		{
			m_pByte = pByte;
			pByte = nullptr;
		}
	}
}