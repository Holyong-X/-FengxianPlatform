// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_MeshComponentInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_MeshComponentInterface() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_MeshComponentInterface_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_USuperMap_MeshComponentInterface();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void USuperMap_MeshComponentInterface::StaticRegisterNativesUSuperMap_MeshComponentInterface()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USuperMap_MeshComponentInterface);
	UClass* Z_Construct_UClass_USuperMap_MeshComponentInterface_NoRegister()
	{
		return USuperMap_MeshComponentInterface::StaticClass();
	}
	struct Z_Construct_UClass_USuperMap_MeshComponentInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USuperMap_MeshComponentInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USuperMap_MeshComponentInterface_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// ??????\xce\xaa??\xcd\xac???\xcd\xb5?Mesh?\xe1\xb9\xa9\xd2\xbb????\xcd\xac???\xe2\xb2\xbf?\xd3\xbf\xda\xa3???\xca\xb5????\xd2\xbb??USceneComponent??????UMeshComponent\n" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Component/SuperMap_MeshComponentInterface.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_MeshComponentInterface.h" },
		{ "ToolTip", "??????\xce\xaa??\xcd\xac???\xcd\xb5?Mesh?\xe1\xb9\xa9\xd2\xbb????\xcd\xac???\xe2\xb2\xbf?\xd3\xbf\xda\xa3???\xca\xb5????\xd2\xbb??USceneComponent??????UMeshComponent" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USuperMap_MeshComponentInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USuperMap_MeshComponentInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USuperMap_MeshComponentInterface_Statics::ClassParams = {
		&USuperMap_MeshComponentInterface::StaticClass,
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
		0x00A000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USuperMap_MeshComponentInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USuperMap_MeshComponentInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USuperMap_MeshComponentInterface()
	{
		if (!Z_Registration_Info_UClass_USuperMap_MeshComponentInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USuperMap_MeshComponentInterface.OuterSingleton, Z_Construct_UClass_USuperMap_MeshComponentInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USuperMap_MeshComponentInterface.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<USuperMap_MeshComponentInterface>()
	{
		return USuperMap_MeshComponentInterface::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USuperMap_MeshComponentInterface);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MeshComponentInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MeshComponentInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USuperMap_MeshComponentInterface, USuperMap_MeshComponentInterface::StaticClass, TEXT("USuperMap_MeshComponentInterface"), &Z_Registration_Info_UClass_USuperMap_MeshComponentInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USuperMap_MeshComponentInterface), 496273851U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MeshComponentInterface_h_449281557(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MeshComponentInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_MeshComponentInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
