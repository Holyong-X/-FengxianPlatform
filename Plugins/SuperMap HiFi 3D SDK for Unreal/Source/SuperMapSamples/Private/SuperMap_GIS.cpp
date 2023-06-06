// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperMap_GIS.h"
#include "Core/CameraState.h"
#include "Core/Layer3D.h"
#include "Core/TerrainLayer.h"
#include "Core/Layer3DS3MFile.h"
#include "Data/DataSource.h"
#include "Data/Rectangle2D.h"
#include "Core/Style3D.h"
#include "Core/Layer3DImageFile.h"
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::ControlUE;

ASuperMap_GIS::ASuperMap_GIS()
{
	m_bIsVisible = true;
}

ASuperMap_GIS::~ASuperMap_GIS()
{

}

void ASuperMap_GIS::SetLODRangeScale(float value)
{
	Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(m_strLayerName);
	if (pLayer != nullptr && pLayer->Type() == Layer3DType::S3M)
	{
		Gameint nLayerId = pLayer->GetLayerID();
		Layer3DS3MFile* pLayerS3M = (Layer3DS3MFile*)pLayer;
		pLayerS3M->SetLODRangeScale(nLayerId, value);
	}
	else if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() > 0)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0)->SetLODRangeScale(value);
	}
}

float ASuperMap_GIS::GetLODRangeScale()
{
	Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(m_strLayerName);
	if (pLayer != nullptr && pLayer->Type() == Layer3DType::S3M)
	{
		Gameint nLayerId = pLayer->GetLayerID();
		Layer3DS3MFile* pLayerS3M = (Layer3DS3MFile*)pLayer;
		return pLayerS3M->GetLODRangeScale(nLayerId);
	}
	else if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() > 0)
	{
		return RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0)->GetLODRangeScale();
	}
	return -1;
}

void ASuperMap_GIS::SetShowInvalidation(bool bShow)
{
	if (RealspaceView::GetSingleton() != NULL)
	{
		Gameint nSceneType = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType();
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() == 0)
		{
			return;
		}
		Gamebool bValue = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0)->GetShowInvalidation();
		if (bShow != bValue && nSceneType == 0)
		{
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0)->SetShowInvalidation(bShow);
		}
	}
}

void ASuperMap_GIS::EnsureVisible(FName layerName)
{
	if (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::None)
	{
		return;
	}
	float height = FIXED_ALTITUDE;
	Rectangle2D rect2d = GetLayerBounds(layerName, height);
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->EnsureVisible(rect2d, height);
}

void ASuperMap_GIS::FlyToLayer(FName layerName)
{
	if (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::None)
	{
		return;
	}
	float height = FIXED_ALTITUDE;
	Rectangle2D rect2d = GetLayerBounds(layerName, height);

	FVector vPostion;
	Vector2d fVector2D = rect2d.Center();
	vPostion.X = fVector2D.X;
	vPostion.Y = fVector2D.Y;
	vPostion.Z = fmax(fabs(rect2d.Right - rect2d.Left), fabs(rect2d.Top - rect2d.Bottom));

	if (CameraControl::m_eSceneType == UGC_PLANE)
	{
		vPostion.Z = height;
		Swap(vPostion.X, vPostion.Y);
	}
	else if (CameraControl::m_eSceneType == UGC_EARTH ||
		CameraControl::m_eSceneType == UGC_EARTH_ELLIPSOID_WGS84)
	{
		Gamefloat dSize = vPostion.Z;

		dSize /= 2;
		if (dSize > (90 - FMath::RadiansToDegrees(PI / 8)))
		{
			dSize = (90 - FMath::RadiansToDegrees(PI / 8));
		}
		Gamefloat dAltitude = sin(FMath::DegreesToRadians(dSize)) * 6378137.0;
		if (tan(PI / 8) != 0)
		{
			dAltitude /= tan(PI / 8);
		}
		dAltitude += cos(FMath::DegreesToRadians(dSize)) * 6378137.0;
		dAltitude = dAltitude - 6378137.0;
		vPostion.Z = dAltitude;
	}

	CameraState* cameraState = new CameraState();
	cameraState->SetUGCameraState(vPostion.X, vPostion.Y, vPostion.Z,0,0,0);
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->Fly(cameraState, 2000);
	delete cameraState;
	cameraState = nullptr;
}

void ASuperMap_GIS::SetIsVisible(FName layerName, bool isvisible)
{
	m_bIsVisible = isvisible;
	Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(layerName);
	if (pLayer != nullptr)
	{
		pLayer->SetIsVisible(m_bIsVisible);
		if (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::Editor)
		{
			pLayer->UpdateData();
		}
	}

	TerrainLayer*  pTerrainLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(layerName);
	if (pTerrainLayer != nullptr)
	{
		pTerrainLayer->SetIsVisible(m_bIsVisible);
	}
}

bool ASuperMap_GIS::GetIsVisible()
{
	return m_bIsVisible;
}

bool ASuperMap_GIS::GetLayerIsVisible(FString layerName)
{
	Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(layerName));
	if (pLayer != nullptr)
	{
		return pLayer->GetIsVisible();
	}

	TerrainLayer*  pTerrainLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(FName(layerName));
	if (pTerrainLayer != nullptr)
	{
		return pTerrainLayer->GetIsVisible();
	}
	return false;
}

void ASuperMap_GIS::SetLayerInfos(FName strLayerName)
{
	m_strLayerName = strLayerName;
}

FVector ASuperMap_GIS::GetLayerCenterPoint(FName layerName)
{
	Rectangle2D rect2d;
	FVector vPoint;
	Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(layerName);
	TerrainLayer* pTerrainLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(layerName);
	if (pLayer != NULL)
	{
		rect2d = pLayer->GetBounds();
	}
	else if (pTerrainLayer != NULL)
	{
		rect2d = pTerrainLayer->GetBounds();
	}
	else
	{
		FString strName = layerName.ToString();
		FString leftS, rightS;
		strName.Split("@", &leftS, &rightS);
		DataSource dataSource = SuperMapSDK::UnrealEngine::Data::DataSource();
		Gamebool result = dataSource.Open(rightS);
		if (result)
		{
			Dataset* pDataset = dataSource.GetDataset(leftS);
			if (pDataset != NULL)
			{
				rect2d = pDataset->GetBounds();
			}
		}
	}
	vPoint.Y = (rect2d.Bottom + rect2d.Top)/2;
	vPoint.X = (rect2d.Left + rect2d.Right)/2;
	vPoint.Z = 0;
	return vPoint;
}

void ASuperMap_GIS::SetConstantPolygonOffset(FName strLayerName ,float fOffset)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName);
	if (pLayer3D == nullptr)
	{
		return;
	}
	if (pLayer3D->Type() == Layer3DType::S3M)
	{
		Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
		pLayer3DS3MFile->SetConstantPolygonOffset(fOffset);
	}
}

float ASuperMap_GIS::GetConstantPolygonOffset(FName strLayerName)
{
	Gamefloat fOffset = 0;
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName);
	if (pLayer3D == nullptr)
	{
		return -1;
	}
	if (pLayer3D->Type() == Layer3DType::S3M)
	{
		Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
		fOffset = pLayer3DS3MFile->GetConstantPolygonOffset();
	}
	else
	{
		fOffset = -1;
	}
	return fOffset;
}

void ASuperMap_GIS::SetSkirt(bool bSetSkirt)
{
	Scene* pScene = RealspaceView::GetSingleton()->GetSceneControl()->GetScene();
	if (pScene == nullptr)
	{
		return;
	}
	pScene->SetCreateSkirt(bSetSkirt);
}

void ASuperMap_GIS::SetSkirtHeight(float fheight)
{
	Scene* pScene = RealspaceView::GetSingleton()->GetSceneControl()->GetScene();
	if (pScene == nullptr)
	{
		return;
	}
	pScene->SetSkirtHeight(fheight);
}

bool ASuperMap_GIS::GetSkirt()
{
	Scene* pScene = RealspaceView::GetSingleton()->GetSceneControl()->GetScene();
	if (pScene == nullptr)
	{
		return false;
	}
	return pScene->GetCreateSkirt();
}

void ASuperMap_GIS::SetVisibleInViewport(FName strName, int nIndex, bool visible)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr)
	{
		pLayer3D->SetVisibleInViewport(nIndex, visible);
	}
}

bool ASuperMap_GIS::GetVisibleInViewport(FName strName, int nIndex)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr)
	{
		return pLayer3D->GetVisibleInViewport(nIndex);
	}
	return false;
}

void ASuperMap_GIS::SetMultiViewportMode(int nScreenMode)
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->SetMultiViewportMode(MultiViewportMode(nScreenMode));
}

void ASuperMap_GIS::SetTerrainExaggeration(float fValue)
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->SetTerrainExaggeration(fValue);
}

float ASuperMap_GIS::GetTerrainExaggeration()
{
	return RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainExaggeration();
}

Rectangle2D ASuperMap_GIS::GetLayerBounds(FName layerName, float& height)
{
	Rectangle2D rect2d;
	Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(layerName);
	TerrainLayer* pTerrainLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(layerName);
	if (pLayer != NULL)
	{
		rect2d = pLayer->GetBounds();
		if (CameraControl::m_eSceneType == UGC_PLANE)
		{
			if (pLayer->Type() == Layer3DType::S3M)
			{
				Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer;
				height = pLayer3DS3MFile->GetMaxHeight() * 2;
			}

			if (pLayer->Type() == Layer3DType::ImageFile)
			{
				FVector vInsertionPoint = RealspaceView::GetSingleton()->GetSceneControl()->GetTerrainPosition();
				rect2d.Left -= vInsertionPoint.X;
				rect2d.Bottom -= vInsertionPoint.Y;
				rect2d.Right -= vInsertionPoint.X;
				rect2d.Top -= vInsertionPoint.Y;
			}
		}
	}
	else if (pTerrainLayer != NULL)
	{
		rect2d = pTerrainLayer->GetBounds();
		if (CameraControl::m_eSceneType == UGC_PLANE)
		{
			height = pTerrainLayer->GetMaxHeight() * 2;
			FVector vInsertionPoint = RealspaceView::GetSingleton()->GetSceneControl()->GetTerrainPosition();
			rect2d.Left -= vInsertionPoint.X;
			rect2d.Bottom -= vInsertionPoint.Y;
			rect2d.Right -= vInsertionPoint.X;
			rect2d.Top -= vInsertionPoint.Y;
		}
	}
	else
	{
		FString strName = layerName.ToString();
		FString leftS, rightS;
		strName.Split("@", &leftS, &rightS);
		DataSource dataSource = SuperMapSDK::UnrealEngine::Data::DataSource();
		Gamebool result = dataSource.Open(rightS);
		if (result)
		{
			Dataset* pDataset = dataSource.GetDataset(leftS);
			if (pDataset != NULL)
			{
				rect2d = pDataset->GetBounds();
			}
			dataSource.Close();
		}
	}
	return rect2d;
}

void ASuperMap_GIS::SetObjectsVisible(FName LayerName, TArray<int> nIds, bool bVisible)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(LayerName);
	if (pLayer3D && pLayer3D->Type() == Layer3DType::S3M)
	{
		Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
		if (!bVisible)
		{
			// hide all
			if (nIds.Num() == 0)
			{
				pLayer3DS3MFile->SetObjectsVisible(nIds, !bVisible);
			}
			// hide ids
			else
			{
				pLayer3DS3MFile->SetObjectsVisible(nIds, bVisible);
			}
		}
		else
		{
			// show all
			if (nIds.Num() == 0)
			{
				pLayer3DS3MFile->SetObjectsVisible(nIds, !bVisible);
			}
			// show ids
			else
			{
				pLayer3DS3MFile->SetObjectsVisible(nIds, bVisible);
			}
		}
	}
}

