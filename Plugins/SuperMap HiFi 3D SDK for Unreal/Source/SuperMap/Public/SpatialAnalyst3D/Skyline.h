//////////////////////////////////////////////////////////////////////////                                         
//!  \file Skyline.h
//!  \brief 实现绘制天际线和天际线分析类
//!  \details
//!  \attention 天际线分析依赖天际线，在对天际线进行分析前，必须生成天际线
//////////////////////////////////////////////////////////////////////////
#pragma once
#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Data/Vector3d.h"
#include "Data/GeoLine3D.h"
#include "Data/GeoLine.h"
#include "Data/Matrix4d.h"
#include "Core/RealspaceDLL.h"
#include "Data/GeoModel3D.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Core;

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
			class SUPERMAP_API Skyline : public Core::Analyst3D
			{
			public:
				//! \brief 构造函数
				Skyline(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Skyline();

				//! \brief 设置/获取视线的水平方向,北向为0
				void SetViewerDirection(const double direction);
				double GetViewerDirection();

				//! \brief 设置/获取视线的俯仰角度，水平方向为0
				void SetViewerPitch(const double pitch);
				double GetViewerPitch();

				//! \brief 设置获取天际线半径
				void SetRadius(double dRadius);
				double GetRadius();

				//! \brief 设置天际线颜色
				void SetSkylineColor(const FColor& color);
				FColor GetSkylineColor() const;

				//! \brief 设置观察点位置
				void SetViewerPosition(Vector3d vPos);

				//! \brief 获取观察点位置
				Vector3d GetViewerPosition();

				//! \brief 获取二维的天际线
				GeoLine* GetSkyline2D();

				//! \brief 获取天际线
				GeoLine3D* GetSkyline(double dRadius);

				//! \brief 获取天际线体
				//! \brief 向下拉升高度
				GeoModel3D* GetSkylineSectorBody(double dHeight);

				//! \brief 获取天际线障碍建筑的图层和建筑id
				TMap<Gameint, TArray<Gameint>> GetObjectIDs();
			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief 释放
				void Release();

				//! \brief 绘制天际线
				void CreateSkyline3D(GeoLine3D* pGeoLine3D);

			private:
				//! \brief 实时绘制线(非添加状态)
				ASuperMap_ROEntityActor* m_pSkylineActor;
			private:

				//! \brief 天际线颜色
				FColor m_skylineColor;

				//! \brief 是否更新天际线
				bool m_bUpdateSkyline;

				//! \brief UGC对象
				void* m_pSkyline;
			};
		}
	}
}