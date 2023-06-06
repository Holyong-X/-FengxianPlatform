#include "Data/Workspace.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Workspace::Workspace()
			{
				m_pUGWorkspace = nullptr;
				m_pDataSources = nullptr;
			}

			Workspace::~Workspace()
			{
				m_pUGWorkspace = nullptr;
				m_pDataSources = nullptr;
			}

			Workspace::Workspace(void* pUGWorkspace)
			{
				m_pUGWorkspace = pUGWorkspace;
				m_pDataSources = nullptr;
			}


			DataSources* Workspace::GetDataSources()
			{

				if(m_pDataSources == nullptr)
				{
					void* pUGDataSources = nullptr;
					_Workspace_GetDataSources(m_pUGWorkspace, pUGDataSources);

					if (pUGDataSources != nullptr)
					{
						m_pDataSources = new DataSources(pUGDataSources);
					}
					
				}

				return m_pDataSources;
			}
		}
	}
}