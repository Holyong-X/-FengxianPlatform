// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControlUE/CameraControl.h"
#include "Core/ROCacheManager.h"
#include "ControlUE/CameraControl.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"
using namespace SuperMapSDK::UnrealEngine::ControlUE;
/**
 * 
 */
class UWorld;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API CameraState
			{
			public:
				CameraState();
				CameraState(Gamevoid* pCamera);
				~CameraState();

				//! \brief �����������λ��
				//! \brief �����γ�� �߶� ������ ˮƽ�� ��ת��
				Gamevoid SetUGCameraState(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude,
					Gamedouble dPitch, Gamedouble dHeading, Gamedouble dRoll);

				//! \brief �����������λ��
				//! \brief ������꣬�����ת��
				Gamevoid SetUGCameraState(Vector3d vCameraLocation, FRotator vCameraRotator);

				//! \brief ��ȡ���ָ��
				Gamevoid* GetUGCameraHandler();

				//! \brief ��ȡUGCˮƽ��
				Gamedouble GetUGCameraHeading();

				//! \brief ��ȡUGC������
				Gamedouble GetUGCameraTilt();

				//! \brief ��ȡUGC��ת��
				Gamedouble GetUGCameraRoll();

				//! \brief ��ȡUGC����
				Gamedouble GetUGCameraLongitude();

				//! \brief ��ȡUGCγ��
				Gamedouble GetUGCameraLatitude();

				//! \brief ��ȡUGC�߶�
				Gamedouble GetUGCameraAltitude();

				//! \brief ������ͼUGC����ͼ����
				Gamevoid SetUGCameraViewMatrix(FMatrix ueViewMatrix);

				//! \brief ��������ͬ��
				Gamevoid SyncMainCam(CameraControl* pCameraControl);

				//! \brief ���ù̶��ӽ�״̬���ڷ��й����У��̶��ӽ�״̬Ϊfalse�ɽ�Ÿ�������б���ӽǲ�����
				Gamevoid SetRotationOfCameraFixed(Gamebool bSet);

				//��\brief ��ȡ�̶��ӽ�״̬
				Gamebool IsRotationOfCameraFixed();
			private:

				//! \brief UGC���
				Gamevoid* m_pUGCamera;

				Gamebool m_bCreateUGCamera;

				Gamebool m_bFixedRotationOfCamera;
			};
		}
	}
}

