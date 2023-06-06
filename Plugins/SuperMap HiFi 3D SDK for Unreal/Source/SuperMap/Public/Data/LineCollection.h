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
				//! \brief �������
				virtual bool BuildStyle();

				//! \brief ��ȡ����������
				virtual CollectionType GetType();

			};

		}
	}
}