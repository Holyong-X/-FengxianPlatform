// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SuperMap_CloudLicense.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_CloudLicense() {}
// Cross Module References
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FAvailLicenses();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_CloudLicense_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_CloudLicense();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AvailLicenses;
class UScriptStruct* FAvailLicenses::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AvailLicenses.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AvailLicenses.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAvailLicenses, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("AvailLicenses"));
	}
	return Z_Registration_Info_UScriptStruct_AvailLicenses.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FAvailLicenses>()
{
	return FAvailLicenses::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAvailLicenses_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_ID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_ID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_RemainDays_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_RemainDays;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_Version_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_Version;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_UserID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_UserID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvailLicenses_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAvailLicenses>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_ID_MetaData[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "Comment", "//! \\brief \n" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
		{ "ToolTip", "! \\brief" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_ID = { "m_ID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvailLicenses, m_ID), METADATA_PARAMS(Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_ID_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_ID_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_RemainDays_MetaData[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "Comment", "//! \\brief remaindays\n" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
		{ "ToolTip", "! \\brief remaindays" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_RemainDays = { "m_RemainDays", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvailLicenses, m_RemainDays), METADATA_PARAMS(Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_RemainDays_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_RemainDays_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_Version_MetaData[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "Comment", "//! \\brief version\n" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
		{ "ToolTip", "! \\brief version" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_Version = { "m_Version", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvailLicenses, m_Version), METADATA_PARAMS(Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_Version_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_Version_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_UserID_MetaData[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "Comment", "//! \\brief userid\n" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
		{ "ToolTip", "! \\brief userid" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_UserID = { "m_UserID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvailLicenses, m_UserID), METADATA_PARAMS(Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_UserID_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_UserID_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAvailLicenses_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_ID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_RemainDays,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_Version,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewProp_m_UserID,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAvailLicenses_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"AvailLicenses",
		sizeof(FAvailLicenses),
		alignof(FAvailLicenses),
		Z_Construct_UScriptStruct_FAvailLicenses_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvailLicenses_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAvailLicenses_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvailLicenses_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAvailLicenses()
	{
		if (!Z_Registration_Info_UScriptStruct_AvailLicenses.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AvailLicenses.InnerSingleton, Z_Construct_UScriptStruct_FAvailLicenses_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AvailLicenses.InnerSingleton;
	}
	DEFINE_FUNCTION(ASuperMap_CloudLicense::execCloudLicense_LicenseVerify)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CloudLicense_LicenseVerify();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CloudLicense::execCloudLicense_TrialLicense)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->CloudLicense_TrialLicense();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CloudLicense::execCloudLicense_Connect)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_id);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->CloudLicense_Connect(Z_Param_id);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CloudLicense::execCloudLicense_GetAvailLicenses)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FAvailLicenses>*)Z_Param__Result=P_THIS->CloudLicense_GetAvailLicenses();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CloudLicense::execCloudLicense_Logout)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloudLicense_Logout();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CloudLicense::execCloudLicense_Login)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_user);
		P_GET_PROPERTY(FStrProperty,Z_Param_password);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CloudLicense_Login(Z_Param_user,Z_Param_password);
		P_NATIVE_END;
	}
	void ASuperMap_CloudLicense::StaticRegisterNativesASuperMap_CloudLicense()
	{
		UClass* Class = ASuperMap_CloudLicense::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloudLicense_Connect", &ASuperMap_CloudLicense::execCloudLicense_Connect },
			{ "CloudLicense_GetAvailLicenses", &ASuperMap_CloudLicense::execCloudLicense_GetAvailLicenses },
			{ "CloudLicense_LicenseVerify", &ASuperMap_CloudLicense::execCloudLicense_LicenseVerify },
			{ "CloudLicense_Login", &ASuperMap_CloudLicense::execCloudLicense_Login },
			{ "CloudLicense_Logout", &ASuperMap_CloudLicense::execCloudLicense_Logout },
			{ "CloudLicense_TrialLicense", &ASuperMap_CloudLicense::execCloudLicense_TrialLicense },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics
	{
		struct SuperMap_CloudLicense_eventCloudLicense_Connect_Parms
		{
			FString id;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_id;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CloudLicense_eventCloudLicense_Connect_Parms, id), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CloudLicense_eventCloudLicense_Connect_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::NewProp_id,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CloudLicense, nullptr, "CloudLicense_Connect", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::SuperMap_CloudLicense_eventCloudLicense_Connect_Parms), Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics
	{
		struct SuperMap_CloudLicense_eventCloudLicense_GetAvailLicenses_Parms
		{
			TArray<FAvailLicenses> ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FAvailLicenses, METADATA_PARAMS(nullptr, 0) }; // 3800610569
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CloudLicense_eventCloudLicense_GetAvailLicenses_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 3800610569
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CloudLicense, nullptr, "CloudLicense_GetAvailLicenses", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::SuperMap_CloudLicense_eventCloudLicense_GetAvailLicenses_Parms), Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics
	{
		struct SuperMap_CloudLicense_eventCloudLicense_LicenseVerify_Parms
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
	void Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_CloudLicense_eventCloudLicense_LicenseVerify_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_CloudLicense_eventCloudLicense_LicenseVerify_Parms), &Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CloudLicense, nullptr, "CloudLicense_LicenseVerify", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::SuperMap_CloudLicense_eventCloudLicense_LicenseVerify_Parms), Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics
	{
		struct SuperMap_CloudLicense_eventCloudLicense_Login_Parms
		{
			FString user;
			FString password;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_user;
		static const UECodeGen_Private::FStrPropertyParams NewProp_password;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::NewProp_user = { "user", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CloudLicense_eventCloudLicense_Login_Parms, user), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::NewProp_password = { "password", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CloudLicense_eventCloudLicense_Login_Parms, password), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_CloudLicense_eventCloudLicense_Login_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_CloudLicense_eventCloudLicense_Login_Parms), &Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::NewProp_user,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::NewProp_password,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CloudLicense, nullptr, "CloudLicense_Login", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::SuperMap_CloudLicense_eventCloudLicense_Login_Parms), Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Logout_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Logout_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Logout_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CloudLicense, nullptr, "CloudLicense_Logout", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Logout_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Logout_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Logout()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Logout_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics
	{
		struct SuperMap_CloudLicense_eventCloudLicense_TrialLicense_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CloudLicense_eventCloudLicense_TrialLicense_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_CloudLicense" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CloudLicense, nullptr, "CloudLicense_TrialLicense", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::SuperMap_CloudLicense_eventCloudLicense_TrialLicense_Parms), Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_CloudLicense);
	UClass* Z_Construct_UClass_ASuperMap_CloudLicense_NoRegister()
	{
		return ASuperMap_CloudLicense::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_CloudLicense_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_CloudLicense_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_CloudLicense_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Connect, "CloudLicense_Connect" }, // 999895424
		{ &Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_GetAvailLicenses, "CloudLicense_GetAvailLicenses" }, // 3100923191
		{ &Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_LicenseVerify, "CloudLicense_LicenseVerify" }, // 3929420654
		{ &Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Login, "CloudLicense_Login" }, // 519953747
		{ &Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_Logout, "CloudLicense_Logout" }, // 4018185368
		{ &Z_Construct_UFunction_ASuperMap_CloudLicense_CloudLicense_TrialLicense, "CloudLicense_TrialLicense" }, // 1620557988
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_CloudLicense_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SuperMap_CloudLicense.h" },
		{ "ModuleRelativePath", "Public/SuperMap_CloudLicense.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_CloudLicense_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_CloudLicense>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_CloudLicense_Statics::ClassParams = {
		&ASuperMap_CloudLicense::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_CloudLicense_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_CloudLicense_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_CloudLicense()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_CloudLicense.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_CloudLicense.OuterSingleton, Z_Construct_UClass_ASuperMap_CloudLicense_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_CloudLicense.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_CloudLicense>()
	{
		return ASuperMap_CloudLicense::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_CloudLicense);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_CloudLicense_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_CloudLicense_h_Statics::ScriptStructInfo[] = {
		{ FAvailLicenses::StaticStruct, Z_Construct_UScriptStruct_FAvailLicenses_Statics::NewStructOps, TEXT("AvailLicenses"), &Z_Registration_Info_UScriptStruct_AvailLicenses, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAvailLicenses), 3800610569U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_CloudLicense_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_CloudLicense, ASuperMap_CloudLicense::StaticClass, TEXT("ASuperMap_CloudLicense"), &Z_Registration_Info_UClass_ASuperMap_CloudLicense, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_CloudLicense), 3740299947U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_CloudLicense_h_1125326418(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_CloudLicense_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_CloudLicense_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_CloudLicense_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_CloudLicense_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
