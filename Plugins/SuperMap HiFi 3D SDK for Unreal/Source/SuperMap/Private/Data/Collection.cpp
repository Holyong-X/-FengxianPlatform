#include "Data/Collection.h"
#include "Engine/StaticMesh.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Collection::Collection(UWorld* pWorld)
			{
				m_pWorld = pWorld;
				m_pInstancedActor = nullptr;
			}

			Collection::~Collection()
			{
				if (m_pInstancedActor == nullptr)
				{
					m_pInstancedActor->Destroy();
				}
			}

			void Collection::SetStyleParam(CollectionStyleParam & styleParam)
			{
				m_StyleParam = styleParam;
			}

			CollectionStyleParam& Collection::GetStyleParam()
			{
				return m_StyleParam;
			}

			Geometry* Collection::GetGeometry(int32 nIndex)
			{
				if (nIndex < 0 || nIndex > m_Geometrys.Num())
				{
					return nullptr;
				}

				return m_Geometrys[nIndex];
			}

			void Collection::AddGeometry(Geometry* pGeometry)
			{
				if (pGeometry == nullptr)
				{
					return;
				}

				m_Geometrys.Add(pGeometry);
			}

			FQuat Collection::CallRotator(FVector vDirectionUP)
			{
				FVector vUp = vDirectionUP;
				vUp.Normalize();

				FVector vInitital(0, 0, 1);
				vInitital.Normalize();

				float fACos = FMath::Acos(FVector::DotProduct(vInitital, vUp));
				FVector vAxis = FVector::CrossProduct(vInitital, vUp);

				FQuat q(vAxis, fACos);

				FRotator r(0, 0, 0);

				FQuat qInitital(r);
				qInitital = q * qInitital;
				qInitital.Normalize();

				return qInitital;
			}

			UStaticMesh* Collection::CreateStaticMesh(FString strAssetPath)
			{
				UStaticMesh* pStaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *strAssetPath));
				return pStaticMesh;
			}
		}
	}
}