#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEnum.h"
#include "Core/RealspaceDLL.h"
#include "Component/CustomRealRasterMesh.h"

namespace SuperMapSDK
{
	class GameCamera;
	class GameComponent;
	class SUPERMAP_API GameRenderTexture
	{
	public:
		GameRenderTexture(Gamelong nTextureName, FString strSceneName, SceneManagerType sceneManagerType, int32 nWidth, int32 nHeight, int32 nFormat);
		~GameRenderTexture();
	public:
		//! \brief 获取场景类型
		SceneManagerType GetSceneManagerType();

		//! \brief 将渲染对象添加到对应类型的renderTexture上
		void AddGameComponent(GameComponent* pGameComponent);

		//! \brief 将渲染对象从renderTexture上移除
		void RemoveGameComponent(GameComponent* pGameComponent);

		//! \brief 获取纹理像素
		void* GetFrameBuffer(int32 nXOffset, int32 nYOffset, int32 nWidth, int32 nHeight, int32& nBufferSize);

		//! \brief 渲染场景
		void UpdateScene();

		//! \brief 获取对象句柄
		Gamelong GetHandle();

		//! \brief 获取关联的相机对象句柄
		void* GetCameraHandle();

		//! \brief 获取渲染目标
		UTextureRenderTarget2D* GetRenderTarget();

		//! \brief 获取倾斜模型压平开挖渲染目标
		UTextureRenderTarget2D* GetFlattenRenderTarget();

		//! \brief 获取场景名称
		FString GetSceneName();

		//! \brief 空间查询渲染对像
		void RenderObjectWithSpatialQuery();
	private:
		// 将渲染队列里的对象以实时栅格化的方式绘制到当前的纹理上
		void RealtimeRaster();

		void RealtimeRasterFlattenRegion();

		void RealtimeRasterExcavationRegion();

		void RealtimeRasterImage(TArray<CustomRealRasterMesh*> arrRasterMesh, TArray<FVector4> transforms, TArray<Gamelong> textureNames);

		//! \brief 创建渲染目标
		void CreateRenderTarget(UTextureRenderTarget2D* &pRenderTarget);

		//! \brief 更新图层的选择材质
		void SetShaderParameterForSelection(Gamebool bRenderToSelectionTexture, Gamebool bRenderAlpha);
	private:
		//! \brief 渲染目标
		UTextureRenderTarget2D* m_pFlattenRenderTarget;
		UTextureRenderTarget2D* m_pRenderTarget;
		UTextureRenderTarget2D* m_pAlphaRenderTarget;
		UTextureRenderTarget2D* m_pSelectRenderTarget;
		//! \brief 渲染纹理大小
		Gameint m_nWidth;
		Gameint m_nHeight;

		//! \brief 纹理名称
		Gamelong m_nTextureName;

		//! \brief 场景名称
		FString m_strSceneName;

		//! \brief 场景类型
		SceneManagerType m_eSceneManagerType;

		//! \brief 图层持有的渲染对象
		TMap<Gamelong, GameComponent*> m_mapGameComponent;

		//! \brief 持有的相机对象
		GameCamera* m_pGameCamera;

		//! \brief 对象句柄
		Gamelong m_nHandle;

		//! \brief 纹理格式
		PixelFormat m_nPixelFormat;
	};
}