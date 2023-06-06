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
				//! \brief ��������
				virtual GeometryType GetType();


				//! \brief �õ����еĵ�
				void GetPoints(TArray<Vector3d>& arrPoints);
				void GetPoints(TArray<FVector>& arrPoints);
				void GetPoints(double* &pData , int32 &nCount);

				//�õ�ϸ�ֲ�ֵ��
				void GetSubdivisionPoints(TArray<FVector>& arrLocations, float fDistance);

				//! \brief ��ȡ�����Ӷ���ĵ�ĸ����ܺ�
				int32 GetPointCount();


				//! \brief ��ȡ�����Ӷ���ĸ���
				int32 GetSubCount();


				//! \brief �õ�ĳ���Ӷ���ĵ�ĸ���
				void GetPolyCounts(TArray<int32>& arrPolyCounts);


				//! \brief ���ǻ�
				void GetTriangleIndices(TArray<int32> & indicesArray, Gameint nPrePtsNum = 0);
				
				//! \brief ������е�
				void SetPoints(TArray<Vector3d> arrPoints);

				//! \brief �Ƿ�Ϊ��
				bool IsEmpty();

				//! \brief ������е�
				void Clear();

				//! \brief ��ӵ�
				int AddPart(TArray<Vector3d> points);

				//! \brief �����
				bool InsertPart(int index, TArray<Vector3d> points);

				//! \brief �Ƴ�ָ����
				bool RemovePart(int index);

				//! \brief ��ȡ�ڵ�
				Vector3d GetInnerPoint3D();
			private:

				bool ComputeSubdivision(float*& pVertexData, int32& nVertex, uint32*& pIndexes, int32& nIndice, float dMinDistance);

				//! \brief �ϲ�������е�
				TArray<Vector3d> m_arrPoint3Ds;
			};

		}
	}
}