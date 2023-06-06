#pragma once
#include "Data/DataSource.h"
#include "Core/RealspaceDLL.h"
class UWorld;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{

			class SUPERMAP_API DataSources
			{
			public:
				DataSources(void* m_pUGDataSources);
				DataSources();
				~DataSources();


				bool SetAt(FString strDataSourceAlias, DataSource* datasource);

				bool ReleaseAt(FString strDataSourceAlias);

				//! \brief 打开数据源
				//! \param strDataSourceName [in] 数据源名称
				DataSource* GetAt(int nIndex);

				//! \brief 打开数据源
				//! \param strDataSourceName [in] 数据源名称
				DataSource* GetAt(FString strAlias);

			private:
			
				//! \brief 底层数据源
				void* m_pDataSources;
			};
		}
	}
}