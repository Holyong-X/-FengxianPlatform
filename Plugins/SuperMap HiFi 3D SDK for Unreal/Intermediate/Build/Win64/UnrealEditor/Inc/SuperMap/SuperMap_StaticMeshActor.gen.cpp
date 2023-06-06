// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_StaticMeshActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_StaticMeshActor() {}
// Cross Module References
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_StaticMeshActor_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_StaticMeshActor();
	ENGINE_API UClass* Z_Construct_UClass_AStaticMeshActor();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
	ENGINE_API UClass* Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FMatrix();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceConstant_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_StaticMeshActor::execUDB_ModelSave)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UDB_ModelSave();
		P_NATIVE_END;
	}
	void ASuperMap_StaticMeshActor::StaticRegisterNativesASuperMap_StaticMeshActor()
	{
		UClass* Class = ASuperMap_StaticMeshActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UDB_ModelSave", &ASuperMap_StaticMeshActor::execUDB_ModelSave },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_StaticMeshActor_UDB_ModelSave_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_StaticMeshActor_UDB_ModelSave_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "StaticMeshActor" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_StaticMeshActor_UDB_ModelSave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_StaticMeshActor, nullptr, "UDB_ModelSave", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_StaticMeshActor_UDB_ModelSave_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_StaticMeshActor_UDB_ModelSave_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_StaticMeshActor_UDB_ModelSave()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_StaticMeshActor_UDB_ModelSave_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_StaticMeshActor);
	UClass* Z_Construct_UClass_ASuperMap_StaticMeshActor_NoRegister()
	{
		return ASuperMap_StaticMeshActor::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InstancedStaticMeshComponents_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InstancedStaticMeshComponents_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InstancedStaticMeshComponents;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMeshComponents_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaticMeshComponents_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_StaticMeshComponents;
		static const UECodeGen_Private::FStructPropertyParams NewProp_m_arrMatrixs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_arrMatrixs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_m_arrMatrixs;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_mapMaterials_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_mapMaterials_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_mapMaterials_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_m_mapMaterials;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strDataSourceName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strDataSourceName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strDatasetName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strDatasetName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strSMID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_m_strSMID;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AttributeQuery_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AttributeQuery_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttributeQuery_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_AttributeQuery;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AStaticMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_StaticMeshActor_UDB_ModelSave, "UDB_ModelSave" }, // 112923276
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input" },
		{ "IncludePath", "Component/SuperMap_StaticMeshActor.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_InstancedStaticMeshComponents_Inner = { "InstancedStaticMeshComponents", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_InstancedStaticMeshComponents_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "StaticMeshActor" },
		{ "Comment", "//! \\brief \xe5\xae\x9e\xe4\xbe\x8b\xe5\x8c\x96\xe9\x9d\x99\xe6\x80\x81\xe7\xbd\x91\xe6\xa0\xbc\xe7\xbb\x84\xe4\xbb\xb6\n" },
		{ "EditInline", "true" },
		{ "ExposeFunctionCategories", "Mesh,Rendering,Physics,Components|StaticMesh" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
		{ "ToolTip", "! \\brief \xe5\xae\x9e\xe4\xbe\x8b\xe5\x8c\x96\xe9\x9d\x99\xe6\x80\x81\xe7\xbd\x91\xe6\xa0\xbc\xe7\xbb\x84\xe4\xbb\xb6" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_InstancedStaticMeshComponents = { "InstancedStaticMeshComponents", nullptr, (EPropertyFlags)0x001000800000001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_StaticMeshActor, InstancedStaticMeshComponents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_InstancedStaticMeshComponents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_InstancedStaticMeshComponents_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_StaticMeshComponents_Inner = { "StaticMeshComponents", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_StaticMeshComponents_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "StaticMeshActor" },
		{ "Comment", "//! \\brief \xe9\x9d\x99\xe6\x80\x81\xe7\xbd\x91\xe6\xa0\xbc\xe7\xbb\x84\xe4\xbb\xb6\n" },
		{ "EditInline", "true" },
		{ "ExposeFunctionCategories", "Mesh,Rendering,Physics,Components|StaticMesh" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
		{ "ToolTip", "! \\brief \xe9\x9d\x99\xe6\x80\x81\xe7\xbd\x91\xe6\xa0\xbc\xe7\xbb\x84\xe4\xbb\xb6" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_StaticMeshComponents = { "StaticMeshComponents", nullptr, (EPropertyFlags)0x001000800000001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_StaticMeshActor, StaticMeshComponents), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_StaticMeshComponents_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_StaticMeshComponents_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_arrMatrixs_Inner = { "m_arrMatrixs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FMatrix, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_arrMatrixs_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "StaticMeshActor" },
		{ "Comment", "//! \\brief \xe9\x9d\x99\xe6\x80\x81\xe7\xbd\x91\xe6\xa0\xbc\xe7\xbb\x84\xe4\xbb\xb6\xe7\x9f\xa9\xe9\x98\xb5\n" },
		{ "ExposeFunctionCategories", "Mesh,Rendering,Physics,Components|StaticMesh" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
		{ "ToolTip", "! \\brief \xe9\x9d\x99\xe6\x80\x81\xe7\xbd\x91\xe6\xa0\xbc\xe7\xbb\x84\xe4\xbb\xb6\xe7\x9f\xa9\xe9\x98\xb5" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_arrMatrixs = { "m_arrMatrixs", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_StaticMeshActor, m_arrMatrixs), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_arrMatrixs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_arrMatrixs_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_mapMaterials_ValueProp = { "m_mapMaterials", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UMaterialInstanceConstant_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_mapMaterials_Key_KeyProp = { "m_mapMaterials_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_mapMaterials_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "StaticMeshActor" },
		{ "Comment", "//! \\brief \xe6\x9d\x90\xe8\xb4\xa8\n" },
		{ "ExposeFunctionCategories", "Model Material" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
		{ "ToolTip", "! \\brief \xe6\x9d\x90\xe8\xb4\xa8" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_mapMaterials = { "m_mapMaterials", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_StaticMeshActor, m_mapMaterials), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_mapMaterials_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_mapMaterials_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDataSourceName_MetaData[] = {
		{ "Category", "StaticMeshActor" },
		{ "Comment", "//! \\brief \xe6\x95\xb0\xe6\x8d\xae\xe6\xba\x90\xe5\x90\x8d\xe7\xa7\xb0\n" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
		{ "ToolTip", "! \\brief \xe6\x95\xb0\xe6\x8d\xae\xe6\xba\x90\xe5\x90\x8d\xe7\xa7\xb0" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDataSourceName = { "m_strDataSourceName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_StaticMeshActor, m_strDataSourceName), METADATA_PARAMS(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDataSourceName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDataSourceName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDatasetName_MetaData[] = {
		{ "Category", "StaticMeshActor" },
		{ "Comment", "//! \\brief \xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\x90\x8d\xe7\xa7\xb0\n" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
		{ "ToolTip", "! \\brief \xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\x90\x8d\xe7\xa7\xb0" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDatasetName = { "m_strDatasetName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_StaticMeshActor, m_strDatasetName), METADATA_PARAMS(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDatasetName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDatasetName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strSMID_MetaData[] = {
		{ "Category", "StaticMeshActor" },
		{ "Comment", "//! \\brief \xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\xaf\xb9\xe8\xb1\xa1ID\n" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
		{ "ToolTip", "! \\brief \xe6\x95\xb0\xe6\x8d\xae\xe9\x9b\x86\xe5\xaf\xb9\xe8\xb1\xa1ID" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strSMID = { "m_strSMID", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_StaticMeshActor, m_strSMID), METADATA_PARAMS(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strSMID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strSMID_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_AttributeQuery_ValueProp = { "AttributeQuery", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_AttributeQuery_Key_KeyProp = { "AttributeQuery_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_AttributeQuery_MetaData[] = {
		{ "Category", "\xe5\xb1\x9e\xe6\x80\xa7\xe6\x9f\xa5\xe8\xaf\xa2" },
		{ "Comment", "//! \\brief \xe5\xb1\x9e\xe6\x80\xa7\n" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_StaticMeshActor.h" },
		{ "ToolTip", "! \\brief \xe5\xb1\x9e\xe6\x80\xa7" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_AttributeQuery = { "AttributeQuery", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_StaticMeshActor, AttributeQuery), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_AttributeQuery_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_AttributeQuery_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_InstancedStaticMeshComponents_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_InstancedStaticMeshComponents,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_StaticMeshComponents_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_StaticMeshComponents,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_arrMatrixs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_arrMatrixs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_mapMaterials_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_mapMaterials_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_mapMaterials,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDataSourceName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strDatasetName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_m_strSMID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_AttributeQuery_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_AttributeQuery_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::NewProp_AttributeQuery,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_StaticMeshActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::ClassParams = {
		&ASuperMap_StaticMeshActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_StaticMeshActor()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_StaticMeshActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_StaticMeshActor.OuterSingleton, Z_Construct_UClass_ASuperMap_StaticMeshActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_StaticMeshActor.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_StaticMeshActor>()
	{
		return ASuperMap_StaticMeshActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_StaticMeshActor);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_StaticMeshActor, ASuperMap_StaticMeshActor::StaticClass, TEXT("ASuperMap_StaticMeshActor"), &Z_Registration_Info_UClass_ASuperMap_StaticMeshActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_StaticMeshActor), 1776660043U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshActor_h_2413219490(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_StaticMeshActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
