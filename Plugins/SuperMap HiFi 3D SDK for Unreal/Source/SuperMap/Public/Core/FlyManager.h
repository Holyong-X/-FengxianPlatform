#pragma once

#include "CoreMinimal.h"
#include "Core/RealspaceDLL.h"
#include "Base3D/CommonDefine.h"
#include "Core/Routes.h"
#include "Core/Scene.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			//! \brief ���й��䷽ʽ
			enum FlyTurningMode
			{
				//! \brief ƽ������
				Smoothly = 0,

				//! \brief ֱ�ǹ���
				Directly = 1
			};

			//! \brief ����״̬
			enum FlyStatus
			{
				//! \brief ��ǰ����״̬Ϊ�Ѿ�ֹͣ
				Stop = 0,

				//! \brief ��ǰ����״̬Ϊ��ͣ
				Pause = 1,

				//! \brief ��ǰ����״̬Ϊ���ڷ����У���������ͣ�����÷���״̬����ΪPlay�������С� 
				Play = 2
			};

			class SUPERMAP_API FlyManager
			{
			public:
				FlyManager();
				FlyManager(Scene* pScene);
				~FlyManager();
			public:

				//! \brief ��ȡ�����ñ��η��У�����ǰ����·�ߣ���Ҫ����ʱ�䣬��λΪ�롣 
				void SetDuration(Gamedouble dDuration);

				Gamedouble GetDuration();

				//! \brief ��ȡ�����ò������ʡ�������ֵ�ķ�ΧΪ0-100��������1.0ʱ�����ط���·�����ٷ��У�С��1.0ʱ����ʾ�ط���·�����ٷ��С�
				void SetPlayRate(Gamedouble dPlayRate);

				Gamedouble GetPlayRate();

				//! \brief ��ȡ�����÷��й��䷽ʽ��֧��ֱ�ǹ����ƽ�����䡣
				void SetTurningMode(FlyTurningMode eFlyTurningMode);

				FlyTurningMode GetTurningMode();

				//! \brief ��ȡ·�߼��ϡ�
				Routes* GetRoutes();

				//! \brief ��ȡ��ǰ�ķ���״̬��ֹͣ����ͣ�������У��� 
				FlyStatus GetStatus();

				//! \brief ���շ��ص�·�߼��ϣ�Routes��ָ����·�߿�ʼ���У�����������жϵķ��С� 
				void Play();

				//! \brief ֹͣ��ǰ���С�
				void Stop();

				//! \brief ��ͣ��ǰ���С� 
				void Pause();

				//! \brief ���·��й�����ڲ����㡣
				void Update();

				//! \brief ��ȡ��ǰվ������
				Gameint GetCurrentStopIndex();

				//! \brief ���õ�ǰվ��
				void SetCurrentStopIndex(Gameint nIndex);

				//! \brief �жϷ����Ƿ�ִ�վ��
				Gamebool GetArriedStatus();

				//! \brief ���ò����
				void SetOriginalPosition(Vector3d vOriginalPos);

				//! \brief ��ȡ���н���
				Gamedouble GetCurrentProgress();
			private:
				void* m_pFlyManager;

				Routes* m_pRoutes;

				Scene* m_pScene;
			};
		}
	}
}