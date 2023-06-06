#include "Core/GlobalImage.h"
#include "Core/RealspaceDLL.h"
#include "Algorithm3D/MathEngine.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			GlobalImage::GlobalImage(Gamevoid* pUGCGlobalImage)
			{
				m_pGlobalImageUGCHandle = pUGCGlobalImage;
			}

			Gameint GlobalImage::AddExcavationRegion(Geometry* pGeometry, FString strTag)
			{
				Gamebool isVisible = _GlobalImage_GetVisible(m_pGlobalImageUGCHandle);
				_GlobalImage_SetVisible(m_pGlobalImageUGCHandle, false);
				ANSICHAR* cTag = nullptr;
				MathEngine::FStringToANSIChar(strTag, cTag);
				Gameint result = _GlobalImage_AddExcavationRegion(m_pGlobalImageUGCHandle, pGeometry->GetHandler(), cTag);
				delete[] cTag;
				cTag = nullptr;
				return result;
			}

			Gamevoid GlobalImage::ClearExcavationRegion()
			{
				_GlobalImage_ClearExcavationRegions(m_pGlobalImageUGCHandle);
			}

			FString GlobalImage::GetExcavationRegionTag(Gameint nIndex)
			{
				Gamechar* cTag = nullptr;
				_GlobalImage_GetExcavationRegionTag(m_pGlobalImageUGCHandle, nIndex, cTag);

				FName strNameTag(cTag);
				FString strSTag = strNameTag.ToString();

				delete[] cTag;
				cTag = nullptr;
				return strSTag;
			}

			Gameint GlobalImage::IndexOfExcavationRegion(FString strTag)
			{
				ANSICHAR* cTag = nullptr;
				MathEngine::FStringToANSIChar(strTag, cTag);
				delete[] cTag;
				cTag = nullptr;
				return _GlobalImage_IndexOfExcavationRegion(m_pGlobalImageUGCHandle, cTag);
			}

			Gamebool GlobalImage::RemoveExcavationRegion(Gameint nIndex)
			{
				return _GlobalImage_RemoveExcavationRegion(m_pGlobalImageUGCHandle, nIndex);
			}

			Gamebool GlobalImage::SetExcavationRegionTag(Gameint nIndex, FString strTag)
			{
				ANSICHAR* cTag = nullptr;
				MathEngine::FStringToANSIChar(strTag, cTag);
				delete[] cTag;
				cTag = nullptr;
				return _GlobalImage_SetExcavationRegionTag(m_pGlobalImageUGCHandle, nIndex, cTag);
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif