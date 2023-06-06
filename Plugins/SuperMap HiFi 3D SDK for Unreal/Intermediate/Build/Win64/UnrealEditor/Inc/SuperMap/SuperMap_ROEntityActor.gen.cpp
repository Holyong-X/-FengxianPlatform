// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_ROEntityActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ROEntityActor() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_ROEntityActor_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_ROEntityActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void ASuperMap_ROEntityActor::StaticRegisterNativesASuperMap_ROEntityActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ROEntityActor);
	UClass* Z_Construct_UClass_ASuperMap_ROEntityActor_NoRegister()
	{
		return ASuperMap_ROEntityActor::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ROEntityActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ROEntityActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ROEntityActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Component/SuperMap_ROEntityActor.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_ROEntityActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ROEntityActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ROEntityActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ROEntityActor_Statics::ClassParams = {
		&ASuperMap_ROEntityActor::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ROEntityActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ROEntityActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ROEntityActor()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ROEntityActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ROEntityActor.OuterSingleton, Z_Construct_UClass_ASuperMap_ROEntityActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ROEntityActor.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_ROEntityActor>()
	{
		return ASuperMap_ROEntityActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ROEntityActor);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_ROEntityActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_ROEntityActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ROEntityActor, ASuperMap_ROEntityActor::StaticClass, TEXT("ASuperMap_ROEntityActor"), &Z_Registration_Info_UClass_ASuperMap_ROEntityActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ROEntityActor), 1635210863U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_ROEntityActor_h_3333423785(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_ROEntityActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_ROEntityActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
