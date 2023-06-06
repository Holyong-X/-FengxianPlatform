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

				//! \brief 打开数据源
				//! \param strDataSourceName [in] 数据源名称
				bool Open(FString strDataSourceName);

				//! \brief 关闭数据源
				bool Close();

				//! \brief 获取数据集通过名字
				//! \param strDatasetName [in] 数据集名称
				//! \return 数据集
				Dataset* GetDataset(FString strDatasetName);

				//! \brief 获取数据集通过索引下标
				//! \param nIndex [in] 数据集索引
				//! \return 数据集 
				Dataset* GetDataset(int nIndex);

				//! \brief 获取数据源名称
				//! \return 数据源名称
				FString GetName();

				//! \brief 回去数据集集合
				//! \return 数据集集合
				std::vector<Dataset*> GetDatasetList();

				//! \brief 获取数据集的个数
				//! \return 数据集个数
				int32 GetDatasetCount();


				//! \brief 返回UGC句柄
				void* GetHandler();
			private:
				//! \brief 数据源名称
				FString m_strName;

				//! \brief 数据集
				std::vector<Dataset*> m_Datasets;

				//! \brief 底层数据源
				void* m_pUGDataSource;
			};
		}
	}
}