#pragma once

#include <map>
#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/SceneType.h"
#include "Layout/SlateRect.h"
#include "ControlUE/CameraControl.h"
#include "Graphics3D/GameComponent.h"
#include "Base3D/CommonDefine.h"
#include "Core/Layer3D.h"
#include "Data/Rectangle2D.h"
#include "Core/Query3D.h"
#include "Core/CameraState.h"
#include "Core/RealspaceDLL.h"
#include "Core/GlobalImage.h"
class UWorld;

using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::Data;

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
			//! \brief 飞行定位回调事件
			typedef void(*FlownFunc)(void* pScene);
			void OnFlown(void* pScene);

			enum SUPERMAP_API PixelToGlobeMode
			{
				//! \brief 地形和模型都参与求交点
				TerrainAndModel = 0,

				//! \brief 只与地表求交点
				Sphere = 1
			};

			enum MultiViewportMode
			{
				None = 0,//还原分屏
				Horizontal = 1,//左右分屏
			};

			enum SUPERMAP_API StereoMode
			{
				ANAGLYPHIC = 0, //互补色方式
				HTCVIVE_VR = 10 //HTC VIVE虚拟现实头盔
			};

			class Layer3Ds;
			class TerrainLayers;
			class TrackingLayer;
			class FlyManager;
			//class SuperMapSDK::GameComponent;
			class SUPERMAP_API Scene
			{
			public:
				Scene();
				~Scene();
			private:
				//! \brief 普通图层数组对象
				Layer3Ds* m_pLayer3Ds;

				//! \brief 地形图层对象
				TerrainLayers* m_pTerrainLayers;

				//! \brief 跟踪图层对象
				TrackingLayer* m_pTrackingLayer;

				//! \brief 场景类型
				SceneType m_eSceneType;

				//! \brief 地形伪坐标插入点
				FVector m_vtTerrainPos;

				//! \brief 相机操作类
				ControlUE::CameraControl* m_pCameraControl;

				//! \brief 分析对象队列
				std::map<FName, Analyst3D*> m_mapAnalyst;

				//! \brief 世界场景对象
				UWorld* m_pWorld;

				//! \brief 场景
				void* m_pUGScene;

				//! \brief 分屏模式
				MultiViewportMode m_eViewportMode;

				//! \brief 空间查询类
				Query3D* m_pQuery3D;

				//! \brief 飞行管理
				FlyManager* m_pFlyManager;

				//! \brief 主相机状态
				CameraState* m_pCameraState;

				//! \brief 地形影像
				GlobalImage* m_pGlobalImage;
			private:
				void GetLayer3DsFromXML();
				void GetTerrainLayersFromXML();
			public:
				//! \brief 获取地形影像
				GlobalImage* GetGlobalImage();

				//! \brief 设置相机操作类
				void SetCameraControl(SuperMapSDK::UnrealEngine::ControlUE::CameraControl* pCamerControl);

				//! \brief 获取相机操作类
				CameraControl* GetCameraControl();

				//! \brief 设置世界场景类
				void SetWorld(UWorld* pWorld);

				//! \brief 获取世界场景类
				UWorld* GetWorld();

				//! \brief 获取Query3D
				Query3D* GetQuery3D();

				//! \brief 获取场景类型
				SceneType GetSceneType();

				//! \brief 设置场景类型
				void SetSceneType(SceneType eSceneType);

				//! \brief 返回3D图层集合
				Layer3Ds* GetLayer3Ds();

				//! \brief 返回地形图层集合
				TerrainLayers* GetTerrainLayers();

				//! \brief 获取跟踪图层
				TrackingLayer* GetTrackingLayer();

				//! \brief 设置相机
				void SetCamera(Gamefloat* matView, Gamefloat fNearDist, Gamefloat fFarDist, Gamefloat fFov, Gamefloat fAspect);

				//! \brief 设置相机Fov视角
				void SetCameraFov(Gamedouble dFov);

				//! \brief 获取相机Fov视角
				Gamedouble GetCameraFov();

				//! \brief 相机飞到bounds位置 
				void EnsureVisible(Rectangle2D rect2D, Gamedouble dHeight = FIXED_ALTITUDE);

				//! \brief 清空图层
				void Clear();

				//! \brief 返回像素UE空间下的笛卡尔坐标
				Vector3d PixelToCartesian(Vector3d vMouse);

				//! \brief 返回像素对应的真实地理坐标
				Vector3d PixelToGlobe(Vector3d vMouse, PixelToGlobeMode mode = TerrainAndModel);

				//! \brief 获取分析功能列表
				std::map<FName, Analyst3D*>& GetAnalyst3DList();

				//! \brief 裙边设置
				Gamebool GetCreateSkirt();

				//! \brief 裙边设置
				void SetCreateSkirt(Gamebool bCreatesSkirt);

				//! \brief 设置裙边高度
				void SetSkirtHeight(Gamefloat fHeight);

				//! \brief 保存Json
				void ToJson(FString strPath);

				//! \brief 设置分屏模式
				void SetMultiViewportMode(MultiViewportMode mode);

				//! \brief 获取分屏模式
				MultiViewportMode GetMultiViewportMode();

				//! \brief 分析功能渲染函数(内部调用函数)
				void Render();

				//! \brief 输出xml文件
				Gamebool ToXML(FString strFileAdress);

				//! \brief 读取xml文件
				Gamebool FromXML(FString strFileAdress);

				//! \brief 通过指定经纬度获取空间坐标 及 模型旋转角度
				//! \brief bUseGeoreference 为false 不忽略动态原点
				FTransform LongitudeLatitudeToUE(FVector vLonLat, Gamebool bIgnoreWorldOrigin = false);

				//! \brief 场景设置无效区域
				void SetShowInvalidation(Gamebool bShow);

				//! \brief 创建场景指针
				void SetHandler(void* pScene);

				//! \brief 获取场景指针
				void* GetHandler();

				//! \brief 获取飞行管理类
				FlyManager* GetFlyManager();

				//! \brief 设置飞行定位
				void Fly(CameraState* pCameraState, Gameint milliseconds);

				//! \brief 设置地形夸张
				void SetTerrainExaggeration(Gamedouble dValue);

				//! \brief 获取地形夸张数值
				Gamedouble GetTerrainExaggeration();

				//! \brief 获取选中对象的材质信息
				SelectedInfo GetSelectedInfo();

				//! \brief 获取主相机相机状态
				CameraState* GetCameraState();

				//! \brief 初始化飞行回调事件
				void InitializeFlyCallbackHandle();

				//! \brief 设置立体显示模式
				void SetStereoMode(StereoMode mode);

				//! \brief 场景刷新
				void Updata();

				//! \brief 局部地形刷新
				void GlobalRefreshRaster(Rectangle2D rec);

				//! \brief 获取立体显示模式
				StereoMode GetStereoMode();

				void AddNativeGameComponent(GameComponent* pGameComponent);
				void RemoveNativeGameComponent(GameComponent* pGameComponent);

				Layer3D* FindLayerByNodeName(Gamelong nodeName);


				friend class SceneControl;
				friend class Analyst3D;
				friend class ROCacheManager;
			};
		}
	}
}