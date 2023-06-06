#pragma once
#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/RealspaceDLL.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Data/Matrix4d.h"
#include "Data/GeoModel3D.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK::UnrealEngine::Data;

class UWorld;
class ASuperMap_ROEntityActor;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class Scene;
		}

		namespace ControlUE
		{
			class CameraControl;
		}

		namespace SpatialAnalyst3D
		{
			typedef void(*ProfileGetImageEvent)(void* pActor);

			struct SUPERMAP_API ProfileGetImageCallBack
			{
			public:
				void* m_pActor;
				//�����¼�
				ProfileGetImageEvent Event;
			public:
				ProfileGetImageCallBack()
				{
					m_pActor = nullptr;
				}
				void Execute()
				{
					if (m_pActor == nullptr)
					{
						return;
					}
					Event(m_pActor);
				}
			};

			class SUPERMAP_API Profile : public Core::Analyst3D
			{
			public:
				//! \brief ���캯��
				Profile(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Profile();

			public:
				//! \brief ��������ĸ߶�
				//! \remarks ��λ����
				void SetExtendHeight(double height);
				double GetExtendHeight();

				//! \brief ���������߷�������ʼ��
				void SetStartPoint3D(Vector3d vPoint);
				Vector3d GetStartPoint3D();

				//! \brief ���������߷����Ľ�����
				void SetEndPoint3D(Vector3d vPoint);
				Vector3d GetEndPoint3D();

				//! \brief ��ȡ����ͼ�������ϵ��Ӧ����άλ��
				Vector3d GetLeftTopPosition();

				//! \brief ��ȡ����ͼ�������µ��Ӧ����άλ��
				Vector3d GetRightBottomPosition();

				UTexture2D* GetImageData();

				void CallFunc_ProfileInstance(void* pActor, ProfileGetImageEvent QAEvent);
			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief �ͷ�
				void Release();
			private:
				void OutputProfileToImageData(UTexture2D* & pTexture2D);
			private:

				// �Ƿ���
				Gamebool m_bEnable;

				void* m_pUGProfile;

				UTexture2D* m_pTexture2D;

				//�ص��¼��ṹ��
				ProfileGetImageCallBack m_ProfileGetImageEvent;
			};
		}
	}
}