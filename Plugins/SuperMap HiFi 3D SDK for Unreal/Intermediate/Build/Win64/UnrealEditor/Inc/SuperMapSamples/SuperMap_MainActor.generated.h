// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FMaterialInfo;
 
struct FRealPosition;
struct FSuperMap_LayerInfo;
#ifdef SUPERMAPSAMPLES_SuperMap_MainActor_generated_h
#error "SuperMap_MainActor.generated.h already included, missing '#pragma once' in SuperMap_MainActor.h"
#endif
#define SUPERMAPSAMPLES_SuperMap_MainActor_generated_h

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_20_DELEGATE \
static inline void FMainActorDelegate_DelegateWrapper(const FMulticastScriptDelegate& MainActorDelegate) \
{ \
	MainActorDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_21_DELEGATE \
static inline void FOpenMultiFileDelegate_DelegateWrapper(const FMulticastScriptDelegate& OpenMultiFileDelegate) \
{ \
	OpenMultiFileDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_30_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSuperMapTable_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<struct FSuperMapTable>();

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_52_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSuperMap_LayerInfo_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<struct FSuperMap_LayerInfo>();

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_104_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRealPosition_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<struct FRealPosition>();

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_126_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMaterialInfo_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SUPERMAPSAMPLES_API UScriptStruct* StaticStruct<struct FMaterialInfo>();

#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_SPARSE_DATA
#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetDataSetType); \
	DECLARE_FUNCTION(execSetMaterialParams); \
	DECLARE_FUNCTION(execSetSceneParams); \
	DECLARE_FUNCTION(execSetSceneParamsFromJson); \
	DECLARE_FUNCTION(execExportMaterialFromS3MLayer); \
	DECLARE_FUNCTION(execSetStereoMode); \
	DECLARE_FUNCTION(execDatasetMaterialToJson); \
	DECLARE_FUNCTION(execClearAssetResoure); \
	DECLARE_FUNCTION(execAddAssetResoure); \
	DECLARE_FUNCTION(execQueryField); \
	DECLARE_FUNCTION(execGetFieldInfos); \
	DECLARE_FUNCTION(execGetDatasetName); \
	DECLARE_FUNCTION(execSetImportAsset); \
	DECLARE_FUNCTION(execGetDatasourcePath); \
	DECLARE_FUNCTION(execGetDatasetList); \
	DECLARE_FUNCTION(execSetFieldAssetResoure); \
	DECLARE_FUNCTION(execSetEnableCollision); \
	DECLARE_FUNCTION(execSetEnableComputeNormal); \
	DECLARE_FUNCTION(execGetGeoreferenceOrigin); \
	DECLARE_FUNCTION(execSetGeoreferenceOrigin); \
	DECLARE_FUNCTION(execGetCameraFov); \
	DECLARE_FUNCTION(execSetCameraFov); \
	DECLARE_FUNCTION(execSetUserAction); \
	DECLARE_FUNCTION(execSetEditorAction); \
	DECLARE_FUNCTION(execDeleteObjectMaterialInfo); \
	DECLARE_FUNCTION(execSetObjectMaterialInfo); \
	DECLARE_FUNCTION(execGetSelectMaterialInfo); \
	DECLARE_FUNCTION(execGetRestoreLayers); \
	DECLARE_FUNCTION(execGetS3MLayers); \
	DECLARE_FUNCTION(execGetHypsometricSettingLayers); \
	DECLARE_FUNCTION(execModificationLayerName); \
	DECLARE_FUNCTION(execPlayingActor); \
	DECLARE_FUNCTION(execSetEditorState); \
	DECLARE_FUNCTION(execSetLayerObjectMaterial); \
	DECLARE_FUNCTION(execSetLayerMaterial); \
	DECLARE_FUNCTION(execFromXML); \
	DECLARE_FUNCTION(execToXML); \
	DECLARE_FUNCTION(execGetRealPosition); \
	DECLARE_FUNCTION(execGetLocalPosition); \
	DECLARE_FUNCTION(execIsSecondTerrainLayer); \
	DECLARE_FUNCTION(execGetTerrainLayersCount); \
	DECLARE_FUNCTION(execRemoveLayer_Web); \
	DECLARE_FUNCTION(execRemoveTerrainLayer); \
	DECLARE_FUNCTION(execRemoveLayer); \
	DECLARE_FUNCTION(execAddWMTSMap); \
	DECLARE_FUNCTION(execAddUrlLayers); \
	DECLARE_FUNCTION(execAddLocalLayers); \
	DECLARE_FUNCTION(execGetLayerType); \
	DECLARE_FUNCTION(execSetIsShowRealPosition); \
	DECLARE_FUNCTION(execSetSceneType); \
	DECLARE_FUNCTION(execOpenFileFolderDialog); \
	DECLARE_FUNCTION(execOpenFileDialog);


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDataSetType); \
	DECLARE_FUNCTION(execSetMaterialParams); \
	DECLARE_FUNCTION(execSetSceneParams); \
	DECLARE_FUNCTION(execSetSceneParamsFromJson); \
	DECLARE_FUNCTION(execExportMaterialFromS3MLayer); \
	DECLARE_FUNCTION(execSetStereoMode); \
	DECLARE_FUNCTION(execDatasetMaterialToJson); \
	DECLARE_FUNCTION(execClearAssetResoure); \
	DECLARE_FUNCTION(execAddAssetResoure); \
	DECLARE_FUNCTION(execQueryField); \
	DECLARE_FUNCTION(execGetFieldInfos); \
	DECLARE_FUNCTION(execGetDatasetName); \
	DECLARE_FUNCTION(execSetImportAsset); \
	DECLARE_FUNCTION(execGetDatasourcePath); \
	DECLARE_FUNCTION(execGetDatasetList); \
	DECLARE_FUNCTION(execSetFieldAssetResoure); \
	DECLARE_FUNCTION(execSetEnableCollision); \
	DECLARE_FUNCTION(execSetEnableComputeNormal); \
	DECLARE_FUNCTION(execGetGeoreferenceOrigin); \
	DECLARE_FUNCTION(execSetGeoreferenceOrigin); \
	DECLARE_FUNCTION(execGetCameraFov); \
	DECLARE_FUNCTION(execSetCameraFov); \
	DECLARE_FUNCTION(execSetUserAction); \
	DECLARE_FUNCTION(execSetEditorAction); \
	DECLARE_FUNCTION(execDeleteObjectMaterialInfo); \
	DECLARE_FUNCTION(execSetObjectMaterialInfo); \
	DECLARE_FUNCTION(execGetSelectMaterialInfo); \
	DECLARE_FUNCTION(execGetRestoreLayers); \
	DECLARE_FUNCTION(execGetS3MLayers); \
	DECLARE_FUNCTION(execGetHypsometricSettingLayers); \
	DECLARE_FUNCTION(execModificationLayerName); \
	DECLARE_FUNCTION(execPlayingActor); \
	DECLARE_FUNCTION(execSetEditorState); \
	DECLARE_FUNCTION(execSetLayerObjectMaterial); \
	DECLARE_FUNCTION(execSetLayerMaterial); \
	DECLARE_FUNCTION(execFromXML); \
	DECLARE_FUNCTION(execToXML); \
	DECLARE_FUNCTION(execGetRealPosition); \
	DECLARE_FUNCTION(execGetLocalPosition); \
	DECLARE_FUNCTION(execIsSecondTerrainLayer); \
	DECLARE_FUNCTION(execGetTerrainLayersCount); \
	DECLARE_FUNCTION(execRemoveLayer_Web); \
	DECLARE_FUNCTION(execRemoveTerrainLayer); \
	DECLARE_FUNCTION(execRemoveLayer); \
	DECLARE_FUNCTION(execAddWMTSMap); \
	DECLARE_FUNCTION(execAddUrlLayers); \
	DECLARE_FUNCTION(execAddLocalLayers); \
	DECLARE_FUNCTION(execGetLayerType); \
	DECLARE_FUNCTION(execSetIsShowRealPosition); \
	DECLARE_FUNCTION(execSetSceneType); \
	DECLARE_FUNCTION(execOpenFileFolderDialog); \
	DECLARE_FUNCTION(execOpenFileDialog);


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASuperMap_MainActor(); \
	friend struct Z_Construct_UClass_ASuperMap_MainActor_Statics; \
public: \
	DECLARE_CLASS(ASuperMap_MainActor, ACameraActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperMapSamples"), NO_API) \
	DECLARE_SERIALIZER(ASuperMap_MainActor)


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_INCLASS \
private: \
	static void StaticRegisterNativesASuperMap_MainActor(); \
	friend struct Z_Construct_UClass_ASuperMap_MainActor_Statics; \
public: \
	DECLARE_CLASS(ASuperMap_MainActor, ACameraActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SuperMapSamples"), NO_API) \
	DECLARE_SERIALIZER(ASuperMap_MainActor)


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASuperMap_MainActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASuperMap_MainActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASuperMap_MainActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASuperMap_MainActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASuperMap_MainActor(ASuperMap_MainActor&&); \
	NO_API ASuperMap_MainActor(const ASuperMap_MainActor&); \
public:


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASuperMap_MainActor(ASuperMap_MainActor&&); \
	NO_API ASuperMap_MainActor(const ASuperMap_MainActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASuperMap_MainActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASuperMap_MainActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASuperMap_MainActor)


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_162_PROLOG
#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_SPARSE_DATA \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_RPC_WRAPPERS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_INCLASS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_SPARSE_DATA \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_INCLASS_NO_PURE_DECLS \
	FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h_165_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SUPERMAPSAMPLES_API UClass* StaticClass<class ASuperMap_MainActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_MainActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
