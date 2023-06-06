// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_SightlineInstance.h"
#include "SpatialAnalyst3D/Sightline.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;

ASuperMap_SightlineInstance::ASuperMap_SightlineInstance()
{
	m_nMouseLeftDown = 0;
	m_bMouseRightDown = false;
	m_bIsShowViewerPosition = false;
	m_bSightline = false;
	m_bEditSphere = false;
	m_bSelectSphere = false;
	m_vMouse = FVector::ZeroVector;
}

ASuperMap_SightlineInstance::~ASuperMap_SightlineInstance()
{
	ClearRefSphere();
	ClearBarriedSphere();
}

void ASuperMap_SightlineInstance::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	ClearRefSphere();
	ClearBarriedSphere();
}

void ASuperMap_SightlineInstance::SetIsSightline(bool bsightline)
{
	m_bSightline = bsightline;
	ClearRefSphere();
	ClearBarriedSphere();
	if (bsightline)
	{
		m_bIsShowViewerPosition = false;
		m_bMouseRightDown = false;
		m_nMouseLeftDown = 0;
		m_strAnalyst3DName = "Sightline";
		m_mapMouseControl[m_strAnalyst3DName] = this;
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			delete pAnalyst3D;
			mapAnalyst.erase(m_strAnalyst3DName);
		}
		Sightline* pSightline = new Sightline(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
		pSightline->Build();
		mapAnalyst[m_strAnalyst3DName] = pSightline;
		m_bEditSphere = false;
		m_bSelectSphere = false;
	}
	else if (!bsightline && m_strAnalyst3DName == "Sightline")
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
		m_bEditSphere = false;
		m_vMouse = FVector::ZeroVector;
	}
}

FString ASuperMap_SightlineInstance::GetViewerPosition()
{
	FString strPos;
	FVector vMouse;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
	Vector3d vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
	{
		strPos = FString::Printf(TEXT("X:%.2f  Y:%.2f  Z:%.2f "), vPos.X/100, vPos.Y/100, vPos.Z/100);
	}
	else
	{
		strPos = FString::Printf(TEXT("Lon:%.8f °  Lat:%.8f °"), vPos.X, vPos.Y);
	}
	return strPos;
}

bool ASuperMap_SightlineInstance::IsShowViewerPosition()
{
	bool isshow = m_bIsShowViewerPosition;
	if (m_bIsShowViewerPosition)
	{
		m_bIsShowViewerPosition = false;

	}
	return isshow;
}

Vector3d ASuperMap_SightlineInstance::TransformMousePosition(FVector vMouse)
{
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
	return vPos;
}

void ASuperMap_SightlineInstance::MouseLeftButtonDown()
{
	FVector vMouse;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
	Vector3d vPos;
	if (m_bSightline && !m_bMouseRightDown && !m_bEditSphere)
	{
		m_nMouseLeftDown++;		
		vPos = TransformMousePosition(vMouse);
		if (m_nMouseLeftDown == 1)
		{
			Sightline* pSightLine = (Sightline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
			pSightLine->SetViewerPosition(vPos.ToFVector());
			m_vViewerPosition = vPos.ToFVector();
			m_bIsShowViewerPosition = true;
			CallSightline.Broadcast();
		}
		else
		{
			Sightline* pSightLine = (Sightline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
			pSightLine->AddTargetPoint(vPos.ToFVector());
			m_bIsShowViewerPosition = false;
		}
	}
	if (m_bMouseRightDown && m_bSightline && m_bEditSphere)
	{
		if (m_bSelectSphere)
		{
			Sightline* pSightLine = (Sightline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
			vPos = TransformMousePosition(vMouse);			
			if (m_nOldIndex == 0)
			{
				m_vViewerPosition = vPos.ToFVector();
				pSightLine->SetViewerPosition(m_vViewerPosition);
				CallSightline.Broadcast();
			}
			else
			{
				pSightLine->SetTargetPoint(m_nOldIndex - 1, vPos.ToFVector());
			}
			TArray<FVector> arrBarrierPoint;
			for (Gameint i = 0; i < pSightLine->GetTargetPointCount(); i++)
			{
				Sightline::SightlineResult result = pSightLine->GetSightlineResult(i);
				if (!result.bVisibie)
				{
					if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
						RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
					{
						arrBarrierPoint.Add(MathEngine::SphericalToCartesian_GeoOrigin(result.vBarrierPoint));
					}
					else
					{
						arrBarrierPoint.Add(result.vBarrierPoint);
					}
				}
			}
			SpawnarrBarriedSphere(arrBarrierPoint);
			FVector vpos = vPos.ToFVector();
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
				RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
			{
				vpos = MathEngine::SphericalToCartesian_GeoOrigin(vpos);
			}
			m_arrRefSphereActor[m_nOldIndex]->SetActorLocation(vpos);
			m_bSelectSphere = false;
		}
		else
		{
			FHitResult hitResult;
			Gamebool bHit = false;

			FVector vLocation;
			FVector vDirection;

			if (GetWorld()->GetFirstPlayerController()->DeprojectScreenPositionToWorld(vMouse.X, vMouse.Y, vLocation, vDirection))
			{
				// 终点
				FVector vEnd = vLocation + (vDirection * 1000000000000.0);
				bHit = GetWorld()->LineTraceSingleByChannel(hitResult, vLocation, vEnd, ECC_WorldStatic);
			}
			if (bHit)
			{
				ASuperMap_SphereActor* hitActor = Cast<ASuperMap_SphereActor>(hitResult.GetActor());
				if (hitActor != nullptr)
				{
					if (hitActor->GetSphereType() == ESuperMap_Sphere::TargetPoint_SightLine || hitActor->GetSphereType() == ESuperMap_Sphere::ViewerPoint_SightLine)
					{
						ClearBarriedSphere();
						m_nOldIndex = hitActor->GetSphereIndex();
						m_bSelectSphere = true;
					}	
				}
			}
		}	
	}
}

void ASuperMap_SightlineInstance::MouseRealTimeAnchor()
{
	FVector vMouse = FVector::ZeroVector;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);

	if (vMouse == m_vMouse)
	{
		return;
	}

	m_vMouse = vMouse;
	Vector3d vPos;
	vPos = TransformMousePosition(vMouse);
	Sightline* pSightLine = (Sightline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
	if (m_bSightline && m_nMouseLeftDown > 0 && !m_bMouseRightDown)
	{
		Gameint nCount = pSightLine->GetTargetPointCount();
		if (nCount < m_nMouseLeftDown)
		{
			pSightLine->AddTargetPoint(vPos.ToFVector());
		}
		else if (nCount > 0)
		{
			pSightLine->SetTargetPoint(nCount-1,vPos.ToFVector());
		}	
	}
	if (m_bSightline && m_bMouseRightDown && m_bSelectSphere)
	{
		if (m_nOldIndex == 0)
		{
			m_vViewerPosition = vPos.ToFVector();
			pSightLine->SetViewerPosition(m_vViewerPosition);
		}
		else
		{
			pSightLine->SetTargetPoint(m_nOldIndex - 1, vPos.ToFVector());
		}
		FVector vpos = vPos.ToFVector();
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
		{
			vpos = MathEngine::SphericalToCartesian_GeoOrigin(vpos);
		}
		m_arrRefSphereActor[m_nOldIndex]->SetActorLocation(vpos);

		SpawnSphere();
	}
}

void ASuperMap_SightlineInstance::MouseRightButtonDown()
{
	if (m_bSightline && !m_bMouseRightDown)
	{
		Sightline* pSightLine = (Sightline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		Gameint nCount = pSightLine->GetTargetPointCount();
		if (nCount == m_nMouseLeftDown)
		{
			pSightLine->RemoveTargetPoint(m_nMouseLeftDown - 1);
		}
		SpawnSphere();
		m_bMouseRightDown = true;
	}
}

void ASuperMap_SightlineInstance::SpawnSphere()
{
	ClearRefSphere();
	ClearBarriedSphere();

	Sightline* pSightLine = (Sightline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
	Gameint nCount = pSightLine->GetTargetPointCount();
	// 所有目标点数组
	TArray<FVector> arrPositions;
	arrPositions.Add(m_vViewerPosition);
	for (Gameint i = 0; i < nCount; i++)
	{
		arrPositions.Add(pSightLine->GetTargetPoint(i));
	}

	// 对观察点和目标点数组进行一个坐标转化(考虑球面状况)
	TArray<FVector> arrPositionsConverted;
	for (Gameint i = 0; i < arrPositions.Num(); i++)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
		{
			arrPositionsConverted.Add(MathEngine::SphericalToCartesian_GeoOrigin(arrPositions[i]));
		}
		else
		{
			arrPositionsConverted.Add(arrPositions[i]);
		}
	}
	SpawnarrRefSphere(arrPositionsConverted);

	// 获得所有的障碍点
	TArray<FVector> arrBarrierPoint;
	for (Gameint i = 0; i < pSightLine->GetTargetPointCount(); i++)
	{
		Sightline::SightlineResult result = pSightLine->GetSightlineResult(i);
		if (!result.bVisibie)
		{
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
				RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
			{
				arrBarrierPoint.Add(MathEngine::SphericalToCartesian_GeoOrigin(result.vBarrierPoint));
			}
			else
			{
				arrBarrierPoint.Add(result.vBarrierPoint);
			}
		}
	}
	SpawnarrBarriedSphere(arrBarrierPoint);
	
	m_bEditSphere = true;
}

void ASuperMap_SightlineInstance::SpawnarrRefSphere(TArray<FVector> arrPositions)
{
	for (Gameint i = 0; i < arrPositions.Num(); i++)
	{
		ASuperMap_SphereActor* ASphere = GetWorld()->SpawnActor<ASuperMap_SphereActor>();
		ASphere->InitSphere(FRotator(0, 0, 0), arrPositions[i], FVector(3.f));
		if (i == 0)
		{
			ASphere->SetSphereType(ESuperMap_Sphere::ViewerPoint_SightLine);
		}
		else
		{
			ASphere->SetSphereType(ESuperMap_Sphere::TargetPoint_SightLine);
		}
		ASphere->SetSphereIndex(i);
		m_arrRefSphereActor.Add(ASphere);
	}
}

void ASuperMap_SightlineInstance::SpawnarrBarriedSphere(TArray<FVector> arrBarrierPoint)
{
	for (Gameint i = 0; i < arrBarrierPoint.Num(); i++)
	{
		ASuperMap_SphereActor* ASphere = GetWorld()->SpawnActor<ASuperMap_SphereActor>();
		ASphere->InitSphere(FRotator(0, 0, 0), arrBarrierPoint[i], FVector(3.f));
		ASphere->SetSphereType(ESuperMap_Sphere::BarriedPoint_SightLine);
		m_arrBarriedSphereActor.Add(ASphere);
	}
}

void ASuperMap_SightlineInstance::ClearRefSphere()
{
	for (Gameint i = 0; i < m_arrRefSphereActor.Num(); i++)
	{
		m_arrRefSphereActor[i]->Destroy(false, false);
		m_arrRefSphereActor[i]->m_pSphereMesh = nullptr;
	}
	m_arrRefSphereActor.Empty();
	
}

void ASuperMap_SightlineInstance::ClearBarriedSphere()
{
	for (Gameint i = 0; i < m_arrBarriedSphereActor.Num(); i++)
	{
		m_arrBarriedSphereActor[i]->Destroy(false, false);
		m_arrBarriedSphereActor[i]->m_pSphereMesh = nullptr;
	}
	m_arrBarriedSphereActor.Empty();
}