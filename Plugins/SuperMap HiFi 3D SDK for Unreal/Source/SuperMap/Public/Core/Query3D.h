#pragma once

#include "CoreMinimal.h"
#include "Core/Analyst3D.h"
#include "Base3D/CommonDefine.h"
#include "Data/Vector3d.h"
#include "Data/Geometry3D.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Base3D;
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API Query3D
			{
			public:
				enum PositionMode
				{
					//! \brief ����
					Disjoint3D = 0,
					//! \brief �ཻ
					Intersects3D = 1,
					//! \brief ����
					Contains3D = 2,
				};
			public:
				//! \brief ���캯��
				Query3D();
				~Query3D();

				//! \brief ���ÿռ��ѯ���ζ���
				void SetQueryGeometry(Geometry3D* pGeometry3D);

				//! \brief ����ѡ������
				void SetPickRect(Vector3d vStart, Vector3d vEnd);

				//! \brief ���ü��β�ѯ��λ�ù�ϵ
				void SetPositionMode(Query3D::PositionMode nMode);

				//! \brief ��ȡ���β�ѯ��λ�ù�ϵ
				Query3D::PositionMode GetPositionMode();

				//! \brief ���ù���ͼ��
				void AddLayerID(Gameint nLayerID);

				//! \brief ����ѡ������
				void UpdateRectSelect();

				//! \brief ��ȡѡ�е�����ID
				TMap<Gameint, TArray<Gameint> > GetQueryIDs();

				//! \brief �Ƴ��ռ��ѯͼ��ID��
				void RemoveLayerID(Gameint nLayerId);

				//! \brief �ռ��ѯ����
				void Realse();
			private:
				void* m_pUGQuery3D;
			};
		}
	}
}