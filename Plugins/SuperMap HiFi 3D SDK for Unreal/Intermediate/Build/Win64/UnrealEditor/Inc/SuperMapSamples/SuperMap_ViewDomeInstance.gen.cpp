// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ViewDomeInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ViewDemoDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ViewDomeInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ViewDomeInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_ViewDemoDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_ViewDemoDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_ViewDemoDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "ViewDemoDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_ViewDemoDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_ViewDemoDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ViewDemoDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_ViewDemoDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_ViewDomeInstance::execGetViewerPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetViewerPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewDomeInstance::execSetViewerPosition)
	{
		P_GET_STRUCT(FVector,Z_Param_pos);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewerPosition(Z_Param_pos);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewDomeInstance::execGetViewDomeDistance)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetViewDomeDistance();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewDomeInstance::execSetViewDomeDistance)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fDistance);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewDomeDistance(Z_Param_fDistance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewDomeInstance::execGetViewDomeType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetViewDomeType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewDomeInstance::execSetViewDomeType)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_type);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewDomeType(Z_Param_type);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewDomeInstance::execGetViewDomeDisplayStyle)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetViewDomeDisplayStyle();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewDomeInstance::execSetViewDomeDisplayStyle)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_type);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewDomeDisplayStyle(Z_Param_type);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewDomeInstance::execBuildViewDome)
	{
		P_GET_UBOOL(Z_Param_bViewDome);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildViewDome(Z_Param_bViewDome);
		P_NATIVE_END;
	}
	void ASuperMap_ViewDomeInstance::StaticRegisterNativesASuperMap_ViewDomeInstance()
	{
		UClass* Class = ASuperMap_ViewDomeInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildViewDome", &ASuperMap_ViewDomeInstance::execBuildViewDome },
			{ "GetViewDomeDisplayStyle", &ASuperMap_ViewDomeInstance::execGetViewDomeDisplayStyle },
			{ "GetViewDomeDistance", &ASuperMap_ViewDomeInstance::execGetViewDomeDistance },
			{ "GetViewDomeType", &ASuperMap_ViewDomeInstance::execGetViewDomeType },
			{ "GetViewerPosition", &ASuperMap_ViewDomeInstance::execGetViewerPosition },
			{ "SetViewDomeDisplayStyle", &ASuperMap_ViewDomeInstance::execSetViewDomeDisplayStyle },
			{ "SetViewDomeDistance", &ASuperMap_ViewDomeInstance::execSetViewDomeDistance },
			{ "SetViewDomeType", &ASuperMap_ViewDomeInstance::execSetViewDomeType },
			{ "SetViewerPosition", &ASuperMap_ViewDomeInstance::execSetViewerPosition },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics
	{
		struct SuperMap_ViewDomeInstance_eventBuildViewDome_Parms
		{
			bool bViewDome;
		};
		static void NewProp_bViewDome_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bViewDome;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::NewProp_bViewDome_SetBit(void* Obj)
	{
		((SuperMap_ViewDomeInstance_eventBuildViewDome_Parms*)Obj)->bViewDome = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::NewProp_bViewDome = { "bViewDome", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ViewDomeInstance_eventBuildViewDome_Parms), &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::NewProp_bViewDome_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::NewProp_bViewDome,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewDomeInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7\xf1\xbf\xaa\xb3??\xc8\xb7???\n//! \\param bclip [in] true??\xca\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7\xf1\xbf\xaa\xb3??\xc8\xb7???\n! \\param bclip [in] true??\xca\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewDomeInstance, nullptr, "BuildViewDome", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::SuperMap_ViewDomeInstance_eventBuildViewDome_Parms), Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics
	{
		struct SuperMap_ViewDomeInstance_eventGetViewDomeDisplayStyle_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ViewDomeInstance_eventGetViewDomeDisplayStyle_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewDomeInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1?????\xc8\xb5???\xca\xbe\xc4\xa3\xca\xbd???\xdf\xa3????\xe4\xa3\xac?\xcf\xa3?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1?????\xc8\xb5???\xca\xbe\xc4\xa3\xca\xbd???\xdf\xa3????\xe4\xa3\xac?\xcf\xa3?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewDomeInstance, nullptr, "GetViewDomeDisplayStyle", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::SuperMap_ViewDomeInstance_eventGetViewDomeDisplayStyle_Parms), Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics
	{
		struct SuperMap_ViewDomeInstance_eventGetViewDomeDistance_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ViewDomeInstance_eventGetViewDomeDistance_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewDomeInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1???\xd3\xbe???????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1???\xd3\xbe???????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewDomeInstance, nullptr, "GetViewDomeDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::SuperMap_ViewDomeInstance_eventGetViewDomeDistance_Parms), Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics
	{
		struct SuperMap_ViewDomeInstance_eventGetViewDomeType_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ViewDomeInstance_eventGetViewDomeType_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewDomeInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1?????\xc8\xb5\xc4\xbd??????\xcd\xa3???\xca\xbe???\xd3\xa1??????\xd3\xb2??\xd6\xa3?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1?????\xc8\xb5\xc4\xbd??????\xcd\xa3???\xca\xbe???\xd3\xa1??????\xd3\xb2??\xd6\xa3?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewDomeInstance, nullptr, "GetViewDomeType", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::SuperMap_ViewDomeInstance_eventGetViewDomeType_Parms), Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics
	{
		struct SuperMap_ViewDomeInstance_eventGetViewerPosition_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ViewDomeInstance_eventGetViewerPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewDomeInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1?\xd3\xb5?\xce\xbb??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1?\xd3\xb5?\xce\xbb??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewDomeInstance, nullptr, "GetViewerPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::SuperMap_ViewDomeInstance_eventGetViewerPosition_Parms), Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics
	{
		struct SuperMap_ViewDomeInstance_eventSetViewDomeDisplayStyle_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ViewDomeInstance_eventSetViewDomeDisplayStyle_Parms, type), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::NewProp_type,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewDomeInstance" },
		{ "Comment", "//! \\brief ???\xc3\xbf????\xc8\xb5???\xca\xbe\xc4\xa3\xca\xbd???\xdf\xa3????\xe4\xa3\xac?\xcf\xa3?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xbf????\xc8\xb5???\xca\xbe\xc4\xa3\xca\xbd???\xdf\xa3????\xe4\xa3\xac?\xcf\xa3?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewDomeInstance, nullptr, "SetViewDomeDisplayStyle", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::SuperMap_ViewDomeInstance_eventSetViewDomeDisplayStyle_Parms), Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics
	{
		struct SuperMap_ViewDomeInstance_eventSetViewDomeDistance_Parms
		{
			float fDistance;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fDistance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::NewProp_fDistance = { "fDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ViewDomeInstance_eventSetViewDomeDistance_Parms, fDistance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::NewProp_fDistance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewDomeInstance" },
		{ "Comment", "//! \\brief ???\xc3\xbf??\xd3\xbe???????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xbf??\xd3\xbe???????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewDomeInstance, nullptr, "SetViewDomeDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::SuperMap_ViewDomeInstance_eventSetViewDomeDistance_Parms), Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics
	{
		struct SuperMap_ViewDomeInstance_eventSetViewDomeType_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ViewDomeInstance_eventSetViewDomeType_Parms, type), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::NewProp_type,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewDomeInstance" },
		{ "Comment", "//! \\brief ???\xc3\xbf????\xc8\xb5\xc4\xbd??????\xcd\xa3???\xca\xbe???\xd3\xa1??????\xd3\xb2??\xd6\xa3?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xbf????\xc8\xb5\xc4\xbd??????\xcd\xa3???\xca\xbe???\xd3\xa1??????\xd3\xb2??\xd6\xa3?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewDomeInstance, nullptr, "SetViewDomeType", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::SuperMap_ViewDomeInstance_eventSetViewDomeType_Parms), Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics
	{
		struct SuperMap_ViewDomeInstance_eventSetViewerPosition_Parms
		{
			FVector pos;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_pos;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::NewProp_pos = { "pos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ViewDomeInstance_eventSetViewerPosition_Parms, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::NewProp_pos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewDomeInstance" },
		{ "Comment", "//! \\brief ?????\xd3\xb5?\xce\xbb??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ToolTip", "! \\brief ?????\xd3\xb5?\xce\xbb??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewDomeInstance, nullptr, "SetViewerPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::SuperMap_ViewDomeInstance_eventSetViewerPosition_Parms), Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ViewDomeInstance);
	UClass* Z_Construct_UClass_ASuperMap_ViewDomeInstance_NoRegister()
	{
		return ASuperMap_ViewDomeInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventViewDemo_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_EventViewDemo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_BuildViewDome, "BuildViewDome" }, // 3975910867
		{ &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDisplayStyle, "GetViewDomeDisplayStyle" }, // 642543788
		{ &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeDistance, "GetViewDomeDistance" }, // 1135033554
		{ &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewDomeType, "GetViewDomeType" }, // 2181970270
		{ &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_GetViewerPosition, "GetViewerPosition" }, // 2917395087
		{ &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDisplayStyle, "SetViewDomeDisplayStyle" }, // 3540079021
		{ &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeDistance, "SetViewDomeDistance" }, // 2634367736
		{ &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewDomeType, "SetViewDomeType" }, // 918203454
		{ &Z_Construct_UFunction_ASuperMap_ViewDomeInstance_SetViewerPosition, "SetViewerPosition" }, // 652439069
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::NewProp_EventViewDemo_MetaData[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewDomeInstance.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::NewProp_EventViewDemo = { "EventViewDemo", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_ViewDomeInstance, EventViewDemo), Z_Construct_UDelegateFunction_SuperMapSamples_ViewDemoDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::NewProp_EventViewDemo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::NewProp_EventViewDemo_MetaData)) }; // 4003958588
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::NewProp_EventViewDemo,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ViewDomeInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::ClassParams = {
		&ASuperMap_ViewDomeInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ViewDomeInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ViewDomeInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ViewDomeInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_ViewDomeInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ViewDomeInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_ViewDomeInstance>()
	{
		return ASuperMap_ViewDomeInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ViewDomeInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewDomeInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewDomeInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ViewDomeInstance, ASuperMap_ViewDomeInstance::StaticClass, TEXT("ASuperMap_ViewDomeInstance"), &Z_Registration_Info_UClass_ASuperMap_ViewDomeInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ViewDomeInstance), 1083524661U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewDomeInstance_h_3853488102(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewDomeInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewDomeInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
