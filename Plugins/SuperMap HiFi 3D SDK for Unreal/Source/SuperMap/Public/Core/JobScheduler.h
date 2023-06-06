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

				//! \brief ��ʼʱ��
				void Start();

				//! \brief ����ʱ��
				void End();

				//! \biref �Ƿ��������
				Gamebool IsFinish();

				//! \brief ��ȡ����
				static JobScheduler* GetSingleton();

			private:
				//! \brief �������(����)
				Gamefloat m_nDelatTime;

				//! \brief ��ǰ֡����ʼʱ��
				high_resolution_clock::time_point m_StartDateTime;

				//! \brief ��ǰ֡�Ľ���ʱ��
				high_resolution_clock::time_point m_EndDateTime;

				//! \brief ������
				static JobScheduler* m_pJobScheduler;
			};
		}
	}
}