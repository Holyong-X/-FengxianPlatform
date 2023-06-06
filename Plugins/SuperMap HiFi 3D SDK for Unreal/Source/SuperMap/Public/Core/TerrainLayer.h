#pragma once

#include "CoreMinimal.h"
#include "Data/Rectangle2D.h"
#include "Core/RealspaceDLL.h"
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API TerrainLayer
			{
			public:
				TerrainLayer(FName strLayerName);
				~TerrainLayer();

				//! \brief 获取最小高度
				float GetMinHeight();
				
				//! \breif 获取最大高度
				float GetMaxHeight();
				
				//! \brief 获取bounds
				Rectangle2D GetBounds();

				//! \brief 获取地形图层名字
				FName GetName();

				//! \brief 设置地形是否可见
				void SetIsVisible(bool bVisible);

				//! \brief 获取是否可见
				bool GetIsVisible();

				//! \brief 是否显示无效区域
				void SetShowInvalidation(bool bShow);

				//! \brief 是否显示无效区域
				bool GetShowInvalidation();

				//! \brief 设置当前图层的LOD层级
				void SetLODRangeScale(float values);

				//! \brief 获取当前图层的LOD层级
				float GetLODRangeScale();

				//! \brief 渲染数据
				void Render();

				//! \brief 获取对应经纬度的 高度
				Gamedouble GetHeight(Vector3d vLonLat);

			private:
				//! \brief 最小高度
				float m_fMinHeight;

				//! \brief 最大高度
				float m_fMaxHeight;

				//! \brief 地形图层名字
				FName m_strLayerName;
			};
		}
	}
}