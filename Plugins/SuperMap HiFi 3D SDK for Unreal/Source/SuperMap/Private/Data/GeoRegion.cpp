#include "Data/GeoRegion.h"
#include "Algorithm3D/MathEngine.h"

using namespace SuperMapSDK::UnrealEngine::Core;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			GeoRegion::GeoRegion()
			{
				m_pUGGeometry = nullptr;
				_GeoRegion_Create(m_pUGGeometry);
			}

			GeoRegion::GeoRegion(void* pGeoPoint)
			{
				m_pUGGeometry = pGeoPoint;
			}

			GeoRegion::~GeoRegion()
			{
				_GeoRegion_Destroy(m_pUGGeometry);
			}

			GeoRegion* GeoRegion::Copy()
			{
				void* pNewGeometry = nullptr;
				_GeoRegion_Copy(m_pUGGeometry, pNewGeometry);
				GeoRegion* newGeoRegion = new GeoRegion(pNewGeometry);
				return newGeoRegion;
			}

			void  GeoRegion::SetPoints(TArray<Vector2d> arrPoints)
			{
				m_arrPoint2Ds = arrPoints;
				double* pPoints = new double[m_arrPoint2Ds.Num() * 2];
				for (int i = 0; i < m_arrPoint2Ds.Num(); i++)
				{
					pPoints[2 * i] = m_arrPoint2Ds[i].X;
					pPoints[2 * i + 1] = m_arrPoint2Ds[i].Y;
				}
				_GeoRegion_MakeWithPoints(m_pUGGeometry, pPoints, m_arrPoint2Ds.Num());
				delete[] pPoints;
				pPoints = NULL;
			}

			GeometryType GeoRegion::GetType()
			{
				return GeometryType::GT_GeoRegion;
			}
		}
	}
}