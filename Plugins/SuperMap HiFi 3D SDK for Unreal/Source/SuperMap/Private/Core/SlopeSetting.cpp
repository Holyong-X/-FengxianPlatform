#include "Core/SlopeSetting.h"
#include "Core/ROCacheManager.h"

using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			SlopeMapShaderParams::SlopeMapShaderParams()
			{
				SlopeDisplayMode = 0;
				SlopeFloorAngle = 0;
				SlopeCeilAngle = 0;
				SlopeMinVisibleSlope = 0;
				SlopeMaxVisibleSlope = 0;
				SlopeColorTexture = nullptr;
				SlopeArrowTexture = nullptr;
				SlopeArrowsMove = 0;
				SlopeTopLevel = 0;
				SlopeTimeVal = 0;
			}

			SlopeSetting::SlopeSetting()
			{
				_SlopeSetting_Create(m_pSlopeSetting);
				_TerrainLayer_SetSlopeSetting(m_pSlopeSetting);
				m_colorTableTexture = nullptr;
				m_arrowTexture = nullptr;
				m_dCeil = 90;
				m_dFloor = 0;
				m_bArrowMove = false;
			}

			SlopeSetting::SlopeSetting(SlopeSetting& other)
			{
				_SlopeSetting_Create(m_pSlopeSetting);
				_TerrainLayer_SetSlopeSetting(m_pSlopeSetting);

				SetDisplaySytle(other.GetDisplaySytle());
				SetColorTableMaxKey(other.GetColorTableMaxKey());
				SetColorTableMinKey(other.GetColorTableMinKey());
				SetMaxVisibleValue(other.GetMaxVisibleValue());
				SetMinVisibleValue(other.GetMinVisibleValue());
				SetColorTableTexture(other.GetColorTableTexture());
				SetArrowTexture(other.GetArrowTexture());
				SetArrowMove(other.IsArrowMove());
			}

			SlopeSetting& SlopeSetting::operator=(SlopeSetting& other)
			{
				SetDisplaySytle(other.GetDisplaySytle());
				SetColorTableMaxKey(other.GetColorTableMaxKey());
				SetColorTableMinKey(other.GetColorTableMinKey());
				SetMaxVisibleValue(other.GetMaxVisibleValue());
				SetMinVisibleValue(other.GetMinVisibleValue());
				SetColorTableTexture(other.GetColorTableTexture());
				SetArrowTexture(other.GetArrowTexture());
				SetArrowMove(other.IsArrowMove());
				return *this;
			}

			SlopeSetting::~SlopeSetting()
			{
				if (m_pSlopeSetting != nullptr)
				{
					_SlopeSetting_Destroy(m_pSlopeSetting);
				}

				if (m_colorTableTexture != nullptr)
				{
					m_colorTableTexture = nullptr;
				}

				if (m_arrowTexture != nullptr)
				{
					m_arrowTexture->RemoveFromRoot();
					m_arrowTexture->MarkPendingKill();
					m_arrowTexture = nullptr;
				}
			}

			void SlopeSetting::SetDisplaySytle(SlopeSetting::DisplayMode mode)
			{
				_SlopeSetting_SetDisplayMode(m_pSlopeSetting, (int)mode);
			}

			SlopeSetting::DisplayMode SlopeSetting::GetDisplaySytle()
			{
				return (SlopeSetting::DisplayMode)_SlopeSetting_GetDisplayMode(m_pSlopeSetting);
			}

			void SlopeSetting::SetMinVisibleValue(double minValue)
			{
				_SlopeSetting_SetMinVisibleValue(m_pSlopeSetting, minValue);
			}

			double SlopeSetting::GetMinVisibleValue()
			{
				return _SlopeSetting_GetMinVisibleValue(m_pSlopeSetting);
			}

			void SlopeSetting::SetMaxVisibleValue(double maxValue)
			{
				_SlopeSetting_SetMaxVisibleValue(m_pSlopeSetting, maxValue);
			}

			double SlopeSetting::GetMaxVisibleValue()
			{
				return _SlopeSetting_GetMaxVisibleValue(m_pSlopeSetting);
			}

			void SlopeSetting::SetColorTableMaxKey(double dMaxKey)
			{
				m_dCeil = dMaxKey;
			}

			double SlopeSetting::GetColorTableMaxKey()
			{
				return m_dCeil;
			}

			void SlopeSetting::SetColorTableMinKey(double dMinKey)
			{
				m_dFloor = dMinKey;
			}

			double SlopeSetting::GetColorTableMinKey()
			{
				return m_dFloor;
			}

			void SlopeSetting::SetColorTableTexture(UTexture2D* colorTableTexture)
			{
				m_colorTableTexture = colorTableTexture;
			}

			UTexture2D* SlopeSetting::GetColorTableTexture()
			{
				return m_colorTableTexture;
			}

			void SlopeSetting::SetArrowTexture(UTexture2D* arrowTexture)
			{
				m_arrowTexture = arrowTexture;
			}

			UTexture2D* SlopeSetting::GetArrowTexture()
			{
				return m_arrowTexture;
			}

			void SlopeSetting::SetArrowMove(bool isMove)
			{
				m_bArrowMove = isMove;
			}

			bool SlopeSetting::IsArrowMove()
			{
				return m_bArrowMove;
			}

			void SlopeSetting::ReleaseTexture()
			{
				if (m_colorTableTexture != nullptr)
				{
					m_colorTableTexture->RemoveFromRoot();
					m_colorTableTexture->MarkPendingKill();
					m_colorTableTexture = nullptr;
				}
			}

			void SlopeSetting::InitialColorTableTexture()
			{
				ReleaseTexture();

				// TODO:解析颜色表文件
				int nWidth = 1;
				int nHeight = 10;
				m_colorTableTexture = UTexture2D::CreateTransient(nWidth, nHeight, EPixelFormat::PF_R8G8B8A8);
				m_colorTableTexture->AddressX = TextureAddress::TA_Clamp;
				m_colorTableTexture->AddressY = TextureAddress::TA_Clamp;
				m_colorTableTexture->AddToRoot();

				uint8* pTextureData = new uint8[nWidth * nHeight * 4];

				for (int i = 0; i < nHeight; i++)
				{
					pTextureData[i * 4 + 0] = 25 * i;
					pTextureData[i * 4 + 1] = 255 - 25 * i;
					pTextureData[i * 4 + 2] = 0;
					pTextureData[i * 4 + 3] = 255;
				}

				FTexture2DMipMap& pTexture2DMipMap = m_colorTableTexture->PlatformData->Mips[0];
				int64 nBufferSize = pTexture2DMipMap.BulkData.GetBulkDataSize();

				void* Data = pTexture2DMipMap.BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(Data, pTextureData, nBufferSize);
				pTexture2DMipMap.BulkData.Unlock();

				m_colorTableTexture->UpdateResource();

				delete[] pTextureData;
				pTextureData = nullptr;
			}

			void SlopeSetting::UpdateShaderParams(SlopeMapShaderParams& param)
			{
				param.SlopeDisplayMode = int(GetDisplaySytle());
				param.SlopeFloorAngle = FMath::DegreesToRadians(GetColorTableMinKey());
				param.SlopeCeilAngle = FMath::DegreesToRadians(GetColorTableMaxKey());
				param.SlopeMinVisibleSlope = FMath::DegreesToRadians(GetMinVisibleValue());
				param.SlopeMaxVisibleSlope = FMath::DegreesToRadians(GetMaxVisibleValue());
				param.SlopeColorTexture = GetColorTableTexture();
				param.SlopeArrowTexture = GetArrowTexture();
				param.SlopeArrowsMove = IsArrowMove() ? 1.0 : 0.0;
			}
		}
	}
}