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
				//! \brief 设置宽度
				void SetWidth(double dWidth);

				//! \brief 获取宽度
				double GetWidth();

				//! \brief 设置长度
				void SetLength(double dLength);

				//! \brief 获取长度
				double GetLength();

				//! \brief 设置高度
				void SetHeight(double dHeight);

				//! \brief 获取高度
				double GetHeight();

				//! \brief 裁剪盒子颜色
				void SetColor(FVector4 color);
				FVector4 GetColor();

				//! \brief 获取插入点
				Vector3d GetCenter();
			private:
				//! \brief 盒子颜色
				FVector4 m_vColor;
			};
		} 
	}
}