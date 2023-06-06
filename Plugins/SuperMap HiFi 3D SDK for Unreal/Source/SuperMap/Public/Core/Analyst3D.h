#pragma once

#include "CoreMinimal.h"
#include "ControlUE/CameraControl.h"

class UWorld;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace ControlUE 
		{
			class CameraControl;
		}
		
		namespace Core
		{
			//! \brief 分析类型
			enum AnalyzeMode
			{
				//! \brief ViewShed 可视域分析
				View_Shed = 1,
				//! \brief 通视分析
				Sight_Line = 2,
				//! \brief 视屏投放
				Projection_Image = 3,
				//! \brief 开敞度
				View_Dome = 4,
				//! \brief 点聚合分析
				Cluster_Analyze = 5,
				//! \brief 立面图分析
				Facade_Analyze = 6,
				//! \brief 剖面图分析
				Profile_Analyze = 7,
				//! \brief 多可视域分析
				Multi_ViewShed3D = 8
			};

			class Scene;
			class SUPERMAP_API Analyst3D
			{
			protected:
				//! \brief 分析对象名字
				AnalyzeMode m_eAnalyzeMode;

				//! \brief 场景
				Scene* m_pScene;

				//! \brief UE世界场景
				UWorld* m_pWorld;

				//! \brief 当前分析对象名字
				FName m_strName;

				//! \brief 当前是否更新分析渲染
				bool m_bNeedUpdata;

				//! \brief 相机操作
				ControlUE::CameraControl* m_pCameraControl;

			public:
				//! \brief 获取分析类型
				AnalyzeMode GetAnalyzeMode();

				//! \brief 执行分析
				void Build();

				//! \brief 清除分析
				void Clear();
			protected:

				//! \brief 分析操作
				virtual void DoBuild() = 0;

				//! \brief 内部分析释放
				virtual void DoClear() = 0;

				//! \brief 裁剪渲染
				virtual void Render() = 0;

			public:
				Analyst3D(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Analyst3D();
				friend class Core::Scene;
			};
		}
	}
}