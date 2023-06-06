#pragma once

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{

			enum SUPERMAP_API GeometryType
			{
				//! ������
				GT_None = 0,
				//! \brief ������	
				GT_GeoPoint = 1,
				//! \brief ������
				GT_GeoLine = 3,
				//! \brief ������
				GT_GeoRegion = 5,
				//! \brief ��ά��
				GT_GeoPoint3D = 101,
				//! \brief ��ά��
				GT_GeoLine3D = 103,
				//! \brief ��ά��
				GT_GeoRegion3D = 105,
				//! \brief ģ��
				GT_GeoModel3D = 1218
			};
		}
	}
}