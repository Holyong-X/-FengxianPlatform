// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_FacadeInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_FacadeInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FacadeInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FacadeInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_FacadeInstance::execCreateFacade)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateFacade();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FacadeInstance::execSetOutputPath)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_strOutputPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetOutputPath(Z_Param_strOutputPath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FacadeInstance::execSetVisibleHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fMin);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fMax);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetVisibleHeight(Z_Param_fMin,Z_Param_fMax);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FacadeInstance::execSetResolution)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fResolution);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetResolution(Z_Param_fResolution);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FacadeInstance::execSetVisibleFarDistance)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fFar);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetVisibleFarDistance(Z_Param_fFar);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FacadeInstance::execBuildFacade)
	{
		P_GET_UBOOL(Z_Param_bFacade);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildFacade(Z_Param_bFacade);
		P_NATIVE_END;
	}
	void ASuperMap_FacadeInstance::StaticRegisterNativesASuperMap_FacadeInstance()
	{
		UClass* Class = ASuperMap_FacadeInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildFacade", &ASuperMap_FacadeInstance::execBuildFacade },
			{ "CreateFacade", &ASuperMap_FacadeInstance::execCreateFacade },
			{ "SetOutputPath", &ASuperMap_FacadeInstance::execSetOutputPath },
			{ "SetResolution", &ASuperMap_FacadeInstance::execSetResolution },
			{ "SetVisibleFarDistance", &ASuperMap_FacadeInstance::execSetVisibleFarDistance },
			{ "SetVisibleHeight", &ASuperMap_FacadeInstance::execSetVisibleHeight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics
	{
		struct SuperMap_FacadeInstance_eventBuildFacade_Parms
		{
			bool bFacade;
		};
		static void NewProp_bFacade_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFacade;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::NewProp_bFacade_SetBit(void* Obj)
	{
		((SuperMap_FacadeInstance_eventBuildFacade_Parms*)Obj)->bFacade = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::NewProp_bFacade = { "bFacade", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FacadeInstance_eventBuildFacade_Parms), &Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::NewProp_bFacade_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::NewProp_bFacade,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FacadeInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FacadeInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FacadeInstance, nullptr, "BuildFacade", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::SuperMap_FacadeInstance_eventBuildFacade_Parms), Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FacadeInstance_CreateFacade_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FacadeInstance_CreateFacade_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FacadeInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FacadeInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FacadeInstance_CreateFacade_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FacadeInstance, nullptr, "CreateFacade", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FacadeInstance_CreateFacade_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_CreateFacade_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FacadeInstance_CreateFacade()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FacadeInstance_CreateFacade_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics
	{
		struct SuperMap_FacadeInstance_eventSetOutputPath_Parms
		{
			FString strOutputPath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_strOutputPath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::NewProp_strOutputPath = { "strOutputPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FacadeInstance_eventSetOutputPath_Parms, strOutputPath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::NewProp_strOutputPath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FacadeInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FacadeInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FacadeInstance, nullptr, "SetOutputPath", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::SuperMap_FacadeInstance_eventSetOutputPath_Parms), Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics
	{
		struct SuperMap_FacadeInstance_eventSetResolution_Parms
		{
			float fResolution;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fResolution;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::NewProp_fResolution = { "fResolution", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FacadeInstance_eventSetResolution_Parms, fResolution), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::NewProp_fResolution,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FacadeInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FacadeInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FacadeInstance, nullptr, "SetResolution", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::SuperMap_FacadeInstance_eventSetResolution_Parms), Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics
	{
		struct SuperMap_FacadeInstance_eventSetVisibleFarDistance_Parms
		{
			float fFar;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fFar;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::NewProp_fFar = { "fFar", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FacadeInstance_eventSetVisibleFarDistance_Parms, fFar), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::NewProp_fFar,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FacadeInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FacadeInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FacadeInstance, nullptr, "SetVisibleFarDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::SuperMap_FacadeInstance_eventSetVisibleFarDistance_Parms), Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics
	{
		struct SuperMap_FacadeInstance_eventSetVisibleHeight_Parms
		{
			float fMin;
			float fMax;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fMin;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fMax;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::NewProp_fMin = { "fMin", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FacadeInstance_eventSetVisibleHeight_Parms, fMin), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::NewProp_fMax = { "fMax", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FacadeInstance_eventSetVisibleHeight_Parms, fMax), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::NewProp_fMin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::NewProp_fMax,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FacadeInstance" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FacadeInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FacadeInstance, nullptr, "SetVisibleHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::SuperMap_FacadeInstance_eventSetVisibleHeight_Parms), Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_FacadeInstance);
	UClass* Z_Construct_UClass_ASuperMap_FacadeInstance_NoRegister()
	{
		return ASuperMap_FacadeInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_FacadeInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_FacadeInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_FacadeInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_FacadeInstance_BuildFacade, "BuildFacade" }, // 1334146057
		{ &Z_Construct_UFunction_ASuperMap_FacadeInstance_CreateFacade, "CreateFacade" }, // 2834080554
		{ &Z_Construct_UFunction_ASuperMap_FacadeInstance_SetOutputPath, "SetOutputPath" }, // 679221300
		{ &Z_Construct_UFunction_ASuperMap_FacadeInstance_SetResolution, "SetResolution" }, // 627883314
		{ &Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleFarDistance, "SetVisibleFarDistance" }, // 679306609
		{ &Z_Construct_UFunction_ASuperMap_FacadeInstance_SetVisibleHeight, "SetVisibleHeight" }, // 2819972698
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_FacadeInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_FacadeInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FacadeInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_FacadeInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_FacadeInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_FacadeInstance_Statics::ClassParams = {
		&ASuperMap_FacadeInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_FacadeInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_FacadeInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_FacadeInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_FacadeInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_FacadeInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_FacadeInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_FacadeInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_FacadeInstance>()
	{
		return ASuperMap_FacadeInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_FacadeInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FacadeInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FacadeInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_FacadeInstance, ASuperMap_FacadeInstance::StaticClass, TEXT("ASuperMap_FacadeInstance"), &Z_Registration_Info_UClass_ASuperMap_FacadeInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_FacadeInstance), 1713453530U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FacadeInstance_h_232275585(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FacadeInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FacadeInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
