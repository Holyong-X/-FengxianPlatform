#include "Core/Georeference.h"
#include "Algorithm3D/MathEngine.h"
#include "Base3D/CommonDefine.h"
#include "Core/ROCacheManager.h"

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Matrix4d Georeference::m_georeferenceToECEF = Matrix4d::IDENTITY;
			Matrix4d Georeference::m_ECEFtoGeoreference = Matrix4d::IDENTITY;
			Matrix4d Georeference::m_ueAbsToECEF = Matrix4d(
				CM_TO_M, 0, 0, 0,
				0, CM_TO_M, 0, 0,
				0, 0, CM_TO_M, 0,
				0, 0, 0, 1.0);
			Matrix4d Georeference::m_ECEFtoUeAbs = Matrix4d(
				M_TO_CM, 0, 0, 0,
				0, M_TO_CM, 0, 0,
				0, 0, M_TO_CM, 0,
				0, 0, 0, 1.0);

			double Georeference::m_dLongitude = 0.0;
			double Georeference::m_dLatitude = 0.0;
			double Georeference::m_dAltitude = 0.0;

			UWorld* Georeference::m_pWorld = nullptr;

			Georeference::Georeference()
			{
			}

			Georeference::~Georeference()
			{
			}

			void Georeference::Reset()
			{
				m_georeferenceToECEF = Matrix4d::IDENTITY;
				m_ECEFtoGeoreference = Matrix4d::IDENTITY;
				m_ueAbsToECEF = Matrix4d(
					CM_TO_M, 0, 0, 0,
					0, CM_TO_M, 0, 0,
					0, 0, CM_TO_M, 0,
					0, 0, 0, 1.0);
				m_ECEFtoUeAbs = Matrix4d(
					M_TO_CM, 0, 0, 0,
					0, M_TO_CM, 0, 0,
					0, 0, M_TO_CM, 0,
					0, 0, 0, 1.0);

				m_dLongitude = 0.0;
				m_dLatitude = 0.0;
				m_dAltitude = 0.0;
			}

			void Georeference::SetWorld(UWorld* pWorld)
			{
				m_pWorld = pWorld;
			}

			void Georeference::SetGeoreferenceOrigin(double dLongitude, double dLatitude, double dAltitude)
			{
				m_dLongitude = dLongitude;
				m_dLatitude = dLatitude;
				m_dAltitude = dAltitude;

				m_ECEFtoGeoreference = Algorithm3D::MathEngine::CalRotation(dLongitude, dLatitude, dAltitude);
				m_georeferenceToECEF = m_ECEFtoGeoreference.Invert();

				Matrix4d scaleToUGC = Matrix4d(
					CM_TO_M, 0, 0, 0,
					0, CM_TO_M, 0, 0,
					0, 0, CM_TO_M, 0,
					0, 0, 0, 1.0);
				m_ueAbsToECEF = scaleToUGC * m_georeferenceToECEF;

				Matrix4d scaleToUE = Matrix4d(
					M_TO_CM, 0, 0, 0,
					0, M_TO_CM, 0, 0,
					0, 0, M_TO_CM, 0,
					0, 0, 0, 1.0);
				m_ECEFtoUeAbs = m_ECEFtoGeoreference * scaleToUE;
			}

			const Matrix4d& Georeference::GetGeoreferenceToECEF()
			{
				return m_georeferenceToECEF;
			}

			const Matrix4d& Georeference::GetECEFtoGeoreference()
			{
				return m_ECEFtoGeoreference;
			}

			const Matrix4d& Georeference::GetUeAbsToECEF()
			{
				return m_ueAbsToECEF;
			}

			const Matrix4d& Georeference::GetECEFtoUeAbs()
			{
				return m_ECEFtoUeAbs;
			}

			Matrix4d Georeference::TransformECEFToUERelative(const Matrix4d& localToECEF)
			{
				Matrix4d doubleObjectMatrix = localToECEF;
				doubleObjectMatrix = doubleObjectMatrix * Georeference::GetECEFtoGeoreference();

				if (m_pWorld != nullptr)
				{
					if (ROCacheManager::m_eSceneType == Globe || ROCacheManager::m_eSceneType == Ellipsoid_WGS84)
					{
						doubleObjectMatrix[3][0] -= MathEngine::m_vWorldOffset.X;
						doubleObjectMatrix[3][1] -= MathEngine::m_vWorldOffset.Y;
						doubleObjectMatrix[3][2] -= MathEngine::m_vWorldOffset.Z;
					}

					Vector3d vOffset(m_pWorld->OriginLocation);
					doubleObjectMatrix[3][0] -= vOffset.X;
					doubleObjectMatrix[3][1] -= vOffset.Y;
					doubleObjectMatrix[3][2] -= vOffset.Z;
				}
				return doubleObjectMatrix;
			}
		}

		Vector3d Georeference::TransformGeorefenceECEFToUERelative(Vector3d vGeoECEF)
		{
			if (m_pWorld == nullptr)
			{
				return Vector3d(0.0, 0.0, 0.0);
			}
			//! \brief 米到厘米
			vGeoECEF *= M_TO_CM;

			//! \breif 绝对坐标
			Vector3d vUEAbsPos = vGeoECEF - Vector3d(MathEngine::m_vWorldOffset);

			//! \brief 渲染坐标
			Vector3d vUEPos = vUEAbsPos - Vector3d(m_pWorld->OriginLocation);

			return vUEPos;
		}

		Vector3d Georeference::TransformUEAbsToGeorefenceECEF(Vector3d vUEAbsPos)
		{
			//! \brief 设置地理原点的ECEF坐标
			Vector3d vGeoreferenceECEF = vUEAbsPos + Vector3d(MathEngine::m_vWorldOffset);

			vGeoreferenceECEF *= CM_TO_M;

			return vGeoreferenceECEF;
		}

		Vector3d Georeference::TransformUERelativeToGeorefenceECEF(Vector3d vUEPos)
		{
			if (m_pWorld == nullptr)
			{
				return Vector3d(0.0, 0.0, 0.0);
			}

			//! \breif 绝对坐标
			Vector3d vUEAbsPos = vUEPos + Vector3d(m_pWorld->OriginLocation);

			//! \brief 设置地理原点的ECEF坐标
			Vector3d vGeoreferenceECEF = vUEAbsPos + Vector3d(MathEngine::m_vWorldOffset);

			vGeoreferenceECEF *= CM_TO_M;

			return vGeoreferenceECEF;
		}

		Vector3d Georeference::TransformOriginECEFToUEReative(Vector3d vECEF)
		{
			if (m_pWorld == nullptr)
			{
				return Vector3d(0.0, 0.0, 0.0);
			}

			//! \brief 米到厘米
			vECEF *= M_TO_CM;

			//! \brief 设置地理原点的ECEF坐标
			Vector3d vGeoreferECEF = vECEF.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
			
			//! \brief 绝对坐标
			Vector3d vUEAbsPos = vGeoreferECEF - Vector3d(MathEngine::m_vWorldOffset);
			
			//! \brief 局部坐标
			Vector3d vUEReative = vUEAbsPos - Vector3d(m_pWorld->OriginLocation);

			return vUEReative;
		}

		Vector3d Georeference::TransformUERelativeToOriginECEF(Vector3d vUEPos)
		{
			if (m_pWorld == nullptr)
			{
				return Vector3d(0.0,0.0,0.0);
			}

			//! \breif 绝对坐标
			Vector3d vUEAbsPos = vUEPos + Vector3d(m_pWorld->OriginLocation);

			//! \brief 设置地理原点的ECEF坐标
			Vector3d vGeorerenceECEF = vUEAbsPos + Vector3d(MathEngine::m_vWorldOffset);

			//! \brief 设置（0，0，0）原点的ECEF坐标
			Vector3d vOrginalECEF = vGeorerenceECEF.MultiplyMatrix(Georeference::GetECEFtoGeoreference().Invert());

			//! \brief 厘米到米
			vOrginalECEF *= CM_TO_M;
			return vOrginalECEF;
		}

		void Georeference::TransformUERelativeToOriginECEF(Vector3d& vUEPos, FRotator& rRotate)
		{
			if (m_pWorld == nullptr)
			{
				return;
			}

			//! \breif 绝对坐标
			Vector3d vUEAbsPos = vUEPos + Vector3d(m_pWorld->OriginLocation);

			//! \brief 设置地理原点的ECEF坐标
			Vector3d vGeorefenceECEF = vUEAbsPos + Vector3d(MathEngine::m_vWorldOffset);

			//! \brief 厘米到米
			vGeorefenceECEF *= CM_TO_M;

			//! \brief 设置（0，0，0）原点的ECEF坐标
			FVector vGeorefenceECEF_Float = vGeorefenceECEF.ToFVector();

			MathEngine::UpdateRotationAndLocation(vGeorefenceECEF_Float, rRotate, Georeference::GetECEFtoGeoreference().Invert());
			Vector3d vOrginalECEF(vGeorefenceECEF_Float);

			vUEPos = vOrginalECEF;
		}

		Vector3d Georeference::TransformUERelativeToUEAbs(Vector3d vUEPos)
		{
			if (m_pWorld == nullptr)
			{
				return Vector3d(0.0,0.0,0.0);
			}

			//! \brief 相对坐标到绝对坐标
			return vUEPos + Vector3d(m_pWorld->OriginLocation);
		}

		Vector3d Georeference::TransformUEAbsToUERelative(Vector3d vUEAbsPos)
		{
			if (m_pWorld == nullptr)
			{
				return vUEAbsPos;
			}

			//! \brief 绝对坐标到相对坐标
			return vUEAbsPos - Vector3d(m_pWorld->OriginLocation);
		}

		Vector3d Georeference::TransformUEECEFToUGCECEF(Vector3d vUEPos)
		{
			//! \brief UE坐标系到UGC坐标系
			Swap(vUEPos.X, vUEPos.Y);
			return vUEPos;
		}

		void Georeference::TransformECEFToUERelative(const Matrix4d& localToECEF, FTransform& transform)
		{
			Matrix4d doubleObjectMatrix = Georeference::TransformECEFToUERelative(localToECEF);
			FMatrix dMat;
			Matrix4d::ToFMatrix(doubleObjectMatrix, dMat);
			transform.SetFromMatrix(dMat);
		}
	}
}