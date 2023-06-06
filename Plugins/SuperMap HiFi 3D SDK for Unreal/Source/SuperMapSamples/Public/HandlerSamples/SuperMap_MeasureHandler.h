// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/TerrainLayers.h"
#include "Core/SceneEditorWnd.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_MeasureHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLayerDeleteDelegate);

void OnLayerDeleteCallBack(void* pActor);
UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_MeasureHandler : public AActor
{
	GENERATED_BODY()
	
public:	

	ASuperMap_MeasureHandler();
	~ASuperMap_MeasureHandler();
public:	

	//! \brief �Ƿ�����
	//! \param bclip [in] true��ʼ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	void SetIsMeasureHandler(bool bmeasureHandler);

	//! \brief ѡ�����㷽ʽ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	void SetMeasureAction(int mode);

	//! \brief ��ý��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	float GetMeasureResult();

	//! \brief �����ȸ���
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	void HypsometricSetting(bool IsHyp, FName strLayerName);

	//! \brief ��ȡ��ǰ״̬
	UFUNCTION(BlueprintCallable, Category = "SuperMap_MeasureHandler")
	bool GetCurrentState();

	//! \brief ͼ��ɾ����Ļص�
	void LayerDeleteEvent();
private:
	//! \brief ��άͼ��ֲ���ɫ��ʾΪNone
	void Layer3DS3MFileInitSetting(SuperMapSDK::UnrealEngine::Core::HypsometricSetting* pHypsometricSetting, Layer3DS3MFile* pLayer3DS3MFile);

	//! \brief ����ͼ��ֲ���ɫ��ʾΪNone
	void TerrainLayersInitSetting(SuperMapSDK::UnrealEngine::Core::HypsometricSetting* pHypsometricSetting, TerrainLayers* pTerrainLayers);

private:

	//! \brief �Ƿ��������
	Gamebool m_bMeasureHandler;

	Gameint m_nMeasureAction;

	Gamedouble m_dResult;

	Gamebool m_bState;

	TerrainLayers* m_pTerrainLayers;

	Layer3DS3MFile* m_pLayer3DS3MFile;
};
