#include "Data/Geometry.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Geometry::Geometry()
			{

			}

			Geometry::~Geometry()
			{

			}

			void* Geometry::GetHandler()
			{
				return m_pUGGeometry;
			}

			void Geometry::SetRenderFeature(void* pRenderFeature)
			{
				m_pRenderFeature = pRenderFeature;
			}

			Style3D* Geometry::GetStyle3D()
			{
				void* pStyle = nullptr;
				_Geometry_GetStyle(m_pUGGeometry, pStyle);
				Style3D* pStyle3D = new Style3D(pStyle);
				return pStyle3D;
			}

			void Geometry::SetStyle3D(Style3D* pStyle)
			{
				_Geometry_SetStyle(m_pUGGeometry, pStyle->GetHandler());
			}

			Rectangle2D Geometry::GetBounds()
			{
				Gamedouble left = 0, top = 0, right = 0, bottom = 0;
				_Geometry_GetBounds(m_pUGGeometry, left, right, top, bottom);
				Rectangle2D rec = Rectangle2D(left, top, right, bottom);
				return rec;
			}
		}
	}
}