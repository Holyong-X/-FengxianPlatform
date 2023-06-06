#pragma once

#include "CoreMinimal.h"
#include "Core/Layer3DDatasetVector.h"

class UWorld;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Layer3DDatasetVectorPoint : public Layer3DDatasetVector
			{
			public:
				Layer3DDatasetVectorPoint();
				Layer3DDatasetVectorPoint(FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DDatasetVectorPoint();

			public:
				//! \brief 构建风格
				virtual bool BuildStyle(UWorld* pWorld);

				//! \brief 获取类型
				virtual DatasetType GetType();

				//! \brief 渲染数据
				virtual void Render(UWorld* pWorld);
			};

		}
	}
}