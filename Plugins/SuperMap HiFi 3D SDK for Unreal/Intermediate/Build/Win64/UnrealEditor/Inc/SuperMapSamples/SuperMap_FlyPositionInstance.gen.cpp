// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SceneOperation/SuperMap_FlyPositionInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_FlyPositionInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FlyPositionInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FlyPositionInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_FlyPositionInstance::execDestroyFlyPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DestroyFlyPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyPositionInstance::execSetFlyPositionParamsFromCamera)
	{
		P_GET_STRUCT(FVector,Z_Param_vCameraLocation);
		P_GET_STRUCT(FRotator,Z_Param_vCameraRotator);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFlyPositionParamsFromCamera(Z_Param_vCameraLocation,Z_Param_vCameraRotator);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyPositionInstance::execSetFlyPositionParams)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fLongitude);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fLatitude);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fAltitude);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fPitch);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fHeading);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fRoll);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFlyPositionParams(Z_Param_fLongitude,Z_Param_fLatitude,Z_Param_fAltitude,Z_Param_fPitch,Z_Param_fHeading,Z_Param_fRoll);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyPositionInstance::execSetFlyTime)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_dDuration);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFlyTime(Z_Param_dDuration);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyPositionInstance::execLaunchFlyPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LaunchFlyPosition();
		P_NATIVE_END;
	}
	void ASuperMap_FlyPositionInstance::StaticRegisterNativesASuperMap_FlyPositionInstance()
	{
		UClass* Class = ASuperMap_FlyPositionInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DestroyFlyPosition", &ASuperMap_FlyPositionInstance::execDestroyFlyPosition },
			{ "LaunchFlyPosition", &ASuperMap_FlyPositionInstance::execLaunchFlyPosition },
			{ "SetFlyPositionParams", &ASuperMap_FlyPositionInstance::execSetFlyPositionParams },
			{ "SetFlyPositionParamsFromCamera", &ASuperMap_FlyPositionInstance::execSetFlyPositionParamsFromCamera },
			{ "SetFlyTime", &ASuperMap_FlyPositionInstance::execSetFlyTime },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_FlyPositionInstance_DestroyFlyPosition_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyPositionInstance_DestroyFlyPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyPositionInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_DestroyFlyPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyPositionInstance, nullptr, "DestroyFlyPosition", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_DestroyFlyPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_DestroyFlyPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyPositionInstance_DestroyFlyPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyPositionInstance_DestroyFlyPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyPositionInstance_LaunchFlyPosition_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyPositionInstance_LaunchFlyPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyPositionInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_LaunchFlyPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyPositionInstance, nullptr, "LaunchFlyPosition", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_LaunchFlyPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_LaunchFlyPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyPositionInstance_LaunchFlyPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyPositionInstance_LaunchFlyPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics
	{
		struct SuperMap_FlyPositionInstance_eventSetFlyPositionParams_Parms
		{
			float fLongitude;
			float fLatitude;
			float fAltitude;
			float fPitch;
			float fHeading;
			float fRoll;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fLongitude;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fLatitude;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fAltitude;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fPitch;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fHeading;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fRoll;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fLongitude = { "fLongitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyPositionInstance_eventSetFlyPositionParams_Parms, fLongitude), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fLatitude = { "fLatitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyPositionInstance_eventSetFlyPositionParams_Parms, fLatitude), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fAltitude = { "fAltitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyPositionInstance_eventSetFlyPositionParams_Parms, fAltitude), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fPitch = { "fPitch", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyPositionInstance_eventSetFlyPositionParams_Parms, fPitch), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fHeading = { "fHeading", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyPositionInstance_eventSetFlyPositionParams_Parms, fHeading), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fRoll = { "fRoll", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyPositionInstance_eventSetFlyPositionParams_Parms, fRoll), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fLongitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fLatitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fAltitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fPitch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fHeading,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::NewProp_fRoll,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyPositionInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyPositionInstance, nullptr, "SetFlyPositionParams", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::SuperMap_FlyPositionInstance_eventSetFlyPositionParams_Parms), Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics
	{
		struct SuperMap_FlyPositionInstance_eventSetFlyPositionParamsFromCamera_Parms
		{
			FVector vCameraLocation;
			FRotator vCameraRotator;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_vCameraLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_vCameraRotator;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::NewProp_vCameraLocation = { "vCameraLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyPositionInstance_eventSetFlyPositionParamsFromCamera_Parms, vCameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::NewProp_vCameraRotator = { "vCameraRotator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyPositionInstance_eventSetFlyPositionParamsFromCamera_Parms, vCameraRotator), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::NewProp_vCameraLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::NewProp_vCameraRotator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyPositionInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyPositionInstance, nullptr, "SetFlyPositionParamsFromCamera", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::SuperMap_FlyPositionInstance_eventSetFlyPositionParamsFromCamera_Parms), Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics
	{
		struct SuperMap_FlyPositionInstance_eventSetFlyTime_Parms
		{
			float dDuration;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_dDuration;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::NewProp_dDuration = { "dDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyPositionInstance_eventSetFlyTime_Parms, dDuration), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::NewProp_dDuration,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyPositionInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyPositionInstance, nullptr, "SetFlyTime", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::SuperMap_FlyPositionInstance_eventSetFlyTime_Parms), Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_FlyPositionInstance);
	UClass* Z_Construct_UClass_ASuperMap_FlyPositionInstance_NoRegister()
	{
		return ASuperMap_FlyPositionInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_FlyPositionInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_FlyPositionInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_FlyPositionInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_FlyPositionInstance_DestroyFlyPosition, "DestroyFlyPosition" }, // 2181888907
		{ &Z_Construct_UFunction_ASuperMap_FlyPositionInstance_LaunchFlyPosition, "LaunchFlyPosition" }, // 2240469554
		{ &Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParams, "SetFlyPositionParams" }, // 3201351599
		{ &Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyPositionParamsFromCamera, "SetFlyPositionParamsFromCamera" }, // 3867361564
		{ &Z_Construct_UFunction_ASuperMap_FlyPositionInstance_SetFlyTime, "SetFlyTime" }, // 2997739252
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_FlyPositionInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SceneOperation/SuperMap_FlyPositionInstance.h" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyPositionInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_FlyPositionInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_FlyPositionInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_FlyPositionInstance_Statics::ClassParams = {
		&ASuperMap_FlyPositionInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_FlyPositionInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_FlyPositionInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_FlyPositionInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_FlyPositionInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_FlyPositionInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_FlyPositionInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_FlyPositionInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_FlyPositionInstance>()
	{
		return ASuperMap_FlyPositionInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_FlyPositionInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyPositionInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyPositionInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_FlyPositionInstance, ASuperMap_FlyPositionInstance::StaticClass, TEXT("ASuperMap_FlyPositionInstance"), &Z_Registration_Info_UClass_ASuperMap_FlyPositionInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_FlyPositionInstance), 305254055U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyPositionInstance_h_1340124050(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyPositionInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyPositionInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
