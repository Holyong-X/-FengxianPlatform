// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SceneOperation/SuperMap_FlyManagerInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_FlyManagerInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UScriptStruct* Z_Construct_UScriptStruct_FRouteStopCameraInfo();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	SUPERMAPSAMPLES_API UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_FlyManagerDelegate__DelegateSignature();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FlyManagerInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_FlyManagerInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RouteStopCameraInfo;
class UScriptStruct* FRouteStopCameraInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RouteStopCameraInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RouteStopCameraInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRouteStopCameraInfo, Z_Construct_UPackage__Script_SuperMapSamples(), TEXT("RouteStopCameraInfo"));
	}
	return Z_Registration_Info_UScriptStruct_RouteStopCameraInfo.OuterSingleton;
}
template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<FRouteStopCameraInfo>()
{
	return FRouteStopCameraInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fLon_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fLon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fLat_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fLat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fAltitude_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fAltitude;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fTilt_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fTilt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fHeading_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fHeading;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fRoll_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fRoll;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fDuration_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fDuration;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRouteStopCameraInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLon_MetaData[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLon = { "fLon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRouteStopCameraInfo, fLon), METADATA_PARAMS(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLon_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLon_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLat_MetaData[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLat = { "fLat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRouteStopCameraInfo, fLat), METADATA_PARAMS(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLat_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLat_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fAltitude_MetaData[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fAltitude = { "fAltitude", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRouteStopCameraInfo, fAltitude), METADATA_PARAMS(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fAltitude_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fAltitude_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fTilt_MetaData[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fTilt = { "fTilt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRouteStopCameraInfo, fTilt), METADATA_PARAMS(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fTilt_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fTilt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fHeading_MetaData[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fHeading = { "fHeading", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRouteStopCameraInfo, fHeading), METADATA_PARAMS(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fHeading_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fHeading_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fRoll_MetaData[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fRoll = { "fRoll", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRouteStopCameraInfo, fRoll), METADATA_PARAMS(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fRoll_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fRoll_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fDuration_MetaData[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fDuration = { "fDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRouteStopCameraInfo, fDuration), METADATA_PARAMS(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fDuration_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fDuration_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fLat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fAltitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fTilt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fHeading,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fRoll,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewProp_fDuration,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
		nullptr,
		&NewStructOps,
		"RouteStopCameraInfo",
		sizeof(FRouteStopCameraInfo),
		alignof(FRouteStopCameraInfo),
		Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FRouteStopCameraInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_RouteStopCameraInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RouteStopCameraInfo.InnerSingleton, Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_RouteStopCameraInfo.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_SuperMapSamples_FlyManagerDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SuperMapSamples_FlyManagerDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SuperMapSamples_FlyManagerDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SuperMapSamples, nullptr, "FlyManagerDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SuperMapSamples_FlyManagerDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SuperMapSamples_FlyManagerDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SuperMapSamples_FlyManagerDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SuperMapSamples_FlyManagerDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execIsCurrentRouteTiltFixed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsCurrentRouteTiltFixed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetCurrentRouteTiltFixed)
	{
		P_GET_UBOOL(Z_Param_bSet);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCurrentRouteTiltFixed(Z_Param_bSet);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execIsCurrentRouteHeadingFixed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsCurrentRouteHeadingFixed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetCurrentRouteHeadingFixed)
	{
		P_GET_UBOOL(Z_Param_bSet);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCurrentRouteHeadingFixed(Z_Param_bSet);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execGetCurrentRouteIndex)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetCurrentRouteIndex();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetRouteStopCameraParam)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_RouteStopName);
		P_GET_STRUCT(FRouteStopCameraInfo,Z_Param_info);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRouteStopCameraParam(Z_Param_RouteStopName,Z_Param_info);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execGetRouteStopCameraParam)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_RouteStopName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FRouteStopCameraInfo*)Z_Param__Result=P_THIS->GetRouteStopCameraParam(Z_Param_RouteStopName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execGetRouteStopName)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetRouteStopName(Z_Param_nIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execGetNumOfRouteStops)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumOfRouteStops();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execGetRouteStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetRouteStop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetRouteStop)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRouteStop(Z_Param_nIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execDeleteRouteStop)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_RouteStopName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DeleteRouteStop(Z_Param_RouteStopName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execAddRouteStop)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_RouteStopName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddRouteStop(Z_Param_RouteStopName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSaveRoute)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SaveRoute(Z_Param_FileName,Z_Param_FilePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execCreateRoute)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_RouteName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateRoute(Z_Param_RouteName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetRouteName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_name);
		P_GET_PROPERTY(FIntProperty,Z_Param_nIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRouteName(Z_Param_name,Z_Param_nIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execGetRouteName)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetRouteName(Z_Param_nIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetFlyTurningMode)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFlyTurningMode(Z_Param_nMode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetCurrentRoute)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCurrentRoute(Z_Param_nIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetEnableLoopFly)
	{
		P_GET_UBOOL(Z_Param_bEnableLoop);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEnableLoopFly(Z_Param_bEnableLoop);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execLaunchFly)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FlyFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->LaunchFly(Z_Param_FlyFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execGetFlyStatus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetFlyStatus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetFlyStatus)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nStatus);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFlyStatus(Z_Param_nStatus);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetPlayRate)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_dPlayRate);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPlayRate(Z_Param_dPlayRate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execGetDuration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetDuration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_FlyManagerInstance::execSetDuration)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_dDuration);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDuration(Z_Param_dDuration);
		P_NATIVE_END;
	}
	void ASuperMap_FlyManagerInstance::StaticRegisterNativesASuperMap_FlyManagerInstance()
	{
		UClass* Class = ASuperMap_FlyManagerInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddRouteStop", &ASuperMap_FlyManagerInstance::execAddRouteStop },
			{ "CreateRoute", &ASuperMap_FlyManagerInstance::execCreateRoute },
			{ "DeleteRouteStop", &ASuperMap_FlyManagerInstance::execDeleteRouteStop },
			{ "GetCurrentRouteIndex", &ASuperMap_FlyManagerInstance::execGetCurrentRouteIndex },
			{ "GetDuration", &ASuperMap_FlyManagerInstance::execGetDuration },
			{ "GetFlyStatus", &ASuperMap_FlyManagerInstance::execGetFlyStatus },
			{ "GetNumOfRouteStops", &ASuperMap_FlyManagerInstance::execGetNumOfRouteStops },
			{ "GetRouteName", &ASuperMap_FlyManagerInstance::execGetRouteName },
			{ "GetRouteStop", &ASuperMap_FlyManagerInstance::execGetRouteStop },
			{ "GetRouteStopCameraParam", &ASuperMap_FlyManagerInstance::execGetRouteStopCameraParam },
			{ "GetRouteStopName", &ASuperMap_FlyManagerInstance::execGetRouteStopName },
			{ "IsCurrentRouteHeadingFixed", &ASuperMap_FlyManagerInstance::execIsCurrentRouteHeadingFixed },
			{ "IsCurrentRouteTiltFixed", &ASuperMap_FlyManagerInstance::execIsCurrentRouteTiltFixed },
			{ "LaunchFly", &ASuperMap_FlyManagerInstance::execLaunchFly },
			{ "SaveRoute", &ASuperMap_FlyManagerInstance::execSaveRoute },
			{ "SetCurrentRoute", &ASuperMap_FlyManagerInstance::execSetCurrentRoute },
			{ "SetCurrentRouteHeadingFixed", &ASuperMap_FlyManagerInstance::execSetCurrentRouteHeadingFixed },
			{ "SetCurrentRouteTiltFixed", &ASuperMap_FlyManagerInstance::execSetCurrentRouteTiltFixed },
			{ "SetDuration", &ASuperMap_FlyManagerInstance::execSetDuration },
			{ "SetEnableLoopFly", &ASuperMap_FlyManagerInstance::execSetEnableLoopFly },
			{ "SetFlyStatus", &ASuperMap_FlyManagerInstance::execSetFlyStatus },
			{ "SetFlyTurningMode", &ASuperMap_FlyManagerInstance::execSetFlyTurningMode },
			{ "SetPlayRate", &ASuperMap_FlyManagerInstance::execSetPlayRate },
			{ "SetRouteName", &ASuperMap_FlyManagerInstance::execSetRouteName },
			{ "SetRouteStop", &ASuperMap_FlyManagerInstance::execSetRouteStop },
			{ "SetRouteStopCameraParam", &ASuperMap_FlyManagerInstance::execSetRouteStopCameraParam },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics
	{
		struct SuperMap_FlyManagerInstance_eventAddRouteStop_Parms
		{
			FString RouteStopName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_RouteStopName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::NewProp_RouteStopName = { "RouteStopName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventAddRouteStop_Parms, RouteStopName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::NewProp_RouteStopName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief ????\xd5\xbe??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief ????\xd5\xbe??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "AddRouteStop", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::SuperMap_FlyManagerInstance_eventAddRouteStop_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics
	{
		struct SuperMap_FlyManagerInstance_eventCreateRoute_Parms
		{
			FString RouteName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_RouteName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::NewProp_RouteName = { "RouteName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventCreateRoute_Parms, RouteName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::NewProp_RouteName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief ?\xc2\xbd?\xc2\xb7??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief ?\xc2\xbd?\xc2\xb7??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "CreateRoute", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::SuperMap_FlyManagerInstance_eventCreateRoute_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics
	{
		struct SuperMap_FlyManagerInstance_eventDeleteRouteStop_Parms
		{
			FString RouteStopName;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_RouteStopName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::NewProp_RouteStopName = { "RouteStopName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventDeleteRouteStop_Parms, RouteStopName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::NewProp_RouteStopName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief \xc9\xbe??\xd5\xbe??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief \xc9\xbe??\xd5\xbe??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "DeleteRouteStop", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::SuperMap_FlyManagerInstance_eventDeleteRouteStop_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics
	{
		struct SuperMap_FlyManagerInstance_eventGetCurrentRouteIndex_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetCurrentRouteIndex_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ??\xc8\xa1\xc2\xb7??????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ??\xc8\xa1\xc2\xb7??????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "GetCurrentRouteIndex", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::SuperMap_FlyManagerInstance_eventGetCurrentRouteIndex_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics
	{
		struct SuperMap_FlyManagerInstance_eventGetDuration_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetDuration_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ??\xc8\xa1????\xca\xb1??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ??\xc8\xa1????\xca\xb1??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "GetDuration", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::SuperMap_FlyManagerInstance_eventGetDuration_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics
	{
		struct SuperMap_FlyManagerInstance_eventGetFlyStatus_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetFlyStatus_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ??\xc8\xa1????\xd7\xb4\xcc\xac\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ??\xc8\xa1????\xd7\xb4\xcc\xac" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "GetFlyStatus", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::SuperMap_FlyManagerInstance_eventGetFlyStatus_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics
	{
		struct SuperMap_FlyManagerInstance_eventGetNumOfRouteStops_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetNumOfRouteStops_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ??\xc8\xa1??\xc7\xb0????\xc2\xb7??\xd5\xbe??????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ??\xc8\xa1??\xc7\xb0????\xc2\xb7??\xd5\xbe??????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "GetNumOfRouteStops", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::SuperMap_FlyManagerInstance_eventGetNumOfRouteStops_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics
	{
		struct SuperMap_FlyManagerInstance_eventGetRouteName_Parms
		{
			int32 nIndex;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nIndex;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::NewProp_nIndex = { "nIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetRouteName_Parms, nIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetRouteName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::NewProp_nIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ??\xc8\xa1??????\xc2\xb7??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ??\xc8\xa1??????\xc2\xb7??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "GetRouteName", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::SuperMap_FlyManagerInstance_eventGetRouteName_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics
	{
		struct SuperMap_FlyManagerInstance_eventGetRouteStop_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetRouteStop_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ??\xc8\xa1??\xc7\xb0????\xca\xb1???\xda\xb5?\xd5\xbe??\xce\xbb?\xc3\xa3??????\xd0\xba???\xcd\xa3\xca\xb1??\xd0\xa7??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ??\xc8\xa1??\xc7\xb0????\xca\xb1???\xda\xb5?\xd5\xbe??\xce\xbb?\xc3\xa3??????\xd0\xba???\xcd\xa3\xca\xb1??\xd0\xa7??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "GetRouteStop", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::SuperMap_FlyManagerInstance_eventGetRouteStop_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics
	{
		struct SuperMap_FlyManagerInstance_eventGetRouteStopCameraParam_Parms
		{
			FString RouteStopName;
			FRouteStopCameraInfo ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_RouteStopName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::NewProp_RouteStopName = { "RouteStopName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetRouteStopCameraParam_Parms, RouteStopName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetRouteStopCameraParam_Parms, ReturnValue), Z_Construct_UScriptStruct_FRouteStopCameraInfo, METADATA_PARAMS(nullptr, 0) }; // 1056960246
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::NewProp_RouteStopName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ??\xc8\xa1\xd5\xbe????????????\xcf\xa2\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ??\xc8\xa1\xd5\xbe????????????\xcf\xa2" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "GetRouteStopCameraParam", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::SuperMap_FlyManagerInstance_eventGetRouteStopCameraParam_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics
	{
		struct SuperMap_FlyManagerInstance_eventGetRouteStopName_Parms
		{
			int32 nIndex;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nIndex;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::NewProp_nIndex = { "nIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetRouteStopName_Parms, nIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventGetRouteStopName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::NewProp_nIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ??\xc8\xa1??????\xc2\xb7\xd5\xbe????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ??\xc8\xa1??????\xc2\xb7\xd5\xbe????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "GetRouteStopName", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::SuperMap_FlyManagerInstance_eventGetRouteStopName_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics
	{
		struct SuperMap_FlyManagerInstance_eventIsCurrentRouteHeadingFixed_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_FlyManagerInstance_eventIsCurrentRouteHeadingFixed_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FlyManagerInstance_eventIsCurrentRouteHeadingFixed_Parms), &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "IsCurrentRouteHeadingFixed", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::SuperMap_FlyManagerInstance_eventIsCurrentRouteHeadingFixed_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics
	{
		struct SuperMap_FlyManagerInstance_eventIsCurrentRouteTiltFixed_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_FlyManagerInstance_eventIsCurrentRouteTiltFixed_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FlyManagerInstance_eventIsCurrentRouteTiltFixed_Parms), &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "IsCurrentRouteTiltFixed", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::SuperMap_FlyManagerInstance_eventIsCurrentRouteTiltFixed_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics
	{
		struct SuperMap_FlyManagerInstance_eventLaunchFly_Parms
		{
			FString FlyFile;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_FlyFile;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::NewProp_FlyFile = { "FlyFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventLaunchFly_Parms, FlyFile), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventLaunchFly_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::NewProp_FlyFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ???\xd8\xb7???\xc2\xb7????????????\xce\xaa-1\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ???\xd8\xb7???\xc2\xb7????????????\xce\xaa-1" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "LaunchFly", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::SuperMap_FlyManagerInstance_eventLaunchFly_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSaveRoute_Parms
		{
			FString FileName;
			FString FilePath;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSaveRoute_Parms, FileName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSaveRoute_Parms, FilePath), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::NewProp_FileName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::NewProp_FilePath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief ????\xc2\xb7??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief ????\xc2\xb7??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SaveRoute", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::SuperMap_FlyManagerInstance_eventSaveRoute_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetCurrentRoute_Parms
		{
			int32 nIndex;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::NewProp_nIndex = { "nIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetCurrentRoute_Parms, nIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::NewProp_nIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  \xd1\xa1????????\xc2\xb7\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  \xd1\xa1????????\xc2\xb7" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetCurrentRoute", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::SuperMap_FlyManagerInstance_eventSetCurrentRoute_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetCurrentRouteHeadingFixed_Parms
		{
			bool bSet;
		};
		static void NewProp_bSet_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSet;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::NewProp_bSet_SetBit(void* Obj)
	{
		((SuperMap_FlyManagerInstance_eventSetCurrentRouteHeadingFixed_Parms*)Obj)->bSet = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::NewProp_bSet = { "bSet", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FlyManagerInstance_eventSetCurrentRouteHeadingFixed_Parms), &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::NewProp_bSet_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::NewProp_bSet,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ?????\xc7\xb7??????\xd3\xbd?\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ?????\xc7\xb7??????\xd3\xbd?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetCurrentRouteHeadingFixed", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::SuperMap_FlyManagerInstance_eventSetCurrentRouteHeadingFixed_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetCurrentRouteTiltFixed_Parms
		{
			bool bSet;
		};
		static void NewProp_bSet_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSet;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::NewProp_bSet_SetBit(void* Obj)
	{
		((SuperMap_FlyManagerInstance_eventSetCurrentRouteTiltFixed_Parms*)Obj)->bSet = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::NewProp_bSet = { "bSet", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FlyManagerInstance_eventSetCurrentRouteTiltFixed_Parms), &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::NewProp_bSet_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::NewProp_bSet,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ?????\xc7\xb7???????\xd0\xb1?\xd3\xbd?\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ?????\xc7\xb7???????\xd0\xb1?\xd3\xbd?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetCurrentRouteTiltFixed", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::SuperMap_FlyManagerInstance_eventSetCurrentRouteTiltFixed_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetDuration_Parms
		{
			float dDuration;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_dDuration;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::NewProp_dDuration = { "dDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetDuration_Parms, dDuration), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::NewProp_dDuration,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ???\xc3\xb7???\xca\xb1??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ???\xc3\xb7???\xca\xb1??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetDuration", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::SuperMap_FlyManagerInstance_eventSetDuration_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetEnableLoopFly_Parms
		{
			bool bEnableLoop;
		};
		static void NewProp_bEnableLoop_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableLoop;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::NewProp_bEnableLoop_SetBit(void* Obj)
	{
		((SuperMap_FlyManagerInstance_eventSetEnableLoopFly_Parms*)Obj)->bEnableLoop = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::NewProp_bEnableLoop = { "bEnableLoop", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_FlyManagerInstance_eventSetEnableLoopFly_Parms), &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::NewProp_bEnableLoop_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::NewProp_bEnableLoop,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ???\xc3\xb7???\xd1\xad??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ???\xc3\xb7???\xd1\xad??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetEnableLoopFly", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::SuperMap_FlyManagerInstance_eventSetEnableLoopFly_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetFlyStatus_Parms
		{
			int32 nStatus;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nStatus;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::NewProp_nStatus = { "nStatus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetFlyStatus_Parms, nStatus), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::NewProp_nStatus,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ??\xc8\xa1????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ??\xc8\xa1????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetFlyStatus", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::SuperMap_FlyManagerInstance_eventSetFlyStatus_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetFlyTurningMode_Parms
		{
			int32 nMode;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::NewProp_nMode = { "nMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetFlyTurningMode_Parms, nMode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::NewProp_nMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ???\xc3\xb7???\xd7\xaa??\xc4\xa3\xca\xbd\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ???\xc3\xb7???\xd7\xaa??\xc4\xa3\xca\xbd" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetFlyTurningMode", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::SuperMap_FlyManagerInstance_eventSetFlyTurningMode_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetPlayRate_Parms
		{
			float dPlayRate;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_dPlayRate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::NewProp_dPlayRate = { "dPlayRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetPlayRate_Parms, dPlayRate), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::NewProp_dPlayRate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ???\xc3\xb7???????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ???\xc3\xb7???????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetPlayRate", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::SuperMap_FlyManagerInstance_eventSetPlayRate_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetRouteName_Parms
		{
			FString name;
			int32 nIndex;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_name;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetRouteName_Parms, name), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::NewProp_nIndex = { "nIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetRouteName_Parms, nIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::NewProp_name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::NewProp_nIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief  ???\xc3\xb7?????\xc2\xb7??\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief  ???\xc3\xb7?????\xc2\xb7??" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetRouteName", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::SuperMap_FlyManagerInstance_eventSetRouteName_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetRouteStop_Parms
		{
			int32 nIndex;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::NewProp_nIndex = { "nIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetRouteStop_Parms, nIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::NewProp_nIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief ??????????\xce\xaa\xd6\xb8??????\xd5\xbe??????????\xd7\xb4\xcc\xac\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief ??????????\xce\xaa\xd6\xb8??????\xd5\xbe??????????\xd7\xb4\xcc\xac" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetRouteStop", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::SuperMap_FlyManagerInstance_eventSetRouteStop_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics
	{
		struct SuperMap_FlyManagerInstance_eventSetRouteStopCameraParam_Parms
		{
			FString RouteStopName;
			FRouteStopCameraInfo info;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_RouteStopName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_info;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::NewProp_RouteStopName = { "RouteStopName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetRouteStopCameraParam_Parms, RouteStopName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::NewProp_info = { "info", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_FlyManagerInstance_eventSetRouteStopCameraParam_Parms, info), Z_Construct_UScriptStruct_FRouteStopCameraInfo, METADATA_PARAMS(nullptr, 0) }; // 1056960246
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::NewProp_RouteStopName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::NewProp_info,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_FlyManagerInstance" },
		{ "Comment", "//! brief ????\xd5\xbe????????????\xcf\xa2\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ToolTip", "! brief ????\xd5\xbe????????????\xcf\xa2" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_FlyManagerInstance, nullptr, "SetRouteStopCameraParam", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::SuperMap_FlyManagerInstance_eventSetRouteStopCameraParam_Parms), Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_FlyManagerInstance);
	UClass* Z_Construct_UClass_ASuperMap_FlyManagerInstance_NoRegister()
	{
		return ASuperMap_FlyManagerInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallFlyManagerEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CallFlyManagerEvent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_AddRouteStop, "AddRouteStop" }, // 3317167019
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_CreateRoute, "CreateRoute" }, // 15409458
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_DeleteRouteStop, "DeleteRouteStop" }, // 906961582
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetCurrentRouteIndex, "GetCurrentRouteIndex" }, // 850005333
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetDuration, "GetDuration" }, // 1100398117
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetFlyStatus, "GetFlyStatus" }, // 3902703284
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetNumOfRouteStops, "GetNumOfRouteStops" }, // 866089494
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteName, "GetRouteName" }, // 240764970
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStop, "GetRouteStop" }, // 805114206
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopCameraParam, "GetRouteStopCameraParam" }, // 3407186494
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_GetRouteStopName, "GetRouteStopName" }, // 3333595589
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteHeadingFixed, "IsCurrentRouteHeadingFixed" }, // 2549977358
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_IsCurrentRouteTiltFixed, "IsCurrentRouteTiltFixed" }, // 61735519
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_LaunchFly, "LaunchFly" }, // 432968985
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SaveRoute, "SaveRoute" }, // 3531953178
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRoute, "SetCurrentRoute" }, // 575975706
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteHeadingFixed, "SetCurrentRouteHeadingFixed" }, // 1157338956
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetCurrentRouteTiltFixed, "SetCurrentRouteTiltFixed" }, // 2067089544
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetDuration, "SetDuration" }, // 1305076987
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetEnableLoopFly, "SetEnableLoopFly" }, // 1095898386
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyStatus, "SetFlyStatus" }, // 1072049116
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetFlyTurningMode, "SetFlyTurningMode" }, // 3402884514
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetPlayRate, "SetPlayRate" }, // 3911199793
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteName, "SetRouteName" }, // 942372567
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStop, "SetRouteStop" }, // 1393868264
		{ &Z_Construct_UFunction_ASuperMap_FlyManagerInstance_SetRouteStopCameraParam, "SetRouteStopCameraParam" }, // 1269186029
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SceneOperation/SuperMap_FlyManagerInstance.h" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::NewProp_CallFlyManagerEvent_MetaData[] = {
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_FlyManagerInstance.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::NewProp_CallFlyManagerEvent = { "CallFlyManagerEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_FlyManagerInstance, CallFlyManagerEvent), Z_Construct_UDelegateFunction_SuperMapSamples_FlyManagerDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::NewProp_CallFlyManagerEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::NewProp_CallFlyManagerEvent_MetaData)) }; // 2071229567
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::NewProp_CallFlyManagerEvent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_FlyManagerInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::ClassParams = {
		&ASuperMap_FlyManagerInstance::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_FlyManagerInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_FlyManagerInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_FlyManagerInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_FlyManagerInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_FlyManagerInstance>()
	{
		return ASuperMap_FlyManagerInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_FlyManagerInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_Statics::ScriptStructInfo[] = {
		{ FRouteStopCameraInfo::StaticStruct, Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics::NewStructOps, TEXT("RouteStopCameraInfo"), &Z_Registration_Info_UScriptStruct_RouteStopCameraInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRouteStopCameraInfo), 1056960246U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_FlyManagerInstance, ASuperMap_FlyManagerInstance::StaticClass, TEXT("ASuperMap_FlyManagerInstance"), &Z_Registration_Info_UClass_ASuperMap_FlyManagerInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_FlyManagerInstance), 606387685U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_4082938403(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
