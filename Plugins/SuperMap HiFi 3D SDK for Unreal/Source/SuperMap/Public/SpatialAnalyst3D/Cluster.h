#pragma once
#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Core/RealspaceDLL.h"
#include "Core/SceneType.h"
#include "Core/Scene.h"
#include "ControlUE/CameraControl.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Data/Matrix4d.h"
#include "Data/GeoModel3D.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK::UnrealEngine::Data;

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

		struct SUPERMAP_API ClusteredEntity
		{
		public:
			//! \brief λ�ڵ㼯��������
			Gameint m_nIndex;
			//! \brief ��Ļ����
			FVector2D m_vScreenPosition;
			//! \brief ��ӦUE��������
			Vector3d m_vUnrealWorldPosition;
			//! \brief �Ƿ����
			Gamebool m_bCluster;

		public:
			ClusteredEntity()
			{
				m_nIndex = -1;
				m_vScreenPosition = FVector2D(0, 0);
				m_vUnrealWorldPosition = Vector3d(0,0,0);
				m_bCluster = false;
			}
		};

		struct SUPERMAP_API ClusteredEntities
		{
		public:
			//! \brief �������ĵ���Ļ����
			FVector2D m_vScreenPosition;
			//! \brief ��ӦUE��������
			Vector3d m_vUnrealWorldPosition;
			//! \brief ʵ�弯��
			TArray<ClusteredEntity> m_Entities;
		};

		namespace SpatialAnalyst3D
		{
			//�ϲ㴥���¼�
			typedef void(*ClusterEvent)(void* pActor, TMap<FString, TArray<ClusteredEntities>> mapClusterEntities);
			struct SUPERMAP_API ClusterEventCallBack
			{
			public:
				void* m_pActor;
				//�����¼�
				ClusterEvent Event;
			public:
				ClusterEventCallBack()
				{
					m_pActor = nullptr;
				}
			};

			class SUPERMAP_API Cluster : public Core::Analyst3D
			{
			public:
				Cluster(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl);
				virtual ~Cluster();
			public:
				//! \brief �������ط�Χ
				void SetPixelRange(Gameint pixelRange);
				Gameint GetPixelRange();
				//! \brief ��С�ɾ�����
				void SetMinimumClusterSize(Gameint minimumClusterSize);
				Gameint GetMinimumClusterSize();
				//! \brief �Ƿ���о���
				void IsEnable(Gamebool bEnable);
				Gamebool GetIsEnable();
				//! \brief ���þ���ĵ�������㼯������Ϊ��γ�ȣ�
				void SetGeoPositions(const TMap<FString, TArray<Vector3d>>& mapGeoPos);
				//! \brief �����¼�
				void SetClusterEventFunc(void* pActor, ClusterEvent infoEvent);
			protected:
				void DoBuild() override;

				void DoClear() override;

				void Render() override;

				//! \brief �ͷ�
				void Release();
			private:
				//! \brief ��������㼯
				TMap<FString, TArray<Vector3d>> m_mapGeoPositions;
				//! \brief ����ʵ�弯��
				TMap<FString, TArray<ClusteredEntities>> m_mapClusteredEntities;
				//! \brief �������ط�Χ
				Gameint m_nPixelRange;

				//! \brief ��С�ɾ�����
				Gameint m_nMinimumClusterSize;

				// �Ƿ���
				Gamebool m_bEnable;

				ClusterEventCallBack m_ClusterEvent;

				FVector m_vlastCameraLocation;
				FRotator m_vlastCameraRotator;
			private:
				Gamebool GetScreenSpacePosition(Vector3d& geoPos, ClusteredEntity& clusteredEntity);

				void DoCluster();
			};
		}
	}
}