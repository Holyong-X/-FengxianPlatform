// Fill out your copyright notice in the Description page of Project Settings.

#include "SpatialAnalysis/SuperMap_CalculationTinInstance.h"
#include "Data/GeoRegion.h"
#include "Data/GeoRegion3D.h"
#include "Core/TerrainLayers.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/Georeference.h"
using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK;
ASuperMap_CalculationTinInstance::ASuperMap_CalculationTinInstance()
{
 	PrimaryActorTick.bCanEverTick = true;
	m_bCalculationTin = false;
	m_bButtonRightDown = false;
	m_nMouseLeftDown = 0;
	m_pCalculationTerrain = nullptr;
	m_pROEntityActor = nullptr;
	m_pGeoRegion3D = nullptr;
	m_fDperPixel = 1;
	m_fBaseAltitude = 0;
	m_bExcavation = false;
	m_bGetResult = false;
}

ASuperMap_CalculationTinInstance::~ASuperMap_CalculationTinInstance()
{
	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor = nullptr;
	}
	if (m_pCalculationTerrain != nullptr)
	{
		delete m_pCalculationTerrain;
		m_pCalculationTerrain = nullptr;
	}
	if (m_pModifyTerrainObject != nullptr)
	{
		delete m_pModifyTerrainObject;
		m_pModifyTerrainObject = nullptr;
	}
	m_pGeoRegion3D = nullptr;
	m_listPosition3D.Empty();
	m_listPosition.Empty();
	m_listDrawPosition.Empty();
}

void ASuperMap_CalculationTinInstance::Realse()
{
	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor->Destroy(false, false);
		m_pROEntityActor = nullptr;
	}
	if (m_pModifyTerrainObject != nullptr)
	{
		delete m_pModifyTerrainObject;
		m_pModifyTerrainObject = nullptr;
	}
	if (m_pCalculationTerrain != nullptr)
	{
		delete m_pCalculationTerrain;
		m_pCalculationTerrain = nullptr;
	}
	if (m_pGeoRegion3D != nullptr)
	{
		delete m_pGeoRegion3D;
		m_pGeoRegion3D = nullptr;
	}
	if (m_bGetResult)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetModifyTerrainSetting()->Clear();
	}
	if (m_bExcavation)
	{
		GlobalImage* pGlobalImage = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetGlobalImage();
		pGlobalImage->ClearExcavationRegion();
	}
	m_listPosition.Empty();
	m_listPosition3D.Empty();
	m_listDrawPosition.Empty();
	m_bButtonRightDown = false;
	m_nMouseLeftDown = 0;
	m_bExcavation = false;
	m_bGetResult = false;
}

void ASuperMap_CalculationTinInstance::BuildCalculationTin(bool bCalculationTin)
{
	m_bCalculationTin = bCalculationTin;
	Realse();
	if (m_bCalculationTin)
	{
		if (m_pCalculationTerrain == nullptr)
		{
			m_pCalculationTerrain = new CalculationTerrain();
		}
		FName strInstanceName = "CalculationTin";
		m_mapMouseControl[strInstanceName] = this;
		m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
		//m_pModifyTerrainObject = new ModifyTerrainObject();
	}
	else
	{
		std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find("Flatten");
		if (itorMouseControl != m_mapMouseControl.end())
		{
			m_mapMouseControl.erase(itorMouseControl->first);
		}
	}
}

bool ASuperMap_CalculationTinInstance::CalculateResult()
{
	if (m_bCalculationTin && m_bButtonRightDown && m_pCalculationTerrain != nullptr && !m_bGetResult)
	{
		m_bGetResult = true;
		GeoRegion* pGeoRegion = new GeoRegion();
		pGeoRegion->SetPoints(m_listPosition);

		m_pGeoRegion3D = new GeoRegion3D();
		m_pGeoRegion3D->SetPoints(m_listPosition3D);
		//高程 为面平均高度+附加高度
		Gamedouble height = m_pGeoRegion3D->GetInnerPoint3D().Z;
		Gamedouble realHeight = height + m_fBaseAltitude;

		ModifyTerrainSetting* pModifyTerrainSetting = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetModifyTerrainSetting();
		if (m_pModifyTerrainObject == nullptr)
		{
			m_pModifyTerrainObject = new ModifyTerrainObject();
		}
		m_pModifyTerrainObject->SetRegion(m_pGeoRegion3D);
		m_pModifyTerrainObject->SetHeight(m_fBaseAltitude);
		pModifyTerrainSetting->Add(m_pModifyTerrainObject, TEXT("ModifyTerrainObject"));
		Gamebool result = m_pCalculationTerrain->CutFill(pGeoRegion, m_fDperPixel, realHeight);
		Excavation(m_pGeoRegion3D);
		DrawSideFace();
		delete pGeoRegion;
		pGeoRegion = nullptr;
		return result;
	}
	return false;
}

