// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MtlAnalyzer/Public/MtlAnalyzer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMtlAnalyzer() {}
// Cross Module References
	MTLANALYZER_API UClass* Z_Construct_UClass_UMtlAnalyzer_NoRegister();
	MTLANALYZER_API UClass* Z_Construct_UClass_UMtlAnalyzer();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface();
	UPackage* Z_Construct_UPackage__Script_MtlAnalyzer();
// End Cross Module References
	void UMtlAnalyzer::StaticRegisterNativesUMtlAnalyzer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMtlAnalyzer);
	UClass* Z_Construct_UClass_UMtlAnalyzer_NoRegister()
	{
		return UMtlAnalyzer::StaticClass();
	}
	struct Z_Construct_UClass_UMtlAnalyzer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMtlAnalyzer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMaterialInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_MtlAnalyzer,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMtlAnalyzer_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Thumbnail" },
		{ "IncludePath", "MtlAnalyzer.h" },
		{ "ModuleRelativePath", "Public/MtlAnalyzer.h" },
		{ "NotBlueprintType", "true" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMtlAnalyzer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMtlAnalyzer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMtlAnalyzer_Statics::ClassParams = {
		&UMtlAnalyzer::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UMtlAnalyzer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMtlAnalyzer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMtlAnalyzer()
	{
		if (!Z_Registration_Info_UClass_UMtlAnalyzer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMtlAnalyzer.OuterSingleton, Z_Construct_UClass_UMtlAnalyzer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMtlAnalyzer.OuterSingleton;
	}
	template<> MTLANALYZER_API UClass* StaticClass<UMtlAnalyzer>()
	{
		return UMtlAnalyzer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMtlAnalyzer);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_MtlAnalyzer_Public_MtlAnalyzer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_MtlAnalyzer_Public_MtlAnalyzer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMtlAnalyzer, UMtlAnalyzer::StaticClass, TEXT("UMtlAnalyzer"), &Z_Registration_Info_UClass_UMtlAnalyzer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMtlAnalyzer), 2439151919U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_MtlAnalyzer_Public_MtlAnalyzer_h_139168182(TEXT("/Script/MtlAnalyzer"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_MtlAnalyzer_Public_MtlAnalyzer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_MtlAnalyzer_Public_MtlAnalyzer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
