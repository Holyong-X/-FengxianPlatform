// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_SkylineInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_SkylineInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_SkylineInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_SkylineInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_SkylineInstance::execSkylineGetObjectIDs)
	{
		P_GET_UBOOL(Z_Param_isLight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SkylineGetObjectIDs(Z_Param_isLight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SkylineInstance::execSetSkylineSectorBody)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSkylineSectorBody(Z_Param_fHeight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SkylineInstance::execSetRadius)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_dRadius);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRadius(Z_Param_dRadius);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SkylineInstance::execSetViewerDirection)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_direction);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewerDirection(Z_Param_direction);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SkylineInstance::execSetViewerPitch)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_pitch);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetViewerPitch(Z_Param_pitch);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SkylineInstance::execSetSkylineColor)
	{
		P_GET_STRUCT(FColor,Z_Param_color);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSkylineColor(Z_Param_color);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SkylineInstance::execSetIsSkyline)
	{
		P_GET_UBOOL(Z_Param_bskyline);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsSkyline(Z_Param_bskyline);
		P_NATIVE_END;
	}
	void ASuperMap_SkylineInstance::StaticRegisterNativesASuperMap_SkylineInstance()
	{
		UClass* Class = ASuperMap_SkylineInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetIsSkyline", &ASuperMap_SkylineInstance::execSetIsSkyline },
			{ "SetRadius", &ASuperMap_SkylineInstance::execSetRadius },
			{ "SetSkylineColor", &ASuperMap_SkylineInstance::execSetSkylineColor },
			{ "SetSkylineSectorBody", &ASuperMap_SkylineInstance::execSetSkylineSectorBody },
			{ "SetViewerDirection", &ASuperMap_SkylineInstance::execSetViewerDirection },
			{ "SetViewerPitch", &ASuperMap_SkylineInstance::execSetViewerPitch },
			{ "SkylineGetObjectIDs", &ASuperMap_SkylineInstance::execSkylineGetObjectIDs },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics
	{
		struct SuperMap_SkylineInstance_eventSetIsSkyline_Parms
		{
			bool bskyline;
		};
		static void NewProp_bskyline_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bskyline;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::NewProp_bskyline_SetBit(void* Obj)
	{
		((SuperMap_SkylineInstance_eventSetIsSkyline_Parms*)Obj)->bskyline = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::NewProp_bskyline = { "bskyline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_SkylineInstance_eventSetIsSkyline_Parms), &Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::NewProp_bskyline_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::NewProp_bskyline,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SkylineInstance" },
		{ "Comment", "//! \\brief ?????\xdf\xb7???\n//! \\param bclip [in] true??\xca\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ToolTip", "! \\brief ?????\xdf\xb7???\n! \\param bclip [in] true??\xca\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SkylineInstance, nullptr, "SetIsSkyline", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::SuperMap_SkylineInstance_eventSetIsSkyline_Parms), Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics
	{
		struct SuperMap_SkylineInstance_eventSetRadius_Parms
		{
			float dRadius;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_dRadius;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::NewProp_dRadius = { "dRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SkylineInstance_eventSetRadius_Parms, dRadius), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::NewProp_dRadius,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SkylineInstance" },
		{ "Comment", "//! \\brief ???\xc3\xbb?\xc8\xa1?????\xdf\xb0\xeb\xbe\xb6\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xbb?\xc8\xa1?????\xdf\xb0\xeb\xbe\xb6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SkylineInstance, nullptr, "SetRadius", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::SuperMap_SkylineInstance_eventSetRadius_Parms), Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics
	{
		struct SuperMap_SkylineInstance_eventSetSkylineColor_Parms
		{
			FColor color;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_color;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::NewProp_color = { "color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SkylineInstance_eventSetSkylineColor_Parms, color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::NewProp_color,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SkylineInstance" },
		{ "Comment", "//! \\brief ????????\xc9\xab\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ToolTip", "! \\brief ????????\xc9\xab" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SkylineInstance, nullptr, "SetSkylineColor", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::SuperMap_SkylineInstance_eventSetSkylineColor_Parms), Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics
	{
		struct SuperMap_SkylineInstance_eventSetSkylineSectorBody_Parms
		{
			float fHeight;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fHeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::NewProp_fHeight = { "fHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SkylineInstance_eventSetSkylineSectorBody_Parms, fHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::NewProp_fHeight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SkylineInstance" },
		{ "Comment", "//! \\brief ???\xd3\xb1\xd5\xba???????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ToolTip", "! \\brief ???\xd3\xb1\xd5\xba???????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SkylineInstance, nullptr, "SetSkylineSectorBody", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::SuperMap_SkylineInstance_eventSetSkylineSectorBody_Parms), Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics
	{
		struct SuperMap_SkylineInstance_eventSetViewerDirection_Parms
		{
			float direction;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_direction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::NewProp_direction = { "direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SkylineInstance_eventSetViewerDirection_Parms, direction), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::NewProp_direction,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SkylineInstance" },
		{ "Comment", "//! \\brief ????/??\xc8\xa1???\xdf\xb5?\xcb\xae\xc6\xbd????,????\xce\xaa""0\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ToolTip", "! \\brief ????/??\xc8\xa1???\xdf\xb5?\xcb\xae\xc6\xbd????,????\xce\xaa""0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SkylineInstance, nullptr, "SetViewerDirection", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::SuperMap_SkylineInstance_eventSetViewerDirection_Parms), Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics
	{
		struct SuperMap_SkylineInstance_eventSetViewerPitch_Parms
		{
			float pitch;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_pitch;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::NewProp_pitch = { "pitch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SkylineInstance_eventSetViewerPitch_Parms, pitch), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::NewProp_pitch,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SkylineInstance" },
		{ "Comment", "//! \\brief ???\xc3\xb8?????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xb8?????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SkylineInstance, nullptr, "SetViewerPitch", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::SuperMap_SkylineInstance_eventSetViewerPitch_Parms), Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics
	{
		struct SuperMap_SkylineInstance_eventSkylineGetObjectIDs_Parms
		{
			bool isLight;
		};
		static void NewProp_isLight_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isLight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::NewProp_isLight_SetBit(void* Obj)
	{
		((SuperMap_SkylineInstance_eventSkylineGetObjectIDs_Parms*)Obj)->isLight = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::NewProp_isLight = { "isLight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_SkylineInstance_eventSkylineGetObjectIDs_Parms), &Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::NewProp_isLight_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::NewProp_isLight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SkylineInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1?\xcf\xb0?????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1?\xcf\xb0?????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SkylineInstance, nullptr, "SkylineGetObjectIDs", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::SuperMap_SkylineInstance_eventSkylineGetObjectIDs_Parms), Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_SkylineInstance);
	UClass* Z_Construct_UClass_ASuperMap_SkylineInstance_NoRegister()
	{
		return ASuperMap_SkylineInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_SkylineInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_bSkyline2D_MetaData[];
#endif
		static void NewProp_m_bSkyline2D_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_m_bSkyline2D;
		static const UECodeGen_Private::FStructPropertyParams NewProp_m_arrPoint2Ds_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_arrPoint2Ds_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_m_arrPoint2Ds;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_SkylineInstance_SetIsSkyline, "SetIsSkyline" }, // 1080360956
		{ &Z_Construct_UFunction_ASuperMap_SkylineInstance_SetRadius, "SetRadius" }, // 2652773478
		{ &Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineColor, "SetSkylineColor" }, // 1995574067
		{ &Z_Construct_UFunction_ASuperMap_SkylineInstance_SetSkylineSectorBody, "SetSkylineSectorBody" }, // 1949065416
		{ &Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerDirection, "SetViewerDirection" }, // 1204587599
		{ &Z_Construct_UFunction_ASuperMap_SkylineInstance_SetViewerPitch, "SetViewerPitch" }, // 4121683374
		{ &Z_Construct_UFunction_ASuperMap_SkylineInstance_SkylineGetObjectIDs, "SkylineGetObjectIDs" }, // 415877583
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_bSkyline2D_MetaData[] = {
		{ "Category", "SuperMap_SkylineInstance" },
		{ "Comment", "//! \\breif ?\xc7\xb7???\xca\xbe??\xce\xac??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ToolTip", "! \\breif ?\xc7\xb7???\xca\xbe??\xce\xac??" },
	};
#endif
	void Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_bSkyline2D_SetBit(void* Obj)
	{
		((ASuperMap_SkylineInstance*)Obj)->m_bSkyline2D = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_bSkyline2D = { "m_bSkyline2D", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASuperMap_SkylineInstance), &Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_bSkyline2D_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_bSkyline2D_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_bSkyline2D_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_arrPoint2Ds_Inner = { "m_arrPoint2Ds", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_arrPoint2Ds_MetaData[] = {
		{ "Category", "SuperMap_SkylineInstance" },
		{ "Comment", "//! \\breif ??\xc8\xa1??\xce\xac?\xdf\xb5?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SkylineInstance.h" },
		{ "ToolTip", "! \\breif ??\xc8\xa1??\xce\xac?\xdf\xb5?" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_arrPoint2Ds = { "m_arrPoint2Ds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_SkylineInstance, m_arrPoint2Ds), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_arrPoint2Ds_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_arrPoint2Ds_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_bSkyline2D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_arrPoint2Ds_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::NewProp_m_arrPoint2Ds,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_SkylineInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::ClassParams = {
		&ASuperMap_SkylineInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_SkylineInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_SkylineInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_SkylineInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_SkylineInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_SkylineInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_SkylineInstance>()
	{
		return ASuperMap_SkylineInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_SkylineInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SkylineInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SkylineInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_SkylineInstance, ASuperMap_SkylineInstance::StaticClass, TEXT("ASuperMap_SkylineInstance"), &Z_Registration_Info_UClass_ASuperMap_SkylineInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_SkylineInstance), 4053934623U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SkylineInstance_h_145021475(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SkylineInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SkylineInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
