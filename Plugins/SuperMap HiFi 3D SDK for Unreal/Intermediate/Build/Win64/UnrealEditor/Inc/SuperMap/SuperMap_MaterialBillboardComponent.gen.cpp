// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_MaterialBillboardComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_MaterialBillboardComponent() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_MaterialBillboardComponent_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_MaterialBillboardComponent();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialBillboardComponent();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void USuperMap_MaterialBillboardComponent::StaticRegisterNativesUSuperMap_MaterialBillboardComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USuperMap_MaterialBillboardComponent);
	UClass* Z_Construct_UClass_USuperMap_MaterialBillboardComponent_NoRegister()
	{
		return USuperMap_MaterialBillboardComponent::StaticClass();
	}
	struct Z_Construct_UClass_USuperMap_MaterialBillboardComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USuperMap_MaterialBillboardComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMaterialBillboardComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuperMap_MaterialBillboardComponent_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object Activation Components|Activation Physics Collision Lighting Mesh PhysicsVolume Mobility VirtualTexture Trigger" },
		{ "IncludePath", "Component/SuperMap_MaterialBillboardComponent.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_MaterialBillboardComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USuperMap_MaterialBillboardComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USuperMap_MaterialBillboardComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USuperMap_MaterialBillboardComponent_Statics::ClassParams = {
		&USuperMap_MaterialBillboardComponent::StaticClass,
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
		0x00B030A4u,
		METADATA_PARAMS(Z_Construct_UClass_USuperMap_MaterialBillboardComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USuperMap_MaterialBillboardComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USuperMap_MaterialBillboardComponent()
	{
		if (!Z_Registration_Info_UClass_USuperMap_MaterialBillboardComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USuperMap_MaterialBillboardComponent.OuterSingleton, Z_Construct_UClass_USuperMap_MaterialBillboardComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USuperMap_MaterialBillboardComponent.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<USuperMap_MaterialBillboardComponent>()
	{
		return USuperMap_MaterialBillboardComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USuperMap_MaterialBillboardComponent);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MaterialBillboardComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MaterialBillboardComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USuperMap_MaterialBillboardComponent, USuperMap_MaterialBillboardComponent::StaticClass, TEXT("USuperMap_MaterialBillboardComponent"), &Z_Registration_Info_UClass_USuperMap_MaterialBillboardComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USuperMap_MaterialBillboardComponent), 2714495305U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MaterialBillboardComponent_h_72892162(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MaterialBillboardComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MaterialBillboardComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
