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
			 * 相机编辑模式
			 */
			enum CMEditMode
			{
				NORMAL,  // 场景相机正常操作
				EDITING, // 场景进入编辑模式
				ROAM	 // 漫游模式
			};

			/*
			 * 相机操作状态
			*/
			enum CMState
			{
				None,
				Moving,   // 平移
				Rotating, // 旋转
				Scaling	  // 缩放
			};

			/*
			 * 鼠标按键
			*/
			enum CMMouseButtonState
			{
				MouseBtn_Nothing,    //  鼠标无按键
				MouseBtn_Left_Down,  //  鼠标左键按下
				MouseBtn_Left_Up,    //  鼠标左键抬起
				MouseBtn_Left_DoubleClick, //  鼠标左键双击
				MouseBtn_Right_Down, //  鼠标右键按下
				MouseBtn_Right_Up,   //  鼠标右键抬起
				MouseBtn_Middle_Move, //  鼠标中键滚动
				MouseBtn_Middle_Down, // 鼠标中键按下
				MouseBtn_Middle_Up, // 鼠标中键抬起
			};

			/*
			 * 场景类型
			*/
			enum UGCSceneType
			{
				UGC_PLANE, // 平面场景
				UGC_EARTH, // 球面场景
				UGC_EARTH_ELLIPSOID_WGS84 // 椭球场景
			};

			/*
			 * 捕捉深度纹理参数
			*/
			struct CaptureDepthTexParm
			{
				//! \brief 纹理宽
				uint32 m_textureWidth;

				//! \brief 纹理高
				uint32 m_textureHeight;

				//! \brief 相机宽高比
				double m_dCameraAspect;

				//! \brief 相机近裁剪面距离
				double m_dCameraNearDist;

				//! \brief 相机远裁剪面距离
				double m_dCameraFarDist;

				//! \brief 相机视场角
				double m_dCameraFov;

				//! \brief 相机视图变换(等同于m_viewMatrix)
				FTransform m_transform;

				//! \brief 相机视图矩阵
				FMatrix m_viewMatrix;

				//! \brief 相机投影矩阵
				FMatrix m_projMatrix;

				//! \brief 相机的位置
				FVector m_vCameraLocation;

				//! \brief 相机的旋转
				FRotator m_rCameraRotation;
			};

			class SUPERMAP_API CameraControl
			{
			public:
				CameraControl();
				~CameraControl();
			public:
				//! \brief 鼠标按键状态
				CMMouseButtonState m_eCamMouseBtnState;

				//! \brief 相机视口宽度
				int32 m_nScreenWidth;

				//! \brief 相机视口高度
				int32 m_nScreenHeight;

				//! \brief 当前控制器
				APlayerController* m_pCurrentPlayerControl;

				//! \brief 当前主相机
				ACameraActor* m_pCameraActor;

				//! \brief UE的世界场景
				UWorld* m_pWorld;

				//! \brief 鼠标的起始点
				FVector m_vMouseStartPoint;

				//! \brief 鼠标的终止点
				FVector m_vMouseEndPoint;

				//! \brief 鼠标拾取的锚点(世界坐标三维点)
				FVector m_vMouseAnchor;

				//! \brief 鼠标拾取的点(实时)
				FVector m_vMouseActorRealTime;

				//! \brief 鼠标拾取的锚点(世界坐标三维点，没有修改过原点的坐标)
				FVector m_vMouseAnchorNoWorldOrginOffset;

				//! \breif 鼠标拾取的点（起始点，世界坐标三维点）
				FVector m_vAnchorStart;

				//! \brief 鼠标拾取的点（终止点，世界做表三维点）
				FVector m_vAnchorEnd;

				//! \brief 缩放系数
				float m_fScrollFactor;

				//! \brief 场景类型
				static UGCSceneType m_eSceneType;

				//! \brief 世界坐标原点
				FIntVector m_vecWorldOrigin;

				//! \brief 旋转情况下的固定世界坐标原点
				FIntVector m_vecWorldOriginForRotate;

				//! \brief 是否有交点
				bool m_bHit;

				//! \brief 相机的编辑模式
				CMEditMode m_eEditMode;

				//! \brief 相机状态
				CMState m_eCameraState;

				//! \brief 相机位置
				Vector3d m_vCameraLocation;
				FRotator m_vCameraRotator;
			private:
				//! \brief 操作中心的Tilt
				float m_fOpCenterTile;

				//! \brief 创建一个深度渲染对象
				UTextureRenderTarget2D* m_pDepthRenderTarget;

				//! \brief 当前坐标点
				FVector m_vCurrentMouse;
				FVector m_vCurrentWorldPostion;

				//! \brief 相机Fov视角
				Gamedouble m_dFov;
			private:

				//! \breif API是否初始化
				bool m_bAPIInitial;

				//! \brief 获取相机的方向
				FVector GetDirection();

				//! \breif 获取相机朝上的轴
				FVector GetUp();
			public:
				//! \brief 相机操作
				void CameraOperation();

				//! \brief 相机飞到bounds位置
				void FlyToBounds(FVector vLocal, FVector vLonLat);

				//! \brief 设置相机编辑模式
				void SetEditMode(CMEditMode eEditMode);

				//! \brief 获取相机编辑模式
				CMEditMode GetEditMode();

#if PLATFORM_LINUX
				//! \brief 获取深度图
				void GetDepthTexture(CaptureDepthTexParm captureDepthTexParm, TArray<FFloat16Color>& arrDepthBuffer);
#else
				//! \brief 获取深度图
				void GetDepthTexture(CaptureDepthTexParm captureDepthTexParm, TArray<FLinearColor>& arrDepthBuffer);
#endif

				//! \brief 将深度渲染到指定的纹理上
				void RenderToDepthTexture(CaptureDepthTexParm captureDepthTexParm, UTextureRenderTarget2D* pTextureRenderTarget2D);

				//! \brief 获取深度值
				void GetDepthTexture(CaptureDepthTexParm captureDepthTexparam , void* &pDepthBuffer);
				
				//! \brief 获取鼠标对应的地位位置
				bool GetWorldPositionByDepth(FVector vMouse, Vector3d& vWorldPosition);

				//! \brief 重置相机
				void Reset();

				//! \brief 设置相机Fov视角
				void SetFov(Gamedouble dFov);

				//! \brief 获取相机Fov视角
				Gamedouble GetFov();

				//! \brief 获取当前鼠标坐标
				void GetMousePos(float &x, float &y);
			public:
				//==========================================================
				//内部调用的方法，暂不写入文档
				//! \brief 获取Local世界坐标
				Vector3d GetLocalWorldPosition(Gameint nMouseX, Gameint nMouseY, Gamebool bUseDepth = true);

				//! \brief 求鼠标射线与三角网的交点
				void LineTrace(bool bLineTrace = true);
				void LineTrace(int32 nMouseX, int32 nMouseY);


				//! \brief 射线求交获取选中结果
				void LineTrace(int32 nMouseX, int32 nMouseY, FHitResult& hitResult);


				void PrepareCurrentStartMouse();
				void PrepareCurrentEndMouse();
				void EndPointTOStartPoint();

				//! \brief 设置当前相机控制器的位置和旋转
				void SetLocationAndRotationToPlayerControl(const FVector& location, const FRotator& rotation);

				//! \brief 获取当前相机Location和Rotation
				void GetCameraLocationAndRotation(FVector &vCameraLocation, FRotator &vCameraRotator);

				//! \brief 设置相机的位置和旋转角
				void SetCameraLocationAndRotation(FVector vCameraLocation, FRotator vCameraRotator);
				//===========================================================
			private:

				//! \brief 获取投影矩阵
				FMatrix GetCameraProjectionMatrix();

				//! \brief 获取视口大小
				void GetViewportSize(int32 &x, int32 &y);

				//! \brief 计算相机旋转角
				FRotator CalRotation(FVector vLonLat);

				//! \breif 鼠标点转化世界坐标和方向
				void MouseToWorld(FVector vMousePt, FVector & vWorld, FVector &vDirection, float fDepth1 = 0.5f, float fDepth2 = 1.0f, FVector vMove = FVector::ZeroVector);

				// -----------------------------------
				// 球面场景操作方法
				// -----------------------------------
				//! \brief 中键俯仰时计算鼠标抓取点的tilt
				void ReCalOpCenterTilt();

				//! \brief 球面平移
				void Earth_Pan();

				//! \brief 球面场景上近地面平移操作
				void Earth_PanNearGround(const FVector& LocationStart, const FVector& DirectionStart, const FVector& LocationEnd, const FVector& DirectionEnd);

				//! \brief 球面旋转
				void Earth_Rotate();

				//! \brief 球面缩放
				void Earth_Scale();

				// ------------------------------------
				// 平面场景操作方法
				// ------------------------------------

				//! \brief 平面平移
				void Plane_Pan();


				//! \brief 平面旋转
				void Plane_Rotate();


				//! \brief 平面缩放
				void Plane_Scale();

				//! \brief 获取相机里地面的高度
				float GetEarthCameraHeight();

				//! \brief 将UE的渲染坐标系点变换到ECEF的坐标点
				void TransformUERelativeToECEF(FVector& vLocation, FVector& vDirection);
				void TransformECEFToUERelative(FVector& vLocation, FVector& vDirection);
			};
		}
	}
}