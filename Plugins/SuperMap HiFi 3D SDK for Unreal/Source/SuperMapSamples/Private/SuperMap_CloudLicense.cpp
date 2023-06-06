// Fill out your copyright notice in the Description page of Project Settings.


#include "SuperMap_CloudLicense.h"


ASuperMap_CloudLicense::ASuperMap_CloudLicense()
{
	m_pCloudLicense = new SuperMapSDK::UnrealEngine::Core::CloudLicense();
}

ASuperMap_CloudLicense::~ASuperMap_CloudLicense()
{
	if (m_pCloudLicense != nullptr)
	{
		delete m_pCloudLicense;
		m_pCloudLicense = nullptr;
	}
}

bool ASuperMap_CloudLicense::CloudLicense_Login(FString user, FString password)
{
	return m_pCloudLicense->Login(user, password);
}

void ASuperMap_CloudLicense::CloudLicense_Logout()
{
	m_pCloudLicense->Logout();
}

TArray<FAvailLicenses> ASuperMap_CloudLicense::CloudLicense_GetAvailLicenses()
{
	TArray<FAvailLicenses> arrAvailLicenses;
	std::vector<FString> vecAvailLicenses = m_pCloudLicense->GetAvailLicenses();
	for (int i = 0; i < (vecAvailLicenses.size() / 4); i++)
	{
		FAvailLicenses licensesData;
		licensesData.m_ID = vecAvailLicenses[4 * i];
		licensesData.m_RemainDays = vecAvailLicenses[4 * i + 1];
		licensesData.m_Version = vecAvailLicenses[4 * i + 2];
		licensesData.m_UserID = vecAvailLicenses[4 * i + 3];
		arrAvailLicenses.Emplace(licensesData);
	}
	return arrAvailLicenses;
}

int ASuperMap_CloudLicense::CloudLicense_Connect(FString id)
{
	return m_pCloudLicense->Connect(id);
}

int	ASuperMap_CloudLicense::CloudLicense_TrialLicense()
{
	return m_pCloudLicense->TrialLicense();
}

bool ASuperMap_CloudLicense::CloudLicense_LicenseVerify()
{
	return m_pCloudLicense->LicenseVerify();
}
