// Fill out your copyright notice in the Description page of Project Settings.
#include "SpatialAnalysis/SuperMap_ProjectionImageInstance.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Public/SceneView.h"
#include "Core/CameraState.h"
#include "GameFramework/PlayerController.h"
#include "Core/Georeference.h"
#include <IImageWrapperModule.h>
#include <IImageWrapper.h>
#include "Algorithm3D/MathEngine.h"

using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
ASuperMap_ProjectionImageInstance::ASuperMap_ProjectionImageInstance()
{
	m_bProjectionImage = false;
	m_nMouseLeftDown = 0;
	m_bCustom = false;
	m_fHintLineLength = 0;
}

ASuperMap_ProjectionImageInstance::~ASuperMap_ProjectionImageInstance()
{

}

void ASuperMap_ProjectionImageInstance::SetIsProjectionImage(bool bProjectionImage)
{
	m_bProjectionImage = bProjectionImage;
	if (bProjectionImage)
	{
		m_nMouseLeftDown = 0;
		m_strAnalyst3DName = "ProjectionImage";
		m_mapMouseControl[m_strAnalyst3DName] = this;
		std::map<FName, Analyst3D*>& mapAnalyst = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList();
		std::map<FName, Analyst3D*>::iterator itor = mapAnalyst.find(m_strAnalyst3DName);
		if (itor != mapAnalyst.end())
		{
			Analyst3D* pAnalyst3D = itor->second;
			delete pAnalyst3D;
			mapAnalyst.erase(m_strAnalyst3DName);
		}
		ProjectionImage* pProjectionImage = new ProjectionImage(GetWorld(), RealspaceView::GetSingleton()->GetSceneControl()->GetScene(), RealspaceView::GetSingleton()->GetCameraControl());
		mapAnalyst[m_strAnalyst3DName] = pProjectionImage;
	}
	else if (!bProjectionImage && m_strAnalyst3DName == "ProjectionImage")
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
		m_bCustom = false;
	}
}

void ASuperMap_ProjectionImageInstance::SetProjectionImageInfos(FString strFileName)
{
	if (m_bProjectionImage)
	{
		ProjectionImage* pProjectionImage = (ProjectionImage*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pProjectionImage->ProjectionFromXML(strFileName);
	}
}

void ASuperMap_ProjectionImageInstance::BuildProjectionImage()
{
	if (m_bProjectionImage)
	{
		ProjectionImage* pProjectionImage = (ProjectionImage*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];

		if (!m_bCustom)
		{
			SetCurrentCameraAttribute(pProjectionImage);
		}
		
		pProjectionImage->Build();
	}
}
void ASuperMap_ProjectionImageInstance::SetCurrentCameraAttribute(ProjectionImage* pProjection)
{
	// 获取当前相机的位置
	FVector vLocation;
	FRotator rRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(vLocation, rRotator);
	vLocation += FVector(GetWorld()->OriginLocation);
	int32 nWidth = GetWorld()->GetGameViewport()->Viewport->GetSizeXY().X;
	int32 nHeight = GetWorld()->GetGameViewport()->Viewport->GetSizeXY().Y;
	nWidth *= 0.5;
	nHeight *= 0.5;
	Vector3d vMouse(nWidth, nHeight, 0.0);
	Vector3d vPos;
	vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
	vPos += FVector(GetWorld()->OriginLocation);
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
	{
		vLocation += FVector(MathEngine::m_vWorldOffset);
		vPos += FVector(MathEngine::m_vWorldOffset);
	}

	Vector3d vLocation3d(vLocation);
	Vector3d vPos3d(vPos);

	Gamedouble dDistance = vLocation3d.Distance(vPos3d) + 100;
	if (m_fHintLineLength < dDistance)
	{
		m_fHintLineLength = dDistance;
	}
	vPos3d *= CM_TO_M;
	vLocation3d *= CM_TO_M;
	bool bIsSphere = false;
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
	{
		vLocation3d.MultiplyMatrix(Georeference::GetECEFtoGeoreference().Invert());
		Swap(vLocation3d.X, vLocation3d.Y);
		vPos3d.MultiplyMatrix(Georeference::GetECEFtoGeoreference().Invert());
		Swap(vPos3d.X, vPos3d.Y);
		bIsSphere = true;
	}
	Vector3d vDir = vPos3d - vLocation3d;

	double dHeading = 0;
	double dPitch = 0;
	MathEngine::CalHeadingAndPitch(bIsSphere, vLocation3d.X, vLocation3d.Y, vLocation3d.Z,
		vDir.X, vDir.Y, vDir.Z,
		dHeading, dPitch);

	Vector3d vLocation3d1(vLocation);
	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Globe ||
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SceneType::Ellipsoid_WGS84)
	{
		vLocation3d1 *= CM_TO_M;
		vLocation3d1.MultiplyMatrix(Georeference::GetECEFtoGeoreference().Invert());
		Swap(vLocation3d1.X, vLocation3d1.Y);
		vLocation3d1 = MathEngine::CartesianToSpherical(vLocation3d1.X, vLocation3d1.Y, vLocation3d1.Z);
	}
	pProjection->SetViewerPosition(vLocation3d1);
	pProjection->SetHeading(dHeading);
	pProjection->SetPitch(dPitch);
	pProjection->SetHintLineLength(m_fHintLineLength);
}

