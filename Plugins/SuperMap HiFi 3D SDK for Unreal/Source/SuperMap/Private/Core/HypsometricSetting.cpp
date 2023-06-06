#include "Core/HypsometricSetting.h"
#include "Core/ROCacheManager.h"

using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			HypsometricSetting::HypsometricSetting()
			{
				_CreateHypsometricSetting(m_pHypsometricSetting);
				m_colorTableTexture = nullptr;
				m_dCeil = -1;
				m_dFloor = -1;
				_SetLineColor(m_pHypsometricSetting, 255, 40.8, 0, 255);
			}

			HypsometricSetting::~HypsometricSetting()
			{
				if (m_pHypsometricSetting != nullptr)
				{
					_DestroyHypsometricSetting(m_pHypsometricSetting);
				}
			}

			void HypsometricSetting::SetDisplayMode(DisplayMode mode)
			{
				_SetDisplayMode(m_pHypsometricSetting, (int)mode);
			}

			DisplayMode HypsometricSetting::GetDisplayMode()
			{
				return (DisplayMode)_GetDisplayMode(m_pHypsometricSetting);
			}

			void HypsometricSetting::SetMinVisibleValue(double minValue)
			{
				_SetMinVisibleValue(m_pHypsometricSetting, minValue);
			}

			double HypsometricSetting::GetMinVisibleValue()
			{
				return _GetMinVisibleValue(m_pHypsometricSetting);
			}

			void HypsometricSetting::SetMaxVisibleValue(double maxValue)
			{
				_SetMaxVisibleValue(m_pHypsometricSetting, maxValue);
			}

			double HypsometricSetting::GetMaxVisibleValue()
			{
				return _GetMaxVisibleValue(m_pHypsometricSetting);
			}

			void HypsometricSetting::SetAnalysisMode(AnalysisMode mode)
			{
				_SetAnalysisMode(m_pHypsometricSetting, (int)mode);
			}

			AnalysisMode HypsometricSetting::GetAnalysisMode()
			{
				return (AnalysisMode)_GetAnalysisMode(m_pHypsometricSetting);
			}

			void HypsometricSetting::SetColorTableMaxKey(double dMaxKey)
			{
				m_dCeil = dMaxKey;
			}

			double HypsometricSetting::GetColorTableMaxKey()
			{
				return m_dCeil;
			}

			void HypsometricSetting::SetColorTableMinKey(double dMinKey)
			{
				m_dFloor = dMinKey;
			}

			double HypsometricSetting::GetColorTableMinKey()
			{
				return m_dFloor;
			}

			void HypsometricSetting::SetLinesInterval(double dLinesInterval)
			{
				_SetLinesInterval(m_pHypsometricSetting, dLinesInterval);
			}

			double HypsometricSetting::GetLinesInterval()
			{
				return _GetLinesInterval(m_pHypsometricSetting);
			}

			void HypsometricSetting::SetLineColor(FColor color)
			{
				_SetLineColor(m_pHypsometricSetting, color.R, color.G, color.B, color.A);
			}

			FColor HypsometricSetting::GetLineColor()
			{
				float fR = 0, fG = 0, fB = 0, fA = 0;
				_GetLineColor(m_pHypsometricSetting, fR, fG, fB, fA);
				FColor lineColor = FColor(fR, fG, fB, fA);
				return lineColor;
			}

			void HypsometricSetting::SetColorTableFile(FString strFilePath)
			{
				m_strColorTableFile = strFilePath;
				InitialColorTableTexture();
			}

			FString HypsometricSetting::GetColorTableFile()
			{
				return m_strColorTableFile;
			}

			void HypsometricSetting::SetColorTableTexture(UTexture2D* colorTableTexture)
			{
				m_colorTableTexture = colorTableTexture;
			}

			UTexture2D* HypsometricSetting::GetColorTableTexture()
			{
				return m_colorTableTexture;
			}

			void HypsometricSetting::ReleaseTexture()
			{
				if (m_colorTableTexture == nullptr)
				{
					return;
				}
				m_colorTableTexture->RemoveFromRoot();
				m_colorTableTexture->MarkPendingKill();
				m_colorTableTexture = nullptr;
			}

			void HypsometricSetting::InitialColorTableTexture()
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

			ModifyTerrainObject::ModifyTerrainObject()
			{
				m_pModifyTerrainObject = nullptr;
				_ModifyTerrainObject_Create(m_pModifyTerrainObject);
			}

			ModifyTerrainObject::~ModifyTerrainObject()
			{
				//_ModifyTerrainObject_Destroy(m_pModifyTerrainObject);
				m_pModifyTerrainObject = nullptr;
			}

			void ModifyTerrainObject::SetRegion(GeoRegion3D* pGeoRegion3D)
			{
				if (pGeoRegion3D == nullptr)
				{
					return;
				}
				_ModifyTerrainObject_SetRegion(m_pModifyTerrainObject, pGeoRegion3D->GetHandler());
			}

			void ModifyTerrainObject::SetHeight(double dHeight)
			{
				_ModifyTerrainObject_SetHeight(m_pModifyTerrainObject, dHeight);
			}

			void* ModifyTerrainObject::GetHandler()
			{
				return m_pModifyTerrainObject;
			}

			ModifyTerrainSetting::ModifyTerrainSetting(void* pModifyTerrainSetting)
			{
				m_pModifyTerrainSetting = pModifyTerrainSetting;
			}

			ModifyTerrainSetting::ModifyTerrainSetting()
			{
				m_pModifyTerrainSetting = nullptr;
			}

			ModifyTerrainSetting::~ModifyTerrainSetting()
			{
				m_pModifyTerrainSetting = nullptr;
			}

			void ModifyTerrainSetting::Add(ModifyTerrainObject* pModifyTerrainObject, FString tag)
			{
				if (pModifyTerrainObject == nullptr)
				{
					return;
				}
				const TCHAR* ctag = *tag;
				ANSICHAR* cctag = TCHAR_TO_UTF8(ctag);
				_ModifyTerrainSetting_Add(m_pModifyTerrainSetting, pModifyTerrainObject->GetHandler(), cctag);
			}

			void ModifyTerrainSetting::Clear()
			{
				_ModifyTerrainSetting_Clear(m_pModifyTerrainSetting);
			}
		}
	}
}