#pragma once


namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			enum SUPERMAP_API Layer3DType
			{
				ImageFile          = 1,
				KML                = 2,
				Map				   = 9,
				WMS				   = 11,
				WMTS			   = 12,
				DatasetVector	   = 14,
				S3M                = 15,
				DatasetModel	   = 16,
				BingMaps           = 22,
				OpenStreetMaps     = 24,
				DatasetVectorPoint = 26,
				ArcgisMaps         = 34,
			};

			enum SUPERMAP_API ImageFormatType
			{
				none = 0,
				BMP = 121,
				JPG = 122,
				JPG_PNG = 147,
			};

			enum SUPERMAP_API TerrainLayerType
			{
				STK = 2,
				TIANDITU = 3,
			};

			// OSGB类型
			enum SUPERMAP_API OSGBType
			{
				ObliquePhotogrammetry3DModel = 0,		//倾斜摄影模型
				NormalCacheFile = 1,				//普通OSGB缓存
				Volume = 2,					//体数据
				IconPoint = 3,					//点图标类型
				ClampGroundLine = 4,		//贴地线矢量
				ClampObjectLine = 5,		//贴对象线矢量
				ClampGroundRegion = 6,	//贴地面矢量
				ClampObjectRegion = 7,	//贴对象面矢量
				ExtendClampRegoin = 8,	//带拉伸高度的贴对象的面矢量
				Terrain = 9,						//地形
				Text = 10,								//文字
				PointCloud = 11,					//点云
				PolylineEffect = 13,				// 线型符号
				RegionEffect = 14,					// 面填充
				RealtimeRaster = 16,	//贴地面矢量缓存
			};
		}
	}
}