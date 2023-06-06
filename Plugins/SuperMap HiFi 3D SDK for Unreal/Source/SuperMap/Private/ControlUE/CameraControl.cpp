#include "ControlUE/CameraControl.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Engine/GameViewportClient.h"
#include "Engine/Public/SceneView.h"
#include "Engine/LocalPlayer.h"
#include "Base3D/CommonDefine.h"
#include "Camera/CameraActor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Camera/CameraComponent.h"
#include "Data/Matrix4d.h"
#include "Core/Georeference.h"
#include "ControlUE/RealspaceView.h"
#include "Algorithm3D/MathEngine.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{ 
		namespace ControlUE
		{
			UGCSceneType CameraControl::m_eSceneType = UGC_EARTH;

			const float fDepthTextureWidth = 32;

			CameraControl::CameraControl()
			{
				m_eCamMouseBtnState = MouseBtn_Nothing;
				m_eCameraState = None;
				m_eEditMode = NORMAL;

				m_nScreenWidth = 0;
				m_nScreenHeight = 0;

				m_fScrollFactor = 0;

				m_pCurrentPlayerControl = nullptr;

				m_vMouseStartPoint = FVector(0.0, 0.0, 0.0);
				m_vMouseEndPoint = FVector(0.0, 0.0, 0.0);
				m_vMouseAnchor = FVector(0.0, 0.0, 0.0);
				m_vMouseAnchorNoWorldOrginOffset = FVector(0.0, 0.0, 0.0);

				m_vecWorldOrigin = FIntVector(0, 0, 0);
				m_vecWorldOriginForRotate = FIntVector(0, 0, 0);
				m_vAnchorStart = FVector(0.0, 0.0, 0.0);
				m_vAnchorEnd = FVector(0.0, 0.0, 0.0);
				m_fOpCenterTile = 0.0f;
				m_dFov = 60;
				m_pDepthRenderTarget = nullptr;
			}

			CameraControl::~CameraControl()
			{
				if (m_pDepthRenderTarget != nullptr)
				{
					m_pDepthRenderTarget->RemoveFromRoot();
				}

			}

			void  CameraControl::SetEditMode(CMEditMode eEditMode)
			{
				m_eEditMode = eEditMode;
			}

			CMEditMode CameraControl::GetEditMode()
			{
				return m_eEditMode;
			}

			Vector3d CameraControl::GetLocalWorldPosition(Gameint nMouseX, Gameint nMouseY, Gamebool bUseDepth)
			{
				if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetMultiViewportMode() == Horizontal && nMouseX > m_nScreenWidth)
				{
					nMouseX -= m_nScreenWidth;
				}

				FVector vMouse = FVector(nMouseX, nMouseY, 0);
				Vector3d vWorldPosition;
#if PLATFORM_LINUX
				bUseDepth = false;
#endif
				if (!bUseDepth)
				{
					// 方向
					FVector vLocation;
					FVector vDirection;
					MouseToWorld(vMouse, vLocation, vDirection);
					vLocation = Georeference::TransformUERelativeToGeorefenceECEF(Vector3d(vLocation)).ToFVector();
					//vDirection *= CM_TO_M;

					// 求与球的交点
					SuperMapSDK::UnrealEngine::Core::_RayIntersectionWithSphere(vLocation.X, vLocation.Y, vLocation.Z,
						vDirection.X, vDirection.Y, vDirection.Z, vWorldPosition.X, vWorldPosition.Y, vWorldPosition.Z);
					vWorldPosition *= M_TO_CM;
					vWorldPosition -= Vector3d(MathEngine::m_vWorldOffset);
					return vWorldPosition;
				}

				GetWorldPositionByDepth(vMouse, vWorldPosition);

				if (!m_bHit)
				{
					return Vector3d(0.0f, 0.0f, 0.0f);
				}

				Vector3d vPos = vWorldPosition;
				vPos += Vector3d(CameraControl::m_vecWorldOrigin);
				return vPos;
			}

			void CameraControl::RenderToDepthTexture(CaptureDepthTexParm captureDepthTexParm, UTextureRenderTarget2D* pTextureRenderTarget2D)
			{
				if (m_pCameraActor == nullptr)
				{
					return;
				}

				uint32 textureWidth = captureDepthTexParm.m_textureWidth;
				uint32 textureHeight = captureDepthTexParm.m_textureHeight;

				FVector vOriCameraLocation;
				FRotator rOriCameraRotation;
				GetCameraLocationAndRotation(vOriCameraLocation, rOriCameraRotation);
				m_pCameraActor->SetActorLocationAndRotation(captureDepthTexParm.m_vCameraLocation, captureDepthTexParm.m_rCameraRotation);

				// 获取场景采集组件
				USceneCaptureComponent2D* pSceneCaptureCompone2D = (USceneCaptureComponent2D*)m_pCameraActor->GetRootComponent()->GetChildComponent(1);
				if (pSceneCaptureCompone2D == NULL)
				{
					return;
				}

				TEnumAsByte<enum ESceneCaptureSource> eTemp = pSceneCaptureCompone2D->CaptureSource;
				pSceneCaptureCompone2D->CaptureSource = SCS_DeviceDepth;
				pSceneCaptureCompone2D->CompositeMode = ESceneCaptureCompositeMode::SCCM_Overwrite;

				UCameraComponent* pCameraComponent = m_pCameraActor->GetCameraComponent();
				if (pCameraComponent == NULL)
				{
					return;
				}

				pSceneCaptureCompone2D->TextureTarget = pTextureRenderTarget2D;
				pSceneCaptureCompone2D->bUseCustomProjectionMatrix = true;
				pSceneCaptureCompone2D->CustomProjectionMatrix = captureDepthTexParm.m_projMatrix;
				pSceneCaptureCompone2D->CaptureScene();

				pSceneCaptureCompone2D->CaptureSource = eTemp;
				pSceneCaptureCompone2D->bUseCustomProjectionMatrix = false;

				m_pCameraActor->SetActorLocationAndRotation(vOriCameraLocation, rOriCameraRotation);
			}


#if PLATFORM_LINUX
			void CameraControl::GetDepthTexture(CaptureDepthTexParm captureDepthTexParm, TArray<FFloat16Color>& arrDepthBuffer)
#else
			void CameraControl::GetDepthTexture(CaptureDepthTexParm captureDepthTexParm, TArray<FLinearColor>& arrDepthBuffer)
