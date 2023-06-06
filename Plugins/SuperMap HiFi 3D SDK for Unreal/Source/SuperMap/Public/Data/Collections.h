#pragma once

#include "CoreMinimal.h"
#include <vector>

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			class Collection;
			class SUPERMAP_API Collections
			{
			public:
				Collections();
				~Collections();

				//! \brief 获取集合体集合
				std::vector<Collection*>& GetCollections();

				//! \brief 添加集合体集合
				void AddCollection(Collection* pCollection);

			private:

				//! \brief 集合体的集合
				std::vector<Collection*> m_vecCollections;
			};

		}
	}
}