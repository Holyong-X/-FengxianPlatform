// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_ClipBoxInstance.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Algorithm3D/MathEngine.h"
#include "Base3D/CommonDefine.h"
#include "ControlUE/RealspaceView.h"
#include "Core/TrackingLayer.h"
#include "Core/Georeference.h"

using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::ControlUE;
ASuperMap_ClipBoxInstance::ASuperMap_ClipBoxInstance()
{
	PrimaryActorTick.bCanEverTick = true;
	m_nMouseLeftDown   = 0;
	m_bClip            = false;
	m_bUseWebUI = false;
	m_pLayer3DS3MFile = nullptr;
	m_eBoxClipMode   = ClipNothing;
	m_nClipBoxMode = 0;
	m_vStart = Vector3d(0,0,0);
	m_vEnd = Vector3d(0,0,0);
	m_vCenter = Vector3d(0,0,0);
	m_dWidth = 0;
	m_dLength = 0;
	m_dHeight = 0;
	m_bUpdateClipValue = false;
	m_bDrawBox = false;
	m_bEndDraw = false;
}

ASuperMap_ClipBoxInstance::~ASuperMap_ClipBoxInstance()
{
	m_bClip = false;
	m_pLayer3DS3MFile = nullptr;
	if (m_pGeoBox != nullptr)
	{
		delete m_pGeoBox;
		m_pGeoBox = nullptr;
	}
	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor = nullptr;
	}
	if (m_pROEntityActor_Face != nullptr)
	{
		m_pROEntityActor_Face = nullptr;
	}
	m_vPosition.Empty();
}

void ASuperMap_ClipBoxInstance::SetIsClip(bool bclip)
{
	m_bClip = bclip;
	m_bEndDraw = false;
	Gameint index = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->IndexOf(FString("Clipbox"));
	if (index != -1)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Remove(index);
	}
	if (m_bClip)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(Pan);
		FName strAnalyst3DName = "SceneClip";
		m_mapMouseControl[strAnalyst3DName] = this;
		m_nMouseLeftDown = 0;
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
		if (m_pROEntityActor_Face != nullptr)
		{
			m_pROEntityActor_Face->Destroy(false, false);
			m_pROEntityActor_Face = nullptr;
		}
		m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
		m_vPosition.Empty();
		m_pGeoBox = new GeoBox();
	}
	else if (!m_bClip)
	{
		FName strAnalyst3DName = "SceneClip";
		std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find(strAnalyst3DName);
		if (itorMouseControl != m_mapMouseControl.end())
		{
			m_mapMouseControl.erase(strAnalyst3DName);
		}
		m_nMouseLeftDown = 0;
		m_pLayer3DS3MFile->ClearCustomClipPlane();
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
		if (m_pROEntityActor_Face != nullptr)
		{
			m_pROEntityActor_Face->Destroy(false, false);
			m_pROEntityActor_Face = nullptr;
		}
		m_vPosition.Empty();
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Clear();
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(PanSelect);
	}
}

void ASuperMap_ClipBoxInstance::MouseLeftButtonDown()
{
	if (m_bClip && !m_bUseWebUI)
	{
		m_nMouseLeftDown++;
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos;
		vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
		{
			vPos += FVector(GetWorld()->OriginLocation);
		}
		if (m_nMouseLeftDown == 1)
		{
			m_vStart = vPos;
			m_vPosition.Add(vPos);
		}

		if (m_nMouseLeftDown == 2)
		{
			if (m_nClipBoxMode == 0)
			{
				m_pROEntityActor->ClearMesh();
				m_bEndDraw = true;
			}
			m_vEnd = vPos;
			m_vPosition.Add(vPos);
			CalculateClipBoxParam(m_vEnd);
			m_bUpdateClipValue = true;
			m_bDrawBox = true;
			ClipGeoBox();
		}
		if (m_nMouseLeftDown == 3 && m_nClipBoxMode == 1)
		{
			m_bEndDraw = true;
			DrawFace(vPos);
			m_vPosition.Add(vPos);
			DrawFace();
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
			{
				for (Gameint i = 0; i < 3; i++)
				{
					m_vPosition[i] *= CM_TO_M;
					Swap(m_vPosition[i].X, m_vPosition[i].Y);
				}
				
			}
			else
			{
				for (Gameint i = 0; i < 3; i++)
				{
					Vector3d point = Georeference::TransformUERelativeToOriginECEF(m_vPosition[i]);
					point = Georeference::TransformUEECEFToUGCECEF(point);
					point = SuperMapSDK::UnrealEngine::Algorithm3D::MathEngine::CartesianToSpherical(point.X, point.Y, point.Z);
					m_vPosition[i] = point;
				}
			}
			m_bUpdateClipValue = true;
		}
	}
}

