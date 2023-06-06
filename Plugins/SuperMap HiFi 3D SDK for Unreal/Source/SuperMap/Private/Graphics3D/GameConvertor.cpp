#include "Graphics3D/GameConvertor.h"
#include "Graphics3D/GameEnum.h"
#include "RenderCore/Public/RenderUtils.h"
#include "Engine/Texture2D.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Core;

namespace SuperMapSDK
{
	GameConvertor::GameConvertor()
	{

	}

	GameConvertor::~GameConvertor()
	{

	}

	EPixelFormat GameConvertor::ToEPixelFormat(Gameint nPixelFormat, Gameint nCompressType)
	{
		UGPixelFormat ePixelFormat = (UGPixelFormat)nPixelFormat;
		UGCodecType eCompressType = (UGCodecType)nCompressType;

		EPixelFormat eTextureFormat = EPixelFormat::PF_DXT5;

		int comp = 3;
		if (UGPixelFormat::UGC_PF_B8G8R8 != ePixelFormat && UGPixelFormat::UGC_PF_R8G8B8 != ePixelFormat)
		{
			comp = 4;
		}

		if (UGPixelFormat::UGC_PF_FLOAT32_RGBA == ePixelFormat)
		{
			comp = 4;
		}

		if (UGPixelFormat::UGC_PF_FLOAT32_RGBA == ePixelFormat)
		{
			eTextureFormat = EPixelFormat::PF_A32B32G32R32F;
		}
		else if (eCompressType == UGCodecType::encNONE)
		{
			//! \brief UE的格式要有Alpha通道
			switch (ePixelFormat)
			{
			case UGPixelFormat::UGC_PF_BYTE_BGRA:
				eTextureFormat = EPixelFormat::PF_B8G8R8A8;
				break;
			case UGPixelFormat::UGC_PF_BYTE_RGBA:
				eTextureFormat = EPixelFormat::PF_R8G8B8A8;
				break;
			case UGPixelFormat::UGC_PF_BYTE_BGR:
				eTextureFormat = EPixelFormat::PF_B8G8R8A8;
				break;
			case UGPixelFormat::UGC_PF_BYTE_RGB:
				eTextureFormat = EPixelFormat::PF_R8G8B8A8;
				break;
			default:
				eTextureFormat = EPixelFormat::PF_R8G8B8A8;
				break;
			}
		}
		else if (eCompressType == UGCodecType::enrS3TCDXTN)
		{
			eTextureFormat = (comp == 3 ? EPixelFormat::PF_DXT1 : EPixelFormat::PF_DXT5);
		}
		return eTextureFormat;
	}

	PixelFormat GameConvertor::ToPixelFormat(Gameint nFormat)
	{
		switch (nFormat)
		{
		case 0:
			break;
		case 1:
			break;
		case 32:
			return IPF_RGBA;
		case 3200:
			return IPF_FLOAT;
		default:
			break;
		}

		return IPF_UNKNOWN;
	}

	Gameint GameConvertor::CalTextureSize(Gameint nWidth, Gameint nHeight, Gameint nPixelFormat, EPixelFormat ePixelFormat)
	{
		Gameint nBlockSizeX = 0;
		Gameint nBlockSizeY = 0;
		Gameint nBlockBytes = 0;

		UGPixelFormat eUGPixelFormat = (UGPixelFormat)nPixelFormat;

		if (ePixelFormat == EPixelFormat::PF_DXT1 || ePixelFormat == EPixelFormat::PF_DXT5)
		{
			nBlockSizeX = 4; nBlockSizeY = 4;
			nBlockBytes = 8;
			if (ePixelFormat == EPixelFormat::PF_DXT5)
			{
				nBlockBytes = 16;
			}
		}
		else if (eUGPixelFormat == UGPixelFormat::UGC_PF_FLOAT32_RGBA)
		{
			nBlockSizeX = 1; nBlockSizeY = 1;
			nBlockBytes = 16;
		}
		else if (eUGPixelFormat == UGPixelFormat::UGC_PF_BYTE_BGR || eUGPixelFormat == UGPixelFormat::UGC_PF_BYTE_BGRA ||
				 eUGPixelFormat == UGPixelFormat::UGC_PF_BYTE_RGB || eUGPixelFormat == UGPixelFormat::UGC_PF_BYTE_RGBA)
		{
			nBlockSizeX = 1; nBlockSizeY = 1;
			nBlockBytes = 4;
		}

		int nNumBlocksX = nWidth / nBlockSizeX;
		int nNumBlocksY = nHeight / nBlockSizeY;

		nNumBlocksX = (nNumBlocksX == 0 ? nNumBlocksX + 1 : nNumBlocksX);
		nNumBlocksY = (nNumBlocksY == 0 ? nNumBlocksY + 1 : nNumBlocksY);

		int nTexSize = (nNumBlocksX * nNumBlocksY * nBlockBytes);

		return nTexSize;
	}

