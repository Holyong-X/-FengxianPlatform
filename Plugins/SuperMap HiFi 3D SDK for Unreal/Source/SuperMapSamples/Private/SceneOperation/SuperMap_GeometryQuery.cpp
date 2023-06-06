// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneOperation/SuperMap_GeometryQuery.h"
#include "ControlUE/RealspaceView.h"
#include "Algorithm3D/MathEngine.h"
#include "Render/DrawBox.h"
#include "Core/Georeference.h"
using namespace SuperMapSDK;

ASuperMap_GeometryQuery::ASuperMap_GeometryQuery()
{
	PrimaryActorTick.bCanEverTick = true;
	m_bGeometryQuery = false;
	m_pROEntityActor = nullptr;
	m_pGeoBox = nullptr;
	m_nMouseLeftDown = 0;
	m_dWidth = 0;
	m_dLength = 0;
	m_dHeight = 0;
}

ASuperMap_GeometryQuery::~ASuperMap_GeometryQuery()
{
	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor = nullptr;
	}
	if (m_pGeoBox != nullptr)
	{
		delete m_pGeoBox;
		m_pGeoBox = nullptr;
	}
}

void ASuperMap_GeometryQuery::Realse()
{
	if (m_pGeoBox != nullptr)
	{
		delete m_pGeoBox;
		m_pGeoBox = nullptr;
	}

	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor->Destroy(false, false);
		m_pROEntityActor = nullptr;
	}


	Gameint nLayerCount = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();
	for (Gameint nLayer = 0; nLayer < nLayerCount; nLayer++)
	{
		Gameint nLayerID = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(nLayer)->GetLayerID();
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetQuery3D()->RemoveLayerID(nLayerID);
	}
}

void ASuperMap_GeometryQuery::BuildGeometryQuery(bool bGeometryQuery)
{
	m_bGeometryQuery = bGeometryQuery;
	m_nMouseLeftDown = 0;
	
	Realse();

	if (m_bGeometryQuery)
	{
		FName strAnalyst3DName = "GeometryQuery";
		m_mapMouseControl[strAnalyst3DName] = this;
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(Pan);
	}
	else if(!m_bGeometryQuery)
	{
		FName strAnalyst3DName = "GeometryQuery";
		std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find(strAnalyst3DName);
		if (itorMouseControl != m_mapMouseControl.end())
		{
			m_mapMouseControl.erase(strAnalyst3DName);
		}
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(PanSelect);
	}
}

