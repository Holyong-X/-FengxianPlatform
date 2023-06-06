#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK
{
	enum PixelFormat
	{
		//! \brief ��δ�趨, �ڲ�ʹ��
		IPF_UNKNOWN = 0,
		//! \brief 1λ,��ɫ
		IPF_MONO = 1,
		//! \brief 4λ,16ɫ
		IPF_FBIT = 4,
		//! \brief 8λ�޷���,256ɫ
		IPF_UBYTE = 8,
		//! \brief 8λ�з���,256ɫ,����
		IPF_BYTE = 80,
		//! \brief 16λ�з���,��ɫ
		IPF_TBYTE = 16,
		//! \brief 16λ�޷���,��ɫ������
		IPF_UTBYTE = 160,
		//! \brief 24λ,���ɫ
		IPF_RGB = 24,
		//! \brief 32λ,��ǿ���ɫ
		IPF_RGBA = 32,
		//! \brief 48λ,���ɫ
		IPF_TRGB = 48,
		//! \brief 64λ,������
		IPF_LONGLONG = 64,
		//! \brief LONG
		IPF_LONG = 320,
		//! \brief LONG
		IPF_ULONG = 321,
		//! \brief 32λ,������
		IPF_FLOAT = 3200,
		//! \brief 96λ��ʽ��Rͨ��32λ��float����Bͨ��32λ��float����Gͨ��32λ��float��
		IPF_FLOAT32_RGB = 4800,
		//! \brief 128λ��ʽ��Rͨ��32λ��float����Bͨ��32λ��float����Gͨ��32λ��float��, Aͨ��32λ��float��
		IPF_FLOAT32_RGBA = 4801,
		//! \brief 64λ,˫���ȸ�����
		IPF_DOUBLE = 6400
	};

	//! \brief ���ظ�ʽ
	enum UGPixelFormat
	{
		//! \brief δ֪���ظ�ʽ.
		UGC_PF_UNKNOWN = 0,
		//! \brief 8λ���أ���������.
		UGC_PF_L8 = 1,
		UGC_PF_BYTE_L = UGC_PF_L8,
		//! \brief 16λ���أ���������.
		UGC_PF_L16 = 2,
		UGC_PF_SHORT_L = UGC_PF_L16,
		//! \brief 8λ���أ�����alphaֵ.
		UGC_PF_A8 = 3,
		UGC_PF_BYTE_A = UGC_PF_A8,
		//! \brief 8λ����, 4λalphaֵ, 4λ����.
		UGC_PF_A4L4 = 4,
		//! \brief ���ֽ�����, һ������alphaֵ��һ����������
		//! \brief 8λ����, 4λ����, 4λalpha.
		UGC_PF_L4A4 = 35,
		//! \brief 16λ����, ÿ4λ����BGRA.
		UGC_PF_B4G4R4A4 = 36,
		//! \brief 24λ����, ÿ8λ����BRG.
		UGC_PF_B8R8G8 = 37,
		//! \brief 32λ����, ÿ10λ����BGR, 2λ����alpha.
		UGC_PF_B10G10R10A2 = 38,
		UGC_PF_BYTE_LA = 5,
		//! \brief 16λ���ظ�ʽ, R,G,BΪ5��6��5.
		UGC_PF_R5G6B5 = 6,
		//! \brief 16λ���ظ�ʽ, B,G,RΪ5��6��5.
		UGC_PF_B5G6R5 = 7,
		//! \brief 8λ����, B,G,RΪ2��3��3.
		UGC_PF_R3G3B2 = 31,
		//! \brief 16λ����, alpha��R,G,BΪ4,4,4,4.
		UGC_PF_A4R4G4B4 = 8,
		//! \brief 16λ����, alpha��R,G,BΪ1,5,5,5.
		UGC_PF_A1R5G5B5 = 9,
		//! \brief 24λ����, R,G,BΪ8,8,8.
		UGC_PF_R8G8B8 = 10,
		//! \brief 24λ����, B,G,RΪ8,8,8.
		UGC_PF_B8G8R8 = 11,
		//! \brief 32λ����, alpha,R,G,BΪ8,8,8,8.
		UGC_PF_A8R8G8B8 = 12,
		//! \brief 32λ����, B, G, R,alphaΪ8,8,8,8.
		UGC_PF_A8B8G8R8 = 13,
		//! \brief 32λ����, B, G, R,alphaΪ8,8,8,8.
		UGC_PF_B8G8R8A8 = 14,
		//! \brief 32λ����, R, G, B,alphaΪ8,8,8,8.
		UGC_PF_R8G8B8A8 = 28,
		// 128λ����, ÿ��Ԫ��ռ32λ
		UGC_PF_FLOAT32_RGBA = 25,
		//! \brief 32λ����, R, G, BΪ8��8,8��alpha��Ч
		UGC_PF_X8R8G8B8 = 26,
		//! \brief 32λ����, B G, RΪ8��8,8��alpha��Ч
		UGC_PF_X8B8G8R8 = 27,
		//! \brief 3�ֽ�����, ÿ����ɫռһ���ֽ�
		UGC_PF_BYTE_RGB = UGC_PF_B8G8R8,
		//! \brief 3�ֽ�����, ÿ����ɫռһ���ֽ�
		UGC_PF_BYTE_BGR = UGC_PF_R8G8B8,
		//! \brief 4�ֽ�����, ÿ����ɫ��alpha��ռһ���ֽ�
		UGC_PF_BYTE_BGRA = UGC_PF_A8R8G8B8,
		//! \brief 4�ֽ�����, ÿ����ɫ��alpha��ռһ���ֽ�
		UGC_PF_BYTE_RGBA = UGC_PF_A8B8G8R8,
		//! \brief 32λ���� ��λ����alpha��ÿ����ɫռ10λ
		UGC_PF_A2R10G10B10 = 15,
		//! \brief 32λ����, ��λ����alpha��ÿ����ɫռ10λ
		UGC_PF_A2B10G10R10 = 16,
		//! \brief DirectDraw Surface (DDS) DXT1 format
		UGC_PF_DXT1 = 17,
		//! \brief DirectDraw Surface (DDS) DXT2 format
		UGC_PF_DXT2 = 18,
		//! \brief DirectDraw Surface (DDS) DXT3 format
		UGC_PF_DXT3 = 19,
		//! \brief DirectDraw Surface (DDS) DXT4 format
		UGC_PF_DXT4 = 20,
		//! \brief DirectDraw Surface (DDS)) DXT5 format
		UGC_PF_DXT5 = 21,
		// 16λ����, ����R
		UGC_PF_FLOAT16_R = 32,
		// 48λ����, ÿ16λfloat����RGB
		UGC_PF_FLOAT16_RGB = 22,
		// 64λ����,ÿ16λfloat����RGBA
		UGC_PF_FLOAT16_RGBA = 23,
		// 16λ���أ�float����R
		UGC_PF_FLOAT32_R = 33,
		// 96λ����, ÿ32λfloat����RGB
		UGC_PF_FLOAT32_RGB = 24,
		// 128λ����, ÿ32λfloat����RGBA
		// �����������
		UGC_PF_DEPTH = 29,
		// 64λ����, ÿ16λfloat����RGBA
		UGC_PF_SHORT_RGBA = 30,
		// ��ǰ�������ظ�ʽ����Ŀ
		UGC_PF_COUNT = 34
	};

	//! ��������
	enum UGCodecType
	{
		//! ��ʹ�ñ��뷽ʽ
		encNONE = 0,
		//{{����ԭ����ѡ�����ʹ�ã����¸��汾ȥ��
		//! ʹ��BYTE(1)���ʹ洢
		encBYTE = 1,
		//! ʹ��WORD(2)���ʹ洢
		encWORD = 2,
		//! ʹ��3�ֽ����ʹ洢
		enc3BYTE = 3,
		//! ʹ��4�ֽ����ʹ洢
		encDWORD = 4,
		//! ʹ��float���ʹ洢
		//encFLOAT	= 5,	
		//! ʹ��doubel���ʹ洢	
		//encDOUBLE	= 6,	
		//! Image��ѹ��
		encDCT = 8,
		//! SuperMap Grid LZW encoded.
		encSGL = 9,
		//! another Grid LZW encoded.
		encLGL = 10,
		//! ����������ɫӰ���ѹ����ʽ������
		encLZW = 11,
		//! PNGѹ���㷨
		encPNG = 12,
		//}}

		//! \brief ʸ������
		//! \brief ��ʹ�ñ��뷽ʽ
		envNONE = 0,
		//! \brief ʹ��doubel���ʹ洢	
		//envDOUBLE	= 6,
		//! \brief ʹ��BYTE(1)���ʹ洢
		envBYTE = 1,
		//! \brief ʹ��WORD(2)���ʹ洢
		envWORD = 2,
		//! \brief ʹ��3�ֽ����ʹ洢
		env3BYTE = 3,
		//! \brief ʹ��4�ֽ����ʹ洢
		envDWORD = 4,
		//! \brief ZIP����ѹ����ʽ
		envLZW = 11,
		//! \brief ʹ�ù���������	 
		envHfm = 13,

		//! \brief դ�����
		//! \brief ��ʹ�ñ��뷽ʽ
		enrNONE = 0,
		//! \brief Image��ѹ��
		enrDCT = 8,
		//! \brief SuperMap Grid �γ̱���.
		enrSGL = 9,
		//! \brief another Grid �γ̱���. ����֧�ָ������Ĵ���
		enrLGL = 10,
		//! \brief ����������ɫӰ���ѹ����ʽ������,�õ���ZIPѹ������
		enrLZW = 11,
		//! \brief PNGѹ���㷨
		enrPNG = 12,
		//! \brief ʹ�ù���������
		enrHfm = 13,

		//! \brief s3t dxtn����ѹ��
		enrS3TCDXTN = 14,

		//! \brief lzma����ѹ��
		enrLZMA = 15,

		//! \brief Gif����
		enrGIF = 16,

		//! \brief ��ϱ���
		enrCompound = 17,

		//! \brief DDS+ZIP����
		enrDDSZIP = 18,

		//! \brief pvr PVRTC2  2 or 4 bpp,may be ipad4 will support... wxh
		enrPVRTPF_PVRTC2 = 19,

		//! \brief pvr PVRTC  2 or 4 bpp the ipad3 only support pvrtc1 default 2bpp
		enrPVRTPF_PVRTC = 20,

		//! \brief pvr PVRTC  2 or 4 bpp this is 4bpp
		enrPVRTPF_PVRTC_4bpp = 21,

		//! \brief Ericsson Texture compression version 1, standard format for openGL ES 2.0.  added by shansg
		enrPVRTPF_ETC1 = 22,

		//! \brief JPG
		enrJPG = 23,

		//! \brief pvr PVRTCFAST
		enrPVRTPF_PVRTC_FAST = 24,

		//! \brief WEBP
		enrWEBP = 25,

		//! \brief CRN_DXT5
		enrCRN_DXT5 = 26,
	};

	//! ��������
	enum DataType
	{
		ModelCache = 0,  //��ģ
		Model = 1,  //��б
		PointCloud = 2,  //����
		Globe = 3,  //����
		ModelInstance = 4,  //ʵ����
		ModelPro = 5,  //ģ�����ݼ�
		RealtimeRaster = 6,  //ʵʱդ�񻯵Ķ���
		Star = 7,  //�ǿ�
		ClampToModel = 8,  //����������
		Atmosphere = 9	  //����
	};

	enum SceneManagerType
	{
		//! \brief  ��������ά���Ƶĳ���
		DRAW3D = 0,
		//! \brief  ʵʱդ�񻯵ĳ���
		REAL_TIME_RASTER = 1,
		//! \brief  ʵʱդ�񻯻���ʵʱ�̵߳ĳ���
		REAL_TIME_ELEVATION = 3,
		//! \brief  ʵʱդ�񻯻��Ƶ��η������������ĳ���
		REAL_TIME_ELEVATION_NORMAL = 4,
		//! \brief  S3Mģ��ʵʱդ�񻯻��Ƹ̵߳ĳ���
		REAL_TIME_ELEVATION_S3M = 5,
		//! \brief  ��������ʵʱդ�񻯻��Ƹ̵߳ĳ���
		REAL_TIME_ELEVATION_RULER = 6,
		//! \brief ѡ�񳡾�����
		DRAW_SELECTION = 7,
		//! \brief  ʵʱդ�񻯺���߽�ĳ���
		REAL_TIME_RASTER_OCEAN = 11,
		//! \brief �ռ��ѯ��������
		DRAW_SPATIALQUERY = 16,
		//! \brief �ռ��ѯ��ǳ�������
		DRAW_SPATIALQUERY_COLOR = 17,
	};

	//! \brief ͸���������
	enum AlphaMode
	{
		PBRAM_UnKnown = 0,
		//! \brief ƬԪ��alphaֵ���Ϊ1.0,
		PBRAM_OPAQUE = 1,
		//! \brief ƬԪ����alpha����
		PBRAM_MASK = 2,
		//! \brief ƬԪ��alphaֵ���baseColor��alphaֵ
		PBRAM_BLEND = 3,
	};

	// ��Ⱦ״̬
	enum UGRenderStateSet
	{
		RSS_ALL = 0xFFFFFFFF,		    // �����г�������Ⱦ
		RSS_Normal = 0x1,				// ֻ����������Ⱦ
		RSS_Stencil = 0x2,				// ֻ���ɰ泡����Ⱦ
		RSS_Selection = 0x4,		    // ֻ��ѡ�񳡾���Ⱦ
		RSS_RayCastSelection = 0x8,				// ֻ������ѡ�񳡾���Ⱦ
		RSS_VertexSelection = 0x10,				// ֻ�ڶ��㲶׽������Ⱦ
		RSS_Query_Result = 0x20,				// ֻ�ڻ��Ʋ�ѯ���������Ⱦ
		RSS_Height = 0x40,				// ֻ�ڻ��Ƹ߶ȳ�����Ⱦ
		RSS_NormalAndDepth = 0x80,				// ֻ�ڻ��Ʒ��ߺ���ȳ�����Ⱦ
		RSS_OIT = 0x100,            // ֻ�ڻ���OIT������Ⱦ
		RSS_Composite = 0x200,             // ֻ�ڻ�����Ļ�ϳɳ���ʱ���Ƶ���Ⱦ״̬
		RSS_RenderToTexture = 0x400,             // ֻ�ڻ��Ƶ�����ʱ���Ƶ���Ⱦ״̬
		RSS_SpatialQuery = 0x800            // ֻ�ڻ��ƿռ��ѯ������Ⱦ
	};

	enum UGVertexDataStateSet
	{
		VST_ALL = 0xFFFFFFFF,		// ȫ��״̬
		VST_Vertex = 0x1,				// ����״̬
		VST_Normal = 0x2,				// ����״̬
		VST_VertexColor = 0x4,				// ������ɫ״̬
		VST_VertexSecondColor = 0x8,				// ����ڶ���ɫ״̬
		VST_TexCoord = 0x10,				// ��������״̬
		VST_CUSTOM0 = 0x12,			// �Զ�������0
	};

	enum VertexCompressOptions
	{
		SVC_Vertex = 1,				//�����ѹ��
		SVC_Normal = 2,				//���ߴ�ѹ��
		SVC_VertexColor = 4,		//������ɫ��ѹ��
		SVC_SecondColor = 8,		//SecondColor��ѹ��
		SVC_TexutreCoord = 16,		//���������ѹ��
		SVC_TexutreCoordIsW = 32,   // ��ʾ��һ����������洢�����Wλ
	};

	//! \brief ���Ե�����
	enum VertexAttributeType
	{
		AT_32BIT = 0,
		AT_FLOAT = 1,
		AT_DOUBLE = 2,
		AT_16BIT = 3,
	};

	enum VertexAttributeDescript
	{
		VERTEXWEIGHT = 0,
		TEXTURECOORDMATRIX = 1,
		TILINGTEXTURECOORDS = 2
	};

	enum InstanceTpye
	{
		IT_NONE = 0,
		IT_MODEL = 1,
		IT_PIPE = 2
	};

	// ��ǰ��Ⱦʹ�õ�material����
	enum UseMaterialFlag
	{
		UMF_NORMAL = 0,    // ������Ⱦʹ�õĲ���
		UMF_SELECTION = 1, // ѡ��ʹ�õĲ���
		UMF_RECT_SELECTION = 2, // ��ѡʹ�õĲ���
		UMF_VIEWPORT = 3 // ���ӿ�ʹ�õĲ���
	};

	// CullMode
	enum CullingMode
	{
		//! \brief Hardware never culls triangles and renders everything it receives.
		CULL_NONE = 1,
		//! \brief Hardware culls triangles whose vertices are listed clockwise in the view (default).
		CULL_CLOCKWISE = 2,
		//! \brief Hardware culls triangles whose vertices are listed anticlockwise in the view.
		CULL_ANTICLOCKWISE = 3
	};

	enum EntityType
	{
		ET_NONE = 0,
		ET_NORMAL = 1,
		ET_INSTANCE = 2,
	};
}