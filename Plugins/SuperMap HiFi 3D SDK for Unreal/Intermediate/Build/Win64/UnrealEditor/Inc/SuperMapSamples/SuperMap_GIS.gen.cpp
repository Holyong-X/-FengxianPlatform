// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SuperMap_GIS.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_GIS() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_GIS_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_GIS();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector4();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_GIS::execGetLayer3DType)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_layerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetLayer3DType(Z_Param_layerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetImageLayerOpaqueRate)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_layerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetImageLayerOpaqueRate(Z_Param_layerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetImageLayerOpaqueRate)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_layerName);
		P_GET_PROPERTY(FFloatProperty,Z_Param_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetImageLayerOpaqueRate(Z_Param_layerName,Z_Param_value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetLoadingPriority)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetLoadingPriority(Z_Param_strName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetLoadingPriority)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_PROPERTY(FIntProperty,Z_Param_type);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLoadingPriority(Z_Param_strName,Z_Param_type);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execResetObjectsColor)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetObjectsColor(Z_Param_strName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetObjectsColor)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_TARRAY(int32,Z_Param_ids);
		P_GET_STRUCT(FVector4,Z_Param_color);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetObjectsColor(Z_Param_strName,Z_Param_ids,Z_Param_color);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetLayerMaxObjectVisibleDistance)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetLayerMaxObjectVisibleDistance(Z_Param_strName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetLayerMinObjectVisibleDistance)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLayerMinObjectVisibleDistance(Z_Param_strName,Z_Param_fValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetLayerMaxObjectVisibleDistance)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLayerMaxObjectVisibleDistance(Z_Param_strName,Z_Param_fValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetLayerMarker3DTranslation)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetLayerMarker3DTranslation(Z_Param_strName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetLayerMarker3DTranslation)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_STRUCT(FVector,Z_Param_vTranslation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLayerMarker3DTranslation(Z_Param_strName,Z_Param_vTranslation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetLayerMarker3DRotate)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetLayerMarker3DRotate(Z_Param_strName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetLayerMarker3DRotate)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_STRUCT(FVector,Z_Param_vRotate);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLayerMarker3DRotate(Z_Param_strName,Z_Param_vRotate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetLayerMarker3DScale)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetLayerMarker3DScale(Z_Param_strName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetLayerMarker3DScale)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_STRUCT(FVector,Z_Param_vScale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLayerMarker3DScale(Z_Param_strName,Z_Param_vScale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetSelectStyle)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector4*)Z_Param__Result=P_THIS->GetSelectStyle(Z_Param_strName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetSelectStyle)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_STRUCT(FVector4,Z_Param_color);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSelectStyle(Z_Param_strName,Z_Param_color);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetJsonArrayStringValue)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Descriptor);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetJsonArrayStringValue(Z_Param_Descriptor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetObjectsVisible)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_LayerName);
		P_GET_TARRAY(int32,Z_Param_nIds);
		P_GET_UBOOL(Z_Param_bVisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetObjectsVisible(Z_Param_LayerName,Z_Param_nIds,Z_Param_bVisible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetTerrainExaggeration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetTerrainExaggeration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetTerrainExaggeration)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTerrainExaggeration(Z_Param_fValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetMultiViewportMode)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_nScreenMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMultiViewportMode(Z_Param_nScreenMode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetVisibleInViewport)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_PROPERTY(FIntProperty,Z_Param_nIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetVisibleInViewport(Z_Param_strName,Z_Param_nIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetVisibleInViewport)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strName);
		P_GET_PROPERTY(FIntProperty,Z_Param_nIndex);
		P_GET_UBOOL(Z_Param_visible);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetVisibleInViewport(Z_Param_strName,Z_Param_nIndex,Z_Param_visible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetSkirtHeight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_fheight);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSkirtHeight(Z_Param_fheight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetSkirt)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetSkirt();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetSkirt)
	{
		P_GET_UBOOL(Z_Param_bSetSkirt);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSkirt(Z_Param_bSetSkirt);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetConstantPolygonOffset)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetConstantPolygonOffset(Z_Param_strLayerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetConstantPolygonOffset)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_GET_PROPERTY(FFloatProperty,Z_Param_fOffset);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetConstantPolygonOffset(Z_Param_strLayerName,Z_Param_fOffset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetLayerCenterPoint)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_layerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetLayerCenterPoint(Z_Param_layerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetLayerIsVisible)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_layerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetLayerIsVisible(Z_Param_layerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetIsVisible)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsVisible();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetIsVisible)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_layerName);
		P_GET_UBOOL(Z_Param_isvisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIsVisible(Z_Param_layerName,Z_Param_isvisible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetLayerInfos)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLayerInfos(Z_Param_strLayerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execFlyToLayer)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_layerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FlyToLayer(Z_Param_layerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execEnsureVisible)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_layerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnsureVisible(Z_Param_layerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetShowInvalidation)
	{
		P_GET_UBOOL(Z_Param_bShow);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetShowInvalidation(Z_Param_bShow);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execGetLODRangeScale)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetLODRangeScale();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_GIS::execSetLODRangeScale)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLODRangeScale(Z_Param_value);
		P_NATIVE_END;
	}
	void ASuperMap_GIS::StaticRegisterNativesASuperMap_GIS()
	{
		UClass* Class = ASuperMap_GIS::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EnsureVisible", &ASuperMap_GIS::execEnsureVisible },
			{ "FlyToLayer", &ASuperMap_GIS::execFlyToLayer },
			{ "GetConstantPolygonOffset", &ASuperMap_GIS::execGetConstantPolygonOffset },
			{ "GetImageLayerOpaqueRate", &ASuperMap_GIS::execGetImageLayerOpaqueRate },
			{ "GetIsVisible", &ASuperMap_GIS::execGetIsVisible },
			{ "GetJsonArrayStringValue", &ASuperMap_GIS::execGetJsonArrayStringValue },
			{ "GetLayer3DType", &ASuperMap_GIS::execGetLayer3DType },
			{ "GetLayerCenterPoint", &ASuperMap_GIS::execGetLayerCenterPoint },
			{ "GetLayerIsVisible", &ASuperMap_GIS::execGetLayerIsVisible },
			{ "GetLayerMarker3DRotate", &ASuperMap_GIS::execGetLayerMarker3DRotate },
			{ "GetLayerMarker3DScale", &ASuperMap_GIS::execGetLayerMarker3DScale },
			{ "GetLayerMarker3DTranslation", &ASuperMap_GIS::execGetLayerMarker3DTranslation },
			{ "GetLayerMaxObjectVisibleDistance", &ASuperMap_GIS::execGetLayerMaxObjectVisibleDistance },
			{ "GetLoadingPriority", &ASuperMap_GIS::execGetLoadingPriority },
			{ "GetLODRangeScale", &ASuperMap_GIS::execGetLODRangeScale },
			{ "GetSelectStyle", &ASuperMap_GIS::execGetSelectStyle },
			{ "GetSkirt", &ASuperMap_GIS::execGetSkirt },
			{ "GetTerrainExaggeration", &ASuperMap_GIS::execGetTerrainExaggeration },
			{ "GetVisibleInViewport", &ASuperMap_GIS::execGetVisibleInViewport },
			{ "ResetObjectsColor", &ASuperMap_GIS::execResetObjectsColor },
			{ "SetConstantPolygonOffset", &ASuperMap_GIS::execSetConstantPolygonOffset },
			{ "SetImageLayerOpaqueRate", &ASuperMap_GIS::execSetImageLayerOpaqueRate },
			{ "SetIsVisible", &ASuperMap_GIS::execSetIsVisible },
			{ "SetLayerInfos", &ASuperMap_GIS::execSetLayerInfos },
			{ "SetLayerMarker3DRotate", &ASuperMap_GIS::execSetLayerMarker3DRotate },
			{ "SetLayerMarker3DScale", &ASuperMap_GIS::execSetLayerMarker3DScale },
			{ "SetLayerMarker3DTranslation", &ASuperMap_GIS::execSetLayerMarker3DTranslation },
			{ "SetLayerMaxObjectVisibleDistance", &ASuperMap_GIS::execSetLayerMaxObjectVisibleDistance },
			{ "SetLayerMinObjectVisibleDistance", &ASuperMap_GIS::execSetLayerMinObjectVisibleDistance },
			{ "SetLoadingPriority", &ASuperMap_GIS::execSetLoadingPriority },
			{ "SetLODRangeScale", &ASuperMap_GIS::execSetLODRangeScale },
			{ "SetMultiViewportMode", &ASuperMap_GIS::execSetMultiViewportMode },
			{ "SetObjectsColor", &ASuperMap_GIS::execSetObjectsColor },
			{ "SetObjectsVisible", &ASuperMap_GIS::execSetObjectsVisible },
			{ "SetSelectStyle", &ASuperMap_GIS::execSetSelectStyle },
			{ "SetShowInvalidation", &ASuperMap_GIS::execSetShowInvalidation },
			{ "SetSkirt", &ASuperMap_GIS::execSetSkirt },
			{ "SetSkirtHeight", &ASuperMap_GIS::execSetSkirtHeight },
			{ "SetTerrainExaggeration", &ASuperMap_GIS::execSetTerrainExaggeration },
			{ "SetVisibleInViewport", &ASuperMap_GIS::execSetVisibleInViewport },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics
	{
		struct SuperMap_GIS_eventEnsureVisible_Parms
		{
			FName layerName;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_layerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventEnsureVisible_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::NewProp_layerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe5\xae\x9a\xe4\xbd\x8d\xe5\x88\xb0\xe6\x8c\x87\xe5\xae\x9a\xe5\x9b\xbe\xe5\xb1\x82\n//! \\param layerName [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe5\xae\x9a\xe4\xbd\x8d\xe5\x88\xb0\xe6\x8c\x87\xe5\xae\x9a\xe5\x9b\xbe\xe5\xb1\x82\n! \\param layerName [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "EnsureVisible", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::SuperMap_GIS_eventEnsureVisible_Parms), Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics
	{
		struct SuperMap_GIS_eventFlyToLayer_Parms
		{
			FName layerName;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_layerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventFlyToLayer_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::NewProp_layerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe9\xa3\x9e\xe8\xa1\x8c\xe5\x88\xb0\xe6\x8c\x87\xe5\xae\x9a\xe5\x9b\xbe\xe5\xb1\x82\n//! \\param layerName [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe9\xa3\x9e\xe8\xa1\x8c\xe5\x88\xb0\xe6\x8c\x87\xe5\xae\x9a\xe5\x9b\xbe\xe5\xb1\x82\n! \\param layerName [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "FlyToLayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::SuperMap_GIS_eventFlyToLayer_Parms), Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics
	{
		struct SuperMap_GIS_eventGetConstantPolygonOffset_Parms
		{
			FName strLayerName;
			float ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetConstantPolygonOffset_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetConstantPolygonOffset_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::NewProp_strLayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe5\x81\x8f\xe7\xa7\xbb\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe5\x81\x8f\xe7\xa7\xbb" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetConstantPolygonOffset", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::SuperMap_GIS_eventGetConstantPolygonOffset_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics
	{
		struct SuperMap_GIS_eventGetImageLayerOpaqueRate_Parms
		{
			FName layerName;
			float ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_layerName;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetImageLayerOpaqueRate_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetImageLayerOpaqueRate_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::NewProp_layerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetImageLayerOpaqueRate", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::SuperMap_GIS_eventGetImageLayerOpaqueRate_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics
	{
		struct SuperMap_GIS_eventGetIsVisible_Parms
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
	void Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_GIS_eventGetIsVisible_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GIS_eventGetIsVisible_Parms), &Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief  \xe8\x8e\xb7\xe5\x8f\x96\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief  \xe8\x8e\xb7\xe5\x8f\x96\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetIsVisible", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::SuperMap_GIS_eventGetIsVisible_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics
	{
		struct SuperMap_GIS_eventGetJsonArrayStringValue_Parms
		{
			FString Descriptor;
			TArray<int32> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Descriptor;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::NewProp_Descriptor = { "Descriptor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetJsonArrayStringValue_Parms, Descriptor), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetJsonArrayStringValue_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::NewProp_Descriptor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\breif \xe8\xa7\xa3\xe6\x9e\x90\xe5\xad\x97\xe6\xae\xb5\xef\xbc\x88\xe4\xba\x91\xe6\xb8\xb2\xe6\x9f\x93 \xe8\xae\xbe\xe7\xbd\xae\xe5\xaf\xb9\xe8\xb1\xa1\xe6\x98\xbe\xe9\x9a\x90\xe7\x9b\xb8\xe5\x85\xb3\xef\xbc\x89\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\breif \xe8\xa7\xa3\xe6\x9e\x90\xe5\xad\x97\xe6\xae\xb5\xef\xbc\x88\xe4\xba\x91\xe6\xb8\xb2\xe6\x9f\x93 \xe8\xae\xbe\xe7\xbd\xae\xe5\xaf\xb9\xe8\xb1\xa1\xe6\x98\xbe\xe9\x9a\x90\xe7\x9b\xb8\xe5\x85\xb3\xef\xbc\x89" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetJsonArrayStringValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::SuperMap_GIS_eventGetJsonArrayStringValue_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics
	{
		struct SuperMap_GIS_eventGetLayer3DType_Parms
		{
			FName layerName;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_layerName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayer3DType_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayer3DType_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::NewProp_layerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe7\xbc\x93\xe5\xad\x98\xe5\x9b\xbe\xe5\xb1\x82Type\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe7\xbc\x93\xe5\xad\x98\xe5\x9b\xbe\xe5\xb1\x82Type" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetLayer3DType", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::SuperMap_GIS_eventGetLayer3DType_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics
	{
		struct SuperMap_GIS_eventGetLayerCenterPoint_Parms
		{
			FName layerName;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_layerName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerCenterPoint_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerCenterPoint_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::NewProp_layerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82\xe4\xb8\xad\xe5\xbf\x83\xe7\x82\xb9\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82\xe4\xb8\xad\xe5\xbf\x83\xe7\x82\xb9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetLayerCenterPoint", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::SuperMap_GIS_eventGetLayerCenterPoint_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics
	{
		struct SuperMap_GIS_eventGetLayerIsVisible_Parms
		{
			FString layerName;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_layerName;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerIsVisible_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_GIS_eventGetLayerIsVisible_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GIS_eventGetLayerIsVisible_Parms), &Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::NewProp_layerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetLayerIsVisible", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::SuperMap_GIS_eventGetLayerIsVisible_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics
	{
		struct SuperMap_GIS_eventGetLayerMarker3DRotate_Parms
		{
			FName strName;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerMarker3DRotate_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerMarker3DRotate_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\breif \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe6\x97\x8b\xe8\xbd\xac\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\breif \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe6\x97\x8b\xe8\xbd\xac" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetLayerMarker3DRotate", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::SuperMap_GIS_eventGetLayerMarker3DRotate_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics
	{
		struct SuperMap_GIS_eventGetLayerMarker3DScale_Parms
		{
			FName strName;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerMarker3DScale_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerMarker3DScale_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\breif \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe7\xbc\xa9\xe6\x94\xbe\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\breif \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe7\xbc\xa9\xe6\x94\xbe" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetLayerMarker3DScale", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::SuperMap_GIS_eventGetLayerMarker3DScale_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics
	{
		struct SuperMap_GIS_eventGetLayerMarker3DTranslation_Parms
		{
			FName strName;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerMarker3DTranslation_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerMarker3DTranslation_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\breif \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe5\xb9\xb3\xe7\xa7\xbb\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\breif \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe5\xb9\xb3\xe7\xa7\xbb" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetLayerMarker3DTranslation", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::SuperMap_GIS_eventGetLayerMarker3DTranslation_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics
	{
		struct SuperMap_GIS_eventGetLayerMaxObjectVisibleDistance_Parms
		{
			FName strName;
			float ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerMaxObjectVisibleDistance_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLayerMaxObjectVisibleDistance_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetLayerMaxObjectVisibleDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::SuperMap_GIS_eventGetLayerMaxObjectVisibleDistance_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics
	{
		struct SuperMap_GIS_eventGetLoadingPriority_Parms
		{
			FName strName;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLoadingPriority_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLoadingPriority_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetLoadingPriority", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::SuperMap_GIS_eventGetLoadingPriority_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics
	{
		struct SuperMap_GIS_eventGetLODRangeScale_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetLODRangeScale_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82LOD\xe5\xb1\x82\xe7\xba\xa7\n//! \\return \n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9b\xbe\xe5\xb1\x82LOD\xe5\xb1\x82\xe7\xba\xa7\n! \\return" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetLODRangeScale", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::SuperMap_GIS_eventGetLODRangeScale_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics
	{
		struct SuperMap_GIS_eventGetSelectStyle_Parms
		{
			FName strName;
			FVector4 ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetSelectStyle_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetSelectStyle_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetSelectStyle", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::SuperMap_GIS_eventGetSelectStyle_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics
	{
		struct SuperMap_GIS_eventGetSkirt_Parms
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
	void Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_GIS_eventGetSkirt_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GIS_eventGetSkirt_Parms), &Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe8\xa3\x99\xe8\xbe\xb9\xe8\xae\xbe\xe7\xbd\xae\xe7\x8a\xb6\xe6\x80\x81\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe8\xa3\x99\xe8\xbe\xb9\xe8\xae\xbe\xe7\xbd\xae\xe7\x8a\xb6\xe6\x80\x81" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetSkirt", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::SuperMap_GIS_eventGetSkirt_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetSkirt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetSkirt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics
	{
		struct SuperMap_GIS_eventGetTerrainExaggeration_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetTerrainExaggeration_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9c\xb0\xe5\xbd\xa2\xe5\xa4\xb8\xe5\xbc\xa0\xe6\x95\xb0\xe5\x80\xbc\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9c\xb0\xe5\xbd\xa2\xe5\xa4\xb8\xe5\xbc\xa0\xe6\x95\xb0\xe5\x80\xbc" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetTerrainExaggeration", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::SuperMap_GIS_eventGetTerrainExaggeration_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics
	{
		struct SuperMap_GIS_eventGetVisibleInViewport_Parms
		{
			FName strName;
			int32 nIndex;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nIndex;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetVisibleInViewport_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::NewProp_nIndex = { "nIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventGetVisibleInViewport_Parms, nIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_GIS_eventGetVisibleInViewport_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GIS_eventGetVisibleInViewport_Parms), &Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::NewProp_nIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x88\x86\xe5\xb1\x8f\xe6\x98\xbe\xe5\xbd\xb1\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\x8e\xb7\xe5\x8f\x96\xe5\x88\x86\xe5\xb1\x8f\xe6\x98\xbe\xe5\xbd\xb1" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "GetVisibleInViewport", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::SuperMap_GIS_eventGetVisibleInViewport_Parms), Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics
	{
		struct SuperMap_GIS_eventResetObjectsColor_Parms
		{
			FName strName;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventResetObjectsColor_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::NewProp_strName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xbf\x98\xe5\x8e\x9f\xe5\x9b\xbe\xe5\xb1\x82\xe5\xaf\xb9\xe8\xb1\xa1\xe8\xae\xbe\xe7\xbd\xae\xe7\x9a\x84\xe9\xa2\x9c\xe8\x89\xb2\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xbf\x98\xe5\x8e\x9f\xe5\x9b\xbe\xe5\xb1\x82\xe5\xaf\xb9\xe8\xb1\xa1\xe8\xae\xbe\xe7\xbd\xae\xe7\x9a\x84\xe9\xa2\x9c\xe8\x89\xb2" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "ResetObjectsColor", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::SuperMap_GIS_eventResetObjectsColor_Parms), Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics
	{
		struct SuperMap_GIS_eventSetConstantPolygonOffset_Parms
		{
			FName strLayerName;
			float fOffset;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fOffset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetConstantPolygonOffset_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::NewProp_fOffset = { "fOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetConstantPolygonOffset_Parms, fOffset), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::NewProp_strLayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::NewProp_fOffset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe5\x81\x8f\xe7\xa7\xbb\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe5\x81\x8f\xe7\xa7\xbb" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetConstantPolygonOffset", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::SuperMap_GIS_eventSetConstantPolygonOffset_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics
	{
		struct SuperMap_GIS_eventSetImageLayerOpaqueRate_Parms
		{
			FName layerName;
			float value;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_layerName;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetImageLayerOpaqueRate_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetImageLayerOpaqueRate_Parms, value), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::NewProp_layerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xbd\xb1\xe5\x83\x8f\xe5\x9b\xbe\xe5\xb1\x82\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xbd\xb1\xe5\x83\x8f\xe5\x9b\xbe\xe5\xb1\x82\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetImageLayerOpaqueRate", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::SuperMap_GIS_eventSetImageLayerOpaqueRate_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics
	{
		struct SuperMap_GIS_eventSetIsVisible_Parms
		{
			FName layerName;
			bool isvisible;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_layerName;
		static void NewProp_isvisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isvisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::NewProp_layerName = { "layerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetIsVisible_Parms, layerName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::NewProp_isvisible_SetBit(void* Obj)
	{
		((SuperMap_GIS_eventSetIsVisible_Parms*)Obj)->isvisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::NewProp_isvisible = { "isvisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GIS_eventSetIsVisible_Parms), &Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::NewProp_isvisible_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::NewProp_layerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::NewProp_isvisible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe9\x9a\x90\xe8\x97\x8f\xe5\x9b\xbe\xe5\xb1\x82\n//! \\param layerName [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0\n//! \\param isvisible [in] true\xe6\x98\xbe\xe7\xa4\xba\xe5\x9b\xbe\xe5\xb1\x82\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe9\x9a\x90\xe8\x97\x8f\xe5\x9b\xbe\xe5\xb1\x82\n! \\param layerName [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0\n! \\param isvisible [in] true\xe6\x98\xbe\xe7\xa4\xba\xe5\x9b\xbe\xe5\xb1\x82" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetIsVisible", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::SuperMap_GIS_eventSetIsVisible_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics
	{
		struct SuperMap_GIS_eventSetLayerInfos_Parms
		{
			FName strLayerName;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerInfos_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::NewProp_strLayerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe4\xbf\xa1\xe6\x81\xaf\n//! \\param strLayerName [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\n//! \\param isSelection [in] true \xe6\x89\x93\xe5\xbc\x80\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe4\xbf\xa1\xe6\x81\xaf\n! \\param strLayerName [in] \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\n! \\param isSelection [in] true \xe6\x89\x93\xe5\xbc\x80" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetLayerInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::SuperMap_GIS_eventSetLayerInfos_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics
	{
		struct SuperMap_GIS_eventSetLayerMarker3DRotate_Parms
		{
			FName strName;
			FVector vRotate;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_vRotate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMarker3DRotate_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::NewProp_vRotate = { "vRotate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMarker3DRotate_Parms, vRotate), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::NewProp_vRotate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\breif \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe6\x97\x8b\xe8\xbd\xac\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\breif \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe6\x97\x8b\xe8\xbd\xac" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetLayerMarker3DRotate", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::SuperMap_GIS_eventSetLayerMarker3DRotate_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics
	{
		struct SuperMap_GIS_eventSetLayerMarker3DScale_Parms
		{
			FName strName;
			FVector vScale;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_vScale;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMarker3DScale_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::NewProp_vScale = { "vScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMarker3DScale_Parms, vScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::NewProp_vScale,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\breif \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe7\xbc\xa9\xe6\x94\xbe\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\breif \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe7\xbc\xa9\xe6\x94\xbe" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetLayerMarker3DScale", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::SuperMap_GIS_eventSetLayerMarker3DScale_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics
	{
		struct SuperMap_GIS_eventSetLayerMarker3DTranslation_Parms
		{
			FName strName;
			FVector vTranslation;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_vTranslation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMarker3DTranslation_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::NewProp_vTranslation = { "vTranslation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMarker3DTranslation_Parms, vTranslation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::NewProp_vTranslation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\breif \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe5\xb9\xb3\xe7\xa7\xbb\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\breif \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe7\x9a\x84\xe5\xb9\xb3\xe7\xa7\xbb" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetLayerMarker3DTranslation", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::SuperMap_GIS_eventSetLayerMarker3DTranslation_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics
	{
		struct SuperMap_GIS_eventSetLayerMaxObjectVisibleDistance_Parms
		{
			FName strName;
			float fValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMaxObjectVisibleDistance_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::NewProp_fValue = { "fValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMaxObjectVisibleDistance_Parms, fValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::NewProp_fValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe6\x9c\x80\xe8\xbf\x9c\xe5\x8f\xaf\xe8\xa7\x81\xe8\xb7\x9d\xe7\xa6\xbb\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe6\x9c\x80\xe8\xbf\x9c\xe5\x8f\xaf\xe8\xa7\x81\xe8\xb7\x9d\xe7\xa6\xbb" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetLayerMaxObjectVisibleDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::SuperMap_GIS_eventSetLayerMaxObjectVisibleDistance_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics
	{
		struct SuperMap_GIS_eventSetLayerMinObjectVisibleDistance_Parms
		{
			FName strName;
			float fValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMinObjectVisibleDistance_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::NewProp_fValue = { "fValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLayerMinObjectVisibleDistance_Parms, fValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::NewProp_fValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe6\x9c\x80\xe8\xbf\x91\xe5\x8f\xaf\xe8\xa7\x81\xe8\xb7\x9d\xe7\xa6\xbb\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe6\x9c\x80\xe8\xbf\x91\xe5\x8f\xaf\xe8\xa7\x81\xe8\xb7\x9d\xe7\xa6\xbb" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetLayerMinObjectVisibleDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::SuperMap_GIS_eventSetLayerMinObjectVisibleDistance_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics
	{
		struct SuperMap_GIS_eventSetLoadingPriority_Parms
		{
			FName strName;
			int32 type;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_type;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLoadingPriority_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLoadingPriority_Parms, type), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::NewProp_type,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe5\x8a\xa0\xe8\xbd\xbd\xe6\x95\xb0\xe6\x8d\xae\xe6\xa8\xa1\xe5\xbc\x8f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe5\x8a\xa0\xe8\xbd\xbd\xe6\x95\xb0\xe6\x8d\xae\xe6\xa8\xa1\xe5\xbc\x8f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetLoadingPriority", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::SuperMap_GIS_eventSetLoadingPriority_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics
	{
		struct SuperMap_GIS_eventSetLODRangeScale_Parms
		{
			float value;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetLODRangeScale_Parms, value), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82LOD\xe5\xb1\x82\xe7\xba\xa7\n//! \\param value [in] \xe5\xb1\x82\xe7\xba\xa7\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82LOD\xe5\xb1\x82\xe7\xba\xa7\n! \\param value [in] \xe5\xb1\x82\xe7\xba\xa7" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetLODRangeScale", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::SuperMap_GIS_eventSetLODRangeScale_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics
	{
		struct SuperMap_GIS_eventSetMultiViewportMode_Parms
		{
			int32 nScreenMode;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nScreenMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::NewProp_nScreenMode = { "nScreenMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetMultiViewportMode_Parms, nScreenMode), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::NewProp_nScreenMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x88\x86\xe5\xb1\x8f\xe7\x9b\xb8\xe6\x9c\xba\xe8\xa7\x86\xe9\x87\x8e\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x88\x86\xe5\xb1\x8f\xe7\x9b\xb8\xe6\x9c\xba\xe8\xa7\x86\xe9\x87\x8e" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetMultiViewportMode", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::SuperMap_GIS_eventSetMultiViewportMode_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics
	{
		struct SuperMap_GIS_eventSetObjectsColor_Parms
		{
			FName strName;
			TArray<int32> ids;
			FVector4 color;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ids_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ids;
		static const UECodeGen_Private::FStructPropertyParams NewProp_color;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetObjectsColor_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::NewProp_ids_Inner = { "ids", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::NewProp_ids = { "ids", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetObjectsColor_Parms, ids), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::NewProp_color = { "color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetObjectsColor_Parms, color), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::NewProp_ids_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::NewProp_ids,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::NewProp_color,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe5\xaf\xb9\xe8\xb1\xa1\xe9\xa2\x9c\xe8\x89\xb2\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9b\xbe\xe5\xb1\x82\xe5\xaf\xb9\xe8\xb1\xa1\xe9\xa2\x9c\xe8\x89\xb2" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetObjectsColor", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::SuperMap_GIS_eventSetObjectsColor_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics
	{
		struct SuperMap_GIS_eventSetObjectsVisible_Parms
		{
			FName LayerName;
			TArray<int32> nIds;
			bool bVisible;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_LayerName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nIds_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_nIds;
		static void NewProp_bVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_LayerName = { "LayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetObjectsVisible_Parms, LayerName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_nIds_Inner = { "nIds", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_nIds = { "nIds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetObjectsVisible_Parms, nIds), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_bVisible_SetBit(void* Obj)
	{
		((SuperMap_GIS_eventSetObjectsVisible_Parms*)Obj)->bVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GIS_eventSetObjectsVisible_Parms), &Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_LayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_nIds_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_nIds,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::NewProp_bVisible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetObjectsVisible", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::SuperMap_GIS_eventSetObjectsVisible_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics
	{
		struct SuperMap_GIS_eventSetSelectStyle_Parms
		{
			FName strName;
			FVector4 color;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_color;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetSelectStyle_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::NewProp_color = { "color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetSelectStyle_Parms, color), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::NewProp_color,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetSelectStyle", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::SuperMap_GIS_eventSetSelectStyle_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics
	{
		struct SuperMap_GIS_eventSetShowInvalidation_Parms
		{
			bool bShow;
		};
		static void NewProp_bShow_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShow;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::NewProp_bShow_SetBit(void* Obj)
	{
		((SuperMap_GIS_eventSetShowInvalidation_Parms*)Obj)->bShow = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::NewProp_bShow = { "bShow", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GIS_eventSetShowInvalidation_Parms), &Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::NewProp_bShow_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::NewProp_bShow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe6\x97\xa0\xe6\x95\x88\xe5\x8c\xba\xe5\x9f\x9f\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe6\x97\xa0\xe6\x95\x88\xe5\x8c\xba\xe5\x9f\x9f" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetShowInvalidation", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::SuperMap_GIS_eventSetShowInvalidation_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics
	{
		struct SuperMap_GIS_eventSetSkirt_Parms
		{
			bool bSetSkirt;
		};
		static void NewProp_bSetSkirt_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSetSkirt;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::NewProp_bSetSkirt_SetBit(void* Obj)
	{
		((SuperMap_GIS_eventSetSkirt_Parms*)Obj)->bSetSkirt = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::NewProp_bSetSkirt = { "bSetSkirt", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GIS_eventSetSkirt_Parms), &Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::NewProp_bSetSkirt_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::NewProp_bSetSkirt,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe8\xa3\x99\xe8\xbe\xb9\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe8\xa3\x99\xe8\xbe\xb9" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetSkirt", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::SuperMap_GIS_eventSetSkirt_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetSkirt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetSkirt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics
	{
		struct SuperMap_GIS_eventSetSkirtHeight_Parms
		{
			float fheight;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fheight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::NewProp_fheight = { "fheight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetSkirtHeight_Parms, fheight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::NewProp_fheight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe8\xa3\x99\xe8\xbe\xb9\xe9\xab\x98\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe8\xa3\x99\xe8\xbe\xb9\xe9\xab\x98\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetSkirtHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::SuperMap_GIS_eventSetSkirtHeight_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics
	{
		struct SuperMap_GIS_eventSetTerrainExaggeration_Parms
		{
			float fValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_fValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::NewProp_fValue = { "fValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetTerrainExaggeration_Parms, fValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::NewProp_fValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xb0\xe5\xbd\xa2\xe5\xa4\xb8\xe5\xbc\xa0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xb0\xe5\xbd\xa2\xe5\xa4\xb8\xe5\xbc\xa0" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetTerrainExaggeration", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::SuperMap_GIS_eventSetTerrainExaggeration_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics
	{
		struct SuperMap_GIS_eventSetVisibleInViewport_Parms
		{
			FName strName;
			int32 nIndex;
			bool visible;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strName;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_nIndex;
		static void NewProp_visible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_visible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::NewProp_strName = { "strName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetVisibleInViewport_Parms, strName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::NewProp_nIndex = { "nIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_GIS_eventSetVisibleInViewport_Parms, nIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::NewProp_visible_SetBit(void* Obj)
	{
		((SuperMap_GIS_eventSetVisibleInViewport_Parms*)Obj)->visible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::NewProp_visible = { "visible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_GIS_eventSetVisibleInViewport_Parms), &Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::NewProp_visible_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::NewProp_strName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::NewProp_nIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::NewProp_visible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x88\x86\xe5\xb1\x8f\xe6\x98\xbe\xe5\xbd\xb1\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe8\xae\xbe\xe7\xbd\xae\xe5\x88\x86\xe5\xb1\x8f\xe6\x98\xbe\xe5\xbd\xb1" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_GIS, nullptr, "SetVisibleInViewport", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::SuperMap_GIS_eventSetVisibleInViewport_Parms), Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_GIS);
	UClass* Z_Construct_UClass_ASuperMap_GIS_NoRegister()
	{
		return ASuperMap_GIS::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_GIS_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_m_strLayerName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_m_strLayerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_GIS_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_GIS_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_GIS_EnsureVisible, "EnsureVisible" }, // 3069317028
		{ &Z_Construct_UFunction_ASuperMap_GIS_FlyToLayer, "FlyToLayer" }, // 3784538097
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetConstantPolygonOffset, "GetConstantPolygonOffset" }, // 413985539
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetImageLayerOpaqueRate, "GetImageLayerOpaqueRate" }, // 1440854182
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetIsVisible, "GetIsVisible" }, // 3976444749
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetJsonArrayStringValue, "GetJsonArrayStringValue" }, // 2246557249
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetLayer3DType, "GetLayer3DType" }, // 2444965103
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetLayerCenterPoint, "GetLayerCenterPoint" }, // 835931379
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetLayerIsVisible, "GetLayerIsVisible" }, // 1373632587
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DRotate, "GetLayerMarker3DRotate" }, // 3169484502
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DScale, "GetLayerMarker3DScale" }, // 827020067
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetLayerMarker3DTranslation, "GetLayerMarker3DTranslation" }, // 852384381
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetLayerMaxObjectVisibleDistance, "GetLayerMaxObjectVisibleDistance" }, // 185347132
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetLoadingPriority, "GetLoadingPriority" }, // 2948843132
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetLODRangeScale, "GetLODRangeScale" }, // 3907942377
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetSelectStyle, "GetSelectStyle" }, // 130893543
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetSkirt, "GetSkirt" }, // 2681136300
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetTerrainExaggeration, "GetTerrainExaggeration" }, // 4013440160
		{ &Z_Construct_UFunction_ASuperMap_GIS_GetVisibleInViewport, "GetVisibleInViewport" }, // 128997717
		{ &Z_Construct_UFunction_ASuperMap_GIS_ResetObjectsColor, "ResetObjectsColor" }, // 3758017711
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetConstantPolygonOffset, "SetConstantPolygonOffset" }, // 2806488418
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetImageLayerOpaqueRate, "SetImageLayerOpaqueRate" }, // 3513428877
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetIsVisible, "SetIsVisible" }, // 1986814231
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetLayerInfos, "SetLayerInfos" }, // 3378800922
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DRotate, "SetLayerMarker3DRotate" }, // 539226530
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DScale, "SetLayerMarker3DScale" }, // 343117134
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetLayerMarker3DTranslation, "SetLayerMarker3DTranslation" }, // 2898912430
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetLayerMaxObjectVisibleDistance, "SetLayerMaxObjectVisibleDistance" }, // 1671362529
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetLayerMinObjectVisibleDistance, "SetLayerMinObjectVisibleDistance" }, // 790352707
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetLoadingPriority, "SetLoadingPriority" }, // 2080449017
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetLODRangeScale, "SetLODRangeScale" }, // 204832191
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetMultiViewportMode, "SetMultiViewportMode" }, // 1455580479
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetObjectsColor, "SetObjectsColor" }, // 45132733
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetObjectsVisible, "SetObjectsVisible" }, // 1667003654
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetSelectStyle, "SetSelectStyle" }, // 322800619
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetShowInvalidation, "SetShowInvalidation" }, // 318932937
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetSkirt, "SetSkirt" }, // 1405246553
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetSkirtHeight, "SetSkirtHeight" }, // 2864697551
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetTerrainExaggeration, "SetTerrainExaggeration" }, // 3276900494
		{ &Z_Construct_UFunction_ASuperMap_GIS_SetVisibleInViewport, "SetVisibleInViewport" }, // 4199125872
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_GIS_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SuperMap_GIS.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_GIS_Statics::NewProp_m_strLayerName_MetaData[] = {
		{ "Category", "SuperMap_GIS" },
		{ "Comment", "//! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0\n" },
		{ "ModuleRelativePath", "Public/SuperMap_GIS.h" },
		{ "ToolTip", "! \\brief \xe5\x9b\xbe\xe5\xb1\x82\xe5\x90\x8d\xe7\xa7\xb0" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ASuperMap_GIS_Statics::NewProp_m_strLayerName = { "m_strLayerName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASuperMap_GIS, m_strLayerName), METADATA_PARAMS(Z_Construct_UClass_ASuperMap_GIS_Statics::NewProp_m_strLayerName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_GIS_Statics::NewProp_m_strLayerName_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASuperMap_GIS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASuperMap_GIS_Statics::NewProp_m_strLayerName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_GIS_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_GIS>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_GIS_Statics::ClassParams = {
		&ASuperMap_GIS::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASuperMap_GIS_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_GIS_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_GIS_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_GIS_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_GIS()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_GIS.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_GIS.OuterSingleton, Z_Construct_UClass_ASuperMap_GIS_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_GIS.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_GIS>()
	{
		return ASuperMap_GIS::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_GIS);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_GIS_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_GIS_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_GIS, ASuperMap_GIS::StaticClass, TEXT("ASuperMap_GIS"), &Z_Registration_Info_UClass_ASuperMap_GIS, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_GIS), 717811476U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_GIS_h_1600266788(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_GIS_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SuperMap_GIS_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
