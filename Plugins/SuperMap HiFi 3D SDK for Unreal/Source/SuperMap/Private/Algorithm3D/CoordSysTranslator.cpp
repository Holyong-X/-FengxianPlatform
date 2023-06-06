#include "Algorithm3D/CoordSysTranslator.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Core;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Algorithm3D
		{
			CoordSysTranslator::CoordSysTranslator()
			{

			}

			CoordSysTranslator::~CoordSysTranslator()
			{

			}

			Gamebool CoordSysTranslator::Inverse(TArray<Vector3d>& points, PrjCoordSys prjCoordSys)
			{
				Gamebool bSuccess = false;
				Gamedouble* pts = ToOneDimension(points);
				bSuccess = _PrjCoordSys_Inverse(prjCoordSys.GetHandler(), pts, points.Num());
				if (bSuccess)
				{
					CoordSysTranslator::ToThreeDimensionArr(points, pts);
				}
				delete[] pts;
				return bSuccess;
			}

			Gamebool CoordSysTranslator::Forward(TArray<Vector3d>& points, PrjCoordSys prjCoordSys)
			{
				Gamebool bSuccess = false;
				Gamedouble* pts = ToOneDimension(points);
				bSuccess = _PrjCoordSys_Forward(prjCoordSys.GetHandler(), pts, points.Num());
				if (bSuccess)
				{
					CoordSysTranslator::ToThreeDimensionArr(points, pts);
				}
				delete[] pts;
				return bSuccess;
			}
			
			Gamedouble* CoordSysTranslator::ToOneDimension(TArray<Vector3d> arr)
			{
				Gamedouble* items = new Gamedouble[arr.Num() * 3];
				for (Gameint i = 0; i < arr.Num(); i++)
				{
					items[i * 3] = arr[i].X;
					items[i * 3 + 1] = arr[i].Y;
					items[i * 3 + 2] = arr[i].Z;
				}
				return items;
			}

			void CoordSysTranslator::ToThreeDimensionArr(TArray<Vector3d>& arr, Gamedouble* items)
			{
				for (Gameint i = 0; i < arr.Num(); i++)
				{
					arr[i].X = items[i * 3];
					arr[i].Y = items[i * 3 + 1];
					arr[i].Z = items[i * 3 + 2];
				}
			}
		}
	}
}