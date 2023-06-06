// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SceneOperation/SuperMap_ExcavationInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ExcavationInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ExcavationInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ExcavationInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execSetSideMaterialPath)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSideMaterialPath(Z_Param_filePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execSetTopMaterialPath)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTopMaterialPath(Z_Param_filePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execIsChartlet)
	{
		P_GET_UBOOL(Z_Param_bChartlet);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->IsChartlet(Z_Param_bChartlet);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execSetInterpolatoryCount)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nCount);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetInterpolatoryCount(Z_Param_nCount);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execSetTopTexture)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTopTexture(Z_Param_filePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execSetSideTexture)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSideTexture(Z_Param_filePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execSetExtendHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_height);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetExtendHeight(Z_Param_height);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execAddWebExcavationRegion)
	{
		P_GET_TARRAY(FVector,Z_Param_arrPos);
		P_GET_PROPERTY(FStrProperty,Z_Param_Tag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddWebExcavationRegion(Z_Param_arrPos,Z_Param_Tag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execGetJsonArrayStringValue)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Descriptor);
		P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FVector>*)Z_Param__Result=P_THIS->GetJsonArrayStringValue(Z_Param_Descriptor,Z_Param_FieldName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execSetUseWeb)
	{
		P_GET_UBOOL(Z_Param_bUseWithoutWeb);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUseWeb(Z_Param_bUseWithoutWeb);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execClearModifyRegion)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearModifyRegion();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execSelectLayer)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_GET_UBOOL(Z_Param_IsSelect);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectLayer(Z_Param_strLayerName,Z_Param_IsSelect);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execSetModifyRegionMode)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_type);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetModifyRegionMode(Z_Param_type);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execAddExcavationRegion)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddExcavationRegion();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ExcavationInstance::execBuildExcavation)
	{
		P_GET_UBOOL(Z_Param_bExcavation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildExcavation(Z_Param_bExcavation);
		P_NATIVE_END;
	}
	void ASuperMap_ExcavationInstance::StaticRegisterNativesASuperMap_ExcavationInstance()
	{
		UClass* Class = ASuperMap_ExcavationInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddExcavationRegion", &ASuperMap_ExcavationInstance::execAddExcavationRegion },
			{ "AddWebExcavationRegion", &ASuperMap_ExcavationInstance::execAddWebExcavationRegion },
			{ "BuildExcavation", &ASuperMap_ExcavationInstance::execBuildExcavation },
			{ "ClearModifyRegion", &ASuperMap_ExcavationInstance::execClearModifyRegion },
			{ "GetJsonArrayStringValue", &ASuperMap_ExcavationInstance::execGetJsonArrayStringValue },
			{ "IsChartlet", &ASuperMap_ExcavationInstance::execIsChartlet },
			{ "SelectLayer", &ASuperMap_ExcavationInstance::execSelectLayer },
			{ "SetExtendHeight", &ASuperMap_ExcavationInstance::execSetExtendHeight },
			{ "SetInterpolatoryCount", &ASuperMap_ExcavationInstance::execSetInterpolatoryCount },
			{ "SetModifyRegionMode", &ASuperMap_ExcavationInstance::execSetModifyRegionMode },
			{ "SetSideMaterialPath", &ASuperMap_ExcavationInstance::execSetSideMaterialPath },
			{ "SetSideTexture", &ASuperMap_ExcavationInstance::execSetSideTexture },
			{ "SetTopMaterialPath", &ASuperMap_ExcavationInstance::execSetTopMaterialPath },
			{ "SetTopTexture", &ASuperMap_ExcavationInstance::execSetTopTexture },
			{ "SetUseWeb", &ASuperMap_ExcavationInstance::execSetUseWeb },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddExcavationRegion_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddExcavationRegion_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ?????\xc2\xb5\xc4\xbf?????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ?????\xc2\xb5\xc4\xbf?????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddExcavationRegion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "AddExcavationRegion", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddExcavationRegion_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddExcavationRegion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddExcavationRegion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddExcavationRegion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics
	{
		struct SuperMap_ExcavationInstance_eventAddWebExcavationRegion_Parms
		{
			TArray<FVector> arrPos;
			FString Tag;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_arrPos_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_arrPos;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Tag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::NewProp_arrPos_Inner = { "arrPos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::NewProp_arrPos = { "arrPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventAddWebExcavationRegion_Parms, arrPos), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventAddWebExcavationRegion_Parms, Tag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::NewProp_arrPos_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::NewProp_arrPos,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::NewProp_Tag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "// Web ????\xc8\xbe?\xd3\xbf?????\n//! \\brief ??????\xd0\xb1\xd1\xb9\xc6\xbd??\xce\xbb??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "Web ????\xc8\xbe?\xd3\xbf?????\n! \\brief ??????\xd0\xb1\xd1\xb9\xc6\xbd??\xce\xbb??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "AddWebExcavationRegion", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::SuperMap_ExcavationInstance_eventAddWebExcavationRegion_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics
	{
		struct SuperMap_ExcavationInstance_eventBuildExcavation_Parms
		{
			bool bExcavation;
		};
		static void NewProp_bExcavation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bExcavation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::NewProp_bExcavation_SetBit(void* Obj)
	{
		((SuperMap_ExcavationInstance_eventBuildExcavation_Parms*)Obj)->bExcavation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::NewProp_bExcavation = { "bExcavation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ExcavationInstance_eventBuildExcavation_Parms), &Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::NewProp_bExcavation_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::NewProp_bExcavation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7?????\n//! \\param bflatten [in] true??\xca\xbc\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7?????\n! \\param bflatten [in] true??\xca\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "BuildExcavation", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::SuperMap_ExcavationInstance_eventBuildExcavation_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_ClearModifyRegion_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_ClearModifyRegion_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_ClearModifyRegion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "ClearModifyRegion", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_ClearModifyRegion_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_ClearModifyRegion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_ClearModifyRegion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_ClearModifyRegion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics
	{
		struct SuperMap_ExcavationInstance_eventGetJsonArrayStringValue_Parms
		{
			FString Descriptor;
			FString FieldName;
			TArray<FVector> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Descriptor;
		static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::NewProp_Descriptor = { "Descriptor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventGetJsonArrayStringValue_Parms, Descriptor), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventGetJsonArrayStringValue_Parms, FieldName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventGetJsonArrayStringValue_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::NewProp_Descriptor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::NewProp_FieldName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ??????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ??????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "GetJsonArrayStringValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::SuperMap_ExcavationInstance_eventGetJsonArrayStringValue_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics
	{
		struct SuperMap_ExcavationInstance_eventIsChartlet_Parms
		{
			bool bChartlet;
		};
		static void NewProp_bChartlet_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bChartlet;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::NewProp_bChartlet_SetBit(void* Obj)
	{
		((SuperMap_ExcavationInstance_eventIsChartlet_Parms*)Obj)->bChartlet = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::NewProp_bChartlet = { "bChartlet", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ExcavationInstance_eventIsChartlet_Parms), &Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::NewProp_bChartlet_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::NewProp_bChartlet,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7???\xcd\xbc\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7???\xcd\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "IsChartlet", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::SuperMap_ExcavationInstance_eventIsChartlet_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics
	{
		struct SuperMap_ExcavationInstance_eventSelectLayer_Parms
		{
			FName strLayerName;
			bool IsSelect;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static void NewProp_IsSelect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSelect;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventSelectLayer_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::NewProp_IsSelect_SetBit(void* Obj)
	{
		((SuperMap_ExcavationInstance_eventSelectLayer_Parms*)Obj)->IsSelect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::NewProp_IsSelect = { "IsSelect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ExcavationInstance_eventSelectLayer_Parms), &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::NewProp_IsSelect_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::NewProp_strLayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::NewProp_IsSelect,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ????\xcd\xbc??\n//! true Terreain\n//! false S3M\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ????\xcd\xbc??\n! true Terreain\n! false S3M" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "SelectLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::SuperMap_ExcavationInstance_eventSelectLayer_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics
	{
		struct SuperMap_ExcavationInstance_eventSetExtendHeight_Parms
		{
			float height;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_height;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::NewProp_height = { "height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventSetExtendHeight_Parms, height), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::NewProp_height,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "SetExtendHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::SuperMap_ExcavationInstance_eventSetExtendHeight_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics
	{
		struct SuperMap_ExcavationInstance_eventSetInterpolatoryCount_Parms
		{
			int32 nCount;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nCount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::NewProp_nCount = { "nCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventSetInterpolatoryCount_Parms, nCount), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::NewProp_nCount,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ??\xd6\xb5??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ??\xd6\xb5??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "SetInterpolatoryCount", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::SuperMap_ExcavationInstance_eventSetInterpolatoryCount_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics
	{
		struct SuperMap_ExcavationInstance_eventSetModifyRegionMode_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventSetModifyRegionMode_Parms, type), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::NewProp_type,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ???\xda\xb7?\xca\xbd??0 ?? 1 ?\xe2\xa3\xa9\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ???\xda\xb7?\xca\xbd??0 ?? 1 ?\xe2\xa3\xa9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "SetModifyRegionMode", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::SuperMap_ExcavationInstance_eventSetModifyRegionMode_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics
	{
		struct SuperMap_ExcavationInstance_eventSetSideMaterialPath_Parms
		{
			FString filePath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventSetSideMaterialPath_Parms, filePath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::NewProp_filePath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "SetSideMaterialPath", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::SuperMap_ExcavationInstance_eventSetSideMaterialPath_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics
	{
		struct SuperMap_ExcavationInstance_eventSetSideTexture_Parms
		{
			FString filePath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventSetSideTexture_Parms, filePath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::NewProp_filePath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "SetSideTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::SuperMap_ExcavationInstance_eventSetSideTexture_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics
	{
		struct SuperMap_ExcavationInstance_eventSetTopMaterialPath_Parms
		{
			FString filePath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventSetTopMaterialPath_Parms, filePath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::NewProp_filePath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "SetTopMaterialPath", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::SuperMap_ExcavationInstance_eventSetTopMaterialPath_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics
	{
		struct SuperMap_ExcavationInstance_eventSetTopTexture_Parms
		{
			FString filePath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ExcavationInstance_eventSetTopTexture_Parms, filePath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::NewProp_filePath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "SetTopTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::SuperMap_ExcavationInstance_eventSetTopTexture_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics
	{
		struct SuperMap_ExcavationInstance_eventSetUseWeb_Parms
		{
			bool bUseWithoutWeb;
		};
		static void NewProp_bUseWithoutWeb_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseWithoutWeb;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::NewProp_bUseWithoutWeb_SetBit(void* Obj)
	{
		((SuperMap_ExcavationInstance_eventSetUseWeb_Parms*)Obj)->bUseWithoutWeb = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::NewProp_bUseWithoutWeb = { "bUseWithoutWeb", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ExcavationInstance_eventSetUseWeb_Parms), &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::NewProp_bUseWithoutWeb_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::NewProp_bUseWithoutWeb,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ExcavationInstance" },
		{ "Comment", "//! \\brief ?????\xc7\xb7?\xca\xb9??????\xc8\xbe\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ToolTip", "! \\brief ?????\xc7\xb7?\xca\xb9??????\xc8\xbe" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ExcavationInstance, nullptr, "SetUseWeb", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::SuperMap_ExcavationInstance_eventSetUseWeb_Parms), Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ExcavationInstance);
	UClass* Z_Construct_UClass_ASuperMap_ExcavationInstance_NoRegister()
	{
		return ASuperMap_ExcavationInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ExcavationInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ExcavationInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_ExcavationInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddExcavationRegion, "AddExcavationRegion" }, // 249854798
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_AddWebExcavationRegion, "AddWebExcavationRegion" }, // 2470467027
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_BuildExcavation, "BuildExcavation" }, // 685101294
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_ClearModifyRegion, "ClearModifyRegion" }, // 1375372665
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_GetJsonArrayStringValue, "GetJsonArrayStringValue" }, // 1177510702
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_IsChartlet, "IsChartlet" }, // 1133098406
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SelectLayer, "SelectLayer" }, // 735906727
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetExtendHeight, "SetExtendHeight" }, // 3560152671
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetInterpolatoryCount, "SetInterpolatoryCount" }, // 701063846
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetModifyRegionMode, "SetModifyRegionMode" }, // 587495597
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideMaterialPath, "SetSideMaterialPath" }, // 3517450026
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetSideTexture, "SetSideTexture" }, // 334201797
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopMaterialPath, "SetTopMaterialPath" }, // 654359106
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetTopTexture, "SetTopTexture" }, // 2871050804
		{ &Z_Construct_UFunction_ASuperMap_ExcavationInstance_SetUseWeb, "SetUseWeb" }, // 1171771265
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ExcavationInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SceneOperation/SuperMap_ExcavationInstance.h" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ExcavationInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ExcavationInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ExcavationInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ExcavationInstance_Statics::ClassParams = {
		&ASuperMap_ExcavationInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ExcavationInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ExcavationInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ExcavationInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ExcavationInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ExcavationInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_ExcavationInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ExcavationInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_ExcavationInstance>()
	{
		return ASuperMap_ExcavationInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ExcavationInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ExcavationInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ExcavationInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ExcavationInstance, ASuperMap_ExcavationInstance::StaticClass, TEXT("ASuperMap_ExcavationInstance"), &Z_Registration_Info_UClass_ASuperMap_ExcavationInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ExcavationInstance), 3551685936U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ExcavationInstance_h_842304126(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ExcavationInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ExcavationInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
