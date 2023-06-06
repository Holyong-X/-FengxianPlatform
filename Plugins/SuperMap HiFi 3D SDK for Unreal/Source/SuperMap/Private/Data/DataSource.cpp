#include "Data/DataSource.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			DataSource::DataSource()
			{
			}

			DataSource::DataSource(void* pUGDataSource)
			{
				m_pUGDataSource = pUGDataSource;
			}

			DataSource::~DataSource()
			{
			}

			bool DataSource::Open(FString strDataSourceName)
			{
				const TCHAR* cDataSouceName = *strDataSourceName;
				ANSICHAR* ccDataSouceName = TCHAR_TO_UTF8(cDataSouceName);

				char* DataSourceName = nullptr;
				void*** pDatasets = nullptr;
				int32 nCount = 0;

				bool result = SuperMapSDK::UnrealEngine::Core::_DataSource_Open(ccDataSouceName, m_pUGDataSource, DataSourceName, pDatasets, nCount);
				if (!result)
				{
					return false;
				}
				m_strName = strDataSourceName;

				for (int32 n = 0; n < nCount; n++)
				{
					Dataset* pDataset = new Dataset(this, (*pDatasets)[n]);
					m_Datasets.push_back(pDataset);
				}

				return true;
			}

			bool DataSource::Close()
			{
				SuperMapSDK::UnrealEngine::Core::_DataSource_Close(m_pUGDataSource);
				m_pUGDataSource = NULL;

				for (int32 n = 0; n < m_Datasets.size(); n++)
				{
					delete m_Datasets[n];
				}

				m_Datasets.clear();

				return true;
			}

			Dataset* DataSource::GetDataset(FString strDatasetName)
			{
				Dataset* pDataset = nullptr;

				if (m_Datasets.size() == 0)
				{
					void*** pDatasets = nullptr;
					int32 nCount = 0;
					SuperMapSDK::UnrealEngine::Core::_DataSource_GetDataset(m_pUGDataSource, pDatasets, nCount);
					for (int32 i = 0; i < nCount; i++)
					{
						Dataset* ppDataset = new Dataset(this, (*pDatasets)[i]);
						m_Datasets.push_back(ppDataset);
					}
				}

				for (int32 n = 0; n < m_Datasets.size(); n++)
				{
					if (m_Datasets[n]->GetName() == strDatasetName)
					{
						pDataset = m_Datasets[n];
						break;
					}
				}

				return pDataset;
			}

			int32 DataSource::GetDatasetCount()
			{
				return m_Datasets.size();
			}

			Dataset* DataSource::GetDataset(int nIndex)
			{
				return m_Datasets[nIndex];
			}

			FString DataSource::GetName()
			{
				return m_strName;
			}

			std::vector<Dataset*> DataSource::GetDatasetList()
			{
				return m_Datasets;
			}

			void* DataSource::GetHandler()
			{
				return m_pUGDataSource;
			}

		}
	}
}