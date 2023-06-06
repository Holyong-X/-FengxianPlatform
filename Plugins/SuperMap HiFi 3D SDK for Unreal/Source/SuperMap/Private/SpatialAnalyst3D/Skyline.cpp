#include "SpatialAnalyst3D/Skyline.h"
#include "Engine/World.h"
#include "Component/MeshData.h"
#include "Core/ROCache.h"
#include "Base3D/CommonDefine.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Core/Georeference.h"
#include "Algorithm3D/MathEngine.h"
#include "map"

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst3D
		{
			Skyline::Skyline(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl) : Analyst3D(pWorld, pScene, pCameraControl)
			{
				m_skylineColor   = FColor::Red;
				m_pSkyline       = nullptr;
				m_bUpdateSkyline = false;
				m_pSkylineActor  = pWorld->SpawnActor<ASuperMap_ROEntityActor>();
				
				m_pSkylineActor->SetIsSceneHiddenObject(true);

				if (_CreateSkyline != nullptr)
				{
					_CreateSkyline(m_pSkyline);
				}
			}

			Skyline::~Skyline()
			{
				Release();
			}

			void Skyline::Release()
			{
				m_pSkylineActor->SetIsSceneHiddenObject(false);
				m_pSkylineActor->Destroy(false, false);
				m_pSkylineActor = nullptr;

				if (_DestroySkyline != nullptr)
				{
					_DestroySkyline(m_pSkyline);
				}
			}

			void Skyline::SetViewerDirection(double dDirection)
			{
				SuperMapSDK::UnrealEngine::Core::_SetSkylineViewerDirection(m_pSkyline, dDirection);
				m_bUpdateSkyline = true;
			}

			double Skyline::GetViewerDirection()
			{
				double dDirection = 0;
				if (_GetSkylineViewerDirection != nullptr)
				{
					_GetSkylineViewerDirection(m_pSkyline, dDirection);
				}
				
				return dDirection;
			}

			void Skyline::SetViewerPosition(Vector3d vPos)
			{
				Vector3d vNewPos = vPos;
				if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
				{
					vNewPos.X = vPos.Y * CM_TO_M;
					vNewPos.Y = vPos.X * CM_TO_M;
					vNewPos.Z = vPos.Z * CM_TO_M;
				}

				if (_SetSkylineViewerPosition != nullptr)
				{
					_SetSkylineViewerPosition(m_pSkyline, vNewPos.X, vNewPos.Y, vNewPos.Z);
				}
				m_bUpdateSkyline = true;
			}

			Vector3d Skyline::GetViewerPosition()
			{
				double dPosX = 0, dPosY = 0, dPosZ = 0;

				if (_GetSkylineViewerPosition != nullptr)
				{
					_GetSkylineViewerPosition(m_pSkyline, dPosX, dPosY, dPosZ);
				}

				return Vector3d(dPosX, dPosY, dPosZ);
			}

			void Skyline::SetViewerPitch(double dPitch)
			{
				dPitch = dPitch - 90.0;
				SuperMapSDK::UnrealEngine::Core::_SetSkylineViewerPitch(m_pSkyline, dPitch);
				m_bUpdateSkyline = true;
			}

			double Skyline::GetViewerPitch()
			{
				double dPitch = 0;
				SuperMapSDK::UnrealEngine::Core::_GetSkylineViewerPitch(m_pSkyline, dPitch);
				dPitch = 90 + dPitch;
				return dPitch;
			}

			void Skyline::SetRadius(double dRadius)
			{
				SuperMapSDK::UnrealEngine::Core::_SetSkylineRadius(m_pSkyline, dRadius);
			}

			double Skyline::GetRadius()
			{
				double dRadius = 0;
				SuperMapSDK::UnrealEngine::Core::_GetSkylineRadius(m_pSkyline, dRadius);
				return dRadius;
			}

			void Skyline::SetSkylineColor(const FColor& color)
			{
				m_skylineColor = color;

				if (m_pSkylineActor != nullptr)
				{
					UMaterialInstanceDynamic* pMaterialInterfaceDynamic = (UMaterialInstanceDynamic*)m_pSkylineActor->GetMaterial();
					if (pMaterialInterfaceDynamic != nullptr)
					{
						pMaterialInterfaceDynamic->SetVectorParameterValue(FName("LineColor"), m_skylineColor);
					}
				}
			}

			FColor Skyline::GetSkylineColor() const
			{
				return m_skylineColor;
			}

			void Skyline::DoBuild()
			{
				if (_BuildSkyline != nullptr)
				{
					_BuildSkyline(m_pSkyline);
				}
			}

			void Skyline::DoClear()
			{
		
			}

			void Skyline::CreateSkyline3D(GeoLine3D* pGeoLine3D)
			{
				if (pGeoLine3D == nullptr)
				{
					return;
				}

				m_pSkylineActor->ClearMesh();

				TArray<Vector3d> arrPoints;
				pGeoLine3D->GetPoints(arrPoints);

				TArray<SM_Vertex> arrVtxs;
				int32 nPoints = arrPoints.Num();

				TArray<int32> arrIndexs;

				for (int32 n = 0; n < nPoints; n++)
				{
					Vector3d v3DPos = arrPoints[n];

					if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH ||
						ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH_ELLIPSOID_WGS84)
					{
						Data::Vector3d cartesianPos3d;
						SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(v3DPos.X, v3DPos.Y, v3DPos.Z, cartesianPos3d.X, cartesianPos3d.Y, cartesianPos3d.Z);
						v3DPos = cartesianPos3d * M_TO_CM;
						v3DPos.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
						v3DPos -= MathEngine::m_vWorldOffset;
					}
					else if(ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
					{
						Swap(v3DPos.X, v3DPos.Y);

						v3DPos *= M_TO_CM;
					}

					v3DPos.X -= m_pWorld->OriginLocation.X;
					v3DPos.Y -= m_pWorld->OriginLocation.Y;
					v3DPos.Z -= m_pWorld->OriginLocation.Z;

					SM_Vertex vertex;
					vertex.Position.X = v3DPos.X;
					vertex.Position.Y = v3DPos.Y;
					vertex.Position.Z = v3DPos.Z;
					vertex.Color = m_skylineColor;
					arrVtxs.Add(vertex);
					
					if (n < (nPoints - 1))
					{
						arrIndexs.Add(n);
						arrIndexs.Add(n + 1);
					}
					
				}

				TArray<SM_SubMesh> arrSubMeshs;
				SM_SubMesh subMesh;

				UMaterialInterface* pMat = m_pSkylineActor->GetMaterial();
				if (m_pSkylineActor->GetMaterial() == nullptr)
				{
					static UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
					pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
					((UMaterialInstanceDynamic*)pMat)->SetVectorParameterValue(FName("LineColor"), FColor::Red);
					subMesh.m_pMaterialInterface = pMat;
					m_pSkylineActor->SetMaterial(pMat);
				}
				subMesh.IndexBuffer = arrIndexs;
				arrSubMeshs.Add(subMesh);

				m_pSkylineActor->SetDrawType(2);
				m_pSkylineActor->CreateLineMeshComponent(arrVtxs, arrSubMeshs);

				m_bUpdateSkyline = false;
			}


			void Skyline::Render()
			{
				if (m_bUpdateSkyline)
				{
					GeoLine3D* pGeoLine3D = GetSkyline(0);
					CreateSkyline3D(pGeoLine3D);

					if (pGeoLine3D != nullptr)
					{
						delete pGeoLine3D;
					}
				}
			}

			GeoLine3D* Skyline::GetSkyline(double dRadius)
			{
				if (_GetSkyline != nullptr)
				{
					void* pUGGeoLine3D = nullptr;
					_GetSkyline(m_pSkyline, pUGGeoLine3D);
					
					GeoLine3D* pGeoLine3D = new GeoLine3D(pUGGeoLine3D);
					return pGeoLine3D;
				}

				return nullptr;
			}

			GeoLine* Skyline::GetSkyline2D()
			{
				if (_GetSkyline2D != nullptr)
				{
					void* pUGGeoLine2D = nullptr;
					_GetSkyline2D(m_pSkyline, pUGGeoLine2D);

					GeoLine* pGeoLine = new GeoLine(pUGGeoLine2D);
					return pGeoLine;
				}

				return nullptr;
			}

			GeoModel3D* Skyline::GetSkylineSectorBody(double dHeight)
			{
				void* pUGGeoModel3D = nullptr;
				_GetSkylineSectorBody(m_pSkyline, dHeight, pUGGeoModel3D);
				if (pUGGeoModel3D != nullptr)
				{
					GeoModel3D* pGeoModel3D = new GeoModel3D(pUGGeoModel3D);
					return pGeoModel3D;
				}
				return nullptr;
			}

			TMap<Gameint, TArray<Gameint>> Skyline::GetObjectIDs()
			{
				TMap<Gameint, TArray<Gameint>> objectIDs;
				std::map<Gameint, Gameint*> mapGameObject;
				Gameint* nIdCount = nullptr;
				_Skyline_GetObjectIDs(m_pSkyline, mapGameObject, nIdCount);
				std::map<Gameint, Gameint* >::iterator itorObject = mapGameObject.begin();
				Gameint index = 0;
				while (itorObject != mapGameObject.end())
				{
					TArray<Gameint> ids;
					for (Gameint i = 0; i < nIdCount[index]; i++)
					{
						Gameint id = itorObject->second[i];
						ids.Add(id);
					}
					objectIDs.Add(itorObject->first, ids);
					index++;

					MathEngine::FreeUGInt(itorObject->second);
					itorObject++;
				}
				if (index > 0)
				{
					MathEngine::FreeUGInt(nIdCount);
				}
				return objectIDs;
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif