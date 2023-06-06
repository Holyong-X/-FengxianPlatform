#include "Core/JobScheduler.h"
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{

			JobScheduler* JobScheduler::m_pJobScheduler = nullptr;

			JobScheduler::JobScheduler()
			{
				m_nDelatTime = 0.3;
			}

			JobScheduler::~JobScheduler()
			{

			}

			JobScheduler* JobScheduler::GetSingleton()
			{
				if (m_pJobScheduler == nullptr)
				{
					m_pJobScheduler = new JobScheduler;
				}

				return m_pJobScheduler;
			}

			void JobScheduler::Start()
			{
				m_StartDateTime = high_resolution_clock::now();
			}

			void JobScheduler::End()
			{
				m_EndDateTime = high_resolution_clock::now();
			}

			Gamebool JobScheduler::IsFinish()
			{
				milliseconds timeInterval =std::chrono::duration_cast<milliseconds>(m_EndDateTime - m_StartDateTime);
				if (timeInterval.count() > 1)	
				{
					return true;
				}

				return false;
			}
		}
	}
}