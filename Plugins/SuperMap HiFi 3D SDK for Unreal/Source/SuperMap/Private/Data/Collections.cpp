#include "Data/Collections.h"
#include "Core/Public/HAL/PlatformFilemanager.h"
#include "Core/Public/Misc/FileHelper.h"
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Collections::Collections()
			{

			}

			Collections::~Collections()
			{

			}

			std::vector<Collection*>& Collections::GetCollections()
			{
				return m_vecCollections;
			}

			
		}
	}
}