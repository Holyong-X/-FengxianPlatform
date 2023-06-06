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
				//�����¼�
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
				//! \brief ������б����
				void SelecteServiceRequest(Vector3d vMouse);

				//! \brief ��ȡ��Ӧʸ����
				GeoRegion3D* GetGeoRegion3D();

				//! \brief ��ȡ��б��������
				TMap<FString, FString> GetSelectAttribute();

				//! \brief ������б��Ӧʸ��������
				void SetIServiceData(FString strUrlServer, FString strDataSourceName, FString strDatasetName);

				//! \brief ���û�ȡ�ײ��̵߳��ֶ���
				void SetBottomAltitudeFiledName(FString strBottomAltitude);

				//! \brief ���û�ȡ�߶�ֵ���ֶ���
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
				//��ַ
				FString m_strDataServer;

				FString m_strDataSourceName;

				FString m_strDatasetName;

				//�ײ��߳�
				FString m_strBottomAltitude;

				//�߶�
				FString m_strExtendHeight;

				GeoRegion3D* m_pGeoRegion3D;

				TMap<FString, FString> m_mapAttributes;

				DataServiceRequestCallBack m_DataServiceRequestEvent;
			};
		}
	}
}