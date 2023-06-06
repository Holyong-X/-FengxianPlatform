
#include "SpatialAnalysis/SuperMap_ViewDomeInstance.h"
#include "SpatialAnalyst3D/ViewDome.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;

ASuperMap_ViewDomeInstance::ASuperMap_ViewDomeInstance()
{
	m_bViewDome = false;
	m_nDomeType = 0;
	m_nDisplayStyle = 0;
	m_fDistance = 150;
	m_nMouseLeftDown = 0;
	m_vColor = FVector4(0.661178, 1., 0.745884, 1.);
}

ASuperMap_ViewDomeInstance::~ASuperMap_ViewDomeInstance()
{
}

void ASuperMap_ViewDomeInstance::BuildViewDome(bool bViewDome)
{
	m_bViewDome = bViewDome;
	m_nMouseLeftDown = 0;
	if (bViewDome)
	{
		m_strAnalyst3DName = "ViewDome";
		m_mapMouseControl[m_strAnalyst3DName] = this;
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			delete pAnalyst3D;
			mapAnalyst.erase(m_strAnalyst3DName);
		}
		ViewDome* pViewDome = new ViewDome(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
		mapAnalyst[m_strAnalyst3DName] = pViewDome;
	}
	else if (!bViewDome && m_strAnalyst3DName == "ViewDome")
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
	}
}

void ASuperMap_ViewDomeInstance::SetViewDomeDisplayStyle(int type)
{
	m_nDisplayStyle = type;
	if (m_bViewDome)
	{
		ViewDome* pViewDome = (ViewDome*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pViewDome->SetViewDomeDisplayStyle((ViewDome::DisplayMode)m_nDisplayStyle);
		pViewDome->Build();
	}
}

int ASuperMap_ViewDomeInstance::GetViewDomeDisplayStyle()
{
	return m_nDisplayStyle;
}

void ASuperMap_ViewDomeInstance::SetViewDomeType(int type)
{
	m_nDomeType = type;
	if (m_bViewDome)
	{
		ViewDome* pViewDome = (ViewDome*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pViewDome->SetDomeType((ViewDome::DomeType)m_nDomeType);
		pViewDome->Build();
	}
}

int ASuperMap_ViewDomeInstance::GetViewDomeType()
{
	return m_nDomeType;
}

void ASuperMap_ViewDomeInstance::SetViewDomeDistance(float fDistance)
{
	m_fDistance = fDistance;
	if (m_bViewDome)
	{
		ViewDome* pViewDome = (ViewDome*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pViewDome->SetViewDomeDistance(m_fDistance);
		pViewDome->Build();
	}
}

float ASuperMap_ViewDomeInstance::GetViewDomeDistance()
{
	return m_fDistance;
}

void ASuperMap_ViewDomeInstance::SetViewerPosition(FVector pos)
{
	if (m_bViewDome)
	{
		ViewDome* pViewDome = (ViewDome*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pViewDome->SetViewerPosition(pos);
		pViewDome->Build();
	}
}

FVector ASuperMap_ViewDomeInstance::GetViewerPosition()
{
	if (m_bViewDome)
	{
		ViewDome* pViewDome = (ViewDome*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		return pViewDome->GetViewerPosition();
	}
	return FVector::ZeroVector;
}

void ASuperMap_ViewDomeInstance::MouseLeftButtonDown()
{
	if (m_bViewDome && m_nMouseLeftDown == 0)
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
		ViewDome* pViewDome = (ViewDome*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pViewDome->SetDomeType((ViewDome::DomeType)m_nDomeType);
		pViewDome->SetViewerPosition(vPos.ToFVector());
		pViewDome->SetViewDomeDisplayStyle((ViewDome::DisplayMode)m_nDisplayStyle);
		pViewDome->SetViewDomeDistance(m_fDistance);
		pViewDome->Build();
		m_nMouseLeftDown++;
		EventViewDemo.Broadcast();
	}
}

void ASuperMap_ViewDomeInstance::MouseRightButtonDown()
{

}

void ASuperMap_ViewDomeInstance::MouseRealTimeAnchor()
{

}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif