#include "Core/AttributeFields.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			AttributeFields::AttributeFields()
			{
				m_nObjectID = -1;
			}

			AttributeFields::AttributeFields(const AttributeFields & attributeFields)
			{
				m_nObjectID = attributeFields.m_nObjectID;
				m_vecFieldInfos = attributeFields.m_vecFieldInfos;
				m_vecCaptions = attributeFields.m_vecCaptions;
			}

			AttributeFields::~AttributeFields()
			{
				m_vecFieldInfos.clear();
				m_vecCaptions.clear();
			}

			void AttributeFields::SetID(int32 nID)
			{
				m_nObjectID = nID;
			}

			int32 AttributeFields::GetID()
			{
				return m_nObjectID;
			}

			std::vector<FString> AttributeFields::GetFieldInfos()
			{
				return m_vecFieldInfos;
			}

			std::vector<FString> AttributeFields::GetFieldValues()
			{
				return m_vecFieldValues;
			}

			void AttributeFields::SetFieldInfos(std::vector<FString> & vecFieldInfos)
			{
				m_vecFieldInfos.clear();
				m_vecFieldInfos = vecFieldInfos;
			}

			void AttributeFields::SetFieldValues(std::vector<FString> & vecFieldValues)
			{
				m_vecFieldValues.clear();
				m_vecFieldValues = vecFieldValues;
			}

			std::vector<FString> AttributeFields::GetCaptions()
			{
				return m_vecCaptions;
			}

			void AttributeFields::SetCaptions(std::vector<FString> & vecCaptions)
			{
				m_vecCaptions.clear();
				m_vecCaptions = vecCaptions;
			}

			void AttributeFields::SetFields(std::vector<FString> & vecFieldInfos, std::vector<FString> & vecFieldValues)
			{
				if (vecFieldInfos.size() != vecFieldValues.size())
				{
					return;
				}

				m_vecFieldInfos.clear();
				m_vecFieldInfos = vecFieldInfos;

				m_vecFieldValues.clear();
				m_vecFieldValues = vecFieldValues;
			}

			int32 AttributeFields::FieldInfoCount()
			{
				return m_vecFieldInfos.size();
			}

			int32 AttributeFields::FieldValueCount()
			{
				return m_vecFieldValues.size();
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif