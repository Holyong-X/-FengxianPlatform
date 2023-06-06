#pragma once

#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Data/Vector3d.h"
#include "Data/Matrix4d.h"
#include "Data/GeoLine3D.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Data;

class UWorld;
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
			
			class SUPERMAP_API Facade : public Analyst3D
			{
			public:
				//! \brief 构造函数
				Facade(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Facade();

				//! \brief 设置/获取输出文件路径
				void SetOutputPath(FString strOutputPath);
				FString GetOutputPath();

				//! \brief 设置观察线
				void SetViewLine(GeoLine3D* pGeoLine3D);

				//! \brief 设置出图参数
				void SetResolution(Gamedouble dResolution);
				void SetVisibleHeight(Gamedouble dMin, Gamedouble dMax);
				void SetVisibleFarDistance(Gamedouble dFar);

				//! \brief 获取出图参数
				Gamedouble GetResolution();
				void GetVisibleHeight(Gamedouble &dMin, Gamedouble &dMax);
				Gamedouble GetVisibleFarDistance();

			protected:
				void DoBuild();

				void DoClear();

				void Render();

				//! \brief 释放
				void Release();
			private:
				//! \brief 观察路径
				GeoLine3D* m_pGeoLine3D;

				//! \brief 输出路径
				FString m_strOutputPath;

				//! \brief 出图的分辨率
				Gamedouble m_dResolution;

				//! \brief 可见的最小高度
				Gamedouble m_dMinHeight;

				//! \brief 可见的最大高度
				Gamedouble m_dMaxHeight;

				//! \brief 可见的最远距离
				Gamedouble m_dFarDist;

				//! \brief 是否出图
				Gamebool m_bOutput;
			};
		}
	}
}