#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameTexture.h"
#include "Engine/World.h"

namespace SuperMapSDK
{
	class SUPERMAP_API GameTextureManager
	{
	public:
		GameTextureManager();
		~GameTextureManager();

		//! \brief 获取单例类
		static GameTextureManager* GetSingleton();

		//! \brief 销毁单例类
		static void DestorySingleton();

		//! \brief 创建纹理
		GameTexture* CreateTexture(Gamelong nTextureHandle, GameTexture2DInfo& texture2DInfo);

		//! \brief 销毁纹理
		void DestroyTexture(void* pTextureHandle);

		//! \brief 更新纹理
		void UpdateTexture(void* pTextureHandle, GameTexture2DInfo& texture2DInfo);

		//! \brief 获取纹理
		GameTexture* GetTexture(Gamelong nTextureHandle);

		//! \brief 释放纹理
		void Clear();

		//! \brief 纹理是否已上传显卡
		Gamebool IsInitialGPU(void* pTextureHandle);

		//! \brief 设置场景对象
		void SetWorld(UWorld* pWorld);

		//! \brief 添加到纹理缓存池
		Gamebool AddTextureToCache(GameTexture* pTexture);

		//! \brief 从缓存池获取纹理
		UTexture2D* GetTextureFromCache(Gameulong nType);

		//! \brief 判断纹理类型
		Gameulong GetType(GameTexture2DInfo & texture2DInfo);
		Gameulong GetType(GameTexture* pGameTexture);

		//! \brief 异步更新缓存池
		void AsyncUpdateTextureCache();
	private:
		//! \brief 创建UE纹理
		UTexture2D* CreateUTexture2D(GameTexture* pGameTexture, GameTexture2DInfo& texture2DInfo);

		//! \brief 异步填纹理
		void AsyncUploadTexture(GameTexture* pGameTexture, UTexture2D* pTexture2D, GameTexture2DInfo& texture2DInfo, Gamebool bAsyncUpload);

		//! \brief 填充纹理
		void UploadTexture(GameTexture* pGameTexture, UTexture2D* pTexture2D, GameTexture2DInfo& texture2DInfo);

		//! \brief 异步更新纹理
		void AsyncUpdateTexture(GameTexture* pGameTexture, UTexture2D* pTexture2D, GameTexture2DInfo& texture2DInfo, Gamebool bAsyncUpload);
	private:
		//! \brief GameTexture单例
		static GameTextureManager* m_pGameTextureManager;

		//! \brief 纹理映射表
		TMap<Gamelong, GameTexture*> m_mapTextures;

		//! \brief 世界场景对象
		UWorld* m_pWorld;

		//! \brief 减轻渲染线程的负担
		Gameint m_nTexture;

		//! \brief 纹理缓存池
		TMap<Gameulong, TArray<UTexture2D*> > m_mapTextureCache;

		TArray<GameFuture*> m_FutureResult;
	};
}