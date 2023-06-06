#include "Render/RenderObject.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			RenderObject::RenderObject()
			{
				m_pGeometry = nullptr;
				m_bInitial = false;
			}

			RenderObject::~RenderObject()
			{
				if (m_pGeometry != nullptr)
				{
					delete m_pGeometry;
				}
			}

			Geometry* RenderObject::GetGeometry()
			{
				return m_pGeometry;
			}

			void RenderObject::SetGeometry(Geometry* pGeo)
			{
				m_pGeometry = pGeo;
			}

			void RenderObject::SetWorld(UWorld* pWorld)
			{
				m_pWorld = pWorld;
			}

			void RenderObject::SetName(FString strName)
			{
				m_strName = strName;
			}

			void RenderObject::SetVisible(bool bVisible)
			{
				m_bVisible = bVisible;
			}

			void RenderObject::Render()
			{

			}
		}
	}
}