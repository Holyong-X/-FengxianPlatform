#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class Layer3D;
			class Layer3DS3MFile;
			class SUPERMAP_API Selection3D
			{
			public:
				friend class Layer3DS3MFile;
			private:
				//! \brief ������ͼ��
				Layer3D* m_pLayer;

				//! \brief UGC���
				void* m_pUGSelection3D;
			public:
				Selection3D(Layer3D* pLayer3D);
				~Selection3D();

				//! \brief ��ȡ����ͼ��
				Layer3D* GetLayer();

				//! \brief ����������ȡѡ��ID
				Gameint GetID(Gameint nIndex);

				//! \brief ��ȡѡ���ж�����Ŀ
				Gameint GetCount();

				//! \brief ���ID
				Gameint Add(Gameint nID);
				
				//! \brief �������ID
				void Clear();

				//! \brief ����ID
				Gamebool FindID(Gameint nID);
			};
		}
	}
}