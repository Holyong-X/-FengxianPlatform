#include "Core/TrackingLayer.h"
#include "Data/GeoPoint3D.h"
#include "Data/GeoLine3D.h"
#include "Data/GeoModel3D.h"

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Core
		{
			TrackingLayer::TrackingLayer()
			{
				_TrackingLayer3D_GetLayerPtr(m_pUGLayer3D);
			}

			TrackingLayer::~TrackingLayer()
			{
				m_pUGLayer3D = nullptr;
			}

			int32 TrackingLayer::AddGeometry(Geometry* pGeometry, FString strTag)
			{
				if (pGeometry == nullptr)
				{
					return -1;
				}
				const TCHAR* c = *strTag;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);
				void* pRenderFeature = nullptr;
				int32 nIndex = _TrackingLayer3D_Add(pGeometry->GetHandler(), cc, pRenderFeature);

				pGeometry->SetRenderFeature(pRenderFeature);

				return nIndex;
			}

			bool TrackingLayer::Remove(int32 nIndex)
			{
				bool bSuccess = _TrackingLayer3D_Remove(nIndex);
				return bSuccess;
			}

			Geometry* TrackingLayer::TrackingLayer::Get(int32 nIndex)
			{
				void* pUGGeometry = nullptr;
				_TrackingLayer3D_Get(nIndex, pUGGeometry);

				if (pUGGeometry != nullptr)
				{
					int32 nGeoType = _Geometry_GetType(pUGGeometry);
					Geometry* pResult = nullptr;
					switch (nGeoType)
					{
					case GeometryType::GT_GeoLine3D:
						pResult = new GeoLine3D(pUGGeometry);
						break;
					case GeometryType::GT_GeoModel3D:
						pResult = new GeoModel3D(pUGGeometry);
						break;
					case GeometryType::GT_GeoPoint:
						//result = new GeoPoint(ref pGeometry);
						break;
					case GeometryType::GT_GeoPoint3D:
						pResult = new GeoPoint3D(pUGGeometry);
						break;
					case GeometryType::GT_GeoRegion3D:
						//result = new GeoRegion3D(ref pGeometry);
						break;
					default:
						break;
					}
					return pResult;
				}

				return nullptr;
			}

			FString TrackingLayer::GetTag(int32 nIndex)
			{
				char* tag = _TrackingLayer3D_GetTag(nIndex);
				FName strName(tag);
				_FreeByte(tag);
				return strName.ToString();
			}

			void TrackingLayer::Clear()
			{
				_TrackingLayer3D_Clear();
			}

			int32 TrackingLayer::IndexOf(FString strTag)
			{
				const TCHAR* c = *strTag;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);

				int32 nIndex = _TrackingLayer3D_IndexOf(cc);
				return nIndex;
			}

			int32 TrackingLayer::GetCount()
			{
				int32 nCount = _TrackingLayer3D_GetCount();
				return nCount;
			}

			void TrackingLayer::AddNativeGameComponent(GameComponent* pGameComponent)
			{
				m_mapNativeGameComponent.Add(pGameComponent->GetNodeName(), pGameComponent);
				UpdateShaderForOneNativeGameComponent(pGameComponent);
			}

			void TrackingLayer::RemoveNativeGameComponent(GameComponent* pGameComponent)
			{
				m_mapNativeGameComponent.Remove(pGameComponent->GetNodeName());
			}

			void TrackingLayer::UpdateShaderForOneNativeGameComponent(GameComponent* pGameComponent)
			{
				TArray<GameMaterial*>& listGameMaterial = pGameComponent->GetAllGameMaterial();
				for (Gameint i = 0; i < listGameMaterial.Num(); i++)
				{
					GameMaterial* pGameMaterial = listGameMaterial[i];
					if (pGameMaterial == nullptr)
					{
						continue;
					}
					// 更新图层需要替换的材质
					UpdateMaterialInfo(pGameMaterial);
				}
			}

			void TrackingLayer::UpdateMaterialInfo(GameMaterial* pGameMaterial)
			{
				FString strNewMaterialPath = "";
				FString strMaterialOriginName = pGameMaterial->GetMaterialOrginName();
				Gamebool isFind = (m_ObjectMaterialInfo.m_mapMaterialNameChanges.Find(strMaterialOriginName) != nullptr);
				if (!m_MaterialInfo.m_strMaterialName.IsEmpty())
				{
					strNewMaterialPath = m_MaterialInfo.m_strMaterialName;
				}
				else if (isFind)
				{
					strNewMaterialPath = m_ObjectMaterialInfo.m_mapMaterialNameChanges[strMaterialOriginName].AssociateMaterialPath;
				}
				if (strNewMaterialPath != "")
				{
					UMaterialInterface* pMaterialInterface = LoadObject<UMaterialInterface>(nullptr, *strNewMaterialPath);
					UMaterialInstanceDynamic* pNewMID = UMaterialInstanceDynamic::Create(pMaterialInterface, nullptr);
					pNewMID->AddToRoot();
					pGameMaterial->SetMID(pNewMID);
				}
			}
		}
	}
}