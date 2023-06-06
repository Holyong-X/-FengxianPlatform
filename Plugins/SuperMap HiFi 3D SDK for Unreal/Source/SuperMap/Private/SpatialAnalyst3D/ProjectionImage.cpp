#include "SpatialAnalyst3D/ProjectionImage.h"
#include "Engine/World.h"
#include "Core/ROCache.h"
#include "Base3D/CommonDefine.h"
#include "Component/SuperMap_MeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Core/ROCacheManager.h"
#include "Core/ROCache.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Algorithm3D/MathEngine.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameRenderTexture.h"
#include "Graphics3D/GameRenderTextureManager.h"

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst3D
		{

			ProjectionImage::ProjectionImage(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl) : Analyst3D(pWorld, pScene, pCameraControl)
			{
				m_vViewerPosition = FVector(0.0f, 0.0f, 0.0f);
				m_Direction = 0.0f;
				m_Pitch = 0.0f;

				m_bUpdate = false;
				m_bEnable = false;
				m_eAnalyzeMode = Projection_Image;
				m_pUGProjectionImage = nullptr;
				m_pProjectionTexture = nullptr;

				_CreateProjectionImage(m_pUGProjectionImage);
			}

			ProjectionImage::~ProjectionImage()
			{
				Release();
				_DestroyProjectionImage(m_pUGProjectionImage);
			}

			void ProjectionImage::Release()
			{
				if (m_pProjectionTexture != nullptr)
				{
					m_pProjectionTexture->RemoveFromRoot();
					m_pProjectionTexture->MarkPendingKill();
					m_pProjectionTexture = nullptr;
				}
			}

			void ProjectionImage::DoBuild()
			{
				m_bEnable = true;
				m_bUpdate = true;
				_BuildProjectionImage(m_pUGProjectionImage);
			}

			void ProjectionImage::DoClear()
			{
				m_bEnable = false;
				m_bUpdate = true;
				UpdateShaderUniforms();
			}

			void ProjectionImage::Render()
			{
				if (m_bUpdate)
				{
					_ProjectionImageRender(m_pUGProjectionImage);

					UpdateCamera();
					UpdateShaderUniforms();
				}
				m_bUpdate = false;
			}

			void ProjectionImage::SetViewerPosition(Vector3d pos)
			{
				Vector3d vNewPos = pos;
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					vNewPos.X = pos.Y * CM_TO_M;
					vNewPos.Y = pos.X * CM_TO_M;
					vNewPos.Z = pos.Z * CM_TO_M;
				}

				_SetProjectionImageViewPosition(m_pUGProjectionImage, (double)vNewPos.X, (double)vNewPos.Y, (double)vNewPos.Z);
				m_vViewerPosition = pos;
				m_bUpdate = true;
			}

			void ProjectionImage::SetHintLineLength(Gamedouble dLength)
			{
				_ProjectionImageSetHintLineLength(m_pUGProjectionImage, dLength);
			}

			Vector3d ProjectionImage::GetViewerPosition()
			{
				double dX = 0, dY = 0, dZ = 0;
				_GetProjectionImageViewPosition(m_pUGProjectionImage, dX, dY, dZ);
				m_vViewerPosition = Vector3d(dX, dY, dZ);
				return m_vViewerPosition;
			}

			void ProjectionImage::SetHeading(double dDir)
			{
				m_Direction = dDir;
				m_bUpdate = true;

				_SetProjectionImageHeading(m_pUGProjectionImage, (double)m_Direction);
			}

			double ProjectionImage::GetHeading()
			{
				m_Direction = _GetProjectionImageHeading(m_pUGProjectionImage);
				return m_Direction;
			}

			void ProjectionImage::SetPitch(double dPitch)
			{
				m_Pitch = dPitch;
				m_bUpdate = true;

				_SetProjectionImagePitch(m_pUGProjectionImage, (double)m_Pitch);
			}

			double ProjectionImage::GetPitch()
			{
				m_Pitch = _GetProjectionImagePitch(m_pUGProjectionImage);
				return m_Pitch;
			}

			void ProjectionImage::SetAffineMatrix(Vector3d v3X, Vector3d v3Y)
			{
				_SetProjectionImageAffineMatrix(m_pUGProjectionImage, v3X.X, v3X.Y, v3X.Z, v3Y.X, v3Y.Y, v3Y.Z);
			}

			void ProjectionImage::GetAffineMatrix(Vector3d &v3X, Vector3d &v3Y)
			{
				_GetProjectionImageAffineMatrix(m_pUGProjectionImage, v3X.X, v3X.Y, v3X.Z,
					v3Y.X, v3Y.Y, v3Y.Z);
			}

			void ProjectionImage::SetIsHomnymyPoints(bool bUsed)
			{
				_SetProjectionImageIsHomonymyPoints(m_pUGProjectionImage, bUsed);
				m_bUpdate = true;
			}
		
			bool ProjectionImage::IsHomnymyPoints()
			{
				return _GetProjectionImageIsHomonymyPoints(m_pUGProjectionImage);
			}

			void ProjectionImage::SetImageData(UTexture2D* pImage)
			{
				if (m_pProjectionTexture != nullptr)
				{
					m_pProjectionTexture->RemoveFromRoot();
					m_pProjectionTexture->MarkPendingKill();
					m_pProjectionTexture = nullptr;
				}

				m_pProjectionTexture = pImage;
				m_pProjectionTexture->AddToRoot();

				m_bUpdate = true;
			}

			bool ProjectionImage::ProjectionToXML(FString strFileName)
			{
				const TCHAR* c = *strFileName;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);

				return _ProjectionImageToXML(m_pUGProjectionImage , cc);
			}

			bool ProjectionImage::ProjectionFromXML(FString strFileName)
			{
				const TCHAR* c = *strFileName;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);

				m_bUpdate = true;

				return _ProjectionImageFromXML(m_pUGProjectionImage, cc);
			}

			void ProjectionImage::UpdateCamera()
			{
				double dNearClip = 10;
				double dFarClip = 100;
				double dFov = 60;
				double dAspect = 1.0;

				double* pViewMatrix = new double[16];
				double* pProjMatrix = new double[16];

				_GetProjectionImageGetCamera(m_pUGProjectionImage, dFov, dAspect, dNearClip, dFarClip, pViewMatrix, pProjMatrix);
				m_dNearClip = dNearClip * M_TO_CM;
				m_dFarClip = dFarClip * M_TO_CM;

				Matrix4d ugcViewMatrix(pViewMatrix);
				Matrix4d ueViewMatrix;

				MathEngine::UGCViewMatrixToUEViewMatrix(ugcViewMatrix, ueViewMatrix);
				m_matDepthViewMatrix = ueViewMatrix;

				dFov = MathEngine::VerticalToHorizontalFOV(dFov, dAspect);
				m_matDepthPrjMatrix = FReversedZPerspectiveMatrix(dFov * 0.5, dAspect, 1.0, m_dNearClip, m_dFarClip);

				delete[] pViewMatrix;
				delete[] pProjMatrix;
			}

			void ProjectionImage::UpdateUniformsForMaterial(UMaterialInstanceDynamic* pMat, bool bNewMaterial)
			{
				if (pMat == nullptr)
				{
					return;
				}

				if (pMat != nullptr && pMat->GetBaseMaterial() != nullptr && (pMat->GetBaseMaterial()->GetName() == "Global" || pMat->GetBaseMaterial()->GetName() == "SM_Terrain"))
				{
					return;
				}

				if (!bNewMaterial && !m_bUpdate)
				{
					return;
				}
				float fEnable = m_bEnable ? 1.0f : 0.0f;
				pMat->SetScalarParameterValue(FName("EnableProjection"), fEnable);
				if (m_bEnable)
				{
					void* pGT = _GetProjectionImageDepthHandle(m_pUGProjectionImage);
					GameRenderTexture* pGameRenderTexture = (GameRenderTexture*)pGT;
					if (pGameRenderTexture != nullptr)
					{
						UTextureRenderTarget2D* pTextureRenderTarget2D = pGameRenderTexture->GetRenderTarget();
						pMat->SetTextureParameterValue(FName("ProjectionDepthTexture"), pTextureRenderTarget2D);
					}

					MathEngine::SetShaderMatrixParamter(pMat, m_matRenderTextureMat, TEXT("ProjectionViewMat"));
					Vector3d v3X;
					Vector3d v3Y;

					if (!IsHomnymyPoints())
					{
						v3X = Vector3d(1.0, 0.0, 0.0);
						v3Y = Vector3d(0.0, 1.0, 0.0);
					}
					else
					{
						_GetProjectionImageAffineMatrix(m_pUGProjectionImage, v3X.X, v3X.Y, v3X.Z,
							v3Y.X, v3Y.Y, v3Y.Z);
					}
					
					pMat->SetVectorParameterValue(FName("AffineX"), FLinearColor(v3X.X, v3X.Y, v3X.Z, 1.0));
					pMat->SetVectorParameterValue(FName("AffineY"), FLinearColor(v3Y.X, v3Y.Y, v3Y.Z, 1.0));
					
					if (m_pProjectionTexture != nullptr)
					{
						pMat->SetTextureParameterValue(FName("ProjectionTexture"), m_pProjectionTexture);
					}
				}
			}

			void ProjectionImage::UpdateShaderUniforms()
			{
				Matrix4d depthViewPrjMatrix = m_matDepthViewMatrix * m_matDepthPrjMatrix;
				m_matRenderTextureMat = depthViewPrjMatrix;
				m_matMainViewPosToDepthViewPos = depthViewPrjMatrix;

				TMap<Gamelong, GameComponent*> allGameCom = GameObjectManager::GetSingleton()->GetRenderGameComponent();
				for (TMap<Gamelong, GameComponent*>::TConstIterator It = allGameCom.CreateConstIterator(); It; ++It)
				{
					GameComponent* pGameComponent = It->Value;
					if (pGameComponent != nullptr && pGameComponent->GetSceneNode() != nullptr)
					{
						TArray<UMaterialInterface*> arrCustomMaterials;
						pGameComponent->GetSceneNode()->GetAllCustomMaterials(arrCustomMaterials);
						for (int materialIndex = 0; materialIndex < arrCustomMaterials.Num(); materialIndex++)
						{
							UMaterialInstanceDynamic* pMat = (UMaterialInstanceDynamic*)arrCustomMaterials[materialIndex];
							UpdateUniformsForMaterial(pMat, false);
						}
					}
				}
			}
		}
	}
}