// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/SlopeSetting.h"
#include "Core/TerrainLayers.h"
#include "Base3D/CommonDefine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_SlopeInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::Core;

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_SlopeInstance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuperMap_SlopeInstance();
	~ASuperMap_SlopeInstance();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//! \brief �Ƿ�ִ���¶��������
	//! \return trueΪ��ʼִ���¶��������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void BuildSlope(bool SlopeEnable);

	//! \brief ������ʾģʽ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void DisplayModeChanged(int nDisplayMode);

	//! \brief ���������ͷ�Ƿ��˶�
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void SetArrowMove(bool isMove);
	
	//! \brief ������ɫ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void SetColorTable(FString strColorTableName);

	//! \brief ������С�ɼ�ֵ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void SetMinVisibleValue(float minValue);

	//! \brief �������ɼ�ֵ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void SetMaxVisibleValue(float maxValue);

	//! \brief ���ͼ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	void EndSlope();

	//! \brief ��ȡ�ļ����µ���ɫ���ļ�·��
	//! \return ��ȡ��ɫ��洢·��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_SlopeInstance")
	TArray<FString> GetColorTableFiles();

private:
	//! \brief ������ɫ��
	UTexture2D* ParseColorSctu(FString& strColorTableName);

	//! \brief ������ɫ��
	void ParseColorSctu(FString& strColorTableName, TArray<Gamefloat>& arrValue, TArray<Gameint>& arrColor);

	//! \brief ��ʾcolor��16������ɵ��ַ���תint	
	Gameint ColorStringToInt(FString str);

private:
	//! \brief �Ƿ����¶��������
	Gamebool m_bSlopeEnable;

	TerrainLayers* m_pTerrainLayers;

	SlopeSetting* m_pSlopeSetting;

	FString m_strFileColorTable;
};
