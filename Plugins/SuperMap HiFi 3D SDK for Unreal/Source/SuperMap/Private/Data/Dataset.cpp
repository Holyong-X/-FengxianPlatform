#include "Data/Dataset.h"
#include "Data/GeoPoint3D.h"
#include "Data/GeoLine3D.h"
#include "Data/GeoRegion3D.h"

using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			Dataset::Dataset()
			{
				Core::RealspaceDLL::LoadAllAPI();
				m_pDataSource = nullptr;
				m_pUGDataset  = nullptr;
			}

			Dataset::Dataset(DataSource* pDataSource, void* pUGDataset)
			{
				Core::RealspaceDLL::LoadAllAPI();
			
				m_pDataSource = pDataSource;
				m_pUGDataset  = pUGDataset;

				if (Core::_GetDatasetName != nullptr && pUGDataset != nullptr)
				{
					char* cName = nullptr;
					Core::_GetDatasetName(pUGDataset, cName);
					m_strName = UTF8_TO_TCHAR(cName);
					Core::_FreeByte(cName);
				}
			}

			void* Dataset::Handler()
			{
				return m_pUGDataset;
			}

			FString Dataset::GetName()
			{
				return m_strName;
			}

			Dataset::~Dataset()
			{

			}

			DataSource* Dataset::GetDataSource()
			{
				return m_pDataSource;
			}

			Rectangle2D Dataset::GetBounds()
			{
				const TCHAR* cDataSetName = *m_strName;
				ANSICHAR* ccDataSetName = TCHAR_TO_UTF8(cDataSetName);

				float left, bottom, right, top;

				SuperMapSDK::UnrealEngine::Core::_Dataset_GetBounds(m_pUGDataset, left, bottom, right, top);

				Rectangle2D rect2D;

				rect2D.Left   = left;
				rect2D.Bottom = bottom;
				rect2D.Right  = right;
				rect2D.Top    = top;

				return rect2D;
			}

			DatasetType Dataset::GetType()
			{
				int nType;
				SuperMapSDK::UnrealEngine::Core::_Dataset_GetType(m_pUGDataset, nType);

				DatasetType eDatasetType = DT_UnKnown;
				if (nType == 1 || nType == 101)
				{
					eDatasetType = DT_POINT;
				}
				else if (nType == 3 || nType == 103)
				{
					eDatasetType = DT_LINE;
				}
				else if (nType == 5 || nType == 105)
				{
					eDatasetType = DT_REGION;
				}
				else if (nType == 203)
				{
					eDatasetType = DT_Model;
				}

				return eDatasetType;
			}

			TArray<Geometry*> Dataset::Query()
			{
				int32 nCount = 0;
				void*** pGeometry = nullptr;

				SuperMapSDK::UnrealEngine::Core::_Dataset_Query(m_pUGDataset, pGeometry, nCount);

				DatasetType eDatasetType = GetType();
				TArray<Geometry*> arrGeometrys;
				for (int32 n = 0; n < nCount; n++)
				{
					void* pGeo = (*pGeometry)[n];


					switch (eDatasetType)
					{
					case DT_POINT:
					{
						GeoPoint3D* pPoint3D = new GeoPoint3D(pGeo);
						arrGeometrys.Add(pPoint3D);
					}
					break;
					case DT_LINE:
					{
						GeoLine3D* pLine3D = new GeoLine3D(pGeo);
						arrGeometrys.Add(pLine3D);
					}
					break;
					case DT_REGION:
					{
						GeoRegion3D* pRegion3D = new GeoRegion3D(pGeo);
						arrGeometrys.Add(pRegion3D);
					}
					break;

					default:
						break;
					}

				}

				return arrGeometrys;
			}

			TArray<Geometry*> Dataset::QueryBySql(FString sql)
			{
				const TCHAR* cName = *m_strName;
				ANSICHAR* acName = TCHAR_TO_UTF8(cName);

				const TCHAR* cSql = *sql;
				ANSICHAR* acSql = TCHAR_TO_UTF8(cSql);

				int32 nCount = 0;
				void*** pUGGeometrys = nullptr;

				SuperMapSDK::UnrealEngine::Core::_Dataset_QueryBySql(m_pUGDataset, acSql, pUGGeometrys, nCount);

				DatasetType eDatasetType = GetType();
				TArray<Geometry*> arrGeometrys;
				for (int32 n = 0; n < nCount; n++)
				{
					void* pUGGeometry = (*pUGGeometrys)[n];
					Geometry* pGeometry = nullptr;

					switch (eDatasetType)
					{
					case DT_POINT:
					{
						pGeometry = new GeoPoint3D(pUGGeometry);
						break;
					}
					
					case DT_LINE:
					{
						pGeometry = new GeoLine3D(pUGGeometry);
						break;
					}
					
					case DT_REGION:
					{
						pGeometry = new GeoRegion3D(pUGGeometry);
						break;
					}
					
					default:
						break;
					}
					arrGeometrys.Add(pGeometry);
				}

				return arrGeometrys;
			}


			void Dataset::GetFieldInfos(TArray<FieldInfo>& arrFieldInfo)
			{
				int32 nCount = 0;
				char*** pArrFieldNames = nullptr;
				int32** pArrTypes = nullptr;
				
				SuperMapSDK::UnrealEngine::Core::_Dataset_GetFieldInfos(m_pUGDataset, pArrFieldNames, pArrTypes, nCount);

				for (int32 n = 0; n < nCount; n++)
				{
					FString name = UTF8_TO_TCHAR((*pArrFieldNames)[n]);
					
					FieldInfo info;
					info.m_strName = name;
					info.m_eType = (FieldType)(*pArrTypes)[n];

					arrFieldInfo.Add(info);
				}

				//释放中间层new的
				SuperMapSDK::UnrealEngine::Core::_ReleaseCharArray(pArrFieldNames, nCount);
				SuperMapSDK::UnrealEngine::Core::_ReleaseIntArray(pArrTypes);
			}

			TArray<FString> Dataset::QueryField(FString strFieldName)
			{
				const TCHAR* cFieldName = *strFieldName;
				ANSICHAR* acFieldName = TCHAR_TO_UTF8(cFieldName);

				int32 nCount = 0;
				char*** pArrFieldValues = nullptr;

				SuperMapSDK::UnrealEngine::Core::_Dataset_QueryField(m_pUGDataset, acFieldName, pArrFieldValues, nCount);

				TArray<FString> arrValues;
				for (int32 n = 0; n < nCount; n++)
				{
					FString name = UTF8_TO_TCHAR((*pArrFieldValues)[n]);
					arrValues.Add(name);
				}
				if (nCount > 0)
				{
					//释放中间层new的
					SuperMapSDK::UnrealEngine::Core::_ReleaseCharArray(pArrFieldValues, nCount);
				}
				return arrValues;
			}

			TArray<FString> Dataset::QueryAttributeById(int32 nID)
			{
				const TCHAR* cName = *m_strName;
				ANSICHAR* acName = TCHAR_TO_UTF8(cName);

				
				int32 nCount = 0;
				char*** pArrFieldValues = nullptr;

				SuperMapSDK::UnrealEngine::Core::_Dataset_QueryAttributeById(m_pUGDataset, nID, pArrFieldValues, nCount);

				TArray<FString> arrValues;
				if (pArrFieldValues == nullptr)
				{
					return arrValues;
				}

				for (int32 n = 0; n < nCount; n++)
				{
					FString name = UTF8_TO_TCHAR((*pArrFieldValues)[n]);
					arrValues.Add(name);
				}

				//释放中间层new的
				SuperMapSDK::UnrealEngine::Core::_ReleaseCharArray(pArrFieldValues, nCount);

				return arrValues;
			}
		
		}
	}
}