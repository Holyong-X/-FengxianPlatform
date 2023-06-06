#pragma once

#include "CoreMinimal.h"
#include "Core/ROCache.h"
#include "Graphics3D/GameEnum.h"

using namespace SuperMapSDK::UnrealEngine::Core;

class UTextureRenderTarget2D;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			class SUPERMAP_API CustomRenderTargetInfo
			{
			public:
				CustomRenderTargetInfo();
				~CustomRenderTargetInfo();

				//! \brief ������ȾĿ��
				void SetRenderTarget(UTextureRenderTarget2D* pRenderTarget);

				//! \brief ��ȡ��ȾĿ��
				UTextureRenderTarget2D* GetRenderTarget();

				//! \brief ������������
				void SetTextureName(FString strName);

				//! \brief ���ýڵ�����
				void SetSceneNodeName(FString strName);

				//! \brief ���ó�������
				void SetSceneManagerType(SceneManagerType eType);

				//! \brief ��ȡ��������
				SceneManagerType GetSceneManagerType();

				//! \brief �����Ƿ�դ�����
				void SetIsRaster(bool bRaster);

				//! \brief ��ȡ�Ƿ�դ��
				bool GetIsRaster();

			private:
				//! \brief ��ȾĿ��
				UTextureRenderTarget2D* m_pRenderTarget;

				//! \brief �Ƿ��Ѿ�դ��
				bool m_bIsRaster;

				//! \brief ��������
				FString m_strTextureName;

				//! \brief �����ڵ�����
				FString m_strSceneNodeName;

				//! \brief ��������
				SceneManagerType m_eSceneManagerType;
			};
		}
	}
}