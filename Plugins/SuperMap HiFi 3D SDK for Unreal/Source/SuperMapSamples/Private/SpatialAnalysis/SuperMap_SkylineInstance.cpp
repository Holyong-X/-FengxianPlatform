// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_SkylineInstance.h"
#include "SpatialAnalyst3D/Skyline.h"
#include "Core/CameraState.h"
#include "GameFramework/PlayerController.h"
#include "Algorithm3D/MathEngine.h"
#include "Base3D/CommonDefine.h"
#include "Core/Georeference.h"
#include "Runtime/Engine/Public/SceneView.h"
using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;

ASuperMap_SkylineInstance::ASuperMap_SkylineInstance()
{
	m_bSkyline = false;
	m_bSkyline2D = false;
	m_dDirection = 0;
	m_dPitch = 0;
	m_dRadius = 4750.0;
	m_cColor = FColor::Red;
	m_mapLayerIds.Empty();
}

ASuperMap_SkylineInstance::~ASuperMap_SkylineInstance()
{
	m_arrPoint2Ds.Empty();
}

void ASuperMap_SkylineInstance::SetIsSkyline(bool bskyline)
{
	Gameint nLayerCount = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();
	for (TMap<Gameint, TArray<Gameint> >::TConstIterator It = m_mapLayerIds.CreateConstIterator(); It; ++It)
	{
		for (Gameint i = 0; i < nLayerCount; i++)
		{
			Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(i);
			if (pLayer3D != nullptr && pLayer3D->GetLayerID() == It->Key && pLayer3D->Type() == S3M)
			{
				pLayer3D->ReleaseSelection();
			}
		}
	}
	m_mapLayerIds.Empty();
	if (m_bSkyline != bskyline)
	{
		m_bSkyline = bskyline;
		if (m_bSkyline)
		{
			m_strAnalyst3DName = "Skyline";
			m_mapMouseControl[m_strAnalyst3DName] = this;
			std::map<FName, SuperMapSDK::UnrealEngine::Core::Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
			std::map<FName, SuperMapSDK::UnrealEngine::Core::Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
			if (itor != mapAnalyst.end())
			{
				SuperMapSDK::UnrealEngine::Core::Analyst3D* pAnalyst3D = itor->second;
				delete pAnalyst3D;
				mapAnalyst.erase(m_strAnalyst3DName);
				m_arrPoint2Ds.Empty();
			}
			SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline* pSkyline = new SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
			mapAnalyst[m_strAnalyst3DName] = pSkyline;
		}
		else if (!m_bSkyline && m_strAnalyst3DName == "Skyline")
		{
			std::map<FName, SuperMapSDK::UnrealEngine::Core::Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
			std::map<FName, SuperMapSDK::UnrealEngine::Core::Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
			if (itor != mapAnalyst.end())
			{
				SuperMapSDK::UnrealEngine::Core::Analyst3D* pAnalyst3D = itor->second;
				pAnalyst3D->Clear();
				delete pAnalyst3D;
				pAnalyst3D = NULL;
				mapAnalyst.erase(m_strAnalyst3DName);
				m_arrPoint2Ds.Empty();
			}

			std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find(m_strAnalyst3DName);
			if (itorMouseControl != m_mapMouseControl.end())
			{
				m_mapMouseControl.erase(itorMouseControl->first);
			}

			m_strAnalyst3DName = FName();
		}
	}
	Gameint nIndex = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->IndexOf(TEXT("SkylineSector_GeoModel"));
	Gamebool bSuccess = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Remove(nIndex);
	if (m_bSkyline)
	{
		BuildSkyline();
	}
}

void ASuperMap_SkylineInstance::SetSkylineColor(FColor color)
{
	m_cColor = color;
}

void ASuperMap_SkylineInstance::SetViewerPitch(float pitch)
{
	m_dPitch = pitch;
	SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline* pSkyline = (SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
	pSkyline->SetViewerPitch(m_dPitch);
}

void ASuperMap_SkylineInstance::SetViewerDirection(float direction)
{
	m_dDirection = direction;
	SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline* pSkyline = (SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
	pSkyline->SetViewerDirection(m_dDirection);
}

void ASuperMap_SkylineInstance::SetRadius(float dRadius)
{
	m_dRadius = dRadius;
	SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline* pSkyline = (SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
	pSkyline->SetRadius(m_dRadius);
}

void ASuperMap_SkylineInstance::BuildSkyline()
{
	if (!m_bSkyline)
	{
		return;
	}
	SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline* pSkyline = (SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];

	// 获取当前相机的位置
	FVector vLocation;
	FRotator rRotator;
	FVector vUELocation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(vLocation, rRotator);

	Vector3d vLocation3d(vLocation);
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
	{
		Georeference::TransformUERelativeToOriginECEF(vLocation3d, rRotator);
		vUELocation = vLocation3d.ToFVector();
		Swap(vLocation3d.X, vLocation3d.Y);
		vLocation3d = MathEngine::CartesianToSpherical(vLocation3d.X, vLocation3d.Y, vLocation3d.Z);
	}
	else
	{
		vLocation3d = Georeference::TransformUERelativeToUEAbs(vLocation3d);
		vUELocation = vLocation3d.ToFVector();
		vUELocation = vUELocation * CM_TO_M;
	}

	FVector vCameraLocationF = vUELocation;
	Swap(vCameraLocationF.X, vCameraLocationF.Y);
	FQuat qQuat = rRotator.Quaternion();
	FVector vUp = qQuat.GetUpVector();
	vUp.Normalize();
	Swap(vUp.X, vUp.Y);
	FVector vRight = qQuat.GetRightVector();
	vRight.Normalize();
	Swap(vRight.X, vRight.Y);
	FMatrix matRoationXY = FRotationMatrix::MakeFromYZ(vRight, vUp);
	rRotator = matRoationXY.Rotator();
	FViewMatrices viewMatrices;
	viewMatrices.UpdateViewMatrix(vCameraLocationF, rRotator);
	FMatrix mat = viewMatrices.GetViewMatrix();

	CameraState cameraState;
	cameraState.SetUGCameraViewMatrix(mat);

	m_dDirection = cameraState.GetUGCameraHeading();
	m_dPitch = cameraState.GetUGCameraTilt();

	pSkyline->SetViewerPosition(vLocation3d.ToFVector());
	pSkyline->SetViewerDirection(m_dDirection);
	pSkyline->SetViewerPitch(m_dPitch);
	pSkyline->SetSkylineColor(m_cColor);
	pSkyline->Build();
	GetSkyline2D();
}

void ASuperMap_SkylineInstance::GetSkyline2D()
{
	if (!m_bSkyline2D)
	{
		return;
	}
	m_arrPoint2Ds.Empty();
	SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline* pSkyline = (SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
	
	if (pSkyline != nullptr)
	{
		GeoLine* pGeoLine = pSkyline->GetSkyline2D();
		if (pGeoLine != nullptr)
		{
			pGeoLine->GetPoints(m_arrPoint2Ds);
		}
	}

	Gameint nWidth = 450;
	Gameint nHeight = 400;
	Gamedouble maxY = 0;
	Gamedouble minY = 0;
	if (m_arrPoint2Ds.Num() > 0)
	{
		m_arrPoint2Ds[0].X *= nWidth;
		m_arrPoint2Ds[0].Y *= -nHeight;
		maxY = m_arrPoint2Ds[0].Y;
		minY = maxY;
	}
	
	for (int i = 1; i < m_arrPoint2Ds.Num(); i++)
	{
		if (m_arrPoint2Ds[i].X == 0)
		{
			m_arrPoint2Ds.RemoveAt(i);
			i--;
			continue;
		}

		m_arrPoint2Ds[i].X *= nWidth;
		m_arrPoint2Ds[i].Y *= -nHeight;

		if (abs(m_arrPoint2Ds[i - 1].X - m_arrPoint2Ds[i].X) < 0.1 && abs(m_arrPoint2Ds[i - 1].Y - m_arrPoint2Ds[i].Y) < 0.1)
		{
			m_arrPoint2Ds.RemoveAt(i);
			i--;
			continue;
		}

		if (maxY < m_arrPoint2Ds[i].Y)
		{
			maxY = m_arrPoint2Ds[i].Y;
		}
		if (minY > m_arrPoint2Ds[i].Y)
		{
			minY = m_arrPoint2Ds[i].Y;
		}
	}

	if (m_arrPoint2Ds.Num() > 0)
	{
		float startY = m_arrPoint2Ds[0].Y;
		float endY = m_arrPoint2Ds[m_arrPoint2Ds.Num() - 1].Y;
		m_arrPoint2Ds.EmplaceAt(0, FVector2D(0, startY));
		m_arrPoint2Ds.Add(FVector2D(nWidth, endY));
	}

	Gamebool UseMin = ((minY + 2 * FMath::Abs(maxY)) < 0);
	for (int n = 0; n < m_arrPoint2Ds.Num(); n++)
	{
		if (!UseMin)
		{
			m_arrPoint2Ds[n].Y += 2 * FMath::Abs(maxY);
		}
		else
		{
			m_arrPoint2Ds[n].Y += FMath::Abs(minY);
		}
	}
}

void ASuperMap_SkylineInstance::SetSkylineSectorBody(float fHeight)
{
	if (!m_bSkyline)
	{
		return;
	}
	Gameint nIndex = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->IndexOf(TEXT("SkylineSector_GeoModel"));
	Gamebool bSuccess = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Remove(nIndex);

	SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline* pSkyline = (SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
	GeoModel3D* pGeoModel = pSkyline->GetSkylineSectorBody(fHeight);
	if (pGeoModel)
	{
		Style3D* pVisibleStyle = new Style3D();
		pVisibleStyle->SetFillColor(FVector4(0, 1, 0, 0.5));
		pVisibleStyle->SetAltitudeMode(AltitudeMode::Absolute);
		pGeoModel->SetStyle3D(pVisibleStyle);
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->AddGeometry(pGeoModel, TEXT("SkylineSector_GeoModel"));
	}
}

void ASuperMap_SkylineInstance::SkylineGetObjectIDs(bool isLight)
{
	if (!m_bSkyline)
	{
		return;
	}
	if (m_mapLayerIds.Num() == 0)
	{
		SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline* pSkyline = (SuperMapSDK::UnrealEngine::SpatialAnalyst3D::Skyline*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		m_mapLayerIds = pSkyline->GetObjectIDs();
	}
	Gameint nLayerCount = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();

	for (TMap<Gameint, TArray<Gameint> >::TConstIterator It = m_mapLayerIds.CreateConstIterator(); It; ++It)
	{
		for (Gameint i = 0; i < nLayerCount; i++)
		{
			Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(i);
			if (pLayer3D != nullptr && pLayer3D->GetLayerID() == It->Key && pLayer3D->Type() == S3M)
			{
				pLayer3D->ReleaseSelection();
				if (isLight)
				{
					for (int j = 0; j < It->Value.Num(); j++)
					{
						pLayer3D->AddSelectedID(It->Value[j]);
					}
					FVector4 color = FVector4(1, 0, 0, 1);
					Style3D* pStyle3D = new Style3D();
					pStyle3D->SetFillColor(color);
					pLayer3D->SetSelectStyle(pStyle3D);
				}
			}
		}
	}
}

void ASuperMap_SkylineInstance::MouseLeftButtonDown()
{

}

void ASuperMap_SkylineInstance::MouseRightButtonDown()
{
	
}

void ASuperMap_SkylineInstance::MouseRealTimeAnchor()
{

}

