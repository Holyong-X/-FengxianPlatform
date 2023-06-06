#include "Algorithm3D/PrjCoordSys.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Core;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Algorithm3D
		{
			PrjCoordSys::PrjCoordSys()
			{
				m_Name.Empty();
				m_pUGprjCoordSys = nullptr;
				_PrjCoordSys_Create(m_pUGprjCoordSys);
			}

			PrjCoordSys::~PrjCoordSys()
			{
			}

			FString PrjCoordSys::Name()
			{
				return m_Name;
			}

			Gamebool  PrjCoordSys::FromEPSG(Gameint epsgCode)
			{
				Gamebool bSuccess = _PrjCoordSys_FromEPSGCode(m_pUGprjCoordSys, epsgCode);
				if (bSuccess)
				{
					Gamechar* Name;
					_PrjCoordSys_GetName(m_pUGprjCoordSys, Name);
					m_Name = UTF8_TO_TCHAR(Name);
				}
				return bSuccess;
			}

			Gamebool PrjCoordSys::FromFile(FString xmlFile)
			{
				const TCHAR* cxmlFile = *xmlFile;
				ANSICHAR* ccxmlFile = TCHAR_TO_UTF8(cxmlFile);
				Gamebool bSuccess = false;
				if (FPaths::FileExists(ccxmlFile))
				{
					bSuccess = _PrjCoordSys_FromFile(m_pUGprjCoordSys, ccxmlFile);
					if (bSuccess)
					{
						Gamechar* Name;
						_PrjCoordSys_GetName(m_pUGprjCoordSys, Name);
						m_Name = UTF8_TO_TCHAR(Name);
					}
				}
				return bSuccess;
			}

			Gamevoid PrjCoordSys::Dispose()
			{
				_PrjCoordSys_Dispose(m_pUGprjCoordSys);
			}

			Gamevoid* PrjCoordSys::GetHandler()
			{
				return m_pUGprjCoordSys;
			}
		}
	}
}