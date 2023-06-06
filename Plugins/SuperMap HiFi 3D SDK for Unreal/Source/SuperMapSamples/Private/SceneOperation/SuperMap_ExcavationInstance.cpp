// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneOperation/SuperMap_ExcavationInstance.h"
#include "GameFramework/PlayerController.h"
#include "Core/TerrainLayers.h"
#include "Core/TerrainLayer.h"
#include "Core/GlobalImage.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/Georeference.h"
#include "Data/Vector3d.h"
#include <IImageWrapperModule.h>
#include <IImageWrapper.h>
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK;
PRAGMA_DISABLE_OPTIMIZATION
ASuperMap_ExcavationInstance::ASuperMap_ExcavationInstance()
{
 	PrimaryActorTick.bCanEverTick = true;
	m_pROEntityActor = nullptr;
	m_pTopFaceROEntityActor = nullptr;
	m_nMouseLeftDown = 0;
	m_bExcavation = false;
	m_bButtonRightDown = false;
	m_nModifyRegionMode = 0;
	m_bIsTerrainLayer = false;
	m_mapLayer3DS3MFiles.Empty();
	m_bButtonLeftDown = false;
	m_bWithoutWeb = true;
	m_fExtendHeight = 50;
	m_strSideTexture = TEXT("");
	m_strTopTexture = TEXT("");
	m_nInterpolatoryCount = 10;
	m_pSideTexture = nullptr;
	m_bChartlet = false;
}

ASuperMap_ExcavationInstance::~ASuperMap_ExcavationInstance()
{
	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor = nullptr;
	}
	if (m_pTopFaceROEntityActor != nullptr)
	{
		m_pTopFaceROEntityActor = nullptr;
	}
	if (m_pSideTexture != nullptr)
	{
		m_pSideTexture->RemoveFromRoot();
		m_pSideTexture->MarkPendingKill();
		m_pSideTexture = nullptr;
	}
	m_mapLayer3DS3MFiles.Empty();
	m_bIsTerrainLayer = false;
}

void ASuperMap_ExcavationInstance::ClearModifyRegion()
{
	for (int i = 0; i < m_arrGeoRegion3Ds.Num(); i++)
	{
		delete m_arrGeoRegion3Ds[i];
		m_arrGeoRegion3Ds[i] = nullptr;
	}
	m_arrGeoRegion3Ds.Empty();

	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor->Destroy(false, false);
		m_pROEntityActor = nullptr;
	}
	if (m_pTopFaceROEntityActor != nullptr)
	{
		m_pTopFaceROEntityActor->Destroy(false, false);
		m_pTopFaceROEntityActor = nullptr;
	}
	
	if (m_pSideTexture != nullptr)
	{
		m_pSideTexture->RemoveFromRoot();
		m_pSideTexture->MarkPendingKill();
		m_pSideTexture = nullptr;
	}

	m_listPosition.Empty();
	m_listDrawPosition.Empty();
	for (TMap<FName, Layer3DS3MFile*>::TConstIterator It = m_mapLayer3DS3MFiles.CreateConstIterator(); It; ++It)
	{
		It->Value->ClearModifyRegions();
	}
	if (m_bIsTerrainLayer)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetGlobalImage()->ClearExcavationRegion();
	}
	m_strTopMaterialPath = "";
	m_strSideMaterialPath = "";
}

void ASuperMap_ExcavationInstance::BuildExcavation(bool bExcavation)
{
	m_bExcavation = bExcavation;
	ClearModifyRegion();
	m_nMouseLeftDown = 0;
	if (m_bExcavation)
	{
		FName strInstanceName = "Excavation";
		m_mapMouseControl[strInstanceName] = this;
		m_bButtonRightDown = true;
	}
	else
	{
		std::map<FName, FSuperMap_MouseControl*>::iterator itorMouseControl = m_mapMouseControl.find("Excavation");
		if (itorMouseControl != m_mapMouseControl.end())
		{
			m_mapMouseControl.erase(itorMouseControl->first);
		}
	}
}

void ASuperMap_ExcavationInstance::AddExcavationRegion()
{
	if (m_pROEntityActor != nullptr)
	{
		m_pROEntityActor->Destroy(false, false);
		m_pROEntityActor = nullptr;
	}
	m_pROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
	m_pTopFaceROEntityActor = GetWorld()->SpawnActor<ASuperMap_ROEntityActor>();
	m_bButtonRightDown = false;
	m_nMouseLeftDown = 0;
	m_listPosition.Empty();
	m_listDrawPosition.Empty();
}

void ASuperMap_ExcavationInstance::SetModifyRegionMode(int type)
{
	m_nModifyRegionMode = type;
}

void ASuperMap_ExcavationInstance::SelectLayer(FName strLayerName, bool IsSelect)
{
	if (IsSelect)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName) != nullptr)
		{
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName)->Type() == S3M)
			{
				Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName);
				m_mapLayer3DS3MFiles.Add(strLayerName, pLayer3DS3MFile);
			}
		}
		if (strLayerName.Compare("GlobalImage") == 0)
		{
			m_bIsTerrainLayer = true;
		}
	}
	else
	{
		m_mapLayer3DS3MFiles.Remove(strLayerName);
		if (strLayerName.Compare("GlobalImage") == 0)
		{
			m_bIsTerrainLayer = false;
		}
	}
}

void ASuperMap_ExcavationInstance::MouseLeftButtonDown()
{
	if (m_bExcavation && !m_bButtonRightDown && m_bWithoutWeb)
	{
		m_bButtonLeftDown = true;
		m_nMouseLeftDown++;
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos, vDrawPos;
		vDrawPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToCartesian(vMouse);
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
		{
			vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
			vPos *= CM_TO_M;
			//vPos = vDrawPos + FVector(GetWorld()->OriginLocation);
			//vPos = vPos.ToUGCVector();
		}
		else
		{
			vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
		}
		if (m_listDrawPosition.Num() > 0)
		{
			m_listDrawPosition.RemoveAt(m_listDrawPosition.Num() - 1);
		}
		m_listPosition.Add(vPos);
		m_listDrawPosition.Add(vDrawPos.ToFVector());
		m_bButtonLeftDown = false;
	}
}

void ASuperMap_ExcavationInstance::MouseRightButtonDown()
{
	if (m_bExcavation && !m_bButtonRightDown && m_bWithoutWeb)
	{
		if (m_nMouseLeftDown < 3)
		{
			m_listPosition.Empty();
			m_listDrawPosition.Empty();
			if (m_pROEntityActor != nullptr)
			{
				m_pROEntityActor->Destroy(false, false);
				m_pROEntityActor = nullptr;
			}
			if (m_pTopFaceROEntityActor != nullptr)
			{
				m_pTopFaceROEntityActor->Destroy(false, false);
				m_pTopFaceROEntityActor = nullptr;
			}
			
			return;
		}

		m_listDrawPosition.RemoveAt(m_listDrawPosition.Num() - 1);


		//==================================================
		FVector pos0 = m_listPosition[0].ToFVector();
		FVector pos1 = m_listPosition[1].ToFVector();
		FVector pos2 = m_listPosition[2].ToFVector();
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetSceneType() != SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
		{
			pos0 = MathEngine::SphericalToCartesian(m_listPosition[0].X, m_listPosition[0].Y, m_listPosition[0].Z);
			pos1 = MathEngine::SphericalToCartesian(m_listPosition[1].X, m_listPosition[1].Y, m_listPosition[1].Z);
			pos2 = MathEngine::SphericalToCartesian(m_listPosition[2].X, m_listPosition[2].Y, m_listPosition[2].Z);
		}

		FVector v1 = pos0 - pos1;
		FVector v2 = pos0 - pos2;
		FVector v3 = FVector::CrossProduct(v1,v2);
		FVector v4 = FVector(GetWorld()->OriginLocation) + MathEngine::m_vWorldOffset;
		v4 = (Vector3d(v4).MultiplyMatrix(Georeference::GetECEFtoGeoreference().Invert())).ToFVector();
		Gamefloat dot = FVector::DotProduct(v3, v4);

		if (dot < 0)
		{
			int i = 1;
			int j = m_listPosition.Num() - 1;
			for (; i < j; ++i, --j)
			{
				Vector3d buf = m_listPosition[i];
				m_listPosition[i] = m_listPosition[j];
				m_listPosition[j] = buf;
			}
		}
		//===================================================
		GeoRegion3D* pGeoRegion3D = new GeoRegion3D();
		pGeoRegion3D->SetPoints(m_listPosition);
		m_arrGeoRegion3Ds.Add(pGeoRegion3D);
		if (m_bChartlet)
		{
			//SetStyle(pGeoRegion3D);
			DrawSideFace(pGeoRegion3D);
			DrawTopFace(pGeoRegion3D);
		}
		if (m_bIsTerrainLayer)
		{
			FString strTag = FString::Printf(TEXT("TerrainExcavation_%d"), m_arrGeoRegion3Ds.Num());
			GlobalImage* pGlobalImage = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetGlobalImage();
			pGlobalImage->AddExcavationRegion(pGeoRegion3D, strTag);
		}
		for (TMap<FName, Layer3DS3MFile*>::TConstIterator It = m_mapLayer3DS3MFiles.CreateConstIterator(); It; ++It)
		{
			It->Value->ClearModifyRegions();
			It->Value->SetModifyRegions(m_arrGeoRegion3Ds, (ModifyRegionMode)m_nModifyRegionMode);
		}

		DrawFace();
		m_bButtonRightDown = true;
	}
}

