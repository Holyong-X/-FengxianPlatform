// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_SightlineInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_SightlineInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_SightlineDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_SightlineInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_SightlineInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_SightlineDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_SightlineDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SightlineInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_SightlineDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "SightlineDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_SightlineDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_SightlineDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_SightlineDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_SightlineDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_SightlineInstance::execIsShowViewerPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsShowViewerPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SightlineInstance::execGetViewerPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetViewerPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SightlineInstance::execSetIsSightline)
	{
		P_GET_UBOOL(Z_Param_bsightline);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsSightline(Z_Param_bsightline);
		P_NATIVE_END;
	}
	void ASuperMap_SightlineInstance::StaticRegisterNativesASuperMap_SightlineInstance()
	{
		UClass* Class = ASuperMap_SightlineInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetViewerPosition", &ASuperMap_SightlineInstance::execGetViewerPosition },
			{ "IsShowViewerPosition", &ASuperMap_SightlineInstance::execIsShowViewerPosition },
			{ "SetIsSightline", &ASuperMap_SightlineInstance::execSetIsSightline },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics
	{
		struct SuperMap_SightlineInstance_eventGetViewerPosition_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SightlineInstance_eventGetViewerPosition_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SightlineInstance" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe8\xa7\x82\xe5\xaf\x9f\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SightlineInstance.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe8\xa7\x82\xe5\xaf\x9f\xe7\x82\xb9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SightlineInstance, nullptr, "GetViewerPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::SuperMap_SightlineInstance_eventGetViewerPosition_Parms), Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics
	{
		struct SuperMap_SightlineInstance_eventIsShowViewerPosition_Parms
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
	void Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_SightlineInstance_eventIsShowViewerPosition_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_SightlineInstance_eventIsShowViewerPosition_Parms), &Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SightlineInstance" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe8\xa7\x82\xe5\xaf\x9f\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SightlineInstance.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe6\x98\xbe\xe7\xa4\xba\xe8\xa7\x82\xe5\xaf\x9f\xe7\x82\xb9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SightlineInstance, nullptr, "IsShowViewerPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::SuperMap_SightlineInstance_eventIsShowViewerPosition_Parms), Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics
	{
		struct SuperMap_SightlineInstance_eventSetIsSightline_Parms
		{
			bool bsightline;
		};
		static void NewProp_bsightline_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bsightline;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::NewProp_bsightline_SetBit(void* Obj)
	{
		((SuperMap_SightlineInstance_eventSetIsSightline_Parms*)Obj)->bsightline = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::NewProp_bsightline = { "bsightline", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_SightlineInstance_eventSetIsSightline_Parms), &Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::NewProp_bsightline_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::NewProp_bsightline,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SightlineInstance" },
		{ "Comment", "//! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe8\xa7\x86\xe9\x80\x9a\xe5\x88\x86\xe6\x9e\x90\n//! \\param bclip [in] true\xe5\xbc\x80\xe5\xa7\x8b\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SightlineInstance.h" },
		{ "ToolTip", "! \\brief \xe6\x98\xaf\xe5\x90\xa6\xe8\xa7\x86\xe9\x80\x9a\xe5\x88\x86\xe6\x9e\x90\n! \\param bclip [in] true\xe5\xbc\x80\xe5\xa7\x8b" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SightlineInstance, nullptr, "SetIsSightline", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::SuperMap_SightlineInstance_eventSetIsSightline_Parms), Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_SightlineInstance);
	UClass* Z_Construct_UClass_ASuperMap_SightlineInstance_NoRegister()
	{
		return ASuperMap_SightlineInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_SightlineInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallSightline_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallSightline;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_SightlineInstance_GetViewerPosition, "GetViewerPosition" }, // 3276794981
		{ &Z_Construct_UFunction_ASuperMap_SightlineInstance_IsShowViewerPosition, "IsShowViewerPosition" }, // 1783317895
		{ &Z_Construct_UFunction_ASuperMap_SightlineInstance_SetIsSightline, "SetIsSightline" }, // 225940581
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_SightlineInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SightlineInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::NewProp_CallSightline_MetaData[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_SightlineInstance.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::NewProp_CallSightline = { "CallSightline", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_SightlineInstance, CallSightline), Z_Construct_UDelegateFunction_SuperMapSamples_SightlineDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::NewProp_CallSightline_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::NewProp_CallSightline_MetaData)) }; // 2009389919
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::NewProp_CallSightline,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_SightlineInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::ClassParams = {
		&ASuperMap_SightlineInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_SightlineInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_SightlineInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_SightlineInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_SightlineInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_SightlineInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_SightlineInstance>()
	{
		return ASuperMap_SightlineInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_SightlineInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SightlineInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SightlineInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_SightlineInstance, ASuperMap_SightlineInstance::StaticClass, TEXT("ASuperMap_SightlineInstance"), &Z_Registration_Info_UClass_ASuperMap_SightlineInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_SightlineInstance), 2304752249U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SightlineInstance_h_1313591817(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SightlineInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_SightlineInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
