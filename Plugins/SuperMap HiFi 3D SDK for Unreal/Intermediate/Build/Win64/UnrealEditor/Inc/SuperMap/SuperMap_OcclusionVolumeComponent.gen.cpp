// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_OcclusionVolumeComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_OcclusionVolumeComponent() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_OcclusionVolumeComponent();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void USuperMap_OcclusionVolumeComponent::StaticRegisterNativesUSuperMap_OcclusionVolumeComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USuperMap_OcclusionVolumeComponent);
	UClass* Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_NoRegister()
	{
		return USuperMap_OcclusionVolumeComponent::StaticClass();
	}
	struct Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrimitiveComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Mobility VirtualTexture Trigger" },
		{ "IncludePath", "Component/SuperMap_OcclusionVolumeComponent.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_OcclusionVolumeComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USuperMap_OcclusionVolumeComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_Statics::ClassParams = {
		&USuperMap_OcclusionVolumeComponent::StaticClass,
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
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USuperMap_OcclusionVolumeComponent()
	{
		if (!Z_Registration_Info_UClass_USuperMap_OcclusionVolumeComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USuperMap_OcclusionVolumeComponent.OuterSingleton, Z_Construct_UClass_USuperMap_OcclusionVolumeComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USuperMap_OcclusionVolumeComponent.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<USuperMap_OcclusionVolumeComponent>()
	{
		return USuperMap_OcclusionVolumeComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USuperMap_OcclusionVolumeComponent);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_OcclusionVolumeComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_OcclusionVolumeComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USuperMap_OcclusionVolumeComponent, USuperMap_OcclusionVolumeComponent::StaticClass, TEXT("USuperMap_OcclusionVolumeComponent"), &Z_Registration_Info_UClass_USuperMap_OcclusionVolumeComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USuperMap_OcclusionVolumeComponent), 2618194927U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_OcclusionVolumeComponent_h_3195348874(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_OcclusionVolumeComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_OcclusionVolumeComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
