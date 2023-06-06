#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK
{
	enum PixelFormat
	{
		//! \brief 尚未设定, 内部使用
		IPF_UNKNOWN = 0,
		//! \brief 1位,单色
		IPF_MONO = 1,
		//! \brief 4位,16色
		IPF_FBIT = 4,
		//! \brief 8位无符号,256色
		IPF_UBYTE = 8,
		//! \brief 8位有符号,256色,新增
		IPF_BYTE = 80,
		//! \brief 16位有符号,彩色
		IPF_TBYTE = 16,
		//! \brief 16位无符号,彩色，新增
		IPF_UTBYTE = 160,
		//! \brief 24位,真彩色
		IPF_RGB = 24,
		//! \brief 32位,增强真彩色
		IPF_RGBA = 32,
		//! \brief 48位,真彩色
		IPF_TRGB = 48,
		//! \brief 64位,长整型
		IPF_LONGLONG = 64,
		//! \brief LONG
		IPF_LONG = 320,
		//! \brief LONG
		IPF_ULONG = 321,
		//! \brief 32位,浮点型
		IPF_FLOAT = 3200,
		//! \brief 96位格式，R通道32位（float），B通道32位（float），G通道32位（float）
		IPF_FLOAT32_RGB = 4800,
		//! \brief 128位格式，R通道32位（float），B通道32位（float），G通道32位（float）, A通道32位（float）
		IPF_FLOAT32_RGBA = 4801,
		//! \brief 64位,双精度浮点型
		IPF_DOUBLE = 6400
	};

	//! \brief 像素格式
	enum UGPixelFormat
	{
		//! \brief 未知像素格式.
		UGC_PF_UNKNOWN = 0,
		//! \brief 8位像素，用于亮度.
		UGC_PF_L8 = 1,
		UGC_PF_BYTE_L = UGC_PF_L8,
		//! \brief 16位像素，用于亮度.
		UGC_PF_L16 = 2,
		UGC_PF_SHORT_L = UGC_PF_L16,
		//! \brief 8位像素，用于alpha值.
		UGC_PF_A8 = 3,
		UGC_PF_BYTE_A = UGC_PF_A8,
		//! \brief 8位像素, 4位alpha值, 4位亮度.
		UGC_PF_A4L4 = 4,
		//! \brief 两字节像素, 一个用于alpha值，一个用于亮度
		//! \brief 8位像素, 4位亮度, 4位alpha.
		UGC_PF_L4A4 = 35,
		//! \brief 16位像素, 每4位用于BGRA.
		UGC_PF_B4G4R4A4 = 36,
		//! \brief 24位像素, 每8位用于BRG.
		UGC_PF_B8R8G8 = 37,
		//! \brief 32位像素, 每10位用于BGR, 2位用于alpha.
		UGC_PF_B10G10R10A2 = 38,
		UGC_PF_BYTE_LA = 5,
		//! \brief 16位像素格式, R,G,B为5，6，5.
		UGC_PF_R5G6B5 = 6,
		//! \brief 16位像素格式, B,G,R为5，6，5.
		UGC_PF_B5G6R5 = 7,
		//! \brief 8位像素, B,G,R为2，3，3.
		UGC_PF_R3G3B2 = 31,
		//! \brief 16位像素, alpha，R,G,B为4,4,4,4.
		UGC_PF_A4R4G4B4 = 8,
		//! \brief 16位像素, alpha，R,G,B为1,5,5,5.
		UGC_PF_A1R5G5B5 = 9,
		//! \brief 24位像素, R,G,B为8,8,8.
		UGC_PF_R8G8B8 = 10,
		//! \brief 24位像素, B,G,R为8,8,8.
		UGC_PF_B8G8R8 = 11,
		//! \brief 32位像素, alpha,R,G,B为8,8,8,8.
		UGC_PF_A8R8G8B8 = 12,
		//! \brief 32位像素, B, G, R,alpha为8,8,8,8.
		UGC_PF_A8B8G8R8 = 13,
		//! \brief 32位像素, B, G, R,alpha为8,8,8,8.
		UGC_PF_B8G8R8A8 = 14,
		//! \brief 32位像素, R, G, B,alpha为8,8,8,8.
		UGC_PF_R8G8B8A8 = 28,
		// 128位像素, 每个元素占32位
		UGC_PF_FLOAT32_RGBA = 25,
		//! \brief 32位像素, R, G, B为8，8,8。alpha无效
		UGC_PF_X8R8G8B8 = 26,
		//! \brief 32位像素, B G, R为8，8,8。alpha无效
		UGC_PF_X8B8G8R8 = 27,
		//! \brief 3字节像素, 每个颜色占一个字节
		UGC_PF_BYTE_RGB = UGC_PF_B8G8R8,
		//! \brief 3字节像素, 每个颜色占一个字节
		UGC_PF_BYTE_BGR = UGC_PF_R8G8B8,
		//! \brief 4字节像素, 每个颜色和alpha各占一个字节
		UGC_PF_BYTE_BGRA = UGC_PF_A8R8G8B8,
		//! \brief 4字节像素, 每个颜色和alpha各占一个字节
		UGC_PF_BYTE_RGBA = UGC_PF_A8B8G8R8,
		//! \brief 32位像素 两位用于alpha，每个颜色占10位
		UGC_PF_A2R10G10B10 = 15,
		//! \brief 32位像素, 两位用于alpha，每个颜色占10位
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
		// 16位像素, 用于R
		UGC_PF_FLOAT16_R = 32,
		// 48位像素, 每16位float用于RGB
		UGC_PF_FLOAT16_RGB = 22,
		// 64位像素,每16位float用于RGBA
		UGC_PF_FLOAT16_RGBA = 23,
		// 16位像素，float用于R
		UGC_PF_FLOAT32_R = 33,
		// 96位像素, 每32位float用于RGB
		UGC_PF_FLOAT32_RGB = 24,
		// 128位像素, 每32位float用于RGBA
		// 用于深度像素
		UGC_PF_DEPTH = 29,
		// 64位像素, 每16位float用于RGBA
		UGC_PF_SHORT_RGBA = 30,
		// 当前定义像素格式的数目
		UGC_PF_COUNT = 34
	};

	//! 编码类型
	enum UGCodecType
	{
		//! 不使用编码方式
		encNONE = 0,
		//{{保留原编码选项，但不使用，在下个版本去掉
		//! 使用BYTE(1)类型存储
		encBYTE = 1,
		//! 使用WORD(2)类型存储
		encWORD = 2,
		//! 使用3字节类型存储
		enc3BYTE = 3,
		//! 使用4字节类型存储
		encDWORD = 4,
		//! 使用float类型存储
		//encFLOAT	= 5,	
		//! 使用doubel类型存储	
		//encDOUBLE	= 6,	
		//! Image的压缩
		encDCT = 8,
		//! SuperMap Grid LZW encoded.
		encSGL = 9,
		//! another Grid LZW encoded.
		encLGL = 10,
		//! 适用于索引色影像的压缩方式，无损
		encLZW = 11,
		//! PNG压缩算法
		encPNG = 12,
		//}}

		//! \brief 矢量编码
		//! \brief 不使用编码方式
		envNONE = 0,
		//! \brief 使用doubel类型存储	
		//envDOUBLE	= 6,
		//! \brief 使用BYTE(1)类型存储
		envBYTE = 1,
		//! \brief 使用WORD(2)类型存储
		envWORD = 2,
		//! \brief 使用3字节类型存储
		env3BYTE = 3,
		//! \brief 使用4字节类型存储
		envDWORD = 4,
		//! \brief ZIP无损压缩方式
		envLZW = 11,
		//! \brief 使用哈夫曼编码	 
		envHfm = 13,

		//! \brief 栅格编码
		//! \brief 不使用编码方式
		enrNONE = 0,
		//! \brief Image的压缩
		enrDCT = 8,
		//! \brief SuperMap Grid 游程编码.
		enrSGL = 9,
		//! \brief another Grid 游程编码. 不再支持该类编码的创建
		enrLGL = 10,
		//! \brief 适用于索引色影像的压缩方式，无损,用的是ZIP压缩方法
		enrLZW = 11,
		//! \brief PNG压缩算法
		enrPNG = 12,
		//! \brief 使用哈夫曼编码
		enrHfm = 13,

		//! \brief s3t dxtn纹理压缩
		enrS3TCDXTN = 14,

		//! \brief lzma无损压缩
		enrLZMA = 15,

		//! \brief Gif编码
		enrGIF = 16,

		//! \brief 混合编码
		enrCompound = 17,

		//! \brief DDS+ZIP编码
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

	//! 数据类型
	enum DataType
	{
		ModelCache = 0,  //精模
		Model = 1,  //倾斜
		PointCloud = 2,  //点云
		Globe = 3,  //地形
		ModelInstance = 4,  //实例化
		ModelPro = 5,  //模型数据集
		RealtimeRaster = 6,  //实时栅格化的对象
		Star = 7,  //星空
		ClampToModel = 8,  //贴对象物体
		Atmosphere = 9	  //大气
	};

	enum SceneManagerType
	{
		//! \brief  正常的三维绘制的场景
		DRAW3D = 0,
		//! \brief  实时栅格化的场景
		REAL_TIME_RASTER = 1,
		//! \brief  实时栅格化绘制实时高程的场景
		REAL_TIME_ELEVATION = 3,
		//! \brief  实时栅格化绘制地形法线纹理的纹理的场景
		REAL_TIME_ELEVATION_NORMAL = 4,
		//! \brief  S3M模型实时栅格化绘制高程的场景
		REAL_TIME_ELEVATION_S3M = 5,
		//! \brief  地形量算实时栅格化绘制高程的场景
		REAL_TIME_ELEVATION_RULER = 6,
		//! \brief 选择场景绘制
		DRAW_SELECTION = 7,
		//! \brief  实时栅格化海洋边界的场景
		REAL_TIME_RASTER_OCEAN = 11,
		//! \brief 空间查询场景绘制
		DRAW_SPATIALQUERY = 16,
		//! \brief 空间查询标记场景绘制
		DRAW_SPATIALQUERY_COLOR = 17,
	};

	//! \brief 透明混合类型
	enum AlphaMode
	{
		PBRAM_UnKnown = 0,
		//! \brief 片元中alpha值输出为1.0,
		PBRAM_OPAQUE = 1,
		//! \brief 片元进行alpha过滤
		PBRAM_MASK = 2,
		//! \brief 片元的alpha值输出baseColor的alpha值
		PBRAM_BLEND = 3,
	};

	// 渲染状态
	enum UGRenderStateSet
	{
		RSS_ALL = 0xFFFFFFFF,		    // 在所有场景中渲染
		RSS_Normal = 0x1,				// 只正常场景渲染
		RSS_Stencil = 0x2,				// 只在蒙版场景渲染
		RSS_Selection = 0x4,		    // 只在选择场景渲染
		RSS_RayCastSelection = 0x8,				// 只在射线选择场景渲染
		RSS_VertexSelection = 0x10,				// 只在顶点捕捉场景渲染
		RSS_Query_Result = 0x20,				// 只在绘制查询结果场景渲染
		RSS_Height = 0x40,				// 只在绘制高度场景渲染
		RSS_NormalAndDepth = 0x80,				// 只在绘制法线和深度场景渲染
		RSS_OIT = 0x100,            // 只在绘制OIT场景渲染
		RSS_Composite = 0x200,             // 只在绘制屏幕合成场景时绘制的渲染状态
		RSS_RenderToTexture = 0x400,             // 只在绘制到纹理时绘制的渲染状态
		RSS_SpatialQuery = 0x800            // 只在绘制空间查询场景渲染
	};

	enum UGVertexDataStateSet
	{
		VST_ALL = 0xFFFFFFFF,		// 全部状态
		VST_Vertex = 0x1,				// 顶点状态
		VST_Normal = 0x2,				// 法线状态
		VST_VertexColor = 0x4,				// 顶点颜色状态
		VST_VertexSecondColor = 0x8,				// 顶点第二颜色状态
		VST_TexCoord = 0x10,				// 纹理坐标状态
		VST_CUSTOM0 = 0x12,			// 自定义属性0
	};

	enum VertexCompressOptions
	{
		SVC_Vertex = 1,				//顶点带压缩
		SVC_Normal = 2,				//法线带压缩
		SVC_VertexColor = 4,		//顶点颜色带压缩
		SVC_SecondColor = 8,		//SecondColor带压缩
		SVC_TexutreCoord = 16,		//纹理坐标带压缩
		SVC_TexutreCoordIsW = 32,   // 表示第一重纹理坐标存储顶点的W位
	};

	//! \brief 属性的类型
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

	// 当前渲染使用的material种类
	enum UseMaterialFlag
	{
		UMF_NORMAL = 0,    // 正常渲染使用的材质
		UMF_SELECTION = 1, // 选择使用的材质
		UMF_RECT_SELECTION = 2, // 框选使用的材质
		UMF_VIEWPORT = 3 // 多视口使用的材质
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