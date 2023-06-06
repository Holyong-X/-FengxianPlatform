// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core/CloudLicense.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperMap_CloudLicense.generated.h"


USTRUCT(BlueprintType)
struct SUPERMAPSAMPLES_API FAvailLicenses {

	GENERATED_BODY()

	//! \brief 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_CloudLicense")
	FString m_ID;

	//! \brief remaindays
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_CloudLicense")
	FString m_RemainDays;

	//! \brief version
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_CloudLicense")
	FString m_Version;

	//! \brief userid
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SuperMap_CloudLicense")
	FString m_UserID;
};

UCLASS()
class SUPERMAPSAMPLES_API ASuperMap_CloudLicense : public AActor
{
	GENERATED_BODY()
	
public:	

	ASuperMap_CloudLicense();
	~ASuperMap_CloudLicense();

public:
	UFUNCTION(BlueprintCallable, Category = "SuperMap_CloudLicense")
	bool CloudLicense_Login(FString user, FString password);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_CloudLicense")
	void CloudLicense_Logout();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_CloudLicense")
	TArray<FAvailLicenses> CloudLicense_GetAvailLicenses();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_CloudLicense")
	int	CloudLicense_Connect(FString id);

	UFUNCTION(BlueprintCallable, Category = "SuperMap_CloudLicense")
	int	CloudLicense_TrialLicense();

	UFUNCTION(BlueprintCallable, Category = "SuperMap_CloudLicense")
	bool CloudLicense_LicenseVerify();
private:

	SuperMapSDK::UnrealEngine::Core::CloudLicense* m_pCloudLicense;

};
