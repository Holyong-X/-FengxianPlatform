#pragma once

#include "Data/DataSources.h"
#include "CoreMinimal.h"
#include "Core/RealspaceDLL.h"

class UWorld;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API Workspace
			{
			public:
				Workspace();
				Workspace(void* pUGWorkspace);
				~Workspace();

				DataSources* GetDataSources();


	
			private:
				//! \brief µ×²ãÊý¾ÝÔ´
				void* m_pUGWorkspace;

				DataSources* m_pDataSources;
			};
		}
	}
}