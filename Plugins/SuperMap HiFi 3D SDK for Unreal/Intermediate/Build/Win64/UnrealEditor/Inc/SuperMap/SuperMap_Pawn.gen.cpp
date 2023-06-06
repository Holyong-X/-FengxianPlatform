// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Editor/SuperMap_Pawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_Pawn() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_Pawn_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_Pawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
// End Cross Module References
	void ASuperMap_Pawn::StaticRegisterNativesASuperMap_Pawn()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_Pawn);
	UClass* Z_Construct_UClass_ASuperMap_Pawn_NoRegister()
	{
		return ASuperMap_Pawn::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_Pawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_Pawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_Pawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Editor/SuperMap_Pawn.h" },
		{ "ModuleRelativePath", "Public/Editor/SuperMap_Pawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_Pawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_Pawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_Pawn_Statics::ClassParams = {
		&ASuperMap_Pawn::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_Pawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_Pawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_Pawn()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_Pawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_Pawn.OuterSingleton, Z_Construct_UClass_ASuperMap_Pawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_Pawn.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_Pawn>()
	{
		return ASuperMap_Pawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_Pawn);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Pawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Pawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_Pawn, ASuperMap_Pawn::StaticClass, TEXT("ASuperMap_Pawn"), &Z_Registration_Info_UClass_ASuperMap_Pawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_Pawn), 1651578825U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Pawn_h_2733405665(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Pawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Editor_SuperMap_Pawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
