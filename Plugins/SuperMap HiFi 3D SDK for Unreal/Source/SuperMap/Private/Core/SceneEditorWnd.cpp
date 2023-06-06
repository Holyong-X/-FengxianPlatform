#include "Core/SceneEditorWnd.h"
#include "ControlUE/RealspaceView.h"
#include "Camera/CameraActor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Core/Handler/MeasureHandler.h"
#include "Data/GeoLine3D.h"
#include "Data/GeoRegion3D.h"
#include "Data/Vector3d.h"
#include "Core/Query3D.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameRenderTextureManager.h"
#include "Core/Georeference.h"
#include "Algorithm3D/MathEngine.h"
#include "Graphics3D/GameMaterialManager.h"
#include "Component/SuperMap_MeshSceneProxy.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			SceneEditorWnd::SceneEditorWnd(Scene* pScene)
			{
				m_eAction3D = PanSelect;
				m_pLayer3DS3MFile = nullptr;
				m_pTerrainLayers = nullptr;
				m_pRuler = nullptr;
				m_nMouseLeftDown = 0;
				m_vMouse = FVector(0,0,0);
				m_vRealPosition = Vector3d();
				m_bErrorPosition = false;
				m_bEditSphere = false;
				m_bSelectSphere = false;
				m_nMeasureIndex = -1;
				m_nSphereMeasureIndex = -1;
				m_pScene = pScene;
				m_enMouseDown = MB_None;
				m_bUpdateSelectedInfo = false;
				m_nSelectedLayerID = -1;
				m_pMatInstanceDynamic = nullptr;
				m_SelectedEventInfos.m_pActor = nullptr;
				m_AttributeSelectEvent.m_pActor = nullptr;
				m_pROEntityActor = nullptr;
				m_eUserAction = UserAction::RoObjectSelect;
				m_nSelectMode = SelectMode::Blend_EmssiveColor;
			}

			SceneEditorWnd::~SceneEditorWnd()
			{
				if (m_pRuler != nullptr)
				{
					m_pRuler = nullptr;
				}
				for (int i = 0; i < m_arrRuler.Num(); i++)
				{
					delete m_arrRuler[i];
				}
				m_arrRuler.Empty();
				m_pLayer3DS3MFile = nullptr;
				m_pTerrainLayers = nullptr;
				if (m_pROEntityActor != nullptr)
				{
					m_pROEntityActor = nullptr;
				}
				m_pScene = nullptr;
				m_eUserAction = UserAction::RoObjectSelect;
				m_eAction3D = PanSelect;
				ClearMeasureSphere();
			}

			void SceneEditorWnd::Release()
			{
				if (m_pLayer3DS3MFile != nullptr)
				{
					m_pLayer3DS3MFile->ClearHypsometricSetting();
					m_pLayer3DS3MFile = nullptr;
				}
				if (m_pTerrainLayers != nullptr)
				{
					m_pTerrainLayers->ClearHypsometricSetting();
					m_pTerrainLayers = nullptr;
				}
				if (m_pRuler != nullptr)
				{
					m_pRuler = nullptr;
				}
				if (m_pROEntityActor != nullptr)
				{
					m_pROEntityActor->Destroy(false, false);
					m_pROEntityActor = nullptr;
				}
				//if (m_pMatInstanceDynamic != nullptr)
				//{
				//	m_pMatInstanceDynamic->SetVectorParameterValue(TEXT("SubSelectedColor"), FLinearColor(1, 0, 0, 0));
				//	m_pMatInstanceDynamic = nullptr;
				//}
				for (int i = 0; i < m_arrRuler.Num(); i++)
				{
					delete m_arrRuler[i];
				}
				m_arrRuler.Empty();
				m_nMouseLeftDown = 0;
				m_eAction3D = PanSelect;
				ClearMeasureSphere();
				m_nMeasureIndex = -1;
				m_nSphereMeasureIndex = -1;
				m_eUserAction = UserAction::RoObjectSelect;
			}

			void SceneEditorWnd::SetAction(Action3D eAction)
			{
				m_eAction3D = eAction;

				if (m_pRuler != nullptr)
				{
					m_pRuler = nullptr;
				}

				if (m_pLayer3DS3MFile != nullptr)
				{
					m_pLayer3DS3MFile = nullptr;
				}

				if (m_pTerrainLayers != nullptr)
				{
					m_pTerrainLayers = nullptr;
				}

				if (m_pROEntityActor != nullptr)
				{
					m_pROEntityActor->Destroy(false, false);
					m_pROEntityActor = nullptr;
				}
				switch (m_eAction3D)
				{
					case MeasureDistance:
					{
						m_pRuler = new MeasureHandler(RealspaceView::GetSingleton()->GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
						m_arrRuler.Add(m_pRuler);
						m_pRuler->SetMeasureAction(MeasureHandler::MeasureAction::MeasureDistance);
						m_nMouseLeftDown = 0;
						m_nMeasureIndex += 1;
						break;
					}
					case MeasureArea:
					{
						m_pRuler = new MeasureHandler(RealspaceView::GetSingleton()->GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
						m_arrRuler.Add(m_pRuler);
						m_pRuler->SetMeasureAction(MeasureHandler::MeasureAction::MeasureArea);
						m_nMouseLeftDown = 0;
						m_nMeasureIndex += 1;
						break;
					}
					case MeasureHeight:
					{
						m_pRuler = new MeasureHandler(RealspaceView::GetSingleton()->GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
						m_arrRuler.Add(m_pRuler);
						m_pRuler->SetMeasureAction(MeasureHandler::MeasureAction::MeasureHeight);
						m_nMouseLeftDown = 0;
						m_nMeasureIndex += 1;
						
						int nCount_Layer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();
						if (nCount_Layer3D > 0)
						{
							for (int i = 0; i < nCount_Layer3D; i++)
							{
								Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(i);
								if (pLayer->Type() == S3M)
								{
									Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer;
									if (pLayer3DS3MFile->GetHypsometricSetting() != nullptr)
									{
										m_pLayer3DS3MFile = pLayer3DS3MFile;
										break;
									}
								}
							}
						}
						
						int nCount_TerrainLayers = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count();
						if (nCount_TerrainLayers > 0)
						{
							TerrainLayers* pTerrainLayers = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers();
							if (pTerrainLayers->GetHypsometricSetting() != nullptr)
							{
								m_pTerrainLayers = pTerrainLayers;
							}
						}

						break;
					}
					case MeasureHorizontalDistance:
					{
						m_pRuler = new MeasureHandler(RealspaceView::GetSingleton()->GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
						m_arrRuler.Add(m_pRuler);
						m_pRuler->SetMeasureAction(MeasureHandler::MeasureAction::MeasureHorizontalDistance);
						m_nMouseLeftDown = 0;
						m_nMeasureIndex += 1;
						break;
					}
					case PanSelect:
					{
						for (int i = 0; i < m_arrRuler.Num(); i++)
						{
							delete m_arrRuler[i];
						}
						m_arrRuler.Empty();
						break;
					}
					case RectSelect:
					{
						m_pROEntityActor = RealspaceView::GetSingleton()->GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
						m_nMouseLeftDown = 0;
						break;
					}
					default:
						break;
				}
			}

			Action3D SceneEditorWnd::GetAction()
			{
				return m_eAction3D;
			}

			void SceneEditorWnd::OnLButtonDown()
			{
				m_enMouseDown = MB_Left;

				// 获取鼠标
				m_vStartPoint = GetMousePoint();
				switch (m_eAction3D)
				{
					case Null:
					{
						break;
					}
					case Pan:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_Down;
						break;
					}
					case PanSelect:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_Down;
						if (m_bEditSphere)
						{
							MeasureMLButtonDown();
						}
						break;
					}
					case PointSelect:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_DoubleClick;
						break;
					}
					case MeasureDistance:
					case MeasureArea:
					case MeasureHeight:
					case MeasureHorizontalDistance:
					{
						MeasureMLButtonDown();
						break;
					}
					case RectSelect:
					{
						m_nMouseLeftDown = 1;
						Gameint nLayerCount = m_pScene->GetLayer3Ds()->Count();
						for (Gameint nLayer = 0; nLayer < nLayerCount; nLayer++)
						{
							Gameint nLayerID = m_pScene->GetLayer3Ds()->GetAt(nLayer)->GetLayerID();
							m_pScene->GetQuery3D()->AddLayerID(nLayerID);
						}
						break;
					}
					default:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_Down;
						break;
					}
				}
			}

			Gamebool SceneEditorWnd::IsHitTestValid()
			{
				if (FMath::Abs(m_vStartPoint.X - m_vEndPoint.X) < 12 &&
					FMath::Abs(m_vStartPoint.Y - m_vEndPoint.Y) < 12)
				{
					return true;
				}

				return false;
			}

			Vector3d SceneEditorWnd::GetMousePoint()
			{
				Gamefloat fMouseX = 0.0, fMouseY = 0.0;
				RealspaceView::GetSingleton()->GetCameraControl()->GetMousePos(fMouseX, fMouseY);
				return Vector3d(fMouseX, fMouseY, 0.0);
			}

			void SceneEditorWnd::SetShaderParameterForSelection(Gamebool bRenderToSelectionTexture, Gamebool bRenderAlpha)
			{
				Gamefloat fRenderMode  = bRenderToSelectionTexture ? 1.0f : 0.0f;
				Gamefloat fSelectLevel = bRenderAlpha ? 1.0f : 0.0f;

				ENQUEUE_RENDER_COMMAND(FSetUseMaterial)
					([bRenderToSelectionTexture](FRHICommandListImmediate& RHICmdList) {
					FSuperMapMeshSceneProxy::SetSceneUseMaterialFlag_RenderThread((bRenderToSelectionTexture ? UseMaterialFlag::UMF_SELECTION : UseMaterialFlag::UMF_NORMAL));
						});
				FName strName = TEXT("SelectLevel");
				GameMaterialManager::GetSingleton()->SetMatFloatShareParam(strName, fSelectLevel);
			}

			void SceneEditorWnd::AddSelectedObjectIDForLayer(Gameint nLayerID, Gameint nObjectID, Gamebool isRasterObject)
			{
				if (nLayerID < 0 || nObjectID < 0)
				{
					return;
				}
				Layer3Ds* pLayers = m_pScene->GetLayer3Ds();
				for (Gameint i = 0; i < pLayers->Count(); i++)
				{
					Layer3D* pLayer = pLayers->GetAt(i);
					
					if (pLayer->GetLayerID() == nLayerID)
					{
						if (pLayer->GetSelection3D() != nullptr)
						{
							m_bUpdateSelectedInfo = true;
							m_nSelectedLayerID = nLayerID;
							m_AttributeSelectEvent.m_pSelectLayerHandle = pLayer;
							m_AttributeSelectEvent.m_nSelectID = nObjectID;
							if (pLayer->GetSelection3D()->FindID(nObjectID))
							{
								return;
							}
							if (m_nSelectMode == Blend_VertexColor || isRasterObject)
							{
								pLayer->ReleaseSelection();
								pLayer->AddSelectedID(nObjectID);
							}
						}
					}
				}
			}

			void SceneEditorWnd::ReleaseSelection()
			{
				Layer3Ds* pLayers = m_pScene->GetLayer3Ds();
				for (Gameint i = 0; i < pLayers->Count(); i++)
				{
					Layer3D* pLayer = pLayers->GetAt(i);

					if (pLayer->GetLayerID() != m_nSelectedLayerID)
					{
						pLayer->ReleaseSelection();
					}
				}
			}

			Gamebool SceneEditorWnd::IsUpdateSelectedInfo()
			{
				Gamebool bUpdateSelectedInfo = m_bUpdateSelectedInfo;
				m_bUpdateSelectedInfo = false;
				return bUpdateSelectedInfo;
			}

			void SceneEditorWnd::HitTest()
			{
				if (m_pScene->GetWorld()->WorldType == EWorldType::Editor)
				{
					return;
				}
				//==================== 获取图层ID和对象ID=========================================

				// 获取场景采集组件
				ACameraActor* pCamera = RealspaceView::GetSingleton()->GetMainCameraActor();
				USceneCaptureComponent2D* pSceneCaptureCompone2D = (USceneCaptureComponent2D*)pCamera->GetRootComponent()->GetChildComponent(1);
				if (pSceneCaptureCompone2D == NULL)
				{
					return;
				}

				// 获取鼠标
				Vector3d vMousePoint = GetMousePoint();
				Gameint nCameraWidth = RealspaceView::GetSingleton()->GetCameraControl()->m_nScreenWidth;
				Gameint nCameraHeight = RealspaceView::GetSingleton()->GetCameraControl()->m_nScreenHeight;

				if (m_pScene->GetMultiViewportMode() == Horizontal)
				{
					if (vMousePoint.X > nCameraWidth)
					{
						vMousePoint.X -= nCameraWidth;
					}

					vMousePoint.X = vMousePoint.X + nCameraWidth / 2;
					nCameraWidth *= 2;
				}

				if (vMousePoint.X < 0 || vMousePoint.Y < 0)
				{
					return;
				}

				SetShaderParameterForSelection(true, false);

				// 创建渲染纹理
				UTextureRenderTarget2D* pTextureRenderTarget2D = NewObject<UTextureRenderTarget2D>();
#if PLATFORM_LINUX
				pTextureRenderTarget2D->RenderTargetFormat = RTF_RGBA16f;
#else
				pTextureRenderTarget2D->RenderTargetFormat = RTF_RGBA32f;
#endif
				pTextureRenderTarget2D->InitCustomFormat(nCameraWidth, nCameraHeight, EPixelFormat::PF_FloatRGBA, false);
				pSceneCaptureCompone2D->TextureTarget = pTextureRenderTarget2D;

				pSceneCaptureCompone2D->CaptureScene();

				FTextureRenderTargetResource* pRTResource = pTextureRenderTarget2D->GameThread_GetRenderTargetResource();

				FReadSurfaceDataFlags rsdf;
				rsdf.SetLinearToGamma(false);
				Gameint nSize = nCameraWidth * nCameraHeight;
#if PLATFORM_LINUX
				TArray<FFloat16Color> arrOutBMP;
				arrOutBMP.AddUninitialized(nSize);
				pRTResource->ReadFloat16Pixels(arrOutBMP);
#else
				TArray<FLinearColor> arrOutBMP;
				arrOutBMP.AddUninitialized((4 < nSize ? 4 : nSize));

				FIntRect readRect(vMousePoint.X, vMousePoint.Y, vMousePoint.X+1, vMousePoint.Y+1);
				pRTResource->ReadLinearColorPixels(arrOutBMP, rsdf, readRect);
#endif
				Gameuint nIndex = 0;
				Gamefloat fR = arrOutBMP[nIndex].R;
				Gamefloat fG = arrOutBMP[nIndex].G;
				Gamefloat fB = arrOutBMP[nIndex].B;
				Gamefloat fA = arrOutBMP[nIndex].A;

				SetShaderParameterForSelection(true, true);
				pSceneCaptureCompone2D->CaptureScene();

#if PLATFORM_LINUX
				TArray<FFloat16Color> arrOutBMP1;
				arrOutBMP1.AddUninitialized(nSize);
				pRTResource->ReadFloat16Pixels(arrOutBMP1);
#else
				TArray<FLinearColor> arrOutBMP1;
				arrOutBMP1.AddUninitialized((4 < nSize ? 4 : nSize));
				pRTResource->ReadLinearColorPixels(arrOutBMP1, rsdf, readRect);
#endif

				fA = arrOutBMP1[nIndex].R;

				Gameuint nID = 0;
				_RGBAID(fR, fG, fB, fA, nID);

				Gameint nSelectID = -1;
				Gameint nSelectLayerID = -1;
				_RGBAObjectID(fR, fG, fB, fA, nSelectID, nSelectLayerID);
				//===================================================================
				
				AddSelectedObjectIDForLayer(nSelectLayerID , nSelectID, false);

				pTextureRenderTarget2D->MarkPendingKill();
				pTextureRenderTarget2D = nullptr;

				SetShaderParameterForSelection(false, false);

				FName strName = TEXT("SelectID");
				GameMaterialManager::GetSingleton()->SetMatVector4dShareParam(strName, FLinearColor(fR, fG,fB,fA));
			}

			void SceneEditorWnd::HitTestRasterObject()
			{
				//得到鼠标单击经纬度位置
				Vector3d pos = m_pScene->PixelToGlobe(m_vEndPoint);
				if (CameraControl::m_eSceneType == UGC_PLANE)
				{
					pos *= CM_TO_M;
				}
				//获取到地形切片的 地理范围
				Gamedouble left;
				Gamedouble bottom;
				Gamedouble right;
				Gamedouble top;

				if (_Scene_GetTileBounds(m_pScene->GetHandler(), pos.X, pos.Y, left, bottom, right, top))
				{
					// 创建渲染纹理
					UTextureRenderTarget2D* pTextureRenderTarget2D = NewObject<UTextureRenderTarget2D>();
#if PLATFORM_LINUX
					pTextureRenderTarget2D->RenderTargetFormat = RTF_RGBA16f;
#else
					pTextureRenderTarget2D->RenderTargetFormat = RTF_RGBA32f;
#endif
					pTextureRenderTarget2D->InitAutoFormat(256, 256);
					pTextureRenderTarget2D->AddToRoot();

					//栅格化矢量
					FVector4 transform(pos.X, pos.Y, right - left, top - bottom);

					GameRenderTextureManager::GetSingleton()->RealtimeRasterVector(pTextureRenderTarget2D, transform, true);

					//获取像素

					FTextureRenderTargetResource* pRTResource = pTextureRenderTarget2D->GameThread_GetRenderTargetResource();

					FReadSurfaceDataFlags rsdf;
					rsdf.SetLinearToGamma(false);
#if PLATFORM_LINUX
					TArray<FFloat16Color> arrOutBMP;
					arrOutBMP.AddUninitialized(256 * 256);
					pRTResource->ReadFloat16Pixels(arrOutBMP);
#else
					TArray<FLinearColor> arrOutBMP;
					arrOutBMP.AddUninitialized(256 * 256);
					pRTResource->ReadLinearColorPixels(arrOutBMP, rsdf);

#endif

					Gameuint nIndex = 256 * 128 + 128;

					Gamefloat fR = arrOutBMP[nIndex].R;
					Gamefloat fG = arrOutBMP[nIndex].G;
					Gamefloat fB = arrOutBMP[nIndex].B;
					Gamefloat fA = arrOutBMP[nIndex].A;

					Gameint nSelectID = -1;
					Gameint nSelectLayerID = -1;
					_RGBAObjectID(fR, fG, fB, fA, nSelectID, nSelectLayerID);

					AddSelectedObjectIDForLayer(nSelectLayerID, nSelectID, true);

					if (pTextureRenderTarget2D != nullptr)
					{
						pTextureRenderTarget2D->RemoveFromRoot();
						pTextureRenderTarget2D = nullptr;
					}
				}
			}

			void SceneEditorWnd::OnLButtonUp()
			{
				m_enMouseDown = MB_None;
				m_vEndPoint = GetMousePoint();
				
				switch (m_eAction3D)
				{
					case Null:
					{
						break;
					}
					case Pan:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_Up;
						break;
					}
					case PanSelect:
					case PointSelect:
					{
						if (IsHitTestValid())
						{
							if (m_eUserAction == UserAction::SubObjectSelect)
							{
								m_SelectedEventInfos.m_struDatasetModelInfo = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSelectedInfo();
								m_pMatInstanceDynamic = m_SelectedEventInfos.m_struDatasetModelInfo.m_pMatInstanceDynamic;
								m_SelectedEventInfos.m_SelectedInfoEvent(m_SelectedEventInfos.m_pActor, m_SelectedEventInfos.m_struDatasetModelInfo);
							}
							m_bUpdateSelectedInfo = false;
							m_nSelectedLayerID = -1;
							m_AttributeSelectEvent.m_pSelectLayerHandle = nullptr;
							m_AttributeSelectEvent.m_nSelectID = -1;
							HitTest();

							if (!m_bUpdateSelectedInfo)
							{//正常场景选择失败,选择贴地矢量
								HitTestRasterObject();
							}
							ReleaseSelection();

							m_AttributeSelectEvent.Execute();
						}

						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_Up;
						RealspaceView::GetSingleton()->GetCameraControl()->m_vMouseStartPoint = FVector(-1, -1, -1);
						break;
					}
					case RectSelect:
					{
						m_pScene->GetQuery3D()->SetPickRect(m_vStartPoint, m_vEndPoint);
						m_pScene->GetQuery3D()->UpdateRectSelect();
						m_nMouseLeftDown = 0;
						m_pROEntityActor->ClearMesh();
						break;
					}
					default:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_Up;
						RealspaceView::GetSingleton()->GetCameraControl()->m_vMouseStartPoint = FVector(-1, -1, -1);
						break;
					}
				}
			}

			void SceneEditorWnd::OnLButtonDblClk()
			{
				switch (m_eAction3D)
				{
					case Null:
					{
						break;
					}
					case Pan:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_Down;//位移
						break;
					}
					case PanSelect:
					case PointSelect:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_DoubleClick;
						RealspaceView::GetSingleton()->GetCameraControl()->m_vMouseStartPoint = FVector(-1, -1, -1);
						break;
					}
					case MeasureDistance:
					case MeasureArea:
					case MeasureHeight:
					case MeasureHorizontalDistance:
					{
						MeasureMLButtonDown();
						break;
					}
					default:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Left_DoubleClick;
						RealspaceView::GetSingleton()->GetCameraControl()->m_vMouseStartPoint = FVector(-1, -1, -1);
						break;
					}
				}
			}

			void SceneEditorWnd::OnRButtonDown()
			{
				switch (m_eAction3D)
				{
					case Null:
					{
						break;
					}
					case Pan:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Right_Down;
						break;
					}
					case PanSelect:
					case PointSelect:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Right_Down;
						break;
					}
					case MeasureDistance:
					case MeasureArea:
					case MeasureHeight:
					case MeasureHorizontalDistance:
					{
						if (m_nMouseLeftDown > 0)
						{
							MeasureMRButtonDown();
							m_nMouseLeftDown = 0;
							m_eAction3D = PanSelect;
						}
						break;
					}
					case RectSelect:
					{
						SetAction(PanSelect);
						break;
					}
					default:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Right_Down;
						break;
					}
				}
			}

			void SceneEditorWnd::OnRButtonUp()
			{
				switch (m_eAction3D)
				{
					case Null:
					{
						break;
					}
					case Pan:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Right_Up;
						break;
					}
					case PanSelect:
					case PointSelect:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Right_Up;
						break;
					}
					default:
					{
						RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Right_Up;
						break;
					}
				}
			}

			void SceneEditorWnd::OnMButtonDown()
			{
				RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Middle_Down;
			}

			void SceneEditorWnd::OnMButtonUp()
			{
				RealspaceView::GetSingleton()->GetCameraControl()->m_eCamMouseBtnState = MouseBtn_Middle_Up;
			}

			void SceneEditorWnd::OnMouseWheel(float Value)
			{
				if (CameraControl::m_eSceneType == UGC_PLANE)
				{
					RealspaceView::GetSingleton()->GetCameraControl()->m_fScrollFactor = Value * 100.0f * 4.0f;
				}
				else
				{
					RealspaceView::GetSingleton()->GetCameraControl()->m_fScrollFactor = Value;
				}
			}

			void SceneEditorWnd::OnMouseMove()
			{
				FVector vMouse = FVector::ZeroVector;
				RealspaceView::GetSingleton()->GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
				if (m_vMouse == vMouse || vMouse.IsNearlyZero())
				{
					return;
				}
				m_vMouse = vMouse;
				switch (m_eAction3D)
				{
					case MeasureDistance:
					case MeasureArea:
					case MeasureHeight:
					case MeasureHorizontalDistance:
					{
						MeasureMMove(m_vMouse);
						break;
					}
					case PanSelect:
					{
						if (m_pRuler != nullptr)
						{
							MeasureMMove(m_vMouse);
						}
						break;
					}
					case RectSelect:
					{
						if (m_nMouseLeftDown == 1)
						{
							RectSelectDrawFace();
						}
						break;
					}
					default:
						break;
				}					
			}

			void SceneEditorWnd::MeasureMLButtonDown()
			{
				if (m_pRuler == nullptr)
				{
					return;
				}
				FVector vMouse;
				RealspaceView::GetSingleton()->GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
				Vector3d vPos;
				if (CameraControl::m_eSceneType == UGC_PLANE)
				{
					vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
				}
				else if (CameraControl::m_eSceneType == UGC_EARTH ||
					     CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
				}
				if (!m_bErrorPosition)
				{
					m_vRealPosition = vPos;
				}
				if (!m_pRuler->GetHandlerStop())
				{
					m_nMouseLeftDown++;
					if (m_pRuler->GetMeasureAction() != MeasureHandler::MeasureHeight)
					{
						m_pRuler->AddTargetPoint(m_vRealPosition);
						m_pRuler->UpdateMeasure();
					}
					else
					{
						if (m_nMouseLeftDown <= 2)
						{
							m_pRuler->AddTargetPoint(m_vRealPosition);
							m_pRuler->UpdateMeasure();
							if (m_nMouseLeftDown == 2)
							{
								if (!m_pRuler->GetHandlerStop())
								{
									m_pRuler->RemoveTargetPoint(m_pRuler->GetTargetPointCount() - 1);
									m_pRuler->SetHandlerStop(true);
									SpawnMeasureSphere();
									m_eAction3D = PanSelect;
									m_bEditSphere = true;
									m_bErrorPosition = false;
								}
								//等高线	
								if (m_pLayer3DS3MFile != nullptr)
								{
									MeasureReferenceLine(m_vRealPosition);
								}
								else if (m_pTerrainLayers != nullptr)
								{
									MeasureReferenceLine(m_vRealPosition);
								}
							}
						}
					}
				}			
				if (m_pRuler->GetHandlerStop() && m_bEditSphere && m_eAction3D == PanSelect)
				{
					if (m_bSelectSphere)
					{
						m_arrRuler[m_nSphereMeasureIndex]->SetTargetPoint(m_nOldIndex, vPos);
						m_arrRuler[m_nSphereMeasureIndex]->UpdateMeasure();
						if (m_arrRuler[m_nSphereMeasureIndex]->GetMeasureAction() == MeasureHandler::MeasureArea)
						{
							m_arrRuler[m_nSphereMeasureIndex]->UpdateMeasureArea();
						}
						if (m_arrRuler[m_nSphereMeasureIndex]->GetMeasureAction() == MeasureHandler::MeasureHeight)
						{
							if (m_nOldIndex != 0)
							{
								if (m_pLayer3DS3MFile != nullptr)
								{
									MeasureReferenceLine(m_vRealPosition);
								}
								else if (m_pTerrainLayers != nullptr)
								{
									MeasureReferenceLine(m_vRealPosition);
								}
							}
							else
							{
								if (m_pLayer3DS3MFile != nullptr)
								{
									MeasureReferenceLine(Vector3d(m_arrRuler[m_nSphereMeasureIndex]->GetTargetPoint(1)));
								}
								else if (m_pTerrainLayers != nullptr)
								{
									MeasureReferenceLine(Vector3d(m_arrRuler[m_nSphereMeasureIndex]->GetTargetPoint(1)));
								}
							}
						}
						int count = 0;
						for (Gameint i = 0; i < m_nSphereMeasureIndex; i++)
						{
							count += m_arrRuler[i]->GetTargetPointCount();
						}
						arrRefSphereActor[m_nOldIndex + count]->SetActorLocation(vPos.ToFVector());
						m_bSelectSphere = false;
					}
					else
					{
						FHitResult hitResult;
						Gamebool bHit = false;

						FVector vLocation;
						FVector vDirection;

						if (RealspaceView::GetSingleton()->GetWorld()->GetFirstPlayerController()->DeprojectScreenPositionToWorld(vMouse.X, vMouse.Y, vLocation, vDirection))
						{
							FVector vEnd = vLocation + (vDirection * 1000000000000.0);
							bHit = RealspaceView::GetSingleton()->GetWorld()->LineTraceSingleByChannel(hitResult, vLocation, vEnd, ECC_Visibility);
						}
						if (bHit)
						{
							ASuperMap_SphereActor* hitActor = Cast<ASuperMap_SphereActor>(hitResult.GetActor());
							if (hitActor != nullptr)
							{
								if (hitActor->GetSphereType() == ESuperMap_Sphere::Point_Measure)
								{
									m_nOldIndex = hitActor->GetSphereIndex();
									m_nSphereMeasureIndex = hitActor->GetSphereMeasureIndex();
									m_bSelectSphere = true;
								}
							}
						}
					}
				}
			}

			void SceneEditorWnd::MeasureMRButtonDown()
			{
				if (m_pRuler == nullptr)
				{
					return;
				}
				if (!m_pRuler->GetHandlerStop())
				{
					m_pRuler->RemoveTargetPoint(m_pRuler->GetTargetPointCount() - 1);
					m_pRuler->SetHandlerStop(true);
					if (m_pRuler->GetMeasureAction() == MeasureHandler::MeasureArea)
					{
						m_pRuler->MeasureAreaEnd();
					}
					m_pRuler->UpdateMeasure();
					SpawnMeasureSphere();
					m_bEditSphere = true;
					m_eAction3D = PanSelect;
					m_bErrorPosition = false;
				}
			}

			void SceneEditorWnd::MeasureMMove(FVector vMouse)
			{
				if (m_pRuler == nullptr || m_nMouseLeftDown <= 0)
				{
					return;
				}
				Vector3d vPos;

				vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);

				if (m_vRealPosition.Distance(vPos) < 100000000)
				{
					m_vRealPosition = vPos;
					m_bErrorPosition = true;

				}
				if (!m_pRuler->GetHandlerStop())
				{
					int nCount = m_pRuler->GetTargetPointCount();
					if (nCount <= m_nMouseLeftDown)
					{
						m_pRuler->AddTargetPoint(m_vRealPosition);
					}
					if (nCount > 0)
					{
						m_pRuler->SetTargetPoint(nCount - 1, m_vRealPosition);
					}

					m_pRuler->UpdateMeasure();

					//等高线
					if (m_nMouseLeftDown == 1 && m_pLayer3DS3MFile != nullptr && m_pRuler->GetMeasureAction() == MeasureHandler::MeasureHeight)
					{
						MeasureReferenceLine(m_vRealPosition);
					}

					//等高线
					else if (m_nMouseLeftDown == 1 && m_pTerrainLayers != nullptr && m_pRuler->GetMeasureAction() == MeasureHandler::MeasureHeight)
					{
						MeasureReferenceLine(m_vRealPosition);
					}
				}
				if (m_pRuler->GetHandlerStop() && m_bSelectSphere && m_eAction3D == PanSelect)
				{
					m_arrRuler[m_nSphereMeasureIndex]->SetTargetPoint(m_nOldIndex, vPos);
					m_arrRuler[m_nSphereMeasureIndex]->UpdateMeasure();
					if (m_arrRuler[m_nSphereMeasureIndex]->GetMeasureAction() == MeasureHandler::MeasureArea)
					{
						m_arrRuler[m_nSphereMeasureIndex]->UpdateMeasureArea();
					}
					if (m_arrRuler[m_nSphereMeasureIndex]->GetMeasureAction() == MeasureHandler::MeasureHeight)
					{
						if (m_nOldIndex != 0)
						{
							if (m_pLayer3DS3MFile != nullptr)
							{
								MeasureReferenceLine(m_vRealPosition);
							}
							else if (m_pTerrainLayers != nullptr)
							{
								MeasureReferenceLine(m_vRealPosition);
							}
						}
						else
						{
							if (m_pLayer3DS3MFile != nullptr)
							{
								MeasureReferenceLine(Vector3d(m_arrRuler[m_nSphereMeasureIndex]->GetTargetPoint(1)));
							}
							else if (m_pTerrainLayers != nullptr)
							{
								MeasureReferenceLine(Vector3d(m_arrRuler[m_nSphereMeasureIndex]->GetTargetPoint(1)));
							}
						}
					}
					int count = 0;
					for (Gameint i = 0; i < m_nSphereMeasureIndex; i++)
					{
						count += m_arrRuler[i]->GetTargetPointCount();
					}
					arrRefSphereActor[m_nOldIndex + count]->SetActorLocation(vPos.ToFVector());
				}
			}

			MeasureHandler* SceneEditorWnd::GetMeasureHandler()
			{
				return m_pRuler;
			}

			void SceneEditorWnd::MeasureReferenceLine(Vector3d vPos)
			{
				Gamedouble dHeight = -1;
				if (ROCacheManager::m_eSceneType == SceneType::Flat)
				{
					dHeight = m_vRealPosition.Z;
				}
				else
				{
					Vector3d vNewPos = Georeference::TransformUERelativeToGeorefenceECEF(vPos).ToFVector();
					float fNewPosDis;
					FVector vNewPosDir;
					FVector vFNewPos = vNewPos.ToFVector();
					vFNewPos.ToDirectionAndLength(vNewPosDir, fNewPosDis);
					vNewPosDir *= -1;
					Vector3d vIntersect3d;
					Gamebool bIsHit = MathEngine::RayIntersectionWithGlobe(vNewPos, vNewPosDir, vIntersect3d, SceneType(CameraControl::m_eSceneType), 6378137.0f);
					dHeight = vNewPos.Distance(vIntersect3d);
					dHeight *= M_TO_CM;
				}
				HypsometricSetting* pHypsometricSetting = new HypsometricSetting();
				pHypsometricSetting->SetMaxVisibleValue(dHeight);
				pHypsometricSetting->SetAnalysisMode(AM_GUIDES);
				pHypsometricSetting->SetDisplayMode(Line);
				if (m_pLayer3DS3MFile != nullptr)
				{
					m_pLayer3DS3MFile->SetHypsometricSetting(pHypsometricSetting);
				}
				else if (m_pTerrainLayers != nullptr)
				{
					m_pTerrainLayers->SetHypsometricSetting(pHypsometricSetting);
				}

				delete pHypsometricSetting;
				pHypsometricSetting = nullptr;
			}

			void SceneEditorWnd::SpawnMeasureSphere()
			{
				for (Gameint i = 0; i < m_arrRuler[m_nMeasureIndex]->GetTargetPointCount(); i++)
				{
					ASuperMap_SphereActor* ASphere = RealspaceView::GetSingleton()->GetWorld()->SpawnActor<ASuperMap_SphereActor>();
					ASphere->InitSphere(FRotator(0, 0, 0), m_arrRuler[m_nMeasureIndex]->GetTargetPoint(i), FVector(3.f));
					ASphere->SetSphereType(ESuperMap_Sphere::Point_Measure);
					ASphere->SetSphereIndex(i);
					ASphere->SetSphereMeasureIndex(m_nMeasureIndex);
					arrRefSphereActor.Add(ASphere);
				}
			}

			void SceneEditorWnd::ClearMeasureSphere()
			{
				for (Gameint i = 0; i < arrRefSphereActor.Num(); i++)
				{
					arrRefSphereActor[i]->Destroy();
					arrRefSphereActor[i]->m_pSphereMesh = nullptr;
				}
				arrRefSphereActor.Empty();
			}

			void SceneEditorWnd::RectSelectDrawFace()
			{
				m_pROEntityActor->ClearMesh();
				Vector3d vMouse = GetMousePoint();
				Vector3d vMouse1 = Vector3d(vMouse.X, m_vStartPoint.Y, 0);
				Vector3d vMouse2 = Vector3d(m_vStartPoint.X, vMouse.Y, 0);
				Vector3d vPos1 = m_pScene->PixelToCartesian(m_vStartPoint);
				Vector3d vPos2 = m_pScene->PixelToCartesian(vMouse1);
				Vector3d vPos3 = m_pScene->PixelToCartesian(vMouse);
				Vector3d vPos4 = m_pScene->PixelToCartesian(vMouse2);

				TArray<SM_Vertex> arrVtxs;
				TArray<Gameint> arrIndexs;
				//顶点
				SM_Vertex vertex1;
				vertex1.Position = vPos1.ToFVector();
				vertex1.Color = FColor::Green;
				arrVtxs.Add(vertex1);
				SM_Vertex vertex2;
				vertex2.Position = vPos2.ToFVector();
				vertex2.Color = FColor::Green;
				arrVtxs.Add(vertex2);
				SM_Vertex vertex3;
				vertex3.Position = vPos3.ToFVector();
				vertex3.Color = FColor::Green;
				arrVtxs.Add(vertex3);
				SM_Vertex vertex4;
				vertex4.Position = vPos4.ToFVector();
				vertex4.Color = FColor::Green;
				arrVtxs.Add(vertex4);
				//索引
				arrIndexs.Add(0);
				arrIndexs.Add(1);
				arrIndexs.Add(1);
				arrIndexs.Add(2);
				arrIndexs.Add(2);
				arrIndexs.Add(3);
				arrIndexs.Add(3);
				arrIndexs.Add(0);

				//mesh
				TArray<SM_SubMesh> arrSubMeshs;
				SM_SubMesh subMesh;
				if (m_pROEntityActor->GetMaterial() == nullptr)
				{
					static UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
					UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
					subMesh.m_pMaterialInterface = pMat;
				}
				subMesh.IndexBuffer = arrIndexs;
				arrSubMeshs.Add(subMesh);
				m_pROEntityActor->SetDrawType(2);//0三角、2线
				m_pROEntityActor->CreateProceduralMesh(arrVtxs, arrSubMeshs);
			}

			void SceneEditorWnd::SetSelectedInfoEventFunc(void* pActor, SelectedInfoEvent infoEvent)
			{
				m_SelectedEventInfos.m_SelectedInfoEvent = infoEvent;
				m_SelectedEventInfos.m_pActor = pActor;
			}

			void SceneEditorWnd::SetUserAction(UserAction eAction)
			{
				m_eUserAction = eAction;
				//if (m_pMatInstanceDynamic != nullptr)
				//{
				//	m_pMatInstanceDynamic->SetVectorParameterValue(TEXT("SubSelectedColor"), FLinearColor(1, 1, 1, 1));
				//	m_pMatInstanceDynamic = nullptr;
				//}
			}

			void SceneEditorWnd::CallFunc_AttributeQuery(void* pActor, AttributeSelectEvent QAEvent)
			{
				m_AttributeSelectEvent.m_pActor = pActor;
				m_AttributeSelectEvent.Event = QAEvent;
			}
		}
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif