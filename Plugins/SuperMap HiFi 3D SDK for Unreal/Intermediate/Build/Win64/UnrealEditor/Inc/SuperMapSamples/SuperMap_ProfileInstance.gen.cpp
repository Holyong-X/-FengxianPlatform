// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SpatialAnalysis/SuperMap_ProfileInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ProfileInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ProfileTextureDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ProfileInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ProfileInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_ProfileTextureDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_ProfileTextureDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProfileInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_ProfileTextureDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "ProfileTextureDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_ProfileTextureDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_ProfileTextureDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ProfileTextureDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_ProfileTextureDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_ProfileInstance::execGetHeightPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector2D*)Z_Param__Result=P_THIS->GetHeightPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ProfileInstance::execGetImageData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=P_THIS->GetImageData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ProfileInstance::execBuildProfile)
	{
		P_GET_UBOOL(Z_Param_bProfile);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildProfile(Z_Param_bProfile);
		P_NATIVE_END;
	}
	void ASuperMap_ProfileInstance::StaticRegisterNativesASuperMap_ProfileInstance()
	{
		UClass* Class = ASuperMap_ProfileInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildProfile", &ASuperMap_ProfileInstance::execBuildProfile },
			{ "GetHeightPosition", &ASuperMap_ProfileInstance::execGetHeightPosition },
			{ "GetImageData", &ASuperMap_ProfileInstance::execGetImageData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics
	{
		struct SuperMap_ProfileInstance_eventBuildProfile_Parms
		{
			bool bProfile;
		};
		static void NewProp_bProfile_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bProfile;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::NewProp_bProfile_SetBit(void* Obj)
	{
		((SuperMap_ProfileInstance_eventBuildProfile_Parms*)Obj)->bProfile = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::NewProp_bProfile = { "bProfile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ProfileInstance_eventBuildProfile_Parms), &Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::NewProp_bProfile_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::NewProp_bProfile,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProfileInstance" },
		{ "Comment", "//! \\brief ?\xc7\xb7?????????\n//! \\param bclip [in] true??\xca\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProfileInstance.h" },
		{ "ToolTip", "! \\brief ?\xc7\xb7?????????\n! \\param bclip [in] true??\xca\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProfileInstance, nullptr, "BuildProfile", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::SuperMap_ProfileInstance_eventBuildProfile_Parms), Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics
	{
		struct SuperMap_ProfileInstance_eventGetHeightPosition_Parms
		{
			FVector2D ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ProfileInstance_eventGetHeightPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProfileInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1????\xcd\xbc?\xdf\xb6?\n//! \\brief X\xce\xaa?????\xdf\xb6\xc8\xa3?Y\xce\xaa??\xd0\xa1?\xdf\xb6?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProfileInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1????\xcd\xbc?\xdf\xb6?\n! \\brief X\xce\xaa?????\xdf\xb6\xc8\xa3?Y\xce\xaa??\xd0\xa1?\xdf\xb6?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProfileInstance, nullptr, "GetHeightPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::SuperMap_ProfileInstance_eventGetHeightPosition_Parms), Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics
	{
		struct SuperMap_ProfileInstance_eventGetImageData_Parms
		{
			UTexture2D* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ProfileInstance_eventGetImageData_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ProfileInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1????????\xcd\xbc\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProfileInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1????????\xcd\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ProfileInstance, nullptr, "GetImageData", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::SuperMap_ProfileInstance_eventGetImageData_Parms), Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ProfileInstance);
	UClass* Z_Construct_UClass_ASuperMap_ProfileInstance_NoRegister()
	{
		return ASuperMap_ProfileInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ProfileInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallProfileTexture_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallProfileTexture;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_ProfileInstance_BuildProfile, "BuildProfile" }, // 3289768741
		{ &Z_Construct_UFunction_ASuperMap_ProfileInstance_GetHeightPosition, "GetHeightPosition" }, // 335424531
		{ &Z_Construct_UFunction_ASuperMap_ProfileInstance_GetImageData, "GetImageData" }, // 1509925730
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpatialAnalysis/SuperMap_ProfileInstance.h" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProfileInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::NewProp_CallProfileTexture_MetaData[] = {
		{ "Comment", "//! \\brief ?\xd8\xb5??????\xc2\xbc?\n" },
		{ "ModuleRelativePath", "Public/SpatialAnalysis/SuperMap_ProfileInstance.h" },
		{ "ToolTip", "! \\brief ?\xd8\xb5??????\xc2\xbc?" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::NewProp_CallProfileTexture = { "CallProfileTexture", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_ProfileInstance, CallProfileTexture), Z_Construct_UDelegateFunction_SuperMapSamples_ProfileTextureDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::NewProp_CallProfileTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::NewProp_CallProfileTexture_MetaData)) }; // 3506832056
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::NewProp_CallProfileTexture,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ProfileInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::ClassParams = {
		&ASuperMap_ProfileInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ProfileInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ProfileInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ProfileInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_ProfileInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ProfileInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_ProfileInstance>()
	{
		return ASuperMap_ProfileInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ProfileInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProfileInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProfileInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ProfileInstance, ASuperMap_ProfileInstance::StaticClass, TEXT("ASuperMap_ProfileInstance"), &Z_Registration_Info_UClass_ASuperMap_ProfileInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ProfileInstance), 3359255469U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProfileInstance_h_2800183797(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProfileInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SpatialAnalysis_SuperMap_ProfileInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
