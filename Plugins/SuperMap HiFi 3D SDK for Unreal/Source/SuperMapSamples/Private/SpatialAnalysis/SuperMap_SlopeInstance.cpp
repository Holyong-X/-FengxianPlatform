// Fill out your copyright notice in the Description page of Project Settings.


#include "SpatialAnalysis/SuperMap_SlopeInstance.h"
#include "ControlUE/RealspaceView.h"
#include "XmlParser/Public/XmlParser.h"
#include "Interfaces/IPluginManager.h"
#include "HAL/FileManager.h"

// Sets default values
ASuperMap_SlopeInstance::ASuperMap_SlopeInstance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pTerrainLayers = nullptr;
	m_pSlopeSetting = nullptr;
	m_strFileColorTable.Empty();
}

ASuperMap_SlopeInstance::~ASuperMap_SlopeInstance()
{
	if (m_pSlopeSetting != nullptr)
	{
		delete m_pSlopeSetting;
		m_pSlopeSetting = nullptr;
	}
	m_pTerrainLayers = nullptr;
	m_strFileColorTable.Empty();
}

// Called when the game starts or when spawned
void ASuperMap_SlopeInstance::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASuperMap_SlopeInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASuperMap_SlopeInstance::BuildSlope(bool SlopeEnable)
{
	m_bSlopeEnable = SlopeEnable;
	if (SlopeEnable)
	{
		if (m_pTerrainLayers != nullptr)
		{
			m_pTerrainLayers->ClearSlopeSetting();
			m_pTerrainLayers = nullptr;
		}
		int nCount = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->Count();
		if (nCount > 0)
		{
			m_pTerrainLayers = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers();
		}
		if (m_pSlopeSetting != nullptr)
		{
			delete m_pSlopeSetting;
			m_pSlopeSetting = nullptr;
		}
		m_pSlopeSetting = new SlopeSetting();
	}
	else
	{
		if (m_pTerrainLayers != nullptr)
		{
			m_pTerrainLayers->ClearSlopeSetting();
		}
		if (m_pSlopeSetting != nullptr)
		{
			delete m_pSlopeSetting;
		}
		m_pSlopeSetting = nullptr;
		m_pTerrainLayers = nullptr;
	}
}


void ASuperMap_SlopeInstance::EndSlope()
{
	if (m_pTerrainLayers != nullptr)
	{
		m_pTerrainLayers->ClearSlopeSetting();
	}
}

void ASuperMap_SlopeInstance::DisplayModeChanged(int nDisplayMode)
{
	if (m_bSlopeEnable)
	{
		m_pSlopeSetting->SetDisplaySytle(SlopeSetting::DisplayMode(nDisplayMode));
		m_pTerrainLayers->SetSlopeSetting(m_pSlopeSetting);
	}
}

void ASuperMap_SlopeInstance::SetArrowMove(bool isMove)
{
	if (m_bSlopeEnable)
	{
		m_pSlopeSetting->SetArrowMove(isMove);
		m_pTerrainLayers->SetSlopeSetting(m_pSlopeSetting);
	}	
}	

void ASuperMap_SlopeInstance::SetMinVisibleValue(float minValue)
{
	if (m_bSlopeEnable)
	{
		m_pSlopeSetting->SetMinVisibleValue(minValue);
		m_pTerrainLayers->SetSlopeSetting(m_pSlopeSetting);
	}	
}


void ASuperMap_SlopeInstance::SetMaxVisibleValue(float maxValue)
{
	if (m_bSlopeEnable)
	{
		m_pSlopeSetting->SetMaxVisibleValue(maxValue);
		m_pTerrainLayers->SetSlopeSetting(m_pSlopeSetting);
	}
}


TArray<FString> ASuperMap_SlopeInstance::GetColorTableFiles()
{
	TArray<FString> arrFiles;
	FString strColorTableFileDir(IPluginManager::Get().FindPlugin("SuperMap")->GetBaseDir() + "/Content/ColorTable");
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

void ASuperMap_SlopeInstance::SetColorTable(FString strColorTableName)
{
	if (m_bSlopeEnable)
	{
		if (strColorTableName.IsEmpty())
		{
			strColorTableName = m_strFileColorTable;
		}
		strColorTableName = strColorTableName + ".sctu";
		std::map<FString, UTexture2D*>& mapColorTable = ROCacheManager::GetSingleton()->GetColorTableManager();
		std::map<FString, UTexture2D*>::iterator itorColorTable = mapColorTable.find(strColorTableName);
		if (itorColorTable == mapColorTable.end())
		{
			UTexture2D* pColorSctu = ParseColorSctu(strColorTableName);
			mapColorTable[strColorTableName] = pColorSctu;
		}
		if (m_pSlopeSetting != nullptr)
		{
			m_pSlopeSetting->SetColorTableTexture(mapColorTable[strColorTableName]);
			m_pTerrainLayers->SetSlopeSetting(m_pSlopeSetting);
		}
	}
}

UTexture2D* ASuperMap_SlopeInstance::ParseColorSctu(FString& strColorTableName)
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

	uint8* pTextureData = new uint8[nWidth * nHeight * 4];

	for (Gameint i = 0; i < nHeight; i++)
	{
		Gameint color = arrColor[i];
		pTextureData[i * 4 + 3] = color >> 24;
		pTextureData[i * 4 + 0] = color >> 16 % (2 << 8);
		pTextureData[i * 4 + 1] = color >> 8 % (2 << 16);
		pTextureData[i * 4 + 2] = color % (2 << 24);
	}

	FTexture2DMipMap& pTexture2DMipMap = colorTableTexture->PlatformData->Mips[0];
	int64 nBufferSize = pTexture2DMipMap.BulkData.GetBulkDataSize();

	void* Data = pTexture2DMipMap.BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(Data, pTextureData, nBufferSize);
	pTexture2DMipMap.BulkData.Unlock();

	colorTableTexture->UpdateResource();

	delete[] pTextureData;
	pTextureData = nullptr;

	return colorTableTexture;
}

void ASuperMap_SlopeInstance::ParseColorSctu(FString& strColorTableName, TArray<Gamefloat>& arrValue, TArray<Gameint>& arrColor)
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

Gameint ASuperMap_SlopeInstance::ColorStringToInt(FString str)
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