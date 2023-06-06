//#if (!SM_FOR_UE_FIVE && WITH_EDITOR)
#ifdef BUILD_EDITOR
#include "DataExchange/MaterialConverter.h"
#include "DataExchange/NameUtility.h"
#include "DataExchange/MaterialUtility.h"
#include "Materials/MaterialExpressionConstant.h"
#include "Materials/MaterialExpressionConstant2Vector.h"
#include "Materials/MaterialExpressionConstant3Vector.h"
#include "Materials/MaterialExpressionConstant4Vector.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Logging/LogMacros.h"
PRAGMA_DISABLE_OPTIMIZATION

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace DataExchange
		{
			namespace
			{
				// Component masks
				const FLinearColor RedMask(1.0f, 0.0f, 0.0f, 0.0f);
				const FLinearColor GreenMask(0.0f, 1.0f, 0.0f, 0.0f);
				const FLinearColor BlueMask(0.0f, 0.0f, 1.0f, 0.0f);
				const FLinearColor AlphaMask(0.0f, 0.0f, 0.0f, 1.0f);
				const FLinearColor RgbMask = RedMask + GreenMask + BlueMask;
				const FLinearColor RgbaMask = RgbMask + AlphaMask;

				// Property-specific component masks
				const FLinearColor BaseColorMask = RgbMask;
				const FLinearColor OpacityMask = AlphaMask;
				const FLinearColor MetallicMask = BlueMask;
				const FLinearColor RoughnessMask = GreenMask;
				const FLinearColor OcclusionMask = RedMask;
				const FLinearColor ClearCoatMask = RedMask;
				const FLinearColor ClearCoatRoughnessMask = GreenMask;

				// Ideal masks for texture-inputs (doesn't require baking)
				const TArray<FLinearColor> DefaultColorInputMasks = { RgbMask, RgbaMask };
				const TArray<FLinearColor> BaseColorInputMasks = { BaseColorMask };
				const TArray<FLinearColor> OpacityInputMasks = { OpacityMask };
				const TArray<FLinearColor> MetallicInputMasks = { MetallicMask };
				const TArray<FLinearColor> RoughnessInputMasks = { RoughnessMask };
				const TArray<FLinearColor> OcclusionInputMasks = { OcclusionMask };
				const TArray<FLinearColor> ClearCoatInputMasks = { ClearCoatMask };
				const TArray<FLinearColor> ClearCoatRoughnessInputMasks = { ClearCoatRoughnessMask };

#pragma region param
				const FIntPoint TexSize = { 512,512 };
#pragma endregion
			}

			UVArray::~UVArray()
			{
				if (m_pTexCoord != nullptr)
				{
					delete[] m_pTexCoord;
					m_pTexCoord = nullptr;
				}
			}

			SubMeshData::~SubMeshData()
			{
				if (m_pPos != nullptr)
				{
					delete[] m_pPos;
					m_pPos = nullptr;
				}
				if (m_pIndices != nullptr)
				{
					delete[] m_pIndices;
					m_pIndices = nullptr;
				}
				if (m_pNormals != nullptr)
				{
					delete[] m_pNormals;
					m_pNormals = nullptr;
				}
				if (m_pPosColor != nullptr)
				{
					delete[] m_pPosColor;
					m_pPosColor = nullptr;
				}
				if (m_pUVs != nullptr)
				{
					delete[] m_pUVs;
					m_pUVs = nullptr;
				}
				if (mtlData != nullptr)
				{
					delete mtlData;
					mtlData = nullptr;
				}
				if (mtlName != nullptr)
				{
					delete mtlName;
					mtlName = nullptr;
				}
			}

			MeshData::~MeshData()
			{
				if (subMeshData != nullptr)
				{
					delete[]subMeshData;
					subMeshData = nullptr;
				}
				if (m_ObjectMat != nullptr)
				{
					delete[]m_ObjectMat;
					m_ObjectMat = nullptr;
				}
				if (m_strName != nullptr)
				{
					delete m_strName;
					m_strName = nullptr;
				}
			}

			MaterialData::~MaterialData()
			{
				if (name != nullptr)
				{
				}
				if (baseTexMap != nullptr)
				{
					delete baseTexMap;
					baseTexMap = nullptr;
				}
				if (baseColorFactor != nullptr)
				{
					delete[] baseColorFactor;
					baseColorFactor = nullptr;
				}
				if (MetallicRoughMap != nullptr)
				{
					delete MetallicRoughMap;
					MetallicRoughMap = nullptr;
				}
				if (OcclusionMap != nullptr)
				{
					delete OcclusionMap;
					OcclusionMap = nullptr;
				}
				if (EmissionMap != nullptr)
				{
					delete EmissionMap;
					EmissionMap = nullptr;
				}
				if (EmissionFactor != nullptr)
				{
					delete[] EmissionFactor;
				}
				if (NormalMap != nullptr)
				{
					delete NormalMap;
					NormalMap = nullptr;
				}
				if (BaseTex_matrix != nullptr)
				{
					delete BaseTex_matrix;
					BaseTex_matrix = nullptr;
				}
				if (MetallicRough_matrix != nullptr)
				{
					delete BaseTex_matrix;
					BaseTex_matrix = nullptr;
				}
				if (Occlusion_matrix != nullptr)
				{
					delete BaseTex_matrix;
					BaseTex_matrix = nullptr;
				}
				if (Emission_matrix != nullptr)
				{
					delete BaseTex_matrix;
					BaseTex_matrix = nullptr;
				}
				if (Normal_matrix != nullptr)
				{
					delete BaseTex_matrix;
					BaseTex_matrix = nullptr;
				}
			}

			TexMappingData::~TexMappingData()
			{
				if (texData != nullptr)
				{
					delete texData;
					texData = nullptr;
				}
				if (texName != nullptr)
				{
					delete texName;
					texName = nullptr;
				}
				delete[] transForm;
				transForm = nullptr;
			}

			Gamevoid FMaterialConverter::DoWork()
			{
				
				const UMaterial* ParentMaterial = mMaterial->GetMaterial();

				if (ParentMaterial->MaterialDomain != MD_Surface)
				{
					// TODO: report warning (non-surface materials not supported, will be treated as surface)
				}
				
				mMtlData->alphaCutOff = mMaterial->GetOpacityMaskClipValue();

				ConvertAlphaMode(mMtlData->alphaMode);
				E_ShadingModel shadingModel;
				ConvertShadingModel(shadingModel);

				if (shadingModel != E_ShadingModel::None)
				{
					const FMaterialPropertyEx BaseColorProperty = shadingModel == E_ShadingModel::Unlit ? MP_EmissiveColor : MP_BaseColor;
					const FMaterialPropertyEx OpacityProperty = mMtlData->alphaMode == 2 ? MP_OpacityMask : MP_Opacity;
					// TODO: check if a property is active before trying to get it (i.e. Material->IsPropertyActive)

					if (mMtlData->alphaMode == 1)//opaque
					{
						mMtlData->baseColorFactor = TryGetConstantColor(BaseColorProperty);
						if (mMtlData->baseColorFactor == nullptr)
						{
							mMtlData->baseTexMap = TryGetSourceTexture(BaseColorProperty, DefaultColorInputMasks);
							if (mMtlData->baseTexMap == nullptr)
							{
								mMtlData->baseTexMap = new TexMappingData;
								mMtlData->baseColorFactor = new Gamefloat[4]{ 1,1,1,1 };
								if (!TryGetBakedMaterialPropertyF4(mMtlData->baseTexMap, mMtlData->baseColorFactor, BaseColorProperty, TEXT("BaseColor")))
								{									
									//UE_LOG(TEXT("Failed to export %s for material %s"), *BaseColorProperty.ToString(), *mMaterial->GetName());
								}
							}
						}
						else
						{
							mMtlData->baseColorFactor[4] = 1.0f; // make sure base color is opaque
						}
					}
					else
					{
						if (!TryGetBaseColorAndOpacity(mMtlData->baseTexMap, mMtlData->baseColorFactor, BaseColorProperty, OpacityProperty))
						{
							//UE_LOG(TEXT("Failed to export %s and %s for material %s"), *BaseColorProperty.ToString(), *OpacityProperty.ToString(), *mMaterial->GetName());
						}
					}
				}

				if (shadingModel == E_ShadingModel::Default || shadingModel == E_ShadingModel::ClearCoat)
				{
					const FMaterialPropertyEx MetallicProperty = MP_Metallic;
					const FMaterialPropertyEx RoughnessProperty = MP_Roughness;

					if (!TryGetMetallicAndRoughness(mMtlData->MetallicRoughMap, mMtlData->metallicFactor, mMtlData->RoughnessFactor, MetallicProperty, RoughnessProperty))
					{
						//UE_LOG(TEXT("Failed to export %s and %s for material %s"), *MetallicProperty.ToString(), *RoughnessProperty.ToString(), *mMaterial->GetName());
					}

					const FMaterialPropertyEx EmissiveProperty = MP_EmissiveColor;
					if (!TryGetEmissive(mMtlData, EmissiveProperty))
					{
						//UE_LOG(TEXT("Failed to export %s for material %s"), *EmissiveProperty.ToString(), *mMaterial->GetName());
					}

					const FMaterialPropertyEx NormalProperty = shadingModel == E_ShadingModel::ClearCoat ? FMaterialPropertyEx(TEXT("ClearCoatBottomNormal")) : FMaterialPropertyEx(MP_Normal);
					if (IsPropertyNonDefault(NormalProperty))
					{
						mMtlData->NormalMap = TryGetSourceTexture(NormalProperty, DefaultColorInputMasks);
						if (mMtlData->NormalMap == nullptr)
						{
							Gamefloat mScale = 1;
							if (!TryGetBakedMaterialProperty(mMtlData->NormalMap, NormalProperty, TEXT("Normal")))
							{
								//UE_LOG(TEXT("Failed to export %s for material %s"), *NormalProperty.ToString(), *mMaterial->GetName());
							}
						}
					}

					const FMaterialPropertyEx AmbientOcclusionProperty = MP_AmbientOcclusion;
					if (IsPropertyNonDefault(AmbientOcclusionProperty))
					{
						mMtlData->OcclusionMap = TryGetSourceTexture(AmbientOcclusionProperty, OcclusionInputMasks);
						if (mMtlData->OcclusionMap == nullptr)
						{
							if (!TryGetBakedMaterialProperty(mMtlData->OcclusionMap, AmbientOcclusionProperty, TEXT("Occlusion"), true))
							{
								//UE_LOG(TEXT("Failed to export %s for material %s"), *AmbientOcclusionProperty.ToString(), *mMaterial->GetName());
							}
						}
					}
				}
			}

			Gamevoid FMaterialConverter::ConvertAlphaMode(Gameint& outAlphaMode)
			{
				EBlendMode BlendMode = mMaterial->GetBlendMode();
				if (const UMaterialInstance * MaterialInstance = Cast<UMaterialInstance>(mMaterial))
				{

					EBlendMode DefaultValue = MaterialInstance->Parent->GetBlendMode();
					const EBlendMode Value = MaterialInstance->BasePropertyOverrides.bOverride_BlendMode ? MaterialInstance->BasePropertyOverrides.BlendMode.GetValue() : DefaultValue;
					bool NonDefaultOnly = false;
					if (!(NonDefaultOnly && Value == DefaultValue))
					{
						BlendMode = Value;
					}
				}
				switch (BlendMode)
				{
				case BLEND_Opaque:  outAlphaMode = 1; break;
				case BLEND_Masked:  outAlphaMode = 2; break;
				case BLEND_Translucent:
				case BLEND_Additive:
				case BLEND_Modulate:
				case BLEND_AlphaComposite:
					outAlphaMode = 3; break;
				default:			outAlphaMode = 0; break;
				}

				if (outAlphaMode == 0)
				{
					outAlphaMode = 3;
					//UE_LOG(TEXT("Unsupported blend mode (%s) in material %s, will export as %s"),
					//	*FNameUtility::GetName(BlendMode),
					//	*mMaterial->GetName(),
					//	*FNameUtility::GetName(BLEND_Translucent));
				}

				if (outAlphaMode == 3 && BlendMode != BLEND_Translucent)
				{
					//UE_LOG(TEXT("Extra blend mode (%s) in material %s UnSupported Now, will export as %s"),
					//	*FNameUtility::GetName(BlendMode),
					//	*mMaterial->GetName(),
					//	*FNameUtility::GetName(BLEND_Translucent));
				}
			}

			Gamevoid FMaterialConverter::ConvertShadingModel(E_ShadingModel& outShadingModel)
			{
				EMaterialShadingModel ShadingModel;
				{
					const FMaterialShadingModelField ShadingModels = mMaterial->GetShadingModels();
					if (mMaterial->IsShadingModelFromMaterialExpression())
					{
						const FMaterialShadingModelField Evaluation = FMaterialUtility::EvaluateShadingModelExpression(mMaterial);
						if (Evaluation.CountShadingModels() == 1)
						{
							ShadingModel = Evaluation.GetFirstShadingModel();
						}
						else if (Evaluation.CountShadingModels() > 1)
						{
							ShadingModel = FMaterialUtility::GetRichestShadingModel(Evaluation);
							//UE_LOG(TEXT("Evaluation of shading model expression in material %s is inconclusive (%s), will export as %s"),
							//	*mMaterial->GetName(),
							//	*FMaterialUtility::ShadingModelsToString(Evaluation),
							//	*FNameUtility::GetName(ShadingModel));
						}
						else
						{
							ShadingModel = FMaterialUtility::GetRichestShadingModel(ShadingModels);
							//UE_LOG(TEXT("Evaluation of shading model expression in material %s returned none, will export as %s"),
							//	*mMaterial->GetName(),
							//	*FNameUtility::GetName(ShadingModel));
						}
					}
					else
					{
						ShadingModel = ShadingModels.GetFirstShadingModel();
					}

					switch (ShadingModel)
					{
					case MSM_Unlit: outShadingModel = E_ShadingModel::Unlit; break;
					case MSM_DefaultLit: outShadingModel = E_ShadingModel::Default; break;
					case MSM_ClearCoat:	outShadingModel = E_ShadingModel::ClearCoat; break;
					default:	outShadingModel = E_ShadingModel::None; break;
					}
					if (outShadingModel == E_ShadingModel::None)
					{
						outShadingModel = E_ShadingModel::Default;
						//UE_LOG(TEXT("Shading model (%s) in material %s disabled by export options, will export as %s"),
						//	*FNameUtility::GetName(ShadingModel),
						//	*mMaterial->GetName(),
						//	*FNameUtility::GetName(MSM_DefaultLit));
						return;
					}
					Gamebool bIsExportUnlitMat = false;
					if (outShadingModel == E_ShadingModel::Unlit && !bIsExportUnlitMat)
					{
						outShadingModel = E_ShadingModel::Default;
						//UE_LOG(TEXT("Shading model (%s) in material %s disabled by export options, will export as %s"),
						//	*FNameUtility::GetName(ShadingModel),
						//	*mMaterial->GetName(),
						//	*FNameUtility::GetName(MSM_DefaultLit));
						return;
					}
					Gamebool bIsExportClearCoatMat = false;
					if (outShadingModel == E_ShadingModel::ClearCoat && !bIsExportClearCoatMat)
					{
						outShadingModel = E_ShadingModel::Default;
						//UE_LOG(TEXT("Shading model (%s) in material %s disabled by export options, will export as %s"),
						//	*FNameUtility::GetName(ShadingModel),
						//	*mMaterial->GetName(),
						//	*FNameUtility::GetName(MSM_DefaultLit));
						return;
					}
				}
			}

			Gamefloat*  FMaterialConverter::TryGetConstantColor(const FMaterialPropertyEx& Property)
			{
				FLinearColor Value;
				if (TryGetConstantColor(Value, Property))
				{
					Gamefloat* OutValue = new Gamefloat[4]{ 0 };

					Gamebool bForceLDR = true;//param,需要外部设置，这里写死

					ConvertColor(Value, OutValue, bForceLDR);

					return OutValue;
				}
				return nullptr;
			}

			Gamebool FMaterialConverter::TryGetConstantColor(FLinearColor& OutValue, const FMaterialPropertyEx& Property)
			{
				const Gamebool bUseMaterialAttributes = mMaterial->GetMaterial()->bUseMaterialAttributes;
				if (bUseMaterialAttributes)
				{
					// TODO: check if attribute property connected, i.e. Material->GetMaterial()->MaterialAttributes.IsConnected(Property)
					return false;
				}

				const FMaterialInput<FColor>* MaterialInput = FMaterialUtility::GetInputForProperty<FColor>(mMaterial, Property);
				if (MaterialInput == nullptr)
				{
					// TODO: report error
					return false;
				}

				if (MaterialInput->UseConstant)
				{
					OutValue = { MaterialInput->Constant };
					return true;
				}

				const UMaterialExpression* Expression = MaterialInput->Expression;
				if (Expression == nullptr)
				{
					OutValue = FLinearColor(FMaterialUtility::GetPropertyDefaultValue(Property));
					return true;
				}

				if (const UMaterialExpressionVectorParameter* VectorParameter = ExactCast<UMaterialExpressionVectorParameter>(Expression))
				{
					FLinearColor Value = VectorParameter->DefaultValue;

					const UMaterialInstance* MaterialInstance = Cast<UMaterialInstance>(mMaterial);
					if (MaterialInstance != nullptr)
					{
						const FHashedMaterialParameterInfo ParameterInfo(VectorParameter->GetParameterName());
						if (!MaterialInstance->GetVectorParameterValue(ParameterInfo, Value))
						{
							// TODO: how to handle this?
						}
					}

					const Gameuint MaskComponentCount = FMaterialUtility::GetMaskComponentCount(*MaterialInput);

					if (MaskComponentCount > 0)
					{
						const FLinearColor Mask = FMaterialUtility::GetMask(*MaterialInput);

						Value *= Mask;

						if (MaskComponentCount == 1)
						{
							const Gamefloat ComponentValue = Value.R + Value.G + Value.B + Value.A;
							Value = { ComponentValue, ComponentValue, ComponentValue, ComponentValue };
						}
					}

					OutValue = Value;
					return true;
				}

				if (const UMaterialExpressionScalarParameter* ScalarParameter = ExactCast<UMaterialExpressionScalarParameter>(Expression))
				{
					Gamefloat Value = ScalarParameter->DefaultValue;

					const UMaterialInstance* MaterialInstance = Cast<UMaterialInstance>(mMaterial);
					if (MaterialInstance != nullptr)
					{
						const FHashedMaterialParameterInfo ParameterInfo(ScalarParameter->GetParameterName());
						if (!MaterialInstance->GetScalarParameterValue(ParameterInfo, Value))
						{
							// TODO: how to handle this?
						}
					}

					OutValue = { Value, Value, Value, Value };
					return true;
				}

				if (const UMaterialExpressionConstant4Vector* Constant4Vector = ExactCast<UMaterialExpressionConstant4Vector>(Expression))
				{
					OutValue = Constant4Vector->Constant;
					return true;
				}

				if (const UMaterialExpressionConstant3Vector* Constant3Vector = ExactCast<UMaterialExpressionConstant3Vector>(Expression))
				{
					OutValue = Constant3Vector->Constant;
					return true;
				}

				if (const UMaterialExpressionConstant2Vector* Constant2Vector = ExactCast<UMaterialExpressionConstant2Vector>(Expression))
				{
					OutValue = { Constant2Vector->R, Constant2Vector->G, 0, 0 };
					return true;
				}

				if (const UMaterialExpressionConstant* Constant = ExactCast<UMaterialExpressionConstant>(Expression))
				{
					OutValue = { Constant->R, Constant->R, Constant->R, Constant->R };
					return true;
				}

				return false;
			}

			DataExchange::TexMappingData* FMaterialConverter::TryGetSourceTexture(const FMaterialPropertyEx& Property, const TArray<FLinearColor>& AllowedMasks)
			{
				const UTexture2D* Texture;
				Gameint TexCoord;
				Gamefloat* transFrom = new Gamefloat[5]{ 0,0,1,1,0 };
				if (TryGetSourceTexture(Texture, TexCoord, transFrom, Property, AllowedMasks))
				{
					TexMappingData* pTexData = new TexMappingData;
					FMemory::Memcpy(pTexData->transForm, transFrom, 5);
					Tex2DToTexMappingData((UTexture2D*)Texture, pTexData);
					pTexData->coordIndex = TexCoord;
					delete[] transFrom; transFrom = nullptr;
					return pTexData;
				}
				return nullptr;
			}

			Gamebool FMaterialConverter::TryGetSourceTexture(const UTexture2D*& OutTexture, Gameint& OutTexCoord, Gamefloat*& OutTransform, const FMaterialPropertyEx& Property, const TArray<FLinearColor>& AllowedMasks)
			{

				const FExpressionInput* MaterialInput = FMaterialUtility::GetInputForProperty(mMaterial, Property);
				if (MaterialInput == nullptr)
				{
					// TODO: report error
					return false;
				}

				const UMaterialExpression* Expression = MaterialInput->Expression;
				if (Expression == nullptr)
				{
					return false;
				}

				const FLinearColor InputMask = FMaterialUtility::GetMask(*MaterialInput);
				if (AllowedMasks.Num() > 0 && !AllowedMasks.Contains(InputMask))
				{
					return false;
				}

				// TODO: add support or warning for texture sampler settings that override texture asset addressing (i.e. wrap, clamp etc)?

				if (const UMaterialExpressionTextureSampleParameter2D* TextureParameter = ExactCast<UMaterialExpressionTextureSampleParameter2D>(Expression))
				{
					UTexture* ParameterValue = TextureParameter->Texture;

					const UMaterialInstance* MaterialInstance = Cast<UMaterialInstance>(mMaterial);
					if (MaterialInstance != nullptr)
					{
						const FHashedMaterialParameterInfo ParameterInfo(TextureParameter->GetParameterName());
						if (!MaterialInstance->GetTextureParameterValue(ParameterInfo, ParameterValue))
						{
							// TODO: how to handle this?
						}
					}

					OutTexture = Cast<UTexture2D>(ParameterValue);

					if (OutTexture == nullptr)
					{
						if (ParameterValue == nullptr)
						{
							// TODO: report error (no texture parameter assigned)
						}
						else
						{
							// TODO: report error (incorrect texture type)
						}
						return false;
					}

					if (!FMaterialUtility::TryGetTextureCoordinateIndex(TextureParameter, OutTexCoord, OutTransform))
					{
						// TODO: report error (failed to identify texture coordinate index)
						return false;
					}
					return true;
				}
				//UE4有 UE5 去掉了，后续看看是否可以加上
				//if (const UMaterialExpressionTextureSample* TextureSampler = ExactCast<UMaterialExpressionTextureSample>(Expression))
				//{
				//	// TODO: add support for texture object input expression
				//	OutTexture = Cast<UTexture2D>(TextureSampler->Texture);
				//	if (OutTexture == nullptr)
				//	{
				//		if (TextureSampler->Texture == nullptr)
				//		{
				//			// TODO: report error (no texture sample assigned)
				//		}
				//		else
				//		{
				//			// TODO: report error (incorrect texture type)
				//		}
				//		return false;
				//	}
				//	if (!FMaterialUtility::TryGetTextureCoordinateIndex(TextureSampler, OutTexCoord, OutTransform))
				//	{
				//		// TODO: report error (failed to identify texture coordinate index)
				//		return false;
				//	}
				//	return true;
				//}

				return false;
			}

			Gamevoid FMaterialConverter::Tex2DToTexMappingData(UTexture2D* tex2D, TexMappingData* &texMapData, \
				ChannelType orgType /*= ChannelType::RGBA*/, ChannelType desType /*= ChannelType::RGBA*/, FIntPoint texSize /*= FIntPoint::ZeroValue*/)
			{
				tex2D->AddToRoot();
				TextureCompressionSettings oldCompressionSettings = tex2D->CompressionSettings;
				TextureMipGenSettings oldMipGenSettings = tex2D->MipGenSettings;
				Gamebool oldSRGB = tex2D->SRGB;

				tex2D->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
				tex2D->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
				tex2D->SRGB = false;
				tex2D->UpdateResource();

				const FColor* colorData = static_cast<const FColor*>(tex2D->PlatformData->Mips[0].BulkData.LockReadOnly());
				if (texMapData == nullptr)
				{
					texMapData = new TexMappingData;
				}

				if (texSize == FIntPoint::ZeroValue)
				{
					texMapData->height = tex2D->GetSizeY();
					texMapData->width = tex2D->GetSizeX();
				}
				else
				{
					texMapData->height = texSize.Y;
					texMapData->width = texSize.X;
				}
				//if (texMapData->texName == L"")
				{
					FString texName;
					tex2D->GetName(texName);
					texMapData->texName = FNameUtility::FStringToChar(texName);
				}
				if (texMapData->texData == nullptr)
				{
					texMapData->texData = new unsigned char[texMapData->height*texMapData->width * 4];
					FMemory::Memset(texMapData->texData, 255, texMapData->height*texMapData->width * 4);
				}
				Gameint iDesOffset = 0;
				if (orgType != desType)
				{
					Gameint tmpDes = desType;
					while (tmpDes != 1)
					{
						tmpDes = tmpDes >> 1;
						iDesOffset++;
					}
				}
				for (Gameint y = 0; y < texMapData->height; y++)
				{
					for (Gameint x = 0; x < texMapData->width; x++)
					{
						Gameint pixelIdx = y * texMapData->width + x;
						FColor pixelColor = colorData[0];//当烘培属性为常数时，只有一个像素
						if (texSize == FIntPoint::ZeroValue || (texMapData->width == tex2D->GetSizeX() && texMapData->height == tex2D->GetSizeY()))
						{
							pixelColor = colorData[pixelIdx];
						}
						if (orgType == ChannelType::RGB && desType == ChannelType::A)
						{
							if (pixelColor == FColor::Black)
							{
								pixelColor.A = 0;
							}
							else
							{
								pixelColor.A = 255;
							}
							texMapData->texData[pixelIdx * 4 + 3] = pixelColor.A;
						}
						else if (orgType == desType)
						{
							if (desType & ChannelType::R)
								texMapData->texData[pixelIdx * 4] = pixelColor.R;
							if (desType & ChannelType::G)
								texMapData->texData[pixelIdx * 4 + 1] = pixelColor.G;
							if (desType & ChannelType::B)
								texMapData->texData[pixelIdx * 4 + 2] = pixelColor.B;
							if (desType & ChannelType::A)
								texMapData->texData[pixelIdx * 4 + 3] = pixelColor.A;
						}
						else
						{
							switch (orgType)
							{
							case ChannelType::R:
								texMapData->texData[pixelIdx * 4 + iDesOffset] = pixelColor.R;
								break;
							case ChannelType::G:
								texMapData->texData[pixelIdx * 4 + iDesOffset] = pixelColor.G;
								break;
							case ChannelType::B:
								texMapData->texData[pixelIdx * 4 + iDesOffset] = pixelColor.B;
								break;
							case ChannelType::A:
								texMapData->texData[pixelIdx * 4 + iDesOffset] = pixelColor.A;
								break;
							}
						}
					}
				}

				tex2D->PlatformData->Mips[0].BulkData.Unlock();

				tex2D->CompressionSettings = oldCompressionSettings;
				tex2D->MipGenSettings = oldMipGenSettings;
				tex2D->SRGB = oldSRGB;
				tex2D->UpdateResource();
				tex2D->RemoveFromRoot();
			}

			Gamebool FMaterialConverter::TryGetBakedMaterialPropertyF4(TexMappingData*& TexData, Gamefloat* &colorFactor, const FMaterialPropertyEx& Property, const FString& PropertyName)
			{
				Gameint coord = 0;
				FPropBakeOutput propBakeOutput = BakeMaterialProperty(Property, coord);

				if (propBakeOutput.bIsConstant)
				{
					Gamebool bStrictCompliance = true;//Param
					ConvertColor(propBakeOutput.ConstantValue, colorFactor, bStrictCompliance);
					delete TexData;
					TexData = nullptr;
					return true;
				}
				if (TexData == nullptr)
				{
					TexData = new TexMappingData;
					TexData->coordIndex = coord;
				}
				if (!BakedPixelsToTexMappingData(propBakeOutput, TexData, PropertyName))
				{
					return false;
				}
				return true;
			}

			Gamebool FMaterialConverter::TryGetBakedMaterialPropertyF(TexMappingData*& TexData, Gamefloat &colorFactor, const FMaterialPropertyEx& Property, const FString& PropertyName)
			{
				Gameint coord = 0;
				FPropBakeOutput PropertyBakeOutput = BakeMaterialProperty(Property, coord);

				if (PropertyBakeOutput.bIsConstant)
				{
					colorFactor = PropertyBakeOutput.ConstantValue.R;
					return true;
				}
				if (TexData == nullptr)
				{
					TexData = new TexMappingData;
					TexData->coordIndex = coord;
				}

				if (BakedPixelsToTexMappingData(PropertyBakeOutput, TexData, PropertyName))
				{
					colorFactor = 1; // make sure property is not zero
					return true;
				}

				return false;
			}

			Gamebool FMaterialConverter::TryGetBakedMaterialProperty(TexMappingData*& TexData, const FMaterialPropertyEx& Property, const FString& PropertyName, Gamebool bTransformToLinear)
			{
				Gameint coord = 0;
				FPropBakeOutput PropertyBakeOutput = BakeMaterialProperty(Property, coord);

				if (!PropertyBakeOutput.bIsConstant)
				{
					if (TexData == nullptr)
					{
						TexData = new TexMappingData;
						TexData->coordIndex = coord;
					}
					//if (bTransformToLinear)
					//{
					//	FMaterialUtility::TransformToLinear(PropertyBakeOutput.Pixels);
					//}

					return BakedPixelsToTexMappingData(PropertyBakeOutput, TexData, PropertyName);
				}
				else//目前用到这个方法的就法线贴图和遮挡贴图,当是常数时不解析，直接返回为true
				{
					return true;
				}
#if (ENGINE_MAJOR_VERSION > 4)
				const FVector4f MaskedConstant = FVector4f(PropertyBakeOutput.ConstantValue) * FMaterialUtility::GetPropertyMask(Property);
#else
				const FVector4 MaskedConstant = FVector4(PropertyBakeOutput.ConstantValue) * FMaterialUtility::GetPropertyMask(Property);
#endif
				if (MaskedConstant == FMaterialUtility::GetPropertyDefaultValue(Property))
				{
					// Constant value is the same as the property's default so we can set gltf to default.
					return true;
				}

				if (FMaterialUtility::IsNormalMap(Property))
				{
					// TODO: In some cases baking normal can result in constant vector that differs slight from default (i.e 0,0,1).
					// Yet often, when looking at such a material, it should be exactly default. Needs further investigation.
					// Maybe because of incorrect sRGB conversion? For now, assume a constant normal is always default.
					return true;
				}

				// TODO: let function fail and investigate why in some cases a constant baking result is returned for a property
				// that is non-constant. This happens (for example) when baking AmbientOcclusion for a translucent material,
				// even though the same material when set to opaque will properly bake AmbientOcclusion to a texture.
				// For now, create a 1x1 texture with the constant value.
				if (TexData == nullptr)
				{
					TexData = new TexMappingData;
					TexData->coordIndex = coord;
				}
				BakedPixelsToTexMappingData(PropertyBakeOutput, TexData, PropertyName);
				return true;
			}

			FPropBakeOutput FMaterialConverter::BakeMaterialProperty(const FMaterialPropertyEx& Property, Gameint& OutTexCoord, Gamebool bFillAlpha /*= true*/)
			{
				if (mMeshData == nullptr)
				{
					FIndexArray TexCoords;
					FMaterialUtility::GetAllTextureCoordinateIndices(mMaterial, Property, TexCoords);

					if (TexCoords.Num() > 0)
					{
						OutTexCoord = TexCoords[0];

						if (TexCoords.Num() > 1)
						{
							//UE_LOG(TEXT("%s for material %s uses multiple texture coordinates (%s), baked texture will be sampled using only the first (%d)"),
							//	*Property.ToString(),
							//	*mMaterial->GetName(),
							//	*FString::JoinBy(TexCoords, TEXT(", "), FString::FromInt),
							//	OutTexCoord);
						}
					}
					else
					{
						OutTexCoord = 0;
					}
				}
				else
				{
					OutTexCoord = mMeshData->BakeUsingTexCoord;
					MeshDataBakedProperties.Add(Property);
				}
				const FPropBakeOutput propBakeOutput = FMaterialUtility::BakeMaterialProperty(TexSize, Property, mMaterial, OutTexCoord,
					mMeshData, SectionIndices, bFillAlpha);

				return propBakeOutput;
			}

			Gamevoid FMaterialConverter::ConvertColor(const FLinearColor& Value, Gamefloat*& OutValue, Gamebool bForceLDR)
			{
				if (bForceLDR)
				{
					OutValue[0] = FMath::Clamp(Value.R, 0.0f, 1.0f);
					OutValue[1] = FMath::Clamp(Value.G, 0.0f, 1.0f);
					OutValue[2] = FMath::Clamp(Value.B, 0.0f, 1.0f);
					OutValue[3] = FMath::Clamp(Value.A, 0.0f, 1.0f);
				}
				else
				{
					OutValue[0] = FMath::Max(Value.R, 0.0f);
					OutValue[1] = FMath::Max(Value.G, 0.0f);
					OutValue[2] = FMath::Max(Value.B, 0.0f);
					OutValue[3] = FMath::Max(Value.A, 0.0f);
				}
			}

			Gamebool FMaterialConverter::BakedPixelsToTexMappingData(FPropBakeOutput& bakeData, TexMappingData* &texMapData, const FString& PropertyName)
			{
				if (bakeData.Pixels.Num() != bakeData.Size.X * bakeData.Size.Y)
				{
					return false;
				}
				if (texMapData == nullptr)
				{
					texMapData = new TexMappingData;
				}
				FString texName = GetBakedTexName(PropertyName);
				texMapData->texName = FNameUtility::FStringToChar(texName);
				texMapData->width = bakeData.Size.X;
				texMapData->height = bakeData.Size.Y;
				texMapData->texData = new unsigned char[bakeData.Size.X * bakeData.Size.Y * 4];
				for (Gameint y = 0; y < bakeData.Size.Y; y++)
				{
					for (Gameint x = 0; x < bakeData.Size.X; x++)
					{
						Gameint pixelIdx = y * bakeData.Size.X + x;
						FColor pixelColor = bakeData.Pixels[pixelIdx];
						texMapData->texData[pixelIdx * 4] = pixelColor.R;
						texMapData->texData[pixelIdx * 4 + 1] = pixelColor.G;
						texMapData->texData[pixelIdx * 4 + 2] = pixelColor.B;
						texMapData->texData[pixelIdx * 4 + 3] = pixelColor.A;
					}
				}
				return true;
			}

			FString FMaterialConverter::GetMaterialName() const
			{
				FString MtlName = mMaterial->GetName();

				if (mMeshData != nullptr)
				{
					MtlName += TEXT("_") + mMeshData->Name;
				}

				return MtlName;
			}

			FString FMaterialConverter::GetBakedTexName(const FString& PropertyName) const
			{
				return GetMaterialName() + TEXT("_") + PropertyName;
			}

			Gamebool FMaterialConverter::TryGetConstantScalar(Gamefloat& OutValue, const FMaterialPropertyEx& Property) const
			{
				const Gamebool bUseMaterialAttributes = mMaterial->GetMaterial()->bUseMaterialAttributes;
				if (bUseMaterialAttributes)
				{
					// TODO: check if attribute property connected, i.e. Material->GetMaterial()->MaterialAttributes.IsConnected(Property)
					return false;
				}

				const FMaterialInput<Gamefloat>* MaterialInput = FMaterialUtility::GetInputForProperty<Gamefloat>(mMaterial, Property);
				if (MaterialInput == nullptr)
				{
					// TODO: report error
					return false;
				}

				if (MaterialInput->UseConstant)
				{
					OutValue = MaterialInput->Constant;
					return true;
				}

				const UMaterialExpression* Expression = MaterialInput->Expression;
				if (Expression == nullptr)
				{
					OutValue = FMaterialUtility::GetPropertyDefaultValue(Property).X;
					return true;
				}

				if (const UMaterialExpressionVectorParameter* VectorParameter = ExactCast<UMaterialExpressionVectorParameter>(Expression))
				{
					FLinearColor Value = VectorParameter->DefaultValue;

					const UMaterialInstance* MaterialInstance = Cast<UMaterialInstance>(mMaterial);
					if (MaterialInstance != nullptr)
					{
						const FHashedMaterialParameterInfo ParameterInfo(VectorParameter->GetParameterName());
						if (!MaterialInstance->GetVectorParameterValue(ParameterInfo, Value))
						{
							// TODO: how to handle this?
						}
					}

					const Gameuint MaskComponentCount = FMaterialUtility::GetMaskComponentCount(*MaterialInput);

					if (MaskComponentCount > 0)
					{
						const FLinearColor Mask = FMaterialUtility::GetMask(*MaterialInput);
						Value *= Mask;
					}

					// TODO: is this a correct assumption, that the max component should be used as value?
					OutValue = Value.GetMax();
					return true;
				}

				if (const UMaterialExpressionScalarParameter* ScalarParameter = ExactCast<UMaterialExpressionScalarParameter>(Expression))
				{
					Gamefloat Value = ScalarParameter->DefaultValue;

					const UMaterialInstance* MaterialInstance = Cast<UMaterialInstance>(mMaterial);
					if (MaterialInstance != nullptr)
					{
						const FHashedMaterialParameterInfo ParameterInfo(ScalarParameter->GetParameterName());
						if (!MaterialInstance->GetScalarParameterValue(ParameterInfo, Value))
						{
							// TODO: how to handle this?
						}
					}

					OutValue = Value;
					return true;
				}

				if (const UMaterialExpressionConstant4Vector* Constant4Vector = ExactCast<UMaterialExpressionConstant4Vector>(Expression))
				{
					OutValue = Constant4Vector->Constant.R;
					return true;
				}

				if (const UMaterialExpressionConstant3Vector* Constant3Vector = ExactCast<UMaterialExpressionConstant3Vector>(Expression))
				{
					OutValue = Constant3Vector->Constant.R;
					return true;
				}

				if (const UMaterialExpressionConstant2Vector* Constant2Vector = ExactCast<UMaterialExpressionConstant2Vector>(Expression))
				{
					OutValue = Constant2Vector->R;
					return true;
				}

				if (const UMaterialExpressionConstant* Constant = ExactCast<UMaterialExpressionConstant>(Expression))
				{
					OutValue = Constant->R;
					return true;
				}

				return false;
			}

			Gamebool FMaterialConverter::TryGetBaseColorAndOpacity(TexMappingData*& baseTexData, Gamefloat*& baseColorFactor, const FMaterialPropertyEx& BaseColorProperty, const FMaterialPropertyEx& OpacityProperty)
			{
				baseColorFactor = TryGetConstantColor(BaseColorProperty);
				const Gamebool bIsBaseColorConstant = baseColorFactor != nullptr;
				if (baseColorFactor == nullptr)
				{
					baseColorFactor = new Gamefloat[4]{ 1.f,1.f,1.f,1.f };
				}
				const Gamebool bIsOpacityConstant = TryGetConstantScalar(baseColorFactor[3], OpacityProperty);

				if (bIsBaseColorConstant && bIsOpacityConstant)
				{
					return true;
				}
				else
				{
					baseColorFactor[3] = 1.f;
				}

				const UTexture2D* BaseColorTexture;
				const UTexture2D* OpacityTexture;
				Gameint BaseColorTexCoord;
				Gameint OpacityTexCoord;
				Gamefloat* BaseColorTransform = new Gamefloat[5]{ 0,0,1,1,0 };
				Gamefloat* OpacityTransform = new Gamefloat[5]{ 0,0,1,1,0 };

				const Gamebool bHasBaseColorSourceTexture = TryGetSourceTexture(BaseColorTexture, BaseColorTexCoord, BaseColorTransform, BaseColorProperty, BaseColorInputMasks);
				const Gamebool bHasOpacitySourceTexture = TryGetSourceTexture(OpacityTexture, OpacityTexCoord, OpacityTransform, OpacityProperty, OpacityInputMasks);

				// Detect the "happy path" where both inputs share the same texture and are correctly masked.
				if (bHasBaseColorSourceTexture && bHasOpacitySourceTexture && BaseColorTexture == OpacityTexture && BaseColorTexCoord == OpacityTexCoord &&
					BaseColorTransform[0] == OpacityTransform[0] && BaseColorTransform[1] == OpacityTransform[1] && BaseColorTransform[2] == OpacityTransform[2]
					&& BaseColorTransform[3] == OpacityTransform[3] && BaseColorTransform[4] == OpacityTransform[4])
				{
					baseTexData->coordIndex = BaseColorTexCoord;
					baseTexData->transForm = BaseColorTransform;
					Tex2DToTexMappingData((UTexture2D*)BaseColorTexture, baseTexData);
					delete[] OpacityTransform; 
					OpacityTransform = nullptr;
					return true;
				}

				//开始烘培
				//FIntPoint TextureSize = Builder.GetBakeSizeForMaterialProperty(Material, BaseColorProperty);
				//const TextureAddress TextureAddress = Builder.GetBakeTilingForMaterialProperty(Material, BaseColorProperty);
				//const EGLTFJsonTextureWrap TextureWrapS = FGLTFConverterUtility::ConvertWrap(TextureAddress);
				//const EGLTFJsonTextureWrap TextureWrapT = FGLTFConverterUtility::ConvertWrap(TextureAddress);
				//const TextureFilter TextureFilter = Builder.GetBakeFilterForMaterialProperty(Material, BaseColorProperty);
				//const EGLTFJsonTextureFilter TextureMinFilter = FGLTFConverterUtility::ConvertMinFilter(TextureFilter);
				//const EGLTFJsonTextureFilter TextureMagFilter = FGLTFConverterUtility::ConvertMagFilter(TextureFilter);

				const FPropBakeOutput BaseColorBakeOutput = BakeMaterialProperty(BaseColorProperty, BaseColorTexCoord);
				const FPropBakeOutput OpacityBakeOutput = BakeMaterialProperty(OpacityProperty, OpacityTexCoord, true);
				const Gamefloat BaseColorScale = BaseColorProperty == MP_EmissiveColor ? BaseColorBakeOutput.EmissiveScale : 1;

				Gamebool bStrictCompliance = true;//param
				// Detect when both baked properties are constants, which means we can avoid exporting a texture
				if (BaseColorBakeOutput.bIsConstant && OpacityBakeOutput.bIsConstant)
				{
					FLinearColor BaseColorFactor(BaseColorBakeOutput.ConstantValue * BaseColorScale);
					BaseColorFactor.A = OpacityBakeOutput.ConstantValue.A;
					ConvertColor(BaseColorFactor, baseColorFactor, bStrictCompliance);
					delete[] OpacityTransform;
					OpacityTransform = nullptr;
					delete[] BaseColorTransform;
					BaseColorTransform = nullptr;
					return true;
				}

				Gameint TexCoord;
				if (BaseColorBakeOutput.bIsConstant)
				{
					TexCoord = OpacityTexCoord;
				}
				else if (OpacityBakeOutput.bIsConstant)
				{
					TexCoord = BaseColorTexCoord;
				}
				else if (BaseColorTexCoord == OpacityTexCoord)
				{
					TexCoord = BaseColorTexCoord;
				}
				else
				{
					delete[] OpacityTransform;
					OpacityTransform = nullptr;
					delete[] BaseColorTransform;
					BaseColorTransform = nullptr;
					// TODO: report error (texture coordinate conflict)
					return false;
				}

				FIntPoint TextureSize = BaseColorBakeOutput.Size.ComponentMax(OpacityBakeOutput.Size);
				BaseColorTexture = FMaterialUtility::CreateTransientTexture(BaseColorBakeOutput);
				OpacityTexture = FMaterialUtility::CreateTransientTexture(OpacityBakeOutput);

				Tex2DToTexMappingData((UTexture2D*)BaseColorTexture, baseTexData, DataExchange::RGBA, DataExchange::RGBA, TextureSize);
				Tex2DToTexMappingData((UTexture2D*)OpacityTexture, baseTexData, DataExchange::A, DataExchange::A, TextureSize);
				baseTexData->coordIndex = TexCoord;
				FString texName = GetBakedTexName(_TEXT("Diffuse_Opacity"));
				baseTexData->texName = FNameUtility::FStringToChar(texName);
				ConvertColor({ BaseColorScale, BaseColorScale, BaseColorScale }, baseColorFactor, bStrictCompliance);
				delete[] OpacityTransform;
				OpacityTransform = nullptr;
				delete[] BaseColorTransform;
				BaseColorTransform = nullptr;
				return true;
			}

			Gamebool FMaterialConverter::TryGetMetallicAndRoughness(TexMappingData*& MetRouTexData, Gamefloat& metFactor, Gamefloat& rouFactor, const FMaterialPropertyEx& MetallicProperty, const FMaterialPropertyEx& RoughnessProperty)
			{
				const Gamebool bIsMetallicConstant = TryGetConstantScalar(metFactor, MetallicProperty);
				const Gamebool bIsRoughnessConstant = TryGetConstantScalar(rouFactor, RoughnessProperty);

				if (bIsMetallicConstant && bIsRoughnessConstant)
				{
					return true;
				}

				// NOTE: since we always bake the properties (for now) when at least one property is non-const, we need
				// to reset the constant factors to their defaults. Otherwise the baked value of a constant property
				// would be scaled with the factor, i.e a double scaling.
				metFactor = 1.0f;
				rouFactor = 1.0f;

				const UTexture2D* MetallicTexture;
				const UTexture2D* RoughnessTexture;
				Gameint MetallicTexCoord;
				Gameint RoughnessTexCoord;
				Gamefloat* MetallicTransform = new Gamefloat[5]{ 0,0,1,1,0 };
				Gamefloat* RoughnessTransform = new Gamefloat[5]{ 0,0,1,1,0 };

				const Gamebool bHasMetallicSourceTexture = TryGetSourceTexture(MetallicTexture, MetallicTexCoord, MetallicTransform, MetallicProperty, MetallicInputMasks);
				const Gamebool bHasRoughnessSourceTexture = TryGetSourceTexture(RoughnessTexture, RoughnessTexCoord, RoughnessTransform, RoughnessProperty, RoughnessInputMasks);

				// Detect the "happy path" where both inputs share the same texture and are correctly masked.
				if (bHasMetallicSourceTexture && bHasRoughnessSourceTexture && MetallicTexture == RoughnessTexture && MetallicTexCoord == RoughnessTexCoord &&
					MetallicTransform[0] == RoughnessTransform[0] && MetallicTransform[1] == RoughnessTransform[1] && MetallicTransform[2] == RoughnessTransform[2]
					&& MetallicTransform[3] == RoughnessTransform[3] && MetallicTransform[4] == RoughnessTransform[4])
				{
					MetRouTexData->coordIndex = MetallicTexCoord;
					MetRouTexData->transForm = MetallicTransform;
					Tex2DToTexMappingData((UTexture2D*)MetallicTexture, MetRouTexData, DataExchange::G, DataExchange::G);
					Tex2DToTexMappingData((UTexture2D*)MetallicTexture, MetRouTexData, DataExchange::B, DataExchange::R);
					delete[] RoughnessTransform; 
					RoughnessTransform = nullptr;
					return true;
				}

				//// TODO: add support for calculating the ideal resolution to use for baking based on connected (texture) nodes
				//FIntPoint TextureSize = Builder.GetBakeSizeForMaterialProperty(Material, MetallicProperty);
				//const TextureAddress TextureAddress = Builder.GetBakeTilingForMaterialProperty(Material, MetallicProperty);
				//const EGLTFJsonTextureWrap TextureWrapS = FGLTFConverterUtility::ConvertWrap(TextureAddress);
				//const EGLTFJsonTextureWrap TextureWrapT = FGLTFConverterUtility::ConvertWrap(TextureAddress);
				//const TextureFilter TextureFilter = Builder.GetBakeFilterForMaterialProperty(Material, MetallicProperty);
				//const EGLTFJsonTextureFilter TextureMinFilter = FGLTFConverterUtility::ConvertMinFilter(TextureFilter);
				//const EGLTFJsonTextureFilter TextureMagFilter = FGLTFConverterUtility::ConvertMagFilter(TextureFilter);

				FPropBakeOutput MetallicBakeOutput = BakeMaterialProperty(MetallicProperty, MetallicTexCoord/*, TextureSize*/);
				FPropBakeOutput RoughnessBakeOutput = BakeMaterialProperty(RoughnessProperty, RoughnessTexCoord/*, TextureSize*/);

				// Detect when both baked properties are constants, which means we can use factors and avoid exporting a texture
				if (MetallicBakeOutput.bIsConstant && RoughnessBakeOutput.bIsConstant)
				{
					metFactor = MetallicBakeOutput.ConstantValue.R;
					metFactor = RoughnessBakeOutput.ConstantValue.R;
					delete[] RoughnessTransform;
					RoughnessTransform = nullptr;
					delete[] MetallicTransform;
					MetallicTransform = nullptr;
					return true;
				}

				Gameint TexCoord;
				if (MetallicBakeOutput.bIsConstant)
				{
					TexCoord = RoughnessTexCoord;
				}
				else if (MetallicBakeOutput.bIsConstant)
				{
					TexCoord = MetallicTexCoord;
				}
				else if (MetallicTexCoord == RoughnessTexCoord)
				{
					TexCoord = MetallicTexCoord;
				}
				else
				{
					// TODO: report error (texture coordinate conflict)
					delete[] RoughnessTransform;
					RoughnessTransform = nullptr;
					delete[] MetallicTransform;
					MetallicTransform = nullptr;
					return false;
				}

				FIntPoint TextureSize = RoughnessBakeOutput.Size.ComponentMax(MetallicBakeOutput.Size);
				MetallicTexture = FMaterialUtility::CreateTransientTexture(MetallicBakeOutput);
				RoughnessTexture = FMaterialUtility::CreateTransientTexture(RoughnessBakeOutput);

				Tex2DToTexMappingData((UTexture2D*)RoughnessTexture, MetRouTexData, DataExchange::G, DataExchange::G, TextureSize);
				Tex2DToTexMappingData((UTexture2D*)MetallicTexture, MetRouTexData, DataExchange::B, DataExchange::R, TextureSize);
				FString texName = GetBakedTexName(_TEXT("MetallicRoughness"));
				MetRouTexData->texName = FNameUtility::FStringToChar(texName);
				MetRouTexData->coordIndex = TexCoord;
				delete[] RoughnessTransform;
				RoughnessTransform = nullptr;
				delete[] MetallicTransform;
				MetallicTransform = nullptr;
				return true;
			}

			Gamebool FMaterialConverter::TryGetEmissive(MaterialData*& mtlData, const FMaterialPropertyEx& EmissiveProperty)
			{
				mtlData->EmissionFactor = TryGetConstantColor(MP_EmissiveColor);
				if (mtlData->EmissionFactor != nullptr)
				{
					return true;
				}
				mtlData->EmissionMap = TryGetSourceTexture(EmissiveProperty, DefaultColorInputMasks);
				if (mtlData->EmissionMap != nullptr)
				{
					mtlData->EmissionFactor = new Gamefloat[4]{ 1.f,1.f,1.f,1.f };
					return true;
				}
				Gameint TexCoord = 0;
				const FPropBakeOutput PropertyBakeOutput = BakeMaterialProperty(EmissiveProperty, TexCoord);
				const Gamefloat EmissiveScale = PropertyBakeOutput.EmissiveScale;

				if (PropertyBakeOutput.bIsConstant)
				{
					const FLinearColor EmissiveColor = PropertyBakeOutput.ConstantValue;
					mtlData->EmissionFactor = new Gamefloat[4]{ 0,0,0,1 };
					Gamebool bStrictCompliance = true;
					ConvertColor(EmissiveColor * EmissiveScale, mtlData->EmissionFactor, bStrictCompliance);
				}
				else
				{
					if (BakedPixelsToTexMappingData((FPropBakeOutput&)PropertyBakeOutput, mtlData->EmissionMap, TEXT("Emissive")))
					{
						return false;
					}
					mtlData->EmissionFactor[0] = mtlData->EmissionFactor[1] = mtlData->EmissionFactor[2] = EmissiveScale;
				}

				return true;
			}

			Gamebool FMaterialConverter::IsPropertyNonDefault(const FMaterialPropertyEx& Property) const
			{
				const Gamebool bUseMaterialAttributes = mMaterial->GetMaterial()->bUseMaterialAttributes;
				if (bUseMaterialAttributes)
				{
					// TODO: check if attribute property connected, i.e. Material->GetMaterial()->MaterialAttributes.IsConnected(Property)
					return true;
				}

				const FExpressionInput* MaterialInput = FMaterialUtility::GetInputForProperty(mMaterial, Property);
				if (MaterialInput == nullptr)
				{
					// TODO: report error
					return false;
				}

				const UMaterialExpression* Expression = MaterialInput->Expression;
				if (Expression == nullptr)
				{
					return false;
				}

				return true;
			}


		}
	}
}
PRAGMA_ENABLE_OPTIMIZATION
#endif