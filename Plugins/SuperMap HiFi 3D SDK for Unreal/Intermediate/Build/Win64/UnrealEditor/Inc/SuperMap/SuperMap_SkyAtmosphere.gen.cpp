// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Editor/SuperMap_SkyAtmosphere.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_SkyAtmosphere() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_SkyAtmosphere_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_SkyAtmosphere();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void ASuperMap_SkyAtmosphere::StaticRegisterNativesASuperMap_SkyAtmosphere()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_SkyAtmosphere);
	UClass* Z_Construct_UClass_ASuperMap_SkyAtmosphere_NoRegister()
	{
		return ASuperMap_SkyAtmosphere::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_SkyAtmosphere_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_SkyAtmosphere_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SkyAtmosphere_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Editor/SuperMap_SkyAtmosphere.h" },
		{ "ModuleRelativePath", "Public/Editor/SuperMap_SkyAtmosphere.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_SkyAtmosphere_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_SkyAtmosphere>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_SkyAtmosphere_Statics::ClassParams = {
		&ASuperMap_SkyAtmosphere::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SkyAtmosphere_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SkyAtmosphere_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_SkyAtmosphere()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_SkyAtmosphere.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_SkyAtmosphere.OuterSingleton, Z_Construct_UClass_ASuperMap_SkyAtmosphere_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_SkyAtmosphere.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_SkyAtmosphere>()
	{
		return ASuperMap_SkyAtmosphere::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_SkyAtmosphere);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_SkyAtmosphere_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_SkyAtmosphere_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_SkyAtmosphere, ASuperMap_SkyAtmosphere::StaticClass, TEXT("ASuperMap_SkyAtmosphere"), &Z_Registration_Info_UClass_ASuperMap_SkyAtmosphere, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_SkyAtmosphere), 1997441815U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_SkyAtmosphere_h_3823698391(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_SkyAtmosphere_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_SkyAtmosphere_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
