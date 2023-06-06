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
				//! \breif 场景
				Scene* m_pScene;

				//! \brief 图层列表
				TArray<TerrainLayer*> m_terrain3Ds;

			public:
				//! \brief 图层数目
				int Count();

				//! \brief 添加iserver地形图层
				TerrainLayer* Add(FString strIServerUrl, FString strLayerName);

				//! \brief 添加地形图层
				TerrainLayer* Add(FString strFile, bool bAddToHead);

				//! \brief 添加公共地形图层
				TerrainLayer* Add(FString strUrl, FString strLayerName, TerrainLayerType eLayerType);

				//! \brief 获取指定下标的地形
				TerrainLayer* GetAt(int32 index);

				//! \brief 获取指定名称的地形
				TerrainLayer* GetAt(FName strLayerName);

				//! \brief 移除地形图层
				bool Remove(int Index = 0);

				//! \brief 渲染数据
				void Render();

				//! \brief 设置分层设色类
				void SetHypsometricSetting(HypsometricSetting* pHypsometricSetting);

				//! \brief 获取分层设色类
				HypsometricSetting* GetHypsometricSetting();

				//! \brief 获取修改地形对象
				ModifyTerrainSetting* GetModifyTerrainSetting();

				//! \brief 清除分层设色
				void ClearHypsometricSetting();

				//! \brief 设置坡度坡向类
				void SetSlopeSetting(SlopeSetting* pSlopeSetting);

				//! \brief 获取坡度坡向类
				SlopeSetting* GetSlopeSetting();

				//! \brief 清除坡度坡向
				void ClearSlopeSetting();

				//! \brief 清除地形图层
				void Clear();

				//! \brief 将GameComponent添加到地形的渲染对象队列中
				void AddNativeGameComponent(GameComponent* pGameComponent);
				//! \brief 将GameComponent从地形的渲染对象队列中移除
				void RemoveNativeGameComponent(GameComponent* pGameComponent);
				//! \brief 获取地形图层列表
				TArray<TerrainLayer*>& GetTerrainLayer3Ds();
			private:

				//! \brief 渲染数据
				void UpdateHypsometricSetting();

				//! \brief 更新坡度坡向
				void UpdateSlopeSetting();

				//! \brief 更新坡度坡向动态参数
				void UpdateDynamicSlopeParam();

				//! \brief 更新此GameComponent的材质的着色器参数
				void UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent);

				void UpdateSlopeShaderForOneMaterial(UMaterialInstanceDynamic* pMat);

				void UpdateHypsometricSettingShaderForOneMaterial(UMaterialInstanceDynamic* pMat);
			private:
				//! \brief 分层设色
				HypsometricSetting* m_pHypsometricSetting;

				ModifyTerrainSetting* m_pModifyTerrainSetting;

				//! \brief 分层设色更新
				bool m_bUpdateHypsometricSetting;

				//! \brief 坡度坡向
				SlopeSetting* m_pSlopeSetting;

				//! \brief 坡度坡向更新
				bool m_bUpdateSlopeSetting;

				//! \brief 坡度分析的着色器参数对象
				SlopeMapShaderParams m_SlopeMapShaderParams;

				//! \brief 时间累计
				float m_fSumTime;

				//! \brief 地形持有的渲染对象
				TMap<Gamelong, GameComponent*> m_mapNativeGameComponent;
			};
		}
	}
}