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
				//! \brief �õ����еĵ�
				void GetPoints(TArray<FVector2D>& arrPoints);

			private:
				//! \brief ��������
				virtual GeometryType GetType();

				//! \brief ��ȡ�����Ӷ���ĵ�ĸ����ܺ�
				int32 GetPointCount();

				//! \brief ��ȡ�����Ӷ���ĸ���
				int32 GetSubCount();

				//! \brief �õ�ĳ���Ӷ���ĵ�ĸ���
				void GetPolyCounts(TArray<int32>& arrPolyCounts);

				void SetPoints(TArray<FVector2D> arrPoints);
			
			private:
				//! \brief �ϲ�������е�
				TArray<FVector2D> m_arrPoint2Ds;
			};
		}
	}
}
