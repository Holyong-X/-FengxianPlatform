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
				//! \brief ʲôҲ����
				Null = 0,
				//! \brief ƽ��
				Pan = 1,
				//! \brief ��ѡ
				PointSelect = 10,
				//! \brief �༭
				Edit = 21,
				//! \brief �������
				MeasureDistance = 31,
				//! \brief �������
				MeasureArea = 32,
				//! \brief ����߶�
				MeasureHeight = 33,
				//! \brief ˮƽ����
				MeasureHorizontalDistance = 39,
				//! \brief ƽ��ѡ��
				PanSelect = 105,
				//! \brief ����ѡ��
				RectSelect = 11,
			};

			enum SUPERMAP_API UserAction
			{
				RoObjectSelect = 0,
				//! \brief �Ӷ���ѡ��
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
				//�����¼�
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
				//ʵ�ִ����¼���Actor
				void* m_pActor;
				//����
				SelectedInfo m_struDatasetModelInfo;
				//�����¼�
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

				//! \brief ���ò�������
				void SetAction(Action3D eAction);
				
				//! \brief ������Ҳ�������
				void SetUserAction(UserAction eAction);

				//! \brief ֹͣ����
				void Release();

				//! \brief ��ȡ��������
				Action3D GetAction();

				//! \brief ����������
				void OnLButtonDown();

				//! \brief ������̧��
				void OnLButtonUp();

				//! \brief ������˫��
				void OnLButtonDblClk();

				//! \brief ����Ҽ�����
				void OnRButtonDown();

				//! \brief ����Ҽ�̧��
				void OnRButtonUp();

				//! \brief �м������
				void OnMButtonDown();

				//! \brief �м��̧��
				void OnMButtonUp();

				//! \brief �м������
				void OnMouseWheel(float Value);

				//! \brief ����ƶ�
				void OnMouseMove();

				//! \brief ��ȡ������
				MeasureHandler* GetMeasureHandler();

				//! \brief �Ƿ����ѡ����Ϣ
				Gamebool IsUpdateSelectedInfo();

				void SetSelectedInfoEventFunc(void* pActor, SelectedInfoEvent infoEvent);

				void CallFunc_AttributeQuery(void* pActor, AttributeSelectEvent QAEvent);
			private:
				//! \brief ����
				void MeasureMLButtonDown();

				void MeasureMRButtonDown();

				void MeasureMMove(FVector vMouse);

				void SpawnMeasureSphere();

				void ClearMeasureSphere();

				void MeasureReferenceLine(Vector3d vPos);

				//! \brief �����������ƶ�
				void DoLButtonMove();

				//! \brief �Ƿ�ѡ��
				Gamebool IsHitTestValid();

				//! \brief ʰȡѡ��
				void HitTest();

				void HitTestRasterObject();

				//! \brief �����ѡ��
				void ReleaseSelection();

				//! \brief ��ȡ����
				Vector3d GetMousePoint();

				//! \brief ����ͼ���ѡ�����
				void SetShaderParameterForSelection(Gamebool bRenderToSelectionTexture, Gamebool bRenderAlpha);

				//! \brief ��ͼ�����ѡ��ID
				void AddSelectedObjectIDForLayer(Gameint nLayerID, Gameint nObjectID, Gamebool isRasterObject);

				//! \brief ���ƿ�ѡ��
				void RectSelectDrawFace();
			private:
				//! \brief �ο���ԭ��Index
				Gameint m_nOldIndex;

				//! \brief �Ƿ�ɱ༭�ο���
				Gamebool m_bEditSphere;

				//! \brief �ο����Ƿ��ѵ�ѡ
				Gamebool m_bSelectSphere;

				//! \brief UE�ο������
				TArray<ASuperMap_SphereActor*> arrRefSphereActor;

				//! \brief �������
				Gameint m_nMeasureIndex;

				//! \brief ��ǰѡ��ο�����������
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

				//! \brief ��ǰ����;
				FVector m_vMouse;

				//! \brief ����
				Scene* m_pScene;

				//! \brief ���״̬
				MouseButtonID m_enMouseDown;

				//! \brief ��갴��λ��
				Vector3d m_vStartPoint;
				Vector3d m_vEndPoint;

				//! \brief �Ƿ�ѡ�и���
				Gamebool m_bUpdateSelectedInfo;
				//! \brief ��ѡ��ͼ��id
				Gameint m_nSelectedLayerID;

				UMaterialInstanceDynamic* m_pMatInstanceDynamic;

				UserAction m_eUserAction;

				ASuperMap_ROEntityActor* m_pROEntityActor;

				SelectMode m_nSelectMode;
			};
		}
	}
}
