// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Editor/SuperMap_PlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_PlayerController() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_PlayerController_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_PlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void ASuperMap_PlayerController::StaticRegisterNativesASuperMap_PlayerController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_PlayerController);
	UClass* Z_Construct_UClass_ASuperMap_PlayerController_NoRegister()
	{
		return ASuperMap_PlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_PlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_PlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_PlayerController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Editor/SuperMap_PlayerController.h" },
		{ "ModuleRelativePath", "Public/Editor/SuperMap_PlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_PlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_PlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_PlayerController_Statics::ClassParams = {
		&ASuperMap_PlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_PlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_PlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_PlayerController()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_PlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_PlayerController.OuterSingleton, Z_Construct_UClass_ASuperMap_PlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_PlayerController.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_PlayerController>()
	{
		return ASuperMap_PlayerController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_PlayerController);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_PlayerController, ASuperMap_PlayerController::StaticClass, TEXT("ASuperMap_PlayerController"), &Z_Registration_Info_UClass_ASuperMap_PlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_PlayerController), 3360959611U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerController_h_1759458196(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
