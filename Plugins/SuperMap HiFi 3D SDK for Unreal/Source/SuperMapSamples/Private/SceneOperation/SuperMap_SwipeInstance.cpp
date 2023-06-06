// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneOperation/SuperMap_SwipeInstance.h"
#include "Core/Layer3D.h"
#include "Core/TerrainLayer.h"
#include "Core/Layer3DS3MFile.h"
#include "Data/DataSource.h"
#include "Data/Rectangle2D.h"

// Sets default values
ASuperMap_SwipeInstance::ASuperMap_SwipeInstance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_fTop = 0.;
	m_fBottom = 1.;
	m_fLeft = 0.;
	m_fRight = 1.;
}

void ASuperMap_SwipeInstance::SetSwipe(FName strLayerName, bool bSelected)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName);
	if (pLayer3D == nullptr)
	{
		return;
	}
	if (bSelected != pLayer3D->GetSwipeEnabled())
	{
		pLayer3D->SetSwipeEnabled(bSelected);
	}
	if (bSelected)
	{
		Rectangle2D rec = Rectangle2D(m_fLeft,m_fTop,m_fRight,m_fBottom);
		pLayer3D->SetSwipeRegion(rec);
	}
}

bool ASuperMap_SwipeInstance::GetSwipeEnabled(FName strLayerName)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName);
	if (pLayer3D == nullptr)
	{
		return false;
	}
	return pLayer3D->GetSwipeEnabled();
}

void ASuperMap_SwipeInstance::SetSwipeTop(float top)
{
	m_fTop = top;
}

void ASuperMap_SwipeInstance::SetSwipeBottom(float bottom)
{
	m_fBottom = bottom;
}

void ASuperMap_SwipeInstance::SetSwipeRight(float right)
{
	m_fRight = right;
}

void ASuperMap_SwipeInstance::SetSwipeLeft(float left)
{
	m_fLeft = left;
}
