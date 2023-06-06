#pragma once

#include "CoreMinimal.h"
#include "Data/GeometryType.h"
#include "Data/Geometry.h"
#include "Data/Vector3d.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API Geometry3D : public Geometry
			{
			public:
				Geometry3D();
				virtual ~Geometry3D();
			public:
				//! \brief ��������
				virtual GeometryType GetType();

				//! \brief �������ĵ�
				void SetPosition(Vector3d vPos);

				//! \brief ��ȡ���ĵ�
				Vector3d GetPosition();

				//! \brief ������ת
				void SetRotation(double dRotateX, double dRotateY, double dRotateZ);

				//! \brief ��ȡ��ת
				Vector3d GetRotation();

				//! \brief ��������
				void SetScale(double dScaleX, double dScaleY, double dScaleZ);

				//! \brief ��ȡ����
				Vector3d GetScale();
			};

		}
	}
}