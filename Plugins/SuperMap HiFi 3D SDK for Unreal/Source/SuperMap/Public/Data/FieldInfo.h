#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			//! \brief �ֶ�����
			enum SUPERMAP_API FieldType
			{
				//! \brief ��Ч���ֶ����͡�
				FT_UnKnown = 0,
				//! \brief ����ֵ�����ֽڣ�TRUE,FALSE��
				FT_Boolean = 1,
				//! \brief �޷��ŵ����0-255�� 
				FT_Byte = 2,
				//! \brief �����ͣ�2�ֽڡ�
				FT_INT16 = 3,
				//! \brief �����ͣ�4�ֽڡ�
				FT_INT32 = 4,
				//! \brief �����ͣ�8�ֽڡ�
				FT_INT64 = 16,
				//! \brief �����ȸ����ͣ�4�ֽڡ�
				FT_Float = 6,
				//! \brief ˫���ȸ����ͣ�8�ֽڡ�
				FT_Double = 7,
				//! \brief �����ͣ��ꡢ�¡��գ�����ʱ�䡣
				FT_Date = 8,
				//! \brief �̶����ȶ������ͣ���ָ�����ȡ�
				FT_Binary = 9,
				//! \brief �������ַ����͡�
				FT_Text = 10,
				//! \brief ���������������͡�
				FT_LongBinary = 11,
				//! \brief �����ַ����ͣ���ָ�����ȡ�
				FT_Char = 18,
				//! \brief ʱ���ͣ�Сʱ���֡��룬�������ڡ�
				FT_Time = 22,
				//! \brief ʱ����ͣ��ꡢ�¡��ա�Сʱ���֡��롣
				FT_TimeStamp = 23,
				//! \brief ���ֽڲ������ַ������͡�
				FT_NText = 127,
				//! \brief �����������͡�
				FT_Geometry = 128,
				//����Pg�е�Jsonb�ֶ�����
				FT_JsonB = 129
			};

			//! \brief �ֶ���Ϣ
			class SUPERMAP_API FieldInfo
			{
			public:
				FieldInfo(){};
				~FieldInfo(){};

				//! \brief �����ֶ�����
				FString m_strName;

				//! \brief �����ֶ���������
				FieldType m_eType;
			};
		}
	}
}