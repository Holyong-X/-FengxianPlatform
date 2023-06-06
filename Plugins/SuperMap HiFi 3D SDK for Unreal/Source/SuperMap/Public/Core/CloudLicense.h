#pragma once

#include "CoreMinimal.h"
#include "ControlUE/CameraControl.h"
#include "Core/RealspaceDLL.h"
#include "Base3D/CommonDefine.h"
#include <vector>

class UWorld;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{

			class SUPERMAP_API CloudLicense
			{			
			public:
				CloudLicense();
				~CloudLicense();
			public:
				//! \brief ����ɵ�¼
				Gamebool Login(FString user, FString password);

				//! \brief ����ɵǳ�
				void Logout();

				//! \brief �������id
				Gameint Connect(FString id);

				//! \brief ��ȡ�������
				std::vector<FString> GetAvailLicenses();

				//! \brief �������
				Gameint TrialLicense();

				//! \brief �����֤
				Gamebool LicenseVerify();
			private:

				//��½��
				bool m_bLogining;
			};
		}
	}
}