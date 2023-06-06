#pragma once

#include "CoreMinimal.h"
#include "Layer3DType.h"
#include "Core/HypsometricSetting.h"
#include "Core/SlopeSetting.h"
#include "Core/RealspaceDLL.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class TerrainLayer;
			class Scene;
			class SUPERMAP_API TerrainLayers
			{
			public:
				TerrainLayers();
				TerrainLayers(Scene* pScene);
				~TerrainLayers();

			private:
				//! \breif ����
				Scene* m_pScene;

				//! \brief ͼ���б�
				TArray<TerrainLayer*> m_terrain3Ds;

			public:
				//! \brief ͼ����Ŀ
				int Count();

				//! \brief ���iserver����ͼ��
				TerrainLayer* Add(FString strIServerUrl, FString strLayerName);

				//! \brief ��ӵ���ͼ��
				TerrainLayer* Add(FString strFile, bool bAddToHead);

				//! \brief ��ӹ�������ͼ��
				TerrainLayer* Add(FString strUrl, FString strLayerName, TerrainLayerType eLayerType);

				//! \brief ��ȡָ���±�ĵ���
				TerrainLayer* GetAt(int32 index);

				//! \brief ��ȡָ�����Ƶĵ���
				TerrainLayer* GetAt(FName strLayerName);

				//! \brief �Ƴ�����ͼ��
				bool Remove(int Index = 0);

				//! \brief ��Ⱦ����
				void Render();

				//! \brief ���÷ֲ���ɫ��
				void SetHypsometricSetting(HypsometricSetting* pHypsometricSetting);

				//! \brief ��ȡ�ֲ���ɫ��
				HypsometricSetting* GetHypsometricSetting();

				//! \brief ��ȡ�޸ĵ��ζ���
				ModifyTerrainSetting* GetModifyTerrainSetting();

				//! \brief ����ֲ���ɫ
				void ClearHypsometricSetting();

				//! \brief �����¶�������
				void SetSlopeSetting(SlopeSetting* pSlopeSetting);

				//! \brief ��ȡ�¶�������
				SlopeSetting* GetSlopeSetting();

				//! \brief ����¶�����
				void ClearSlopeSetting();

				//! \brief �������ͼ��
				void Clear();

				//! \brief ��GameComponent��ӵ����ε���Ⱦ���������
				void AddNativeGameComponent(GameComponent* pGameComponent);
				//! \brief ��GameComponent�ӵ��ε���Ⱦ����������Ƴ�
				void RemoveNativeGameComponent(GameComponent* pGameComponent);
				//! \brief ��ȡ����ͼ���б�
				TArray<TerrainLayer*>& GetTerrainLayer3Ds();
			private:

				//! \brief ��Ⱦ����
				void UpdateHypsometricSetting();

				//! \brief �����¶�����
				void UpdateSlopeSetting();

				//! \brief �����¶�����̬����
				void UpdateDynamicSlopeParam();

				//! \brief ���´�GameComponent�Ĳ��ʵ���ɫ������
				void UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent);

				void UpdateSlopeShaderForOneMaterial(UMaterialInstanceDynamic* pMat);

				void UpdateHypsometricSettingShaderForOneMaterial(UMaterialInstanceDynamic* pMat);
			private:
				//! \brief �ֲ���ɫ
				HypsometricSetting* m_pHypsometricSetting;

				ModifyTerrainSetting* m_pModifyTerrainSetting;

				//! \brief �ֲ���ɫ����
				bool m_bUpdateHypsometricSetting;

				//! \brief �¶�����
				SlopeSetting* m_pSlopeSetting;

				//! \brief �¶��������
				bool m_bUpdateSlopeSetting;

				//! \brief �¶ȷ�������ɫ����������
				SlopeMapShaderParams m_SlopeMapShaderParams;

				//! \brief ʱ���ۼ�
				float m_fSumTime;

				//! \brief ���γ��е���Ⱦ����
				TMap<Gamelong, GameComponent*> m_mapNativeGameComponent;
			};
		}
	}
}