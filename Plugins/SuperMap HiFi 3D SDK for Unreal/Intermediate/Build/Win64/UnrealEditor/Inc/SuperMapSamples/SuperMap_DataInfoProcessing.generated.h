// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSceneInfo;
struct FDateTime;
struct FWeatherInfo;
struct FPostProcessingInfo;
#ifdef SUPERMAPSAMPLES_SuperMap_DataInfoProcessing_generated_h
#error "SuperMap_DataInfoProcessing.generated.h already included, missing '#pragma once' in SuperMap_DataInfoProcessing.h"
#endif
#define SUPERMAPSAMPLES_SuperMap_DataInfoProcessing_generated_h

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_9_DELEGATE \
static inline void FActorDelegate_DelegateWrapper(const FMulticastScriptDelegate& ActorDelegate) \
{ \
	ActorDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_16_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPostProcessingInfo_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<struct FPostProcessingInfo>();

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_62_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWeatherInfo_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<struct FWeatherInfo>();

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_90_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSceneInfo_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<struct FSceneInfo>();

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_SPARSE_DATA
#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetSceneInfo); \
	DECLARE_FUNCTION(execSetSceneInfo); \
	DECLARE_FUNCTION(execGetWeatherInfo); \
	DECLARE_FUNCTION(execSetWeatherInfo); \
	DECLARE_FUNCTION(execGetPostProcessingInfo); \
	DECLARE_FUNCTION(execSetPostProcessingInfo);


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetSceneInfo); \
	DECLARE_FUNCTION(execSetSceneInfo); \
	DECLARE_FUNCTION(execGetWeatherInfo); \
	DECLARE_FUNCTION(execSetWeatherInfo); \
	DECLARE_FUNCTION(execGetPostProcessingInfo); \
	DECLARE_FUNCTION(execSetPostProcessingInfo);


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASuperMap_DataInfoProcessing(); \
	friend struct Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics; \
public: \
	DECLARE_CLASS(ASuperMap_DataInfoProcessing, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperMapSamples"), NO_API) \
	DECLARE_SERIALIZER(ASuperMap_DataInfoProcessing)


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_INCLASS \
private: \
	static void StaticRegisterNativesASuperMap_DataInfoProcessing(); \
	friend struct Z_Construct_UClass_ASuperMap_DataInfoProcessing_Statics; \
public: \
	DECLARE_CLASS(ASuperMap_DataInfoProcessing, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperMapSamples"), NO_API) \
	DECLARE_SERIALIZER(ASuperMap_DataInfoProcessing)


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASuperMap_DataInfoProcessing(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASuperMap_DataInfoProcessing) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASuperMap_DataInfoProcessing); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASuperMap_DataInfoProcessing); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASuperMap_DataInfoProcessing(ASuperMap_DataInfoProcessing&&); \
	NO_API ASuperMap_DataInfoProcessing(const ASuperMap_DataInfoProcessing&); \
public:


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASuperMap_DataInfoProcessing(ASuperMap_DataInfoProcessing&&); \
	NO_API ASuperMap_DataInfoProcessing(const ASuperMap_DataInfoProcessing&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASuperMap_DataInfoProcessing); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASuperMap_DataInfoProcessing); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASuperMap_DataInfoProcessing)


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_102_PROLOG
#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_SPARSE_DATA \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_RPC_WRAPPERS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_INCLASS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_SPARSE_DATA \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_INCLASS_NO_PURE_DECLS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h_105_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERMAPSAMPLES_API UClass* StaticClass<class ASuperMap_DataInfoProcessing>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_DataInfoProcessing_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
