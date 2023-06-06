#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/Public/Misc/DateTime.h"
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{

			class SUPERMAP_API JobScheduler
			{
			public:
				JobScheduler();
				~JobScheduler();

				//! \brief 开始时间
				void Start();

				//! \brief 结束时间
				void End();

				//! \biref 是否结束任务
				Gamebool IsFinish();

				//! \brief 获取单例
				static JobScheduler* GetSingleton();

			private:
				//! \brief 结束间隔(毫秒)
				Gamefloat m_nDelatTime;

				//! \brief 当前帧的起始时间
				high_resolution_clock::time_point m_StartDateTime;

				//! \brief 当前帧的结束时间
				high_resolution_clock::time_point m_EndDateTime;

				//! \brief 单例类
				static JobScheduler* m_pJobScheduler;
			};
		}
	}
}