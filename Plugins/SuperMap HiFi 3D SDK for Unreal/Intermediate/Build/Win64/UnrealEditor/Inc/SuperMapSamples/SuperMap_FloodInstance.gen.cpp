// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_FloodInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_FloodInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_FloodDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FloodInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FloodInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_FloodDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_FloodDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_FloodDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "FloodDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_FloodDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_FloodDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_FloodDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_FloodDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execGetColorTableFiles)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetColorTableFiles();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execClearLayer)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_minHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearLayer(Z_Param_minHeight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execGetPlayState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetPlayState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execSetPlayState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPlayState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execSetColorTable)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strColorTableName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetColorTable(Z_Param_strColorTableName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execSetMinHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_minHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMinHeight(Z_Param_minHeight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execSetMaxHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_maxHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaxHeight(Z_Param_maxHeight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execGetMinHeight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMinHeight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execGetMaxHeight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMaxHeight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execGetCurrentHeight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCurrentHeight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execSetCurrentHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_currentHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCurrentHeight(Z_Param_currentHeight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execSetSpeed)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fSpeed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSpeed(Z_Param_fSpeed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execSelectLayer)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectLayer(Z_Param_strLayerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FloodInstance::execBuildFlood)
	{
		P_GET_UBOOL(Z_Param_bFlood);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildFlood(Z_Param_bFlood);
		P_NATIVE_END;
	}
	void ASuperMap_FloodInstance::StaticRegisterNativesASuperMap_FloodInstance()
	{
		UClass* Class = ASuperMap_FloodInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildFlood", &ASuperMap_FloodInstance::execBuildFlood },
			{ "ClearLayer", &ASuperMap_FloodInstance::execClearLayer },
			{ "GetColorTableFiles", &ASuperMap_FloodInstance::execGetColorTableFiles },
			{ "GetCurrentHeight", &ASuperMap_FloodInstance::execGetCurrentHeight },
			{ "GetMaxHeight", &ASuperMap_FloodInstance::execGetMaxHeight },
			{ "GetMinHeight", &ASuperMap_FloodInstance::execGetMinHeight },
			{ "GetPlayState", &ASuperMap_FloodInstance::execGetPlayState },
			{ "SelectLayer", &ASuperMap_FloodInstance::execSelectLayer },
			{ "SetColorTable", &ASuperMap_FloodInstance::execSetColorTable },
			{ "SetCurrentHeight", &ASuperMap_FloodInstance::execSetCurrentHeight },
			{ "SetMaxHeight", &ASuperMap_FloodInstance::execSetMaxHeight },
			{ "SetMinHeight", &ASuperMap_FloodInstance::execSetMinHeight },
			{ "SetPlayState", &ASuperMap_FloodInstance::execSetPlayState },
			{ "SetSpeed", &ASuperMap_FloodInstance::execSetSpeed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics
	{
		struct SuperMap_FloodInstance_eventBuildFlood_Parms
		{
			bool bFlood;
		};
		static void NewProp_bFlood_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlood;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::NewProp_bFlood_SetBit(void* Obj)
	{
		((SuperMap_FloodInstance_eventBuildFlood_Parms*)Obj)->bFlood = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::NewProp_bFlood = { "bFlood", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FloodInstance_eventBuildFlood_Parms), &Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::NewProp_bFlood_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::NewProp_bFlood,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "BuildFlood", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::SuperMap_FloodInstance_eventBuildFlood_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics
	{
		struct SuperMap_FloodInstance_eventClearLayer_Parms
		{
			float minHeight;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_minHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::NewProp_minHeight = { "minHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventClearLayer_Parms, minHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::NewProp_minHeight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ????\xcd\xbc??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ????\xcd\xbc??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "ClearLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::SuperMap_FloodInstance_eventClearLayer_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics
	{
		struct SuperMap_FloodInstance_eventGetColorTableFiles_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventGetColorTableFiles_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1?\xc4\xbc????\xc2\xb5???\xc9\xab???\xc4\xbc?\xc2\xb7??\n//! \\return ??\xc8\xa1??\xc9\xab???\xe6\xb4\xa2\xc2\xb7??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1?\xc4\xbc????\xc2\xb5???\xc9\xab???\xc4\xbc?\xc2\xb7??\n! \\return ??\xc8\xa1??\xc9\xab???\xe6\xb4\xa2\xc2\xb7??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "GetColorTableFiles", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::SuperMap_FloodInstance_eventGetColorTableFiles_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics
	{
		struct SuperMap_FloodInstance_eventGetCurrentHeight_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventGetCurrentHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ??\xc7\xb0?\xdf\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ??\xc7\xb0?\xdf\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "GetCurrentHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::SuperMap_FloodInstance_eventGetCurrentHeight_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics
	{
		struct SuperMap_FloodInstance_eventGetMaxHeight_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventGetMaxHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ???\xdf\xb8\xdf\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ???\xdf\xb8\xdf\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "GetMaxHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::SuperMap_FloodInstance_eventGetMaxHeight_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics
	{
		struct SuperMap_FloodInstance_eventGetMinHeight_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventGetMinHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ???\xcd\xb8\xdf\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ???\xcd\xb8\xdf\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "GetMinHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::SuperMap_FloodInstance_eventGetMinHeight_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics
	{
		struct SuperMap_FloodInstance_eventGetPlayState_Parms
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
	void Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_FloodInstance_eventGetPlayState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FloodInstance_eventGetPlayState_Parms), &Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1????????????\xcd\xa3\xd7\xb4\xcc\xac\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1????????????\xcd\xa3\xd7\xb4\xcc\xac" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "GetPlayState", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::SuperMap_FloodInstance_eventGetPlayState_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics
	{
		struct SuperMap_FloodInstance_eventSelectLayer_Parms
		{
			FName strLayerName;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventSelectLayer_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::NewProp_strLayerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "SelectLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::SuperMap_FloodInstance_eventSelectLayer_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics
	{
		struct SuperMap_FloodInstance_eventSetColorTable_Parms
		{
			FString strColorTableName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strColorTableName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::NewProp_strColorTableName = { "strColorTableName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventSetColorTable_Parms, strColorTableName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::NewProp_strColorTableName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ??????\xc9\xab??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ??????\xc9\xab??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "SetColorTable", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::SuperMap_FloodInstance_eventSetColorTable_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics
	{
		struct SuperMap_FloodInstance_eventSetCurrentHeight_Parms
		{
			float currentHeight;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_currentHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::NewProp_currentHeight = { "currentHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventSetCurrentHeight_Parms, currentHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::NewProp_currentHeight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ???\xc3\xb5?\xc7\xb0?\xdf\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xb5?\xc7\xb0?\xdf\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "SetCurrentHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::SuperMap_FloodInstance_eventSetCurrentHeight_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics
	{
		struct SuperMap_FloodInstance_eventSetMaxHeight_Parms
		{
			float maxHeight;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_maxHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::NewProp_maxHeight = { "maxHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventSetMaxHeight_Parms, maxHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::NewProp_maxHeight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ???????\xdf\xb8\xdf\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ???????\xdf\xb8\xdf\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "SetMaxHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::SuperMap_FloodInstance_eventSetMaxHeight_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics
	{
		struct SuperMap_FloodInstance_eventSetMinHeight_Parms
		{
			float minHeight;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_minHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::NewProp_minHeight = { "minHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventSetMinHeight_Parms, minHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::NewProp_minHeight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ???????\xcd\xb8\xdf\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ???????\xcd\xb8\xdf\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "SetMinHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::SuperMap_FloodInstance_eventSetMinHeight_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_SetPlayState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_SetPlayState_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ???\xc3\xb7???????????\xcd\xa3?\xd0\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xb7???????????\xcd\xa3?\xd0\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetPlayState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "SetPlayState", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_SetPlayState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetPlayState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_SetPlayState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_SetPlayState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics
	{
		struct SuperMap_FloodInstance_eventSetSpeed_Parms
		{
			float fSpeed;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::NewProp_fSpeed = { "fSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FloodInstance_eventSetSpeed_Parms, fSpeed), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::NewProp_fSpeed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FloodInstance" },
		{ "Comment", "//! \\brief ??\xc3\xbb?\xd9\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ToolTip", "! \\brief ??\xc3\xbb?\xd9\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FloodInstance, nullptr, "SetSpeed", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::SuperMap_FloodInstance_eventSetSpeed_Parms), Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_FloodInstance);
	UClass* Z_Construct_UClass_ASuperMap_FloodInstance_NoRegister()
	{
		return ASuperMap_FloodInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_FloodInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallFlood_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallFlood;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_FloodInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_FloodInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_BuildFlood, "BuildFlood" }, // 724975526
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_ClearLayer, "ClearLayer" }, // 2631845529
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_GetColorTableFiles, "GetColorTableFiles" }, // 3667032771
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_GetCurrentHeight, "GetCurrentHeight" }, // 3902890381
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_GetMaxHeight, "GetMaxHeight" }, // 3683940586
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_GetMinHeight, "GetMinHeight" }, // 1889623579
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_GetPlayState, "GetPlayState" }, // 623131152
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_SelectLayer, "SelectLayer" }, // 3450617403
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_SetColorTable, "SetColorTable" }, // 3865504104
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_SetCurrentHeight, "SetCurrentHeight" }, // 2462570554
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_SetMaxHeight, "SetMaxHeight" }, // 3087464292
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_SetMinHeight, "SetMinHeight" }, // 1328044045
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_SetPlayState, "SetPlayState" }, // 2674847134
		{ &Z_Construct_UFunction_ASuperMap_FloodInstance_SetSpeed, "SetSpeed" }, // 668562802
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_FloodInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_FloodInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_FloodInstance_Statics::NewProp_CallFlood_MetaData[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FloodInstance.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_FloodInstance_Statics::NewProp_CallFlood = { "CallFlood", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_FloodInstance, CallFlood), Z_Construct_UDelegateFunction_SuperMapSamples_FloodDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_FloodInstance_Statics::NewProp_CallFlood_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_FloodInstance_Statics::NewProp_CallFlood_MetaData)) }; // 4222690601
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_FloodInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_FloodInstance_Statics::NewProp_CallFlood,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_FloodInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_FloodInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_FloodInstance_Statics::ClassParams = {
		&ASuperMap_FloodInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_FloodInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_FloodInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_FloodInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_FloodInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_FloodInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_FloodInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_FloodInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_FloodInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_FloodInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_FloodInstance>()
	{
		return ASuperMap_FloodInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_FloodInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FloodInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FloodInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_FloodInstance, ASuperMap_FloodInstance::StaticClass, TEXT("ASuperMap_FloodInstance"), &Z_Registration_Info_UClass_ASuperMap_FloodInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_FloodInstance), 1673332107U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FloodInstance_h_679752267(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FloodInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FloodInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
