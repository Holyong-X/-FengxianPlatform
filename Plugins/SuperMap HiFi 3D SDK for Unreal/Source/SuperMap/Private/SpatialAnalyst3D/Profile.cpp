#include "SpatialAnalyst3D/Profile.h"
#include "Graphics3D/GameObjectManager.h"
#include "Graphics3D/GameRenderTexture.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/ROCache.h"
#include "Component/SuperMap_MeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Graphics3D/GameConvertor.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Core;
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst3D
		{
			Profile::Profile(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl) : Analyst3D(pWorld, pScene, pCameraControl)
			{
				m_pUGProfile = nullptr;
				m_bEnable = false;
				m_pTexture2D = nullptr;
				m_eAnalyzeMode = Core::Profile_Analyze;
				_Profile_Create(m_pUGProfile);
			}

			Profile::~Profile()
			{
				if (m_pTexture2D)
				{
					m_pTexture2D->RemoveFromRoot();
				}
				m_bEnable = false;
				_Profile_Destroy(m_pUGProfile);
			}

			void Profile::Release()
			{
				m_bEnable = false;
			}

			void Profile::DoBuild()
			{
				_Profile_Build(m_pUGProfile);
			}

			void Profile::DoClear()
			{
				
			}

			void Profile::Render()
			{
				if (m_bEnable)
				{
					UTexture2D* texture = nullptr;
					OutputProfileToImageData(texture);
					m_pTexture2D = texture;
					m_bEnable = false;
					m_ProfileGetImageEvent.Execute();
				}
			}

			void Profile::SetExtendHeight(double height)
			{
				_Profile_SetExtendHeight(m_pUGProfile, height);
				m_bEnable = true;
			}

			double Profile::GetExtendHeight()
			{
				return _Profile_GetExtendHeight(m_pUGProfile);
			}

			void Profile::SetStartPoint3D(Vector3d vPoint)
			{
				_Profile_SetStartPoint3D(m_pUGProfile, vPoint.X, vPoint.Y, vPoint.Z);
				m_bEnable = true;
			}

			Vector3d Profile::GetStartPoint3D()
			{
				double x = 0, y = 0, z = 0;
				_Profile_GetStartPoint3D(m_pUGProfile, x, y, z);
				return Vector3d(x, y, z);
			}

			void Profile::SetEndPoint3D(Vector3d vPoint)
			{
				_Profile_SetEndPoint3D(m_pUGProfile, vPoint.X, vPoint.Y, vPoint.Z);
				m_bEnable = true;
			}

			Vector3d Profile::GetEndPoint3D()
			{
				double x = 0, y = 0, z = 0;
				_Profile_GetEndPoint3D(m_pUGProfile, x, y, z);
				return Vector3d(x, y, z);
			}

			Vector3d Profile::GetLeftTopPosition()
			{
				double x = 0, y = 0, z = 0;
				_Profile_GetLeftTopPosition(m_pUGProfile, x, y, z);
				return Vector3d(x, y, z);
			}

			Vector3d Profile::GetRightBottomPosition()
			{
				double x = 0, y = 0, z = 0;
				_Profile_GetRightBottomPosition(m_pUGProfile, x, y, z);
				return Vector3d(x, y, z);
			}

			UTexture2D* Profile::GetImageData()
			{
				if (!m_pTexture2D)
				{
					return nullptr;
				}
				return m_pTexture2D;
			}

			void Profile::CallFunc_ProfileInstance(void* pActor, ProfileGetImageEvent QAEvent)
			{
				m_ProfileGetImageEvent.m_pActor = pActor;
				m_ProfileGetImageEvent.Event = QAEvent;
			}

			void Profile::OutputProfileToImageData(UTexture2D*& pTexture2D)
			{
				int nWidth = 0, nHeight = 0, nFormat = 0, nTextureCodecType = 0, nWidthBytes = 0;
				void* pBits;
				_Profile_OutputProfileToImageData(m_pUGProfile, nWidth, nHeight, nFormat, nTextureCodecType, nWidthBytes, pBits);
				if (nWidth == 0 || nHeight == 0 || nWidthBytes == 0)
				{
					return;
				}
				Gameuchar* pByte = (Gameuchar*)pBits;
				EPixelFormat ePixelFormat = GameConvertor::ToEPixelFormat(nFormat, nTextureCodecType);
				int byteSize = nWidthBytes * nHeight;
				Gameuint8* pDataBuffer = (Gameuint8*)FMemory::Malloc(byteSize);
				FMemory::Memcpy(pDataBuffer, pByte, byteSize);
				if (!pTexture2D)
				{
					pTexture2D = NewObject<UTexture2D>(
						GetTransientPackage(),
						NAME_None,
						RF_Transient
						);
				}
				if (ePixelFormat == EPixelFormat::PF_R8G8B8A8 || ePixelFormat == EPixelFormat::PF_B8G8R8A8)
				{
					pTexture2D->AddressX = TextureAddress::TA_Clamp;
					pTexture2D->AddressY = TextureAddress::TA_Clamp;
				}
				else if (ePixelFormat == EPixelFormat::PF_A32B32G32R32F)
				{
					pTexture2D->Filter = TF_Nearest;
				}
				if (pTexture2D == NULL)
				{
					return;
				}
				pTexture2D->AddToRoot();

				bool bCopyDataIsUGCBuffer = true;
				if (nTextureCodecType == 0 && (nFormat == UGPixelFormat::UGC_PF_BYTE_BGR || nFormat == UGPixelFormat::UGC_PF_BYTE_RGB))
				{
					Gameuint nSize = (byteSize / 3);
					Gameuint nNewSizeInByte = nSize * 4;
					Gameuint8* pNewData = (Gameuint8*)FMemory::Malloc(nNewSizeInByte);

					for (Gameuint i = 0; i < nSize; i++)
					{
						pNewData[i * 4 + 0] = pDataBuffer[i * 3 + 0];
						pNewData[i * 4 + 1] = pDataBuffer[i * 3 + 1];
						pNewData[i * 4 + 2] = pDataBuffer[i * 3 + 2];
						pNewData[i * 4 + 3] = 255;
					}

					pDataBuffer = pNewData;
					bCopyDataIsUGCBuffer = false;
					byteSize = nNewSizeInByte;
				}

				TMap<Gameint, Gameint> mapMipmaps;
				GameConvertor::CalMipMap(nWidth, nHeight, byteSize,
					10, ePixelFormat, mapMipmaps);

				pTexture2D->PlatformData = new FTexturePlatformData();
				pTexture2D->PlatformData->SizeX = nWidth;
				pTexture2D->PlatformData->SizeY = nHeight;
				pTexture2D->PlatformData->PixelFormat = ePixelFormat;

				Gameint nOffset = 0;
				for (TMap<Gameint, Gameint>::TConstIterator It = mapMipmaps.CreateConstIterator(); It; ++It)
				{
					Gameint nLevel = FMath::Pow(2, It->Key);

					Gameint nMipWidth = nWidth / nLevel;
					Gameint nMipHeight = nHeight / nLevel;

					FTexture2DMipMap* Mip = new FTexture2DMipMap();
					pTexture2D->PlatformData->Mips.Add(Mip);
					Mip->SizeX = nMipWidth;
					Mip->SizeY = nMipHeight;
					Mip->BulkData.Lock(LOCK_READ_WRITE);
					void* pData = Mip->BulkData.Realloc(It->Value);
					FMemory::Memcpy(pData, pDataBuffer + nOffset, It->Value);
					Mip->BulkData.Unlock();

					nOffset += It->Value;
				}

				pTexture2D->UpdateResource();

				if (!bCopyDataIsUGCBuffer)
				{
					FMemory::Free(pDataBuffer);
				}
				pDataBuffer = nullptr;
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif