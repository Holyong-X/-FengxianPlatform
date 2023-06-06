#include "Data/GeoLine.h"

using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			GeoLine::GeoLine()
			{
				m_pUGGeometry = nullptr;
				_GeoLine_Create(m_pUGGeometry);
			}

			GeoLine::GeoLine(void* pGeoLine)
			{
				m_pUGGeometry = pGeoLine;
			}

			GeoLine::~GeoLine()
			{
				_GeoLine_Destroy(m_pUGGeometry);
			}

			GeoLine* GeoLine::Copy()
			{
				void* pNewGeometry = nullptr;
				_GeoLine_Copy(m_pUGGeometry, pNewGeometry);
				GeoLine* newGeoLine = new GeoLine(pNewGeometry);
				return newGeoLine;
			}

			GeometryType GeoLine::GetType()
			{
				return GeometryType::GT_GeoLine;
			}

			void GeoLine::GetPoints(TArray<FVector2D>& arrPoints)
			{
				if (m_arrPoint2Ds.Num() == 0)
				{
					double** pPoints = NULL;
					int32 nPointCount = 0;
					_GeoLine_GetPointCount(m_pUGGeometry, nPointCount);
					_GeoLine_GetPoints(m_pUGGeometry, pPoints);

					for (int32 i = 0; i < nPointCount; i++)
					{
						m_arrPoint2Ds.Add(FVector2D(pPoints[0][2 * i], pPoints[0][2 * i + 1]));
					}
					if (nPointCount > 0)
					{
						_ReleaseDoubleArray(pPoints);
					}
				}
				arrPoints.Append(m_arrPoint2Ds);
			}

			int32 GeoLine::GetPointCount()
			{
				int32 nPointCount = 0;
				_GeoLine_GetPointCount(m_pUGGeometry, nPointCount);
				return nPointCount;
			}

			int32 GeoLine::GetSubCount()
			{
				int32 nSubCount = 0;
				_GeoLine_GetSubCount(m_pUGGeometry, nSubCount);
				return nSubCount;
			}

			void GeoLine::GetPolyCounts(TArray<int32>& arrPolyCounts)
			{
				int32** pPolyCounts = NULL;
				int32 nSubCount = 0;
				_GeoLine_GetSubCount(m_pUGGeometry, nSubCount);
				_GeoLine_GetPolyCounts(m_pUGGeometry, pPolyCounts);

				for (int32 i = 0; i < nSubCount; i++)
				{
					arrPolyCounts.Add(pPolyCounts[0][i]);
				}

				_ReleaseIntArray(pPolyCounts);
			}

			void GeoLine::SetPoints(TArray<FVector2D> arrPoints)
			{
				m_arrPoint2Ds = arrPoints;
			}
		}
	}
}