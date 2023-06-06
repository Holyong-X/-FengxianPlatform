#include "SpatialAnalyst3D/ViewShed.h"
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
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
//! Multiplier for degrees to radians
#define DTOR    0.0174532925199432957692369077

//! Multiplier for radians to degrees
#define RTOD    57.295779513082320876798154814

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst3D
		{

			ViewShed::ViewShed(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl) : Analyst3D(pWorld, pScene, pCameraControl)
			{
				m_VisibleAreaColor = FVector4(0.0, 1.0, 0.0, 1.0);
				m_HiddenAreaColor = FVector4(1.0,0.0,0.0,1.0);
				m_vViewerPosition = FVector(0.0f, 0.0f, 0.0f);
				m_vRealViewPos = FVector(0, 0, 0);
				m_Direction = 0.0f;
				m_Pitch = 0.0f;
				m_HorizontalFov = 90.0f;
				m_VerticalFov = 60.0f;
				m_Distance = 500000.0f;

				m_bUpdate = false;
				m_bEnable = false;
				m_eAnalyzeMode = Core::View_Shed;
				m_pUGViewShed = nullptr;

				_CreateViewShed(m_pUGViewShed);
				_SetViewShedDistance(m_pUGViewShed, (double)m_Distance);
			}

			ViewShed::~ViewShed()
			{
				Release();
				_DestroyViewShed(m_pUGViewShed);
			}

			void ViewShed::Release()
			{
	
			}

			void ViewShed::DoBuild()
			{
				m_bEnable = true;
				m_bUpdate = true;
				_BuildViewShed(m_pUGViewShed);
			}

			void ViewShed::DoClear()
			{
				m_bEnable = false;
				m_bUpdate = true;
				UpdateShaderUniforms();
			}

			void ViewShed::Render()
			{
				if (m_bUpdate)
				{
					UpdateCamera();
					UpdateShaderUniforms();
				}
				m_bUpdate = false;
			}

			void* ViewShed::GetHandler()
			{
				return m_pUGViewShed;
			}

			void ViewShed::SetVisibleAreaColor(const FVector4& color)
			{
				m_VisibleAreaColor = color;
				_SetViewShedVisibleAreaColor(m_pUGViewShed, m_VisibleAreaColor.X, m_VisibleAreaColor.Y,
					m_VisibleAreaColor.Z, m_VisibleAreaColor.W);
				m_bUpdate = true;
			}
			
			FVector4 ViewShed::GetVisibleAreaColor()
			{
				GameVector4 vVisibleAreaColor;
				_GetViewShedVisibleAreaColor(m_pUGViewShed, vVisibleAreaColor.X, vVisibleAreaColor.Y,
					vVisibleAreaColor.Z, vVisibleAreaColor.W);
				m_VisibleAreaColor = FVector4(vVisibleAreaColor);
				return m_VisibleAreaColor;
			}

			void ViewShed::SetHiddenAreaColor(const FVector4& color)
			{
				m_HiddenAreaColor = color;
				_SetViewShedHiddenAreaColor(m_pUGViewShed, m_HiddenAreaColor.X, m_HiddenAreaColor.Y,
					m_HiddenAreaColor.Z, m_HiddenAreaColor.W);
				m_bUpdate = true;
			}

			FVector4 ViewShed::GetHiddenAreaColor()
			{
				GameVector4 vHiddenAreaColor;
				_GetViewShedHiddenAreaColor(m_pUGViewShed, vHiddenAreaColor.X, vHiddenAreaColor.Y,
					vHiddenAreaColor.Z, vHiddenAreaColor.W);
				m_HiddenAreaColor = FVector4(vHiddenAreaColor);
				return m_HiddenAreaColor;
			}

			void ViewShed::SetViewerPosition(FVector pos)
			{
				FVector vNewPos = pos;
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					vNewPos.X = pos.Y * CM_TO_M;
					vNewPos.Y = pos.X * CM_TO_M;
					vNewPos.Z = pos.Z * CM_TO_M;
				}
				
				_SetViewShedViewerPosition(m_pUGViewShed, (double)vNewPos.X, (double)vNewPos.Y, (double)vNewPos.Z);
				m_vViewerPosition = pos;
				m_bUpdate = true;
			}

			FVector ViewShed::GetViewerPosition() const
			{
				return m_vViewerPosition;
			}
			
			void ViewShed::SetName(FString name)
			{
				const TCHAR* cname = *name;
				ANSICHAR* ccname = TCHAR_TO_UTF8(cname);
				_ViewShed_SetName(m_pUGViewShed, ccname);
			}

			FString ViewShed::GetName()
			{
				char* cName = _ViewShed_GetName(m_pUGViewShed);
				FString strName = UTF8_TO_TCHAR(cName);
				return strName;
			}

			void ViewShed::SetDirection(double dir)
			{
				m_Direction = dir;
				m_bUpdate = true;

				_SetViewShedHeading(m_pUGViewShed, (double)dir);
			}

			double ViewShed::GetDirection()
			{
				return m_Direction;
			}

			void ViewShed::SetPitch(double pitch)
			{
				m_Pitch = pitch;
				m_bUpdate = true;

				_SetViewShedPitch(m_pUGViewShed, (double)pitch);
			}
			
			double ViewShed::GetPitch()
			{
				m_Pitch = _GetViewShedPitch(m_pUGViewShed);
				return m_Pitch;
			}

			void ViewShed::SetHorizontalFov(double fov)
			{
				m_HorizontalFov = fov;
				m_bUpdate = true;

				_SetViewShedHorizontalFov(m_pUGViewShed, (double)fov);
			}

			double ViewShed::GetHorizontalFov()
			{
				m_HorizontalFov = _GetViewShedHorizontalFov(m_pUGViewShed);
				return m_HorizontalFov;
			}

			GeoModel3D* ViewShed::GetViewShedVisibleBody()
			{
				void* pUGGeoModel3D = nullptr;
				_GetViewShedVisibleBody(m_pUGViewShed, pUGGeoModel3D);

				if (pUGGeoModel3D != nullptr)
				{
					GeoModel3D* pGeoModel3D = new GeoModel3D(pUGGeoModel3D);
					return pGeoModel3D;
				}
				return nullptr;
			}

			GeoModel3D* ViewShed::GetViewShedHiddenBody()
			{
				void* pUGGeoModel3D = nullptr;
				_GetViewShedHiddenBody(m_pUGViewShed, pUGGeoModel3D);

				if (pUGGeoModel3D != nullptr)
				{
					GeoModel3D* pGeoModel3D = new GeoModel3D(pUGGeoModel3D);
					return pGeoModel3D;
				}
				return nullptr;
			}

			void ViewShed::SetVerticalFov(double fov)
			{
				m_VerticalFov = fov;
				m_bUpdate = true;

				_SetViewShedVerticalFov(m_pUGViewShed, (double)fov);
			}

			double ViewShed::GetVerticalFov()
			{
				m_VerticalFov = _GetViewShedVerticalFov(m_pUGViewShed);
				return m_VerticalFov;
			}

			void ViewShed::SetDistance(double dist)
			{
				m_Distance = dist;
				m_bUpdate = true;

				_SetViewShedDistance(m_pUGViewShed, (double)dist);
			}

			double ViewShed::GetDistance()
			{
				m_Distance = _GetViewShedDistance(m_pUGViewShed);
				return m_Distance;
			}

			void ViewShed::UpdateCamera()
			{
				double dNearClip = 10;
				double dFarClip = 100;
				double dFov = 60;
				double dAspect = 1.0;

				double* pViewMatrix = new double[16];
				double* pProjMatrix = new double[16];

				_GetCamera(m_pUGViewShed, dFov, dAspect, dNearClip, dFarClip, pViewMatrix);
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

			void ViewShed::SetDistDirByPoint(const FVector& point)
			{
				FVector vNewPos = point;
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					Swap(vNewPos.X, vNewPos.Y);
					vNewPos *= CM_TO_M;
				}

				if (_SetDistDirByPoint != nullptr)
				{
					_SetDistDirByPoint(m_pUGViewShed, vNewPos.X, vNewPos.Y, vNewPos.Z);
				}

				m_bUpdate = true;
			}

			void ViewShed::SetMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strTex)
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

				FString strX = strTex + TEXT("X");
				FString strY = strTex + TEXT("Y");
				FString strZ = strTex + TEXT("Z");
				FString strW = strTex + TEXT("W");

				pMID->SetVectorParameterValue(FName(strX), vX);
				pMID->SetVectorParameterValue(FName(strY), vY);
				pMID->SetVectorParameterValue(FName(strZ), vZ);
				pMID->SetVectorParameterValue(FName(strW), vW);
			}

			void ViewShed::UpdateUniformsForMaterial(UMaterialInstanceDynamic* pMat, bool bNewMaterial)
			{
				if (pMat== nullptr)
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
				pMat->SetScalarParameterValue(FName("Enable"), fEnable);
				if (m_bEnable)
				{
					pMat->SetVectorParameterValue(FName("VisibleColor"), FLinearColor(m_VisibleAreaColor));
					pMat->SetVectorParameterValue(FName("HiddenColor"), FLinearColor(m_HiddenAreaColor));
					pMat->SetScalarParameterValue(FName("Distance"), GetDistance());
					void* pGT = _GetDepthRenderTextureHandle(m_pUGViewShed);
					GameRenderTexture* pGameRenderTexture = (GameRenderTexture*)pGT;
					if (pGameRenderTexture != nullptr)
					{
						UTextureRenderTarget2D* pTextureRenderTarget2D = pGameRenderTexture->GetRenderTarget();
						pMat->SetTextureParameterValue(FName("DepthTexture"), pTextureRenderTarget2D);
					}

					SetMatrix(pMat, m_matRenderTextureMat, TEXT("DepthViewMat"));	
					pMat->SetVectorParameterValue(FName("ViewPos"), FLinearColor(m_vRealViewPos));
				}
				
			}

			void ViewShed::UpdateShaderUniforms()
			{
				Matrix4d depthViewPrjMatrix = m_matDepthViewMatrix * m_matDepthPrjMatrix;
				m_matRenderTextureMat = depthViewPrjMatrix;
				m_matMainViewPosToDepthViewPos = depthViewPrjMatrix;
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					m_vRealViewPos = m_vViewerPosition;
				}
				else
				{
					m_vRealViewPos = MathEngine::SphericalToCartesian_GeoOrigin(m_vViewerPosition);
				}
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

			TArray<Vector3d> ViewShed::GetBarrierPoints()
			{
				TArray<Vector3d> arrPoint;
				Gamedouble* pPoint;
				Gameint size = _ViewShed_GetBarrierPoints(m_pUGViewShed, pPoint);
				for (Gameint i = 0; i < size; ++i)
				{
					Vector3d vPoint;
					vPoint.X = pPoint[i * 3];
					vPoint.Y = pPoint[i * 3 + 1];
					vPoint.Z = pPoint[i * 3 + 2];
					arrPoint.Add(vPoint);
				}
				return arrPoint;
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif