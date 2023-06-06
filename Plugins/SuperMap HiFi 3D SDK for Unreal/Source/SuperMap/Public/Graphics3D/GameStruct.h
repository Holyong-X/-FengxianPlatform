#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEnum.h"

namespace SuperMapSDK
{
	// 用来传给游戏引擎的结构体
	struct GameVec4d
	{
		Gamedouble x;
		Gamedouble y;
		Gamedouble z;
		Gamedouble w;
	};

	struct GameVec3d
	{
		Gamedouble x;
		Gamedouble y;
		Gamedouble z;
	};

	struct GameVec2d
	{
		Gamedouble x;
		Gamedouble y;
	};

	struct GameVec4f
	{
		Gamefloat x;
		Gamefloat y;
		Gamefloat z;
		Gamefloat w;
	};

	struct GameVec3f
	{
		Gamefloat x;
		Gamefloat y;
		Gamefloat z;
	};

	struct GameVec2f
	{
		Gamefloat x;
		Gamefloat y;
	};

	// 纹理运动参数
	struct UVGameMotionParameter
	{
		//! \brief U方向的速度
		Gamefloat m_fSpeedU;
		//! \brief V方向的速度
		Gamefloat m_fSpeedV;
		//! \brief 周期
		Gamefloat m_fPeriod;
	};

	struct GameTextureMotionParam
	{
		//! \brief 纹理平移运动的参数
		UVGameMotionParameter m_OffsetMotion;
		//! \brief 纹理缩放的参数
		UVGameMotionParameter m_TilingMotion;
	};

	struct GamePBRMetallicRough
	{
	public:
		GamePBRMetallicRough();
		GamePBRMetallicRough(const GamePBRMetallicRough& other);
		~GamePBRMetallicRough();
	public:
		//! \brief 物体的基本颜色因子
		GameVec4d m_vec4BaseColor;
		//! \brief 物体基本颜色的纹理在纹理数组中的序号
		Gameint m_nBaseColorTextureIndex;
		//! \brief 物体基本颜色的纹理坐标在纹理坐标数组中的序号
		Gameint m_nBaseColorTextureCoordIndex;
		//! \brief 基色纹理运动的参数对象
		GameTextureMotionParam m_BaseColorTextureMotion;
		//! \brief 金属度和粗糙性纹理在纹理数组中的序号(R通道存储金属度，G通道存储粗糙度)
		Gameint m_nMetallicRoughnessTextureIndex;
		//! \brief 金属度和粗糙性纹理的纹理坐标在数组中的序号
		Gameint m_nMetallicRoughnessTextureCoordIndex;
		//! \brief 控制金属性强弱的因子
		Gamefloat m_fMetallicFactor;
		//! \brief 控制粗糙性强弱的因子
		Gamefloat m_fRoughnessFactor;
	};

	struct GamePBRSpecularGlossy
	{
	public:
		GamePBRSpecularGlossy();
		~GamePBRSpecularGlossy();
	public:
		//! \brief 散射颜色
		GameVec4d m_vec4DiffuseFactor;
		//! \brief 镜面光颜色
		GameVec3d m_vec3SpecularFactor;
		//! \brief 高光强度
		Gamefloat m_fGlossinessFactor;
		//! \brief 散射颜色纹理
		Gamechar* m_strDiffuseTexture;
		//! \brief 镜面光高光强度纹理，RGB通道存镜面光颜色，A通道存高光强度
		Gamechar* m_strSpecularGlossinessTexture;
	};

	// PBR材质
	struct GamePBRParam
	{
	public:
		GamePBRParam();
		GamePBRParam(const GamePBRParam& other);
		~GamePBRParam();
	public:
		//! \brief 控制自发光强度的因子
		GameVec3d m_vec3EmissiveFactor;
		//! \brief 自发光纹理在纹理数组中的序号 RGB纹理
		Gameint m_nEmissiveTextureIndex;
		//! \brief 自发光纹理的纹理坐标在纹理坐标数组中的序号
		Gameint m_nEmissiveTextureCoordIndex;
		//! \brief 自发光纹理运动的参数对象
		GameTextureMotionParam m_EmissiveTextureMotion;
		//! \brief 法线纹理在纹理数组中的序号，物体表面的凹凸细节 float格式RGB纹理
		Gameint m_nNormalTextureIndex;
		//! \brief 法线纹理的纹理坐标在纹理坐标数组中的序号
		Gameint m_nNormalTextureCoordIndex;
		//! \brief 法线纹理的缩放因子
		Gamefloat m_fNormalTextureScale;
		//! \brief 遮挡图在纹理数组中的序号，用于物体表面凹凸性对光照的影响，比如缝隙处就暗 float灰度纹理
		Gameint m_nOcclusionTextureIndex;
		//! \brief 遮挡图的纹理坐标在纹理坐标数组中的序号
		Gameint m_nOcclusionTextureCoordIndex;
		//! \brief 遮挡图的缩放因子
		Gamefloat m_fOcclusionTextureStrength;
		//! \brief UGAlphaMode
		Gameint	m_AlphaMode;
		//! \brief 当alphaMode为Mask时，着色器根据这个值和baseColor的Alpha值进行比较决定是否丢弃
		Gamefloat	m_fAlphaCutoff;
		//! \brief 是否双面渲染
		Gameint m_bDoubleSided;
		//! \brief 掩膜图在纹理数组中的序号，用于物体表面凹凸性对光照的影响，比如缝隙处就暗 float灰度纹理
		Gameint m_nMaskTextureIndex;
		//! \brief 掩膜图的纹理坐标在纹理坐标数组中的序号
		Gameint m_nMaskTextureCoordIndex;

		//! \brief 金属粗糙度模型
		GamePBRMetallicRough* m_pPBRMetallicRough;

		//! \brief 镜面光高光模型
		GamePBRSpecularGlossy* m_pPBRSpecularGlossy;
	};

	class GameMaterialParam
	{
	public:
		GameMaterialParam();
		~GameMaterialParam();

		//! \brief 拷贝
		void Copy(GameMaterialParam* pMaterialParam);

	public:
		Gamelong      m_nMaterialName;
		Gamechar* m_strMaterialName;
		Gamechar* m_strShaderName;
		Gameint      m_nTextureCount;
		Gamelong* m_pTextureNames;
		Gamedouble** m_pTexTransforms;
		Gameint*	m_pMinFilters;
		Gameint*	m_pMagFilters;
		Gameint*	m_pMipFilters;
		Gameint*	m_pTexAddressingMode;
		Gameint      m_nDataType;
		Gameint      m_nBatchTextureIndex;
		GameVec4d     m_diffuse;
		GamePBRParam* m_pPBRParam;
		Gamechar** m_setMacro;
		Gameint m_nMacroCount;
		Gameint m_nState;
		CullingMode m_eCullingMode;
	};

	struct GameDataVertexPackage
	{
	public:
		GameDataVertexPackage();
		~GameDataVertexPackage();
	public:
		// 顶点
		Gamefloat* m_Pos;
		Gameint    m_nPosCount;
		Gameint    m_nPosDim;

		// 法线
		Gamefloat* m_Normal;
		Gameuint   m_nNormalCount;
		Gameuint   m_nNormalDim;

		// 切线
		Gamefloat* m_Tangent;
		Gameuint   m_nTangentCount;
		Gameuint   m_nTangentDim;

		// 顶点颜色
		Gameuint* m_PosColor;
		Gameint    m_nColorCount;

		// SecondColor
		Gameuint* m_PosSceondColor;
		Gameint    m_nSecondColorCount;

		// 纹理坐标(先只考虑一层纹理)
		Gamefloat* m_TexCoord0;
		Gameint    m_nTexCoordCount0;
		Gameint    m_nTexCoordDim0;
		GameVec2f m_texCoord0Min;
		GameVec2f m_texCoordCompressUV0Constant;

		// 纹理坐标(先只考虑一层纹理)
		Gamefloat* m_TexCoord1;
		Gameint    m_nTexCoordCount1;
		Gameint    m_nTexCoordDim1;
		GameVec2f m_texCoord1Min;
		GameVec2f m_texCoordCompressUV1Constant;

		//-------实例化信息------------
		Gamefloat* m_TexCoord2;
		Gameint    m_nTexCoordCount2;
		Gameint    m_nTexCoordDim2;

		Gamefloat* m_TexCoord3;
		Gameint    m_nTexCoordCount3;
		Gameint    m_nTexCoordDim3;
		//-----------------------------

		// 压缩
		Gameint m_nCompressType;

		// 压缩
		Gamefloat* m_fMinVerticesValue;
		Gamefloat  m_fVertCompressConstant;

		//! \brief 顶点混合权重,目前当做BatchID使用，前端设置，并不存储到数据中
		Gamefloat* m_pBlendWeights;
		Gameuint   m_nBlendWeightsCount;

