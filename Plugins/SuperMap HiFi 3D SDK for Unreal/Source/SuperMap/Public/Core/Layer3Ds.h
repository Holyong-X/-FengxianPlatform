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
				//! \brief ��������
				Scene* m_pScene;

				//! \brief ͼ���б�
				TArray<Layer3D*> m_arrLayer3Ds;

				//! \brief �ɼ���
				Gamebool m_bIsVisible;

			public:
				//! \brief ���ͼ��
				Gamevoid Clear();

				//! \brief ��ȡͼ�����
				Gameint Count();

				//! \brief ��ȡָ���±��ͼ��
				Layer3D* GetAt(Gameint index);

				//! \brief ��ȡָ�����Ƶ�ͼ��
				Layer3D* GetAt(FName strLayerName);

				//! \brief ��ȡͼ���Ƿ�ɼ�
				Gamebool GetIsVisible();

				//! \brief ����ͼ���Ƿ�ɼ�
				Gamevoid SetIsVisible(Gamebool bVisible);

				//! \brief ���ͼ��
				Layer3D* Add(FString strDataName, Layer3DType eLayerType, Gamebool bAddToHead, FString strLayerName);

				//! \brief ���iserverͼ��
				Layer3D* Add(FString strIserverUrl, Layer3DType eLayerType, FString strLayerName, Gamebool bAddToHead);

				//! \brief ���OpenStreetMap��BingMaps�ȵ�ͼ
				Layer3D* Add(FString strStdLayerName, FString strStdUserName, FString strStdPassWord, Layer3DType layerType);

				//! \brief ������ͼ
				Layer3D* Add(FString iserverURL, FString layerName, FString dataName, Gamefloat fDPI, ImageFormatType imageType, Gamebool addToHead);

				//! \brief ����������ͷ����ͼ����
				Layer3D* Add(FString strUrl, FString strLayerName, Layer3DType eLayerType, Gamebool bAddToHead);

				//! \brief ���ʸ�����ݼ�ͼ��
				Layer3D* Add(FString strDataName,DatasetType eDatasetType);

				//! \brief ֱ�Ӽ���osgb��ʽ��б
				//! \param strXMLFile [in], xml�ļ� 
				//! \param strRootPath [in], osgb�����Ŀ¼
				//! \param strKeyWord [in], osgb�ؼ���
				Layer3D* Add(FString strXMLFile, FString strRootPath, FString strName, FString strKeyWord = "");

				//! \brief �Ƴ�ָ��ͼ��
				Gamebool Remove(FString layerName);

				//! \brief ����ͼ������ȡͼ��
				Layer3D* FindLayerByNodeName(Gamelong nNodeName);
			private:
				//! \brief ��ͼ����뵽ָ��λ��
				Gamevoid InternalInsert(Gameint index, Layer3D* pLayer);

				//! \breif �������ʹ���ͼ��
				Layer3D* CreateLayer(FName strLayerName, Layer3DType layerType, Gamevoid* pUGLayer3D = nullptr);

				//! \breif �������ݼ����ʹ���ͼ��
				Layer3D* CreateLayer(FName strLayerName, DatasetType datasetType);

				//! \brief �������ݼ�ͼ��
				Layer3D* FindLayer(FName strLayerName);

				//! \brief �ж��Ƿ����ĳ���͵�ͼ��
				Gameint IsContain(Layer3DType eLayerType);

				friend class Scene;
			};
		}
	}
}