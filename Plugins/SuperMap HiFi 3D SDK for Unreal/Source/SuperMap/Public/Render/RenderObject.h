#pragma once
#include "CoreMinimal.h"
#include "Data/Geometry.h"
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			class SUPERMAP_API RenderObject
			{
			public:
				RenderObject();
				virtual ~RenderObject();
			public:
				//! \brief 设置UE的场景管理器
				void SetWorld(UWorld* pWorld);

				//! \brief 获取几何体对象
				Geometry* GetGeometry();

				//! \brief 设置几何体对象
				void SetGeometry(Geometry* pGeo);

				//! \brief 设置渲染对象名字
				void SetName(FString strName);

				//! \brief 设置是否可见
				void SetVisible(bool bVisible);

			protected:
				virtual void Render();

			protected:

				//! \brief 是否可见
				bool m_bVisible;

				//! \brief 渲染对象名
				FString m_strName;
				
				//! \brief 渲染几何体
				Geometry* m_pGeometry;
				
				//! \brief 是否初始化
				bool m_bInitial;
				
				UWorld* m_pWorld;
			};
		}
	}
}