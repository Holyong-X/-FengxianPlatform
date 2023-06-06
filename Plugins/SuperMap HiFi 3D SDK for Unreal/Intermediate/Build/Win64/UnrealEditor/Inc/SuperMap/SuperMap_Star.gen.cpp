// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Editor/SuperMap_Star.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_Star() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_Star_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_Star();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void ASuperMap_Star::StaticRegisterNativesASuperMap_Star()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_Star);
	UClass* Z_Construct_UClass_ASuperMap_Star_NoRegister()
	{
		return ASuperMap_Star::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_Star_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_Star_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_Star_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Editor/SuperMap_Star.h" },
		{ "ModuleRelativePath", "Public/Editor/SuperMap_Star.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_Star_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_Star>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_Star_Statics::ClassParams = {
		&ASuperMap_Star::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_Star_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_Star_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_Star()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_Star.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_Star.OuterSingleton, Z_Construct_UClass_ASuperMap_Star_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_Star.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_Star>()
	{
		return ASuperMap_Star::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_Star);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Star_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Star_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_Star, ASuperMap_Star::StaticClass, TEXT("ASuperMap_Star"), &Z_Registration_Info_UClass_ASuperMap_Star, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_Star), 2783962112U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Star_h_845923436(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Star_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Star_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
