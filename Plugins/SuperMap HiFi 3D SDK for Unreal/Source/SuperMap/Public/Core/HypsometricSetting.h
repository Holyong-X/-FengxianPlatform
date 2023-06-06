#pragma once
#include "CoreMinimal.h"
#include "Core/RealspaceDLL.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Component/SuperMap_MeshComponent.h"
#include "Data/GeoRegion3D.h"
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			enum DisplayMode
			{
				//! \brief ��
				NONE = 0,
				//! \brief �������
				Face = 1,
				//! \brief ��ֵ��
				Line = 2,
				//! \brief ���ģʽ
				Face_And_Line = 3,
			};

			enum AnalysisMode
			{
				AM_CONTOUR_MAP = 0,	// �߶ȷ���
				AM_GUIDES = 2,	// �ο���
			};

			class SUPERMAP_API HypsometricSetting
			{
			public:
				HypsometricSetting();
				~HypsometricSetting();
			public:

				//! \brief �����Ƿ���ʾ��&���ɫ��
				void SetDisplayMode(DisplayMode mode);

				//! \brief ����ߵ���ʾģʽ��
				DisplayMode GetDisplayMode();

				//! \brief �����Ƿ���ģʽ
				void SetAnalysisMode(AnalysisMode mode);

				//! \brief ��÷���ģʽ
				AnalysisMode GetAnalysisMode();

				//! \brief ���ü��
				void SetLinesInterval(double dLinesInterval);

				//! \brief ��ȡ���
				double GetLinesInterval();

				//! \brief ��������ɫ
				void SetLineColor(FColor color);

				//! \brief ��ȡ����ɫ
				FColor GetLineColor();

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

				//! \brief ������ɫ���ļ�·��
				void SetColorTableFile(FString strFilePath);

				//! \brief ��ȡ��ɫ���ļ�·��
				FString GetColorTableFile();

				//! \brief ������ɫ��
				void SetColorTableTexture(UTexture2D* colorTableTexture);

				//! \brief ��ȡ��ɫ��
				UTexture2D* GetColorTableTexture();
			private:
				void ReleaseTexture();
				void InitialColorTableTexture();
			private:
				//! \brief ��ɫ���ļ�
				FString m_strColorTableFile;
				//! \brief ��ɫ������
				UTexture2D* m_colorTableTexture;
				//! \brief ���ձ����ֵ
				double m_dCeil;
				//! \brief ���ձ���Сֵ
				double m_dFloor;
				//! \brief UGC����
				void* m_pHypsometricSetting;
			};

			class SUPERMAP_API ModifyTerrainObject
			{
			public:
				ModifyTerrainObject();
				~ModifyTerrainObject();
			public:
				//! \brief �������ڷ���
				//! \brief �ⲿ��Ҫɾ��GeoRegion3D(�ڲ��Ѹ���)
				void SetRegion(GeoRegion3D* pGeoRegion3D);

				//! \brief �������ڷ��߶�
				void SetHeight(double dHeight);

				void* GetHandler();
			private:
				void* m_pModifyTerrainObject;
			};

			class SUPERMAP_API ModifyTerrainSetting
			{
			public:
				ModifyTerrainSetting(void* pModifyTerrainSetting);
				ModifyTerrainSetting();
				~ModifyTerrainSetting();
			public:
				//! \brief ���һ���޸ĵ��εĶ���
				void Add(ModifyTerrainObject* pModifyTerrainObject, FString tag);

				//! \brief ���
				void Clear();
			private:
				void* m_pModifyTerrainSetting;
			};
		}
	}
}