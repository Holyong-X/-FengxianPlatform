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
				//! \brief 坐标系名称
				FString m_Name;
				//! \brief UGC对象指针
				Gamevoid* m_pUGprjCoordSys;
			
			public:
				//! \brief 获取坐标系名称
				//! \return m_Name
				FString Name();

				//! \brief 根据EPSG代码重设坐标系对象
				//! \param EPSG代码
				Gamebool FromEPSG(Gameint epsgCode);

				//! \brief根据xml文件重设坐标系对象
				//! \param xmlFile文件
				Gamebool FromFile(FString xmlFile);

				//! \brief 
				Gamevoid Dispose();

				//! \brief 获取UGC对象指针
				//! \return m_pUGprjCoordSys
				Gamevoid* GetHandler();
			};
		}
	}
}