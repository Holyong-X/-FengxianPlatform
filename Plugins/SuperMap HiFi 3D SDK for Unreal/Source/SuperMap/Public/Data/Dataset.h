#pragma once

#include <map>
#include "Data/Geometry.h"
#include "Data/FieldInfo.h"
#include "Data/Rectangle2D.h"
#include "Core/RealspaceDLL.h"
using namespace SuperMapSDK::UnrealEngine::Data;

class UWorld;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			//! \brief ���ݼ�����
			enum SUPERMAP_API DatasetType
			{
				DT_UnKnown = -1,  //δ֪
				DT_POINT,   //  ��
				DT_LINE,	//  ��
				DT_REGION,  //  ��
				DT_Model,	//	ģ��	
			};

			class DataSource;
			class SUPERMAP_API Dataset
			{
			public:
				Dataset();
				Dataset(DataSource* pDataSource, void* pUGDataset);
				~Dataset();

				void* Handler();

				//! \brief ��ȡ���ݼ�����
				//! \return ���ݼ�����
				FString GetName();

				//! \brief ��ѯ���ݼ�������
				//! \return ������
				TArray<Geometry*> Query();

				//! \brief ��ѯ���ݼ�ͨ��SQL
				//! \param strSQL [in] SQL����
				//! \return ������
				TArray<Geometry*> QueryBySql(FString strSQL);

				//! \brief ��ѯ�����ֶ�����ֵ
				//! \param strFieldName [in] �����ֶ�
				//! \return ����ֵ
				TArray<FString> QueryField(FString strFieldName);

				//! \brief ��ѯ����ͨ��ID
				//! \param nID [in] ����ID
				//! \return ����ֵ
				TArray<FString> QueryAttributeById(int32 nID);

				//! \brief ��ȡ�ֶ���Ϣ
				//! \param arrFieldInfo [out] �ֶ���Ϣ
				void GetFieldInfos(TArray<FieldInfo>& arrFieldInfo);

				//! \brief ��ȡ���ݼ�Bound
				//! \return ���ݼ�Bound
				Rectangle2D GetBounds();

				//! \brief �������ݼ�����
				//! \return ���ݼ�����
				DatasetType GetType();

				//! \brief ��ȡ��������Դ
				//! \return ����Դ
				DataSource* GetDataSource();
			
			private:

				//! \brief ��������Դ
				DataSource* m_pDataSource;

				//! \brief �����ݼ�ʵ��
				void* m_pUGDataset;

				//! \brief ���ݼ�����
				FString m_strName;

				//! \brief ����������
				UWorld* m_pWorld;
			};
		}
	}
}