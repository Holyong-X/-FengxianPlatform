#pragma once

#include "CoreMinimal.h"
#include "Core/Layer3D.h"
#include "Data/Geometry.h"

using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class SUPERMAP_API TrackingLayer : public Layer3D
			{
			public:
				TrackingLayer();
				virtual ~TrackingLayer();

			public:
				//! \brief ���Geometry���ζ���
				int32 AddGeometry(Geometry* pGeometry, FString strTag);

				//! \brief �Ƴ�ͼ����ָ����ŵĶ���
				bool Remove(int32 nIndex);

				//! \brief ����ͼ����ָ����ŵļ�����
				Geometry* Get(int32 nIndex);

				//! \brief ��ȡָ����Ŷ���ı�ǩ��
				FString GetTag(int32 nIndex);

				//! \brief ����ͼ����ָ����ŵĶ���ı�ǩ��
				void Clear();

				//! \brief ����ָ����ǩ����������
				int32 IndexOf(FString strTag);

				//! \brief ͼ���ж���ĸ���
				int32 GetCount();

				//! \brief ���ͼ�����Ⱦ����
				virtual void AddNativeGameComponent(GameComponent* pGameComponent);
				//! \brief �Ƴ�ͼ�����Ⱦ����
				virtual void RemoveNativeGameComponent(GameComponent* pGameComponent);
			private:
				void UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent);

				//! \brief ����ͼ�����
				void UpdateMaterialInfo(GameMaterial* pGameMaterial);
			};

		}
	}
}