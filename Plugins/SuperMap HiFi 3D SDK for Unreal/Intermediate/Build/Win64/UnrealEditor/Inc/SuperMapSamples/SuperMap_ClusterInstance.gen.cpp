// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_ClusterInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ClusterInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ClusterDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ClusterInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ClusterInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_ClusterDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_ClusterDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_ClusterDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "ClusterDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_ClusterDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_ClusterDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ClusterDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_ClusterDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execRemoveLayer)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_LayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveLayer(Z_Param_LayerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execQueryPointBySql)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_LayerName);
		P_GET_PROPERTY(FStrProperty,Z_Param_dataset);
		P_GET_PROPERTY(FStrProperty,Z_Param_styleField);
		P_GET_TARRAY(FString,Z_Param_strSql);
		P_GET_TARRAY(FString,Z_Param_strPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->QueryPointBySql(Z_Param_LayerName,Z_Param_dataset,Z_Param_styleField,Z_Param_strSql,Z_Param_strPath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execGetRelatedLabelPath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetRelatedLabelPath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execGetMinimumClusterSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetMinimumClusterSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execSetMinimumClusterSize)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_minimumClusterSize);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMinimumClusterSize(Z_Param_minimumClusterSize);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execGetClusterEnable)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetClusterEnable();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execSetClusterEnable)
	{
		P_GET_UBOOL(Z_Param_bEnble);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetClusterEnable(Z_Param_bEnble);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execCluster_GetPixelRange)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->Cluster_GetPixelRange();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execCluster_SetPixelRange)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_pixelRange);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Cluster_SetPixelRange(Z_Param_pixelRange);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execCluster_SetGeoPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Cluster_SetGeoPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execCluster_GetScreenPosition)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_path);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FVector2D>*)Z_Param__Result=P_THIS->Cluster_GetScreenPosition(Z_Param_path);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ClusterInstance::execCluster_Build)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Cluster_Build();
		P_NATIVE_END;
	}
	void ASuperMap_ClusterInstance::StaticRegisterNativesASuperMap_ClusterInstance()
	{
		UClass* Class = ASuperMap_ClusterInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Cluster_Build", &ASuperMap_ClusterInstance::execCluster_Build },
			{ "Cluster_GetPixelRange", &ASuperMap_ClusterInstance::execCluster_GetPixelRange },
			{ "Cluster_GetScreenPosition", &ASuperMap_ClusterInstance::execCluster_GetScreenPosition },
			{ "Cluster_SetGeoPosition", &ASuperMap_ClusterInstance::execCluster_SetGeoPosition },
			{ "Cluster_SetPixelRange", &ASuperMap_ClusterInstance::execCluster_SetPixelRange },
			{ "GetClusterEnable", &ASuperMap_ClusterInstance::execGetClusterEnable },
			{ "GetMinimumClusterSize", &ASuperMap_ClusterInstance::execGetMinimumClusterSize },
			{ "GetRelatedLabelPath", &ASuperMap_ClusterInstance::execGetRelatedLabelPath },
			{ "QueryPointBySql", &ASuperMap_ClusterInstance::execQueryPointBySql },
			{ "RemoveLayer", &ASuperMap_ClusterInstance::execRemoveLayer },
			{ "SetClusterEnable", &ASuperMap_ClusterInstance::execSetClusterEnable },
			{ "SetMinimumClusterSize", &ASuperMap_ClusterInstance::execSetMinimumClusterSize },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_Build_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_Build_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "Comment", "//! \\brief ??????????\xcd\xbc??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
		{ "ToolTip", "! \\brief ??????????\xcd\xbc??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_Build_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "Cluster_Build", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_Build_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_Build_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_Build()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_Build_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics
	{
		struct SuperMap_ClusterInstance_eventCluster_GetPixelRange_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventCluster_GetPixelRange_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "Cluster_GetPixelRange", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::SuperMap_ClusterInstance_eventCluster_GetPixelRange_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics
	{
		struct SuperMap_ClusterInstance_eventCluster_GetScreenPosition_Parms
		{
			FString path;
			TArray<FVector2D> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_path;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::NewProp_path = { "path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventCluster_GetScreenPosition_Parms, path), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventCluster_GetScreenPosition_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::NewProp_path,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1\xcd\xbc\xc6\xac\xc2\xb7????\xd3\xa6????\xc4\xbb??????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1\xcd\xbc\xc6\xac\xc2\xb7????\xd3\xa6????\xc4\xbb??????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "Cluster_GetScreenPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::SuperMap_ClusterInstance_eventCluster_GetScreenPosition_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetGeoPosition_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetGeoPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "Comment", "//! \\brief \n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
		{ "ToolTip", "! \\brief" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetGeoPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "Cluster_SetGeoPosition", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetGeoPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetGeoPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetGeoPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetGeoPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics
	{
		struct SuperMap_ClusterInstance_eventCluster_SetPixelRange_Parms
		{
			int32 pixelRange;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_pixelRange;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::NewProp_pixelRange = { "pixelRange", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventCluster_SetPixelRange_Parms, pixelRange), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::NewProp_pixelRange,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "Comment", "//! \\brief ???\xc3\xb1??\xc3\xbe???\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xb1??\xc3\xbe???" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "Cluster_SetPixelRange", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::SuperMap_ClusterInstance_eventCluster_SetPixelRange_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics
	{
		struct SuperMap_ClusterInstance_eventGetClusterEnable_Parms
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
	void Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_ClusterInstance_eventGetClusterEnable_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ClusterInstance_eventGetClusterEnable_Parms), &Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "GetClusterEnable", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::SuperMap_ClusterInstance_eventGetClusterEnable_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics
	{
		struct SuperMap_ClusterInstance_eventGetMinimumClusterSize_Parms
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
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventGetMinimumClusterSize_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "GetMinimumClusterSize", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::SuperMap_ClusterInstance_eventGetMinimumClusterSize_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics
	{
		struct SuperMap_ClusterInstance_eventGetRelatedLabelPath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventGetRelatedLabelPath_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "GetRelatedLabelPath", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::SuperMap_ClusterInstance_eventGetRelatedLabelPath_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics
	{
		struct SuperMap_ClusterInstance_eventQueryPointBySql_Parms
		{
			FString LayerName;
			FString dataset;
			FString styleField;
			TArray<FString> strSql;
			TArray<FString> strPath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_LayerName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_dataset;
		static const UECodeGen_Private::FStrPropertyParams NewProp_styleField;
		static const UECodeGen_Private::FStrPropertyParams NewProp_strSql_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_strSql;
		static const UECodeGen_Private::FStrPropertyParams NewProp_strPath_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_strPath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_LayerName = { "LayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventQueryPointBySql_Parms, LayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_dataset = { "dataset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventQueryPointBySql_Parms, dataset), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_styleField = { "styleField", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventQueryPointBySql_Parms, styleField), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_strSql_Inner = { "strSql", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_strSql = { "strSql", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventQueryPointBySql_Parms, strSql), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_strPath_Inner = { "strPath", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_strPath = { "strPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventQueryPointBySql_Parms, strPath), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_LayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_dataset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_styleField,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_strSql_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_strSql,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_strPath_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::NewProp_strPath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "Comment", "//=====================================================================\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "QueryPointBySql", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::SuperMap_ClusterInstance_eventQueryPointBySql_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics
	{
		struct SuperMap_ClusterInstance_eventRemoveLayer_Parms
		{
			FString LayerName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_LayerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::NewProp_LayerName = { "LayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventRemoveLayer_Parms, LayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::NewProp_LayerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "RemoveLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::SuperMap_ClusterInstance_eventRemoveLayer_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics
	{
		struct SuperMap_ClusterInstance_eventSetClusterEnable_Parms
		{
			bool bEnble;
		};
		static void NewProp_bEnble_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnble;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::NewProp_bEnble_SetBit(void* Obj)
	{
		((SuperMap_ClusterInstance_eventSetClusterEnable_Parms*)Obj)->bEnble = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::NewProp_bEnble = { "bEnble", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ClusterInstance_eventSetClusterEnable_Parms), &Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::NewProp_bEnble_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::NewProp_bEnble,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7?????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7?????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "SetClusterEnable", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::SuperMap_ClusterInstance_eventSetClusterEnable_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics
	{
		struct SuperMap_ClusterInstance_eventSetMinimumClusterSize_Parms
		{
			int32 minimumClusterSize;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_minimumClusterSize;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::NewProp_minimumClusterSize = { "minimumClusterSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ClusterInstance_eventSetMinimumClusterSize_Parms, minimumClusterSize), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::NewProp_minimumClusterSize,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ClusterInstance" },
		{ "Comment", "//! \\brief ??\xd0\xa1?\xc9\xbe?????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
		{ "ToolTip", "! \\brief ??\xd0\xa1?\xc9\xbe?????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ClusterInstance, nullptr, "SetMinimumClusterSize", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::SuperMap_ClusterInstance_eventSetMinimumClusterSize_Parms), Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ClusterInstance);
	UClass* Z_Construct_UClass_ASuperMap_ClusterInstance_NoRegister()
	{
		return ASuperMap_ClusterInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ClusterInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallGetScreenPos_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallGetScreenPos;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_Build, "Cluster_Build" }, // 2041916124
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetPixelRange, "Cluster_GetPixelRange" }, // 2217740163
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_GetScreenPosition, "Cluster_GetScreenPosition" }, // 323585302
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetGeoPosition, "Cluster_SetGeoPosition" }, // 250619822
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_Cluster_SetPixelRange, "Cluster_SetPixelRange" }, // 2872374433
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_GetClusterEnable, "GetClusterEnable" }, // 847028005
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_GetMinimumClusterSize, "GetMinimumClusterSize" }, // 420992425
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_GetRelatedLabelPath, "GetRelatedLabelPath" }, // 3769929267
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_QueryPointBySql, "QueryPointBySql" }, // 567221973
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_RemoveLayer, "RemoveLayer" }, // 3342412511
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_SetClusterEnable, "SetClusterEnable" }, // 550795684
		{ &Z_Construct_UFunction_ASuperMap_ClusterInstance_SetMinimumClusterSize, "SetMinimumClusterSize" }, // 3913628477
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_ClusterInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::NewProp_CallGetScreenPos_MetaData[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ClusterInstance.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::NewProp_CallGetScreenPos = { "CallGetScreenPos", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_ClusterInstance, CallGetScreenPos), Z_Construct_UDelegateFunction_SuperMapSamples_ClusterDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::NewProp_CallGetScreenPos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::NewProp_CallGetScreenPos_MetaData)) }; // 727685180
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::NewProp_CallGetScreenPos,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ClusterInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::ClassParams = {
		&ASuperMap_ClusterInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ClusterInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ClusterInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ClusterInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_ClusterInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ClusterInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_ClusterInstance>()
	{
		return ASuperMap_ClusterInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ClusterInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClusterInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClusterInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ClusterInstance, ASuperMap_ClusterInstance::StaticClass, TEXT("ASuperMap_ClusterInstance"), &Z_Registration_Info_UClass_ASuperMap_ClusterInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ClusterInstance), 3124143002U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClusterInstance_h_3763220331(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClusterInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ClusterInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
