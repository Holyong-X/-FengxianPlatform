#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK
{
	#define CM_TO_M 0.01
	#define M_TO_CM 100
	#define NEAR_GROUND_HEIGHT_BY_METER 4000

	//! \brief ÿһ��ʵ����ģ�͵���Ч��Ϣ��float����
	#define SIZE_PER_MODEL_INSTANCE 17 
	//! \brief ÿһ��������Ϣ��Ч��Ϣ��float����
	#define SIZE_PER_PIPE_INSTANCE  29
	//! \brief ������߷�
	#define FIXED_ALTITUDE 8848.13
	//! \brief �滻����Ĭ�ϲ�����
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

	// ��̬ԭ�������Χ����λ���ף�
	const Gamedouble WORLD_ORIGIN_AREA = (20000.0 * M_TO_CM);

	// ��̬ԭ��
	static FIntVector m_vWorldOrigin = FIntVector(0, 0, 0);

	// �첽����
	static Gamebool m_bEnableAsync = true;

	// ���߼���
	static Gamebool m_bEnableNormal = false;

	// ��ײ���
	static Gamebool m_bEnableCollision = false;

	// ������أ�������ԣ�
	static Gamebool m_bEnableTextureCache = false;
}