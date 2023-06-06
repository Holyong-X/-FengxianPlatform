// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_StaticMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_StaticMeshComponent() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_StaticMeshComponent_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_StaticMeshComponent();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void USuperMap_StaticMeshComponent::StaticRegisterNativesUSuperMap_StaticMeshComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USuperMap_StaticMeshComponent);
	UClass* Z_Construct_UClass_USuperMap_StaticMeshComponent_NoRegister()
	{
		return USuperMap_StaticMeshComponent::StaticClass();
	}
	struct Z_Construct_UClass_USuperMap_StaticMeshComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USuperMap_StaticMeshComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UStaticMeshComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuperMap_StaticMeshComponent_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object Activation Components|Activation Trigger" },
		{ "IncludePath", "Component/SuperMap_StaticMeshComponent.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USuperMap_StaticMeshComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USuperMap_StaticMeshComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USuperMap_StaticMeshComponent_Statics::ClassParams = {
		&USuperMap_StaticMeshComponent::StaticClass,
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
		0x00B010A4u,
		METADATA_PARAMS(Z_Construct_UClass_USuperMap_StaticMeshComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USuperMap_StaticMeshComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USuperMap_StaticMeshComponent()
	{
		if (!Z_Registration_Info_UClass_USuperMap_StaticMeshComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USuperMap_StaticMeshComponent.OuterSingleton, Z_Construct_UClass_USuperMap_StaticMeshComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USuperMap_StaticMeshComponent.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<USuperMap_StaticMeshComponent>()
	{
		return USuperMap_StaticMeshComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USuperMap_StaticMeshComponent);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USuperMap_StaticMeshComponent, USuperMap_StaticMeshComponent::StaticClass, TEXT("USuperMap_StaticMeshComponent"), &Z_Registration_Info_UClass_USuperMap_StaticMeshComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USuperMap_StaticMeshComponent), 2355807037U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshComponent_h_3984967239(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
