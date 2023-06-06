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
				//! \brief ��ȡ/����վ����
				FString GetName();
				void SetName(FString Name);
				
				//! \brief ��ȡ�����ô�վ���������һվ����еĳ���ʱ�䡣Ĭ��ֵΪ0����λΪ�롣
				Gamedouble GetDuration();
				void SetDuration(Gamedouble dDutation);
				
				//! \brief ����/��ȡվ��������̬
				void SetCamera(CameraState* state);
				CameraState* GetCameraState();

				//! \brief ��ȡվ��ָ��
				void* GetHandler();

				//! \brief ���ý��ײ�Ĳ�������
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
				//! \brief ��ȡ/����·����
				FString GetName();
				void SetName(FString Name);

				//! \brief ����/��ȡ·���Ƿ�ѭ������
				void SetIsFlyingLoop(Gamebool bIsFlyingLoop);
				Gamebool GetIsFlyingLoop();

				//! \brief ��ȡ·��վ�����
				Gameint Count();

				//! \brief ��ȡվ������
				Gameint IndexOf(FString strStopName);

				//! \brief ��ȡվ��
				RouteStop GetStop(Gameint nIndex);

				//! \brief ����վ��
				Gamebool Insert(RouteStop stop, Gameint nIndex);

				//! \brief �ж��Ƿ����վ��
				Gamebool Contains(FString StopName);
				
				//! \brief ����վ��
				bool Add(RouteStop* stop);

				//! \brief ɾ��վ��
				bool Remove(int nIndex);

				//! \brief ���������ӽ�
				void SetHeadingFixed(bool bSet);
				Gamebool IsHeadingFixed();

				//! \brief ������б�ӽ�
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

				//! \brief ��ȡ�����õ�ǰ��·�ߣ�Ĭ��û��RouteʱΪ-1
				Gamebool SetCurrentRouteIndex(Gameint nIndex);

				Gameint GetCurrentRouteIndex();

				//! \brief ����������ȡ·��
				Route* GetRoute(Gameint nIndex);

				//! \brief ����·�����ƻ�ȡ·������
				Gameint IndexOf(FString strRouteName);

				//! \brief  ��ָ�����ļ��е���·�߼��϶���
				Gamebool FromFile(FString file);

				//! \brief ��·�߼��ϵ��������ļ�
				Gamebool ToFile(FString file);

				//! \brief �½�����·��
				Gamebool Create(FString RouteName);

				//! \brief ɾ��ָ��������·��
				Gamebool Remove(Gameint nIndex);

			private:
				void* m_pRoutes;
			};
		}
	}
}