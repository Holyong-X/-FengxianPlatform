// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SceneOperation/SuperMap_GeometryQuery.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_GeometryQuery() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_GeometryQuery_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_GeometryQuery();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_GeometryQuery::execBuildGeometryQuery)
	{
		P_GET_UBOOL(Z_Param_bGeometryQuery);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildGeometryQuery(Z_Param_bGeometryQuery);
		P_NATIVE_END;
	}
	void ASuperMap_GeometryQuery::StaticRegisterNativesASuperMap_GeometryQuery()
	{
		UClass* Class = ASuperMap_GeometryQuery::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildGeometryQuery", &ASuperMap_GeometryQuery::execBuildGeometryQuery },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics
	{
		struct SuperMap_GeometryQuery_eventBuildGeometryQuery_Parms
		{
			bool bGeometryQuery;
		};
		static void NewProp_bGeometryQuery_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGeometryQuery;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::NewProp_bGeometryQuery_SetBit(void* Obj)
	{
		((SuperMap_GeometryQuery_eventBuildGeometryQuery_Parms*)Obj)->bGeometryQuery = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::NewProp_bGeometryQuery = { "bGeometryQuery", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GeometryQuery_eventBuildGeometryQuery_Parms), &Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::NewProp_bGeometryQuery_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::NewProp_bGeometryQuery,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_GeometryQuery" },
		{ "Comment", "//! \\brief ?????\xd5\xbc???\xd1\xaf\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_GeometryQuery.h" },
		{ "ToolTip", "! \\brief ?????\xd5\xbc???\xd1\xaf" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GeometryQuery, nullptr, "BuildGeometryQuery", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::SuperMap_GeometryQuery_eventBuildGeometryQuery_Parms), Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_GeometryQuery);
	UClass* Z_Construct_UClass_ASuperMap_GeometryQuery_NoRegister()
	{
		return ASuperMap_GeometryQuery::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_GeometryQuery_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_GeometryQuery_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_GeometryQuery_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_GeometryQuery_BuildGeometryQuery, "BuildGeometryQuery" }, // 982633256
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_GeometryQuery_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SceneOperation/SuperMap_GeometryQuery.h" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_GeometryQuery.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_GeometryQuery_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_GeometryQuery>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_GeometryQuery_Statics::ClassParams = {
		&ASuperMap_GeometryQuery::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_GeometryQuery_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_GeometryQuery_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_GeometryQuery()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_GeometryQuery.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_GeometryQuery.OuterSingleton, Z_Construct_UClass_ASuperMap_GeometryQuery_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_GeometryQuery.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_GeometryQuery>()
	{
		return ASuperMap_GeometryQuery::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_GeometryQuery);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_GeometryQuery_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_GeometryQuery_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_GeometryQuery, ASuperMap_GeometryQuery::StaticClass, TEXT("ASuperMap_GeometryQuery"), &Z_Registration_Info_UClass_ASuperMap_GeometryQuery, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_GeometryQuery), 2463114333U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_GeometryQuery_h_3821883240(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_GeometryQuery_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_GeometryQuery_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
