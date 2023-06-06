#include "Data/LineCollection.h"
#include "Engine/World.h"
#include "Data/GeoLine3D.h"
#include "ControlUE/CameraControl.h"
#include "Algorithm3D/MathEngine.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			LineCollection::LineCollection(UWorld* pWorld) :Collection(pWorld)
			{

			}


			LineCollection::~LineCollection()
			{

			}

			bool LineCollection::BuildStyle()
			{
				if (m_pWorld == nullptr || m_Geometrys.Num() == 0)
				{
					return false;
				}

				if (m_StyleParam.m_strAssetResoureName.IsEmpty() ||
					m_StyleParam.m_strAssetResourePath.IsEmpty())
				{
					return false;
				}

				if (m_pInstancedActor == nullptr)
				{
					m_pInstancedActor = m_pWorld->SpawnActor<ASuperMap_InstancedActor>();
				}

				// 载入静态网格
				UStaticMesh* pStaticMesh = CreateStaticMesh(m_StyleParam.m_strAssetResourePath);
				if (pStaticMesh == nullptr)
				{
					return false;
				}

				m_pInstancedActor->m_pInstanceStaticMeshComponent->SetStaticMesh(pStaticMesh);

				// 最基础的模式（每个点上面）
				for (int32 nGeometry = 0; nGeometry < m_Geometrys.Num(); nGeometry++)
				{
					GeoLine3D* pGeoLine3D = (GeoLine3D*)(m_Geometrys[nGeometry]);
					if (pGeoLine3D == nullptr)
					{
						continue;
					}

					TArray<FVector> arrPoints;
					pGeoLine3D->GetPoints(arrPoints);
					
					for (int32 nPoint = 0 ; nPoint < arrPoints.Num(); nPoint++)
					{
						FTransform trans;
						FVector vWorldOrigin = FVector(m_pWorld->OriginLocation);
						if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
						{
							FVector vLocation = arrPoints[nPoint] - vWorldOrigin;
							trans.SetLocation(vLocation);
						}
						else if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH ||
							     ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH_ELLIPSOID_WGS84)
						{
							FVector vSphericalLocation = arrPoints[nPoint];
							FVector vRealLocation = Algorithm3D::MathEngine::SphericalToCartesian(vSphericalLocation.X, vSphericalLocation.Y, vSphericalLocation.Z);

							vRealLocation *= M_TO_CM;

							FQuat qRotation = CallRotator(vRealLocation);
							FVector vLocation = vRealLocation - vWorldOrigin;

							trans.SetLocation(vLocation);
							trans.SetRotation(qRotation);
						}

						m_pInstancedActor->m_pInstanceStaticMeshComponent->AddInstance(trans);
					}
				}

				return true;
			}

			CollectionType LineCollection::GetType()
			{
				return CollectionType::CT_LINE;
			}
		}
	}
}