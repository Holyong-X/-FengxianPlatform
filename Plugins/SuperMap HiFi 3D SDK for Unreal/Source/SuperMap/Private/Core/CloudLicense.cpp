#include "Core/CloudLicense.h"


namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{

			CloudLicense::CloudLicense()
			{
				m_bLogining = false;
			}

			CloudLicense::~CloudLicense()
			{
				Logout();
			}

			Gamebool CloudLicense::Login(FString user, FString password)
			{
				if (_Login == nullptr)
				{
					return false;
				}
				const TCHAR* cuser = *user;
				ANSICHAR* ccuser = TCHAR_TO_UTF8(cuser);
				const TCHAR* cpassword = *password;
				ANSICHAR* ccpassword = TCHAR_TO_UTF8(cpassword);
				m_bLogining = _Login(ccuser, ccpassword, 63000);
				return m_bLogining;
			}

			void CloudLicense::Logout()
			{
				if (_Logout == nullptr || !m_bLogining)
				{
					return;
				}
				_Logout();
				m_bLogining = false;
			}

			Gameint CloudLicense::Connect(FString id)
			{
				if (_Connect == nullptr || !m_bLogining)
				{
					return -1;
				}
				const TCHAR* cid = *id;
				ANSICHAR* ccid = TCHAR_TO_UTF8(cid);
				return _Connect(ccid);
			}

			std::vector<FString> CloudLicense::GetAvailLicenses()
			{
				std::vector<FString> vecAvailLicenses;
				if (!m_bLogining)
				{
					return vecAvailLicenses;
				}
				char** pAvailLicenses = nullptr;
				if (_GetLicenseNum != nullptr)
				{
					Gameint nCount = _GetLicenseNum();
					if (_GetLicenseID && _GetLicenseRemainDays && _GetLicenseVersion && _GetLicenseUserId && nCount > 0)
					{
						for (Gameint i = 0; i < nCount; i++)
						{
							vecAvailLicenses.push_back(UTF8_TO_TCHAR(_GetLicenseID(i)));
							vecAvailLicenses.push_back(UTF8_TO_TCHAR(_GetLicenseRemainDays(i)));
							vecAvailLicenses.push_back(UTF8_TO_TCHAR(_GetLicenseVersion(i)));
							vecAvailLicenses.push_back(UTF8_TO_TCHAR(_GetLicenseUserId(i)));
						}
					}
				}
				return vecAvailLicenses;
			}

			Gameint CloudLicense::TrialLicense()
			{
				if (_ConnectTrial)
				{
					return _ConnectTrial();
				}
				return -1;
			}

			Gamebool CloudLicense::LicenseVerify()
			{
				if (_LicenseVerify_GameEngine)
				{
					return _LicenseVerify_GameEngine();
				}
				return false;
			}
		}
	}
}

