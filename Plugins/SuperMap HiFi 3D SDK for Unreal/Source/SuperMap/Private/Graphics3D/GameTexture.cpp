#include "Graphics3D/GameTexture.h"
#include "Engine/Texture2D.h"
#include "Graphics3D/GameTextureManager.h"
#include "Base3D/StatsGroupDefine.h"
#include "Graphics3D/GameConvertor.h"
#include "Graphics3D/GameLifetime.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	GameTexture::GameTexture()
	{
		m_pTexture2D = nullptr;
		m_bInitialGPU = false;
		m_nWidth = 0; 
		m_nHeight = 0;
		m_nUpdate1 = 0;
		m_nUpdate2 = 0;

		m_ePixelFormat = PF_B8G8R8A8;
		m_nMipmap = 0;
	}

	GameTexture::~GameTexture()
	{
		if (m_pTexture2D != nullptr)
		{	
			m_pTexture2D->RemoveFromRoot();
			GameLifetime::Destory(m_pTexture2D);
		}
	}

	void GameTexture::InitializeCallbackHandle()
	{
		CreateTextureFunction createTexture = CreateTexture;
		DestroyTextureFunction destroyTexture = DestroyTexture;
		UpdateTextureFunction  updateTexture = UpdateTexture;
		IsInitialGPUFunction isInitialGPU = IsInitialGPU;

		if (_InitTextureCallbackHandle != nullptr)
		{
			_InitTextureCallbackHandle((Gamevoid*)createTexture, (Gamevoid*)destroyTexture, (Gamevoid*)updateTexture, (Gamevoid*)isInitialGPU);
		}
	}

	UTexture2D* GameTexture::GetTexture2D()
	{
		return m_pTexture2D;
	}

	void GameTexture::SetTexture2D(UTexture2D* pTexture2D)
	{
		m_pTexture2D = pTexture2D;
	}

	void GameTexture::SetTexHashCodeName(Gamelong nHashCodeName)
	{
		m_nHashCodeName = nHashCodeName;
	}

	Gamelong GameTexture::GetTexHashCodeName()
	{
		return m_nHashCodeName;
	}

	void GameTexture::SetInitialGPU(Gamebool bInitial)
	{
		m_bInitialGPU = bInitial;
	}

	Gamebool GameTexture::GetInitialGPU()
	{
		return m_bInitialGPU;
	}

	Gamebool GameTexture::GetInitialAndUpdateGPU()
	{
		return m_bInitialGPU && (m_nUpdate1 == m_nUpdate2);
	}

	void GameTexture::AddUpdate()
	{
		m_nUpdate1 = m_nUpdate1 + 1;
	}

	void GameTexture::RemoveUpdate()
	{
		m_nUpdate2 = m_nUpdate2 + 1;
	}

	void GameTexture::SetWidth(Gameint nWidth)
	{
		m_nWidth = nWidth;
	}

	Gameint GameTexture::GetWidth()
	{
		return m_nWidth;
	}

	void GameTexture::SetHeight(Gameint nHeight)
	{
		m_nHeight = nHeight;
	}

	Gameint GameTexture::GetHeight()
	{
		return m_nHeight;
	}

	void GameTexture::SetPixelFormat(EPixelFormat ePixelFormat)
	{
		m_ePixelFormat = ePixelFormat;
	}

	EPixelFormat GameTexture::GetPixelFormat()
	{
		return m_ePixelFormat;
	}

	void GameTexture::SetMipmapCount(Gameint nMipmap)
	{
		m_nMipmap = nMipmap;
	}

	Gameint GameTexture::GetMipmapCount()
	{
		return m_nMipmap;
	}

	void* CreateTexture(Gamelong nTextureHandle, Gameint nWidth, Gameint nHeight, Gameuint nSizeInByte, Gameuchar*& pByte, Gameint nFormat,
		Gameint nCompressType, Gamebool bCanReleased, Gamebool bSRGB)
	{
		STATS_SM_CREATETEXTURE


		GameTexture2DInfo textureInfo;
		textureInfo.m_nWidth = nWidth;
		textureInfo.m_nHeight = nHeight;
		textureInfo.m_nSizeInByte = nSizeInByte;
		textureInfo.m_nFormat = nFormat;
		textureInfo.m_nCompressType = nCompressType;
		textureInfo.m_bUGMemory = bCanReleased;
		textureInfo.m_bSRGB = bSRGB;
		textureInfo.SetTextureData(pByte, nSizeInByte, !bCanReleased);

		return GameTextureManager::GetSingleton()->CreateTexture(nTextureHandle, textureInfo);
	}

	void DestroyTexture(void* pTextureHandle)
	{
		STATS_SM_DESTROYTEXTURE

		GameTextureManager::GetSingleton()->DestroyTexture(pTextureHandle);
	}

	void UpdateTexture(void* pTextureHandle, Gameint nOffsetX, Gameint nOffsetY, Gameint width, Gameint height, Gameuint nSizeInByte, Gameuchar* pByte, 
		Gameint nFormat, Gameint nCompressType, Gamebool bCanReleased)
	{
		STATS_SM_UPDATETEXTURE

		GameTexture2DInfo textureInfo;
		textureInfo.m_nOffsetX = nOffsetX;
		textureInfo.m_nOffsetY = nOffsetY;
		textureInfo.m_nWidth = width;
		textureInfo.m_nHeight = height;
		textureInfo.m_nSizeInByte = nSizeInByte;
		if (nSizeInByte == 0)
		{
			EPixelFormat ePixelFormat = GameConvertor::ToEPixelFormat(nFormat, nCompressType);
			textureInfo.m_nSizeInByte = GameConvertor::CalTextureSize(textureInfo.m_nWidth, textureInfo.m_nHeight, nFormat, ePixelFormat);
		}

		textureInfo.m_nFormat = nFormat;
		textureInfo.m_nCompressType = nCompressType;
		textureInfo.m_bUGMemory = bCanReleased;
		textureInfo.SetTextureData(pByte, textureInfo.m_nSizeInByte, !bCanReleased);

		GameTextureManager::GetSingleton()->UpdateTexture(pTextureHandle, textureInfo);
	}

	Gamebool IsInitialGPU(void* pTextureHandle)
	{
		STATS_SM_ISINITIALGPU

		return GameTextureManager::GetSingleton()->IsInitialGPU(pTextureHandle);
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif