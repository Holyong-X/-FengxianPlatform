// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/HypsometricSetting.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/TerrainLayers.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "SuperMap_FloodInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFloodDelegate);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_FloodInstance : public AActor
{
	GENERATED_BODY()
	
public:	
	ASuperMap_FloodInstance();
	~ASuperMap_FloodInstance();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void BuildFlood(bool bFlood);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SelectLayer(FName strLayerName);

	//! \brief ��û�ٶ�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetSpeed(float fSpeed);

	//! \brief ���õ�ǰ�߶�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetCurrentHeight(float currentHeight);

	//! \brief ��ǰ�߶�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	float GetCurrentHeight();

	//! \brief ��߸߶�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	float GetMaxHeight();

	//! \brief ��͸߶�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	float GetMinHeight();

	//! \brief ������߸߶�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetMaxHeight(float maxHeight);

	//! \brief ������͸߶�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetMinHeight(float minHeight);

	//! \brief ������ɫ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetColorTable(FString strColorTableName);

	//! \brief ���÷�����������ͣ�ж�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void SetPlayState();

	//! \brief ��ȡ������������ͣ״̬
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	bool GetPlayState();

	//! \brief ���ͼ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	void ClearLayer(float minHeight);

	//! \brief ��ȡ�ļ����µ���ɫ���ļ�·��
	//! \return ��ȡ��ɫ��洢·��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FloodInstance")
	TArray<FString> GetColorTableFiles();

public:
	UPROPERTY(BlueprintAssignable)
	FFloodDelegate CallFlood;

private:
	//! \brief ������ɫ��
	UTexture2D* ParseColorSctu(FString& strColorTableName);

	//! \brief ������ɫ��
	void ParseColorSctu(FString& strColorTableName, TArray<Gamefloat>& arrValue, TArray<Gameint>& arrColor);

	//! \brief ��ʾcolor��16������ɵ��ַ���תint	
	Gameint ColorStringToInt(FString str);
private:

	Gamefloat m_fMaxHeight;

	Gamefloat m_fMinHeight;

	Gamefloat m_fCurrentHeight;

	Gamebool m_bPlay;

	Gamefloat m_fSpeed;

	FString m_strFileColorTable;

	SuperMapSDK::UnrealEngine::Core::HypsometricSetting* m_pHypsometricSetting;

	TerrainLayers* m_pTerrainLayers;

	Layer3DS3MFile* m_pLayer3DS3MFile;
};
