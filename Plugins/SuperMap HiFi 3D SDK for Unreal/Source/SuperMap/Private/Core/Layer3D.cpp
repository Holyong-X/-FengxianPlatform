#include "Core/Layer3D.h"
#include "Core/ROCacheManager.h"
#include "ControlUE/RealspaceView.h"
#include "ControlUE/CameraControl.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Base3D/CommonDefine.h"
#include "Core/Georeference.h"
#include "Graphics3D/GameComponent.h"
#include "Graphics3D/GameMaterialManager.h"
#include "Algorithm3D/MathEngine.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::ControlUE;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{

			Layer3D::Layer3D()
			{
				m_bIsVisible = true;
				m_pSelection = nullptr;
				m_pUGLayer3D = nullptr;
				m_bUpdateClip = false;
				m_bHasClip = false;
				m_eBoxClipMode = ClipInner;
				m_nNodeName = 0;
				m_bInitial = false;
				m_bVisibleInViewport[0] = true;
				m_bVisibleInViewport[1] = true;
				m_bIsViewport = false;
				m_pUEAssetStyle = nullptr;
				m_LayerDeleteEventInfos.m_pActor = nullptr;
			}

			Layer3D::Layer3D(FName strLayerName, Layer3DType eLayerType)
			{
				m_strLayerName = strLayerName;
				m_strDataLayerName = strLayerName;
				m_eLayerType = eLayerType;
				m_bIsVisible = true;
				m_pSelection = nullptr;
				m_pUGLayer3D = nullptr;
				m_bUpdateClip = false;
				m_bHasClip = false;
				m_eBoxClipMode = ClipInner;
				m_nNodeName = 0;
				m_bVisibleInViewport[0] = true;
				m_bVisibleInViewport[1] = true;
				m_bIsViewport = false;
				m_pUEAssetStyle = nullptr;
				m_bInitial = false;
				m_LayerDeleteEventInfos.m_pActor = nullptr;
			}
			Layer3D::Layer3D(Gamevoid* pUGLayer3D, FName strLayerName, Layer3DType eLayerType)
			{
				m_strLayerName = strLayerName;
				m_strDataLayerName = strLayerName;
				m_eLayerType = eLayerType;
				m_bIsVisible = true;
				m_pUGLayer3D = pUGLayer3D;
				m_bUpdateClip = false;
				m_bHasClip = false;
				m_eBoxClipMode = ClipInner;
				m_nNodeName = 0;
				m_bVisibleInViewport[0] = true;
				m_bVisibleInViewport[1] = true;
				m_pSelection = new Selection3D(this);
				m_bIsViewport = false;
				m_pUEAssetStyle = nullptr;
				m_bInitial = false;
				m_LayerDeleteEventInfos.m_pActor = nullptr;
			}

			Layer3D::~Layer3D()
			{
				if (m_pSelection != NULL)
				{
					delete m_pSelection;
					m_pSelection = NULL;
				}

				m_mapNativeGameComponent.Empty();

				if (m_pUEAssetStyle != nullptr)
				{
					delete m_pUEAssetStyle;
					m_pUEAssetStyle = nullptr;
				}

				_Layer3D_RemoveGPUSharedParameters(m_nLayerID);
				m_LayerDeleteEventInfos.m_pActor = nullptr;
			}

			Gamevoid* Layer3D::GetHandler()
			{
				return m_pUGLayer3D;
			}

			FName Layer3D::Name()
			{
				return m_strLayerName;
			}

			FName Layer3D::DataName()
			{
				return m_strDataLayerName;
			}

			FString Layer3D::GetDataPath()
			{
				FString dataPath;
				Gamechar* cPath = nullptr;
				_Layer3D_GetDataPath(m_pUGLayer3D, cPath);
				if (cPath != nullptr)
				{
					dataPath = UTF8_TO_TCHAR(cPath);
					_FreeByte(cPath);
				}
				return dataPath;
			}

			Gamebool Layer3D::GetIsVisible()
			{
				FString strName = m_strLayerName.ToString();
				const TCHAR* c = *strName;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);

				m_bIsVisible = _GetVisible(cc);

				return m_bIsVisible;
			}

			Gamevoid Layer3D::SetIsVisible(Gamebool bVisible)
			{
				if (m_bIsVisible != bVisible)
				{
					m_bIsVisible = bVisible;

					FString strName = m_strLayerName.ToString();
					const TCHAR* c = *strName;
					ANSICHAR* cc = TCHAR_TO_UTF8(c);

					_SetVisible(bVisible, cc);
				}
			}

			Gamebool Layer3D::GetIsVisibleChanged()
			{
				return m_bIsVisibleChanged;
			}

			Gamevoid Layer3D::SetIsVisibleChanged(Gamebool bVisible)
			{
				m_bIsVisibleChanged = bVisible;
			}

			FName Layer3D::NodeName()
			{
				FString strName = m_strLayerName.ToString();
				const TCHAR* c = *strName;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);

				ANSICHAR* ccc = _GetNodeName(cc);
				return FName(ccc);
			}

			Gamelong Layer3D::NodeNameHashCode()
			{
				m_nNodeName = _GetLayerNodeNameHashCode(m_pUGLayer3D);
				return m_nNodeName;
			}

			Gamevoid Layer3D::AddSelectedID(Gameint nID)
			{
				_Layer3D_AddSelectedID(m_pUGLayer3D, nID);
			}

			Gamevoid Layer3D::ReleaseSelection()
			{
				_Layer3D_RemoveAllSelectedID(m_pUGLayer3D);
			}

			Gamevoid Layer3D::SetOriginalPosition(FVector vPos)
			{
				FString strName = m_strLayerName.ToString();
				const TCHAR* c = *strName;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);

				_SetOriginalPosition(2, cc, vPos.X, vPos.Y, vPos.Z);
			}

			Layer3DType Layer3D::Type()
			{
				return m_eLayerType;
			}

			OSGBType Layer3D::DataType()
			{
				//! \brief 数据类型
				OSGBType m_eFileType = (OSGBType)_Layer3D_GetOSGBType(m_pUGLayer3D);

				return m_eFileType;
			}

			Layer3DMaterialInfo& Layer3D::GetMaterialInfo()
			{
				return m_MaterialInfo;
			}

			Gamevoid Layer3D::SetMaterialInfo(Layer3DMaterialInfo& info)
			{
				if (info.m_strMaterialName == m_MaterialInfo.m_strMaterialName)
				{
					return;
				}

				m_MaterialInfo = info;
				UpdateData();
			}

			Gamevoid Layer3D::GetClipParamFromUGC()
			{
				Matrix4d matXY;
				matXY[0][0] = 0;
				matXY[1][0] = 1;
				matXY[1][1] = 0;
				matXY[0][1] = 1;

				Matrix4d matObjectMatrix = Georeference::GetECEFtoGeoreference();

				matObjectMatrix = matXY * matObjectMatrix * matXY;

				Matrix4d matScale;
				matScale[0][0] = M_TO_CM;
				matScale[1][1] = M_TO_CM;
				matScale[2][2] = M_TO_CM;

				matObjectMatrix = matObjectMatrix * matScale * matXY;

				Vector3d vOriginLocation = RealspaceView::GetSingleton()->GetWorld()->OriginLocation;

				Matrix4d matTrans;
				if ((Gameuint)CameraControl::m_eSceneType == (Gameuint)Globe || (Gameuint)CameraControl::m_eSceneType == (Gameuint)Ellipsoid_WGS84)
				{
					matTrans[3][0] -= MathEngine::m_vWorldOffset.X;
					matTrans[3][1] -= MathEngine::m_vWorldOffset.Y;
					matTrans[3][2] -= MathEngine::m_vWorldOffset.Z;
				}
				
				matTrans[3][0] -= vOriginLocation.X;
				matTrans[3][1] -= vOriginLocation.Y;
				matTrans[3][2] -= vOriginLocation.Z;

				matObjectMatrix = matObjectMatrix * matTrans;
				Gamedouble* pMatIndent = new Gamedouble[16];

				Gameint nPlanes = 0;
				Gamedouble* pPlanes = nullptr;
				Matrix4d::ToDoublePointer(matObjectMatrix, pMatIndent);
				_GetClipPlaneParameter(m_pUGLayer3D, pMatIndent, pPlanes, nPlanes);

				m_ClipParam.m_arrClipPlanes.Empty();

				for (Gameint n = 0; n < nPlanes; n++)
				{
					Vector3d vNormal = Vector3d(pPlanes[n * 4], pPlanes[n * 4 + 1], pPlanes[n * 4 + 2]);
					Gamedouble dDistance = pPlanes[n * 4 + 3];
					Plane plane(vNormal, dDistance);
					m_ClipParam.m_arrClipPlanes.Add(plane);
				}

				m_ClipParam.m_vClipLineColor = GetClipLineColor();
				m_ClipParam.m_eBoxClipMode = m_eBoxClipMode;

				delete[] pMatIndent;
			}

			Gamevoid Layer3D::ClearCustomClipPlane()
			{
				_ClearCustomClipPlane(m_pUGLayer3D);
				m_bUpdateClip = true;
			}

			ObjectMaterialInfo& Layer3D::GetObjectMaterialInfo()
			{
				return m_ObjectMaterialInfo;
			}

			Gamevoid Layer3D::SetObjectMaterialInfo(ObjectMaterialInfo& info)
			{
				Gamebool beChange = false;

				if (info.m_mapMaterialNameChanges.Num() > 0)
				{
					for (auto It : info.m_mapMaterialNameChanges)
					{
						FString stringName = It.Key;
						//缓存
						if (m_eLayerType == Layer3DType::S3M)
						{
							//材质替换分割“_”确定前部名称
							Gameint nIndex = 0;
							if (stringName.FindLastChar(TCHAR('_'), nIndex))
							{
								Gameint nStrCount = stringName.Len() - nIndex;
								stringName.RemoveAt(nIndex, nStrCount);
							}
						}
						AssociateMaterialInfo associateMaterialInfo = It.Value;


						if (!m_ObjectMaterialInfo.m_mapMaterialNameChanges.Find(stringName)
							||(m_ObjectMaterialInfo.m_mapMaterialNameChanges.Find(stringName) &&
							 !m_ObjectMaterialInfo.m_mapMaterialNameChanges[stringName].AssociateMaterialPath.Equals(associateMaterialInfo.AssociateMaterialPath)))
						{
							m_ObjectMaterialInfo.m_mapMaterialNameChanges.Add(stringName, associateMaterialInfo);
							beChange = true;
						}
					}
				}

				if (!beChange)
				{
					return;
				}


				UpdateData();
			}

			Gamevoid Layer3D::DeleteObjectMaterialInfo(FString strMaterialName)
			{
				FString stringName = strMaterialName;
				//缓存
				if (m_eLayerType == Layer3DType::S3M)
				{
					//材质替换分割“_”确定前部名称
					Gameint nIndex = 0;
					if (stringName.FindLastChar(TCHAR('_'), nIndex))
					{
						Gameint nStrCount = stringName.Len() - nIndex;
						stringName.RemoveAt(nIndex, nStrCount);
					}
				}

				if (m_MaterialInfo.m_mapMaterialMappingInfo.Find(stringName))
				{
					m_MaterialInfo.m_mapMaterialMappingInfo.Remove(stringName);
				}

				if (m_ObjectMaterialInfo.m_mapMaterialNameChanges.Find(stringName))
				{
					m_ObjectMaterialInfo.m_mapMaterialNameChanges.Remove(stringName);
					UpdateData();
				}
			}

			Gamevoid Layer3D::SetCustomClipPlane(Vector3d firstPoint, Vector3d secondPoint, Vector3d thirdPoint)
			{
				_SetCustomClipPlane(m_pUGLayer3D,
					firstPoint.X , firstPoint.Y , firstPoint.Z,
					secondPoint.X, secondPoint.Y, secondPoint.Z,
					thirdPoint.X , thirdPoint.Y , thirdPoint.Z);
				m_bUpdateClip = true;
				m_bHasClip = true;
			}

			Gamevoid Layer3D::ClipByBox(GeoBox* pGeoBox, BoxClipPart ePlaneClipMode)
			{
				m_pClipBox = pGeoBox;
				m_eBoxClipMode = ePlaneClipMode;
				_SetCustomClipBox(m_pUGLayer3D, pGeoBox->GetHandler(), (Gameint)ePlaneClipMode);
				m_bUpdateClip = true;
				m_bHasClip = true;
			}

			GeoBox* Layer3D::GetClipBox()
			{
				return m_pClipBox;
			}

			BoxClipPart Layer3D::GetBoxClipPart()
			{
				return m_eBoxClipMode;
			}

			void Layer3D::UpdateClipParam()
			{
				m_bUpdateClip = true;
			}

			Gamevoid Layer3D::SetClipLineColor(Vector4d vClipLineColor)
			{
				_SetClipLineColor(m_pUGLayer3D, vClipLineColor.X, vClipLineColor.Y, vClipLineColor.Z, vClipLineColor.W);
			}

			Vector4d Layer3D::GetClipLineColor()
			{
				GameVector4 vClipLineColor;
				_GetClipLineColor(m_pUGLayer3D, vClipLineColor.X , vClipLineColor.Y, vClipLineColor.Z,vClipLineColor.W);
				return Vector4d(vClipLineColor.X, vClipLineColor.Y, vClipLineColor.Z, vClipLineColor.W);
			}

			//! \brief 返回bounds中心点
			Rectangle2D Layer3D::GetBounds()
			{
				Rectangle2D rect2D;
				float left;
				float bottom;
				float right;
				float top;

				FString strName = m_strLayerName.ToString();
				const TCHAR* c = *strName;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);

				_GetLayerBounds(cc, left, bottom, right, top);

				rect2D.Left   = left;
				rect2D.Bottom = bottom;
				rect2D.Right = right;
				rect2D.Top = top;

				return rect2D;
			}

			Gameint Layer3D::GetLayerID()
			{
				return m_nLayerID;
			}

			Gamevoid Layer3D::SetLayerID(Gameint nLayerID)
			{
				m_nLayerID = nLayerID;
			}

			Selection3D* Layer3D::GetSelection3D()
			{
				return m_pSelection;
			}

			Gamevoid Layer3D::SetSwipeEnabled(Gamebool bSwipe)
			{
				_SetSwipeEnabled(m_pUGLayer3D, bSwipe);
				m_bInitial = false;
			}

			Gamebool Layer3D::GetSwipeEnabled()
			{
				return _GetSwipeEnabled(m_pUGLayer3D);
			}

			Gamevoid Layer3D::SetSwipeRegion(Rectangle2D rcBox)
			{
				_SetSwipeRegion(m_pUGLayer3D, rcBox.Left, rcBox.Top, rcBox.Right, rcBox.Bottom);
			}

			Rectangle2D Layer3D::GetSwipeRegion()
			{
				Gamedouble dLeft = 0, dRight = 0, dTop = 0, dBottom = 0;
				_GetSwipeRegion(m_pUGLayer3D, dLeft, dTop, dRight, dBottom);
				Rectangle2D result = Rectangle2D(dLeft, dTop, dRight, dBottom);
				return result;
			}

			Gamevoid Layer3D::Render(UWorld* pWorld)
			{
			}

			JsonFile* Layer3D::LayerToJson()
			{
				JsonFile* jsonMatArryFile = new JsonFile(JsonValueType::arrayValue);
				JsonFile* jsonMatExportedArryFile = new JsonFile(JsonValueType::arrayValue);
				JsonFile* jsonMatConnectFile = new JsonFile(JsonValueType::objectValue);
				JsonFile* jsonMatExportedConnectFile = new JsonFile(JsonValueType::objectValue);
				JsonFile* jsonMatUVOffsetAndScale = new JsonFile(JsonValueType::objectValue);
				JsonFile* jsonMatFile = new JsonFile(JsonValueType::objectValue);
				if (m_eLayerType == S3M)
				{
					//材质替换
					for (auto It : m_ObjectMaterialInfo.m_mapMaterialNameChanges)
					{
						FString strOriginalMaterial = It.Key;
						AssociateMaterialInfo associateMaterialInfo = It.Value;
						jsonMatConnectFile->Add("AssociateMaterial", associateMaterialInfo.AssociateMaterialPath);
						jsonMatConnectFile->Add("OriginalMaterial", strOriginalMaterial);

						jsonMatUVOffsetAndScale->Add("OffsetU", associateMaterialInfo.AssociateMaterialUVTiling.R);
						jsonMatUVOffsetAndScale->Add("OffsetV", associateMaterialInfo.AssociateMaterialUVTiling.G);
						jsonMatUVOffsetAndScale->Add("ScaleU", associateMaterialInfo.AssociateMaterialUVTiling.B);
						jsonMatUVOffsetAndScale->Add("ScaleV", associateMaterialInfo.AssociateMaterialUVTiling.A);

						jsonMatConnectFile->Add("UVTransformation", jsonMatUVOffsetAndScale);
						jsonMatArryFile->Add(jsonMatConnectFile);

						jsonMatExportedConnectFile->Add("AssociateMaterial", associateMaterialInfo.AssociateMaterialName);
						jsonMatExportedConnectFile->Add("OriginalMaterial", strOriginalMaterial);
						jsonMatExportedConnectFile->Add("UVTransformation", jsonMatUVOffsetAndScale);
						jsonMatExportedArryFile->Add(jsonMatExportedConnectFile);
					}
				}

				jsonMatFile->Add("MaterialType", FString("UEMaterial"));
				jsonMatFile->Add("MaterialMap", jsonMatArryFile);
				jsonMatFile->Add("MaterialExportedMap", jsonMatExportedArryFile);

				// 外挂
				JsonFile* jsAssetStyleFile = new JsonFile(JsonValueType::objectValue);
				JsonFile* jsonMatArryStyleFile = new JsonFile(JsonValueType::arrayValue);

				Gameint nStyleModel = 0;
				if (m_pUEAssetStyle != nullptr)
				{
					nStyleModel = (Gameint)m_pUEAssetStyle->GetMode();
					for (auto It : m_pUEAssetStyle->GetAssetStyles())
					{
						AssetStyle* pAssetStyle = It.Value;
						if (pAssetStyle != NULL)
						{
							jsAssetStyleFile->Add("ResoureConditions", It.Key);
							jsAssetStyleFile->Add("ResoureName", pAssetStyle->GetStyleParam().m_strAssetResourePath);
							jsonMatArryStyleFile->Add(jsAssetStyleFile);
						}
					}
				}

				//缓存
				jsonMatFile->Add("MaterialName", m_MaterialInfo.m_strMaterialName);

				JsonFile* jsonLayerFile = new JsonFile(JsonValueType::objectValue);
				// 目前使用的是相同的名字
				jsonLayerFile->Add("Caption", m_strLayerName.ToString());
				jsonLayerFile->Add("DataSetAlias", m_strLayerName.ToString());
				jsonLayerFile->Add("LayerName", m_strLayerName.ToString());

				if (m_eLayerType == Layer3DType::S3M)
				{
					jsonLayerFile->Add("LayerType", FString("S3M"));
					jsonLayerFile->Add("Materials", jsonMatFile);

					Layer3DS3MFile* pS3M = (Layer3DS3MFile*)this;
					float fLayerLod = pS3M->GetLODRangeScale(m_nLayerID);
					jsonLayerFile->Add("LODRangeScale", fLayerLod);
				}
				else if (m_eLayerType == Layer3DType::DatasetVector)
				{
					jsonLayerFile->Add("LayerType", FString("Dataset"));
					jsonLayerFile->Add("DatasetType", FString("VectorPoint"));
					jsonLayerFile->Add("LayerStyleMode", nStyleModel);
					jsonLayerFile->Add("AssetStyle", jsonMatArryStyleFile);
				}
				else
				{
					jsonLayerFile->Add("LayerType", FString("Dataset"));
					jsonLayerFile->Add("DatasetType", FString("Model"));
					jsonLayerFile->Add("Materials", jsonMatFile);
				}
				Gamedouble dmax = 600000, dmin = 0;
				GetMaxMinObjectVisibleDistance(dmax, dmin);
				jsonLayerFile->Add("MaxObjectVisibleDistance", dmax);
				jsonLayerFile->Add("MinObjectVisibleDistance", dmin);
				delete jsonMatExportedArryFile;
				jsonMatExportedArryFile = nullptr;
				delete jsonMatArryFile;
				jsonMatArryFile = nullptr;
				delete jsonMatArryStyleFile;
				jsonMatArryStyleFile = nullptr;
				delete jsonMatConnectFile;
				jsonMatConnectFile = nullptr;
				delete jsonMatFile;
				jsonMatFile = nullptr;
				delete jsAssetStyleFile;
				jsAssetStyleFile = nullptr;

				return jsonLayerFile;
			}

			Gamevoid Layer3D::SetVisibleInViewport(Gameint nIndex, Gamebool visible)
			{
				m_bVisibleInViewport[nIndex] = visible;

				for (TMap<Gamelong, GameComponent*>::TConstIterator It = m_mapNativeGameComponent.CreateConstIterator(); It; ++It)
				{
					GameComponent* pGameComponent = It->Value;
					if (pGameComponent != nullptr)
					{
						USuperMap_MeshComponentInterface* pComponent = pGameComponent->GetSceneNode();
						if (pComponent != nullptr)
						{
							pComponent->SetVisibleInViewport(nIndex, visible);
						}
					}
				}
			}

			Gamevoid Layer3D::SetViewportEnabled(Gamebool bViewport)
			{
				m_bIsViewport = bViewport;
			}

			Gamevoid Layer3D::UpdateData()
			{
				_SetInitialized(m_pUGLayer3D, false);
				m_bInitial = false;
			}

			Gamevoid Layer3D::SetSelectStyle(Style3D* pStyle3D)
			{
				_Layer3D_SetSelectStyle(m_pUGLayer3D, pStyle3D->GetHandler());
				FVector4 color = pStyle3D->GetFillColor();
				FName strName = TEXT("SelectedColor");
				GameMaterialManager::GetSingleton()->SetMatVector4dShareParam(strName, FLinearColor(color.X, color.Y, color.Z, color.W));
			}

			void Layer3D::GetSelectStyle(Style3D* &style3d)
			{
				Gamevoid* pStyle3D = nullptr;
				_Layer3D_GetSelectStyle(m_pUGLayer3D, pStyle3D);
				style3d = new Style3D(pStyle3D);
			}

			Gamebool Layer3D::IsMarkerLayer()
			{
				return _Layer3D_IsMarkerLayer(m_pUGLayer3D);
			}

			Gamevoid Layer3D::SetMarkerLayer(Gamebool bIsMarkerLayer)
			{
				_Layer3D_SetMarkerLayer(m_pUGLayer3D, bIsMarkerLayer);
			}

			Gamebool Layer3D::GetVisibleInViewport(Gameint nIndex)
			{
				return m_bVisibleInViewport[nIndex];
			}

			Gamevoid Layer3D::AddNativeGameComponent(GameComponent* pGameComponent)
			{
				m_mapNativeGameComponent.Add(pGameComponent->GetNodeName(), pGameComponent);
			}

			Gamevoid Layer3D::RemoveNativeGameComponent(GameComponent* pGameComponent)
			{

			}

			TMap<Gamelong, GameComponent*>& Layer3D::GetAllNativeGameComponent()
			{
				return m_mapNativeGameComponent;
			}

			UEAssetStyle* Layer3D::GetUEAssetStyle()
			{
				if (m_pUEAssetStyle == nullptr)
				{
					m_pUEAssetStyle = new UEAssetStyle();
				}
				return m_pUEAssetStyle;
			}

			Gamevoid Layer3D::SetStyle(Style3D* pStyle)
			{
				if (_Layer3D_SetStyle)
				{
					_Layer3D_SetStyle(m_pUGLayer3D, pStyle->GetHandler());
				}
			}

			void Layer3D::GetStyle(Style3D* &pStyle)
			{
				if (_Layer3D_GetStyle)
				{
					Gamevoid* style3D = nullptr;
					_Layer3D_GetStyle(m_pUGLayer3D, style3D);
					pStyle = new Style3D(style3D);
				}
			}

			Gamevoid Layer3D::SetMaxObjectVisibleDistance(Gamedouble dValue)
			{
				if (_SetMaxObjectVisibleDistance)
				{
					_SetMaxObjectVisibleDistance(m_pUGLayer3D, dValue);
				}
			}

			void Layer3D::SetDeleteLayerEventFunc(void* pActor, LayerDeleteEvent evnt)
			{
				m_LayerDeleteEventInfos.m_pActor = pActor;
				m_LayerDeleteEventInfos.m_LayerDeleteEvent = evnt;
			}
			//Gamevoid Layer3D::SetMinObjectVisibleDistance(Gamedouble dValue)
			//{
			//	if (_SetMinObjectVisibleDistance)
			//	{
			//		_SetMinObjectVisibleDistance(m_pUGLayer3D, dValue);
			//	}
			//}

			Gamevoid Layer3D::GetMaxMinObjectVisibleDistance(Gamedouble& dmax, Gamedouble& dmin)
			{
				if (_GetMaxMinObjectVisibleDistance)
				{
					_GetMaxMinObjectVisibleDistance(m_pUGLayer3D, dmax, dmin);
				}
			}

			UEAssetStyle::UEAssetStyle()
			{
				m_eMode = UEAssetStyle::Mode::ASSET_MESH;
			}

			UEAssetStyle::~UEAssetStyle()
			{
				if (m_mapAssetStyles.Num() > 0)
				{
					for (auto It : m_mapAssetStyles)
					{
						AssetStyle* pAssetStyle = It.Value;
						delete pAssetStyle;
						pAssetStyle = nullptr;
					}
				}
				m_mapAssetStyles.Empty();
			}

			Gamevoid UEAssetStyle::SetAssetStyles(TMap<FString, AssetStyle*> mapAssetStyles)
			{
				if (m_mapAssetStyles.Num() > 0)
				{
					for (auto It : m_mapAssetStyles)
					{
						AssetStyle* pAssetStyle = It.Value;
						delete pAssetStyle;
						pAssetStyle = nullptr;

					}
				}
				m_mapAssetStyles = mapAssetStyles;
			}

			TMap<FString, AssetStyle*> UEAssetStyle::GetAssetStyles()
			{
				return m_mapAssetStyles;
			}

			Gamevoid UEAssetStyle::SetMode(UEAssetStyle::Mode type)
			{
				m_eMode = type;
			}

			UEAssetStyle::Mode UEAssetStyle::GetMode()
			{
				return m_eMode;
			}
		}
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif
