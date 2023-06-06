#include "Core/Layer3DKML.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Layer3DKML::Layer3DKML()
			{

			}

			Layer3DKML::Layer3DKML(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType)
				: Layer3D(pUGLayer3D, strLayerName, eLayerType)
			{

			}

			Layer3DKML::~Layer3DKML()
			{

			}
		}
	}
}