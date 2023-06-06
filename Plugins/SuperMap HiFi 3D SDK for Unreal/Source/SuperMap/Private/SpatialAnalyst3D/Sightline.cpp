#include "SpatialAnalyst3D/Sightline.h"
#include "Engine/World.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Base3D/CommonDefine.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Core/Georeference.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst3D
		{
			Sightline::Sightline(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl) : Analyst3D(pWorld, pScene, pCameraControl)
			{
				m_vViewerPosition = FVector(0.0, 0.0, 0.0);
				m_pSightline = nullptr;
				m_bUpdateSightline = false;
				m_eAnalyzeMode = Core::Sight_Line;
				m_strName = FName("Sightline");
				m_pROEntityActor = pWorld->SpawnActor<ASuperMap_ROEntityActor>();

				m_pROEntityActor->SetIsSceneHiddenObject(true);

				SuperMapSDK::UnrealEngine::Core::_CreateSightline(m_pSightline);
				RemoveAllTargetPoints();
			}

			Sightline::~Sightline()
			{
				Release();
			}

			void Sightline::Release()
			{
				m_pROEntityActor->SetIsSceneHiddenObject(false);
				m_pROEntityActor->Destroy(false, false);
				m_pROEntityActor = nullptr;

				m_arrSightlineResult.Empty();
			}

			void Sightline::SetViewerPosition(FVector vPos)
			{
				FVector vNewPos = vPos;
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					vNewPos.X = vPos.Y * CM_TO_M;
					vNewPos.Y = vPos.X * CM_TO_M;
					vNewPos.Z = vPos.Z * CM_TO_M;
				}

				SuperMapSDK::UnrealEngine::Core::_SetSightlineViewerPosition(m_pSightline, vNewPos.X, vNewPos.Y, vNewPos.Z);
				m_vViewerPosition = vPos;
				m_bUpdateSightline = true;
			}

			FVector Sightline::GetViewerPosition()
			{
				Gamedouble dPosX, dPosY, dPosZ;
				SuperMapSDK::UnrealEngine::Core::_GetSightlineViewerPosition(m_pSightline, dPosX, dPosY, dPosZ);

				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					dPosX = dPosY * M_TO_CM;
					dPosY = dPosX * M_TO_CM;
					dPosZ = dPosZ * M_TO_CM;
				}

				m_vViewerPosition.X = dPosX;
				m_vViewerPosition.Y = dPosY;
				m_vViewerPosition.Z = dPosZ;

				return m_vViewerPosition;
			}

			void Sightline::SetVisibleColor(FLinearColor color)
			{
				SuperMapSDK::UnrealEngine::Core::_SetSightlineVisibleColor(m_pSightline, color.R, color.G, color.B, color.A);
				m_bUpdateSightline = true;
			}

			FLinearColor Sightline::GetVisibleColor()
			{
				Gamefloat fR = 0.0f, fG = 0.0f, fB = 0.0f, fA = 0.0f;
				SuperMapSDK::UnrealEngine::Core::_SetSightlineVisibleColor(m_pSightline, fR, fG, fB, fA);

				return FLinearColor(fR, fG, fB, fA);
			}

			void Sightline::SetHiddenColor(FLinearColor color)
			{
				SuperMapSDK::UnrealEngine::Core::_SetSightlineHiddenColor(m_pSightline, color.R, color.G, color.B, color.A);
				m_bUpdateSightline = true;
			}

			FLinearColor Sightline::GetHiddenColor()
			{
				Gamefloat fR= 0.0f, fG = 0.0f, fB = 0.0f, fA = 0.0f;
				SuperMapSDK::UnrealEngine::Core::_SetSightlineHiddenColor(m_pSightline, fR, fG, fB, fA);

				return FLinearColor(fR, fG, fB, fA);
			}

			//! \brief 设置目标点
			void Sightline::SetTargetPoint(Gameint nIndex, FVector vPoint)
			{
				FVector vNewPos = vPoint;
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					vNewPos.X = vPoint.Y * CM_TO_M;
					vNewPos.Y = vPoint.X * CM_TO_M;
					vNewPos.Z = vPoint.Z * CM_TO_M;
				}

				SuperMapSDK::UnrealEngine::Core::_SetSightlineTargetPoint(m_pSightline, nIndex, vNewPos.X, vNewPos.Y, vNewPos.Z);

				m_bUpdateSightline = true;
			}

			//! \brief 获取目标点
			FVector Sightline::GetTargetPoint(Gameint nIndex)
			{
				Gamedouble dPosX = 0.0, dPosZ = 0.0, dPosY = 0.0;

				SuperMapSDK::UnrealEngine::Core::_GetSightlineTargetPoint(m_pSightline, nIndex, dPosX, dPosY, dPosZ);

				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					Swap(dPosX, dPosY);

					dPosX *= M_TO_CM;
					dPosY *= M_TO_CM;
					dPosZ *= M_TO_CM;
				}

				return FVector(dPosX, dPosY, dPosZ);
			}

			//! \brief 移除指定目标点
			void Sightline::RemoveTargetPoint(Gameint nIndex)
			{
				SuperMapSDK::UnrealEngine::Core::_RemoveSightlineTargetPoint(m_pSightline, nIndex);

				m_bUpdateSightline = true;
			}

			//! \brief 移除所有目标点
			void Sightline::RemoveAllTargetPoints()
			{
				SuperMapSDK::UnrealEngine::Core::_RemoveSightlineAllTargetPoint(m_pSightline);

				m_bUpdateSightline = true;
			}

			//! \brief 获取目标点的个数
			Gameint Sightline::GetTargetPointCount()
			{
				return SuperMapSDK::UnrealEngine::Core::_GetSightlineTargetPointCount(m_pSightline);
			}

			void Sightline::AddTargetPoint(FVector vPoint)
			{
				Vector3d vNewPos = vPoint;
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					vNewPos.X = vPoint.Y * CM_TO_M;
					vNewPos.Y = vPoint.X * CM_TO_M;
					vNewPos.Z = vPoint.Z * CM_TO_M;
				}

				SuperMapSDK::UnrealEngine::Core::_AddSightlineTargetPoint(m_pSightline , vNewPos.X, vNewPos.Y, vNewPos.Z);

				m_bUpdateSightline = true;
			}

			static void FMatrixToDoublePtr(FMatrix & matrix, Gamedouble* & pDoublePtr)
			{
				pDoublePtr = new double[16];

				for (Gameint i = 0; i < 4; i++)
				{
					for (Gameint j = 0; j < 4; j++)
					{
						pDoublePtr[i * 4 + j] = matrix.M[i][j];
					}
				}
			}

			//! \brief 绘制通视分析
			void Sightline::CreateSightline()
			{
				m_pROEntityActor->ClearMesh();

				TArray<SM_Vertex> arrVtxs;
				TArray<Gameint> arrIndexs;
				Gameint nTargetPointCount = GetTargetPointCount();
				for (Gameint n = 0; n < nTargetPointCount; n++)
				{
					if (_IsInsideView != nullptr)
					{
						Gamebool bInsideView = _IsInsideView(m_pSightline, n);
						if (!bInsideView)
						{
							AddLine(arrVtxs, arrIndexs, n, FColor(169,169,169,255));
							continue;
						}
					}
					
					Gamedouble dBarrierPointX = 0, dBarrierPointY = 0, dBarrierPointZ = 0;
					Gamedouble dReflectionPointX = 0, dReflectionPointY = 0, dReflectionPointZ = 0;
					Gamebool bSuccess = false;
					if (_GetBarrierPointAndReflectionPoint != nullptr)
					{
						bSuccess = _GetBarrierPointAndReflectionPoint(m_pSightline, n, dBarrierPointX, dBarrierPointY, dBarrierPointZ,
							dReflectionPointX, dReflectionPointY, dReflectionPointZ);

						if (m_pScene->GetSceneType() == Core::SceneType::Flat)
						{
							Swap(dBarrierPointX, dBarrierPointY);

							dBarrierPointX *= M_TO_CM;
							dBarrierPointY *= M_TO_CM;
							dBarrierPointZ *= M_TO_CM;
						}	
					}
					if (!bSuccess)
					{
						// 绘制障碍点
						SM_Vertex v;
						v.Position = m_vViewerPosition;
						v.Color = FColor::Green;

						if (m_pScene->GetSceneType() == Core::SceneType::Globe || 
							m_pScene->GetSceneType() == Core::SceneType::Ellipsoid_WGS84)
						{
							v.Position = MathEngine::SphericalToCartesian_GeoOrigin(v.Position);
						}
						else
						{
							v.Position -= FVector(ROCacheManager::m_vecWorldOrigin);
						}
						arrVtxs.Add(v);
						arrIndexs.Add(arrVtxs.Num() - 1);

						SM_Vertex v1;
						v1.Position = FVector(dBarrierPointX, dBarrierPointY, dBarrierPointZ);

						if (m_pScene->GetSceneType() == Core::SceneType::Globe ||
							m_pScene->GetSceneType() == Core::SceneType::Ellipsoid_WGS84)
						{
							v1.Position = MathEngine::SphericalToCartesian_GeoOrigin(v1.Position);
						}
						else
						{
							v1.Position -= FVector(ROCacheManager::m_vecWorldOrigin);
						}
						v1.Color = FColor::Green;
						arrVtxs.Add(v1);
						arrIndexs.Add(arrVtxs.Num() - 1);

						v1.Color = FColor::Red;
						arrVtxs.Add(v1);
						arrIndexs.Add(arrVtxs.Num() - 1);

						FVector vTargetPoint = GetTargetPoint(n);

						SM_Vertex v2;
						v2.Position = vTargetPoint;
						v2.Color = FColor::Red;

						if (m_pScene->GetSceneType() == Core::SceneType::Globe ||
							m_pScene->GetSceneType() == Core::SceneType::Ellipsoid_WGS84)
						{
							v2.Position = MathEngine::SphericalToCartesian_GeoOrigin(v2.Position);
						}
						else
						{
							v2.Position -= FVector(ROCacheManager::m_vecWorldOrigin);
						}
						arrVtxs.Add(v2);
						arrIndexs.Add(arrVtxs.Num() - 1);	
					}
					else
					{
						// 绘制无障碍点
						AddLine(arrVtxs,arrIndexs, n, FColor::Green);
					}
				}

				TArray<SM_SubMesh> arrSubMeshs;

				SM_SubMesh subMesh;

				if (m_pROEntityActor->GetMaterial() == nullptr)
				{
					static UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
					UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
					subMesh.m_pMaterialInterface = pMat;
					m_pROEntityActor->SetMaterial(pMat);
				}

				subMesh.IndexBuffer = arrIndexs;

				arrSubMeshs.Add(subMesh);

				m_pROEntityActor->SetDrawType(2);
				m_pROEntityActor->CreateLineMeshComponent(arrVtxs, arrSubMeshs);
				m_bUpdateSightline = false;
			}

			void Sightline::DoBuild()
			{
				if (_SightlineBuild != nullptr)
				{
					_SightlineBuild(m_pSightline);
				}
			}

			void Sightline::DoClear()
			{
				m_bUpdateSightline = false;
			}

			void Sightline::AddLine(TArray<SM_Vertex>& arrVtxs, TArray<int32>& arrIndexs, int32 nIndex, FColor color)
			{
				SM_Vertex v;
				v.Position = m_vViewerPosition;

				if (m_pScene->GetSceneType() == Core::SceneType::Globe ||
					m_pScene->GetSceneType() == Core::SceneType::Ellipsoid_WGS84)
				{
					v.Position = MathEngine::SphericalToCartesian_GeoOrigin(v.Position);
				}
				else
				{
					v.Position -= FVector(ROCacheManager::m_vecWorldOrigin);
				}
				FVector vTargetPoint = GetTargetPoint(nIndex);
				SM_Vertex v1;
				v1.Position = vTargetPoint;

				if (m_pScene->GetSceneType() == Core::SceneType::Globe ||
					m_pScene->GetSceneType() == Core::SceneType::Ellipsoid_WGS84)
				{
					v1.Position = MathEngine::SphericalToCartesian_GeoOrigin(v1.Position);
				}
				else
				{
					v1.Position -= FVector(ROCacheManager::m_vecWorldOrigin);
				}
				v.Color = color;
				v1.Color = color;

				arrVtxs.Add(v);
				arrIndexs.Add(arrVtxs.Num() - 1);

				arrVtxs.Add(v1);
				arrIndexs.Add(arrVtxs.Num() - 1);
			}	

			void Sightline::Render()
			{
				if (m_bUpdateSightline)
				{
					CreateSightline();
					UpdateArrSightlineResult();
				}
			}

			Sightline::SightlineResult Sightline::GetSightlineResult(Gameint nIndex)
			{
				if (m_arrSightlineResult.Num() == 0 || nIndex >= m_arrSightlineResult.Num())
				{
					return SightlineResult();
				}
				return m_arrSightlineResult[nIndex];
			}

			void Sightline::UpdateArrSightlineResult()
			{
				m_arrSightlineResult.Empty();
				Gameint nTargetPointCount = GetTargetPointCount();
				for (Gameint n = 0; n < nTargetPointCount; n++)
				{
					Gamedouble dBarrierPointX = 0, dBarrierPointY = 0, dBarrierPointZ = 0;
					Gamedouble dReflectionPointX = 0, dReflectionPointY = 0, dReflectionPointZ = 0;
					Gamebool bSuccess = false;
					if (_GetBarrierPointAndReflectionPoint != nullptr)
					{
						bSuccess = _GetBarrierPointAndReflectionPoint(m_pSightline, n, dBarrierPointX, dBarrierPointY, dBarrierPointZ,
							dReflectionPointX, dReflectionPointY, dReflectionPointZ);

						if (m_pScene->GetSceneType() == Core::SceneType::Flat)
						{
							Swap(dBarrierPointX, dBarrierPointY);

							dBarrierPointX *= M_TO_CM;
							dBarrierPointY *= M_TO_CM;
							dBarrierPointZ *= M_TO_CM;
						}
					}
					SightlineResult Result;
					Result.vViewerPoint = FVector(m_vViewerPosition);
					Result.vTargetPoint = FVector(GetTargetPoint(n));
					if (!bSuccess)
					{
						Result.vBarrierPoint = FVector(dBarrierPointX, dBarrierPointY, dBarrierPointZ);
						Result.bVisibie = false;
					}
					else
					{
						Result.vBarrierPoint = FVector();
						Result.bVisibie = true;
					}
					m_arrSightlineResult.Add(Result);
				}
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif