// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneOperation/SuperMap_FlyPositionInstance.h"

ASuperMap_FlyPositionInstance::ASuperMap_FlyPositionInstance()
{
	m_pCameraState = nullptr;
	m_nFlyTime = 0;
}

ASuperMap_FlyPositionInstance::~ASuperMap_FlyPositionInstance()
{
	DestroyFlyPosition();
}

void ASuperMap_FlyPositionInstance::DestroyFlyPosition()
{
	if (m_pCameraState)
	{
		delete m_pCameraState;
		m_pCameraState = nullptr;
	}
}

void ASuperMap_FlyPositionInstance::LaunchFlyPosition()
{
	if (m_pCameraState)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->Fly(m_pCameraState, m_nFlyTime);
		delete m_pCameraState;
		m_pCameraState = nullptr;
	}
}

void ASuperMap_FlyPositionInstance::SetFlyTime(float dDuration)
{
	m_nFlyTime = (int)(dDuration);
}

void ASuperMap_FlyPositionInstance::SetFlyPositionParams(float fLongitude, float fLatitude, float fAltitude,
	float fPitch, float fHeading, float fRoll)
{
	if (m_pCameraState == nullptr)
	{
		m_pCameraState = new CameraState();
	}
	m_pCameraState->SetUGCameraState((double)fLongitude, (double)fLatitude, (double)fAltitude, (double)fPitch, (double)fHeading, (double)fRoll);
}

void ASuperMap_FlyPositionInstance::SetFlyPositionParamsFromCamera(FVector vCameraLocation, FRotator vCameraRotator)
{
	if (m_pCameraState == nullptr)
	{
		m_pCameraState = new CameraState();
	}
	m_pCameraState->SetUGCameraState(vCameraLocation, vCameraRotator);
}
