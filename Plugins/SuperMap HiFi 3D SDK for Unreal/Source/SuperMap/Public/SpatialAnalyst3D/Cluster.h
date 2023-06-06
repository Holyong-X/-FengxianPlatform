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
			//! \brief 位于点集的索引号
			Gameint m_nIndex;
			//! \brief 屏幕坐标
			FVector2D m_vScreenPosition;
			//! \brief 对应UE世界坐标
			Vector3d m_vUnrealWorldPosition;
			//! \brief 是否聚类
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
			//! \brief 聚类中心点屏幕坐标
			FVector2D m_vScreenPosition;
			//! \brief 对应UE世界坐标
			Vector3d m_vUnrealWorldPosition;
			//! \brief 实体集合
			TArray<ClusteredEntity> m_Entities;
		};

		namespace SpatialAnalyst3D
		{
			//上层触发事件
			typedef void(*ClusterEvent)(void* pActor, TMap<FString, TArray<ClusteredEntities>> mapClusterEntities);
			struct SUPERMAP_API ClusterEventCallBack
			{
			public:
				void* m_pActor;
				//触发事件
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
				//! \brief 聚类像素范围
				void SetPixelRange(Gameint pixelRange);
				Gameint GetPixelRange();
				//! \brief 最小可聚类数
				void SetMinimumClusterSize(Gameint minimumClusterSize);
				Gameint GetMinimumClusterSize();
				//! \brief 是否进行聚类
				void IsEnable(Gamebool bEnable);
				Gamebool GetIsEnable();
				//! \brief 设置聚类的地理坐标点集（球面为经纬度）
				void SetGeoPositions(const TMap<FString, TArray<Vector3d>>& mapGeoPos);
				//! \brief 分配事件
				void SetClusterEventFunc(void* pActor, ClusterEvent infoEvent);
			protected:
				void DoBuild() override;

				void DoClear() override;

				void Render() override;

				//! \brief 释放
				void Release();
			private:
				//! \brief 地理坐标点集
				TMap<FString, TArray<Vector3d>> m_mapGeoPositions;
				//! \brief 聚类实体集合
				TMap<FString, TArray<ClusteredEntities>> m_mapClusteredEntities;
				//! \brief 聚类像素范围
				Gameint m_nPixelRange;

				//! \brief 最小可聚类数
				Gameint m_nMinimumClusterSize;

				// 是否开启
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