#pragma once

#include "CoreMinimal.h"
#include "Data/GeometryType.h"
#include "Core/Style3D.h"
#include "Data/Rectangle2D.h"

using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{

			class SUPERMAP_API Geometry
			{
			public:
				Geometry();
				virtual ~Geometry();
			public:
				//! \brief 数据类型
				virtual GeometryType GetType() = 0;

				//! \brief 返回UGC句柄
				virtual void* GetHandler();

				//! \brief 保存渲染对象
				virtual void SetRenderFeature(void* pRenderFeature);

				//! \brief 获取Style3D
				Style3D* GetStyle3D();

				//! \brief 设置Style3D
				void SetStyle3D(Style3D* pStyle);

				//! \brief 获取bounds
				Rectangle2D GetBounds();
			protected:
				void* m_pUGGeometry;
				void* m_pRenderFeature;
			};
		}
	}
}