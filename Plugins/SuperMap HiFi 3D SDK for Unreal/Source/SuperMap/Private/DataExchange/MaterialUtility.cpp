// Copyright Epic Games, Inc. All Rights Reserved.
//#if (!SM_FOR_UE_FIVE && WITH_EDITOR)
#ifdef BUILD_EDITOR
#include "DataExchange/MaterialUtility.h"
#include "DataExchange/TexUtility.h"
#include "DataExchange/NameUtility.h"
#include "MtlAnalyzer.h"
#include "Engine/TextureRenderTarget2D.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "Modules/ModuleManager.h"
#include "MtlBaking/Public/IMaterialBakingModule.h"
#include "MtlBaking/Public/MaterialBakingStructures.h"
#include "NormalMapPreview.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialExpressionCustomOutput.h"
#include "Materials/MaterialExpressionClearCoatNormalCustomOutput.h"
#include "Materials/MaterialExpressionTextureCoordinate.h"
#include "MeshDescription.h"
#include "Misc/DefaultValueHelper.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace DataExchange
		{
			//UMaterialInterface* FMaterialUtility::GetDefaultMaterial()
			//{
			//	static UMaterial* DefaultMaterial = FMaterialUtilities::GetBaseMaterial(EGLTFJsonShadingModel::Default);
			//	return DefaultMaterial;
			//}

#if WITH_EDITOR

			bool FMaterialUtility::IsNormalMap(const FMaterialPropertyEx& Property)
			{
				return Property == MP_Normal || Property == TEXT("ClearCoatBottomNormal");
			}

			bool FMaterialUtility::IsSRGB(const FMaterialPropertyEx& Property)
			{
				return Property == MP_BaseColor || Property == MP_EmissiveColor || Property == MP_SubsurfaceColor || Property == TEXT("TransmittanceColor");
			}

#if (ENGINE_MAJOR_VERSION > 4 || ENGINE_MINOR_VERSION >= 27)
			FGuid FMaterialUtility::GetAttributeID(const FMaterialPropertyEx& Property)
			{
				return Property.IsCustomOutput()
					? FMaterialAttributeDefinitionMap::GetCustomAttributeID(Property.CustomOutput.ToString())
					: FMaterialAttributeDefinitionMap::GetID(Property.Type);
			}

			FGuid FMaterialUtility::GetAttributeIDChecked(const FMaterialPropertyEx& Property)
			{
				const FGuid AttributeID = GetAttributeID(Property);
				check(AttributeID != FMaterialAttributeDefinitionMap::GetDefaultID());
				return AttributeID;
			}
#endif

#if (ENGINE_MAJOR_VERSION > 4)
			FVector4f FMaterialUtility::GetPropertyDefaultValue(const FMaterialPropertyEx & Property)
#else
			FVector4 FMaterialUtility::GetPropertyDefaultValue(const FMaterialPropertyEx& Property)
#endif
			{
				return FMaterialAttributeDefinitionMap::GetDefaultValue(GetAttributeIDChecked(Property));
			}

#if (ENGINE_MAJOR_VERSION > 4)
			FVector4f FMaterialUtility::GetPropertyMask(const FMaterialPropertyEx & Property)
			{
				switch (FMaterialAttributeDefinitionMap::GetValueType(GetAttributeIDChecked(Property)))
				{
				case MCT_Float:
				case MCT_Float1: return FVector4f(1, 0, 0, 0);
				case MCT_Float2: return FVector4f(1, 1, 0, 0);
				case MCT_Float3: return FVector4f(1, 1, 1, 0);
				case MCT_Float4: return FVector4f(1, 1, 1, 1);
				default:
					checkNoEntry();
					return FVector4f();
				}
			}
#else
			FVector4 FMaterialUtility::GetPropertyMask(const FMaterialPropertyEx& Property)
			{
				switch (FMaterialAttributeDefinitionMap::GetValueType(GetAttributeIDChecked(Property)))
				{
				case MCT_Float:
				case MCT_Float1: return FVector4(1, 0, 0, 0);
				case MCT_Float2: return FVector4(1, 1, 0, 0);
				case MCT_Float3: return FVector4(1, 1, 1, 0);
				case MCT_Float4: return FVector4(1, 1, 1, 1);
				default:
					checkNoEntry();
					return FVector4();
				}
			}
#endif

			const FExpressionInput* FMaterialUtility::GetInputForProperty(const UMaterialInterface * Material, const FMaterialPropertyEx & Property)
			{
				if (Property.IsCustomOutput())
				{
					const UMaterialExpressionCustomOutput* CustomOutput = GetCustomOutputByName(Material, Property.CustomOutput.ToString());
					return CustomOutput != nullptr ? &CastChecked<UMaterialExpressionClearCoatNormalCustomOutput>(CustomOutput)->Input : nullptr;
				}

				UMaterial* UnderlyingMaterial = const_cast<UMaterial*>(Material->GetMaterial());
				return UnderlyingMaterial->GetExpressionInputForProperty(Property.Type);
			}

			UTexture2D* FMaterialUtility::CreateTransientTexture(const FPropBakeOutput& PropertyBakeOutput, bool bUseSRGB /*= false*/)
			{
				return FTexUtility::CreateTransientTexture(
					PropertyBakeOutput.Pixels.GetData(),
					PropertyBakeOutput.Pixels.Num() * PropertyBakeOutput.Pixels.GetTypeSize(),
					PropertyBakeOutput.Size,
					PropertyBakeOutput.PixelFormat,
					bUseSRGB);
			}

			const UMaterialExpressionCustomOutput* FMaterialUtility::GetCustomOutputByName(const UMaterialInterface* Material, const FString& Name)
			{
				// TODO: should we also search inside material functions and attribute layers?

				for (const UMaterialExpression* Expression : Material->GetMaterial()->Expressions)
				{
					const UMaterialExpressionCustomOutput* CustomOutput = Cast<UMaterialExpressionCustomOutput>(Expression);
					if (CustomOutput != nullptr && CustomOutput->GetDisplayName() == Name)
					{
						return CustomOutput;
					}
				}

				return nullptr;
			}

			FPropBakeOutput FMaterialUtility::BakeMaterialProperty(const FIntPoint & OutputSize, const FMaterialPropertyEx & Property, const UMaterialInterface * Material, int32 TexCoord, const FUeMeshData* MeshData, const FIndexArray & MeshSectionIndices, bool bFillAlpha, bool bAdjustNormalmaps)
			{
				FMeshRenderData MeshSet;
				MeshSet.TextureCoordinateBox = { { 0.0f, 0.0f }, { 1.0f, 1.0f } };
				MeshSet.TextureCoordinateIndex = TexCoord;
				MeshSet.MaterialIndices = MeshSectionIndices; // NOTE: MaterialIndices is actually section indices
				if (MeshData != nullptr)
				{
					MeshSet.MeshDescription = const_cast<FMeshDescription*>(&MeshData->Description);
					MeshSet.LightMap = MeshData->LightMap;
					MeshSet.LightMapIndex = MeshData->LightMapTexCoord;
					MeshSet.LightmapResourceCluster = MeshData->LightMapResourceCluster;
					MeshSet.PrimitiveData = &MeshData->PrimitiveData;
				}

				FMaterialDataEx MatSet;
				MatSet.Material = const_cast<UMaterialInterface*>(Material);
				MatSet.PropertySizes.Add(Property, OutputSize);
				MatSet.bTangentSpaceNormal = true;

				TArray<FMeshRenderData*> MeshSettings;
				TArray<FMaterialDataEx*> MatSettings;
				MeshSettings.Add(&MeshSet);
				MatSettings.Add(&MatSet);

				TArray<FBakeOutputEx> BakeOutputs;
				IMaterialBakingModule& Module = FModuleManager::Get().LoadModuleChecked<IMaterialBakingModule>("MaterialBaking");

				Module.SetLinearBake(true);
				Module.BakeMaterials(MatSettings, MeshSettings, BakeOutputs);
				const bool bIsLinearBake = Module.IsLinearBake(Property);
				Module.SetLinearBake(false);

				FBakeOutputEx& BakeOutput = BakeOutputs[0];

				TArray<FColor> BakedPixels = TArray<FColor>(MoveTemp(BakeOutput.PropertyData.FindChecked(Property)));
				const FIntPoint BakedSize = BakeOutput.PropertySizes.FindChecked(Property);
				const float EmissiveScale = BakeOutput.EmissiveScale;

				if (bFillAlpha)
				{
					// NOTE: alpha is 0 by default after baking a property, but we prefer 255 (1.0).
					// It makes it easier to view the exported textures.
					for (FColor& Pixel : BakedPixels)
					{
						Pixel.A = 255;
					}
				}

				if (bAdjustNormalmaps && IsNormalMap(Property))
				{
					// TODO: add support for adjusting normals in baking module instead
					FTexUtility::FlipGreenChannel(BakedPixels);
				}

				bool bFromSRGB = !bIsLinearBake;
				bool bToSRGB = IsSRGB(Property);
				//FTexUtility::TransformColorSpace(*BakedPixels, bFromSRGB, bToSRGB);
				{
					if (bFromSRGB != bToSRGB)
					{
						if (bToSRGB)
						{
							for (FColor& Pixel : BakedPixels)
							{
								Pixel = Pixel.ReinterpretAsLinear().ToFColor(true);
							}
						}
						else
						{
							for (FColor& Pixel : BakedPixels)
							{
								Pixel = FLinearColor(Pixel).ToFColor(false);
							}
						}
					}
				}

				FPropBakeOutput PropertyBakeOutput(Property, PF_B8G8R8A8, BakedPixels, BakedSize, EmissiveScale, !bIsLinearBake);

				if (BakedPixels.Num() == 1)
				{
					const FColor& Pixel = (BakedPixels)[0];

					PropertyBakeOutput.bIsConstant = true;
					PropertyBakeOutput.ConstantValue = bToSRGB ? FLinearColor(Pixel) : Pixel.ReinterpretAsLinear();
				}

				return PropertyBakeOutput;
			}
				
			//FJsonTexture* FMaterialUtility::AddTexture(FConvertBuilder & Builder, TGLTFSharedArray<FColor> & Pixels, const FIntPoint & TextureSize, bool bIgnoreAlpha, bool bIsNormalMap, const FString & TextureName, EGLTFJsonTextureFilter MinFilter, EGLTFJsonTextureFilter MagFilter, EGLTFJsonTextureWrap WrapS, EGLTFJsonTextureWrap WrapT)
			//{
			//	// TODO: maybe we should reuse existing samplers?
			//	FJsonSampler* JsonSampler = Builder.AddSampler();
			//	JsonSampler->Name = TextureName;
			//	JsonSampler->MinFilter = MinFilter;
			//	JsonSampler->MagFilter = MagFilter;
			//	JsonSampler->WrapS = WrapS;
			//	JsonSampler->WrapT = WrapT;
			//	// TODO: reuse same texture index when image is the same
			//	FJsonTexture* JsonTexture = Builder.AddTexture();
			//	JsonTexture->Name = TextureName;
			//	JsonTexture->Sampler = JsonSampler;
			//	JsonTexture->Source = Builder.AddUniqueImage(Pixels, TextureSize, bIgnoreAlpha, bIsNormalMap ? EGLTFTextureType::Normalmaps : EGLTFTextureType::None, TextureName);
			//	return JsonTexture;
			//}

			FLinearColor FMaterialUtility::GetMask(const FExpressionInput & ExpressionInput)
			{
				return FLinearColor(ExpressionInput.MaskR, ExpressionInput.MaskG, ExpressionInput.MaskB, ExpressionInput.MaskA);
			}

			uint32 FMaterialUtility::GetMaskComponentCount(const FExpressionInput & ExpressionInput)
			{
				return ExpressionInput.MaskR + ExpressionInput.MaskG + ExpressionInput.MaskB + ExpressionInput.MaskA;
			}

			bool FMaterialUtility::TryGetTextureCoordinateIndex(const UMaterialExpressionTextureSample * TextureSampler, int32 & TexCoord, float*& Transform)
			{
				const UMaterialExpression* Expression = TextureSampler->Coordinates.Expression;
				if (Expression == nullptr)
				{
					TexCoord = TextureSampler->ConstCoordinate;
					//Transform = {};
					return true;
				}

				if (const UMaterialExpressionTextureCoordinate * TextureCoordinate = Cast<UMaterialExpressionTextureCoordinate>(Expression))
				{
					TexCoord = TextureCoordinate->CoordinateIndex;
					Transform[0] = TextureCoordinate->UnMirrorU ? TextureCoordinate->UTiling * 0.5 : 0.0;
					Transform[1] = TextureCoordinate->UnMirrorV ? TextureCoordinate->VTiling * 0.5 : 0.0;
					Transform[2] = TextureCoordinate->UTiling * (TextureCoordinate->UnMirrorU ? 0.5 : 1.0);
					Transform[3] = TextureCoordinate->VTiling * (TextureCoordinate->UnMirrorV ? 0.5 : 1.0);
					Transform[4] = 0;
					return true;
				}

				// TODO: add support for advanced expression tree (ex UMaterialExpressionTextureCoordinate -> UMaterialExpressionMultiply -> UMaterialExpressionAdd)

				return false;
			}

			void FMaterialUtility::GetAllTextureCoordinateIndices(const UMaterialInterface * InMaterial, const FMaterialPropertyEx & InProperty, FIndexArray & OutTexCoords)
			{
				FMtlAnalysis Analysis;
				AnalyzeMaterialProperty(InMaterial, InProperty, Analysis);

				const TBitArray<>& TexCoords = Analysis.TextureCoordinates;
				for (int32 Index = 0; Index < TexCoords.Num(); Index++)
				{
					if (TexCoords[Index])
					{
						OutTexCoords.Add(Index);
					}
				}
			}

			void FMaterialUtility::AnalyzeMaterialProperty(const UMaterialInterface * InMaterial, const FMaterialPropertyEx & InProperty, FMtlAnalysis & OutAnalysis)
			{
				if (GetInputForProperty(InMaterial, InProperty) == nullptr)
				{
					OutAnalysis = FMtlAnalysis();
					return;
				}

				UMtlAnalyzer::AnalyzeMaterialPropertyEx(InMaterial, InProperty.Type, InProperty.CustomOutput.ToString(), OutAnalysis);
			}

			FMaterialShadingModelField FMaterialUtility::EvaluateShadingModelExpression(const UMaterialInterface * Material)
			{
				FMtlAnalysis Analysis;
				AnalyzeMaterialProperty(Material, MP_ShadingModel, Analysis);

				int32 Value;
				if (FDefaultValueHelper::ParseInt(Analysis.ParameterCode, Value))
				{
					return static_cast<EMaterialShadingModel>(Value);
				}

				return Analysis.ShadingModels;
			}

#endif

			EMaterialShadingModel FMaterialUtility::GetRichestShadingModel(const FMaterialShadingModelField & ShadingModels)
			{
				if (ShadingModels.HasShadingModel(MSM_ClearCoat))
				{
					return MSM_ClearCoat;
				}

				if (ShadingModels.HasShadingModel(MSM_DefaultLit))
				{
					return MSM_DefaultLit;
				}

				if (ShadingModels.HasShadingModel(MSM_Unlit))
				{
					return MSM_Unlit;
				}

				// TODO: add more shading models when conversion supported

				return ShadingModels.GetFirstShadingModel();
			}

			FString FMaterialUtility::ShadingModelsToString(const FMaterialShadingModelField & ShadingModels)
			{
				FString Result;

				for (uint32 Index = 0; Index < MSM_NUM; Index++)
				{
					const EMaterialShadingModel ShadingModel = static_cast<EMaterialShadingModel>(Index);
					if (ShadingModels.HasShadingModel(ShadingModel))
					{
						FString Name = FNameUtility::GetName(ShadingModel);
						Result += Result.IsEmpty() ? Name : TEXT(", ") + Name;
					}
				}

				return Result;
			}

			bool FMaterialUtility::NeedsMeshData(const UMaterialInterface * Material)
			{
#if WITH_EDITOR
				if (Material != nullptr)
				{
					// TODO: only analyze properties that will be needed for this specific material
					const TArray<FMaterialPropertyEx> Properties =
					{
						MP_BaseColor,
						MP_EmissiveColor,
						MP_Opacity,
						MP_OpacityMask,
						MP_Metallic,
						MP_Roughness,
						MP_Normal,
						MP_AmbientOcclusion,
						MP_CustomData0,
						MP_CustomData1,
						TEXT("ClearCoatBottomNormal"),
					};

					bool bNeedsMeshData = false;
					FMtlAnalysis Analysis;

					// TODO: optimize baking by separating need for vertex data and primitive data

					for (const FMaterialPropertyEx& Property : Properties)
					{
						AnalyzeMaterialProperty(Material, Property, Analysis);
						bNeedsMeshData |= Analysis.bRequiresVertexData;
						bNeedsMeshData |= Analysis.bRequiresPrimitiveData;
					}

					return bNeedsMeshData;
				}
#endif

				return false;
			}

			bool FMaterialUtility::NeedsMeshData(const TArray<const UMaterialInterface*> & Materials)
			{
#if WITH_EDITOR
				for (const UMaterialInterface* Material : Materials)
				{
					if (NeedsMeshData(Material))
					{
						return true;
					}
				}
#endif

				return false;
			}
		}
	}
}
#endif