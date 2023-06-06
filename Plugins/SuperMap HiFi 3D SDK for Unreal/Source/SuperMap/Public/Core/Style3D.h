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
			//! \brief ���ĸ߶�ģʽ
			enum AltitudeMode
			{
				//! \brief ���Ը߶�
				Absolute = 2,
				//! \brief ������
				ClampToObject = 6,
			};

			//! \brief ���ģʽ
			enum FillMode3D
			{
				//! \brief ���
				FillMode3D_Fill = 1,
				//! \brief ����
				FillMode3D_Line = 2,
				//! \brief ���������
				FillMode3D_LineAndFill = 3
			};

			class SUPERMAP_API Style3D
			{
			public:
				Style3D();
				Style3D(void* pStyle3D);
				~Style3D();

				void* GetHandler();

				//! \brief �߶�ģʽ
				void SetAltitudeMode(AltitudeMode mode);

				AltitudeMode GetAltitudeMode();

				//! \brief �ײ��߳�
				void SetBottomAltitude(Gamedouble dAltitude);

				Gamedouble GetBottomAltitude();

				//! \brief ����߶�
				void SetExtendHeight(Gamedouble dHeight);

				Gamedouble GetExtendHeight();

				//! \brief �����ɫ
				void SetFillColor(FVector4 fillColor);

				FVector4 GetFillColor();

				//! \brief ���ģʽ
				void SetFill3DMode(FillMode3D mode);

				FillMode3D GetFill3DMode();

				//! \brief �������ɫ
				void SetLineColor3D(FColor lineColor3D);

				FColor GetLineColor3D();

				//! \brief �߿�
				void SetLineWidth(Gamedouble dLineWidth);

				Gamedouble GetLineWidth();

				//! \brief ����
				void SetMarker3DScale(FVector vScale);
				FVector GetMarker3DScale();

				//! \brief ��ת
				void SetMarker3DRotate(FVector vRotate);
				FVector GetMarker3DRotate();

				//! \brief ƽ��
				void SetMarker3DTranslation(FVector vTranslation);
				FVector GetMarker3DTranslation();

				//! \brief ���ö�������
				void SetTopTexture(FString filePath);
				void SetSideTexture(FString filePath);
				
				//! \brief ��������UV
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