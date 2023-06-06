#pragma once
#include "ControlUE/CameraControl.h"
#include "Data/Geometry.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/TerrainLayers.h"
#include "Component/SuperMap_SphereActor.h"
#include "Component/SuperMap_ROEntityActor.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			typedef void(*SelectedInfoEvent) (void* pActor, SelectedInfo selectedInfo);
			typedef void(*AttributeSelectEvent)(void* pActor, void* pSelectLayerHandle, Gameint nSelectID);

			enum SUPERMAP_API MouseButtonID
			{
				MB_None = 0,
				MB_Left = 1,
				MB_Right = 2,
				MB_Middle = 3
			};


			enum SUPERMAP_API Action3D
			{
				//! \brief 什么也不干
				Null = 0,
				//! \brief 平移
				Pan = 1,
				//! \brief 点选
				PointSelect = 10,
				//! \brief 编辑
				Edit = 21,
				//! \brief 量算距离
				MeasureDistance = 31,
				//! \brief 量算面积
				MeasureArea = 32,
				//! \brief 量算高度
				MeasureHeight = 33,
				//! \brief 水平量算
				MeasureHorizontalDistance = 39,
				//! \brief 平移选择
				PanSelect = 105,
				//! \brief 拉框选择
				RectSelect = 11,
			};

			enum SUPERMAP_API UserAction
			{
				RoObjectSelect = 0,
				//! \brief 子对象选择
				SubObjectSelect = 1
			};

			enum SUPERMAP_API SelectMode
			{
				Blend_VertexColor,
				Blend_EmssiveColor
			};

			struct SUPERMAP_API AttributeSelectCallBack
			{
			public:
				void* m_pActor;
				//触发事件
				AttributeSelectEvent Event;
				void* m_pSelectLayerHandle;
				Gameint m_nSelectID;
			public:
				AttributeSelectCallBack()
				{
					m_pActor = nullptr;
					m_pSelectLayerHandle = nullptr;
					m_nSelectID = -1;
				}
				void Execute()
				{
					if (m_pActor == nullptr)
					{
						return;
					}
					Event(m_pActor,m_pSelectLayerHandle,m_nSelectID);
				}
			};

			struct SUPERMAP_API SelectedEventInfos
			{
			public:
				//实现触发事件的Actor
				void* m_pActor;
				//数据
				SelectedInfo m_struDatasetModelInfo;
				//触发事件
				SelectedInfoEvent m_SelectedInfoEvent;
			public:
				SelectedEventInfos()
				{
					m_pActor = nullptr;
				}
			};

			class MeasureHandler;
			class SUPERMAP_API SceneEditorWnd
			{
			public:
				SceneEditorWnd(Scene* pScene);
				~SceneEditorWnd();

				//! \brief 设置操作类型
				void SetAction(Action3D eAction);
				
				//! \brief 设置玩家操作类型
				void SetUserAction(UserAction eAction);

				//! \brief 停止运行
				void Release();

				//! \brief 获取操作类型
				Action3D GetAction();

				//! \brief 鼠标左键按下
				void OnLButtonDown();

				//! \brief 鼠标左键抬起
				void OnLButtonUp();

				//! \brief 鼠标左键双击
				void OnLButtonDblClk();

				//! \brief 鼠标右键按下
				void OnRButtonDown();

				//! \brief 鼠标右键抬起
				void OnRButtonUp();

				//! \brief 中间键按下
				void OnMButtonDown();

				//! \brief 中间键抬起
				void OnMButtonUp();

				//! \brief 中间键滑动
				void OnMouseWheel(float Value);

				//! \brief 鼠标移动
				void OnMouseMove();

				//! \brief 获取量算类
				MeasureHandler* GetMeasureHandler();

				//! \brief 是否更新选中信息
				Gamebool IsUpdateSelectedInfo();

				void SetSelectedInfoEventFunc(void* pActor, SelectedInfoEvent infoEvent);

				void CallFunc_AttributeQuery(void* pActor, AttributeSelectEvent QAEvent);
			private:
				//! \brief 量算
				void MeasureMLButtonDown();

				void MeasureMRButtonDown();

				void MeasureMMove(FVector vMouse);

				void SpawnMeasureSphere();

				void ClearMeasureSphere();

				void MeasureReferenceLine(Vector3d vPos);

				//! \brief 鼠标左键按下移动
				void DoLButtonMove();

				//! \brief 是否选中
				Gamebool IsHitTestValid();

				//! \brief 拾取选中
				void HitTest();

				void HitTestRasterObject();

				//! \brief 清除非选中
				void ReleaseSelection();

				//! \brief 获取鼠标点
				Vector3d GetMousePoint();

				//! \brief 更新图层的选择材质
				void SetShaderParameterForSelection(Gamebool bRenderToSelectionTexture, Gamebool bRenderAlpha);

				//! \brief 给图层添加选中ID
				void AddSelectedObjectIDForLayer(Gameint nLayerID, Gameint nObjectID, Gamebool isRasterObject);

				//! \brief 绘制框选框
				void RectSelectDrawFace();
			private:
				//! \brief 参考球原先Index
				Gameint m_nOldIndex;

				//! \brief 是否可编辑参考球
				Gamebool m_bEditSphere;

				//! \brief 参考球是否已点选
				Gamebool m_bSelectSphere;

				//! \brief UE参考球对象
				TArray<ASuperMap_SphereActor*> arrRefSphereActor;

				//! \brief 量算序号
				Gameint m_nMeasureIndex;

				//! \brief 当前选择参考球的量算序号
				Gameint m_nSphereMeasureIndex;

				MeasureHandler* m_pRuler;

				Action3D m_eAction3D;

				Gameint m_nMouseLeftDown;

				Layer3DS3MFile* m_pLayer3DS3MFile;

				TerrainLayers* m_pTerrainLayers;

				TArray<MeasureHandler*> m_arrRuler;

				SelectedEventInfos m_SelectedEventInfos;

				AttributeSelectCallBack m_AttributeSelectEvent;

				Vector3d m_vRealPosition;

				Gamebool m_bErrorPosition;

				//! \brief 当前鼠标点;
				FVector m_vMouse;

				//! \brief 场景
				Scene* m_pScene;

				//! \brief 鼠标状态
				MouseButtonID m_enMouseDown;

				//! \brief 鼠标按下位置
				Vector3d m_vStartPoint;
				Vector3d m_vEndPoint;

				//! \brief 是否选中更新
				Gamebool m_bUpdateSelectedInfo;
				//! \brief 被选中图层id
				Gameint m_nSelectedLayerID;

				UMaterialInstanceDynamic* m_pMatInstanceDynamic;

				UserAction m_eUserAction;

				ASuperMap_ROEntityActor* m_pROEntityActor;

				SelectMode m_nSelectMode;
			};
		}
	}
}
