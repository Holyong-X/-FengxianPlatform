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

		//! \brief ��ȡ������
		static GameTextureManager* GetSingleton();

		//! \brief ���ٵ�����
		static void DestorySingleton();

		//! \brief ��������
		GameTexture* CreateTexture(Gamelong nTextureHandle, GameTexture2DInfo& texture2DInfo);

		//! \brief ��������
		void DestroyTexture(void* pTextureHandle);

		//! \brief ��������
		void UpdateTexture(void* pTextureHandle, GameTexture2DInfo& texture2DInfo);

		//! \brief ��ȡ����
		GameTexture* GetTexture(Gamelong nTextureHandle);

		//! \brief �ͷ�����
		void Clear();

		//! \brief �����Ƿ����ϴ��Կ�
		Gamebool IsInitialGPU(void* pTextureHandle);

		//! \brief ���ó�������
		void SetWorld(UWorld* pWorld);

		//! \brief ��ӵ��������
		Gamebool AddTextureToCache(GameTexture* pTexture);

		//! \brief �ӻ���ػ�ȡ����
		UTexture2D* GetTextureFromCache(Gameulong nType);

		//! \brief �ж���������
		Gameulong GetType(GameTexture2DInfo & texture2DInfo);
		Gameulong GetType(GameTexture* pGameTexture);

		//! \brief �첽���»����
		void AsyncUpdateTextureCache();
	private:
		//! \brief ����UE����
		UTexture2D* CreateUTexture2D(GameTexture* pGameTexture, GameTexture2DInfo& texture2DInfo);

		//! \brief �첽������
		void AsyncUploadTexture(GameTexture* pGameTexture, UTexture2D* pTexture2D, GameTexture2DInfo& texture2DInfo, Gamebool bAsyncUpload);

		//! \brief �������
		void UploadTexture(GameTexture* pGameTexture, UTexture2D* pTexture2D, GameTexture2DInfo& texture2DInfo);

		//! \brief �첽��������
		void AsyncUpdateTexture(GameTexture* pGameTexture, UTexture2D* pTexture2D, GameTexture2DInfo& texture2DInfo, Gamebool bAsyncUpload);
	private:
		//! \brief GameTexture����
		static GameTextureManager* m_pGameTextureManager;

		//! \brief ����ӳ���
		TMap<Gamelong, GameTexture*> m_mapTextures;

		//! \brief ���糡������
		UWorld* m_pWorld;

		//! \brief ������Ⱦ�̵߳ĸ���
		Gameint m_nTexture;

		//! \brief �������
		TMap<Gameulong, TArray<UTexture2D*> > m_mapTextureCache;

		TArray<GameFuture*> m_FutureResult;
	};
}