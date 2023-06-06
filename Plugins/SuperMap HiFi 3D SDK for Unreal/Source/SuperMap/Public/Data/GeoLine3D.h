#pragma once


#include "CoreMinimal.h"
#include "Data/GeometryType.h"
#include "Data/Geometry3D.h"
#include "Data/Vector3d.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			
			class SUPERMAP_API GeoLine3D : public Geometry3D
			{
			public:
				GeoLine3D();
				GeoLine3D(void* pGeoLine3D);
				virtual ~GeoLine3D();
				GeoLine3D* Copy();
			public:

				//! \brief 返回类型
				virtual GeometryType GetType();

				//! \brief 得到所有的点
				void GetPoints(TArray<Vector3d>& arrPoints);
				void GetPoints(TArray<FVector>& arrPoints);

				//得到细分插值点
				void GetSubdivisionPoints(TArray<FVector>& arrLocations, float fDistance);

				//! \brief 获取所有子对象的点的个数总和
				int32 GetPointCount();


				//! \brief 获取所有子对象的个数
				int32 GetSubCount();


				//! \brief 得到某个子对象的点的个数
				void GetPolyCounts(TArray<int32>& arrPolyCounts);

				void SetPoints(TArray<Vector3d> arrPoints);

				//! \brief 创建子对象
				void Make(TArray<Vector3d> arrPoints);

				//! \brief 将所有子对象视为整体
				void AddPart(Vector3d vStart, Vector3d vEnd);

				//! \brief 将所有子对象删除
				void RemovePart(Gameint nPartIndex);

			private:
				//! \brief 上层持有所有点
				TArray<Vector3d> m_arrPoint3Ds;
			};

		}
	}
}



	


