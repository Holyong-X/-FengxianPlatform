#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Graphics3D/GameEnum.h"
#include "Data/Vector4d.h"

namespace SuperMapSDK
{
	// ���崴����ȾĿ������
	typedef void* (*CreateRenderTextureCallBack)(Gameint mode, Gamelong nTextureName, char* strSceneName, int32 nWidth, int32 nHeight, int32 nFormat);

	// ɾ��������ȾĿ������
	typedef void (*DestoryRenderTextureCallBack)(void* pRenderTextureHandle);

	// ��ȡbuffer
	typedef void* (*GetFrameBufferCallBack)(void* pRenderTextureHandle, int32 nXOffset, int32 nYOffset, int32 nWidth, int32 nHeight, int32& nBufferSize);

	// ɾ��buffer
	typedef void(*DeleteFrameBufferCallBack)(void* pBuffer);

	// ������Ⱦ����
	typedef void(*UpdateSceneCallBack)(void* pRenderTextureHandle);

	// �������״̬
	typedef void(*SetRenderDepthCallBack)(void* pRenderTextureHandle, Gamebool bEnable);

	// ��ȡ��ǰ���
	typedef void* (*GetCameraCallBack)(void* pRenderTextureHandle);

	// ���buffer
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
	// ���ڲ����õĽӿ�
	public:
		GameRenderTextureManager();
		~GameRenderTextureManager();

		//! \brief ��ȡ������
		static GameRenderTextureManager* GetSingleton();

		//! \brief ���ٵ�����
		static void DestorySingleton();

		//! \brief �ͷ�����
		void Clear();

		//! \brief ����Ⱦ������ӵ���Ӧ���͵�renderTexture��
		void AddGameComponent(GameComponent* pGameComponent);

		//! \brief ��Ⱦʸ������ͼ��
		void RealtimeRasterVector(UTextureRenderTarget2D* pRenderTarget, FVector4 transform, Gamebool bSecondColor = false);

		//! \brief ��Ⱦ�ر�����
		void RealtimeRasterExcavationRegion(UTextureRenderTarget2D* pRenderTarget, Vector4d transform);

		//! \brief ����Ⱦ�����renderTexture���Ƴ�
		void RemoveGameComponent(GameComponent* pGameComponent);
		// ���ײ���õĽӿ�
	public:
		void* Create(Gamelong nTextureName, FString strSceneName, SceneManagerType sceneManagerType, int32 nWidth, int32 nHeight, int32 nFormat);

		void Remove(void* pRenderTextureHandle);

		GameRenderTexture* Get(Gamelong nRenderTextureHandle);
	private:
		//! \brief GameTexture����
		static GameRenderTextureManager* m_pGameTextureManager;

		//! \brief ����ӳ���
		TMap<Gamelong, GameRenderTexture*> m_mapTextures;


		//! \brief ͼ����е�դ����Ⱦ����ʸ�����ݣ�
		TMap<Gamelong, GameComponent*> m_mapGameComponent;
	};
}