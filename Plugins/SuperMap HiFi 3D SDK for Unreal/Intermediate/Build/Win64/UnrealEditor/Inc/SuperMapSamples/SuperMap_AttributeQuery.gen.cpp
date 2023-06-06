// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SuperMap_AttributeQuery.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_AttributeQuery() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_AttributeQueryDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FAttributeInfos();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_AttributeQuery_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_AttributeQuery();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_AttributeQueryDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_AttributeQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_AttributeQueryDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "AttributeQueryDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_AttributeQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_AttributeQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_AttributeQueryDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_AttributeQueryDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AttributeInfos;
class UScriptStruct* FAttributeInfos::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AttributeInfos.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AttributeInfos.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAttributeInfos, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("AttributeInfos"));
	}
	return Z_Registration_Info_UScriptStruct_AttributeInfos.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FAttributeInfos>()
{
	return FAttributeInfos::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAttributeInfos_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strFileInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strFileInfo;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strFileValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strFileValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAttributeInfos_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAttributeInfos>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileInfo_MetaData[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "Comment", "//! \\brief \xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x97\xe6\xae\xb5\n" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
		{ "ToolTip", "! \\brief \xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x97\xe6\xae\xb5" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileInfo = { "m_strFileInfo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAttributeInfos, m_strFileInfo), METADATA_PARAMS(Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileInfo_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileValue_MetaData[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "Comment", "//! \\brief \xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
		{ "ToolTip", "! \\brief \xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileValue = { "m_strFileValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAttributeInfos, m_strFileValue), METADATA_PARAMS(Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAttributeInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewProp_m_strFileValue,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAttributeInfos_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"AttributeInfos",
		sizeof(FAttributeInfos),
		alignof(FAttributeInfos),
		Z_Construct_UScriptStruct_FAttributeInfos_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttributeInfos_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAttributeInfos_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttributeInfos_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAttributeInfos()
	{
		if (!Z_Registration_Info_UScriptStruct_AttributeInfos.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AttributeInfos.InnerSingleton, Z_Construct_UScriptStruct_FAttributeInfos_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AttributeInfos.InnerSingleton;
	}
	DEFINE_FUNCTION(ASuperMap_AttributeQuery::execSetUseWeb)
	{
		P_GET_UBOOL(Z_Param_bUse);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUseWeb(Z_Param_bUse);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_AttributeQuery::execGetSelectionInfosByID)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_GET_PROPERTY(FIntProperty,Z_Param_nID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FAttributeInfos>*)Z_Param__Result=P_THIS->GetSelectionInfosByID(Z_Param_strLayerName,Z_Param_nID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_AttributeQuery::execGetSelectionID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSelectionID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_AttributeQuery::execIsGetDatasetModelSelectionInfos)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsGetDatasetModelSelectionInfos();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_AttributeQuery::execGetDatasetModelSelectionInfos)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FAttributeInfos>*)Z_Param__Result=P_THIS->GetDatasetModelSelectionInfos();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_AttributeQuery::execGetSelectionInfos)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FAttributeInfos>*)Z_Param__Result=P_THIS->GetSelectionInfos();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_AttributeQuery::execIsGetSelectionInfos)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsGetSelectionInfos();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_AttributeQuery::execIsSelectionInfos)
	{
		P_GET_UBOOL(Z_Param_selectionInfos);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->IsSelectionInfos(Z_Param_selectionInfos);
		P_NATIVE_END;
	}
	void ASuperMap_AttributeQuery::StaticRegisterNativesASuperMap_AttributeQuery()
	{
		UClass* Class = ASuperMap_AttributeQuery::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDatasetModelSelectionInfos", &ASuperMap_AttributeQuery::execGetDatasetModelSelectionInfos },
			{ "GetSelectionID", &ASuperMap_AttributeQuery::execGetSelectionID },
			{ "GetSelectionInfos", &ASuperMap_AttributeQuery::execGetSelectionInfos },
			{ "GetSelectionInfosByID", &ASuperMap_AttributeQuery::execGetSelectionInfosByID },
			{ "IsGetDatasetModelSelectionInfos", &ASuperMap_AttributeQuery::execIsGetDatasetModelSelectionInfos },
			{ "IsGetSelectionInfos", &ASuperMap_AttributeQuery::execIsGetSelectionInfos },
			{ "IsSelectionInfos", &ASuperMap_AttributeQuery::execIsSelectionInfos },
			{ "SetUseWeb", &ASuperMap_AttributeQuery::execSetUseWeb },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics
	{
		struct SuperMap_AttributeQuery_eventGetDatasetModelSelectionInfos_Parms
		{
			TArray<FAttributeInfos> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FAttributeInfos, METADATA_PARAMS(nullptr, 0) }; // 2228797425
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_AttributeQuery_eventGetDatasetModelSelectionInfos_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 2228797425
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\xa8\xa1\xe5\x9e\x8b\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\xb1\x9e\xe6\x80\xa7\xe6\x9f\xa5\xe8\xaf\xa2\xe4\xbf\xa1\xe6\x81\xaf\n//! \\return \xe8\xbf\x94\xe5\x9b\x9e\xe5\xb1\x9e\xe6\x80\xa7\xe8\xa1\xa8\n" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\xa8\xa1\xe5\x9e\x8b\xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\xb1\x9e\xe6\x80\xa7\xe6\x9f\xa5\xe8\xaf\xa2\xe4\xbf\xa1\xe6\x81\xaf\n! \\return \xe8\xbf\x94\xe5\x9b\x9e\xe5\xb1\x9e\xe6\x80\xa7\xe8\xa1\xa8" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_AttributeQuery, nullptr, "GetDatasetModelSelectionInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::SuperMap_AttributeQuery_eventGetDatasetModelSelectionInfos_Parms), Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics
	{
		struct SuperMap_AttributeQuery_eventGetSelectionID_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_AttributeQuery_eventGetSelectionID_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "Comment", "//! \\brief \xe8\xbf\x94\xe5\x9b\x9e\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7id\n" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
		{ "ToolTip", "! \\brief \xe8\xbf\x94\xe5\x9b\x9e\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7id" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_AttributeQuery, nullptr, "GetSelectionID", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::SuperMap_AttributeQuery_eventGetSelectionID_Parms), Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics
	{
		struct SuperMap_AttributeQuery_eventGetSelectionInfos_Parms
		{
			TArray<FAttributeInfos> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FAttributeInfos, METADATA_PARAMS(nullptr, 0) }; // 2228797425
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_AttributeQuery_eventGetSelectionInfos_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 2228797425
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\xb1\x9e\xe6\x80\xa7\xe6\x9f\xa5\xe8\xaf\xa2\xe4\xbf\xa1\xe6\x81\xaf\n//! \\return \xe8\xbf\x94\xe5\x9b\x9e\xe5\xb1\x9e\xe6\x80\xa7\xe8\xa1\xa8\n" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\xb1\x9e\xe6\x80\xa7\xe6\x9f\xa5\xe8\xaf\xa2\xe4\xbf\xa1\xe6\x81\xaf\n! \\return \xe8\xbf\x94\xe5\x9b\x9e\xe5\xb1\x9e\xe6\x80\xa7\xe8\xa1\xa8" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_AttributeQuery, nullptr, "GetSelectionInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::SuperMap_AttributeQuery_eventGetSelectionInfos_Parms), Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics
	{
		struct SuperMap_AttributeQuery_eventGetSelectionInfosByID_Parms
		{
			FName strLayerName;
			int32 nID;
			TArray<FAttributeInfos> ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nID;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_AttributeQuery_eventGetSelectionInfosByID_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::NewProp_nID = { "nID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_AttributeQuery_eventGetSelectionInfosByID_Parms, nID), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FAttributeInfos, METADATA_PARAMS(nullptr, 0) }; // 2228797425
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_AttributeQuery_eventGetSelectionInfosByID_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 2228797425
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::NewProp_strLayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::NewProp_nID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "Comment", "//\xe4\xba\x91\xe6\xb8\xb2\xe6\x9f\x93\xe6\x8e\xa5\xe5\x8f\xa3\n//! \\brief \xe9\x80\x9a\xe8\xbf\x87ID\xe8\x8e\xb7\xe5\x8f\x96\xe5\xb1\x9e\xe6\x80\xa7\n" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
		{ "ToolTip", "\xe4\xba\x91\xe6\xb8\xb2\xe6\x9f\x93\xe6\x8e\xa5\xe5\x8f\xa3\n! \\brief \xe9\x80\x9a\xe8\xbf\x87ID\xe8\x8e\xb7\xe5\x8f\x96\xe5\xb1\x9e\xe6\x80\xa7" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_AttributeQuery, nullptr, "GetSelectionInfosByID", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::SuperMap_AttributeQuery_eventGetSelectionInfosByID_Parms), Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics
	{
		struct SuperMap_AttributeQuery_eventIsGetDatasetModelSelectionInfos_Parms
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
	void Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_AttributeQuery_eventIsGetDatasetModelSelectionInfos_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_AttributeQuery_eventIsGetDatasetModelSelectionInfos_Parms), &Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7id\xe6\x98\xaf\xe5\x90\xa6\xe7\x9b\xb8\xe5\x90\x8c\n//! \\return true \xe4\xb8\x8e\xe4\xb8\x8a\xe6\xac\xa1\xe6\x9f\xa5\xe8\xaf\xa2\xe6\xa8\xa1\xe5\x9e\x8b\xe4\xb8\x8d\xe7\x9b\xb8\xe5\x90\x8c\xe5\x88\xb7\xe6\x96\xb0\xe6\x95\xb0\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7id\xe6\x98\xaf\xe5\x90\xa6\xe7\x9b\xb8\xe5\x90\x8c\n! \\return true \xe4\xb8\x8e\xe4\xb8\x8a\xe6\xac\xa1\xe6\x9f\xa5\xe8\xaf\xa2\xe6\xa8\xa1\xe5\x9e\x8b\xe4\xb8\x8d\xe7\x9b\xb8\xe5\x90\x8c\xe5\x88\xb7\xe6\x96\xb0\xe6\x95\xb0\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_AttributeQuery, nullptr, "IsGetDatasetModelSelectionInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::SuperMap_AttributeQuery_eventIsGetDatasetModelSelectionInfos_Parms), Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics
	{
		struct SuperMap_AttributeQuery_eventIsGetSelectionInfos_Parms
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
	void Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_AttributeQuery_eventIsGetSelectionInfos_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_AttributeQuery_eventIsGetSelectionInfos_Parms), &Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7id\xe6\x98\xaf\xe5\x90\xa6\xe7\x9b\xb8\xe5\x90\x8c\n//! \\return true \xe4\xb8\x8e\xe4\xb8\x8a\xe6\xac\xa1\xe6\x9f\xa5\xe8\xaf\xa2\xe6\xa8\xa1\xe5\x9e\x8b\xe7\x9b\xb8\xe5\x90\x8c\xe4\xb8\x8d\xe5\x88\xb7\xe6\x96\xb0\xe6\x95\xb0\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7id\xe6\x98\xaf\xe5\x90\xa6\xe7\x9b\xb8\xe5\x90\x8c\n! \\return true \xe4\xb8\x8e\xe4\xb8\x8a\xe6\xac\xa1\xe6\x9f\xa5\xe8\xaf\xa2\xe6\xa8\xa1\xe5\x9e\x8b\xe7\x9b\xb8\xe5\x90\x8c\xe4\xb8\x8d\xe5\x88\xb7\xe6\x96\xb0\xe6\x95\xb0\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_AttributeQuery, nullptr, "IsGetSelectionInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::SuperMap_AttributeQuery_eventIsGetSelectionInfos_Parms), Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics
	{
		struct SuperMap_AttributeQuery_eventIsSelectionInfos_Parms
		{
			bool selectionInfos;
		};
		static void NewProp_selectionInfos_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_selectionInfos;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::NewProp_selectionInfos_SetBit(void* Obj)
	{
		((SuperMap_AttributeQuery_eventIsSelectionInfos_Parms*)Obj)->selectionInfos = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::NewProp_selectionInfos = { "selectionInfos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_AttributeQuery_eventIsSelectionInfos_Parms), &Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::NewProp_selectionInfos_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::NewProp_selectionInfos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7\n//! \\param selectionInfos [in] true \xe8\xa1\xa8\xe7\xa4\xba\xe8\xbf\x9b\xe8\xa1\x8c\xe5\xb1\x9e\xe6\x80\xa7\xe6\x9f\xa5\xe8\xaf\xa2\n" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x9f\xa5\xe8\xaf\xa2\xe5\xb1\x9e\xe6\x80\xa7\n! \\param selectionInfos [in] true \xe8\xa1\xa8\xe7\xa4\xba\xe8\xbf\x9b\xe8\xa1\x8c\xe5\xb1\x9e\xe6\x80\xa7\xe6\x9f\xa5\xe8\xaf\xa2" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_AttributeQuery, nullptr, "IsSelectionInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::SuperMap_AttributeQuery_eventIsSelectionInfos_Parms), Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics
	{
		struct SuperMap_AttributeQuery_eventSetUseWeb_Parms
		{
			bool bUse;
		};
		static void NewProp_bUse_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUse;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::NewProp_bUse_SetBit(void* Obj)
	{
		((SuperMap_AttributeQuery_eventSetUseWeb_Parms*)Obj)->bUse = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::NewProp_bUse = { "bUse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_AttributeQuery_eventSetUseWeb_Parms), &Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::NewProp_bUse_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::NewProp_bUse,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_AttributeQuery" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_AttributeQuery, nullptr, "SetUseWeb", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::SuperMap_AttributeQuery_eventSetUseWeb_Parms), Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_AttributeQuery);
	UClass* Z_Construct_UClass_ASuperMap_AttributeQuery_NoRegister()
	{
		return ASuperMap_AttributeQuery::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_AttributeQuery_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallAttributeQuery_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallAttributeQuery;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_AttributeQuery_GetDatasetModelSelectionInfos, "GetDatasetModelSelectionInfos" }, // 2606546880
		{ &Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionID, "GetSelectionID" }, // 1714095477
		{ &Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfos, "GetSelectionInfos" }, // 1786467210
		{ &Z_Construct_UFunction_ASuperMap_AttributeQuery_GetSelectionInfosByID, "GetSelectionInfosByID" }, // 2047038121
		{ &Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetDatasetModelSelectionInfos, "IsGetDatasetModelSelectionInfos" }, // 2206820748
		{ &Z_Construct_UFunction_ASuperMap_AttributeQuery_IsGetSelectionInfos, "IsGetSelectionInfos" }, // 1062061471
		{ &Z_Construct_UFunction_ASuperMap_AttributeQuery_IsSelectionInfos, "IsSelectionInfos" }, // 1425509043
		{ &Z_Construct_UFunction_ASuperMap_AttributeQuery_SetUseWeb, "SetUseWeb" }, // 402786945
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SuperMap_AttributeQuery.h" },
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::NewProp_CallAttributeQuery_MetaData[] = {
		{ "ModuleRelativePath", "Public/SuperMap_AttributeQuery.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::NewProp_CallAttributeQuery = { "CallAttributeQuery", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_AttributeQuery, CallAttributeQuery), Z_Construct_UDelegateFunction_SuperMapSamples_AttributeQueryDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::NewProp_CallAttributeQuery_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::NewProp_CallAttributeQuery_MetaData)) }; // 3554768532
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::NewProp_CallAttributeQuery,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_AttributeQuery>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::ClassParams = {
		&ASuperMap_AttributeQuery::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_AttributeQuery()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_AttributeQuery.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_AttributeQuery.OuterSingleton, Z_Construct_UClass_ASuperMap_AttributeQuery_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_AttributeQuery.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_AttributeQuery>()
	{
		return ASuperMap_AttributeQuery::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_AttributeQuery);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_AttributeQuery_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_AttributeQuery_h_Statics::ScriptStructInfo[] = {
		{ FAttributeInfos::StaticStruct, Z_Construct_UScriptStruct_FAttributeInfos_Statics::NewStructOps, TEXT("AttributeInfos"), &Z_Registration_Info_UScriptStruct_AttributeInfos, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAttributeInfos), 2228797425U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_AttributeQuery_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_AttributeQuery, ASuperMap_AttributeQuery::StaticClass, TEXT("ASuperMap_AttributeQuery"), &Z_Registration_Info_UClass_ASuperMap_AttributeQuery, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_AttributeQuery), 84066347U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_AttributeQuery_h_4116753631(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_AttributeQuery_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_AttributeQuery_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_AttributeQuery_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_AttributeQuery_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
