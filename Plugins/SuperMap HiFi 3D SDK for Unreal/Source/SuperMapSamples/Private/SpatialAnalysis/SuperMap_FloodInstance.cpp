// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_FloodInstance.h"
#include "ControlUE/RealspaceView.h"
#include "XmlParser/Public/XmlParser.h"
#include "Interfaces/IPluginManager.h"
#include "HAL/FileManager.h"

ASuperMap_FloodInstance::ASuperMap_FloodInstance()
{
	PrimaryActorTick.bCanEverTick = true;
	m_pHypsometricSetting = nullptr;
	m_pTerrainLayers = nullptr;
	m_pLayer3DS3MFile = nullptr;
	m_fCurrentHeight = 0;
	m_fSpeed = 0;
	m_fMaxHeight = 0;
	m_fMinHeight = 0;
	m_strFileColorTable.Empty();
	m_bPlay = false;
}

ASuperMap_FloodInstance::~ASuperMap_FloodInstance()
{
	if (m_pTerrainLayers != nullptr)
	{
		m_pTerrainLayers->ClearHypsometricSetting();
		m_pTerrainLayers = nullptr;
	}
	if (m_pLayer3DS3MFile != nullptr)
	{
		m_pLayer3DS3MFile->ClearHypsometricSetting();
		m_pLayer3DS3MFile = nullptr;
	}
	if (m_pHypsometricSetting != nullptr)
	{
		delete m_pHypsometricSetting;
		m_pHypsometricSetting = nullptr;
	}
	m_strFileColorTable.Empty();
}


void ASuperMap_FloodInstance::BuildFlood(bool bFlood)
{
	if (bFlood)
	{
		if (m_pHypsometricSetting != nullptr)
		{
			delete m_pHypsometricSetting;
			m_pHypsometricSetting = nullptr;
		}
		m_pHypsometricSetting = new SuperMapSDK::UnrealEngine::Core::HypsometricSetting();
		m_pHypsometricSetting->SetAnalysisMode(AnalysisMode::AM_CONTOUR_MAP);
		m_pHypsometricSetting->SetDisplayMode(DisplayMode::Face);
	}
	else
	{
		if (m_pTerrainLayers != nullptr)
		{
			m_pTerrainLayers->ClearHypsometricSetting();
			m_pTerrainLayers = nullptr;
		}
		if (m_pLayer3DS3MFile != nullptr)
		{
			m_pLayer3DS3MFile->ClearHypsometricSetting();
			m_pLayer3DS3MFile = nullptr;
		}
		if (m_pHypsometricSetting != nullptr)
		{
			delete m_pHypsometricSetting;
			m_pHypsometricSetting = nullptr;
		}
	}
}

void ASuperMap_FloodInstance::SelectLayer(FName strLayerName)
{
	if (m_pTerrainLayers != nullptr)
	{
		m_pTerrainLayers->ClearHypsometricSetting();
		m_pTerrainLayers = nullptr;
	}

	if (m_pLayer3DS3MFile != nullptr)
	{
		m_pLayer3DS3MFile->ClearHypsometricSetting();
		m_pLayer3DS3MFile = nullptr;
	}

	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName) != nullptr)
	{
		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName)->Type() == S3M)
		{
			m_pLayer3DS3MFile = (Layer3DS3MFile*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName);
		}
	}

	if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(strLayerName) != nullptr)
	{
		m_pTerrainLayers = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers();
	}

	if (m_pHypsometricSetting != nullptr)
	{
		m_pHypsometricSetting->SetColorTableMaxKey((GetMaxHeight() * 100));
		m_pHypsometricSetting->SetColorTableMinKey((GetMinHeight() * 100));
		m_pHypsometricSetting->SetMinVisibleValue((GetMinHeight() * 100));
	}
}

void ASuperMap_FloodInstance::SetSpeed(float fSpeed)
{
	m_fSpeed = fSpeed;
}

float ASuperMap_FloodInstance::GetCurrentHeight()
{
	return m_fCurrentHeight;
}

void ASuperMap_FloodInstance::SetCurrentHeight(float currentHeight)
{
	m_fCurrentHeight = currentHeight;
}

float ASuperMap_FloodInstance::GetMaxHeight()
{
	Gamefloat maxHeight = 0;
	if (m_pTerrainLayers != nullptr)
	{
		maxHeight = m_pTerrainLayers->GetAt(0)->GetMaxHeight();	
	}
	if (m_pLayer3DS3MFile != nullptr)
	{
		maxHeight = m_pLayer3DS3MFile->GetMaxDataValue();
	}
	return maxHeight;
}
	

float ASuperMap_FloodInstance::GetMinHeight()
{
	Gamefloat minHeight = 0;
	if(m_pTerrainLayers != nullptr)
	{
		minHeight = m_pTerrainLayers->GetAt(0)->GetMinHeight();	
	}
	if (m_pLayer3DS3MFile != nullptr)
	{
		minHeight = m_pLayer3DS3MFile->GetMinDataValue();
	}
	m_fCurrentHeight = m_fCurrentHeight > minHeight ? m_fCurrentHeight : minHeight;
	return minHeight;
}

void ASuperMap_FloodInstance::SetMaxHeight(float maxHeight)
{
	m_fMaxHeight = maxHeight * 100;
}

void ASuperMap_FloodInstance::SetMinHeight(float minHeight)
{
	m_fMinHeight = minHeight * 100;
	if (m_pHypsometricSetting != nullptr)
	{
		m_pHypsometricSetting->SetMinVisibleValue(m_fMinHeight);
	}
}

void ASuperMap_FloodInstance::SetPlayState()
{
	m_bPlay = !m_bPlay;
}

bool ASuperMap_FloodInstance::GetPlayState()
{
	return m_bPlay;
}

void ASuperMap_FloodInstance::ClearLayer(float minHeight)
{
	SetMinHeight(minHeight);
	if (m_pTerrainLayers != nullptr)
	{
		m_pTerrainLayers->ClearHypsometricSetting();
	}
	else if (m_pLayer3DS3MFile != nullptr)
	{
		m_pLayer3DS3MFile->ClearHypsometricSetting();
	}
	m_fCurrentHeight = minHeight;
	m_bPlay = false;
}

// Called every frame
void ASuperMap_FloodInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!m_bPlay)
	{
		return;
	}
	if (m_fCurrentHeight*100 < m_fMaxHeight && m_pTerrainLayers != nullptr)
	{
		m_pHypsometricSetting->SetMaxVisibleValue(m_fCurrentHeight * 100);
		m_pTerrainLayers->SetHypsometricSetting(m_pHypsometricSetting);
		m_fCurrentHeight += m_fSpeed * DeltaTime;
	}
	else if (m_fCurrentHeight * 100 < m_fMaxHeight && m_pLayer3DS3MFile != nullptr)
	{
		m_pHypsometricSetting->SetMaxVisibleValue(m_fCurrentHeight * 100);
		m_pLayer3DS3MFile->SetHypsometricSetting(m_pHypsometricSetting);
		m_fCurrentHeight += m_fSpeed * DeltaTime;
	}
	CallFlood.Broadcast();
}

TArray<FString> ASuperMap_FloodInstance::GetColorTableFiles()
{
	TArray<FString> arrFiles;
	FString strColorTableFileDir(IPluginManager::Get().FindPlugin("SuperMap")->GetBaseDir() + "/Content/ColorTable/Flood");
	const TCHAR* strPathDir = strColorTableFileDir.GetCharArray().GetData();
	IFileManager& fileManager = IFileManager::Get();
	if (fileManager.DirectoryExists(strPathDir))
	{
		FString str = "*.sctu";
		fileManager.FindFiles(arrFiles, strPathDir, *str);
		if (arrFiles.Num() > 0)
		{
			m_strFileColorTable = FPaths::GetBaseFilename(arrFiles[0]);
		}
	}
	return arrFiles;
}

void ASuperMap_FloodInstance::SetColorTable(FString strColorTableName)
{
	if (strColorTableName.IsEmpty())
	{
		strColorTableName = m_strFileColorTable;
	}
	strColorTableName = strColorTableName + ".sctu";
	std::map<FString, UTexture2D*>& mapColorTable = SuperMapSDK::UnrealEngine::Core::ROCacheManager::GetSingleton()->GetColorTableManager();
	std::map<FString, UTexture2D*>::iterator itorColorTable = mapColorTable.find(strColorTableName);
	if (itorColorTable == mapColorTable.end())
	{
		UTexture2D* pColorSctu = ParseColorSctu(strColorTableName);
		mapColorTable[strColorTableName] = pColorSctu;
	}
	if (m_pHypsometricSetting != nullptr)
	{
		m_pHypsometricSetting->SetColorTableTexture(mapColorTable[strColorTableName]);
	}
}

UTexture2D* ASuperMap_FloodInstance::ParseColorSctu(FString& strColorTableName)
{
	FString strColorTableFileDir(IPluginManager::Get().FindPlugin("SuperMap")->GetBaseDir() + "/Content/ColorTable/Flood/" + strColorTableName);
	UTexture2D* colorTableTexture = nullptr;

	TArray<Gamefloat> arrValue;
	TArray<Gameint> arrColor;

	ParseColorSctu(strColorTableFileDir, arrValue, arrColor);

	Gameint nWidth = 1;
	Gameint nHeight = arrColor.Num();
	colorTableTexture = UTexture2D::CreateTransient(nWidth, nHeight, EPixelFormat::PF_R8G8B8A8);
	colorTableTexture->AddressX = TextureAddress::TA_Clamp;
	colorTableTexture->AddressY = TextureAddress::TA_Clamp;
	colorTableTexture->AddToRoot();

	Gameuint8* pTextureData = new Gameuint8[nWidth * nHeight * 4];

	for (Gameint i = 0; i < nHeight; i++)
	{
		Gameint color = arrColor[i];
		pTextureData[i * 4 + 3] = color >> 24;
		pTextureData[i * 4 + 0] = color >> 16 % (2 << 8);
		pTextureData[i * 4 + 1] = color >> 8 % (2 << 16);
		pTextureData[i * 4 + 2] = color % (2 << 24);
	}

	FTexture2DMipMap& pTexture2DMipMap = colorTableTexture->PlatformData->Mips[0];
	Gamelong nBufferSize = pTexture2DMipMap.BulkData.GetBulkDataSize();

	void* Data = pTexture2DMipMap.BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(Data, pTextureData, nBufferSize);
	pTexture2DMipMap.BulkData.Unlock();

	colorTableTexture->UpdateResource();

	delete[] pTextureData;
	pTextureData = nullptr;

	return colorTableTexture;
}

void ASuperMap_FloodInstance::ParseColorSctu(FString& strColorTableName, TArray<Gamefloat>& arrValue, TArray<Gameint>& arrColor)
{
	Gameint nItemCount;
	//create XmlFile object;
	FXmlFile* pXmlFile = new FXmlFile(*strColorTableName);
	//get XmlFile's root node
	FXmlNode* pRootNode = pXmlFile->GetRootNode();
	const TArray<FXmlNode*> assetNode = pRootNode->GetChildrenNodes();
	for (Gameint i = 0; i < assetNode.Num(); i++)
	{
		const TArray<FXmlNode*> contentNode = assetNode[i]->GetChildrenNodes();
		for (Gameint j = 0; j < contentNode.Num(); j++)
		{


			FString strTag = contentNode[j]->GetTag();
			if (strTag == "ItemCount")
			{
				FString strItemCount = contentNode[j]->GetContent();
				nItemCount = FCString::Atoi(*strItemCount);
			}

			if (strTag == "Item")
			{
				TArray<FXmlAttribute> arrAttri = contentNode[j]->GetAttributes();
				//arrAttri = contentNode[j]->GetAttribute();
				for (Gameint k = 0; k < arrAttri.Num(); k++)
				{
					FString strAttriTag = arrAttri[k].GetTag();
					if (strAttriTag == "value")
					{
						FString strValue = arrAttri[k].GetValue();
						Gamefloat fValue = FCString::Atof(*strValue);
						arrValue.Add(fValue);
					}

					if (strAttriTag == "color")
					{
						FString strValue = arrAttri[k].GetValue();
						Gameint nValue = ColorStringToInt(strValue);
						arrColor.Add(nValue);
					}
				}
			}
		}
	}
}

Gameint ASuperMap_FloodInstance::ColorStringToInt(FString str)
{
	Gameint out = 0;
	std::string strTemp = TCHAR_TO_ANSI(*str);
	Gameint p = strTemp.length();
	for (Gameint i = 0; i < p; i++)
	{
		Gamechar ch = strTemp[i];
		Gameint value = 0;
		if (Gameint(ch) >= Gameint('a'))
		{
			value = Gameint(ch) - Gameint('a') + 10;
		}
		else if (Gameint(ch) >= Gameint('A'))
		{
			value = Gameint(ch) - Gameint('A') + 10;
		}
		else if (Gameint(ch) >= Gameint('0'))
		{
			value = Gameint(ch) - Gameint('0');
		}
		out = out * 16 + value;
	}
	return out;
}