#pragma once

#include "CoreMinimal.h"
#include "ControlUE/CameraControl.h"
#include "Core/SceneControl.h"
#include "Core/Scene.h"
#include "Core/Layer3Ds.h"
#include "Core/TerrainLayers.h"
#include "Core/ROCacheManager.h"
#include "Core/Selection3D.h"
#include "Math/Rotator.h"
#include "Engine/World.h"

class UWorld;
class ACameraActor;
class AActor;

using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core 
		{
			class SceneControl;
		}
		namespace ControlUE
		{
			class FWorkRunnable;
			class SUPERMAP_API RealspaceView
			{

			public:
				RealspaceView();
				~RealspaceView();

			public:
				//! \brief ��ȡRealspaceView
				static RealspaceView* GetSingleton();

				//! \brief ����CameraActor
				void SetMainCameraActor(ACameraActor* pMainCamera);

				//! \brief ��ȡCameraActor
				ACameraActor* GetMainCameraActor();

				//! \brief �ж�CameraActor�Ƿ�Ϊ��ǰ�ĳ�����
				bool IsOwner(ACameraActor* pMainCamera);

				//! \brief ���RealspaceView
				void DestroySingleton();

				//! \brief ÿһ֡������Ⱦ
				void Render(float DeltaTime);

				void ReleaseROManager();

				//! \breif ������Ⱦ
				void Destroy(bool bQuitApplication);

				//! \brief ��ʼ��
				bool Initialize(ACameraActor* pMainCamera);

				//! \brief �Ƿ��ʼ����
				bool IsInitialized();

				//! \brief ����������
				void MouseLeftButtonDown();

				//! \brief ������̧��
				void MouseLeftButtonUp();

				//! \brief ������˫��
				void MouseLeftButtonDoubleClick();

				//! \brief ����Ҽ�����
				void MouseRightButtonDown();

				//! \brief ����Ҽ�̧��
				void MouseRightButtonUp();

				//! \brief �м���ƶ�
				void MouseMiddleButtonMove(float Value);

				//! \brief �м��̧��
				void MouseMiddleButtonUp();

				//! \brief �м������
				void MouseMiddleButtonDown();

				//! \brief ��ȡ��������
				SuperMapSDK::UnrealEngine::Core::SceneControl* GetSceneControl();

				//! \brief ��������ԭ������
				void SetPosition(FVector & vPosition);

				//! \brief ��ȡCameraControl
				CameraControl* GetCameraControl();

				//! \brief ���õ���ԭ��
				//! \param dLongitude [in] ����
				//! \param dLatitude  [in] γ��
				//! \param dAltitude  [in] �߶ȣ�Ĭ��Ϊ0
				void SetGeoreferenceOrigin(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude = 0.0);
				
				//! \brief ��ȡ����ԭ��
				Vector3d GetGeoreferenceOrigin();

				//! \brief ��ȡ�༭ģʽ
				EWorldType::Type GetWorldType();

				//! \brief ��ȡ��ǰ���糡��������
				UWorld* GetWorld();

				//! \brief ��ȡ������ѡ�е�Actor
				AActor* GetSelectedActor();

				//! \brief �Ƿ�����ײ���
				void SetEnableCollision(Gamebool bEnable);

				//! \brief �Ƿ������߼���
				void SetEnableComputeNormal(Gamebool bEnable);

				//! \brief ���ø��¸���(�����첽�����)
				void SetUpdateCount(Gameint nCount);
			private:
				//! \brief ���ͬ��
				void SyncUGCCam();

				//! \brief ��̬�ı�����ԭ��
				void UpdateOriginWorldCerter();

				//! \brief ����ʵ��������
				void UpdateInstancedActor();

				//! \brief ������ת֮��λ��
				void UpdateRotationAndLocation(Vector3d &vLocation, FRotator &vRotator , Matrix4d mat4d);

				//! \brief ѡ�����ݼ��������
				void SelectActor();
				void SetMIDScalarParameterValue(AActor* pActor, float fScalar);
				
				//! \brief ��ʼ���ص�����
				void InitGraphics3DCallbackHandle();

				//! \brief ��ȡ�����λ�ú���ת
				void GetCameraLocationAndRotator(Vector3d &vLocation, FRotator &vRotator);

				//! \brief ���������λ�ú���ת
				void SetCameraLocationAndRotator(Vector3d vLocation, FRotator vRotator);

				//! \brief ��ʼ�����ڴ�С
				Gamebool InitialWindow();
				
				//! \brief ���ڸı�
				Gamevoid OnWindowResize();

				//! \brief ����PlayerCameraManager
				Gamevoid UpdatePlayerCameraManager();

				//! \brief ��ȡ���ڴ�С
				Gamevoid GetWindowSize(Gameint & nWidth, Gameint & nHeight);

				//! \brief ��ʼ�������ʲ���
				void LoadAssetLibrary();

				//! \brief �첽��ʼ�����
				void AsyncComponent();

				//! \brief �����������������
				void UpdateSkyAtmosphere();
			private:
				//! \brief RealspaceView����
				static RealspaceView* m_pRealspaceView;

				//! \brief Object��ѯid
				uint32 m_nSelectedId;

				//! \brief ѡ�ж����ѡ��
				Selection3D* m_pSelection;

				//! \brief �Ƿ��ʼ���ɹ�
				bool m_bInitial;

				//! \brief ���������
				CameraControl m_CameraControl;

				//! \brief ���������
				APlayerController* m_pPlayerController;

				//! \brief ���糡��
				UWorld* m_pWorld;

				//! \brief �����
				ACameraActor* m_pMainCamera;

				//! \brief �ײ㳡��������
				SuperMapSDK::UnrealEngine::Core::SceneControl* m_pSceneControl;

				//! \brief �������ĵ�
				FVector m_vOriginalPosition;

				//! \brief �Ƿ�������
				bool m_bOperateCamera;

				//! \brief �ڲü�ģʽ�²������
				bool m_bClipingAndOperateCamera;

				//! \brief �Ƿ����ȸ��߷���
				bool m_bContourMapEnable;

				//! \brief ������һ�����������ʱ��
				float m_fTimeFromLastCollectionGarbage;

				//! \brief ������ѡ�е�Actor
				AActor* m_pSelectedActor;

				//! \brief ����ԭ��
				Vector3d m_vGeoreferenceOrigin;

				//! \brief ������Ⱦ�������
				Gameint m_nUpdateCount;

				//! \brief ���ڿ��
				Gameint m_nWindowWidth;
				
				//! \brief ���ڸ߶�
				Gameint m_nWindowHeight;
			};
		}
	}
}
