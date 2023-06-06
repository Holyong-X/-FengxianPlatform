#pragma once
#include "CoreMinimal.h"
#include "Core/RealspaceDLL.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Component/SuperMap_MeshComponent.h"
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			struct SlopeMapShaderParams
			{
			public:
				SlopeMapShaderParams();
			public:
				int SlopeDisplayMode;
				float SlopeFloorAngle;
				float SlopeCeilAngle;
				float SlopeMinVisibleSlope;
				float SlopeMaxVisibleSlope;
				UTexture2D* SlopeColorTexture;
				UTexture2D* SlopeArrowTexture;
				float SlopeArrowsMove;
				float SlopeTopLevel;
				float SlopeTimeVal;
			};

			class SUPERMAP_API SlopeSetting
			{
			public:
				//! \brief ��ʾģʽ
				enum DisplayMode
				{
					//! \brief ��ʹ����ʾģʽ
					NONE = 0,
					//! \brief ��ʾ���
					FACE = 1,
					//! \brief ��ʾ����
					ARROW = 2,
					//! \brief ��ʾ��������
					FACE_AND_ARROW = 3
				};

			public:
				SlopeSetting();

				SlopeSetting(SlopeSetting& other);

				~SlopeSetting();
			public:
				SlopeSetting& operator=(SlopeSetting& other);

				//! \brief �����Ƿ���ʾ��&���ɫ��
				void SetDisplaySytle(SlopeSetting::DisplayMode mode);

				//! \brief ����ߵ���ʾģʽ��
				SlopeSetting::DisplayMode GetDisplaySytle();

				//! \brief ������ɫ�����ֵ
				void SetColorTableMaxKey(double dMaxKey);

				//! \brief ��ȡ��ɫ�����ֵ
				double GetColorTableMaxKey();

				//! \brief ������ɫ�����ֵ
				void SetColorTableMinKey(double dMinKey);

				//! \brief ��ȡ��ɫ�����ֵ
				double GetColorTableMinKey();

				//! \brief ������С�ɼ�ֵ
				void SetMinVisibleValue(double minValue);

				//! \brief ��ȡ��С�ɼ�ֵ
				double GetMinVisibleValue();

				//! \brief �������ɼ�ֵ
				void SetMaxVisibleValue(double maxValue);

				//! \brief ��ȡ��С�ɼ�ֵ
				double GetMaxVisibleValue();

				//! \brief ������ɫ��
				void SetColorTableTexture(UTexture2D* colorTableTexture);

				//! \brief ��ȡ��ɫ��
				UTexture2D* GetColorTableTexture();

				//! \brief ���������ͷ����
				void SetArrowTexture(UTexture2D* arrowTexture);

				//! \brief ��ȡ�����ͷ����
				UTexture2D* GetArrowTexture();

				//! \brief ���������ͷ�Ƿ��˶�
				void SetArrowMove(bool isMove);

				//! \brief ��ȡ�����ͷ�Ƿ��˶�
				bool IsArrowMove();

				//! \brief ����ɫ����������ֵ
				void UpdateShaderParams(SlopeMapShaderParams& param);
			private:
				void ReleaseTexture();
				void InitialColorTableTexture();
			private:
				//! \brief ��ɫ������
				UTexture2D* m_colorTableTexture;
				//! \brief �����ͷ����
				UTexture2D* m_arrowTexture;
				//! \brief ���ձ����ֵ
				double m_dCeil;
				//! \brief ���ձ���Сֵ
				double m_dFloor;
				//! \brief �����ͷ�Ƿ��˶�
				bool m_bArrowMove;
				//! \brief UGC����
				void* m_pSlopeSetting;
			};
		}
	}
}