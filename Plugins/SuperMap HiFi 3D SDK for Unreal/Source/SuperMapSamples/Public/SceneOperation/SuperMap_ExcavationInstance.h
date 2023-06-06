// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Core/Layer3DS3MFile.h"
#include "Base3D/MaterialDefine.h"
#include "Data/GeoRegion3D.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_ExcavationInstance.generated.h"

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_ExcavationInstance : public AActor, public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_ExcavationInstance();
	~ASuperMap_ExcavationInstance();

	virtual void Tick(float DeltaTime) override;

public:

	//! \brief �Ƿ���
	//! \param bflatten [in] true��ʼ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void BuildExcavation(bool bExcavation);

	//! \brief ����µĿ�����
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void AddExcavationRegion();

	//! \brief ���ڷ�ʽ��0 �� 1 �⣩
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetModifyRegionMode(int type);

	//! \brief ����ͼ��
	//! true Terreain
	//! false S3M
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SelectLayer(FName strLayerName, bool IsSelect);

	//! \brief ���
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void ClearModifyRegion();

	//! \brief �����Ƿ�ʹ������Ⱦ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetUseWeb(bool bUseWithoutWeb);

	//! \brief ����������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	TArray<FVector> GetJsonArrayStringValue(FString Descriptor, FString FieldName);

	// Web ����Ⱦ�ӿ����
	//! \brief ������бѹƽ��λ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void AddWebExcavationRegion(TArray<FVector> arrPos, FString Tag);

	//! \brief �������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetExtendHeight(float height);

	//! \brief ��������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetSideTexture(FString filePath);

	//! \brief ��������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetTopTexture(FString filePath);

	//! \brief ��ֵ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetInterpolatoryCount(int nCount);

	//! \brief �Ƿ���ͼ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void IsChartlet(bool bChartlet);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetTopMaterialPath(FString filePath);
	UFUNCTION(BlueprintCallable, Category = "SuperMap_ExcavationInstance")
	void SetSideMaterialPath(FString filePath);
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	//! \brief �����߿�
	void DrawFace();

	//! \brief ������ͼ���
	void SetStyle(GeoRegion3D* pGeoRegion3D);

	//! \brief ���Ʋ�������
	void DrawSideFace(GeoRegion3D* geoRegion3D);

	void DrawTopFace(GeoRegion3D* geoRegion3D);

	//! \brief ͼƬתTexture2D
	UTexture2D* GetTexture2DFromDiskFile(FString FilePath);

	//! \brief �㷨��
	Vector3d GetNormalVectior(Vector3d v1, Vector3d v2, Vector3d v3);

protected:
	virtual void BeginPlay() override;

private:
	//! \brief �Ƿ���п���
	Gamebool m_bExcavation;
	//! \brief ������
	TArray<GeoRegion3D*> m_arrGeoRegion3Ds;
	//! \brief �������UGC��
	TArray<Vector3d> m_listPosition;
	//! \brief ��ǰ������Ļ��Ƶ�
	TArray<FVector> m_listDrawPosition;
	//! \brief ���ڷ�ʽ
	Gameint m_nModifyRegionMode;

	TMap<FName, Layer3DS3MFile*> m_mapLayer3DS3MFiles;

	ASuperMap_ROEntityActor* m_pROEntityActor;

	ASuperMap_ROEntityActor* m_pTopFaceROEntityActor;

	Gameint m_nMouseLeftDown;

	Gamebool m_bButtonRightDown;

	Gamebool m_bButtonLeftDown;

	Gamebool m_bIsTerrainLayer;

	Gamebool m_bWithoutWeb;

	Gamefloat m_fExtendHeight;
	FString m_strSideTexture;
	UTexture2D* m_pSideTexture;
	FString m_strTopTexture;
	Gameint m_nInterpolatoryCount;
	Gamebool m_bChartlet;

	FString m_strSideMaterialPath;
	FString m_strTopMaterialPath;
};
