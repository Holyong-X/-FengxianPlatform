#include "Graphics3D/GameTextureManager.h"
#include "Engine/Texture2D.h"
#include "Graphics3D/GameEnum.h"
#include "Graphics3D/GameConvertor.h"
#include "Core/Public/PixelFormat.h"
#include "Async/Async.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"
#include "Graphics3D/GameLifetime.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Core;

namespace SuperMapSDK
{
	GameTextureManager* GameTextureManager::m_pGameTextureManager = nullptr;
	GameTextureManager::GameTextureManager()
	{
		m_nTexture = 0;
	}

	GameTextureManager::~GameTextureManager()
	{
		Clear();
		m_nTexture = 0;
	}

	void GameTextureManager::Clear()
	{
		for (TMap<Gamelong, GameTexture*>::TConstIterator It = m_mapTextures.CreateConstIterator(); It; ++It)
		{
			delete It->Value;
		}

		for (TMap<Gameulong, TArray<UTexture2D*> >::TIterator It = m_mapTextureCache.CreateIterator(); It; ++It)
		{
			TArray<UTexture2D*> & arrTemp = It->Value;
			Gameint nCount = arrTemp.Num();
			for (Gameint n = 0; n < nCount; n++)
			{
				UTexture2D* pTex = arrTemp[n];
				pTex->RemoveFromRoot();
			}

			arrTemp.Empty();
		}

		Gameint nCount = m_FutureResult.Num();
		for (Gameint n = 0; n < nCount; n++)
		{
			delete m_FutureResult[n];
		}

		m_mapTextureCache.Empty();
		m_mapTextures.Empty();
		m_FutureResult.Empty();
	}

	void GameTextureManager::DestorySingleton()
	{
		if (m_pGameTextureManager != nullptr)
		{
			delete m_pGameTextureManager;
			m_pGameTextureManager = nullptr;
		}
	}

	GameTextureManager* GameTextureManager::GetSingleton()
	{
		if (m_pGameTextureManager == nullptr)
		{
			m_pGameTextureManager = new GameTextureManager();
		}

		return m_pGameTextureManager;
	}

	void GameTextureManager::SetWorld(UWorld* pWorld)
	{
		m_pWorld = pWorld;
	}

	UTexture2D* GameTextureManager::CreateUTexture2D(GameTexture* pGameTexture, GameTexture2DInfo& texture2DInfo)
	{
		if (texture2DInfo.m_nWidth == 0 || texture2DInfo.m_nHeight == 0 || texture2DInfo.m_nSizeInByte == 0)
		{
			return nullptr;
		}

		EPixelFormat ePixelFormat = GameConvertor::ToEPixelFormat(texture2DInfo.m_nFormat, texture2DInfo.m_nCompressType);
		texture2DInfo.m_nEPixelFormat = ePixelFormat;

		Gameulong nType = GetType(texture2DInfo);
		UTexture2D* pTexture2D = GetTextureFromCache(nType);

		if (!pTexture2D)
		{
			pTexture2D = NewObject<UTexture2D>(
				GetTransientPackage(),
				NAME_None,
				RF_Transient | RF_DuplicateTransient | RF_TextExportTransient
				);
		}
		
		if (ePixelFormat == EPixelFormat::PF_R8G8B8A8 || ePixelFormat == EPixelFormat::PF_B8G8R8A8)
		{
			pTexture2D->AddressX = TextureAddress::TA_Clamp;
			pTexture2D->AddressY = TextureAddress::TA_Clamp;
			pTexture2D->SRGB = texture2DInfo.m_bSRGB;
		}
		else if (ePixelFormat == EPixelFormat::PF_A32B32G32R32F)
		{
			pTexture2D->Filter = TF_Nearest;
		}


		if (pTexture2D == NULL)
		{
			return nullptr;
		}

		pTexture2D->AddToRoot();

		// 编辑模式下不异步加载纹理
#if SM_FOR_UE_FIVE
		Gamebool bAsyncUpload = false;
#else
		Gamebool bAsyncUpload = ((m_pWorld->WorldType == EWorldType::Editor ? false : true) && m_bEnableAsync);
#endif
		AsyncUploadTexture(pGameTexture, pTexture2D, texture2DInfo, bAsyncUpload);

		return pTexture2D;
	}

	void GameTextureManager::AsyncUploadTexture(GameTexture* pGameTexture, UTexture2D* pTexture2D, GameTexture2DInfo& texture2DInfo, Gamebool bAsyncUpload)
	{
		if (bAsyncUpload)
		{
			Gameint nOffsetX = texture2DInfo.m_nOffsetX;
			Gameint nOffsetY = texture2DInfo.m_nOffsetY;
			Gameint nWidth = texture2DInfo.m_nWidth;
			Gameint nHeight = texture2DInfo.m_nHeight;
			Gameuint nSizeInByte = texture2DInfo.m_nSizeInByte;
			Gameuchar* pByte = texture2DInfo.m_pByte;
			Gameint nFormat = texture2DInfo.m_nFormat;
			EPixelFormat nEPixelFormat = texture2DInfo.m_nEPixelFormat;
			Gameint nCompressType = texture2DInfo.m_nCompressType;
			Gamebool bUGMemory = texture2DInfo.m_bUGMemory;
			Gamebool bSRGB = texture2DInfo.m_bSRGB;
			// 内存传到异步函数里面去了，在里面释放
			texture2DInfo.m_pByte = nullptr;
			auto result = Async<>(EAsyncExecution::ThreadPool, [this, pGameTexture, pTexture2D, nOffsetX, nOffsetY, nWidth, nHeight, nSizeInByte, pByte, nFormat, nEPixelFormat, nCompressType, bUGMemory, bSRGB]() {
				GameTexture2DInfo innerTexture2DInfo;
				innerTexture2DInfo.m_nOffsetX = nOffsetX;
				innerTexture2DInfo.m_nOffsetY = nOffsetY;
				innerTexture2DInfo.m_nWidth = nWidth;
				innerTexture2DInfo.m_nHeight = nHeight;
				innerTexture2DInfo.m_nSizeInByte = nSizeInByte;
				innerTexture2DInfo.m_pByte = pByte;
				innerTexture2DInfo.m_nFormat = nFormat;
				innerTexture2DInfo.m_nEPixelFormat = nEPixelFormat;
				innerTexture2DInfo.m_nCompressType = nCompressType;
				innerTexture2DInfo.m_bUGMemory = bUGMemory;
				innerTexture2DInfo.m_bSRGB = bSRGB;
				this->UploadTexture(pGameTexture, pTexture2D, innerTexture2DInfo);
			});
		}
		else
		{
			UploadTexture(pGameTexture, pTexture2D, texture2DInfo);
		}
	}

	void GameTextureManager::UploadTexture(GameTexture* pGameTexture, UTexture2D* pTexture2D, GameTexture2DInfo& texture2DInfo)
	{
		Gameuint8* pCopyDataBuffer = texture2DInfo.m_pByte;
		bool bCopyDataIsUGCBuffer = true;

		UGPixelFormat eUGPixelFormat = (UGPixelFormat)texture2DInfo.m_nFormat;
		if (texture2DInfo.m_nCompressType == 0 && (eUGPixelFormat == UGPixelFormat::UGC_PF_BYTE_BGR || eUGPixelFormat == UGPixelFormat::UGC_PF_BYTE_RGB))
		{
			Gameuint nSize = (texture2DInfo.m_nSizeInByte / 3);
			Gameuint nNewSizeInByte = nSize * 4;
			Gameuint8* pNewData = (Gameuint8*)FMemory::Malloc(nNewSizeInByte);

			for (Gameuint i = 0; i < nSize; i++)
			{
				pNewData[i * 4 + 0] = pCopyDataBuffer[i * 3 + 0];
				pNewData[i * 4 + 1] = pCopyDataBuffer[i * 3 + 1];
				pNewData[i * 4 + 2] = pCopyDataBuffer[i * 3 + 2];
				pNewData[i * 4 + 3] = 255;
			}

			pCopyDataBuffer = pNewData;
			bCopyDataIsUGCBuffer = false;
			texture2DInfo.m_nSizeInByte = nNewSizeInByte;
		}

		// 计算Mipmap
		TMap<Gameint, Gameint> mapMipmaps;
		GameConvertor::CalMipMap(texture2DInfo.m_nWidth, texture2DInfo.m_nHeight, texture2DInfo.m_nSizeInByte, 
			texture2DInfo.m_nFormat, texture2DInfo.m_nEPixelFormat, mapMipmaps);

		pGameTexture->SetMipmapCount(mapMipmaps.Num());

		pTexture2D->PlatformData = new FTexturePlatformData();
		pTexture2D->PlatformData->SizeX = texture2DInfo.m_nWidth;
		pTexture2D->PlatformData->SizeY = texture2DInfo.m_nHeight;
		pTexture2D->PlatformData->PixelFormat = texture2DInfo.m_nEPixelFormat;

		Gameint nOffset = 0;
		for (TMap<Gameint, Gameint>::TConstIterator It = mapMipmaps.CreateConstIterator(); It; ++It)
		{
			Gameint nLevel = FMath::Pow(2, It->Key);

			Gameint nMipWidth  = texture2DInfo.m_nWidth / nLevel;
			Gameint nMipHeight = texture2DInfo.m_nHeight / nLevel;
				
			FTexture2DMipMap* Mip = new FTexture2DMipMap();
			pTexture2D->PlatformData->Mips.Add(Mip);
			Mip->SizeX = nMipWidth;
			Mip->SizeY = nMipHeight;
			Mip->BulkData.Lock(LOCK_READ_WRITE);
			void* pData = Mip->BulkData.Realloc(It->Value);
			FMemory::Memcpy(pData, pCopyDataBuffer + nOffset, It->Value);
			Mip->BulkData.Unlock();
			
			nOffset += It->Value;
		}

		pTexture2D->UpdateResource();

		if (!bCopyDataIsUGCBuffer)
		{
			FMemory::Free(pCopyDataBuffer);
		}
		pCopyDataBuffer = nullptr;
		
		pGameTexture->SetInitialGPU(true);
	}

	GameTexture* GameTextureManager::CreateTexture(Gamelong nTextureHandle, GameTexture2DInfo& texture2DInfo)
	{
		Gamebool bHas = m_mapTextures.Contains(nTextureHandle);
		if (bHas)
		{
			return m_mapTextures[nTextureHandle];
		}

		GameTexture* pGameTexture = new GameTexture();
		pGameTexture->SetWidth(texture2DInfo.m_nWidth);
		pGameTexture->SetHeight(texture2DInfo.m_nHeight);

		// 创建UE的纹理对象
		UTexture2D* pTexture2D = CreateUTexture2D(pGameTexture, texture2DInfo);
		
		pGameTexture->SetPixelFormat(texture2DInfo.m_nEPixelFormat);
		pGameTexture->SetTexture2D(pTexture2D);
		pGameTexture->SetTexHashCodeName(nTextureHandle);

		m_mapTextures.Add(nTextureHandle, pGameTexture);

		return pGameTexture;
	}

	GameTexture* GameTextureManager::GetTexture(Gamelong nTextureHandle)
	{
		Gamebool bHas = m_mapTextures.Contains(nTextureHandle);
		if (bHas)
		{
			return m_mapTextures[nTextureHandle];
		}

		return nullptr;
	}

	void GameTextureManager::DestroyTexture(void* pTextureHandle)
	{
		GameTexture* pGameTexture = (GameTexture*)pTextureHandle;
		Gamelong nTextureHandle = pGameTexture->GetTexHashCodeName();
#if SM_FOR_UE_FIVE
		Gamebool bAsyncUpload = false;
#else
		Gamebool bAsyncUpload = ((m_pWorld->WorldType == EWorldType::Editor ? false : true) && m_bEnableAsync);
#endif
		if (bAsyncUpload)
		{
			if (!m_bEnableTextureCache)
			{
				GameFuture* pGameFuture = new GameFuture();
				pGameFuture->m_DeleteTexture = Async<>(EAsyncExecution::ThreadPool, [this, pGameTexture]() {
					while (!pGameTexture->GetInitialAndUpdateGPU()) {}
					UTexture2D* pTexture = nullptr;
					if (pGameTexture->GetTexture2D())
					{
						pTexture = pGameTexture->GetTexture2D();
						pGameTexture->SetTexture2D(nullptr);
					}
					delete pGameTexture;
					return pTexture;
				});

				GameLifetime::Destory(pGameFuture);
			}
			else
			{
				GameFuture* pGameFuture = new GameFuture();
				pGameFuture->m_FutureTextureCache = Async<>(EAsyncExecution::ThreadPool, [this, pGameTexture]() {
					while (!pGameTexture->GetInitialAndUpdateGPU()) {}

					UTexture2D* pTexture2D = pGameTexture->GetTexture2D();

					Gameulong nType = this->GetType(pGameTexture);
					pGameTexture->SetTexture2D(nullptr);

					delete pGameTexture;
					return TPair<Gameulong, UTexture2D*>(nType, pTexture2D);
				});

				m_FutureResult.Add(pGameFuture);
			}
		}
		else
		{
			if (AddTextureToCache(pGameTexture))
			{
				pGameTexture->SetTexture2D(nullptr);
			}
			delete pGameTexture;
		}
		pGameTexture = nullptr;
		m_mapTextures.Remove(nTextureHandle);
	}
	void GameTextureManager::AsyncUpdateTexture(GameTexture* pGameTexture, UTexture2D* pTexture2D, GameTexture2DInfo& texture2DInfo, Gamebool bAsyncUpload)
	{
		if (bAsyncUpload)
		{
			Gameint nOffsetX = texture2DInfo.m_nOffsetX;
			Gameint nOffsetY = texture2DInfo.m_nOffsetY;
			Gameint nWidth = texture2DInfo.m_nWidth;
			Gameint nHeight = texture2DInfo.m_nHeight;
			Gameuint nSizeInByte = texture2DInfo.m_nSizeInByte;
			Gameuchar* pByte = texture2DInfo.m_pByte;
			Gameint nFormat = texture2DInfo.m_nFormat;
			EPixelFormat nEPixelFormat = texture2DInfo.m_nEPixelFormat;
			Gameint nCompressType = texture2DInfo.m_nCompressType;
			Gamebool bUGMemory = texture2DInfo.m_bUGMemory;
			// 内存传到异步函数里面去了，在里面释放
			texture2DInfo.m_pByte = nullptr;

			auto result = Async<>(EAsyncExecution::ThreadPool, [pGameTexture, pTexture2D, nOffsetX, nOffsetY, nWidth, nHeight, nSizeInByte, pByte, nFormat, nEPixelFormat, nCompressType, bUGMemory]() {
				while (!pGameTexture->GetInitialGPU())
				{
					// 等待纹理上传到显卡
				}

				GameTexture2DInfo innerTexture2DInfo;
				innerTexture2DInfo.m_nOffsetX = nOffsetX;
				innerTexture2DInfo.m_nOffsetY = nOffsetY;
				innerTexture2DInfo.m_nWidth = nWidth;
				innerTexture2DInfo.m_nHeight = nHeight;
				innerTexture2DInfo.m_nSizeInByte = nSizeInByte;
				innerTexture2DInfo.m_pByte = pByte;
				innerTexture2DInfo.m_nFormat = nFormat;
				innerTexture2DInfo.m_nEPixelFormat = nEPixelFormat;
				innerTexture2DInfo.m_nCompressType = nCompressType;
				innerTexture2DInfo.m_bUGMemory = bUGMemory;
				GameConvertor::UpdateTextureRegion(pTexture2D, innerTexture2DInfo, 0, false, 1, 0);
				innerTexture2DInfo.m_pByte = nullptr;
				pGameTexture->RemoveUpdate();
			});
		}
		else
		{
			GameConvertor::UpdateTextureRegion(pTexture2D, texture2DInfo, 0, false, 1, 0);
			texture2DInfo.m_pByte = nullptr;
			pGameTexture->RemoveUpdate();
		}
	}

	Gameulong GameTextureManager::GetType(GameTexture2DInfo & texture2DInfo)
	{
		Gameulong nType = texture2DInfo.m_nEPixelFormat;

		TMap<Gameint, Gameint> mapMipmaps;
		GameConvertor::CalMipMap(texture2DInfo.m_nWidth, texture2DInfo.m_nHeight, texture2DInfo.m_nSizeInByte,
			texture2DInfo.m_nFormat, texture2DInfo.m_nEPixelFormat, mapMipmaps);

		Gameint nMipmap = mapMipmaps.Num();
		if (nMipmap > 0)
		{
			nType |= 0x80;
		}

		Gameulong nWidth = texture2DInfo.m_nWidth;
		Gameulong nHeight = texture2DInfo.m_nHeight;

		nType |= nHeight << 8;
		nType |= nWidth << 24;

		return nType;
	}

	Gameulong GameTextureManager::GetType(GameTexture* pGameTexture)
	{
		Gameulong nType = pGameTexture->GetPixelFormat();

		Gameint nMipmap = pGameTexture->GetMipmapCount();
		if (nMipmap > 0)
		{
			nType |= 0x80;
		}

		Gameulong nWidth = pGameTexture->GetWidth();
		Gameulong nHeight = pGameTexture->GetHeight();

		nType |= nHeight << 8;
		nType |= nWidth << 24;

		return nType;
	}

	void GameTextureManager::AsyncUpdateTextureCache()
	{
		if (!m_bEnableTextureCache) return;

		TArray<GameFuture*> mTemp;

		Gameint nCount = m_FutureResult.Num();
		for (Gameint n = 0; n < nCount; n++)
		{
			GameFuture* pFuture = m_FutureResult[n];
			if (pFuture->m_FutureTextureCache.IsReady())
			{
				TPair<Gameulong, UTexture2D*> pair = pFuture->m_FutureTextureCache.Get();
				if (m_mapTextureCache.Contains(pair.Key))
				{
					m_mapTextureCache[pair.Key].Add(pair.Value);
				}
				else
				{
					TArray<UTexture2D*> arrTemp;
					arrTemp.Add(pair.Value);

					m_mapTextureCache.Add(pair.Key, arrTemp);
				}

				pair.Value->ReleaseResource();

				delete pair.Value->PlatformData;
				pair.Value->PlatformData = nullptr;

				delete pFuture;
			
			}
			else
			{
				mTemp.Add(pFuture);
			}
		}

		m_FutureResult.Empty();
		m_FutureResult = mTemp;
	}

	Gamebool GameTextureManager::AddTextureToCache(GameTexture* pTexture)
	{
		if (!m_bEnableTextureCache) return false;

		Gameulong nType = GetType(pTexture);
		TArray<UTexture2D*>* pTextureArray = m_mapTextureCache.Find(nType);
		if (pTextureArray)
		{
			pTextureArray->Push(pTexture->GetTexture2D());
		}
		else
		{
			TArray<UTexture2D*> arrTemp;
			arrTemp.Add(pTexture->GetTexture2D());
			m_mapTextureCache.Add(nType, arrTemp);
		}

		pTexture->GetTexture2D()->ReleaseResource();

		delete pTexture->GetTexture2D()->PlatformData;
		pTexture->GetTexture2D()->PlatformData = nullptr;

		return true;
	}

	UTexture2D* GameTextureManager::GetTextureFromCache(Gameulong nType)
	{
		if (!m_bEnableTextureCache) return nullptr;

		UTexture2D* pTexture2D = nullptr;
		TArray<UTexture2D*>* pTextureArray = m_mapTextureCache.Find(nType);
		if (pTextureArray != nullptr)
		{
			if (pTextureArray->Num() > 0)
			{
				pTexture2D = pTextureArray->Pop();
			}
		}

		return pTexture2D;
	}

	void GameTextureManager::UpdateTexture(void* pTextureHandle, GameTexture2DInfo& texture2DInfo)
	{
		GameTexture* pGameTexture = (GameTexture*)pTextureHandle;
		UTexture2D* pTexture2D = pGameTexture->GetTexture2D();
		if (!pTexture2D) return;
		if (texture2DInfo.m_nSizeInByte > 0 && texture2DInfo.m_pByte != nullptr)
		{
			pGameTexture->AddUpdate();
#if SM_FOR_UE_FIVE
			Gamebool bAsyncUpload = false;
#else
			Gamebool bAsyncUpload = ((m_pWorld->WorldType == EWorldType::Editor ? false : true) && m_bEnableAsync);
#endif
			AsyncUpdateTexture(pGameTexture, pTexture2D, texture2DInfo, bAsyncUpload);
		}
	}

	Gamebool GameTextureManager::IsInitialGPU(void* pTextureHandle)
	{
		GameTexture* pGameTexture = (GameTexture*)pTextureHandle;
		return pGameTexture->GetInitialAndUpdateGPU();
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif