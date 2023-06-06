#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			//! \brief 风格的高度模式
			enum AltitudeMode
			{
				//! \brief 绝对高度
				Absolute = 2,
				//! \brief 贴对象
				ClampToObject = 6,
			};

			//! \brief 填充模式
			enum FillMode3D
			{
				//! \brief 填充
				FillMode3D_Fill = 1,
				//! \brief 轮廓
				FillMode3D_Line = 2,
				//! \brief 填充与轮廓
				FillMode3D_LineAndFill = 3
			};

			class SUPERMAP_API Style3D
			{
			public:
				Style3D();
				Style3D(void* pStyle3D);
				~Style3D();

				void* GetHandler();

				//! \brief 高度模式
				void SetAltitudeMode(AltitudeMode mode);

				AltitudeMode GetAltitudeMode();

				//! \brief 底部高程
				void SetBottomAltitude(Gamedouble dAltitude);

				Gamedouble GetBottomAltitude();

				//! \brief 拉伸高度
				void SetExtendHeight(Gamedouble dHeight);

				Gamedouble GetExtendHeight();

				//! \brief 填充颜色
				void SetFillColor(FVector4 fillColor);

				FVector4 GetFillColor();

				//! \brief 填充模式
				void SetFill3DMode(FillMode3D mode);

				FillMode3D GetFill3DMode();

				//! \brief 线填充颜色
				void SetLineColor3D(FColor lineColor3D);

				FColor GetLineColor3D();

				//! \brief 线宽
				void SetLineWidth(Gamedouble dLineWidth);

				Gamedouble GetLineWidth();

				//! \brief 缩放
				void SetMarker3DScale(FVector vScale);
				FVector GetMarker3DScale();

				//! \brief 旋转
				void SetMarker3DRotate(FVector vRotate);
				FVector GetMarker3DRotate();

				//! \brief 平移
				void SetMarker3DTranslation(FVector vTranslation);
				FVector GetMarker3DTranslation();

				//! \brief 设置顶面纹理
				void SetTopTexture(FString filePath);
				void SetSideTexture(FString filePath);
				
				//! \brief 设置纹理UV
				void SetTilingU(double dTilingU);
				void SetTilingV(double dTilingV);
				void SetTopTilingU(double dU);
				void SetTopTilingV(double dV);
			private:

				void* m_pStyle3D;
			};
		}
	}
}