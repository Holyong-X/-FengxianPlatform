// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMap/Public/Component/SuperMap_SphereActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_SphereActor() {}
// Cross Module References
	SUPERMAP_API UEnum* Z_Construct_UEnum_SuperMap_ESuperMap_Sphere();
	UPackage* Z_Construct_UPackage__Script_SuperMap();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_SphereActor_NoRegister();
	SUPERMAP_API UClass* Z_Construct_UClass_ASuperMap_SphereActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESuperMap_Sphere;
	static UEnum* ESuperMap_Sphere_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESuperMap_Sphere.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESuperMap_Sphere.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SuperMap_ESuperMap_Sphere, Z_Construct_UPackage__Script_SuperMap(), TEXT("ESuperMap_Sphere"));
		}
		return Z_Registration_Info_UEnum_ESuperMap_Sphere.OuterSingleton;
	}
	template<> SUPERMAP_API UEnum* StaticEnum<ESuperMap_Sphere>()
	{
		return ESuperMap_Sphere_StaticEnum();
	}
	struct Z_Construct_UEnum_SuperMap_ESuperMap_Sphere_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SuperMap_ESuperMap_Sphere_Statics::Enumerators[] = {
		{ "ESuperMap_Sphere::ViewerPoint_SightLine", (int64)ESuperMap_Sphere::ViewerPoint_SightLine },
		{ "ESuperMap_Sphere::TargetPoint_SightLine", (int64)ESuperMap_Sphere::TargetPoint_SightLine },
		{ "ESuperMap_Sphere::BarriedPoint_SightLine", (int64)ESuperMap_Sphere::BarriedPoint_SightLine },
		{ "ESuperMap_Sphere::Point_Measure", (int64)ESuperMap_Sphere::Point_Measure },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SuperMap_ESuperMap_Sphere_Statics::Enum_MetaDataParams[] = {
		{ "BarriedPoint_SightLine.Name", "ESuperMap_Sphere::BarriedPoint_SightLine" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_SphereActor.h" },
		{ "Point_Measure.Name", "ESuperMap_Sphere::Point_Measure" },
		{ "TargetPoint_SightLine.Name", "ESuperMap_Sphere::TargetPoint_SightLine" },
		{ "ViewerPoint_SightLine.Name", "ESuperMap_Sphere::ViewerPoint_SightLine" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SuperMap_ESuperMap_Sphere_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SuperMap,
		nullptr,
		"ESuperMap_Sphere",
		"ESuperMap_Sphere",
		Z_Construct_UEnum_SuperMap_ESuperMap_Sphere_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SuperMap_ESuperMap_Sphere_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SuperMap_ESuperMap_Sphere_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SuperMap_ESuperMap_Sphere_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SuperMap_ESuperMap_Sphere()
	{
		if (!Z_Registration_Info_UEnum_ESuperMap_Sphere.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESuperMap_Sphere.InnerSingleton, Z_Construct_UEnum_SuperMap_ESuperMap_Sphere_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESuperMap_Sphere.InnerSingleton;
	}
	DEFINE_FUNCTION(ASuperMap_SphereActor::execMouseEndOverEvent)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_Component);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MouseEndOverEvent(Z_Param_Component);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SphereActor::execMouseBeginOverEvent)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_Component);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MouseBeginOverEvent(Z_Param_Component);
		P_NATIVE_END;
	}
	void ASuperMap_SphereActor::StaticRegisterNativesASuperMap_SphereActor()
	{
		UClass* Class = ASuperMap_SphereActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MouseBeginOverEvent", &ASuperMap_SphereActor::execMouseBeginOverEvent },
			{ "MouseEndOverEvent", &ASuperMap_SphereActor::execMouseEndOverEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics
	{
		struct SuperMap_SphereActor_eventMouseBeginOverEvent_Parms
		{
			UPrimitiveComponent* Component;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Component_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Component;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::NewProp_Component_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::NewProp_Component = { "Component", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SphereActor_eventMouseBeginOverEvent_Parms, Component), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::NewProp_Component_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::NewProp_Component_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::NewProp_Component,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Component/SuperMap_SphereActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SphereActor, nullptr, "MouseBeginOverEvent", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::SuperMap_SphereActor_eventMouseBeginOverEvent_Parms), Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics
	{
		struct SuperMap_SphereActor_eventMouseEndOverEvent_Parms
		{
			UPrimitiveComponent* Component;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Component_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Component;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::NewProp_Component_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::NewProp_Component = { "Component", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SphereActor_eventMouseEndOverEvent_Parms, Component), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::NewProp_Component_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::NewProp_Component_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::NewProp_Component,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Component/SuperMap_SphereActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SphereActor, nullptr, "MouseEndOverEvent", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::SuperMap_SphereActor_eventMouseEndOverEvent_Parms), Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_SphereActor);
	UClass* Z_Construct_UClass_ASuperMap_SphereActor_NoRegister()
	{
		return ASuperMap_SphereActor::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_SphereActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_pSphereMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_m_pSphereMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_SphereActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMap,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_SphereActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_SphereActor_MouseBeginOverEvent, "MouseBeginOverEvent" }, // 2011831090
		{ &Z_Construct_UFunction_ASuperMap_SphereActor_MouseEndOverEvent, "MouseEndOverEvent" }, // 223710936
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SphereActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Component/SuperMap_SphereActor.h" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_SphereActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SphereActor_Statics::NewProp_m_pSphereMesh_MetaData[] = {
		{ "Category", "SuperMap_SphereActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Component/SuperMap_SphereActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASuperMap_SphereActor_Statics::NewProp_m_pSphereMesh = { "m_pSphereMesh", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_SphereActor, m_pSphereMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SphereActor_Statics::NewProp_m_pSphereMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SphereActor_Statics::NewProp_m_pSphereMesh_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_SphereActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_SphereActor_Statics::NewProp_m_pSphereMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_SphereActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_SphereActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_SphereActor_Statics::ClassParams = {
		&ASuperMap_SphereActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_SphereActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SphereActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SphereActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SphereActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_SphereActor()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_SphereActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_SphereActor.OuterSingleton, Z_Construct_UClass_ASuperMap_SphereActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_SphereActor.OuterSingleton;
	}
	template<> SUPERMAP_API UClass* StaticClass<ASuperMap_SphereActor>()
	{
		return ASuperMap_SphereActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_SphereActor);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SphereActor_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SphereActor_h_Statics::EnumInfo[] = {
		{ ESuperMap_Sphere_StaticEnum, TEXT("ESuperMap_Sphere"), &Z_Registration_Info_UEnum_ESuperMap_Sphere, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 649130428U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SphereActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_SphereActor, ASuperMap_SphereActor::StaticClass, TEXT("ASuperMap_SphereActor"), &Z_Registration_Info_UClass_ASuperMap_SphereActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_SphereActor), 4229776602U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SphereActor_h_140426548(TEXT("/Script/SuperMap"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SphereActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SphereActor_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SphereActor_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMap_Public_Component_SuperMap_SphereActor_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
