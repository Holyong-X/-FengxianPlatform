// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_ContourMapInstance.h"
#include "Core/TerrainLayer.h"
#include "Core/ROCacheManager.h"
#include "XmlParser/Public/XmlParser.h"
#include "Interfaces/IPluginManager.h"
#include "HAL/FileManager.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;
ASuperMap_ContourMapInstance::ASuperMap_ContourMapInstance()
{
	m_bContourMapEnable = false;
	m_pHypsometricSetting = nullptr;
	m_pTerrainLayers = nullptr;
}

ASuperMap_ContourMapInstance::~ASuperMap_ContourMapInstance()
{
	if (m_pHypsometricSetting != nullptr)
	{
		delete m_pHypsometricSetting;
		m_pHypsometricSetting = nullptr;
	}
	m_pTerrainLayers = nullptr;
}

void ASuperMap_ContourMapInstance::BuildContourMap(bool ContourMapEnable)
{

	m_bContourMapEnable = ContourMapEnable;
	if (ContourMapEnable)
	{
		if (m_pHypsometricSetting == nullptr)
		{
			m_pHypsometricSetting = new HypsometricSetting();
			m_pHypsometricSetting->SetAnalysisMode(AnalysisMode::AM_CONTOUR_MAP);
		}
		if (m_pTerrainLayers == nullptr)
		{
			m_pTerrainLayers = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers();
		}
	}
	else if (!ContourMapEnable)
	{
		if (m_pHypsometricSetting != nullptr)
		{
			delete m_pHypsometricSetting;
			m_pHypsometricSetting = nullptr;
		}
		if (m_pTerrainLayers != nullptr)
		{
			m_pTerrainLayers->ClearHypsometricSetting();
			m_pTerrainLayers = nullptr;
		}
	}
}

void ASuperMap_ContourMapInstance::InitialContourMap(int nDisplayMode, float fCeil, float fFloor, float fMax, float fMin, float fContourInterval,
	FString strColorTableName)
{
	if (m_bContourMapEnable && m_pHypsometricSetting != nullptr)
	{
		m_pHypsometricSetting->SetDisplayMode(SuperMapSDK::UnrealEngine::Core::DisplayMode(nDisplayMode + 1));
		m_pHypsometricSetting->SetColorTableMaxKey(fCeil * 100);
		m_pHypsometricSetting->SetColorTableMinKey(fFloor * 100);
		m_pHypsometricSetting->SetMaxVisibleValue(fMax * 100);
		m_pHypsometricSetting->SetMinVisibleValue(fMin * 100);
		m_pHypsometricSetting->SetLinesInterval(fContourInterval * 100);
		m_pHypsometricSetting->SetColorTableTexture(GetColorMap(strColorTableName));
		Build();
	}
}

void ASuperMap_ContourMapInstance::ColorTableChanged(FString strColorTableName)
{
	if (m_bContourMapEnable && m_pHypsometricSetting != nullptr)
	{
		m_pHypsometricSetting->SetColorTableTexture(GetColorMap(strColorTableName));
		Build();
	}
}

void ASuperMap_ContourMapInstance::ContourIntervalModeChanged(float fContourInterval)
{
	if (m_bContourMapEnable && m_pHypsometricSetting != nullptr)
	{
		fContourInterval *= 100;
		m_pHypsometricSetting->SetLinesInterval(fContourInterval);
		Build();
	}
}

void ASuperMap_ContourMapInstance::FloorModeChanged(float fFloor)
{
	if (m_bContourMapEnable && m_pHypsometricSetting != nullptr)
	{
		fFloor *= 100;
		m_pHypsometricSetting->SetColorTableMinKey(fFloor);
		Build();
	}
}

void ASuperMap_ContourMapInstance::CeilModeChanged(float fCeil)
{
	if (m_bContourMapEnable && m_pHypsometricSetting != nullptr)
	{
		fCeil *= 100;
		m_pHypsometricSetting->SetColorTableMaxKey(fCeil);
		Build();
	}
}

void ASuperMap_ContourMapInstance::MaxVisibleValueChanged(float fMax)
{
	if (m_bContourMapEnable && m_pHypsometricSetting != nullptr)
	{
		fMax *= 100;
		m_pHypsometricSetting->SetMaxVisibleValue(fMax);
		Build();
	}
}

void ASuperMap_ContourMapInstance::MinVisibleValueChanged(float fMin)
{
	if (m_bContourMapEnable && m_pHypsometricSetting != nullptr)
	{
		fMin *= 100;
		m_pHypsometricSetting->SetMinVisibleValue(fMin);
		Build();
	}
}

void ASuperMap_ContourMapInstance::DisplayModeChanged(int nDisplayMode)
{
	if (m_bContourMapEnable && m_pHypsometricSetting != nullptr)
	{
		nDisplayMode += 1;
		m_pHypsometricSetting->SetDisplayMode(SuperMapSDK::UnrealEngine::Core::DisplayMode(nDisplayMode));
		Build();
	}
}

float ASuperMap_ContourMapInstance::GetMinHeight()
{
	SuperMapSDK::UnrealEngine::Core::TerrainLayer* pTerrainLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0);
	if (pTerrainLayer != NULL)
	{
		return pTerrainLayer->GetMinHeight();
	}
	return 20000;
}

float ASuperMap_ContourMapInstance::GetMaxHeight()
{
	SuperMapSDK::UnrealEngine::Core::TerrainLayer* pTerrainLayer = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(0);
	if (pTerrainLayer != NULL)
	{
		return pTerrainLayer->GetMaxHeight();
	}
	return 0;
}

TArray<FString> ASuperMap_ContourMapInstance::GetColorTableFiles()
{
	TArray<FString> arrFiles;
	FString strColorTableFileDir(IPluginManager::Get().FindPlugin("SuperMap")->GetBaseDir() + "/Content/ColorTable");
	const TCHAR* strPathDir = strColorTableFileDir.GetCharArray().GetData();
	IFileManager& fileManager = IFileManager::Get();
	if (fileManager.DirectoryExists(strPathDir))
	{
		FString str = "*.sctu";
		fileManager.FindFiles(arrFiles, strPathDir, *str);
	}
	return arrFiles;
}

void ASuperMap_ContourMapInstance::Build()
{
	if (m_bContourMapEnable && m_pHypsometricSetting != nullptr)
	{
		m_pTerrainLayers->SetHypsometricSetting(m_pHypsometricSetting);
	}
}

UTexture2D* ASuperMap_ContourMapInstance::GetColorMap(FString strColorTableName)
{
	strColorTableName = strColorTableName + ".sctu";
	std::map<FString, UTexture2D*>& mapColorTable = SuperMapSDK::UnrealEngine::Core::ROCacheManager::GetSingleton()->GetColorTableManager();
	std::map<FString, UTexture2D*>::iterator itorColorTable = mapColorTable.find(strColorTableName);
	if (itorColorTable == mapColorTable.end())
	{
		UTexture2D* pColorSctu = ParseColorSctu(strColorTableName);
		mapColorTable[strColorTableName] = pColorSctu;
	}
	return mapColorTable[strColorTableName];
}

void ASuperMap_ContourMapInstance::ParseColorSctu(FString& strColorTableName, TArray<Gamefloat>& arrValue, TArray<Gameint>& arrColor)
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

UTexture2D* ASuperMap_ContourMapInstance::ParseColorSctu(FString& strColorTableName)
{
	FString strColorTableFileDir(IPluginManager::Get().FindPlugin("SuperMap")->GetBaseDir() + "/Content/ColorTable/" + strColorTableName);
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

Gameint ASuperMap_ContourMapInstance::ColorStringToInt(FString str)
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
