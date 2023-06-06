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

			// ͶӰת�����͡���Ҫ����ͶӰ����֮�估ͶӰ����ϵ֮���ת��
			class SUPERMAP_API CoordSysTranslator
			{
			public:
				CoordSysTranslator();
				~CoordSysTranslator();

				//! \brief ��ͬһ��������ϵ�£��÷������ڽ�ָ���� Vector3d ���͵ĵ�����ͶӰ����ת������������
				//! \param 
				static Gamebool Inverse(TArray<Vector3d>& points, PrjCoordSys prjCoordSys);
				
				//! \brief ��ͬһ��������ϵ�£��÷������ڽ�ָ���� Vector3d ���͵ĵ����ĵ�������ת����ͶӰ����
				//! \param 
				static Gamebool Forward(TArray<Vector3d>& points, PrjCoordSys prjCoordSys);

			private:
				static Gamedouble* ToOneDimension(TArray<Vector3d> arr);

				static void ToThreeDimensionArr(TArray<Vector3d>& arr, Gamedouble* items);
			};
			
		}
	}
}