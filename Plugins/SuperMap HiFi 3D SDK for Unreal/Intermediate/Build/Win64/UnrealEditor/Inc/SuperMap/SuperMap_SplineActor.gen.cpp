// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_SplineActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_SplineActor() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_SplineActor_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_SplineActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
// End Cross Module References
	void ASuperMap_SplineActor::StaticRegisterNativesASuperMap_SplineActor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_SplineActor);
	UClass* Z_Construct_UClass_ASuperMap_SplineActor_NoRegister()
	{
		return ASuperMap_SplineActor::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_SplineActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_pSplineStaticMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_pSplineStaticMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_pSpline_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_pSpline;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_SplineActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SplineActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Component/SuperMap_SplineActor.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_SplineActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSplineStaticMesh_MetaData[] = {
		{ "Category", "SuperMap_SplineActor" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_SplineActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSplineStaticMesh = { "m_pSplineStaticMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_SplineActor, m_pSplineStaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSplineStaticMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSplineStaticMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSpline_MetaData[] = {
		{ "Category", "SuperMap_SplineActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_SplineActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSpline = { "m_pSpline", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_SplineActor, m_pSpline), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSpline_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSpline_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_SplineActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSplineStaticMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_SplineActor_Statics::NewProp_m_pSpline,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_SplineActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_SplineActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_SplineActor_Statics::ClassParams = {
		&ASuperMap_SplineActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASuperMap_SplineActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SplineActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SplineActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SplineActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_SplineActor()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_SplineActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_SplineActor.OuterSingleton, Z_Construct_UClass_ASuperMap_SplineActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_SplineActor.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_SplineActor>()
	{
		return ASuperMap_SplineActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_SplineActor);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SplineActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SplineActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_SplineActor, ASuperMap_SplineActor::StaticClass, TEXT("ASuperMap_SplineActor"), &Z_Registration_Info_UClass_ASuperMap_SplineActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_SplineActor), 477620947U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SplineActor_h_3270928352(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SplineActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SplineActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
