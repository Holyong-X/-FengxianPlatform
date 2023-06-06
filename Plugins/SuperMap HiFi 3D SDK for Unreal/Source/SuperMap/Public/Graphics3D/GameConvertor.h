#pragma once

#include "CoreMinimal.h"
#include "Graphics3D/GameEnum.h"
#include "Runtime/Core/Public/PixelFormat.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEntity.h"
#include "Component/MeshData.h"
#include "Core/RealspaceDLL.h"

class UTexture2D;
namespace SuperMapSDK
{
	class SUPERMAP_API GameConvertor
	{
	public:
		GameConvertor();
		~GameConvertor();

	public:

		//! \brief 转化成UE的纹理格式类型
		static EPixelFormat ToEPixelFormat(Gameint nFromat, Gameint nCompressType);

		//! \brief 转化成RenderTexture的纹理格式类型
		static PixelFormat ToPixelFormat(Gameint nFormat);

		//! \brief 计算纹理的MipMap
		static void CalMipMap(Gameint nWidth, Gameint nHeight, Gameint nTextureSize,
			Gameint nPixelFormat, EPixelFormat ePixelFormat,
			TMap<Gameint, Gameint>& mapMipMaps);

		//! \brief 更新纹理
		static void UpdateTextureRegion(UTexture2D* pTex2D, GameTexture2DInfo& textureInfo, Gameint nOffset, Gamebool bIsData,
			Gameint nNum, Gameint nMipIndex);

		//! \brief 计算纹理大小
		static Gameint CalTextureSize(Gameint nWidth, Gameint nHeight, Gameint nPixelFormat, EPixelFormat ePixelFormat);

		//! \brief GameDataVertexPackageToDataVertex
		static void GameDataVertexPackageToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);

		//! \brief GameIndexPackageToDataIndice
		static void GameIndexPackageToDataIndice(GameIndexPackage*& pGameIndexPackage, DataIndice*& pDataIndice);

		//! \brief 是否有指定压缩项
		static bool HasCompressOptions(Gameint nCompressType, VertexCompressOptions enOptions)
		{
			return (nCompressType & enOptions) == enOptions;
		}

		static uint32 GetByteSizeByVertexAttributeType(VertexAttributeType vType);
	private:
		static void PosToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void NormalToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void TangentToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void VertexColorToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void SecondColorToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void TexCoord0ToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void TexCoord1ToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void TexCoord2ToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void TexCoord3ToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void BlendWeightToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void CompressParamToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
		static void VertexAttToDataVertex(GameDataVertexPackage*& pGameDataVertex, DataVertex*& pDataVertex);
	};
}
