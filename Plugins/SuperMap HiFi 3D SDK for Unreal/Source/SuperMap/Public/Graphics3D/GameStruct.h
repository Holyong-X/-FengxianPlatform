#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEnum.h"

namespace SuperMapSDK
{
	// ����������Ϸ����Ľṹ��
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

	// �����˶�����
	struct UVGameMotionParameter
	{
		//! \brief U������ٶ�
		Gamefloat m_fSpeedU;
		//! \brief V������ٶ�
		Gamefloat m_fSpeedV;
		//! \brief ����
		Gamefloat m_fPeriod;
	};

	struct GameTextureMotionParam
	{
		//! \brief ����ƽ���˶��Ĳ���
		UVGameMotionParameter m_OffsetMotion;
		//! \brief �������ŵĲ���
		UVGameMotionParameter m_TilingMotion;
	};

	struct GamePBRMetallicRough
	{
	public:
		GamePBRMetallicRough();
		GamePBRMetallicRough(const GamePBRMetallicRough& other);
		~GamePBRMetallicRough();
	public:
		//! \brief ����Ļ�����ɫ����
		GameVec4d m_vec4BaseColor;
		//! \brief ���������ɫ�����������������е����
		Gameint m_nBaseColorTextureIndex;
		//! \brief ���������ɫ�������������������������е����
		Gameint m_nBaseColorTextureCoordIndex;
		//! \brief ��ɫ�����˶��Ĳ�������
		GameTextureMotionParam m_BaseColorTextureMotion;
		//! \brief �����Ⱥʹֲ������������������е����(Rͨ���洢�����ȣ�Gͨ���洢�ֲڶ�)
		Gameint m_nMetallicRoughnessTextureIndex;
		//! \brief �����Ⱥʹֲ�����������������������е����
		Gameint m_nMetallicRoughnessTextureCoordIndex;
		//! \brief ���ƽ�����ǿ��������
		Gamefloat m_fMetallicFactor;
		//! \brief ���ƴֲ���ǿ��������
		Gamefloat m_fRoughnessFactor;
	};

	struct GamePBRSpecularGlossy
	{
	public:
		GamePBRSpecularGlossy();
		~GamePBRSpecularGlossy();
	public:
		//! \brief ɢ����ɫ
		GameVec4d m_vec4DiffuseFactor;
		//! \brief �������ɫ
		GameVec3d m_vec3SpecularFactor;
		//! \brief �߹�ǿ��
		Gamefloat m_fGlossinessFactor;
		//! \brief ɢ����ɫ����
		Gamechar* m_strDiffuseTexture;
		//! \brief �����߹�ǿ������RGBͨ���澵�����ɫ��Aͨ����߹�ǿ��
		Gamechar* m_strSpecularGlossinessTexture;
	};

	// PBR����
	struct GamePBRParam
	{
	public:
		GamePBRParam();
		GamePBRParam(const GamePBRParam& other);
		~GamePBRParam();
	public:
		//! \brief �����Է���ǿ�ȵ�����
		GameVec3d m_vec3EmissiveFactor;
		//! \brief �Է������������������е���� RGB����
		Gameint m_nEmissiveTextureIndex;
		//! \brief �Է�������������������������������е����
		Gameint m_nEmissiveTextureCoordIndex;
		//! \brief �Է��������˶��Ĳ�������
		GameTextureMotionParam m_EmissiveTextureMotion;
		//! \brief �������������������е���ţ��������İ�͹ϸ�� float��ʽRGB����
		Gameint m_nNormalTextureIndex;
		//! \brief ��������������������������������е����
		Gameint m_nNormalTextureCoordIndex;
		//! \brief �����������������
		Gamefloat m_fNormalTextureScale;
		//! \brief �ڵ�ͼ�����������е���ţ�����������氼͹�ԶԹ��յ�Ӱ�죬�����϶���Ͱ� float�Ҷ�����
		Gameint m_nOcclusionTextureIndex;
		//! \brief �ڵ�ͼ�������������������������е����
		Gameint m_nOcclusionTextureCoordIndex;
		//! \brief �ڵ�ͼ����������
		Gamefloat m_fOcclusionTextureStrength;
		//! \brief UGAlphaMode
		Gameint	m_AlphaMode;
		//! \brief ��alphaModeΪMaskʱ����ɫ���������ֵ��baseColor��Alphaֵ���бȽϾ����Ƿ���
		Gamefloat	m_fAlphaCutoff;
		//! \brief �Ƿ�˫����Ⱦ
		Gameint m_bDoubleSided;
		//! \brief ��Ĥͼ�����������е���ţ�����������氼͹�ԶԹ��յ�Ӱ�죬�����϶���Ͱ� float�Ҷ�����
		Gameint m_nMaskTextureIndex;
		//! \brief ��Ĥͼ�������������������������е����
		Gameint m_nMaskTextureCoordIndex;

		//! \brief �����ֲڶ�ģ��
		GamePBRMetallicRough* m_pPBRMetallicRough;

		//! \brief �����߹�ģ��
		GamePBRSpecularGlossy* m_pPBRSpecularGlossy;
	};

	class GameMaterialParam
	{
	public:
		GameMaterialParam();
		~GameMaterialParam();

		//! \brief ����
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
		// ����
		Gamefloat* m_Pos;
		Gameint    m_nPosCount;
		Gameint    m_nPosDim;

		// ����
		Gamefloat* m_Normal;
		Gameuint   m_nNormalCount;
		Gameuint   m_nNormalDim;

		// ����
		Gamefloat* m_Tangent;
		Gameuint   m_nTangentCount;
		Gameuint   m_nTangentDim;

		// ������ɫ
		Gameuint* m_PosColor;
		Gameint    m_nColorCount;

		// SecondColor
		Gameuint* m_PosSceondColor;
		Gameint    m_nSecondColorCount;

		// ��������(��ֻ����һ������)
		Gamefloat* m_TexCoord0;
		Gameint    m_nTexCoordCount0;
		Gameint    m_nTexCoordDim0;
		GameVec2f m_texCoord0Min;
		GameVec2f m_texCoordCompressUV0Constant;

		// ��������(��ֻ����һ������)
		Gamefloat* m_TexCoord1;
		Gameint    m_nTexCoordCount1;
		Gameint    m_nTexCoordDim1;
		GameVec2f m_texCoord1Min;
		GameVec2f m_texCoordCompressUV1Constant;

		//-------ʵ������Ϣ------------
		Gamefloat* m_TexCoord2;
		Gameint    m_nTexCoordCount2;
		Gameint    m_nTexCoordDim2;

		Gamefloat* m_TexCoord3;
		Gameint    m_nTexCoordCount3;
		Gameint    m_nTexCoordDim3;
		//-----------------------------

		// ѹ��
		Gameint m_nCompressType;

		// ѹ��
		Gamefloat* m_fMinVerticesValue;
		Gamefloat  m_fVertCompressConstant;

		//! \brief ������Ȩ��,Ŀǰ����BatchIDʹ�ã�ǰ�����ã������洢��������
		Gamefloat* m_pBlendWeights;
		Gameuint   m_nBlendWeightsCount;

		// �Ƿ������Ϸ�������ͷ�
		Gamebool m_bCanBeReleased;

		// �������Ƿ���Wλ
		Gamebool m_bHasVertexWeight;

		//! \brief ������Ŀ
		Gameuint m_nVertexAttCount;

		//! \brief ����������Ŀ������
		Gameuint* m_vecVertexAttDataCount;

		//! \brief ��������ά��������
		Gameushort* m_vecVertexAttDataDimension;

		//! \brief �����������͵�����
		Gameuint* m_vecVertexAttDataType;

		//! \brief �������ݵ�����
		void** m_vecVertexAttData;
	};

	struct GameIndexPackage
	{
	public:
		GameIndexPackage();
		~GameIndexPackage();
	public:
		// ��ǰ֡������Ϣ
		Gameushort* m_pIndexes;

		// ����ֵ����
		Gameint m_nIndexCount;

		// ��������
		Gameint m_nOperationType;

		// ��������
		Gameushort m_enIndexType;

		// �Ƿ������Ϸ�������ͷ�
		Gamebool m_bCanBeReleased;
	};

	//! \brief BoundBox
	struct GameBoundingBox
	{
	public:
		GameBoundingBox();
		~GameBoundingBox();
	public:
		// ��Χ����Сֵ
		GameVec3d m_vMin;

		// ��Χ�����ֵ
		GameVec3d m_vMax;
	};

	//! \brief ���µ�������Ϣ
	struct GameTexture2DInfo
	{
	public:
		GameTexture2DInfo();
		~GameTexture2DInfo();

		// ���ⲿ����������ָ������ݴ�������bCopy�������ݲ����棬bCopyΪfalseֱ��ָ��ԭ�������ݣ��������ڴ���ͷ�
		void SetTextureData(Gameuchar*& pByte, Gameuint nSizeInByte, bool bCopy);
	public:
		// Ҫ���µ�����������ԭʼ�����ϵ�ƫ����
		Gameint m_nOffsetX;

		// Ҫ���µ�����������ԭʼ�����ϵ�ƫ����
		Gameint m_nOffsetY;

