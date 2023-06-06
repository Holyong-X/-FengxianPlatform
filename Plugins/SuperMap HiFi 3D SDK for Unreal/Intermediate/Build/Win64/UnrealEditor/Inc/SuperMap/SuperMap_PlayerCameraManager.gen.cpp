// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Editor/SuperMap_PlayerCameraManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_PlayerCameraManager() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_PlayerCameraManager_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_PlayerCameraManager();
	ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void ASuperMap_PlayerCameraManager::StaticRegisterNativesASuperMap_PlayerCameraManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_PlayerCameraManager);
	UClass* Z_Construct_UClass_ASuperMap_PlayerCameraManager_NoRegister()
	{
		return ASuperMap_PlayerCameraManager::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_PlayerCameraManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_PlayerCameraManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_PlayerCameraManager_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "Editor/SuperMap_PlayerCameraManager.h" },
		{ "ModuleRelativePath", "Public/Editor/SuperMap_PlayerCameraManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_PlayerCameraManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_PlayerCameraManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_PlayerCameraManager_Statics::ClassParams = {
		&ASuperMap_PlayerCameraManager::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_PlayerCameraManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_PlayerCameraManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_PlayerCameraManager()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_PlayerCameraManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_PlayerCameraManager.OuterSingleton, Z_Construct_UClass_ASuperMap_PlayerCameraManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_PlayerCameraManager.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_PlayerCameraManager>()
	{
		return ASuperMap_PlayerCameraManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_PlayerCameraManager);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerCameraManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerCameraManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_PlayerCameraManager, ASuperMap_PlayerCameraManager::StaticClass, TEXT("ASuperMap_PlayerCameraManager"), &Z_Registration_Info_UClass_ASuperMap_PlayerCameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_PlayerCameraManager), 7613935U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerCameraManager_h_3405503907(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerCameraManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_PlayerCameraManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