TArray<int> ASuperMap_GIS::GetJsonArrayStringValue(FString Descriptor)
{
	TArray<int> arrIds;
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Descriptor);

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
	{
		TSharedPtr<FJsonValue> arguments = JsonObject->TryGetField(TEXT("arguments"));
		if (arguments.IsValid())
		{
			TSharedPtr<FJsonValue> objectIds = arguments->AsObject()->TryGetField(TEXT("objectIds"));
			if (objectIds.IsValid())
			{
				for (int i = 0; i < objectIds->AsArray().Num(); ++i)
				{
					int tmp;
					if (objectIds->AsArray()[i]->TryGetNumber(tmp))
					{
						arrIds.Add(tmp);
					}
				}
			}
		}
	}
	return arrIds;
}

void ASuperMap_GIS::SetSelectStyle(FName strName, FVector4 color)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr)
	{
		color.X /= 255;
		color.Y /= 255;
		color.Z /= 255;
		color.W /= 200;
		Style3D* pStyle3D = new Style3D();
		pStyle3D->SetFillColor(color);
		pLayer3D->SetSelectStyle(pStyle3D);
		delete pStyle3D;
		pStyle3D = nullptr;
	}
}

FVector4 ASuperMap_GIS::GetSelectStyle(FName strName)
{
	FVector4 fill = FVector4(0,0,0,0);
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr)
	{
		Style3D* pStyle3D = nullptr;
		pLayer3D->GetSelectStyle(pStyle3D);
		if (pStyle3D != nullptr)
		{
			fill = pStyle3D->GetFillColor();
			fill.X *= 255;
			fill.Y *= 255;
			fill.Z *= 255;
			fill.W *= 200;
			delete pStyle3D;
			pStyle3D = nullptr;
		}
	}
	return fill;
}

void ASuperMap_GIS::SetLayerMarker3DScale(FName strName, FVector vScale)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr && pLayer3D->Type() == Layer3DType::S3M)
	{
		Style3D* pStyle3D = nullptr;
		pLayer3D->GetStyle(pStyle3D);
		if (pStyle3D != nullptr)
		{
			pStyle3D->SetMarker3DScale(vScale);
			pLayer3D->UpdateData();
			delete pStyle3D;
			pStyle3D = nullptr;
		}
	}
}

FVector ASuperMap_GIS::GetLayerMarker3DScale(FName strName)
{
	FVector result = FVector();
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr && pLayer3D->Type() == Layer3DType::S3M)
	{
		Style3D* pStyle3D = nullptr;
		pLayer3D->GetStyle(pStyle3D);
		if (pStyle3D != nullptr)
		{
			result = pStyle3D->GetMarker3DScale();
			delete pStyle3D;
			pStyle3D = nullptr;
		}
	}
	return result;
}

void ASuperMap_GIS::SetLayerMarker3DRotate(FName strName, FVector vRotate)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr && pLayer3D->Type() == Layer3DType::S3M)
	{
		Style3D* pStyle3D = nullptr;
		pLayer3D->GetStyle(pStyle3D);
		if (pStyle3D != nullptr)
		{
			pStyle3D->SetMarker3DRotate(vRotate);
			pLayer3D->UpdateData();
			delete pStyle3D;
			pStyle3D = nullptr;
		}
	}
}

FVector ASuperMap_GIS::GetLayerMarker3DRotate(FName strName)
{
	FVector result = FVector();
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr && pLayer3D->Type() == Layer3DType::S3M)
	{
		Style3D* pStyle3D = nullptr;
		pLayer3D->GetStyle(pStyle3D);
		if (pStyle3D != nullptr)
		{
			result = pStyle3D->GetMarker3DRotate();
			delete pStyle3D;
			pStyle3D = nullptr;
		}
	}
	return result;
}

