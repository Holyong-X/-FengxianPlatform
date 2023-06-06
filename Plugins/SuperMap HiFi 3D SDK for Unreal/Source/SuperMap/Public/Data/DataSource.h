#pragma once

#include "Data/Dataset.h"
#include <vector>
#include "Core/RealspaceDLL.h"

class UWorld;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class Dataset;
			class SUPERMAP_API DataSource
			{
			public:
				DataSource();
				DataSource(void* pUGDataSource);
				~DataSource();

				//! \brief ������Դ
				//! \param strDataSourceName [in] ����Դ����
				bool Open(FString strDataSourceName);

				//! \brief �ر�����Դ
				bool Close();

				//! \brief ��ȡ���ݼ�ͨ������
				//! \param strDatasetName [in] ���ݼ�����
				//! \return ���ݼ�
				Dataset* GetDataset(FString strDatasetName);

				//! \brief ��ȡ���ݼ�ͨ�������±�
				//! \param nIndex [in] ���ݼ�����
				//! \return ���ݼ� 
				Dataset* GetDataset(int nIndex);

				//! \brief ��ȡ����Դ����
				//! \return ����Դ����
				FString GetName();

				//! \brief ��ȥ���ݼ�����
				//! \return ���ݼ�����
				std::vector<Dataset*> GetDatasetList();

				//! \brief ��ȡ���ݼ��ĸ���
				//! \return ���ݼ�����
				int32 GetDatasetCount();


				//! \brief ����UGC���
				void* GetHandler();
			private:
				//! \brief ����Դ����
				FString m_strName;

				//! \brief ���ݼ�
				std::vector<Dataset*> m_Datasets;

				//! \brief �ײ�����Դ
				void* m_pUGDataSource;
			};
		}
	}
}