// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/HandlerSamples/SuperMap_MeasureHandler.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_MeasureHandler() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_LayerDeleteDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_MeasureHandler_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_MeasureHandler();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_LayerDeleteDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_LayerDeleteDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HandlerSamples/SuperMap_MeasureHandler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_LayerDeleteDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "LayerDeleteDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_LayerDeleteDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_LayerDeleteDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_LayerDeleteDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_LayerDeleteDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_MeasureHandler::execGetCurrentState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetCurrentState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MeasureHandler::execHypsometricSetting)
	{
		P_GET_UBOOL(Z_Param_IsHyp);
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HypsometricSetting(Z_Param_IsHyp,Z_Param_strLayerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MeasureHandler::execGetMeasureResult)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMeasureResult();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MeasureHandler::execSetMeasureAction)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMeasureAction(Z_Param_mode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MeasureHandler::execSetIsMeasureHandler)
	{
		P_GET_UBOOL(Z_Param_bmeasureHandler);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsMeasureHandler(Z_Param_bmeasureHandler);
		P_NATIVE_END;
	}
	void ASuperMap_MeasureHandler::StaticRegisterNativesASuperMap_MeasureHandler()
	{
		UClass* Class = ASuperMap_MeasureHandler::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCurrentState", &ASuperMap_MeasureHandler::execGetCurrentState },
			{ "GetMeasureResult", &ASuperMap_MeasureHandler::execGetMeasureResult },
			{ "HypsometricSetting", &ASuperMap_MeasureHandler::execHypsometricSetting },
			{ "SetIsMeasureHandler", &ASuperMap_MeasureHandler::execSetIsMeasureHandler },
			{ "SetMeasureAction", &ASuperMap_MeasureHandler::execSetMeasureAction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics
	{
		struct SuperMap_MeasureHandler_eventGetCurrentState_Parms
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
	void Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_MeasureHandler_eventGetCurrentState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MeasureHandler_eventGetCurrentState_Parms), &Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MeasureHandler" },
		{ "Comment", "//! \\brief ??\xc8\xa1??\xc7\xb0\xd7\xb4\xcc\xac\n" },
		{ "ModuleRelativePath", "Public/HandlerSamples/SuperMap_MeasureHandler.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1??\xc7\xb0\xd7\xb4\xcc\xac" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MeasureHandler, nullptr, "GetCurrentState", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::SuperMap_MeasureHandler_eventGetCurrentState_Parms), Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics
	{
		struct SuperMap_MeasureHandler_eventGetMeasureResult_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MeasureHandler_eventGetMeasureResult_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MeasureHandler" },
		{ "Comment", "//! \\brief ???\xc3\xbd???\n" },
		{ "ModuleRelativePath", "Public/HandlerSamples/SuperMap_MeasureHandler.h" },
		{ "ToolTip", "! \\brief ???\xc3\xbd???" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MeasureHandler, nullptr, "GetMeasureResult", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::SuperMap_MeasureHandler_eventGetMeasureResult_Parms), Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics
	{
		struct SuperMap_MeasureHandler_eventHypsometricSetting_Parms
		{
			bool IsHyp;
			FName strLayerName;
		};
		static void NewProp_IsHyp_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsHyp;
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::NewProp_IsHyp_SetBit(void* Obj)
	{
		((SuperMap_MeasureHandler_eventHypsometricSetting_Parms*)Obj)->IsHyp = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::NewProp_IsHyp = { "IsHyp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MeasureHandler_eventHypsometricSetting_Parms), &Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::NewProp_IsHyp_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MeasureHandler_eventHypsometricSetting_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::NewProp_IsHyp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::NewProp_strLayerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MeasureHandler" },
		{ "Comment", "//! \\brief ?????\xc8\xb8???\n" },
		{ "ModuleRelativePath", "Public/HandlerSamples/SuperMap_MeasureHandler.h" },
		{ "ToolTip", "! \\brief ?????\xc8\xb8???" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MeasureHandler, nullptr, "HypsometricSetting", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::SuperMap_MeasureHandler_eventHypsometricSetting_Parms), Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics
	{
		struct SuperMap_MeasureHandler_eventSetIsMeasureHandler_Parms
		{
			bool bmeasureHandler;
		};
		static void NewProp_bmeasureHandler_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bmeasureHandler;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::NewProp_bmeasureHandler_SetBit(void* Obj)
	{
		((SuperMap_MeasureHandler_eventSetIsMeasureHandler_Parms*)Obj)->bmeasureHandler = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::NewProp_bmeasureHandler = { "bmeasureHandler", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MeasureHandler_eventSetIsMeasureHandler_Parms), &Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::NewProp_bmeasureHandler_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::NewProp_bmeasureHandler,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MeasureHandler" },
		{ "Comment", "//! \\brief ?\xc7\xb7?????\n//! \\param bclip [in] true??\xca\xbc\n" },
		{ "ModuleRelativePath", "Public/HandlerSamples/SuperMap_MeasureHandler.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7?????\n! \\param bclip [in] true??\xca\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MeasureHandler, nullptr, "SetIsMeasureHandler", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::SuperMap_MeasureHandler_eventSetIsMeasureHandler_Parms), Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics
	{
		struct SuperMap_MeasureHandler_eventSetMeasureAction_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::NewProp_mode = { "mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MeasureHandler_eventSetMeasureAction_Parms, mode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::NewProp_mode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MeasureHandler" },
		{ "Comment", "//! \\brief \xd1\xa1?????\xe3\xb7\xbd\xca\xbd\n" },
		{ "ModuleRelativePath", "Public/HandlerSamples/SuperMap_MeasureHandler.h" },
		{ "ToolTip", "! \\brief \xd1\xa1?????\xe3\xb7\xbd\xca\xbd" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MeasureHandler, nullptr, "SetMeasureAction", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::SuperMap_MeasureHandler_eventSetMeasureAction_Parms), Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_MeasureHandler);
	UClass* Z_Construct_UClass_ASuperMap_MeasureHandler_NoRegister()
	{
		return ASuperMap_MeasureHandler::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_MeasureHandler_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_MeasureHandler_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_MeasureHandler_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_MeasureHandler_GetCurrentState, "GetCurrentState" }, // 953939945
		{ &Z_Construct_UFunction_ASuperMap_MeasureHandler_GetMeasureResult, "GetMeasureResult" }, // 2909151648
		{ &Z_Construct_UFunction_ASuperMap_MeasureHandler_HypsometricSetting, "HypsometricSetting" }, // 3963345284
		{ &Z_Construct_UFunction_ASuperMap_MeasureHandler_SetIsMeasureHandler, "SetIsMeasureHandler" }, // 326613188
		{ &Z_Construct_UFunction_ASuperMap_MeasureHandler_SetMeasureAction, "SetMeasureAction" }, // 1289474162
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MeasureHandler_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "HandlerSamples/SuperMap_MeasureHandler.h" },
		{ "ModuleRelativePath", "Public/HandlerSamples/SuperMap_MeasureHandler.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_MeasureHandler_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_MeasureHandler>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_MeasureHandler_Statics::ClassParams = {
		&ASuperMap_MeasureHandler::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MeasureHandler_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MeasureHandler_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_MeasureHandler()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_MeasureHandler.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_MeasureHandler.OuterSingleton, Z_Construct_UClass_ASuperMap_MeasureHandler_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_MeasureHandler.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_MeasureHandler>()
	{
		return ASuperMap_MeasureHandler::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_MeasureHandler);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_HandlerSamples_SuperMap_MeasureHandler_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_HandlerSamples_SuperMap_MeasureHandler_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_MeasureHandler, ASuperMap_MeasureHandler::StaticClass, TEXT("ASuperMap_MeasureHandler"), &Z_Registration_Info_UClass_ASuperMap_MeasureHandler, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_MeasureHandler), 1572521495U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_HandlerSamples_SuperMap_MeasureHandler_h_4177558946(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_HandlerSamples_SuperMap_MeasureHandler_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_HandlerSamples_SuperMap_MeasureHandler_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
