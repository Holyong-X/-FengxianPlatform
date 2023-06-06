#include "Core/Query3D.h"
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
			Query3D::Query3D()
			{
				m_pUGQuery3D = nullptr;
				_Query3D_Create(m_pUGQuery3D);
			}

			Query3D::~Query3D()
			{
				m_pUGQuery3D = nullptr;
			}

			void Query3D::Realse()
			{
				_Query3D_RealseSpatialQuery(m_pUGQuery3D);
			}

			void Query3D::SetQueryGeometry(Geometry3D* pGeometry3D)
			{
				_Query3D_SetGeometry(m_pUGQuery3D, pGeometry3D->GetHandler());
			}

			void Query3D::SetPickRect(Vector3d vStart, Vector3d vEnd)
			{
				_Query3D_SetPickRect(m_pUGQuery3D, vStart.X, vStart.Y, vEnd.X, vEnd.Y);
			}

			void Query3D::AddLayerID(Gameint nLayerID)
			{
				_Query3D_AddLayerID(m_pUGQuery3D, nLayerID);
			}

			void Query3D::UpdateRectSelect()
			{
				_Query3D_UpdateRectSelect(m_pUGQuery3D);
			}

			TMap<Gameint, TArray<Gameint> > Query3D::GetQueryIDs()
			{
				Gameint* pLayer3DIDs = nullptr;
				Gameint nCount = 0;
				Gameint** pSelectionIDs = nullptr;
				Gameint* pIDCount = nullptr;

				_Query3D_GetSpatialQueryIDs(m_pUGQuery3D, pLayer3DIDs, nCount, pSelectionIDs, pIDCount);
				TMap<Gameint, TArray<Gameint> > result;
				for (Gameint n = 0 ; n < nCount; n++)
				{
					Gameint nLayerId = pLayer3DIDs[n];
					TArray<Gameint> nSelectionIds;
					for (Gameint m = 0; m < pIDCount[n]; m++)
					{
						nSelectionIds.Add(pSelectionIDs[n][m]);
					}
					result.Add(nLayerId, nSelectionIds);
				}
				if (nCount > 0)
				{
					MathEngine::FreeUGInt(pLayer3DIDs);
					MathEngine::FreeUGInt(pIDCount);
					_ReleaseIntArray(pSelectionIDs);
				}
				return result;
			}

			void Query3D::SetPositionMode(Query3D::PositionMode nMode)
			{
				_Query3D_SetPositionMode(m_pUGQuery3D, nMode);
			}

			Query3D::PositionMode Query3D::GetPositionMode()
			{
				return (Query3D::PositionMode)_Query3D_GetPositionMode(m_pUGQuery3D);
			}

			void Query3D::RemoveLayerID(Gameint nLayerId)
			{
				_Query3D_RemoveLayerID(m_pUGQuery3D, nLayerId);
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif