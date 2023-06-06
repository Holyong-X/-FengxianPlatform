#pragma once

#include "CoreMinimal.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			//! \brief 字段类型
			enum SUPERMAP_API FieldType
			{
				//! \brief 无效的字段类型。
				FT_UnKnown = 0,
				//! \brief 布尔值，单字节，TRUE,FALSE。
				FT_Boolean = 1,
				//! \brief 无符号单字李，0-255。 
				FT_Byte = 2,
				//! \brief 短整型，2字节。
				FT_INT16 = 3,
				//! \brief 长整型，4字节。
				FT_INT32 = 4,
				//! \brief 长整型，8字节。
				FT_INT64 = 16,
				//! \brief 单精度浮点型，4字节。
				FT_Float = 6,
				//! \brief 双精度浮点型，8字节。
				FT_Double = 7,
				//! \brief 日期型，年、月、日，不带时间。
				FT_Date = 8,
				//! \brief 固定长度二进制型，需指定长度。
				FT_Binary = 9,
				//! \brief 不定长字符串型。
				FT_Text = 10,
				//! \brief 不定长二进制类型。
				FT_LongBinary = 11,
				//! \brief 定长字符串型，需指定长度。
				FT_Char = 18,
				//! \brief 时间型，小时、分、秒，不带日期。
				FT_Time = 22,
				//! \brief 时间戳型，年、月、日、小时、分、秒。
				FT_TimeStamp = 23,
				//! \brief 宽字节不定长字符串类型。
				FT_NText = 127,
				//! \brief 几何数据类型。
				FT_Geometry = 128,
				//用作Pg中的Jsonb字段类型
				FT_JsonB = 129
			};

			//! \brief 字段信息
			class SUPERMAP_API FieldInfo
			{
			public:
				FieldInfo(){};
				~FieldInfo(){};

				//! \brief 属性字段名字
				FString m_strName;

				//! \brief 属性字段数组类型
				FieldType m_eType;
			};
		}
	}
}