	void GameConvertor::CalMipMap(Gameint nWidth, Gameint nHeight, Gameint nTextureSize,
		Gameint nPixelFormat, EPixelFormat ePixelFormat,
		TMap<Gameint, Gameint>& mapMipMaps)
	{
		Gameint nBlockSizeX = GPixelFormats[ePixelFormat].BlockSizeX;
		Gameint nBlockSizeY = GPixelFormats[ePixelFormat].BlockSizeY;
		Gameint nBlockBytes = GPixelFormats[ePixelFormat].BlockBytes;
		Gameint nMipmapLevel = 0;
		Gameint nTotalTexSize = 0;
		while (true)
		{
			if ((nWidth % nBlockSizeX) != 0 || (nHeight % nBlockSizeY) != 0)
			{
				break;
			}

			int nTexSize = CalTextureSize(nWidth, nHeight, nPixelFormat, ePixelFormat);

			mapMipMaps.Add(nMipmapLevel, nTexSize);

			nTotalTexSize += nTexSize;

			if (nTotalTexSize == nTextureSize)
			{
				break;
			}

			nWidth /= 2;
			nHeight /= 2;

			if (nWidth == 0 || nHeight == 0)
			{
				break;
			}

			nMipmapLevel++;
		}
	}

	void GameConvertor::UpdateTextureRegion(UTexture2D* pTex2D, GameTexture2DInfo& textureInfo, Gameint nOffset, Gamebool bIsData,
		Gameint nNum, Gameint nMipIndex)
	{
		UGFREE_UCHAR freeUchar = _FreeUChar;
		FUpdateTextureRegion2D* pRegion2D = new FUpdateTextureRegion2D;

		pRegion2D->DestX = textureInfo.m_nOffsetX;
		pRegion2D->DestY = textureInfo.m_nOffsetY;

		pRegion2D->SrcX = 0;
		pRegion2D->SrcY = 0;

		pRegion2D->Width = textureInfo.m_nWidth;
		pRegion2D->Height = textureInfo.m_nHeight;

		EPixelFormat ePixelFormat = pTex2D->GetPixelFormat();

		Gameint BlockSizeX = GPixelFormats[ePixelFormat].BlockSizeX;
		Gameint BlockSizeY = GPixelFormats[ePixelFormat].BlockSizeY;
		Gameint BlockBytes = GPixelFormats[ePixelFormat].BlockBytes;

		Gameint nTexWidth = pTex2D->GetSizeX();
		Gameint nTemp = textureInfo.m_nWidth + textureInfo.m_nOffsetX;
		if (nTemp > nTexWidth)
		{
			FMemory::Free(textureInfo.m_pByte);
			delete pRegion2D;
			return;
		}

		pTex2D->UpdateTextureRegions(nMipIndex, 1, pRegion2D, BlockBytes * (pRegion2D->Width / BlockSizeX), BlockBytes, textureInfo.m_pByte + nOffset, [nNum, freeUchar, bIsData, nOffset](auto InTextureData, auto InRegions)
			{
				FMemory::Free(InTextureData - nOffset);
				delete InRegions;
			});
	}

	void GameConvertor::PosToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nPosCount = pGameDataVertex->m_nPosCount;
		pDataVertex->m_nPosDim = pGameDataVertex->m_nPosDim;
		pDataVertex->m_Pos = nullptr;

