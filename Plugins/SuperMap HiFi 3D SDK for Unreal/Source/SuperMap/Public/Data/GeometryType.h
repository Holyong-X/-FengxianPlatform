#pragma once

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{

			enum SUPERMAP_API GeometryType
			{
				//! 空类型
				GT_None = 0,
				//! \brief 点类型	
				GT_GeoPoint = 1,
				//! \brief 线类型
				GT_GeoLine = 3,
				//! \brief 面类型
				GT_GeoRegion = 5,
				//! \brief 三维点
				GT_GeoPoint3D = 101,
				//! \brief 三维线
				GT_GeoLine3D = 103,
				//! \brief 三维面
				GT_GeoRegion3D = 105,
				//! \brief 模型
				GT_GeoModel3D = 1218
			};
		}
	}
}