// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneOperation/SuperMap_FlyManagerInstance.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/Georeference.h"
#include "Runtime/Core/Public/Misc/MessageDialog.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::Core;
PRAGMA_DISABLE_OPTIMIZATION
// Sets default values
ASuperMap_FlyManagerInstance::ASuperMap_FlyManagerInstance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_bFlyInit = false;
	m_bEnableLoopFly = false;
	m_nRouteIndex = 0;
	m_nTurningMode = FlyTurningMode::Smoothly;
	m_dPlayRate = 1;
	m_bFly = false;
}

ASuperMap_FlyManagerInstance::~ASuperMap_FlyManagerInstance()
{
	m_bFlyInit = false;
	m_bEnableLoopFly = false;
	m_nRouteIndex = 0;
	m_nTurningMode = FlyTurningMode::Smoothly;
	m_dPlayRate = 1;
	m_bFly = false;
}

// Called when the game starts or when spawned
void ASuperMap_FlyManagerInstance::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASuperMap_FlyManagerInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_bFly)
	{
 		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager()->GetStatus() == FlyStatus::Stop)
		{
			if (CallFlyManagerEvent.IsBound())
			{
				CallFlyManagerEvent.Broadcast();
			}
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetCameraState()->SetRotationOfCameraFixed(true);
			m_bFly = false;
		}
	}
}

int ASuperMap_FlyManagerInstance::LaunchFly(FString FlyFile)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		Routes* pRoutes = pFlyManager->GetRoutes();
		Gamebool success = pRoutes->FromFile(FlyFile);
		if (!success)
		{
			delete pFlyManager;
			pFlyManager = nullptr;
			return -1;
		}
		pFlyManager->SetTurningMode(pFlyManager->GetTurningMode());
		int n = pRoutes->GetCurrentRouteIndex();
		if (n == -1)
		{
			delete pFlyManager;
			pFlyManager = nullptr;
			return -1;
		}
		m_nRouteIndex = pRoutes->GetCurrentRouteIndex();
		int nCount = pRoutes->Count();
		if (nCount < 1)
		{
			delete pFlyManager;
			pFlyManager = nullptr;
			return -1;
		}
		Route* pRoute = pRoutes->GetRoute(m_nRouteIndex);
		pRoute->SetIsFlyingLoop(m_bEnableLoopFly);
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
		{
			pFlyManager->SetOriginalPosition(RealspaceView::GetSingleton()->GetSceneControl()->GetTerrainPosition());
		}
		
		pFlyManager->Update();
		m_bFlyInit = true;
		return nCount;
	}
	return -1;
}

void ASuperMap_FlyManagerInstance::SetFlyStatus(int nStatus)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (m_bFlyInit && pFlyManager != nullptr)
	{
		switch (nStatus)
		{
		case 0:
			pFlyManager->Stop();
			m_bFly = false;
			break;
		case 1:
			pFlyManager->Pause();
			m_bFly = false;
			break;
		case 2:
			pFlyManager->Play();
			m_bFly = true;
			break;
		}
	}
}

int ASuperMap_FlyManagerInstance::GetFlyStatus()
{
	int status = 0;
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		if (pFlyManager->GetStatus() == FlyStatus::Pause)
		{
			status = 1;
		}
		else if (pFlyManager->GetStatus() == FlyStatus::Stop)
		{
			status = 0;
		}
		else
		{
			status = 2;
		} 
	}
	return status;
}

void ASuperMap_FlyManagerInstance::SetEnableLoopFly(bool bEnableLoop)
{
	m_bEnableLoopFly = bEnableLoop;
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (m_bFlyInit && pFlyManager != nullptr)
	{
		pFlyManager->GetRoutes()->GetRoute(m_nRouteIndex)->SetIsFlyingLoop(m_bEnableLoopFly);
		pFlyManager->Update();
	}
}

void ASuperMap_FlyManagerInstance::SetCurrentRoute(int nIndex)
{
	m_nRouteIndex = nIndex;
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr && pFlyManager->GetStatus() == FlyStatus::Stop)
	{
		Gamebool bCurrent = pFlyManager->GetRoutes()->SetCurrentRouteIndex(m_nRouteIndex);
		if (bCurrent)
		{
			pFlyManager->Update();
		}
	}
}

