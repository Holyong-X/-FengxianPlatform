#pragma once

#include "CoreMinimal.h"
#include "Core/RealspaceDLL.h"
#include "Base3D/CommonDefine.h"
#include "Core/Routes.h"
#include "Core/Scene.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			//! \brief 飞行拐弯方式
			enum FlyTurningMode
			{
				//! \brief 平滑拐弯
				Smoothly = 0,

				//! \brief 直角拐弯
				Directly = 1
			};

			//! \brief 飞行状态
			enum FlyStatus
			{
				//! \brief 当前飞行状态为已经停止
				Stop = 0,

				//! \brief 当前飞行状态为暂停
				Pause = 1,

				//! \brief 当前飞行状态为正在飞行中，可以在暂停后设置飞行状态类型为Play继续飞行。 
				Play = 2
			};

			class SUPERMAP_API FlyManager
			{
			public:
				FlyManager();
				FlyManager(Scene* pScene);
				~FlyManager();
			public:

				//! \brief 获取或设置本次飞行（即当前整个路线）需要的总时间，单位为秒。 
				void SetDuration(Gamedouble dDuration);

				Gamedouble GetDuration();

				//! \brief 获取或设置播放速率。该属性值的范围为0-100，当大于1.0时，则沿飞行路径快速飞行，小于1.0时，表示沿飞行路径慢速飞行。
				void SetPlayRate(Gamedouble dPlayRate);

				Gamedouble GetPlayRate();

				//! \brief 获取或设置飞行拐弯方式。支持直角拐弯和平滑拐弯。
				void SetTurningMode(FlyTurningMode eFlyTurningMode);

				FlyTurningMode GetTurningMode();

				//! \brief 获取路线集合。
				Routes* GetRoutes();

				//! \brief 获取当前的飞行状态（停止，暂停，飞行中）。 
				FlyStatus GetStatus();

				//! \brief 按照返回的路线集合（Routes）指定的路线开始飞行，或继续进行中断的飞行。 
				void Play();

				//! \brief 停止当前飞行。
				void Stop();

				//! \brief 暂停当前飞行。 
				void Pause();

				//! \brief 更新飞行管理的内部计算。
				void Update();

				//! \brief 获取当前站点索引
				Gameint GetCurrentStopIndex();

				//! \brief 设置当前站点
				void SetCurrentStopIndex(Gameint nIndex);

				//! \brief 判断飞行是否抵达站点
				Gamebool GetArriedStatus();

				//! \brief 设置插入点
				void SetOriginalPosition(Vector3d vOriginalPos);

				//! \brief 获取飞行进度
				Gamedouble GetCurrentProgress();
			private:
				void* m_pFlyManager;

				Routes* m_pRoutes;

				Scene* m_pScene;
			};
		}
	}
}