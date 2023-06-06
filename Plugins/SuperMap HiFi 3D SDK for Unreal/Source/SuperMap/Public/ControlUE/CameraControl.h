#pragma once

#include "Math/Vector.h"
#include "Math/Rotator.h"
#include "Data/Vector3d.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Core/RealspaceDLL.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
class ACameraActor;
class APlayerController;
class UWorld;

using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace ControlUE
		{
			/*
			 * ����༭ģʽ
			 */
			enum CMEditMode
			{
				NORMAL,  // ���������������
				EDITING, // ��������༭ģʽ
				ROAM	 // ����ģʽ
			};

			/*
			 * �������״̬
			*/
			enum CMState
			{
				None,
				Moving,   // ƽ��
				Rotating, // ��ת
				Scaling	  // ����
			};

			/*
			 * ��갴��
			*/
			enum CMMouseButtonState
			{
				MouseBtn_Nothing,    //  ����ް���
				MouseBtn_Left_Down,  //  ����������
				MouseBtn_Left_Up,    //  ������̧��
				MouseBtn_Left_DoubleClick, //  ������˫��
				MouseBtn_Right_Down, //  ����Ҽ�����
				MouseBtn_Right_Up,   //  ����Ҽ�̧��
				MouseBtn_Middle_Move, //  ����м�����
				MouseBtn_Middle_Down, // ����м�����
				MouseBtn_Middle_Up, // ����м�̧��
			};

			/*
			 * ��������
			*/
			enum UGCSceneType
			{
				UGC_PLANE, // ƽ�泡��
				UGC_EARTH, // ���泡��
				UGC_EARTH_ELLIPSOID_WGS84 // ���򳡾�
			};

			/*
			 * ��׽����������
			*/
			struct CaptureDepthTexParm
			{
				//! \brief �����
				uint32 m_textureWidth;

				//! \brief �����
				uint32 m_textureHeight;

				//! \brief �����߱�
				double m_dCameraAspect;

				//! \brief ������ü������
				double m_dCameraNearDist;

				//! \brief ���Զ�ü������
				double m_dCameraFarDist;

				//! \brief ����ӳ���
				double m_dCameraFov;

				//! \brief �����ͼ�任(��ͬ��m_viewMatrix)
				FTransform m_transform;

				//! \brief �����ͼ����
				FMatrix m_viewMatrix;

				//! \brief ���ͶӰ����
				FMatrix m_projMatrix;

				//! \brief �����λ��
				FVector m_vCameraLocation;

				//! \brief �������ת
				FRotator m_rCameraRotation;
			};

			class SUPERMAP_API CameraControl
			{
			public:
				CameraControl();
				~CameraControl();
			public:
				//! \brief ��갴��״̬
				CMMouseButtonState m_eCamMouseBtnState;

				//! \brief ����ӿڿ��
				int32 m_nScreenWidth;

				//! \brief ����ӿڸ߶�
				int32 m_nScreenHeight;

				//! \brief ��ǰ������
				APlayerController* m_pCurrentPlayerControl;

				//! \brief ��ǰ�����
				ACameraActor* m_pCameraActor;

				//! \brief UE�����糡��
				UWorld* m_pWorld;

				//! \brief ������ʼ��
				FVector m_vMouseStartPoint;

				//! \brief ������ֹ��
				FVector m_vMouseEndPoint;

				//! \brief ���ʰȡ��ê��(����������ά��)
				FVector m_vMouseAnchor;

				//! \brief ���ʰȡ�ĵ�(ʵʱ)
				FVector m_vMouseActorRealTime;

				//! \brief ���ʰȡ��ê��(����������ά�㣬û���޸Ĺ�ԭ�������)
				FVector m_vMouseAnchorNoWorldOrginOffset;

				//! \breif ���ʰȡ�ĵ㣨��ʼ�㣬����������ά�㣩
				FVector m_vAnchorStart;

				//! \brief ���ʰȡ�ĵ㣨��ֹ�㣬����������ά�㣩
				FVector m_vAnchorEnd;

				//! \brief ����ϵ��
				float m_fScrollFactor;

				//! \brief ��������
				static UGCSceneType m_eSceneType;

				//! \brief ��������ԭ��
				FIntVector m_vecWorldOrigin;

				//! \brief ��ת����µĹ̶���������ԭ��
				FIntVector m_vecWorldOriginForRotate;

				//! \brief �Ƿ��н���
				bool m_bHit;

				//! \brief ����ı༭ģʽ
				CMEditMode m_eEditMode;

				//! \brief ���״̬
				CMState m_eCameraState;

				//! \brief ���λ��
				Vector3d m_vCameraLocation;
				FRotator m_vCameraRotator;
			private:
				//! \brief �������ĵ�Tilt
				float m_fOpCenterTile;

				//! \brief ����һ�������Ⱦ����
				UTextureRenderTarget2D* m_pDepthRenderTarget;

				//! \brief ��ǰ�����
				FVector m_vCurrentMouse;
				FVector m_vCurrentWorldPostion;

				//! \brief ���Fov�ӽ�
				Gamedouble m_dFov;
			private:

				//! \breif API�Ƿ��ʼ��
				bool m_bAPIInitial;

				//! \brief ��ȡ����ķ���
				FVector GetDirection();

				//! \breif ��ȡ������ϵ���
				FVector GetUp();
			public:
				//! \brief �������
				void CameraOperation();

				//! \brief ����ɵ�boundsλ��
				void FlyToBounds(FVector vLocal, FVector vLonLat);

				//! \brief ��������༭ģʽ
				void SetEditMode(CMEditMode eEditMode);

				//! \brief ��ȡ����༭ģʽ
				CMEditMode GetEditMode();

#if PLATFORM_LINUX
				//! \brief ��ȡ���ͼ
				void GetDepthTexture(CaptureDepthTexParm captureDepthTexParm, TArray<FFloat16Color>& arrDepthBuffer);
#else
				//! \brief ��ȡ���ͼ
				void GetDepthTexture(CaptureDepthTexParm captureDepthTexParm, TArray<FLinearColor>& arrDepthBuffer);
#endif

				//! \brief �������Ⱦ��ָ����������
				void RenderToDepthTexture(CaptureDepthTexParm captureDepthTexParm, UTextureRenderTarget2D* pTextureRenderTarget2D);

				//! \brief ��ȡ���ֵ
				void GetDepthTexture(CaptureDepthTexParm captureDepthTexparam , void* &pDepthBuffer);
				
				//! \brief ��ȡ����Ӧ�ĵ�λλ��
				bool GetWorldPositionByDepth(FVector vMouse, Vector3d& vWorldPosition);

				//! \brief �������
				void Reset();

				//! \brief �������Fov�ӽ�
				void SetFov(Gamedouble dFov);

				//! \brief ��ȡ���Fov�ӽ�
				Gamedouble GetFov();

				//! \brief ��ȡ��ǰ�������
				void GetMousePos(float &x, float &y);
			public:
				//==========================================================
				//�ڲ����õķ������ݲ�д���ĵ�
				//! \brief ��ȡLocal��������
				Vector3d GetLocalWorldPosition(Gameint nMouseX, Gameint nMouseY, Gamebool bUseDepth = true);

				//! \brief ������������������Ľ���
				void LineTrace(bool bLineTrace = true);
				void LineTrace(int32 nMouseX, int32 nMouseY);


				//! \brief �����󽻻�ȡѡ�н��
				void LineTrace(int32 nMouseX, int32 nMouseY, FHitResult& hitResult);


				void PrepareCurrentStartMouse();
				void PrepareCurrentEndMouse();
				void EndPointTOStartPoint();

				//! \brief ���õ�ǰ�����������λ�ú���ת
				void SetLocationAndRotationToPlayerControl(const FVector& location, const FRotator& rotation);

				//! \brief ��ȡ��ǰ���Location��Rotation
				void GetCameraLocationAndRotation(FVector &vCameraLocation, FRotator &vCameraRotator);

				//! \brief ���������λ�ú���ת��
				void SetCameraLocationAndRotation(FVector vCameraLocation, FRotator vCameraRotator);
				//===========================================================
			private:

				//! \brief ��ȡͶӰ����
				FMatrix GetCameraProjectionMatrix();

				//! \brief ��ȡ�ӿڴ�С
				void GetViewportSize(int32 &x, int32 &y);

				//! \brief ���������ת��
				FRotator CalRotation(FVector vLonLat);

				//! \breif ����ת����������ͷ���
				void MouseToWorld(FVector vMousePt, FVector & vWorld, FVector &vDirection, float fDepth1 = 0.5f, float fDepth2 = 1.0f, FVector vMove = FVector::ZeroVector);

				// -----------------------------------
				// ���泡����������
				// -----------------------------------
				//! \brief �м�����ʱ�������ץȡ���tilt
				void ReCalOpCenterTilt();

				//! \brief ����ƽ��
				void Earth_Pan();

				//! \brief ���泡���Ͻ�����ƽ�Ʋ���
				void Earth_PanNearGround(const FVector& LocationStart, const FVector& DirectionStart, const FVector& LocationEnd, const FVector& DirectionEnd);

				//! \brief ������ת
				void Earth_Rotate();

				//! \brief ��������
				void Earth_Scale();

				// ------------------------------------
				// ƽ�泡����������
				// ------------------------------------

				//! \brief ƽ��ƽ��
				void Plane_Pan();


				//! \brief ƽ����ת
				void Plane_Rotate();


				//! \brief ƽ������
				void Plane_Scale();

				//! \brief ��ȡ��������ĸ߶�
				float GetEarthCameraHeight();

				//! \brief ��UE����Ⱦ����ϵ��任��ECEF�������
				void TransformUERelativeToECEF(FVector& vLocation, FVector& vDirection);
				void TransformECEFToUERelative(FVector& vLocation, FVector& vDirection);
			};
		}
	}
}