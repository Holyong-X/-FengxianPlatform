#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK
{
	#define CM_TO_M 0.01
	#define M_TO_CM 100
	#define NEAR_GROUND_HEIGHT_BY_METER 4000

	//! \brief 每一个实例化模型的有效信息的float个数
	#define SIZE_PER_MODEL_INSTANCE 17 
	//! \brief 每一个管线信息有效信息的float个数
	#define SIZE_PER_PIPE_INSTANCE  29
	//! \brief 世界最高峰
	#define FIXED_ALTITUDE 8848.13
	//! \brief 替换材质默认参数名
	#define DEAFAULT_UV_OFFSET_AND_SCALE TEXT("UVOffsetAndScale")

#if PLATFORM_LINUX
	typedef long long		   __int64;
	typedef long long          Gamelong;
	typedef unsigned long long Gameulong;
#else
	typedef __int64           Gamelong;
	typedef unsigned  __int64 Gameulong;
#endif
	typedef int32		   Gameint;
	typedef uint32		   Gameuint;
	typedef uint8		   Gameuint8;
	typedef unsigned char  Gameuchar;
	typedef char		   Gamechar;
	typedef unsigned short Gameushort;
	typedef float		   Gamefloat;
	typedef double		   Gamedouble;
	typedef bool		   Gamebool;
	typedef void		   Gamevoid;

#if SM_FOR_UE_FIVE
	typedef FVector2f	   GameVector2;
	typedef FVector3f	   GameVector3;
	typedef FVector4f	   GameVector4;
#else
	typedef FVector2D	   GameVector2;
	typedef FVector		   GameVector3;
	typedef FVector4	   GameVector4;
#endif

	// 动态原点的区域范围（单位厘米）
	const Gamedouble WORLD_ORIGIN_AREA = (20000.0 * M_TO_CM);

	// 动态原点
	static FIntVector m_vWorldOrigin = FIntVector(0, 0, 0);

	// 异步加载
	static Gamebool m_bEnableAsync = true;

	// 法线计算
	static Gamebool m_bEnableNormal = false;

	// 碰撞检测
	static Gamebool m_bEnableCollision = false;

	// 纹理缓存池（方便测试）
	static Gamebool m_bEnableTextureCache = false;
}