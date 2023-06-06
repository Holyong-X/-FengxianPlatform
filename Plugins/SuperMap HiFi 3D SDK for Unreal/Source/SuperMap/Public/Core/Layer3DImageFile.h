#pragma once

#include "Layer3D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Layer3DImageFile : public Layer3D
			{
			public:
				Layer3DImageFile();
				Layer3DImageFile(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DImageFile();

				void SetOpaqueRate(Gamedouble value);
				Gamedouble GetOpaqueRate();
			};
		}
	}
}