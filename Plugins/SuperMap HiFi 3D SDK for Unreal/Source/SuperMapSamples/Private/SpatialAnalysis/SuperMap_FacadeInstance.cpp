// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_FacadeInstance.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/Georeference.h"
PRAGMA_DISABLE_OPTIMIZATION
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK;

// Sets default values
ASuperMap_FacadeInstance::ASuperMap_FacadeInstance()
{
	PrimaryActorTick.bCanEverTick = true;
	m_vStarPoint = Vector3d(0, 0, 0);
	m_vEndPoint = Vector3d(0, 0, 0);
	m_pROEntityActor = nullptr;
	m_pFacade = nullptr;
	m_nMouseLeftDown = 0;
	m_bFacade = false;
	m_minVisibleHeight = 0;
	m_maxVisibleHeight = 100;
}

ASuperMap_FacadeInstance::~ASuperMap_FacadeInstance()
{
	m_bFacade = false;
	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor = nullptr;
	}
}

void ASuperMap_FacadeInstance::Realse()
{
	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor->Destroy(false, false);
		m_pROEntityActor = nullptr;
	}
}

void ASuperMap_FacadeInstance::BuildFacade(bool bFacade)
{
	m_bFacade = bFacade;
	if (m_bFacade)
	{
		m_vStarPoint = Vector3d(0, 0, 0);
		m_vEndPoint = Vector3d(0, 0, 0);
		m_strAnalyst3DName = "Facade";
		m_mapMouseControl[m_strAnalyst3DName] = this;
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			delete pAnalyst3D;
			mapAnalyst.erase(m_strAnalyst3DName);
		}
		Facade* pFacade = new Facade(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
		mapAnalyst[m_strAnalyst3DName] = pFacade;
		m_nMouseLeftDown = 0;
		Realse();
		m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
	}
	else if (!m_bFacade && m_strAnalyst3DName == "Facade")
	{
		Realse();
		m_nMouseLeftDown = 0;
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

void ASuperMap_FacadeInstance::SetVisibleFarDistance(float fFar)
{
	if (m_bFacade)
	{
		Facade* pFacade = (Facade*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pFacade->SetVisibleFarDistance(fFar);
	}
}

void ASuperMap_FacadeInstance::SetResolution(float fResolution)
{
	if (m_bFacade)
	{
		Facade* pFacade = (Facade*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pFacade->SetResolution(fResolution);
	}
}

void ASuperMap_FacadeInstance::SetVisibleHeight(float fMin, float fMax)
{
	m_minVisibleHeight = fMin;
	m_maxVisibleHeight = fMax;
	if (m_bFacade)
	{
		Facade* pFacade = (Facade*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pFacade->SetVisibleHeight(fMin, fMax);
		DrawFace();
	}
}

void ASuperMap_FacadeInstance::SetOutputPath(FString strOutputPath)
{
	if (m_bFacade)
	{
		strOutputPath = strOutputPath + "/FacadeImage.tif";
		CreateFileName(strOutputPath);
		Facade* pFacade = (Facade*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pFacade->SetOutputPath(strOutputPath);
	}
}

void ASuperMap_FacadeInstance::CreateFileName(FString& strOutputPath)
{
	FString filePath = strOutputPath;
	Gameint nIndex = 0;
	FString fileName = FPaths::GetBaseFilename(filePath);
	FString fileRootpath = FPaths::GetPath(filePath);
	while(FPlatformFileManager::Get().GetPlatformFile().FileExists(*filePath))
	{
		nIndex++;
		filePath = fileRootpath + "/" + fileName + FString::Printf(TEXT("_%d.tif"), nIndex);
	}
	strOutputPath = filePath;
}

void ASuperMap_FacadeInstance::MouseLeftButtonDown()
{
	if (m_bFacade && m_nMouseLeftDown < 2)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos;
		vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		m_DrawFlatStartPoint = vPos;
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
		{
			vPos += FVector(GetWorld()->OriginLocation);
			Swap(vPos.X, vPos.Y);
			vPos *= CM_TO_M;
		}
		else
		{
			vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
		}
		m_nMouseLeftDown++;
		if (m_nMouseLeftDown == 1)
		{
			m_vStarPoint = vPos;
		}
		if (m_nMouseLeftDown == 2)
		{
			m_vEndPoint = vPos;
			Realse();
			DrawFace();
		}
	}
}

void ASuperMap_FacadeInstance::MouseRightButtonDown()
{
	if (m_bFacade)
	{
		Realse();
		m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
		m_nMouseLeftDown = 0;
		m_vStarPoint = Vector3d(0, 0, 0);
		m_vEndPoint = Vector3d(0, 0, 0);
	}
}

void ASuperMap_FacadeInstance::MouseRealTimeAnchor()
{
	if (m_bFacade && m_nMouseLeftDown == 1)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos;
		vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		DrawLine(vPos);
		m_DrawFlatEndPoint = vPos;
	}
}

void ASuperMap_FacadeInstance::CreateFacade()
{
	if (m_bFacade && m_nMouseLeftDown > 1)
	{
		TArray<Vector3d> arrPoints;
		arrPoints.Add(m_vStarPoint);
		arrPoints.Add(m_vEndPoint);
		Facade* pFacade = (Facade*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		GeoLine3D* pGeoLine3D = new GeoLine3D();
		pGeoLine3D->Make(arrPoints);
		pFacade->SetViewLine(pGeoLine3D);
		pFacade->Build();
		Realse();
		m_nMouseLeftDown = 0;
		m_bFacade = false;
	}
}

void ASuperMap_FacadeInstance::BeginPlay()
{
	Super::BeginPlay();
}

void ASuperMap_FacadeInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASuperMap_FacadeInstance::DrawLine(Vector3d vPos)
{
	m_pROEntityActor->ClearMesh();
	TArray<SM_Vertex> arrVtxs;
	TArray<Gameint> arrIndexs;
	//顶点
	SM_Vertex start;
	start.Position = m_DrawFlatStartPoint.ToFVector();
	start.Color = FColor::Yellow;
	arrVtxs.Add(start);
	SM_Vertex end;
	end.Position = vPos.ToFVector();
	end.Color = FColor::Yellow;
	arrVtxs.Add(end);
	//索引
	arrIndexs.Add(0);
	arrIndexs.Add(1);

	//mesh
	TArray<SM_SubMesh> arrSubMeshs;
	SM_SubMesh subMesh;
	if (m_pROEntityActor->GetMaterial() == nullptr)
	{
		static UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		subMesh.m_pMaterialInterface = pMat;
	}
	subMesh.IndexBuffer = arrIndexs;
	arrSubMeshs.Add(subMesh);
	m_pROEntityActor->SetDrawType(2);//0三角、2线
	m_pROEntityActor->CreateLineMeshComponent(arrVtxs, arrSubMeshs);
}

void ASuperMap_FacadeInstance::DrawFace()
{
	if (m_pROEntityActor == nullptr)
	{
		m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
	}
	m_pROEntityActor->ClearMesh();
	FVector point1, point2, point3, point4;
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
	{
		point1 = FVector(m_DrawFlatStartPoint.X, m_DrawFlatStartPoint.Y, m_minVisibleHeight);
		point2 = FVector(m_DrawFlatEndPoint.X, m_DrawFlatEndPoint.Y, m_minVisibleHeight);
		point3 = FVector(m_DrawFlatEndPoint.X, m_DrawFlatEndPoint.Y, m_maxVisibleHeight);
		point4 = FVector(m_DrawFlatStartPoint.X, m_DrawFlatStartPoint.Y, m_maxVisibleHeight);
	}
	else
	{
		Vector3d uePos1 = MathEngine::SphericalToCartesian2(m_vStarPoint.X, m_vStarPoint.Y, m_minVisibleHeight);
		point1 = Georeference::TransformOriginECEFToUEReative(uePos1).ToFVector();
		Vector3d uePos2 = MathEngine::SphericalToCartesian2(m_vEndPoint.X, m_vEndPoint.Y, m_minVisibleHeight);
		point2 = Georeference::TransformOriginECEFToUEReative(uePos2).ToFVector();
		Vector3d uePos3 = MathEngine::SphericalToCartesian2(m_vEndPoint.X, m_vEndPoint.Y, m_maxVisibleHeight);
		point3 = Georeference::TransformOriginECEFToUEReative(uePos3).ToFVector();
		Vector3d uePos4 = MathEngine::SphericalToCartesian2(m_vStarPoint.X, m_vStarPoint.Y, m_maxVisibleHeight);
		point4 = Georeference::TransformOriginECEFToUEReative(uePos4).ToFVector();
	}

	TArray<SM_Vertex> arrVtxs;
	TArray<Gameint> arrIndexs;
	//顶点
	SM_Vertex pos1;
	pos1.Position = point1;
	pos1.Color = FColor::Green;
	arrVtxs.Add(pos1);
	SM_Vertex pos2;
	pos2.Position = point2;
	pos2.Color = FColor::Green;
	arrVtxs.Add(pos2);
	SM_Vertex pos3;
	pos3.Position = point3;
	pos3.Color = FColor::Green;
	arrVtxs.Add(pos3);
	SM_Vertex pos4;
	pos4.Position = point4;
	pos4.Color = FColor::Green;
	arrVtxs.Add(pos4);
	//索引
	arrIndexs.Add(0);
	arrIndexs.Add(1);
	arrIndexs.Add(2);
	arrIndexs.Add(0);
	arrIndexs.Add(3);
	arrIndexs.Add(2);
	//mesh
	TArray<SM_SubMesh> arrSubMeshs;
	SM_SubMesh subMesh;
	if (m_pROEntityActor->GetMaterial() == nullptr)
	{
		static UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		pMat->SetScalarParameterValue(FName("Transparent"), 0.2);
		subMesh.m_pMaterialInterface = pMat;
	}
	subMesh.IndexBuffer = arrIndexs;
	arrSubMeshs.Add(subMesh);
	m_pROEntityActor->SetDrawType(0);//0三角、2线
	m_pROEntityActor->CreateProceduralMesh(arrVtxs, arrSubMeshs);
}

PRAGMA_ENABLE_OPTIMIZATION