// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SceneOperation/SuperMap_RectSelect.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_RectSelect() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_RectSelect_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_RectSelect();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_RectSelect::execBuildRectSelect)
	{
		P_GET_UBOOL(Z_Param_bRectSelect);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildRectSelect(Z_Param_bRectSelect);
		P_NATIVE_END;
	}
	void ASuperMap_RectSelect::StaticRegisterNativesASuperMap_RectSelect()
	{
		UClass* Class = ASuperMap_RectSelect::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildRectSelect", &ASuperMap_RectSelect::execBuildRectSelect },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics
	{
		struct SuperMap_RectSelect_eventBuildRectSelect_Parms
		{
			bool bRectSelect;
		};
		static void NewProp_bRectSelect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRectSelect;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::NewProp_bRectSelect_SetBit(void* Obj)
	{
		((SuperMap_RectSelect_eventBuildRectSelect_Parms*)Obj)->bRectSelect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::NewProp_bRectSelect = { "bRectSelect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_RectSelect_eventBuildRectSelect_Parms), &Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::NewProp_bRectSelect_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::NewProp_bRectSelect,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASuperMap_RectSelect" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_RectSelect.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_RectSelect, nullptr, "BuildRectSelect", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::SuperMap_RectSelect_eventBuildRectSelect_Parms), Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_RectSelect);
	UClass* Z_Construct_UClass_ASuperMap_RectSelect_NoRegister()
	{
		return ASuperMap_RectSelect::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_RectSelect_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_RectSelect_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_RectSelect_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_RectSelect_BuildRectSelect, "BuildRectSelect" }, // 600673413
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_RectSelect_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SceneOperation/SuperMap_RectSelect.h" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_RectSelect.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_RectSelect_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_RectSelect>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_RectSelect_Statics::ClassParams = {
		&ASuperMap_RectSelect::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_RectSelect_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_RectSelect_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_RectSelect()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_RectSelect.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_RectSelect.OuterSingleton, Z_Construct_UClass_ASuperMap_RectSelect_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_RectSelect.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_RectSelect>()
	{
		return ASuperMap_RectSelect::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_RectSelect);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_RectSelect_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_RectSelect_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_RectSelect, ASuperMap_RectSelect::StaticClass, TEXT("ASuperMap_RectSelect"), &Z_Registration_Info_UClass_ASuperMap_RectSelect, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_RectSelect), 2601077706U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_RectSelect_h_830083102(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_RectSelect_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_RectSelect_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
