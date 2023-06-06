#pragma once
#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Component/SuperMap_SphereActor.h"
#include "Data/Vector3d.h"
#include "Algorithm3D/MathEngine.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Data;

class UWorld;
class ASuperMap_ROEntityActor;
class ASuperMap_SphereActor;

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
			class SUPERMAP_API Sightline : public Core::Analyst3D
			{
			public:
				//! \brief 构造函数
				Sightline(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Sightline();

				struct SightlineResult
				{
					FVector vViewerPoint;
					FVector vTargetPoint;
					FVector vBarrierPoint;
					Gamebool bVisibie;
				};

			public:
				//! \brief 设置目标观察点
				void SetViewerPosition(FVector vPos);

				//! \brief 获取目标观察点
				FVector GetViewerPosition();

				//! \brief 设置可视线的颜色
				void SetVisibleColor(FLinearColor color);

				//! \brief 获取可视线的颜色
				FLinearColor GetVisibleColor();

				//! \brief 设置可视线的颜色
				void SetHiddenColor(FLinearColor color);

				//! \brief 获取可视线的颜色
				FLinearColor GetHiddenColor();

				//! \brief 添加目标点
				void AddTargetPoint(FVector vPoint);

				//! \brief 设置目标点
				void SetTargetPoint(Gameint nIndex, FVector vPoint);

				//! \brief 获取目标点
				FVector GetTargetPoint(Gameint nIndex);

				//! \brief 移除指定目标点
				void RemoveTargetPoint(Gameint nIndex);

				//! \brief 移除所有目标点
				void RemoveAllTargetPoints();

				//! \brief 获取目标点的个数
				Gameint GetTargetPointCount();

				//! \brief 获取通视结果
				SightlineResult GetSightlineResult(Gameint nIndex);

			protected:
				void DoBuild();

				void DoClear();

				void Render();

				void AddLine(TArray<SM_Vertex>& arrVtxs, TArray<Gameint>& arrIndexs, Gameint nIndex, FColor color);

				//! \brief 释放
				void Release();

				//! \brief 绘制通视分析
				void CreateSightline();

				//! \更新通视结果数组
				void UpdateArrSightlineResult();

			private:
				//! \brief 实时绘制线(添加状态)
				ASuperMap_ROEntityActor* m_pROEntityActor;
			private:
				//! \brief 设置观察点
				FVector m_vViewerPosition;

				//! \brief 是否更新可视线
				Gamebool m_bUpdateSightline;

				//! \brief UGC对象
				void* m_pSightline;	

				TArray<SightlineResult> m_arrSightlineResult;
			};
		}
	}
}