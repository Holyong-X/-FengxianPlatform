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

		//! \brief ��ȡ��ʾ����
		void UpdateShowObject(SceneManagerType nSceneType, Gamebool bUseRectMaterial = true,Gamebool bOutputAlpha = false);

	private:
		Gameint m_nHandle;

		//! \brief (����ͶӰ)������ڴ�С
		Gamedouble m_nOrthoWidnowWidth;
		Gamedouble m_nOrthoWidnowHeight;

		Gamedouble m_dCameraPositionX;
		Gamedouble m_dCameraPositionY;

		//! \brief �������
		ASuperMap_CaptureSceneActor* m_pCameraActor;
	};

	class SUPERMAP_API GameCameraManager
	{
		// ���ڲ����õĽӿ�
	public:
		GameCameraManager();
		~GameCameraManager();

		//! \brief ��ȡ������
		static GameCameraManager* GetSingleton();

		//! \brief ���ó�������
		void SetWorld(UWorld* pWorld);
		UWorld* GetWorld();

		//! \brief ���ٵ�����
		static void DestorySingleton();

		//! \brief �����������
		GameCamera* Create(Gamebool bCreateActor = true);

		//! \brief ��ȡ�������
		GameCamera* Get(Gameint cameraHandle);

		//! \brief �ӹ������Ƴ��������
		void Remove(Gameint cameraHandle);

		//! \brief ���������
		void SetMainCameraViewMatrix(Gamedouble* pViewMatrix);
	private:
		//! \brief GameTexture����
		static GameCameraManager* m_pGameCameraManager;

		//! \brief ����ӳ���
		TMap<Gameint, GameCamera*> m_mapCamera;

		//! \brief ���糡������
		UWorld* m_pWorld;
	};
}