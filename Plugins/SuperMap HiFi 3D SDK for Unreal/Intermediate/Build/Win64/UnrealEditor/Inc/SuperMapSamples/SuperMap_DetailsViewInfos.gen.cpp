// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/Toolkit/SuperMap_DetailsViewInfos.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_DetailsViewInfos() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_DetailsViewInfos_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_DetailsViewInfos();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector4();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_DetailsViewInfos::execSetMaterialUVTiling)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_LayerName);
		P_GET_PROPERTY(FStrProperty,Z_Param_OriMaterialName);
		P_GET_STRUCT(FVector4,Z_Param_UVOffsetAndScale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaterialUVTiling(Z_Param_LayerName,Z_Param_OriMaterialName,Z_Param_UVOffsetAndScale);
		P_NATIVE_END;
	}
	void ASuperMap_DetailsViewInfos::StaticRegisterNativesASuperMap_DetailsViewInfos()
	{
		UClass* Class = ASuperMap_DetailsViewInfos::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetMaterialUVTiling", &ASuperMap_DetailsViewInfos::execSetMaterialUVTiling },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics
	{
		struct SuperMap_DetailsViewInfos_eventSetMaterialUVTiling_Parms
		{
			FString LayerName;
			FString OriMaterialName;
			FVector4 UVOffsetAndScale;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_LayerName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_OriMaterialName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_UVOffsetAndScale;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::NewProp_LayerName = { "LayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DetailsViewInfos_eventSetMaterialUVTiling_Parms, LayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::NewProp_OriMaterialName = { "OriMaterialName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DetailsViewInfos_eventSetMaterialUVTiling_Parms, OriMaterialName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::NewProp_UVOffsetAndScale = { "UVOffsetAndScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_DetailsViewInfos_eventSetMaterialUVTiling_Parms, UVOffsetAndScale), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::NewProp_LayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::NewProp_OriMaterialName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::NewProp_UVOffsetAndScale,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_DetailsViewInfos" },
		{ "Comment", "//! brief  ??????????UV????\n" },
		{ "ModuleRelativePath", "Public/Toolkit/SuperMap_DetailsViewInfos.h" },
		{ "ToolTip", "! brief  ??????????UV????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_DetailsViewInfos, nullptr, "SetMaterialUVTiling", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::SuperMap_DetailsViewInfos_eventSetMaterialUVTiling_Parms), Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_DetailsViewInfos);
	UClass* Z_Construct_UClass_ASuperMap_DetailsViewInfos_NoRegister()
	{
		return ASuperMap_DetailsViewInfos::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_ReplaceMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_ReplaceMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_ReplaceLayerMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_ReplaceLayerMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_ReplaceStaticMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_ReplaceStaticMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_ExcavationSideMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_ExcavationSideMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_ExcavationTopMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_ExcavationTopMaterial;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_DetailsViewInfos_SetMaterialUVTiling, "SetMaterialUVTiling" }, // 1814543541
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Toolkit/SuperMap_DetailsViewInfos.h" },
		{ "ModuleRelativePath", "Public/Toolkit/SuperMap_DetailsViewInfos.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceMaterial_MetaData[] = {
		{ "Category", "SuperMap_DetailsViewInfos" },
		{ "Comment", "//! brief  ?????\xe6\xbb\xbbUI\n" },
		{ "ModuleRelativePath", "Public/Toolkit/SuperMap_DetailsViewInfos.h" },
		{ "ToolTip", "! brief  ?????\xe6\xbb\xbbUI" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceMaterial = { "m_ReplaceMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_DetailsViewInfos, m_ReplaceMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceLayerMaterial_MetaData[] = {
		{ "Category", "SuperMap_DetailsViewInfos" },
		{ "Comment", "//! brief  \xcd\xbc???\xe6\xbb\xbbUI\n" },
		{ "ModuleRelativePath", "Public/Toolkit/SuperMap_DetailsViewInfos.h" },
		{ "ToolTip", "! brief  \xcd\xbc???\xe6\xbb\xbbUI" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceLayerMaterial = { "m_ReplaceLayerMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_DetailsViewInfos, m_ReplaceLayerMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceLayerMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceLayerMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceStaticMesh_MetaData[] = {
		{ "Category", "SuperMap_DetailsViewInfos" },
		{ "Comment", "//! brief  ?\xca\xb2??\xe6\xbb\xbbUI\n" },
		{ "ModuleRelativePath", "Public/Toolkit/SuperMap_DetailsViewInfos.h" },
		{ "ToolTip", "! brief  ?\xca\xb2??\xe6\xbb\xbbUI" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceStaticMesh = { "m_ReplaceStaticMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_DetailsViewInfos, m_ReplaceStaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceStaticMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceStaticMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationSideMaterial_MetaData[] = {
		{ "Category", "SuperMap_DetailsViewInfos" },
		{ "Comment", "//! brief  ???\xe6\xbf\xaa??????UI\n" },
		{ "ModuleRelativePath", "Public/Toolkit/SuperMap_DetailsViewInfos.h" },
		{ "ToolTip", "! brief  ???\xe6\xbf\xaa??????UI" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationSideMaterial = { "m_ExcavationSideMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_DetailsViewInfos, m_ExcavationSideMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationSideMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationSideMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationTopMaterial_MetaData[] = {
		{ "Category", "SuperMap_DetailsViewInfos" },
		{ "Comment", "//! brief  ???\xe6\xbf\xaa??????UI\n" },
		{ "ModuleRelativePath", "Public/Toolkit/SuperMap_DetailsViewInfos.h" },
		{ "ToolTip", "! brief  ???\xe6\xbf\xaa??????UI" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationTopMaterial = { "m_ExcavationTopMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_DetailsViewInfos, m_ExcavationTopMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationTopMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationTopMaterial_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceLayerMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ReplaceStaticMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationSideMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::NewProp_m_ExcavationTopMaterial,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_DetailsViewInfos>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::ClassParams = {
		&ASuperMap_DetailsViewInfos::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_DetailsViewInfos()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_DetailsViewInfos.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_DetailsViewInfos.OuterSingleton, Z_Construct_UClass_ASuperMap_DetailsViewInfos_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_DetailsViewInfos.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_DetailsViewInfos>()
	{
		return ASuperMap_DetailsViewInfos::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_DetailsViewInfos);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_Toolkit_SuperMap_DetailsViewInfos_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_Toolkit_SuperMap_DetailsViewInfos_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_DetailsViewInfos, ASuperMap_DetailsViewInfos::StaticClass, TEXT("ASuperMap_DetailsViewInfos"), &Z_Registration_Info_UClass_ASuperMap_DetailsViewInfos, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_DetailsViewInfos), 4030513748U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_Toolkit_SuperMap_DetailsViewInfos_h_3697696080(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_Toolkit_SuperMap_DetailsViewInfos_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_Toolkit_SuperMap_DetailsViewInfos_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
