#include "Data/Geometry3D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Geometry3D::Geometry3D()
			{

			}

			Geometry3D::~Geometry3D()
			{

			}

			GeometryType Geometry3D::GetType()
			{
				return GeometryType::GT_None;
			}

			void Geometry3D::SetPosition(Vector3d vPos)
			{
				_Geometry3D_SetPosition(m_pUGGeometry, vPos.X,  vPos.Y, vPos.Z);
				if (m_pRenderFeature != nullptr)
				{
					_RenderFeature_SetGeometry(m_pRenderFeature, m_pUGGeometry);
				}
			}

			Vector3d Geometry3D::GetPosition()
			{
				double dX = 0, dY = 0, dZ = 0;
				_Geometry3D_GetPosition(m_pUGGeometry, dX, dY, dZ);

				return Vector3d(dX, dY, dZ);
			}

			void Geometry3D::SetRotation(double dRotateX, double dRotateY, double dRotateZ)
			{
				_Geometry3D_SetRotation(m_pUGGeometry, dRotateX, dRotateY, dRotateZ);
				if (m_pRenderFeature != nullptr)
				{
					_RenderFeature_SetGeometry(m_pRenderFeature, m_pUGGeometry);
				}
			}

			Vector3d Geometry3D::GetRotation()
			{
				double dX = 0, dY = 0, dZ = 0;
				_Geometry3D_GetRotation(m_pUGGeometry, dX, dY, dZ);

				return Vector3d(dX, dY, dZ);
			}

			void Geometry3D::SetScale(double dScaleX, double dScaleY, double dScaleZ)
			{
				_Geometry3D_SetScale(m_pUGGeometry, dScaleX, dScaleY, dScaleZ);
				if (m_pRenderFeature != nullptr)
				{
					_RenderFeature_SetGeometry(m_pRenderFeature, m_pUGGeometry);
				}
			}

			Vector3d Geometry3D::GetScale()
			{
				double dX = 0, dY = 0, dZ = 0;
				_Geometry3D_GetScale(m_pUGGeometry, dX, dY, dZ);

				return Vector3d(dX, dY, dZ);
			}
		}
	}
}