// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ClipBoxInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ClipboxDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ClipBoxInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ClipBoxInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_ClipboxDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_ClipboxDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_ClipboxDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "ClipboxDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_ClipboxDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_ClipboxDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ClipboxDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_ClipboxDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetIsWebUI)
	{
		P_GET_UBOOL(Z_Param_bWebUI);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsWebUI(Z_Param_bWebUI);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execClipGeoBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClipGeoBox();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetbDrawBox)
	{
		P_GET_UBOOL(Z_Param_bBox);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetbDrawBox(Z_Param_bBox);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execGetbDrawBox)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetbDrawBox();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSelectLayer3D)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_nLayer);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectLayer3D(Z_Param_nLayer);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execGetClipHeight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetClipHeight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execGetClipWidth)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetClipWidth();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execGetClipLength)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetClipLength();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execGetClipCenterZ)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetClipCenterZ();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetClipCenterZ)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_height);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClipCenterZ(Z_Param_height);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetClipHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_height);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClipHeight(Z_Param_height);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetClipWidth)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_width);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClipWidth(Z_Param_width);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetClipLength)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_length);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClipLength(Z_Param_length);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execGetClipCenter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetClipCenter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetClipCenter)
	{
		P_GET_STRUCT(FVector,Z_Param_vPos);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClipCenter(Z_Param_vPos);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetClipOpacity)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_opacity);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClipOpacity(Z_Param_opacity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetClipMode)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClipMode(Z_Param_mode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetClipBoxMode)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClipBoxMode(Z_Param_mode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClipBoxInstance::execSetIsClip)
	{
		P_GET_UBOOL(Z_Param_bclip);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsClip(Z_Param_bclip);
		P_NATIVE_END;
	}
	void ASuperMap_ClipBoxInstance::StaticRegisterNativesASuperMap_ClipBoxInstance()
	{
		UClass* Class = ASuperMap_ClipBoxInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ClipGeoBox", &ASuperMap_ClipBoxInstance::execClipGeoBox },
			{ "GetbDrawBox", &ASuperMap_ClipBoxInstance::execGetbDrawBox },
			{ "GetClipCenter", &ASuperMap_ClipBoxInstance::execGetClipCenter },
			{ "GetClipCenterZ", &ASuperMap_ClipBoxInstance::execGetClipCenterZ },
			{ "GetClipHeight", &ASuperMap_ClipBoxInstance::execGetClipHeight },
			{ "GetClipLength", &ASuperMap_ClipBoxInstance::execGetClipLength },
			{ "GetClipWidth", &ASuperMap_ClipBoxInstance::execGetClipWidth },
			{ "SelectLayer3D", &ASuperMap_ClipBoxInstance::execSelectLayer3D },
			{ "SetbDrawBox", &ASuperMap_ClipBoxInstance::execSetbDrawBox },
			{ "SetClipBoxMode", &ASuperMap_ClipBoxInstance::execSetClipBoxMode },
			{ "SetClipCenter", &ASuperMap_ClipBoxInstance::execSetClipCenter },
			{ "SetClipCenterZ", &ASuperMap_ClipBoxInstance::execSetClipCenterZ },
			{ "SetClipHeight", &ASuperMap_ClipBoxInstance::execSetClipHeight },
			{ "SetClipLength", &ASuperMap_ClipBoxInstance::execSetClipLength },
			{ "SetClipMode", &ASuperMap_ClipBoxInstance::execSetClipMode },
			{ "SetClipOpacity", &ASuperMap_ClipBoxInstance::execSetClipOpacity },
			{ "SetClipWidth", &ASuperMap_ClipBoxInstance::execSetClipWidth },
			{ "SetIsClip", &ASuperMap_ClipBoxInstance::execSetIsClip },
			{ "SetIsWebUI", &ASuperMap_ClipBoxInstance::execSetIsWebUI },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_ClipGeoBox_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_ClipGeoBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//\xe4\xba\x91\xe6\xb8\xb2\xe6\x9f\x93\xe4\xbc\x9a\xe4\xbd\xbf\xe7\x94\xa8\n//! \\brief \n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "\xe4\xba\x91\xe6\xb8\xb2\xe6\x9f\x93\xe4\xbc\x9a\xe4\xbd\xbf\xe7\x94\xa8\n! \\brief" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_ClipGeoBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "ClipGeoBox", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_ClipGeoBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_ClipGeoBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_ClipGeoBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_ClipGeoBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics
	{
		struct SuperMap_ClipBoxInstance_eventGetbDrawBox_Parms
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
	void Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_ClipBoxInstance_eventGetbDrawBox_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ClipBoxInstance_eventGetbDrawBox_Parms), &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe7\xbb\x98\xe5\x88\xb6\xe5\xa5\xbd""box\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe7\xbb\x98\xe5\x88\xb6\xe5\xa5\xbd""box" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "GetbDrawBox", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::SuperMap_ClipBoxInstance_eventGetbDrawBox_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics
	{
		struct SuperMap_ClipBoxInstance_eventGetClipCenter_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventGetClipCenter_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe4\xb8\xad\xe5\xbf\x83\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe4\xb8\xad\xe5\xbf\x83\xe7\x82\xb9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "GetClipCenter", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::SuperMap_ClipBoxInstance_eventGetClipCenter_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics
	{
		struct SuperMap_ClipBoxInstance_eventGetClipCenterZ_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventGetClipCenterZ_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\xba\x95\xe9\x9d\xa2\xe9\xab\x98\xe7\xa8\x8b\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\xba\x95\xe9\x9d\xa2\xe9\xab\x98\xe7\xa8\x8b" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "GetClipCenterZ", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::SuperMap_ClipBoxInstance_eventGetClipCenterZ_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics
	{
		struct SuperMap_ClipBoxInstance_eventGetClipHeight_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventGetClipHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe9\xab\x98\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe9\xab\x98\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "GetClipHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::SuperMap_ClipBoxInstance_eventGetClipHeight_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics
	{
		struct SuperMap_ClipBoxInstance_eventGetClipLength_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventGetClipLength_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe9\x95\xbf\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe9\x95\xbf\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "GetClipLength", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::SuperMap_ClipBoxInstance_eventGetClipLength_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics
	{
		struct SuperMap_ClipBoxInstance_eventGetClipWidth_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventGetClipWidth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\xae\xbd\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\xae\xbd\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "GetClipWidth", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::SuperMap_ClipBoxInstance_eventGetClipWidth_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSelectLayer3D_Parms
		{
			FName nLayer;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_nLayer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::NewProp_nLayer = { "nLayer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventSelectLayer3D_Parms, nLayer), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::NewProp_nLayer,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SelectLayer3D", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::SuperMap_ClipBoxInstance_eventSelectLayer3D_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetbDrawBox_Parms
		{
			bool bBox;
		};
		static void NewProp_bBox_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bBox;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::NewProp_bBox_SetBit(void* Obj)
	{
		((SuperMap_ClipBoxInstance_eventSetbDrawBox_Parms*)Obj)->bBox = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::NewProp_bBox = { "bBox", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ClipBoxInstance_eventSetbDrawBox_Parms), &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::NewProp_bBox_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::NewProp_bBox,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetbDrawBox", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::SuperMap_ClipBoxInstance_eventSetbDrawBox_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetClipBoxMode_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::NewProp_mode = { "mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventSetClipBoxMode_Parms, mode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::NewProp_mode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe8\xa3\x81\xe5\x89\xaa\xe6\x96\xb9\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe8\xa3\x81\xe5\x89\xaa\xe6\x96\xb9\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetClipBoxMode", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::SuperMap_ClipBoxInstance_eventSetClipBoxMode_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetClipCenter_Parms
		{
			FVector vPos;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_vPos;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::NewProp_vPos = { "vPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventSetClipCenter_Parms, vPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::NewProp_vPos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xad\xe5\xbf\x83\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xad\xe5\xbf\x83\xe7\x82\xb9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetClipCenter", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::SuperMap_ClipBoxInstance_eventSetClipCenter_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetClipCenterZ_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::NewProp_height = { "height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventSetClipCenterZ_Parms, height), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::NewProp_height,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xba\x95\xe9\x9d\xa2\xe9\xab\x98\xe7\xa8\x8b\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xba\x95\xe9\x9d\xa2\xe9\xab\x98\xe7\xa8\x8b" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetClipCenterZ", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::SuperMap_ClipBoxInstance_eventSetClipCenterZ_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetClipHeight_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::NewProp_height = { "height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventSetClipHeight_Parms, height), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::NewProp_height,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe9\xab\x98\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe9\xab\x98\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetClipHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::SuperMap_ClipBoxInstance_eventSetClipHeight_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetClipLength_Parms
		{
			float length;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_length;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::NewProp_length = { "length", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventSetClipLength_Parms, length), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::NewProp_length,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe9\x95\xbf\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe9\x95\xbf\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetClipLength", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::SuperMap_ClipBoxInstance_eventSetClipLength_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetClipMode_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::NewProp_mode = { "mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventSetClipMode_Parms, mode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::NewProp_mode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe6\x98\xbe\xe7\xa4\xba\xe6\x96\xb9\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe6\x98\xbe\xe7\xa4\xba\xe6\x96\xb9\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetClipMode", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::SuperMap_ClipBoxInstance_eventSetClipMode_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetClipOpacity_Parms
		{
			float opacity;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_opacity;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::NewProp_opacity = { "opacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventSetClipOpacity_Parms, opacity), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::NewProp_opacity,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetClipOpacity", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::SuperMap_ClipBoxInstance_eventSetClipOpacity_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetClipWidth_Parms
		{
			float width;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_width;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::NewProp_width = { "width", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClipBoxInstance_eventSetClipWidth_Parms, width), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::NewProp_width,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xae\xbd\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xae\xbd\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetClipWidth", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::SuperMap_ClipBoxInstance_eventSetClipWidth_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetIsClip_Parms
		{
			bool bclip;
		};
		static void NewProp_bclip_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bclip;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::NewProp_bclip_SetBit(void* Obj)
	{
		((SuperMap_ClipBoxInstance_eventSetIsClip_Parms*)Obj)->bclip = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::NewProp_bclip = { "bclip", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ClipBoxInstance_eventSetIsClip_Parms), &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::NewProp_bclip_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::NewProp_bclip,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe8\xa3\x81\xe5\x89\xaa\n//! \\param bclip [in] true\xe5\xbc\x80\xe5\xa7\x8b\xe8\xa3\x81\xe5\x89\xaa\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe8\xa3\x81\xe5\x89\xaa\n! \\param bclip [in] true\xe5\xbc\x80\xe5\xa7\x8b\xe8\xa3\x81\xe5\x89\xaa" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetIsClip", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::SuperMap_ClipBoxInstance_eventSetIsClip_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics
	{
		struct SuperMap_ClipBoxInstance_eventSetIsWebUI_Parms
		{
			bool bWebUI;
		};
		static void NewProp_bWebUI_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWebUI;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::NewProp_bWebUI_SetBit(void* Obj)
	{
		((SuperMap_ClipBoxInstance_eventSetIsWebUI_Parms*)Obj)->bWebUI = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::NewProp_bWebUI = { "bWebUI", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ClipBoxInstance_eventSetIsWebUI_Parms), &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::NewProp_bWebUI_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::NewProp_bWebUI,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClipBoxInstance" },
		{ "Comment", "//! \\brief \n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ToolTip", "! \\brief" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClipBoxInstance, nullptr, "SetIsWebUI", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::SuperMap_ClipBoxInstance_eventSetIsWebUI_Parms), Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ClipBoxInstance);
	UClass* Z_Construct_UClass_ASuperMap_ClipBoxInstance_NoRegister()
	{
		return ASuperMap_ClipBoxInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallClipBox_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallClipBox;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_ClipGeoBox, "ClipGeoBox" }, // 701422296
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetbDrawBox, "GetbDrawBox" }, // 4242324627
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenter, "GetClipCenter" }, // 4067617775
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipCenterZ, "GetClipCenterZ" }, // 2818148752
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipHeight, "GetClipHeight" }, // 266319587
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipLength, "GetClipLength" }, // 1955060384
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_GetClipWidth, "GetClipWidth" }, // 370454413
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SelectLayer3D, "SelectLayer3D" }, // 2482486738
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetbDrawBox, "SetbDrawBox" }, // 2608713296
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipBoxMode, "SetClipBoxMode" }, // 1803708053
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenter, "SetClipCenter" }, // 3469485022
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipCenterZ, "SetClipCenterZ" }, // 1876037761
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipHeight, "SetClipHeight" }, // 3538835013
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipLength, "SetClipLength" }, // 2448944291
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipMode, "SetClipMode" }, // 721349944
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipOpacity, "SetClipOpacity" }, // 674525060
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetClipWidth, "SetClipWidth" }, // 2845407842
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsClip, "SetIsClip" }, // 1562929974
		{ &Z_Construct_UFunction_ASuperMap_ClipBoxInstance_SetIsWebUI, "SetIsWebUI" }, // 3543206048
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::NewProp_CallClipBox_MetaData[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClipBoxInstance.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::NewProp_CallClipBox = { "CallClipBox", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_ClipBoxInstance, CallClipBox), Z_Construct_UDelegateFunction_SuperMapSamples_ClipboxDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::NewProp_CallClipBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::NewProp_CallClipBox_MetaData)) }; // 1974638922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::NewProp_CallClipBox,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ClipBoxInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::ClassParams = {
		&ASuperMap_ClipBoxInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ClipBoxInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ClipBoxInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ClipBoxInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_ClipBoxInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ClipBoxInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_ClipBoxInstance>()
	{
		return ASuperMap_ClipBoxInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ClipBoxInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClipBoxInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClipBoxInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ClipBoxInstance, ASuperMap_ClipBoxInstance::StaticClass, TEXT("ASuperMap_ClipBoxInstance"), &Z_Registration_Info_UClass_ASuperMap_ClipBoxInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ClipBoxInstance), 3022682181U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClipBoxInstance_h_1920981261(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClipBoxInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClipBoxInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
