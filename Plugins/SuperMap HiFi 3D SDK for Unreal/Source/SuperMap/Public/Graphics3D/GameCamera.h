#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEnum.h"
#include "Component/SuperMap_CaptureSceneActor.h"
#include "Engine/World.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	typedef void (*SetViewMatrixCallBack)(Gamevoid* pCameraHandle, Gamedouble* pViewMatrix);
	typedef void (*SetProjMatrixCallBack)(Gamevoid* pCameraHandle, Gamedouble* pProjMatrix);
	typedef void(*SetCameraParamCallBack)(Gamevoid* pCameraHandle, Gamebool bOrthographic, Gamedouble& dFov, Gamedouble& dAspect, Gamedouble& dNear, double& dFar, double*& pProjMatrix);
	typedef void(*SetPositionCallBack)(Gamevoid* pCameraHandle, Gamedouble dX, Gamedouble dY, Gamedouble dZ);
	typedef void(*SetLookAtCallBack)(Gamevoid* pCameraHandle, Gamedouble dTargetX, Gamedouble dTargetY, Gamedouble dTargetZ, Gamedouble dUpX, Gamedouble dUpY, Gamedouble dUpZ);
	typedef void(*SetViewportRectCallBack)(Gamevoid* pCameraHandle, Gamedouble dX, Gamedouble dY, Gamedouble dWidth, Gamedouble dHeight);
	typedef void(*SetOrthoWindowCallBack)(Gamevoid* pCameraHandle, Gamedouble dWidth, Gamedouble dHeight);

	typedef void(*SetMainCameraViewMatrixCallBack)(Gamedouble* pViewMatrix);

	void SetViewMatrix(Gamevoid* pCameraHandle, Gamedouble* pViewMatrix);
	void SetProjMatrix(Gamevoid* pCameraHandle, Gamedouble* pProjMatrix);
	void SetCameraParam(Gamevoid* pCameraHandle, Gamebool bOrthographic, Gamedouble &dFov, Gamedouble &dAspect, Gamedouble &dNear, Gamedouble &dFar, Gamedouble*& pProjMatrix);
	void SetUGCPosition(Gamevoid* pCameraHandle, Gamedouble dX, Gamedouble dY, Gamedouble dZ);
	void SetLookAt(Gamevoid* pCameraHandle, Gamedouble dTargetX, Gamedouble dTargetY, Gamedouble dTargetZ, Gamedouble dUpX, Gamedouble dUpY, Gamedouble dUpZ);
	void SetViewportRect(Gamevoid* pCameraHandle, Gamedouble dX, Gamedouble dY, Gamedouble dWidth, Gamedouble dHeight);
	void SetOrthoWindow(Gamevoid* pCameraHandle, Gamedouble dWidth, Gamedouble dHeight);

	void SetMainCameraViewMatrix(Gamedouble* pViewMatrix);

	class SUPERMAP_API GameCamera
	{
	public:
		GameCamera(Gamebool bCreateActor = true);
		~GameCamera();
	public:
		Gameint GetHandle();

		void SetViewMatrix(Gamedouble* pViewMatrix);
		void SetProjMatrix(Gamedouble* pProjMatrix);
		void SetCameraParam(Gamebool bOrthographic, Gamedouble& dFov, Gamedouble& dAspect, Gamedouble& dNear, Gamedouble& dFar, Gamedouble*& pProjMatrix);

		void SetUGCPosition(Gamedouble dX, Gamedouble dY, Gamedouble dZ);
		void GetUGCPosition(Gamedouble& dX, Gamedouble& dY, Gamedouble& dZ);
		void SetLookAt(Gamedouble dTargetX, Gamedouble dTargetY, Gamedouble dTargetZ, Gamedouble dUpX, Gamedouble dUpY, Gamedouble dUpZ);
		void SetViewportRect(Gamedouble dX, Gamedouble dY, Gamedouble dWidth, Gamedouble dHeight);
		void SetOrthoWindow(Gamedouble dWidth, Gamedouble dHeight);
		void GetOrthoWindow(Gamedouble& dWidth, Gamedouble& dHeight);

		ASuperMap_CaptureSceneActor* GetCaptureSceneActor();

		//! \brief 获取显示队列
		void UpdateShowObject(SceneManagerType nSceneType, Gamebool bUseRectMaterial = true,Gamebool bOutputAlpha = false);

	private:
		Gameint m_nHandle;

		//! \brief (正交投影)相机窗口大小
		Gamedouble m_nOrthoWidnowWidth;
		Gamedouble m_nOrthoWidnowHeight;

		Gamedouble m_dCameraPositionX;
		Gamedouble m_dCameraPositionY;

		//! \brief 相机对象
		ASuperMap_CaptureSceneActor* m_pCameraActor;
	};

	class SUPERMAP_API GameCameraManager
	{
		// 供内部调用的接口
	public:
		GameCameraManager();
		~GameCameraManager();

		//! \brief 获取单例类
		static GameCameraManager* GetSingleton();

		//! \brief 设置场景对象
		void SetWorld(UWorld* pWorld);
		UWorld* GetWorld();

		//! \brief 销毁单例类
		static void DestorySingleton();

		//! \brief 创建相机对象
		GameCamera* Create(Gamebool bCreateActor = true);

		//! \brief 获取相机对象
		GameCamera* Get(Gameint cameraHandle);

		//! \brief 从管理器移除相机对象
		void Remove(Gameint cameraHandle);

		//! \brief 设置主相机
		void SetMainCameraViewMatrix(Gamedouble* pViewMatrix);
	private:
		//! \brief GameTexture单例
		static GameCameraManager* m_pGameCameraManager;

		//! \brief 纹理映射表
		TMap<Gameint, GameCamera*> m_mapCamera;

		//! \brief 世界场景对象
		UWorld* m_pWorld;
	};
}