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
				//! \brief 返回类型
				virtual GeometryType GetType();

				//! \brief 设置中心点
				void SetPosition(Vector3d vPos);

				//! \brief 获取中心点
				Vector3d GetPosition();

				//! \brief 设置旋转
				void SetRotation(double dRotateX, double dRotateY, double dRotateZ);

				//! \brief 获取旋转
				Vector3d GetRotation();

				//! \brief 设置缩放
				void SetScale(double dScaleX, double dScaleY, double dScaleZ);

				//! \brief 获取缩放
				Vector3d GetScale();
			};

		}
	}
}