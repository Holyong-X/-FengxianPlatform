#include "Core/Layer3Ds.h"
#include "Core/Layer3DS3MFile.h"
#include "Core/Layer3DImageFile.h"
#include "Core/Layer3DServeiceMaps.h"
#include "Core/Public/Misc/Paths.h"
#include "Core/Layer3DDatasetModel.h"
#include "Core/Layer3DDatasetVectorPoint.h"
#include "Core/Layer3DDatasetVectorLine.h"
#include "Core/Layer3DDatasetVectorRegion.h"
#include "Core/Layer3DKML.h"
#include "Algorithm3D/MathEngine.h"
#include "Core/Scene.h"

#if PLATFORM_LINUX
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::Algorithm3D;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			Layer3Ds::Layer3Ds()
			{
				m_pScene = nullptr;
			}
			Layer3Ds::Layer3Ds(Scene* pScene)
			{
				m_pScene = pScene;
			}

			Gamevoid Layer3Ds::Clear()
			{
				for (Gameint i = 0; i < m_arrLayer3Ds.Num();)
				{
					Layer3D* pLayer3D = m_arrLayer3Ds[i];
					if (pLayer3D)
					{
						delete pLayer3D;
						pLayer3D = nullptr;
					}
					m_arrLayer3Ds.RemoveAt(i);
				}
			}

			Layer3Ds::~Layer3Ds()
			{
				m_pScene = nullptr;
				Clear();
			}

			Gameint Layer3Ds::Count()
			{
				return m_arrLayer3Ds.Num();
			}

			Layer3D* Layer3Ds::GetAt(Gameint index)
			{
				if (index >= m_arrLayer3Ds.Num())
				{
					return nullptr;
				}
				return m_arrLayer3Ds[index];
			}

			Layer3D* Layer3Ds::GetAt(FName strLayerName)
			{
				return FindLayer(strLayerName);
			}

			Gamebool Layer3Ds::GetIsVisible()
			{
				m_bIsVisible = _GetIsVisible();
				return m_bIsVisible;
			}

			Gamevoid Layer3Ds::SetIsVisible(Gamebool bVisible)
			{
				m_bIsVisible = bVisible;
				_SetIsVisible(bVisible);

				for (Gameint i = 0; i < m_arrLayer3Ds.Num(); i++)
				{
					m_arrLayer3Ds[i]->SetIsVisible(bVisible);
				}
			}

			Layer3D* Layer3Ds::Add(FString strDataName, Layer3DType eLayerType, Gamebool bAddToHead, FString strLayerName)
			{
				const TCHAR* cLName = *strLayerName;
				ANSICHAR* ccLName = TCHAR_TO_UTF8(cLName);

				ANSICHAR* cc = nullptr;
				MathEngine::FStringToANSIChar(strDataName, cc);
				
				Layer3D* pLayer3D;
				Gameint nLayerID;
				Gamevoid * pUGCLayer3D = nullptr;

				if (eLayerType == Layer3DType::DatasetModel)
				{
					nLayerID = _AddDatasetModel(pUGCLayer3D, cc, ccLName);

					// 获取图层名
					FName strName(*strDataName);
					pLayer3D = CreateLayer(strName, Layer3DType::DatasetModel, pUGCLayer3D);
				}
				else
				{
					Gameint type = (Gameint)eLayerType;
					nLayerID = _AddLayer(pUGCLayer3D, cc, type, bAddToHead, ccLName);

					// 获取图层名
					FName strName(*strLayerName);
					pLayer3D = CreateLayer(strName, eLayerType, pUGCLayer3D);
				}

				pLayer3D->SetLayerID(nLayerID);
				InternalInsert(m_arrLayer3Ds.Num(), pLayer3D);

				if (cc != nullptr)
				{
					delete cc;
					cc = nullptr;
				}

				return pLayer3D;
			}

			Layer3D* Layer3Ds::Add(FString strXMLFile, FString strRootPath, FString strName, FString strKeyWord)
			{
				const TCHAR* cXMLFile = *strXMLFile;
				ANSICHAR* ccXMLFile = TCHAR_TO_UTF8(cXMLFile);
				const TCHAR* cRootPath = *strRootPath;
				ANSICHAR* ccRootPath = TCHAR_TO_UTF8(cRootPath);
				const TCHAR* cName = *strName;
				ANSICHAR* ccName = TCHAR_TO_UTF8(cName);
				const TCHAR* cKeyWord = *strKeyWord;
				ANSICHAR* ccKeyWord = TCHAR_TO_UTF8(cKeyWord);

				Gamevoid* pUGCLayer3D = nullptr;
				Gameint	nLayerID = _AddOSGBLayer(pUGCLayer3D, ccXMLFile, ccRootPath, ccName, ccKeyWord);
				FName name(cName);

				Layer3D* pLayer3D = CreateLayer(name, Layer3DType::S3M, pUGCLayer3D);
				pLayer3D->SetLayerID(nLayerID);
				InternalInsert(m_arrLayer3Ds.Num(), pLayer3D);
				return pLayer3D;
			}

			Layer3D* Layer3Ds::Add(FString strDataName, DatasetType eDatasetType)
			{
				Layer3D* pLayer3D = nullptr;
				FName strName(*strDataName);
				pLayer3D = CreateLayer(strName, eDatasetType);
				pLayer3D->SetLayerID(-1);
				InternalInsert(m_arrLayer3Ds.Num(), pLayer3D);
				return pLayer3D;
			}

			Layer3D* Layer3Ds::Add(FString strIserverUrl, Layer3DType eLayerType, FString strLayerName, Gamebool bAddToHead)
			{
				FString strDataName = FPaths::GetBaseFilename(strIserverUrl);
				FString strUrlPath = FPaths::GetPath(strIserverUrl);
				Gameint type = (Gameint)eLayerType;
				const TCHAR* cUrl = *strUrlPath;
				ANSICHAR* ccUrl = TCHAR_TO_UTF8(cUrl);
				const TCHAR* cLayerName = *strLayerName;
				ANSICHAR* ccLayerName = TCHAR_TO_UTF8(cLayerName);
				const TCHAR* cDataName = *strDataName;
				ANSICHAR* ccDataName = TCHAR_TO_UTF8(cDataName);

				Gamevoid* pUGCLayer3D = nullptr;
				Gameint	nLayerID = _Add(pUGCLayer3D, ccUrl, type, ccLayerName, ccDataName, bAddToHead);

				// 获取图层名
				FName strName(cLayerName);

				Layer3D* pLayer3D = CreateLayer(strName, eLayerType, pUGCLayer3D);
				pLayer3D->SetLayerID(nLayerID);
				InternalInsert(m_arrLayer3Ds.Num(), pLayer3D);

				return pLayer3D;
			}

			Layer3D* Layer3Ds::Add(FString strStdLayerName, FString strStdUserName, FString strStdPassWord, Layer3DType layerType)
			{
				Gameint type = (Gameint)layerType;
				const TCHAR* cLayerName = *strStdLayerName;
				ANSICHAR* ccLayerName = TCHAR_TO_UTF8(cLayerName);

				const TCHAR* cStdUserName = *strStdUserName;
				ANSICHAR* ccStdUserName = TCHAR_TO_UTF8(cStdUserName);

				const TCHAR* cPassWord = *strStdPassWord;
				ANSICHAR* ccPassWord = TCHAR_TO_UTF8(cPassWord);

				Gamevoid* pUGCLayer3D = nullptr;
				Gameint nLayerID = _AddOnlineMap(pUGCLayer3D, ccLayerName, type, ccStdUserName, ccPassWord);

				FName strName(cLayerName);
				Layer3D* pLayer3D = CreateLayer(strName, layerType, pUGCLayer3D);
				pLayer3D->SetLayerID(nLayerID);
				InternalInsert(m_arrLayer3Ds.Num(), pLayer3D);
				return pLayer3D;
			}

			Layer3D* Layer3Ds::Add(FString strURL, FString strLayerName, FString strDataName, Gamefloat fDPI, ImageFormatType eImageType, Gamebool bAddToHead)
			{
				const TCHAR* cstrURL = *strURL;
				ANSICHAR* ccstrURL = TCHAR_TO_UTF8(cstrURL);

				const TCHAR* clayerName = *strLayerName;
				ANSICHAR* cclayerName = TCHAR_TO_UTF8(clayerName);

				const TCHAR* cstrDataName = *strDataName;
				ANSICHAR* ccstrDataName = TCHAR_TO_UTF8(cstrDataName);

				Gamevoid* pUGCLayer3D = nullptr;
				Gameint nLayerID = _AddTianditu(pUGCLayer3D , ccstrURL, cclayerName, ccstrDataName, fDPI, eImageType, bAddToHead);
				FName strName(clayerName);
				Layer3D* pLayer3D = CreateLayer(strName, Layer3DType::ImageFile, pUGCLayer3D);
				pLayer3D->SetLayerID(nLayerID);
				InternalInsert(m_arrLayer3Ds.Num(), pLayer3D);
				return pLayer3D;
			}

			Layer3D* Layer3Ds::Add(FString strUrl, FString strLayerName, Layer3DType eLayerType, Gamebool bAddToHead)
			{
				Gameint type = (Gameint)eLayerType;
				const TCHAR* cUrl = *strUrl;
				ANSICHAR* ccUrl = TCHAR_TO_UTF8(cUrl);
				//_AddLayer(cc, type, bAddToHead);

				const TCHAR* cLayerName = *strLayerName;
				ANSICHAR* ccLayerName = TCHAR_TO_UTF8(cLayerName);
				Gamevoid* pUGCLayer3D = nullptr;
				Gameint nLayerID = _AddArcgisMap(pUGCLayer3D , ccUrl, ccLayerName);

				// 获取图层名
				FName strName(cLayerName);

				Layer3D* pLayer3D = CreateLayer(strName, eLayerType, pUGCLayer3D);
				pLayer3D->SetLayerID(nLayerID);
				InternalInsert(m_arrLayer3Ds.Num(), pLayer3D);

				return pLayer3D;
			}

			Layer3D* Layer3Ds::FindLayer(FName strLayerName)
			{
				for (Layer3D* pLayer3D : m_arrLayer3Ds)
				{
					if (pLayer3D != NULL)
					{
						FName strName = pLayer3D->Name();
						if (strName == strLayerName)
						{
							return pLayer3D;
						}
					}
				}

				return nullptr;
			}

			Gamevoid Layer3Ds::InternalInsert(Gameint index, Layer3D* pLayer)
			{
				if (index >= m_arrLayer3Ds.Num())
				{
					m_arrLayer3Ds.Add(pLayer);
				}
				else
				{
					m_arrLayer3Ds.Insert(pLayer, index);
				}
			}

			Layer3D* Layer3Ds::CreateLayer(FName strLayerName, Layer3DType layerType, Gamevoid* pUGLayer3D)
			{
				switch (layerType)
				{
				case Layer3DType::KML:
				{
					Layer3DKML* pKMLLayer = new Layer3DKML(pUGLayer3D, strLayerName, layerType);
					return pKMLLayer;
				}
				case Layer3DType::S3M:
				{
					Layer3DS3MFile* layer = new Layer3DS3MFile(pUGLayer3D, strLayerName, layerType);
					return layer;
				}
				case Layer3DType::ImageFile:
				{
					Layer3DImageFile* layerImage = new Layer3DImageFile(pUGLayer3D, strLayerName, layerType);
					m_pScene->SetShowInvalidation(true);
					return layerImage;
				}
				case Layer3DType::BingMaps:
				case Layer3DType::OpenStreetMaps:
				case Layer3DType::ArcgisMaps:
				case Layer3DType::WMS:
				case Layer3DType::WMTS:
				case Layer3DType::Map:
				{
					Layer3DServeiceMaps* layerServeice = new Layer3DServeiceMaps(pUGLayer3D, strLayerName, layerType);
					return layerServeice;
				}
				case Layer3DType::DatasetModel:
				{
					Layer3DDatasetModel * layerDatasetModel = new Layer3DDatasetModel(pUGLayer3D, strLayerName, layerType);
					return layerDatasetModel;
				}
				default:
					break;
				}
				return nullptr;
			}

			Layer3D* Layer3Ds::CreateLayer(FName strLayerName, DatasetType datasetType)
			{
				switch (datasetType)
				{
				case DatasetType::DT_POINT:
				{
					Layer3DDatasetVectorPoint * layerVectorPoint = new Layer3DDatasetVectorPoint(strLayerName, Layer3DType::DatasetVector);
					return layerVectorPoint;
				}
				case DatasetType::DT_LINE:
				{
					Layer3DDatasetVectorLine * layerVectorLine = new Layer3DDatasetVectorLine(strLayerName, Layer3DType::DatasetVector);
					return layerVectorLine;
				}
				case DatasetType::DT_REGION:
				{
					Layer3DDatasetVectorRegion * layerVectorRegion = new Layer3DDatasetVectorRegion(strLayerName, Layer3DType::DatasetVector);
					return layerVectorRegion;
				}
				default:
					break;
				}
				return nullptr;
			}

			Gameint Layer3Ds::IsContain(Layer3DType eLayerType)
			{
				Gameint nSize = m_arrLayer3Ds.Num();
				for (Gameint i = 0; i < nSize; i++)
				{
					Layer3D* pLayer3D = m_arrLayer3Ds[i];
					if (pLayer3D->Type() == eLayerType)
					{
						return i;
					}
				}
				return -1;
			}

			Gamebool Layer3Ds::Remove(FString layerName)
			{
				FName nlayerName = FName(layerName);
				for (Gameint i = 0; i < m_arrLayer3Ds.Num(); i++)
				{
					if (m_arrLayer3Ds[i]->Name() == nlayerName)
					{
						delete m_arrLayer3Ds[i];
						m_arrLayer3Ds[i] = nullptr;
						m_arrLayer3Ds.RemoveAt(i);
						break;
					}
				}
				const TCHAR* cLayerName = *layerName;
				ANSICHAR* ccLayerName = TCHAR_TO_UTF8(cLayerName);
				return _RemoveLayers(ccLayerName);
			}

			Layer3D* Layer3Ds::FindLayerByNodeName(Gamelong nNodeName)
			{
				// TODO 优化性能
				for (Gameint i = 0; i < m_arrLayer3Ds.Num(); i++)
				{
					if (m_arrLayer3Ds[i]->NodeNameHashCode() == nNodeName)
					{
						return m_arrLayer3Ds[i];
					}
				}
				return nullptr;
			}
		}
	}
}
#if PLATFORM_LINUX
PRAGMA_DISABLE_OPTIMIZATION
#endif