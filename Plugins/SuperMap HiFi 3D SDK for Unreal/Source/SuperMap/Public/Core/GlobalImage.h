#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Data/Geometry.h"

using namespace SuperMapSDK;
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{

			class SUPERMAP_API GlobalImage
			{
			public:
				GlobalImage(Gamevoid* pUGCGlobalImage);

				//! \brief ���õ��βü�����
				Gameint AddExcavationRegion(Geometry* pGeometry, FString strTag);

				//! \brief ��յ��βü�����
				Gamevoid ClearExcavationRegion();

				//! \brief ��ȡ���βü������ǩ
				FString GetExcavationRegionTag(Gameint nIndex);

				//! \brief ��ȡ���βü������±�
				Gameint IndexOfExcavationRegion(FString strTag);

				//! \brief ɾ�����βü�����
				Gamebool RemoveExcavationRegion(Gameint nIndex);

				//! \brief ���õ��βü������ǩ
				Gamebool SetExcavationRegionTag(Gameint nIndex, FString strTag);
			private:
				Gamevoid* m_pGlobalImageUGCHandle;
			};
		}
	}
}