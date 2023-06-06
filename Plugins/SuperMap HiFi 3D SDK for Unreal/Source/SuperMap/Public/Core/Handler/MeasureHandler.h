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
					//! \brief �ռ����
					MeasureDistance = 0,
					//! \brief ˮƽ����
					MeasureHorizontalDistance = 1,
					//! \brief ���
					MeasureArea = 2,
					//! \brief �߶�
					MeasureHeight = 3,

				};
			public:
				//! \brief ���캯��
				MeasureHandler(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~MeasureHandler();

			private:
				//�������
				void UpdateMeasure();

				void Release();

				void UpdateMeasureArea();

				void GetTargetPointMaxHeight();

				//! \brief �������㷽ʽ
				void SetMeasureAction(MeasureAction Measureaction);
				MeasureAction GetMeasureAction();

				//! \brief ����Ŀ���
				void SetTargetPoint(Gameint nIndex, Vector3d vPoint);

				//! \brief ��ȡĿ���
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

				//! \brief ʵʱ����
				ASuperMap_ROEntityActor *m_pROEntityActor_Line;

				//! \brief ʵʱ����
				ASuperMap_ROEntityActor *m_pROEntityActor;

				//! \brief ��
				ASuperMap_ROEntityActor *m_pROEntityActor_Face;

				//! \brief ֹͣ��������
				Gamebool m_bHandlerStop;

				//! \brief ��ʱ��
				FVector m_vTemporarypoint;

				//! \brief ���������
				TArray<Vector3d> m_listTargetPos;

				//! \brief ��������
				MeasureAction m_eMeasureAction;

				//! \brief ˮƽ�����ߵ�
				Gamedouble m_dHeight;

				//\brief ˮƽ��೤��
				TArray<Gamedouble> m_arrHorizontalLength;

				//! \brief UE���ֶ���
				ASuperMap_TextActor* m_pMeasureText;

			public:

				friend class SceneEditorWnd;
			};
		}
	}
}

