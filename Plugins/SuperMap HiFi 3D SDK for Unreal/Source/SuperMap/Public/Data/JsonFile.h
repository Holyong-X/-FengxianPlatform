#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"
#if (!SM_FOR_UE_FIVE && WITH_EDITOR)
using namespace SuperMapSDK::UnrealEngine::DataExchange;
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			enum JsonValueType
			{
				nullValue = 0, //'null' value
				intValue,      //signed integer value
				uintValue,     //unsigned integer value
				realValue,     //double value
				stringValue,   //UTF-8 string value
				booleanValue,  //bool value
				arrayValue,    //array value (ordered list)
				objectValue    //object value (collection of name/value pairs)
			};

			class SUPERMAP_API JsonUtils
			{
			public:
				//! \brief 完成材质数据转换及保存为json文件 
				static void MaterialSaveToJson(UMaterialInterface* pMaterialInterface, FString strPath);
			};

			class SUPERMAP_API JsonFile
			{
			public:
				JsonFile();
				JsonFile(JsonValueType jsonType);
				JsonFile(void* pJson);
				~JsonFile();

				Gameint GetArraySize();

				JsonFile* GetAt(Gameint nIndex);

				FString GetAtString(Gameint nIndex);

				void Add(FString strFiled, FString strValue);

				void Add(FString strFiled, Gamedouble dValue);

				void Add(FString strFiled, Gameint nValue);

				void Add(FString strFiled, Gamefloat fValue);

				void Add(FString strFiled, Gamebool bValue);

				void Add(JsonFile* jTargetValue);

				void Add(FString strFiled, JsonFile* jTargetValue);

				Gamebool GetValue(FString strFiled, Gameint & iValue);

				Gamebool GetValue(FString strFiled, Gamefloat & fValue);

				Gamebool GetValue(FString strFiled, Gamedouble & dValue);

				Gamebool GetValue(FString strFiled, Gamebool & bValue);

				Gamebool GetValue(FString strFiled, FString & strValue);

				Gamebool GetValue(FString strFiled, JsonFile* & pJsonValue);

				Gamebool Contains(FString strFiled);

				void SaveToStdFile(FString strName);

				void SaveToString(FString & strJson);

				void LoadFromStdFile(FString strName);

				void LoadFromString(FString strName);

				void* GetJsonPtr();

				void SetJsonPtr(void* pJsonPtr);

				TArray<FString> GetAllKeys();
			private:
				void* m_pJsonValue;
			};
		}
	}
}
