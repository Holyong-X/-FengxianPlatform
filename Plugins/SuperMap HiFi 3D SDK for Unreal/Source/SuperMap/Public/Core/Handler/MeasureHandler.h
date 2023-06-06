// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "Data/Vector3d.h"
#include "Data/GeoRegion3D.h"
#include "ControlUE/CameraControl.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Component/SuperMap_TextActor.h"
/**
 *
 */
using namespace SuperMapSDK::UnrealEngine::Data;

class UWorld;
class ASuperMap_ROEntityActor;
class ASuperMap_TextActor;

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
			
			class SUPERMAP_API MeasureHandler
			{
			public:
				enum MeasureAction
				{
					//! \brief 空间距离
					MeasureDistance = 0,
					//! \brief 水平距离
					MeasureHorizontalDistance = 1,
					//! \brief 面积
					MeasureArea = 2,
					//! \brief 高度
					MeasureHeight = 3,

				};
			public:
				//! \brief 构造函数
				MeasureHandler(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~MeasureHandler();

			private:
				//结果绘制
				void UpdateMeasure();

				void Release();

				void UpdateMeasureArea();

				void GetTargetPointMaxHeight();

				//! \brief 设置量算方式
				void SetMeasureAction(MeasureAction Measureaction);
				MeasureAction GetMeasureAction();

				//! \brief 设置目标点
				void SetTargetPoint(Gameint nIndex, Vector3d vPoint);

				//! \brief 获取目标点
				FVector GetTargetPoint(Gameint nIndex);

				void AddTargetPoint(Vector3d vPoint);

				Gameint GetTargetPointCount();

				void MeasureAreaEnd();

				void RemoveTargetPoint(Gameint nIndex);

				FVector CalculateForHorizontal(Vector3d Target);

				void SetHandlerStop(Gamebool bStop);

				Gamebool GetHandlerStop();
			public:

				Gamedouble GetArea();

				Gamedouble GetHeight();

				TArray<Gamedouble> GetCurLength();

			private:

				//! \brief 实时绘制
				ASuperMap_ROEntityActor *m_pROEntityActor_Line;

				//! \brief 实时绘制
				ASuperMap_ROEntityActor *m_pROEntityActor;

				//! \brief 面
				ASuperMap_ROEntityActor *m_pROEntityActor_Face;

				//! \brief 停止分析操作
				Gamebool m_bHandlerStop;

				//! \brief 临时点
				FVector m_vTemporarypoint;

				//! \brief 对象点数组
				TArray<Vector3d> m_listTargetPos;

				//! \brief 量算类型
				MeasureAction m_eMeasureAction;

				//! \brief 水平测距最高点
				Gamedouble m_dHeight;

				//\brief 水平测距长度
				TArray<Gamedouble> m_arrHorizontalLength;

				//! \brief UE绘字对象
				ASuperMap_TextActor* m_pMeasureText;

			public:

				friend class SceneEditorWnd;
			};
		}
	}
}

