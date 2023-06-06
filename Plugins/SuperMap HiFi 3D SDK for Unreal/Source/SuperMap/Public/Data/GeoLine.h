#pragma once

#include "CoreMinimal.h"
#include "Data/Geometry.h"
#include "Core/RealspaceDLL.h"
#include "Data/GeometryType.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API GeoLine : public Geometry
			{
			public:
				GeoLine();
				GeoLine(void* pGeoLine);
				virtual ~GeoLine();
				GeoLine* Copy();
				//! \brief 得到所有的点
				void GetPoints(TArray<FVector2D>& arrPoints);

			private:
				//! \brief 返回类型
				virtual GeometryType GetType();

				//! \brief 获取所有子对象的点的个数总和
				int32 GetPointCount();

				//! \brief 获取所有子对象的个数
				int32 GetSubCount();

				//! \brief 得到某个子对象的点的个数
				void GetPolyCounts(TArray<int32>& arrPolyCounts);

				void SetPoints(TArray<FVector2D> arrPoints);
			
			private:
				//! \brief 上层持有所有点
				TArray<FVector2D> m_arrPoint2Ds;
			};
		}
	}
}
