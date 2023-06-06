// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_FlattenInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_FlattenInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FlattenInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FlattenInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_FlattenInstance::execGetJsonArrayStringValue)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Descriptor);
		P_GET_PROPERTY(FStrProperty,Z_Param_FieldName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FVector>*)Z_Param__Result=P_THIS->GetJsonArrayStringValue(Z_Param_Descriptor,Z_Param_FieldName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlattenInstance::execSetUseWeb)
	{
		P_GET_UBOOL(Z_Param_bUseWithoutWeb);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetUseWeb(Z_Param_bUseWithoutWeb);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlattenInstance::execAddFlattenRegion)
	{
		P_GET_TARRAY(FVector,Z_Param_arrPos);
		P_GET_PROPERTY(FStrProperty,Z_Param_Tag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddFlattenRegion(Z_Param_arrPos,Z_Param_Tag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlattenInstance::execSetIsFlatten)
	{
		P_GET_UBOOL(Z_Param_bflatten);
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsFlatten(Z_Param_bflatten,Z_Param_strLayerName);
		P_NATIVE_END;
	}
	void ASuperMap_FlattenInstance::StaticRegisterNativesASuperMap_FlattenInstance()
	{
		UClass* Class = ASuperMap_FlattenInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddFlattenRegion", &ASuperMap_FlattenInstance::execAddFlattenRegion },
			{ "GetJsonArrayStringValue", &ASuperMap_FlattenInstance::execGetJsonArrayStringValue },
			{ "SetIsFlatten", &ASuperMap_FlattenInstance::execSetIsFlatten },
			{ "SetUseWeb", &ASuperMap_FlattenInstance::execSetUseWeb },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics
	{
		struct SuperMap_FlattenInstance_eventAddFlattenRegion_Parms
		{
			TArray<FVector> arrPos;
			FString Tag;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_arrPos_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_arrPos;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Tag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::NewProp_arrPos_Inner = { "arrPos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::NewProp_arrPos = { "arrPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlattenInstance_eventAddFlattenRegion_Parms, arrPos), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlattenInstance_eventAddFlattenRegion_Parms, Tag), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::NewProp_arrPos_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::NewProp_arrPos,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::NewProp_Tag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlattenInstance" },
		{ "Comment", "// Web ????\xc8\xbe?\xd3\xbf?????\n//! \\brief ??????\xd0\xb1\xd1\xb9\xc6\xbd??\xce\xbb??\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FlattenInstance.h" },
		{ "ToolTip", "Web ????\xc8\xbe?\xd3\xbf?????\n! \\brief ??????\xd0\xb1\xd1\xb9\xc6\xbd??\xce\xbb??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlattenInstance, nullptr, "AddFlattenRegion", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::SuperMap_FlattenInstance_eventAddFlattenRegion_Parms), Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics
	{
		struct SuperMap_FlattenInstance_eventGetJsonArrayStringValue_Parms
		{
			FString Descriptor;
			FString FieldName;
			TArray<FVector> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Descriptor;
		static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::NewProp_Descriptor = { "Descriptor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlattenInstance_eventGetJsonArrayStringValue_Parms, Descriptor), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlattenInstance_eventGetJsonArrayStringValue_Parms, FieldName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlattenInstance_eventGetJsonArrayStringValue_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::NewProp_Descriptor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::NewProp_FieldName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlattenInstance" },
		{ "Comment", "//! \\brief ??????????\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FlattenInstance.h" },
		{ "ToolTip", "! \\brief ??????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlattenInstance, nullptr, "GetJsonArrayStringValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::SuperMap_FlattenInstance_eventGetJsonArrayStringValue_Parms), Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics
	{
		struct SuperMap_FlattenInstance_eventSetIsFlatten_Parms
		{
			bool bflatten;
			FName strLayerName;
		};
		static void NewProp_bflatten_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bflatten;
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::NewProp_bflatten_SetBit(void* Obj)
	{
		((SuperMap_FlattenInstance_eventSetIsFlatten_Parms*)Obj)->bflatten = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::NewProp_bflatten = { "bflatten", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FlattenInstance_eventSetIsFlatten_Parms), &Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::NewProp_bflatten_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlattenInstance_eventSetIsFlatten_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::NewProp_bflatten,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::NewProp_strLayerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlattenInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7???\xd0\xb1\xd1\xb9\xc6\xbd\n//! \\param bflatten [in] true??\xca\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FlattenInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7???\xd0\xb1\xd1\xb9\xc6\xbd\n! \\param bflatten [in] true??\xca\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlattenInstance, nullptr, "SetIsFlatten", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::SuperMap_FlattenInstance_eventSetIsFlatten_Parms), Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics
	{
		struct SuperMap_FlattenInstance_eventSetUseWeb_Parms
		{
			bool bUseWithoutWeb;
		};
		static void NewProp_bUseWithoutWeb_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseWithoutWeb;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::NewProp_bUseWithoutWeb_SetBit(void* Obj)
	{
		((SuperMap_FlattenInstance_eventSetUseWeb_Parms*)Obj)->bUseWithoutWeb = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::NewProp_bUseWithoutWeb = { "bUseWithoutWeb", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FlattenInstance_eventSetUseWeb_Parms), &Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::NewProp_bUseWithoutWeb_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::NewProp_bUseWithoutWeb,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlattenInstance" },
		{ "Comment", "//! \\brief ?????\xc7\xb7?\xca\xb9??????\xc8\xbe\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FlattenInstance.h" },
		{ "ToolTip", "! \\brief ?????\xc7\xb7?\xca\xb9??????\xc8\xbe" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlattenInstance, nullptr, "SetUseWeb", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::SuperMap_FlattenInstance_eventSetUseWeb_Parms), Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_FlattenInstance);
	UClass* Z_Construct_UClass_ASuperMap_FlattenInstance_NoRegister()
	{
		return ASuperMap_FlattenInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_FlattenInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_FlattenInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_FlattenInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_FlattenInstance_AddFlattenRegion, "AddFlattenRegion" }, // 3286069627
		{ &Z_Construct_UFunction_ASuperMap_FlattenInstance_GetJsonArrayStringValue, "GetJsonArrayStringValue" }, // 2261475582
		{ &Z_Construct_UFunction_ASuperMap_FlattenInstance_SetIsFlatten, "SetIsFlatten" }, // 3696059346
		{ &Z_Construct_UFunction_ASuperMap_FlattenInstance_SetUseWeb, "SetUseWeb" }, // 3939858335
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_FlattenInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_FlattenInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_FlattenInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_FlattenInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_FlattenInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_FlattenInstance_Statics::ClassParams = {
		&ASuperMap_FlattenInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_FlattenInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_FlattenInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_FlattenInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_FlattenInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_FlattenInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_FlattenInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_FlattenInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_FlattenInstance>()
	{
		return ASuperMap_FlattenInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_FlattenInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FlattenInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FlattenInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_FlattenInstance, ASuperMap_FlattenInstance::StaticClass, TEXT("ASuperMap_FlattenInstance"), &Z_Registration_Info_UClass_ASuperMap_FlattenInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_FlattenInstance), 1993585480U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FlattenInstance_h_2974795998(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FlattenInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_FlattenInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