		// 是否可在游戏引擎中释放
		Gamebool m_bCanBeReleased;

		// 属性中是否含有W位
		Gamebool m_bHasVertexWeight;

		//! \brief 属性数目
		Gameuint m_nVertexAttCount;

		//! \brief 属性数据数目的数组
		Gameuint* m_vecVertexAttDataCount;

		//! \brief 属性数据维数的数组
		Gameushort* m_vecVertexAttDataDimension;

		//! \brief 属性数据类型的数组
		Gameuint* m_vecVertexAttDataType;

		//! \brief 属性数据的数组
		void** m_vecVertexAttData;
	};

	struct GameIndexPackage
	{
	public:
		GameIndexPackage();
		~GameIndexPackage();
	public:
		// 当前帧索引信息
		Gameushort* m_pIndexes;

		// 索引值个数
		Gameint m_nIndexCount;

		// 绘制类型
		Gameint m_nOperationType;

		// 索引类型
		Gameushort m_enIndexType;

		// 是否可在游戏引擎中释放
		Gamebool m_bCanBeReleased;
	};

	//! \brief BoundBox
	struct GameBoundingBox
	{
	public:
		GameBoundingBox();
		~GameBoundingBox();
	public:
		// 包围盒最小值
		GameVec3d m_vMin;

		// 包围盒最大值
		GameVec3d m_vMax;
	};

	//! \brief 更新的纹理信息
	struct GameTexture2DInfo
	{
	public:
		GameTexture2DInfo();
		~GameTexture2DInfo();

		// 将外部的纹理数据指针的数据传给对象，bCopy则复制数据并保存，bCopy为false直接指向原来的数据，并负责内存的释放
		void SetTextureData(Gameuchar*& pByte, Gameuint nSizeInByte, bool bCopy);
	public:
		// 要更新的纹理数据在原始纹理上的偏移量
		Gameint m_nOffsetX;

		// 要更新的纹理数据在原始纹理上的偏移量
		Gameint m_nOffsetY;

		// 要更新的纹理数据的宽度
		Gameint m_nWidth;

		// 要更新的纹理数据的高度
		Gameint m_nHeight;

		// 要更新的纹理数据的字节长度
		Gameuint m_nSizeInByte;

		// 要更新的纹理数据的数据指针
		Gameuchar* m_pByte;

		// 要更新的纹理数据的格式
		Gameint m_nFormat;

		// 在UE中使用的像素格式
		EPixelFormat m_nEPixelFormat;

		// 要更新的纹理数据的压缩格式
		Gameint m_nCompressType;

		// 持有的数据是否是UGC中的的内存
		Gamebool m_bUGMemory;

		// 是否开启伽马矫正
		Gamebool m_bSRGB;
	};

	// 对应底层的自定义顶点属性信息
	struct VertexAttribute
	{
		VertexAttribute()
		{
			m_nVertexAttDataCount = 0;
			m_nVertexAttDataDimension = 0;
			m_enVertexAttDataType = VertexAttributeType::AT_FLOAT;
			m_pVertexAttData = nullptr;
		}

		void Release(bool bUseUGCMem);

		void Init(GameDataVertexPackage*& pGameDataVertex, int nIndex);

		//! \brief 属性数据数目
		Gameuint m_nVertexAttDataCount;

		//! \brief 属性数据维数
		Gameushort m_nVertexAttDataDimension;

		//! \brief 属性数据类型
		VertexAttributeType m_enVertexAttDataType;

		//! \brief 属性数据的数组
		void* m_pVertexAttData;
	};

	struct DataVertex
	{
	public:
		// 顶点
		Gamefloat* m_Pos;
		Gameint m_nPosCount;
		Gameint m_nPosDim;

		// 法线
		Gamefloat* m_Normal;
		Gameuint m_nNormalCount;
		Gameuint m_nNormalDim;

		// 切线
		Gamefloat* m_Tangent;
		Gameuint m_nTangentCount;
		Gameuint m_nTangentDim;

		// 顶点颜色
		Gameuint* m_PosColor;
		Gameint m_nColorCount;

		// SecondColor
		Gameuint* m_PosSceondColor;
		Gameint m_nSecondColorCount;

		// 纹理坐标(先只考虑一层纹理)
		Gamefloat* m_TexCoord;
		Gameint m_nTexCoordCount;
		Gameint m_nTexCoordDim;
		FVector2D m_texCoord0Min;
		FVector2D m_texCoordCompressUV0Constant;

		// 纹理坐标(先只考虑一层纹理)
		Gamefloat* m_TexCoord1;
		Gameint m_nTexCoordCount1;
		Gameint m_nTexCoordDim1;
		FVector2D m_texCoord1Min;
		FVector2D m_texCoordCompressUV1Constant;

		//-------实例化信息------------
		Gamefloat* m_TexCoord2;
		Gameint m_nTexCoordCount2;
		Gameint m_nTexCoordDim2;

		Gamefloat* m_TexCoord3;
		Gameint m_nTexCoordCount3;
		Gameint m_nTexCoordDim3;
		//-----------------------------

		// 模型变换矩阵
		Gamefloat* m_ObjectMat;
		// 高精度模型矩阵
		Gamedouble* m_doubleObjectMat;

		//------------------------------
		// 压缩
		Gameint m_nCompressType;

		// 压缩
		FVector4 m_vMinVerticesValue;
		Gamefloat m_fVertCompressConstant;
		//------------------------------

		//! \brief 顶点混合权重,目前当做BatchID使用，前端设置，并不存储到数据中
		Gamefloat* m_pBlendWeights;
		Gameuint m_nBlendWeightsCount;
		///////////////////////////////////////////////////////////////////
		// 属性中是否含有W位
		Gamebool m_bHasVertexWeight;

		//! \brief 属性数目
		Gameuint m_nVertexAttCount;

		//! \brief 自定义属性的数组
		TArray<VertexAttribute> m_vecVertexAttribute;

		///////////////////////////////////////////////////////////////////
		// 持有的数据是否是UGC中的的内存
		Gamebool m_bUGMemory;

	public:
		~DataVertex();

		DataVertex* Copy();

		// 获取纹理坐标属性在自定义属性数组中的序号
		int GetIndexOfTexMatrixInVertexAttData();
	};

	struct DataIndice
	{
	public:
		// 当前帧索引信息
		Gameuint* m_Index;

		Gameushort* m_shortIndex;

		Gameint m_nIndexCount;

		// 绘制类型
		Gameint m_nOperationType;

		// 索引类型
		Gameushort m_enIndexType;

		// 材质真实的名字
		Gamechar* m_strRealMaterialName;

		// 材质Hash名
		Gamelong m_MtlHashCode;

		// 持有的数据是否是UGC中的的内存
		Gamebool m_bUGMemory;

	public:
		~DataIndice();
	};

	struct SM_Vertex
	{
	public:
		FVector Position;
		FVector Normal;
		FVector Tangent;
		FColor Color;
		FVector4 SecondColor;
		FVector2D UV0;
		FVector2D UV1;
		FVector2D UV2;
		FVector2D UV3;
		float PositionW;

		SM_Vertex()
			: Position(0.f, 0.f, 0.f)
			, Normal(0.f, 0.f, 1.f)
			, Tangent(1.f, 0.f, 0.f)
			, Color(255, 255, 255)
			, SecondColor(255, 255, 255, 255)
			, UV0(0.f, 0.f)
			, UV1(0.f, 0.f)
			, UV2(0.f, 0.f)
			, UV3(0.f, 0.f)
			, PositionW(0.0f)
		{}
	};

	struct SM_SubMesh
	{
	public:
		TArray<int32> IndexBuffer;

		UMaterialInterface* m_pMaterialInterface;

	public:

		SM_SubMesh() { m_pMaterialInterface = nullptr; }
		SM_SubMesh(const SM_SubMesh& sm)
		{
			IndexBuffer = sm.IndexBuffer;
			m_pMaterialInterface = sm.m_pMaterialInterface;
		}
		//UGC::UGString strTest;
		/** Reset this section, clear all mesh info. */
		void Reset()
		{
			//strTest = _U("test");
			IndexBuffer.Empty();
		}
	};

	struct InstanceCallbackHandleCollector
	{
		void* createInstanceEntity;
		void* destroyInstanceMesh;
		void* getInstanceMeshAttachComponent;
		void* writeInstanceBuffer;
		void* setInstanceBoundingBox;
		void* updateInstanceVertexColor;
	};

	struct GameFuture
	{
	public:
		TFuture<TPair<Gameulong, UTexture2D*> > m_FutureTextureCache;
		TFuture<UTexture2D*> m_DeleteTexture;
	};
}