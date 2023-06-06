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
				//! \brief �������
				virtual bool BuildStyle();

				//! \brief ��ȡ�����������
				virtual CollectionType GetType();
			};

		}
	}
}