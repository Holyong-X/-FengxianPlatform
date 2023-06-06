#include "Data/PointCollection.h"
#include "Engine/World.h"
#include "Component/SuperMap_InstancedActor.h"
#include "Data/GeoPoint3D.h"
#include "ControlUE/CameraControl.h"
#include "Algorithm3D/MathEngine.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			PointCollection::PointCollection(UWorld* pWorld):Collection(pWorld)
			{
				m_eCollectionType = CollectionType::CT_POINT;
			}


			PointCollection::~PointCollection()
			{
				
			}

			bool PointCollection::BuildStyle()
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
				for (int32 nGeometry = 0 ; nGeometry < m_Geometrys.Num(); nGeometry++)
				{
					GeoPoint3D* pGeoPoint3D = (GeoPoint3D*)(m_Geometrys[nGeometry]);
					if (pGeoPoint3D == nullptr)
					{
						continue;
					}

					FTransform trans;
					FVector vWorldOrigin = FVector(m_pWorld->OriginLocation);
					if(ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_PLANE)
					{
						FVector vLocation = pGeoPoint3D->GetPoint3D().ToFVector() - vWorldOrigin;
						trans.SetLocation(vLocation);
					}
					else if (ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH ||
						     ControlUE::CameraControl::m_eSceneType == ControlUE::UGC_EARTH_ELLIPSOID_WGS84)
					{
						FVector vSphericalLocation = pGeoPoint3D->GetPoint3D().ToFVector();
						FVector vRealLocation = Algorithm3D::MathEngine::SphericalToCartesian(vSphericalLocation.X, vSphericalLocation.Y, vSphericalLocation.Z);

						vRealLocation *= M_TO_CM;

						FQuat qRotation = CallRotator(vRealLocation);
						FVector vLocation = vRealLocation - vWorldOrigin;

						trans.SetLocation(vLocation);
						trans.SetRotation(qRotation);
					}

					m_pInstancedActor->m_pInstanceStaticMeshComponent->AddInstance(trans);
				}

				return true;
			}

			CollectionType PointCollection::GetType()
			{
				return CollectionType::CT_POINT;
			}
		}
	}
}