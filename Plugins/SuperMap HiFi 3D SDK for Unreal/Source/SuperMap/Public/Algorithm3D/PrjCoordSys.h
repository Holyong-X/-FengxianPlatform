#pragma once
#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Algorithm3D
		{
			class SUPERMAP_API PrjCoordSys
			{
			public:
				PrjCoordSys();
				~PrjCoordSys();

			private:
				//! \brief ����ϵ����
				FString m_Name;
				//! \brief UGC����ָ��
				Gamevoid* m_pUGprjCoordSys;
			
			public:
				//! \brief ��ȡ����ϵ����
				//! \return m_Name
				FString Name();

				//! \brief ����EPSG������������ϵ����
				//! \param EPSG����
				Gamebool FromEPSG(Gameint epsgCode);

				//! \brief����xml�ļ���������ϵ����
				//! \param xmlFile�ļ�
				Gamebool FromFile(FString xmlFile);

				//! \brief 
				Gamevoid Dispose();

				//! \brief ��ȡUGC����ָ��
				//! \return m_pUGprjCoordSys
				Gamevoid* GetHandler();
			};
		}
	}
}