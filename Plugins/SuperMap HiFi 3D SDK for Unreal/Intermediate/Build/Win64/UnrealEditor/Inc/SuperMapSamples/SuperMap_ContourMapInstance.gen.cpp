// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_ContourMapInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ContourMapInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ContourMapInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ContourMapInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execGetMaxHeight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMaxHeight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execGetMinHeight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMinHeight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execGetColorTableFiles)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetColorTableFiles();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execColorTableChanged)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strColorTableName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ColorTableChanged(Z_Param_strColorTableName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execContourIntervalModeChanged)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fContourInterval);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ContourIntervalModeChanged(Z_Param_fContourInterval);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execFloorModeChanged)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fFloor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FloorModeChanged(Z_Param_fFloor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execMinVisibleValueChanged)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fMin);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MinVisibleValueChanged(Z_Param_fMin);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execMaxVisibleValueChanged)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fMax);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MaxVisibleValueChanged(Z_Param_fMax);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execCeilModeChanged)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fCeil);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CeilModeChanged(Z_Param_fCeil);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execDisplayModeChanged)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nDisplayMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisplayModeChanged(Z_Param_nDisplayMode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execInitialContourMap)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nDisplayMode);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fCeil);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fFloor);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fMax);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fMin);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fContourInterval);
		P_GET_PROPERTY(FStrProperty,Z_Param_strColorTableName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InitialContourMap(Z_Param_nDisplayMode,Z_Param_fCeil,Z_Param_fFloor,Z_Param_fMax,Z_Param_fMin,Z_Param_fContourInterval,Z_Param_strColorTableName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ContourMapInstance::execBuildContourMap)
	{
		P_GET_UBOOL(Z_Param_ContourMapEnable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildContourMap(Z_Param_ContourMapEnable);
		P_NATIVE_END;
	}
	void ASuperMap_ContourMapInstance::StaticRegisterNativesASuperMap_ContourMapInstance()
	{
		UClass* Class = ASuperMap_ContourMapInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildContourMap", &ASuperMap_ContourMapInstance::execBuildContourMap },
			{ "CeilModeChanged", &ASuperMap_ContourMapInstance::execCeilModeChanged },
			{ "ColorTableChanged", &ASuperMap_ContourMapInstance::execColorTableChanged },
			{ "ContourIntervalModeChanged", &ASuperMap_ContourMapInstance::execContourIntervalModeChanged },
			{ "DisplayModeChanged", &ASuperMap_ContourMapInstance::execDisplayModeChanged },
			{ "FloorModeChanged", &ASuperMap_ContourMapInstance::execFloorModeChanged },
			{ "GetColorTableFiles", &ASuperMap_ContourMapInstance::execGetColorTableFiles },
			{ "GetMaxHeight", &ASuperMap_ContourMapInstance::execGetMaxHeight },
			{ "GetMinHeight", &ASuperMap_ContourMapInstance::execGetMinHeight },
			{ "InitialContourMap", &ASuperMap_ContourMapInstance::execInitialContourMap },
			{ "MaxVisibleValueChanged", &ASuperMap_ContourMapInstance::execMaxVisibleValueChanged },
			{ "MinVisibleValueChanged", &ASuperMap_ContourMapInstance::execMinVisibleValueChanged },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics
	{
		struct SuperMap_ContourMapInstance_eventBuildContourMap_Parms
		{
			bool ContourMapEnable;
		};
		static void NewProp_ContourMapEnable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ContourMapEnable;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::NewProp_ContourMapEnable_SetBit(void* Obj)
	{
		((SuperMap_ContourMapInstance_eventBuildContourMap_Parms*)Obj)->ContourMapEnable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::NewProp_ContourMapEnable = { "ContourMapEnable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ContourMapInstance_eventBuildContourMap_Parms), &Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::NewProp_ContourMapEnable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::NewProp_ContourMapEnable,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\n//! \\return true\xe4\xb8\xba\xe5\xbc\x80\xe5\xa7\x8b\xe6\x89\xa7\xe8\xa1\x8c\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\n! \\return true\xe4\xb8\xba\xe5\xbc\x80\xe5\xa7\x8b\xe6\x89\xa7\xe8\xa1\x8c\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "BuildContourMap", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::SuperMap_ContourMapInstance_eventBuildContourMap_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics
	{
		struct SuperMap_ContourMapInstance_eventCeilModeChanged_Parms
		{
			float fCeil;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fCeil;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::NewProp_fCeil = { "fCeil", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventCeilModeChanged_Parms, fCeil), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::NewProp_fCeil,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x9c\x80\xe9\xab\x98\xe9\xab\x98\xe5\xba\xa6\n//! \\param fCeil [in] \xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x9c\x80\xe9\xab\x98\xe9\xab\x98\xe5\xba\xa6\n! \\param fCeil [in] \xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "CeilModeChanged", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::SuperMap_ContourMapInstance_eventCeilModeChanged_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics
	{
		struct SuperMap_ContourMapInstance_eventColorTableChanged_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::NewProp_strColorTableName = { "strColorTableName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventColorTableChanged_Parms, strColorTableName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::NewProp_strColorTableName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\n//! \\param strColorTableName [in] \xe5\xaf\xb9\xe5\xba\x94\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\xe8\xb7\xaf\xe5\xbe\x84\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\n! \\param strColorTableName [in] \xe5\xaf\xb9\xe5\xba\x94\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\xe8\xb7\xaf\xe5\xbe\x84" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "ColorTableChanged", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::SuperMap_ContourMapInstance_eventColorTableChanged_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics
	{
		struct SuperMap_ContourMapInstance_eventContourIntervalModeChanged_Parms
		{
			float fContourInterval;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fContourInterval;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::NewProp_fContourInterval = { "fContourInterval", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventContourIntervalModeChanged_Parms, fContourInterval), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::NewProp_fContourInterval,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe9\x97\xb4\xe8\xb7\x9d\n//! \\param fContourInterval [in] \xe9\x97\xb4\xe8\xb7\x9d\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe9\x97\xb4\xe8\xb7\x9d\n! \\param fContourInterval [in] \xe9\x97\xb4\xe8\xb7\x9d" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "ContourIntervalModeChanged", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::SuperMap_ContourMapInstance_eventContourIntervalModeChanged_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics
	{
		struct SuperMap_ContourMapInstance_eventDisplayModeChanged_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::NewProp_nDisplayMode = { "nDisplayMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventDisplayModeChanged_Parms, nDisplayMode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::NewProp_nDisplayMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x88\x86\xe6\x9e\x90\xe6\xa8\xa1\xe5\xbc\x8f\n//! \\param nDisplayMode [in] 1\xe3\x80\x81\xe7\xad\x89\xe5\x80\xbc\xe9\x9d\xa2 2\xe3\x80\x81\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf 3\xe3\x80\x81\xe6\xb7\xb7\xe5\x90\x88\xe6\xa8\xa1\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x88\x86\xe6\x9e\x90\xe6\xa8\xa1\xe5\xbc\x8f\n! \\param nDisplayMode [in] 1\xe3\x80\x81\xe7\xad\x89\xe5\x80\xbc\xe9\x9d\xa2 2\xe3\x80\x81\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf 3\xe3\x80\x81\xe6\xb7\xb7\xe5\x90\x88\xe6\xa8\xa1\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "DisplayModeChanged", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::SuperMap_ContourMapInstance_eventDisplayModeChanged_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics
	{
		struct SuperMap_ContourMapInstance_eventFloorModeChanged_Parms
		{
			float fFloor;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fFloor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::NewProp_fFloor = { "fFloor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventFloorModeChanged_Parms, fFloor), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::NewProp_fFloor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x9c\x80\xe4\xbd\x8e\xe9\xab\x98\xe5\xba\xa6\n//! \\param fFloor [in] \xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x9c\x80\xe4\xbd\x8e\xe9\xab\x98\xe5\xba\xa6\n! \\param fFloor [in] \xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "FloorModeChanged", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::SuperMap_ContourMapInstance_eventFloorModeChanged_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics
	{
		struct SuperMap_ContourMapInstance_eventGetColorTableFiles_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventGetColorTableFiles_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6\xe5\xa4\xb9\xe4\xb8\x8b\xe7\x9a\x84\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\n//! \\return \xe8\x8e\xb7\xe5\x8f\x96\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\xe5\xad\x98\xe5\x82\xa8\xe8\xb7\xaf\xe5\xbe\x84\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6\xe5\xa4\xb9\xe4\xb8\x8b\xe7\x9a\x84\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\n! \\return \xe8\x8e\xb7\xe5\x8f\x96\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\xe5\xad\x98\xe5\x82\xa8\xe8\xb7\xaf\xe5\xbe\x84" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "GetColorTableFiles", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::SuperMap_ContourMapInstance_eventGetColorTableFiles_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics
	{
		struct SuperMap_ContourMapInstance_eventGetMaxHeight_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventGetMaxHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9c\xb0\xe5\xbd\xa2\xe6\x9c\x80\xe9\xab\x98\xe5\x80\xbc\n//! \\return \xe8\xbf\x94\xe5\x9b\x9e\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9c\xb0\xe5\xbd\xa2\xe6\x9c\x80\xe9\xab\x98\xe5\x80\xbc\n! \\return \xe8\xbf\x94\xe5\x9b\x9e\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "GetMaxHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::SuperMap_ContourMapInstance_eventGetMaxHeight_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics
	{
		struct SuperMap_ContourMapInstance_eventGetMinHeight_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventGetMinHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9c\xb0\xe5\xbd\xa2\xe6\x9c\x80\xe4\xbd\x8e\xe5\x80\xbc\n//! \\return \xe8\xbf\x94\xe5\x9b\x9e\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9c\xb0\xe5\xbd\xa2\xe6\x9c\x80\xe4\xbd\x8e\xe5\x80\xbc\n! \\return \xe8\xbf\x94\xe5\x9b\x9e\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "GetMinHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::SuperMap_ContourMapInstance_eventGetMinHeight_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics
	{
		struct SuperMap_ContourMapInstance_eventInitialContourMap_Parms
		{
			int32 nDisplayMode;
			float fCeil;
			float fFloor;
			float fMax;
			float fMin;
			float fContourInterval;
			FString strColorTableName;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nDisplayMode;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fCeil;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fFloor;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fMax;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fMin;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fContourInterval;
		static const UECodeGen_Private::FStrPropertyParams NewProp_strColorTableName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_nDisplayMode = { "nDisplayMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventInitialContourMap_Parms, nDisplayMode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fCeil = { "fCeil", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventInitialContourMap_Parms, fCeil), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fFloor = { "fFloor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventInitialContourMap_Parms, fFloor), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fMax = { "fMax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventInitialContourMap_Parms, fMax), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fMin = { "fMin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventInitialContourMap_Parms, fMin), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fContourInterval = { "fContourInterval", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventInitialContourMap_Parms, fContourInterval), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_strColorTableName = { "strColorTableName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventInitialContourMap_Parms, strColorTableName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_nDisplayMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fCeil,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fFloor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fMax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fMin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_fContourInterval,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::NewProp_strColorTableName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x95\xb0\xe5\x80\xbc\n//! \\param nDisplayMode [in] 1\xe3\x80\x81\xe7\xad\x89\xe5\x80\xbc\xe9\x9d\xa2 2\xe3\x80\x81\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf 3\xe3\x80\x81\xe6\xb7\xb7\xe5\x90\x88\xe6\xa8\xa1\xe5\xbc\x8f\n//! \\param fCeil [in] \xe5\x88\x86\xe6\x9e\x90\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n//! \\param fFloor [in] \xe5\x88\x86\xe6\x9e\x90\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n//! \\param fMax [in] \xe5\x8f\xaf\xe8\xa7\x81\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n//! \\param fMin [in] \xe5\x8f\xaf\xe8\xa7\x81\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n//! \\param fContourInterval [in] \xe9\x97\xb4\xe8\xb7\x9d\n//! \\param strColorTableName [in] \xe5\xaf\xb9\xe5\xba\x94\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\xe8\xb7\xaf\xe5\xbe\x84\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x95\xb0\xe5\x80\xbc\n! \\param nDisplayMode [in] 1\xe3\x80\x81\xe7\xad\x89\xe5\x80\xbc\xe9\x9d\xa2 2\xe3\x80\x81\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf 3\xe3\x80\x81\xe6\xb7\xb7\xe5\x90\x88\xe6\xa8\xa1\xe5\xbc\x8f\n! \\param fCeil [in] \xe5\x88\x86\xe6\x9e\x90\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n! \\param fFloor [in] \xe5\x88\x86\xe6\x9e\x90\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n! \\param fMax [in] \xe5\x8f\xaf\xe8\xa7\x81\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n! \\param fMin [in] \xe5\x8f\xaf\xe8\xa7\x81\xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n! \\param fContourInterval [in] \xe9\x97\xb4\xe8\xb7\x9d\n! \\param strColorTableName [in] \xe5\xaf\xb9\xe5\xba\x94\xe9\xa2\x9c\xe8\x89\xb2\xe8\xa1\xa8\xe8\xb7\xaf\xe5\xbe\x84" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "InitialContourMap", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::SuperMap_ContourMapInstance_eventInitialContourMap_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics
	{
		struct SuperMap_ContourMapInstance_eventMaxVisibleValueChanged_Parms
		{
			float fMax;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fMax;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::NewProp_fMax = { "fMax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventMaxVisibleValueChanged_Parms, fMax), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::NewProp_fMax,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x9c\x80\xe5\xa4\xa7\xe5\x8f\xaf\xe8\xa7\x81\xe5\x80\xbc\n//! \\param fMax [in] \xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x9c\x80\xe5\xa4\xa7\xe5\x8f\xaf\xe8\xa7\x81\xe5\x80\xbc\n! \\param fMax [in] \xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "MaxVisibleValueChanged", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::SuperMap_ContourMapInstance_eventMaxVisibleValueChanged_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics
	{
		struct SuperMap_ContourMapInstance_eventMinVisibleValueChanged_Parms
		{
			float fMin;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fMin;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::NewProp_fMin = { "fMin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ContourMapInstance_eventMinVisibleValueChanged_Parms, fMin), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::NewProp_fMin,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ContourMapInstance" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x9c\x80\xe5\xb0\x8f\xe5\x8f\xaf\xe8\xa7\x81\xe5\x80\xbc\n//! \\param fMin [in] \xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe7\xad\x89\xe5\x80\xbc\xe7\xba\xbf\xe5\x88\x86\xe6\x9e\x90\xe6\x9c\x80\xe5\xb0\x8f\xe5\x8f\xaf\xe8\xa7\x81\xe5\x80\xbc\n! \\param fMin [in] \xe9\xab\x98\xe5\xba\xa6\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ContourMapInstance, nullptr, "MinVisibleValueChanged", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::SuperMap_ContourMapInstance_eventMinVisibleValueChanged_Parms), Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ContourMapInstance);
	UClass* Z_Construct_UClass_ASuperMap_ContourMapInstance_NoRegister()
	{
		return ASuperMap_ContourMapInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ContourMapInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ContourMapInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_ContourMapInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_BuildContourMap, "BuildContourMap" }, // 4165752705
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_CeilModeChanged, "CeilModeChanged" }, // 190894122
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_ColorTableChanged, "ColorTableChanged" }, // 1550768481
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_ContourIntervalModeChanged, "ContourIntervalModeChanged" }, // 3532006108
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_DisplayModeChanged, "DisplayModeChanged" }, // 379712910
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_FloorModeChanged, "FloorModeChanged" }, // 4167071694
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetColorTableFiles, "GetColorTableFiles" }, // 2949635747
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMaxHeight, "GetMaxHeight" }, // 2401750904
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_GetMinHeight, "GetMinHeight" }, // 1593950336
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_InitialContourMap, "InitialContourMap" }, // 3809586696
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_MaxVisibleValueChanged, "MaxVisibleValueChanged" }, // 511552833
		{ &Z_Construct_UFunction_ASuperMap_ContourMapInstance_MinVisibleValueChanged, "MinVisibleValueChanged" }, // 3657002346
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ContourMapInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_ContourMapInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ContourMapInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ContourMapInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ContourMapInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ContourMapInstance_Statics::ClassParams = {
		&ASuperMap_ContourMapInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ContourMapInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ContourMapInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ContourMapInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ContourMapInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ContourMapInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_ContourMapInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ContourMapInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_ContourMapInstance>()
	{
		return ASuperMap_ContourMapInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ContourMapInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ContourMapInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ContourMapInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ContourMapInstance, ASuperMap_ContourMapInstance::StaticClass, TEXT("ASuperMap_ContourMapInstance"), &Z_Registration_Info_UClass_ASuperMap_ContourMapInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ContourMapInstance), 3454764499U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ContourMapInstance_h_1123730854(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ContourMapInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ContourMapInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