#endif
			{
				if (m_pCameraActor == nullptr)
				{
					return;
				}

				uint32 textureWidth = captureDepthTexParm.m_textureWidth;
				uint32 textureHeight = captureDepthTexParm.m_textureHeight;

				// 创建渲染纹理
				UTextureRenderTarget2D* pTextureRenderTarget2D = NewObject<UTextureRenderTarget2D>();
#if PLATFORM_LINUX
				pTextureRenderTarget2D->RenderTargetFormat = RTF_RGBA16f;
#else
				pTextureRenderTarget2D->RenderTargetFormat = RTF_RGBA32f;
#endif
				pTextureRenderTarget2D->Filter = TF_Nearest;
				pTextureRenderTarget2D->ClearColor = FLinearColor::Black;
				pTextureRenderTarget2D->InitAutoFormat(textureWidth, textureHeight);

				RenderToDepthTexture(captureDepthTexParm, pTextureRenderTarget2D);

				FTextureRenderTargetResource* pRTResource = pTextureRenderTarget2D->GameThread_GetRenderTargetResource();
				arrDepthBuffer.AddUninitialized(textureWidth * textureHeight);

				FReadSurfaceDataFlags rsdf(RCM_MinMax, CubeFace_MAX);
				rsdf.SetLinearToGamma(false);
#if PLATFORM_LINUX
				pRTResource->ReadFloat16Pixels(arrDepthBuffer);
#else
				pRTResource->ReadLinearColorPixels(arrDepthBuffer, rsdf);
#endif
				pTextureRenderTarget2D->MarkPendingKill();
				pTextureRenderTarget2D = nullptr;
			}

			bool CameraControl::GetWorldPositionByDepth(FVector vMouse, Vector3d& vWorldPosition)
			{
				if (m_pCameraActor == nullptr)
				{
					return false;
				}

				// 获取鼠标
				float xMouse = vMouse.X;
				float yMouse = vMouse.Y;

				if (xMouse < 0 || yMouse < 0)
				{
					return false;
				}

				// 获取场景采集组件
				USceneCaptureComponent2D* pSceneCaptureCompone2D = (USceneCaptureComponent2D*)m_pCameraActor->GetRootComponent()->GetChildComponent(1);
				if (pSceneCaptureCompone2D == NULL)
				{
					return false;
				}

				// 设置捕捉设备深度
				TEnumAsByte<enum ESceneCaptureSource> eTemp = pSceneCaptureCompone2D->CaptureSource;
				pSceneCaptureCompone2D->CaptureSource = SCS_DeviceDepth;
				pSceneCaptureCompone2D->CompositeMode = ESceneCaptureCompositeMode::SCCM_Overwrite;

				UCameraComponent* pCameraComponent = m_pCameraActor->GetCameraComponent();
				if (pCameraComponent == NULL)
				{
					return false;
				}

				FVector vCameraLocation;
				FRotator rCameraRotation;
				GetCameraLocationAndRotation(vCameraLocation, rCameraRotation);

				// 获取主相机参数
				FMinimalViewInfo viewInfo;
				pCameraComponent->GetCameraView(0, viewInfo);

				// 自定义投影矩阵
				float halfFov = viewInfo.FOV * (float)PI / 360.0f;

				// 这个地方先做一次射线求交估算范围
				FVector vLocation;
				FVector vDirection;
				FVector vCamerationDirection_normal = rCameraRotation.Vector();

				FVector vMousex = vMouse;
				if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetMultiViewportMode() == Horizontal && m_eSceneType == UGC_PLANE)
				{
					vMousex.X *= 2;
				}
				MouseToWorld(vMousex, vLocation, vDirection);

				FHitResult hitResult;
				bool bHit = false;
				FVector hitResultSphere;
				Gamefloat fDistance = 0.0f;
				Gamefloat fFarDist = 1000000.0f;
				Gamefloat fNearDist = 1000.0f;

				// 射线求交成功后开启此功能
				FRotator rDirection_normal = rCameraRotation;
				if (m_eSceneType == UGC_PLANE)
				{
					// 终点
					FVector vEnd = vLocation + (vDirection * 1000000000000.0f);
					bHit = m_pWorld->LineTraceSingleByChannel(hitResult, vLocation, vEnd, ECC_Visibility);
					if (bHit)
					{
						USuperMap_MeshComponent* pMeshComponent = (USuperMap_MeshComponent*)hitResult.GetComponent();

						if (pMeshComponent != nullptr && !pMeshComponent->GetVisibleInViewport(0))
						{
							vWorldPosition = hitResult.ImpactPoint;
							return true;
						}
					
					}
				}
				else if (m_eSceneType == UGC_EARTH || m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					vDirection.Normalize();
					TransformUERelativeToECEF(vLocation, vDirection);
					Vector3d vLocationSphere = Vector3d(vLocation);
					FVector vDirectionSphere = vDirection;
					Vector3d vResult;
					MathEngine::RayIntersectionWithGlobe(vLocationSphere, vDirectionSphere, vResult, SceneType(CameraControl::m_eSceneType), 6378137.0f);
					hitResultSphere = vResult.ToFVector();
					TransformECEFToUERelative(hitResultSphere, vDirectionSphere);
					bHit = true;
				}
				if (bHit)
				{
					if (m_eSceneType == UGC_EARTH || m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						fDistance = FVector::Distance(vCameraLocation, hitResultSphere);
					}
					else
					{
						fDistance = FVector::Distance(vCameraLocation, hitResult.ImpactPoint);
					}
					fNearDist = fDistance - 10000000.0f;
					fNearDist = fNearDist > 100.0f ? fNearDist : 100.0f;
					fFarDist = fDistance + 1000000.0f;
				}

				int32 nScreenWidth = m_nScreenWidth;
				int32 nScreenHeight = m_nScreenHeight;

				// 创建渲染纹理
				if (m_pDepthRenderTarget == nullptr)
				{
					m_pDepthRenderTarget = NewObject<UTextureRenderTarget2D>();
					m_pDepthRenderTarget->AddToRoot();
#if PLATFORM_LINUX
					m_pDepthRenderTarget->RenderTargetFormat = RTF_RGBA16f;
#else
					m_pDepthRenderTarget->RenderTargetFormat = RTF_RGBA32f;
#endif
					m_pDepthRenderTarget->ClearColor = FLinearColor::Black;
					m_pDepthRenderTarget->InitAutoFormat(nScreenWidth, nScreenHeight);
				}

				if (m_pDepthRenderTarget->SizeX != nScreenWidth || 
					m_pDepthRenderTarget->SizeY != nScreenHeight)
				{
					m_pDepthRenderTarget->ResizeTarget(nScreenWidth, nScreenHeight);
				}
				
				pSceneCaptureCompone2D->TextureTarget = m_pDepthRenderTarget;

				FMatrix projectMatrix = FReversedZPerspectiveMatrix(halfFov, viewInfo.AspectRatio, 1.0, fNearDist, fFarDist);

				pSceneCaptureCompone2D->bUseCustomProjectionMatrix = true;
				pSceneCaptureCompone2D->CustomProjectionMatrix = projectMatrix;
				pSceneCaptureCompone2D->CaptureScene();

				pSceneCaptureCompone2D->CaptureSource = eTemp;
				pSceneCaptureCompone2D->bUseCustomProjectionMatrix = false;

				FReadSurfaceDataFlags rsdf(RCM_MinMax, CubeFace_MAX);
				rsdf.SetLinearToGamma(false);

				FIntRect readRect(xMouse, yMouse, xMouse + 1, yMouse + 1);

				FTextureRenderTargetResource* pRTResource = m_pDepthRenderTarget->GameThread_GetRenderTargetResource();
#if PLATFORM_LINUX
				TArray<FFloat16Color> arrOut;
				arrOut.AddUninitialized(m_pDepthRenderTarget->GetSurfaceWidth()* m_pDepthRenderTarget->GetSurfaceHeight());
				pRTResource->ReadFloat16Pixels(arrOut);
				int32 nIndex = xMouse * yMouse;

				float fDepth = arrOut[nIndex].R + arrOut[nIndex].G / 255.0 + arrOut[nIndex].B / 65025.0 + arrOut[nIndex].A / 16581375.0;
#else
				TArray<FLinearColor> arrOut;
				arrOut.AddUninitialized(2 * 2);

				Gamebool bRead = pRTResource->ReadLinearColorPixels(arrOut, rsdf, readRect);
				Gamefloat fDepth = 1.0;
				if (bRead)
				{
					fDepth = arrOut[0].R + arrOut[0].G / 255.0 + arrOut[0].B / 65025.0 + arrOut[0].A / 16581375.0;
				}
#endif			
				// 获取视图矩阵
				FViewMatrices viewMatrices;
				viewMatrices.UpdateViewMatrix(FVector(0.0,0.0,0.0), rDirection_normal);
				FMatrix viewMatrix = viewMatrices.GetViewMatrix();

				FMatrix viewProjMatrix = viewMatrix * projectMatrix;
				FMatrix invViewProjMatrix = viewProjMatrix.Inverse();

				float fMouseX = xMouse;
				float fMouseY = yMouse;

				float PixelX = FMath::TruncToFloat(fMouseX);
				float PixelY = FMath::TruncToFloat(fMouseY);

				// Get the eye position and direction of the mouse cursor in two stages (inverse transform projection, then inverse transform view).
				// This avoids the numerical instability that occurs when a view matrix with large translation is composed with a projection matrix

				// Get the pixel coordinates into 0..1 normalized coordinates within the constrained view rectangle
				const float NormalizedX = (PixelX - 0) / ((float)nScreenWidth);
				const float NormalizedY = (PixelY - 0) / ((float)nScreenHeight);

				// Get the pixel coordinates into -1..1 projection space
				const float ScreenSpaceX = (NormalizedX - 0.5f) * 2.0f;
				const float ScreenSpaceY = ((1.0f - NormalizedY) - 0.5f) * 2.0f;

				FVector4 vPos(ScreenSpaceX, ScreenSpaceY, 1 - fDepth, 1.0);
				vPos = invViewProjMatrix.TransformFVector4(vPos);


				vWorldPosition = Vector3d(vPos.X, vPos.Y, vPos.Z);
				if (vPos.W != 0.0f)
				{
					vWorldPosition = Vector3d(vWorldPosition.X / vPos.W, vWorldPosition.Y / vPos.W, vWorldPosition.Z / vPos.W);
				}
				vWorldPosition += vCameraLocation;
				// 恢复相机位置
				//m_pCameraActor->SetActorLocationAndRotation(vCameraLocation, rCameraRotation);

				arrOut.Empty();

				// 测试结果
				/*
				if (m_eCamMouseBtnState == MouseBtn_Left_Down)
				{
					DrawDebugSphere(m_pWorld, m_vMouseAnchor, 500.0f, 32, FColor::Green, true, 999999, SDPG_World);
				}
				*/

				return true;
			}

			void CameraControl::LineTrace(int32 nMouseX, int32 nMouseY)
			{
				if (CameraControl::m_eSceneType == UGC_EARTH || CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					// 方向
					FVector vLocation;
					FVector vDirection;

					FVector vCameraLocation;
					FRotator rCameraRotation;
					GetCameraLocationAndRotation(vCameraLocation, rCameraRotation);

					FVector vMouse(nMouseX, nMouseY, 0.0f);
					MouseToWorld(vMouse, vLocation, vDirection);
					vLocation += FVector(m_vecWorldOrigin);

					vLocation *= CM_TO_M;
					vDirection *= CM_TO_M;

					// 求与球的交点
					Data::Vector3d vIntersectStart3d;
					SuperMapSDK::UnrealEngine::Core::_RayIntersectionWithSphere(vLocation.X, vLocation.Y, vLocation.Z,
						vDirection.X, vDirection.Y, vDirection.Z, vIntersectStart3d.X, vIntersectStart3d.Y, vIntersectStart3d.Z);
					FVector vIntersectStart = vIntersectStart3d.ToFVector();
					vIntersectStart *= M_TO_CM;

					if (!vIntersectStart.IsNearlyZero())
					{
						m_vMouseActorRealTime = vIntersectStart - FVector(m_vecWorldOrigin);
						m_bHit = true;
					}
					else
					{
						m_bHit = false;
					}

					return;
				}


				// 求交结果
				FHitResult hitResult;

				// 方向
				FVector vLocation;
				FVector vDirection;

				FVector vCameraLocation;
				FRotator rCameraRotation;
				GetCameraLocationAndRotation(vCameraLocation, rCameraRotation);

				FVector vMouse(nMouseX, nMouseY, 0.0f);
				MouseToWorld(vMouse, vLocation, vDirection);

				// 终点
				FVector vEnd = vLocation + (vDirection * 1000000000000.0f);

				bool bHit = m_pWorld->LineTraceSingleByChannel(hitResult, vLocation, vEnd, ECC_Visibility);
				if (bHit)
				{
					// 设置基准点
					m_vMouseActorRealTime = hitResult.ImpactPoint;
					m_bHit = true;
				}
				else
				{
					m_bHit = false;
				}
			}

			void CameraControl::LineTrace(bool bLineTrace)
			{
#if !PLATFORM_LINUX
				if (m_pWorld->WorldType == EWorldType::Editor)
#endif
				{
					if ((CameraControl::m_eSceneType == UGC_EARTH || CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84) && !bLineTrace)
					{
						// 方向
						FVector vLocation;
						FVector vDirection;

						FVector vCameraLocation;
						FRotator rCameraRotation;

						GetCameraLocationAndRotation(vCameraLocation, rCameraRotation);

						FVector vMouse;

						float mouseX, mouseY;
						GetMousePos(mouseX, mouseY);
						vMouse.X = mouseX;
						vMouse.Y = mouseY;

						MouseToWorld(vMouse, vLocation, vDirection);

						TransformUERelativeToECEF(vLocation, vDirection);
						vDirection *= CM_TO_M;

						// 求与球的交点
						Data::Vector3d vIntersectStart3d;

						MathEngine::RayIntersectionWithGlobe(vLocation, vDirection, vIntersectStart3d, SceneType(CameraControl::m_eSceneType), 6378137.00);

						if (CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
						{
							vIntersectStart3d = vIntersectStart3d.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
						}
						FVector vIntersectStart = vIntersectStart3d.ToFVector();
						if (!vIntersectStart.IsNearlyZero())
						{
							m_vMouseAnchor = Georeference::TransformGeorefenceECEFToUERelative(Vector3d(vIntersectStart)).ToFVector();
							m_vMouseAnchorNoWorldOrginOffset = vIntersectStart * M_TO_CM;
							m_vecWorldOriginForRotate = m_vecWorldOrigin;
							m_bHit = true;
						}
						else
						{
							m_bHit = false;
						}

						return;
					}

					// 求交结果
					FHitResult hitResult;
					// 方向
					FVector vLocation;
					FVector vDirection;
					FVector vCameraLocation;
					FRotator rCameraRotation;

					GetCameraLocationAndRotation(vCameraLocation, rCameraRotation);
					FVector vMouse;
					float mouseX, mouseY;
					GetMousePos(mouseX, mouseY);
					vMouse.X = mouseX;
					vMouse.Y = mouseY;
					MouseToWorld(vMouse, vLocation, vDirection);
					// 终点
					FVector vEnd = vLocation + (vDirection * 1000000000000.0f);

					bool bHit = false;
					bHit = m_pWorld->LineTraceSingleByChannel(hitResult, vLocation, vEnd, ECC_Visibility);
					if (bHit)
					{
						// 设置基准点
						m_vMouseAnchor = hitResult.ImpactPoint;
						m_vMouseAnchorNoWorldOrginOffset = hitResult.ImpactPoint;
						m_vecWorldOriginForRotate = m_vecWorldOrigin;
						m_bHit = true;
					}
					else
					{
						m_bHit = false;
					}

					return;
				}

				// 运行模式下用深度取世界坐标
				FVector vMouse;
				float mouseX, mouseY;
				GetMousePos(mouseX, mouseY);
				vMouse.X = mouseX;
				vMouse.Y = mouseY;

				bool bHit = false;
				Vector3d vMouseAnchor;
				bHit = GetWorldPositionByDepth(vMouse, vMouseAnchor);
				m_vMouseAnchor = vMouseAnchor.ToFVector();
				if (bHit)
				{
					m_vMouseAnchorNoWorldOrginOffset = m_vMouseAnchor;
					m_vecWorldOriginForRotate = m_vecWorldOrigin;
					m_bHit = true;
				}
				else
				{
					m_bHit = false;
				}

				return;
			}


			void CameraControl::LineTrace(int32 nMouseX, int32 nMouseY, FHitResult& hitResult)
			{
				// 方向
				FVector vLocation;
				FVector vDirection;

				FVector vCameraLocation;
				FRotator rCameraRotation;
				GetCameraLocationAndRotation(vCameraLocation, rCameraRotation);
				
				FVector vMouse(nMouseX, nMouseY, 0.0f);
				MouseToWorld(vMouse, vLocation, vDirection);

				// 终点
				FVector vEnd = vLocation + (vDirection * 1000000000000.0f);

				m_pWorld->LineTraceSingleByChannel(hitResult, vLocation, vEnd, ECC_Visibility);

				UPrimitiveComponent* pComponent = hitResult.GetComponent();
				FCollisionQueryParams DefalutParams = FCollisionQueryParams::DefaultQueryParam;
				Gameint nTraceCount = 10;
				while (nTraceCount > 0 && pComponent != nullptr)
				{
					AActor* pActor = pComponent->GetOwner();
					if (pActor->ActorHasTag(TEXT("SUPERMAP")))
					{
						USuperMap_MeshComponentInterface* pParent = (USuperMap_MeshComponentInterface*)pComponent->GetAttachParent();
						Gamebool bLayerVisible = pParent->GetLayerVisibility();
						Gamebool bInternalVisible = pParent->GetInternalVisibility();

						if (bLayerVisible && bInternalVisible)
						{
							break;
						}
						DefalutParams.AddIgnoredComponent(pComponent);
	
						m_pWorld->LineTraceSingleByChannel(hitResult, vLocation, vEnd, ECC_Visibility, DefalutParams);
						pComponent = hitResult.GetComponent();
					}

					nTraceCount--;
				}
			}


			FMatrix CameraControl::GetCameraProjectionMatrix()
			{
				FMatrix projectMatrix;
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
				#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();

					FViewportClient* pViewportClient = pViewport->GetClient();
					FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);

					FSceneViewFamilyContext ViewFamily(FSceneViewFamilyContext::ConstructionValues(pViewport, pEditorViewportClient->GetScene(),
						pEditorViewportClient->EngineShowFlags).SetRealtimeUpdate(pEditorViewportClient->IsRealtime()));

					FSceneView* pSceneView = pEditorViewportClient->CalcSceneView(&ViewFamily);
					projectMatrix = pSceneView->ViewMatrices.GetProjectionMatrix();
				#endif
				}
				else
				{
					ULocalPlayer* pLocalP = m_pCurrentPlayerControl->GetLocalPlayer();
					if (pLocalP->ViewportClient)
					{
						FSceneViewProjectionData ProjectionData;
#if SM_FOR_UE_FIVE
						if (pLocalP->GetProjectionData(pLocalP->ViewportClient->Viewport, /*out*/ ProjectionData))
#else
						if (pLocalP->GetProjectionData(pLocalP->ViewportClient->Viewport, eSSP_FULL, /*out*/ ProjectionData))
#endif
						{
							projectMatrix = ProjectionData.ProjectionMatrix;
						}
					}
				}
				return projectMatrix;
			}
			void CameraControl::SetCameraLocationAndRotation(FVector vCameraLocation, FRotator vCameraRotator)
			{
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
				#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();
					FViewportClient* pViewportClient = pViewport->GetClient();
					FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);
					pEditorViewportClient->SetViewLocation(vCameraLocation);
					pEditorViewportClient->SetViewRotation(vCameraRotator);
				#endif
				}
				else
				{
					m_pCurrentPlayerControl->GetPawn()->SetActorLocation(vCameraLocation);
					m_pCurrentPlayerControl->SetControlRotation(vCameraRotator);
				}

				m_vCameraLocation = vCameraLocation;
				m_vCameraRotator  = vCameraRotator;
			}

			void CameraControl::GetCameraLocationAndRotation(FVector &vCameraLocation, FRotator &vCameraRotator)
			{
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
				#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();

					FViewportClient* pViewportClient = pViewport->GetClient();
					FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);

					vCameraLocation = pEditorViewportClient->GetViewLocation();
					vCameraRotator = pEditorViewportClient->GetViewRotation();
				#endif
				}
				else
				{
					m_pCurrentPlayerControl->GetPlayerViewPoint(vCameraLocation, vCameraRotator);
				}
			}

			void CameraControl::GetViewportSize(int32 &x, int32 &y)
			{
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
				#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();

					x = pViewport->GetSizeXY().X;
					y = pViewport->GetSizeXY().Y;
				#endif
				}
				else
				{
					m_pCurrentPlayerControl->GetViewportSize(x, y);
				}
			}

			void CameraControl::GetMousePos(float &x, float &y)
			{
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
				#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();
					x = pViewport->GetMouseX();
					y = pViewport->GetMouseY();
				#endif
				}
				else
				{
					float fX, fY;
					m_pCurrentPlayerControl->GetMousePosition(fX, fY);
					if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetMultiViewportMode() == Horizontal && fX > m_nScreenWidth)
					{
						fX -= m_nScreenWidth;
					}

					x = fX;
					y = fY;
				}
			}

			void CameraControl::PrepareCurrentStartMouse()
			{
				FVector vMousePoint;
				float mouseX, mouseY;
				GetMousePos(mouseX, mouseY);
				vMousePoint.X = mouseX;
				vMousePoint.Y = mouseY;
				m_vMouseStartPoint = vMousePoint;
			}

			void CameraControl::PrepareCurrentEndMouse()
			{
				FVector vMousePoint;				
				float mouseX, mouseY;
				GetMousePos(mouseX, mouseY);
				vMousePoint.X = mouseX;
				vMousePoint.Y = mouseY; m_vMouseEndPoint = vMousePoint;
			}

			void CameraControl::EndPointTOStartPoint()
			{
				m_vMouseStartPoint = m_vMouseEndPoint;
			}


			FVector CameraControl::GetDirection()
			{
				FVector vCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotation(vCameraLocation, vCameraRotator);

				FQuat qCameraQuat(vCameraRotator);

				return qCameraQuat * -FVector(0.0f, 0.0f, 1.0f);
			}

			FVector CameraControl::GetUp()
			{
				FVector vCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotation(vCameraLocation, vCameraRotator);

				FQuat qCameraQuat(vCameraRotator);

				return qCameraQuat * FVector(1.0f, 0.0f, 0.0f);
			}

			void CameraControl::ReCalOpCenterTilt()
			{
				if (m_vMouseAnchor.IsNearlyZero())
				{
					return;
				}

				FVector vCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotation(vCameraLocation, vCameraRotator);

				vCameraLocation += FVector(m_vecWorldOrigin);

				FQuat qCameraQuat(vCameraRotator);

				FVector vE1ToB, v0, v1, v2;
				vE1ToB = (m_vMouseAnchor + FVector(m_vecWorldOriginForRotate)) - vCameraLocation;
				v0 = m_vMouseAnchor + FVector(m_vecWorldOriginForRotate);


				float l_E1ToB, fCosAlpha, t, a, b, c;
				//float l_E1ToB;
				FVector vE1ToBDir;
				vE1ToB.ToDirectionAndLength(vE1ToBDir, l_E1ToB);

				FVector vDir = GetDirection();
				float fDir;
				FVector vDDir;
				vDir.ToDirectionAndLength(vDDir, fDir);

				vE1ToB.Normalize();

				fCosAlpha = FVector::DotProduct(vDir, vE1ToB) / fDir;


				float fV0;
				FVector vV0Dir;
				v0.ToDirectionAndLength(vV0Dir, fV0);

				t = l_E1ToB * fCosAlpha + FMath::Sqrt(l_E1ToB * l_E1ToB * (fCosAlpha * fCosAlpha - 1.0) + fV0 * fV0);

				v1 = -vDir;
				v2 = GetUp();

				a = FVector::DotProduct(v0, v1);
				b = FVector::DotProduct(v0, v2);
				c = t - l_E1ToB * fCosAlpha;

				float fSinPsi, fSinPhi, theta1, theta2, theta;
				fSinPsi = FMath::Clamp(c / FMath::Sqrt(a * a + b * b), -1.0f, 1.0f);
				fSinPhi = FMath::Clamp(a / FMath::Sqrt(a * a + b * b), -1.0f, 1.0f);

				theta1 = FMath::Asin(fSinPsi) - FMath::Asin(fSinPhi);
				theta2 = PI - FMath::Asin(fSinPsi) - FMath::Asin(fSinPhi);

				theta = FMath::Abs(m_fOpCenterTile - theta1) > FMath::Abs(m_fOpCenterTile - theta2) ? theta2 : theta1;

				if (FMath::IsNearlyZero(theta))
				{
					return;
				}

				m_fOpCenterTile = theta;
			}

			void CameraControl::GetDepthTexture(CaptureDepthTexParm captureDepthTexparam, void* &pDepthBuffer)
			{
				if (m_pCameraActor == nullptr)
				{
					return;
				}

				uint32 textureWidth = captureDepthTexparam.m_textureWidth;
				uint32 textureHeight = captureDepthTexparam.m_textureHeight;

				FVector vOriCameraLocation;
				FRotator rOriCameraRotation;
				GetCameraLocationAndRotation(vOriCameraLocation, rOriCameraRotation);

				m_pCameraActor->SetActorLocationAndRotation(captureDepthTexparam.m_vCameraLocation, captureDepthTexparam.m_rCameraRotation);

				// 获取场景采集组件
				USceneCaptureComponent2D* pSceneCaptureCompone2D = (USceneCaptureComponent2D*)m_pCameraActor->GetRootComponent()->GetChildComponent(1);
				if (pSceneCaptureCompone2D == NULL)
				{
					return;
				}

				FMatrix matTemp = pSceneCaptureCompone2D->CustomProjectionMatrix;
				TEnumAsByte<enum ESceneCaptureSource> eTemp = pSceneCaptureCompone2D->CaptureSource;
				pSceneCaptureCompone2D->CaptureSource = SCS_DeviceDepth;
				pSceneCaptureCompone2D->CompositeMode = ESceneCaptureCompositeMode::SCCM_Overwrite;

				UCameraComponent* pCameraComponent = m_pCameraActor->GetCameraComponent();
				if (pCameraComponent == NULL)
				{
					return;
				}

				// 创建渲染纹理
				UTextureRenderTarget2D* pTextureRenderTarget2D = NewObject<UTextureRenderTarget2D>();
#if PLATFORM_LINUX
				pTextureRenderTarget2D->RenderTargetFormat = RTF_RGBA16f;
#else
				pTextureRenderTarget2D->RenderTargetFormat = RTF_RGBA32f;
#endif
				pTextureRenderTarget2D->Filter = TF_Nearest;
				pTextureRenderTarget2D->ClearColor = FLinearColor::Black;
				pTextureRenderTarget2D->InitAutoFormat(textureWidth, textureHeight);

				pSceneCaptureCompone2D->TextureTarget = pTextureRenderTarget2D;
				pSceneCaptureCompone2D->bUseCustomProjectionMatrix = true;
				pSceneCaptureCompone2D->CustomProjectionMatrix = captureDepthTexparam.m_projMatrix;
				pSceneCaptureCompone2D->CaptureScene();

				pSceneCaptureCompone2D->CaptureSource = eTemp;
				pSceneCaptureCompone2D->bUseCustomProjectionMatrix = false;

				FTextureRenderTargetResource* pRTResource = pTextureRenderTarget2D->GameThread_GetRenderTargetResource();

				FReadSurfaceDataFlags rsdf(RCM_MinMax, CubeFace_MAX);
				rsdf.SetLinearToGamma(false);

#if PLATFORM_LINUX
				TArray<FFloat16Color> arrDepthBuffer;
				arrDepthBuffer.AddUninitialized(textureWidth * textureHeight);
				pRTResource->ReadFloat16Pixels(arrDepthBuffer);
#else
				TArray<FLinearColor> arrDepthBuffer;
				arrDepthBuffer.AddUninitialized(textureWidth * textureHeight);
				pRTResource->ReadLinearColorPixels(arrDepthBuffer, rsdf);
#endif
				int32 nSize = arrDepthBuffer.Num();
				float* pBuffer = new float[nSize];
				for (int32 nBuffer = 0; nBuffer < arrDepthBuffer.Num(); nBuffer++)
				{
#if PLATFORM_LINUX
					FFloat16Color & color = arrDepthBuffer[nBuffer];
#else
					FLinearColor & color = arrDepthBuffer[nBuffer];
#endif
					float fDepth = color.R + color.G / 255.0f + color.B / 65025.0f + color.A / 16581375.0f;
					
					pBuffer[nBuffer] = fDepth;
				}

				pDepthBuffer = (float*)pBuffer;

				pTextureRenderTarget2D->MarkPendingKill();
				pTextureRenderTarget2D = nullptr;

				m_pCameraActor->SetActorLocationAndRotation(vOriCameraLocation, rOriCameraRotation);

				pSceneCaptureCompone2D->bUseCustomProjectionMatrix = false;
				pSceneCaptureCompone2D->CustomProjectionMatrix =matTemp;
				return;
			}

			void CameraControl::Earth_Pan()
			{
				// 获取当前相机的状态
				if (FMath::IsNearlyEqual(m_vMouseStartPoint.X, m_vMouseEndPoint.X) &&
					FMath::IsNearlyEqual(m_vMouseStartPoint.Y, m_vMouseEndPoint.Y))//m_vMouseStartPoint.Equals(m_vMouseEndPoint))
				{
					/*FString strText;
					strText = FString::Printf(TEXT("Windows w : %d , Windows h : %d"), 0, 5);
					GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, strText);*/
					m_vMouseStartPoint = m_vMouseEndPoint;
					return;
				}

				FVector LocationStart2;
				FVector LocationStart, DirectionStart;

				LocationStart2 = LocationStart;

				// 绝对坐标
				FVector LocationEnd2;
				FVector LocationEnd, DirectionEnd;

				FVector vUERelativeCameraLocation;
				FVector vGeoECEFCameraLocation;
				FRotator vCameraRotator;
				// 获取相机的Location和Rotation
				GetCameraLocationAndRotation(vUERelativeCameraLocation, vCameraRotator);
				
				vGeoECEFCameraLocation = Georeference::TransformUERelativeToGeorefenceECEF(Vector3d(vUERelativeCameraLocation)).ToFVector();
				Gamefloat fCameraHeightByMeter = GetEarthCameraHeight();

				FVector vCL = vGeoECEFCameraLocation;
				Gamefloat fCurPos;
				FVector vCurDir;
				vCL.ToDirectionAndLength(vCurDir, fCurPos);

				// 鼠标起始点
				MouseToWorld(m_vMouseStartPoint, LocationStart, DirectionStart);
				// 鼠标终止点
				MouseToWorld(m_vMouseEndPoint, LocationEnd, DirectionEnd);

				// 远地面的操作
				if (fCameraHeightByMeter > NEAR_GROUND_HEIGHT_BY_METER)
				{
					TransformUERelativeToECEF(LocationStart, DirectionStart);
					TransformUERelativeToECEF(LocationEnd, DirectionEnd);
					//DirectionStart *= CM_TO_M;
					//DirectionEnd *= CM_TO_M;

					Gamedouble dRadius = 0.0;
					if (m_pWorld->WorldType == EWorldType::Editor)
					{
						dRadius = 6378137.0f;
					}
					else
					{
						Vector3d vStartWorld = GetLocalWorldPosition(m_vMouseStartPoint.X, m_vMouseStartPoint.Y);
						vStartWorld = Georeference::TransformUEAbsToGeorefenceECEF(vStartWorld);
						dRadius = vStartWorld.Magnitude();
					}

					Vector3d vIntersectStart = Vector3d(0,0,0);
					Gamebool bStart = MathEngine::RayIntersectionWithGlobe(LocationStart, DirectionStart, vIntersectStart, SceneType(CameraControl::m_eSceneType), dRadius);

					Vector3d vIntersectEnd = Vector3d(0, 0, 0);
					Gamebool bEnd = MathEngine::RayIntersectionWithGlobe(LocationEnd, DirectionEnd, vIntersectEnd, SceneType(CameraControl::m_eSceneType), dRadius);

					if (CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						vIntersectStart = vIntersectStart.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
						vIntersectEnd = vIntersectEnd.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
					}

					if (!bStart || !bEnd)
					{
						m_vMouseStartPoint = m_vMouseEndPoint;
						return;
					}


					if (fCurPos < 6378937.0f)
					{
						Gamedouble dx = (vIntersectEnd.X - vIntersectStart.X) * M_TO_CM;
						Gamedouble dy = (vIntersectEnd.Y - vIntersectStart.Y) * M_TO_CM;
						Gamedouble dz = (vIntersectEnd.Z - vIntersectStart.Z) * M_TO_CM;

						if (FMath::IsNearlyZero(dx) && FMath::IsNearlyZero(dy) && FMath::IsNearlyZero(dz))
						{
							m_vMouseStartPoint = m_vMouseEndPoint;
							return;
						}

						if (FMath::Abs(dx) > 700 * M_TO_CM &&
							FMath::Abs(dy) > 700 * M_TO_CM &&
							FMath::Abs(dz) > 700 * M_TO_CM )
						{
							m_vMouseStartPoint = m_vMouseEndPoint;
							return;
						}

						Gamedouble ddx = vUERelativeCameraLocation.X * 1.0 - dx;
						Gamedouble ddy = vUERelativeCameraLocation.Y * 1.0 - dy;
						Gamedouble ddz = vUERelativeCameraLocation.Z * 1.0 - dz;

						FVector tran;
						tran.X = ddx;
						tran.Y = ddy;
						tran.Z = ddz;
						m_vMouseStartPoint = m_vMouseEndPoint;

						SetCameraLocationAndRotation(tran, vCameraRotator);
						return;
					}

					FQuat qCameraQuat(vCameraRotator);

					Gamedouble tx, ty, tz;
					Gamedouble qx, qy, qz, qw;

					SuperMapSDK::UnrealEngine::Core::_CalLocationAndRotation(vIntersectStart.X, vIntersectStart.Y, vIntersectStart.Z,
						vIntersectEnd.X, vIntersectEnd.Y, vIntersectEnd.Z,
						vGeoECEFCameraLocation.X, vGeoECEFCameraLocation.Y, vGeoECEFCameraLocation.Z,
						qCameraQuat.X, qCameraQuat.Y, qCameraQuat.Z, qCameraQuat.W,
						tx, ty, tz, qx, qy, qz, qw
					);

					FVector tran = Georeference::TransformGeorefenceECEFToUERelative(Vector3d(tx, ty, tz)).ToFVector();
					FQuat q2(qx, qy, qz, qw);
					FRotator r2 = q2.Rotator();

					SetCameraLocationAndRotation(tran, r2);
				}
				else
				{
					Earth_PanNearGround(LocationStart, DirectionStart, LocationEnd, DirectionEnd);
				}

				m_vMouseStartPoint = m_vMouseEndPoint;
			}

			void CameraControl::Earth_PanNearGround(const FVector& LocationStart, const FVector& DirectionStart, const FVector& LocationEnd, const FVector& DirectionEnd)
			{
				FVector sphereCenter(0, 0, 0);
				sphereCenter = sphereCenter - FVector(m_vecWorldOrigin);
				FVector planePoint = m_vMouseAnchorNoWorldOrginOffset - FVector(m_vecWorldOrigin);
				FVector upDir = planePoint - sphereCenter;
				upDir.Normalize();

				FPlane plane(planePoint, upDir);

				FVector vStartIntersect = FMath::RayPlaneIntersection(LocationStart, DirectionStart, plane);
				FVector vEndIntersect = FMath::RayPlaneIntersection(LocationEnd, DirectionEnd, plane);

				FVector vMove = vEndIntersect - vStartIntersect;

				FVector vCurrentLocation = m_pCurrentPlayerControl->GetPawn()->GetActorLocation();
				vCurrentLocation += -vMove;

				FRotator rCurrentRotator = m_pCurrentPlayerControl->GetControlRotation();
				SetCameraLocationAndRotation(vCurrentLocation, rCurrentRotator);
			}

			void CameraControl::Earth_Rotate()
			{
				FVector UNIT_X = FVector(1.0f, 0.0f, 0.0f);
				FVector	UNIT_Y = FVector(0.0f, 1.0f, 0.0f);
				FVector	UNIT_Z = FVector(0.0f, 0.0f, 1.0f);

				FVector vOffset = m_vMouseEndPoint - m_vMouseStartPoint;

				if (vOffset.IsNearlyZero() || !m_bHit)
				{
					return;
				}

				Gamefloat fHeightRadio = (-vOffset.Y * 1.0f) / (m_nScreenHeight * 1.0f);
				fHeightRadio *= (PI / 2.0f);
				fHeightRadio = FMath::Clamp(fHeightRadio, -0.1f, 0.1f);

				Gamefloat fWidthRadio = (-vOffset.X * 1.0f) / (m_nScreenWidth * 1.0f);
				fWidthRadio *= PI;
				fWidthRadio = FMath::Clamp(fWidthRadio, -0.2f, 0.2f);

				//fHeightRadio = FMath::Clamp(m_fOpCenterTile + fHeightRadio, -PI, PI) - m_fOpCenterTile;
				m_fOpCenterTile += fHeightRadio;

				FVector vCameraLocation;
				FRotator vCameraRotator;
				
				GetCameraLocationAndRotation(vCameraLocation, vCameraRotator);

				FVector vOriCameraLocation = vCameraLocation;
				vCameraLocation += FVector(m_vecWorldOrigin);

				Vector3d vecRotateAxis = Vector3d(m_vMouseAnchor) + Vector3d(m_vecWorldOriginForRotate);

				Vector3d vEyeToTarget = Vector3d(m_vMouseAnchor) + Vector3d(m_vecWorldOriginForRotate) - Vector3d(vCameraLocation);

				FQuat qCameraQuat(vCameraRotator);

				Gamedouble quaX, quaY, quaZ, quaW;
				Gamedouble transsX, transsY, transsZ;
				SuperMapSDK::UnrealEngine::Core::_CalPitchAndHeadingWithWorldOffset(vecRotateAxis.X, vecRotateAxis.Y, vecRotateAxis.Z,
					vEyeToTarget.X, vEyeToTarget.Y, vEyeToTarget.Z,
					qCameraQuat.X, qCameraQuat.Y, qCameraQuat.Z, qCameraQuat.W,
					vOriCameraLocation.X, vOriCameraLocation.Y, vOriCameraLocation.Z,
					MathEngine::m_vWorldOffset.X, MathEngine::m_vWorldOffset.Y, MathEngine::m_vWorldOffset.Z,
					fWidthRadio, fHeightRadio,
					quaX, quaY, quaZ, quaW,
					transsX, transsY, transsZ);

				FQuat camQua(quaX, quaY, quaZ, quaW);
				FVector trans;
				trans.X = transsX;
				trans.Y = transsY;
				trans.Z = transsZ;

				// 防止相机陷入地下
				FVector tansOnSphere = trans;
				FVector direction;
				TransformUERelativeToECEF(tansOnSphere, direction);
				Gamefloat fR;
				FVector vD;
				tansOnSphere.ToDirectionAndLength(vD, fR);
				vD *= -1;
				Vector3d vIntersect3d;
				Gamebool bIsHit = MathEngine::RayIntersectionWithGlobe(tansOnSphere, vD, vIntersect3d, SceneType(CameraControl::m_eSceneType), 6378137.0f);

				if (!bIsHit)
				{
					return;
				}
				/////////////////////
				SetCameraLocationAndRotation(trans, camQua.Rotator());
			}

			void CameraControl::Earth_Scale()
			{
				// 当前鼠标
				FVector vMousePoint;
				float mouseX, mouseY;
				GetMousePos(mouseX, mouseY);
				vMousePoint.X = mouseX;
				vMousePoint.Y = mouseY;
				Gamedouble dRadius = 0.0;
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
					dRadius = 6378137.0f;
				}
				else
				{
					Vector3d vStartWorld = GetLocalWorldPosition(vMousePoint.X, vMousePoint.Y);
					vStartWorld = Georeference::TransformUEAbsToGeorefenceECEF(vStartWorld);
					dRadius = vStartWorld.Magnitude();
				}


				// 获取当前相机的位置
				FVector vUERelativeCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotation(vUERelativeCameraLocation, vCameraRotator);
				FVector vGeoECEFCameraLocation = Georeference::TransformUERelativeToGeorefenceECEF(Vector3d(vUERelativeCameraLocation)).ToFVector();

				// 鼠标射线
				FVector vStart;
				FVector vStartDirection;

				MouseToWorld(vMousePoint, vStart, vStartDirection);
				TransformUERelativeToECEF(vStart, vStartDirection);
				//vStartDirection *= CM_TO_M;

				// 求与球的交点
				Data::Vector3d vIntersect3d;

				MathEngine::RayIntersectionWithGlobe(vStart, vStartDirection, vIntersect3d, SceneType(CameraControl::m_eSceneType),dRadius);
				
				if (CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					vIntersect3d = vIntersect3d.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
				}

				FVector vIntersect = vIntersect3d.ToFVector();

				// 判断相机的位置
				FVector vCurDir;
				Gamefloat fCurrentDis;
				vGeoECEFCameraLocation.ToDirectionAndLength(vCurDir, fCurrentDis);

				FVector vDistance = (vIntersect - vGeoECEFCameraLocation);
				FVector vDir;
				Gamefloat fDistanceCamToIntersect = 0;
				vDistance.ToDirectionAndLength(vDir, fDistanceCamToIntersect);
				

				Gamedouble fValue = m_fScrollFactor > 0.0 ? 120 * 0.0007 : -120 * 0.0007;
				Gamedouble fCurrentDist = fDistanceCamToIntersect + 6378137.0f;
				Gamedouble fTargetDistance = fDistanceCamToIntersect * fValue + fCurrentDist;
				fTargetDistance = FMath::Clamp(fTargetDistance, (6378137.0  - 11034.0), 7.5 * 6378137.0);

				Gamedouble fDeltaDistance = (fTargetDistance - fCurrentDist) * M_TO_CM;

				FQuat qCameraQuat(vCameraRotator);
				FVector v0 = vIntersect - vGeoECEFCameraLocation;
				FVector v1 = qCameraQuat * FVector(0.0f, 1.0f, 0.0f);
				FVector vZoomAxis = v0 - FVector::DotProduct(v0, v1) * v1;
				vZoomAxis.Normalize();

				FVector vMove = fDeltaDistance * vZoomAxis;

				// 平移向量
				FVector vLocation = vUERelativeCameraLocation + vMove;
				if (fDistanceCamToIntersect < 0.1 && fValue > 0)
				{
					return;
				}
				if (fDistanceCamToIntersect < 1000)
				{
					SetCameraLocationAndRotation(vLocation, vCameraRotator);
					return;
				}
				
				// 旋转向量
				FVector vWorld = Georeference::TransformUERelativeToGeorefenceECEF(Vector3d(vLocation)).ToFVector();
				FVector vLocationDir;
				Gamefloat fLocation;
				vWorld.ToDirectionAndLength(vLocationDir, fLocation);

				if (fCurrentDis > (7 * 6378137.0f))
				{
					return;
				}
				if (fLocation > (7 * 6378137.0f))
				{
					return;
				}
			
				FVector vMouseWorld;
				FVector vWorldDirection;
				MouseToWorld(vMousePoint, vMouseWorld, vWorldDirection, 0.5, 1.0 , vMove);
				vWorldDirection.Normalize();
				TransformUERelativeToECEF(vMouseWorld, vWorldDirection);
				// 求与球的交点
				Data::Vector3d vIntersect3d2;

				Gamebool bIsHit = MathEngine::RayIntersectionWithGlobe(vMouseWorld, vWorldDirection, vIntersect3d2, SceneType(CameraControl::m_eSceneType), dRadius);
				if (CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					vIntersect3d2 = vIntersect3d2.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
				}
				FVector vIntersect2 = vIntersect3d2.ToFVector();
				if (!bIsHit)
				{
					return;
				}
				//-------------------------
				vGeoECEFCameraLocation = Georeference::TransformUERelativeToGeorefenceECEF(Vector3d(vLocation)).ToFVector();

				// 使用double计算避免四元数与向量计算丢失精度
				Gamedouble tx, ty, tz;
				Gamedouble qx, qy, qz, qw;

				SuperMapSDK::UnrealEngine::Core::_CalLocationAndRotation(vIntersect.X, vIntersect.Y, vIntersect.Z,
					vIntersect2.X, vIntersect2.Y, vIntersect2.Z,
					vGeoECEFCameraLocation.X, vGeoECEFCameraLocation.Y, vGeoECEFCameraLocation.Z,
					qCameraQuat.X, qCameraQuat.Y, qCameraQuat.Z, qCameraQuat.W,
					tx, ty, tz, qx, qy, qz, qw
				);

				FVector tran = Georeference::TransformGeorefenceECEFToUERelative(Vector3d(tx, ty, tz)).ToFVector();
				FQuat q2(qx, qy, qz, qw);
				FRotator r2 = q2.Rotator();

				vWorld = FVector(tx, ty, tz);
				vWorld.ToDirectionAndLength(vLocationDir, fLocation);

				if (fLocation > (7 * 6378137.0f))
				{
					return;
				}

				SetCameraLocationAndRotation(tran, r2);
			}

			void CameraControl::MouseToWorld(FVector vMousePt, FVector & vWorld, FVector &vDirection
				, float fDepth1, float fDepth2, FVector vMove)
			{
				// 求视图矩阵
				FMatrix projectMatrix = GetCameraProjectionMatrix();

				// 相机位置
				FVector vCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotation(vCameraLocation, vCameraRotator);
				vCameraLocation += vMove;
				// 获取视图矩阵
				FViewMatrices viewMatrices;
				viewMatrices.UpdateViewMatrix(FVector::ZeroVector, vCameraRotator);
				FMatrix viewMatrix = viewMatrices.GetViewMatrix();

				FMatrix viewProjectMatrix = viewMatrix * projectMatrix;
				FMatrix invViewProjectMatrix = viewProjectMatrix.Inverse();

				double PixelX = FMath::TruncToFloat(vMousePt.X);
				double PixelY = FMath::TruncToFloat(vMousePt.Y);

				int32 nWidth;
				int32 nHeight;

				GetViewportSize(nWidth, nHeight);

				// Get the eye position and direction of the mouse cursor in two stages (inverse transform projection, then inverse transform view).
				// This avoids the numerical instability that occurs when a view matrix with large translation is composed with a projection matrix

				// Get the pixel coordinates into 0..1 normalized coordinates within the constrained view rectangle
				const double NormalizedX = (PixelX - 0) / ((float)nWidth);
				const double NormalizedY = (PixelY - 0) / ((float)nHeight);

				// Get the pixel coordinates into -1..1 projection space
				const double ScreenSpaceX = (NormalizedX - 0.5f) * 2.0f;
				const double ScreenSpaceY = ((1.0f - NormalizedY) - 0.5f) * 2.0f;

				FVector4 ipos1(ScreenSpaceX, ScreenSpaceY, fDepth1, 1.0);
				FVector4 ipos2(ScreenSpaceX, ScreenSpaceY, fDepth2, 1.0);
				ipos1 = invViewProjectMatrix.TransformFVector4(ipos1);
				ipos2 = invViewProjectMatrix.TransformFVector4(ipos2);

				FVector iipos1(ipos1.X, ipos1.Y, ipos1.Z);
				if (ipos1.W != 0.0f)
				{
					iipos1 /= ipos1.W;
				}
				FVector iipos2(ipos2.X, ipos2.Y, ipos2.Z);
				if (ipos2.W != 0.0f)
				{
					iipos2 /= ipos2.W;
				}

				vWorld = iipos2 + vCameraLocation;
				vDirection = iipos1 - iipos2;
			}

			void CameraControl::Plane_Pan()
			{
				if (m_vMouseEndPoint.Equals(m_vMouseStartPoint) || !m_bHit)
				{
					return;
				}


				// 创建一个平面
				FVector vPlane1(0.0f, 0.0f, m_vMouseAnchor.Z);
				FVector vPlane2(0.0f, 1.0f, m_vMouseAnchor.Z);
				FVector vPlane3(1.0f, 0.0f, m_vMouseAnchor.Z);

				FPlane plane(vPlane1, vPlane2, vPlane3);

				// 相机位置
				FVector vCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotation(vCameraLocation, vCameraRotator);	

				FVector vStart , vStartDirection;
				FVector vEnd   , vEndDirection;

				MouseToWorld(m_vMouseStartPoint, vStart, vStartDirection, -1.0f, 1.0f);
				vStartDirection *= -1;
				MouseToWorld(m_vMouseEndPoint, vEnd  , vEndDirection, -1.0f, 1.0f);
				vEndDirection *= -1;

				FVector vStartIntersect = FMath::RayPlaneIntersection(vStart, vStartDirection, plane);
				FVector vEndIntersect = FMath::RayPlaneIntersection(vEnd, vEndDirection, plane);

				vStartIntersect.Z = m_vMouseAnchor.Z;
				vEndIntersect.Z = m_vMouseAnchor.Z;

				FVector vMove = vEndIntersect - vStartIntersect;

				float fMoveDis = 0;
				FVector vDirection;
				vMove.ToDirectionAndLength(vDirection, fMoveDis);

				// 这里为防止相机拉平时平移距离过大，进行了限制，相机视线方向与场景Z轴方向大于75度时乘一个平移距离缩放系数
				float limitCoeff = 1.0;
				FVector cameraDirection = -vStartDirection;
				cameraDirection.Normalize();
				float cosAngle = FVector::DotProduct(FVector(0, 0, 1), cameraDirection);
				float angleBetweenUpDirAndCamDir = acosf(cosAngle) * (180.f / PI);
				if (FMath::Abs(angleBetweenUpDirAndCamDir) > 0.0 && FMath::Abs(angleBetweenUpDirAndCamDir) < 90.0) 
				{
					float fCameraZ = vCameraLocation.Z + FVector(m_vecWorldOrigin).Z;
					limitCoeff = angleBetweenUpDirAndCamDir > 75 ? powf(cosAngle, 0.5) : limitCoeff;
					fMoveDis = fMoveDis > fCameraZ * 3 ? fCameraZ * 3 : fMoveDis;
				}
				else 
				{
					return;
				}
				FVector limitMove = vDirection * fMoveDis * limitCoeff;

				FVector vCurrentLocation = vCameraLocation;
				vCurrentLocation += -limitMove;

				FRotator rCurrentRotator = vCameraRotator;
				SetCameraLocationAndRotation(vCurrentLocation, rCurrentRotator);
				
				m_vMouseStartPoint = m_vMouseEndPoint;

			}

			void CameraControl::Plane_Rotate()
			{
				FVector UNIT_X = FVector(1.0f, 0.0f, 0.0f);
				FVector	UNIT_Y = FVector(0.0f, 1.0f, 0.0f);
				FVector	UNIT_Z = FVector(0.0f, 0.0f, 1.0f);

				FVector vOffset = m_vMouseEndPoint - m_vMouseStartPoint;

				if (vOffset.IsNearlyZero())
				{
					return;
				}

				float fHeightRadio = -(vOffset.Y * 1.0f) / (m_nScreenHeight * 1.0f);
				fHeightRadio *= (PI / 2.0f);
				fHeightRadio = FMath::Clamp(fHeightRadio, -0.1f, 0.1f);

				float fWidthRadio = (-vOffset.X * 1.0f) / (m_nScreenWidth * 1.0f);
				fWidthRadio *= PI;
				fWidthRadio = FMath::Clamp(fWidthRadio, -0.2f, 0.2f);

				FVector vCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotation(vCameraLocation, vCameraRotator);
				FQuat orientation(vCameraRotator);

				float fHeading = -fWidthRadio;

				FQuat q(UNIT_Z, fHeading);
				FVector vCamDirection = orientation * -UNIT_Z;
				float fDot = FVector::DotProduct(UNIT_Z, -vCamDirection);
				fDot = FMath::Clamp(fDot, -1.0f, 1.0f);

				fDot = FMath::Acos(fDot);

				float fPitch = fDot;

				float fNormalizedPitch = fPitch + fHeightRadio;

				float fPitchAngle = (fNormalizedPitch > PI ? PI : (fNormalizedPitch < 0 ? 0 : fNormalizedPitch));

				float fPitchRadio = (fPitchAngle - fPitch);

				FVector xAxis = orientation * UNIT_Y;
				FQuat q1(xAxis, fPitchRadio);
				FQuat q2 = q * q1;

				FQuat q3(UNIT_Z, fHeading);
				q3.Normalize();
				q3 = q3 * orientation;

				xAxis = q3 * UNIT_Y;
				FQuat q4(xAxis, fPitchRadio);
				q4.Normalize();

				q3 = q4 * q3;

				vCameraLocation = (q2 * (vCameraLocation + FVector(m_vecWorldOrigin) - (m_vMouseAnchor + FVector(m_vecWorldOriginForRotate)))) + (m_vMouseAnchor + FVector(m_vecWorldOriginForRotate));
				vCameraLocation -= FVector(m_vecWorldOrigin);

				FRotator rCurrentRotator = q3.Rotator();

				SetCameraLocationAndRotation(vCameraLocation, rCurrentRotator);
			}

			void CameraControl::Plane_Scale()
			{
				FRotator rCurrentRotator;
				FVector vCurrentLocation;
				
				GetCameraLocationAndRotation(vCurrentLocation, rCurrentRotator);

				Vector3d vDist = Vector3d(m_vMouseAnchor) + Vector3d(m_vecWorldOriginForRotate) - 
					(Vector3d(vCurrentLocation)+Vector3d(m_vecWorldOrigin));

				Vector3d vDir = vDist.Normalize();
				Gamedouble dDist = vDist.Magnitude();

				if (m_fScrollFactor != 0)
				{
					dDist = dDist * 0.00006f * m_fScrollFactor;
				}
				else
				{
					Gamedouble dValue = -(m_vMouseEndPoint.Y - m_vMouseStartPoint.Y) * 2.0f / m_nScreenHeight;
					dDist = dDist * 0.0008f * 1250.0f * dValue * 0.1f;
				}

				vCurrentLocation += (vDir * dDist).ToFVector();
				SetCameraLocationAndRotation(vCurrentLocation, rCurrentRotator);
			}

			FRotator CameraControl::CalRotation(FVector vLonlat)
			{
				FVector UNIT_X = FVector(1.0f, 0.0f, 0.0f);
				FVector	UNIT_Y = FVector(0.0f, 1.0f, 0.0f);
				FVector	UNIT_Z = FVector(0.0f, 0.0f, 1.0f);

				FQuat orientation = FQuat::Identity;

				FVector xAxis = orientation * UNIT_X;
				FQuat q1(xAxis, FMath::DegreesToRadians( -vLonlat.Y ) );

				q1.Normalize();

				q1 = q1 * orientation;

				xAxis = q1 * UNIT_Y;
				FQuat q2(xAxis, FMath::DegreesToRadians(vLonlat.X ));
				q2.Normalize();

				q2 = q2 * q1;

				xAxis = q2 * UNIT_Y;
				FQuat q3(xAxis, PI * 0.5f);
				q3.Normalize();
			   
				q3 = q3 * q2;

				FRotator rotator = q3.Rotator();
				return rotator;
			}

			void CameraControl::SetLocationAndRotationToPlayerControl(const FVector& location, const FRotator& rotation)
			{
				FTransform fTransform = FTransform(rotation, location);
				Matrix4d matRot(fTransform.ToMatrixWithScale());
				matRot = matRot * Core::Georeference::GetECEFtoGeoreference();
				FMatrix matfloatRot;
				Matrix4d::ToFMatrix(matRot, matfloatRot);
				fTransform.SetFromMatrix(matfloatRot);
				FVector vLocation = fTransform.GetLocation();
				FQuat qRotation = fTransform.GetRotation();
				vLocation -= FVector(m_vecWorldOrigin);

				if (CameraControl::m_eSceneType == UGC_EARTH ||
					CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					vLocation -= MathEngine::m_vWorldOffset;
				}

				if (m_pWorld->WorldType == EWorldType::Editor)
				{
				#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();
					FViewportClient* pViewportClient = pViewport->GetClient();
					FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);
					pEditorViewportClient->SetViewLocation(vLocation);
					pEditorViewportClient->SetViewRotation(FRotator(qRotation));
				#endif 
				}
				else
				{
					m_pCurrentPlayerControl->GetPawn()->SetActorLocation(vLocation);
					m_pCurrentPlayerControl->SetControlRotation(FRotator(qRotation));
				}
			}


			void CameraControl::FlyToBounds(FVector vLocal, FVector vLonLat)
			{
				if (CameraControl::m_eSceneType == UGC_PLANE)
				{
					FRotator rRotator;
					rRotator.Pitch = -90;
					rRotator.Yaw = 0;
					rRotator.Roll = 0;
					FVector vTemp = FVector(vLocal.X, vLocal.Y, vLocal.Z);
					SetLocationAndRotationToPlayerControl(vTemp, rRotator);
					
				}
				else if (CameraControl::m_eSceneType == UGC_EARTH ||
					CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{	
					FVector vTemp = FVector(vLocal.X, vLocal.Y, vLocal.Z);
					SetLocationAndRotationToPlayerControl(vTemp, CalRotation(vLonLat));
				}
			}


			void CameraControl::CameraOperation()
			{
				// 处于编辑模式下，就直接返回
				if (m_eEditMode == EDITING)
				{
					return;
				}
				if (CameraControl::m_eSceneType == UGC_EARTH || CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					if ((m_eCameraState == Moving && m_eCamMouseBtnState == MouseBtn_Left_Up) ||
						(m_eCameraState == Scaling && m_eCamMouseBtnState == MouseBtn_Right_Up) ||
						(m_eCameraState == Rotating && m_eCamMouseBtnState == MouseBtn_Middle_Up))
					{
						m_eCameraState = None;
						m_eCamMouseBtnState = MouseBtn_Nothing;
					}

					// 平移
					if (m_eCamMouseBtnState == MouseBtn_Left_Down)
					{
						PrepareCurrentStartMouse();
						m_eCameraState = Moving;
						m_eCamMouseBtnState = MouseBtn_Nothing;
					}
					else if (m_eCameraState == Moving)
					{
						// 平移操作
						PrepareCurrentEndMouse();
						Earth_Pan();
					}

					// 旋转
					if (m_eCamMouseBtnState == MouseBtn_Middle_Down)
					{
						LineTrace(false);
						PrepareCurrentStartMouse();
						ReCalOpCenterTilt();
						m_eCameraState = Rotating;
						m_eCamMouseBtnState = MouseBtn_Nothing;
					}
					else if (m_eCameraState == Rotating)
					{
						// 旋转
						PrepareCurrentEndMouse();
						Earth_Rotate();
						EndPointTOStartPoint();
					}

					// 滚轮缩放
					if (m_eCameraState != Scaling && m_fScrollFactor != 0.0f)
					{
						Earth_Scale();
						m_fScrollFactor = 0.0f;
					}
				}

				if (CameraControl::m_eSceneType == UGC_PLANE)
				{

					if ((m_eCameraState == Moving && m_eCamMouseBtnState == MouseBtn_Left_Up) ||
						(m_eCameraState == Scaling && m_eCamMouseBtnState == MouseBtn_Right_Up) ||
						(m_eCameraState == Rotating && m_eCamMouseBtnState == MouseBtn_Middle_Up))
					{
						m_eCameraState = None;
						m_eCamMouseBtnState = MouseBtn_Nothing;
					}

					// 平移
					if (m_eCamMouseBtnState == MouseBtn_Left_Down)
					{
						LineTrace();
						PrepareCurrentStartMouse();
						m_eCameraState = Moving;
						m_eCamMouseBtnState = MouseBtn_Nothing;

					}
					else if (m_eCameraState == Moving)
					{
						// 平移操作
						PrepareCurrentEndMouse();
						Plane_Pan();
						EndPointTOStartPoint();
					}

					// 旋转
					if (m_eCamMouseBtnState == MouseBtn_Middle_Down)
					{
						LineTrace();
						PrepareCurrentStartMouse();
						m_eCameraState = Rotating;
						m_eCamMouseBtnState = MouseBtn_Nothing;
					}
					else if (m_eCameraState == Rotating)
					{
						// 旋转
						PrepareCurrentEndMouse();
						Plane_Rotate();
						EndPointTOStartPoint();
					}


					// 缩放
					if (m_eCamMouseBtnState == MouseBtn_Right_Down)
					{
						LineTrace();
						PrepareCurrentStartMouse();

						m_eCameraState = Scaling;
						m_eCamMouseBtnState = MouseBtn_Nothing;
					}
					else if (m_eCameraState == Scaling)
					{
						// 缩放操作
						PrepareCurrentEndMouse();
						Plane_Scale();
					}

					// 滚轮缩放
					if (m_eCameraState != Scaling && m_fScrollFactor != 0.0f)
					{
						LineTrace();
						Plane_Scale();
						m_fScrollFactor = 0.0f;
					}
				}
			}

			float CameraControl::GetEarthCameraHeight()
			{
				FVector vRealCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotation(vRealCameraLocation, vCameraRotator);
				vRealCameraLocation = Georeference::TransformUERelativeToGeorefenceECEF(Vector3d(vRealCameraLocation)).ToFVector();
				float fCameraHeightByMeter;
				FVector vCurDir;
				vRealCameraLocation.ToDirectionAndLength(vCurDir, fCameraHeightByMeter);
				return fCameraHeightByMeter;
			}

			void CameraControl::Reset()
			{
				m_vecWorldOrigin = FIntVector(0, 0, 0);
				m_vecWorldOriginForRotate = FIntVector(0, 0, 0);

				if (m_pDepthRenderTarget != nullptr)
				{
					m_pDepthRenderTarget->RemoveFromRoot();
					m_pDepthRenderTarget = nullptr;
				}
			}

			void CameraControl::SetFov(Gamedouble dFov)
			{
				m_dFov = dFov;
			}

			Gamedouble CameraControl::GetFov()
			{
				Gamedouble fov = m_dFov;
				if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetMultiViewportMode() == Horizontal)
				{
					fov = m_dFov / 2;
				}
				return fov;
			}

			void CameraControl::TransformUERelativeToECEF(FVector& vLocation, FVector& vDirection)
			{
				if (CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					vLocation = Georeference::TransformUERelativeToOriginECEF(Vector3d(vLocation)).ToFVector();
					Vector3d v3dDirection = Vector3d(vDirection);
					vDirection = v3dDirection.MultiplyMatrix(Georeference::GetECEFtoGeoreference().Invert()).ToFVector();
				}
				else
				{
					vLocation = Georeference::TransformUERelativeToGeorefenceECEF(Vector3d(vLocation)).ToFVector();
				}
			}

			void CameraControl::TransformECEFToUERelative(FVector& vLocation, FVector& vDirection)
			{
				if (CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					vLocation = Georeference::TransformOriginECEFToUEReative(Vector3d(vLocation)).ToFVector();
					Vector3d v3dDirection = Vector3d(vDirection);
					vDirection = v3dDirection.MultiplyMatrix(Georeference::GetECEFtoGeoreference()).ToFVector();
				}
				else
				{
					vLocation = Georeference::TransformGeorefenceECEFToUERelative(Vector3d(vLocation)).ToFVector();
				}
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif