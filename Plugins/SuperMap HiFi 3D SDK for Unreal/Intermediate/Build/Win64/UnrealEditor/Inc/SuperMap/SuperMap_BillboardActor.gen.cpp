// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_BillboardActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_BillboardActor() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_BillboardActor_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_BillboardActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_BillboardActor::execSetGeoLocation)
	{
		P_GET_STRUCT(FVector,Z_Param_vPos);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetGeoLocation(Z_Param_vPos);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_BillboardActor::execSetContentStr)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Str);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetContentStr(Z_Param_Str);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_BillboardActor::execSetContentArrStr)
	{
		P_GET_TARRAY(FString,Z_Param_arrStr);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetContentArrStr(Z_Param_arrStr);
		P_NATIVE_END;
	}
	void ASuperMap_BillboardActor::StaticRegisterNativesASuperMap_BillboardActor()
	{
		UClass* Class = ASuperMap_BillboardActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetContentArrStr", &ASuperMap_BillboardActor::execSetContentArrStr },
			{ "SetContentStr", &ASuperMap_BillboardActor::execSetContentStr },
			{ "SetGeoLocation", &ASuperMap_BillboardActor::execSetGeoLocation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics
	{
		struct SuperMap_BillboardActor_eventSetContentArrStr_Parms
		{
			TArray<FString> arrStr;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_arrStr_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_arrStr;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::NewProp_arrStr_Inner = { "arrStr", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::NewProp_arrStr = { "arrStr", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_BillboardActor_eventSetContentArrStr_Parms, arrStr), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::NewProp_arrStr_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::NewProp_arrStr,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_BillboardActor" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_BillboardActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_BillboardActor, nullptr, "SetContentArrStr", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::SuperMap_BillboardActor_eventSetContentArrStr_Parms), Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics
	{
		struct SuperMap_BillboardActor_eventSetContentStr_Parms
		{
			FString Str;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Str;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::NewProp_Str = { "Str", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_BillboardActor_eventSetContentStr_Parms, Str), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::NewProp_Str,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_BillboardActor" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_BillboardActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_BillboardActor, nullptr, "SetContentStr", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::SuperMap_BillboardActor_eventSetContentStr_Parms), Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics
	{
		struct SuperMap_BillboardActor_eventSetGeoLocation_Parms
		{
			FVector vPos;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_vPos;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::NewProp_vPos = { "vPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_BillboardActor_eventSetGeoLocation_Parms, vPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::NewProp_vPos,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_BillboardActor" },
		{ "Comment", "// ???\xc3\xb2????\xe5\xbe\xad\xce\xb3\xce\xbb??\n" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_BillboardActor.h" },
		{ "ToolTip", "???\xc3\xb2????\xe5\xbe\xad\xce\xb3\xce\xbb??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_BillboardActor, nullptr, "SetGeoLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::SuperMap_BillboardActor_eventSetGeoLocation_Parms), Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_BillboardActor);
	UClass* Z_Construct_UClass_ASuperMap_BillboardActor_NoRegister()
	{
		return ASuperMap_BillboardActor::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_BillboardActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_pTextRender_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_pTextRender;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_pBackground_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_pBackground;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_BillboardActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_BillboardActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentArrStr, "SetContentArrStr" }, // 2894013558
		{ &Z_Construct_UFunction_ASuperMap_BillboardActor_SetContentStr, "SetContentStr" }, // 460458696
		{ &Z_Construct_UFunction_ASuperMap_BillboardActor_SetGeoLocation, "SetGeoLocation" }, // 1825750826
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_BillboardActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Component/SuperMap_BillboardActor.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_BillboardActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pTextRender_MetaData[] = {
		{ "Category", "SuperMap_BillboardActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_BillboardActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pTextRender = { "m_pTextRender", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_BillboardActor, m_pTextRender), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pTextRender_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pTextRender_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pBackground_MetaData[] = {
		{ "Category", "SuperMap_BillboardActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_BillboardActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pBackground = { "m_pBackground", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_BillboardActor, m_pBackground), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pBackground_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pBackground_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_BillboardActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pTextRender,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_BillboardActor_Statics::NewProp_m_pBackground,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_BillboardActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_BillboardActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_BillboardActor_Statics::ClassParams = {
		&ASuperMap_BillboardActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_BillboardActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_BillboardActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_BillboardActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_BillboardActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_BillboardActor()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_BillboardActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_BillboardActor.OuterSingleton, Z_Construct_UClass_ASuperMap_BillboardActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_BillboardActor.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_BillboardActor>()
	{
		return ASuperMap_BillboardActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_BillboardActor);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_BillboardActor, ASuperMap_BillboardActor::StaticClass, TEXT("ASuperMap_BillboardActor"), &Z_Registration_Info_UClass_ASuperMap_BillboardActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_BillboardActor), 4230642744U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardActor_h_4267990138(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_BillboardActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
