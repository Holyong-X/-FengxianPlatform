#pragma once

#include "CoreMinimal.h"

class UWorld;
class UStaticMesh;
class ASuperMap_InstancedActor;
class ASuperMap_ROEntityActor;
class ASuperMap_SplineActor;

using namespace SuperMapSDK::UnrealEngine::Data;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			//! \brief 集合体风格参数
			struct SUPERMAP_API StyleParam
			{
			public:
				//! \brief 外挂资产名称
				FString m_strAssetResoureName;

				//! \brief 外挂资产引用路径
				FString m_strAssetResourePath;

				//外挂资产的间隔
				float m_fDistance;
			}; 

			class SUPERMAP_API AssetStyle
			{
			public:
				AssetStyle(UWorld* pWorld);
				virtual ~AssetStyle();

			public:

				//! \brief 设置风格参数
				void SetStyleParam(StyleParam & styleParam);

				//! \brief 获取风格参数
				StyleParam& GetStyleParam();

				bool BuildStyle(TArray<Vector3d> arrLocations);

				bool BuildStyle(TArray<FVector> arrLocations);

				bool BuildSubdivisionStyle(TArray<FVector> arrLocations);

				bool BuildStyle(TArray<FVector> arrPositions, TArray<int32> arrIndexs);

				bool BuildStyle(TArray<Vector3d> arrPositions, TArray<int32> arrIndexs);

				bool BuildStyle(TArray<TArray<Vector3d>> arrLinesPts);

			protected:
				//! \brief 加载StaticMesh
				UStaticMesh* CreateStaticMesh(FString strAssetPath);

				//! \brief 计算球面的旋转量
				FQuat CallRotator(FVector vDirectionUP);
			private:

				void GetSubdivisionPoints(TArray<TArray<Vector3d>>& pots1, TArray<TArray<Vector3d>>& pots2);
			protected:
				//! \brief 集合体风格
				StyleParam m_StyleParam;

				//! \brief UE的场景管理器
				UWorld* m_pWorld;

				//! \brief 实例化渲染对象
				ASuperMap_InstancedActor* m_pInstancedActor;

				ASuperMap_ROEntityActor* m_pROEntityActor;

				ASuperMap_SplineActor* m_pSplineActor;
			};

		}
	}
}