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

				//! \brief ��ȡ�����弯��
				std::vector<Collection*>& GetCollections();

				//! \brief ��Ӽ����弯��
				void AddCollection(Collection* pCollection);

			private:

				//! \brief ������ļ���
				std::vector<Collection*> m_vecCollections;
			};

		}
	}
}