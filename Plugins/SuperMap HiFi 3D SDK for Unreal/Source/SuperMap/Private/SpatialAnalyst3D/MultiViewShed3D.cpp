#include "SpatialAnalyst3D/MultiViewShed3D.h"
#include "Base3D/CommonDefine.h"
#include "Algorithm3D/MathEngine.h"
#include "Graphics3D/GameObjectManager.h"
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

			MultiViewShed3D::MultiViewShed3D(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl) : Analyst3D(pWorld, pScene, pCameraControl)
			{
				m_pUGMultiViewShed3D = nullptr;
				_MultiViewShed3D_Create(m_pUGMultiViewShed3D);
				m_bEnable = false;
				m_eAnalyzeMode = Core::Multi_ViewShed3D;
			}

			MultiViewShed3D::~MultiViewShed3D()
			{
				Release();
				_MultiViewShed3D_Destroy(m_pUGMultiViewShed3D);
			}

			void MultiViewShed3D::AddViewShed(ViewShed* pViewShed)
			{
				void* pUGViewShed = pViewShed->GetHandler();
				_MultiViewShed3D_AddViewShed(m_pUGMultiViewShed3D, pUGViewShed);
				m_arrViewShed.Add(pViewShed);
				m_bUpdate = true;
			}

			void MultiViewShed3D::RemoveViewShed(ViewShed* pViewShed)
			{
				void* pUGViewShed = pViewShed->GetHandler();
				_MultiViewShed3D_RemoveViewShed(m_pUGMultiViewShed3D, pUGViewShed);
				m_arrViewShed.Remove(pViewShed);
				delete pViewShed;
				pViewShed = nullptr;
				m_bUpdate = true;
			}

			void MultiViewShed3D::Release()
			{
				for (int i = 0; i < m_arrViewShed.Num(); i++)
				{
					_ViewShed_RemoveFromAnalyst3DList(m_arrViewShed[i]->GetHandler());
					m_arrViewShed[i] = nullptr;
				}
				m_arrViewShed.Empty();
				m_arrRealViewPos.Empty();
				m_matRenderTextureMat.Empty();
				m_arrDistance.Empty();
			}

			void MultiViewShed3D::DoBuild()
			{
				_MultiViewShed3D_Build(m_pUGMultiViewShed3D);
				m_bUpdate = true;
				m_bEnable = true;
			}

			void MultiViewShed3D::DoClear()
			{
				Release();
				m_bEnable = false;
				m_bUpdate = true;
				UpdateShaderUniforms();
			}

			void MultiViewShed3D::Render()
			{
				if (m_bUpdate)
				{
					UpdateCamera();
					UpdateShaderUniforms();
					m_bUpdate = false;
				}
			}

			void MultiViewShed3D::UpdateCamera()
			{
				m_arrDistance.Empty();
				m_matRenderTextureMat.Empty();
				m_arrRealViewPos.Empty();
				for (int i = 0; i < m_arrViewShed.Num(); i++)
				{
					m_arrDistance.Add(m_arrViewShed[i]->GetDistance());
					FVector vRealViewPos = FVector(0, 0, 0);
					if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
					{
						vRealViewPos = m_arrViewShed[i]->GetViewerPosition();
					}
					else
					{
						vRealViewPos = MathEngine::SphericalToCartesian_GeoOrigin(m_arrViewShed[i]->GetViewerPosition());
					}
					m_arrRealViewPos.Add(vRealViewPos);
					double dNearClip = 10;
					double dFarClip = 100;
					double dFov = 60;
					double dAspect = 1.0;
					double* pViewMatrix = new double[16];
					double* pProjMatrix = new double[16];
					_GetCamera(m_arrViewShed[i]->GetHandler(), dFov, dAspect, dNearClip, dFarClip, pViewMatrix);
					Matrix4d ugcViewMatrix(pViewMatrix);
					Matrix4d ueViewMatrix;
					MathEngine::UGCViewMatrixToUEViewMatrix(ugcViewMatrix, ueViewMatrix);
					dFov = MathEngine::VerticalToHorizontalFOV(dFov, dAspect);
					Matrix4d matDepthPrjMatrix = FReversedZPerspectiveMatrix(dFov * 0.5, dAspect, 1.0, dNearClip * M_TO_CM, dFarClip * M_TO_CM);
					Matrix4d matRenderTextureMat = ueViewMatrix * matDepthPrjMatrix;
					m_matRenderTextureMat.Add(matRenderTextureMat);
					delete[] pViewMatrix;
					delete[] pProjMatrix;
				}
			}

			void MultiViewShed3D::UpdateShaderUniforms()
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

			void MultiViewShed3D::SetMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strTex)
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

			void MultiViewShed3D::UpdateUniformsForMaterial(UMaterialInstanceDynamic* pMat, bool bNewMaterial)
			{
				if (pMat == nullptr)
				{
					return;
				}

				if (pMat != nullptr && pMat->GetBaseMaterial() != nullptr &&(pMat->GetBaseMaterial()->GetName() == "Global" || pMat->GetBaseMaterial()->GetName() == "SM_Terrain"))
				{
					return;
				}

				if (!bNewMaterial && !m_bUpdate)
				{
					return;
				}
				float fEnable = m_bEnable ? 1.0f : 0.0f;
				pMat->SetScalarParameterValue(FName("MultiViewShed3D_Enable"), fEnable);
				if (m_bEnable)
				{
					pMat->SetScalarParameterValue(FName("MultiViewShed3D_TextureCount"), m_arrDistance.Num());
					for (int i = 0; i < m_arrDistance.Num(); i++)
					{
						FString distanceName = "MultiViewShed3D_Distance" + FString::Printf(TEXT("%d"), (i + 1));
						pMat->SetScalarParameterValue(FName(distanceName), m_arrDistance[i]);
						void* pGT = _GetDepthRenderTextureHandle(m_arrViewShed[i]->GetHandler());
						GameRenderTexture* pGameRenderTexture = (GameRenderTexture*)pGT;
						if (pGameRenderTexture != nullptr)
						{
							FString textureName = "MultiViewShed3D_DepthTexture" + FString::Printf(TEXT("%d"), (i + 1));
							UTextureRenderTarget2D* pTextureRenderTarget2D = pGameRenderTexture->GetRenderTarget();
							pMat->SetTextureParameterValue(FName(textureName), pTextureRenderTarget2D);
						}
						FString depthViewMatName = "MultiViewShed3D_DepthViewMat" + FString::Printf(TEXT("%d"), (i + 1));
						SetMatrix(pMat, m_matRenderTextureMat[i], depthViewMatName);
						FString viewposName = "MultiViewShed3D_ViewPos" + FString::Printf(TEXT("%d"), (i + 1));
						pMat->SetVectorParameterValue(FName(viewposName), FLinearColor(m_arrRealViewPos[i]));
					}
				}
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif