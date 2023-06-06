#pragma once

#include "CoreMinimal.h"
#include "Layer3D.h"
#include "Core/AttributeFields.h"
#include "Core/HypsometricSetting.h"
#include "Data/GeoRegion3D.h"
#include "Data/Matrix4d.h"
#include "Data/Vector4d.h"
#include "Core/ROCacheManager.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Core;

class UWorld;
class UTextureRenderTarget2D;
class UTexture2D;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			enum SUPERMAP_API ModifyRegionMode
			{
				ClipInside,
				ClipOutside,
				Mosaic,
				Flatten,
				Modify_None
			};

			enum SUPERMAP_API LoadingPriorityEnum
			{
				//广度优先
				Root_Priority,
				//深度优先
				Child_Priority,
				//索引优先
				UsePagedLodInfo,
				//深度优先非线性切换
				Child_Priority_NonLinear

			};

			struct S3MEffectShaderParamters
			{
				//! \brief 倾斜压平开挖矢量面
				ModifyRegionMode m_eModifyRegionMode;

				//! \brief 倾斜压平开挖范围
				FVector4 m_v4S3MEffectRectPos;

				//! \brief 压平开挖多边形的个数
				int32 m_nRegionCount;

				//! \brief
				Matrix4d m_matWorldToFlattenLocal;
				Matrix4d m_matS3MEffectLocalToWorld;
				
				//! \brief 压平开挖多边形纹理
				UTextureRenderTarget2D* m_pS3MEffectTexture;

				S3MEffectShaderParamters()
				{
					m_eModifyRegionMode = ModifyRegionMode::Modify_None;
					m_pS3MEffectTexture = nullptr;
				}
			};

			class SUPERMAP_API ObjectsColorDictionary
			{
			public:
				ObjectsColorDictionary(void* pUGLayer3D);
				~ObjectsColorDictionary();

				//! \brief 设置对象颜色
				void SetObjectsColor(TArray<Gameint> ids, FVector4 color);
				
				//! \brief 获得对象颜色
				TMap<Gameint, FVector4> GetObjectsColor();
				
				//! \brief 重置对象颜色
				void RemoveObjectsColor(TArray<Gameint> ids);

				//! \brief 重置所有对象颜色
				void ResetObjectsColor();

			private:

				void* m_pUGLayer3DS3MFile;
			};

			class SUPERMAP_API Layer3DS3MFile : public Layer3D
			{
			public:
				Layer3DS3MFile();
				Layer3DS3MFile(FName strLayerName, Layer3DType eLayerType);
				Layer3DS3MFile(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3DS3MFile();

				//! \brief 获取当前图层的属性字段
				std::vector<FString> GetFieldInfos();
				std::vector<FString> GetFieldInfos(Gameint nID);

				//! \brief 获取当前属性字段名称
				std::vector<FString> GetAllFieldValues(Gameint nID);

				//! \brief 获取图层最大高度
				Gamedouble GetMaxHeight();

				//! \brief 获取图层低高程
				Gamedouble GetMinHeight();

				//! \brief 设置当前图层的LOD层级
				void SetLODRangeScale(int nLayerID, float values);

				//! \brief 获取当前图层的LOD层级
				float GetLODRangeScale(int nLayerID);

				//! \brief 添加压平的矢量(由图层释放矢量面)
				void AddFlattenRegion(GeoRegion3D* pGeoRegion3D, FString strTag);

				//! \brief 清除压平矢量面
				void ClearFlattenRegion();

				//! \brief 获取压平开挖需要的参数
				S3MEffectShaderParamters GetS3MEffectParam();

				//! \brief 设置分层设色类
				void SetHypsometricSetting(HypsometricSetting* pHypsometricSetting);

				//! \brief 获取分层设色类
				HypsometricSetting* GetHypsometricSetting();

				//! \brief 清除分层设色
				void ClearHypsometricSetting();

				//! \brief 多边形偏移
				void SetConstantPolygonOffset(double dOffset);
				double GetConstantPolygonOffset();

				//! \brief 设置ID列表中对象的可见性
				void SetObjectsVisible(TArray<Gameint> ids, Gamebool bVisible);

				//! \breif 设置ID列表种材质替换名
				void SetObjectsMaterial(TArray<Gameint> ids, FString strMaterialName);

				//! \brief 渲染数据
				virtual void Render(UWorld* pWorld);

				//! \brief 获取图层高度最大最小值
				double GetMaxDataValue();
				double GetMinDataValue();

				//! \brief 获取图层属性信息
				AttributeFields GetAttributeFields();

				//! \brief 模型倾斜开挖
				void SetModifyRegions(TArray<GeoRegion3D*> pGeoRegion3Ds, ModifyRegionMode type);

				void ClearModifyRegions();
				//! \brief 设置/获取Meshopt数据是否CPU解量化
				void SetDecodeMeshopt(Gamebool value);
				Gamebool IsDecodeMeshopt();

				//! \brief 导出S3M图层关联材质
				void ExportUEMaterialToJson(FString ScpFilePath);				
				
				//! \brief 添加关联材质路径到scp文件
				void AddRelatedPathToScpFile(FString LayerInfoPath, FString ScpFilePath);

				//! \brief 获取设置对象颜色的指针
				ObjectsColorDictionary* GetObjectsColorDictionary();

				//! \brief 设置加载数据模式
				void SetLoadingPriority(LoadingPriorityEnum type);

				//! \brief 获取加载数据模式
				LoadingPriorityEnum GetLoadingPriority();

				//! \brief 添加影象图层
				void SetCoverImageryLayer(TArray<Layer3D*> arrImageLayers);

				//! \brief 添加图层的渲染对象
				virtual void AddNativeGameComponent(GameComponent* pGameComponent);
				//! \brief 移除图层的渲染对象
				virtual void RemoveNativeGameComponent(GameComponent* pGameComponent);
			private:
				//! \brief 计算压平开挖参数
				void CalS3MEffectParam(int32 nRegionCount, ModifyRegionMode type);

				//! \brief 图层更新压平参数
				void UpdateMaterialS3MEffectParam(int32 nRegionCount,bool bClear = false);

				//! \brief 材质设置矩阵
				void SetMaterialMatrix(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strName);

				//! \brief 渲染数据
				void UpdataHypsometricSetting();

				//! \brief 更新裁剪渲染的参数
				void UpdateClipShaderParam();

				//! \brief 设置材质裁剪参数
				void SetClipShaderParam(UMaterialInstanceDynamic* pMID);

				//! \brief 设置压平着色器参数
				void SetFlattenShaderParam(UMaterialInstanceDynamic* pMID);

				//! \brief 设置开挖着色器参数
				void SetExcavationShaderParam(UMaterialInstanceDynamic* pMat);

				//! \brief 设置等值线着色器参数
				void SetHypsometricSettingShaderParam(UMaterialInstanceDynamic* pMID);

				//! \brief 更换图层材质
				void UpdateMaterialInfo(GameMaterial* pGameMaterial);

				void UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent);

				//! \brief S3M图层信息保存
				void LayerInfoToJson(FString strPath);
			private:
				//! \brief 当前获取ID对象的属性信息
				AttributeFields m_AttributeFields;

				//! \brief 倾斜压平开挖参数
				S3MEffectShaderParamters m_S3MEffectParam;

				//! \brief 等高线高度常量
				double m_dHypsometricHeight;

				//! \brief 多边形偏移量常量
				double m_dConstantPolygonOffset;

				//! \brief 分层设色
				HypsometricSetting* m_pHypsometricSetting;

				//! \brief 压平更新
				Gamebool m_bUpdateS3MEffectShader;

				//! \brief 开挖面个数
				Gameint m_nModifyRegionsCount;

				//! \brief 分层设色更新
				Gamebool m_bUpdataHypsometricSetting;

				//! \brief 开挖、压平类型
				ModifyRegionMode m_eModifyRegionMode;

				friend class ROCacheManager;

				//! \brief 关联材质指针数组
				TArray<UMaterialInterface*> m_arrPtrMaterialInterface;

				ObjectsColorDictionary* m_pObjectsColorDictionary;
			};
		}
	}
}