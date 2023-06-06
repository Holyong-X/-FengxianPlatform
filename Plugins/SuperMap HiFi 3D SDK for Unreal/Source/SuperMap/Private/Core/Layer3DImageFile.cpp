#include "Core/Layer3DImageFile.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Layer3DImageFile::Layer3DImageFile()
			{
			}

			Layer3DImageFile::Layer3DImageFile(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType) :Layer3D(pUGLayer3D, strLayerName, eLayerType)
			{

			}

			Layer3DImageFile::~Layer3DImageFile()
			{

			}

			void Layer3DImageFile::SetOpaqueRate(Gamedouble value)
			{
				_Layer3D_SetOpaqueRate(GetHandler(), value);
			}

			Gamedouble Layer3DImageFile::GetOpaqueRate()
			{
				return _Layer3D_GetOpaqueRate(GetHandler());
			}
		}
	}
}