void ASuperMap_ClipBoxInstance::CalculateClipBoxParam(Vector3d vPos)
{
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
	{
		Vector3d end = vPos;
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
		Vector3d vEnd = vPos;

		Vector3d vStartInM = Georeference::TransformUERelativeToOriginECEF(m_vStart);
		Vector3d vEndInM  = Georeference::TransformUERelativeToOriginECEF(vEnd);

		Vector3d vStartInM_UGC = Georeference::TransformUEECEFToUGCECEF(vStartInM);
		Vector3d vEndInM_UGC   = Georeference::TransformUEECEFToUGCECEF(vEndInM);

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

void ASuperMap_ClipBoxInstance::MouseRealTimeAnchor()
{
	if (m_bClip && m_nMouseLeftDown > 0 && !m_bUseWebUI && !m_bEndDraw)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos;
		vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
		{
			vPos += FVector(GetWorld()->OriginLocation);
		}
		if (m_nClipBoxMode == 0)
		{
			DrawLine(vPos);
			//CalculateClipBoxParam(vPos);
			m_bDrawBox = true;
			ChangeClipBox();
			CallClipBox.Broadcast();
		}
		else if(m_nClipBoxMode == 1)
		{
			DrawFace(vPos);
		}
	}
}

void ASuperMap_ClipBoxInstance::MouseRightButtonDown()
{

}

void ASuperMap_ClipBoxInstance::SetClipMode(int mode)
{
	m_eBoxClipMode = (BoxClipPart)mode;
	if (m_bClip)
	{
		m_bUpdateClipValue = true;
	}
}

bool ASuperMap_ClipBoxInstance::GetbDrawBox()
{
	return m_bDrawBox;
}

void ASuperMap_ClipBoxInstance::SetbDrawBox(bool bBox)
{

	m_bDrawBox = bBox;
	
}

void ASuperMap_ClipBoxInstance::SetClipBoxMode(int mode)
{
	m_nClipBoxMode = mode;
}

void ASuperMap_ClipBoxInstance::SetClipOpacity(float opacity)
{
	m_fOpacity = opacity;
}

void ASuperMap_ClipBoxInstance::SetClipLength(float length)
{
	if (m_bClip)
	{
		m_dLength = length;
		m_bUpdateClipValue = true;
	}
}

float ASuperMap_ClipBoxInstance::GetClipLength()
{
	return (float)m_dLength;
}

void ASuperMap_ClipBoxInstance::SetClipWidth(float width)
{
	if (m_bClip)
	{
		m_dWidth = width;
		m_bUpdateClipValue = true;
	}
}

float ASuperMap_ClipBoxInstance::GetClipWidth()
{
	return (float)m_dWidth;
}

void ASuperMap_ClipBoxInstance::SetClipHeight(float height)
{
	if (m_bClip)
	{
		m_dHeight = height;
		m_bUpdateClipValue = true;
	}
}

float ASuperMap_ClipBoxInstance::GetClipHeight()
{
	return (float)m_dHeight;
}

void ASuperMap_ClipBoxInstance::SetClipCenter(FVector vPos)
{
	if (m_bClip)
	{
		m_vCenter = vPos;
		m_bUpdateClipValue = true;
	}
}

FVector ASuperMap_ClipBoxInstance::GetClipCenter()
{
	return m_vCenter.ToFVector();
}

void ASuperMap_ClipBoxInstance::SetClipCenterZ(float height)
{
	if (m_bClip)
	{
		float diff = height - m_vCenter.Z;
		m_vCenter.Z += diff;
		m_bUpdateClipValue = true;
	}
}

float ASuperMap_ClipBoxInstance::GetClipCenterZ()
{
	return m_vCenter.Z;
}

void ASuperMap_ClipBoxInstance::ChangeClipBox()
{
	if (m_pGeoBox != nullptr)
	{
		double dWidth  = FMath::Max(m_dWidth, 0.1);
		double dLength = FMath::Max(m_dLength, 0.1);
		double dHeight = FMath::Max(m_dHeight, 0.1);

		m_pGeoBox->SetWidth(dWidth);
		m_pGeoBox->SetLength(dLength);
		m_pGeoBox->SetHeight(dHeight);
		m_pGeoBox->SetPosition(m_vCenter);
	}
}

Gamedouble ASuperMap_ClipBoxInstance::GetLengthFromVector(Vector3d start, Vector3d end)
{
	double length = sqrt((start.X - end.X) * (start.X - end.X) + (start.Y - end.Y) * (start.Y - end.Y) + (start.Z - end.Z) * (start.Z - end.Z));
	return length;
}

void ASuperMap_ClipBoxInstance::SelectLayer3D(FName nLayer)
{
	if (m_pLayer3DS3MFile != nullptr)
	{
		m_pLayer3DS3MFile->ClearCustomClipPlane();
		m_pLayer3DS3MFile = nullptr;
	}
	Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(nLayer);
	if (pLayer != nullptr)
	{
		m_pLayer3DS3MFile = (Layer3DS3MFile*)pLayer;
	}
}

void ASuperMap_ClipBoxInstance::ClipGeoBox()
{
	Gameint index = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->IndexOf(FString("Clipbox"));
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Remove(index);
	Style3D* pStyle = new Style3D();
	pStyle->SetFillColor(FVector4(1, 0, 0, 1));
	m_pGeoBox->SetStyle3D(pStyle);
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->AddGeometry(m_pGeoBox, TEXT("Clipbox"));
	delete pStyle;
	pStyle = nullptr;
}

void ASuperMap_ClipBoxInstance::SetIsWebUI(bool bWebUI)
{
	m_bUseWebUI = bWebUI;
}

// Called every frame
void ASuperMap_ClipBoxInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_bUpdateClipValue)
	{
		if (m_nClipBoxMode == 0)
		{
			ChangeClipBox();
			m_pLayer3DS3MFile->ClipByBox(m_pGeoBox, m_eBoxClipMode);
		}
		else if (m_nClipBoxMode == 1 && m_vPosition.Num() == 3)
		{
			if (m_eBoxClipMode == ClipOuter)
			{
				m_pLayer3DS3MFile->SetCustomClipPlane(m_vPosition[2], m_vPosition[1], m_vPosition[0]);
			}
			else if (ClipInner)
			{
				m_pLayer3DS3MFile->SetCustomClipPlane(m_vPosition[0], m_vPosition[1], m_vPosition[2]);
			}
		}
		m_bUpdateClipValue = false;
	}
}

