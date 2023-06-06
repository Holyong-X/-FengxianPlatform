// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_CalculationTinInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_CalculationTinInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_CalculationTinInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_CalculationTinInstance::execSetBaseAltitude)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fBaseAltitude);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetBaseAltitude(Z_Param_fBaseAltitude);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CalculationTinInstance::execSetDperPixel)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fDperPixel);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDperPixel(Z_Param_fDperPixel);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CalculationTinInstance::execGetNoChangeArea)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetNoChangeArea();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CalculationTinInstance::execGetCutArea)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCutArea();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CalculationTinInstance::execGetFillArea)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetFillArea();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CalculationTinInstance::execGetCutVolume)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCutVolume();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CalculationTinInstance::execGetFillVolume)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetFillVolume();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CalculationTinInstance::execCalculateResult)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CalculateResult();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_CalculationTinInstance::execBuildCalculationTin)
	{
		P_GET_UBOOL(Z_Param_bCalculationTin);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildCalculationTin(Z_Param_bCalculationTin);
		P_NATIVE_END;
	}
	void ASuperMap_CalculationTinInstance::StaticRegisterNativesASuperMap_CalculationTinInstance()
	{
		UClass* Class = ASuperMap_CalculationTinInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildCalculationTin", &ASuperMap_CalculationTinInstance::execBuildCalculationTin },
			{ "CalculateResult", &ASuperMap_CalculationTinInstance::execCalculateResult },
			{ "GetCutArea", &ASuperMap_CalculationTinInstance::execGetCutArea },
			{ "GetCutVolume", &ASuperMap_CalculationTinInstance::execGetCutVolume },
			{ "GetFillArea", &ASuperMap_CalculationTinInstance::execGetFillArea },
			{ "GetFillVolume", &ASuperMap_CalculationTinInstance::execGetFillVolume },
			{ "GetNoChangeArea", &ASuperMap_CalculationTinInstance::execGetNoChangeArea },
			{ "SetBaseAltitude", &ASuperMap_CalculationTinInstance::execSetBaseAltitude },
			{ "SetDperPixel", &ASuperMap_CalculationTinInstance::execSetDperPixel },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics
	{
		struct SuperMap_CalculationTinInstance_eventBuildCalculationTin_Parms
		{
			bool bCalculationTin;
		};
		static void NewProp_bCalculationTin_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCalculationTin;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::NewProp_bCalculationTin_SetBit(void* Obj)
	{
		((SuperMap_CalculationTinInstance_eventBuildCalculationTin_Parms*)Obj)->bCalculationTin = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::NewProp_bCalculationTin = { "bCalculationTin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_CalculationTinInstance_eventBuildCalculationTin_Parms), &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::NewProp_bCalculationTin_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::NewProp_bCalculationTin,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_CalculationTinInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CalculationTinInstance, nullptr, "BuildCalculationTin", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::SuperMap_CalculationTinInstance_eventBuildCalculationTin_Parms), Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics
	{
		struct SuperMap_CalculationTinInstance_eventCalculateResult_Parms
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
	void Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_CalculationTinInstance_eventCalculateResult_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_CalculationTinInstance_eventCalculateResult_Parms), &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_CalculationTinInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CalculationTinInstance, nullptr, "CalculateResult", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::SuperMap_CalculationTinInstance_eventCalculateResult_Parms), Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics
	{
		struct SuperMap_CalculationTinInstance_eventGetCutArea_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CalculationTinInstance_eventGetCutArea_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_CalculationTinInstance" },
		{ "Comment", "//! \\brief  ??\xc8\xa1?\xda\xb7?????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
		{ "ToolTip", "! \\brief  ??\xc8\xa1?\xda\xb7?????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CalculationTinInstance, nullptr, "GetCutArea", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::SuperMap_CalculationTinInstance_eventGetCutArea_Parms), Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics
	{
		struct SuperMap_CalculationTinInstance_eventGetCutVolume_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CalculationTinInstance_eventGetCutVolume_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_CalculationTinInstance" },
		{ "Comment", "//! \\brief  ??\xc8\xa1?\xda\xb7?????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
		{ "ToolTip", "! \\brief  ??\xc8\xa1?\xda\xb7?????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CalculationTinInstance, nullptr, "GetCutVolume", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::SuperMap_CalculationTinInstance_eventGetCutVolume_Parms), Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics
	{
		struct SuperMap_CalculationTinInstance_eventGetFillArea_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CalculationTinInstance_eventGetFillArea_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_CalculationTinInstance" },
		{ "Comment", "//! \\brief  ??\xc8\xa1?\xee\xb7\xbd????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
		{ "ToolTip", "! \\brief  ??\xc8\xa1?\xee\xb7\xbd????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CalculationTinInstance, nullptr, "GetFillArea", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::SuperMap_CalculationTinInstance_eventGetFillArea_Parms), Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics
	{
		struct SuperMap_CalculationTinInstance_eventGetFillVolume_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CalculationTinInstance_eventGetFillVolume_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_CalculationTinInstance" },
		{ "Comment", "//! \\brief  ??\xc8\xa1?\xee\xb7\xbd????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
		{ "ToolTip", "! \\brief  ??\xc8\xa1?\xee\xb7\xbd????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CalculationTinInstance, nullptr, "GetFillVolume", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::SuperMap_CalculationTinInstance_eventGetFillVolume_Parms), Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics
	{
		struct SuperMap_CalculationTinInstance_eventGetNoChangeArea_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CalculationTinInstance_eventGetNoChangeArea_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_CalculationTinInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1\xce\xb4????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1\xce\xb4????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CalculationTinInstance, nullptr, "GetNoChangeArea", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::SuperMap_CalculationTinInstance_eventGetNoChangeArea_Parms), Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics
	{
		struct SuperMap_CalculationTinInstance_eventSetBaseAltitude_Parms
		{
			float fBaseAltitude;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fBaseAltitude;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::NewProp_fBaseAltitude = { "fBaseAltitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CalculationTinInstance_eventSetBaseAltitude_Parms, fBaseAltitude), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::NewProp_fBaseAltitude,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_CalculationTinInstance" },
		{ "Comment", "//! \\brief ???\xc3\xb8??\xd3\xb8\xdf\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xb8??\xd3\xb8\xdf\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CalculationTinInstance, nullptr, "SetBaseAltitude", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::SuperMap_CalculationTinInstance_eventSetBaseAltitude_Parms), Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics
	{
		struct SuperMap_CalculationTinInstance_eventSetDperPixel_Parms
		{
			float fDperPixel;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fDperPixel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::NewProp_fDperPixel = { "fDperPixel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_CalculationTinInstance_eventSetDperPixel_Parms, fDperPixel), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::NewProp_fDperPixel,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_CalculationTinInstance" },
		{ "Comment", "//! \\brief ???\xc3\xb2???????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xb2???????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_CalculationTinInstance, nullptr, "SetDperPixel", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::SuperMap_CalculationTinInstance_eventSetDperPixel_Parms), Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_CalculationTinInstance);
	UClass* Z_Construct_UClass_ASuperMap_CalculationTinInstance_NoRegister()
	{
		return ASuperMap_CalculationTinInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_CalculationTinInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_CalculationTinInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_CalculationTinInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_BuildCalculationTin, "BuildCalculationTin" }, // 2127541893
		{ &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_CalculateResult, "CalculateResult" }, // 3464022954
		{ &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutArea, "GetCutArea" }, // 2862934896
		{ &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetCutVolume, "GetCutVolume" }, // 2991640417
		{ &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillArea, "GetFillArea" }, // 808400055
		{ &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetFillVolume, "GetFillVolume" }, // 3766134140
		{ &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_GetNoChangeArea, "GetNoChangeArea" }, // 3828041581
		{ &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetBaseAltitude, "SetBaseAltitude" }, // 3026302515
		{ &Z_Construct_UFunction_ASuperMap_CalculationTinInstance_SetDperPixel, "SetDperPixel" }, // 3162878246
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_CalculationTinInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_CalculationTinInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_CalculationTinInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_CalculationTinInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_CalculationTinInstance_Statics::ClassParams = {
		&ASuperMap_CalculationTinInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_CalculationTinInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_CalculationTinInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_CalculationTinInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_CalculationTinInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_CalculationTinInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_CalculationTinInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_CalculationTinInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_CalculationTinInstance>()
	{
		return ASuperMap_CalculationTinInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_CalculationTinInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_CalculationTinInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_CalculationTinInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_CalculationTinInstance, ASuperMap_CalculationTinInstance::StaticClass, TEXT("ASuperMap_CalculationTinInstance"), &Z_Registration_Info_UClass_ASuperMap_CalculationTinInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_CalculationTinInstance), 3302571745U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_CalculationTinInstance_h_2172499414(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_CalculationTinInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_CalculationTinInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
