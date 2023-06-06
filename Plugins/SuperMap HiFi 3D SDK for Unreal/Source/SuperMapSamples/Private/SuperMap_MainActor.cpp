// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperMap_MainActor.h"
#include "ControlUE/RealspaceView.h"
#include "Data/UnrealWorkspaceManager.h"
#include "Engine/GameViewportClient.h"
#include "SlateCore/Public/Widgets/SWindow.h"
#include "Components/InputComponent.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "GameFramework/PlayerController.h"
#include "Layout/SlateRect.h"

#include "Core/SceneControl.h"
#include "Core/Scene.h"
#include "Core/Layer3Ds.h"
#include "Core/Layer3D.h"
#include "Core/TerrainLayers.h"
#include "Core/TerrainLayer.h"
#include "Core/Public/Misc/Paths.h"
#include "Core/ROCacheManager.h"
#include "Core/Layer3DS3MFile.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Application/SlateApplicationBase.h"
#include "Core/Public/Misc/MessageDialog.h"
#include "Kismet/KismetSystemLibrary.h"
#include "XmlParser/Public/XmlParser.h"
#include "Interfaces/IPluginManager.h"
#include "Core/Georeference.h"
#include "Graphics3D/GameMaterialManager.h"
#if WITH_EDITOR
#include "Editor.h"
#include "LevelEditorViewport.h"
#endif
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "Data/FieldInfo.h"
#include "Core/Layer3DDatasetVector.h"
#include "Core/Layer3DDatasetModel.h"
#include "Core/Layer3DDatasetVectorLine.h"
#include "Core/Layer3DDatasetVectorRegion.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Base3D/CommonDefine.h"
#include "Data/AssetLibrary.h"
#include "HAL/PlatformFilemanager.h"
#include "Core/TrackingLayer.h"
#include "Algorithm3D/MathEngine.h"

using namespace SuperMapSDK::UnrealEngine::Base3D;
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
ASuperMap_MainActor::ASuperMap_MainActor()
{
	// 每帧调用
	PrimaryActorTick.bCanEverTick = true;
	m_nSceneType = 2;
	m_vPosition = FVector(0.0f, 0.0f, 0.0f);
	m_vGeoreferenceOrigin = FVector(0.0f, 0.0f, 0.0f);
	m_bIncludeS3M = false;
	m_bIncludeTerrain = false;

	m_bInitialize = false;
	m_bIsShowGlobe = false;
	m_bGetMousePosition = false;
	m_bShowMousePosition = false;
	m_bShouldTick = false;

	m_pWorkspace = nullptr;
	m_pDataSources = nullptr;

	m_bImportAsset = false;
	m_bDeleteDefaultGlobalImage = false;
	m_bComputeNormal = false;
	m_bEnableCollision = false;
	m_nUpdateCount = 2;
	m_bEditorSaveGeoreference = false;
	m_bIsMultifile = false;
	m_strLanguage = TEXT("Chinese");
}

ASuperMap_MainActor::~ASuperMap_MainActor()
{
}

void ASuperMap_MainActor::BeginDestroy()
{
	if (RealspaceView::GetSingleton()->IsOwner(this))
	{
		RealspaceView::GetSingleton()->Destroy(true);
		RealspaceView::GetSingleton()->SetMainCameraActor(nullptr);
		RealspaceView::GetSingleton()->ReleaseROManager();
	}
	AActor::BeginDestroy();
}

void ASuperMap_MainActor::MouseLeftButtonDown()
{
	RealspaceView::GetSingleton()->MouseLeftButtonDown();

	//获取鼠标当前点
	if (m_bShowMousePosition)
	{
		FVector vMouse;
		GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
		Vector3d vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
		if (m_nSceneType == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
		{
			vPos.X *= CM_TO_M;
			vPos.Y *= CM_TO_M;
			vPos.Z *= CM_TO_M;
		}
		m_vMousePosition.m_strX = FString::Printf(TEXT("%.8f"), vPos.X);
		m_vMousePosition.m_strY = FString::Printf(TEXT("%.8f"), vPos.Y);
		m_vMousePosition.m_strZ = FString::Printf(TEXT("%.3f"), vPos.Z);
		m_bGetMousePosition = true;
	}
	
	std::map<FName, FSuperMap_MouseControl*>::iterator itor = m_mapMouseControl.begin();
	while (itor != m_mapMouseControl.end())
	{
		FSuperMap_MouseControl* pMouseControl = itor->second;
		if (pMouseControl != nullptr)
		{
			pMouseControl->MouseLeftButtonDown();
		}
		itor++;
	}
}

void ASuperMap_MainActor::SetIsShowRealPosition(bool bShowRealPosition)
{
	m_bShowRealPosition = bShowRealPosition;
}

void ASuperMap_MainActor::MouseLeftButtonUp()
{
	RealspaceView::GetSingleton()->MouseLeftButtonUp();
}

void ASuperMap_MainActor::MouseLeftButtonDoubleClick()
{
	RealspaceView::GetSingleton()->MouseLeftButtonDoubleClick();
}

void ASuperMap_MainActor::MouseRightButtonUp()
{
	RealspaceView::GetSingleton()->MouseRightButtonUp();
}

void ASuperMap_MainActor::MouseRightButtonDown()
{
	RealspaceView::GetSingleton()->MouseRightButtonDown();

	std::map<FName, FSuperMap_MouseControl*>::iterator itor = m_mapMouseControl.begin();
	while (itor != m_mapMouseControl.end())
	{
		FSuperMap_MouseControl* pMouseControl = itor->second;
		if (pMouseControl != nullptr)
		{
			pMouseControl->MouseRightButtonDown();
		}
		itor++;
	}
}

void ASuperMap_MainActor::MouseMiddleButtonMove(float Value)
{
	RealspaceView::GetSingleton()->MouseMiddleButtonMove(Value);
}

void ASuperMap_MainActor::MouseMiddleButtonUp()
{
	RealspaceView::GetSingleton()->MouseMiddleButtonUp();
}

void ASuperMap_MainActor::MouseMiddleButtonDown()
{
	RealspaceView::GetSingleton()->MouseMiddleButtonDown();
}

bool ASuperMap_MainActor::OpenFileDialog(FString strFileTypes)
{
	void* ParentWindowHandle = FSlateApplicationBase::Get().GetActiveTopLevelWindow()->GetNativeWindow()->GetOSWindowHandle();
	IDesktopPlatform* pDesktopPlatform = FDesktopPlatformModule::Get();
	if (pDesktopPlatform)
	{
		EFileDialogFlags::Type SelectionFlag = EFileDialogFlags::Multiple;
		TArray<FString> arrFileNames;
		FString strTile = "Choose File";
		FString FileTypes = TEXT("(所有格式)|*.*;");
		if (!strFileTypes.IsEmpty())
		{
			FileTypes = TEXT("(支持格式) |") + strFileTypes;
		}
		bool bSuccess = pDesktopPlatform->OpenFileDialog(ParentWindowHandle, strTile, ".", "", FileTypes, SelectionFlag, arrFileNames);
		if (bSuccess && arrFileNames.Num() == 1)
		{
			m_strLayerAddress = arrFileNames[0];
			m_strLayerAddress = FPaths::ConvertRelativePathToFull(m_strLayerAddress);
			return true;
		}
		else if (bSuccess && arrFileNames.Num() > 1)
		{
			for (int32 i = 0; i < arrFileNames.Num(); i++)
			{
				if (FPaths::GetExtension(arrFileNames[i]).Compare("udbx") == 0 || FPaths::GetExtension(arrFileNames[i]).Compare("udb") == 0)
				{
					break;
				}
				FSuperMap_LayerInfo layerInfo;
				layerInfo.m_strName = ModificationLayerName(FPaths::GetBaseFilename(arrFileNames[i]), 0);
				layerInfo.m_strPath = FPaths::ConvertRelativePathToFull(arrFileNames[i]);
				layerInfo.m_strDataName = FPaths::GetBaseFilename(arrFileNames[i]);
				layerInfo.m_nType = 0;
				layerInfo.m_bMarkerLayer = false;
				layerInfo.m_nLayerType = 0;
				AddLocalLayers(layerInfo);
				m_arrLayers.Add(layerInfo);
			}
			m_strLayerAddress = "";
			CallFOpenMultiFile.Broadcast();
			m_bIsMultifile = true;
			return true;
		}
	}
	return false;
}

bool ASuperMap_MainActor::OpenFileFolderDialog()
{
	void* ParentWindowHandle = FSlateApplicationBase::Get().GetActiveTopLevelWindow()->GetNativeWindow()->GetOSWindowHandle();
	IDesktopPlatform* pDesktopPlatform = FDesktopPlatformModule::Get();
	if (pDesktopPlatform)
	{
		FString FolderName;
		FString strTile = "choose folder";
		bool bSuccess = pDesktopPlatform->OpenDirectoryDialog(ParentWindowHandle, strTile, ".", FolderName);
		if (bSuccess && FolderName.Len() > 0)
		{
			m_strLayerAddress = FolderName;
			return true;
		}
	}
	return false;
}

bool ASuperMap_MainActor::AddLocalLayers(FSuperMap_LayerInfo strLayers)
{
	if (!m_bShouldTick && (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::None))
	{
		return false;
	}

	if (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::PIE
		|| RealspaceView::GetSingleton()->GetWorldType() == EWorldType::Game)
	{
		m_bImportAsset = false;
	}
	else if (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::Editor)
	{
		m_bImportAsset = true;
	}
	FString strFileName = strLayers.m_strPath;

	FString strLayerName = strLayers.m_strName;

	FString strExt = FPaths::GetExtension(strFileName);

	RealspaceView::GetSingleton()->GetSceneControl()->SetTerrainPosition(m_vPosition.X, m_vPosition.Y, m_vPosition.Z);

	if (strExt.Compare("scp") == 0)
	{
		Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strFileName, SuperMapSDK::UnrealEngine::Core::Layer3DType::S3M, false, strLayerName);
		m_bIncludeS3M = true;
		
		if (m_nSceneType == Flat && pLayer3D != nullptr && pLayer3D->Type() == SuperMapSDK::UnrealEngine::Core::Layer3DType::S3M)
		{
			pLayer3D->SetOriginalPosition(m_vPosition);
		}
		if (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::Editor && pLayer3D->Type() == SuperMapSDK::UnrealEngine::Core::Layer3DType::S3M)
		{
			Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
			pLayer3DS3MFile->SetDecodeMeshopt(true);
		}
		if (pLayer3D != nullptr && pLayer3D->GetLayerID() != -1)
		{
			return true;
		}
	}
	else if (strExt.Compare("xml") == 0)
	{
		Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strFileName, FPaths::GetPath(strFileName), strLayerName, strLayers.m_strDatasetName);
		m_bIncludeS3M = true;
		if (m_nSceneType == Flat && pLayer3D != nullptr && pLayer3D->Type() == SuperMapSDK::UnrealEngine::Core::Layer3DType::S3M)
		{
			pLayer3D->SetOriginalPosition(m_vPosition);
		}
		if (pLayer3D != nullptr && pLayer3D->GetLayerID() != -1)
		{
			return true;
		}
	}
	else if (strExt.Compare("kml") == 0 || strExt.Compare("kmz") == 0)
	{
		Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strFileName, SuperMapSDK::UnrealEngine::Core::Layer3DType::KML, false, strLayerName);
		if (pLayer3D != nullptr && pLayer3D->GetLayerID() != -1)
		{
			return true;
		}
	}
	else if (strExt.Compare("sct") == 0)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() > 0)
		{
			return false;
		}
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Add(strFileName, false);
		m_bIncludeTerrain = true;
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() > 0)
		{
			return true;
		}
	}
	else if (strExt.Compare("sci3d") == 0
		|| strExt.Compare("sci") == 0
		|| strExt.Compare("sit") == 0)
	{
		Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strFileName, SuperMapSDK::UnrealEngine::Core::Layer3DType::ImageFile, false, strLayerName);
		if (pLayer3D != nullptr && pLayer3D->GetLayerID() != -1)
		{
			if (strLayers.m_bMarkerLayer)
			{
				pLayer3D->SetMarkerLayer(true);
			}
			return true;
		}
	}
	else if (strExt.Compare("udbx") == 0 || strExt.Compare("udb") == 0)
	{
		bool bDatasourceOpened = true;
		DataSource* dataSource = nullptr;

		if (!m_bImportAsset)
		{
			dataSource = m_pDataSources->GetAt(strLayerName);
		}
		
		Gamebool openSuccess = true;
		if (dataSource == nullptr)
		{
			dataSource = new DataSource();
			openSuccess = dataSource->Open(strFileName);
			bDatasourceOpened = false;
		}
		if (!openSuccess)
		{
			return false;
		}
		if (strLayers.m_strDatasetName == "")
		{
			dataSource->Close();
			return false;
		}
		Dataset* pDataset = dataSource->GetDataset(strLayers.m_strDatasetName);
		if (pDataset == nullptr)
		{
			dataSource->Close();
			return false;
		}
		DatasetType datasetType = pDataset->GetType();
		FString name = pDataset->GetName() + "@" + strLayerName;
		if (datasetType == DatasetType::DT_Model)
		{
	//		if(m_bImportAsset)
	//		{
	//			m_bIncludeS3M = true;
	//			// 找到所有的静态的网格保存文件
	//			TArray<AActor*> arrActors;
	//			UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(strLayers.m_strDatasetName), arrActors);
	//			if (arrActors.Num() == 0)
	//			{
	//#if WITH_EDITOR
	//				Layer3DDatasetModel datasetMode;
	//				datasetMode.SetOriginalPosition(m_vPosition);
	//				datasetMode.SetDataset(pDataset);
	//				datasetMode.SetWorld(GetWorld());
	//				datasetMode.Open();
	//#endif
	//			}
	//		}
	//		else
			{
				if (!bDatasourceOpened)
				{
					m_pDataSources->SetAt(strLayerName, dataSource);
				}
				Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(name, Layer3DType::DatasetModel, false,name);
				pLayer3D->SetOriginalPosition(m_vPosition);
				Layer3DDatasetModel* pLayerDatasetModel = (Layer3DDatasetModel*)pLayer3D;
				pLayerDatasetModel->SetDataset(pDataset);
				FromJson();
			}
		}
		else if (datasetType == DatasetType::DT_POINT || datasetType == DatasetType::DT_LINE || datasetType == DatasetType::DT_REGION)
		{
			Layer3DDatasetVector* pDatasetLayer = (Layer3DDatasetVector*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(name, datasetType);
			TArray<Geometry*> arrGeometry;
			TArray<TMap<FString, FString>> arrAttributes;
			GetDatasetGeoAttribute(pDataset, arrGeometry, arrAttributes);
			pDatasetLayer->SetGeoAttributes(arrAttributes);
			pDatasetLayer->SetGeometrys(arrGeometry);
			InitialAssetResoure(name);
			dataSource->Close();
		}
		//if (datasetType == DatasetType::DT_Model && m_bImportAsset)
		//{
		//	dataSource->Close();
		//}
		dataSource = nullptr;
		return true;
	}
	return false;
}

void ASuperMap_MainActor::GetDatasetGeoAttribute(Dataset* dateset, TArray<Geometry*>& arrGeometry, TArray<TMap<FString, FString>>& arrAttributes)
{
	if (dateset == nullptr)
	{
		return;
	}
	arrGeometry = dateset->Query();
	TArray<FieldInfo> arrFieldInfos;
	dateset->GetFieldInfos(arrFieldInfos);
	for (int i = 1; i <= arrGeometry.Num(); i++)
	{
		TMap<FString, FString> attribute;
		TArray<FString> arrFieldValue = dateset->QueryAttributeById(i);
		if (arrFieldValue.Num() == 0)continue;
		for (int j = 0; j < arrFieldInfos.Num(); j++)
		{
			attribute.Add(arrFieldInfos[j].m_strName, arrFieldValue[j]);
		}
		arrAttributes.Add(attribute);
	}
}

bool ASuperMap_MainActor::AddUrlLayers(FSuperMap_LayerInfo strLayers)
{
	if (!m_bShouldTick && (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::Editor || RealspaceView::GetSingleton()->GetWorldType() == EWorldType::None))
	{
		return false;
	}
	FSuperMap_LayerInfo layerInfo = strLayers;
	int32 nLayerType = layerInfo.m_nLayerType;
	FString strUrlPath = layerInfo.m_strPath;
	int UrlLen = strUrlPath.Len();
	char cUrl = strUrlPath[UrlLen - 1];
	if (cUrl == '/' || cUrl == '\\')
	{
		strUrlPath.RemoveAt(UrlLen - 1, 1);
	}

	RealspaceView::GetSingleton()->GetSceneControl()->SetTerrainPosition(m_vPosition.X, m_vPosition.Y, m_vPosition.Z);
	Layer3D* pLayer3D = nullptr;
	FString strUrl = layerInfo.m_strPath + '/' + layerInfo.m_strDataName;
	if (nLayerType == 0)
	{
		pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strUrl, SuperMapSDK::UnrealEngine::Core::Layer3DType::S3M, layerInfo.m_strName, false);
		if (m_nSceneType == Flat && pLayer3D != nullptr)
		{
			pLayer3D->SetOriginalPosition(m_vPosition);
		}
		if (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::Editor && pLayer3D->Type() == SuperMapSDK::UnrealEngine::Core::Layer3DType::S3M)
		{
			Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
			pLayer3DS3MFile->SetDecodeMeshopt(true);
		}
		m_bIncludeS3M = true;
	}
	else if (nLayerType == 1)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() > 0)
		{
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Remove();
		}
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Add(layerInfo.m_strPath, layerInfo.m_strName);
		m_bIncludeTerrain = true;
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() > 0)
		{
			return true;
		}
	}
	else if (nLayerType == 2)
	{
		pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strUrl, SuperMapSDK::UnrealEngine::Core::Layer3DType::ImageFile, layerInfo.m_strName, false);
		if (strLayers.m_bMarkerLayer)
		{
			pLayer3D->SetMarkerLayer(true);
		}
	}
	else if (nLayerType == 3)
	{
		pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(layerInfo.m_strPath, layerInfo.m_strName, SuperMapSDK::UnrealEngine::Core::Layer3DType::ArcgisMaps, false);
	}
	else if (nLayerType == 4)
	{
		pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strUrl, SuperMapSDK::UnrealEngine::Core::Layer3DType::Map, layerInfo.m_strName, false);
	}
	else if (nLayerType == 5)
	{
		pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strUrl, SuperMapSDK::UnrealEngine::Core::Layer3DType::WMS, layerInfo.m_strName, false);
	}
	else if (nLayerType == 6)
	{
		pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strUrl, SuperMapSDK::UnrealEngine::Core::Layer3DType::WMTS, layerInfo.m_strName, false);
	}
	if (pLayer3D != nullptr && pLayer3D->GetLayerID() != -1)
	{
		return true;
	}
	return false;
}

