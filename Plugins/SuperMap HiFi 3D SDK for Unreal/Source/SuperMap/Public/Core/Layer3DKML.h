#pragma once
#include "Layer3D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Layer3DKML : public Layer3D
			{
			public:
				Layer3DKML();
				Layer3DKML(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DKML();
			};
		}
	}
}