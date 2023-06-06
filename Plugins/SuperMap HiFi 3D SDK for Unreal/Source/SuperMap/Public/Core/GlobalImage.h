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

				//! \brief 设置地形裁剪区域
				Gameint AddExcavationRegion(Geometry* pGeometry, FString strTag);

				//! \brief 清空地形裁剪区域
				Gamevoid ClearExcavationRegion();

				//! \brief 获取地形裁剪区域标签
				FString GetExcavationRegionTag(Gameint nIndex);

				//! \brief 获取地形裁剪区域下标
				Gameint IndexOfExcavationRegion(FString strTag);

				//! \brief 删除地形裁剪区域
				Gamebool RemoveExcavationRegion(Gameint nIndex);

				//! \brief 设置地形裁剪区域标签
				Gamebool SetExcavationRegionTag(Gameint nIndex, FString strTag);
			private:
				Gamevoid* m_pGlobalImageUGCHandle;
			};
		}
	}
}