void ASuperMap_ExcavationInstance::MouseRealTimeAnchor()
{
	if (m_bExcavation && !m_bButtonRightDown && m_nMouseLeftDown > 0 && !m_bButtonLeftDown && m_bWithoutWeb)
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

void ASuperMap_ExcavationInstance::DrawFace()
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
		UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *SM_EXCAVATION_SIDEFACE_MAT);
		UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
		if (m_pSideTexture != nullptr)
		{
			pMat->SetTextureParameterValue(FName("SideFace"), m_pSideTexture);
		}
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

void ASuperMap_ExcavationInstance::SetStyle(GeoRegion3D* pGeoRegion3D)
{
	Style3D* style = new Style3D();

	FString filePath = m_strTopTexture;
	style->SetAltitudeMode(Absolute);
	style->SetSideTexture(filePath);
	style->SetTilingU(1);
	style->SetTilingV(1);
	style->SetTopTexture(filePath);
	style->SetTopTilingU(1);
	style->SetTopTilingV(1);
	style->SetExtendHeight(-m_fExtendHeight);
	pGeoRegion3D->SetStyle3D(style);
}

void ASuperMap_ExcavationInstance::DrawSideFace(GeoRegion3D* geoRegion3D)
{
	if (m_bChartlet)
	{
		Vector3d innerPos = geoRegion3D->GetInnerPoint3D();
		// 细分差值 num 差值个数
		int num = m_nInterpolatoryCount;
		double bottom = innerPos.Z - m_fExtendHeight;
		double top = -9999;
		TArray<FVector2D> arrUV;
		TArray<Vector3d> arrLocations;
		TArray<Gameint> arrIndex;
		TArray<Vector3d> listPosition = m_listPosition;
		listPosition.Add(m_listPosition[0]);
		for (int i = 0; i < listPosition.Num() - 1; i++)
		{
			Vector3d unit = (listPosition[i + 1] - listPosition[i]) / num;

			for (int j = 0; j < num; j++)
			{
				Vector3d pos = listPosition[i] + Vector3d(unit.X * j, unit.Y * j, unit.Z * j);

				arrLocations.Add(pos);
				arrLocations.Add(pos);
			}
		}
		arrLocations.Add(listPosition[0]);
		arrLocations.Add(listPosition[0]);
		for (int max = 0; max < arrLocations.Num(); max++)
		{
			double dZ = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0)->GetHeight(arrLocations[max]);
			arrLocations[max].Z = dZ;
			if (dZ > top)
			{
				top = dZ;
			}
		}
		for (int nPosCount = 0; nPosCount < arrLocations.Num(); nPosCount++)
		{
			if (nPosCount % 2 != 0)
			{
				arrLocations[nPosCount].Z = bottom;
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
		//计算每段贴纹理的长度
		TArray<Gamedouble> widths;
		TArray<Vector3d> vUpos;
		TArray<Vector3d> vNormals;
		widths.Add(0);
		for (Gameint uv = 0; uv < listPosition.Num() - 1; uv++)
		{
			Vector3d vWidth1 = MathEngine::SphericalToCartesian2(listPosition[uv].X, listPosition[uv].Y, 0);
			Vector3d vWidth2 = MathEngine::SphericalToCartesian2(listPosition[uv + 1].X, listPosition[uv + 1].Y, 0);
			Gamedouble width = widths[uv] + vWidth1.Distance(vWidth2);
			vUpos.Add(vWidth1);
			widths.Add(width);
			Vector3d nor = GetNormalVectior(listPosition[uv], Vector3d(listPosition[uv].X, listPosition[uv].Y, bottom),listPosition[uv + 1]);
			vNormals.Add(nor);
		}
		Vector3d copynormal = vNormals[vNormals.Num() - 1];
		vNormals.Add(copynormal);
		vUpos.Add(MathEngine::SphericalToCartesian2(listPosition[listPosition.Num() - 1].X, listPosition[listPosition.Num() - 1].Y, 0));
		for (Gameint i = 0; i < arrLocations.Num(); i++)
		{
			SM_Vertex point;
			//UV
			int poscount = i / (2 * num);

			Vector3d pos0 = MathEngine::SphericalToCartesian2(arrLocations[i].X, arrLocations[i].Y, 0);
			Vector3d pos1 = vUpos[poscount];
			double w = pos0.Distance(pos1) + widths[poscount];
			float h = FMath::Abs(arrLocations[i].Z - top);
			float u = w * CM_TO_M;
			float v = h * CM_TO_M;
			//法线
			FVector normal = vNormals[poscount].ToFVector();
			//顶点
			Vector3d ppos = MathEngine::SphericalToCartesian2(arrLocations[i].X, arrLocations[i].Y, arrLocations[i].Z);
			ppos *= M_TO_CM;
			ppos.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
			ppos -= (Vector3d(GetWorld()->OriginLocation) + MathEngine::m_vWorldOffset);

			point.Position = ppos.ToFVector();
			point.UV0 = FVector2D(u, v);
			point.Color = FColor::Yellow;
			point.Normal = normal;
			arrVtxs.Add(point);
		}
		TArray<SM_SubMesh> arrSubMeshs;//mesh
		SM_SubMesh subMesh;

		if (m_pROEntityActor->GetMaterial() == nullptr)
		{
			UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *m_strSideMaterialPath);
			UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
			if (m_pSideTexture != nullptr)
			{
				//pMat->SetTextureParameterValue(FName("SideFace"), m_pSideTexture);
			}
			pMat->AddToRoot();
			subMesh.m_pMaterialInterface = pMat;
		}
		subMesh.IndexBuffer = arrIndex;
		arrSubMeshs.Add(subMesh);
		m_pROEntityActor->SetDrawType(0);//0三角、2线
		m_pROEntityActor->CreateProceduralMesh(arrVtxs, arrSubMeshs);
	}
}

void ASuperMap_ExcavationInstance::DrawTopFace(GeoRegion3D* geoRegion3D)
{
	if (m_bChartlet)
	{
		Vector3d innerPos = geoRegion3D->GetInnerPoint3D();
		TArray<SM_Vertex> arrVtxs;//顶点
		TArray<Vector3d> listPosition = m_listPosition;
		listPosition.Add(m_listPosition[0]);
		FVector v1 = m_listPosition[0].ToFVector() - m_listPosition[1].ToFVector();
		FVector v2 = m_listPosition[0].ToFVector() - m_listPosition[2].ToFVector();
		FVector v3 = FVector::CrossProduct(v1, v2);
		v3.Normalize();
		for (Gameint i = 0; i < listPosition.Num(); i++)
		{
			SM_Vertex point;
			//UV
			Rectangle2D rec = geoRegion3D->GetBounds();
			Gamedouble width = FMath::Abs(rec.Width());
			Gamedouble height = FMath::Abs(rec.Height());
			double u = FMath::Abs(listPosition[i].X - rec.Left) / width;
			double v = FMath::Abs(listPosition[i].Y - rec.Top) / height;
			//法线
			FVector normal = v3;
			//顶点
			Vector3d ppos = MathEngine::SphericalToCartesian2(listPosition[i].X, listPosition[i].Y, (innerPos.Z - m_fExtendHeight));
			ppos *= M_TO_CM;
			ppos.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
			ppos -= (Vector3d(GetWorld()->OriginLocation) + MathEngine::m_vWorldOffset);
			point.Position = ppos.ToFVector();
			point.UV0 = FVector2D(u, v);
			point.Normal = normal;
			arrVtxs.Add(point);
		}
		TArray<SM_SubMesh> arrSubMeshs;//mesh
		SM_SubMesh subMesh;

		if (m_pTopFaceROEntityActor->GetMaterial() == nullptr)
		{
			UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *m_strTopMaterialPath);
			UMaterialInstanceDynamic* pMat = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
			pMat->AddToRoot();
			subMesh.m_pMaterialInterface = pMat;
		}
		TArray<Gameint> arrIndexs;//索引
		for (int index = listPosition.Num() - 2; index > 1; index--)
		{
			arrIndexs.Add(0);
			arrIndexs.Add(index);
			arrIndexs.Add(index - 1);

		}
		//geoRegion3D->GetTriangleIndices(arrIndexs);
		subMesh.IndexBuffer = arrIndexs;
		arrSubMeshs.Add(subMesh);
		m_pTopFaceROEntityActor->SetDrawType(0);//0三角、2线
		m_pTopFaceROEntityActor->CreateProceduralMesh(arrVtxs, arrSubMeshs);

	}
}

void ASuperMap_ExcavationInstance::BeginPlay()
{
	Super::BeginPlay();
}

void ASuperMap_ExcavationInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASuperMap_ExcavationInstance::SetUseWeb(bool bUseWithoutWeb)
{
	m_bWithoutWeb = bUseWithoutWeb;
}

