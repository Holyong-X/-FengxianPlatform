#pragma once

#include "CoreMinimal.h"
#include "Data/Collection.h"
#include "Core/RealspaceDLL.h"

class UWorld;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class SUPERMAP_API PointCollection : public Collection
			{
			public:
				PointCollection(UWorld* pWorld);
				virtual ~PointCollection();

			public:
				//! \brief 构建风格
				virtual bool BuildStyle();

				//! \brief 获取集合体类型
				virtual CollectionType GetType();
			};

		}
	}
}