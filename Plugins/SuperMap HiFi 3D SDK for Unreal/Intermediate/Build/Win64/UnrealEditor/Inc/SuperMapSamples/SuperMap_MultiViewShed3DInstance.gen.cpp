// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_MultiViewShed3DInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_MultiViewShed3DInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_AddViewShed3DDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_AddViewShed3DDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_AddViewShed3DDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_MultiViewShed3DInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_AddViewShed3DDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "AddViewShed3DDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_AddViewShed3DDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_AddViewShed3DDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_AddViewShed3DDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_AddViewShed3DDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_MultiViewShed3DInstance::execRemoveViewShed3D)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_viewshedName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveViewShed3D(Z_Param_viewshedName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MultiViewShed3DInstance::execAddViewShed3D)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_viewshedName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddViewShed3D(Z_Param_viewshedName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_MultiViewShed3DInstance::execBuildMultiViewShed3D)
	{
		P_GET_UBOOL(Z_Param_bMultiViewShed3D);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildMultiViewShed3D(Z_Param_bMultiViewShed3D);
		P_NATIVE_END;
	}
	void ASuperMap_MultiViewShed3DInstance::StaticRegisterNativesASuperMap_MultiViewShed3DInstance()
	{
		UClass* Class = ASuperMap_MultiViewShed3DInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddViewShed3D", &ASuperMap_MultiViewShed3DInstance::execAddViewShed3D },
			{ "BuildMultiViewShed3D", &ASuperMap_MultiViewShed3DInstance::execBuildMultiViewShed3D },
			{ "RemoveViewShed3D", &ASuperMap_MultiViewShed3DInstance::execRemoveViewShed3D },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics
	{
		struct SuperMap_MultiViewShed3DInstance_eventAddViewShed3D_Parms
		{
			FString viewshedName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_viewshedName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::NewProp_viewshedName = { "viewshedName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MultiViewShed3DInstance_eventAddViewShed3D_Parms, viewshedName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::NewProp_viewshedName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MultiViewShed3DInstance" },
		{ "Comment", "//! \\brief ???\xd3\xbf?????????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_MultiViewShed3DInstance.h" },
		{ "ToolTip", "! \\brief ???\xd3\xbf?????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance, nullptr, "AddViewShed3D", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::SuperMap_MultiViewShed3DInstance_eventAddViewShed3D_Parms), Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics
	{
		struct SuperMap_MultiViewShed3DInstance_eventBuildMultiViewShed3D_Parms
		{
			bool bMultiViewShed3D;
		};
		static void NewProp_bMultiViewShed3D_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bMultiViewShed3D;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::NewProp_bMultiViewShed3D_SetBit(void* Obj)
	{
		((SuperMap_MultiViewShed3DInstance_eventBuildMultiViewShed3D_Parms*)Obj)->bMultiViewShed3D = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::NewProp_bMultiViewShed3D = { "bMultiViewShed3D", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_MultiViewShed3DInstance_eventBuildMultiViewShed3D_Parms), &Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::NewProp_bMultiViewShed3D_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::NewProp_bMultiViewShed3D,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MultiViewShed3DInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7?????????????????\n//! \\param bclip [in] true??\xca\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_MultiViewShed3DInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7?????????????????\n! \\param bclip [in] true??\xca\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance, nullptr, "BuildMultiViewShed3D", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::SuperMap_MultiViewShed3DInstance_eventBuildMultiViewShed3D_Parms), Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics
	{
		struct SuperMap_MultiViewShed3DInstance_eventRemoveViewShed3D_Parms
		{
			FString viewshedName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_viewshedName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::NewProp_viewshedName = { "viewshedName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_MultiViewShed3DInstance_eventRemoveViewShed3D_Parms, viewshedName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::NewProp_viewshedName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_MultiViewShed3DInstance" },
		{ "Comment", "//! \\brief ???\xd3\xbf?????????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_MultiViewShed3DInstance.h" },
		{ "ToolTip", "! \\brief ???\xd3\xbf?????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance, nullptr, "RemoveViewShed3D", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::SuperMap_MultiViewShed3DInstance_eventRemoveViewShed3D_Parms), Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_MultiViewShed3DInstance);
	UClass* Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_NoRegister()
	{
		return ASuperMap_MultiViewShed3DInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallAddViewShed3D_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallAddViewShed3D;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_AddViewShed3D, "AddViewShed3D" }, // 2455492781
		{ &Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_BuildMultiViewShed3D, "BuildMultiViewShed3D" }, // 294083380
		{ &Z_Construct_UFunction_ASuperMap_MultiViewShed3DInstance_RemoveViewShed3D, "RemoveViewShed3D" }, // 1001400116
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_MultiViewShed3DInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_MultiViewShed3DInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::NewProp_CallAddViewShed3D_MetaData[] = {
		{ "Comment", "//??\xcd\xbc?????\xc2\xbc?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_MultiViewShed3DInstance.h" },
		{ "ToolTip", "??\xcd\xbc?????\xc2\xbc?" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::NewProp_CallAddViewShed3D = { "CallAddViewShed3D", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_MultiViewShed3DInstance, CallAddViewShed3D), Z_Construct_UDelegateFunction_SuperMapSamples_AddViewShed3DDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::NewProp_CallAddViewShed3D_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::NewProp_CallAddViewShed3D_MetaData)) }; // 759145840
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::NewProp_CallAddViewShed3D,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_MultiViewShed3DInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::ClassParams = {
		&ASuperMap_MultiViewShed3DInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_MultiViewShed3DInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_MultiViewShed3DInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_MultiViewShed3DInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_MultiViewShed3DInstance>()
	{
		return ASuperMap_MultiViewShed3DInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_MultiViewShed3DInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_MultiViewShed3DInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_MultiViewShed3DInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_MultiViewShed3DInstance, ASuperMap_MultiViewShed3DInstance::StaticClass, TEXT("ASuperMap_MultiViewShed3DInstance"), &Z_Registration_Info_UClass_ASuperMap_MultiViewShed3DInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_MultiViewShed3DInstance), 2886750880U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_MultiViewShed3DInstance_h_810396592(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_MultiViewShed3DInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_MultiViewShed3DInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
