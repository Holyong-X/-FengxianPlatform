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
			class SUPERMAP_API GeoBox : public Geometry3D
			{
			public:
				GeoBox();
				GeoBox(void* pGeoBox);
				virtual ~GeoBox();
				GeoBox* Copy();
			public:
				//! \brief ���ÿ��
				void SetWidth(double dWidth);

				//! \brief ��ȡ���
				double GetWidth();

				//! \brief ���ó���
				void SetLength(double dLength);

				//! \brief ��ȡ����
				double GetLength();

				//! \brief ���ø߶�
				void SetHeight(double dHeight);

				//! \brief ��ȡ�߶�
				double GetHeight();

				//! \brief �ü�������ɫ
				void SetColor(FVector4 color);
				FVector4 GetColor();

				//! \brief ��ȡ�����
				Vector3d GetCenter();
			private:
				//! \brief ������ɫ
				FVector4 m_vColor;
			};
		} 
	}
}