void ASuperMap_FlyManagerInstance::SetPlayRate(float dPlayRate)
{
	m_dPlayRate = dPlayRate;
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (m_bFlyInit && pFlyManager != nullptr)
	{
		pFlyManager->SetPlayRate((double)m_dPlayRate);
		pFlyManager->Update();
	}
}

void ASuperMap_FlyManagerInstance::SetFlyTurningMode(int nMode)
{
	switch (nMode)
	{
	case 0:
		m_nTurningMode = FlyTurningMode::Smoothly;
		break;
	case 1:
		m_nTurningMode = FlyTurningMode::Directly;
		break;
	}
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (m_bFlyInit && pFlyManager != nullptr)
	{
		pFlyManager->SetTurningMode(m_nTurningMode);
		pFlyManager->Update();
	}
}

void ASuperMap_FlyManagerInstance::SetDuration(float dDuration)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr && pFlyManager->GetStatus() == FlyStatus::Stop)
	{
		pFlyManager->SetDuration((double)dDuration);
		pFlyManager->Update();
	}
}

float ASuperMap_FlyManagerInstance::GetDuration()
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (m_bFlyInit && pFlyManager != nullptr)
	{
		return (float)pFlyManager->GetDuration();
	}
	return 0;
}

FString ASuperMap_FlyManagerInstance::GetRouteName(int nIndex)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		return pFlyManager->GetRoutes()->GetRoute(nIndex)->GetName();
	}
	return FString("");
}

void ASuperMap_FlyManagerInstance::SetRouteName(FString name, int nIndex)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		pFlyManager->GetRoutes()->GetRoute(nIndex)->SetName(name);
	}
}

int ASuperMap_FlyManagerInstance::GetCurrentRouteIndex()
{
	return m_nRouteIndex;
}

void ASuperMap_FlyManagerInstance::SetRouteStop(int nIndex)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (m_bFlyInit && pFlyManager != nullptr)
	{
		pFlyManager->SetCurrentStopIndex(nIndex);
	}
}

int ASuperMap_FlyManagerInstance::GetRouteStop()
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (m_bFlyInit && pFlyManager != nullptr && pFlyManager->GetStatus() != FlyStatus::Stop)
	{
		return pFlyManager->GetCurrentStopIndex();
	}
	return -1;
}

int ASuperMap_FlyManagerInstance::GetNumOfRouteStops()
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (m_bFlyInit && pFlyManager != nullptr)
	{
		return pFlyManager->GetRoutes()->GetRoute(m_nRouteIndex)->Count();
	}
	return -1;
}

FString ASuperMap_FlyManagerInstance::GetRouteStopName(int nIndex)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (m_bFlyInit && pFlyManager != nullptr)
	{
		return pFlyManager->GetRoutes()->GetRoute(m_nRouteIndex)->GetStop(nIndex).GetName();
	}
	return FString("");
}

void ASuperMap_FlyManagerInstance::CreateRoute(FString RouteName)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		if (pFlyManager->GetStatus() != FlyStatus::Stop)
		{
			pFlyManager->Stop();
		}
		Gamebool bSuccess = pFlyManager->GetRoutes()->Create(RouteName);
		pFlyManager->Update();
		m_bFlyInit = true;
		Routes* pRoutes = pFlyManager->GetRoutes();
		m_nRouteIndex = pRoutes->GetCurrentRouteIndex();
	}
}

void ASuperMap_FlyManagerInstance::SaveRoute(FString FileName, FString FilePath)
{
	bool bResult = false;
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		FString strPath = FilePath + TEXT("/") + FileName + TEXT(".fpf");
		pFlyManager->GetRoutes()->GetRoute(m_nRouteIndex)->SetName(FileName);
		bResult = pFlyManager->GetRoutes()->ToFile(strPath);
	}
	if (bResult)
	{
		FText message = FText::FromString(TEXT("保存成功"));
		FMessageDialog::Open(EAppMsgType::Ok, message);
	}
	else
	{
		FText message = FText::FromString(TEXT("保存失败"));
		FMessageDialog::Open(EAppMsgType::Ok, message);
	}
}

void ASuperMap_FlyManagerInstance::AddRouteStop(FString RouteStopName)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		Gameint nIndex = pFlyManager->GetRoutes()->GetCurrentRouteIndex();
		if (nIndex != -1)
		{
			FVector vCameraLocation;
			FRotator rCameraRotator;
			GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(vCameraLocation, rCameraRotator);
			bool bIsEnsure = false;
			vCameraLocation += FVector(GetWorld()->OriginLocation);

			Gameint Width = GetWorld()->GetGameViewport()->Viewport->GetSizeXY().X * 0.5;
			Gameint Height = GetWorld()->GetGameViewport()->Viewport->GetSizeXY().Y * 0.5;
			Vector3d vMiddle = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(Vector3d(Width, Height, 0.));
			vMiddle += FVector(GetWorld()->OriginLocation);

			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
				RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
			{
				vCameraLocation += MathEngine::m_vWorldOffset;
				vMiddle += MathEngine::m_vWorldOffset;
			}

			
			Vector3d v3dCameraLocation(vCameraLocation);
			
			Gamebool bIsSphere = false;
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe || 
				RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
			{
				bIsSphere = true;
				vMiddle = vMiddle.MultiplyMatrix(Georeference::GetECEFtoGeoreference().Invert());
				v3dCameraLocation = v3dCameraLocation.MultiplyMatrix(Georeference::GetECEFtoGeoreference().Invert());

			}
			vMiddle *= CM_TO_M;
			v3dCameraLocation *= CM_TO_M;
			Swap(vMiddle.X, vMiddle.Y);
			Swap(v3dCameraLocation.X, v3dCameraLocation.Y);
			Vector3d vDir = vMiddle - v3dCameraLocation;
			Gamedouble dHeading = 0;
			Gamedouble dTilt = 0;
			Gamedouble dRoll = 0;
			MathEngine::CalHeadingAndPitch(bIsSphere, v3dCameraLocation.X, v3dCameraLocation.Y, v3dCameraLocation.Z, vDir.X, vDir.Y, vDir.Z, dHeading, dTilt);
			Vector3d vPos(vCameraLocation);
			
			
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
				RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
			{
				vPos = vPos.MultiplyMatrix(Georeference::GetECEFtoGeoreference().Invert());
				vPos *= CM_TO_M;
				Swap(vPos.X, vPos.Y);
				vPos = MathEngine::CartesianToSpherical(vPos.X, vPos.Y, vPos.Z);
			}
			dTilt += 90.0;
			RouteStop* stop = new RouteStop(RouteStopName);
			CameraState* pCameraState = new CameraState();
			if (bIsEnsure)
			{
				dTilt = 0;
				dHeading = 0;
				dRoll = 0;
			}
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
			{
				vPos += RealspaceView::GetSingleton()->GetSceneControl()->GetTerrainPosition();
				vPos *= CM_TO_M;
				Swap(vPos.X, vPos.Y);
			}
			pCameraState->SetUGCameraState(vPos.X, vPos.Y, vPos.Z, dTilt, dHeading, dRoll);
			stop->SetCamera(pCameraState);
			stop->SetDuration(5);
			pFlyManager->GetRoutes()->GetRoute(nIndex)->Add(stop);
		}	
	}
}

void ASuperMap_FlyManagerInstance::DeleteRouteStop(FString RouteStopName)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{

		Gameint nIndex = pFlyManager->GetRoutes()->GetCurrentRouteIndex();
		if (nIndex != -1)
		{
			Route* pRoute = pFlyManager->GetRoutes()->GetRoute(nIndex);
			if (pRoute->Contains(RouteStopName))
			{
				pRoute->Remove(pRoute->IndexOf(RouteStopName));
				pFlyManager->Update();
			}
		}
	}
}

