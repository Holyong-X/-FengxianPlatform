// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_BillboardComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_BillboardComponent() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_BillboardComponent_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_BillboardComponent();
	ENGINE_API UClass* Z_Construct_UClass_UMeshComponent();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void USuperMap_BillboardComponent::StaticRegisterNativesUSuperMap_BillboardComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USuperMap_BillboardComponent);
	UClass* Z_Construct_UClass_USuperMap_BillboardComponent_NoRegister()
	{
		return USuperMap_BillboardComponent::StaticClass();
	}
	struct Z_Construct_UClass_USuperMap_BillboardComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USuperMap_BillboardComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMeshComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuperMap_BillboardComponent_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Mobility Trigger" },
		{ "IncludePath", "Component/SuperMap_BillboardComponent.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_BillboardComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USuperMap_BillboardComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USuperMap_BillboardComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USuperMap_BillboardComponent_Statics::ClassParams = {
		&USuperMap_BillboardComponent::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_USuperMap_BillboardComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USuperMap_BillboardComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USuperMap_BillboardComponent()
	{
		if (!Z_Registration_Info_UClass_USuperMap_BillboardComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USuperMap_BillboardComponent.OuterSingleton, Z_Construct_UClass_USuperMap_BillboardComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USuperMap_BillboardComponent.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<USuperMap_BillboardComponent>()
	{
		return USuperMap_BillboardComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USuperMap_BillboardComponent);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USuperMap_BillboardComponent, USuperMap_BillboardComponent::StaticClass, TEXT("USuperMap_BillboardComponent"), &Z_Registration_Info_UClass_USuperMap_BillboardComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USuperMap_BillboardComponent), 1630347634U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardComponent_h_3446895345(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
