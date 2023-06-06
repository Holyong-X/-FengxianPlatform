#include "Render/DrawBox.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Component/SuperMap_MeshComponent.h"
#include "Engine/World.h"
#include "Core/ROCacheManager.h"
#include "Data/Matrix4d.h"
#include "Base3D/CommonDefine.h"
#include "Core/Georeference.h"
#include "Algorithm3D/MathEngine.h"

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			DrawBox::DrawBox()
			{
	
			}

			DrawBox::~DrawBox()
			{

			}

			void DrawBox::GetBoundsVector(Vector3d start, Vector3d end, Vector3d& v1, Vector3d& v2, Vector3d& v3, Vector3d& v4,
				Vector3d& v5, Vector3d& v6, Vector3d& v7, Vector3d& v8)
			{
				Data::Vector3d vStart = start;
				Data::Vector3d vEnd = end;
				if (ROCacheManager::m_eSceneType == Core::Flat)
				{
					Swap(vStart.X, vStart.Y);
					Swap(vEnd.X, vEnd.Y);
					float height = FMath::Abs(vStart.Z - vEnd.Z);
					v1 = Vector3d(vStart.X, vStart.Y, 0);
					v2 = Vector3d(vStart.X, vEnd.Y, 0);
					v3 = Vector3d(vEnd.X, vStart.Y, 0);
					v4 = Vector3d(vEnd.X, vEnd.Y, 0);
					v5 = Vector3d(vStart.X, vStart.Y, height);
					v6 = Vector3d(vStart.X, vEnd.Y, height);
					v7 = Vector3d(vEnd.X, vStart.Y, height);
					v8 = Vector3d(vEnd.X, vEnd.Y, height);
				}
				else
				{
					// 高度
					float fLonMin, fLatMin, fAltitudeMin;
					float fLonMax, fLatMax, fAltitudeMax;

					fLonMin = FMath::Min(vStart.X, vEnd.X);
					fLonMax = FMath::Max(vStart.X, vEnd.X);

					fLatMin = FMath::Min(vStart.Y, vEnd.Y);
					fLatMax = FMath::Max(vStart.Y, vEnd.Y);

					fAltitudeMin = FMath::Min(vStart.Z, vEnd.Z);
					fAltitudeMax = FMath::Max(vStart.Z, vEnd.Z);

					// 求包围盒的八个点
					SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(fLonMin, fLatMin, fAltitudeMin, v1.X, v1.Y, v1.Z);
					SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(fLonMin, fLatMax, fAltitudeMin, v2.X, v2.Y, v2.Z);
					SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(fLonMax, fLatMin, fAltitudeMin, v3.X, v3.Y, v3.Z);
					SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(fLonMax, fLatMax, fAltitudeMin, v4.X, v4.Y, v4.Z);

					v1 *= M_TO_CM;
					v2 *= M_TO_CM;
					v3 *= M_TO_CM;
					v4 *= M_TO_CM;
					
					v1.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
					v2.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
					v3.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
					v4.MultiplyMatrix(Georeference::GetECEFtoGeoreference());

					v1 -= (Vector3d(ROCacheManager::m_vecWorldOrigin) + MathEngine::m_vWorldOffset);
					v2 -= (Vector3d(ROCacheManager::m_vecWorldOrigin) + MathEngine::m_vWorldOffset);
					v3 -= (Vector3d(ROCacheManager::m_vecWorldOrigin) + MathEngine::m_vWorldOffset);
					v4 -= (Vector3d(ROCacheManager::m_vecWorldOrigin) + MathEngine::m_vWorldOffset);

					SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(fLonMin, fLatMin, fAltitudeMax, v5.X, v5.Y, v5.Z);
					SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(fLonMin, fLatMax, fAltitudeMax, v6.X, v6.Y, v6.Z);
					SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(fLonMax, fLatMin, fAltitudeMax, v7.X, v7.Y, v7.Z);
					SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(fLonMax, fLatMax, fAltitudeMax, v8.X, v8.Y, v8.Z);
					v5 *= M_TO_CM;
					v6 *= M_TO_CM;
					v7 *= M_TO_CM;
					v8 *= M_TO_CM;

					v5.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
					v6.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
					v7.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
					v8.MultiplyMatrix(Georeference::GetECEFtoGeoreference());

					v5 -= (Vector3d(ROCacheManager::m_vecWorldOrigin) + MathEngine::m_vWorldOffset);
					v6 -= (Vector3d(ROCacheManager::m_vecWorldOrigin) + MathEngine::m_vWorldOffset);
					v7 -= (Vector3d(ROCacheManager::m_vecWorldOrigin) + MathEngine::m_vWorldOffset);
					v8 -= (Vector3d(ROCacheManager::m_vecWorldOrigin) + MathEngine::m_vWorldOffset);
				}
			}
		}
	}
}