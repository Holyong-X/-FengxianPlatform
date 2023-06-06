#include "Data/DataSources.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			using namespace SuperMapSDK::UnrealEngine::Core;
			DataSources::DataSources()
			{
				m_pDataSources = nullptr;
			}
			DataSources::DataSources(void* m_pUGDataSources)
			{
				m_pDataSources = m_pUGDataSources;
			}
			DataSources::~DataSources()
			{
				m_pDataSources = nullptr;
			}

			
			bool DataSources::SetAt(FString strDataSourceAlias, DataSource* datasource)
			{
				const TCHAR* cDataSourceAlias = *strDataSourceAlias;
				ANSICHAR* acDataSourceAlias = TCHAR_TO_UTF8(cDataSourceAlias);

				_DataSources_SetAt(acDataSourceAlias, m_pDataSources, datasource->GetHandler());

				return true;
			}

			bool DataSources::ReleaseAt(FString strDataSourceAlias)
			{
				const TCHAR* cDataSourceAlias = *strDataSourceAlias;
				ANSICHAR* acDataSourceAlias = TCHAR_TO_UTF8(cDataSourceAlias);

				_DataSources_ReleaseAt(acDataSourceAlias, m_pDataSources);

				return true;
			}

			//! \brief 打开数据源
			//! \param strDataSourceName [in] 数据源名称
			DataSource* DataSources::GetAt(int nIndex)
			{
				return nullptr;
			}

			DataSource* DataSources::GetAt(FString strAlias)
			{
				const TCHAR* cstrAlias = *strAlias;
				ANSICHAR* ccstrAlias = TCHAR_TO_UTF8(cstrAlias);
				void* pDataSource = nullptr;
				bool result = _DataSources_GetAtByAlias(ccstrAlias,m_pDataSources, pDataSource);
				if (result)
				{
					return new DataSource(pDataSource);
				}
				else
				{
					return nullptr;
				}
			}
		}
	}
}