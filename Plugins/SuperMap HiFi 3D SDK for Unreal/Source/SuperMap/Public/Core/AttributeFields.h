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
				//! \brief 对象ID
				int32  m_nObjectID;

				//! \brief 对象的属性形象
				std::vector<FString> m_vecFieldInfos;

				//! \brief 对象的属性值
				std::vector<FString> m_vecFieldValues;

				//! \brief 对象的外键名
				std::vector<FString> m_vecCaptions;
			public:
				AttributeFields();
				AttributeFields(const AttributeFields & fieldInfo);
				~AttributeFields();

				//! \brief 获取属性字段
				std::vector<FString> GetFieldInfos();

				//! \brief 设置属性字段
				void SetFieldInfos(std::vector<FString> & vecFieldInfos);

				//! \brief 获取属性值信息
				std::vector<FString> GetFieldValues();

				//! \brief 设置属性值信息
				void SetFieldValues(std::vector<FString> & vecFieldValues);

				//! \brief 获取外键信息
				std::vector<FString> GetCaptions();

				//! \brief 设置外键信息
				void SetCaptions(std::vector<FString> & vecCaptions);

				//! \breif 设置属性
				void SetFields(std::vector<FString> & vecFieldInfos, std::vector<FString> & vecFieldValues);

				//! \brief 获取对象ID
				int32 GetID();

				//! \brief 设置对象ID
				void SetID(int32 nID);

				//! \brief 属性字段个数
				int32 FieldInfoCount();

				//! \breif 属性值个数
				int32 FieldValueCount();
			};
		}
	}
}