float ASuperMap_CalculationTinInstance::GetFillVolume()
{
	if (m_bCalculationTin && m_pCalculationTerrain != nullptr)
	{
		float fFillVolume = m_pCalculationTerrain->GetFillVolume();
		return fFillVolume;
	}
	return 0;
}

float ASuperMap_CalculationTinInstance::GetCutVolume()
{
	if (m_bCalculationTin && m_pCalculationTerrain != nullptr)
	{
		float fCutVolume = m_pCalculationTerrain->GetCutVolume();
		return fCutVolume;
	}
	return 0;
}

float ASuperMap_CalculationTinInstance::GetFillArea()
{
	if (m_bCalculationTin && m_pCalculationTerrain != nullptr)
	{
		float fFillArea = m_pCalculationTerrain->GetFillArea();
		return fFillArea;
	}
	return 0;
}

float ASuperMap_CalculationTinInstance::GetCutArea()
{
	if (m_bCalculationTin && m_pCalculationTerrain != nullptr)
	{
		float fCutArea = m_pCalculationTerrain->GetCutArea();
		return fCutArea;
	}
	return 0;
}

float ASuperMap_CalculationTinInstance::GetNoChangeArea()
{
	if (m_bCalculationTin && m_pCalculationTerrain != nullptr)
	{
		float fNoChangeArea = m_pCalculationTerrain->GetNoChangeArea();
		return fNoChangeArea;
	}
	return 0;
}

void ASuperMap_CalculationTinInstance::SetDperPixel(float fDperPixel)
{
	m_fDperPixel = fDperPixel;
}

void ASuperMap_CalculationTinInstance::SetBaseAltitude(float fBaseAltitude)
{
	m_fBaseAltitude = fBaseAltitude;
}

void ASuperMap_CalculationTinInstance::MouseLeftButtonDown()
{
	if (m_bCalculationTin && !m_bButtonRightDown)
	{
		m_nMouseLeftDown++;
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos, vDrawPos;
		vDrawPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
		{
			vPos = vDrawPos + FVector(GetWorld()->OriginLocation);
			vPos = vPos.ToUGCVector();
		}
		else
		{
			vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
		}
		if (m_listDrawPosition.Num() > 0)
		{
			m_listDrawPosition.RemoveAt(m_listDrawPosition.Num() - 1);
		}
		m_listPosition.Add(Vector2d(vPos.X, vPos.Y));
		m_listPosition3D.Add(vPos);
		m_listDrawPosition.Add(vDrawPos.ToFVector());
	}
}

void ASuperMap_CalculationTinInstance::MouseRightButtonDown()
{
	if (m_nMouseLeftDown < 3)
	{
		m_listPosition.Empty();
		m_listPosition3D.Empty();
		m_listDrawPosition.Empty();
		if (m_pROEntityActor != nullptr)
		{
			m_pROEntityActor->Destroy(false, false);
			m_pROEntityActor = nullptr;
		}
		m_bCalculationTin = false;
		return;
	}
	m_listDrawPosition.RemoveAt(m_listDrawPosition.Num() - 1);
	DrawFace();
	m_bButtonRightDown = true;
}

void ASuperMap_CalculationTinInstance::MouseRealTimeAnchor()
{
	if (m_bCalculationTin && !m_bButtonRightDown && m_nMouseLeftDown > 0)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos, vDrawPos;
		vDrawPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		if (m_listDrawPosition.Num() <= m_nMouseLeftDown)
		{
			m_listDrawPosition.Add(vDrawPos.ToFVector());
		}
		if (m_listDrawPosition.Num() > 0)
		{
			m_listDrawPosition[m_listDrawPosition.Num() - 1] = vDrawPos.ToFVector();
		}
		DrawFace();
	}
}

void ASuperMap_CalculationTinInstance::DrawFace()
{
	if (m_pROEntityActor == nullptr)
	{
		return;
	}
	TArray<SM_Vertex> arrVtxs;//顶点
	for (Gameint i = 0; i < m_listDrawPosition.Num(); i++)
	{
		SM_Vertex point;
		point.Position = m_listDrawPosition[i];
		point.Color = FColor::Yellow;
		arrVtxs.Add(point);
	}

	TArray<SM_SubMesh> arrSubMeshs;//mesh
	SM_SubMesh subMesh;

	if (m_pROEntityActor->GetMaterial() == nullptr)
	{
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		subMesh.m_pMaterialInterface = pMat;
	}

	TArray<Gameint> arrIndexs;//索引

	for (Gameint j = 0; j < m_listDrawPosition.Num() - 1; j++)
	{
		arrIndexs.Add(j);
		arrIndexs.Add(j + 1);
	}
	arrIndexs.Add(m_listDrawPosition.Num() - 1);
	arrIndexs.Add(0);

	subMesh.IndexBuffer = arrIndexs;
	arrSubMeshs.Add(subMesh);

	m_pROEntityActor->SetDrawType(2);//0三角、2线
	m_pROEntityActor->CreateLineMeshComponent(arrVtxs, arrSubMeshs);
}

void ASuperMap_CalculationTinInstance::Excavation(GeoRegion3D* PGeoRegion3D)
{
	FString strTag = TEXT("CalculationExcavation");
	GlobalImage* pGlobalImage = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetGlobalImage();
	pGlobalImage->AddExcavationRegion(PGeoRegion3D, strTag);
	m_bExcavation = true;
}

void ASuperMap_CalculationTinInstance::DrawSideFace()
{
	int num = 15;
	double height = m_fBaseAltitude;
	TArray<Vector3d> arrLocations;
	TArray<Vector3d> arrRegionPos;
	TArray<Gameint> arrIndex;
	TArray<Vector3d> listPosition = m_listPosition3D;
	listPosition.Add(m_listPosition3D[0]);
	for (int i = 0; i < listPosition.Num() - 1; i++)
	{
		Vector3d unit = (listPosition[i + 1] - listPosition[i]) / num;

		for (int j = 0; j < num; j++)
		{
			Vector3d pos = listPosition[i] + Vector3d(unit.X * j, unit.Y * j, unit.Z * j);

			arrLocations.Add(pos);
			arrLocations.Add(pos);
			arrRegionPos.Add(pos);
		}
	}
	arrLocations.Add(listPosition[0]);
	arrLocations.Add(listPosition[0]);
	arrRegionPos.Add(listPosition[0]);
	for (int max = 0; max < arrLocations.Num(); max++)
	{
		double dZ = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0)->GetHeight(arrLocations[max]);
		arrLocations[max].Z = dZ;
	}
	for (int nPosCount = 0; nPosCount < arrLocations.Num(); nPosCount++)
	{
		if (nPosCount % 2 != 0)
		{
			arrLocations[nPosCount].Z = arrRegionPos[nPosCount / 2].Z + height;
		}
		else if (nPosCount % 2 == 0 && nPosCount < arrLocations.Num() - 3)
		{
			arrIndex.Add(nPosCount);
			arrIndex.Add(nPosCount + 1);
			arrIndex.Add(nPosCount + 2);
			arrIndex.Add(nPosCount + 3);
			arrIndex.Add(nPosCount + 2);
			arrIndex.Add(nPosCount + 1);
		}
	}

	//绘制 侧面====================================================================================
	if (m_pROEntityActor == nullptr)
	{
		return;
	}
	TArray<SM_Vertex> arrVtxs;//顶点
	for (Gameint i = 0; i < arrLocations.Num(); i++)
	{
		SM_Vertex point;
		//顶点
		Vector3d ppos = MathEngine::SphericalToCartesian2(arrLocations[i].X, arrLocations[i].Y, arrLocations[i].Z);
		ppos *= M_TO_CM;
		ppos.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
		ppos -= (Vector3d(GetWorld()->OriginLocation) + MathEngine::m_vWorldOffset);

		point.Position = ppos.ToFVector();
		point.Color = FColor::Yellow;
		arrVtxs.Add(point);
	}
	TArray<SM_SubMesh> arrSubMeshs;//mesh
	SM_SubMesh subMesh;

	if (m_pROEntityActor->GetMaterial() == nullptr)
	{
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_SPHERERENDER_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		pMat->AddToRoot();
		subMesh.m_pMaterialInterface = pMat;
	}
	subMesh.IndexBuffer = arrIndex;
	arrSubMeshs.Add(subMesh);
	m_pROEntityActor->SetDrawType(0);//0三角、2线
	m_pROEntityActor->CreateProceduralMesh(arrVtxs, arrSubMeshs);
}

Vector3d ASuperMap_CalculationTinInstance::GetNormalVectior(Vector3d v1, Vector3d v2, Vector3d v3)
{
	Vector3d normal;

	double x1 = v2.X - v1.X;	double x2 = v3.X - v1.X;
	double y1 = v2.Y - v1.Y;	double y2 = v3.Y - v1.Y;
	double z1 = v2.Z - v1.Z;	double z2 = v3.Z - v1.Z;

	double a = y1 * z2 - y2 * z1;
	double b = z1 * x2 - z2 * x1;
	double c = x1 * y2 - x2 * y1;

	if (c < 0)
	{
		a = -a;
		b = -b;
		c = -c;
	}
	normal = Vector3d(a, b, c);
	normal.Normalize();
	return normal;
}

void ASuperMap_CalculationTinInstance::BeginPlay()
{
	Super::BeginPlay();
}

void ASuperMap_CalculationTinInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

