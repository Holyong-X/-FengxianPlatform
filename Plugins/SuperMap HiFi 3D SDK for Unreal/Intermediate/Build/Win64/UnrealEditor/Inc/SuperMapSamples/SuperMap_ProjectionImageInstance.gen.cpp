// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ProjectionImageInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ProjectionImageInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ProjectionImageInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_ProjectionImageInstance::execGetTexture2DFromDiskFile)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=P_THIS->GetTexture2DFromDiskFile(Z_Param_FilePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ProjectionImageInstance::execSetHintLineLength)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_dLength);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHintLineLength(Z_Param_dLength);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ProjectionImageInstance::execSetPitch)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_dPitch);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPitch(Z_Param_dPitch);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ProjectionImageInstance::execSetHeading)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_dDir);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHeading(Z_Param_dDir);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ProjectionImageInstance::execSetViewerPosition)
	{
		P_GET_STRUCT(FVector,Z_Param_vPos);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewerPosition(Z_Param_vPos);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ProjectionImageInstance::execBuildProjectionImage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildProjectionImage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ProjectionImageInstance::execSetProjectionImageInfos)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strFileName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetProjectionImageInfos(Z_Param_strFileName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ProjectionImageInstance::execSetIsProjectionImage)
	{
		P_GET_UBOOL(Z_Param_bViewShed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsProjectionImage(Z_Param_bViewShed);
		P_NATIVE_END;
	}
	void ASuperMap_ProjectionImageInstance::StaticRegisterNativesASuperMap_ProjectionImageInstance()
	{
		UClass* Class = ASuperMap_ProjectionImageInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildProjectionImage", &ASuperMap_ProjectionImageInstance::execBuildProjectionImage },
			{ "GetTexture2DFromDiskFile", &ASuperMap_ProjectionImageInstance::execGetTexture2DFromDiskFile },
			{ "SetHeading", &ASuperMap_ProjectionImageInstance::execSetHeading },
			{ "SetHintLineLength", &ASuperMap_ProjectionImageInstance::execSetHintLineLength },
			{ "SetIsProjectionImage", &ASuperMap_ProjectionImageInstance::execSetIsProjectionImage },
			{ "SetPitch", &ASuperMap_ProjectionImageInstance::execSetPitch },
			{ "SetProjectionImageInfos", &ASuperMap_ProjectionImageInstance::execSetProjectionImageInfos },
			{ "SetViewerPosition", &ASuperMap_ProjectionImageInstance::execSetViewerPosition },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_BuildProjectionImage_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_BuildProjectionImage_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProjectionImageInstance" },
		{ "Comment", "//! \\brief ????????\xce\xbb??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
		{ "ToolTip", "! \\brief ????????\xce\xbb??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_BuildProjectionImage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProjectionImageInstance, nullptr, "BuildProjectionImage", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_BuildProjectionImage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_BuildProjectionImage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_BuildProjectionImage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_BuildProjectionImage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics
	{
		struct SuperMap_ProjectionImageInstance_eventGetTexture2DFromDiskFile_Parms
		{
			FString FilePath;
			UTexture2D* ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ProjectionImageInstance_eventGetTexture2DFromDiskFile_Parms, FilePath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ProjectionImageInstance_eventGetTexture2DFromDiskFile_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::NewProp_FilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProjectionImageInstance" },
		{ "Comment", "//! \\brief \xcd\xb6??\xcd\xbc\xc6\xac\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
		{ "ToolTip", "! \\brief \xcd\xb6??\xcd\xbc\xc6\xac" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProjectionImageInstance, nullptr, "GetTexture2DFromDiskFile", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::SuperMap_ProjectionImageInstance_eventGetTexture2DFromDiskFile_Parms), Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics
	{
		struct SuperMap_ProjectionImageInstance_eventSetHeading_Parms
		{
			float dDir;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_dDir;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::NewProp_dDir = { "dDir", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ProjectionImageInstance_eventSetHeading_Parms, dDir), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::NewProp_dDir,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProjectionImageInstance" },
		{ "Comment", "//! \\brief ???????\xdf\xb7???\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
		{ "ToolTip", "! \\brief ???????\xdf\xb7???" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProjectionImageInstance, nullptr, "SetHeading", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::SuperMap_ProjectionImageInstance_eventSetHeading_Parms), Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics
	{
		struct SuperMap_ProjectionImageInstance_eventSetHintLineLength_Parms
		{
			float dLength;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_dLength;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::NewProp_dLength = { "dLength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ProjectionImageInstance_eventSetHintLineLength_Parms, dLength), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::NewProp_dLength,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProjectionImageInstance" },
		{ "Comment", "//! \\brief ?????\xd3\xbe?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
		{ "ToolTip", "! \\brief ?????\xd3\xbe?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProjectionImageInstance, nullptr, "SetHintLineLength", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::SuperMap_ProjectionImageInstance_eventSetHintLineLength_Parms), Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics
	{
		struct SuperMap_ProjectionImageInstance_eventSetIsProjectionImage_Parms
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
	void Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::NewProp_bViewShed_SetBit(void* Obj)
	{
		((SuperMap_ProjectionImageInstance_eventSetIsProjectionImage_Parms*)Obj)->bViewShed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::NewProp_bViewShed = { "bViewShed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ProjectionImageInstance_eventSetIsProjectionImage_Parms), &Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::NewProp_bViewShed_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::NewProp_bViewShed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProjectionImageInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7?????\xcd\xb6??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7?????\xcd\xb6??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProjectionImageInstance, nullptr, "SetIsProjectionImage", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::SuperMap_ProjectionImageInstance_eventSetIsProjectionImage_Parms), Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics
	{
		struct SuperMap_ProjectionImageInstance_eventSetPitch_Parms
		{
			float dPitch;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_dPitch;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::NewProp_dPitch = { "dPitch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ProjectionImageInstance_eventSetPitch_Parms, dPitch), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::NewProp_dPitch,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProjectionImageInstance" },
		{ "Comment", "//! \\brief ??????\xd0\xb1?\xc7\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
		{ "ToolTip", "! \\brief ??????\xd0\xb1?\xc7\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProjectionImageInstance, nullptr, "SetPitch", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::SuperMap_ProjectionImageInstance_eventSetPitch_Parms), Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics
	{
		struct SuperMap_ProjectionImageInstance_eventSetProjectionImageInfos_Parms
		{
			FString strFileName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strFileName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::NewProp_strFileName = { "strFileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ProjectionImageInstance_eventSetProjectionImageInfos_Parms, strFileName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::NewProp_strFileName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProjectionImageInstance" },
		{ "Comment", "//! \\brief ????XML\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
		{ "ToolTip", "! \\brief ????XML" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProjectionImageInstance, nullptr, "SetProjectionImageInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::SuperMap_ProjectionImageInstance_eventSetProjectionImageInfos_Parms), Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics
	{
		struct SuperMap_ProjectionImageInstance_eventSetViewerPosition_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::NewProp_vPos = { "vPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ProjectionImageInstance_eventSetViewerPosition_Parms, vPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::NewProp_vPos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProjectionImageInstance" },
		{ "Comment", "//! \\brief ?????\xd3\xb5?\xce\xbb??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
		{ "ToolTip", "! \\brief ?????\xd3\xb5?\xce\xbb??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProjectionImageInstance, nullptr, "SetViewerPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::SuperMap_ProjectionImageInstance_eventSetViewerPosition_Parms), Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ProjectionImageInstance);
	UClass* Z_Construct_UClass_ASuperMap_ProjectionImageInstance_NoRegister()
	{
		return ASuperMap_ProjectionImageInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ProjectionImageInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ProjectionImageInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_ProjectionImageInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_BuildProjectionImage, "BuildProjectionImage" }, // 2523066119
		{ &Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_GetTexture2DFromDiskFile, "GetTexture2DFromDiskFile" }, // 2406249950
		{ &Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHeading, "SetHeading" }, // 2855698598
		{ &Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetHintLineLength, "SetHintLineLength" }, // 2571686978
		{ &Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetIsProjectionImage, "SetIsProjectionImage" }, // 487317216
		{ &Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetPitch, "SetPitch" }, // 1552465400
		{ &Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetProjectionImageInfos, "SetProjectionImageInfos" }, // 1630462684
		{ &Z_Construct_UFunction_ASuperMap_ProjectionImageInstance_SetViewerPosition, "SetViewerPosition" }, // 918719948
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ProjectionImageInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProjectionImageInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ProjectionImageInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ProjectionImageInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ProjectionImageInstance_Statics::ClassParams = {
		&ASuperMap_ProjectionImageInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ProjectionImageInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ProjectionImageInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ProjectionImageInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ProjectionImageInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ProjectionImageInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_ProjectionImageInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ProjectionImageInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_ProjectionImageInstance>()
	{
		return ASuperMap_ProjectionImageInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ProjectionImageInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProjectionImageInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProjectionImageInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ProjectionImageInstance, ASuperMap_ProjectionImageInstance::StaticClass, TEXT("ASuperMap_ProjectionImageInstance"), &Z_Registration_Info_UClass_ASuperMap_ProjectionImageInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ProjectionImageInstance), 3789374458U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProjectionImageInstance_h_3908353416(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProjectionImageInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProjectionImageInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
