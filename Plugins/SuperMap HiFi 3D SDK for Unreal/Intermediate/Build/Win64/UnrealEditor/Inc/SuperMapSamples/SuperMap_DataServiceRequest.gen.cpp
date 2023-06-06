// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SceneOperation/SuperMap_DataServiceRequest.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_DataServiceRequest() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_DataServiceRequestDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FDataServiceRequestInfos();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_DataServiceRequest_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_DataServiceRequest();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_DataServiceRequestDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_DataServiceRequestDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_DataServiceRequestDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "DataServiceRequestDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_DataServiceRequestDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_DataServiceRequestDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_DataServiceRequestDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_DataServiceRequestDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_DataServiceRequestInfos;
class UScriptStruct* FDataServiceRequestInfos::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_DataServiceRequestInfos.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_DataServiceRequestInfos.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDataServiceRequestInfos, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("DataServiceRequestInfos"));
	}
	return Z_Registration_Info_UScriptStruct_DataServiceRequestInfos.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FDataServiceRequestInfos>()
{
	return FDataServiceRequestInfos::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDataServiceRequestInfos>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileInfo_MetaData[] = {
		{ "Category", "ASuperMap_DataServiceRequest" },
		{ "Comment", "//! \\brief ??\xd1\xaf?????\xd6\xb6?\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
		{ "ToolTip", "! \\brief ??\xd1\xaf?????\xd6\xb6?" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileInfo = { "m_strFileInfo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDataServiceRequestInfos, m_strFileInfo), METADATA_PARAMS(Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileInfo_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileValue_MetaData[] = {
		{ "Category", "ASuperMap_DataServiceRequest" },
		{ "Comment", "//! \\brief ??\xd1\xaf????\xd6\xb5\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
		{ "ToolTip", "! \\brief ??\xd1\xaf????\xd6\xb5" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileValue = { "m_strFileValue", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FDataServiceRequestInfos, m_strFileValue), METADATA_PARAMS(Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewProp_m_strFileValue,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"DataServiceRequestInfos",
		sizeof(FDataServiceRequestInfos),
		alignof(FDataServiceRequestInfos),
		Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FDataServiceRequestInfos()
	{
		if (!Z_Registration_Info_UScriptStruct_DataServiceRequestInfos.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_DataServiceRequestInfos.InnerSingleton, Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_DataServiceRequestInfos.InnerSingleton;
	}
	DEFINE_FUNCTION(ASuperMap_DataServiceRequest::execGetSelectAttribute)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FDataServiceRequestInfos>*)Z_Param__Result=P_THIS->GetSelectAttribute();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_DataServiceRequest::execSetIServiceData)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strUrlServer);
		P_GET_PROPERTY(FStrProperty,Z_Param_strDataSourceName);
		P_GET_PROPERTY(FStrProperty,Z_Param_strDatasetName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIServiceData(Z_Param_strUrlServer,Z_Param_strDataSourceName,Z_Param_strDatasetName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_DataServiceRequest::execSetExtendHeightFiledName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strExtendHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetExtendHeightFiledName(Z_Param_strExtendHeight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_DataServiceRequest::execSetBottomAltitudeFiledName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strBottomAltitude);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetBottomAltitudeFiledName(Z_Param_strBottomAltitude);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_DataServiceRequest::execBuildDataServiceRequest)
	{
		P_GET_UBOOL(Z_Param_bDataServiceRequest);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildDataServiceRequest(Z_Param_bDataServiceRequest);
		P_NATIVE_END;
	}
	void ASuperMap_DataServiceRequest::StaticRegisterNativesASuperMap_DataServiceRequest()
	{
		UClass* Class = ASuperMap_DataServiceRequest::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildDataServiceRequest", &ASuperMap_DataServiceRequest::execBuildDataServiceRequest },
			{ "GetSelectAttribute", &ASuperMap_DataServiceRequest::execGetSelectAttribute },
			{ "SetBottomAltitudeFiledName", &ASuperMap_DataServiceRequest::execSetBottomAltitudeFiledName },
			{ "SetExtendHeightFiledName", &ASuperMap_DataServiceRequest::execSetExtendHeightFiledName },
			{ "SetIServiceData", &ASuperMap_DataServiceRequest::execSetIServiceData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics
	{
		struct SuperMap_DataServiceRequest_eventBuildDataServiceRequest_Parms
		{
			bool bDataServiceRequest;
		};
		static void NewProp_bDataServiceRequest_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDataServiceRequest;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::NewProp_bDataServiceRequest_SetBit(void* Obj)
	{
		((SuperMap_DataServiceRequest_eventBuildDataServiceRequest_Parms*)Obj)->bDataServiceRequest = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::NewProp_bDataServiceRequest = { "bDataServiceRequest", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_DataServiceRequest_eventBuildDataServiceRequest_Parms), &Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::NewProp_bDataServiceRequest_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::NewProp_bDataServiceRequest,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_DataServiceRequest" },
		{ "Comment", "//! \\brief ??????\xd0\xb1???\xe5\xbb\xaf???\xd4\xb2?\xd1\xaf\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
		{ "ToolTip", "! \\brief ??????\xd0\xb1???\xe5\xbb\xaf???\xd4\xb2?\xd1\xaf" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataServiceRequest, nullptr, "BuildDataServiceRequest", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::SuperMap_DataServiceRequest_eventBuildDataServiceRequest_Parms), Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics
	{
		struct SuperMap_DataServiceRequest_eventGetSelectAttribute_Parms
		{
			TArray<FDataServiceRequestInfos> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FDataServiceRequestInfos, METADATA_PARAMS(nullptr, 0) }; // 3436694846
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataServiceRequest_eventGetSelectAttribute_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 3436694846
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_DataServiceRequest" },
		{ "Comment", "//! \\brief ??\xc8\xa1??\xd0\xb1????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1??\xd0\xb1????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataServiceRequest, nullptr, "GetSelectAttribute", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::SuperMap_DataServiceRequest_eventGetSelectAttribute_Parms), Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics
	{
		struct SuperMap_DataServiceRequest_eventSetBottomAltitudeFiledName_Parms
		{
			FString strBottomAltitude;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strBottomAltitude;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::NewProp_strBottomAltitude = { "strBottomAltitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataServiceRequest_eventSetBottomAltitudeFiledName_Parms, strBottomAltitude), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::NewProp_strBottomAltitude,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_DataServiceRequest" },
		{ "Comment", "//! \\brief ???\xc3\xbb?\xc8\xa1?\xd7\xb2??\xdf\xb3\xcc\xb5??\xd6\xb6???\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
		{ "ToolTip", "! \\brief ???\xc3\xbb?\xc8\xa1?\xd7\xb2??\xdf\xb3\xcc\xb5??\xd6\xb6???" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataServiceRequest, nullptr, "SetBottomAltitudeFiledName", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::SuperMap_DataServiceRequest_eventSetBottomAltitudeFiledName_Parms), Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics
	{
		struct SuperMap_DataServiceRequest_eventSetExtendHeightFiledName_Parms
		{
			FString strExtendHeight;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strExtendHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::NewProp_strExtendHeight = { "strExtendHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataServiceRequest_eventSetExtendHeightFiledName_Parms, strExtendHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::NewProp_strExtendHeight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_DataServiceRequest" },
		{ "Comment", "//! \\brief ???\xc3\xbb?\xc8\xa1?\xdf\xb6?\xd6\xb5???\xd6\xb6???\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
		{ "ToolTip", "! \\brief ???\xc3\xbb?\xc8\xa1?\xdf\xb6?\xd6\xb5???\xd6\xb6???" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataServiceRequest, nullptr, "SetExtendHeightFiledName", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::SuperMap_DataServiceRequest_eventSetExtendHeightFiledName_Parms), Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics
	{
		struct SuperMap_DataServiceRequest_eventSetIServiceData_Parms
		{
			FString strUrlServer;
			FString strDataSourceName;
			FString strDatasetName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strUrlServer;
		static const UECodeGen_Private::FStrPropertyParams NewProp_strDataSourceName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_strDatasetName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::NewProp_strUrlServer = { "strUrlServer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataServiceRequest_eventSetIServiceData_Parms, strUrlServer), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::NewProp_strDataSourceName = { "strDataSourceName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataServiceRequest_eventSetIServiceData_Parms, strDataSourceName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::NewProp_strDatasetName = { "strDatasetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataServiceRequest_eventSetIServiceData_Parms, strDatasetName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::NewProp_strUrlServer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::NewProp_strDataSourceName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::NewProp_strDatasetName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_DataServiceRequest" },
		{ "Comment", "//! \\brief ??????\xd0\xb1??\xd3\xa6\xca\xb8????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
		{ "ToolTip", "! \\brief ??????\xd0\xb1??\xd3\xa6\xca\xb8????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataServiceRequest, nullptr, "SetIServiceData", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::SuperMap_DataServiceRequest_eventSetIServiceData_Parms), Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_DataServiceRequest);
	UClass* Z_Construct_UClass_ASuperMap_DataServiceRequest_NoRegister()
	{
		return ASuperMap_DataServiceRequest::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallDataServiceRequest_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallDataServiceRequest;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_DataServiceRequest_BuildDataServiceRequest, "BuildDataServiceRequest" }, // 1879968089
		{ &Z_Construct_UFunction_ASuperMap_DataServiceRequest_GetSelectAttribute, "GetSelectAttribute" }, // 4040486335
		{ &Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetBottomAltitudeFiledName, "SetBottomAltitudeFiledName" }, // 2867483597
		{ &Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetExtendHeightFiledName, "SetExtendHeightFiledName" }, // 3726172561
		{ &Z_Construct_UFunction_ASuperMap_DataServiceRequest_SetIServiceData, "SetIServiceData" }, // 774369823
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SceneOperation/SuperMap_DataServiceRequest.h" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::NewProp_CallDataServiceRequest_MetaData[] = {
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataServiceRequest.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::NewProp_CallDataServiceRequest = { "CallDataServiceRequest", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_DataServiceRequest, CallDataServiceRequest), Z_Construct_UDelegateFunction_SuperMapSamples_DataServiceRequestDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::NewProp_CallDataServiceRequest_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::NewProp_CallDataServiceRequest_MetaData)) }; // 1636607666
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::NewProp_CallDataServiceRequest,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_DataServiceRequest>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::ClassParams = {
		&ASuperMap_DataServiceRequest::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_DataServiceRequest()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_DataServiceRequest.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_DataServiceRequest.OuterSingleton, Z_Construct_UClass_ASuperMap_DataServiceRequest_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_DataServiceRequest.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_DataServiceRequest>()
	{
		return ASuperMap_DataServiceRequest::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_DataServiceRequest);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataServiceRequest_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataServiceRequest_h_Statics::ScriptStructInfo[] = {
		{ FDataServiceRequestInfos::StaticStruct, Z_Construct_UScriptStruct_FDataServiceRequestInfos_Statics::NewStructOps, TEXT("DataServiceRequestInfos"), &Z_Registration_Info_UScriptStruct_DataServiceRequestInfos, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDataServiceRequestInfos), 3436694846U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataServiceRequest_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_DataServiceRequest, ASuperMap_DataServiceRequest::StaticClass, TEXT("ASuperMap_DataServiceRequest"), &Z_Registration_Info_UClass_ASuperMap_DataServiceRequest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_DataServiceRequest), 2868462272U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataServiceRequest_h_3641174111(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataServiceRequest_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataServiceRequest_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataServiceRequest_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataServiceRequest_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
