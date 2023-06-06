#pragma once

#include "CoreMinimal.h"
#include "Layer3DType.h"
#include "Data/Dataset.h"
#include "Core/RealspaceDLL.h"

using namespace SuperMapSDK::UnrealEngine::Data;

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			class Scene;
			class Layer3D;
			class SUPERMAP_API Layer3Ds
			{
			public:
				Layer3Ds();
				Layer3Ds(Scene* pScene);
				~Layer3Ds();
			private:
				//! \brief 场景对象
				Scene* m_pScene;

				//! \brief 图层列表
				TArray<Layer3D*> m_arrLayer3Ds;

				//! \brief 可见性
				Gamebool m_bIsVisible;

			public:
				//! \brief 清空图层
				Gamevoid Clear();

				//! \brief 获取图层个数
				Gameint Count();

				//! \brief 获取指定下标的图层
				Layer3D* GetAt(Gameint index);

				//! \brief 获取指定名称的图层
				Layer3D* GetAt(FName strLayerName);

				//! \brief 获取图层是否可见
				Gamebool GetIsVisible();

				//! \brief 设置图层是否可见
				Gamevoid SetIsVisible(Gamebool bVisible);

				//! \brief 添加图层
				Layer3D* Add(FString strDataName, Layer3DType eLayerType, Gamebool bAddToHead, FString strLayerName);

				//! \brief 添加iserver图层
				Layer3D* Add(FString strIserverUrl, Layer3DType eLayerType, FString strLayerName, Gamebool bAddToHead);

				//! \brief 添加OpenStreetMap、BingMaps等地图
				Layer3D* Add(FString strStdLayerName, FString strStdUserName, FString strStdPassWord, Layer3DType layerType);

				//! \brief 添加天地图
				Layer3D* Add(FString iserverURL, FString layerName, FString dataName, Gamefloat fDPI, ImageFormatType imageType, Gamebool addToHead);

				//! \brief 添加其他类型服务地图数据
				Layer3D* Add(FString strUrl, FString strLayerName, Layer3DType eLayerType, Gamebool bAddToHead);

				//! \brief 添加矢量数据集图层
				Layer3D* Add(FString strDataName,DatasetType eDatasetType);

				//! \brief 直接加载osgb格式倾斜
				//! \param strXMLFile [in], xml文件 
				//! \param strRootPath [in], osgb根结点目录
				//! \param strKeyWord [in], osgb关键字
				Layer3D* Add(FString strXMLFile, FString strRootPath, FString strName, FString strKeyWord = "");

				//! \brief 移除指定图层
				Gamebool Remove(FString layerName);

				//! \brief 根据图层名获取图层
				Layer3D* FindLayerByNodeName(Gamelong nNodeName);
			private:
				//! \brief 将图层插入到指定位置
				Gamevoid InternalInsert(Gameint index, Layer3D* pLayer);

				//! \breif 根据类型创建图层
				Layer3D* CreateLayer(FName strLayerName, Layer3DType layerType, Gamevoid* pUGLayer3D = nullptr);

				//! \breif 根据数据集类型创建图层
				Layer3D* CreateLayer(FName strLayerName, DatasetType datasetType);

				//! \brief 查找数据集图层
				Layer3D* FindLayer(FName strLayerName);

				//! \brief 判断是否包含某类型的图层
				Gameint IsContain(Layer3DType eLayerType);

				friend class Scene;
			};
		}
	}
}