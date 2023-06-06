#pragma once

#include "Layer3D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Layer3DServeiceMaps : public Layer3D
			{
			public:
				Layer3DServeiceMaps();
				Layer3DServeiceMaps(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DServeiceMaps();
			};
		}
	}
}