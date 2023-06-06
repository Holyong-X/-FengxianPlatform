#pragma once

#include "CoreMinimal.h"
#include "Core/Layer3DDatasetVector.h"

class UWorld;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Layer3DDatasetVectorPoint : public Layer3DDatasetVector
			{
			public:
				Layer3DDatasetVectorPoint();
				Layer3DDatasetVectorPoint(FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DDatasetVectorPoint();

			public:
				//! \brief �������
				virtual bool BuildStyle(UWorld* pWorld);

				//! \brief ��ȡ����
				virtual DatasetType GetType();

				//! \brief ��Ⱦ����
				virtual void Render(UWorld* pWorld);
			};

		}
	}
}