#pragma once

#include "CoreMinimal.h"
#include "Data/GeometryType.h"
#include "Data/Geometry3D.h"
#include "Data/Vector3d.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Base3D
		{
			class SUPERMAP_API Plane
			{
			public:
				Plane();
				Plane(Vector3d vNormal, Gamedouble dDistance);
				Plane(const Plane & plane);
				~Plane();

				Vector3d GetNormal();
				Gamedouble GetPlaneDistance();

			private:
				//! \brief ��Ա��ķ�����
				Vector3d m_vNormal;

				//! \brief ��Ա�����ԭ��ľ���
				Gamedouble m_dDistance;
			};
		}
	}
}