TArray<FVector> ASuperMap_ExcavationInstance::GetJsonArrayStringValue(FString Descriptor, FString FieldName)
{
	TArray<FVector> arrVPos;
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Descriptor);

	if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
	{
		TSharedPtr<FJsonValue> arguments = JsonObject->TryGetField(TEXT("arguments"));
		if (arguments.IsValid())
		{
			TSharedPtr<FJsonValue> geometry = arguments->AsObject()->TryGetField(TEXT("geometry"));
			if (geometry.IsValid())
			{
				const TArray<TSharedPtr<FJsonValue>>* arrValue;
				if (geometry->AsObject()->TryGetArrayField(FieldName, arrValue))
				{
					FVector vPos;
					for (int i = 0; i < (*arrValue).Num(); i++)
					{

						FString str_x = (*arrValue)[i]->AsObject()->GetStringField(TEXT("x"));
						vPos.X = FCString::Atof(*str_x);
						FString str_y = (*arrValue)[i]->AsObject()->GetStringField(TEXT("y"));
						vPos.Y = FCString::Atof(*str_y);
						FString str_z = (*arrValue)[i]->AsObject()->GetStringField(TEXT("z"));
						vPos.Z = FCString::Atof(*str_z);
						arrVPos.Emplace(vPos);
					}
				}
			}
		}
	}
	return arrVPos;
}

void ASuperMap_ExcavationInstance::AddWebExcavationRegion(TArray<FVector> arrPos, FString Tag)
{
	if (m_bExcavation)
	{
		TArray<Vector3d> arrvPos;
		for (Gameint i = 0; i < arrPos.Num(); i++)
		{
			arrvPos.Add(Vector3d(arrPos[i]));
		}
		GeoRegion3D* pGeoRegion3D = new GeoRegion3D();
		pGeoRegion3D->SetPoints(m_listPosition);
		m_arrGeoRegion3Ds.Add(pGeoRegion3D);
		if (m_bIsTerrainLayer)
		{
			GlobalImage* pGlobalImage = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetGlobalImage();
			pGlobalImage->AddExcavationRegion(pGeoRegion3D, Tag);
		}
		for (TMap<FName, Layer3DS3MFile*>::TConstIterator It = m_mapLayer3DS3MFiles.CreateConstIterator(); It; ++It)
		{
			It->Value->ClearModifyRegions();
			It->Value->SetModifyRegions(m_arrGeoRegion3Ds, (ModifyRegionMode)m_nModifyRegionMode);
		}
	}
}

void ASuperMap_ExcavationInstance::SetExtendHeight(float height)
{
	m_fExtendHeight = height;
}

void ASuperMap_ExcavationInstance::SetSideTexture(FString filePath)
{
	m_strSideTexture = filePath;
	UTexture2D* pImage = GetTexture2DFromDiskFile(filePath);
	if (pImage == nullptr)
	{
		return;
	}
	if (m_pSideTexture != nullptr)
	{
		m_pSideTexture->RemoveFromRoot();
		m_pSideTexture->MarkPendingKill();
		m_pSideTexture = nullptr;
	}

	m_pSideTexture = pImage;
	m_pSideTexture->AddToRoot();
}

void ASuperMap_ExcavationInstance::SetTopTexture(FString filePath)
{
	m_strTopTexture = filePath;
}

void ASuperMap_ExcavationInstance::SetInterpolatoryCount(int nCount)
{
	m_nInterpolatoryCount = nCount;
}

UTexture2D* ASuperMap_ExcavationInstance::GetTexture2DFromDiskFile(FString FilePath)
{
	TArray<uint8> RawFileData;
	UTexture2D* MyTexture = NULL;
	if (FFileHelper::LoadFileToArray(RawFileData, *FilePath /*"<path to file>"*/))
	{
		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
		// Note: PNG format.  Other formats are supported
		TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);

		if (FPaths::GetExtension(FilePath).Compare("png") == 0)
		{
			ImageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
		}
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
	return MyTexture;
}

void ASuperMap_ExcavationInstance::IsChartlet(bool bChartlet)
{
	m_bChartlet = bChartlet;
}

Vector3d ASuperMap_ExcavationInstance::GetNormalVectior(Vector3d v1, Vector3d v2, Vector3d v3)
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

void ASuperMap_ExcavationInstance::SetTopMaterialPath(FString filePath)
{
	m_strTopMaterialPath = filePath;
}

void ASuperMap_ExcavationInstance::SetSideMaterialPath(FString filePath)
{
	m_strSideMaterialPath = filePath;
}

PRAGMA_ENABLE_OPTIMIZATION