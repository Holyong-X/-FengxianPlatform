// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SceneOperation/SuperMap_ObjectOperation.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_ObjectOperation() {}
// Cross Module References
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ObjectOperation_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_ObjectOperation();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "ObjectOperationDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_ObjectOperation::execFromJson)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FromJson();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ObjectOperation::execToJson)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ToJson();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ObjectOperation::execGetPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ObjectOperation::execGetStaticMeshActor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AStaticMeshActor**)Z_Param__Result=P_THIS->GetStaticMeshActor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_ObjectOperation::execBuildObjectOperation)
	{
		P_GET_UBOOL(Z_Param_bOperation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BuildObjectOperation(Z_Param_bOperation);
		P_NATIVE_END;
	}
	void ASuperMap_ObjectOperation::StaticRegisterNativesASuperMap_ObjectOperation()
	{
		UClass* Class = ASuperMap_ObjectOperation::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildObjectOperation", &ASuperMap_ObjectOperation::execBuildObjectOperation },
			{ "FromJson", &ASuperMap_ObjectOperation::execFromJson },
			{ "GetPosition", &ASuperMap_ObjectOperation::execGetPosition },
			{ "GetStaticMeshActor", &ASuperMap_ObjectOperation::execGetStaticMeshActor },
			{ "ToJson", &ASuperMap_ObjectOperation::execToJson },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics
	{
		struct SuperMap_ObjectOperation_eventBuildObjectOperation_Parms
		{
			bool bOperation;
		};
		static void NewProp_bOperation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOperation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::NewProp_bOperation_SetBit(void* Obj)
	{
		((SuperMap_ObjectOperation_eventBuildObjectOperation_Parms*)Obj)->bOperation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::NewProp_bOperation = { "bOperation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_ObjectOperation_eventBuildObjectOperation_Parms), &Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::NewProp_bOperation_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::NewProp_bOperation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ObjectOperation" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ObjectOperation, nullptr, "BuildObjectOperation", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::SuperMap_ObjectOperation_eventBuildObjectOperation_Parms), Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ObjectOperation_FromJson_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ObjectOperation_FromJson_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ObjectOperation" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ObjectOperation_FromJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ObjectOperation, nullptr, "FromJson", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ObjectOperation_FromJson_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ObjectOperation_FromJson_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ObjectOperation_FromJson()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ObjectOperation_FromJson_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics
	{
		struct SuperMap_ObjectOperation_eventGetPosition_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ObjectOperation_eventGetPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ObjectOperation" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ObjectOperation, nullptr, "GetPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::SuperMap_ObjectOperation_eventGetPosition_Parms), Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics
	{
		struct SuperMap_ObjectOperation_eventGetStaticMeshActor_Parms
		{
			AStaticMeshActor* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_ObjectOperation_eventGetStaticMeshActor_Parms, ReturnValue), Z_Construct_UClass_AStaticMeshActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ObjectOperation" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ObjectOperation, nullptr, "GetStaticMeshActor", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::SuperMap_ObjectOperation_eventGetStaticMeshActor_Parms), Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_ObjectOperation_ToJson_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_ObjectOperation_ToJson_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_ObjectOperation" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_ObjectOperation_ToJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_ObjectOperation, nullptr, "ToJson", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_ObjectOperation_ToJson_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_ObjectOperation_ToJson_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_ObjectOperation_ToJson()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_ObjectOperation_ToJson_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_ObjectOperation);
	UClass* Z_Construct_UClass_ASuperMap_ObjectOperation_NoRegister()
	{
		return ASuperMap_ObjectOperation::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_ObjectOperation_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallGetPosition_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallGetPosition;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_arrActors_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_arrActors_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_m_arrActors;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_ObjectOperation_BuildObjectOperation, "BuildObjectOperation" }, // 2445288056
		{ &Z_Construct_UFunction_ASuperMap_ObjectOperation_FromJson, "FromJson" }, // 2548812423
		{ &Z_Construct_UFunction_ASuperMap_ObjectOperation_GetPosition, "GetPosition" }, // 3796992215
		{ &Z_Construct_UFunction_ASuperMap_ObjectOperation_GetStaticMeshActor, "GetStaticMeshActor" }, // 2368830543
		{ &Z_Construct_UFunction_ASuperMap_ObjectOperation_ToJson, "ToJson" }, // 2473903873
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SceneOperation/SuperMap_ObjectOperation.h" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallEvent = { "CallEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_ObjectOperation, CallEvent), Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallEvent_MetaData)) }; // 4165201420
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallGetPosition_MetaData[] = {
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallGetPosition = { "CallGetPosition", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_ObjectOperation, CallGetPosition), Z_Construct_UDelegateFunction_SuperMapSamples_ObjectOperationDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallGetPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallGetPosition_MetaData)) }; // 4165201420
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_m_arrActors_Inner = { "m_arrActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_m_arrActors_MetaData[] = {
		{ "Category", "SuperMap_ObjectOperation" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_ObjectOperation.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_m_arrActors = { "m_arrActors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_ObjectOperation, m_arrActors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_m_arrActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_m_arrActors_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_CallGetPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_m_arrActors_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::NewProp_m_arrActors,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_ObjectOperation>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::ClassParams = {
		&ASuperMap_ObjectOperation::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_ObjectOperation()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_ObjectOperation.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_ObjectOperation.OuterSingleton, Z_Construct_UClass_ASuperMap_ObjectOperation_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_ObjectOperation.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_ObjectOperation>()
	{
		return ASuperMap_ObjectOperation::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_ObjectOperation);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ObjectOperation_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ObjectOperation_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_ObjectOperation, ASuperMap_ObjectOperation::StaticClass, TEXT("ASuperMap_ObjectOperation"), &Z_Registration_Info_UClass_ASuperMap_ObjectOperation, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_ObjectOperation), 1413318244U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ObjectOperation_h_1306124660(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ObjectOperation_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_ObjectOperation_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
