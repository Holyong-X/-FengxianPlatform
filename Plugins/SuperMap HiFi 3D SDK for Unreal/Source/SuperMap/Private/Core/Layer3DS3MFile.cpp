#include "Core/Layer3DS3MFile.h"
#include "Core/ROCache.h"
#include "Core/RealspaceDLL.h"
#include "Base3D/CommonDefine.h"
#include "Core/Georeference.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Component/SuperMap_MeshComponentInterface.h"
#include "Render/TextureRenderer.h"
#include "Component/SuperMap_MeshComponent.h"
#include "Data/Vector4d.h"
#include "Graphics3D/GameRenderTexture.h"
#include "Graphics3D/GameRenderTextureManager.h"
#include "Data/AssetLibrary.h"
#include "ControlUE/CameraControl.h"
#include "Algorithm3D/MathEngine.h"
#include "Graphics3D/GameMaterialManager.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Render;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::ControlUE;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Layer3DS3MFile::Layer3DS3MFile()
			{
				m_pSelection = new Selection3D(this);
				m_pHypsometricSetting = nullptr;
				m_dConstantPolygonOffset = 0;
				m_bUpdateS3MEffectShader = false;
				m_bUpdataHypsometricSetting = false;
				m_nModifyRegionsCount = 0;
				m_eModifyRegionMode = ModifyRegionMode::Modify_None;
				m_pObjectsColorDictionary = nullptr;
			}

			Layer3DS3MFile::Layer3DS3MFile(FName strLayerName, Layer3DType eLayerType) :Layer3D(strLayerName, eLayerType)
			{
				m_pSelection = new Selection3D(this);
				m_pHypsometricSetting = nullptr;
				m_dConstantPolygonOffset = 0;
				m_bUpdataHypsometricSetting = false;
				m_bUpdateS3MEffectShader = false;
				m_nModifyRegionsCount = 0;
				m_eModifyRegionMode = ModifyRegionMode::Modify_None;
				m_pObjectsColorDictionary = nullptr;
			}

			Layer3DS3MFile::Layer3DS3MFile(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType) :Layer3D(pUGLayer3D,strLayerName, eLayerType)
			{
				m_pSelection = new Selection3D(this);
				m_pHypsometricSetting = nullptr;
				m_dConstantPolygonOffset = 0;
				m_bUpdataHypsometricSetting = false;
				m_bUpdateS3MEffectShader = false;
				m_nModifyRegionsCount = 0;
				m_eModifyRegionMode = ModifyRegionMode::Modify_None;
				m_pObjectsColorDictionary = nullptr;
			}

			Layer3DS3MFile::~Layer3DS3MFile()
			{
				if (m_pHypsometricSetting != nullptr)
				{
					m_pHypsometricSetting->SetDisplayMode(NONE);
					UpdataHypsometricSetting();
					delete m_pHypsometricSetting;
					m_pHypsometricSetting = nullptr;
					m_LayerDeleteEventInfos.m_LayerDeleteEvent(m_LayerDeleteEventInfos.m_pActor);
				}
				if (m_pObjectsColorDictionary != nullptr)
				{
					delete m_pObjectsColorDictionary;
					m_pObjectsColorDictionary = nullptr;
				}
				m_bUpdataHypsometricSetting = false;
				m_arrPtrMaterialInterface.Empty();
				m_LayerDeleteEventInfos.m_pActor = nullptr;
			}

			std::vector<FString> Layer3DS3MFile::GetFieldInfos()
			{
				int32 nCount = 0;
				ObjectFieldInfo*** pObjectFieldInfos = nullptr;

				std::vector<FString> vecFiledInfos;
				std::vector<FString> vecCaptions;
				if (_GetFieldInfosObject != nullptr)
				{
					Gameint nIDCount = m_pSelection->GetCount();
					if (nIDCount == 0)
					{
						return vecFiledInfos;
					}

					Gameint nID = m_pSelection->GetID(0);

					_GetFieldInfosObject(nID, m_nLayerID, pObjectFieldInfos, nCount);
					if (pObjectFieldInfos != nullptr && nCount > 0)
					{
						for (int32 i = 0; i < nCount; i++)
						{
							ObjectFieldInfo* pObjectField = (*pObjectFieldInfos)[i];
							FString strFieldInfo = UTF8_TO_TCHAR(pObjectField->m_strFieldInfo);
							FString strCaption = UTF8_TO_TCHAR(pObjectField->m_strCaption);
							vecFiledInfos.push_back(strFieldInfo);
							vecCaptions.push_back(strCaption);
						}

						_FreeArrayObjectFieldNode(pObjectFieldInfos, nCount);
					}
				}
				if (vecFiledInfos.size() > 0)
				{
					m_AttributeFields.SetFieldInfos(vecFiledInfos);
				}
				if (vecCaptions.size() > 0)
				{
					m_AttributeFields.SetCaptions(vecCaptions);
				}

				return vecFiledInfos;
			}

			std::vector<FString> Layer3DS3MFile::GetFieldInfos(Gameint nID)
			{
				int32 nCount = 0;
				ObjectFieldInfo*** pObjectFieldInfos = nullptr;

				std::vector<FString> vecFiledInfos;
				std::vector<FString> vecCaptions;
				if (_GetFieldInfosObject != nullptr)
				{
					_GetFieldInfosObject(nID, m_nLayerID, pObjectFieldInfos, nCount);
					if (pObjectFieldInfos != nullptr && nCount > 0)
					{
						for (int32 i = 0; i < nCount; i++)
						{
							ObjectFieldInfo* pObjectField = (*pObjectFieldInfos)[i];
							FString strFieldInfo = UTF8_TO_TCHAR(pObjectField->m_strFieldInfo);
							FString strCaption = UTF8_TO_TCHAR(pObjectField->m_strCaption);
							vecFiledInfos.push_back(strFieldInfo);
							vecCaptions.push_back(strCaption);
						}

						_FreeArrayObjectFieldNode(pObjectFieldInfos, nCount);
					}
				}
				if (vecFiledInfos.size() > 0)
				{
					m_AttributeFields.SetFieldInfos(vecFiledInfos);
				}
				if (vecCaptions.size() > 0)
				{
					m_AttributeFields.SetCaptions(vecCaptions);
				}

				return vecFiledInfos;
			}

			std::vector<FString> Layer3DS3MFile::GetAllFieldValues(Gameint nID)
			{
				if (nID == -1)
				{
					return std::vector<FString>();
				}

				if (nID == m_AttributeFields.GetID() && m_AttributeFields.FieldValueCount() > 0)
				{
					return m_AttributeFields.GetFieldValues();
				}

				m_AttributeFields.SetID(nID);

				int32 nCount = 0;
				ObjectFieldInfo*** pObjectFieldValues = nullptr;
				std::vector<FString> vecFiledValues;
				if (_GetAllFieldValueObject != nullptr)
				{
					_GetAllFieldValueObject(nID, m_nLayerID, pObjectFieldValues, nCount);
					if (pObjectFieldValues != nullptr && nCount > 0)
					{

						for (int32 i = 0;i < nCount; i++)
						{
							ObjectFieldInfo* pObjectField = (*pObjectFieldValues)[i];
							FString strFieldValue = UTF8_TO_TCHAR(pObjectField->m_strFieldInfo);

							vecFiledValues.push_back(strFieldValue);
						}

						_FreeArrayObjectFieldNode(pObjectFieldValues, nCount);
					}
				}
				if (vecFiledValues.size() > 0)
				{
					m_AttributeFields.SetFieldValues(vecFiledValues);
				}
				return vecFiledValues;
			}

			AttributeFields Layer3DS3MFile::GetAttributeFields()
			{
				return m_AttributeFields;
			}

			void Layer3DS3MFile::SetLODRangeScale(int nLayerID, float values)
			{
				if (_SetLODRangeScale != nullptr)
				{
					_SetLODRangeScale(nLayerID, values);
				}
			}

			float Layer3DS3MFile::GetLODRangeScale(int nLayerID)
			{
				if (_GetLODRangeScale != nullptr)
				{
					return _GetLODRangeScale(nLayerID);
				}
				return -1;
			}

			void Layer3DS3MFile::AddFlattenRegion(GeoRegion3D* pGeoRegion3D, FString strTag)
			{
				if (pGeoRegion3D != nullptr)
				{
					const TCHAR* c = *strTag;
					ANSICHAR* cc = TCHAR_TO_UTF8(c);

					_AddFlattenRegion(m_nLayerID, pGeoRegion3D->GetHandler(), cc);
				}
				m_eModifyRegionMode = ModifyRegionMode::Flatten;
				m_bUpdateS3MEffectShader = true;
			}

			void Layer3DS3MFile::SetModifyRegions(TArray<GeoRegion3D*> pGeoRegion3Ds, ModifyRegionMode type)
			{
				m_eModifyRegionMode = type;
				Gameint nCount = pGeoRegion3Ds.Num();
				m_nModifyRegionsCount = nCount;
				void** pGeometrys = new void*[nCount];
				for (int i = 0; i < nCount; i++)
				{
					pGeometrys[i] = pGeoRegion3Ds[i]->GetHandler();
				}
				_SetModifyRegions(m_pUGLayer3D, pGeometrys, nCount, type);
				delete[] pGeometrys;
				_SetExcavation(m_pUGLayer3D, true);
				m_bUpdateS3MEffectShader = true;
			}

			void Layer3DS3MFile::ClearModifyRegions()
			{
				_ClearModifyRegions(m_pUGLayer3D);
				_SetExcavation(m_pUGLayer3D, true);
				m_S3MEffectParam.m_nRegionCount = 0;
				m_S3MEffectParam.m_pS3MEffectTexture = nullptr;
				UpdateMaterialS3MEffectParam(0, true);
				m_eModifyRegionMode = ModifyRegionMode::Modify_None;
			}

			void Layer3DS3MFile::SetObjectsVisible(TArray<Gameint> ids, Gamebool bVisible)
			{
				Gameint* pIDs = ids.GetData();
				Gameint nCount = ids.Num();

				_SetObjectsVisible(m_pUGLayer3D, pIDs, nCount, bVisible);
			}

			void Layer3DS3MFile::SetObjectsMaterial(TArray<Gameint> ids, FString strMaterialName)
			{
				Gameint* pIDs = ids.GetData();
				Gameint nCount = ids.Num();
				
				_SetObjectsMaterial(m_pUGLayer3D, pIDs, nCount, TCHAR_TO_UTF8(*strMaterialName));
			}

			void Layer3DS3MFile::Render(UWorld* pWorld)
			{
				Layer3D::Render(pWorld);

				// 获取压平开挖的参数
				if (m_bUpdateS3MEffectShader)
				{
					int32 nRegionCount = 0;
					if (m_S3MEffectParam.m_eModifyRegionMode == ModifyRegionMode::Flatten)
					{
						nRegionCount = _GetFlattenRegionCount(m_nLayerID);
					}
					else if (m_S3MEffectParam.m_eModifyRegionMode == ModifyRegionMode::ClipInside ||
						m_S3MEffectParam.m_eModifyRegionMode == ModifyRegionMode::ClipOutside)
					{
						nRegionCount = m_nModifyRegionsCount;
					}
					CalS3MEffectParam(nRegionCount, m_eModifyRegionMode);
					if (nRegionCount > 0 && m_S3MEffectParam.m_pS3MEffectTexture != nullptr)
					{
						UpdateMaterialS3MEffectParam(nRegionCount);
					}
				}

				if (m_bUpdataHypsometricSetting)
				{
					UpdataHypsometricSetting();
				}

				// 更新裁剪的参数
				if (m_bHasClip && m_bUpdateClip)
				{
					GetClipParamFromUGC();
					UpdateClipShaderParam();
				}

				m_bUpdateClip = false;
			}

			void Layer3DS3MFile::CalS3MEffectParam(int32 nRegionCount, ModifyRegionMode type)
			{
				int32 nFlattenMode = 0;
				double dMinX = 0.0;
				double dMaxX = 0.0;
				double dMinY = 0.0;
				double dMaxY = 0.0;
				void* pS3MEffectTextureHandle = nullptr;
				
				double* pUGS3MEffectWorldMatrix = new double[16];

				if (type == ModifyRegionMode::Flatten)
				{
					_GetFlattenShaderParamter(m_nLayerID, nFlattenMode, dMinX, dMaxX, dMinY, dMaxY,
						pUGS3MEffectWorldMatrix, pS3MEffectTextureHandle);
				}
				else if (type == ModifyRegionMode::ClipInside || type == ModifyRegionMode::ClipOutside)
				{
					_GetExcavationShaderParamter(m_pUGLayer3D, dMinX, dMaxX, dMinY, dMaxY,
						pUGS3MEffectWorldMatrix, pS3MEffectTextureHandle);
				}
				Matrix4d flattenWorldMatrix(pUGS3MEffectWorldMatrix);
				

				flattenWorldMatrix[3][0] *= M_TO_CM;
				flattenWorldMatrix[3][1] *= M_TO_CM;
				flattenWorldMatrix[3][2] *= M_TO_CM;

				flattenWorldMatrix =  flattenWorldMatrix * Georeference::GetECEFtoGeoreference();
				
				if ((Gameuint)CameraControl::m_eSceneType == (Gameuint)Globe || (Gameuint)CameraControl::m_eSceneType == (Gameuint)Ellipsoid_WGS84)
				{
					flattenWorldMatrix[3][0] -= MathEngine::m_vWorldOffset.X;
					flattenWorldMatrix[3][1] -= MathEngine::m_vWorldOffset.Y;
					flattenWorldMatrix[3][2] -= MathEngine::m_vWorldOffset.Z;
				}

				flattenWorldMatrix[3][0] -= FVector(Core::ROCacheManager::m_vecWorldOrigin).X;
				flattenWorldMatrix[3][1] -= FVector(Core::ROCacheManager::m_vecWorldOrigin).Y;
				flattenWorldMatrix[3][2] -= FVector(Core::ROCacheManager::m_vecWorldOrigin).Z;

				m_S3MEffectParam.m_eModifyRegionMode = type;
				m_S3MEffectParam.m_v4S3MEffectRectPos.X = (float)dMinX;
				m_S3MEffectParam.m_v4S3MEffectRectPos.Y = (float)dMaxX;
				m_S3MEffectParam.m_v4S3MEffectRectPos.Z = (float)dMinY;
				m_S3MEffectParam.m_v4S3MEffectRectPos.W = (float)dMaxY;

				if (pS3MEffectTextureHandle != nullptr)
				{
					// 获取纹理
					GameRenderTexture* pGameRenderTexture = (GameRenderTexture*)pS3MEffectTextureHandle;
					if (pGameRenderTexture != nullptr)
					{
						UTextureRenderTarget2D* pTextureRenderTarget2D = pGameRenderTexture->GetFlattenRenderTarget();
						m_S3MEffectParam.m_pS3MEffectTexture = pTextureRenderTarget2D;
					}
					else
					{
						m_S3MEffectParam.m_pS3MEffectTexture = nullptr;
					}
				}
				else
				{
					m_S3MEffectParam.m_pS3MEffectTexture = nullptr;
				}

				Matrix4d matFlattenLocalToWorld = flattenWorldMatrix;
				Matrix4d matWorldToFlattenLocal = matFlattenLocalToWorld.Invert();

				m_S3MEffectParam.m_matS3MEffectLocalToWorld = matFlattenLocalToWorld;
				m_S3MEffectParam.m_matWorldToFlattenLocal = matWorldToFlattenLocal;
				m_S3MEffectParam.m_nRegionCount = nRegionCount;

				delete[] pUGS3MEffectWorldMatrix;
			}

			void Layer3DS3MFile::SetMaterialMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strName)
			{
				FLinearColor vX;
				vX.R = mat[0][0];
				vX.G = mat[0][1];
				vX.B = mat[0][2];
				vX.A = mat[0][3];

				FLinearColor vY;
				vY.R = mat[1][0];
				vY.G = mat[1][1];
				vY.B = mat[1][2];
				vY.A = mat[1][3];

				FLinearColor vZ;
				vZ.R = mat[2][0];
				vZ.G = mat[2][1];
				vZ.B = mat[2][2];
				vZ.A = mat[2][3];

				FLinearColor vW;
				vW.R = mat[3][0];
				vW.G = mat[3][1];
				vW.B = mat[3][2];
				vW.A = mat[3][3];

				FString strX = strName + TEXT("X");
				FString strY = strName + TEXT("Y");
				FString strZ = strName + TEXT("Z");
				FString strW = strName + TEXT("W");

				pMID->SetVectorParameterValue(FName(strX), vX);
				pMID->SetVectorParameterValue(FName(strY), vY);
				pMID->SetVectorParameterValue(FName(strZ), vZ);
				pMID->SetVectorParameterValue(FName(strW), vW);
			}

			S3MEffectShaderParamters Layer3DS3MFile::GetS3MEffectParam()
			{
				return m_S3MEffectParam;
			}

			void Layer3DS3MFile::ClearFlattenRegion()
			{
				if (_ReleaseAllFlattenRegions != nullptr)
				{
					_ReleaseAllFlattenRegions(m_nLayerID);
				}

				m_S3MEffectParam.m_nRegionCount = 0;
				m_S3MEffectParam.m_pS3MEffectTexture = nullptr;

				UpdateMaterialS3MEffectParam(0, true);
			}

			void Layer3DS3MFile::SetClipShaderParam(UMaterialInstanceDynamic* pMID)
			{
				if (pMID == nullptr)
				{
					return;
				}
				int32 nClip = m_ClipParam.m_arrClipPlanes.Num();
				if (nClip == 0)
				{
					pMID->SetScalarParameterValue(FName("ClipPlaneCount"), nClip);
					return;
				}

				for (int32 n = 0; n < nClip; n++)
				{
					FString name = TEXT("ClipPlane") + FString::FromInt(n);

					Plane plane = m_ClipParam.m_arrClipPlanes[n];

					Vector4d vPlane;
					vPlane.X = plane.GetNormal().X;
					vPlane.Y = plane.GetNormal().Y;
					vPlane.Z = plane.GetNormal().Z;
					vPlane.W = plane.GetPlaneDistance();

					FLinearColor vLinearPlane;
					vLinearPlane.R = vPlane.X;
					vLinearPlane.G = vPlane.Y;
					vLinearPlane.B = vPlane.Z;
					vLinearPlane.A = vPlane.W;

					pMID->SetVectorParameterValue(FName(name), vLinearPlane);
				}

				//SetMaterialMatrix(pMat, m_ClipParam.m_matViewMatrix.Invert(), TEXT("ClipViewMatrix"));

				pMID->SetScalarParameterValue(FName("ClipPlaneCount"), nClip);
				pMID->SetScalarParameterValue(FName("ClipMode"), (int32)m_eBoxClipMode);

				Vector4d vClipLineColor = m_ClipParam.m_vClipLineColor;
				FLinearColor vClipLineLinearColor;
				vClipLineLinearColor.R = vClipLineColor.X;
				vClipLineLinearColor.G = vClipLineColor.Y;
				vClipLineLinearColor.B = vClipLineColor.Z;
				vClipLineLinearColor.A = vClipLineColor.W;

				pMID->SetVectorParameterValue(FName("ClipLineColor"), vClipLineLinearColor);
			}

			void Layer3DS3MFile::UpdateClipShaderParam()
			{
				for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapNativeGameComponent.CreateConstIterator(); It; ++It)
				{
					GameComponent* pGameComponent = It->Value;
					if (pGameComponent != nullptr)
					{
						TArray<UMaterialInterface*> arrCustomMaterials;
						pGameComponent->GetSceneNode()->GetAllCustomMaterials(arrCustomMaterials);
						for (int materialIndex = 0; materialIndex < arrCustomMaterials.Num(); materialIndex++)
						{
							UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)arrCustomMaterials[materialIndex];
							SetClipShaderParam(pMat);
						}
					}
				}
			}

			void Layer3DS3MFile::UpdateMaterialS3MEffectParam(int32 nRegionCount, bool bClear)
			{
				for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapNativeGameComponent.CreateConstIterator(); It; ++It)
				{
					GameComponent* pGameComponent = It->Value;
					if (pGameComponent != nullptr)
					{
						TArray<UMaterialInterface*> arrCustomMaterials;
						pGameComponent->GetSceneNode()->GetAllCustomMaterials(arrCustomMaterials);
						for (int materialIndex = 0; materialIndex < arrCustomMaterials.Num(); materialIndex++)
						{
							UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)arrCustomMaterials[materialIndex];
							if (m_S3MEffectParam.m_eModifyRegionMode == ModifyRegionMode::Flatten)
							{
								SetFlattenShaderParam(pMat);
							}
							else if (m_S3MEffectParam.m_eModifyRegionMode == ModifyRegionMode::ClipInside ||
								m_S3MEffectParam.m_eModifyRegionMode == ModifyRegionMode::ClipOutside)
							{
								SetExcavationShaderParam(pMat);
							}
						}
					}
				}
				m_bUpdateS3MEffectShader = false;
			}

			void Layer3DS3MFile::SetExcavationShaderParam(UMaterialInstanceDynamic* pMat)
			{
				int32 nPlane = (Core::ROCacheManager::m_eSceneType == SceneType::Flat ? 0 : 1);
				SetMaterialMatrix(pMat, m_S3MEffectParam.m_matWorldToFlattenLocal, TEXT("ExcavationWorldToFlatLocal"));

				if (m_S3MEffectParam.m_pS3MEffectTexture != nullptr)
				{
					pMat->SetTextureParameterValue(TEXT("ExcavationRegion"), m_S3MEffectParam.m_pS3MEffectTexture);
				}
				pMat->SetVectorParameterValue(TEXT("ExcavationRect"), FLinearColor(m_S3MEffectParam.m_v4S3MEffectRectPos));
				pMat->SetScalarParameterValue(TEXT("ExcavationRegionCount"), m_S3MEffectParam.m_nRegionCount);
				pMat->SetScalarParameterValue(TEXT("ExcavationRegionMode"), m_S3MEffectParam.m_eModifyRegionMode);
			}

			void Layer3DS3MFile::SetFlattenShaderParam(UMaterialInstanceDynamic* pMat)
			{
				int32 nPlane = (Core::ROCacheManager::m_eSceneType == SceneType::Flat ? 0 : 1);
				SetMaterialMatrix(pMat, m_S3MEffectParam.m_matS3MEffectLocalToWorld, TEXT("FlatLocalToWorld"));
				SetMaterialMatrix(pMat, m_S3MEffectParam.m_matWorldToFlattenLocal, TEXT("WorldToFlatLocal"));

				if (m_S3MEffectParam.m_pS3MEffectTexture != nullptr)
				{
					pMat->SetTextureParameterValue(TEXT("FlattenRegion"), m_S3MEffectParam.m_pS3MEffectTexture);
				}
				pMat->SetVectorParameterValue(TEXT("FlattenRect"), FLinearColor(m_S3MEffectParam.m_v4S3MEffectRectPos));
				pMat->SetVectorParameterValue(TEXT("OriginPosition"), FVector(Core::ROCacheManager::m_vecWorldOrigin));
				pMat->SetScalarParameterValue(TEXT("SceneType"), nPlane);
				pMat->SetScalarParameterValue(TEXT("RegionCount"), m_S3MEffectParam.m_nRegionCount);
			}

			void Layer3DS3MFile::UpdataHypsometricSetting()
			{
				for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapNativeGameComponent.CreateConstIterator(); It; ++It)
				{
					GameComponent* pGameComponent = It->Value;
					if (pGameComponent != nullptr)
					{
						TArray<UMaterialInterface*> arrCustomMaterials;
						pGameComponent->GetSceneNode()->GetAllCustomMaterials(arrCustomMaterials);
						for (int materialIndex = 0; materialIndex < arrCustomMaterials.Num(); materialIndex++)
						{
							UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)arrCustomMaterials[materialIndex];
							SetHypsometricSettingShaderParam(pMat);
						}
					}
				}
				m_bUpdataHypsometricSetting = false;
			}

			void Layer3DS3MFile::SetHypsometricSettingShaderParam(UMaterialInstanceDynamic* pMat)
			{
				if (pMat == nullptr)
				{
					return;
				}
				pMat->SetScalarParameterValue(FName("HypsometricSettingMode"), int(m_pHypsometricSetting->GetAnalysisMode()));
				pMat->SetScalarParameterValue(FName("DisplayMode"), int(m_pHypsometricSetting->GetDisplayMode()));
				pMat->SetVectorParameterValue(FName("LineColor"), FLinearColor(m_pHypsometricSetting->GetLineColor()));
				pMat->SetScalarParameterValue(FName("LinesInterval"), m_pHypsometricSetting->GetLinesInterval());
				pMat->SetScalarParameterValue(FName("ColorTableMinKey"), m_pHypsometricSetting->GetColorTableMinKey());
				pMat->SetScalarParameterValue(FName("ColorTableMaxKey"), m_pHypsometricSetting->GetColorTableMaxKey());
				pMat->SetScalarParameterValue(FName("MinVisibleValue"), m_pHypsometricSetting->GetMinVisibleValue());
				pMat->SetScalarParameterValue(FName("MaxVisibleValue"), m_pHypsometricSetting->GetMaxVisibleValue());
				pMat->SetTextureParameterValue(FName("HypsometricSettingTexture"), m_pHypsometricSetting->GetColorTableTexture());
			}

			void Layer3DS3MFile::SetHypsometricSetting(HypsometricSetting* pHypsometricSetting)
			{
				if (m_pHypsometricSetting == nullptr)
				{
					m_pHypsometricSetting = new HypsometricSetting();
				}
				m_pHypsometricSetting->SetAnalysisMode(pHypsometricSetting->GetAnalysisMode());
				m_pHypsometricSetting->SetDisplayMode(pHypsometricSetting->GetDisplayMode());
				m_pHypsometricSetting->SetLineColor(pHypsometricSetting->GetLineColor());
				m_pHypsometricSetting->SetLinesInterval(pHypsometricSetting->GetLinesInterval());
				m_pHypsometricSetting->SetMaxVisibleValue(pHypsometricSetting->GetMaxVisibleValue());
				m_pHypsometricSetting->SetMinVisibleValue(pHypsometricSetting->GetMinVisibleValue());
				m_pHypsometricSetting->SetColorTableMaxKey(pHypsometricSetting->GetColorTableMaxKey());
				m_pHypsometricSetting->SetColorTableMinKey(pHypsometricSetting->GetColorTableMinKey());
				m_pHypsometricSetting->SetColorTableTexture(pHypsometricSetting->GetColorTableTexture());
				m_bUpdataHypsometricSetting = true;
			}

			void Layer3DS3MFile::ClearHypsometricSetting()
			{
				if (m_pHypsometricSetting != nullptr)
				{
					m_pHypsometricSetting->SetDisplayMode(NONE);
					UpdataHypsometricSetting();
					delete m_pHypsometricSetting;
				}
				m_pHypsometricSetting = nullptr;
			}

			HypsometricSetting* Layer3DS3MFile::GetHypsometricSetting()
			{
				return m_pHypsometricSetting;
			}

			void Layer3DS3MFile::SetConstantPolygonOffset(double dOffset)
			{
				m_dConstantPolygonOffset = dOffset;
				for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapNativeGameComponent.CreateConstIterator(); It; ++It)
				{
					GameComponent* pGameComponent = It->Value;
					if (pGameComponent != nullptr)
					{
						TArray<UMaterialInterface*> arrCustomMaterials;
						pGameComponent->GetSceneNode()->GetAllCustomMaterials(arrCustomMaterials);
						for (int materialIndex = 0; materialIndex < arrCustomMaterials.Num(); materialIndex++)
						{
							UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)arrCustomMaterials[materialIndex];
							pMat->SetScalarParameterValue(FName("OffsetValue"), m_dConstantPolygonOffset);
						}
					}
				}
			}

			double Layer3DS3MFile::GetConstantPolygonOffset()
			{
				return m_dConstantPolygonOffset;
			}

			double Layer3DS3MFile::GetMaxDataValue()
			{
				if (_GetMaxDataValue == nullptr)
				{
					return -1;
				}
				return _GetMaxDataValue(m_nLayerID);
			}

			double Layer3DS3MFile::GetMinDataValue()
			{
				if (_GetMinDataValue == nullptr)
				{
					return -1;
				}
				return _GetMinDataValue(m_nLayerID);
			}

			void Layer3DS3MFile::AddNativeGameComponent(GameComponent* pGameComponent)
			{
				m_mapNativeGameComponent.Add(pGameComponent->GetNodeName(), pGameComponent);
				if (m_bIsViewport)
				{
					if (pGameComponent != nullptr)
					{
						USuperMap_MeshComponentInterface* pComponent = pGameComponent->GetSceneNode();
						if (pComponent != nullptr)
						{
							pComponent->SetVisibleInViewport(0, m_bVisibleInViewport[0]);
							pComponent->SetVisibleInViewport(1, m_bVisibleInViewport[1]);
						}
					}
				}
				UpdateShaderForOneNativeGameComponent(pGameComponent);
			}

			void Layer3DS3MFile::RemoveNativeGameComponent(GameComponent* pGameComponent)
			{
				m_mapNativeGameComponent.Remove(pGameComponent->GetNodeName());
			}

			void Layer3DS3MFile::UpdateMaterialInfo(GameMaterial* pGameMaterial)
			{
				FString strMaterialOriginName = pGameMaterial->GetMaterialOrginName();
				Gamebool isFind = false;
				//材质替换分割“_”确定前部名称
				Gameint nIndex = 0;
				if (strMaterialOriginName.FindLastChar(TCHAR('_'), nIndex))
				{
					Gameint nStrCount = strMaterialOriginName.Len() - nIndex;
					strMaterialOriginName.RemoveAt(nIndex, nStrCount);
					isFind = (m_ObjectMaterialInfo.m_mapMaterialNameChanges.Find(strMaterialOriginName) != nullptr);
				}

				UMaterialInstanceDynamic* pMID = pGameMaterial->GetMID();
				FString strNewMaterialPath = "";
				if (!m_MaterialInfo.m_strMaterialName.IsEmpty())
				{
					strNewMaterialPath = m_MaterialInfo.m_strMaterialName;
				}
				else if (isFind)
				{
					strNewMaterialPath = m_ObjectMaterialInfo.m_mapMaterialNameChanges[strMaterialOriginName].AssociateMaterialPath;
				}
				else
				{
					TMap<FName, TMap<FString, FString>> mapS3MLayersMaterialAsset = AssetLibrary::GetSingleton()->GetUEAssetLibrary().m_mapS3MLayersMaterialAsset;
					if (mapS3MLayersMaterialAsset.Num() > 0 && mapS3MLayersMaterialAsset.Contains(m_strLayerName))
					{
						TMap<FString, FString> strNewMaterialAsset = mapS3MLayersMaterialAsset[m_strLayerName];
						if (strNewMaterialAsset.Contains(strMaterialOriginName))
						{
							strNewMaterialPath = strNewMaterialAsset[strMaterialOriginName];
						}
					}
				}
				//初始化替换材质
				if (strNewMaterialPath != "")
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *strNewMaterialPath);
					if (pMaterialInterface == nullptr)
					{
						return;
					}
					UMaterialInstanceDynamic* pNewMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
					pNewMID->AddToRoot();
					pGameMaterial->SetMID(pNewMID);
					FString strMatName = pMaterialInterface->GetName();
					if (pMaterialInterface && m_MaterialInfo.m_strMaterialName.IsEmpty())
					{
						if (!m_MaterialInfo.m_mapMaterialMappingInfo.Find(strMaterialOriginName))
						{
							m_MaterialInfo.m_mapMaterialMappingInfo.Add(strMaterialOriginName, strMatName);
							m_arrPtrMaterialInterface.Add(pMaterialInterface);
						}
					}
					
					if (isFind)
					{
						FLinearColor  uv = FLinearColor(1, 1, 1, 1);
						FHashedMaterialParameterInfo info;
						info.Name = NameToScriptName(DEAFAULT_UV_OFFSET_AND_SCALE);
						if (pNewMID->GetVectorParameterValue(info, uv))
						{
							m_ObjectMaterialInfo.m_mapMaterialNameChanges[strMaterialOriginName].MaterialOriginalUVTiling = uv;
							FLinearColor uvNew = m_ObjectMaterialInfo.m_mapMaterialNameChanges[strMaterialOriginName].MaterialOriginalUVTiling * m_ObjectMaterialInfo.m_mapMaterialNameChanges[strMaterialOriginName].AssociateMaterialUVTiling;
							pNewMID->SetVectorParameterValue(DEAFAULT_UV_OFFSET_AND_SCALE, uvNew);
						}
					}
				}
				pGameMaterial->UpdateShaderParam();
			}

			void Layer3DS3MFile::UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent)
			{
				TArray<GameMaterial*> &listGameMaterial = pGameComponent->GetAllGameMaterial();
				for (Gameint i = 0; i < listGameMaterial.Num(); i++)
				{
					GameMaterial* pGameMaterial = listGameMaterial[i];
					if (pGameMaterial == nullptr)
					{
						continue;
					}

					// 更新图层需要替换的材质
					UpdateMaterialInfo(pGameMaterial);

					UMaterialInstanceDynamic* pMat = pGameMaterial->GetMID();
					if (m_ClipParam.m_eBoxClipMode != BoxClipPart::ClipNothing)
					{
						SetClipShaderParam(pMat);
					}

					if (m_S3MEffectParam.m_pS3MEffectTexture != nullptr)
					{
						if (m_S3MEffectParam.m_eModifyRegionMode == ModifyRegionMode::Flatten)
						{
							SetFlattenShaderParam(pMat);
						}
						else if (m_S3MEffectParam.m_eModifyRegionMode == ModifyRegionMode::ClipInside ||
							m_S3MEffectParam.m_eModifyRegionMode == ModifyRegionMode::ClipOutside)
						{
							SetExcavationShaderParam(pMat);
						}
					}

					if (m_pHypsometricSetting != nullptr)
					{
						SetHypsometricSettingShaderParam(pMat);
					}

					if (m_dConstantPolygonOffset > 0)
					{
						pMat->SetScalarParameterValue(FName("OffsetValue"), m_dConstantPolygonOffset);
					}
					
				}
				pGameComponent->SetLayerName(m_strLayerName.ToString());
			}

			void Layer3DS3MFile::ExportUEMaterialToJson(FString ScpFilePath)
			{
				Gameint index;
				FString str = ScpFilePath;
				if (ScpFilePath.FindLastChar('/', index))
				{
					str.RemoveAt(index, ScpFilePath.Len() - index);
				}
				FString strPath = str + TEXT("/MaterialPackages");
				if (!FPaths::DirectoryExists(strPath))
				{
					IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
					FileManager.CreateDirectory(*strPath);
				}
				// 导出美化材质
				for (const auto & pMat : m_arrPtrMaterialInterface)
				{
					FString strMatName = pMat->GetName();
					FString filePath = strPath + TEXT("/") + strMatName + TEXT(".json");
					Data::JsonUtils::MaterialSaveToJson(pMat, filePath);
				}
				LayerInfoToJson(strPath + TEXT("/LayerInfo.json"));
			}

			void Layer3DS3MFile::LayerInfoToJson(FString strPath)
			{
				JsonFile* jsonArrLayerFile = new JsonFile(JsonValueType::arrayValue);
				jsonArrLayerFile->Add(LayerToJson());
				JsonFile* jsonSceneFile = new JsonFile(JsonValueType::objectValue);
				jsonSceneFile->Add("Layers", jsonArrLayerFile);

				// 场景数组 目前只有一个
				JsonFile* jsonSceneSFile = new JsonFile(JsonValueType::arrayValue);
				jsonSceneSFile->Add(jsonSceneFile);

				// 数据源
				JsonFile* jsonDatasourceSetFile = new JsonFile(JsonValueType::arrayValue);
				JsonFile* jsonServerFile = new JsonFile(JsonValueType::objectValue);

				jsonServerFile->Add("Server", FString(""));
				jsonDatasourceSetFile->Add(jsonServerFile);

				JsonFile* rootJsonFile = new JsonFile(JsonValueType::objectValue);
				rootJsonFile->Add("DataSources", jsonDatasourceSetFile);
				rootJsonFile->Add("Scenes", jsonSceneSFile);
				rootJsonFile->Add("Version", FString("1.0"));
				rootJsonFile->SaveToStdFile(strPath);

				delete jsonArrLayerFile;
				jsonArrLayerFile = nullptr;
				delete jsonSceneFile;
				jsonSceneFile = nullptr;
				delete jsonSceneSFile;
				jsonSceneSFile = nullptr;
				delete jsonDatasourceSetFile;
				jsonDatasourceSetFile = nullptr;
				delete jsonServerFile;
				jsonServerFile = nullptr;
				delete rootJsonFile;
				rootJsonFile = nullptr;
			}

			void Layer3DS3MFile::AddRelatedPathToScpFile(FString LayerInfoPath, FString ScpFilePath)
			{
				// 导出材质路径关联到Scp
				ANSICHAR* cLayerInfoPath;
				MathEngine::FStringToANSIChar(LayerInfoPath, cLayerInfoPath);

				ANSICHAR* cScpFilePath;
				MathEngine::FStringToANSIChar(ScpFilePath, cScpFilePath);

				if (cLayerInfoPath != nullptr && cScpFilePath != nullptr)
				{
					_AddMaterialAssociateWithScp(this, cLayerInfoPath, cScpFilePath);
				}

				if (cLayerInfoPath != nullptr)
				{
					delete cLayerInfoPath;
					cLayerInfoPath = nullptr;
				}
				if (cScpFilePath != nullptr)
				{
					delete cScpFilePath;
					cScpFilePath = nullptr;
				}
			}

			void Layer3DS3MFile::SetDecodeMeshopt(Gamebool value)
			{
				if (_SetDecodeMeshopt)
				{
					_SetDecodeMeshopt(m_pUGLayer3D, value);
				}
			}

			Gamebool Layer3DS3MFile::IsDecodeMeshopt()
			{
				if (_GetDecodeMeshopt)
				{
					return _GetDecodeMeshopt(m_pUGLayer3D);
				}
				return false;
			}

			void Layer3DS3MFile::SetCoverImageryLayer(TArray<Layer3D*> arrImageLayers)
			{
				Gameint nCount = arrImageLayers.Num();
				void** pImageLayer = new void* [nCount];
				for (int i = 0; i < arrImageLayers.Num(); i++)
				{
					pImageLayer[i] = arrImageLayers[i]->GetHandler();
				}
				_S3MLayer_SetCoverImageryLayer(m_pUGLayer3D, pImageLayer, nCount);
				delete[] pImageLayer;
			}

			ObjectsColorDictionary* Layer3DS3MFile::GetObjectsColorDictionary()
			{
				if (m_pObjectsColorDictionary == nullptr)
				{
					m_pObjectsColorDictionary = new ObjectsColorDictionary(m_pUGLayer3D);
				}
				return m_pObjectsColorDictionary;
			}

			void Layer3DS3MFile::SetLoadingPriority(LoadingPriorityEnum type)
			{
				if (_SetLoadingPriority)
				{
					_SetLoadingPriority(m_pUGLayer3D, type);
				}
			}

			LoadingPriorityEnum Layer3DS3MFile::GetLoadingPriority()
			{
				LoadingPriorityEnum type = Child_Priority;
				if (_GetLoadingPriority)
				{
					type = (LoadingPriorityEnum)_GetLoadingPriority(m_pUGLayer3D);
				}
				return type;
			}

			Gamedouble Layer3DS3MFile::GetMaxHeight()
			{
				return _S3MLayer_GetDataMaxValue(m_pUGLayer3D);
			}

			Gamedouble Layer3DS3MFile::GetMinHeight()
			{
				return _S3MLayer_GetDataMinValue(m_pUGLayer3D);
			}

			ObjectsColorDictionary::ObjectsColorDictionary(void* pUGLayer3D)
			{
				m_pUGLayer3DS3MFile = pUGLayer3D;
			}

			ObjectsColorDictionary::~ObjectsColorDictionary()
			{
				m_pUGLayer3DS3MFile = nullptr;
			}

			void ObjectsColorDictionary::SetObjectsColor(TArray<Gameint> ids, FVector4 color)
			{
				if (_SetObjectsColor)
				{
					Gameint nCount = ids.Num();
					Gameint* IDs = new Gameint[nCount];
					for (Gameint i = 0; i < nCount; i++)
					{
						IDs[i] = ids[i];
					}
					_SetObjectsColor(m_pUGLayer3DS3MFile, IDs, nCount, color.X, color.Y, color.Z, color.W);

					delete[] IDs;
				}
			}

			TMap<Gameint, FVector4> ObjectsColorDictionary::GetObjectsColor()
			{
				TMap<Gameint, FVector4> result;
				if (_GetObjectsColor)
				{
					Gameint* IDs = nullptr;
					Gameint nCount = 0;
					Gamedouble* dRGBA = nullptr;
					_GetObjectsColor(m_pUGLayer3DS3MFile, IDs, nCount, dRGBA);
					
					for (Gameint i = 0; i < nCount; i++)
					{
						result.Add(IDs[i], FVector4(dRGBA[i * 4], dRGBA[i * 4 + 1], dRGBA[i * 4 + 2], dRGBA[i * 4 + 3]));
					}
					if (nCount > 0)
					{
						MathEngine::FreeUGInt(IDs);
						MathEngine::FreeUGDouble(dRGBA);
					}
				}
				return result;
			}

			void ObjectsColorDictionary::RemoveObjectsColor(TArray<Gameint> ids)
			{
				if (_RemoveObjectsColor)
				{
					Gameint nCount = ids.Num();
					Gameint* IDs = new Gameint[nCount];
					_RemoveObjectsColor(m_pUGLayer3DS3MFile, IDs, nCount);
					delete[] IDs;
				}
			}

			void ObjectsColorDictionary::ResetObjectsColor()
			{
				if (_ResetObjectsColor)
				{
					_ResetObjectsColor(m_pUGLayer3DS3MFile);
				}
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif