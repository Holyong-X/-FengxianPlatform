// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_PolyLineMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_PolyLineMeshComponent() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_PolyLineMeshComponent_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_PolyLineMeshComponent();
	ENGINE_API UClass* Z_Construct_UClass_UMeshComponent();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
	ENGINE_API UClass* Z_Construct_UClass_UInterface_CollisionDataProvider_NoRegister();
// End Cross Module References
	void USuperMap_PolyLineMeshComponent::StaticRegisterNativesUSuperMap_PolyLineMeshComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USuperMap_PolyLineMeshComponent);
	UClass* Z_Construct_UClass_USuperMap_PolyLineMeshComponent_NoRegister()
	{
		return USuperMap_PolyLineMeshComponent::StaticClass();
	}
	struct Z_Construct_UClass_USuperMap_PolyLineMeshComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USuperMap_PolyLineMeshComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMeshComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuperMap_PolyLineMeshComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "Mobility Trigger" },
		{ "IncludePath", "Component/SuperMap_PolyLineMeshComponent.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_PolyLineMeshComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_USuperMap_PolyLineMeshComponent_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInterface_CollisionDataProvider_NoRegister, (int32)VTABLE_OFFSET(USuperMap_PolyLineMeshComponent, IInterface_CollisionDataProvider), false },  // 1866130202
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USuperMap_PolyLineMeshComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USuperMap_PolyLineMeshComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USuperMap_PolyLineMeshComponent_Statics::ClassParams = {
		&USuperMap_PolyLineMeshComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USuperMap_PolyLineMeshComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USuperMap_PolyLineMeshComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USuperMap_PolyLineMeshComponent()
	{
		if (!Z_Registration_Info_UClass_USuperMap_PolyLineMeshComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USuperMap_PolyLineMeshComponent.OuterSingleton, Z_Construct_UClass_USuperMap_PolyLineMeshComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USuperMap_PolyLineMeshComponent.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<USuperMap_PolyLineMeshComponent>()
	{
		return USuperMap_PolyLineMeshComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USuperMap_PolyLineMeshComponent);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_PolyLineMeshComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_PolyLineMeshComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USuperMap_PolyLineMeshComponent, USuperMap_PolyLineMeshComponent::StaticClass, TEXT("USuperMap_PolyLineMeshComponent"), &Z_Registration_Info_UClass_USuperMap_PolyLineMeshComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USuperMap_PolyLineMeshComponent), 1966549486U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_PolyLineMeshComponent_h_2122275516(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_PolyLineMeshComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_PolyLineMeshComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
