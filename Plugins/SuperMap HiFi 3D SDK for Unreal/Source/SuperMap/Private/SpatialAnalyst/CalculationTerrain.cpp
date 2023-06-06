#include "SpatialAnalyst/CalculationTerrain.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst
		{
			CalculationTerrain::CalculationTerrain()
			{
				m_dFillVolume = 0.0;
				m_dCutVolume = 0.0;
				m_dFillArea = 0.0;
				m_dCutArea = 0.0;
				m_dNoChangeArea = 0.0;

			}

			CalculationTerrain::~CalculationTerrain()
			{

			}

			Gamebool CalculationTerrain::CutFill(GeoRegion* pGeoRegion, Gamedouble dperPixel, Gamedouble baseAltitude)
			{
				Gamebool result = _CutFill(pGeoRegion->GetHandler(), dperPixel, baseAltitude,
					m_dFillVolume, m_dCutVolume, m_dFillArea, m_dCutArea, m_dNoChangeArea);
				return result;
			}

			Gamedouble CalculationTerrain::GetFillVolume()
			{
				return m_dFillVolume;
			}

			Gamedouble CalculationTerrain::GetCutVolume()
			{
				return m_dCutVolume;
			}

			Gamedouble CalculationTerrain::GetFillArea()
			{
				return m_dFillArea;
			}

			Gamedouble CalculationTerrain::GetCutArea()
			{
				return m_dCutArea;
			}

			Gamedouble CalculationTerrain::GetNoChangeArea()
			{
				return m_dNoChangeArea;
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif