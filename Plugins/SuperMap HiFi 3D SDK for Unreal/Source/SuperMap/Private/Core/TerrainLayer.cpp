#include "Core/TerrainLayer.h"
#include "Core/Public/Misc/Paths.h"
#include "Component/SuperMap_MeshComponent.h"
#include "ControlUE/CameraControl.h"
#include "Core/ROCacheManager.h"
#include "Materials/MaterialInstanceDynamic.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			TerrainLayer::TerrainLayer(FName strLayerName)
			{
				m_fMinHeight = -200;
				m_fMaxHeight = 2000;
				m_strLayerName = strLayerName;
			}

			TerrainLayer::~TerrainLayer()
			{
				
			}

			float TerrainLayer::GetMinHeight()
			{
				m_fMinHeight = _GetMinHeight();
				return m_fMinHeight;
			}			

			float TerrainLayer::GetMaxHeight()
			{
				m_fMaxHeight = _GetMaxHeight();
				return m_fMaxHeight;
			}
			
			Rectangle2D TerrainLayer::GetBounds()
			{
				Rectangle2D rect2d;

				float left;
				float bottom;
				float right;
				float top;
				_GetTerrainBounds(left, bottom, right, top);

				rect2d.Left   = left;
				rect2d.Bottom = bottom;
				rect2d.Right  = right;
				rect2d.Top    = top;
				return rect2d;
			}

			FName TerrainLayer::GetName()
			{
				return m_strLayerName;
			}

			void TerrainLayer::SetIsVisible(bool bVisible)
			{
				if (_SetTerrainVisible != nullptr)
				{
					FString strLayerName = m_strLayerName.ToString();

					const TCHAR* c = *strLayerName;
					ANSICHAR* cc = TCHAR_TO_UTF8(c);

					_SetTerrainVisible(bVisible, cc);
				}
			}

			bool TerrainLayer::GetIsVisible()
			{
				if (_GetTerrainVisible != nullptr)
				{
					FString strLayerName = m_strLayerName.ToString();

					const TCHAR* c = *strLayerName;
					ANSICHAR* cc = TCHAR_TO_UTF8(c);

					return _GetTerrainVisible(cc);
				}

				return false;
			}

			void TerrainLayer::SetShowInvalidation(bool bShow)
			{
				if (_SetShowInvalidation != nullptr)
				{
					_SetShowInvalidation(bShow);
				}
				
			}

			bool TerrainLayer::GetShowInvalidation()
			{
				if (_GetShowInvalidation != nullptr)
				{
					return _GetShowInvalidation();
				}
				return true;
			}

			void TerrainLayer::SetLODRangeScale(float values)
			{
				if (_SetTerrainLODRangeScale != nullptr)
				{
					_SetTerrainLODRangeScale(values);
				}
			}

			float TerrainLayer::GetLODRangeScale()
			{
				if (_GetTerrainLODRangeScale != nullptr)
				{
					return _GetTerrainLODRangeScale();
				}
				return -1;
			}

			Gamedouble TerrainLayer::GetHeight(Vector3d vLonLat)
			{
				return _TerrainLayer_GetHeight(vLonLat.X, vLonLat.Y);
			}

			void TerrainLayer::Render()
			{
				
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif