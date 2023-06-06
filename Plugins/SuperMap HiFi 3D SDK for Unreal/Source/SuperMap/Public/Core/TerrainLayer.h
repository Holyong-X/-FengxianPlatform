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

				//! \brief ��ȡ��С�߶�
				float GetMinHeight();
				
				//! \breif ��ȡ���߶�
				float GetMaxHeight();
				
				//! \brief ��ȡbounds
				Rectangle2D GetBounds();

				//! \brief ��ȡ����ͼ������
				FName GetName();

				//! \brief ���õ����Ƿ�ɼ�
				void SetIsVisible(bool bVisible);

				//! \brief ��ȡ�Ƿ�ɼ�
				bool GetIsVisible();

				//! \brief �Ƿ���ʾ��Ч����
				void SetShowInvalidation(bool bShow);

				//! \brief �Ƿ���ʾ��Ч����
				bool GetShowInvalidation();

				//! \brief ���õ�ǰͼ���LOD�㼶
				void SetLODRangeScale(float values);

				//! \brief ��ȡ��ǰͼ���LOD�㼶
				float GetLODRangeScale();

				//! \brief ��Ⱦ����
				void Render();

				//! \brief ��ȡ��Ӧ��γ�ȵ� �߶�
				Gamedouble GetHeight(Vector3d vLonLat);

			private:
				//! \brief ��С�߶�
				float m_fMinHeight;

				//! \brief ���߶�
				float m_fMaxHeight;

				//! \brief ����ͼ������
				FName m_strLayerName;
			};
		}
	}
}