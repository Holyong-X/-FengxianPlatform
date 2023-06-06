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
			class SUPERMAP_API RegionCollection : public Collection
			{
			public:
				RegionCollection(UWorld* pWorld);
				virtual ~RegionCollection();

			public:
				//! \brief 构建风格
				virtual bool BuildStyle();

				//! \brief 获取集合体的类型
				virtual CollectionType GetType();
			};

		}
	}
}