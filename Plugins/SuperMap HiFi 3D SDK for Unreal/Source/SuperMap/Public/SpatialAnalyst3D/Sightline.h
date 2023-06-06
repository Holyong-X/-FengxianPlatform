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
				//! \brief ���캯��
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
				//! \brief ����Ŀ��۲��
				void SetViewerPosition(FVector vPos);

				//! \brief ��ȡĿ��۲��
				FVector GetViewerPosition();

				//! \brief ���ÿ����ߵ���ɫ
				void SetVisibleColor(FLinearColor color);

				//! \brief ��ȡ�����ߵ���ɫ
				FLinearColor GetVisibleColor();

				//! \brief ���ÿ����ߵ���ɫ
				void SetHiddenColor(FLinearColor color);

				//! \brief ��ȡ�����ߵ���ɫ
				FLinearColor GetHiddenColor();

				//! \brief ���Ŀ���
				void AddTargetPoint(FVector vPoint);

				//! \brief ����Ŀ���
				void SetTargetPoint(Gameint nIndex, FVector vPoint);

				//! \brief ��ȡĿ���
				FVector GetTargetPoint(Gameint nIndex);

				//! \brief �Ƴ�ָ��Ŀ���
				void RemoveTargetPoint(Gameint nIndex);

				//! \brief �Ƴ�����Ŀ���
				void RemoveAllTargetPoints();

				//! \brief ��ȡĿ���ĸ���
				Gameint GetTargetPointCount();

				//! \brief ��ȡͨ�ӽ��
				SightlineResult GetSightlineResult(Gameint nIndex);

			protected:
				void DoBuild();

				void DoClear();

				void Render();

				void AddLine(TArray<SM_Vertex>& arrVtxs, TArray<Gameint>& arrIndexs, Gameint nIndex, FColor color);

				//! \brief �ͷ�
				void Release();

				//! \brief ����ͨ�ӷ���
				void CreateSightline();

				//! \����ͨ�ӽ������
				void UpdateArrSightlineResult();

			private:
				//! \brief ʵʱ������(���״̬)
				ASuperMap_ROEntityActor* m_pROEntityActor;
			private:
				//! \brief ���ù۲��
				FVector m_vViewerPosition;

				//! \brief �Ƿ���¿�����
				Gamebool m_bUpdateSightline;

				//! \brief UGC����
				void* m_pSightline;	

				TArray<SightlineResult> m_arrSightlineResult;
			};
		}
	}
}