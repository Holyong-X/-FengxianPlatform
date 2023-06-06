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
				//! \brief ���캯��
				CalculationTerrain();
				~CalculationTerrain();

				//! \brief  geoRegin �� 
				//! \brief  dperPixe �ֱ��� 
				//! \brief  baseAltitude ���Ӹ߶�
				Gamebool CutFill(GeoRegion* pGeoRegion, Gamedouble dperPixel, Gamedouble baseAltitude);

				//! \brief  ��ȡ����
				Gamedouble GetFillVolume();

				//! \brief  ��ȡ�ڷ����
				Gamedouble GetCutVolume();

				//! \brief  ��ȡ����
				Gamedouble GetFillArea();

				//! \brief  ��ȡ�ڷ����
				Gamedouble GetCutArea();

				//! \brief ��ȡδ����
				Gamedouble GetNoChangeArea();
			private:
				//! \brief  ����
				Gamedouble m_dFillVolume;
				//! \brief  �ڷ����
				Gamedouble m_dCutVolume;
				//! \brief  ����
				Gamedouble m_dFillArea;
				//! \brief  �ڷ����
				Gamedouble m_dCutArea;
				//! \brief  δ����
				Gamedouble m_dNoChangeArea;
			};
		}
	}
}