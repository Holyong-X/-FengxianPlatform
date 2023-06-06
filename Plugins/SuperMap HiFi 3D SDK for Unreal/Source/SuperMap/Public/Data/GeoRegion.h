#pragma once

#include "CoreMinimal.h"
#include "Data/Geometry.h"
#include "Core/RealspaceDLL.h"
#include "Data/GeometryType.h"
#include "Data/Vector2d.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API GeoRegion : public Geometry
			{
			public:
				GeoRegion();
				GeoRegion(void* pGeoRegion);
				virtual ~GeoRegion();
				GeoRegion* Copy();

				void  SetPoints(TArray<Vector2d> arrPoints);

				GeometryType GetType();
			private:

				//! \brief 上层持有所有点
				TArray<Vector2d> m_arrPoint2Ds;
			};
		}
	}
}
