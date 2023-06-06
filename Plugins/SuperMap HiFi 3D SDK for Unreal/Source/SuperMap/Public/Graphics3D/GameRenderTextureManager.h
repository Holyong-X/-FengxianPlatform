#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEnum.h"
#include "Data/Vector4d.h"

namespace SuperMapSDK
{
	// 定义创建渲染目标纹理
	typedef void* (*CreateRenderTextureCallBack)(Gameint mode, Gamelong nTextureName, char* strSceneName, int32 nWidth, int32 nHeight, int32 nFormat);

	// 删除创建渲染目标纹理
	typedef void (*DestoryRenderTextureCallBack)(void* pRenderTextureHandle);

	// 获取buffer
	typedef void* (*GetFrameBufferCallBack)(void* pRenderTextureHandle, int32 nXOffset, int32 nYOffset, int32 nWidth, int32 nHeight, int32& nBufferSize);

	// 删除buffer
	typedef void(*DeleteFrameBufferCallBack)(void* pBuffer);

	// 更新渲染纹理
	typedef void(*UpdateSceneCallBack)(void* pRenderTextureHandle);

	// 设置相机状态
	typedef void(*SetRenderDepthCallBack)(void* pRenderTextureHandle, Gamebool bEnable);

	// 获取当前相机
	typedef void* (*GetCameraCallBack)(void* pRenderTextureHandle);

	// 清除buffer
	typedef void(*ClearFramebufferCallBack)(void* pRenderTextureHandle, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);

	void* CreateRenderTexture(int32 mode, Gamelong nTextureName, char* strSceneName, int32 nWidth, int32 nHeight, int32 nFormat);

	void DestroyRenderTexture(void* pRenderTextureHandle);

	void* GetFrameBuffer(void* pRenderTextureHandle, int32 nXOffset, int32 nYOffset, int32 nWidth, int32 nHeight, int32& nBufferSize);
	void DeleteFrameBuffer(void* pBuffer);

	void UpdateScene(void* pRenderTextureHandle);

	void* GetCamera(void* pRenderTextureHandle);

	void ClearFramebuffer(void* pRenderTextureHandle, Gamefloat fR, Gamefloat fG, Gamefloat fB, Gamefloat fA);

	void SetRenderDepth(void* pRenderTextureHandle, Gamebool bEnable);

	class GameComponent;
	class GameRenderTexture;
	class SUPERMAP_API GameRenderTextureManager
	{
	// 供内部调用的接口
	public:
		GameRenderTextureManager();
		~GameRenderTextureManager();

		//! \brief 获取单例类
		static GameRenderTextureManager* GetSingleton();

		//! \brief 销毁单例类
		static void DestorySingleton();

		//! \brief 释放纹理
		void Clear();

		//! \brief 将渲染对象添加到对应类型的renderTexture上
		void AddGameComponent(GameComponent* pGameComponent);

		//! \brief 渲染矢量贴地图层
		void RealtimeRasterVector(UTextureRenderTarget2D* pRenderTarget, FVector4 transform, Gamebool bSecondColor = false);

		//! \brief 渲染地表开挖面
		void RealtimeRasterExcavationRegion(UTextureRenderTarget2D* pRenderTarget, Vector4d transform);

		//! \brief 将渲染对象从renderTexture上移除
		void RemoveGameComponent(GameComponent* pGameComponent);
		// 供底层调用的接口
	public:
		void* Create(Gamelong nTextureName, FString strSceneName, SceneManagerType sceneManagerType, int32 nWidth, int32 nHeight, int32 nFormat);

		void Remove(void* pRenderTextureHandle);

		GameRenderTexture* Get(Gamelong nRenderTextureHandle);
	private:
		//! \brief GameTexture单例
		static GameRenderTextureManager* m_pGameTextureManager;

		//! \brief 纹理映射表
		TMap<Gamelong, GameRenderTexture*> m_mapTextures;


		//! \brief 图层持有的栅格化渲染对象（矢量数据）
		TMap<Gamelong, GameComponent*> m_mapGameComponent;
	};
}