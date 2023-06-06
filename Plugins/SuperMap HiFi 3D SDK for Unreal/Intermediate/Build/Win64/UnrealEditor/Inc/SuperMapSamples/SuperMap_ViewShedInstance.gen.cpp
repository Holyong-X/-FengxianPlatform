// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_ViewShedInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ViewShedInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ViewShedDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ViewShedInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ViewShedInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_ViewShedDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_ViewShedDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewShedInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_ViewShedDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "ViewShedDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_ViewShedDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_ViewShedDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ViewShedDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_ViewShedDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_ViewShedInstance::execSetViewShedGeoLine)
	{
		P_GET_UBOOL(Z_Param_bVisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewShedGeoLine(Z_Param_bVisible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewShedInstance::execSetViewShedHiddenBody)
	{
		P_GET_UBOOL(Z_Param_bVisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewShedHiddenBody(Z_Param_bVisible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewShedInstance::execSetViewShedVisibleBody)
	{
		P_GET_UBOOL(Z_Param_bVisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewShedVisibleBody(Z_Param_bVisible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewShedInstance::execIsShowViewerPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsShowViewerPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewShedInstance::execGetViewerPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetViewerPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ViewShedInstance::execSetIsViewShed)
	{
		P_GET_UBOOL(Z_Param_bViewShed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsViewShed(Z_Param_bViewShed);
		P_NATIVE_END;
	}
	void ASuperMap_ViewShedInstance::StaticRegisterNativesASuperMap_ViewShedInstance()
	{
		UClass* Class = ASuperMap_ViewShedInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetViewerPosition", &ASuperMap_ViewShedInstance::execGetViewerPosition },
			{ "IsShowViewerPosition", &ASuperMap_ViewShedInstance::execIsShowViewerPosition },
			{ "SetIsViewShed", &ASuperMap_ViewShedInstance::execSetIsViewShed },
			{ "SetViewShedGeoLine", &ASuperMap_ViewShedInstance::execSetViewShedGeoLine },
			{ "SetViewShedHiddenBody", &ASuperMap_ViewShedInstance::execSetViewShedHiddenBody },
			{ "SetViewShedVisibleBody", &ASuperMap_ViewShedInstance::execSetViewShedVisibleBody },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics
	{
		struct SuperMap_ViewShedInstance_eventGetViewerPosition_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ViewShedInstance_eventGetViewerPosition_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewShedInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewShedInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewShedInstance, nullptr, "GetViewerPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::SuperMap_ViewShedInstance_eventGetViewerPosition_Parms), Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics
	{
		struct SuperMap_ViewShedInstance_eventIsShowViewerPosition_Parms
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
	void Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_ViewShedInstance_eventIsShowViewerPosition_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ViewShedInstance_eventIsShowViewerPosition_Parms), &Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewShedInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewShedInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewShedInstance, nullptr, "IsShowViewerPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::SuperMap_ViewShedInstance_eventIsShowViewerPosition_Parms), Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics
	{
		struct SuperMap_ViewShedInstance_eventSetIsViewShed_Parms
		{
			bool bViewShed;
		};
		static void NewProp_bViewShed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bViewShed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::NewProp_bViewShed_SetBit(void* Obj)
	{
		((SuperMap_ViewShedInstance_eventSetIsViewShed_Parms*)Obj)->bViewShed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::NewProp_bViewShed = { "bViewShed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ViewShedInstance_eventSetIsViewShed_Parms), &Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::NewProp_bViewShed_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::NewProp_bViewShed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewShedInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7???????????\n//! \\param bclip [in] true??\xca\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewShedInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7???????????\n! \\param bclip [in] true??\xca\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewShedInstance, nullptr, "SetIsViewShed", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::SuperMap_ViewShedInstance_eventSetIsViewShed_Parms), Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics
	{
		struct SuperMap_ViewShedInstance_eventSetViewShedGeoLine_Parms
		{
			bool bVisible;
		};
		static void NewProp_bVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::NewProp_bVisible_SetBit(void* Obj)
	{
		((SuperMap_ViewShedInstance_eventSetViewShedGeoLine_Parms*)Obj)->bVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ViewShedInstance_eventSetViewShedGeoLine_Parms), &Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::NewProp_bVisible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewShedInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewShedInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewShedInstance, nullptr, "SetViewShedGeoLine", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::SuperMap_ViewShedInstance_eventSetViewShedGeoLine_Parms), Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics
	{
		struct SuperMap_ViewShedInstance_eventSetViewShedHiddenBody_Parms
		{
			bool bVisible;
		};
		static void NewProp_bVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::NewProp_bVisible_SetBit(void* Obj)
	{
		((SuperMap_ViewShedInstance_eventSetViewShedHiddenBody_Parms*)Obj)->bVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ViewShedInstance_eventSetViewShedHiddenBody_Parms), &Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::NewProp_bVisible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewShedInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewShedInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewShedInstance, nullptr, "SetViewShedHiddenBody", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::SuperMap_ViewShedInstance_eventSetViewShedHiddenBody_Parms), Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics
	{
		struct SuperMap_ViewShedInstance_eventSetViewShedVisibleBody_Parms
		{
			bool bVisible;
		};
		static void NewProp_bVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::NewProp_bVisible_SetBit(void* Obj)
	{
		((SuperMap_ViewShedInstance_eventSetViewShedVisibleBody_Parms*)Obj)->bVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ViewShedInstance_eventSetViewShedVisibleBody_Parms), &Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::NewProp_bVisible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ViewShedInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewShedInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ViewShedInstance, nullptr, "SetViewShedVisibleBody", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::SuperMap_ViewShedInstance_eventSetViewShedVisibleBody_Parms), Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ViewShedInstance);
	UClass* Z_Construct_UClass_ASuperMap_ViewShedInstance_NoRegister()
	{
		return ASuperMap_ViewShedInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallViewShed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallViewShed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_ViewShedInstance_GetViewerPosition, "GetViewerPosition" }, // 3836197317
		{ &Z_Construct_UFunction_ASuperMap_ViewShedInstance_IsShowViewerPosition, "IsShowViewerPosition" }, // 3802016756
		{ &Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetIsViewShed, "SetIsViewShed" }, // 1689462314
		{ &Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedGeoLine, "SetViewShedGeoLine" }, // 25747751
		{ &Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedHiddenBody, "SetViewShedHiddenBody" }, // 2073996423
		{ &Z_Construct_UFunction_ASuperMap_ViewShedInstance_SetViewShedVisibleBody, "SetViewShedVisibleBody" }, // 2396274646
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_ViewShedInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewShedInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::NewProp_CallViewShed_MetaData[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ViewShedInstance.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::NewProp_CallViewShed = { "CallViewShed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_ViewShedInstance, CallViewShed), Z_Construct_UDelegateFunction_SuperMapSamples_ViewShedDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::NewProp_CallViewShed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::NewProp_CallViewShed_MetaData)) }; // 1249218980
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::NewProp_CallViewShed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ViewShedInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::ClassParams = {
		&ASuperMap_ViewShedInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ViewShedInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ViewShedInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ViewShedInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_ViewShedInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ViewShedInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_ViewShedInstance>()
	{
		return ASuperMap_ViewShedInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ViewShedInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewShedInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewShedInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ViewShedInstance, ASuperMap_ViewShedInstance::StaticClass, TEXT("ASuperMap_ViewShedInstance"), &Z_Registration_Info_UClass_ASuperMap_ViewShedInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ViewShedInstance), 201969937U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewShedInstance_h_2243628479(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewShedInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ViewShedInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
