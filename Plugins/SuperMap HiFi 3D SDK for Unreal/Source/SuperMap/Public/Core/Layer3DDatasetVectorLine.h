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
			class SUPERMAP_API Layer3DDatasetVectorLine : public Layer3DDatasetVector
			{
			public:
				Layer3DDatasetVectorLine();
				Layer3DDatasetVectorLine(FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DDatasetVectorLine();

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