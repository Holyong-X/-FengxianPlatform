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
			class SUPERMAP_API LineCollection : public Collection
			{
			public:
				LineCollection(UWorld* pWorld);
				virtual ~LineCollection();

			public:
				//! \brief 构建风格
				virtual bool BuildStyle();

				//! \brief 获取集合体类型
				virtual CollectionType GetType();

			};

		}
	}
}