// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/Layer3D.h"
#include "Data/GeoRegion3D.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"
#include "SuperMap_FlattenInstance.generated.h"

using namespace SuperMapSDK::UnrealEngine::Core;

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_FlattenInstance : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_FlattenInstance();
	~ASuperMap_FlattenInstance();

	//! \brief �Ƿ���бѹƽ
	//! \param bflatten [in] true��ʼ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlattenInstance")
	void SetIsFlatten(bool bflatten, FName strLayerName);

	// Web ����Ⱦ�ӿ����
	//! \brief ������бѹƽ��λ��
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlattenInstance")
	void AddFlattenRegion(TArray<FVector> arrPos, FString Tag);

	//! \brief �����Ƿ�ʹ������Ⱦ
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlattenInstance")
	void SetUseWeb(bool bUseWithoutWeb);

	//! \brief ����������
	UFUNCTION(BlueprintCallable, Category = "SuperMap_FlattenInstance")
	TArray<FVector> GetJsonArrayStringValue(FString Descriptor, FString FieldName);

private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();

	void DrawFlatten();
private:

	//! \brief �Ƿ����ѹƽ
	Gamebool m_bFlatten;

	Gamebool m_bWithoutWeb;

	Gamebool m_bButtonRightDown;

	Gameint m_nMouseLeftDown;

	Layer3DS3MFile* m_pLayer3DS3MFile;

	SuperMapSDK::UnrealEngine::Data::GeoRegion3D* m_pGeoRegion3D;

	TArray<Vector3d> m_listPosition;

	TArray<FVector> m_listDrawPosition;

	ASuperMap_ROEntityActor *m_pROEntityActor;

};
