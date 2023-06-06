#include "Core/Routes.h"
#include "Core/CameraState.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			// Routes类
			Routes::Routes()
			{
				m_pRoutes = nullptr;
			}

			Routes::Routes(void* pRoutes)
			{
				m_pRoutes = pRoutes;
			}

			Routes::~Routes()
			{
				m_pRoutes = nullptr;
			}

			Gamebool Routes::SetCurrentRouteIndex(Gameint nIndex)
			{
				return _Routes_SetCurrentRouteIndex(m_pRoutes, nIndex);
			}

			Gameint Routes::GetCurrentRouteIndex()
			{
				return _Routes_GetCurrentRouteIndex(m_pRoutes);
			}

			Route* Routes::GetRoute(Gameint nIndex)
			{
				if (nIndex >= Count())
				{
					return nullptr;
				}
				void* pRoute = nullptr;
				_Routes_GetItem(m_pRoutes, nIndex, pRoute);
				Route* route = new Route(pRoute);
				return route;
			}

			Gameint Routes::IndexOf(FString strRouteName)
			{
				const TCHAR* cRouteName = *strRouteName;
				ANSICHAR* ccRouteName = TCHAR_TO_UTF8(cRouteName);

				Gameint index = -1;
				index = _Routes_IndexOf(m_pRoutes, ccRouteName);
				return index;
			}

			Gameint Routes::Count()
			{
				return _Routes_GetCount(m_pRoutes);
			}

			Gamebool Routes::FromFile(FString file)
			{
				const TCHAR* cfile = *file;
				ANSICHAR* ccfile = TCHAR_TO_UTF8(cfile);
				Gamebool result = _Routes_FromFile(m_pRoutes, ccfile);
				return result;
			}

			//! \brief 将路线集合导出本地文件
			Gamebool Routes::ToFile(FString file)
			{
				const TCHAR* cfile = *file;
				ANSICHAR* ccfile = TCHAR_TO_UTF8(cfile);
				return _Routes_ToFile(m_pRoutes, ccfile);
			}

			//! \brief 新建飞行路线
			Gamebool Routes::Create(FString RouteName)
			{
				void* pRoute = nullptr;
				Gamebool bCreate = _Route_Create(m_pRoutes, pRoute);
				return bCreate;
			}

			//! \brief 删除指定索引的路线
			Gamebool Routes::Remove(Gameint nIndex)
			{
				return _Routes_Remove(m_pRoutes, nIndex);
			}

			// Route类
			Route::Route(void* pRoute)
			{
				m_pRoute = pRoute;
				_Route_GetStops(pRoute, m_pRouteStops);
			}

			Route::~Route()
			{
				m_pRoute = nullptr;
				m_pRouteStops = nullptr;
			}

			FString Route::GetName()
			{
				Gamechar* strName;
				_Route_GetName(m_pRoute, strName);
				return UTF8_TO_TCHAR(strName);
			}

			void Route::SetName(FString Name)
			{
				const TCHAR* cRouteName = *Name;
				ANSICHAR* ccRouteName = TCHAR_TO_UTF8(cRouteName);
				_Route_SetName(m_pRoute, ccRouteName);
			}

			Gameint Route::Count()
			{
				return _RouteStops_GetCount(m_pRouteStops);
			}

			//! \brief 获取站点索引
			Gameint Route::IndexOf(FString strStopName)
			{
				void* pStop = nullptr;
				RouteStop* pRouteStop = nullptr;
				for (Gameint i = 0; i < Count(); ++i)
				{
					_RouteStops_GetStop(m_pRouteStops, i, pStop);
					if (pStop != nullptr)
					{
						pRouteStop = new RouteStop(pStop);
						if (pRouteStop->GetName() == strStopName)
						{
							delete pRouteStop;
							pRouteStop = nullptr;
							return i;
						}
						delete pRouteStop;
						pRouteStop = nullptr;
					}	
				}
				return -1;
			}

			RouteStop Route::GetStop(Gameint nIndex)
			{
				void* pStop = nullptr;
				_RouteStops_GetStop(m_pRouteStops, nIndex, pStop);
				RouteStop routeStop = RouteStop(pStop);
				return routeStop;
			}


			//! \brief 插入站点
			Gamebool Route::Insert(RouteStop stop, Gameint nIndex)
			{
				Gamebool bInsert = _RouteStops_InsertStop(m_pRoute, stop.GetHandler(), nIndex);
				if (bInsert)
				{
					stop.SetbNeedDispose(false);
				}	
				return bInsert;
			}

			//! \brief 判断是否包含站点
			Gamebool Route::Contains(FString StopName)
			{
				void* pStop = nullptr;
				RouteStop* pRouteStop = nullptr;
				for (Gameint i = 0; i < Count(); ++i)
				{
					_RouteStops_GetStop(m_pRouteStops, i, pStop);
					if (pStop != nullptr)
					{
						pRouteStop = new RouteStop(pStop);
						if (pRouteStop->GetName() == StopName)
						{
							delete pRouteStop;
							pRouteStop = nullptr;
							return true;
						}
						delete pRouteStop;
						pRouteStop = nullptr;
					}
				}
				return false;
			}

			//! \brief 新增站点
			bool Route::Add(RouteStop* stop)
			{
				Gamebool bAdd = _RouteStops_InsertStop(m_pRouteStops, stop->GetHandler(), Count());
				if (bAdd)
				{
					stop->SetbNeedDispose(false);
				}
				return bAdd;
			}

			//! \brief 删除站点
			bool Route::Remove(int nIndex)
			{
				return _RouteStops_Remove(m_pRouteStops, nIndex);
			}


			void Route::SetIsFlyingLoop(Gamebool bIsFlyingLoop)
			{
				_Route_SetIsFlyingLoop(m_pRoute, bIsFlyingLoop);
			}

			Gamebool Route::GetIsFlyingLoop()
			{
				return _Route_GetIsFlyingLoop(m_pRoute);
			}

			void Route::SetHeadingFixed(bool bSet)
			{
				_Route_SetHeadingFixed(m_pRoute, bSet);
			}

			Gamebool Route::IsHeadingFixed()
			{
				return _Route_IsHeadingFixed(m_pRoute);
			}

			void Route::SetTiltFixed(bool bSet)
			{
				_Route_SetTiltFixed(m_pRoute, bSet);
			}

			Gamebool Route::IsTiltFixed()
			{
				return _Route_IsTiltFixed(m_pRoute);
			}

			// RouteStop类
			RouteStop::RouteStop(void* pRouteStop)
			{
				m_pRouteStop = pRouteStop;
				Gamechar* strName;
				_RouteStop_GetName(pRouteStop, strName);
				SetName(UTF8_TO_TCHAR(strName));
			}

			RouteStop::RouteStop(FString RouteStopName)
			{
				_RouteStop_Create(m_pRouteStop);
				SetName(RouteStopName);
				m_bNeedDispose = true;
			}

			RouteStop::~RouteStop()
			{
				if (m_bNeedDispose)
				{
					_RouteStop_Destory(m_pRouteStop);
				}
			}

			FString RouteStop::GetName()
			{
				Gamechar* strName;
				_RouteStop_GetName(m_pRouteStop, strName);
				return UTF8_TO_TCHAR(strName);
			}

			void RouteStop::SetName(FString Name)
			{
				const TCHAR* cRouteStopName = *Name;
				ANSICHAR* ccRouteStopName = TCHAR_TO_UTF8(cRouteStopName);
				_RouteStop_SetName(m_pRouteStop, ccRouteStopName);
			}

			Gamedouble RouteStop::GetDuration()
			{
				return _RouteStop_GetDuration(m_pRouteStop);
			}

			void RouteStop::SetDuration(Gamedouble dDutation)
			{
				_RouteStop_SetDuration(m_pRouteStop, dDutation);
			}

			CameraState* RouteStop::GetCameraState()
			{
				if (m_pRouteStop != nullptr)
				{
					CameraState* state = new CameraState();
					double dx = 0, dy = 0, dz = 0, dTilt = 0, dHeading = 0, dRoll = 0;
					_RouteStop_GetCameraState(m_pRouteStop, dx, dy, dz, dTilt, dHeading, dRoll);
					state->SetUGCameraState(dx, dy, dz, dTilt, dHeading, dRoll);
					return state;
				}
				return nullptr;
			}

			void RouteStop::SetCamera(CameraState* state)
			{
				if (state->GetUGCameraHandler() != nullptr)
				{
					_RouteStop_SetCamera(m_pRouteStop, state->GetUGCameraHandler());
				}
			}

			void* RouteStop::GetHandler()
			{
				return m_pRouteStop;
			}

			void RouteStop::SetbNeedDispose(Gamebool bValue)
			{
				m_bNeedDispose = bValue;
			}
		}
	}
}