
#include "Data/DataServiceRequest.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Serialization/JsonWriter.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "Core/Scene.h"
#include "ControlUE/RealspaceView.h"
#include "Core/Style3D.h"
#include "Core/TrackingLayer.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
using namespace SuperMapSDK::UnrealEngine::ControlUE;
using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Data
		{
			DataServiceRequest::DataServiceRequest()
			{
				m_strDataServer = "";

				m_strDataSourceName = "";

				m_strDatasetName = "";

				m_strBottomAltitude = "";

				m_strExtendHeight = "";

				m_pGeoRegion3D = new GeoRegion3D();
			}
			DataServiceRequest::~DataServiceRequest()
			{
				if (m_pGeoRegion3D != nullptr)
				{
					delete m_pGeoRegion3D;
					m_pGeoRegion3D = nullptr;
				}
			}

			void DataServiceRequest::SetIServiceData(FString strUrlServer, FString strDataSourceName, FString strDatasetName)
			{
				m_strDataServer = strUrlServer;

				m_strDataSourceName = strDataSourceName;

				m_strDatasetName = strDatasetName;
			}

			void DataServiceRequest::SetBottomAltitudeFiledName(FString strBottomAltitude)
			{
				m_strBottomAltitude = strBottomAltitude;
			}

			void DataServiceRequest::SetExtendHeightFiledName(FString strExtendHeight)
			{
				m_strExtendHeight = strExtendHeight;
			}

			void DataServiceRequest::SelecteServiceRequest(Vector3d vMouse)
			{
				if (m_strDataServer == "" || m_strDataSourceName == "" || m_strDatasetName == "")
				{
					return;
				}
				Vector3d vPos = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->PixelToGlobe(vMouse);
				if (CameraControl::m_eSceneType == UGC_PLANE)
				{
					vPos.X *= CM_TO_M;
					vPos.Y *= CM_TO_M;
					vPos.Z *= CM_TO_M;
				}
				FString json = ToJson(vPos.X, vPos.Y);
				Release();
				PostJson(json);
			}

			FString DataServiceRequest::ToJson(Gamedouble lon, Gamedouble lat)
			{
				FString dataName = m_strDataSourceName + ":" + m_strDatasetName;
				FString Lon = FString::Printf(TEXT("%.8f"), lon);
				FString Lat = FString::Printf(TEXT("%.8f"), lat);
				FString json = "{\"getFeatureMode\":\"SPATIAL\",\"spatialQueryMode\":\"INTERSECT\",\"datasetNames\":[\"" + dataName + "\"],\"geometry\":{\"id\":0,\"parts\":[1],\"points\":[{\"x\": "
					+ Lon + ",\"y\":" + Lat + "}],\"type\":\"POINT\"}}";
				return json;
			}

			void DataServiceRequest::PostJson(FString postJson)
			{
				FString server_data = postJson;
				// 创建Http 请求
#if SM_FOR_UE_25
				TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
#else
				TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
#endif
				// 设置请求头
				Request->SetHeader("Content-Type", "application/json");
				// 设置请求方式
				Request->SetVerb("POST");
				// 请求的链接
				Request->SetURL(m_strDataServer);
				// 内容包
				Request->SetContentAsString(server_data);
				// 设置回调函数
				Request->OnProcessRequestComplete().BindRaw(this, &DataServiceRequest::RequestComplete);
				// 发送请求
				Request->ProcessRequest();
			}

			void DataServiceRequest::RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
			{
				if (!EHttpResponseCodes::IsOk(ResponsePtr->GetResponseCode()))
				{
					return;
				}
				// 获得返回的json数据
				TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponsePtr->GetContentAsString());
				// 把FString转成TCHAR
				TCHAR* serializedChar = ResponsePtr->GetContentAsString().GetCharArray().GetData();
				// 解决中文乱码问题，服务端也是utf-8
				TCHAR_TO_UTF8(serializedChar);
				FString myData(serializedChar);
				// 创建Json对象
				TSharedPtr<FJsonObject> JsonObject;
				// 反序列化json
				bool bIsOk = FJsonSerializer::Deserialize(JsonReader, JsonObject);
				// 判断是否反序列化成功
				if (bIsOk)
				{
					GetRegion(JsonObject);
					GetAttributes(JsonObject);
					if (m_pGeoRegion3D->GetPointCount() > 0 && !m_strBottomAltitude.IsEmpty() && !m_strExtendHeight.IsEmpty())
					{
						FString strBottomAltitude = m_mapAttributes[m_strBottomAltitude];
						FString strExtendHeight = m_mapAttributes[m_strExtendHeight];

						const TCHAR* cBottomAltitude = *strBottomAltitude;
						ANSICHAR* ccBottomAltitude = TCHAR_TO_UTF8(cBottomAltitude);
						Gamedouble dBottomAltitude = atof(ccBottomAltitude);

						const TCHAR* cExtendHeight = *strExtendHeight;
						ANSICHAR* ccExtendHeight = TCHAR_TO_UTF8(cExtendHeight);
						Gamedouble dExtendHeight = atof(ccExtendHeight);

						Style3D* pStyle3D = new Style3D();
						pStyle3D->SetAltitudeMode(AltitudeMode::Absolute);
						pStyle3D->SetBottomAltitude(dBottomAltitude);
						pStyle3D->SetExtendHeight(dExtendHeight);
						m_pGeoRegion3D->SetStyle3D(pStyle3D);
						RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->AddGeometry(m_pGeoRegion3D, "SelectionModel");
					}
				}
			}

			void DataServiceRequest::GetRegion(TSharedPtr<FJsonObject> jsonObject)
			{
				TArray<Vector3d> pts;
				TArray<TSharedPtr<FJsonValue>> features = jsonObject->GetArrayField("features");
				if (features.Num() > 0)
				{
					TSharedPtr<FJsonObject> feature = features[0]->AsObject();
					TSharedPtr<FJsonObject> geometry = feature->GetObjectField("geometry");
					TArray<TSharedPtr<FJsonValue>> points = geometry->GetArrayField("points");
					for (int i = 0; i < points.Num(); i++)
					{
						FVector vPosition = FVector(0,0,0);
						if (CameraControl::m_eSceneType == UGC_PLANE)
						{
							vPosition = RealspaceView::GetSingleton()->GetSceneControl()->GetTerrainPosition();
						}
						TSharedPtr<FJsonObject> point = points[i]->AsObject();
						Gamedouble x = point->GetNumberField("x") - vPosition.X;
						Gamedouble y = point->GetNumberField("y") - vPosition.Y;
						pts.Add(Vector3d(x, y, 0));
					}
				}
				if (pts.Num() == 0)
				{
					return;
				}
				if (m_pGeoRegion3D != nullptr)
				{
					m_pGeoRegion3D->SetPoints(pts);
				}
			}

			void DataServiceRequest::GetAttributes(TSharedPtr<FJsonObject> jsonObject)
			{
				TArray<TSharedPtr<FJsonValue>> features = jsonObject->GetArrayField("features");
				if (features.Num() > 0)
				{
					TSharedPtr<FJsonObject> feature = features[0]->AsObject();
					TArray<TSharedPtr<FJsonValue>> fieldNames = feature->GetArrayField("fieldNames");
					TArray<TSharedPtr<FJsonValue>> fieldValues = feature->GetArrayField("fieldValues");
					for (int i = 0; i < fieldNames.Num(); i++)
					{
						FString name = fieldNames[i]->AsString();
						FString value = fieldValues[i]->AsString();
						m_mapAttributes.Add(name, value);
					}

					m_DataServiceRequestEvent.Execute();
				}
			}

			GeoRegion3D* DataServiceRequest::GetGeoRegion3D()
			{
				return m_pGeoRegion3D;
			}

			TMap<FString, FString> DataServiceRequest::GetSelectAttribute()
			{
				return m_mapAttributes;
			}

			void DataServiceRequest::Release()
			{
				Gameint index = RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->IndexOf(FString("SelectionModel"));
				if (index != -1)
				{
					RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->GetTrackingLayer()->Remove(index);
					m_pGeoRegion3D->Clear();
				}
				m_mapAttributes.Empty();
			}

			void DataServiceRequest::CallFunc_DataServiceRequest(void* pActor, DataServiceRequestSelectEvent QAEvent)
			{
				m_DataServiceRequestEvent.m_pActor = pActor;
				m_DataServiceRequestEvent.Event = QAEvent;
			}
		}
	}
}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif