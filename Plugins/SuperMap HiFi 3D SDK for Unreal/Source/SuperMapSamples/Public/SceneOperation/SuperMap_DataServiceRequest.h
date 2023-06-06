// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SuperMap_MainActor.h"
#include "Base3D/CommonDefine.h"
#include "Data/DataServiceRequest.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_DataServiceRequest.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDataServiceRequestDelegate);

USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FDataServiceRequestInfos {

	GENERATED_BODY()

	//! \brief ��ѯ�����ֶ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ASuperMap_DataServiceRequest")
	FString m_strFileInfo;

	//! \brief ��ѯ����ֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ASuperMap_DataServiceRequest")
	FString m_strFileValue;

};

void CallbackFunc_DataServiceRequest(void* pActor);

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_DataServiceRequest : public AActor , public FSuperMap_MouseControl
{
	GENERATED_BODY()
	
public:	
	ASuperMap_DataServiceRequest();
	~ASuperMap_DataServiceRequest();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
private:
	void MouseLeftButtonDown();

	void MouseRightButtonDown();

	void MouseRealTimeAnchor();
public:	
	//! \brief ������б���廯���Բ�ѯ
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	void BuildDataServiceRequest(bool bDataServiceRequest);

	//! \brief ���û�ȡ�ײ��̵߳��ֶ���
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	void SetBottomAltitudeFiledName(FString strBottomAltitude);

	//! \brief ���û�ȡ�߶�ֵ���ֶ���
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	void SetExtendHeightFiledName(FString strExtendHeight);

	//! \brief ������б��Ӧʸ��������
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	void SetIServiceData(FString strUrlServer, FString strDataSourceName, FString strDatasetName);

	//! \brief ��ȡ��б��������
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	TArray<FDataServiceRequestInfos> GetSelectAttribute();

	UPROPERTY(BlueprintAssignable)
	FDataServiceRequestDelegate CallDataServiceRequest;

	//! \brief ִ�жಥ
	void ExecuteBroadcast();
private:

	DataServiceRequest* m_pDataServiceRequest;

	Gamebool m_bDataServiceRequest;
};
