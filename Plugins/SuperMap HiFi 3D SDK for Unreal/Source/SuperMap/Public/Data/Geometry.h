#pragma once

#include "CoreMinimal.h"
#include "Data/GeometryType.h"
#include "Core/Style3D.h"
#include "Data/Rectangle2D.h"

using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{

			class SUPERMAP_API Geometry
			{
			public:
				Geometry();
				virtual ~Geometry();
			public:
				//! \brief ��������
				virtual GeometryType GetType() = 0;

				//! \brief ����UGC���
				virtual void* GetHandler();

				//! \brief ������Ⱦ����
				virtual void SetRenderFeature(void* pRenderFeature);

				//! \brief ��ȡStyle3D
				Style3D* GetStyle3D();

				//! \brief ����Style3D
				void SetStyle3D(Style3D* pStyle);

				//! \brief ��ȡbounds
				Rectangle2D GetBounds();
			protected:
				void* m_pUGGeometry;
				void* m_pRenderFeature;
			};
		}
	}
}