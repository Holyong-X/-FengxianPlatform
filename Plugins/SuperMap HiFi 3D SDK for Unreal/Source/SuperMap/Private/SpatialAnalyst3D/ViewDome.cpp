#include "SpatialAnalyst3D/ViewDome.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameRenderTexture.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/ROCache.h"
#include "Component/SuperMap_MeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst3D
		{
			ViewDome::ViewDome(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl) : Analyst3D(pWorld, pScene, pCameraControl)
			{
				m_Color = FVector4(0.0, 1.0, 0.0, 1.0);
				m_LineColor = FVector4(0.0, 1.0, 0.0, 1.0);
				m_vViewerPosition = FVector(0.0f, 0.0f, 0.0f);
				m_bUpdate = false;
				m_bEnable = false;
				m_eAnalyzeMode = Core::View_Dome;
				m_pUGViewDome = nullptr;
				m_dDistance = 150;
				m_eDomeType = ViewDome::DomeType::VisibleDome;
				m_eDisplayMode = ViewDome::DisplayMode::LINE;
				_ViewDome_Create(m_pUGViewDome);
				_ViewDome_SetDistance(m_pUGViewDome, (double)m_dDistance);
			}

			ViewDome::~ViewDome()
			{
				Release();
				_ViewDome_Destroy(m_pUGViewDome);
			}

			void ViewDome::Release()
			{
				if (m_matDepthViewMatrixs.Num() != 0)
				{
					m_matDepthViewMatrixs.Empty();
				}
				if (m_matDepthPrjMatrixs.Num() != 0)
				{
					m_matDepthPrjMatrixs.Empty();
				}
			}

			void ViewDome::DoBuild()
			{
				m_bEnable = true;
				m_bUpdate = true;
				_ViewDome_Build(m_pUGViewDome);
			}

			void ViewDome::DoClear()
			{
				m_bEnable = false;
				m_bUpdate = true;
				UpdateShaderUniforms();
			}

			void ViewDome::Render()
			{
				if (m_bUpdate)
				{
					UpdateCamera();
					UpdateShaderUniforms();
				}
				m_bUpdate = false;
			}

			FVector4 ViewDome::GetViewDomeColor()
			{
				GameVector4 vColor;
				_ViewDome_GetColor(m_pUGViewDome, vColor.X, vColor.Y, vColor.Z, vColor.W);
				m_Color = FVector4(vColor);
				return m_Color;
			}

			void ViewDome::SetViewDomeColor(const FVector4& color)
			{
				m_Color = color;
				_ViewDome_SetColor(m_pUGViewDome, color.X, color.Y, color.Z, color.W);
				m_bUpdate = true;
			}

			FVector4 ViewDome::GetViewDomeLineColor()
			{
				GameVector4 vColor;
				_ViewDome_GetLineColor(m_pUGViewDome, vColor.X, vColor.Y, vColor.Z, vColor.W);
				m_LineColor = FVector(vColor);
				return m_LineColor;
			}

			void ViewDome::SetViewDomeLineColor(const FVector4& color)
			{
				m_LineColor = color;
				_ViewDome_SetColor(m_pUGViewDome, color.X, color.Y, color.Z, color.W);
				m_bUpdate = true;
			}

			void ViewDome::SetViewerPosition(FVector pos)
			{
				FVector vNewPos = pos;
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					vNewPos.X = pos.Y * CM_TO_M;
					vNewPos.Y = pos.X * CM_TO_M;
					vNewPos.Z = pos.Z * CM_TO_M;
				}
				_ViewDome_SetViewerPosition(m_pUGViewDome, (double)vNewPos.X, (double)vNewPos.Y, (double)vNewPos.Z);
				m_vViewerPosition = pos;
				m_bUpdate = true;
			}

			FVector ViewDome::GetViewerPosition() const
			{
				return m_vViewerPosition;
			}

			Gamedouble ViewDome::GetViewDomeDistance()
			{
				m_dDistance = _ViewDome_GetDistance(m_pUGViewDome);
				return m_dDistance;
			}

			void ViewDome::SetViewDomeDistance(Gamedouble viewDistance)
			{
				m_dDistance = viewDistance;
				_ViewDome_SetDistance(m_pUGViewDome, (double)viewDistance);
				m_bUpdate = true;
			}

			ViewDome::DomeType ViewDome::GetDomeType()
			{
				m_eDomeType = (ViewDome::DomeType)_ViewDome_GetDomeType(m_pUGViewDome);
				return m_eDomeType;
			}

			void ViewDome::SetDomeType(ViewDome::DomeType modeType)
			{
				m_eDomeType = modeType;
				_ViewDome_SetDomeType(m_pUGViewDome, (int)modeType);
				m_bUpdate = true;
			}

			ViewDome::DisplayMode ViewDome::GetViewDomeDisplayStyle()
			{
				m_eDisplayMode = (ViewDome::DisplayMode)_ViewDome_GetDisplayStyle(m_pUGViewDome);
				return m_eDisplayMode;
			}

			void ViewDome::SetViewDomeDisplayStyle(ViewDome::DisplayMode displayStyle)
			{
				m_eDisplayMode = displayStyle;
				_ViewDome_SetDisplayStyle(m_pUGViewDome, (int)displayStyle);
				m_bUpdate = true;
			}

			Gamedouble ViewDome::GetViewDomeRatio()
			{
				return _ViewDome_GetRatio(m_pUGViewDome,(int)m_eDomeType);
			}

			void ViewDome::UpdateCamera()
			{
				if (m_matDepthViewMatrixs.Num() != 0)
				{
					m_matDepthViewMatrixs.Empty();
				}
				if (m_matDepthPrjMatrixs.Num() != 0)
				{
					m_matDepthPrjMatrixs.Empty();
				}
				Gamedouble** pViewMatrixs = NULL;
				Gamedouble dFov = 60;
				Gamedouble dAspect = 1;
				Gamedouble dNear = 10;
				Gamedouble dFar = 100;
				Gameint nCount = 0;

				_ViewDome_GetCamera(m_pUGViewDome, pViewMatrixs, dFov, dAspect, dNear, dFar, nCount);

				dNear = dNear * M_TO_CM;
				dFar = dFar * M_TO_CM;
				dFov = MathEngine::VerticalToHorizontalFOV(dFov, dAspect);
				Matrix4d ueProjMatrix = FReversedZPerspectiveMatrix(dFov * 0.5, dAspect, 1.0, dNear, dFar);

				for (int i = 0; i < nCount; i++)
				{
					Gamedouble* pViewMatrix = new Gamedouble[16];
					for (int j = 0; j < 16; j++)
					{
						pViewMatrix[j] = pViewMatrixs[0][i * 16 + j];
					}
					Matrix4d ugcViewMatrix(pViewMatrix);
					Matrix4d ueViewMatrix;
					MathEngine::UGCViewMatrixToUEViewMatrix(ugcViewMatrix, ueViewMatrix);
					m_matDepthViewMatrixs.Add(ueViewMatrix);
					m_matDepthPrjMatrixs.Add(ueProjMatrix);
					delete[] pViewMatrix;
				}
				if (nCount > 0)
				{
					Core::_ReleaseDoubleArray(pViewMatrixs);
				}
			}

			void ViewDome::SetMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strTex)
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

			void ViewDome::UpdateShaderUniforms()
			{
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

			void ViewDome::UpdateUniformsForMaterial(UMaterialInstanceDynamic* pMat, bool bNewMaterial)
			{
				if (pMat == nullptr)
				{
					return;
				}

				if (pMat != nullptr && pMat->GetBaseMaterial() != nullptr && pMat->GetBaseMaterial()->GetName() != "ViewDome")
				{
					return;
				}

				if (!bNewMaterial && !m_bUpdate)
				{
					return;
				}
				float fEnable = m_bEnable ? 1.0f : 0.0f;
				pMat->SetScalarParameterValue(FName("domeEnable"), fEnable);
				if (m_bEnable)
				{
					//domeType
					void** pGT = nullptr;
					Gameint nTexCount = 0;
					_ViewDome_GetDepthRenderTexturePtrHandle(m_pUGViewDome, pGT, nTexCount);
					pMat->SetScalarParameterValue(FName("domeType"), m_eDomeType);
					pMat->SetVectorParameterValue(FName("domeColor"), FLinearColor(m_Color));
					pMat->SetScalarParameterValue(FName("domeDistance"), float(m_dDistance));
					for (int n = 0; n < nTexCount; n++)
					{
						GameRenderTexture* pGameRenderTexture = (GameRenderTexture*)pGT[n];
						if (pGameRenderTexture != nullptr) 
						{
							UTextureRenderTarget2D* pTextureRenderTarget2D = pGameRenderTexture->GetRenderTarget();
							FString strName = TEXT("domeDepthTexture") + FString::Printf(TEXT("%d"), n);
							pMat->SetTextureParameterValue(FName(strName), pTextureRenderTarget2D);
						}
					}
					for (int m = 0; m < m_matDepthViewMatrixs.Num(); m++)
					{
						Matrix4d textureViewMatrix = m_matDepthViewMatrixs[m] * m_matDepthPrjMatrixs[m];
						FString strName = TEXT("domeDepthViewMat") + FString::Printf(TEXT("%d"), m);
						SetMatrix(pMat, textureViewMatrix, strName);

						Matrix4d texWorldViewMatrix = m_matDepthViewMatrixs[m];
						FString strName1 = TEXT("domeWorldViewMatrix") + FString::Printf(TEXT("%d"), m);
						SetMatrix(pMat, texWorldViewMatrix, strName1);

						FString strName2 = TEXT("domeProjMatrix") + FString::Printf(TEXT("%d"), m);
						SetMatrix(pMat, m_matDepthPrjMatrixs[m], strName2);
					}
				}
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif