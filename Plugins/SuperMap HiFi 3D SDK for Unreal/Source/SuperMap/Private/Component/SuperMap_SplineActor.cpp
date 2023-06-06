// Fill out your copyright notice in the Description page of Project Settings.

#include "Component/SuperMap_SplineActor.h"
#include "ControlUE/RealspaceView.h"
#include "Runtime/Engine/Private/SplineMeshSceneProxy.h"
#include "Programs/UnrealLightmass/Public/SceneExport.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "Base3D/CommonDefine.h"
#include "Core/Georeference.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/ROCacheManager.h"
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
ASuperMap_SplineActor::ASuperMap_SplineActor()
{
	PrimaryActorTick.bCanEverTick = true;
    m_pSplineStaticMesh = nullptr;
}

ASuperMap_SplineActor::~ASuperMap_SplineActor()
{
	m_pSplineMeshs.Empty();
}

Gamevoid ASuperMap_SplineActor::BeginPlay()
{
	Super::BeginPlay();
	
}

Gamevoid ASuperMap_SplineActor::Tick(Gamefloat DeltaTime)
{
	Super::Tick(DeltaTime);

}

Gamevoid ASuperMap_SplineActor::CreateSplineMesh(const TArray<TArray<Vector3d>>& pts)
{
	for (const TArray<Vector3d>& point : pts)
	{
		if (m_pSpline != nullptr)
		{
			m_pSpline->DestroyComponent();
			m_pSpline = nullptr;
		}
		m_pSpline = NewObject<USplineComponent>(this, USplineComponent::StaticClass());
		if (point.Num() == 2)
		{
			FVector FirstPos = FVector(point[0].X, point[0].Y, point[0].Z), LastPos = FVector(point[1].X, point[1].Y, point[1].Z);
			FVector Tangent = LastPos - FirstPos;
			Tangent.Normalize();
			FSplinePoint FirstSplinePoint(0, FirstPos, Tangent, Tangent, FRotator(0,0,0), FVector(1,1,1), ESplinePointType::Curve);
			FSplinePoint LastSplinePoint(1, LastPos, Tangent, Tangent, FRotator(0, 0, 0), FVector(1, 1, 1), ESplinePointType::Curve);
			TArray<FSplinePoint> splinePoints;
			splinePoints.Add(FirstSplinePoint);
			splinePoints.Add(LastSplinePoint);
			m_pSpline->AddPoints(splinePoints,false);
			CreateSplineMeshComponent(m_pSpline);
		}
		else
		{
			TArray<FSplinePoint> splinePoints;
			FVector firstTangent = (point[1] - point[0]).ToFVector();
			firstTangent.Normalize();
			FSplinePoint FirstSplinePoint(0, FVector(point[0].X, point[0].Y, point[0].Z) , firstTangent, firstTangent, FRotator(0, 0, 0), FVector(1, 1, 1), ESplinePointType::Curve);
			splinePoints.Add(FirstSplinePoint);
			for (int i = 1; i < point.Num() - 1; i++)
			{
				FVector startPos = FVector(point[i - 1].X, point[i - 1].Y, point[i - 1].Z), midPos = FVector(point[i].X, point[i].Y, point[i].Z),endPos = FVector(point[i + 1].X, point[i + 1].Y, point[i + 1].Z);
				FVector midTangent = endPos - startPos;
				midTangent.Normalize();

				FSplinePoint splinePoint(i, midPos , midTangent, midTangent, FRotator(0, 0, 0), FVector(2, 1, 1), ESplinePointType::Curve);
				splinePoints.Add(splinePoint);
			}
			FVector endTangent = (point[point.Num() - 1] - point[point.Num() - 2]).ToFVector(); 
			endTangent.Normalize();
			FSplinePoint LastSplinePoint((point.Num() - 1), FVector(point[point.Num() - 1].X, point[point.Num() - 1].Y, point[point.Num() - 1].Z), endTangent, endTangent, FRotator(0, 0, 0), FVector(1, 1, 1), ESplinePointType::Curve);
			splinePoints.Add(LastSplinePoint);
			m_pSpline->AddPoints(splinePoints, false);
			CreateSplineMeshComponent(m_pSpline);
		}
	}
	//注册组件
	RegisterAllComponents();
}

Gamevoid ASuperMap_SplineActor::CreateSplineMeshComponent(USplineComponent* pSpline)
{
	int nCount = pSpline->GetNumberOfSplinePoints();
	for (int i = 1; i< nCount; i++)
	{
		FVector StartPos, StartTangent;
		pSpline->GetLocalLocationAndTangentAtSplinePoint(i-1, StartPos, StartTangent);
		FVector EndPos, EndTangent;
		pSpline->GetLocalLocationAndTangentAtSplinePoint(i, EndPos, EndTangent);
		USplineMeshComponent* pSplineMesh = NewObject<USplineMeshComponent>(this, USplineMeshComponent::StaticClass());
		pSplineMesh->SetStaticMesh(m_pSplineStaticMesh);
		pSplineMesh->SetStartAndEnd(StartPos, StartTangent, EndPos, EndTangent);
		m_pSplineMeshs.Add(pSplineMesh);
	}
}

Gamevoid ASuperMap_SplineActor::SetSplineStaticMesh(UStaticMesh* pStaticMesh)
{
    m_pSplineStaticMesh = pStaticMesh;
}

Gamevoid ASuperMap_SplineActor::SetInitPoints(TArray<TArray<Vector3d>> pts)
{
	m_arrInitPoints = pts;
}

Gamevoid ASuperMap_SplineActor::UpdateWorldOrigin()
{
	this->UnregisterAllComponents();
	for (int mesh = 0; mesh < m_pSplineMeshs.Num(); mesh++)
	{
		m_pSplineMeshs[mesh]->DestroyComponent();
		m_pSplineMeshs[mesh] = nullptr;
	}
	m_pSplineMeshs.Empty();

	TArray<TArray<Vector3d>> arrLinesPts = m_arrInitPoints;
	for (Gameint i = 0; i < arrLinesPts.Num(); i++)
	{
		for (Gameint j = 0; j < arrLinesPts[i].Num(); j++)
		{
			Vector3d vecPt;
			if (CameraControl::m_eSceneType == UGC_PLANE)
			{
				vecPt.X = (arrLinesPts[i][j].Y - ROCacheManager::m_vPlaneOffset.Y) * M_TO_CM;
				vecPt.Y = (arrLinesPts[i][j].X - ROCacheManager::m_vPlaneOffset.X) * M_TO_CM;
				vecPt.Z = (arrLinesPts[i][j].Z - ROCacheManager::m_vPlaneOffset.Z) * M_TO_CM;
				vecPt = vecPt - Vector3d(GetWorld()->OriginLocation);
			}
			if (CameraControl::m_eSceneType == UGC_EARTH ||
				CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
			{
				arrLinesPts[i][j] = MathEngine::SphericalToCartesian2(arrLinesPts[i][j].X, arrLinesPts[i][j].Y, arrLinesPts[i][j].Z);
				vecPt = arrLinesPts[i][j] * M_TO_CM;
				vecPt.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
				vecPt = vecPt - MathEngine::m_vWorldOffset;
				vecPt = vecPt - Vector3d(GetWorld()->OriginLocation);
			}
			arrLinesPts[i][j] = vecPt.ToFVector();
		}
	}
	/*
	// 计算转角处的插入点
	TArray<TArray<Vector3d>> pts;
	for (Gameint i = 0; i < arrLinesPts.Num(); i++)
	{
		TArray<Vector3d> linePoints1;
		MathEngine::Chamfer(linePoints1, arrLinesPts[i], 5, false, 10);
		pts.Add(linePoints1);
	}
	
	TArray<TArray<Vector3d>> pts1;
	for (int pt = 0; pt < pts.Num(); pt++)
	{
		TArray<Vector3d> arrLocations;
		TArray<Vector3d> arrPoints = pts[pt];
		MathEngine::GetSubdivisionPoints2(arrPoints, arrLocations, 400);
		pts1.Add(arrLocations);
	}
	*/
	CreateSplineMesh(arrLinesPts);
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif