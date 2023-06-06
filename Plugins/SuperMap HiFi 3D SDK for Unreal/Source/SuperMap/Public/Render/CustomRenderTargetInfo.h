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

				//! \brief 设置渲染目标
				void SetRenderTarget(UTextureRenderTarget2D* pRenderTarget);

				//! \brief 获取渲染目标
				UTextureRenderTarget2D* GetRenderTarget();

				//! \brief 设置纹理名称
				void SetTextureName(FString strName);

				//! \brief 设置节点名称
				void SetSceneNodeName(FString strName);

				//! \brief 设置场景类型
				void SetSceneManagerType(SceneManagerType eType);

				//! \brief 获取场景类型
				SceneManagerType GetSceneManagerType();

				//! \brief 设置是否栅格化完成
				void SetIsRaster(bool bRaster);

				//! \brief 获取是否栅格化
				bool GetIsRaster();

			private:
				//! \brief 渲染目标
				UTextureRenderTarget2D* m_pRenderTarget;

				//! \brief 是否已经栅格化
				bool m_bIsRaster;

				//! \brief 纹理名称
				FString m_strTextureName;

				//! \brief 场景节点名称
				FString m_strSceneNodeName;

				//! \brief 场景类型
				SceneManagerType m_eSceneManagerType;
			};
		}
	}
}