void ASuperMap_GIS::SetLayerMarker3DTranslation(FName strName, FVector vTranslation)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr && pLayer3D->Type() == Layer3DType::S3M)
	{
		Style3D* pStyle3D = nullptr;
		pLayer3D->GetStyle(pStyle3D);
		if (pStyle3D != nullptr)
		{
			pStyle3D->SetMarker3DTranslation(vTranslation);
			pLayer3D->UpdateData();
			delete pStyle3D;
			pStyle3D = nullptr;
		}
	}
}

FVector ASuperMap_GIS::GetLayerMarker3DTranslation(FName strName)
{
	FVector result = FVector();
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr && pLayer3D->Type() == Layer3DType::S3M)
	{
		Style3D* pStyle3D = nullptr;
		pLayer3D->GetStyle(pStyle3D);
		if (pStyle3D != nullptr)
		{
			result = pStyle3D->GetMarker3DTranslation();
			delete pStyle3D;
			pStyle3D = nullptr;
		}
	}
	return result;
}

void ASuperMap_GIS::SetLayerMaxObjectVisibleDistance(FName strName, float fValue)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr)
	{
		pLayer3D->SetMaxObjectVisibleDistance(fValue);
	}
}

float ASuperMap_GIS::GetLayerMaxObjectVisibleDistance(FName strName)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	double fMinValue = 0, fMaxValue = 600000;
	if (pLayer3D != nullptr)
	{
		pLayer3D->GetMaxMinObjectVisibleDistance(fMaxValue, fMinValue);
	}
	return (float)fMaxValue;
}

void ASuperMap_GIS::SetLayerMinObjectVisibleDistance(FName strName, float fValue)
{
	//TODO
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr)
	{
		//pLayer3D->SetMinObjectVisibleDistance(fValue);
	}
}

void ASuperMap_GIS::SetObjectsColor(FName strName, TArray<int> ids, FVector4 color)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr && pLayer3D->Type() == S3M)
	{
		color.X /= 255;
		color.Y /= 255;
		color.Z /= 255;
		color.W /= 200;
		Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
		pLayer3DS3MFile->GetObjectsColorDictionary()->SetObjectsColor(ids, color);
		Rectangle2D rect2d = pLayer3DS3MFile->GetBounds();
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GlobalRefreshRaster(rect2d);
	}
}

void ASuperMap_GIS::ResetObjectsColor(FName strName)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr && pLayer3D->Type() == S3M)
	{
		Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
		pLayer3DS3MFile->GetObjectsColorDictionary()->ResetObjectsColor();
	}
}

void ASuperMap_GIS::SetLoadingPriority(FName strName, int type)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (type == UsePagedLodInfo && pLayer3D->DataType() != OSGBType::ObliquePhotogrammetry3DModel)
	{
		return;
	}
	if (pLayer3D != nullptr && pLayer3D->Type() == S3M)
	{
		Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
		pLayer3DS3MFile->SetLoadingPriority((LoadingPriorityEnum)type);
	}
}

int ASuperMap_GIS::GetLoadingPriority(FName strName)
{
	int type = 1;
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer3D != nullptr && pLayer3D->Type() == S3M)
	{
		Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
		type = pLayer3DS3MFile->GetLoadingPriority();
	}
	return type;
}

void ASuperMap_GIS::SetImageLayerOpaqueRate(FName layerName, float value)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(layerName);
	if (pLayer3D->Type() == ImageFile)
	{
		Layer3DImageFile* pImageLayer = (Layer3DImageFile*)pLayer3D;
		pImageLayer->SetOpaqueRate(value);
	}
}

float ASuperMap_GIS::GetImageLayerOpaqueRate(FName layerName)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(layerName);
	if (pLayer3D->Type() == ImageFile)
	{
		Layer3DImageFile* pImageLayer = (Layer3DImageFile*)pLayer3D;
		return pImageLayer->GetOpaqueRate();
	}
	return 0;
}

int ASuperMap_GIS::GetLayer3DType(FName layerName)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(layerName);
	if (pLayer3D != NULL)
	{
		return pLayer3D->Type();
	}
	else
	{
		return -1;
	}
}