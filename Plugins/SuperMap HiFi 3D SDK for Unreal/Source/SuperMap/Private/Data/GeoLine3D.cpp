
#include "Data/GeoLine3D.h"
#include "Algorithm3D/MathEngine.h"
#include "ControlUE/CameraControl.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			GeoLine3D::GeoLine3D()
			{
				m_pUGGeometry = nullptr;
				Core::_GeoLine3D_Create(m_pUGGeometry);
			}

			GeoLine3D::GeoLine3D(void* pGeoLine3D)
			{
				m_pUGGeometry = pGeoLine3D;
			}

			GeoLine3D::~GeoLine3D()
			{
				Core::_GeoLine3D_Destroy(m_pUGGeometry);
			}

			GeoLine3D* GeoLine3D::Copy()
			{
				void* pNewGeometry = nullptr;
				_GeoLine3D_Copy(m_pUGGeometry, pNewGeometry);
				GeoLine3D* newGeoLine3D = new GeoLine3D(pNewGeometry);
				return newGeoLine3D;
			}

			GeometryType GeoLine3D::GetType()
			{
				return GeometryType::GT_GeoLine3D;
			}


			//! \brief 得到所有的点
			void GeoLine3D::GetPoints(TArray<Vector3d>& arrPoints)
			{
				if (m_arrPoint3Ds.Num() == 0)
				{
					double** pPoints = NULL;
					int nPointCount = 0;
					Core::_GeoLine3D_GetPointCount(m_pUGGeometry, nPointCount);
					Core::_GeoLine3D_GetPoints(m_pUGGeometry, pPoints);

					for (int i = 0; i < nPointCount; i++)
					{
						m_arrPoint3Ds.Add(Vector3d(pPoints[0][3 * i], pPoints[0][3 * i + 1], pPoints[0][3 * i + 2]));
					}
					if (pPoints != NULL && nPointCount > 0)
					{
						Core::_ReleaseDoubleArray(pPoints);
					}
				}
				arrPoints.Append(m_arrPoint3Ds);
			}

			void GeoLine3D::GetPoints(TArray<FVector>& arrPoints)
			{
				if (m_arrPoint3Ds.Num() == 0)
				{
					double** pPoints = NULL;
					int nPointCount = 0;
					Core::_GeoLine3D_GetPointCount(m_pUGGeometry, nPointCount);
					Core::_GeoLine3D_GetPoints(m_pUGGeometry, pPoints);

					for (int i = 0; i < nPointCount; i++)
					{
						m_arrPoint3Ds.Add(Vector3d(pPoints[0][3 * i], pPoints[0][3 * i + 1], pPoints[0][3 * i + 2]));
						arrPoints.Add(FVector(pPoints[0][3 * i], pPoints[0][3 * i + 1], pPoints[0][3 * i + 2]));
					}

					if (pPoints != NULL && nPointCount > 0)
					{
						Core::_ReleaseDoubleArray(pPoints);
					}
				}
				else
				{
					for (int i = 0; i < m_arrPoint3Ds.Num(); i++)
					{
						arrPoints.Add(m_arrPoint3Ds[i].ToFVector());
					}
				}
			}

			//得到细分插值点
			void GeoLine3D::GetSubdivisionPoints(TArray<FVector>& arrLocations, float fDistance)
			{
				TArray<FVector> arrPoints;
				GetPoints(arrPoints);

				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH ||
					ControlUE::CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					for (int i = 0; i < arrPoints.Num(); i++)
					{
						arrPoints[i] = MathEngine::SphericalToCartesian(arrPoints[i].X, arrPoints[i].Y, arrPoints[i].Z);
					}
				}
				MathEngine::GetSubdivisionPoints(arrPoints, arrLocations, fDistance);
			}

			//! \brief 获取所有子对象的点的个数总和
			int32 GeoLine3D::GetPointCount()
			{
				int32 nPointCount = 0;
				Core::_GeoLine3D_GetPointCount(m_pUGGeometry, nPointCount);
				return nPointCount;
			}


			//! \brief 获取所有子对象的个数
			int32 GeoLine3D::GetSubCount()
			{
				int32 nSubCount = 0;
				Core::_GeoLine3D_GetSubCount(m_pUGGeometry, nSubCount);
				return nSubCount;
			}


			void GeoLine3D::GetPolyCounts(TArray<int32>& arrPolyCounts)
			{
				int** pPolyCounts = NULL;
				int nSubCount = 0;
				Core::_GeoLine3D_GetSubCount(m_pUGGeometry, nSubCount);
				Core::_GeoLine3D_GetPolyCounts(m_pUGGeometry, pPolyCounts);

				for (int i = 0; i < nSubCount; i++)
				{
					arrPolyCounts.Add(pPolyCounts[0][i]);
				}

				Core::_ReleaseIntArray(pPolyCounts);
			}

			void  GeoLine3D::SetPoints(TArray<Vector3d> arrPoints)
			{
				m_arrPoint3Ds = arrPoints;
			}

			void GeoLine3D::Make(TArray<Vector3d> arrPoints)
			{
				Gameint nCount = arrPoints.Num();
				Gamedouble* pPoint = new Gamedouble[nCount * 3];

				for (Gameint n = 0; n < nCount; n++)
				{
					pPoint[n * 3 + 0] = arrPoints[n].X;
					pPoint[n * 3 + 1] = arrPoints[n].Y;
					pPoint[n * 3 + 2] = arrPoints[n].Z;
				}

				Gamedouble** pPoints = new Gamedouble*;
				*pPoints = pPoint;

				_GeoLine3D_Make(m_pUGGeometry, pPoints, nCount);
			}

			void GeoLine3D::AddPart(Vector3d vStart, Vector3d vEnd)
			{
				if (vStart == vEnd)
				{
					return;
				}
				Gameint nCount = 2;
				Gamedouble* pPoint = new Gamedouble[nCount * 3];
				pPoint[0] = vStart.X;
				pPoint[1] = vStart.Y;
				pPoint[2] = vStart.Z;
				pPoint[3] = vEnd.X;
				pPoint[4] = vEnd.Y;
				pPoint[5] = vEnd.Z;
				Gamedouble** pPoints = new Gamedouble*;
				*pPoints = pPoint;
				int size = _GeoLine3D_AddPart(m_pUGGeometry, pPoint, nCount);
			}

			void GeoLine3D::RemovePart(Gameint nPartIndex)
			{
				_GeoLine3D_RemovePart(m_pUGGeometry, nPartIndex);
			}
		}
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif