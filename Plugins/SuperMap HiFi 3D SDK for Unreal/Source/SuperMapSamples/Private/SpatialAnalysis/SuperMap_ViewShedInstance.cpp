// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_ViewShedInstance.h"
#include "SpatialAnalyst3D/ViewShed.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;

ASuperMap_ViewShedInstance::ASuperMap_ViewShedInstance()
{
	m_bViewShed = false;
	m_bIsShowViewerPosition = false;
	m_nMouseLeftDown = 0;
	m_pGeoLine3D = nullptr;
	m_pVisibleGeoModel = nullptr;
	m_pHiddenGeoModel = nullptr;
}

ASuperMap_ViewShedInstance::~ASuperMap_ViewShedInstance()
{
	if (m_pGeoLine3D != nullptr)
	{
		m_pGeoLine3D->~GeoLine3D();
	}
	if (m_pVisibleGeoModel != nullptr)
	{
		m_pVisibleGeoModel->~GeoModel3D();
	}
	if (m_pHiddenGeoModel != nullptr)
	{
		m_pHiddenGeoModel->~GeoModel3D();
	}
}

void ASuperMap_ViewShedInstance::SetIsViewShed(bool bViewShed)
{
	m_bViewShed = bViewShed;
	if (m_pGeoLine3D != nullptr)
	{
		m_pGeoLine3D->~GeoLine3D();
	}
	if (m_pVisibleGeoModel)
	{
		m_pVisibleGeoModel->~GeoModel3D();
	}
	if (m_pHiddenGeoModel != nullptr)
	{
		m_pHiddenGeoModel->~GeoModel3D();
	}
	if (bViewShed)
	{
		m_nMouseLeftDown = 0;
		m_strAnalyst3DName = "ViewShed";
		m_mapMouseControl[m_strAnalyst3DName] = this;
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			delete pAnalyst3D;
			pAnalyst3D = nullptr;
			mapAnalyst.erase(m_strAnalyst3DName);
		}
		ViewShed* pViewShed = new ViewShed(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
		mapAnalyst[m_strAnalyst3DName] = pViewShed;
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(Null);
	}
	else if(!bViewShed && m_strAnalyst3DName == "ViewShed")
	{
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			pAnalyst3D->Clear();
			delete pAnalyst3D;
			pAnalyst3D = NULL;
			mapAnalyst.erase(m_strAnalyst3DName);
		}

		std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find(m_strAnalyst3DName);
		if (itorMouseControl != m_mapMouseControl.end())
		{
			m_mapMouseControl.erase(itorMouseControl->first);
		}

		m_strAnalyst3DName = FName();
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Clear();
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(PanSelect);
	}
}

void ASuperMap_ViewShedInstance::MouseLeftButtonDown()
{
	if (m_bViewShed)
	{
		m_nMouseLeftDown++;
		if (m_nMouseLeftDown == 1)
		{
			FVector vMouse;
			GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
			Vector3d vPos;
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
			{
				vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
				vPos += FVector(GetWorld()->OriginLocation);
				vPos.Z += 150;
			}
			else
			{
				vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
				vPos.Z += 1.5;
			}
			ViewShed* pViewShed = (ViewShed*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
			pViewShed->SetViewerPosition(vPos.ToFVector());
			pViewShed->Build();
			pViewShed->SetVerticalFov(90.0);
			m_bIsShowViewerPosition = true;
			CallViewShed.Broadcast();
		}
	}
}

void ASuperMap_ViewShedInstance::MouseRealTimeAnchor()
{
	if (m_nMouseLeftDown == 1)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos;
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
		{
			vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
			vPos += FVector(GetWorld()->OriginLocation);
		}
		else
		{
			vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
		}
		
		ViewShed* pViewShed = (ViewShed*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pViewShed->SetDistDirByPoint(vPos.ToFVector());
	}
}

void ASuperMap_ViewShedInstance::MouseRightButtonDown()
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(PanSelect);
}

FString ASuperMap_ViewShedInstance::GetViewerPosition()
{
	FString strPos;
	FVector vMouse;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
	Vector3d vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
	{
		strPos = FString::Printf(TEXT("X:%.2f  Y:%.2f  Z:%.2f "), vPos.X / 100, vPos.Y / 100, vPos.Z / 100);
	}
	else
	{
		strPos = FString::Printf(TEXT("Lon:%f °  Lat:%f °"), vPos.X, vPos.Y);
	}
	return strPos;
}

bool ASuperMap_ViewShedInstance::IsShowViewerPosition()
{
	bool isshow = m_bIsShowViewerPosition;
	if (m_bIsShowViewerPosition)
	{
		m_bIsShowViewerPosition = false;

	}
	return isshow;
}

void ASuperMap_ViewShedInstance::SetViewShedVisibleBody(bool bVisible)
{
	if (m_bViewShed)
	{
		Gameint nIndex = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->IndexOf(TEXT("ViewShed_VisibleGeoModel"));
		Gamebool bSuccess = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Remove(nIndex);
		if (bVisible)
		{
			ViewShed* pViewShed = (ViewShed*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
			m_pVisibleGeoModel = pViewShed->GetViewShedVisibleBody();
			if (m_pVisibleGeoModel)
			{
				Style3D* pVisibleStyle = new Style3D();
				pVisibleStyle->SetFillColor(FVector4(0, 1, 0, 1));
				pVisibleStyle->SetAltitudeMode(AltitudeMode::Absolute);
				m_pVisibleGeoModel->SetStyle3D(pVisibleStyle);
			}
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->AddGeometry(m_pVisibleGeoModel, TEXT("ViewShed_VisibleGeoModel"));
		}
	}
}

void ASuperMap_ViewShedInstance::SetViewShedHiddenBody(bool bVisible)
{
	if (m_bViewShed)
	{
		Gameint nIndex = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->IndexOf(TEXT("ViewShed_HiddenGeoModel"));
		Gamebool bSuccess = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Remove(nIndex);
		if (bVisible)
		{
			ViewShed* pViewShed = (ViewShed*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
			m_pHiddenGeoModel = pViewShed->GetViewShedHiddenBody();
			if (m_pHiddenGeoModel)
			{
				Style3D* pHiddenStyle = new Style3D();
				pHiddenStyle->SetFillColor(FVector4(1, 0, 0, 1));
				pHiddenStyle->SetAltitudeMode(AltitudeMode::Absolute);
				m_pHiddenGeoModel->SetStyle3D(pHiddenStyle);
			}
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->AddGeometry(m_pHiddenGeoModel, TEXT("ViewShed_HiddenGeoModel"));
		}	
	}
}

void ASuperMap_ViewShedInstance::SetViewShedGeoLine(bool bVisible)
{
	if (m_bViewShed)
	{
		Gameint nIndex = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->IndexOf(TEXT("ViewShed_GeoLine3D"));
		Gamebool bSuccess = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Remove(nIndex);
		if (bVisible)
		{
			ViewShed* pViewShed = (ViewShed*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];

			Vector3d vViewerPos = Vector3d(pViewShed->GetViewerPosition());
			TArray<Vector3d> arrPoint = pViewShed->GetBarrierPoints();
			m_pGeoLine3D = new GeoLine3D();
			TArray<Vector3d> arrPos;
			for (Gameint i = 0; i < arrPoint.Num(); i++)
			{
				m_pGeoLine3D->AddPart(vViewerPos, arrPoint[i]);
			}
			Style3D* pLineStyle = new Style3D();
			pLineStyle->SetLineColor3D(FColor::Green);
			pLineStyle->SetAltitudeMode(AltitudeMode::Absolute);
			m_pGeoLine3D->SetStyle3D(pLineStyle);
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->AddGeometry(m_pGeoLine3D, TEXT("ViewShed_GeoLine3D"));
		}
	}
}