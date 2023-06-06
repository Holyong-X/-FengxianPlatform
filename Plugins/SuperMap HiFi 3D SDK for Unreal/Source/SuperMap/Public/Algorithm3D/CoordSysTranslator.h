#pragma once
#include "CoreMinimal.h"
#include "Data/Vector3d.h"
#include "Algorithm3D/PrjCoordSys.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Algorithm3D
		{
			class PrjCoordSys;

			// 投影转换类型。主要用于投影坐标之间及投影坐标系之间的转换
			class SUPERMAP_API CoordSysTranslator
			{
			public:
				CoordSysTranslator();
				~CoordSysTranslator();

				//! \brief 在同一地理坐标系下，该方法用于将指定的 Vector3d 类型的点对象的投影坐标转换到地理坐标
				//! \param 
				static Gamebool Inverse(TArray<Vector3d>& points, PrjCoordSys prjCoordSys);
				
				//! \brief 在同一地理坐标系下，该方法用于将指定的 Vector3d 类型的点对象的地理坐标转换到投影坐标
				//! \param 
				static Gamebool Forward(TArray<Vector3d>& points, PrjCoordSys prjCoordSys);

			private:
				static Gamedouble* ToOneDimension(TArray<Vector3d> arr);

				static void ToThreeDimensionArr(TArray<Vector3d>& arr, Gamedouble* items);
			};
			
		}
	}
}