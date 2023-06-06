#pragma once

#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Data/GeoRegion3D.h"
#include "Data/Vector3d.h"
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			typedef void(*DataServiceRequestSelectEvent)(void* pActor);
			struct SUPERMAP_API DataServiceRequestCallBack
			{
			public:
				void* m_pActor;
				//触发事件
				DataServiceRequestSelectEvent Event;
			public:
				DataServiceRequestCallBack()
				{
					m_pActor = nullptr;
				}
				void Execute()
				{
					if (m_pActor == nullptr)
					{
						return;
					}
					Event(m_pActor);
				}
			};
			class SUPERMAP_API DataServiceRequest
			{
			public:
				DataServiceRequest();
				~DataServiceRequest();
			public:
				//! \brief 构建倾斜单体
				void SelecteServiceRequest(Vector3d vMouse);

				//! \brief 获取对应矢量面
				GeoRegion3D* GetGeoRegion3D();

				//! \brief 获取倾斜单体数据
				TMap<FString, FString> GetSelectAttribute();

				//! \brief 设置倾斜对应矢量面数据
				void SetIServiceData(FString strUrlServer, FString strDataSourceName, FString strDatasetName);

				//! \brief 设置获取底部高程的字段名
				void SetBottomAltitudeFiledName(FString strBottomAltitude);

				//! \brief 设置获取高度值的字段名
				void SetExtendHeightFiledName(FString strExtendHeight);

				void CallFunc_DataServiceRequest(void* pActor, DataServiceRequestSelectEvent QAEvent);
			private:
				FString ToJson(Gamedouble lon, Gamedouble lat);

				void PostJson(FString postJson);

				void RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);

				void GetRegion(TSharedPtr<FJsonObject> jsonObject);

				void GetAttributes(TSharedPtr<FJsonObject> jsonObject);

				void Release();
			private:
				//网址
				FString m_strDataServer;

				FString m_strDataSourceName;

				FString m_strDatasetName;

				//底部高程
				FString m_strBottomAltitude;

				//高度
				FString m_strExtendHeight;

				GeoRegion3D* m_pGeoRegion3D;

				TMap<FString, FString> m_mapAttributes;

				DataServiceRequestCallBack m_DataServiceRequestEvent;
			};
		}
	}
}