// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_ProfileInstance.h"
#include "SpatialAnalyst3D/Profile.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/Georeference.h"
using namespace SuperMapSDK::UnrealEngine::SpatialAnalyst3D;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK;
// Sets default values
ASuperMap_ProfileInstance::ASuperMap_ProfileInstance()
{
 	PrimaryActorTick.bCanEverTick = true;
	m_bProfile = false;
	m_vStarPoint = Vector3d(0, 0, 0);
	m_vEndPoint = Vector3d(0, 0, 0);
	m_pROEntityActor = nullptr;
	m_nMouseLeftDown = 0;
}

ASuperMap_ProfileInstance::~ASuperMap_ProfileInstance()
{
	m_bProfile = false;
	Realse();
}

void ASuperMap_ProfileInstance::Realse()
{
	if (m_pROEntityActor != nullptr)
	{
		if (m_pROEntityActor->GetMaterial() != nullptr)
		{
			m_pROEntityActor->GetMaterial()->RemoveFromRoot();
		}

		m_pROEntityActor->SetIsSceneHiddenObject(false);
		m_pROEntityActor->Destroy(false, false);
		m_pROEntityActor = nullptr;
	}
}

void ASuperMap_ProfileInstance::BuildProfile(bool bProfile)
{
	m_bProfile = bProfile;
	Realse();
	if (m_bProfile)
	{
		m_vStarPoint = Vector3d(0, 0, 0);
		m_vEndPoint = Vector3d(0, 0, 0);
		m_strAnalyst3DName = "Profile";
		m_mapMouseControl[m_strAnalyst3DName] = this;
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			delete pAnalyst3D;
			mapAnalyst.erase(m_strAnalyst3DName);
		}
		Profile* pProfile = new Profile(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
		mapAnalyst[m_strAnalyst3DName] = pProfile;
		m_nMouseLeftDown = 0;
		m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
		m_pROEntityActor->SetIsSceneHiddenObject(true);
		ProfileGetImageEvent QAEvent = CallbackFunc_ProfileInstance;
		pProfile->CallFunc_ProfileInstance(this, QAEvent);
	}
	else if (!m_bProfile && m_strAnalyst3DName == "Profile")
	{
		m_nMouseLeftDown = 0;
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
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

UTexture2D* ASuperMap_ProfileInstance::GetImageData()
{
	if (m_bProfile)
	{
		Profile* pProfile = (Profile*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		return pProfile->GetImageData();
	}
	return nullptr;
}

FVector2D ASuperMap_ProfileInstance::GetHeightPosition()
{
	if (m_bProfile)
	{
		Profile* pProfile = (Profile*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		Vector3d vLT = pProfile->GetLeftTopPosition();
		Vector3d vRB = pProfile->GetRightBottomPosition();
		return FVector2D(vLT.Z, vRB.Z);
	}
	return FVector2D(0, 0);
}

void ASuperMap_ProfileInstance::MouseLeftButtonDown()
{
	if (m_bProfile && m_nMouseLeftDown < 2)
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

			Profile* pProfile = (Profile*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
			pProfile->Build();
			//pProfile->SetExtendHeight(1024);
			pProfile->SetStartPoint3D(m_vStarPoint);
			pProfile->SetEndPoint3D(m_vEndPoint);
		}
	}
}

void ASuperMap_ProfileInstance::MouseRightButtonDown()
{
	if (m_bProfile)
	{
		//BuildProfile(false);
		//m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
		//m_pROEntityActor->SetIsSceneHiddenObject(true);
		//m_nMouseLeftDown = 0;
		//m_vStarPoint = Vector3d(0, 0, 0);
		//m_vEndPoint = Vector3d(0, 0, 0);
	}
}

void ASuperMap_ProfileInstance::MouseRealTimeAnchor()
{
	if (m_bProfile && m_nMouseLeftDown == 1)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos;
		vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		DrawLine(vPos);
		m_DrawFlatEndPoint = vPos;
	}
}

void ASuperMap_ProfileInstance::DrawLine(Vector3d vPos)
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
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_LINERENDER_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		pMat->AddToRoot();
		subMesh.m_pMaterialInterface = pMat;
	}
	subMesh.IndexBuffer = arrIndexs;
	arrSubMeshs.Add(subMesh);
	m_pROEntityActor->SetDrawType(2);//0三角、2线
	m_pROEntityActor->CreateLineMeshComponent(arrVtxs, arrSubMeshs);
}

void ASuperMap_ProfileInstance::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASuperMap_ProfileInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASuperMap_ProfileInstance::ExecuteBroadcast()
{
	if (CallProfileTexture.IsBound())
	{
		CallProfileTexture.Broadcast();
	}
}

void CallbackFunc_ProfileInstance(void* pActor)
{
	if (pActor == nullptr)
	{
		return;
	}
	ASuperMap_ProfileInstance* AQActor = (ASuperMap_ProfileInstance*)pActor;
	AQActor->ExecuteBroadcast();
}