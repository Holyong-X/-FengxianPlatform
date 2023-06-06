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

				//! \brief ��������
				virtual GeometryType GetType();

				//! \brief �õ����еĵ�
				void GetPoints(TArray<Vector3d>& arrPoints);
				void GetPoints(TArray<FVector>& arrPoints);

				//�õ�ϸ�ֲ�ֵ��
				void GetSubdivisionPoints(TArray<FVector>& arrLocations, float fDistance);

				//! \brief ��ȡ�����Ӷ���ĵ�ĸ����ܺ�
				int32 GetPointCount();


				//! \brief ��ȡ�����Ӷ���ĸ���
				int32 GetSubCount();


				//! \brief �õ�ĳ���Ӷ���ĵ�ĸ���
				void GetPolyCounts(TArray<int32>& arrPolyCounts);

				void SetPoints(TArray<Vector3d> arrPoints);

				//! \brief �����Ӷ���
				void Make(TArray<Vector3d> arrPoints);

				//! \brief �������Ӷ�����Ϊ����
				void AddPart(Vector3d vStart, Vector3d vEnd);

				//! \brief �������Ӷ���ɾ��
				void RemovePart(Gameint nPartIndex);

			private:
				//! \brief �ϲ�������е�
				TArray<Vector3d> m_arrPoint3Ds;
			};

		}
	}
}



	