FRouteStopCameraInfo ASuperMap_FlyManagerInstance::GetRouteStopCameraParam(FString RouteStopName)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		Gameint nIndex = pFlyManager->GetRoutes()->GetCurrentRouteIndex();
		if (nIndex != -1)
		{
			Route* pRoute = pFlyManager->GetRoutes()->GetRoute(nIndex);
			
			RouteStop routestop = pRoute->GetStop(pRoute->IndexOf(RouteStopName));
			m_StopCameraInfo.fTilt = (float)routestop.GetCameraState()->GetUGCameraTilt();
			m_StopCameraInfo.fHeading = (float)routestop.GetCameraState()->GetUGCameraHeading();
			m_StopCameraInfo.fRoll = (float)routestop.GetCameraState()->GetUGCameraRoll();
			m_StopCameraInfo.fDuration = (float)routestop.GetDuration();
			m_StopCameraInfo.fAltitude = (float)routestop.GetCameraState()->GetUGCameraAltitude();
			m_StopCameraInfo.fLon = (float)routestop.GetCameraState()->GetUGCameraLongitude();
			m_StopCameraInfo.fLat = (float)routestop.GetCameraState()->GetUGCameraLatitude();
		}
	}
	return	m_StopCameraInfo;
}

void ASuperMap_FlyManagerInstance::SetRouteStopCameraParam(FString RouteStopName, FRouteStopCameraInfo info)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		Gameint nIndex = pFlyManager->GetRoutes()->GetCurrentRouteIndex();
		if (nIndex != -1)
		{
			Route* pRoute = pFlyManager->GetRoutes()->GetRoute(nIndex);
			RouteStop routestop = pRoute->GetStop(pRoute->IndexOf(RouteStopName));
			CameraState* pCameraState = routestop.GetCameraState();
			pCameraState->SetUGCameraState(info.fLon, info.fLat, info.fAltitude, info.fTilt, info.fHeading, 0.);
			routestop.SetCamera(pCameraState);
			routestop.SetDuration(info.fDuration);
		}
	}
}

void ASuperMap_FlyManagerInstance::FixRotationOfCamera()
{
	if (IsCurrentRouteHeadingFixed() && IsCurrentRouteTiltFixed())
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetCameraState()->SetRotationOfCameraFixed(true);
	}
	else
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetCameraState()->SetRotationOfCameraFixed(false);
	}
}

bool ASuperMap_FlyManagerInstance::IsFixedRotationOfCamera()
{
	return RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetCameraState()->IsRotationOfCameraFixed();
}

void ASuperMap_FlyManagerInstance::SetCurrentRouteHeadingFixed(bool bSet)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		Gameint nIndex = pFlyManager->GetRoutes()->GetCurrentRouteIndex();
		if (nIndex != -1)
		{
			Route* pRoute = pFlyManager->GetRoutes()->GetRoute(nIndex);
			pRoute->SetHeadingFixed(bSet);
			FixRotationOfCamera();
		}
	}
}

bool ASuperMap_FlyManagerInstance::IsCurrentRouteHeadingFixed()
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		Gameint nIndex = pFlyManager->GetRoutes()->GetCurrentRouteIndex();
		if (nIndex != -1)
		{
			Route* pRoute = pFlyManager->GetRoutes()->GetRoute(nIndex);
			return pRoute->IsHeadingFixed();
		}
	}
	return true;
}

void ASuperMap_FlyManagerInstance::SetCurrentRouteTiltFixed(bool bSet)
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		Gameint nIndex = pFlyManager->GetRoutes()->GetCurrentRouteIndex();
		if (nIndex != -1)
		{
			Route* pRoute = pFlyManager->GetRoutes()->GetRoute(nIndex);
			pRoute->SetTiltFixed(bSet);
			FixRotationOfCamera();
		}
	}
}

bool ASuperMap_FlyManagerInstance::IsCurrentRouteTiltFixed()
{
	FlyManager* pFlyManager = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetFlyManager();
	if (pFlyManager != nullptr)
	{
		Gameint nIndex = pFlyManager->GetRoutes()->GetCurrentRouteIndex();
		if (nIndex != -1)
		{
			Route* pRoute = pFlyManager->GetRoutes()->GetRoute(nIndex);
			return pRoute->IsHeadingFixed();
		}
	}
	return true;
}
PRAGMA_ENABLE_OPTIMIZATION