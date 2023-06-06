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
				//! \brief �������
				virtual bool BuildStyle();

				//! \brief ��ȡ����������
				virtual CollectionType GetType();
			};

		}
	}
}