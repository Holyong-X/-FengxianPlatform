#pragma once

#include "CoreMinimal.h"
#include "Core/RealspaceDLL.h"
#include "Base3D/CommonDefine.h"
#include "Core/Scene.h"
#include "Core/CameraState.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API RouteStop
			{
			public:
				RouteStop(void* pRouteStop);
				RouteStop(FString RouteStopName);
				~RouteStop();
			public:
				//! \brief 获取/设置站点名
				FString GetName();
				void SetName(FString Name);
				
				//! \brief 获取或设置从站点出发到下一站点飞行的持续时间。默认值为0，单位为秒。
				Gamedouble GetDuration();
				void SetDuration(Gamedouble dDutation);
				
				//! \brief 设置/获取站点的相机姿态
				void SetCamera(CameraState* state);
				CameraState* GetCameraState();

				//! \brief 获取站点指针
				void* GetHandler();

				//! \brief 设置进底层的不用析构
				void SetbNeedDispose(Gamebool bValue);

			private:
				void* m_pRouteStop;
				Gamebool m_bNeedDispose = false;
			};

			class SUPERMAP_API Route
			{
			public:
				Route(void* pRoute);
				~Route();
			public:
				//! \brief 获取/设置路线名
				FString GetName();
				void SetName(FString Name);

				//! \brief 设置/获取路线是否循环播放
				void SetIsFlyingLoop(Gamebool bIsFlyingLoop);
				Gamebool GetIsFlyingLoop();

				//! \brief 获取路线站点个数
				Gameint Count();

				//! \brief 获取站点索引
				Gameint IndexOf(FString strStopName);

				//! \brief 获取站点
				RouteStop GetStop(Gameint nIndex);

				//! \brief 插入站点
				Gamebool Insert(RouteStop stop, Gameint nIndex);

				//! \brief 判断是否包含站点
				Gamebool Contains(FString StopName);
				
				//! \brief 新增站点
				bool Add(RouteStop* stop);

				//! \brief 删除站点
				bool Remove(int nIndex);

				//! \brief 锁定俯仰视角
				void SetHeadingFixed(bool bSet);
				Gamebool IsHeadingFixed();

				//! \brief 锁定倾斜视角
				void SetTiltFixed(bool bSet);
				Gamebool IsTiltFixed();

			private:
				void* m_pRoute;
				void* m_pRouteStops;
			};

			class SUPERMAP_API Routes
			{
			public:
				Routes();
				Routes(void* pRoutes);
				~Routes();
			public:
				Gameint Count();

				//! \brief 获取或设置当前的路线，默认没有Route时为-1
				Gamebool SetCurrentRouteIndex(Gameint nIndex);

				Gameint GetCurrentRouteIndex();

				//! \brief 根据索引获取路线
				Route* GetRoute(Gameint nIndex);

				//! \brief 根据路线名称获取路线索引
				Gameint IndexOf(FString strRouteName);

				//! \brief  从指定的文件中导入路线集合对象
				Gamebool FromFile(FString file);

				//! \brief 将路线集合导出本地文件
				Gamebool ToFile(FString file);

				//! \brief 新建飞行路线
				Gamebool Create(FString RouteName);

				//! \brief 删除指定索引的路线
				Gamebool Remove(Gameint nIndex);

			private:
				void* m_pRoutes;
			};
		}
	}
}