void ASuperMap_ProjectionImageInstance::SetViewerPosition(FVector vPos)
{
	if (m_bProjectionImage)
	{
		m_bCustom = true;
		ProjectionImage* pProjectionImage = (ProjectionImage*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		if (pProjectionImage)
		{
			pProjectionImage->SetViewerPosition(vPos);
		}
	}
}


void ASuperMap_ProjectionImageInstance::SetHeading(float fDir)
{
	if (m_bProjectionImage)
	{
		m_bCustom = true;
		ProjectionImage* pProjectionImage = (ProjectionImage*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		if (pProjectionImage)
		{
			pProjectionImage->SetHeading((double)fDir);
		}
	}
}

void ASuperMap_ProjectionImageInstance::SetPitch(float fPitch)
{
	if (m_bProjectionImage)
	{
		m_bCustom = true;
		ProjectionImage* pProjectionImage = (ProjectionImage*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		if (pProjectionImage)
		{
			pProjectionImage->SetPitch((double)fPitch);
		}
	}
}

void ASuperMap_ProjectionImageInstance::SetHintLineLength(float dLength)
{
	m_fHintLineLength = dLength;
}

void ASuperMap_ProjectionImageInstance::MouseLeftButtonDown()
{
	
}

void ASuperMap_ProjectionImageInstance::MouseRealTimeAnchor()
{
	
}

void ASuperMap_ProjectionImageInstance::MouseRightButtonDown()
{

}


UTexture2D* ASuperMap_ProjectionImageInstance::GetTexture2DFromDiskFile(FString FilePath)
{
	TArray<uint8> RawFileData;
	UTexture2D* MyTexture = NULL;
	if (FFileHelper::LoadFileToArray(RawFileData, *FilePath /*"<path to file>"*/))
	{
		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
		// Note: PNG format.  Other formats are supported
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
		if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
		{
			TArray<uint8> UncompressedBGRA;
			if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA))
			{
				// Create the UTexture for rendering
				MyTexture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);

				// Fill in the source data from the file
				void* TextureData = MyTexture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData, UncompressedBGRA.GetData(), UncompressedBGRA.Num());
				MyTexture->PlatformData->Mips[0].BulkData.Unlock();

				// Update the rendering resource from data.
				MyTexture->UpdateResource();
			}
		}
	}
	if (m_bProjectionImage && MyTexture != nullptr)
	{
		ProjectionImage* pProjectionImage = (ProjectionImage*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetAnalyst3DList()[m_strAnalyst3DName];
		pProjectionImage->SetImageData(MyTexture);
	}

	return MyTexture;
}