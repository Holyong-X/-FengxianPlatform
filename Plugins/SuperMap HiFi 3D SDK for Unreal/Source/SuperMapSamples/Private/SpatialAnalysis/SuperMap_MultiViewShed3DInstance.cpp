// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_MultiViewShed3DInstance.h"

ASuperMap_MultiViewShed3DInstance::ASuperMap_MultiViewShed3DInstance()
{
 	PrimaryActorTick.bCanEverTick = true;
	m_bMultiViewShed3D = false;
	m_pMultiViewShed3D = nullptr;
	m_pViewShed = nullptr;
	m_nMouseLeftDown = 0;
}

ASuperMap_MultiViewShed3DInstance::~ASuperMap_MultiViewShed3DInstance()
{

	m_pMultiViewShed3D = nullptr;
	m_pViewShed = nullptr;
}

void ASuperMap_MultiViewShed3DInstance::Release()
{
	if (m_pMultiViewShed3D != nullptr)
	{
		m_pMultiViewShed3D = nullptr;
	}
	m_mapViewShed.Empty();
	m_pViewShed = nullptr;
	m_nMouseLeftDown = 0;
	RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(PanSelect);
}

void ASuperMap_MultiViewShed3DInstance::BuildMultiViewShed3D(bool bMultiViewShed3D)
{
	m_bMultiViewShed3D = bMultiViewShed3D;
	FName strAnalyst3DName = "MultiViewShed3D";
	Release();
	if (m_bMultiViewShed3D)
	{
		m_mapMouseControl[strAnalyst3DName] = this;
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			pAnalyst3D->Clear();
			delete pAnalyst3D;
			mapAnalyst.erase(strAnalyst3DName);
		}
		m_pMultiViewShed3D = new MultiViewShed3D(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
		mapAnalyst[strAnalyst3DName] = m_pMultiViewShed3D;
		m_pMultiViewShed3D->Build();
	}
	else
	{
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			pAnalyst3D->Clear();
			delete pAnalyst3D;
			pAnalyst3D = NULL;
			mapAnalyst.erase(strAnalyst3DName);
		}
		m_pMultiViewShed3D = NULL;
		std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find(strAnalyst3DName);
		if (itorMouseControl != m_mapMouseControl.end())
		{
			m_mapMouseControl.erase(itorMouseControl->first);
		}
	}
}

void ASuperMap_MultiViewShed3DInstance::AddViewShed3D(FString viewshedName)
{
	if (m_mapViewShed.Find(viewshedName))
	{
		return;
	}
	if (m_bMultiViewShed3D && m_pMultiViewShed3D != nullptr)
	{
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		m_pViewShed = new ViewShed(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
		mapAnalyst["ViewShed"] = m_pViewShed;
		m_pViewShed->SetName(viewshedName);
		m_nMouseLeftDown = 0;
		m_mapViewShed.Add(viewshedName, m_pViewShed);
		//RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(Null);
	}
}

void ASuperMap_MultiViewShed3DInstance::RemoveViewShed3D(FString viewshedName)
{
	if (m_bMultiViewShed3D && m_pMultiViewShed3D != nullptr && m_mapViewShed.Find(viewshedName))
	{
		m_pMultiViewShed3D->RemoveViewShed(m_mapViewShed[viewshedName]);
		m_mapViewShed.Remove(viewshedName);
	}
}

void ASuperMap_MultiViewShed3DInstance::MouseLeftButtonDown()
{
	if (m_nMouseLeftDown == 0 && m_bMultiViewShed3D && m_pMultiViewShed3D != nullptr)
	{
		ExecuteBroadcast();
	}

	if (m_bMultiViewShed3D && m_pMultiViewShed3D != nullptr && m_pViewShed != nullptr)
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
			m_pViewShed->SetViewerPosition(vPos.ToFVector());
			m_pViewShed->Build();
		}
		if (m_nMouseLeftDown == 2)
		{
			m_pMultiViewShed3D->AddViewShed(m_pViewShed);
			m_pViewShed->Clear();
			std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
			mapAnalyst.erase("ViewShed");
			m_pViewShed = nullptr;
			m_nMouseLeftDown = 0;
		}
	}
}

void ASuperMap_MultiViewShed3DInstance::MouseRightButtonDown()
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(PanSelect);
	if (m_pViewShed != nullptr)
	{
		m_pViewShed->Clear();
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		mapAnalyst.erase("ViewShed");
		m_pViewShed = nullptr;
	}
	m_nMouseLeftDown = 3;
}

void ASuperMap_MultiViewShed3DInstance::MouseRealTimeAnchor()
{
	if (m_bMultiViewShed3D && m_pMultiViewShed3D != nullptr && m_pViewShed != nullptr && m_nMouseLeftDown == 1)
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
		m_pViewShed->SetDistDirByPoint(vPos.ToFVector());
		//m_pMultiViewShed3D->AddViewShed(m_pViewShed, true);
	}
}

void ASuperMap_MultiViewShed3DInstance::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASuperMap_MultiViewShed3DInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASuperMap_MultiViewShed3DInstance::ExecuteBroadcast()
{
	if (CallAddViewShed3D.IsBound())
	{
		CallAddViewShed3D.Broadcast();
	}
}