bool ASuperMap_MainActor::AddWMTSMap(FSuperMap_LayerInfo strLayers)
{
	if (!m_bShouldTick && (RealspaceView::GetSingleton()->GetWorldType() == EWorldType::Editor || RealspaceView::GetSingleton()->GetWorldType() == EWorldType::None))
	{
		return false;
	}
	FSuperMap_LayerInfo layerInfo = strLayers;
	int32 nLayerType = layerInfo.m_nLayerType;
	if (nLayerType == 0)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() == 0)
		{
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Add(layerInfo.m_strUserName, layerInfo.m_strName);
			m_bIncludeTerrain = true;
		}
	}
	else if (nLayerType == 1)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Add(layerInfo.m_strUserName, layerInfo.m_strName, SuperMapSDK::UnrealEngine::Core::TerrainLayerType::STK);
		m_bIncludeTerrain = true;
	}
	else if (nLayerType == 2)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Add(layerInfo.m_strUserName, layerInfo.m_strName, SuperMapSDK::UnrealEngine::Core::TerrainLayerType::TIANDITU);
		m_bIncludeTerrain = true;
	}
	else if (nLayerType == 3)
	{
		SuperMapSDK::UnrealEngine::Core::ImageFormatType type = none;
		FString strPath = layerInfo.m_strUserName + "?tk=" + layerInfo.m_Key;
		if (layerInfo.m_ImageType == 0)
		{
			type = BMP;
		}
		else if (layerInfo.m_ImageType == 1)
		{
			type = JPG;
		}
		else if (layerInfo.m_ImageType == 2)
		{
			type = JPG_PNG;
		}

		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(strPath, layerInfo.m_strName, layerInfo.m_strName, layerInfo.m_DPI, type, false);
	}
	else if (nLayerType == 4)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(layerInfo.m_strName, layerInfo.m_strUserName, layerInfo.m_strPassWord, SuperMapSDK::UnrealEngine::Core::Layer3DType::BingMaps);
	}
	else if (nLayerType == 5)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Add(layerInfo.m_strName, layerInfo.m_strUserName, layerInfo.m_strPassWord, SuperMapSDK::UnrealEngine::Core::Layer3DType::OpenStreetMaps);
	}
	return true;
}

bool ASuperMap_MainActor::SetFieldAssetResoure(FString strName, FString strFieldInfo, int nAssetType)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(strName));
	if (pLayer3D != nullptr && pLayer3D->Type() == Layer3DType::DatasetVector)
	{	
		Layer3DDatasetVector* pLayerDatasetVector = (Layer3DDatasetVector*)pLayer3D;
		DataSource dataSource = DataSource();
		Dataset* pDataset = nullptr;
		bool isOpen = OpenDataset(strName, dataSource, pDataset);

		if (!isOpen || pDataset == nullptr)
		{
			return false;
		}
		pLayerDatasetVector->SetDataset(pDataset);
		TMap<FString, AssetStyle*> mapAssetStyles;
		std::map<FString, FString>::iterator itorFieldInfo = m_mapFieldInfos.begin();
		while (itorFieldInfo != m_mapFieldInfos.end())
		{
			FString strResoureName = itorFieldInfo->first;
			FString strResourePath = itorFieldInfo->second;
			StyleParam styleParam;
			styleParam.m_strAssetResoureName = TEXT("img");
			styleParam.m_strAssetResourePath = strResourePath;
			styleParam.m_fDistance = 20;
			AssetStyle* pAssetStyle = new AssetStyle(GetWorld());
			pAssetStyle->SetStyleParam(styleParam);
			FString name = strFieldInfo + " = \"" + strResoureName + "\"";
			mapAssetStyles.Add(name, pAssetStyle);
			itorFieldInfo++;
		}

		if (mapAssetStyles.Num() > 0)
		{
			pLayerDatasetVector->GetUEAssetStyle()->SetAssetStyles(mapAssetStyles);
			pLayerDatasetVector->GetUEAssetStyle()->SetMode((UEAssetStyle::Mode)nAssetType);
			pLayerDatasetVector->BuildStyle(GetWorld());
		}

		dataSource.Close();
		return true;
	}
	return false;
}

bool ASuperMap_MainActor::SetConditionAssetResoure(FString strName, TMap<FString, FString> mapConditionAssetResourePath, int nType)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(strName));
	if (pLayer3D != nullptr && pLayer3D->Type() == Layer3DType::DatasetVector)
	{
		Layer3DDatasetVector* pLayerDatasetVector = (Layer3DDatasetVector*)pLayer3D;
		DataSource dataSource = DataSource();
		Dataset* pDataset = nullptr;
		bool isOpen = OpenDataset(strName, dataSource, pDataset);

		if (!isOpen || pDataset == nullptr)
		{
			return false;
		}
		pLayerDatasetVector->SetDataset(pDataset);

		TMap<FString, AssetStyle*> mapAssetStyles;
		if (mapConditionAssetResourePath.Num() > 0)
		{
			for (auto It : mapConditionAssetResourePath)
			{
				FString strCondition = It.Key;
				FString strResourePath = It.Value;

				StyleParam styleParam;
				styleParam.m_strAssetResoureName = TEXT("img");
				styleParam.m_strAssetResourePath = strResourePath;
				styleParam.m_fDistance = 20;
				AssetStyle* pAssetStyle = new AssetStyle(GetWorld());
				pAssetStyle->SetStyleParam(styleParam);
				mapAssetStyles.Add(strCondition, pAssetStyle);

			}
			pLayerDatasetVector->GetUEAssetStyle()->SetAssetStyles(mapAssetStyles);
			pLayerDatasetVector->GetUEAssetStyle()->SetMode((UEAssetStyle::Mode)nType);
			pLayerDatasetVector->BuildStyle(GetWorld());

			dataSource.Close();
			return true;
		}
	}
	return false;
}

void ASuperMap_MainActor::AddLayers()
{
	// 球面场景加入默认球皮影像
	if (!m_bDeleteDefaultGlobalImage && m_nSceneType != 0)
	{
		FSuperMap_LayerInfo InitialLayer;
		InitialLayer.m_strName = TEXT("GlobalImage");
		InitialLayer.m_nType = 0;
		InitialLayer.m_nLayerType = 0;
		InitialLayer.m_bMarkerLayer = false;
		TArray<FString> FileNames;
		IFileManager::Get().FindFilesRecursive(FileNames, FPaths::ProjectPluginsDir().GetCharArray().GetData(), TEXT("GlobalImage.sci3d"), true, false);
		for (int i = 0; i < FileNames.Num(); i++)
		{
			InitialLayer.m_strPath = FileNames[i];
			break;
		}
		Gamebool bExitedDefaultLayer = false;
		for (auto& Item : m_arrLayers)
		{
			if (Item.m_strName == TEXT("GlobalImage"))
			{
				bExitedDefaultLayer = true;
				break;
			}
		}
		if (!bExitedDefaultLayer)
		{
			m_arrLayers.Insert(InitialLayer, 0);
		}
	}

	//AddLocalLayerFromXML(IPluginManager::Get().FindPlugin("SuperMap")->GetBaseDir() + "/FileAddress.xml");

	// 添加图层
	for (int32 i = 0; i < m_arrLayers.Num(); i++)
	{
		//本地
		if (m_arrLayers[i].m_nType == 0)
		{
			AddLocalLayers(m_arrLayers[i]);
		}
		//在线
		else if (m_arrLayers[i].m_nType == 1)
		{
			AddUrlLayers(m_arrLayers[i]);
		}
		//公共
		else if (m_arrLayers[i].m_nType == 2)
		{
			AddWMTSMap(m_arrLayers[i]);
		}
	}
}

bool ASuperMap_MainActor::RemoveLayer(FString layerName)
{
	bool result = false;

	result = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Remove(layerName);
	FString datasetName = GetDatasetName(layerName);
	if (datasetName != "" && !m_bImportAsset)
	{
		FString leftS, rightS;
		layerName.Split("@", &leftS, &rightS);
		if (m_pDataSources != nullptr)
		{
			m_pDataSources->ReleaseAt(rightS);
		}
	}
	return result;
}

bool ASuperMap_MainActor::RemoveTerrainLayer()
{
	bool result = false;
	if (RealspaceView::GetSingleton() != NULL)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() > 0)
		{
			result = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Remove();
		}
	}
	return result;
}

void ASuperMap_MainActor::RemoveLayer_Web(FString layerName)
{
	for (int i = 0; i < m_arrLayers.Num(); i++)
	{
		if (m_arrLayers[i].m_strName.Compare(layerName) == 0)
		{
			m_arrLayers.RemoveAt(i);
		}
	}
}

void ASuperMap_MainActor::ToJson()
{
		FString strLevelName = GetWorld()->GetMapName();
		FString strPrefix = GetWorld()->StreamingLevelsPrefix;
		strLevelName.RemoveFromStart(strPrefix);
		FString strFileName = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName + TEXT("/LayerInfo.json");
		FString strDirectory = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName;
		FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*strDirectory);
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->ToJson(strFileName);
		UnrealWorkspaceManager::GetSingleton()->ToJson(strFileName);
}

void ASuperMap_MainActor::DatasetMaterialToJson(FString strDataset)
{
	DataSource dataSource = DataSource();
	Dataset* pDataset = nullptr;
	bool isOpen = OpenDataset(strDataset, dataSource, pDataset);

	if (!isOpen || pDataset == nullptr)
	{
		return;
	}

	if (pDataset->GetType() == DatasetType::DT_Model)
	{
#if WITH_EDITOR
		Layer3DDatasetModel datasetMode;
		datasetMode.SetDataset(pDataset);
		datasetMode.SetWorld(GetWorld());
		datasetMode.ToJson();
#endif
	}
	dataSource.Close();
}

void ASuperMap_MainActor::LoadLayerS3MMaterialMapping(FString strPath)
{
	FString fileStr;
	FFileHelper::LoadFileToString(fileStr, *strPath);
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(fileStr);
	if (!(FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid()))
	{
		return;
	}
	TSharedPtr<FJsonValue> ScenesValue = JsonObject->TryGetField(TEXT("Scenes"));
	if (!ScenesValue.IsValid())
	{
		return;
	}
	const TArray<TSharedPtr<FJsonValue>>* arrScenes;
	if (ScenesValue->TryGetArray(arrScenes))
	{
		for (int k = 0; k <(*arrScenes).Num(); ++k)
		{
			TSharedPtr<FJsonValue> LayersValue = (*arrScenes)[k]->AsObject()->TryGetField(TEXT("Layers"));
			if (!LayersValue.IsValid())
			{
				return;
			}
			const TArray<TSharedPtr<FJsonValue>>* arrLayers;
			if (LayersValue->TryGetArray(arrLayers))
			{
				for (int i = 0; i < (*arrLayers).Num(); ++i)
				{
					FName layername = FName((*arrLayers)[i]->AsObject()->GetStringField(TEXT("LayerName")));
					Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(layername);
					if (!pLayer3D)
					{
						continue;
					}
					if (pLayer3D->Type() != S3M)
					{
						continue;
					}
					Layer3DS3MFile* pLayerS3M = (Layer3DS3MFile*)pLayer3D;
					TSharedPtr<FJsonValue> MaterialsValue = (*arrLayers)[i]->AsObject()->TryGetField(TEXT("Materials"));
					if (!MaterialsValue.IsValid())
					{
						continue;
					}
					TSharedPtr<FJsonValue> MaterialMapValue = MaterialsValue->AsObject()->TryGetField(TEXT("MaterialExportedMap"));
					if (!MaterialMapValue.IsValid())
					{
						continue;
					}
					const TArray<TSharedPtr<FJsonValue>>* arrValue;
					if (MaterialMapValue->TryGetArray(arrValue))
					{
						FString AssociateMaterial;
						FString OriginalMaterial;
						for (int j = 0; j < (*arrValue).Num(); ++j)
						{
							AssociateMaterial = (*arrValue)[j]->AsObject()->GetStringField(TEXT("AssociateMaterial"));
							OriginalMaterial = (*arrValue)[j]->AsObject()->GetStringField(TEXT("OriginalMaterial"));
							pLayerS3M->GetMaterialInfo().m_mapMaterialMappingInfo.Add(OriginalMaterial, AssociateMaterial);
						}
					}
				}
			}
		}
	}
}

void ASuperMap_MainActor::FromJson()
{
	FString strLevelName = GetWorld()->GetMapName();
	FString strPrefix = GetWorld()->StreamingLevelsPrefix;
	strLevelName.RemoveFromStart(strPrefix);
	FString strFileName = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName + TEXT("/LayerInfo.json");
	JsonFile* jsonFile = new JsonFile();
	JsonFile* jsonScenes = nullptr;
	jsonFile->LoadFromStdFile(strFileName);
	jsonFile->GetValue(FString("Scenes"), jsonScenes);
	if (jsonScenes == nullptr)
	{
		return;
	}
	Gameint nScenesCount = jsonScenes->GetArraySize();
	for (int i = 0; i < nScenesCount; i++)
	{
		JsonFile* jsonScene = jsonScenes->GetAt(i);
		if (jsonScene == nullptr)
		{
			continue;
		}
		JsonFile* jsonLayers = nullptr;
		jsonScene->GetValue(FString("Layers"), jsonLayers);
		if (jsonLayers == nullptr)
		{
			continue;
		}
		Gameint nLayersCount = jsonLayers->GetArraySize();
		for (int j = 0; j < nLayersCount; j++)
		{
			JsonFile* jsonLayer = jsonLayers->GetAt(j);
			if (jsonLayer == nullptr)
			{
				continue;
			}
			FString layerName;
			jsonLayer->GetValue(FString("LayerName"), layerName);
			Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(layerName));
			if (pLayer3D == nullptr)
			{
				continue;
			}
			FString layerType;
			jsonLayer->GetValue(FString("LayerType"), layerType);
			float fMax;
			jsonLayer->GetValue(FString("MaxObjectVisibleDistance"), fMax);
			pLayer3D->SetMaxObjectVisibleDistance(fMax);
			JsonFile* jsonMaterials = nullptr;
			//S3M===================================================
			if (layerType.Compare("S3M") == 0)
			{
				float fLod = 1;
				jsonLayer->GetValue(FString("LODRangeScale"), fLod);
				Layer3DS3MFile* pLayer3DS3MFile = (Layer3DS3MFile*)pLayer3D;
				pLayer3DS3MFile->SetLODRangeScale(pLayer3D->GetLayerID(), fLod);
				jsonLayer->GetValue(FString("Materials"), jsonMaterials);
				if (jsonMaterials == nullptr)
				{
					continue;
				}
				JsonFile* jsonMaterialMap = nullptr;
				jsonMaterials->GetValue(FString("MaterialMap"), jsonMaterialMap);
				if (jsonMaterialMap == nullptr)
				{
					delete jsonMaterials;
					jsonMaterials = nullptr;
					continue;
				}
				//缓存材质替换（子对象）
				Gameint nMaterialMapCount = jsonMaterialMap->GetArraySize();
				TMap<FString, AssociateMaterialInfo> mapMaterialNameChanges;
				for (int m = 0; m < nMaterialMapCount; m++)
				{
					JsonFile* jsonMaterial = jsonMaterialMap->GetAt(m);
					if (jsonMaterial == nullptr)
					{
						continue;
					}
					JsonFile* jsonUVOffsetAndScale = nullptr;
					FString strAssociateMaterial;
					FString strOriginalMaterial;
					jsonMaterial->GetValue(FString("AssociateMaterial"), strAssociateMaterial);
					jsonMaterial->GetValue(FString("OriginalMaterial"), strOriginalMaterial);
					jsonMaterial->GetValue(FString("UVTransformation"), jsonUVOffsetAndScale);
					if (jsonUVOffsetAndScale == nullptr)
					{
						continue;
					}
					Gamedouble OffsetU = 1, OffsetV = 1, ScaleU = 1, ScaleV = 1;
					jsonUVOffsetAndScale->GetValue(FString("OffsetU"), OffsetU);
					jsonUVOffsetAndScale->GetValue(FString("OffsetV"), OffsetV);
					jsonUVOffsetAndScale->GetValue(FString("ScaleU"), ScaleU);
					jsonUVOffsetAndScale->GetValue(FString("ScaleV"), ScaleV);
					FLinearColor uvTiling = FLinearColor(OffsetU, OffsetV, ScaleU, ScaleV);
					AssociateMaterialInfo materialInfo;
					materialInfo.AssociateMaterialPath = strAssociateMaterial;
					materialInfo.AssociateMaterialUVTiling = uvTiling;
					materialInfo.AssociateMaterialName = FPaths::GetBaseFilename(strAssociateMaterial);
					mapMaterialNameChanges.Add(strOriginalMaterial, materialInfo);
					delete jsonUVOffsetAndScale;
					jsonUVOffsetAndScale = nullptr;
					delete jsonMaterial;
					jsonMaterial = nullptr;
				}
				ObjectMaterialInfo& infoObject = pLayer3D->GetObjectMaterialInfo();
				infoObject.m_mapMaterialNameChanges = mapMaterialNameChanges;
				delete jsonMaterialMap;
				jsonMaterialMap = nullptr;
				//缓存材质替换（统一替换）
				FString strMaterialName;
				Layer3DMaterialInfo& info = pLayer3D->GetMaterialInfo();
				jsonMaterials->GetValue(FString("MaterialName"), strMaterialName);
				info.m_strMaterialName = strMaterialName;
			}
			//Dataset================================================
			if (layerType.Compare("Dataset") == 0)
			{
				FString datasetType;
				jsonLayer->GetValue(FString("DatasetType"), datasetType);
				if (datasetType.Compare("Model") == 0)
				{
					jsonLayer->GetValue(FString("Materials"), jsonMaterials);
					if (jsonMaterials == nullptr)
					{
						continue;
					}
					
					JsonFile* jsonMaterialMap = nullptr;
					jsonMaterials->GetValue(FString("MaterialMap"), jsonMaterialMap);
					if (jsonMaterialMap == nullptr)
					{
						delete jsonMaterials;
						jsonMaterials = nullptr;
						continue;
					}
					Gameint nMaterialMapCount = jsonMaterialMap->GetArraySize();
					TMap<FString, AssociateMaterialInfo> mapMaterialNameChanges;
					for (int m = 0; m < nMaterialMapCount; m++)
					{
						JsonFile* jsonMaterial = jsonMaterialMap->GetAt(m);
						if (jsonMaterial == nullptr)
						{
							continue;
						}
						JsonFile* jsonUVOffsetAndScale = nullptr;
						FString strAssociateMaterial;
						FString strOriginalMaterial;
						jsonMaterial->GetValue(FString("AssociateMaterial"), strAssociateMaterial);
						jsonMaterial->GetValue(FString("OriginalMaterial"), strOriginalMaterial);
						jsonMaterial->GetValue(FString("UVTransformation"), jsonUVOffsetAndScale);
						if (jsonUVOffsetAndScale == nullptr)
						{
							continue;
						}
						Gamedouble OffsetU = 1, OffsetV = 1, ScaleU = 1, ScaleV = 1;
						jsonUVOffsetAndScale->GetValue(FString("OffsetU"), OffsetU);
						jsonUVOffsetAndScale->GetValue(FString("OffsetV"), OffsetV);
						jsonUVOffsetAndScale->GetValue(FString("ScaleU"), ScaleU);
						jsonUVOffsetAndScale->GetValue(FString("ScaleV"), ScaleV);
						FLinearColor uvTiling = FLinearColor(OffsetU, OffsetV, ScaleU, ScaleV);
						AssociateMaterialInfo materialInfo;
						materialInfo.AssociateMaterialPath = strAssociateMaterial;
						materialInfo.AssociateMaterialUVTiling = uvTiling;
						materialInfo.AssociateMaterialName = FPaths::GetBaseFilename(strAssociateMaterial);
						mapMaterialNameChanges.Add(strOriginalMaterial, materialInfo);
						delete jsonUVOffsetAndScale;
						jsonUVOffsetAndScale = nullptr;
						delete jsonMaterial;
						jsonMaterial = nullptr;
					}
					ObjectMaterialInfo& infoObject = pLayer3D->GetObjectMaterialInfo();
					infoObject.m_mapMaterialNameChanges = mapMaterialNameChanges;
					delete jsonMaterialMap;
					jsonMaterialMap = nullptr;
				}
				if (datasetType.Compare("VectorPoint") == 0)
				{
					Gameint nLayerStyleMode = 0;
					jsonLayer->GetValue(FString("LayerStyleMode"), nLayerStyleMode);
					jsonLayer->GetValue(FString("AssetStyle"), jsonMaterials);
					if (jsonMaterials == nullptr)
					{
						continue;
					}
					Gameint nMaterialsCount = jsonMaterials->GetArraySize();
					TMap<FString, FString> mapConditionAssetResourePath;
					for (int o = 0; o < nMaterialsCount; o++)
					{
						JsonFile* jsonMaterial = jsonMaterials->GetAt(o);
						if (jsonMaterial == nullptr)
						{
							continue;
						}
						FString strResoureConditions;
						FString strResoureName;
						jsonMaterial->GetValue(FString("ResoureConditions"), strResoureConditions);
						jsonMaterial->GetValue(FString("ResoureName"), strResoureName);
						mapConditionAssetResourePath.Add(strResoureConditions, strResoureName);
						delete jsonMaterial;
						jsonMaterial = nullptr;
					}
					if (mapConditionAssetResourePath.Num() > 0)
					{
						SetConditionAssetResoure(layerName, mapConditionAssetResourePath, nLayerStyleMode);
					}
				}
			}
			if (jsonMaterials != nullptr)
			{
				delete jsonMaterials;
				jsonMaterials = nullptr;
			}
		}

		delete jsonLayers;
		jsonLayers = nullptr;

		//先删除图层，再删除场景，否则Linux下场景会崩溃
		delete jsonScene;
		jsonScene = nullptr;
	}
}

