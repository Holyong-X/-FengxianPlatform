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

	//! \brief 查询属性字段
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ASuperMap_DataServiceRequest")
	FString m_strFileInfo;

	//! \brief 查询属性值
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
	//! \brief 启动倾斜单体化属性查询
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	void BuildDataServiceRequest(bool bDataServiceRequest);

	//! \brief 设置获取底部高程的字段名
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	void SetBottomAltitudeFiledName(FString strBottomAltitude);

	//! \brief 设置获取高度值的字段名
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	void SetExtendHeightFiledName(FString strExtendHeight);

	//! \brief 设置倾斜对应矢量面数据
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	void SetIServiceData(FString strUrlServer, FString strDataSourceName, FString strDatasetName);

	//! \brief 获取倾斜单体数据
	UFUNCTION(BlueprintCallable, Category = "ASuperMap_DataServiceRequest")
	TArray<FDataServiceRequestInfos> GetSelectAttribute();

	UPROPERTY(BlueprintAssignable)
	FDataServiceRequestDelegate CallDataServiceRequest;

	//! \brief 执行多播
	void ExecuteBroadcast();
private:

	DataServiceRequest* m_pDataServiceRequest;

	Gamebool m_bDataServiceRequest;
};