void ASuperMap_ClipBoxInstance::DrawLine(Vector3d vPos)
{
	m_pROEntityActor->ClearMesh();
	TArray<SM_Vertex> arrVtxs;
	TArray<Gameint> arrIndexs;
	//顶点
	SM_Vertex start;
	FVector vStart = m_vStart.ToFVector();
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
	{
		vStart -= FVector(GetWorld()->OriginLocation);
	}
	start.Position = vStart;
	start.Color = FColor::Green;
	arrVtxs.Add(start);
	SM_Vertex end;
	FVector vEnd = vPos.ToFVector();
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
	{
		vEnd -= FVector(GetWorld()->OriginLocation);
	}
	end.Position = vEnd;
	end.Color = FColor::Green;
	arrVtxs.Add(end);
	//索引
	arrIndexs.Add(0);
	arrIndexs.Add(1);

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
	m_pROEntityActor->CreateProceduralMesh(arrVtxs, arrSubMeshs);
}

void ASuperMap_ClipBoxInstance::DrawFace(Vector3d vPos)
{
	TArray<SM_Vertex> arrVtxs;//顶点
	for (Gameint i = 0; i < m_vPosition.Num(); i++)
	{
		FVector drawPos = m_vPosition[i].ToFVector();
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
		{
			drawPos -= FVector(GetWorld()->OriginLocation);
		}
		SM_Vertex point;
		point.Position = drawPos;
		point.Color = FColor::Yellow;
		arrVtxs.Add(point);
	}
	SM_Vertex point1;
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
	{
		vPos -= FVector(GetWorld()->OriginLocation);
	}
	point1.Position = vPos.ToFVector();
	point1.Color = FColor::Yellow;
	arrVtxs.Add(point1);

	TArray<SM_SubMesh> arrSubMeshs;//mesh
	SM_SubMesh subMesh;

	if (m_pROEntityActor->GetMaterial() == nullptr)
	{
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		subMesh.m_pMaterialInterface = pMat;
	}

	TArray<Gameint> arrIndexs;//索引

	for (Gameint j = 0; j < m_vPosition.Num(); j++)
	{
		arrIndexs.Add(j);
		arrIndexs.Add(j + 1);
	}
	arrIndexs.Add(m_vPosition.Num());
	arrIndexs.Add(0);

	subMesh.IndexBuffer = arrIndexs;
	arrSubMeshs.Add(subMesh);

	m_pROEntityActor->SetDrawType(2);//0三角、2线
	m_pROEntityActor->CreateLineMeshComponent(arrVtxs, arrSubMeshs);
}

void ASuperMap_ClipBoxInstance::DrawFace()
{
	if (m_pROEntityActor_Face == nullptr)
	{
		m_pROEntityActor_Face = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
	}
	TArray<SM_Vertex> arrVtxs;//顶点
	for (Gameint i = 0; i < m_vPosition.Num(); i++)
	{
		FVector drawPos = m_vPosition[i].ToFVector();
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Flat)
		{
			drawPos -= FVector(GetWorld()->OriginLocation);
		}
		SM_Vertex point;
		point.Position = drawPos;
		point.Color = FColor::Green;
		arrVtxs.Add(point);
	}
	TArray<SM_SubMesh> arrSubMeshs;//mesh
	SM_SubMesh subMesh;

	if (m_pROEntityActor->GetMaterial() == nullptr)
	{
		static UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		pMat->SetScalarParameterValue(FName("Transparent"), 0.2);
		subMesh.m_pMaterialInterface = pMat;
	}

	TArray<Gameint> arrIndexs;//索引
	arrIndexs.Add(0);
	arrIndexs.Add(1);
	arrIndexs.Add(2);
	subMesh.IndexBuffer = arrIndexs;
	arrSubMeshs.Add(subMesh);

	m_pROEntityActor_Face->SetDrawType(0);//0三角、2线
	m_pROEntityActor_Face->CreateProceduralMesh(arrVtxs, arrSubMeshs);
}