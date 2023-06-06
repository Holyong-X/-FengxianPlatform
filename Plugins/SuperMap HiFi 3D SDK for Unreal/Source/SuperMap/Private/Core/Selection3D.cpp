#include "Core/Selection3D.h"
#include "Core/Layer3D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Selection3D::Selection3D(Layer3D* pLayer3D)
			{
				m_pUGSelection3D = nullptr;
				m_pLayer = pLayer3D;

				_Selection3D_CreateByLayer(m_pUGSelection3D, pLayer3D->GetHandler());
			}

			Selection3D::~Selection3D()
			{
				m_pLayer = nullptr;
				Clear();
				m_pUGSelection3D = nullptr;
			}

			Layer3D* Selection3D::GetLayer()
			{
				return m_pLayer;
			}

			Gameint Selection3D::GetID(Gameint nIndex)
			{
				return _Selection3D_GetAt(m_pUGSelection3D, nIndex);
			}

			Gameint Selection3D::GetCount()
			{
				return _Selection3D_GetCount(m_pUGSelection3D);
			}

			Gameint Selection3D::Add(Gameint nID)
			{
				return _Selection3D_Add(m_pUGSelection3D, nID);
			}

			void Selection3D::Clear()
			{
				_Selection3D_Clear(m_pUGSelection3D);
			}		

			Gamebool Selection3D::FindID(Gameint nID)
			{
				return _Selection3D_FindID(m_pUGSelection3D, nID);
			}
		}
	}
}