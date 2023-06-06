// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperMapSamples/Public/SceneOperation/SuperMap_SwipeInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSuperMap_SwipeInstance() {}
// Cross Module References
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_SwipeInstance_NoRegister();
	SUPERMAPSAMPLES_API UClass* Z_Construct_UClass_ASuperMap_SwipeInstance();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SuperMapSamples();
// End Cross Module References
	DEFINE_FUNCTION(ASuperMap_SwipeInstance::execSetSwipeLeft)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_left);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSwipeLeft(Z_Param_left);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SwipeInstance::execSetSwipeRight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_right);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSwipeRight(Z_Param_right);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SwipeInstance::execSetSwipeBottom)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_bottom);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSwipeBottom(Z_Param_bottom);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SwipeInstance::execSetSwipeTop)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_top);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSwipeTop(Z_Param_top);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SwipeInstance::execGetSwipeEnabled)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetSwipeEnabled(Z_Param_strLayerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASuperMap_SwipeInstance::execSetSwipe)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_strLayerName);
		P_GET_UBOOL(Z_Param_bSelected);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSwipe(Z_Param_strLayerName,Z_Param_bSelected);
		P_NATIVE_END;
	}
	void ASuperMap_SwipeInstance::StaticRegisterNativesASuperMap_SwipeInstance()
	{
		UClass* Class = ASuperMap_SwipeInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetSwipeEnabled", &ASuperMap_SwipeInstance::execGetSwipeEnabled },
			{ "SetSwipe", &ASuperMap_SwipeInstance::execSetSwipe },
			{ "SetSwipeBottom", &ASuperMap_SwipeInstance::execSetSwipeBottom },
			{ "SetSwipeLeft", &ASuperMap_SwipeInstance::execSetSwipeLeft },
			{ "SetSwipeRight", &ASuperMap_SwipeInstance::execSetSwipeRight },
			{ "SetSwipeTop", &ASuperMap_SwipeInstance::execSetSwipeTop },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics
	{
		struct SuperMap_SwipeInstance_eventGetSwipeEnabled_Parms
		{
			FName strLayerName;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SwipeInstance_eventGetSwipeEnabled_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SuperMap_SwipeInstance_eventGetSwipeEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_SwipeInstance_eventGetSwipeEnabled_Parms), &Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::NewProp_strLayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SwipeInstance" },
		{ "Comment", "//! \\brief ??\xc8\xa1\xcd\xbc???\xc7\xb7?????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_SwipeInstance.h" },
		{ "ToolTip", "! \\brief ??\xc8\xa1\xcd\xbc???\xc7\xb7?????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SwipeInstance, nullptr, "GetSwipeEnabled", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::SuperMap_SwipeInstance_eventGetSwipeEnabled_Parms), Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics
	{
		struct SuperMap_SwipeInstance_eventSetSwipe_Parms
		{
			FName strLayerName;
			bool bSelected;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_strLayerName;
		static void NewProp_bSelected_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSelected;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::NewProp_strLayerName = { "strLayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SwipeInstance_eventSetSwipe_Parms, strLayerName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::NewProp_bSelected_SetBit(void* Obj)
	{
		((SuperMap_SwipeInstance_eventSetSwipe_Parms*)Obj)->bSelected = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::NewProp_bSelected = { "bSelected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SuperMap_SwipeInstance_eventSetSwipe_Parms), &Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::NewProp_bSelected_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::NewProp_strLayerName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::NewProp_bSelected,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SwipeInstance" },
		{ "Comment", "//! \\brief ???\xc3\xbe???\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_SwipeInstance.h" },
		{ "ToolTip", "! \\brief ???\xc3\xbe???" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SwipeInstance, nullptr, "SetSwipe", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::SuperMap_SwipeInstance_eventSetSwipe_Parms), Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics
	{
		struct SuperMap_SwipeInstance_eventSetSwipeBottom_Parms
		{
			float bottom;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_bottom;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::NewProp_bottom = { "bottom", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SwipeInstance_eventSetSwipeBottom_Parms, bottom), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::NewProp_bottom,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SwipeInstance" },
		{ "Comment", "//??\\brief ?????\xc2\xb7?\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_SwipeInstance.h" },
		{ "ToolTip", "??\\brief ?????\xc2\xb7?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SwipeInstance, nullptr, "SetSwipeBottom", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::SuperMap_SwipeInstance_eventSetSwipeBottom_Parms), Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics
	{
		struct SuperMap_SwipeInstance_eventSetSwipeLeft_Parms
		{
			float left;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_left;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::NewProp_left = { "left", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SwipeInstance_eventSetSwipeLeft_Parms, left), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::NewProp_left,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SwipeInstance" },
		{ "Comment", "//??\\brief ????????\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_SwipeInstance.h" },
		{ "ToolTip", "??\\brief ????????" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SwipeInstance, nullptr, "SetSwipeLeft", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::SuperMap_SwipeInstance_eventSetSwipeLeft_Parms), Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics
	{
		struct SuperMap_SwipeInstance_eventSetSwipeRight_Parms
		{
			float right;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_right;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::NewProp_right = { "right", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SwipeInstance_eventSetSwipeRight_Parms, right), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::NewProp_right,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SwipeInstance" },
		{ "Comment", "//??\\brief ?????\xd2\xb2?\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_SwipeInstance.h" },
		{ "ToolTip", "??\\brief ?????\xd2\xb2?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SwipeInstance, nullptr, "SetSwipeRight", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::SuperMap_SwipeInstance_eventSetSwipeRight_Parms), Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics
	{
		struct SuperMap_SwipeInstance_eventSetSwipeTop_Parms
		{
			float top;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_top;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::NewProp_top = { "top", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SuperMap_SwipeInstance_eventSetSwipeTop_Parms, top), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::NewProp_top,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::Function_MetaDataParams[] = {
		{ "Category", "SuperMap_SwipeInstance" },
		{ "Comment", "//??\\brief ?????\xcf\xb7?\n" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_SwipeInstance.h" },
		{ "ToolTip", "??\\brief ?????\xcf\xb7?" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASuperMap_SwipeInstance, nullptr, "SetSwipeTop", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::SuperMap_SwipeInstance_eventSetSwipeTop_Parms), Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASuperMap_SwipeInstance);
	UClass* Z_Construct_UClass_ASuperMap_SwipeInstance_NoRegister()
	{
		return ASuperMap_SwipeInstance::StaticClass();
	}
	struct Z_Construct_UClass_ASuperMap_SwipeInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASuperMap_SwipeInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperMapSamples,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASuperMap_SwipeInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASuperMap_SwipeInstance_GetSwipeEnabled, "GetSwipeEnabled" }, // 742928908
		{ &Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipe, "SetSwipe" }, // 2967827933
		{ &Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeBottom, "SetSwipeBottom" }, // 3658331501
		{ &Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeLeft, "SetSwipeLeft" }, // 1816964032
		{ &Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeRight, "SetSwipeRight" }, // 3815389668
		{ &Z_Construct_UFunction_ASuperMap_SwipeInstance_SetSwipeTop, "SetSwipeTop" }, // 1954773681
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASuperMap_SwipeInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SceneOperation/SuperMap_SwipeInstance.h" },
		{ "ModuleRelativePath", "Public/SceneOperation/SuperMap_SwipeInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASuperMap_SwipeInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASuperMap_SwipeInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASuperMap_SwipeInstance_Statics::ClassParams = {
		&ASuperMap_SwipeInstance::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASuperMap_SwipeInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASuperMap_SwipeInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASuperMap_SwipeInstance()
	{
		if (!Z_Registration_Info_UClass_ASuperMap_SwipeInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASuperMap_SwipeInstance.OuterSingleton, Z_Construct_UClass_ASuperMap_SwipeInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASuperMap_SwipeInstance.OuterSingleton;
	}
	template<> SUPERMAPSAMPLES_API UClass* StaticClass<ASuperMap_SwipeInstance>()
	{
		return ASuperMap_SwipeInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASuperMap_SwipeInstance);
	struct Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_SwipeInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_SwipeInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASuperMap_SwipeInstance, ASuperMap_SwipeInstance::StaticClass, TEXT("ASuperMap_SwipeInstance"), &Z_Registration_Info_UClass_ASuperMap_SwipeInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASuperMap_SwipeInstance), 3584509035U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_SwipeInstance_h_2511487919(TEXT("/Script/SuperMapSamples"),
		Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_SwipeInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FengxianPlatform_Plugins_SuperMap_HiFi_3D_SDK_for_Unreal_Source_SuperMapSamples_Public_SceneOperation_SuperMap_SwipeInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
