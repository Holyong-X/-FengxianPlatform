#include "Data/GeoBox.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			GeoBox::GeoBox()
			{
				m_pUGGeometry = nullptr;
				_GeoBox_Create(m_pUGGeometry);
				m_pRenderFeature = nullptr;
			}

			GeoBox::GeoBox(void* pGeoBox)
			{
				m_pUGGeometry = pGeoBox;
			}

			GeoBox::~GeoBox()
			{
				m_pRenderFeature = nullptr;
				//_GeoBox_Destroy(m_pUGGeometry);
			}

			GeoBox* GeoBox::Copy()
			{
				void* pNewGeometry = nullptr;
				_GeoBox_Copy(m_pUGGeometry, pNewGeometry);
				GeoBox* newGeoBox = new GeoBox(pNewGeometry);
				return newGeoBox;
			}

			void GeoBox::SetWidth(double dWidth)
			{
				_GeoBox_SetBoxWidth(m_pUGGeometry, dWidth);
				if (m_pRenderFeature != nullptr)
				{
					_RenderFeature_SetGeometry(m_pRenderFeature, m_pUGGeometry);
				}
			}

			double GeoBox::GetWidth()
			{
				return _GeoBox_GetBoxWidth(m_pUGGeometry);
			}

			void GeoBox::SetLength(double dLength)
			{
				_GeoBox_SetBoxHeight(m_pUGGeometry, dLength);
				if (m_pRenderFeature != nullptr)
				{
					_RenderFeature_SetGeometry(m_pRenderFeature, m_pUGGeometry);
				}
			}

			double GeoBox::GetLength()
			{
				return _GeoBox_GetBoxHeight(m_pUGGeometry);
			}

			void GeoBox::SetHeight(double dHeight)
			{
				_GeoBox_SetBoxLength(m_pUGGeometry, dHeight);
				if (m_pRenderFeature != nullptr)
				{
					_RenderFeature_SetGeometry(m_pRenderFeature, m_pUGGeometry);
				}
			}

			double GeoBox::GetHeight()
			{
				return _GeoBox_GetBoxLength(m_pUGGeometry);
			}

			void GeoBox::SetColor(FVector4 color)
			{
				m_vColor = color;
			}

			FVector4 GeoBox::GetColor()
			{
				return m_vColor;
			}

			Vector3d GeoBox::GetCenter()
			{
				double dX = 0, dY = 0, dZ = 0;
				_GeoBox_GetCenterPoint(m_pUGGeometry, dX, dY, dZ);

				return Vector3d(dX, dY, dZ);
			}
		}
	}
}