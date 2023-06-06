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
				//! \brief 获取RealspaceView
				static RealspaceView* GetSingleton();

				//! \brief 设置CameraActor
				void SetMainCameraActor(ACameraActor* pMainCamera);

				//! \brief 获取CameraActor
				ACameraActor* GetMainCameraActor();

				//! \brief 判断CameraActor是否为当前的持有者
				bool IsOwner(ACameraActor* pMainCamera);

				//! \brief 清除RealspaceView
				void DestroySingleton();

				//! \brief 每一帧调用渲染
				void Render(float DeltaTime);

				void ReleaseROManager();

				//! \breif 结束渲染
				void Destroy(bool bQuitApplication);

				//! \brief 初始化
				bool Initialize(ACameraActor* pMainCamera);

				//! \brief 是否初始化过
				bool IsInitialized();

				//! \brief 鼠标左键按下
				void MouseLeftButtonDown();

				//! \brief 鼠标左键抬起
				void MouseLeftButtonUp();

				//! \brief 鼠标左键双击
				void MouseLeftButtonDoubleClick();

				//! \brief 鼠标右键按下
				void MouseRightButtonDown();

				//! \brief 鼠标右键抬起
				void MouseRightButtonUp();

				//! \brief 中间键移动
				void MouseMiddleButtonMove(float Value);

				//! \brief 中间键抬起
				void MouseMiddleButtonUp();

				//! \brief 中间键按下
				void MouseMiddleButtonDown();

				//! \brief 获取场景控制
				SuperMapSDK::UnrealEngine::Core::SceneControl* GetSceneControl();

				//! \brief 设置世界原点插入点
				void SetPosition(FVector & vPosition);

				//! \brief 获取CameraControl
				CameraControl* GetCameraControl();

				//! \brief 设置地理原点
				//! \param dLongitude [in] 经度
				//! \param dLatitude  [in] 纬度
				//! \param dAltitude  [in] 高度，默认为0
				void SetGeoreferenceOrigin(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude = 0.0);
				
				//! \brief 获取地理原点
				Vector3d GetGeoreferenceOrigin();

				//! \brief 获取编辑模式
				EWorldType::Type GetWorldType();

				//! \brief 获取当前世界场景管理器
				UWorld* GetWorld();

				//! \brief 获取场景被选中的Actor
				AActor* GetSelectedActor();

				//! \brief 是否开启碰撞检测
				void SetEnableCollision(Gamebool bEnable);

				//! \brief 是否开启法线计算
				void SetEnableComputeNormal(Gamebool bEnable);

				//! \brief 设置更新个数(开启异步的情况)
				void SetUpdateCount(Gameint nCount);
			private:
				//! \brief 相机同步
				void SyncUGCCam();

				//! \brief 动态改变世界原点
				void UpdateOriginWorldCerter();

				//! \brief 更新实例化数据
				void UpdateInstancedActor();

				//! \brief 计算旋转之后位置
				void UpdateRotationAndLocation(Vector3d &vLocation, FRotator &vRotator , Matrix4d mat4d);

				//! \brief 选中数据集导入对象
				void SelectActor();
				void SetMIDScalarParameterValue(AActor* pActor, float fScalar);
				
				//! \brief 初始化回调函数
				void InitGraphics3DCallbackHandle();

				//! \brief 获取相机的位置和旋转
				void GetCameraLocationAndRotator(Vector3d &vLocation, FRotator &vRotator);

				//! \brief 设置相机的位置和旋转
				void SetCameraLocationAndRotator(Vector3d vLocation, FRotator vRotator);

				//! \brief 初始化窗口大小
				Gamebool InitialWindow();
				
				//! \brief 窗口改变
				Gamevoid OnWindowResize();

				//! \brief 设置PlayerCameraManager
				Gamevoid UpdatePlayerCameraManager();

				//! \brief 获取窗口大小
				Gamevoid GetWindowSize(Gameint & nWidth, Gameint & nHeight);

				//! \brief 初始化导入资产库
				void LoadAssetLibrary();

				//! \brief 异步初始化组件
				void AsyncComponent();

				//! \brief 更改椭球大气的问题
				void UpdateSkyAtmosphere();
			private:
				//! \brief RealspaceView单例
				static RealspaceView* m_pRealspaceView;

				//! \brief Object查询id
				uint32 m_nSelectedId;

				//! \brief 选中对象的选择集
				Selection3D* m_pSelection;

				//! \brief 是否初始化成功
				bool m_bInitial;

				//! \brief 相机操作类
				CameraControl m_CameraControl;

				//! \brief 相机控制器
				APlayerController* m_pPlayerController;

				//! \brief 世界场景
				UWorld* m_pWorld;

				//! \brief 主相机
				ACameraActor* m_pMainCamera;

				//! \brief 底层场景控制类
				SuperMapSDK::UnrealEngine::Core::SceneControl* m_pSceneControl;

				//! \brief 世界中心点
				FVector m_vOriginalPosition;

				//! \brief 是否控制相机
				bool m_bOperateCamera;

				//! \brief 在裁剪模式下操作相机
				bool m_bClipingAndOperateCamera;

				//! \brief 是否开启等高线分析
				bool m_bContourMapEnable;

				//! \brief 距离上一次垃圾清理的时间
				float m_fTimeFromLastCollectionGarbage;

				//! \brief 场景被选中的Actor
				AActor* m_pSelectedActor;

				//! \brief 地理原点
				Vector3d m_vGeoreferenceOrigin;

				//! \brief 更新渲染对象个数
				Gameint m_nUpdateCount;

				//! \brief 窗口宽度
				Gameint m_nWindowWidth;
				
				//! \brief 窗口高度
				Gameint m_nWindowHeight;
			};
		}
	}
}
