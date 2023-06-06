#pragma once
#include "CoreMinimal.h"
#include "Data/GeometryType.h"
#include "Data/Geometry3D.h"
#include "Data/Vector3d.h"
#include "ControlUE/CameraControl.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class Geometry3D;
			class SUPERMAP_API GeoRegion3D :public Geometry3D
			{
			public:
				GeoRegion3D(void* pGeoRegion3D);
				GeoRegion3D();
				virtual ~GeoRegion3D();
				GeoRegion3D* Copy();
			public:
				//! \brief 返回类型
				virtual GeometryType GetType();


				//! \brief 得到所有的点
				void GetPoints(TArray<Vector3d>& arrPoints);
				void GetPoints(TArray<FVector>& arrPoints);
				void GetPoints(double* &pData , int32 &nCount);

				//得到细分插值点
				void GetSubdivisionPoints(TArray<FVector>& arrLocations, float fDistance);

				//! \brief 获取所有子对象的点的个数总和
				int32 GetPointCount();


				//! \brief 获取所有子对象的个数
				int32 GetSubCount();


				//! \brief 得到某个子对象的点的个数
				void GetPolyCounts(TArray<int32>& arrPolyCounts);


				//! \brief 三角化
				void GetTriangleIndices(TArray<int32> & indicesArray, Gameint nPrePtsNum = 0);
				
				//! \brief 添加所有点
				void SetPoints(TArray<Vector3d> arrPoints);

				//! \brief 是否为空
				bool IsEmpty();

				//! \brief 清除所有点
				void Clear();

				//! \brief 添加点
				int AddPart(TArray<Vector3d> points);

				//! \brief 插入点
				bool InsertPart(int index, TArray<Vector3d> points);

				//! \brief 移除指定点
				bool RemovePart(int index);

				//! \brief 获取内点
				Vector3d GetInnerPoint3D();
			private:

				bool ComputeSubdivision(float*& pVertexData, int32& nVertex, uint32*& pIndexes, int32& nIndice, float dMinDistance);

				//! \brief 上层持有所有点
				TArray<Vector3d> m_arrPoint3Ds;
			};

		}
	}
}