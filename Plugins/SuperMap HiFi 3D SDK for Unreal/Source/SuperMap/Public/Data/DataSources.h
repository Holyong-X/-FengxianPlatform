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

				//! \brief ������Դ
				//! \param strDataSourceName [in] ����Դ����
				DataSource* GetAt(int nIndex);

				//! \brief ������Դ
				//! \param strDataSourceName [in] ����Դ����
				DataSource* GetAt(FString strAlias);

			private:
			
				//! \brief �ײ�����Դ
				void* m_pDataSources;
			};
		}
	}
}