void ASuperMap_GeometryQuery::MouseLeftButtonDown()
{
	if (m_bGeometryQuery && m_nMouseLeftDown < 2)
	{
		m_nMouseLeftDown++;
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos,vPosDraw;

		vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		vPosDraw = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
		if (m_nMouseLeftDown == 1)
		{
			m_vStart = vPos;
			m_vStartDraw = vPosDraw;
		}
		if (m_nMouseLeftDown == 2)
		{
			m_vEnd = vPos;
			m_vEndDraw = vPosDraw;
			CalculateGeoBoxParam();
			Realse();
			m_pGeoBox = new GeoBox();
			m_pGeoBox->SetWidth(m_dWidth);
			m_pGeoBox->SetLength(m_dLength);
			m_pGeoBox->SetHeight(m_dHeight);
			m_pGeoBox->SetPosition(m_vCenter);
			//必须先添加geo
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetQuery3D()->SetQueryGeometry(m_pGeoBox);
			Gameint nLayerCount = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();
			for (Gameint nLayer = 0; nLayer < nLayerCount; nLayer++)
			{
				Gameint nLayerID = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(nLayer)->GetLayerID();
				RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetQuery3D()->AddLayerID(nLayerID);
			}
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetQuery3D()->UpdateRectSelect();
			TMap<Gameint, TArray<Gameint> > result = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetQuery3D()->GetQueryIDs();
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetQuery3D()->Realse();

			for (TMap<Gameint, TArray<Gameint> >::TConstIterator It = result.CreateConstIterator(); It; ++It)
			{
				for (Gameint i = 0; i < nLayerCount; i++)
				{
					Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(i);
					if (pLayer3D != nullptr && pLayer3D->GetLayerID() == It->Key && pLayer3D->Type() == S3M)
					{
						pLayer3D->ReleaseSelection();
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
}

void ASuperMap_GeometryQuery::MouseRightButtonDown()
{
	if (m_bGeometryQuery)
	{
		if (m_nMouseLeftDown == 1)
		{
			m_vStart = Vector3d();
			m_vStartDraw = Vector3d();
			m_vEnd = Vector3d();
			m_vEndDraw = Vector3d();
			if (m_pROEntityActor != nullptr)
			{
				m_pROEntityActor->Destroy(false, false);
				m_pROEntityActor = nullptr;
			}
			m_nMouseLeftDown = 0;
			return;
		}
		if (m_nMouseLeftDown > 1)
		{
			Gameint nLayerCount = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();

			for (Gameint i = 0; i < nLayerCount; i++)
			{
				Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(i);
				if (pLayer3D != nullptr && pLayer3D->Type() == S3M)
				{
					pLayer3D->ReleaseSelection();
				}
			}
			BuildGeometryQuery(false);
		}
	}
}

void ASuperMap_GeometryQuery::MouseRealTimeAnchor()
{
	if (m_bGeometryQuery && m_nMouseLeftDown == 1)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos;
		vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
		DrawBox(vPos);
	}
}

void ASuperMap_GeometryQuery::CalculateGeoBoxParam()
{
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
	{
		Vector3d end = m_vEnd;
		end *= CM_TO_M;
		Swap(end.X, end.Y);
		Vector3d start = m_vStart;
		start *= CM_TO_M;
		Swap(start.X, start.Y);
		m_dWidth = abs(end.X - start.X);
		m_dLength = abs(end.Y - start.Y);
		m_dHeight = abs(end.Z - start.Z);
		m_vCenter = (start + end) / 2;
		m_vCenter.Z = m_vCenter.Z - m_dHeight / 2;
	}
	else
	{
		Vector3d vEnd = m_vEnd;

		Vector3d vStartInM = Georeference::TransformUERelativeToOriginECEF(m_vStart);
		Vector3d vEndInM = Georeference::TransformUERelativeToOriginECEF(vEnd);

		Vector3d vStartInM_UGC = Georeference::TransformUEECEFToUGCECEF(vStartInM);
		Vector3d vEndInM_UGC = Georeference::TransformUEECEFToUGCECEF(vEndInM);

		vStartInM_UGC = SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::CartesianToSpherical(vStartInM_UGC.X, vStartInM_UGC.Y, vStartInM_UGC.Z);
		vEndInM_UGC = SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::CartesianToSpherical(vEndInM_UGC.X, vEndInM_UGC.Y, vEndInM_UGC.Z);
		m_vCenter = (vStartInM_UGC + vEndInM_UGC) / 2;
		m_vCenter.Z = m_vCenter.Z - abs(vEndInM_UGC.Z - vStartInM_UGC.Z) / 2;
		Vector3d	v1, v2, v3, v4, v5, v6, v7, v8;
		SuperMapSDK::UnrealEngine::Render::DrawBox::GetBoundsVector(vStartInM_UGC, vEndInM_UGC, v1, v2, v3, v4, v5, v6, v7, v8);
		m_dHeight = GetLengthFromVector(v1, v5) * CM_TO_M;
		m_dLength = GetLengthFromVector(v1, v2) * CM_TO_M;
		m_dWidth = GetLengthFromVector(v1, v3) * CM_TO_M;
	}
}

void ASuperMap_GeometryQuery::DrawBox(Vector3d vPos)
{
	Vector3d v1, v2, v3, v4, v5, v6, v7, v8;
	SuperMapSDK::UnrealEngine::Render::DrawBox::GetBoundsVector(m_vStartDraw, vPos, v1, v2, v3, v4, v5, v6, v7, v8);
	if (m_pROEntityActor == nullptr)
	{
		m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
	}
	TArray<Vector3d> arrPoints;
	arrPoints.Add(v1);
	arrPoints.Add(v2);
	arrPoints.Add(v3);
	arrPoints.Add(v4);
	arrPoints.Add(v5);
	arrPoints.Add(v6);
	arrPoints.Add(v7);
	arrPoints.Add(v8);
	TArray<SM_Vertex> arrVtxs;
	TArray<Gameint> arrIndexs;
	//顶点
	for (int i = 0; i < 8; i++)
	{
		SM_Vertex Ver;
		Ver.Position = arrPoints[i].ToFVector();
		Ver.Color = FColor::Green;
		arrVtxs.Add(Ver);
	}

	//索引
	arrIndexs.Add(0);	arrIndexs.Add(1);
	arrIndexs.Add(1);	arrIndexs.Add(3);
	arrIndexs.Add(3);	arrIndexs.Add(2);
	arrIndexs.Add(2);	arrIndexs.Add(0);

	arrIndexs.Add(0);	arrIndexs.Add(4);
	arrIndexs.Add(1);	arrIndexs.Add(5);
	arrIndexs.Add(2);	arrIndexs.Add(6);
	arrIndexs.Add(3);	arrIndexs.Add(7);

	arrIndexs.Add(4);	arrIndexs.Add(5);
	arrIndexs.Add(5);	arrIndexs.Add(7);
	arrIndexs.Add(7);	arrIndexs.Add(6);
	arrIndexs.Add(6);	arrIndexs.Add(4);

	//mesh
	TArray<SM_SubMesh> arrSubMeshs;
	SM_SubMesh subMesh;
	if (m_pROEntityActor->GetMaterial() == nullptr)
	{
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		subMesh.m_pMaterialInterface = pMat;
	}
	subMesh.IndexBuffer = arrIndexs;
	arrSubMeshs.Add(subMesh);
	m_pROEntityActor->SetDrawType(2);//0三角、2线
	m_pROEntityActor->CreateLineMeshComponent(arrVtxs, arrSubMeshs);
}

void ASuperMap_GeometryQuery::BeginPlay()
{
	Super::BeginPlay();
}

void ASuperMap_GeometryQuery::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

double ASuperMap_GeometryQuery::GetLengthFromVector(Vector3d start, Vector3d end)
{
	double length = sqrt((start.X - end.X) * (start.X - end.X) + (start.Y - end.Y) * (start.Y - end.Y) + (start.Z - end.Z) * (start.Z - end.Z));
	return length;
}