void ASuperMap_MainActor::BeginPlay()
{
	if (!RealspaceView::GetSingleton()->IsOwner(this))
	{
		RealspaceView::GetSingleton()->Destroy(false);
		RealspaceView::GetSingleton()->SetMainCameraActor(this);
	}

	Super::BeginPlay();

	UWorld* pWorld = GetWorld();
	pWorld->SetNewWorldOrigin(FIntVector(0,0,0));

	// 开启输入
	Super::EnableInput(pWorld->GetFirstPlayerController());
	// 绑定鼠标事件
	InputComponent->BindAction("LeftButton", IE_Pressed, this, &ASuperMap_MainActor::MouseLeftButtonDown);
	InputComponent->BindAction("LeftButton", IE_Released, this, &ASuperMap_MainActor::MouseLeftButtonUp);
	InputComponent->BindAction("LeftButton", IE_DoubleClick, this, &ASuperMap_MainActor::MouseLeftButtonDoubleClick);
	InputComponent->BindAction("RightButton", IE_Pressed, this, &ASuperMap_MainActor::MouseRightButtonDown);
	InputComponent->BindAction("RightButton", IE_Released, this, &ASuperMap_MainActor::MouseRightButtonUp);
	InputComponent->BindAction("MiddleButton", IE_Pressed, this, &ASuperMap_MainActor::MouseMiddleButtonDown);
	InputComponent->BindAction("MiddleButton", IE_Released, this, &ASuperMap_MainActor::MouseMiddleButtonUp);
	InputComponent->BindAxis("Wheel", this, &ASuperMap_MainActor::MouseMiddleButtonMove);

	// 设置地形插入点
	RealspaceView::GetSingleton()->GetSceneControl()->SetTerrainPosition(m_vPosition.X, m_vPosition.Y, m_vPosition.Z);

	// 设置场景类型
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->SetSceneType(SuperMapSDK::UnrealEngine::Core::SceneType(m_nSceneType));

	// 设置碰撞检测
	SetEnableCollision(m_bEnableCollision);

	// 初始化场景
	m_bInitialize = RealspaceView::GetSingleton()->Initialize(this);

	if (!m_bInitialize)
	{
		return;
	}

	if (m_pWorkspace == nullptr)
	{
		m_pWorkspace = RealspaceView::GetSingleton()->GetSceneControl()->GetWorkspace();
		m_pDataSources = m_pWorkspace->GetDataSources();
	}

	// 设置初始高度
	InitialPosition();

	// 添加图层
	AddLayers();

	InitialShowInvalidation(m_bIsShowGlobe);
	
	//InitialEnsureVisible();

	// 读取图层信息
	FromJson();

	SetSceneParamsFromJson();
}

void ASuperMap_MainActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// 默认保存一个图层信息
	//ToJson();
	//图层数据保存在XML中
	//ToXML();
	bool bQuitApplication = EndPlayReason == EEndPlayReason::Quit;
	RealspaceView::GetSingleton()->Destroy(bQuitApplication);
	RealspaceView::GetSingleton()->SetMainCameraActor(nullptr);

	m_mapFieldInfos.clear();

	std::map<FName, FSuperMap_MouseControl*>::iterator itorDatasetMouseControl = m_mapMouseControl.begin();
	while (itorDatasetMouseControl != m_mapMouseControl.end())
	{
		m_mapMouseControl.erase(itorDatasetMouseControl->first);
		itorDatasetMouseControl++;
	}
	m_mapMouseControl.clear();
	m_bEditorSaveGeoreference = false;
}

bool ASuperMap_MainActor::ShouldTickIfViewportsOnly() const
{
	return m_bShouldTick;
}

void ASuperMap_MainActor::InitialPosition()
{
	FVector vCameraLocal(0, 0, 0);
	FRotator rRotator;
	UWorld* pWorld = GetWorld();
	if (pWorld == nullptr)
	{
		return;
	}
	rRotator.Roll = 0;
	rRotator.Yaw = 0;
	rRotator.Pitch = -90;
	if (m_nSceneType == 0)
	{
		vCameraLocal.Z = 80000;
	}
	else
	{
		vCameraLocal.Z = 3000000000.0f;
		vCameraLocal -= MathEngine::m_vWorldOffset;
	}
	FVector vTemp = FVector(vCameraLocal.X, vCameraLocal.Y, vCameraLocal.Z);

	/*  编辑模式 */
	if (GetWorld()->WorldType == EWorldType::Editor)
	{
	#if WITH_EDITOR
		FViewport* pViewport = GEditor->GetActiveViewport();
		FViewportClient* pViewportClient = pViewport->GetClient();
		FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);
		pEditorViewportClient->SetViewLocation(vTemp);
		pEditorViewportClient->SetViewRotation(rRotator);
	#endif
	}
	else
	{
		pWorld->GetFirstPlayerController()->GetPawn()->SetActorLocation(vTemp);
		pWorld->GetFirstPlayerController()->SetControlRotation(rRotator);
	}
}

void ASuperMap_MainActor::SetSceneType(const int32 nSceneType)
{
	m_nSceneType = nSceneType * 2;
	if (m_bShouldTick && RealspaceView::GetSingleton()->GetWorldType() == EWorldType::Editor)
	{
		// 设置场景类型
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->SetSceneType(SuperMapSDK::UnrealEngine::Core::SceneType(m_nSceneType));
		RealspaceView::GetSingleton()->Destroy(false);
		RealspaceView::GetSingleton()->SetMainCameraActor(nullptr);
	}
}

int32 ASuperMap_MainActor::GetLayerType(FString layer, bool bBaseFile)
{
	int32 type = -1;
	if (bBaseFile)
	{
		FString strFilename = FPaths::GetBaseFilename(layer);
		if (RealspaceView::GetSingleton() != NULL)
		{
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count() > 0)
			{
				if (FPaths::GetBaseFilename(RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0)->GetName().ToString()) == strFilename)
				{
					type = 2;
				}
				else
				{
					type = 1;
				}
			}
			else
			{
				type = 1;
			}
		}
	}
	else
	{
		FString strExt = FPaths::GetExtension(layer);
		if (strExt.Compare("sct") == 0)
		{
			type = 2;
		}
		else
		{
			type = 1;
		}
	}
	return type;
}

void ASuperMap_MainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 停止运行模式，重新回到编辑模式
	if (!RealspaceView::GetSingleton()->IsInitialized())
	{
		RealspaceView::GetSingleton()->SetMainCameraActor(this);
		m_bInitialize = false;
	}


	if (!m_bInitialize)
	{
		// 设置地形插入点
		RealspaceView::GetSingleton()->GetSceneControl()->SetTerrainPosition(m_vPosition.X, m_vPosition.Y, m_vPosition.Z);
		// 设置碰撞检测

		SetEnableCollision(m_bEnableCollision);

		m_bInitialize = RealspaceView::GetSingleton()->Initialize(this);
		if (m_bInitialize)
		{
			if (m_pWorkspace == nullptr)
			{
				m_pWorkspace = RealspaceView::GetSingleton()->GetSceneControl()->GetWorkspace();
				m_pDataSources = m_pWorkspace->GetDataSources();
			}
			if (m_vGeoreferenceOrigin != FVector(0,0,0))
			{
				RealspaceView::GetSingleton()->SetGeoreferenceOrigin(m_vGeoreferenceOrigin.X, m_vGeoreferenceOrigin.Y, m_vGeoreferenceOrigin.Z);
			}

			InitialPosition();

			// 添加图层
			AddLayers();

			InitialShowInvalidation(m_bIsShowGlobe);
			
			//InitialEnsureVisible();

			// 读取图层信息
			FromJson();

			// 设置法线计算
			if (m_bComputeNormal != SuperMapSDK::m_bEnableNormal)
			{
				SetEnableComputeNormal(m_bComputeNormal);
			}
		}
	}

	if (!m_bInitialize)
	{
		return;
	}

	std::map<FName, FSuperMap_MouseControl*>::iterator itor = m_mapMouseControl.begin();
	while (itor != m_mapMouseControl.end())
	{
		FSuperMap_MouseControl* pMouseControl = itor->second;
		if (pMouseControl != nullptr)
		{
			pMouseControl->MouseRealTimeAnchor();
		}
		itor++;
	}
	
	if (!m_bShouldTick && RealspaceView::GetSingleton()->GetCameraControl()->GetEditMode() != CMEditMode::ROAM)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->OnMouseMove();
		GetPosition();
	}
	RealspaceView::GetSingleton()->SetUpdateCount(m_nUpdateCount);
	RealspaceView::GetSingleton()->Render(DeltaTime);
}

int ASuperMap_MainActor::GetTerrainLayersCount()
{
	return RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count();
}

void ASuperMap_MainActor::InitialShowInvalidation(bool bShow)
{
	if (m_nSceneType == 0)
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->SetShowInvalidation(bShow);
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0)->SetShowInvalidation(bShow);
	}
}

bool ASuperMap_MainActor::IsSecondTerrainLayer()
{
	for (int i = 0; i < m_arrLayers.Num(); i++)
	{
		if (m_arrLayers[i].m_nType == 0)
		{
			FString strFileName = m_arrLayers[i].m_strPath;
			FString strExt = FPaths::GetExtension(strFileName);
			if (strExt.Compare("sct") == 0)
			{
				return false;
			}
		}
		if (m_arrLayers[i].m_nType == 1)
		{
			FSuperMap_LayerInfo& layerInfo = m_arrLayers[i];
			int32 nLayerType = layerInfo.m_nLayerType;
			if (nLayerType == 1)
			{
				return false;
			}
		}
		if (m_arrLayers[i].m_nType == 2)
		{
			FSuperMap_LayerInfo& layerInfo = m_arrLayers[i];
			int32 nLayerType = layerInfo.m_nLayerType;
			if (nLayerType == 0 || nLayerType == 1)
			{
				return false;
			}
		}
	}
	return true;
}

void ASuperMap_MainActor::GetPosition()
{
	if (!m_bInitialize)
	{
		return;
	}
	FVector vMouse = FVector::ZeroVector;
	GetWorld()->GetFirstPlayerController()->GetMousePosition(vMouse.X, vMouse.Y);
	if (m_vMouse == vMouse || vMouse.IsNearlyZero())
	{
		return;
	}
	m_vMouse = vMouse;
	//鼠标锚点
	Vector3d vPos;
	if (m_nSceneType == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
	{
		vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(m_vMouse);
	}
	else
	{
		vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(m_vMouse, PixelToGlobeMode::Sphere);
	}
	 
	//相机高度
	FVector vRealCameraLocation;
	FRotator vCameraRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(vRealCameraLocation, vCameraRotator);
	vRealCameraLocation += FVector(GetWorld()->OriginLocation);
	if (m_nSceneType == SuperMapSDK::UnrealEngine::Core::SceneType::Globe ||
		m_nSceneType == SuperMapSDK::UnrealEngine::Core::SceneType::Ellipsoid_WGS84)
	{
		vRealCameraLocation += MathEngine::m_vWorldOffset;
		Vector3d v3dRealCameraLocation = Vector3d(vRealCameraLocation);
		v3dRealCameraLocation.MultiplyMatrix(Georeference::GetGeoreferenceToECEF());
		vRealCameraLocation = v3dRealCameraLocation.ToFVector();
	}
	float fCameraHeightByMeter;
	FVector vCurDir;
	vRealCameraLocation.ToDirectionAndLength(vCurDir, fCameraHeightByMeter);
	if (m_nSceneType == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
	{
		fCameraHeightByMeter = vRealCameraLocation.Z;
	}
	fCameraHeightByMeter *= 0.00001;
	FString cameraHeight;
	if (m_nSceneType == SuperMapSDK::UnrealEngine::Core::SceneType::Flat)
	{
		cameraHeight = FString::Printf(TEXT("%.2f km"), fCameraHeightByMeter);
		if (fCameraHeightByMeter <= 1 && fCameraHeightByMeter >= 0)
		{
			cameraHeight = FString::Printf(TEXT("%.2f m"), (fCameraHeightByMeter * 1000));
		}
		m_vRealPosition.m_strCameraHeight = cameraHeight;
		m_vRealPosition.m_strX = FString::Printf(TEXT("%.2f m"), (vPos.X / 100));
		m_vRealPosition.m_strY = FString::Printf(TEXT("%.2f m"), (vPos.Y / 100));
		m_vRealPosition.m_strZ = FString::Printf(TEXT("%.2f m"), (vPos.Z / 100));
	}
	else
	{
		vRealCameraLocation *= CM_TO_M;
		Vector3d lonLat = MathEngine::CartesianToSpherical(vRealCameraLocation.Y, vRealCameraLocation.X, vRealCameraLocation.Z);
		fCameraHeightByMeter = lonLat.Z;
		fCameraHeightByMeter /= 1000;
		FString strLon;
		FString strLat;
		if (vPos.Y > 0)
		{
			//北纬
			strLat = "N";
		}
		else
		{
			//南纬
			strLat = "S";
		}
		if (vPos.X > 0)
		{
			//东经
			strLon = "E";
		}
		else
		{
			//西经
			strLon = "W";
		}
		int nLimit = (int)abs(vPos.X);
		float fMin = (abs(vPos.X) - nLimit) * 60;
		int nMin = (int)fMin;
		float fSec = (fMin - nMin) * 60;

		int nLimitY = (int)abs(vPos.Y);
		float fMinY = (abs(vPos.Y) - nLimitY) * 60;
		int nMinY = (int)fMinY;
		float fSecY = (fMinY - nMinY) * 60;

		cameraHeight = FString::Printf(TEXT("%.2f km"), fCameraHeightByMeter);
		if (fCameraHeightByMeter <= 1 && fCameraHeightByMeter >= 0)
		{
			cameraHeight = FString::Printf(TEXT("%.2f m"), (fCameraHeightByMeter * 1000));
		}

		m_vRealPosition.m_strCameraHeight = cameraHeight;
		m_vRealPosition.m_strX = FString::Printf(TEXT("%d ° %d ′ %.2f ″"), nLimit, nMin, fSec) + strLon;
		m_vRealPosition.m_strY = FString::Printf(TEXT("%d ° %d ′ %.2f ″"), nLimitY, nMinY, fSecY) + strLat;
		if (vPos.Z > 8848 || vPos.Z < 0)
		{
			m_vRealPosition.m_strZ = FString::Printf(TEXT("%.2f"), 0.0);
		}
		else
		{
			m_vRealPosition.m_strZ = FString::Printf(TEXT("%.2f"), vPos.Z) + " m";
		}	
	}
}

FRealPosition ASuperMap_MainActor::GetLocalPosition()
{
	return m_vMousePosition;
}

FRealPosition ASuperMap_MainActor::GetRealPosition()
{
	return m_vRealPosition;
}

void ASuperMap_MainActor::InitialEnsureVisible()
{
	if (m_arrLayers.Num() > 0 && RealspaceView::GetSingleton() != NULL)
	{
		for (int i = m_arrLayers.Num() - 1; i >= 0; i--)
		{
			if (m_arrLayers[i].m_nType == 2)
			{
				break;
			}
			FString strLayerName = m_arrLayers[i].m_strName;
			FName layerName = FName(strLayerName);
			Rectangle2D rect2d;
			SuperMapSDK::UnrealEngine::Core::Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(layerName);
			SuperMapSDK::UnrealEngine::Core::TerrainLayer* pTerrainLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(layerName);
			float height = FIXED_ALTITUDE;
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
				break;
			}
			RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->EnsureVisible(rect2d, height);
			return;
		}
	}
}

void ASuperMap_MainActor::FromXML(FString strPath)
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Clear();
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Clear();
	m_arrLayers.Empty();
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->FromXML(strPath);
	int nCount = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();
	for (int i = 0; i < nCount; i++)
	{
		FSuperMap_LayerInfo layerInfo;
		Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(i);
		if (pLayer->Type() == Layer3DType::S3M)
		{
			m_bIncludeS3M = true;
		}
		layerInfo.m_strName = (pLayer->Name()).ToString();
		layerInfo.m_nLayerType = 0;
		layerInfo.m_nType = 0;
		m_arrLayers.Add(layerInfo);
	}
	int nTerrainCount = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count();
	if (nTerrainCount > 0)
	{
		FSuperMap_LayerInfo TerrainlayerInfo;
		TerrainLayer* pTerrainLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0);
		TerrainlayerInfo.m_strName = (pTerrainLayer->GetName()).ToString();
		TerrainlayerInfo.m_nLayerType = 1;
		TerrainlayerInfo.m_nType = 0;
		m_bIncludeTerrain = true;
		m_arrLayers.Add(TerrainlayerInfo);
	}
}

void ASuperMap_MainActor::ParseFile(FString strFileDir)
{
	if (m_arrFileAddress.Num() > 0)
	{
		m_arrFileAddress.Empty();
	}

	FXmlFile* pXmlFile = new FXmlFile(*strFileDir);

	if (!pXmlFile->LoadFile(*strFileDir))
	{
		return;
	}

	//get XmlFile's root node
	FXmlNode* pRootNode = pXmlFile->GetRootNode();
	const TArray<FXmlNode*> assetNode = pRootNode->GetChildrenNodes();
	for (int i = 0; i < assetNode.Num(); i++)
	{
		FString strTag2 = assetNode[i]->GetTag();
		if (strTag2 == "sml:Layers")
		{
			const TArray<FXmlNode*> LayersNode = assetNode[i]->GetChildrenNodes();
			for (int i3 = 0; i3 < LayersNode.Num(); i3++)
			{
				const TArray<FXmlNode*> LayerNode = LayersNode[i3]->GetChildrenNodes();
				for (int i4 = 0; i4 < LayerNode.Num(); i4++)
				{
					FString strTag3 = LayerNode[i4]->GetTag();
					FString layerName;
					if (strTag3 == "sml:LayerName")
					{
						layerName = LayerNode[i4]->GetContent();
					}
					if (strTag3 == "sml:DataSourceAlias" && layerName.Compare("GlobalImage") != 0)
					{
						FString FileAddress = LayerNode[i4]->GetContent();
						m_arrFileAddress.Add(FileAddress);
					}
				}
			}
		}
		else if (strTag2 == "sml:Terrains")
		{
			const TArray<FXmlNode*> TerrainsNode = assetNode[i]->GetChildrenNodes();
			for (int j = 0; j < TerrainsNode.Num(); j++)
			{
				const TArray<FXmlNode*> TerrainNode = TerrainsNode[j]->GetChildrenNodes();
				for (int j1 = 0; j1 < TerrainNode.Num(); j1++)
				{
					FString strTag4 = TerrainNode[j1]->GetTag();
					if (strTag4 == "sml:DataSourceAlias")
					{
						FString FileAddress = TerrainNode[j1]->GetContent();
						m_arrFileAddress.Add(FileAddress);
					}
				}
			}
		}
	}
}

void ASuperMap_MainActor::ToXML(FString strPath)
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->ToXML(strPath);
}

TArray<FString> ASuperMap_MainActor::GetDatasetList(FString strFileName)
{
	TArray<FString> datasetInfos;
	DataSource dataSource = DataSource();
	dataSource.Open(strFileName);
	std::vector<Dataset*> dataset = dataSource.GetDatasetList();
	if (datasetInfos.Num() > 0)
	{
		datasetInfos.Empty();
	}
	for (int i = 0; i < dataset.size(); i++)
	{
		datasetInfos.Emplace(dataset[i]->GetName());
	}
	dataSource.Close();
	return datasetInfos;
}

FString ASuperMap_MainActor::GetDatasourcePath(FString strName)
{
	for (int i = 0; i < m_arrLayers.Num(); i++)
	{
		if (m_arrLayers[i].m_strName == strName && m_arrLayers[i].m_nType == 0 && m_arrLayers[i].m_strDatasetName != "")
		{
			return m_arrLayers[i].m_strPath;
		}
	}
	return "";
}

bool ASuperMap_MainActor::SetLayerMaterial(FName strName, FString strPath)
{
	SuperMapSDK::UnrealEngine::Core::Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer != NULL)
	{
		Layer3DMaterialInfo info;
		info.m_strMaterialName = strPath;
		pLayer->SetMaterialInfo(info);
		return true;
	}
	if(strName.Compare("TrackingLayer") == 0)
	{
		TrackingLayer* pTrackingLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer();
		Layer3DMaterialInfo info;
		info.m_strMaterialName = strPath;
		pTrackingLayer->SetMaterialInfo(info);
		return true;
	}
	return false;
}

bool ASuperMap_MainActor::SetLayerObjectMaterial(FName strName, TMap<FString, FString> m_mapMaterialNameChanges)
{
	SuperMapSDK::UnrealEngine::Core::Layer3D* pLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strName);
	if (pLayer == NULL)
	{
		return false;
	}
	ObjectMaterialInfo info;
	TMap<FString, AssociateMaterialInfo> mapMaterialNameChanges;
	for (TMap<FString, FString>::TConstIterator It = m_mapMaterialNameChanges.CreateConstIterator(); It; ++It)
	{
		AssociateMaterialInfo materialInfo;
		materialInfo.AssociateMaterialPath = It->Value;
		mapMaterialNameChanges.Add(It->Key, materialInfo);
	}

	info.m_mapMaterialNameChanges = mapMaterialNameChanges;
	pLayer->SetObjectMaterialInfo(info);
	return true;
}

TArray<FString> ASuperMap_MainActor::GetFieldInfos(FString strName)
{
	TArray<FString> strFieldInfos;

	DataSource dataSource = DataSource();
	Dataset* pDataset = nullptr;
	bool isOpen = OpenDataset(strName, dataSource, pDataset);

	if (!isOpen || pDataset == nullptr)
	{
		return strFieldInfos;
	}

	TArray<FieldInfo> arrFieldInfos;
	pDataset->GetFieldInfos(arrFieldInfos);
	for (int i = 0; i < arrFieldInfos.Num(); i++)
	{
		strFieldInfos.Emplace(arrFieldInfos[i].m_strName);
	}
	dataSource.Close();

	return strFieldInfos;
}

TArray<FString> ASuperMap_MainActor::QueryField(FString strName, FString strFieldInfo)
{
	TArray<FString> arrField;
	if (strName == "" || strFieldInfo == "")
	{
		return arrField;
	}

	DataSource dataSource = DataSource();
	Dataset* pDataset = nullptr;
	bool isOpen = OpenDataset(strName, dataSource, pDataset);

	if (!isOpen || pDataset == nullptr)
	{
		return arrField;
	}

	arrField = pDataset->QueryField(strFieldInfo);
	for (int i = 0; i < arrField.Num(); i++)
	{
		m_mapFieldInfos[arrField[i]] = arrField[i];
	}

	dataSource.Close();
	return arrField;
}

void ASuperMap_MainActor::AddAssetResoure(FString nIndex, FString strAssetResourePath)
{
	m_mapFieldInfos[nIndex] = strAssetResourePath;
}

void ASuperMap_MainActor::ClearAssetResoure()
{
	m_mapFieldInfos.clear();
}

void ASuperMap_MainActor::SetEditorState(bool isTick)
{
	m_bShouldTick = isTick;
	if (!m_bShouldTick)
	{
		RealspaceView::GetSingleton()->Destroy(true);
		RealspaceView::GetSingleton()->SetMainCameraActor(nullptr);
	}
	else
	{
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->SetSceneType(SuperMapSDK::UnrealEngine::Core::SceneType(m_nSceneType));
#if WITH_EDITOR
		FViewport* pViewport = GEditor->GetActiveViewport();
		FViewportClient* pViewportClient = pViewport->GetClient();
		FEditorViewportClient* pEditorViewportClient = static_cast<FEditorViewportClient*>(pViewportClient);
		pEditorViewportClient->ViewFOV = 60;
#endif
	}
}

bool ASuperMap_MainActor::PlayingActor()
{
	return RealspaceView::GetSingleton()->GetWorldType() != EWorldType::PIE;
}

FString ASuperMap_MainActor::ModificationLayerName(FString strName,int num)
{
	FString strLayerName = strName;
	if (num > 1)
	{
		strLayerName = strName + "#" + FString::FromInt(num - 1);
	}
	for (int i = 0; i < m_arrLayers.Num(); i++)
	{
		if (strLayerName == m_arrLayers[i].m_strName)
		{
			strLayerName = strName + "#" + FString::FromInt(num);
			num++;
			strLayerName = ModificationLayerName(strName,num);
			break;
		}
	}
	return strLayerName;
}

FString ASuperMap_MainActor::GetDatasetName(FString strLayerName)
{
	FString leftS, rightS;
	bool isDataset = strLayerName.Split("@", &leftS, &rightS);
	if (isDataset)
	{
		for (int i = 0; i < m_arrLayers.Num(); i++)
		{
			if (m_arrLayers[i].m_strName == rightS && m_arrLayers[i].m_strDatasetName == leftS)
			{
				return leftS;
			}
		}
	}
	return "";
}

bool ASuperMap_MainActor::OpenDataset(FString strName, DataSource &dataSource, Dataset* &pDataset)
{
	FString strDataset, strDataSource;
	if (!strName.Split("@", &strDataset, &strDataSource))
	{
		return false;
	}
	FString strDataSourcePath = GetDatasourcePath(strDataSource);

	if (strDataSourcePath == "")
	{
		return false;
	}
	dataSource.Open(strDataSourcePath);
	pDataset = dataSource.GetDataset(strDataset);
	return true;
}

TArray<FString> ASuperMap_MainActor::GetHypsometricSettingLayers()
{
	TArray<FString> arrHypsometricSettingLayers;
	int nLayerNumber_Layer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();
	for(int n = 0; n < nLayerNumber_Layer3D; n++)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(n)->Type() == Layer3DType::S3M)
		{
			arrHypsometricSettingLayers.Add(RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(n)->Name().ToString());
		}
	}
	int nLayerNumber_TerrainLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count();
	for (int i = 0; i < nLayerNumber_TerrainLayer; i++)
	{
		arrHypsometricSettingLayers.Add(FPaths::GetBaseFilename(RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(i)->GetName().ToString()));
		
	}
	return arrHypsometricSettingLayers;
}

TArray<FString> ASuperMap_MainActor::GetS3MLayers()
{
	TArray<FString> arrS3MLayers;
	int nLayerNumber = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();
	for (int n = 0; n < nLayerNumber; n++)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(n)->Type() == Layer3DType::S3M)
		{
			arrS3MLayers.Add(RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(n)->Name().ToString());
		}
	}
	return arrS3MLayers;
}

TArray<FString> ASuperMap_MainActor::GetRestoreLayers()
{
	TArray<FString> arrLayers;
	int nLayerNumber = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->Count();
	for (int n = 0; n < nLayerNumber; n++)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(n)->Type() == Layer3DType::S3M
			|| RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(n)->Type() == Layer3DType::DatasetModel)
		{
			arrLayers.Add(RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(n)->Name().ToString());
		}
	}
	return arrLayers;
}

void ASuperMap_MainActor::SetImportAsset(bool bImportAsset)
{
	m_bImportAsset = bImportAsset;
}

FMaterialInfo ASuperMap_MainActor::GetSelectMaterialInfo()
{
	return m_struMaterialInfo;
}

void ASuperMap_MainActor::SetObjectMaterialInfo(FString LayerName, FString Key, FString materialName, FString materialPath)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(LayerName));
	if (pLayer3D != nullptr)
	{
		TMap<FString, AssociateMaterialInfo> materialInfos;
		ObjectMaterialInfo info;
		AssociateMaterialInfo materialInfo;
		materialInfo.AssociateMaterialPath = materialPath;
		materialInfo.AssociateMaterialName = materialName;
		materialInfos.Add(Key, materialInfo);
		info.m_mapMaterialNameChanges = materialInfos;
		pLayer3D->SetObjectMaterialInfo(info);
	}
	if (pLayer3D == nullptr)
	{
		TrackingLayer* pTrackingLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer();
		TMap<FString, AssociateMaterialInfo> materialInfos;
		ObjectMaterialInfo info;
		AssociateMaterialInfo materialInfo;
		materialInfo.AssociateMaterialPath = materialPath;
		materialInfo.AssociateMaterialName = materialName;
		materialInfos.Add(Key, materialInfo);
		info.m_mapMaterialNameChanges = materialInfos;
		pTrackingLayer->SetObjectMaterialInfo(info);
	}
}

void ASuperMap_MainActor::DeleteObjectMaterialInfo(FString LayerName, FString Key)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(LayerName));
	if (pLayer3D != nullptr)
	{
		pLayer3D->DeleteObjectMaterialInfo(Key);
	}
	if (pLayer3D == nullptr)
	{
		TrackingLayer* pTrackingLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer();
		pTrackingLayer->DeleteObjectMaterialInfo(Key);
	}
}

void ASuperMap_MainActor::SetEditorAction(int mode)
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction((Action3D)mode);
}

void ASuperMap_MainActor::SetUserAction(int mode)
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetUserAction((UserAction)mode);
	if (mode == UserAction::SubObjectSelect)
	{
		SelectedInfoEvent selectedInfoEvent = OnSelectedInfoCallBack;
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetSelectedInfoEventFunc(this, selectedInfoEvent);
	}
}

void ASuperMap_MainActor::SetCameraFov(float fFov)
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->SetCameraFov(fFov);
}

float ASuperMap_MainActor::GetCameraFov()
{
	return RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetCameraFov();
}

void ASuperMap_MainActor::SetGeoreferenceOrigin(float fLongitude, float fLatitude, float fAltitude)
{
	if (m_bShouldTick)
	{
		m_bEditorSaveGeoreference = true;
	}
	m_vGeoreferenceOrigin = FVector(fLongitude, fLatitude, fAltitude);
	RealspaceView::GetSingleton()->SetGeoreferenceOrigin(fLongitude, fLatitude, fAltitude);
}

FVector ASuperMap_MainActor::GetGeoreferenceOrigin()
{
	return RealspaceView::GetSingleton()->GetGeoreferenceOrigin().ToFVector();
}

void ASuperMap_MainActor::InitialAssetResoure(FString name)
{
	TArray<FString> arrField = QueryField(name, TEXT("树木种类"));
	for (int j = 0; j < arrField.Num(); j++)
	{
		SetInitialAsset(arrField[j]);
	}
	if (arrField.Num() > 0)
	{
		SetFieldAssetResoure(name, TEXT("树木种类"), 0);
	}
}

void ASuperMap_MainActor::SetInitialAsset(FString strKey)
{
	TMap<FString, FString> mapPluginModelAsset = AssetLibrary::GetSingleton()->GetUEAssetLibrary().m_mapPluginModelAsset;
	FString* strNewPluginModelAsset = mapPluginModelAsset.Find(strKey);
	if (strNewPluginModelAsset == NULL)
	{
		return;
	}
	AddAssetResoure(strKey, (*strNewPluginModelAsset));
}

void ASuperMap_MainActor::SetEnableComputeNormal(bool bEnable)
{
	m_bComputeNormal = bEnable;
	RealspaceView::GetSingleton()->SetEnableComputeNormal(bEnable);
}

void ASuperMap_MainActor::SetEnableCollision(bool bEnable)
{
	m_bEnableCollision = bEnable;
	RealspaceView::GetSingleton()->SetEnableCollision(bEnable);
}

void ASuperMap_MainActor::ExecuteBroadcast()
{
	CallEvent.Broadcast();
}

void ASuperMap_MainActor::SetStereoMode(int type)
{
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->SetStereoMode((StereoMode)type);
}

void OnSelectedInfoCallBack(void* pActor, SelectedInfo info)
{
	if (pActor == nullptr)
	{
		return;
	}
	ASuperMap_MainActor* mainActor = (ASuperMap_MainActor*)pActor;
	mainActor->m_struMaterialInfo.m_strLayerName = info.m_strLayerName;
	mainActor->m_struMaterialInfo.m_strMaterialName = info.m_strMaterialName;
	if (info.m_pMatInstanceDynamic != nullptr)
	{
		mainActor->m_struMaterialInfo.m_pSelectedMatInstance = info.m_pMatInstanceDynamic->Parent;
		FLinearColor  uv = FLinearColor(1, 1, 1, 1);
		FHashedMaterialParameterInfo parameterInfo;
		parameterInfo.Name = NameToScriptName(DEAFAULT_UV_OFFSET_AND_SCALE);
		mainActor->m_struMaterialInfo.m_bHsDeafaultParam = info.m_pMatInstanceDynamic->GetVectorParameterValue(parameterInfo, uv);
		Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(info.m_strLayerName));
		if (pLayer3D != nullptr && pLayer3D->Type() == S3M)
		{
			FString stringName = info.m_strMaterialName;
			Gameint nIndex = 0;
			if (stringName.FindLastChar(TCHAR('_'), nIndex))
			{
				Gameint nStrCount = stringName.Len() - nIndex;
				stringName.RemoveAt(nIndex, nStrCount);
			}
			ObjectMaterialInfo materialInfo = pLayer3D->GetObjectMaterialInfo();
			if (materialInfo.m_mapMaterialNameChanges.Find(stringName))
			{
				mainActor->m_struMaterialInfo.m_vUVTiling = FVector4(materialInfo.m_mapMaterialNameChanges[stringName].AssociateMaterialUVTiling);
			}
			else
			{
				mainActor->m_struMaterialInfo.m_vUVTiling = FVector4(1, 1, 1, 1);
			}
		}
		else
		{
			mainActor->m_struMaterialInfo.m_vUVTiling = FVector4(1, 1, 1, 1);
		}
	}
	mainActor->ExecuteBroadcast();
}

void ASuperMap_MainActor::ExportMaterialFromS3MLayer(FString ScpFilePath, FName LayerName)
{
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(LayerName);
	if (!pLayer3D)
	{
		return;
	}
	if (pLayer3D->Type() != Layer3DType::S3M)
	{
		return;
	}
	Gameint index;
	FString str = ScpFilePath;
	if (ScpFilePath.FindLastChar('/', index))
	{
		str.RemoveAt(index, ScpFilePath.Len() - index);
	}
	FString LayerInfoPath = str + TEXT("/MaterialPackages/LayerInfo.json");
	if (FPaths::FileExists(LayerInfoPath))
	{
		LoadLayerS3MMaterialMapping(LayerInfoPath);
	}
	Layer3DS3MFile* pLayer3DS3M = (Layer3DS3MFile*)pLayer3D;
	pLayer3DS3M->ExportUEMaterialToJson(ScpFilePath);
	pLayer3DS3M->AddRelatedPathToScpFile(LayerInfoPath, ScpFilePath);
}

void ASuperMap_MainActor::SetSceneParamsFromJson()
{
	FString strLevelName = RealspaceView::GetSingleton()->GetWorld()->GetMapName() + TEXT("/");
	FString strPrefix = RealspaceView::GetSingleton()->GetWorld()->StreamingLevelsPrefix;
	strLevelName.RemoveFromStart(strPrefix);
	FString LayerInfoPath = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName + TEXT("LayerInfo.json");
	UnrealWorkspaceManager::GetSingleton()->FromJson(LayerInfoPath);

	UnrealWorkspaceManager::SceneInfo& info = UnrealWorkspaceManager::GetSingleton()->GetSceneInfo();
	if (!info.m_bSceneInfo)
	{
		return;
	}
	if (!m_bEditorSaveGeoreference)
	{
		RealspaceView::GetSingleton()->SetGeoreferenceOrigin(info.m_vGeoreferenceOrigin.X, info.m_vGeoreferenceOrigin.Y, info.m_vGeoreferenceOrigin.Z);
		m_bEditorSaveGeoreference = true;
	}
	Vector3d cameraLocation = Georeference::TransformOriginECEFToUEReative(info.m_vCameraLocation);
	GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(cameraLocation.ToFVector());
	GetWorld()->GetFirstPlayerController()->SetControlRotation(info.m_vCameraRotator);
}

void ASuperMap_MainActor::SetSceneParams()
{
		FString strLevelName = GetWorld()->GetMapName();
		FString strPrefix = GetWorld()->StreamingLevelsPrefix;
		strLevelName.RemoveFromStart(strPrefix);
		FString strFileName = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName + TEXT("/LayerInfo.json");
		FString strDirectory = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName;
		if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*strDirectory))
		{
			FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*strDirectory);
		}
		RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->ToJson(strFileName);
		UnrealWorkspaceManager::GetSingleton()->ToJson(strFileName);
		FText message = FText::FromString(TEXT("保存成功"));
		FMessageDialog::Open(EAppMsgType::Ok, message);
}

void ASuperMap_MainActor::SetMaterialParams()
{
	FString strLevelName = GetWorld()->GetMapName();
	FString strPrefix = GetWorld()->StreamingLevelsPrefix;
	strLevelName.RemoveFromStart(strPrefix);
	FString strFileName = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName + TEXT("/LayerInfo.json");
	FString strDirectory = FPaths::ProjectContentDir() + TEXT("LayerInfo/") + strLevelName;
	FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*strDirectory);
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->ToJson(strFileName);
	UnrealWorkspaceManager::GetSingleton()->ToJson(strFileName);
	FText message = FText::FromString(TEXT("保存成功"));
	FMessageDialog::Open(EAppMsgType::Ok, message);
}

int ASuperMap_MainActor::GetDataSetType(FString layerName)
{
	int type = -1;
	Layer3D* pLayer3D = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(FName(layerName));
	if (pLayer3D != nullptr && pLayer3D->Type() == Layer3DType::DatasetVector)
	{
		Layer3DDatasetVector* pLayerDatasetVector = (Layer3DDatasetVector*)pLayer3D;
		switch (pLayerDatasetVector->GetType())
		{
		case DatasetType::DT_POINT:
			type = 1;
			break;
		case DatasetType::DT_LINE:
			type = 2;
			break;
		case DatasetType::DT_REGION:
			type = 3;
			break;
		case DatasetType::DT_Model:
			type = 4;
			break;
		}
	}
	return type;
}