		// Ҫ���µ��������ݵĿ��
		Gameint m_nWidth;

		// Ҫ���µ��������ݵĸ߶�
		Gameint m_nHeight;

		// Ҫ���µ��������ݵ��ֽڳ���
		Gameuint m_nSizeInByte;

		// Ҫ���µ��������ݵ�����ָ��
		Gameuchar* m_pByte;

		// Ҫ���µ��������ݵĸ�ʽ
		Gameint m_nFormat;

		// ��UE��ʹ�õ����ظ�ʽ
		EPixelFormat m_nEPixelFormat;

		// Ҫ���µ��������ݵ�ѹ����ʽ
		Gameint m_nCompressType;

		// ���е������Ƿ���UGC�еĵ��ڴ�
		Gamebool m_bUGMemory;

		// �Ƿ���٤�����
		Gamebool m_bSRGB;
	};

	// ��Ӧ�ײ���Զ��嶥��������Ϣ
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

		//! \brief ����������Ŀ
		Gameuint m_nVertexAttDataCount;

		//! \brief ��������ά��
		Gameushort m_nVertexAttDataDimension;

		//! \brief ������������
		VertexAttributeType m_enVertexAttDataType;

		//! \brief �������ݵ�����
		void* m_pVertexAttData;
	};

	struct DataVertex
	{
	public:
		// ����
		Gamefloat* m_Pos;
		Gameint m_nPosCount;
		Gameint m_nPosDim;

		// ����
		Gamefloat* m_Normal;
		Gameuint m_nNormalCount;
		Gameuint m_nNormalDim;

		// ����
		Gamefloat* m_Tangent;
		Gameuint m_nTangentCount;
		Gameuint m_nTangentDim;

		// ������ɫ
		Gameuint* m_PosColor;
		Gameint m_nColorCount;

		// SecondColor
		Gameuint* m_PosSceondColor;
		Gameint m_nSecondColorCount;

		// ��������(��ֻ����һ������)
		Gamefloat* m_TexCoord;
		Gameint m_nTexCoordCount;
		Gameint m_nTexCoordDim;
		FVector2D m_texCoord0Min;
		FVector2D m_texCoordCompressUV0Constant;

		// ��������(��ֻ����һ������)
		Gamefloat* m_TexCoord1;
		Gameint m_nTexCoordCount1;
		Gameint m_nTexCoordDim1;
		FVector2D m_texCoord1Min;
		FVector2D m_texCoordCompressUV1Constant;

		//-------ʵ������Ϣ------------
		Gamefloat* m_TexCoord2;
		Gameint m_nTexCoordCount2;
		Gameint m_nTexCoordDim2;

		Gamefloat* m_TexCoord3;
		Gameint m_nTexCoordCount3;
		Gameint m_nTexCoordDim3;
		//-----------------------------

		// ģ�ͱ任����
		Gamefloat* m_ObjectMat;
		// �߾���ģ�;���
		Gamedouble* m_doubleObjectMat;

		//------------------------------
		// ѹ��
		Gameint m_nCompressType;

		// ѹ��
		FVector4 m_vMinVerticesValue;
		Gamefloat m_fVertCompressConstant;
		//------------------------------

		//! \brief ������Ȩ��,Ŀǰ����BatchIDʹ�ã�ǰ�����ã������洢��������
		Gamefloat* m_pBlendWeights;
		Gameuint m_nBlendWeightsCount;
		///////////////////////////////////////////////////////////////////
		// �������Ƿ���Wλ
		Gamebool m_bHasVertexWeight;

		//! \brief ������Ŀ
		Gameuint m_nVertexAttCount;

		//! \brief �Զ������Ե�����
		TArray<VertexAttribute> m_vecVertexAttribute;

		///////////////////////////////////////////////////////////////////
		// ���е������Ƿ���UGC�еĵ��ڴ�
		Gamebool m_bUGMemory;

	public:
		~DataVertex();

		DataVertex* Copy();

		// ��ȡ���������������Զ������������е����
		int GetIndexOfTexMatrixInVertexAttData();
	};

	struct DataIndice
	{
	public:
		// ��ǰ֡������Ϣ
		Gameuint* m_Index;

		Gameushort* m_shortIndex;

		Gameint m_nIndexCount;

		// ��������
		Gameint m_nOperationType;

		// ��������
		Gameushort m_enIndexType;

		// ������ʵ������
		Gamechar* m_strRealMaterialName;

		// ����Hash��
		Gamelong m_MtlHashCode;

		// ���е������Ƿ���UGC�еĵ��ڴ�
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