#include "Core/Style3D.h"

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Style3D::Style3D()
			{
				m_pStyle3D = nullptr;
				_Style3D_Create(m_pStyle3D);
			}

			Style3D::Style3D(void* pStyle3D)
			{
				m_pStyle3D = pStyle3D;
			}

			Style3D::~Style3D()
			{
				if (m_pStyle3D != nullptr)
				{
					_Style3D_Destroy(m_pStyle3D);
				}
			}

			void* Style3D::GetHandler()
			{
				return m_pStyle3D;
			}

			void Style3D::SetAltitudeMode(AltitudeMode mode)
			{
				_Style3D_SetAltitudeMode(m_pStyle3D, (Gameint)mode);
			}

			AltitudeMode Style3D::GetAltitudeMode()
			{
				return (AltitudeMode)_Style3D_GetAltitudeMode(m_pStyle3D);
			}

			void Style3D::SetBottomAltitude(Gamedouble dAltitude)
			{
				_Style3D_SetBottomAltitude(m_pStyle3D, dAltitude);
			}

			Gamedouble Style3D::GetBottomAltitude()
			{
				return _Style3D_GetBottomAltitude(m_pStyle3D);
			}

			void Style3D::SetExtendHeight(Gamedouble dHeight)
			{
				_Style3D_SetExtendHeight(m_pStyle3D, dHeight);
			}

			Gamedouble Style3D::GetExtendHeight()
			{
				return _Style3D_GetExtendHeight(m_pStyle3D);
			}

			void Style3D::SetFillColor(FVector4 fillColor)
			{
				_Style3D_SetFillColor(m_pStyle3D, fillColor.X, fillColor.Y, fillColor.Z, fillColor.W);
			}

			FVector4 Style3D::GetFillColor()
			{
				Gamefloat r, g, b, a;
				_Style3D_GetFillColor(m_pStyle3D, r, g, b, a);
				FVector4 fillColor = FVector4(r, g, b, a);
				return fillColor;
			}

			void Style3D::SetFill3DMode(FillMode3D mode)
			{
				_Style3D_SetFill3DMode(m_pStyle3D, (Gameint)mode);
			}

			FillMode3D Style3D::GetFill3DMode()
			{
				return (FillMode3D)_Style3D_GetFill3DMode(m_pStyle3D);
			}

			void Style3D::SetLineColor3D(FColor lineColor3D)
			{
				_Style3D_SetLineColor3D(m_pStyle3D, lineColor3D.R, lineColor3D.G, lineColor3D.B, lineColor3D.A);
			}

			FColor Style3D::GetLineColor3D()
			{
				Gamefloat r, g, b, a;
				_Style3D_GetLineColor3D(m_pStyle3D, r, g, b, a);
				FColor lineColor = FColor(r, g, b, a);
				return lineColor;
			}

			void Style3D::SetLineWidth(Gamedouble dLineWidth)
			{
				_Style3D_SetLineWidth(m_pStyle3D, dLineWidth);
			}

			Gamedouble Style3D::GetLineWidth()
			{
				return _Style3D_GetLineWidth(m_pStyle3D);
			}

			void Style3D::SetMarker3DScale(FVector vScale)
			{
				if (_Style3D_SetMarker3DScale)
				{
					_Style3D_SetMarker3DScale(m_pStyle3D, vScale.Y, vScale.X, vScale.Z);
				}
			}

			FVector Style3D::GetMarker3DScale()
			{
				Gamedouble dX = 0, dY = 0, dZ = 0;
				if (_Style3D_GetMarker3DScale)
				{
					_Style3D_GetMarker3DScale(m_pStyle3D, dY, dX, dZ);
				}
				FVector result = FVector(dX, dY, dZ);
				return result;
			}

			void Style3D::SetMarker3DRotate(FVector vRotate)
			{
				if (_Style3D_SetMarker3DRotate)
				{
					_Style3D_SetMarker3DRotate(m_pStyle3D, vRotate.Y, vRotate.X, vRotate.Z);
				}
			}

			FVector Style3D::GetMarker3DRotate()
			{
				Gamedouble dX = 0, dY = 0, dZ = 0;
				if (_Style3D_GetMarker3DRotate)
				{
					_Style3D_GetMarker3DRotate(m_pStyle3D, dY, dX, dZ);
				}
				FVector result = FVector(dX, dY, dZ);
				return result;
			}

			void Style3D::SetMarker3DTranslation(FVector vTranslation)
			{
				if (_Style3D_SetMarker3DTranslation)
				{
					_Style3D_SetMarker3DTranslation(m_pStyle3D, vTranslation.Y, vTranslation.X, vTranslation.Z);
				}
			}

			FVector Style3D::GetMarker3DTranslation()
			{
				Gamedouble dX = 0, dY = 0, dZ = 0;
				if (_Style3D_GetMarker3DTranslation)
				{
					_Style3D_GetMarker3DTranslation(m_pStyle3D, dY, dX, dZ);
				}
				FVector result = FVector(dX, dY, dZ);
				return result;
			}

			void Style3D::SetSideTexture(FString filePath)
			{
				const TCHAR* cfilePath = *filePath;
				ANSICHAR* ccfilePath = TCHAR_TO_UTF8(cfilePath);
				_Style3D_SetSideTexture(m_pStyle3D, ccfilePath);
			}

			void Style3D::SetTilingU(double dTilingU)
			{
				_Style3D_SetTilingU(m_pStyle3D, dTilingU);
			}

			void Style3D::SetTilingV(double dTilingV)
			{
				_Style3D_SetTilingV(m_pStyle3D, dTilingV);
			}

			void Style3D::SetTopTexture(FString filePath)
			{
				const TCHAR* cfilePath = *filePath;
				ANSICHAR* ccfilePath = TCHAR_TO_UTF8(cfilePath);
				_Style3D_SetTopTexture(m_pStyle3D, ccfilePath);
			}

			void Style3D::SetTopTilingU(double dU)
			{
				_Style3D_SetTopTilingU(m_pStyle3D, dU);
			}

			void Style3D::SetTopTilingV(double dV)
			{
				_Style3D_SetTopTilingV(m_pStyle3D, dV);
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif