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
			class SUPERMAP_API Layer3DDatasetVectorLine : public Layer3DDatasetVector
			{
			public:
				Layer3DDatasetVectorLine();
				Layer3DDatasetVectorLine(FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DDatasetVectorLine();

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