// Fill out your copyright notice in the Description page of Project Settings.


#include "HandlerSamples/SuperMap_MeasureHandler.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Core/Handler/MeasureHandler.h"
#include "Core/HypsometricSetting.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;

ASuperMap_MeasureHandler::ASuperMap_MeasureHandler()
{
	m_bState = false;
	m_bMeasureHandler = false;
	m_dResult = 0;

	m_pTerrainLayers = nullptr;
	m_pLayer3DS3MFile = nullptr;
}

ASuperMap_MeasureHandler::~ASuperMap_MeasureHandler()
{
	if (m_pLayer3DS3MFile != nullptr)
	{
		m_pLayer3DS3MFile->ClearHypsometricSetting();
		m_pLayer3DS3MFile = nullptr;
	}
	if (m_pTerrainLayers != nullptr)
	{
		m_pTerrainLayers->ClearHypsometricSetting();
		m_pTerrainLayers = nullptr;
	}
}

void ASuperMap_MeasureHandler::SetIsMeasureHandler(bool bmeasureHandler)
{
	m_bMeasureHandler = bmeasureHandler;

	if (m_pLayer3DS3MFile != nullptr)
	{
		SuperMapSDK::UnrealEngine::Core::HypsometricSetting* pHypsometricSetting = new SuperMapSDK::UnrealEngine::Core::HypsometricSetting();
		Layer3DS3MFileInitSetting(pHypsometricSetting, m_pLayer3DS3MFile);
		delete pHypsometricSetting;
		pHypsometricSetting = nullptr;
		
	}
	if (m_pTerrainLayers != nullptr)
	{
		SuperMapSDK::UnrealEngine::Core::HypsometricSetting* pHypsometricSetting = new SuperMapSDK::UnrealEngine::Core::HypsometricSetting();
		TerrainLayersInitSetting(pHypsometricSetting, m_pTerrainLayers);
		delete pHypsometricSetting;
		pHypsometricSetting = nullptr;
	}

	if (m_bMeasureHandler)
	{
		m_dResult = 0;
		switch (m_nMeasureAction)
		{
		case 0:
			RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(MeasureDistance);
			break;
		case 1:
			RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(MeasureHorizontalDistance);
			break;
		case 2:
			RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(MeasureArea);
			break;
		case 3:
			RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(MeasureHeight);
			break;
		default:
			break;
		}
		
	}
	else
	{
		m_dResult = 0;
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->SetAction(PanSelect);
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->Release();
		m_pLayer3DS3MFile = nullptr;
		m_pTerrainLayers = nullptr;
	}
}

void ASuperMap_MeasureHandler::SetMeasureAction(int mode)
{
	m_nMeasureAction = mode;
}

float ASuperMap_MeasureHandler::GetMeasureResult()
{
	MeasureHandler* pHandler = RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->GetMeasureHandler();
	if (pHandler == nullptr)
	{
		return m_dResult;
	}
	m_bState = false;
	switch (m_nMeasureAction)
	{
	case 0:
	case 1:
	{
		m_dResult = 0;
		TArray<double> arrLength = pHandler->GetCurLength();
		for (int i = 0; i < arrLength.Num(); i++)
		{
			m_dResult += arrLength[i];
		}
		break;
	}

	case 2:
		m_dResult = 0;
		m_dResult = pHandler->GetArea();
		m_dResult /= 100;
		break;
	case 3:
		m_dResult = 0;
		m_dResult = pHandler->GetHeight();
		break;
	default:
		break;
	}
	if ((RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->GetAction() != MeasureDistance &&
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->GetAction() != MeasureHorizontalDistance &&
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->GetAction() != MeasureArea &&
		RealspaceView::GetSingleton()->GetSceneControl()->GetSceneEditorWnd()->GetAction() != MeasureHeight))
	{
		m_nMeasureAction = 4;
		m_bState = true;
	}
	return m_dResult / 100;
}

void ASuperMap_MeasureHandler::HypsometricSetting(bool bIsHyp, FName strLayerName)
{
	if (m_pLayer3DS3MFile != nullptr)
	{
		m_pLayer3DS3MFile->ClearHypsometricSetting();
		m_pLayer3DS3MFile = nullptr;
	}
	if (m_pTerrainLayers != nullptr)
	{
		m_pTerrainLayers->ClearHypsometricSetting();
		m_pTerrainLayers = nullptr;
	}

	if (bIsHyp)
	{
		SuperMapSDK::UnrealEngine::Core::HypsometricSetting* pHypsometricSetting = new SuperMapSDK::UnrealEngine::Core::HypsometricSetting();

		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName) != nullptr)
		{
			if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName)->Type() == S3M)
			{
				m_pLayer3DS3MFile = (Layer3DS3MFile*)RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetLayer3Ds()->GetAt(strLayerName);
				Layer3DS3MFileInitSetting(pHypsometricSetting, m_pLayer3DS3MFile);
			}
		}

		if (RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers()->GetAt(strLayerName) != nullptr)
		{
			m_pTerrainLayers = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTerrainLayers();
			TerrainLayersInitSetting(pHypsometricSetting, m_pTerrainLayers);
		}

		delete pHypsometricSetting;
		pHypsometricSetting = nullptr;
	}

}

bool ASuperMap_MeasureHandler::GetCurrentState()
{
	return m_bState;
}

void ASuperMap_MeasureHandler::Layer3DS3MFileInitSetting(SuperMapSDK::UnrealEngine::Core::HypsometricSetting* pHypsometricSetting, Layer3DS3MFile* pLayer3DS3MFile)
{
	if (pLayer3DS3MFile != nullptr)
	{
		pHypsometricSetting->SetDisplayMode(NONE);
		pLayer3DS3MFile->SetHypsometricSetting(pHypsometricSetting);
		pLayer3DS3MFile->SetDeleteLayerEventFunc(this, OnLayerDeleteCallBack);
	}
}

void ASuperMap_MeasureHandler::TerrainLayersInitSetting(SuperMapSDK::UnrealEngine::Core::HypsometricSetting* pHypsometricSetting, TerrainLayers* pTerrainLayers)
{
	if (pTerrainLayers != nullptr)
	{
		pHypsometricSetting->SetDisplayMode(DisplayMode::NONE);
		pTerrainLayers->SetHypsometricSetting(pHypsometricSetting);
	}
}

void OnLayerDeleteCallBack(void* pActor)
{
	if (pActor == nullptr)
	{
		return;
	}
	ASuperMap_MeasureHandler* meaureActor = (ASuperMap_MeasureHandler*)pActor;
	meaureActor->LayerDeleteEvent();
}

void ASuperMap_MeasureHandler::LayerDeleteEvent()
{
	m_pLayer3DS3MFile = nullptr;
	m_pTerrainLayers = nullptr;
}