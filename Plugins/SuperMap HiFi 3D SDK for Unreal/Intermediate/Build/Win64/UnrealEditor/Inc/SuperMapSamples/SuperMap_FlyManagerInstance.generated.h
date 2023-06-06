// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRouteStopCameraInfo;
#ifdef SUPERMAPSAMPLES_SuperMap_FlyManagerInstance_generated_h
#error "SuperMap_FlyManagerInstance.generated.h already included, missing '#pragma once' in SuperMap_FlyManagerInstance.h"
#endif
#define SUPERMAPSAMPLES_SuperMap_FlyManagerInstance_generated_h

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRouteStopCameraInfo_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<struct FRouteStopCameraInfo>();

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_40_DELEGATE \
static inline void FFlyManagerDelegate_DelegateWrapper(const FMulticastScriptDelegate& FlyManagerDelegate) \
{ \
	FlyManagerDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_SPARSE_DATA
#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsCurrentRouteTiltFixed); \
	DECLARE_FUNCTION(execSetCurrentRouteTiltFixed); \
	DECLARE_FUNCTION(execIsCurrentRouteHeadingFixed); \
	DECLARE_FUNCTION(execSetCurrentRouteHeadingFixed); \
	DECLARE_FUNCTION(execGetCurrentRouteIndex); \
	DECLARE_FUNCTION(execSetRouteStopCameraParam); \
	DECLARE_FUNCTION(execGetRouteStopCameraParam); \
	DECLARE_FUNCTION(execGetRouteStopName); \
	DECLARE_FUNCTION(execGetNumOfRouteStops); \
	DECLARE_FUNCTION(execGetRouteStop); \
	DECLARE_FUNCTION(execSetRouteStop); \
	DECLARE_FUNCTION(execDeleteRouteStop); \
	DECLARE_FUNCTION(execAddRouteStop); \
	DECLARE_FUNCTION(execSaveRoute); \
	DECLARE_FUNCTION(execCreateRoute); \
	DECLARE_FUNCTION(execSetRouteName); \
	DECLARE_FUNCTION(execGetRouteName); \
	DECLARE_FUNCTION(execSetFlyTurningMode); \
	DECLARE_FUNCTION(execSetCurrentRoute); \
	DECLARE_FUNCTION(execSetEnableLoopFly); \
	DECLARE_FUNCTION(execLaunchFly); \
	DECLARE_FUNCTION(execGetFlyStatus); \
	DECLARE_FUNCTION(execSetFlyStatus); \
	DECLARE_FUNCTION(execSetPlayRate); \
	DECLARE_FUNCTION(execGetDuration); \
	DECLARE_FUNCTION(execSetDuration);


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsCurrentRouteTiltFixed); \
	DECLARE_FUNCTION(execSetCurrentRouteTiltFixed); \
	DECLARE_FUNCTION(execIsCurrentRouteHeadingFixed); \
	DECLARE_FUNCTION(execSetCurrentRouteHeadingFixed); \
	DECLARE_FUNCTION(execGetCurrentRouteIndex); \
	DECLARE_FUNCTION(execSetRouteStopCameraParam); \
	DECLARE_FUNCTION(execGetRouteStopCameraParam); \
	DECLARE_FUNCTION(execGetRouteStopName); \
	DECLARE_FUNCTION(execGetNumOfRouteStops); \
	DECLARE_FUNCTION(execGetRouteStop); \
	DECLARE_FUNCTION(execSetRouteStop); \
	DECLARE_FUNCTION(execDeleteRouteStop); \
	DECLARE_FUNCTION(execAddRouteStop); \
	DECLARE_FUNCTION(execSaveRoute); \
	DECLARE_FUNCTION(execCreateRoute); \
	DECLARE_FUNCTION(execSetRouteName); \
	DECLARE_FUNCTION(execGetRouteName); \
	DECLARE_FUNCTION(execSetFlyTurningMode); \
	DECLARE_FUNCTION(execSetCurrentRoute); \
	DECLARE_FUNCTION(execSetEnableLoopFly); \
	DECLARE_FUNCTION(execLaunchFly); \
	DECLARE_FUNCTION(execGetFlyStatus); \
	DECLARE_FUNCTION(execSetFlyStatus); \
	DECLARE_FUNCTION(execSetPlayRate); \
	DECLARE_FUNCTION(execGetDuration); \
	DECLARE_FUNCTION(execSetDuration);


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASuperMap_FlyManagerInstance(); \
	friend struct Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics; \
public: \
	DECLARE_CLASS(ASuperMap_FlyManagerInstance, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperMapSamples"), NO_API) \
	DECLARE_SERIALIZER(ASuperMap_FlyManagerInstance)


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_INCLASS \
private: \
	static void StaticRegisterNativesASuperMap_FlyManagerInstance(); \
	friend struct Z_Construct_UClass_ASuperMap_FlyManagerInstance_Statics; \
public: \
	DECLARE_CLASS(ASuperMap_FlyManagerInstance, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperMapSamples"), NO_API) \
	DECLARE_SERIALIZER(ASuperMap_FlyManagerInstance)


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASuperMap_FlyManagerInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASuperMap_FlyManagerInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASuperMap_FlyManagerInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASuperMap_FlyManagerInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASuperMap_FlyManagerInstance(ASuperMap_FlyManagerInstance&&); \
	NO_API ASuperMap_FlyManagerInstance(const ASuperMap_FlyManagerInstance&); \
public:


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASuperMap_FlyManagerInstance(ASuperMap_FlyManagerInstance&&); \
	NO_API ASuperMap_FlyManagerInstance(const ASuperMap_FlyManagerInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASuperMap_FlyManagerInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASuperMap_FlyManagerInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASuperMap_FlyManagerInstance)


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_42_PROLOG
#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_SPARSE_DATA \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_RPC_WRAPPERS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_INCLASS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_SPARSE_DATA \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_INCLASS_NO_PURE_DECLS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERMAPSAMPLES_API UClass* StaticClass<class ASuperMap_FlyManagerInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_FlyManagerInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
