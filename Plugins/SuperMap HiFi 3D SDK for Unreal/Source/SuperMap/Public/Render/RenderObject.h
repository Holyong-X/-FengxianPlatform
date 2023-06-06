#pragma once
#include "CoreMinimal.h"
#include "Data/Geometry.h"
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			class SUPERMAP_API RenderObject
			{
			public:
				RenderObject();
				virtual ~RenderObject();
			public:
				//! \brief ����UE�ĳ���������
				void SetWorld(UWorld* pWorld);

				//! \brief ��ȡ���������
				Geometry* GetGeometry();

				//! \brief ���ü��������
				void SetGeometry(Geometry* pGeo);

				//! \brief ������Ⱦ��������
				void SetName(FString strName);

				//! \brief �����Ƿ�ɼ�
				void SetVisible(bool bVisible);

			protected:
				virtual void Render();

			protected:

				//! \brief �Ƿ�ɼ�
				bool m_bVisible;

				//! \brief ��Ⱦ������
				FString m_strName;
				
				//! \brief ��Ⱦ������
				Geometry* m_pGeometry;
				
				//! \brief �Ƿ��ʼ��
				bool m_bInitial;
				
				UWorld* m_pWorld;
			};
		}
	}
}