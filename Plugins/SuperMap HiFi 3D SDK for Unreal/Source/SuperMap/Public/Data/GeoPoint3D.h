#pragma once
#include "CoreMinimal.h"
#include "Data/GeometryType.h"
#include "Data/Geometry3D.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API GeoPoint3D : public Geometry3D
			{
			public:
				GeoPoint3D();
				GeoPoint3D(void* pGeoPoint3D);
				virtual ~GeoPoint3D();
				GeoPoint3D* Copy();
			public:
				//! \brief 返回类型
				GeometryType GetType();

				//! \brief 设置点
				void SetPoint3D(FVector vPoint3D);

				//! \brief 获取点
				Vector3d GetPoint3D();

				//! \brief 获取点
				Vector3d GetPosition();
			private:
				void* m_pGeoPoint3D;
			};

		}
	}
}