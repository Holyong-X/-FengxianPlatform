#include "Render/CustomRenderTargetInfo.h"
#include "Engine/TextureRenderTarget2D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Render
		{
			CustomRenderTargetInfo::CustomRenderTargetInfo()
			{
				m_pRenderTarget     = nullptr;
				m_eSceneManagerType = DRAW3D;
				m_bIsRaster         = false;
			}
			CustomRenderTargetInfo::~CustomRenderTargetInfo()
			{
				if (m_pRenderTarget != nullptr)
				{
					m_pRenderTarget->RemoveFromRoot();
					m_pRenderTarget = nullptr;
				}
			}

			void CustomRenderTargetInfo::SetRenderTarget(UTextureRenderTarget2D* pRenderTarget)
			{
				m_pRenderTarget = pRenderTarget;
			}

			UTextureRenderTarget2D* CustomRenderTargetInfo::GetRenderTarget()
			{
				return m_pRenderTarget;
			}

			void CustomRenderTargetInfo::SetTextureName(FString strName)
			{
				m_strTextureName = strName;
			}

			void CustomRenderTargetInfo::SetSceneNodeName(FString strName)
			{
				m_strSceneNodeName = strName;
			}

			SceneManagerType CustomRenderTargetInfo::GetSceneManagerType()
			{
				return m_eSceneManagerType;
			}

			void CustomRenderTargetInfo::SetSceneManagerType(SceneManagerType eType)
			{
				m_eSceneManagerType = eType;
			}

			void CustomRenderTargetInfo::SetIsRaster(bool bRaster)
			{
				m_bIsRaster = bRaster;
			}

			bool CustomRenderTargetInfo::GetIsRaster()
			{
				return m_bIsRaster;
			}
		}
	}
}