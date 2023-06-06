#pragma once

#include "CoreMinimal.h"
#include <vector>

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API AttributeFields
			{
			private:
				//! \brief ����ID
				int32  m_nObjectID;

				//! \brief �������������
				std::vector<FString> m_vecFieldInfos;

				//! \brief ���������ֵ
				std::vector<FString> m_vecFieldValues;

				//! \brief ����������
				std::vector<FString> m_vecCaptions;
			public:
				AttributeFields();
				AttributeFields(const AttributeFields & fieldInfo);
				~AttributeFields();

				//! \brief ��ȡ�����ֶ�
				std::vector<FString> GetFieldInfos();

				//! \brief ���������ֶ�
				void SetFieldInfos(std::vector<FString> & vecFieldInfos);

				//! \brief ��ȡ����ֵ��Ϣ
				std::vector<FString> GetFieldValues();

				//! \brief ��������ֵ��Ϣ
				void SetFieldValues(std::vector<FString> & vecFieldValues);

				//! \brief ��ȡ�����Ϣ
				std::vector<FString> GetCaptions();

				//! \brief ���������Ϣ
				void SetCaptions(std::vector<FString> & vecCaptions);

				//! \breif ��������
				void SetFields(std::vector<FString> & vecFieldInfos, std::vector<FString> & vecFieldValues);

				//! \brief ��ȡ����ID
				int32 GetID();

				//! \brief ���ö���ID
				void SetID(int32 nID);

				//! \brief �����ֶθ���
				int32 FieldInfoCount();

				//! \breif ����ֵ����
				int32 FieldValueCount();
			};
		}
	}
}