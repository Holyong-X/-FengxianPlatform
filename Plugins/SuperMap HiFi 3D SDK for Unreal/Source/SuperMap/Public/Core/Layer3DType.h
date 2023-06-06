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

			// OSGB����
			enum SUPERMAP_API OSGBType
			{
				ObliquePhotogrammetry3DModel = 0,		//��б��Ӱģ��
				NormalCacheFile = 1,				//��ͨOSGB����
				Volume = 2,					//������
				IconPoint = 3,					//��ͼ������
				ClampGroundLine = 4,		//������ʸ��
				ClampObjectLine = 5,		//��������ʸ��
				ClampGroundRegion = 6,	//������ʸ��
				ClampObjectRegion = 7,	//��������ʸ��
				ExtendClampRegoin = 8,	//������߶ȵ����������ʸ��
				Terrain = 9,						//����
				Text = 10,								//����
				PointCloud = 11,					//����
				PolylineEffect = 13,				// ���ͷ���
				RegionEffect = 14,					// �����
				RealtimeRaster = 16,	//������ʸ������
			};
		}
	}
}