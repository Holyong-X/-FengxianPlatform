// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_SlopeInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_SlopeInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_SlopeInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_SlopeInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_SlopeInstance::execGetColorTableFiles)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetColorTableFiles();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SlopeInstance::execEndSlope)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndSlope();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SlopeInstance::execSetMaxVisibleValue)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_maxValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaxVisibleValue(Z_Param_maxValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SlopeInstance::execSetMinVisibleValue)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_minValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMinVisibleValue(Z_Param_minValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SlopeInstance::execSetColorTable)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strColorTableName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetColorTable(Z_Param_strColorTableName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SlopeInstance::execSetArrowMove)
	{
		P_GET_UBOOL(Z_Param_isMove);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetArrowMove(Z_Param_isMove);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SlopeInstance::execDisplayModeChanged)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nDisplayMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisplayModeChanged(Z_Param_nDisplayMode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SlopeInstance::execBuildSlope)
	{
		P_GET_UBOOL(Z_Param_SlopeEnable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildSlope(Z_Param_SlopeEnable);
		P_NATIVE_END;
	}
	void ASuperMap_SlopeInstance::StaticRegisterNativesASuperMap_SlopeInstance()
	{
		UClass* Class = ASuperMap_SlopeInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildSlope", &ASuperMap_SlopeInstance::execBuildSlope },
			{ "DisplayModeChanged", &ASuperMap_SlopeInstance::execDisplayModeChanged },
			{ "EndSlope", &ASuperMap_SlopeInstance::execEndSlope },
			{ "GetColorTableFiles", &ASuperMap_SlopeInstance::execGetColorTableFiles },
			{ "SetArrowMove", &ASuperMap_SlopeInstance::execSetArrowMove },
			{ "SetColorTable", &ASuperMap_SlopeInstance::execSetColorTable },
			{ "SetMaxVisibleValue", &ASuperMap_SlopeInstance::execSetMaxVisibleValue },
			{ "SetMinVisibleValue", &ASuperMap_SlopeInstance::execSetMinVisibleValue },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics
	{
		struct SuperMap_SlopeInstance_eventBuildSlope_Parms
		{
			bool SlopeEnable;
		};
		static void NewProp_SlopeEnable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SlopeEnable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::NewProp_SlopeEnable_SetBit(void* Obj)
	{
		((SuperMap_SlopeInstance_eventBuildSlope_Parms*)Obj)->SlopeEnable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::NewProp_SlopeEnable = { "SlopeEnable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_SlopeInstance_eventBuildSlope_Parms), &Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::NewProp_SlopeEnable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::NewProp_SlopeEnable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SlopeInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7?\xd6\xb4???\xc2\xb6?????????\n//! \\return true\xce\xaa??\xca\xbc\xd6\xb4???\xc2\xb6?????????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SlopeInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7?\xd6\xb4???\xc2\xb6?????????\n! \\return true\xce\xaa??\xca\xbc\xd6\xb4???\xc2\xb6?????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SlopeInstance, nullptr, "BuildSlope", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::SuperMap_SlopeInstance_eventBuildSlope_Parms), Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics
	{
		struct SuperMap_SlopeInstance_eventDisplayModeChanged_Parms
		{
			int32 nDisplayMode;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nDisplayMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::NewProp_nDisplayMode = { "nDisplayMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SlopeInstance_eventDisplayModeChanged_Parms, nDisplayMode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::NewProp_nDisplayMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SlopeInstance" },
		{ "Comment", "//! \\brief ??????\xca\xbe\xc4\xa3\xca\xbd\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SlopeInstance.h" },
		{ "ToolTip", "! \\brief ??????\xca\xbe\xc4\xa3\xca\xbd" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SlopeInstance, nullptr, "DisplayModeChanged", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::SuperMap_SlopeInstance_eventDisplayModeChanged_Parms), Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SlopeInstance_EndSlope_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SlopeInstance_EndSlope_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SlopeInstance" },
		{ "Comment", "//! \\brief ????\xcd\xbc??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SlopeInstance.h" },
		{ "ToolTip", "! \\brief ????\xcd\xbc??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SlopeInstance_EndSlope_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SlopeInstance, nullptr, "EndSlope", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SlopeInstance_EndSlope_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_EndSlope_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SlopeInstance_EndSlope()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SlopeInstance_EndSlope_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics
	{
		struct SuperMap_SlopeInstance_eventGetColorTableFiles_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SlopeInstance_eventGetColorTableFiles_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SlopeInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1?\xc4\xbc????\xc2\xb5???\xc9\xab???\xc4\xbc?\xc2\xb7??\n//! \\return ??\xc8\xa1??\xc9\xab???\xe6\xb4\xa2\xc2\xb7??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SlopeInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1?\xc4\xbc????\xc2\xb5???\xc9\xab???\xc4\xbc?\xc2\xb7??\n! \\return ??\xc8\xa1??\xc9\xab???\xe6\xb4\xa2\xc2\xb7??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SlopeInstance, nullptr, "GetColorTableFiles", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::SuperMap_SlopeInstance_eventGetColorTableFiles_Parms), Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics
	{
		struct SuperMap_SlopeInstance_eventSetArrowMove_Parms
		{
			bool isMove;
		};
		static void NewProp_isMove_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isMove;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::NewProp_isMove_SetBit(void* Obj)
	{
		((SuperMap_SlopeInstance_eventSetArrowMove_Parms*)Obj)->isMove = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::NewProp_isMove = { "isMove", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_SlopeInstance_eventSetArrowMove_Parms), &Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::NewProp_isMove_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::NewProp_isMove,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SlopeInstance" },
		{ "Comment", "//! \\brief ??????????\xcd\xb7?\xc7\xb7??\xcb\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SlopeInstance.h" },
		{ "ToolTip", "! \\brief ??????????\xcd\xb7?\xc7\xb7??\xcb\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SlopeInstance, nullptr, "SetArrowMove", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::SuperMap_SlopeInstance_eventSetArrowMove_Parms), Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics
	{
		struct SuperMap_SlopeInstance_eventSetColorTable_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::NewProp_strColorTableName = { "strColorTableName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SlopeInstance_eventSetColorTable_Parms, strColorTableName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::NewProp_strColorTableName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SlopeInstance" },
		{ "Comment", "//! \\brief ??????\xc9\xab??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SlopeInstance.h" },
		{ "ToolTip", "! \\brief ??????\xc9\xab??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SlopeInstance, nullptr, "SetColorTable", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::SuperMap_SlopeInstance_eventSetColorTable_Parms), Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics
	{
		struct SuperMap_SlopeInstance_eventSetMaxVisibleValue_Parms
		{
			float maxValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_maxValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::NewProp_maxValue = { "maxValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SlopeInstance_eventSetMaxVisibleValue_Parms, maxValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::NewProp_maxValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SlopeInstance" },
		{ "Comment", "//! \\brief ?????????\xc9\xbc?\xd6\xb5\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SlopeInstance.h" },
		{ "ToolTip", "! \\brief ?????????\xc9\xbc?\xd6\xb5" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SlopeInstance, nullptr, "SetMaxVisibleValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::SuperMap_SlopeInstance_eventSetMaxVisibleValue_Parms), Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics
	{
		struct SuperMap_SlopeInstance_eventSetMinVisibleValue_Parms
		{
			float minValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_minValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::NewProp_minValue = { "minValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SlopeInstance_eventSetMinVisibleValue_Parms, minValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::NewProp_minValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SlopeInstance" },
		{ "Comment", "//! \\brief ??????\xd0\xa1?\xc9\xbc?\xd6\xb5\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SlopeInstance.h" },
		{ "ToolTip", "! \\brief ??????\xd0\xa1?\xc9\xbc?\xd6\xb5" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SlopeInstance, nullptr, "SetMinVisibleValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::SuperMap_SlopeInstance_eventSetMinVisibleValue_Parms), Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_SlopeInstance);
	UClass* Z_Construct_UClass_ASuperMap_SlopeInstance_NoRegister()
	{
		return ASuperMap_SlopeInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_SlopeInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_SlopeInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_SlopeInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_SlopeInstance_BuildSlope, "BuildSlope" }, // 542869439
		{ &Z_Construct_UFunction_ASuperMap_SlopeInstance_DisplayModeChanged, "DisplayModeChanged" }, // 3989031902
		{ &Z_Construct_UFunction_ASuperMap_SlopeInstance_EndSlope, "EndSlope" }, // 150095263
		{ &Z_Construct_UFunction_ASuperMap_SlopeInstance_GetColorTableFiles, "GetColorTableFiles" }, // 76917643
		{ &Z_Construct_UFunction_ASuperMap_SlopeInstance_SetArrowMove, "SetArrowMove" }, // 3539931243
		{ &Z_Construct_UFunction_ASuperMap_SlopeInstance_SetColorTable, "SetColorTable" }, // 1374191242
		{ &Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMaxVisibleValue, "SetMaxVisibleValue" }, // 3719063322
		{ &Z_Construct_UFunction_ASuperMap_SlopeInstance_SetMinVisibleValue, "SetMinVisibleValue" }, // 3350512918
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SlopeInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_SlopeInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SlopeInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_SlopeInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_SlopeInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_SlopeInstance_Statics::ClassParams = {
		&ASuperMap_SlopeInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SlopeInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SlopeInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_SlopeInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_SlopeInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_SlopeInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_SlopeInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_SlopeInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_SlopeInstance>()
	{
		return ASuperMap_SlopeInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_SlopeInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SlopeInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SlopeInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_SlopeInstance, ASuperMap_SlopeInstance::StaticClass, TEXT("ASuperMap_SlopeInstance"), &Z_Registration_Info_UClass_ASuperMap_SlopeInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_SlopeInstance), 4204562923U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SlopeInstance_h_3310132226(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SlopeInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SlopeInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
