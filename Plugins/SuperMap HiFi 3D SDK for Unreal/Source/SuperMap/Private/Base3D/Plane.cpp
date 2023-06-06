#include "Base3D/Plane.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Base3D
		{
			Plane::Plane()
			{

			}

			Plane::Plane(Vector3d vNormal, Gamedouble dDistance)
			{
				m_vNormal = vNormal;
				m_dDistance = dDistance;
			}

			Plane::Plane(const Plane & plane)
			{
				m_vNormal = plane.m_vNormal;
				m_dDistance = plane.m_dDistance;
			}

			Plane::~Plane()
			{

			}

			Vector3d Plane::GetNormal()
			{
				return m_vNormal;
			}

			Gamedouble Plane::GetPlaneDistance()
			{
				return m_dDistance;
			}
		}
	}
}