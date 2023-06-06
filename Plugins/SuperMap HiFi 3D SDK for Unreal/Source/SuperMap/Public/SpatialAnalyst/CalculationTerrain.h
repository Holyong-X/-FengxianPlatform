#pragma once
#include "CoreMinimal.h"
#include "Core/RealspaceDLL.h"
#include "Data/GeoRegion.h"
#include "Base3D/CommonDefine.h"

using namespace SuperMapSDK::UnrealEngine::Data;
class UWorld;
class ASuperMap_ROEntityActor;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst
		{
			class SUPERMAP_API CalculationTerrain
			{
			public:
				//! \brief 构造函数
				CalculationTerrain();
				~CalculationTerrain();

				//! \brief  geoRegin 面 
				//! \brief  dperPixe 分辨率 
				//! \brief  baseAltitude 附加高度
				Gamebool CutFill(GeoRegion* pGeoRegion, Gamedouble dperPixel, Gamedouble baseAltitude);

				//! \brief  获取填方体积
				Gamedouble GetFillVolume();

				//! \brief  获取挖方体积
				Gamedouble GetCutVolume();

				//! \brief  获取填方面积
				Gamedouble GetFillArea();

				//! \brief  获取挖方面积
				Gamedouble GetCutArea();

				//! \brief 获取未填挖
				Gamedouble GetNoChangeArea();
			private:
				//! \brief  填方体积
				Gamedouble m_dFillVolume;
				//! \brief  挖方体积
				Gamedouble m_dCutVolume;
				//! \brief  填方面积
				Gamedouble m_dFillArea;
				//! \brief  挖方面积
				Gamedouble m_dCutArea;
				//! \brief  未填挖
				Gamedouble m_dNoChangeArea;
			};
		}
	}
}