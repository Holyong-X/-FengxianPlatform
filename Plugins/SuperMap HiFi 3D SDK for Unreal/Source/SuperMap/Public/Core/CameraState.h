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

				//! \brief 设置相机飞行位置
				//! \brief 相机经纬度 高度 俯仰角 水平角 旋转角
				Gamevoid SetUGCameraState(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude,
					Gamedouble dPitch, Gamedouble dHeading, Gamedouble dRoll);

				//! \brief 设置相机飞行位置
				//! \brief 相机坐标，相机旋转角
				Gamevoid SetUGCameraState(Vector3d vCameraLocation, FRotator vCameraRotator);

				//! \brief 获取相机指针
				Gamevoid* GetUGCameraHandler();

				//! \brief 获取UGC水平角
				Gamedouble GetUGCameraHeading();

				//! \brief 获取UGC俯仰角
				Gamedouble GetUGCameraTilt();

				//! \brief 获取UGC旋转角
				Gamedouble GetUGCameraRoll();

				//! \brief 获取UGC经度
				Gamedouble GetUGCameraLongitude();

				//! \brief 获取UGC纬度
				Gamedouble GetUGCameraLatitude();

				//! \brief 获取UGC高度
				Gamedouble GetUGCameraAltitude();

				//! \brief 设置视图UGC的视图矩阵
				Gamevoid SetUGCameraViewMatrix(FMatrix ueViewMatrix);

				//! \brief 相机主相机同步
				Gamevoid SyncMainCam(CameraControl* pCameraControl);

				//! \brief 设置固定视角状态（在飞行管理中，固定视角状态为false可解放俯仰、倾斜等视角操作）
				Gamevoid SetRotationOfCameraFixed(Gamebool bSet);

				//！\brief 获取固定视角状态
				Gamebool IsRotationOfCameraFixed();
			private:

				//! \brief UGC相机
				Gamevoid* m_pUGCamera;

				Gamebool m_bCreateUGCamera;

				Gamebool m_bFixedRotationOfCamera;
			};
		}
	}
}