		if (pGameDataVertex->m_Pos != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_Pos = pGameDataVertex->m_Pos;
				pGameDataVertex->m_Pos = nullptr;
			}
			else
			{
				bool compress = GameConvertor::HasCompressOptions(pGameDataVertex->m_nCompressType, VertexCompressOptions::SVC_Vertex);
				uint32 nValueBytes = compress ? sizeof(Gameushort) : sizeof(Gamefloat);
				Gameuint nPosSize = pDataVertex->m_nPosDim * pDataVertex->m_nPosCount;
				pDataVertex->m_Pos = (Gamefloat*)FMemory::Malloc(nPosSize * nValueBytes);
				FMemory::Memcpy(pDataVertex->m_Pos, pGameDataVertex->m_Pos, nValueBytes * nPosSize);
			}
		}
	}
	void GameConvertor::NormalToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nNormalCount = pGameDataVertex->m_nNormalCount;
		pDataVertex->m_nNormalDim = pGameDataVertex->m_nNormalDim;
		pDataVertex->m_Normal = nullptr;

		if (pGameDataVertex->m_Normal != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_Normal = pGameDataVertex->m_Normal;
				pGameDataVertex->m_Normal = nullptr;
			}
			else
			{
				bool compress = GameConvertor::HasCompressOptions(pGameDataVertex->m_nCompressType, VertexCompressOptions::SVC_Normal);
				uint32 nValueBytes = compress ? sizeof(Gameushort) : sizeof(Gamefloat);
				Gameuint nNormalSize = pDataVertex->m_nNormalDim * pDataVertex->m_nNormalCount;
				pDataVertex->m_Normal = (Gamefloat*)FMemory::Malloc(nNormalSize * nValueBytes);
				FMemory::Memcpy(pDataVertex->m_Normal, pGameDataVertex->m_Normal, nValueBytes * nNormalSize);
			}
		}
	}

	void GameConvertor::TangentToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nTangentCount = pGameDataVertex->m_nTangentCount;
		pDataVertex->m_nTangentDim = pGameDataVertex->m_nTangentDim;
		pDataVertex->m_Tangent = nullptr;

		if (pGameDataVertex->m_Tangent != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_Tangent = pGameDataVertex->m_Tangent;
				pGameDataVertex->m_Tangent = nullptr;
			}
			else
			{
				bool compress = GameConvertor::HasCompressOptions(pGameDataVertex->m_nCompressType, VertexCompressOptions::SVC_Normal);
				uint32 nValueBytes = compress ? sizeof(Gameushort) : sizeof(Gamefloat);
				Gameuint nTangentSize = pDataVertex->m_nTangentDim * pDataVertex->m_nTangentCount;
				pDataVertex->m_Tangent = (Gamefloat*)FMemory::Malloc(nTangentSize * nValueBytes);
				FMemory::Memcpy(pDataVertex->m_Tangent, pGameDataVertex->m_Tangent, nValueBytes * nTangentSize);
			}
		}
	}

	void GameConvertor::VertexColorToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nColorCount = pGameDataVertex->m_nColorCount;
		pDataVertex->m_PosColor = nullptr;
		if (pGameDataVertex->m_PosColor != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_PosColor = pGameDataVertex->m_PosColor;
				pGameDataVertex->m_PosColor = nullptr;
			}
			else
			{
				Gameuint nPosColorSize = pDataVertex->m_nColorCount;
				pDataVertex->m_PosColor = (Gameuint*)FMemory::Malloc(nPosColorSize * sizeof(Gameuint));
				FMemory::Memcpy(pDataVertex->m_PosColor, pGameDataVertex->m_PosColor, sizeof(Gameuint) * nPosColorSize);
			}
		}
	}
	void GameConvertor::SecondColorToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nSecondColorCount = pGameDataVertex->m_nSecondColorCount;
		pDataVertex->m_PosSceondColor = nullptr;
		if (pGameDataVertex->m_PosSceondColor != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_PosSceondColor = pGameDataVertex->m_PosSceondColor;
				pGameDataVertex->m_PosSceondColor = nullptr;
			}
			else
			{
				Gameuint nPosColorSize = pDataVertex->m_nSecondColorCount;
				pDataVertex->m_PosSceondColor = (Gameuint*)FMemory::Malloc(nPosColorSize * sizeof(Gameuint));
				FMemory::Memcpy(pDataVertex->m_PosSceondColor, pGameDataVertex->m_PosSceondColor, sizeof(Gameuint) * nPosColorSize);
			}
		}
	}

	void GameConvertor::TexCoord0ToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nTexCoordCount = pGameDataVertex->m_nTexCoordCount0;
		pDataVertex->m_nTexCoordDim = pGameDataVertex->m_nTexCoordDim0;
		pDataVertex->m_texCoordCompressUV0Constant.X = pGameDataVertex->m_texCoordCompressUV0Constant.x;
		pDataVertex->m_texCoordCompressUV0Constant.Y = pGameDataVertex->m_texCoordCompressUV0Constant.y;
		pDataVertex->m_TexCoord = nullptr;
		if (pGameDataVertex->m_TexCoord0 != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_TexCoord = pGameDataVertex->m_TexCoord0;
				pGameDataVertex->m_TexCoord0 = nullptr;
			}
			else
			{
				bool compress = GameConvertor::HasCompressOptions(pGameDataVertex->m_nCompressType, VertexCompressOptions::SVC_TexutreCoord);
				uint32 nValueBytes = compress ? sizeof(Gameushort) : sizeof(Gamefloat);
				Gameuint nTexSize = pDataVertex->m_nTexCoordCount * pDataVertex->m_nTexCoordDim;
				pDataVertex->m_TexCoord = (Gamefloat*)FMemory::Malloc(nTexSize * nValueBytes);
				FMemory::Memcpy(pDataVertex->m_TexCoord, pGameDataVertex->m_TexCoord0, nValueBytes * nTexSize);
			}
		}
	}

	void GameConvertor::TexCoord1ToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nTexCoordCount1 = pGameDataVertex->m_nTexCoordCount1;
		pDataVertex->m_nTexCoordDim1 = pGameDataVertex->m_nTexCoordDim1;
		pDataVertex->m_texCoordCompressUV1Constant.X = pGameDataVertex->m_texCoordCompressUV1Constant.x;
		pDataVertex->m_texCoordCompressUV1Constant.Y = pGameDataVertex->m_texCoordCompressUV1Constant.y;
		pDataVertex->m_TexCoord1 = nullptr;
		if (pGameDataVertex->m_TexCoord1 != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_TexCoord1 = pGameDataVertex->m_TexCoord1;
				pGameDataVertex->m_TexCoord1 = nullptr;
			}
			else
			{
				bool compress = GameConvertor::HasCompressOptions(pGameDataVertex->m_nCompressType, VertexCompressOptions::SVC_TexutreCoord);
				uint32 nValueBytes = compress ? sizeof(Gameushort) : sizeof(Gamefloat);
				Gameuint nTexSize = pDataVertex->m_nTexCoordCount1 * pDataVertex->m_nTexCoordDim1;
				pDataVertex->m_TexCoord1 = (Gamefloat*)FMemory::Malloc(nTexSize * nValueBytes);
				FMemory::Memcpy(pDataVertex->m_TexCoord1, pGameDataVertex->m_TexCoord1, nValueBytes * nTexSize);
			}
		}
	}

	void GameConvertor::TexCoord2ToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nTexCoordCount2 = pGameDataVertex->m_nTexCoordCount2;
		pDataVertex->m_nTexCoordDim2 = pGameDataVertex->m_nTexCoordDim2;
		pDataVertex->m_TexCoord2 = nullptr;
		if (pGameDataVertex->m_TexCoord2 != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_TexCoord2 = pGameDataVertex->m_TexCoord2;
				pGameDataVertex->m_TexCoord2 = nullptr;
			}
			else
			{
				Gameuint nTexSize = pDataVertex->m_nTexCoordCount2 * pDataVertex->m_nTexCoordDim2;
				pDataVertex->m_TexCoord2 = (Gamefloat*)FMemory::Malloc(nTexSize * sizeof(Gamefloat));
				FMemory::Memcpy(pDataVertex->m_TexCoord2, pGameDataVertex->m_TexCoord2, sizeof(Gamefloat) * nTexSize);
			}
		}
	}

	void GameConvertor::TexCoord3ToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nTexCoordCount3 = pGameDataVertex->m_nTexCoordCount3;
		pDataVertex->m_nTexCoordDim3 = pGameDataVertex->m_nTexCoordDim3;
		pDataVertex->m_TexCoord3 = nullptr;
		if (pGameDataVertex->m_TexCoord3 != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_TexCoord3 = pGameDataVertex->m_TexCoord3;
				pGameDataVertex->m_TexCoord3 = nullptr;
			}
			else
			{
				Gameuint nTexSize = pDataVertex->m_nTexCoordCount3 * pDataVertex->m_nTexCoordDim3;
				pDataVertex->m_TexCoord3 = (Gamefloat*)FMemory::Malloc(nTexSize * sizeof(Gamefloat));
				FMemory::Memcpy(pDataVertex->m_TexCoord3, pGameDataVertex->m_TexCoord3, sizeof(Gamefloat) * nTexSize);
			}
		}
	}

	void GameConvertor::CompressParamToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nCompressType = pGameDataVertex->m_nCompressType;
		if (pGameDataVertex->m_fMinVerticesValue != nullptr)
		{
			pDataVertex->m_vMinVerticesValue.X = pGameDataVertex->m_fMinVerticesValue[0];
			pDataVertex->m_vMinVerticesValue.Y = pGameDataVertex->m_fMinVerticesValue[1];
			pDataVertex->m_vMinVerticesValue.Z = pGameDataVertex->m_fMinVerticesValue[2];
			pDataVertex->m_vMinVerticesValue.W = pGameDataVertex->m_fMinVerticesValue[3];
		}
		pDataVertex->m_fVertCompressConstant = pGameDataVertex->m_fVertCompressConstant;
		bool compress = GameConvertor::HasCompressOptions(pGameDataVertex->m_nCompressType, VertexCompressOptions::SVC_TexutreCoord);
		if (!compress)
		{
			pDataVertex->m_texCoord0Min.X = 0.0;
			pDataVertex->m_texCoord0Min.Y = 0.0;
			pDataVertex->m_texCoordCompressUV0Constant.X = 1;
			pDataVertex->m_texCoordCompressUV0Constant.Y = 1;
		}
		else
		{
			pDataVertex->m_texCoord0Min.X = pGameDataVertex->m_texCoord0Min.x;
			pDataVertex->m_texCoord0Min.Y = pGameDataVertex->m_texCoord0Min.y;
			pDataVertex->m_texCoordCompressUV0Constant.X = pGameDataVertex->m_texCoordCompressUV0Constant.x;
			pDataVertex->m_texCoordCompressUV0Constant.Y = pGameDataVertex->m_texCoordCompressUV0Constant.y;
		}

		pDataVertex->m_texCoord1Min.X = pGameDataVertex->m_texCoord1Min.x;
		pDataVertex->m_texCoord1Min.Y = pGameDataVertex->m_texCoord1Min.y;
		pDataVertex->m_texCoordCompressUV1Constant.X = pGameDataVertex->m_texCoordCompressUV1Constant.x;
		pDataVertex->m_texCoordCompressUV1Constant.Y = pGameDataVertex->m_texCoordCompressUV1Constant.y;
	}

	void GameConvertor::BlendWeightToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_nBlendWeightsCount = pGameDataVertex->m_nBlendWeightsCount;
		pDataVertex->m_pBlendWeights = nullptr;
		if (pGameDataVertex->m_pBlendWeights != nullptr)
		{
			if (pGameDataVertex->m_bCanBeReleased)
			{
				pDataVertex->m_pBlendWeights = pGameDataVertex->m_pBlendWeights;
				pGameDataVertex->m_pBlendWeights = nullptr;
			}
			else
			{
				Gameuint nCount = pDataVertex->m_nBlendWeightsCount;
				pDataVertex->m_pBlendWeights = (Gamefloat*)FMemory::Malloc(nCount * sizeof(Gamefloat));
				FMemory::Memcpy(pDataVertex->m_pBlendWeights, pGameDataVertex->m_pBlendWeights, sizeof(Gamefloat) * nCount);
			}
		}
	}

	uint32 GameConvertor::GetByteSizeByVertexAttributeType(VertexAttributeType vType)
	{
		uint32 nValueByteSize = 0;
		switch (vType)
		{
		case SuperMapSDK::AT_32BIT:
			nValueByteSize = sizeof(Gameuint);
			break;
		case SuperMapSDK::AT_FLOAT:
			nValueByteSize = sizeof(Gamefloat);
			break;
		case SuperMapSDK::AT_DOUBLE:
			nValueByteSize = sizeof(Gamedouble);
			break;
		case SuperMapSDK::AT_16BIT:
			nValueByteSize = sizeof(Gameushort);
			break;
		default:
			break;
		}
		return nValueByteSize;
	}

	void GameConvertor::VertexAttToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_bHasVertexWeight = pGameDataVertex->m_bHasVertexWeight;
		pDataVertex->m_nVertexAttCount = pGameDataVertex->m_nVertexAttCount;
		Gameuint nVertexAttCount = pGameDataVertex->m_nVertexAttCount;
		if(nVertexAttCount == 0)
		{
			return;
		}
		pDataVertex->m_vecVertexAttribute.SetNumUninitialized(nVertexAttCount);
		for (Gameuint i = 0; i < nVertexAttCount; i++)
		{
			pDataVertex->m_vecVertexAttribute[i].Init(pGameDataVertex, i);
		}
	}

	/*骨架，索引都拷贝了，有优化的空间*/
	void GameConvertor::GameDataVertexPackageToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex)
	{
		pDataVertex->m_bUGMemory = pGameDataVertex->m_bCanBeReleased;

		GameConvertor::PosToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::NormalToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::TangentToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::VertexColorToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::SecondColorToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::TexCoord0ToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::TexCoord1ToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::TexCoord2ToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::TexCoord3ToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::BlendWeightToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::CompressParamToDataVertex(pGameDataVertex, pDataVertex);
		GameConvertor::VertexAttToDataVertex(pGameDataVertex, pDataVertex);

		pDataVertex->m_ObjectMat = nullptr;
		pDataVertex->m_doubleObjectMat = nullptr;
	}

	void GameConvertor::GameIndexPackageToDataIndice(GameIndexPackage*& pGameIndexPackage, DataIndice*& pDataIndice)
	{
		pDataIndice->m_shortIndex = nullptr;
		pDataIndice->m_Index = nullptr;
		pDataIndice->m_bUGMemory = pGameIndexPackage->m_bCanBeReleased;

		if (pGameIndexPackage->m_enIndexType == 0)
		{
			if (pGameIndexPackage->m_bCanBeReleased)
			{
				pDataIndice->m_shortIndex = pGameIndexPackage->m_pIndexes;
				pGameIndexPackage->m_pIndexes = nullptr;
			}
			else
			{
				pDataIndice->m_shortIndex = (Gameushort*)FMemory::Malloc(pGameIndexPackage->m_nIndexCount * sizeof(Gameushort));
				FMemory::Memcpy(pDataIndice->m_shortIndex, pGameIndexPackage->m_pIndexes, sizeof(Gameushort) * pGameIndexPackage->m_nIndexCount);
			}
		}
		else if (pGameIndexPackage->m_enIndexType == 1)
		{
			if (pGameIndexPackage->m_bCanBeReleased)
			{
				pDataIndice->m_Index = (Gameuint*)pGameIndexPackage->m_pIndexes;
				pGameIndexPackage->m_pIndexes = nullptr;
			}
			else
			{
				pDataIndice->m_Index = (Gameuint*)FMemory::Malloc(pGameIndexPackage->m_nIndexCount * sizeof(Gameuint));
				FMemory::Memcpy(pDataIndice->m_Index, pGameIndexPackage->m_pIndexes, sizeof(Gameuint) * pGameIndexPackage->m_nIndexCount);
			}
		}

		pDataIndice->m_enIndexType = pGameIndexPackage->m_enIndexType;
		switch (pGameIndexPackage->m_nOperationType)
		{
			// 点
		case 1:
			pDataIndice->m_nOperationType = PT_PointList;
			break;
			// 线
		case 2:
			pDataIndice->m_nOperationType = PT_LineList;
			break;
			// 三角网
		case 4:
			pDataIndice->m_nOperationType = PT_TriangleList;
			break;
			// 四边形
		case 9:
			pDataIndice->m_nOperationType = PT_QuadList;
			break;
		default:
			pDataIndice->m_nOperationType = PT_TriangleList;
			break;
		}


		pDataIndice->m_nIndexCount = pGameIndexPackage->m_nIndexCount;
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif