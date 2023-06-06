// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SuperMap_MainActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_MainActor() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_MainActorDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_OpenMultiFileDelegate__DelegateSignature();
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FSuperMapTable();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FSuperMap_LayerInfo();
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FRealPosition();
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FMaterialInfo();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector4();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_MainActor_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_MainActor();
	ENGINE_API UClass* Z_Construct_UClass_ACameraActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_MainActorDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_MainActorDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_MainActorDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "MainActorDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_MainActorDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_MainActorDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_MainActorDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_MainActorDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SuperMapSamples_OpenMultiFileDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_OpenMultiFileDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_OpenMultiFileDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "OpenMultiFileDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_OpenMultiFileDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_OpenMultiFileDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_OpenMultiFileDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_OpenMultiFileDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}

static_assert(std::is_polymorphic<FSuperMapTable>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FSuperMapTable cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SuperMapTable;
class UScriptStruct* FSuperMapTable::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SuperMapTable.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SuperMapTable.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSuperMapTable, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("SuperMapTable"));
	}
	return Z_Registration_Info_UScriptStruct_SuperMapTable.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FSuperMapTable>()
{
	return FSuperMapTable::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSuperMapTable_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterfaceType_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_InterfaceType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Abbreviation_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Abbreviation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Chinese_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Chinese;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_English_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_English;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Japanese_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Japanese;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMapTable_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSuperMapTable>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_InterfaceType_MetaData[] = {
		{ "Category", "FSuperMapTable" },
		{ "Comment", "//! \\brief \n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_InterfaceType = { "InterfaceType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMapTable, InterfaceType), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_InterfaceType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_InterfaceType_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Abbreviation_MetaData[] = {
		{ "Category", "FSuperMapTable" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Abbreviation = { "Abbreviation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMapTable, Abbreviation), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Abbreviation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Abbreviation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Chinese_MetaData[] = {
		{ "Category", "FSuperMapTable" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Chinese = { "Chinese", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMapTable, Chinese), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Chinese_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Chinese_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_English_MetaData[] = {
		{ "Category", "FSuperMapTable" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_English = { "English", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMapTable, English), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_English_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_English_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Japanese_MetaData[] = {
		{ "Category", "FSuperMapTable" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Japanese = { "Japanese", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMapTable, Japanese), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Japanese_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Japanese_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSuperMapTable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_InterfaceType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Abbreviation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Chinese,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_English,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewProp_Japanese,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSuperMapTable_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"SuperMapTable",
		sizeof(FSuperMapTable),
		alignof(FSuperMapTable),
		Z_Construct_UScriptStruct_FSuperMapTable_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMapTable_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMapTable_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMapTable_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSuperMapTable()
	{
		if (!Z_Registration_Info_UScriptStruct_SuperMapTable.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SuperMapTable.InnerSingleton, Z_Construct_UScriptStruct_FSuperMapTable_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SuperMapTable.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SuperMap_LayerInfo;
class UScriptStruct* FSuperMap_LayerInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SuperMap_LayerInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SuperMap_LayerInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSuperMap_LayerInfo, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("SuperMap_LayerInfo"));
	}
	return Z_Registration_Info_UScriptStruct_SuperMap_LayerInfo.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FSuperMap_LayerInfo>()
{
	return FSuperMap_LayerInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strDatasetName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strDatasetName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strDataName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strDataName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bMarkerLayer_MetaData[];
#endif
		static void NewProp_m_bMarkerLayer_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bMarkerLayer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_nType_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_m_nType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_nLayerType_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_m_nLayerType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strUserName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strUserName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strPassWord_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strPassWord;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_ImageType_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_m_ImageType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_DPI_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_DPI;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_Key_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_Key;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSuperMap_LayerInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strName_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe6\x8d\xae\xe5\x90\x8d\xe5\xad\x97\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe6\x8d\xae\xe5\x90\x8d\xe5\xad\x97" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strName = { "m_strName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_strName), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPath_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe6\x8d\xae\xe8\xb7\xaf\xe5\xbe\x84\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe6\x8d\xae\xe8\xb7\xaf\xe5\xbe\x84" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPath = { "m_strPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_strPath), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDatasetName_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\x90\x8d\xe7\xa7\xb0 or XML\xe5\x85\xb3\xe9\x94\xae\xe5\xad\x97\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\x90\x8d\xe7\xa7\xb0 or XML\xe5\x85\xb3\xe9\x94\xae\xe5\xad\x97" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDatasetName = { "m_strDatasetName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_strDatasetName), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDatasetName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDatasetName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDataName_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief iserver\xe3\x80\x81\xe6\x9c\xac\xe5\x9c\xb0 \xe6\x95\xb0\xe6\x8d\xae\xe7\x9c\x9f\xe5\xae\x9e\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x88\xe5\x9c\xa8\xe9\x87\x8d\xe5\x90\x8d\xe6\x83\x85\xe5\x86\xb5\xe4\xb8\x8b\xef\xbc\x8c\xe6\xad\xa4\xe5\x90\x8d\xe7\xa7\xb0\xe4\xb8\xba\xe7\x9c\x9f\xe5\xae\x9e\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8cm_strName \xe4\xb8\xba\xe2\x80\x9c\xe5\x90\x8d\xe7\xa7\xb0#Num\xe2\x80\x9d\xef\xbc\x89\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief iserver\xe3\x80\x81\xe6\x9c\xac\xe5\x9c\xb0 \xe6\x95\xb0\xe6\x8d\xae\xe7\x9c\x9f\xe5\xae\x9e\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x88\xe5\x9c\xa8\xe9\x87\x8d\xe5\x90\x8d\xe6\x83\x85\xe5\x86\xb5\xe4\xb8\x8b\xef\xbc\x8c\xe6\xad\xa4\xe5\x90\x8d\xe7\xa7\xb0\xe4\xb8\xba\xe7\x9c\x9f\xe5\xae\x9e\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8cm_strName \xe4\xb8\xba\xe2\x80\x9c\xe5\x90\x8d\xe7\xa7\xb0#Num\xe2\x80\x9d\xef\xbc\x89" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDataName = { "m_strDataName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_strDataName), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDataName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDataName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_bMarkerLayer_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe6\x98\xaf\xe5\x90\xa6\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xb0\xe5\xbd\xa2\xe7\xba\xb9\xe7\x90\x86\xe8\x92\x99\xe6\x9d\xbf\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe6\x98\xaf\xe5\x90\xa6\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xb0\xe5\xbd\xa2\xe7\xba\xb9\xe7\x90\x86\xe8\x92\x99\xe6\x9d\xbf" },
	};
#endif
	void Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_bMarkerLayer_SetBit(void* Obj)
	{
		((FSuperMap_LayerInfo*)Obj)->m_bMarkerLayer = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_bMarkerLayer = { "m_bMarkerLayer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSuperMap_LayerInfo), &Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_bMarkerLayer_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_bMarkerLayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_bMarkerLayer_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nType_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief 0:\xe6\x9c\xac\xe5\x9c\xb0 1:iserver 2:\xe5\x85\xac\xe5\x85\xb1\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief 0:\xe6\x9c\xac\xe5\x9c\xb0 1:iserver 2:\xe5\x85\xac\xe5\x85\xb1" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nType = { "m_nType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_nType), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nType_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nLayerType_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief iserver : \xe5\x9b\xbe\xe5\xb1\x82\xe7\xb1\xbb\xe5\x9e\x8b(0:\xe4\xb8\x89\xe7\xbb\xb4\xe5\x88\x87\xe7\x89\x87, 1: \xe5\x9c\xb0\xe5\xbd\xa2, 2: \xe5\xbd\xb1\xe5\x83\x8f, 3: \xe5\x85\xb6\xe4\xbb\x96\xe6\x9c\x8d\xe5\x8a\xa1)\n//! \\brief \xe5\x85\xac\xe5\x85\xb1 : \xe5\x9c\xb0\xe5\x9b\xbe\xe6\x9c\x8d\xe5\x8a\xa1\xe7\xb1\xbb\xe5\x9e\x8b(0: SuperMapTerrain 1 : STK\xe5\x9c\xb0\xe5\xbd\xa2 2 : \xe5\xa4\xa9\xe5\x9c\xb0\xe5\x9b\xbe\xe5\x9c\xb0\xe5\xbd\xa2 3 : \xe5\xa4\xa9\xe5\x9c\xb0\xe5\x9b\xbe 4:Bing Maps 5 : Open Street Map)\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief iserver : \xe5\x9b\xbe\xe5\xb1\x82\xe7\xb1\xbb\xe5\x9e\x8b(0:\xe4\xb8\x89\xe7\xbb\xb4\xe5\x88\x87\xe7\x89\x87, 1: \xe5\x9c\xb0\xe5\xbd\xa2, 2: \xe5\xbd\xb1\xe5\x83\x8f, 3: \xe5\x85\xb6\xe4\xbb\x96\xe6\x9c\x8d\xe5\x8a\xa1)\n! \\brief \xe5\x85\xac\xe5\x85\xb1 : \xe5\x9c\xb0\xe5\x9b\xbe\xe6\x9c\x8d\xe5\x8a\xa1\xe7\xb1\xbb\xe5\x9e\x8b(0: SuperMapTerrain 1 : STK\xe5\x9c\xb0\xe5\xbd\xa2 2 : \xe5\xa4\xa9\xe5\x9c\xb0\xe5\x9b\xbe\xe5\x9c\xb0\xe5\xbd\xa2 3 : \xe5\xa4\xa9\xe5\x9c\xb0\xe5\x9b\xbe 4:Bing Maps 5 : Open Street Map)" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nLayerType = { "m_nLayerType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_nLayerType), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nLayerType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nLayerType_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strUserName_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x85\xac\xe5\x85\xb1\xe6\x9c\x8d\xe5\x8a\xa1\n//! \\brief \xe8\xb4\xa6\xe5\x8f\xb7\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x85\xac\xe5\x85\xb1\xe6\x9c\x8d\xe5\x8a\xa1\n! \\brief \xe8\xb4\xa6\xe5\x8f\xb7" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strUserName = { "m_strUserName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_strUserName), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strUserName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strUserName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPassWord_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\xaf\x86\xe7\xa0\x81\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\xaf\x86\xe7\xa0\x81" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPassWord = { "m_strPassWord", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_strPassWord), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPassWord_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPassWord_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_ImageType_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\xa4\xa9\xe5\x9c\xb0\xe5\x9b\xbe\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\xa4\xa9\xe5\x9c\xb0\xe5\x9b\xbe" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_ImageType = { "m_ImageType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_ImageType), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_ImageType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_ImageType_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_DPI_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_DPI = { "m_DPI", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_DPI), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_DPI_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_DPI_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_Key_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_Key = { "m_Key", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSuperMap_LayerInfo, m_Key), METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_Key_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_Key_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDatasetName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strDataName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_bMarkerLayer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_nLayerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strUserName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_strPassWord,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_ImageType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_DPI,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewProp_m_Key,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"SuperMap_LayerInfo",
		sizeof(FSuperMap_LayerInfo),
		alignof(FSuperMap_LayerInfo),
		Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSuperMap_LayerInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_SuperMap_LayerInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SuperMap_LayerInfo.InnerSingleton, Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SuperMap_LayerInfo.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RealPosition;
class UScriptStruct* FRealPosition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RealPosition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RealPosition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRealPosition, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("RealPosition"));
	}
	return Z_Registration_Info_UScriptStruct_RealPosition.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FRealPosition>()
{
	return FRealPosition::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FRealPosition_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strX_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strX;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strY_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strY;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strZ_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strZ;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strCameraHeight_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strCameraHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRealPosition_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FRealPosition_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRealPosition>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strX_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe7\xbb\x8f\xe5\xba\xa6 X\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe7\xbb\x8f\xe5\xba\xa6 X" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strX = { "m_strX", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRealPosition, m_strX), METADATA_PARAMS(Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strX_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strX_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strY_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe7\xba\xac\xe5\xba\xa6 Y\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe7\xba\xac\xe5\xba\xa6 Y" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strY = { "m_strY", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRealPosition, m_strY), METADATA_PARAMS(Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strY_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strY_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strZ_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe9\xab\x98\xe5\xba\xa6 Z\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe9\xab\x98\xe5\xba\xa6 Z" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strZ = { "m_strZ", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRealPosition, m_strZ), METADATA_PARAMS(Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strZ_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strZ_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strCameraHeight_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe7\x9b\xb8\xe6\x9c\xba\xe9\xab\x98\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe7\x9b\xb8\xe6\x9c\xba\xe9\xab\x98\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strCameraHeight = { "m_strCameraHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRealPosition, m_strCameraHeight), METADATA_PARAMS(Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strCameraHeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strCameraHeight_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRealPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strX,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strY,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strZ,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRealPosition_Statics::NewProp_m_strCameraHeight,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRealPosition_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"RealPosition",
		sizeof(FRealPosition),
		alignof(FRealPosition),
		Z_Construct_UScriptStruct_FRealPosition_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRealPosition_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FRealPosition_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRealPosition_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FRealPosition()
	{
		if (!Z_Registration_Info_UScriptStruct_RealPosition.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RealPosition.InnerSingleton, Z_Construct_UScriptStruct_FRealPosition_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_RealPosition.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MaterialInfo;
class UScriptStruct* FMaterialInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MaterialInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MaterialInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMaterialInfo, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("MaterialInfo"));
	}
	return Z_Registration_Info_UScriptStruct_MaterialInfo.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FMaterialInfo>()
{
	return FMaterialInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMaterialInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strMaterialName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strMaterialName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strLayerName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strLayerName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_pSelectedMatInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_pSelectedMatInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bHsDeafaultParam_MetaData[];
#endif
		static void NewProp_m_bHsDeafaultParam_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bHsDeafaultParam;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_vUVTiling_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_m_vUVTiling;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMaterialInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMaterialInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strMaterialName_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe6\xa8\xa1\xe5\x9e\x8b\xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8\xe5\x90\x8d\xe7\xa7\xb0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe6\xa8\xa1\xe5\x9e\x8b\xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8\xe5\x90\x8d\xe7\xa7\xb0" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strMaterialName = { "m_strMaterialName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMaterialInfo, m_strMaterialName), METADATA_PARAMS(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strMaterialName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strMaterialName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strLayerName_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe6\xa8\xa1\xe5\x9e\x8b\xe7\x9a\x84\xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe6\xa8\xa1\xe5\x9e\x8b\xe7\x9a\x84\xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strLayerName = { "m_strLayerName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMaterialInfo, m_strLayerName), METADATA_PARAMS(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strLayerName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strLayerName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_pSelectedMatInstance_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_pSelectedMatInstance = { "m_pSelectedMatInstance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMaterialInfo, m_pSelectedMatInstance), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_pSelectedMatInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_pSelectedMatInstance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_bHsDeafaultParam_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_bHsDeafaultParam_SetBit(void* Obj)
	{
		((FMaterialInfo*)Obj)->m_bHsDeafaultParam = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_bHsDeafaultParam = { "m_bHsDeafaultParam", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FMaterialInfo), &Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_bHsDeafaultParam_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_bHsDeafaultParam_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_bHsDeafaultParam_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_vUVTiling_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8UV\xe7\xbc\xa9\xe6\x94\xbe\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8UV\xe7\xbc\xa9\xe6\x94\xbe" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_vUVTiling = { "m_vUVTiling", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMaterialInfo, m_vUVTiling), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_vUVTiling_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_vUVTiling_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMaterialInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strMaterialName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_strLayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_pSelectedMatInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_bHsDeafaultParam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewProp_m_vUVTiling,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMaterialInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"MaterialInfo",
		sizeof(FMaterialInfo),
		alignof(FMaterialInfo),
		Z_Construct_UScriptStruct_FMaterialInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMaterialInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMaterialInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMaterialInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_MaterialInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MaterialInfo.InnerSingleton, Z_Construct_UScriptStruct_FMaterialInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MaterialInfo.InnerSingleton;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetDataSetType)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_layerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetDataSetType(Z_Param_layerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetMaterialParams)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaterialParams();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetSceneParams)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSceneParams();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetSceneParamsFromJson)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSceneParamsFromJson();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execExportMaterialFromS3MLayer)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ScpFilePath);
		P_GET_PROPERTY(FNameProperty,Z_Param_LayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ExportMaterialFromS3MLayer(Z_Param_ScpFilePath,Z_Param_LayerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetStereoMode)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_type);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetStereoMode(Z_Param_type);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execDatasetMaterialToJson)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strDataset);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DatasetMaterialToJson(Z_Param_strDataset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execClearAssetResoure)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearAssetResoure();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execAddAssetResoure)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_nIndex);
		P_GET_PROPERTY(FStrProperty,Z_Param_strAssetResourePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddAssetResoure(Z_Param_nIndex,Z_Param_strAssetResourePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execQueryField)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strName);
		P_GET_PROPERTY(FStrProperty,Z_Param_strFieldInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->QueryField(Z_Param_strName,Z_Param_strFieldInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetFieldInfos)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetFieldInfos(Z_Param_strName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetDatasetName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strLayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDatasetName(Z_Param_strLayerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetImportAsset)
	{
		P_GET_UBOOL(Z_Param_bImportAsset);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetImportAsset(Z_Param_bImportAsset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetDatasourcePath)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDatasourcePath(Z_Param_strName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetDatasetList)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strFileName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetDatasetList(Z_Param_strFileName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetFieldAssetResoure)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strName);
		P_GET_PROPERTY(FStrProperty,Z_Param_strFieldInfo);
		P_GET_PROPERTY(FIntProperty,Z_Param_nAssetType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetFieldAssetResoure(Z_Param_strName,Z_Param_strFieldInfo,Z_Param_nAssetType);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetEnableCollision)
	{
		P_GET_UBOOL(Z_Param_bEnable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEnableCollision(Z_Param_bEnable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetEnableComputeNormal)
	{
		P_GET_UBOOL(Z_Param_bEnable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEnableComputeNormal(Z_Param_bEnable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetGeoreferenceOrigin)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetGeoreferenceOrigin();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetGeoreferenceOrigin)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fLongitude);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fLatitude);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fAltitude);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGeoreferenceOrigin(Z_Param_fLongitude,Z_Param_fLatitude,Z_Param_fAltitude);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetCameraFov)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCameraFov();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetCameraFov)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fFov);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCameraFov(Z_Param_fFov);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetUserAction)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUserAction(Z_Param_mode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetEditorAction)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEditorAction(Z_Param_mode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execDeleteObjectMaterialInfo)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_LayerName);
		P_GET_PROPERTY(FStrProperty,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DeleteObjectMaterialInfo(Z_Param_LayerName,Z_Param_Key);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetObjectMaterialInfo)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_LayerName);
		P_GET_PROPERTY(FStrProperty,Z_Param_Key);
		P_GET_PROPERTY(FStrProperty,Z_Param_materialName);
		P_GET_PROPERTY(FStrProperty,Z_Param_materialPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetObjectMaterialInfo(Z_Param_LayerName,Z_Param_Key,Z_Param_materialName,Z_Param_materialPath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetSelectMaterialInfo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FMaterialInfo*)Z_Param__Result=P_THIS->GetSelectMaterialInfo();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetRestoreLayers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetRestoreLayers();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetS3MLayers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetS3MLayers();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetHypsometricSettingLayers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetHypsometricSettingLayers();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execModificationLayerName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strName);
		P_GET_PROPERTY(FIntProperty,Z_Param_num);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->ModificationLayerName(Z_Param_strName,Z_Param_num);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execPlayingActor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->PlayingActor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetEditorState)
	{
		P_GET_UBOOL(Z_Param_isTick);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEditorState(Z_Param_isTick);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetLayerObjectMaterial)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_TMAP(FString,FString,Z_Param_m_mapMaterialNameChanges);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetLayerObjectMaterial(Z_Param_strName,Z_Param_m_mapMaterialNameChanges);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetLayerMaterial)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_PROPERTY(FStrProperty,Z_Param_strPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetLayerMaterial(Z_Param_strName,Z_Param_strPath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execFromXML)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FromXML(Z_Param_strPath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execToXML)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ToXML(Z_Param_strPath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetRealPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FRealPosition*)Z_Param__Result=P_THIS->GetRealPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetLocalPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FRealPosition*)Z_Param__Result=P_THIS->GetLocalPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execIsSecondTerrainLayer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsSecondTerrainLayer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetTerrainLayersCount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetTerrainLayersCount();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execRemoveLayer_Web)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_layerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveLayer_Web(Z_Param_layerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execRemoveTerrainLayer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveTerrainLayer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execRemoveLayer)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_layerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveLayer(Z_Param_layerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execAddWMTSMap)
	{
		P_GET_STRUCT(FSuperMap_LayerInfo,Z_Param_strLayers);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddWMTSMap(Z_Param_strLayers);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execAddUrlLayers)
	{
		P_GET_STRUCT(FSuperMap_LayerInfo,Z_Param_strLayers);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddUrlLayers(Z_Param_strLayers);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execAddLocalLayers)
	{
		P_GET_STRUCT(FSuperMap_LayerInfo,Z_Param_strLayers);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddLocalLayers(Z_Param_strLayers);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execGetLayerType)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_layer);
		P_GET_UBOOL(Z_Param_bBaseFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetLayerType(Z_Param_layer,Z_Param_bBaseFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetIsShowRealPosition)
	{
		P_GET_UBOOL(Z_Param_bShowRealPosition);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsShowRealPosition(Z_Param_bShowRealPosition);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execSetSceneType)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nSceneType);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSceneType(Z_Param_nSceneType);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execOpenFileFolderDialog)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->OpenFileFolderDialog();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MainActor::execOpenFileDialog)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strFileTypes);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->OpenFileDialog(Z_Param_strFileTypes);
		P_NATIVE_END;
	}
	void ASuperMap_MainActor::StaticRegisterNativesASuperMap_MainActor()
	{
		UClass* Class = ASuperMap_MainActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddAssetResoure", &ASuperMap_MainActor::execAddAssetResoure },
			{ "AddLocalLayers", &ASuperMap_MainActor::execAddLocalLayers },
			{ "AddUrlLayers", &ASuperMap_MainActor::execAddUrlLayers },
			{ "AddWMTSMap", &ASuperMap_MainActor::execAddWMTSMap },
			{ "ClearAssetResoure", &ASuperMap_MainActor::execClearAssetResoure },
			{ "DatasetMaterialToJson", &ASuperMap_MainActor::execDatasetMaterialToJson },
			{ "DeleteObjectMaterialInfo", &ASuperMap_MainActor::execDeleteObjectMaterialInfo },
			{ "ExportMaterialFromS3MLayer", &ASuperMap_MainActor::execExportMaterialFromS3MLayer },
			{ "FromXML", &ASuperMap_MainActor::execFromXML },
			{ "GetCameraFov", &ASuperMap_MainActor::execGetCameraFov },
			{ "GetDatasetList", &ASuperMap_MainActor::execGetDatasetList },
			{ "GetDatasetName", &ASuperMap_MainActor::execGetDatasetName },
			{ "GetDataSetType", &ASuperMap_MainActor::execGetDataSetType },
			{ "GetDatasourcePath", &ASuperMap_MainActor::execGetDatasourcePath },
			{ "GetFieldInfos", &ASuperMap_MainActor::execGetFieldInfos },
			{ "GetGeoreferenceOrigin", &ASuperMap_MainActor::execGetGeoreferenceOrigin },
			{ "GetHypsometricSettingLayers", &ASuperMap_MainActor::execGetHypsometricSettingLayers },
			{ "GetLayerType", &ASuperMap_MainActor::execGetLayerType },
			{ "GetLocalPosition", &ASuperMap_MainActor::execGetLocalPosition },
			{ "GetRealPosition", &ASuperMap_MainActor::execGetRealPosition },
			{ "GetRestoreLayers", &ASuperMap_MainActor::execGetRestoreLayers },
			{ "GetS3MLayers", &ASuperMap_MainActor::execGetS3MLayers },
			{ "GetSelectMaterialInfo", &ASuperMap_MainActor::execGetSelectMaterialInfo },
			{ "GetTerrainLayersCount", &ASuperMap_MainActor::execGetTerrainLayersCount },
			{ "IsSecondTerrainLayer", &ASuperMap_MainActor::execIsSecondTerrainLayer },
			{ "ModificationLayerName", &ASuperMap_MainActor::execModificationLayerName },
			{ "OpenFileDialog", &ASuperMap_MainActor::execOpenFileDialog },
			{ "OpenFileFolderDialog", &ASuperMap_MainActor::execOpenFileFolderDialog },
			{ "PlayingActor", &ASuperMap_MainActor::execPlayingActor },
			{ "QueryField", &ASuperMap_MainActor::execQueryField },
			{ "RemoveLayer", &ASuperMap_MainActor::execRemoveLayer },
			{ "RemoveLayer_Web", &ASuperMap_MainActor::execRemoveLayer_Web },
			{ "RemoveTerrainLayer", &ASuperMap_MainActor::execRemoveTerrainLayer },
			{ "SetCameraFov", &ASuperMap_MainActor::execSetCameraFov },
			{ "SetEditorAction", &ASuperMap_MainActor::execSetEditorAction },
			{ "SetEditorState", &ASuperMap_MainActor::execSetEditorState },
			{ "SetEnableCollision", &ASuperMap_MainActor::execSetEnableCollision },
			{ "SetEnableComputeNormal", &ASuperMap_MainActor::execSetEnableComputeNormal },
			{ "SetFieldAssetResoure", &ASuperMap_MainActor::execSetFieldAssetResoure },
			{ "SetGeoreferenceOrigin", &ASuperMap_MainActor::execSetGeoreferenceOrigin },
			{ "SetImportAsset", &ASuperMap_MainActor::execSetImportAsset },
			{ "SetIsShowRealPosition", &ASuperMap_MainActor::execSetIsShowRealPosition },
			{ "SetLayerMaterial", &ASuperMap_MainActor::execSetLayerMaterial },
			{ "SetLayerObjectMaterial", &ASuperMap_MainActor::execSetLayerObjectMaterial },
			{ "SetMaterialParams", &ASuperMap_MainActor::execSetMaterialParams },
			{ "SetObjectMaterialInfo", &ASuperMap_MainActor::execSetObjectMaterialInfo },
			{ "SetSceneParams", &ASuperMap_MainActor::execSetSceneParams },
			{ "SetSceneParamsFromJson", &ASuperMap_MainActor::execSetSceneParamsFromJson },
			{ "SetSceneType", &ASuperMap_MainActor::execSetSceneType },
			{ "SetStereoMode", &ASuperMap_MainActor::execSetStereoMode },
			{ "SetUserAction", &ASuperMap_MainActor::execSetUserAction },
			{ "ToXML", &ASuperMap_MainActor::execToXML },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics
	{
		struct SuperMap_MainActor_eventAddAssetResoure_Parms
		{
			FString nIndex;
			FString strAssetResourePath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_nIndex;
		static const UECodeGen_Private::FStrPropertyParams NewProp_strAssetResourePath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::NewProp_nIndex = { "nIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventAddAssetResoure_Parms, nIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::NewProp_strAssetResourePath = { "strAssetResourePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventAddAssetResoure_Parms, strAssetResourePath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::NewProp_nIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::NewProp_strAssetResourePath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe6\xb7\xbb\xe5\x8a\xa0\xe7\x82\xb9\xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe8\xb7\xaf\xe5\xbe\x84\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\xb7\xbb\xe5\x8a\xa0\xe7\x82\xb9\xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe8\xb7\xaf\xe5\xbe\x84" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "AddAssetResoure", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::SuperMap_MainActor_eventAddAssetResoure_Parms), Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics
	{
		struct SuperMap_MainActor_eventAddLocalLayers_Parms
		{
			FSuperMap_LayerInfo strLayers;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_strLayers;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::NewProp_strLayers = { "strLayers", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventAddLocalLayers_Parms, strLayers), Z_Construct_UScriptStruct_FSuperMap_LayerInfo, METADATA_PARAMS(nullptr, 0) }; // 2973872049
	void Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventAddLocalLayers_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventAddLocalLayers_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::NewProp_strLayers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\xb7\xbb\xe5\x8a\xa0\xe6\x9c\xac\xe5\x9c\xb0\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\xb7\xbb\xe5\x8a\xa0\xe6\x9c\xac\xe5\x9c\xb0\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "AddLocalLayers", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::SuperMap_MainActor_eventAddLocalLayers_Parms), Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics
	{
		struct SuperMap_MainActor_eventAddUrlLayers_Parms
		{
			FSuperMap_LayerInfo strLayers;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_strLayers;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::NewProp_strLayers = { "strLayers", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventAddUrlLayers_Parms, strLayers), Z_Construct_UScriptStruct_FSuperMap_LayerInfo, METADATA_PARAMS(nullptr, 0) }; // 2973872049
	void Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventAddUrlLayers_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventAddUrlLayers_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::NewProp_strLayers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\xb7\xbb\xe5\x8a\xa0\xe5\x9c\xa8\xe7\xba\xbf\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\xb7\xbb\xe5\x8a\xa0\xe5\x9c\xa8\xe7\xba\xbf\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "AddUrlLayers", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::SuperMap_MainActor_eventAddUrlLayers_Parms), Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics
	{
		struct SuperMap_MainActor_eventAddWMTSMap_Parms
		{
			FSuperMap_LayerInfo strLayers;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_strLayers;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::NewProp_strLayers = { "strLayers", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventAddWMTSMap_Parms, strLayers), Z_Construct_UScriptStruct_FSuperMap_LayerInfo, METADATA_PARAMS(nullptr, 0) }; // 2973872049
	void Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventAddWMTSMap_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventAddWMTSMap_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::NewProp_strLayers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\xb7\xbb\xe5\x8a\xa0""arcgis\xe6\x9c\x8d\xe5\x8a\xa1\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\xb7\xbb\xe5\x8a\xa0""arcgis\xe6\x9c\x8d\xe5\x8a\xa1" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "AddWMTSMap", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::SuperMap_MainActor_eventAddWMTSMap_Parms), Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_ClearAssetResoure_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_ClearAssetResoure_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe6\xb8\x85\xe7\xa9\xba\xe8\xb5\x84\xe4\xba\xa7\xe8\xb7\xaf\xe5\xbe\x84\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\xb8\x85\xe7\xa9\xba\xe8\xb5\x84\xe4\xba\xa7\xe8\xb7\xaf\xe5\xbe\x84" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_ClearAssetResoure_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "ClearAssetResoure", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_ClearAssetResoure_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_ClearAssetResoure_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_ClearAssetResoure()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_ClearAssetResoure_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics
	{
		struct SuperMap_MainActor_eventDatasetMaterialToJson_Parms
		{
			FString strDataset;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strDataset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::NewProp_strDataset = { "strDataset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventDatasetMaterialToJson_Parms, strDataset), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::NewProp_strDataset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe6\xa8\xa1\xe5\x9e\x8b\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe6\x9d\x90\xe8\xb4\xa8\xe4\xbf\x9d\xe5\xad\x98Json\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\xa8\xa1\xe5\x9e\x8b\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe6\x9d\x90\xe8\xb4\xa8\xe4\xbf\x9d\xe5\xad\x98Json" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "DatasetMaterialToJson", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::SuperMap_MainActor_eventDatasetMaterialToJson_Parms), Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics
	{
		struct SuperMap_MainActor_eventDeleteObjectMaterialInfo_Parms
		{
			FString LayerName;
			FString Key;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_LayerName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::NewProp_LayerName = { "LayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventDeleteObjectMaterialInfo_Parms, LayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventDeleteObjectMaterialInfo_Parms, Key), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::NewProp_LayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::NewProp_Key,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x88\xa0\xe9\x99\xa4\xe7\xbe\x8e\xe5\x8c\x96\xe6\x9d\x90\xe8\xb4\xa8\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x88\xa0\xe9\x99\xa4\xe7\xbe\x8e\xe5\x8c\x96\xe6\x9d\x90\xe8\xb4\xa8" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "DeleteObjectMaterialInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::SuperMap_MainActor_eventDeleteObjectMaterialInfo_Parms), Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics
	{
		struct SuperMap_MainActor_eventExportMaterialFromS3MLayer_Parms
		{
			FString ScpFilePath;
			FName LayerName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ScpFilePath;
		static const UECodeGen_Private::FNamePropertyParams NewProp_LayerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::NewProp_ScpFilePath = { "ScpFilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventExportMaterialFromS3MLayer_Parms, ScpFilePath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::NewProp_LayerName = { "LayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventExportMaterialFromS3MLayer_Parms, LayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::NewProp_ScpFilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::NewProp_LayerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\xaf\xbc\xe5\x87\xbaS3M\xe5\x9b\xbe\xe5\xb1\x82\xe5\x85\xb3\xe8\x81\x94UE\xe6\x9d\x90\xe8\xb4\xa8\n//! \xe4\xbd\xbf\xe7\x94\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe6\xb7\xbb\xe5\x8a\xa0\xe5\xaf\xb9\xe5\xba\x94\xe6\x8f\x92\xe4\xbb\xb6\xef\xbc\x9a\n//!\"MtlAnalyzer\",\n//!\"MtlBaking\",\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\xaf\xbc\xe5\x87\xbaS3M\xe5\x9b\xbe\xe5\xb1\x82\xe5\x85\xb3\xe8\x81\x94UE\xe6\x9d\x90\xe8\xb4\xa8\n! \xe4\xbd\xbf\xe7\x94\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe6\xb7\xbb\xe5\x8a\xa0\xe5\xaf\xb9\xe5\xba\x94\xe6\x8f\x92\xe4\xbb\xb6\xef\xbc\x9a\n!\"MtlAnalyzer\",\n!\"MtlBaking\"," },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "ExportMaterialFromS3MLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::SuperMap_MainActor_eventExportMaterialFromS3MLayer_Parms), Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics
	{
		struct SuperMap_MainActor_eventFromXML_Parms
		{
			FString strPath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strPath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::NewProp_strPath = { "strPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventFromXML_Parms, strPath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::NewProp_strPath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\xb7\xbb\xe5\x8a\xa0XML\xe4\xb8\xad\xe8\xae\xb0\xe5\xbd\x95\xe7\x9a\x84\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\xb7\xbb\xe5\x8a\xa0XML\xe4\xb8\xad\xe8\xae\xb0\xe5\xbd\x95\xe7\x9a\x84\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "FromXML", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::SuperMap_MainActor_eventFromXML_Parms), Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_FromXML()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_FromXML_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics
	{
		struct SuperMap_MainActor_eventGetCameraFov_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetCameraFov_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe7\x9b\xb8\xe6\x9c\xba""Fov\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe7\x9b\xb8\xe6\x9c\xba""Fov" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetCameraFov", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::SuperMap_MainActor_eventGetCameraFov_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics
	{
		struct SuperMap_MainActor_eventGetDatasetList_Parms
		{
			FString strFileName;
			TArray<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strFileName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::NewProp_strFileName = { "strFileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetDatasetList_Parms, strFileName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetDatasetList_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::NewProp_strFileName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe6\xba\x90\xe6\x89\x80\xe6\x9c\x89\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe6\xba\x90\xe6\x89\x80\xe6\x9c\x89\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetDatasetList", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::SuperMap_MainActor_eventGetDatasetList_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics
	{
		struct SuperMap_MainActor_eventGetDatasetName_Parms
		{
			FString strLayerName;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strLayerName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetDatasetName_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetDatasetName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::NewProp_strLayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\x90\x8d\xe7\xa7\xb0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\x90\x8d\xe7\xa7\xb0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetDatasetName", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::SuperMap_MainActor_eventGetDatasetName_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics
	{
		struct SuperMap_MainActor_eventGetDataSetType_Parms
		{
			FString layerName;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_layerName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetDataSetType_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetDataSetType_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::NewProp_layerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe7\xb1\xbb\xe5\x9e\x8b\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe7\xb1\xbb\xe5\x9e\x8b" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetDataSetType", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::SuperMap_MainActor_eventGetDataSetType_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics
	{
		struct SuperMap_MainActor_eventGetDatasourcePath_Parms
		{
			FString strName;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetDatasourcePath_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetDatasourcePath_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe6\xba\x90\xe8\xb7\xaf\xe5\xbe\x84\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe6\xba\x90\xe8\xb7\xaf\xe5\xbe\x84" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetDatasourcePath", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::SuperMap_MainActor_eventGetDatasourcePath_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics
	{
		struct SuperMap_MainActor_eventGetFieldInfos_Parms
		{
			FString strName;
			TArray<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetFieldInfos_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetFieldInfos_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe7\xb1\xbb\xe5\x9e\x8b\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe7\xb1\xbb\xe5\x9e\x8b" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetFieldInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::SuperMap_MainActor_eventGetFieldInfos_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics
	{
		struct SuperMap_MainActor_eventGetGeoreferenceOrigin_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetGeoreferenceOrigin_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xb0\xe7\x90\x86\xe5\x8e\x9f\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xb0\xe7\x90\x86\xe5\x8e\x9f\xe7\x82\xb9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetGeoreferenceOrigin", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::SuperMap_MainActor_eventGetGeoreferenceOrigin_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics
	{
		struct SuperMap_MainActor_eventGetHypsometricSettingLayers_Parms
		{
			TArray<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetHypsometricSettingLayers_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96HypsometricSetting\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96HypsometricSetting\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetHypsometricSettingLayers", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::SuperMap_MainActor_eventGetHypsometricSettingLayers_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics
	{
		struct SuperMap_MainActor_eventGetLayerType_Parms
		{
			FString layer;
			bool bBaseFile;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_layer;
		static void NewProp_bBaseFile_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bBaseFile;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::NewProp_layer = { "layer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetLayerType_Parms, layer), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::NewProp_bBaseFile_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventGetLayerType_Parms*)Obj)->bBaseFile = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::NewProp_bBaseFile = { "bBaseFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventGetLayerType_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::NewProp_bBaseFile_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetLayerType_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::NewProp_layer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::NewProp_bBaseFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6\xe7\xb1\xbb\xe5\x9e\x8b\n//! \\param layer [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0\n//! \\return 1\xef\xbc\x9a\xe6\x99\xae\xe9\x80\x9a\xe5\x9b\xbe\xe5\xb1\x82 2\xef\xbc\x9a\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6\xe7\xb1\xbb\xe5\x9e\x8b\n! \\param layer [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0\n! \\return 1\xef\xbc\x9a\xe6\x99\xae\xe9\x80\x9a\xe5\x9b\xbe\xe5\xb1\x82 2\xef\xbc\x9a\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetLayerType", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::SuperMap_MainActor_eventGetLayerType_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics
	{
		struct SuperMap_MainActor_eventGetLocalPosition_Parms
		{
			FRealPosition ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetLocalPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FRealPosition, METADATA_PARAMS(nullptr, 0) }; // 1343390513
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe9\xbc\xa0\xe6\xa0\x87\xe4\xbd\x8d\xe7\xbd\xae\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe9\xbc\xa0\xe6\xa0\x87\xe4\xbd\x8d\xe7\xbd\xae" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetLocalPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::SuperMap_MainActor_eventGetLocalPosition_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics
	{
		struct SuperMap_MainActor_eventGetRealPosition_Parms
		{
			FRealPosition ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetRealPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FRealPosition, METADATA_PARAMS(nullptr, 0) }; // 1343390513
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe9\xbc\xa0\xe6\xa0\x87\xe4\xbd\x8d\xe7\xbd\xae\xef\xbc\x8c\xe7\x9b\xb8\xe6\x9c\xba\xe9\xab\x98\xe5\xba\xa6\xef\xbc\x88\xe5\xae\x9e\xe6\x97\xb6\xef\xbc\x89\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe9\xbc\xa0\xe6\xa0\x87\xe4\xbd\x8d\xe7\xbd\xae\xef\xbc\x8c\xe7\x9b\xb8\xe6\x9c\xba\xe9\xab\x98\xe5\xba\xa6\xef\xbc\x88\xe5\xae\x9e\xe6\x97\xb6\xef\xbc\x89" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetRealPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::SuperMap_MainActor_eventGetRealPosition_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics
	{
		struct SuperMap_MainActor_eventGetRestoreLayers_Parms
		{
			TArray<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetRestoreLayers_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x8f\xaf\xe5\x88\x86\xe5\xb1\x8f\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x8f\xaf\xe5\x88\x86\xe5\xb1\x8f\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetRestoreLayers", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::SuperMap_MainActor_eventGetRestoreLayers_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics
	{
		struct SuperMap_MainActor_eventGetS3MLayers_Parms
		{
			TArray<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetS3MLayers_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96S3M\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96S3M\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetS3MLayers", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::SuperMap_MainActor_eventGetS3MLayers_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics
	{
		struct SuperMap_MainActor_eventGetSelectMaterialInfo_Parms
		{
			FMaterialInfo ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetSelectMaterialInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FMaterialInfo, METADATA_PARAMS(nullptr, 0) }; // 1562136874
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe9\x80\x89\xe4\xb8\xad\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8\xe5\x90\x8d\xe7\xa7\xb0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe9\x80\x89\xe4\xb8\xad\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe6\x9d\x90\xe8\xb4\xa8\xe5\x90\x8d\xe7\xa7\xb0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetSelectMaterialInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::SuperMap_MainActor_eventGetSelectMaterialInfo_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics
	{
		struct SuperMap_MainActor_eventGetTerrainLayersCount_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventGetTerrainLayersCount_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe9\x87\x8f\n//! \\return \xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe9\x87\x8f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe9\x87\x8f\n! \\return \xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe9\x87\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "GetTerrainLayersCount", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::SuperMap_MainActor_eventGetTerrainLayersCount_Parms), Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics
	{
		struct SuperMap_MainActor_eventIsSecondTerrainLayer_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventIsSecondTerrainLayer_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventIsSecondTerrainLayer_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe4\xb8\xba\xe5\xa4\x9a\xe4\xbd\x99\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82\n//! \\return false\xe6\x98\xaf\xe5\xa4\x9a\xe4\xbd\x99\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe4\xb8\xba\xe5\xa4\x9a\xe4\xbd\x99\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82\n! \\return false\xe6\x98\xaf\xe5\xa4\x9a\xe4\xbd\x99\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "IsSecondTerrainLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::SuperMap_MainActor_eventIsSecondTerrainLayer_Parms), Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics
	{
		struct SuperMap_MainActor_eventModificationLayerName_Parms
		{
			FString strName;
			int32 num;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_num;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventModificationLayerName_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::NewProp_num = { "num", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventModificationLayerName_Parms, num), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventModificationLayerName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::NewProp_num,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe4\xbf\xae\xe6\x94\xb9\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe4\xbf\xae\xe6\x94\xb9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "ModificationLayerName", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::SuperMap_MainActor_eventModificationLayerName_Parms), Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics
	{
		struct SuperMap_MainActor_eventOpenFileDialog_Parms
		{
			FString strFileTypes;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strFileTypes;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::NewProp_strFileTypes = { "strFileTypes", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventOpenFileDialog_Parms, strFileTypes), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventOpenFileDialog_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventOpenFileDialog_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::NewProp_strFileTypes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe6\x96\x87\xe4\xbb\xb6\n//! \\return \xe5\xa6\x82\xe6\x9e\x9c\xe9\x80\x89\xe6\x8b\xa9\xe6\x96\x87\xe4\xbb\xb6\xe6\x88\x90\xe5\x8a\x9f\xe8\xbf\x94\xe5\x9b\x9etrue\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe6\x96\x87\xe4\xbb\xb6\n! \\return \xe5\xa6\x82\xe6\x9e\x9c\xe9\x80\x89\xe6\x8b\xa9\xe6\x96\x87\xe4\xbb\xb6\xe6\x88\x90\xe5\x8a\x9f\xe8\xbf\x94\xe5\x9b\x9etrue" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "OpenFileDialog", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::SuperMap_MainActor_eventOpenFileDialog_Parms), Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics
	{
		struct SuperMap_MainActor_eventOpenFileFolderDialog_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventOpenFileFolderDialog_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventOpenFileFolderDialog_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe6\x96\x87\xe4\xbb\xb6\xe5\xa4\xb9\n//! \\return \xe5\xa6\x82\xe6\x9e\x9c\xe9\x80\x89\xe6\x8b\xa9\xe6\x96\x87\xe4\xbb\xb6\xe5\xa4\xb9\xe6\x88\x90\xe5\x8a\x9f\xe8\xbf\x94\xe5\x9b\x9etrue\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe6\x96\x87\xe4\xbb\xb6\xe5\xa4\xb9\n! \\return \xe5\xa6\x82\xe6\x9e\x9c\xe9\x80\x89\xe6\x8b\xa9\xe6\x96\x87\xe4\xbb\xb6\xe5\xa4\xb9\xe6\x88\x90\xe5\x8a\x9f\xe8\xbf\x94\xe5\x9b\x9etrue" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "OpenFileFolderDialog", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::SuperMap_MainActor_eventOpenFileFolderDialog_Parms), Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics
	{
		struct SuperMap_MainActor_eventPlayingActor_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventPlayingActor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventPlayingActor_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xaf\xe8\xbf\x90\xe8\xa1\x8c\xe6\xa8\xa1\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xaf\xe8\xbf\x90\xe8\xa1\x8c\xe6\xa8\xa1\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "PlayingActor", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::SuperMap_MainActor_eventPlayingActor_Parms), Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics
	{
		struct SuperMap_MainActor_eventQueryField_Parms
		{
			FString strName;
			FString strFieldInfo;
			TArray<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_strFieldInfo;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventQueryField_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::NewProp_strFieldInfo = { "strFieldInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventQueryField_Parms, strFieldInfo), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventQueryField_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::NewProp_strFieldInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x89\x80\xe5\x90\xab\xe5\x8f\x82\xe6\x95\xb0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x89\x80\xe5\x90\xab\xe5\x8f\x82\xe6\x95\xb0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "QueryField", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::SuperMap_MainActor_eventQueryField_Parms), Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_QueryField()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_QueryField_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics
	{
		struct SuperMap_MainActor_eventRemoveLayer_Parms
		{
			FString layerName;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_layerName;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventRemoveLayer_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventRemoveLayer_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventRemoveLayer_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::NewProp_layerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe5\x9b\xbe\xe5\xb1\x82\n//! \\param layer [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe5\x9b\xbe\xe5\xb1\x82\n! \\param layer [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "RemoveLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::SuperMap_MainActor_eventRemoveLayer_Parms), Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics
	{
		struct SuperMap_MainActor_eventRemoveLayer_Web_Parms
		{
			FString layerName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_layerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventRemoveLayer_Web_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::NewProp_layerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief Web\xe7\xab\xaf\xe7\xa7\xbb\xe9\x99\xa4\xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe7\xbb\x84\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief Web\xe7\xab\xaf\xe7\xa7\xbb\xe9\x99\xa4\xe5\x9b\xbe\xe5\xb1\x82\xe6\x95\xb0\xe7\xbb\x84" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "RemoveLayer_Web", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::SuperMap_MainActor_eventRemoveLayer_Web_Parms), Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics
	{
		struct SuperMap_MainActor_eventRemoveTerrainLayer_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventRemoveTerrainLayer_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventRemoveTerrainLayer_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "RemoveTerrainLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::SuperMap_MainActor_eventRemoveTerrainLayer_Parms), Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics
	{
		struct SuperMap_MainActor_eventSetCameraFov_Parms
		{
			float fFov;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fFov;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::NewProp_fFov = { "fFov", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetCameraFov_Parms, fFov), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::NewProp_fFov,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\x9b\xb8\xe6\x9c\xba""Fov\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\x9b\xb8\xe6\x9c\xba""Fov" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetCameraFov", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::SuperMap_MainActor_eventSetCameraFov_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics
	{
		struct SuperMap_MainActor_eventSetEditorAction_Parms
		{
			int32 mode;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_mode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::NewProp_mode = { "mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetEditorAction_Parms, mode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::NewProp_mode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xbc\x96\xe8\xbe\x91\xe6\x96\xb9\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xbc\x96\xe8\xbe\x91\xe6\x96\xb9\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetEditorAction", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::SuperMap_MainActor_eventSetEditorAction_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics
	{
		struct SuperMap_MainActor_eventSetEditorState_Parms
		{
			bool isTick;
		};
		static void NewProp_isTick_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isTick;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::NewProp_isTick_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventSetEditorState_Parms*)Obj)->isTick = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::NewProp_isTick = { "isTick", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventSetEditorState_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::NewProp_isTick_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::NewProp_isTick,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x85\xb3\xe9\x97\xad\xe7\xbc\x96\xe8\xbe\x91\xe6\xa8\xa1\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x85\xb3\xe9\x97\xad\xe7\xbc\x96\xe8\xbe\x91\xe6\xa8\xa1\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetEditorState", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::SuperMap_MainActor_eventSetEditorState_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics
	{
		struct SuperMap_MainActor_eventSetEnableCollision_Parms
		{
			bool bEnable;
		};
		static void NewProp_bEnable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::NewProp_bEnable_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventSetEnableCollision_Parms*)Obj)->bEnable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::NewProp_bEnable = { "bEnable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventSetEnableCollision_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::NewProp_bEnable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::NewProp_bEnable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xa2\xb0\xe6\x92\x9e\xe6\xa3\x80\xe6\xb5\x8b\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xa2\xb0\xe6\x92\x9e\xe6\xa3\x80\xe6\xb5\x8b" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetEnableCollision", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::SuperMap_MainActor_eventSetEnableCollision_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics
	{
		struct SuperMap_MainActor_eventSetEnableComputeNormal_Parms
		{
			bool bEnable;
		};
		static void NewProp_bEnable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::NewProp_bEnable_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventSetEnableComputeNormal_Parms*)Obj)->bEnable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::NewProp_bEnable = { "bEnable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventSetEnableComputeNormal_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::NewProp_bEnable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::NewProp_bEnable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe6\x98\xaf\xe5\x90\xa6\xe8\xae\xa1\xe7\xae\x97\xe6\xb3\x95\xe7\xba\xbf\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe6\x98\xaf\xe5\x90\xa6\xe8\xae\xa1\xe7\xae\x97\xe6\xb3\x95\xe7\xba\xbf" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetEnableComputeNormal", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::SuperMap_MainActor_eventSetEnableComputeNormal_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics
	{
		struct SuperMap_MainActor_eventSetFieldAssetResoure_Parms
		{
			FString strName;
			FString strFieldInfo;
			int32 nAssetType;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_strFieldInfo;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nAssetType;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetFieldAssetResoure_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_strFieldInfo = { "strFieldInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetFieldAssetResoure_Parms, strFieldInfo), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_nAssetType = { "nAssetType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetFieldAssetResoure_Parms, nAssetType), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventSetFieldAssetResoure_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventSetFieldAssetResoure_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_strFieldInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_nAssetType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//===============================================================\n//! \\brief \xe5\xa4\x96\xe6\x8c\x82\xe8\xb5\x84\xe4\xba\xa7\xe8\x8e\xb7\xe5\x8f\x96\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\xa4\x96\xe6\x8c\x82\xe8\xb5\x84\xe4\xba\xa7\xe8\x8e\xb7\xe5\x8f\x96" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetFieldAssetResoure", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::SuperMap_MainActor_eventSetFieldAssetResoure_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics
	{
		struct SuperMap_MainActor_eventSetGeoreferenceOrigin_Parms
		{
			float fLongitude;
			float fLatitude;
			float fAltitude;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fLongitude;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fLatitude;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fAltitude;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::NewProp_fLongitude = { "fLongitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetGeoreferenceOrigin_Parms, fLongitude), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::NewProp_fLatitude = { "fLatitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetGeoreferenceOrigin_Parms, fLatitude), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::NewProp_fAltitude = { "fAltitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetGeoreferenceOrigin_Parms, fAltitude), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::NewProp_fLongitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::NewProp_fLatitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::NewProp_fAltitude,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xb0\xe7\x90\x86\xe5\x8e\x9f\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xb0\xe7\x90\x86\xe5\x8e\x9f\xe7\x82\xb9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetGeoreferenceOrigin", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::SuperMap_MainActor_eventSetGeoreferenceOrigin_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics
	{
		struct SuperMap_MainActor_eventSetImportAsset_Parms
		{
			bool bImportAsset;
		};
		static void NewProp_bImportAsset_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bImportAsset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::NewProp_bImportAsset_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventSetImportAsset_Parms*)Obj)->bImportAsset = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::NewProp_bImportAsset = { "bImportAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventSetImportAsset_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::NewProp_bImportAsset_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::NewProp_bImportAsset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\x8a\xa0\xe8\xbd\xbd\xe6\x96\xb9\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\x8a\xa0\xe8\xbd\xbd\xe6\x96\xb9\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetImportAsset", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::SuperMap_MainActor_eventSetImportAsset_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics
	{
		struct SuperMap_MainActor_eventSetIsShowRealPosition_Parms
		{
			bool bShowRealPosition;
		};
		static void NewProp_bShowRealPosition_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowRealPosition;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::NewProp_bShowRealPosition_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventSetIsShowRealPosition_Parms*)Obj)->bShowRealPosition = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::NewProp_bShowRealPosition = { "bShowRealPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventSetIsShowRealPosition_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::NewProp_bShowRealPosition_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::NewProp_bShowRealPosition,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\biref \xe8\xae\xbe\xe7\xbd\xae\xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe7\x9c\x9f\xe5\xae\x9e\xe5\x9c\xb0\xe7\x90\x86\xe4\xbd\x8d\xe7\xbd\xae\n//! \\param bShowRealPosition [in] true\xe6\x98\xbe\xe7\xa4\xba\xe7\x9c\x9f\xe5\xae\x9e\xe5\x9d\x90\xe6\xa0\x87\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\biref \xe8\xae\xbe\xe7\xbd\xae\xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe7\x9c\x9f\xe5\xae\x9e\xe5\x9c\xb0\xe7\x90\x86\xe4\xbd\x8d\xe7\xbd\xae\n! \\param bShowRealPosition [in] true\xe6\x98\xbe\xe7\xa4\xba\xe7\x9c\x9f\xe5\xae\x9e\xe5\x9d\x90\xe6\xa0\x87" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetIsShowRealPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::SuperMap_MainActor_eventSetIsShowRealPosition_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics
	{
		struct SuperMap_MainActor_eventSetLayerMaterial_Parms
		{
			FName strName;
			FString strPath;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_strPath;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetLayerMaterial_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::NewProp_strPath = { "strPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetLayerMaterial_Parms, strPath), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventSetLayerMaterial_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventSetLayerMaterial_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::NewProp_strPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe5\xa4\x96\xe6\x8c\x82\xe8\xb5\x84\xe6\x9d\x90\xe8\xae\xbe\xe7\xbd\xae\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe5\xa4\x96\xe6\x8c\x82\xe8\xb5\x84\xe6\x9d\x90\xe8\xae\xbe\xe7\xbd\xae" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetLayerMaterial", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::SuperMap_MainActor_eventSetLayerMaterial_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics
	{
		struct SuperMap_MainActor_eventSetLayerObjectMaterial_Parms
		{
			FName strName;
			TMap<FString,FString> m_mapMaterialNameChanges;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_mapMaterialNameChanges_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_mapMaterialNameChanges_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_m_mapMaterialNameChanges;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetLayerObjectMaterial_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_m_mapMaterialNameChanges_ValueProp = { "m_mapMaterialNameChanges", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_m_mapMaterialNameChanges_Key_KeyProp = { "m_mapMaterialNameChanges_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_m_mapMaterialNameChanges = { "m_mapMaterialNameChanges", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetLayerObjectMaterial_Parms, m_mapMaterialNameChanges), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MainActor_eventSetLayerObjectMaterial_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MainActor_eventSetLayerObjectMaterial_Parms), &Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_m_mapMaterialNameChanges_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_m_mapMaterialNameChanges_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_m_mapMaterialNameChanges,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xa4\x96\xe6\x8c\x82\xe8\xb5\x84\xe6\x9d\x90\xe8\xae\xbe\xe7\xbd\xae\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xa4\x96\xe6\x8c\x82\xe8\xb5\x84\xe6\x9d\x90\xe8\xae\xbe\xe7\xbd\xae" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetLayerObjectMaterial", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::SuperMap_MainActor_eventSetLayerObjectMaterial_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetMaterialParams_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetMaterialParams_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xaf\xbc\xe5\x87\xba\xe6\x9b\xbf\xe6\x8d\xa2\xe6\x9d\x90\xe8\xb4\xa8\xe4\xbf\xa1\xe6\x81\xaf\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xaf\xbc\xe5\x87\xba\xe6\x9b\xbf\xe6\x8d\xa2\xe6\x9d\x90\xe8\xb4\xa8\xe4\xbf\xa1\xe6\x81\xaf" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetMaterialParams_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetMaterialParams", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetMaterialParams_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetMaterialParams_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetMaterialParams()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetMaterialParams_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics
	{
		struct SuperMap_MainActor_eventSetObjectMaterialInfo_Parms
		{
			FString LayerName;
			FString Key;
			FString materialName;
			FString materialPath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_LayerName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UECodeGen_Private::FStrPropertyParams NewProp_materialName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_materialPath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::NewProp_LayerName = { "LayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetObjectMaterialInfo_Parms, LayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetObjectMaterialInfo_Parms, Key), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::NewProp_materialName = { "materialName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetObjectMaterialInfo_Parms, materialName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::NewProp_materialPath = { "materialPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetObjectMaterialInfo_Parms, materialPath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::NewProp_LayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::NewProp_materialName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::NewProp_materialPath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xbe\x8e\xe5\x8c\x96\xe6\x9d\x90\xe8\xb4\xa8\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xbe\x8e\xe5\x8c\x96\xe6\x9d\x90\xe8\xb4\xa8" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetObjectMaterialInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::SuperMap_MainActor_eventSetObjectMaterialInfo_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParams_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParams_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xaf\xbc\xe5\x87\xba\xe5\x9c\xba\xe6\x99\xaf\xe4\xbf\xa1\xe6\x81\xaf\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xaf\xbc\xe5\x87\xba\xe5\x9c\xba\xe6\x99\xaf\xe4\xbf\xa1\xe6\x81\xaf" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParams_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetSceneParams", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParams_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParams_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParams()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParams_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParamsFromJson_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParamsFromJson_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe4\xbb\x8eJson\xe6\x96\x87\xe4\xbb\xb6\xe4\xb8\xad\xe8\xaf\xbb\xe5\x8f\x96\xe5\x9c\xba\xe6\x99\xaf\xe4\xbf\xa1\xe6\x81\xaf\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe4\xbb\x8eJson\xe6\x96\x87\xe4\xbb\xb6\xe4\xb8\xad\xe8\xaf\xbb\xe5\x8f\x96\xe5\x9c\xba\xe6\x99\xaf\xe4\xbf\xa1\xe6\x81\xaf" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParamsFromJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetSceneParamsFromJson", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParamsFromJson_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParamsFromJson_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParamsFromJson()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParamsFromJson_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics
	{
		struct SuperMap_MainActor_eventSetSceneType_Parms
		{
			int32 nSceneType;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_nSceneType_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_nSceneType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::NewProp_nSceneType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::NewProp_nSceneType = { "nSceneType", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetSceneType_Parms, nSceneType), METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::NewProp_nSceneType_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::NewProp_nSceneType_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::NewProp_nSceneType,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe5\x88\x9b\xe5\xbb\xba\xe7\x9a\x84\xe5\x9c\xba\xe6\x99\xaf\xe7\xb1\xbb\xe5\x9e\x8b\n//! \\param nSceneType [in] \xe5\x9c\xba\xe6\x99\xaf\xe7\xb1\xbb\xe5\x9e\x8b\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe9\x80\x89\xe6\x8b\xa9\xe5\x88\x9b\xe5\xbb\xba\xe7\x9a\x84\xe5\x9c\xba\xe6\x99\xaf\xe7\xb1\xbb\xe5\x9e\x8b\n! \\param nSceneType [in] \xe5\x9c\xba\xe6\x99\xaf\xe7\xb1\xbb\xe5\x9e\x8b" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetSceneType", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::SuperMap_MainActor_eventSetSceneType_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics
	{
		struct SuperMap_MainActor_eventSetStereoMode_Parms
		{
			int32 type;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_type;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetStereoMode_Parms, type), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::NewProp_type,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_Dataset" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xba\xe6\x99\xaf\xe6\xa8\xa1\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xba\xe6\x99\xaf\xe6\xa8\xa1\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetStereoMode", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::SuperMap_MainActor_eventSetStereoMode_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics
	{
		struct SuperMap_MainActor_eventSetUserAction_Parms
		{
			int32 mode;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_mode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::NewProp_mode = { "mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventSetUserAction_Parms, mode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::NewProp_mode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\x8e\xa9\xe5\xae\xb6\xe6\x93\x8d\xe4\xbd\x9c\xe6\x96\xb9\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\x8e\xa9\xe5\xae\xb6\xe6\x93\x8d\xe4\xbd\x9c\xe6\x96\xb9\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "SetUserAction", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::SuperMap_MainActor_eventSetUserAction_Parms), Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics
	{
		struct SuperMap_MainActor_eventToXML_Parms
		{
			FString strPath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strPath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::NewProp_strPath = { "strPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MainActor_eventToXML_Parms, strPath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::NewProp_strPath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe8\xbd\xacxml\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe8\xbd\xacxml" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MainActor, nullptr, "ToXML", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::SuperMap_MainActor_eventToXML_Parms), Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MainActor_ToXML()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MainActor_ToXML_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_MainActor);
	UClass* Z_Construct_UClass_ASuperMap_MainActor_NoRegister()
	{
		return ASuperMap_MainActor::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_MainActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallFOpenMultiFile_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallFOpenMultiFile;
		static const UECodeGen_Private::FStructPropertyParams NewProp_m_arrLayers_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_arrLayers_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_m_arrLayers;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strPosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_nSceneType_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_m_nSceneType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_vPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_m_vPosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_vGeoreferenceOrigin_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_m_vGeoreferenceOrigin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bShowRealPosition_MetaData[];
#endif
		static void NewProp_m_bShowRealPosition_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bShowRealPosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bIncludeS3M_MetaData[];
#endif
		static void NewProp_m_bIncludeS3M_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bIncludeS3M;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bIncludeTerrain_MetaData[];
#endif
		static void NewProp_m_bIncludeTerrain_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bIncludeTerrain;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strLayerAddress_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strLayerAddress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bIsShowGlobe_MetaData[];
#endif
		static void NewProp_m_bIsShowGlobe_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bIsShowGlobe;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bShowMousePosition_MetaData[];
#endif
		static void NewProp_m_bShowMousePosition_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bShowMousePosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bGetMousePosition_MetaData[];
#endif
		static void NewProp_m_bGetMousePosition_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bGetMousePosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bDeleteDefaultGlobalImage_MetaData[];
#endif
		static void NewProp_m_bDeleteDefaultGlobalImage_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bDeleteDefaultGlobalImage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bComputeNormal_MetaData[];
#endif
		static void NewProp_m_bComputeNormal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bComputeNormal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bEnableCollision_MetaData[];
#endif
		static void NewProp_m_bEnableCollision_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bEnableCollision;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_nUpdateCount_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_m_nUpdateCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bIsMultifile_MetaData[];
#endif
		static void NewProp_m_bIsMultifile_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bIsMultifile;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strLanguage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strLanguage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bEditorSaveGeoreference_MetaData[];
#endif
		static void NewProp_m_bEditorSaveGeoreference_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bEditorSaveGeoreference;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_MainActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACameraActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_MainActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_MainActor_AddAssetResoure, "AddAssetResoure" }, // 736423106
		{ &Z_Construct_UFunction_ASuperMap_MainActor_AddLocalLayers, "AddLocalLayers" }, // 2928554120
		{ &Z_Construct_UFunction_ASuperMap_MainActor_AddUrlLayers, "AddUrlLayers" }, // 2718216464
		{ &Z_Construct_UFunction_ASuperMap_MainActor_AddWMTSMap, "AddWMTSMap" }, // 2273207507
		{ &Z_Construct_UFunction_ASuperMap_MainActor_ClearAssetResoure, "ClearAssetResoure" }, // 2364188397
		{ &Z_Construct_UFunction_ASuperMap_MainActor_DatasetMaterialToJson, "DatasetMaterialToJson" }, // 328416413
		{ &Z_Construct_UFunction_ASuperMap_MainActor_DeleteObjectMaterialInfo, "DeleteObjectMaterialInfo" }, // 516905583
		{ &Z_Construct_UFunction_ASuperMap_MainActor_ExportMaterialFromS3MLayer, "ExportMaterialFromS3MLayer" }, // 613828653
		{ &Z_Construct_UFunction_ASuperMap_MainActor_FromXML, "FromXML" }, // 3487549136
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetCameraFov, "GetCameraFov" }, // 324632433
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetList, "GetDatasetList" }, // 134796653
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetDatasetName, "GetDatasetName" }, // 2073983404
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetDataSetType, "GetDataSetType" }, // 3705721703
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetDatasourcePath, "GetDatasourcePath" }, // 2197694447
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetFieldInfos, "GetFieldInfos" }, // 2957816455
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetGeoreferenceOrigin, "GetGeoreferenceOrigin" }, // 2019232721
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetHypsometricSettingLayers, "GetHypsometricSettingLayers" }, // 844941723
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetLayerType, "GetLayerType" }, // 3557213065
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetLocalPosition, "GetLocalPosition" }, // 26433064
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetRealPosition, "GetRealPosition" }, // 2992403027
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetRestoreLayers, "GetRestoreLayers" }, // 1909649864
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetS3MLayers, "GetS3MLayers" }, // 3486198167
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetSelectMaterialInfo, "GetSelectMaterialInfo" }, // 3255416260
		{ &Z_Construct_UFunction_ASuperMap_MainActor_GetTerrainLayersCount, "GetTerrainLayersCount" }, // 3643094934
		{ &Z_Construct_UFunction_ASuperMap_MainActor_IsSecondTerrainLayer, "IsSecondTerrainLayer" }, // 3488201868
		{ &Z_Construct_UFunction_ASuperMap_MainActor_ModificationLayerName, "ModificationLayerName" }, // 3213916070
		{ &Z_Construct_UFunction_ASuperMap_MainActor_OpenFileDialog, "OpenFileDialog" }, // 1096884568
		{ &Z_Construct_UFunction_ASuperMap_MainActor_OpenFileFolderDialog, "OpenFileFolderDialog" }, // 368927111
		{ &Z_Construct_UFunction_ASuperMap_MainActor_PlayingActor, "PlayingActor" }, // 3901081315
		{ &Z_Construct_UFunction_ASuperMap_MainActor_QueryField, "QueryField" }, // 4196913556
		{ &Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer, "RemoveLayer" }, // 1287574548
		{ &Z_Construct_UFunction_ASuperMap_MainActor_RemoveLayer_Web, "RemoveLayer_Web" }, // 2045853204
		{ &Z_Construct_UFunction_ASuperMap_MainActor_RemoveTerrainLayer, "RemoveTerrainLayer" }, // 1302981419
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetCameraFov, "SetCameraFov" }, // 7773044
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetEditorAction, "SetEditorAction" }, // 4003157316
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetEditorState, "SetEditorState" }, // 535379525
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetEnableCollision, "SetEnableCollision" }, // 4231555502
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetEnableComputeNormal, "SetEnableComputeNormal" }, // 3046864728
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetFieldAssetResoure, "SetFieldAssetResoure" }, // 2568196106
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetGeoreferenceOrigin, "SetGeoreferenceOrigin" }, // 2174376025
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetImportAsset, "SetImportAsset" }, // 1579941367
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetIsShowRealPosition, "SetIsShowRealPosition" }, // 470139278
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetLayerMaterial, "SetLayerMaterial" }, // 1479267720
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetLayerObjectMaterial, "SetLayerObjectMaterial" }, // 3968702826
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetMaterialParams, "SetMaterialParams" }, // 1831098333
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetObjectMaterialInfo, "SetObjectMaterialInfo" }, // 2243146865
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParams, "SetSceneParams" }, // 4024644172
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetSceneParamsFromJson, "SetSceneParamsFromJson" }, // 1696145293
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetSceneType, "SetSceneType" }, // 901112627
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetStereoMode, "SetStereoMode" }, // 2985936780
		{ &Z_Construct_UFunction_ASuperMap_MainActor_SetUserAction, "SetUserAction" }, // 715807638
		{ &Z_Construct_UFunction_ASuperMap_MainActor_ToXML, "ToXML" }, // 1994249973
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Input Rendering" },
		{ "IncludePath", "SuperMap_MainActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallEvent = { "CallEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, CallEvent), Z_Construct_UDelegateFunction_SuperMapSamples_MainActorDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallEvent_MetaData)) }; // 2329089089
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallFOpenMultiFile_MetaData[] = {
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallFOpenMultiFile = { "CallFOpenMultiFile", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, CallFOpenMultiFile), Z_Construct_UDelegateFunction_SuperMapSamples_OpenMultiFileDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallFOpenMultiFile_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallFOpenMultiFile_MetaData)) }; // 638922186
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_arrLayers_Inner = { "m_arrLayers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSuperMap_LayerInfo, METADATA_PARAMS(nullptr, 0) }; // 2973872049
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_arrLayers_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\breif \xe6\xb7\xbb\xe5\x8a\xa0\xe7\x9a\x84\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\breif \xe6\xb7\xbb\xe5\x8a\xa0\xe7\x9a\x84\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_arrLayers = { "m_arrLayers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, m_arrLayers), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_arrLayers_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_arrLayers_MetaData)) }; // 2973872049
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strPosition_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\breif \xe5\x9d\x90\xe6\xa0\x87\xe4\xbf\xa1\xe6\x81\xaf\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\breif \xe5\x9d\x90\xe6\xa0\x87\xe4\xbf\xa1\xe6\x81\xaf" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strPosition = { "m_strPosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, m_strPosition), METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strPosition_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nSceneType_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\breif \xe5\x9c\xba\xe6\x99\xaf\xe7\xb1\xbb\xe5\x9e\x8b\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\breif \xe5\x9c\xba\xe6\x99\xaf\xe7\xb1\xbb\xe5\x9e\x8b" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nSceneType = { "m_nSceneType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, m_nSceneType), METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nSceneType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nSceneType_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vPosition_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x8f\x92\xe5\x85\xa5\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x8f\x92\xe5\x85\xa5\xe7\x82\xb9" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vPosition = { "m_vPosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, m_vPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vPosition_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vGeoreferenceOrigin_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe5\x9c\xb0\xe7\x90\x86\xe5\x8e\x9f\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe5\x9c\xb0\xe7\x90\x86\xe5\x8e\x9f\xe7\x82\xb9" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vGeoreferenceOrigin = { "m_vGeoreferenceOrigin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, m_vGeoreferenceOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vGeoreferenceOrigin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vGeoreferenceOrigin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowRealPosition_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//\xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe7\x9c\x9f\xe5\xae\x9e\xe5\x9d\x90\xe6\xa0\x87\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "\xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe7\x9c\x9f\xe5\xae\x9e\xe5\x9d\x90\xe6\xa0\x87" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowRealPosition_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bShowRealPosition = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowRealPosition = { "m_bShowRealPosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowRealPosition_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowRealPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowRealPosition_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeS3M_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\xad\x98\xe5\x9c\xa8S3M\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\xad\x98\xe5\x9c\xa8S3M\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeS3M_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bIncludeS3M = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeS3M = { "m_bIncludeS3M", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeS3M_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeS3M_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeS3M_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeTerrain_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\xad\x98\xe5\x9c\xa8\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\xad\x98\xe5\x9c\xa8\xe5\x9c\xb0\xe5\xbd\xa2\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeTerrain_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bIncludeTerrain = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeTerrain = { "m_bIncludeTerrain", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeTerrain_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeTerrain_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeTerrain_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLayerAddress_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x9c\xac\xe5\x9c\xb0\xe9\x80\x89\xe6\x8b\xa9\xe5\x9b\xbe\xe5\xb1\x82\xe5\x9c\xb0\xe5\x9d\x80\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x9c\xac\xe5\x9c\xb0\xe9\x80\x89\xe6\x8b\xa9\xe5\x9b\xbe\xe5\xb1\x82\xe5\x9c\xb0\xe5\x9d\x80" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLayerAddress = { "m_strLayerAddress", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, m_strLayerAddress), METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLayerAddress_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLayerAddress_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsShowGlobe_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe6\x97\xa0\xe6\x95\x88\xe5\x8c\xba\xe5\x9f\x9f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe6\x97\xa0\xe6\x95\x88\xe5\x8c\xba\xe5\x9f\x9f" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsShowGlobe_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bIsShowGlobe = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsShowGlobe = { "m_bIsShowGlobe", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsShowGlobe_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsShowGlobe_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsShowGlobe_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowMousePosition_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\xbd\x93\xe5\x89\x8d\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\xbd\x93\xe5\x89\x8d\xe7\x82\xb9" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowMousePosition_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bShowMousePosition = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowMousePosition = { "m_bShowMousePosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowMousePosition_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowMousePosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowMousePosition_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bGetMousePosition_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8d\xe7\x82\xb9" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bGetMousePosition_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bGetMousePosition = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bGetMousePosition = { "m_bGetMousePosition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bGetMousePosition_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bGetMousePosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bGetMousePosition_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bDeleteDefaultGlobalImage_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\x88\xa0\xe9\x99\xa4\xe9\xbb\x98\xe8\xae\xa4\xe7\x90\x83\xe7\x9a\xae\xe5\xbd\xb1\xe5\x83\x8f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\x88\xa0\xe9\x99\xa4\xe9\xbb\x98\xe8\xae\xa4\xe7\x90\x83\xe7\x9a\xae\xe5\xbd\xb1\xe5\x83\x8f" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bDeleteDefaultGlobalImage_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bDeleteDefaultGlobalImage = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bDeleteDefaultGlobalImage = { "m_bDeleteDefaultGlobalImage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bDeleteDefaultGlobalImage_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bDeleteDefaultGlobalImage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bDeleteDefaultGlobalImage_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bComputeNormal_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\x90\xaf\xe7\x94\xa8\xe6\xb3\x95\xe7\xba\xbf\xe8\xae\xa1\xe7\xae\x97\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\x90\xaf\xe7\x94\xa8\xe6\xb3\x95\xe7\xba\xbf\xe8\xae\xa1\xe7\xae\x97" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bComputeNormal_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bComputeNormal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bComputeNormal = { "m_bComputeNormal", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bComputeNormal_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bComputeNormal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bComputeNormal_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEnableCollision_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\x90\xaf\xe7\x94\xa8\xe7\xa2\xb0\xe6\x92\x9e\xe6\xa3\x80\xe6\xb5\x8b\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe5\x90\xaf\xe7\x94\xa8\xe7\xa2\xb0\xe6\x92\x9e\xe6\xa3\x80\xe6\xb5\x8b" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEnableCollision_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bEnableCollision = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEnableCollision = { "m_bEnableCollision", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEnableCollision_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEnableCollision_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEnableCollision_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nUpdateCount_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\xaf\x8f\xe6\xac\xa1\xe6\x9b\xb4\xe6\x96\xb0RO\xe4\xb8\xaa\xe6\x95\xb0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\xaf\x8f\xe6\xac\xa1\xe6\x9b\xb4\xe6\x96\xb0RO\xe4\xb8\xaa\xe6\x95\xb0" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nUpdateCount = { "m_nUpdateCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, m_nUpdateCount), METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nUpdateCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nUpdateCount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsMultifile_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x89\xb9\xe9\x87\x8f\xe5\x8a\xa0\xe8\xbd\xbd\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x89\xb9\xe9\x87\x8f\xe5\x8a\xa0\xe8\xbd\xbd\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsMultifile_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bIsMultifile = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsMultifile = { "m_bIsMultifile", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsMultifile_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsMultifile_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsMultifile_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLanguage_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe4\xbd\xbf\xe7\x94\xa8\xe8\xaf\xad\xe8\xa8\x80\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe4\xbd\xbf\xe7\x94\xa8\xe8\xaf\xad\xe8\xa8\x80" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLanguage = { "m_strLanguage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MainActor, m_strLanguage), METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLanguage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLanguage_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEditorSaveGeoreference_MetaData[] = {
		{ "Category", "SuperMap_MainActor" },
		{ "Comment", "//! \\brief \xe7\xbc\x96\xe8\xbe\x91\xe6\xa8\xa1\xe5\xbc\x8f\xe4\xb8\x8b\xe7\x9a\x84\xe5\x9c\xb0\xe7\x90\x86\xe8\xbf\x9c\xe7\x82\xb9\xe4\xbf\x9d\xe5\xad\x98\n" },
		{ "ModuleRelativePath", "Public/SuperMap_MainActor.h" },
		{ "ToolTip", "! \\brief \xe7\xbc\x96\xe8\xbe\x91\xe6\xa8\xa1\xe5\xbc\x8f\xe4\xb8\x8b\xe7\x9a\x84\xe5\x9c\xb0\xe7\x90\x86\xe8\xbf\x9c\xe7\x82\xb9\xe4\xbf\x9d\xe5\xad\x98" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEditorSaveGeoreference_SetBit(void* Obj)
	{
		((ASuperMap_MainActor*)Obj)->m_bEditorSaveGeoreference = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEditorSaveGeoreference = { "m_bEditorSaveGeoreference", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_MainActor), &Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEditorSaveGeoreference_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEditorSaveGeoreference_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEditorSaveGeoreference_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_MainActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_CallFOpenMultiFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_arrLayers_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_arrLayers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nSceneType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_vGeoreferenceOrigin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowRealPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeS3M,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIncludeTerrain,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLayerAddress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsShowGlobe,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bShowMousePosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bGetMousePosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bDeleteDefaultGlobalImage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bComputeNormal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEnableCollision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_nUpdateCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bIsMultifile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_strLanguage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MainActor_Statics::NewProp_m_bEditorSaveGeoreference,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_MainActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_MainActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_MainActor_Statics::ClassParams = {
		&ASuperMap_MainActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_MainActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MainActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MainActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_MainActor()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_MainActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_MainActor.OuterSingleton, Z_Construct_UClass_ASuperMap_MainActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_MainActor.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_MainActor>()
	{
		return ASuperMap_MainActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_MainActor);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_Statics::ScriptStructInfo[] = {
		{ FSuperMapTable::StaticStruct, Z_Construct_UScriptStruct_FSuperMapTable_Statics::NewStructOps, TEXT("SuperMapTable"), &Z_Registration_Info_UScriptStruct_SuperMapTable, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSuperMapTable), 633637241U) },
		{ FSuperMap_LayerInfo::StaticStruct, Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics::NewStructOps, TEXT("SuperMap_LayerInfo"), &Z_Registration_Info_UScriptStruct_SuperMap_LayerInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSuperMap_LayerInfo), 2973872049U) },
		{ FRealPosition::StaticStruct, Z_Construct_UScriptStruct_FRealPosition_Statics::NewStructOps, TEXT("RealPosition"), &Z_Registration_Info_UScriptStruct_RealPosition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRealPosition), 1343390513U) },
		{ FMaterialInfo::StaticStruct, Z_Construct_UScriptStruct_FMaterialInfo_Statics::NewStructOps, TEXT("MaterialInfo"), &Z_Registration_Info_UScriptStruct_MaterialInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMaterialInfo), 1562136874U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_MainActor, ASuperMap_MainActor::StaticClass, TEXT("ASuperMap_MainActor"), &Z_Registration_Info_UClass_ASuperMap_MainActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_MainActor), 2578304928U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_3025796301(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
