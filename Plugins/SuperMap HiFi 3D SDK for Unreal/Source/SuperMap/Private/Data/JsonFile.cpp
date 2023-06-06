#include "Data/JsonFile.h"
#include "Algorithm3D/MathEngine.h"
#include "Graphics3D/GameMaterialManager.h"
#ifdef BUILD_EDITOR
#include "DataExchange/MaterialConverter.h"
#endif
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
#ifdef BUILD_EDITOR
using namespace SuperMapSDK::UnrealEngine::DataExchange;
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			JsonFile::JsonFile()
			{
				_CreateJson(m_pJsonValue);
			}

			JsonFile::JsonFile(JsonValueType jsonType)
			{
				_CreateJsonWithType(m_pJsonValue, (Gameint)jsonType);
			}

			JsonFile::JsonFile(void* pJson)
			{
				m_pJsonValue = pJson;
			}

			JsonFile::~JsonFile()
			{
				if (m_pJsonValue != nullptr)
				{
					_RemoveAll(m_pJsonValue);
				}
			}

			Gameint JsonFile::GetArraySize()
			{
				return _Json_GetArrarySize(m_pJsonValue);
			}

			JsonFile* JsonFile::GetAt(Gameint nIndex)
			{

				void* pRefJson = nullptr;
				bool bGet = _Json_GetAt(m_pJsonValue, nIndex, pRefJson);
				if (!bGet)
					return nullptr;
				JsonFile* child = new JsonFile(pRefJson);
				return child;
			}

			FString JsonFile::GetAtString(Gameint nIndex)
			{
				Gamechar* cValue = (char*)"";
				_Json_GetAtString(m_pJsonValue, nIndex, cValue);
				FString strValue = UTF8_TO_TCHAR(cValue);
				return strValue;
			}

			void JsonFile::Add(FString strFiled, FString strValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);
				
				ANSICHAR* ccstrValue;
				MathEngine::FStringToANSIChar(strValue, ccstrValue);
				
				if (ccstrFiled != nullptr && ccstrValue != nullptr)
				{
					_JsonAddString(m_pJsonValue, ccstrFiled, ccstrValue);
				}
				
				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}	
				if (ccstrValue != nullptr)
				{
					delete ccstrValue;
					ccstrValue = nullptr;
				}
			}

			void JsonFile::Add(FString strFiled, Gamedouble dValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				_JsonAddDouble(m_pJsonValue, ccstrFiled, dValue);

				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
			}

			void JsonFile::Add(FString strFiled, Gameint nValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				_JsonAddInt(m_pJsonValue, ccstrFiled, nValue);

				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
			}

			void JsonFile::Add(FString strFiled, Gamefloat fValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				_JsonAddFloat(m_pJsonValue, ccstrFiled, fValue);

				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
			}

			void JsonFile::Add(FString strFiled, Gamebool bValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				_JsonAddBool(m_pJsonValue, ccstrFiled, bValue);

				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
			}

			void JsonFile::Add(JsonFile* jTargetValue)
			{
				_JsonArrayAddJson(m_pJsonValue, jTargetValue->GetJsonPtr());
			}

			void JsonFile::Add(FString strFiled, JsonFile* jTargetValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				_JsonAddJson(m_pJsonValue, ccstrFiled, jTargetValue->GetJsonPtr());

				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
			}

			Gamebool JsonFile::GetValue(FString strFiled, Gameint & iValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				Gamebool result = _JsonGetValueInt(m_pJsonValue, ccstrFiled, iValue);

				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
				return result;
			}

			Gamebool JsonFile::GetValue(FString strFiled, Gamefloat & fValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				Gamebool result = _JsonGetValueFloat(m_pJsonValue, ccstrFiled, fValue);
				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
				return result;
			}

			Gamebool JsonFile::GetValue(FString strFiled, Gamedouble & dValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				Gamebool result = _JsonGetValueDouble(m_pJsonValue, ccstrFiled, dValue);
				
				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
				return result;
			}

			Gamebool JsonFile::GetValue(FString strFiled, Gamebool & bValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				Gamebool result = _JsonGetValueBool(m_pJsonValue, ccstrFiled, bValue);
				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
				return result;
			}

			Gamebool JsonFile::GetValue(FString strFiled, FString & strValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				Gamechar* pCharValue = (char*)"";
				Gamebool result = _JsonGetValueString(m_pJsonValue, ccstrFiled, pCharValue);
				strValue = UTF8_TO_TCHAR(pCharValue);
				
				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
				return result;
			}

			Gamebool JsonFile::GetValue(FString strFiled, JsonFile* & pJsonValue)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				void* pRefJson = nullptr;
				Gamebool result = _JsonGetValueJson(m_pJsonValue, ccstrFiled, pRefJson);
				pJsonValue = new JsonFile(pRefJson);

				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
				return result;
			}

			Gamebool JsonFile::Contains(FString strFiled)
			{
				ANSICHAR* ccstrFiled;
				MathEngine::FStringToANSIChar(strFiled, ccstrFiled);

				Gamebool result = _Contains(m_pJsonValue, ccstrFiled);

				if (ccstrFiled != nullptr)
				{
					delete ccstrFiled;
					ccstrFiled = nullptr;
				}
				return result;
			}

			void JsonFile::SaveToStdFile(FString strName)
			{
				ANSICHAR* ccstrName;
				MathEngine::FStringToANSIChar(strName, ccstrName);

				_SaveToStdFile(m_pJsonValue, ccstrName);

				if (ccstrName != nullptr)
				{
					delete ccstrName;
					ccstrName = nullptr;
				}
			}

			void JsonFile::SaveToString(FString & strJson)
			{
				ANSICHAR* ccstrJson;
				MathEngine::FStringToANSIChar(strJson, ccstrJson);

				_Json_SaveToString(m_pJsonValue, ccstrJson);
				strJson = UTF8_TO_TCHAR(ccstrJson);

				if (ccstrJson != nullptr)
				{
					delete ccstrJson;
					ccstrJson = nullptr;
				}
			}

			void JsonFile::LoadFromStdFile(FString strName)
			{
				ANSICHAR* ccstrName;
				MathEngine::FStringToANSIChar(strName, ccstrName);

				if (_LoadFromStdFile != nullptr)
				{
					_LoadFromStdFile(ccstrName, m_pJsonValue);
				}

				if (ccstrName != nullptr)
				{
					delete ccstrName;
					ccstrName = nullptr;
				}
			}

			void JsonFile::LoadFromString(FString strName)
			{
				ANSICHAR* ccstrName;
				MathEngine::FStringToANSIChar(strName, ccstrName);

				_LoadFromString(ccstrName, m_pJsonValue);

				if (ccstrName != nullptr)
				{
					delete ccstrName;
					ccstrName = nullptr;
				}
			}

			void* JsonFile::GetJsonPtr()
			{
				return m_pJsonValue;
			}

			void JsonFile::SetJsonPtr(void* pJsonPtr)
			{
				if (m_pJsonValue != nullptr)
				{
					delete (char*)m_pJsonValue;
					m_pJsonValue = nullptr;
				}
				m_pJsonValue = pJsonPtr;
			}

			TArray<FString> JsonFile::GetAllKeys()
			{
				Gamechar*** pArrAllKeys = nullptr;
				Gameint nCount = 0;
				_JsonGetAllKeys(m_pJsonValue, nCount, pArrAllKeys);
				TArray<FString> arrValues;
				for (int32 n = 0; n < nCount; n++)
				{
					FString key = UTF8_TO_TCHAR((*pArrAllKeys)[n]);
					arrValues.Add(key);
				}
				if (nCount > 0)
				{
					//释放中间层new的
					SuperMapSDK::UnrealEngine::Core::_ReleaseCharArray(pArrAllKeys, nCount);
				}
				return arrValues;
			}

			void JsonUtils::MaterialSaveToJson(UMaterialInterface* pMaterialInterface, FString strPath)
			{
#ifdef BUILD_EDITOR
				TArray<int32> SectionIndices;
				MaterialData* mtlData = new MaterialData;
				FString strMaterialName = pMaterialInterface->GetName();
				const TCHAR* cName = *strMaterialName;
				ANSICHAR* ccName = TCHAR_TO_UTF8(cName);
				mtlData->name = ANSI_TO_TCHAR(ccName);
				FMaterialConverter mtlCoverter(mtlData, pMaterialInterface, NULL, SectionIndices);
				mtlCoverter.DoWork();
				const TCHAR* TJson = *strPath;
				_SaveMaterialToJson(mtlData, TCHAR_TO_UTF8(TJson));
				delete mtlData;
				mtlData = nullptr;
#endif
			}
		}
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif