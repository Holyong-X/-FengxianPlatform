// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SceneOperation/SuperMap_DataInfoProcessing.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_DataInfoProcessing() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ActorDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FPostProcessingInfo();
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FWeatherInfo();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FSceneInfo();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_DataInfoProcessing_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_DataInfoProcessing();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_ActorDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_ActorDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_ActorDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "ActorDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_ActorDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_ActorDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ActorDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_ActorDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PostProcessingInfo;
class UScriptStruct* FPostProcessingInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PostProcessingInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PostProcessingInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPostProcessingInfo, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("PostProcessingInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PostProcessingInfo.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FPostProcessingInfo>()
{
	return FPostProcessingInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPostProcessingInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsPostProcessingInfo_MetaData[];
#endif
		static void NewProp_IsPostProcessingInfo_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsPostProcessingInfo;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SSRIntensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SSRIntensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SSRQuality_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SSRQuality;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SSRMaxRoughness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SSRMaxRoughness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AOIntensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AOIntensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AORadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AORadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DFAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DFAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DFMax_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DFMax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FocalDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FocalDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DepthBlurKm_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthBlurKm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DepthBlurRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthBlurRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BloomIntensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BloomIntensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BloomThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BloomThreshold;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPostProcessingInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_IsPostProcessingInfo_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ?\xc7\xb7???????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7???????????" },
	};
#endif
	void Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_IsPostProcessingInfo_SetBit(void* Obj)
	{
		((FPostProcessingInfo*)Obj)->IsPostProcessingInfo = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_IsPostProcessingInfo = { "IsPostProcessingInfo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPostProcessingInfo), &Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_IsPostProcessingInfo_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_IsPostProcessingInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_IsPostProcessingInfo_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRIntensity_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xc4\xbb?\xd5\xbc\xe4\xb7\xb4?? \xc7\xbf??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xc4\xbb?\xd5\xbc\xe4\xb7\xb4?? \xc7\xbf??" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRIntensity = { "SSRIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, SSRIntensity), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRIntensity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRIntensity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRQuality_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xc4\xbb?\xd5\xbc\xe4\xb7\xb4?? ????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xc4\xbb?\xd5\xbc\xe4\xb7\xb4?? ????" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRQuality = { "SSRQuality", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, SSRQuality), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRQuality_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRQuality_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRMaxRoughness_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xc4\xbb?\xd5\xbc\xe4\xb7\xb4?? ?????\xd6\xb2\xda\xb6?\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xc4\xbb?\xd5\xbc\xe4\xb7\xb4?? ?????\xd6\xb2\xda\xb6?" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRMaxRoughness = { "SSRMaxRoughness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, SSRMaxRoughness), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRMaxRoughness_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRMaxRoughness_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AOIntensity_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ???????\xda\xb5? \xc7\xbf??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ???????\xda\xb5? \xc7\xbf??" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AOIntensity = { "AOIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, AOIntensity), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AOIntensity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AOIntensity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AORadius_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ???????\xda\xb5? ?\xeb\xbe\xb6\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ???????\xda\xb5? ?\xeb\xbe\xb6" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AORadius = { "AORadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, AORadius), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AORadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AORadius_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFAmount_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xcc\xac\xc4\xa3?? \xc7\xbf??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xcc\xac\xc4\xa3?? \xc7\xbf??" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFAmount = { "DFAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, DFAmount), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFMax_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xcc\xac\xc4\xa3?? ????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xcc\xac\xc4\xa3?? ????" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFMax = { "DFMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, DFMax), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFMax_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFMax_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_FocalDistance_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ???? ????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ???? ????" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_FocalDistance = { "FocalDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, FocalDistance), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_FocalDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_FocalDistance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurKm_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ???? ????\xc4\xa3??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ???? ????\xc4\xa3??" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurKm = { "DepthBlurKm", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, DepthBlurKm), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurKm_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurKm_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurRadius_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ???? ????\xc4\xa3???\xeb\xbe\xb6\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ???? ????\xc4\xa3???\xeb\xbe\xb6" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurRadius = { "DepthBlurRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, DepthBlurRadius), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurRadius_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomIntensity_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ???? \xc7\xbf??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ???? \xc7\xbf??" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomIntensity = { "BloomIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, BloomIntensity), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomIntensity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomIntensity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomThreshold_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ???? ??\xd6\xb5\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ???? ??\xd6\xb5" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomThreshold = { "BloomThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPostProcessingInfo, BloomThreshold), METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomThreshold_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomThreshold_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_IsPostProcessingInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRIntensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRQuality,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_SSRMaxRoughness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AOIntensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_AORadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DFMax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_FocalDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurKm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_DepthBlurRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomIntensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewProp_BloomThreshold,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"PostProcessingInfo",
		sizeof(FPostProcessingInfo),
		alignof(FPostProcessingInfo),
		Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPostProcessingInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PostProcessingInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PostProcessingInfo.InnerSingleton, Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PostProcessingInfo.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_WeatherInfo;
class UScriptStruct* FWeatherInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_WeatherInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_WeatherInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FWeatherInfo, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("WeatherInfo"));
	}
	return Z_Registration_Info_UScriptStruct_WeatherInfo.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FWeatherInfo>()
{
	return FWeatherInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FWeatherInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsWeather_MetaData[];
#endif
		static void NewProp_IsWeather_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsWeather;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_vWeatherPsition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_m_vWeatherPsition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeatherType_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_WeatherType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Wetness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Wetness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SnowCoverage_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SnowCoverage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Cloudiness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Cloudiness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnRate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeatherInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWeatherInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_IsWeather_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ?\xc7\xb7?????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7?????????" },
	};
#endif
	void Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_IsWeather_SetBit(void* Obj)
	{
		((FWeatherInfo*)Obj)->IsWeather = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_IsWeather = { "IsWeather", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FWeatherInfo), &Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_IsWeather_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_IsWeather_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_IsWeather_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_m_vWeatherPsition_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xd1\xa9????\xce\xbb??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xd1\xa9????\xce\xbb??" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_m_vWeatherPsition = { "m_vWeatherPsition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeatherInfo, m_vWeatherPsition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_m_vWeatherPsition_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_m_vWeatherPsition_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_WeatherType_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ????(0:Sun 1:Cloudly 2:Rain 3:Snow)\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ????(0:Sun 1:Cloudly 2:Rain 3:Snow)" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_WeatherType = { "WeatherType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeatherInfo, WeatherType), METADATA_PARAMS(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_WeatherType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_WeatherType_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Wetness_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ????\xca\xaa??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ????\xca\xaa??" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Wetness = { "Wetness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeatherInfo, Wetness), METADATA_PARAMS(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Wetness_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Wetness_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SnowCoverage_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xd1\xa9????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xd1\xa9????" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SnowCoverage = { "SnowCoverage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeatherInfo, SnowCoverage), METADATA_PARAMS(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SnowCoverage_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SnowCoverage_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Cloudiness_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ?????\xc6\xb8???\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ?????\xc6\xb8???" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Cloudiness = { "Cloudiness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeatherInfo, Cloudiness), METADATA_PARAMS(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Cloudiness_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Cloudiness_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SpawnRate_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xd1\xa9??????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xd1\xa9??????" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SpawnRate = { "SpawnRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeatherInfo, SpawnRate), METADATA_PARAMS(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SpawnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SpawnRate_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWeatherInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_IsWeather,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_m_vWeatherPsition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_WeatherType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Wetness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SnowCoverage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_Cloudiness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewProp_SpawnRate,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWeatherInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"WeatherInfo",
		sizeof(FWeatherInfo),
		alignof(FWeatherInfo),
		Z_Construct_UScriptStruct_FWeatherInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeatherInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FWeatherInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWeatherInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FWeatherInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_WeatherInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_WeatherInfo.InnerSingleton, Z_Construct_UScriptStruct_FWeatherInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_WeatherInfo.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SceneInfo;
class UScriptStruct* FSceneInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SceneInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SceneInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSceneInfo, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("SceneInfo"));
	}
	return Z_Registration_Info_UScriptStruct_SceneInfo.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FSceneInfo>()
{
	return FSceneInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSceneInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bIsScene_MetaData[];
#endif
		static void NewProp_m_bIsScene_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bIsScene;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_tSunTime_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_m_tSunTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_fTimeZone_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_m_fTimeZone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSceneInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSceneInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_bIsScene_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ?\xc7\xb7????\xc3\xb3???????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7????\xc3\xb3???????" },
	};
#endif
	void Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_bIsScene_SetBit(void* Obj)
	{
		((FSceneInfo*)Obj)->m_bIsScene = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_bIsScene = { "m_bIsScene", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSceneInfo), &Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_bIsScene_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_bIsScene_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_bIsScene_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_tSunTime_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief \xca\xb1??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief \xca\xb1??" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_tSunTime = { "m_tSunTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneInfo, m_tSunTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_tSunTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_tSunTime_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_fTimeZone_MetaData[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief \xca\xb1??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief \xca\xb1??" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_fTimeZone = { "m_fTimeZone", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSceneInfo, m_fTimeZone), METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_fTimeZone_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_fTimeZone_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSceneInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_bIsScene,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_tSunTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSceneInfo_Statics::NewProp_m_fTimeZone,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSceneInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"SceneInfo",
		sizeof(FSceneInfo),
		alignof(FSceneInfo),
		Z_Construct_UScriptStruct_FSceneInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSceneInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSceneInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_SceneInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SceneInfo.InnerSingleton, Z_Construct_UScriptStruct_FSceneInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SceneInfo.InnerSingleton;
	}
	DEFINE_FUNCTION(ASuperMap_DataInfoProcessing::execGetSceneInfo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FSceneInfo*)Z_Param__Result=P_THIS->GetSceneInfo();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_DataInfoProcessing::execSetSceneInfo)
	{
		P_GET_STRUCT(FDateTime,Z_Param_dateTime);
		P_GET_PROPERTY(FFloatProperty,Z_Param_dateTimeZone);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSceneInfo(Z_Param_dateTime,Z_Param_dateTimeZone);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_DataInfoProcessing::execGetWeatherInfo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FWeatherInfo*)Z_Param__Result=P_THIS->GetWeatherInfo();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_DataInfoProcessing::execSetWeatherInfo)
	{
		P_GET_STRUCT(FWeatherInfo,Z_Param_weatherInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetWeatherInfo(Z_Param_weatherInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_DataInfoProcessing::execGetPostProcessingInfo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FPostProcessingInfo*)Z_Param__Result=P_THIS->GetPostProcessingInfo();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_DataInfoProcessing::execSetPostProcessingInfo)
	{
		P_GET_STRUCT(FPostProcessingInfo,Z_Param_postProcessingInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPostProcessingInfo(Z_Param_postProcessingInfo);
		P_NATIVE_END;
	}
	void ASuperMap_DataInfoProcessing::StaticRegisterNativesASuperMap_DataInfoProcessing()
	{
		UClass* Class = ASuperMap_DataInfoProcessing::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetPostProcessingInfo", &ASuperMap_DataInfoProcessing::execGetPostProcessingInfo },
			{ "GetSceneInfo", &ASuperMap_DataInfoProcessing::execGetSceneInfo },
			{ "GetWeatherInfo", &ASuperMap_DataInfoProcessing::execGetWeatherInfo },
			{ "SetPostProcessingInfo", &ASuperMap_DataInfoProcessing::execSetPostProcessingInfo },
			{ "SetSceneInfo", &ASuperMap_DataInfoProcessing::execSetSceneInfo },
			{ "SetWeatherInfo", &ASuperMap_DataInfoProcessing::execSetWeatherInfo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics
	{
		struct SuperMap_DataInfoProcessing_eventGetPostProcessingInfo_Parms
		{
			FPostProcessingInfo ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataInfoProcessing_eventGetPostProcessingInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FPostProcessingInfo, METADATA_PARAMS(nullptr, 0) }; // 1587148585
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xc8\xa1??????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1??????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataInfoProcessing, nullptr, "GetPostProcessingInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::SuperMap_DataInfoProcessing_eventGetPostProcessingInfo_Parms), Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics
	{
		struct SuperMap_DataInfoProcessing_eventGetSceneInfo_Parms
		{
			FSceneInfo ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataInfoProcessing_eventGetSceneInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FSceneInfo, METADATA_PARAMS(nullptr, 0) }; // 124190006
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xc8\xa1????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataInfoProcessing, nullptr, "GetSceneInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::SuperMap_DataInfoProcessing_eventGetSceneInfo_Parms), Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics
	{
		struct SuperMap_DataInfoProcessing_eventGetWeatherInfo_Parms
		{
			FWeatherInfo ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataInfoProcessing_eventGetWeatherInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FWeatherInfo, METADATA_PARAMS(nullptr, 0) }; // 711124601
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??\xc8\xa1??\xd1\xa9????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1??\xd1\xa9????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataInfoProcessing, nullptr, "GetWeatherInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::SuperMap_DataInfoProcessing_eventGetWeatherInfo_Parms), Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics
	{
		struct SuperMap_DataInfoProcessing_eventSetPostProcessingInfo_Parms
		{
			FPostProcessingInfo postProcessingInfo;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_postProcessingInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::NewProp_postProcessingInfo = { "postProcessingInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataInfoProcessing_eventSetPostProcessingInfo_Parms, postProcessingInfo), Z_Construct_UScriptStruct_FPostProcessingInfo, METADATA_PARAMS(nullptr, 0) }; // 1587148585
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::NewProp_postProcessingInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??????????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??????????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataInfoProcessing, nullptr, "SetPostProcessingInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::SuperMap_DataInfoProcessing_eventSetPostProcessingInfo_Parms), Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics
	{
		struct SuperMap_DataInfoProcessing_eventSetSceneInfo_Parms
		{
			FDateTime dateTime;
			float dateTimeZone;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_dateTime;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_dateTimeZone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::NewProp_dateTime = { "dateTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataInfoProcessing_eventSetSceneInfo_Parms, dateTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::NewProp_dateTimeZone = { "dateTimeZone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataInfoProcessing_eventSetSceneInfo_Parms, dateTimeZone), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::NewProp_dateTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::NewProp_dateTimeZone,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ???\xe6\xb3\xa1??????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ???\xe6\xb3\xa1??????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataInfoProcessing, nullptr, "SetSceneInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::SuperMap_DataInfoProcessing_eventSetSceneInfo_Parms), Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics
	{
		struct SuperMap_DataInfoProcessing_eventSetWeatherInfo_Parms
		{
			FWeatherInfo weatherInfo;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_weatherInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::NewProp_weatherInfo = { "weatherInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DataInfoProcessing_eventSetWeatherInfo_Parms, weatherInfo), Z_Construct_UScriptStruct_FWeatherInfo, METADATA_PARAMS(nullptr, 0) }; // 711124601
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::NewProp_weatherInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_DataInfoProcessing" },
		{ "Comment", "//! \\brief ??????\xd1\xa9????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ToolTip", "! \\brief ??????\xd1\xa9????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DataInfoProcessing, nullptr, "SetWeatherInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::SuperMap_DataInfoProcessing_eventSetWeatherInfo_Parms), Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_DataInfoProcessing);
	UClass* Z_Construct_UClass_ASuperMap_DataInfoProcessing_NoRegister()
	{
		return ASuperMap_DataInfoProcessing::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics
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
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetPostProcessingInfo, "GetPostProcessingInfo" }, // 2497750308
		{ &Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetSceneInfo, "GetSceneInfo" }, // 518880794
		{ &Z_Construct_UFunction_ASuperMap_DataInfoProcessing_GetWeatherInfo, "GetWeatherInfo" }, // 1132575035
		{ &Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetPostProcessingInfo, "SetPostProcessingInfo" }, // 89789867
		{ &Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetSceneInfo, "SetSceneInfo" }, // 3739385556
		{ &Z_Construct_UFunction_ASuperMap_DataInfoProcessing_SetWeatherInfo, "SetWeatherInfo" }, // 1749281935
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SceneOperation/SuperMap_DataInfoProcessing.h" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::NewProp_CallEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_DataInfoProcessing.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::NewProp_CallEvent = { "CallEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_DataInfoProcessing, CallEvent), Z_Construct_UDelegateFunction_SuperMapSamples_ActorDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::NewProp_CallEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::NewProp_CallEvent_MetaData)) }; // 777712100
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::NewProp_CallEvent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_DataInfoProcessing>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::ClassParams = {
		&ASuperMap_DataInfoProcessing::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_DataInfoProcessing()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_DataInfoProcessing.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_DataInfoProcessing.OuterSingleton, Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_DataInfoProcessing.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_DataInfoProcessing>()
	{
		return ASuperMap_DataInfoProcessing::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_DataInfoProcessing);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_Statics::ScriptStructInfo[] = {
		{ FPostProcessingInfo::StaticStruct, Z_Construct_UScriptStruct_FPostProcessingInfo_Statics::NewStructOps, TEXT("PostProcessingInfo"), &Z_Registration_Info_UScriptStruct_PostProcessingInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPostProcessingInfo), 1587148585U) },
		{ FWeatherInfo::StaticStruct, Z_Construct_UScriptStruct_FWeatherInfo_Statics::NewStructOps, TEXT("WeatherInfo"), &Z_Registration_Info_UScriptStruct_WeatherInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FWeatherInfo), 711124601U) },
		{ FSceneInfo::StaticStruct, Z_Construct_UScriptStruct_FSceneInfo_Statics::NewStructOps, TEXT("SceneInfo"), &Z_Registration_Info_UScriptStruct_SceneInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSceneInfo), 124190006U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_DataInfoProcessing, ASuperMap_DataInfoProcessing::StaticClass, TEXT("ASuperMap_DataInfoProcessing"), &Z_Registration_Info_UClass_ASuperMap_DataInfoProcessing, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_DataInfoProcessing), 3018379380U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_1234410305(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
