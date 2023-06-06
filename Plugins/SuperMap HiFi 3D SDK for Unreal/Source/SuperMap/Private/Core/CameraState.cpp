// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CameraState.h"
#include "Engine/World.h"
#include "Core/RealspaceDLL.h"
#include "Data/Matrix4d.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/Georeference.h"
#include "ControlUE/RealspaceView.h"
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::ControlUE;

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			CameraState::CameraState()
			{
				m_pUGCamera = nullptr;
				if (_CameraCreate != nullptr)
				{
					_CameraCreate(m_pUGCamera);
					m_bCreateUGCamera = true;
					m_bFixedRotationOfCamera = true;
				}
			}

			CameraState::CameraState(Gamevoid* pCamera)
			{
				m_bCreateUGCamera = false;
				m_pUGCamera = pCamera;
				m_bFixedRotationOfCamera = true;
			}

			CameraState::~CameraState()
			{
				if (m_bCreateUGCamera && _CameraDestory != nullptr)
				{
					_CameraDestory(m_pUGCamera);
				}
				m_pUGCamera = nullptr;
				m_bCreateUGCamera = false;
			}

			Gamevoid CameraState::SetUGCameraViewMatrix(FMatrix ueViewMatrix)
			{
				Matrix4d matViewMatrix(ueViewMatrix);
				Gamedouble* pViewMatrix = new Gamedouble[16];
				Matrix4d::ToDoublePointer(matViewMatrix, pViewMatrix);
				if (_CameraSetViewMatrix != nullptr)
				{
					_CameraSetViewMatrix(m_pUGCamera, pViewMatrix);
				}

				delete[] pViewMatrix;
			}

			Gamevoid CameraState::SetUGCameraState(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude, 
				Gamedouble dPitch, Gamedouble dHeading, Gamedouble dRoll)
			{
				if (_CameraSetUGCState)
				{
					_CameraSetUGCState(m_pUGCamera, dLongitude, dLatitude, dAltitude, dPitch, dHeading, dRoll);
				}
			}

			Gamevoid CameraState::SetUGCameraState(Vector3d vCameraLocation, FRotator vCameraRotator)
			{
				vCameraLocation += Vector3d(ROCacheManager::m_vecWorldOrigin);
				FVector vfCameraLocation = vCameraLocation.ToFVector();
				MathEngine::UpdateRotationAndLocation(vfCameraLocation, vCameraRotator, Georeference::GetECEFtoGeoreference().Invert());
				vCameraLocation = Vector3d(vfCameraLocation);
				vCameraLocation.X *= CM_TO_M;
				vCameraLocation.Y *= CM_TO_M;
				vCameraLocation.Z *= CM_TO_M;
				// »ñÈ¡ÊÓÍ¼¾ØÕó
				FVector vCameraLocationF = vCameraLocation.ToFVector();
				Swap(vCameraLocationF.X, vCameraLocationF.Y);
				FQuat qQuat = vCameraRotator.Quaternion();
				FVector vUp = qQuat.GetUpVector();
				vUp.Normalize();
				Swap(vUp.X, vUp.Y);
				FVector vRight = qQuat.GetRightVector();
				vRight.Normalize();
				Swap(vRight.X, vRight.Y);
				FMatrix matRoationXY = FRotationMatrix::MakeFromYZ(vRight, vUp);
				vCameraRotator = matRoationXY.Rotator();
				FViewMatrices viewMatrices;
				viewMatrices.UpdateViewMatrix(vCameraLocationF, vCameraRotator);
				FMatrix mat = viewMatrices.GetViewMatrix();
				SetUGCameraViewMatrix(mat);
			}

			Gamedouble CameraState::GetUGCameraHeading()
			{
				Gamedouble dHeading = 0;
				if (_CameraGetHeading != nullptr)
				{
					dHeading = _CameraGetHeading(m_pUGCamera);
					dHeading = FMath::RadiansToDegrees(dHeading);
					
				}
				return dHeading;
			}

			Gamedouble CameraState::GetUGCameraTilt()
			{
				Gamedouble dTilt = 0;
				if (_CameraGetTilt != nullptr)
				{
					dTilt = _CameraGetTilt(m_pUGCamera);
					dTilt = FMath::RadiansToDegrees(dTilt);
				}
				return dTilt;
			}

			Gamedouble CameraState::GetUGCameraRoll()
			{
				Gamedouble dRoll = 0;
				if (_CameraGetRoll != nullptr)
				{
					dRoll = _CameraGetRoll(m_pUGCamera);
				}
				return dRoll;
			}

			Gamedouble CameraState::GetUGCameraLongitude()
			{
				Gamedouble dLongitude = 0;
				if (_Camera_GetLongitude != nullptr)
				{
					dLongitude = _Camera_GetLongitude(m_pUGCamera);
				}
				return dLongitude;
			}
	
			Gamedouble CameraState::GetUGCameraLatitude()
			{
				Gamedouble dLatitude = 0;
				if (_Camera_GetLatitude != nullptr)
				{
					dLatitude = _Camera_GetLatitude(m_pUGCamera);
				}
				return dLatitude;
			}

			Gamedouble CameraState::GetUGCameraAltitude()
			{
				Gamedouble dAltitude = 0;
				if (_Camera_GetAltitude != nullptr)
				{
					dAltitude = _Camera_GetAltitude(m_pUGCamera);
				}
				return dAltitude;
			}

			Gamevoid* CameraState::GetUGCameraHandler()
			{
				return m_pUGCamera;
			}

			Gamevoid CameraState::SyncMainCam(CameraControl* pCameraControl)
			{
				Gamedouble* pViewMatrix = new Gamedouble[16];
				Gamedouble* pProjMatrix = new Gamedouble[16];
				_CameraGetViewProjectMatrix(m_pUGCamera, pViewMatrix, pProjMatrix);
				Matrix4d ugcViewMatrix(pViewMatrix);
				Vector3d vLocation;
				FRotator vRotator;
				MathEngine::UGCViewMatrixToUERotationAndLocation(pViewMatrix, vLocation, vRotator);
				if (m_bFixedRotationOfCamera)
				{
					pCameraControl->SetCameraLocationAndRotation(vLocation.ToFVector(), vRotator);
				}
				else
				{
					FVector vCameraLocation;
					FRotator rCameraRotator;
					RealspaceView::GetSingleton()->GetCameraControl()->m_pCurrentPlayerControl->GetPlayerViewPoint(vCameraLocation, rCameraRotator);
					SetUGCameraState(vLocation.ToFVector(), rCameraRotator);
					RealspaceView::GetSingleton()->GetCameraControl()->m_pCurrentPlayerControl->GetPawn()->SetActorLocation(vLocation.ToFVector());
				}

				delete[] pViewMatrix;
				delete[] pProjMatrix;
			}

			Gamevoid CameraState::SetRotationOfCameraFixed(Gamebool bSet)
			{
				m_bFixedRotationOfCamera = bSet;
			}

			Gamebool CameraState::IsRotationOfCameraFixed()
			{
				return m_bFixedRotationOfCamera;
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif
