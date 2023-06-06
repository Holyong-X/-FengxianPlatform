#pragma once

#include "CoreMinimal.h"
#include "Layer3DType.h"
#include "Layout/SlateRect.h"
#include "Core/Selection3D.h"
#include "Core/Layer3DInfo.h"
#include "Data/Vector3d.h"
#include "Data/Vector4d.h"
#include "Data/GeoBox.h"
#include "Core/ClipMode.h"
#include "Core/AssetStyle.h"
#include "Base3D/Plane.h"
#include "Graphics3D/GameComponent.h"
#include "Data/Rectangle2D.h"
#include "Data/JsonFile.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "Core/RealspaceDLL.h"
#include "Core/Style3D.h"
#include "Core/AssetStyle.h"

using namespace SuperMapSDK::UnrealEngine::Data;
using namespace SuperMapSDK::UnrealEngine::Base3D;
using namespace SuperMapSDK;

typedef void(*LayerDeleteEvent) (void* pActor);
class UWorld;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			struct PlaneClipParam
			{
				//! \brief 裁剪面
				TArray<Plane> m_arrClipPlanes;

				//! \brief 裁剪类型
				BoxClipPart m_eBoxClipMode;

				//! \brief 裁剪边线颜色
				Vector4d  m_vClipLineColor;
			};

			struct SUPERMAP_API LayerDeleteEventInfos
			{
			public:
				//实现触发事件的Actor
				void* m_pActor;
				//触发事件
				LayerDeleteEvent m_LayerDeleteEvent;
			public:
				LayerDeleteEventInfos()
				{
					m_pActor = nullptr;
				}
			};
			//class SuperMapSDK::GameComponent;

			class SUPERMAP_API UEAssetStyle
			{
			public:
				enum SUPERMAP_API Mode
				{
					//外挂小品
					ASSET_MESH = 0,
					//风格样式
					ASSET_MATERIAL = 1,
					//资产放样
					ASSET_LOFT = 2
				};
			public:
				UEAssetStyle();
				~UEAssetStyle();

				//! \brief 设置材质替换数据
				void SetAssetStyles(TMap<FString, AssetStyle*> mapAssetStyles);

				TMap<FString, AssetStyle*> GetAssetStyles();

				//! \brief 风格类型
				UEAssetStyle::Mode GetMode();

				void SetMode(UEAssetStyle::Mode type);
			private:
				UEAssetStyle::Mode m_eMode;

				TMap<FString, AssetStyle*> m_mapAssetStyles;
			};

			class SUPERMAP_API Layer3D
			{
			public:
				Layer3D();
				Layer3D(FName strLayerName, Layer3DType eLayerType);
				Layer3D(void* pUGLayer3D, FName strLayerName, Layer3DType eLayerType);
				virtual ~Layer3D();

			protected:
				//! \brief 图层名字
				FName m_strLayerName;

				//! \brief 图层数据名字
				FName m_strDataLayerName;

				//! \brief 图层类型
				Layer3DType m_eLayerType;

				//! \brief 可见性是否改变
				bool m_bIsVisibleChanged;

				//! \brief 可见性
				bool m_bIsVisible;

				//! \brief 图层材质信息
				Layer3DMaterialInfo m_MaterialInfo;

				//! \brief 图层对象材质信息
				ObjectMaterialInfo m_ObjectMaterialInfo;

				//! \brief 图层ID
				int32 m_nLayerID;

				//! \brief 选择集对象
				Selection3D* m_pSelection;

				//! \brief 裁剪盒子的指针
				GeoBox* m_pClipBox;

				//! \brief 获取Box裁剪模式
				BoxClipPart m_eBoxClipMode;

				//! \brief UGC对象
				void* m_pUGLayer3D;

				//! \brief 更新裁剪
				bool m_bUpdateClip;
				bool m_bHasClip;

				//! \brief 裁剪压平的参数
				PlaneClipParam m_ClipParam;

				//! \brief 图层根节点的名字
				Gamelong m_nNodeName;

				//! \brief 图层持有的渲染对象
				TMap<Gamelong, GameComponent*> m_mapNativeGameComponent;

				//! \brief 初始化
				Gamebool m_bInitial;

				//! \brief 分屏可视性
				Gamebool m_bVisibleInViewport[2];

				//! \brief 是否分屏
				Gamebool m_bIsViewport;

				//! \brief 图层美化风格
				UEAssetStyle* m_pUEAssetStyle;

				//! \brief 删除图层回调事件
				LayerDeleteEventInfos m_LayerDeleteEventInfos;
			public:
				//! \brief 获取UGC句柄
				void* GetHandler();

				//! \brief 获取图层名
				FName Name();

				//! \brief 获取图层全路径
				FString GetDataPath();

				//! \brief 获取图层数据名
				FName DataName();

				//! \brief 获取图层节点名
				FName NodeName();

				//! \brief 获取图层节点名的hashcode值
				Gamelong NodeNameHashCode();

				//! \brief 图层类型
				Layer3DType Type();

				OSGBType DataType();

				//! \brief 获取是否可见性
				virtual bool GetIsVisible();

				//! \brief 设置可见性
				virtual void SetIsVisible(bool bVisible);

				//! \brief 设置插入点 平面使用
				virtual void SetOriginalPosition(FVector vPos);

				//! \brief 返回bounds值
				Rectangle2D GetBounds();

				//! \brief 获取图层ID
				int32 GetLayerID();

				//! \brief 设置图层ID
				void SetLayerID(int32 nLayerID);

				//! \brief 设置选择集
				Selection3D* GetSelection3D();

				//! \brief 获取图层材质信息
				Layer3DMaterialInfo& GetMaterialInfo();

				//! \brief 设置图层材质信息
				void SetMaterialInfo(Layer3DMaterialInfo& info);

				//! \brief 获取图层材质信息
				ObjectMaterialInfo& GetObjectMaterialInfo();

				//! \brief 设置图层材质信息
				void SetObjectMaterialInfo(ObjectMaterialInfo& info);

				//! \brief 设置图层材质信息
				void DeleteObjectMaterialInfo(FString strMaterialName);

				//! \brief 设置自定义裁剪面
				virtual void SetCustomClipPlane(Vector3d firstPoint, Vector3d secondPoint, Vector3d thirdPoint);

				//! \biref 设置一个盒子，对图层可渲染部分进行裁剪
				void ClipByBox(GeoBox* pGeoBox, BoxClipPart ePlaneClipMode);

				//! \brief 获取裁剪盒子
				GeoBox* GetClipBox();

				//! \brief 更新裁剪参数
				void UpdateClipParam();

				//! \brief 获取Box裁剪模式
				BoxClipPart GetBoxClipPart();

				//! \brief 设置裁剪面边缘线的颜色
				void SetClipLineColor(Vector4d vClipLineColor);

				//! \brief 获取裁剪面边缘线的颜色
				Vector4d GetClipLineColor();

				//! \brief 清空自定义裁剪面
				void ClearCustomClipPlane();

				//! \brief 设置是否卷帘
				void SetSwipeEnabled(Gamebool bSwipe);

				//! \brief 获取是否卷帘
				Gamebool GetSwipeEnabled();

				//! \brief 设置卷帘长宽
				void SetSwipeRegion(Rectangle2D rcBox);

				//! \brief 获取卷帘长宽
				Rectangle2D GetSwipeRegion();

				//! \brief 设置是否分屏
				void SetViewportEnabled(Gamebool bViewport);

				//! \brief 保存Json
				JsonFile* LayerToJson();

				//! \brief 更新图层
				void UpdateData();

				//! \brief 设置分屏可视性
				void SetVisibleInViewport(Gameint nIndex, Gamebool visible);

				//! \brief 获取分屏可视性
				Gamebool GetVisibleInViewport(Gameint nIndex);

				//! \brief 添加选中对象
				void AddSelectedID(Gameint nID);

				//! \brief 清空选中对象
				void ReleaseSelection();

				//! \brief 设置图层选中风格
				void SetSelectStyle(Style3D* pStyle3D);

				//! \brief 获取图层选中风格
				void GetSelectStyle(Style3D* &style3d);

				Gamebool IsMarkerLayer();
				void SetMarkerLayer(bool bIsMarkerLayer);

				//! \brief 获取图层美化风格
				UEAssetStyle* GetUEAssetStyle();

				//! \brief 设置图层风格
				void SetStyle(Style3D* pStyle);

				//! \brief 获取图层风格
				void GetStyle(Style3D* &pStyle);

				//! \brief 渲染数据
				virtual void Render(UWorld* pWorld);

				//! \brief 设置图层最远可见距离
				void SetMaxObjectVisibleDistance(Gamedouble dValue);

				//! \brief 设置图层最近可见距离
				//void SetMinObjectVisibleDistance(Gamedouble dValue);

				//! \brief 获取图层最远最近可见距离
				void GetMaxMinObjectVisibleDistance(Gamedouble& dmax, Gamedouble& dmin);

				//! \brief 添加图层的渲染对象
				virtual void AddNativeGameComponent(GameComponent* pGameComponent);
				//! \brief 移除图层的渲染对象
				virtual void RemoveNativeGameComponent(GameComponent* pGameComponent);
				//! \brief 获取图层所有渲染对象
				virtual TMap<Gamelong, GameComponent*>& GetAllNativeGameComponent();

				//! \brief 删除图层回调函数
				void SetDeleteLayerEventFunc(void* pActor, LayerDeleteEvent evnt);
			protected:
				//! \brief 可见性是否改变
				bool GetIsVisibleChanged();

				//! \brief 设置可见性是否改变
				void SetIsVisibleChanged(bool bVisible);

				//! \brief 获取裁剪的参数
				void GetClipParamFromUGC();
			};
		}
	}
}
