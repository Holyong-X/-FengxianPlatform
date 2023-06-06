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
				//! \brief 云许可登录
				Gamebool Login(FString user, FString password);

				//! \brief 云许可登出
				void Logout();

				//! \brief 输入许可id
				Gameint Connect(FString id);

				//! \brief 获取许可数据
				std::vector<FString> GetAvailLicenses();

				//! \brief 试用许可
				Gameint TrialLicense();

				//! \brief 许可认证
				Gamebool LicenseVerify();
			private:

				//登陆中
				bool m_bLogining;
			};
		}
	}
}