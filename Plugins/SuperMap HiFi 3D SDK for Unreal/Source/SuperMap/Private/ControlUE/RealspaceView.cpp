#include "ControlUE/RealspaceView.h"
#include "Engine/Engine.h"
#include "Camera/CameraTypes.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraActor.h"
#include "Engine/LocalPlayer.h"
#include "Engine/Public/SceneView.h"
#include "GameFramework/PlayerController.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Component/SuperMap_MeshComponentInterface.h"
#include "Component/SuperMap_StaticMeshActor.h"
#include "Component/SuperMap_InstancedActor.h"

#include "Component/SuperMap_ROEntityActor.h"
#include "Component/SuperMap_CustomVectorActor.h"
#include "Engine/TextureRenderTarget2D.h"

#include "Core/Public/Misc/Paths.h"
#include "ControlUE/CameraControl.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkyAtmosphereComponent.h"
#include "Renderer/Private/ScenePrivate.h"
#include "Base3D/CommonDefine.h"
#include "Core/Layer3D.h"
#include "Core/Layer3DType.h"
#include "Algorithm3D/MathEngine.h"
#include "Data/UnrealWorkspaceManager.h"
#if WITH_EDITOR
#include "Editor.h"
#include "LevelEditorViewport.h"
#endif
#include "Core/Georeference.h"
#include "Core/Public/Misc/EngineVersion.h"
#include "Graphics3D/GameCamera.h"
#include "Graphics3D/GameRenderTextureManager.h"
#include "Graphics3D/GameComponent.h"
#include "Graphics3D/GameEntity.h"
#include "Graphics3D/GameMaterialManager.h"
#include "Graphics3D/GameTexture.h"
#include "Graphics3D/GameTextureManager.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameEntityManager.h"
#include "Graphics3D/GameInstanceEntity.h"
#include "Component/SuperMap_SplineActor.h"
#include "Data/AssetLibrary.h"
#include "Core/JobScheduler.h"
#include "Core/FlyManager.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::Render;
using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace ControlUE
		{
			RealspaceView* RealspaceView::m_pRealspaceView = NULL;

			RealspaceView::RealspaceView()
			{
				SuperMapSDK::UnrealEngine::Core::RealspaceDLL::LoadAllAPI();

				m_pSceneControl = new Core::SceneControl();
				m_bInitial = false;
				m_bClipingAndOperateCamera = false;
				m_bOperateCamera = true;
				m_fTimeFromLastCollectionGarbage = 0.0f;
				m_pSelectedActor = nullptr;
				m_pMainCamera = nullptr;
				m_pWorld = nullptr;
				m_vGeoreferenceOrigin = FVector(0, 0, 0);
				m_nUpdateCount = 2;
				m_nWindowWidth = 0;
				m_nWindowHeight = 0;
			}

			RealspaceView::~RealspaceView()
			{
				if (m_pSceneControl != nullptr)
				{
					delete m_pSceneControl;
					m_pSceneControl = nullptr;
				}

				m_pRealspaceView = NULL;
				m_pSelectedActor = nullptr;
			}

			RealspaceView* RealspaceView::GetSingleton()
			{
				if (m_pRealspaceView == NULL)
				{
					m_pRealspaceView = new RealspaceView();
				}
				return m_pRealspaceView;
			}

			void RealspaceView::InitGraphics3DCallbackHandle()
			{
				GameComponent::InitializeCallbackHandle();
				GameEntity::InitializeCallbackHandle();
				GameMaterialManager::InitializeCallbackHandle();
				GameTexture::InitializeCallbackHandle();
				GameInstanceEntity::InitializeCallbackHandle();
			}

			void RealspaceView::SetMainCameraActor(ACameraActor* pMainCamera)
			{
				m_pMainCamera = pMainCamera;
			}

			ACameraActor* RealspaceView::GetMainCameraActor()
			{
				return m_pMainCamera;
			}

			bool RealspaceView::IsOwner(ACameraActor* pMainCamera)
			{
				return pMainCamera == m_pMainCamera;
			}

			void RealspaceView::DestroySingleton()
			{
				if (m_pRealspaceView != NULL)
				{
					delete m_pRealspaceView;
					m_pRealspaceView = NULL;
				}
			}

			void RealspaceView::MouseLeftButtonDown()
			{
				if (!m_bInitial)
				{
					return;
				}
				m_pSceneControl->GetSceneEditorWnd()->OnLButtonDown();
			}

			void RealspaceView::MouseLeftButtonUp()
			{
				if (!m_bInitial)
				{
					return;
				}
				m_pSceneControl->GetSceneEditorWnd()->OnLButtonUp();
			}

			void RealspaceView::MouseLeftButtonDoubleClick()
			{
				if (!m_bInitial)
				{
					return;
				}
				m_pSceneControl->GetSceneEditorWnd()->OnLButtonDblClk();
			}

			void RealspaceView::MouseRightButtonUp()
			{
				if (!m_bInitial)
				{
					return;
				}
				m_pSceneControl->GetSceneEditorWnd()->OnRButtonUp();
			}

			void RealspaceView::MouseRightButtonDown()
			{
				if (!m_bInitial)
				{
					return;
				}
				m_pSceneControl->GetSceneEditorWnd()->OnRButtonDown();
			}

			void RealspaceView::MouseMiddleButtonMove(float Value)
			{
				if (!m_bInitial)
				{
					return;
				}
				m_pSceneControl->GetSceneEditorWnd()->OnMouseWheel(Value);
			}

			void RealspaceView::MouseMiddleButtonUp()
			{
				if (!m_bInitial)
				{
					return;
				}
				m_pSceneControl->GetSceneEditorWnd()->OnMButtonUp();
			}

			void RealspaceView::MouseMiddleButtonDown()
			{
				if (!m_bInitial)
				{
					return;
				}
				m_pSceneControl->GetSceneEditorWnd()->OnMButtonDown();
			}

			void RealspaceView::Destroy(bool bQuitApplication)
			{
				if (m_pMainCamera != nullptr && m_pMainCamera->GetWorld() != nullptr)
				{
					m_pMainCamera->GetWorld()->SetNewWorldOrigin(FIntVector(0, 0, 0));
					m_pWorld = nullptr;
				}
				
				m_vWorldOrigin = FIntVector(0, 0, 0);
				SuperMapSDK::UnrealEngine::Core::ROCacheManager::m_vID = FLinearColor(-1.0f, -1.0f, -1.0f, -1.0f);

				SuperMapSDK::UnrealEngine::Core::ROCacheManager::m_vecWorldOrigin = FIntVector(0, 0, 0);
				SuperMapSDK::UnrealEngine::Core::Georeference::Reset();

				// 重置相机参数
				m_CameraControl.Reset();
		
				// 释放内存
				m_pSceneControl->ShutDown(bQuitApplication);

				// 释放数据内存
				SuperMapSDK::UnrealEngine::Core::ROCacheManager::Destroy();

				GameMaterialManager::GetSingleton()->DestorySingleton();
				GameTextureManager::GetSingleton()->DestorySingleton();
				GameObjectManager::GetSingleton()->DestorySingleton();
				GameEntityManager::GetSingleton()->DestorySingleton();
				
				//最后释放库，否则Linux下会崩溃
				AssetLibrary::GetSingleton()->DestroySingleton();
				m_pSelectedActor = nullptr;
				m_pWorld = nullptr;
				m_bInitial = false;
			}

			void RealspaceView::ReleaseROManager()
			{
				// 释放数据内存
				SuperMapSDK::UnrealEngine::Core::ROCacheManager::Destroy();
			}

			void RealspaceView::SetPosition(FVector & vPosition)
			{
				m_vOriginalPosition = vPosition;
			}

			bool RealspaceView::Initialize(ACameraActor* pMainCamera)
			{
				if (pMainCamera == nullptr)
				{
					return false;
				}
				m_pMainCamera = pMainCamera;

				// 创建一个场景捕捉器
				USceneCaptureComponent2D* pScene = NewObject<USceneCaptureComponent2D>(pMainCamera, FName("Capture2D"));
				pScene->AttachToComponent(pMainCamera->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
				pScene->FOVAngle = 60.0;
				pScene->bCaptureEveryFrame = 0;
				pScene->bCaptureOnMovement = 0;
				pScene->ShowFlags.SetFog(false);
				pScene->ShowFlags.SetAtmosphere(false);
				pScene->ShowFlags.SetAmbientOcclusion(false);
				
				Destroy(false);

				m_pWorld = m_pMainCamera->GetWorld();

				//导入资产库
				LoadAssetLibrary();

				CreateRenderTextureCallBack crtCallBack = CreateRenderTexture;
				DestoryRenderTextureCallBack drtCallBack = DestroyRenderTexture;
				GetFrameBufferCallBack gfbCallBack = GetFrameBuffer;
				DeleteFrameBufferCallBack dfbCallBack = DeleteFrameBuffer;
				UpdateSceneCallBack usCallBack = UpdateScene;
				SetRenderDepthCallBack setRenderDepth = SetRenderDepth;
				GetCameraCallBack getCameraCallBack = GetCamera;
				ClearFramebufferCallBack clearFramebufferCallBack = ClearFramebuffer;

				SetViewMatrixCallBack setViewMatrix = SetViewMatrix;
				SetProjMatrixCallBack setProjMatrix = SetProjMatrix;
				SetCameraParamCallBack setCameraParam = SetCameraParam;
				SetPositionCallBack setPosition = SetUGCPosition;
				SetLookAtCallBack setLookAt = SetLookAt;
				SetViewportRectCallBack setViewportRect = SetViewportRect;
				SetOrthoWindowCallBack setOrthoWindow = SetOrthoWindow;

				SetMainCameraViewMatrixCallBack setMainCameraViewMatrix = SetMainCameraViewMatrix;

				_InitDataBufferCallbackHandle((void*)dfbCallBack);
				_InitRenderTextureCallbackHandle((void*)crtCallBack, (void*)drtCallBack, (void*)gfbCallBack, (void*)usCallBack, (void*)setRenderDepth, (void*)getCameraCallBack, (void*)clearFramebufferCallBack);
				_InitCameraCallbackHandle((void*)setViewMatrix, (void*)setProjMatrix, (void*)setCameraParam, (void*)setPosition, (void*)setLookAt, (void*)setViewportRect, (void*)setOrthoWindow);
				_InitMainCameraCallbackHandle((void*)setMainCameraViewMatrix);
				
				InitGraphics3DCallbackHandle();

				m_pSceneControl->GetScene()->SetCameraControl(&m_CameraControl);
				m_pSceneControl->GetScene()->SetWorld(m_pWorld);

				// 设置世界场景
				Georeference::SetWorld(m_pWorld);
				GameObjectManager::GetSingleton()->SetWorld(m_pWorld);
				GameCameraManager::GetSingleton()->SetWorld(m_pWorld);
				GameTextureManager::GetSingleton()->SetWorld(m_pWorld);
				GameEntityManager::GetSingleton()->SetWorld(m_pWorld);
				GameMaterialManager::GetSingleton()->SetWorld(m_pWorld);
				GameObjectManager::GetSingleton()->SetScene(m_pSceneControl->GetScene());
				GameObjectManager::GetSingleton()->SetEnableCollision(SuperMapSDK::m_bEnableCollision);
				SuperMapSDK::UnrealEngine::Core::ROCacheManager::GetSingleton()->SetWorld(m_pWorld);
				SuperMapSDK::UnrealEngine::Core::ROCacheManager::GetSingleton()->SetSceneOpt(m_pSceneControl->GetScene());
				m_CameraControl.m_pWorld = m_pWorld;
				m_CameraControl.m_pCameraActor = m_pMainCamera;

				if (m_pWorld == nullptr) 
				{
					m_bInitial = false;
					return m_bInitial;
				}

				m_bInitial = InitialWindow();
				
				if (!m_bInitial)
				{
					return m_bInitial;
				}

				UpdatePlayerCameraManager();

				m_pPlayerController = m_pWorld->GetFirstPlayerController();
				if (m_pPlayerController != nullptr)
				{
					// 初始化相机的游戏控制器
					m_CameraControl.m_pCurrentPlayerControl = m_pPlayerController;
				}

				if (m_pSceneControl->GetScene()->GetSceneType() == Core::SceneType::Flat)
				{
					CameraControl::m_eSceneType = UGC_PLANE;
					Core::ROCacheManager::m_eSceneType = Core::SceneType::Flat;
				}
				else if(m_pSceneControl->GetScene()->GetSceneType() == Core::SceneType::Globe)
				{
					CameraControl::m_eSceneType = UGC_EARTH;
					Core::ROCacheManager::m_eSceneType = Core::SceneType::Globe;
				}
				else if(m_pSceneControl->GetScene()->GetSceneType() == Core::SceneType::Ellipsoid_WGS84)
				{
					CameraControl::m_eSceneType = UGC_EARTH_ELLIPSOID_WGS84;
					Core::ROCacheManager::m_eSceneType = Core::SceneType::Ellipsoid_WGS84;
				}

				// 初始化UGC场景
				m_pSceneControl->SetMultiTexture(false);
				m_bInitial = m_pSceneControl->InitializeScene(m_nWindowWidth, m_nWindowHeight);

				if (m_vGeoreferenceOrigin != FVector(0, 0, 0) && 
					(m_pSceneControl->GetScene()->GetSceneType() == Core::SceneType::Globe ||
						m_pSceneControl->GetScene()->GetSceneType() == Core::SceneType::Ellipsoid_WGS84))
				{
					SetGeoreferenceOrigin(m_vGeoreferenceOrigin.X, m_vGeoreferenceOrigin.Y, m_vGeoreferenceOrigin.Z);
				}
				return m_bInitial;
			}

			bool RealspaceView::IsInitialized()
			{
				return m_bInitial;
			}

			void RealspaceView::UpdateRotationAndLocation(Vector3d &vLocation, FRotator &vRotator, Matrix4d mat4d)
			{
				FTransform currentTrans;
				currentTrans.SetLocation(vLocation.ToFVector());
				currentTrans.SetRotation(vRotator.Quaternion());

				Matrix4d mat(currentTrans.ToMatrixWithScale());
				mat = mat * mat4d;

				FMatrix matf;
				Matrix4d::ToFMatrix(mat, matf);
				currentTrans.SetFromMatrix(matf);

				vLocation = Vector3d(currentTrans.GetLocation());
				vRotator  = currentTrans.GetRotation().Rotator();
			}

			void RealspaceView::SyncUGCCam()
			{
				Gameint nWidth = 0;
				Gameint nHeight = 0;
				Vector3d vCameraLocation = m_CameraControl.m_vCameraLocation;
				FRotator vCameraRotator = m_CameraControl.m_vCameraRotator;
				float fNearClipPlane = 0;
				float fFarClipPlane = 0;

				if (m_pMainCamera->GetWorld()->WorldType == EWorldType::Editor)
				{
				#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();
					FViewportClient* pViewportClient = pViewport->GetClient();
					FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);

					nWidth = pEditorViewportClient->Viewport->GetSizeXY().X;
					nHeight = pEditorViewportClient->Viewport->GetSizeXY().Y;

					// FOV
					Gamefloat fFov = pEditorViewportClient->FOVAngle;

					// 屏幕纵横比
					Gamefloat fAspect = pEditorViewportClient->AspectRatio;

					// 近裁剪面
					fNearClipPlane = pEditorViewportClient->GetNearClipPlane();

					// 远裁剪面 TODO
					fFarClipPlane = 1000000000000000;
				#endif
				}
				else
				{
					UCameraComponent* pCameraComponent = m_pMainCamera->GetCameraComponent();
					//
					FMinimalViewInfo viewInfo;
					pCameraComponent->GetCameraView(0, viewInfo); // ?

					// FOV
					Gamefloat fFov = viewInfo.FOV;

					// 屏幕纵横比
					Gamefloat fAspect = viewInfo.AspectRatio;

					// 近裁剪面
					fNearClipPlane = viewInfo.OrthoNearClipPlane;

					if (CameraControl::m_eSceneType == UGC_EARTH || 
						CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
					{
						fNearClipPlane = 0.3;
					}

					// 远裁剪面
					fFarClipPlane = viewInfo.OrthoFarClipPlane * (float)1000000000000000;

					APlayerController* pPlayerController = m_pWorld->GetFirstPlayerController();

					nWidth = m_pWorld->GetGameViewport()->Viewport->GetSizeXY().X;
					nHeight = m_pWorld->GetGameViewport()->Viewport->GetSizeXY().Y;
					if (m_pSceneControl->GetScene()->GetMultiViewportMode() == Horizontal)
					{
						nWidth /= 2;
					}
					APlayerCameraManager* pPlayerCameraManager = pPlayerController->PlayerCameraManager;
					m_pMainCamera->SetActorLocationAndRotation(vCameraLocation.ToFVector(), vCameraRotator);
				
					if (pCameraComponent != NULL)
					{
						fAspect = (nWidth * 1.0f) / (nHeight * 1.0f);
						pCameraComponent->SetAspectRatio(fAspect);
					}
				
				}
				Gamefloat fov = m_CameraControl.GetFov();
				Gamefloat aspect = (nWidth * 1.0f) / (nHeight * 1.0f);
				fov = 2 * FMath::RadiansToDegrees(FMath::Atan(FMath::Tan((FMath::DegreesToRadians(fov) * 0.5)) * aspect));

				if (CameraControl::m_eSceneType == UGC_EARTH ||
					CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					Georeference::TransformUERelativeToOriginECEF(vCameraLocation, vCameraRotator);
				}
				else if (CameraControl::m_eSceneType == UGC_PLANE)
				{
					vCameraLocation = Georeference::TransformUERelativeToUEAbs(vCameraLocation);
					vCameraLocation *= CM_TO_M;
				}

				// 获取视图矩阵
				FVector vCameraLocationF = vCameraLocation.ToFVector();
				Swap(vCameraLocationF.X, vCameraLocationF.Y);
				FQuat qQuat = vCameraRotator.Quaternion();
				FVector vUp = qQuat.GetUpVector();
				vUp.Normalize();
				Swap(vUp.X, vUp.Y);
				FVector vRight = qQuat.GetRightVector();
				vRight.Normalize();
				Swap(vRight.X, vRight.Y);
				FMatrix matRoationXY = FRotationMatrix::MakeFromYZ(vRight, vUp);
				vCameraRotator = matRoationXY.Rotator();
				FViewMatrices viewMatrices;
				viewMatrices.UpdateViewMatrix(vCameraLocationF, vCameraRotator);
				FMatrix mat = viewMatrices.GetViewMatrix();

				Gamefloat* mats = new Gamefloat[16];

				for (Gameint i = 0; i < 4; i++)
				{
					for (Gameint j = 0; j < 4; j++)
					{
						mats[i * 4 + j] = mat.M[i][j];
					}
				}

				m_pSceneControl->GetScene()->SetCamera(mats, fNearClipPlane, fFarClipPlane, fov, aspect);

				delete[] mats;
			}

			void RealspaceView::SetCameraLocationAndRotator(Vector3d vLocation, FRotator vRotator)
			{
				if (m_pMainCamera->GetWorld()->WorldType == EWorldType::Editor)
				{
				#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();
					FViewportClient* pViewportClient = pViewport->GetClient();
					FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);
					pEditorViewportClient->SetViewLocation(vLocation.ToFVector());
					pEditorViewportClient->SetViewRotation(vRotator);
				#endif
				}
				else
				{
					m_pPlayerController->GetPawn()->SetActorLocation(vLocation.ToFVector());
					m_pPlayerController->SetControlRotation(vRotator);
				}
			}

			void RealspaceView::GetCameraLocationAndRotator(Vector3d &vLocation, FRotator &vRotator)
			{
				// 根据相机的距离
				FVector vCameraLocation;
				FRotator vCameraRotator;
				if (m_pMainCamera->GetWorld()->WorldType == EWorldType::Editor)
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
					m_pPlayerController->GetPlayerViewPoint(vCameraLocation, vCameraRotator);
				}

				vLocation = Vector3d(vCameraLocation);
				vRotator = vCameraRotator;
			}

			void RealspaceView::UpdateOriginWorldCerter()
			{
				// 根据相机的距离
				Vector3d vCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotator(vCameraLocation, vCameraRotator);

				Vector3d vCameraWorld = vCameraLocation + Vector3d(m_pWorld->OriginLocation);
				if (CameraControl::m_eSceneType == UGC_EARTH ||
					CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
				{
					vCameraWorld += Vector3d(MathEngine::m_vWorldOffset);
				}
				Gamedouble dCameraDistance = vCameraWorld.Magnitude();

				if ((FMath::Abs(vCameraWorld.X) > INT32_MAX || FMath::Abs(vCameraWorld.Y) > INT32_MAX || FMath::Abs(vCameraWorld.Z) > INT32_MAX) && CameraControl::m_eSceneType == UGC_PLANE)
				{
					return;
				}

				Vector3d vWorldOriginArea(WORLD_ORIGIN_AREA, WORLD_ORIGIN_AREA, WORLD_ORIGIN_AREA);

				if ((CameraControl::m_eSceneType == UGC_PLANE && vCameraLocation > vWorldOriginArea)
					|| ((CameraControl::m_eSceneType == UGC_EARTH || CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84) && dCameraDistance < 6388137.0f * M_TO_CM && (FMath::Abs(vCameraLocation.X) > WORLD_ORIGIN_AREA || FMath::Abs(vCameraLocation.Y) > WORLD_ORIGIN_AREA || FMath::Abs(vCameraLocation.Z) > WORLD_ORIGIN_AREA)))
				{
					m_CameraControl.m_vCameraLocation += Vector3d(m_pWorld->OriginLocation);
					vCameraLocation += Vector3d(m_pWorld->OriginLocation);
					FIntVector vOffsetInt;
					vOffsetInt = FIntVector(vCameraLocation.X, vCameraLocation.Y, vCameraLocation.Z);
					m_pWorld->SetNewWorldOrigin(vOffsetInt);

					FVector vOffset(vOffsetInt.X, vOffsetInt.Y, vOffsetInt.Z);
					Core::ROCacheManager::m_vecWorldOrigin = vOffsetInt;
					m_CameraControl.m_vecWorldOrigin = vOffsetInt;
					m_vWorldOrigin = vOffsetInt;
					m_CameraControl.m_vCameraLocation -= Vector3d(m_pWorld->OriginLocation);

					// 更新大气
					uint16 nVersionMajor = FEngineVersion::Current().GetMajor();
					uint16 nVersionMinor = FEngineVersion::Current().GetMinor();

					if (nVersionMajor == 4 && nVersionMinor == 25)
					{
						if (((FScene*)(m_pWorld->Scene))->SkyAtmosphereStack.Num() > 0)
						{
							FSkyAtmosphereSceneProxy* pSceneProxy = ((FScene*)(m_pWorld->Scene))->SkyAtmosphereStack[0];
							FTransform trans;
							trans.SetLocation(-vOffset);

							if (CameraControl::m_eSceneType == UGC_PLANE)
							{
								pSceneProxy->UpdateTransform(trans, uint8((ESkyAtmosphereTransformMode::PlanetTopAtAbsoluteWorldOrigin)));
							}
							else
							{
								pSceneProxy->UpdateTransform(trans, uint8((ESkyAtmosphereTransformMode::PlanetTopAtComponentTransform)));
							}
						}
					}
					#if WITH_EDITOR
					if (m_pMainCamera->GetWorld()->WorldType == EWorldType::Editor)
					{
						FViewport* pViewport = GEditor->GetActiveViewport();
						FViewportClient* pViewportClient = pViewport->GetClient();
						FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);
						pEditorViewportClient->SetViewLocation(m_CameraControl.m_vCameraLocation.ToFVector());
					}
					#endif

					// 更新渲染节点
					GameObjectManager::GetSingleton()->UpdateWorldOrigin(Vector3d(vOffsetInt));

					UpdateInstancedActor();

					// 更新图层分析
					Gameint nCount = m_pSceneControl->GetScene()->GetLayer3Ds()->Count();
					for (Gameint n = 0 ; n < nCount; n++)
					{
						Layer3D* pLayer3D = m_pSceneControl->GetScene()->GetLayer3Ds()->GetAt(n);
						if(pLayer3D)
						{
							pLayer3D->UpdateClipParam();
						}
					}
				}
			}


			CameraControl* RealspaceView::GetCameraControl()
			{
				return &m_CameraControl;
			}

			void RealspaceView::SetMIDScalarParameterValue(AActor* pActor, float fScalar)
			{
			#if WITH_EDITOR	
				ASuperMap_StaticMeshActor* pStaticMeshActorSelected = Cast<ASuperMap_StaticMeshActor>(pActor);
				TMap<FString, UMaterialInstanceConstant*>::TIterator itor = pStaticMeshActorSelected->m_mapMaterials.CreateIterator();
				for (;itor;++itor)
				{
					UMaterialInstanceConstant* pMIC = itor->Value;
					if (pMIC != nullptr)
					{
						pMIC->SetScalarParameterValueEditorOnly(TEXT("Selection"), fScalar);
					}
				}
			#endif
			}

			void RealspaceView::SelectActor()
			{
				if (m_pWorld->WorldType == EWorldType::PIE)
				{
					// 射线求交
					FVector2D vMouse;
					m_pPlayerController->GetMousePosition(vMouse.X, vMouse.Y);

					if (m_pSceneControl->GetScene()->GetMultiViewportMode() == Horizontal && vMouse.X > m_CameraControl.m_nScreenWidth)
					{
						vMouse.X -= m_CameraControl.m_nScreenWidth;
					}

					FVector vWorld;
					FVector vDirection;
					UGameplayStatics::DeprojectScreenToWorld(m_pPlayerController, vMouse, vWorld, vDirection);

					// 
					FVector vStart = vWorld;
					FVector vEnd = vWorld + (vDirection * 1000000000000.0f);

					FHitResult hitResult;
					bool bHit = m_pWorld->LineTraceSingleByChannel(hitResult, vStart, vEnd, ECC_Visibility);
					if (bHit)
					{
					#if !SM_FOR_UE_FIVE
						AActor* pActor = Cast<ASuperMap_StaticMeshActor>(hitResult.Actor);
					#else
						AActor* pActor = Cast<ASuperMap_StaticMeshActor>(hitResult.GetActor());
					#endif
						if (m_pSelectedActor != pActor)
						{
							if (m_pSelectedActor != nullptr)
							{
								SetMIDScalarParameterValue(m_pSelectedActor, 0);
							}

							if (pActor->ActorHasTag(TEXT("SM_UDB")))
							{
								ASuperMap_StaticMeshActor* pStaticMeshActor = Cast<ASuperMap_StaticMeshActor>(pActor);
								pStaticMeshActor->m_bSelected = true;

								SetMIDScalarParameterValue(pActor, 1);
							}

							m_pSelectedActor = pActor;
						}
					}
					else
					{
						if (m_pSelectedActor != nullptr)
						{
							SetMIDScalarParameterValue(m_pSelectedActor, 0);
						}

						m_pSelectedActor = nullptr;
					}
				}

			}

			void RealspaceView::SetGeoreferenceOrigin(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude)
			{
				m_vGeoreferenceOrigin = Vector3d(dLongitude, dLatitude, dAltitude);

				// 只有球面有效
				if (CameraControl::m_eSceneType == UGC_PLANE || m_pMainCamera == nullptr)
				{
					return;
				}
				Vector3d vCameraLocation;
				FRotator vCameraRotator;
				GetCameraLocationAndRotator(vCameraLocation, vCameraRotator);

				Vector3d vCameraWorld = vCameraLocation + Vector3d(m_pWorld->OriginLocation) + MathEngine::m_vWorldOffset;

				if (CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84 && (dLongitude != 0 || dLatitude != 0 || dAltitude != 0))
				{
					Gamedouble Radius = MathEngine::GetEllipsoidRadius(dLongitude, dLatitude, 0.0);
					MathEngine::m_vWorldOffset = FVector(0, 0, Radius * M_TO_CM);
				}

				Matrix4d oldWorldRotate(Core::Georeference::GetECEFtoGeoreference());
				Georeference::SetGeoreferenceOrigin(dLongitude, dLatitude, dAltitude);
				
				// 计算相机偏移位置
				Matrix4d mat4dCameraRot = oldWorldRotate.Invert() * Core::Georeference::GetECEFtoGeoreference();
				UpdateRotationAndLocation(vCameraWorld , vCameraRotator , mat4dCameraRot);

				m_CameraControl.m_vCameraLocation = vCameraWorld - Vector3d(ROCacheManager::m_vecWorldOrigin) - MathEngine::m_vWorldOffset;
				m_CameraControl.m_vCameraRotator  = vCameraRotator;


				SetCameraLocationAndRotator(m_CameraControl.m_vCameraLocation, m_CameraControl.m_vCameraRotator);

				// 旋转渲染网格
				GameObjectManager::GetSingleton()->UpdateWorldOrigin(m_pWorld->OriginLocation);

				UpdateInstancedActor();

				// 旋转数据集
				if (m_pMainCamera->GetWorld()->WorldType == EWorldType::PIE)
				{
					// 找到所有的静态的网格保存文件
					TArray<AActor*> arrActors;
					UGameplayStatics::GetAllActorsWithTag(m_pMainCamera->GetWorld(), FName(TEXT("SM_UDB")), arrActors);

					int32 nCount = arrActors.Num();
					for (int32 n = 0; n < nCount; n++)
					{
						ASuperMap_StaticMeshActor* pActor = (ASuperMap_StaticMeshActor*)arrActors[n];
						if (pActor != nullptr)
						{
							int32 nMatrixCount = pActor->m_arrMatrixs.Num();
							for (int32 nMatrix = 0; nMatrix < nMatrixCount; nMatrix++)
							{
								FMatrix matf = pActor->m_arrMatrixs[nMatrix];

								Matrix4d matd(matf);

								matd[3][0] *= M_TO_CM;
								matd[3][1] *= M_TO_CM;
								matd[3][2] *= M_TO_CM;

								matd = matd * Georeference::GetECEFtoGeoreference();

								matd[3][0] -= FVector(ROCacheManager::m_vecWorldOrigin).X;
								matd[3][1] -= FVector(ROCacheManager::m_vecWorldOrigin).Y;
								matd[3][2] -= FVector(ROCacheManager::m_vecWorldOrigin).Z;

								Matrix4d::ToFMatrix(matd, matf);

								FTransform transform;
								transform.SetFromMatrix(matf);
								pActor->StaticMeshComponents[nMatrix]->SetWorldTransform(transform);
							}
						}
					}
				}
				
			}

			Vector3d RealspaceView::GetGeoreferenceOrigin()
			{
				return m_vGeoreferenceOrigin;
			}

			void RealspaceView::UpdateSkyAtmosphere()
			{
				// 获取场景里面天空大气
				ASkyAtmosphere* pSkyActor = (ASkyAtmosphere*)UGameplayStatics::GetActorOfClass(GetWorld(), ASkyAtmosphere::StaticClass());

				if (pSkyActor)
				{
					USkyAtmosphereComponent* pSkyAtmosphereComponent = pSkyActor->GetComponent();

					Vector3d vLocation = m_CameraControl.m_vCameraLocation;
					Vector3d vOrigin = Georeference::TransformUERelativeToOriginECEF(vLocation);
					Vector3d vLonLat = MathEngine::CartesianToSpherical(vOrigin.X, vOrigin.Y, vOrigin.Z);

					Gamedouble maxRadius = 6387000.0;
					Gamedouble dMaxGroundThreshold = 100.0;
					Gamedouble dMinGroundThreshold = 30.0;
					if (vLonLat.Z / 1000.0 > dMaxGroundThreshold) {
						//this->SetSkyAtmosphereGroundRadius(this->SkyAtmosphere, maxRadius / 1000.0);
						pSkyAtmosphereComponent->BottomRadius = 6387.0;
						pSkyAtmosphereComponent->MarkRenderStateDirty();
					}
					else {
						Vector3d vECEF = MathEngine::SphericalToCartesian2(vLonLat.X, vLonLat.Y, -100.0);
						Gamedouble minRadius = vECEF.Magnitude();

						if (vLonLat.Z / 1000.0 < dMinGroundThreshold) {
							pSkyAtmosphereComponent->BottomRadius = minRadius / 1000.0;
							pSkyAtmosphereComponent->MarkRenderStateDirty();
						}
						else {
							Gamedouble t =
								((vLonLat.Z / 1000.0) - dMinGroundThreshold) /
								(dMaxGroundThreshold - dMinGroundThreshold);
							Gamedouble radius = minRadius + t * (maxRadius - minRadius);
							pSkyAtmosphereComponent->BottomRadius = radius / 1000.0;
							pSkyAtmosphereComponent->MarkRenderStateDirty();
						}
					}
				}
				
			}

			void RealspaceView::AsyncComponent()
			{
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
					return;
				}

				Gameint nCount = m_nUpdateCount;
				if (m_CameraControl.m_eCameraState == None)
				{
					nCount = 20;
				}
				JobScheduler::GetSingleton()->Start();
				TArray<Gamelong> arrRemoves;

				GameObjectListNode* pHead = GameObjectManager::GetSingleton()->GetUnInitialListNode();
				while (pHead)
				{
					GameComponent* pGameComponent = pHead->m_pGameComponent;

					if (pGameComponent->GetEntity()->Type() == ET_INSTANCE)
					{
						TArray<GameMaterial*>& arrMaterials = pGameComponent->GetAllGameMaterial();
						if (arrMaterials.Num() > 0)
						{
							arrMaterials[0]->UpdateTextureParam();

							if (arrMaterials[0]->GetNumUnsetTexture() == 0)
							{
								Gameint nInstanceSize = ((GameInstanceEntity*)pGameComponent->GetEntity())->m_nInstanceSize;
								Gameint nSizeInFloatPerInstance = ((GameInstanceEntity*)pGameComponent->GetEntity())->m_nSizeInFloatPerInstance;
								Gamevoid* pValue = ((GameInstanceEntity*)pGameComponent->GetEntity())->m_pValue;

								pGameComponent->InitInstanceMesh(nInstanceSize, nSizeInFloatPerInstance, pValue);

								nCount--;
								GameObjectManager::GetSingleton()->RemoveUnitialComponent(pGameComponent);
								pHead = GameObjectManager::GetSingleton()->GetUnInitialListNode();

								JobScheduler::GetSingleton()->End();
								if (nCount == 0 || JobScheduler::GetSingleton()->IsFinish())
								{
									break;
								}

								continue;
							}
						}
					}
					else {
						if (((GameEntity*)pGameComponent->GetEntity())->GetAsyncLoading())
						{
							TArray<GameMaterial*>& arrMaterials = pGameComponent->GetAllGameMaterial();
							if (arrMaterials.Num() > 0)
							{
								// 初始化材质
								arrMaterials[0]->InitMaterial();
								arrMaterials[0]->UpdateTextureParam();

								if (arrMaterials[0]->GetNumUnsetTexture() == 0)
								{
									// 给图层添加组件
									pGameComponent->UpdateMaterialForAsync(arrMaterials[0]);
									m_pSceneControl->GetScene()->AddNativeGameComponent(pGameComponent);

									pGameComponent->AsyncMesh();
									nCount--;
									GameObjectManager::GetSingleton()->RemoveUnitialComponent(pGameComponent);
									pHead = GameObjectManager::GetSingleton()->GetUnInitialListNode();

									JobScheduler::GetSingleton()->End();
									if (nCount == 0 || JobScheduler::GetSingleton()->IsFinish())
									{
										break;
									}

									continue;
								}
							}
						}
					}
					
					break;
				}
			}

			void RealspaceView::Render(float DeltaTime)
			{
				if (!m_bInitial)
				{
					Initialize(m_pMainCamera);
				}

				if (!m_bInitial)
				{
					return;
				}

				int32 nWidth = 0, nHeight = 0;
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
				#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();
					FViewportClient* pViewportClient = pViewport->GetClient();
					FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);
					m_CameraControl.m_vCameraLocation = Vector3d(pEditorViewportClient->GetViewLocation());
					m_CameraControl.m_vCameraRotator = pEditorViewportClient->GetViewRotation();
				#endif
				}
				else
				{
					FVector vCL;
					FRotator fRotator;
					//vCL = m_pPlayerController->GetPawn()->GetActorLocation();
					//fRotator = m_pPlayerController->GetControlRotation();

					vCL = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetOwningPlayerController()->GetPawn()->GetActorLocation();
					fRotator = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetOwningPlayerController()->GetPawn()->GetControlRotation();

					m_CameraControl.m_vCameraLocation = vCL;
					m_CameraControl.m_vCameraRotator = fRotator;
				}

				OnWindowResize();

				UpdatePlayerCameraManager();

				// 动态更改世界原点
#if !SM_FOR_UE_FIVE
				if (m_pWorld->WorldType != EWorldType::Editor)
				{
					UpdateOriginWorldCerter();
				}
#endif
				// 设置UGC的相机
				if (m_CameraControl.GetEditMode() != CMEditMode::ROAM)
				{
					m_CameraControl.CameraOperation();
					SyncUGCCam();
				}

				if (m_pWorld->WorldType != EWorldType::Editor)
				{
					UpdateSkyAtmosphere();
				}

				m_pSceneControl->Render();

				m_pSceneControl->GetScene()->Render();

				AsyncComponent();

				Gamedouble dCurrentProgressTime = -1;
				if (m_CameraControl.GetEditMode() == CMEditMode::ROAM)
				{
					dCurrentProgressTime = m_pSceneControl->GetScene()->GetFlyManager()->GetCurrentProgress();
					m_pSceneControl->GetScene()->GetCameraState()->SyncMainCam(&m_CameraControl);
					Vector3d vCameraLocation = m_CameraControl.m_vCameraLocation;
					FRotator vCameraRotator = m_CameraControl.m_vCameraRotator;
					m_pMainCamera->SetActorLocationAndRotation(vCameraLocation.ToFVector(), vCameraRotator);
				}

				m_CameraControl.m_eCamMouseBtnState = MouseBtn_Nothing;

				m_fTimeFromLastCollectionGarbage += DeltaTime;
				if ((m_CameraControl.m_eCameraState == None && m_fTimeFromLastCollectionGarbage > 20.0f) || 
					(m_CameraControl.GetEditMode() == CMEditMode::ROAM && dCurrentProgressTime == 0))
				{
					FMemory::Trim();
					GEngine->ConditionalCollectGarbage();
					m_fTimeFromLastCollectionGarbage = 0.0f;
				}

				GameTextureManager::GetSingleton()->AsyncUpdateTextureCache();
			}

			Core::SceneControl* RealspaceView::GetSceneControl()
			{
				return m_pSceneControl;
			}

			EWorldType::Type RealspaceView::GetWorldType()
			{
				if (m_pWorld == nullptr)
				{
					return EWorldType::None;
				}
				return m_pWorld->WorldType;
			}

			UWorld* RealspaceView::GetWorld()
			{
				return m_pWorld;
			}

			AActor* RealspaceView::GetSelectedActor()
			{
				return m_pSelectedActor;
			}

			void RealspaceView::SetEnableCollision(Gamebool bEnable)
			{
				GameObjectManager::GetSingleton()->SetEnableCollision(bEnable);
				SuperMapSDK::m_bEnableCollision = bEnable;
			}

			Gamevoid RealspaceView::GetWindowSize(Gameint & nWidth, Gameint & nHeight)
			{
				if (m_pWorld->WorldType == EWorldType::Editor)
				{
#if WITH_EDITOR
					FViewport* pViewport = GEditor->GetActiveViewport();
					nWidth = pViewport->GetSizeXY().X;
					nHeight = pViewport->GetSizeXY().Y;
#endif
				}
				else
				{
					if (m_pWorld->GetGameViewport() != nullptr)
					{
						nWidth = m_pWorld->GetGameViewport()->Viewport->GetSizeXY().X;
						nHeight = m_pWorld->GetGameViewport()->Viewport->GetSizeXY().Y;
					}
				}
			}

			Gamebool RealspaceView::InitialWindow()
			{
				Gameint nWidth  = 0;
				Gameint nHeight = 0;
				
				GetWindowSize(nWidth, nHeight);
				
				if (nWidth == 0 || nHeight == 0)
				{
					return false;
				}

				m_nWindowWidth = nWidth;
				m_nWindowHeight = nHeight;

				return true;
			}

			Gamevoid RealspaceView::UpdatePlayerCameraManager()
			{
				Gameint nWidth = m_nWindowWidth;
				Gameint nHeight = m_nWindowHeight;

				Gamefloat fov = m_CameraControl.GetFov();
				if (m_pSceneControl->GetScene()->GetMultiViewportMode() == Horizontal)
				{
					nWidth /= 2;
				}
				m_CameraControl.m_nScreenWidth = nWidth;
				m_CameraControl.m_nScreenHeight = nHeight;
				
				APlayerController* pPlayerController = m_pWorld->GetFirstPlayerController();
				if (pPlayerController != nullptr)
				{
					APlayerCameraManager* pPlayerCameraManager = pPlayerController->PlayerCameraManager;
					pPlayerCameraManager->SetFOV(fov);
					Gamefloat aspect = (nWidth * 1.0f) / (nHeight * 1.0f);
					FMinimalViewInfo view = pPlayerCameraManager->GetCameraCachePOV();
					view.AspectRatio = aspect;
					view.FOV = fov;
					pPlayerCameraManager->SetCameraCachePOV(view);
					UCameraComponent* pCameraComponent = m_pMainCamera->GetCameraComponent();
					if (pCameraComponent != NULL)
					{
						pCameraComponent->SetFieldOfView(fov);
						pCameraComponent->SetAspectRatio(aspect);
					}
				}
			}

			Gamevoid RealspaceView::OnWindowResize()
			{
				Gameint nWidth  = 0;
				Gameint nHeight = 0;

				GetWindowSize(nWidth, nHeight);

				if (m_nWindowWidth != nWidth || m_nWindowHeight != nHeight)
				{
					_SceneControl_OnSize(nWidth, nHeight);
				}

				m_nWindowHeight = nHeight;
				m_nWindowWidth = nWidth;
			}

			void RealspaceView::LoadAssetLibrary()
			{
				FString strLevelName = m_pWorld->GetMapName();
				FString strPrefix = m_pWorld->StreamingLevelsPrefix;
				strLevelName.RemoveFromStart(strPrefix);
				FString strPathMaterials = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName + TEXT("/AutomaticMatchingMaterials.json");
				FString strPathPluginModel = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName + TEXT("/AutomaticMatchingTree.json");
				FString strPathS3MLayersMaterial = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName + TEXT("/AutomaticMatchingMaterials_S3M.json");
				AssetLibrary::GetSingleton()->LoadAutomaticMatchingMaterials(strPathMaterials, TEXT("材质种类"));
				AssetLibrary::GetSingleton()->LoadAutomaticMatchingPluginModel(strPathPluginModel, TEXT("树木种类"));
				AssetLibrary::GetSingleton()->LoadAutomaticMatchingS3MMaterial(strPathS3MLayersMaterial);
			}

			void RealspaceView::SetEnableComputeNormal(Gamebool bEnable)
			{
				SuperMapSDK::m_bEnableNormal = bEnable;
			}

			void RealspaceView::SetUpdateCount(Gameint nCount)
			{
				m_nUpdateCount = nCount;
			}

			void RealspaceView::UpdateInstancedActor()
			{
				// 旋转实例化
				TMap<uint32, ASuperMap_InstancedActor*>& mapInstancedActor = GameObjectManager::GetSingleton()->GetInstancedActors();
				for (TMap<uint32, ASuperMap_InstancedActor*>::TConstIterator itorInstancedActor = mapInstancedActor.CreateConstIterator(); itorInstancedActor; ++itorInstancedActor)
				{
					ASuperMap_InstancedActor* pInstanceActor = itorInstancedActor->Value;
					if (pInstanceActor != nullptr)
					{
						pInstanceActor->UpdateWorldOrigin();
					}
				}
				TMap<uint32, ASuperMap_SplineActor*>& mapSplineActor = GameObjectManager::GetSingleton()->GetSplineActors();
				for (TMap<uint32, ASuperMap_SplineActor*>::TConstIterator itorSplineActor = mapSplineActor.CreateConstIterator(); itorSplineActor; ++itorSplineActor)
				{
					ASuperMap_SplineActor* pSplineActor = itorSplineActor->Value;
					if (pSplineActor != nullptr)
					{
						pSplineActor->UpdateWorldOrigin();
					}
				}
				TArray<ASuperMap_CustomVectorActor*>& arrVectorActor = GameObjectManager::GetSingleton()->GetVectorActors();
				for (Gameint i = 0; i < arrVectorActor.Num(); i++)
				{
					ASuperMap_CustomVectorActor* pVectorActor = arrVectorActor[i];
					pVectorActor->UpdateWorldOrigin();

				}
				TArray<ASuperMap_ROEntityActor*>& arrLineMeshActors = GameObjectManager::GetSingleton()->GetLineMeshActors();
				for (Gameint lineMesh = 0; lineMesh < arrLineMeshActors.Num(); lineMesh++)
				{
					ASuperMap_ROEntityActor* pLineMeshActor = arrLineMeshActors[lineMesh];
					pLineMeshActor->UpdateWorldOrigin();
				}
				TArray<ASuperMap_TextActor*>& arrTextActors = GameObjectManager::GetSingleton()->GetTextActors();
				for (Gameint text = 0; text < arrTextActors.Num(); text++)
				{
					ASuperMap_TextActor* pTextActor = arrTextActors[text];
					pTextActor->UpdateWorldOrigin();
				}
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif