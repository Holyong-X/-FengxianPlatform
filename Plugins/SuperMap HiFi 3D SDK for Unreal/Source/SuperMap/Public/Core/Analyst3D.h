#pragma once

#include "CoreMinimal.h"
#include "ControlUE/CameraControl.h"

class UWorld;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace ControlUE 
		{
			class CameraControl;
		}
		
		namespace Core
		{
			//! \brief ��������
			enum AnalyzeMode
			{
				//! \brief ViewShed ���������
				View_Shed = 1,
				//! \brief ͨ�ӷ���
				Sight_Line = 2,
				//! \brief ����Ͷ��
				Projection_Image = 3,
				//! \brief ������
				View_Dome = 4,
				//! \brief ��ۺϷ���
				Cluster_Analyze = 5,
				//! \brief ����ͼ����
				Facade_Analyze = 6,
				//! \brief ����ͼ����
				Profile_Analyze = 7,
				//! \brief ����������
				Multi_ViewShed3D = 8
			};

			class Scene;
			class SUPERMAP_API Analyst3D
			{
			protected:
				//! \brief ������������
				AnalyzeMode m_eAnalyzeMode;

				//! \brief ����
				Scene* m_pScene;

				//! \brief UE���糡��
				UWorld* m_pWorld;

				//! \brief ��ǰ������������
				FName m_strName;

				//! \brief ��ǰ�Ƿ���·�����Ⱦ
				bool m_bNeedUpdata;

				//! \brief �������
				ControlUE::CameraControl* m_pCameraControl;

			public:
				//! \brief ��ȡ��������
				AnalyzeMode GetAnalyzeMode();

				//! \brief ִ�з���
				void Build();

				//! \brief �������
				void Clear();
			protected:

				//! \brief ��������
				virtual void DoBuild() = 0;

				//! \brief �ڲ������ͷ�
				virtual void DoClear() = 0;

				//! \brief �ü���Ⱦ
				virtual void Render() = 0;

			public:
				Analyst3D(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Analyst3D();
				friend class Core::Scene;
			};
		}
	}
}