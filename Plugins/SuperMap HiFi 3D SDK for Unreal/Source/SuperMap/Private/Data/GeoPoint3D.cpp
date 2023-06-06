#include "Data/GeoPoint3D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			GeoPoint3D::GeoPoint3D()
			{	
				m_pGeoPoint3D = nullptr;
				Core::_GeoPoint3D_Create(m_pGeoPoint3D);
			}

			GeoPoint3D::GeoPoint3D(void* pGeoPoint3D)
			{
				m_pGeoPoint3D = pGeoPoint3D;
			}

			GeoPoint3D::~GeoPoint3D()
			{
				Core::_GeoPoint3D_Destroy(m_pGeoPoint3D);
			}

			GeoPoint3D* GeoPoint3D::Copy()
			{
				void* pNewGeometry = nullptr;
				_GeoPoint3D_Copy(m_pUGGeometry, pNewGeometry);
				GeoPoint3D* newGeoPoint3D = new GeoPoint3D(pNewGeometry);
				return newGeoPoint3D;
			}

			GeometryType GeoPoint3D::GetType()
			{
				return GeometryType::GT_GeoPoint3D;
			}

			void GeoPoint3D::SetPoint3D(FVector vPoint3D)
			{
				double dX = vPoint3D.X;
				double dY = vPoint3D.Y;
				double dZ = vPoint3D.Z;
				Core::_GeoPoint3D_SetPoint3D(m_pGeoPoint3D, dX, dY, dZ);
			}

			Vector3d GeoPoint3D::GetPoint3D()
			{
				double dX = 0.0;
				double dY = 0.0;
				double dZ = 0.0;
				Core::_GeoPoint3D_GetPoint3D(m_pGeoPoint3D, dX, dY, dZ);

				return Vector3d(dX, dY, dZ);
			}

			Vector3d GeoPoint3D::GetPosition()
			{
				double dX = 0.0;
				double dY = 0.0;
				double dZ = 0.0;
				Core::_GeoPoint3D_GetPoint3D(m_pGeoPoint3D, dX, dY, dZ);

				return Vector3d(dX, dY, dZ);
			}
			
		}
	}
}