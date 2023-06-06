#include "Data/UnrealWorkspaceManager.h"
#include "ControlUE/RealspaceView.h"

using namespace SuperMapSDK::UnrealEngine::ControlUE;

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{

	UnrealWorkspaceManager* UnrealWorkspaceManager::m_pUnrealWorkspaceManager = nullptr;
	UnrealWorkspaceManager::UnrealWorkspaceManager()
	{
		m_arrActorInfo.Empty();
		m_WeatherInfo = WeatherInfo();
		m_SceneInfo = SceneInfo();
		m_PostProcessingInfo = PostProcessingInfo();
	}

	UnrealWorkspaceManager ::~UnrealWorkspaceManager()
	{
		m_arrActorInfo.Empty();
	}

	UnrealWorkspaceManager* UnrealWorkspaceManager::GetSingleton()
	{
		if (m_pUnrealWorkspaceManager == nullptr)
		{
			m_pUnrealWorkspaceManager = new UnrealWorkspaceManager();
		}
		return m_pUnrealWorkspaceManager;
	}

	void UnrealWorkspaceManager::DestorySingleton()
	{
		if (m_pUnrealWorkspaceManager != nullptr)
		{
			delete m_pUnrealWorkspaceManager;
			m_pUnrealWorkspaceManager = nullptr;
		}
	}

	TArray<UnrealWorkspaceManager::ActorInfo>& UnrealWorkspaceManager::GetArrActorInfo()
	{
		return m_arrActorInfo;
	}

	UnrealWorkspaceManager::WeatherInfo& UnrealWorkspaceManager::GetWeatherInfo()
	{
		return m_WeatherInfo;
	}

	UnrealWorkspaceManager::SceneInfo& UnrealWorkspaceManager::GetSceneInfo()
	{
		return m_SceneInfo;
	}

	UnrealWorkspaceManager::PostProcessingInfo& UnrealWorkspaceManager::GetPostProcessingInfo()
			{
				return m_PostProcessingInfo;
			}

	void UnrealWorkspaceManager::ToJson(FString path)
	{
		JsonFile* jsonFile = new JsonFile();
		JsonFile* jsonScenes = nullptr;
		jsonFile->LoadFromStdFile(path);
		jsonFile->GetValue(FString("Scenes"), jsonScenes);
		if (jsonScenes == nullptr)
		{
			return;
		}
		Gameint nScenesCount = jsonScenes->GetArraySize();
		for (Gameint i = 0; i < nScenesCount; i++)
		{
			JsonFile* jsonScene = jsonScenes->GetAt(i);
			if (jsonScene == nullptr)
			{
				continue;
			}
			JsonFile* jsonUnrealSceneSetting = new JsonFile(JsonValueType::objectValue);
			jsonUnrealSceneSetting->Add("SceneInfo", SceneInfoToJson());
			jsonUnrealSceneSetting->Add("WeatherInfo", WeatherInfoToJson());
			jsonUnrealSceneSetting->Add("PostProcessingInfo", PostProcessingInfoToJson());
			jsonUnrealSceneSetting->Add("ActorInfos", ActorInfoToJson());
			jsonScene->Add("UnrealSceneSetting", jsonUnrealSceneSetting);
			delete jsonUnrealSceneSetting;
			jsonUnrealSceneSetting = nullptr;
		}
		jsonFile->SaveToStdFile(path);
		delete jsonScenes;
		jsonScenes = nullptr;
	}

	JsonFile* UnrealWorkspaceManager::SceneInfoToJson()
			{
				JsonFile* jsonFile = new JsonFile(JsonValueType::objectValue);
				JsonFile* jsonGeoreferenceOrigin = new JsonFile(JsonValueType::objectValue);
				jsonGeoreferenceOrigin->Add("X", m_SceneInfo.m_vGeoreferenceOrigin.X);
				jsonGeoreferenceOrigin->Add("Y", m_SceneInfo.m_vGeoreferenceOrigin.Y);
				jsonGeoreferenceOrigin->Add("Z", m_SceneInfo.m_vGeoreferenceOrigin.Z);
				jsonFile->Add("GeoreferenceOrigin", jsonGeoreferenceOrigin);
				jsonFile->Add("Weather", m_SceneInfo.m_bIsWeather);

				JsonFile* jsonCameraLocation = new JsonFile(JsonValueType::objectValue);
				jsonCameraLocation->Add("X", m_SceneInfo.m_vCameraLocation.X);
				jsonCameraLocation->Add("Y", m_SceneInfo.m_vCameraLocation.Y);
				jsonCameraLocation->Add("Z", m_SceneInfo.m_vCameraLocation.Z);
				jsonFile->Add("CameraLocation", jsonCameraLocation);

				JsonFile* jsonCameraRotator = new JsonFile(JsonValueType::objectValue);
				jsonCameraRotator->Add("Pitch", m_SceneInfo.m_vCameraRotator.Pitch);
				jsonCameraRotator->Add("Yaw", m_SceneInfo.m_vCameraRotator.Yaw);
				jsonCameraRotator->Add("Roll", m_SceneInfo.m_vCameraRotator.Roll);
				jsonFile->Add("CameraRotator", jsonCameraRotator);

				jsonFile->Add("CameraFov", m_SceneInfo.m_fFov);
				FDateTime sunTime = m_SceneInfo.m_tSunTime;
				FString strTime = FString::Printf(TEXT("%d-%d-%d-%d-%d-%d"), sunTime.GetYear(), sunTime.GetMonth(), sunTime.GetDay(),
					sunTime.GetHour(), sunTime.GetMinute(), sunTime.GetSecond());
				jsonFile->Add("SunTime", strTime);
				jsonFile->Add("SunTimeZone", m_SceneInfo.m_fTimeZone);
				
				delete jsonCameraRotator;
				jsonCameraRotator = nullptr;
				delete jsonCameraLocation;
				jsonCameraLocation = nullptr;
				delete jsonGeoreferenceOrigin;
				jsonGeoreferenceOrigin = nullptr;
				return jsonFile;
			}

	JsonFile* UnrealWorkspaceManager::WeatherInfoToJson()
			{
				JsonFile* jsonFile = new JsonFile(JsonValueType::objectValue);
				JsonFile* jsonWeatherPsition = new JsonFile(JsonValueType::objectValue);
				jsonWeatherPsition->Add("X", m_WeatherInfo.m_vWeatherPsition.X);
				jsonWeatherPsition->Add("Y", m_WeatherInfo.m_vWeatherPsition.Y);
				jsonWeatherPsition->Add("Z", m_WeatherInfo.m_vWeatherPsition.Z);
				jsonFile->Add("WeatherPsition", jsonWeatherPsition);
				jsonFile->Add("WeatherType", m_WeatherInfo.m_nWeatherType);
				jsonFile->Add("Wetness", m_WeatherInfo.m_fWetness);
				jsonFile->Add("SnowCoverage", m_WeatherInfo.m_fSnowCoverage);
				jsonFile->Add("Cloudiness", m_WeatherInfo.m_fCloudiness);
				jsonFile->Add("SpawnRate", m_WeatherInfo.m_fSpawnRate);
				delete jsonWeatherPsition;
				jsonWeatherPsition = nullptr;
				return jsonFile;
			}

	JsonFile* UnrealWorkspaceManager::PostProcessingInfoToJson()
			{
				JsonFile* jsonFile = new JsonFile(JsonValueType::objectValue);
				JsonFile* jsonScreenSpaceReflection = new JsonFile(JsonValueType::objectValue);
				jsonScreenSpaceReflection->Add("SSRIntensity", m_PostProcessingInfo.m_ScreenSpaceReflection.m_fSSRIntensity);
				jsonScreenSpaceReflection->Add("SSRQuality", m_PostProcessingInfo.m_ScreenSpaceReflection.m_fSSRQuality);
				jsonScreenSpaceReflection->Add("SSRMaxRoughness", m_PostProcessingInfo.m_ScreenSpaceReflection.m_fSSRMaxRoughness);
				jsonFile->Add("ScreenSpaceReflection", jsonScreenSpaceReflection);

				JsonFile* jsonAmbientOcclusion = new JsonFile(JsonValueType::objectValue);
				jsonAmbientOcclusion->Add("AOIntensity", m_PostProcessingInfo.m_AmbientOcclusion.m_fAOIntensity);
				jsonAmbientOcclusion->Add("AORadius", m_PostProcessingInfo.m_AmbientOcclusion.m_fAORadius);
				jsonFile->Add("AmbientOcclusion", jsonAmbientOcclusion);

				JsonFile* jsonMotionBlur = new JsonFile(JsonValueType::objectValue);
				jsonMotionBlur->Add("DFAmount", m_PostProcessingInfo.m_MotionBlur.m_fDFAmount);
				jsonMotionBlur->Add("DFMax", m_PostProcessingInfo.m_MotionBlur.m_fDFMax);
				jsonFile->Add("MotionBlur", jsonMotionBlur);

				JsonFile* jsonDepthOfField = new JsonFile(JsonValueType::objectValue);
				jsonDepthOfField->Add("FocalDistance", m_PostProcessingInfo.m_DepthOfField.m_fFocalDistance);
				jsonDepthOfField->Add("DepthBlurKm", m_PostProcessingInfo.m_DepthOfField.m_fDepthBlurKm);
				jsonDepthOfField->Add("DepthBlurRadius", m_PostProcessingInfo.m_DepthOfField.m_fDepthBlurRadius);
				jsonFile->Add("DepthOfField", jsonDepthOfField);

				JsonFile* jsonBloom = new JsonFile(JsonValueType::objectValue);
				jsonBloom->Add("BloomIntensity", m_PostProcessingInfo.m_Bloom.m_fBloomIntensity);
				jsonBloom->Add("BloomThreshold", m_PostProcessingInfo.m_Bloom.m_fBloomThreshold);
				jsonFile->Add("Bloom", jsonBloom);

				delete jsonScreenSpaceReflection;
				jsonScreenSpaceReflection = nullptr;
				delete jsonAmbientOcclusion;
				jsonAmbientOcclusion = nullptr;
				delete jsonMotionBlur;
				jsonMotionBlur = nullptr;
				delete jsonDepthOfField;
				jsonDepthOfField = nullptr;
				delete jsonBloom;
				jsonBloom = nullptr;
				return jsonFile;
			}

	JsonFile* UnrealWorkspaceManager::ActorInfoToJson()
			{
				JsonFile* jsonFile = new JsonFile(JsonValueType::objectValue);
				JsonFile* jsonActorInfos = new JsonFile(JsonValueType::arrayValue);
				for (int i = 0; i < m_arrActorInfo.Num(); i++)
				{
					ActorInfo actorInfo = m_arrActorInfo[i];
					JsonFile* jsonActorInfo = new JsonFile(JsonValueType::objectValue);
					jsonActorInfo->Add("ActorIndex", actorInfo.m_nActorIndex);
					//TODO
					jsonActorInfos->Add(jsonActorInfo);
					delete jsonActorInfo;
					jsonActorInfo = nullptr;
				}
				jsonFile->Add(jsonActorInfos);
				return jsonFile;
			}

	void UnrealWorkspaceManager::FromJson(FString path)
			{
				JsonFile* jsonFile = new JsonFile();
				jsonFile->LoadFromStdFile(path);
				JsonFile* jsonScenes = nullptr;
				jsonFile->GetValue(FString("Scenes"), jsonScenes);
				if (jsonScenes == nullptr)
				{
					delete jsonFile;
					jsonFile = nullptr;
					return;
				}
				Gameint nScenesCount = jsonScenes->GetArraySize();
				//只支持一个场景
				for (int i = 0; i < nScenesCount; i++)
				{
					JsonFile* jsonScene = jsonScenes->GetAt(i);
					if (jsonScene == nullptr)
					{
						continue;
					}
					JsonFile* jsonUnrealSceneSetting = nullptr;
					jsonScene->GetValue(FString("UnrealSceneSetting"), jsonUnrealSceneSetting);
					if (jsonUnrealSceneSetting == nullptr)
					{
						delete jsonScene;
						jsonScene = nullptr;
						continue;
					}
					SceneInfoFromJson(jsonUnrealSceneSetting);
					WeatherInfoFromJson(jsonUnrealSceneSetting);
					PostProcessingInfoFromJson(jsonUnrealSceneSetting);
					ActorInfoFromJson(jsonUnrealSceneSetting);

					delete jsonUnrealSceneSetting;
					jsonUnrealSceneSetting = nullptr;
				}

				delete jsonScenes;
				jsonScenes = nullptr;
				delete jsonFile;
				jsonFile = nullptr;
			}

	void UnrealWorkspaceManager::SceneInfoFromJson(JsonFile* jsonFile)
			{
				JsonFile* jsonSceneInfo = nullptr;
				Gamebool result = jsonFile->GetValue(FString("SceneInfo"), jsonSceneInfo);
				if (!result)
				{
					m_SceneInfo.m_bSceneInfo = false;
					return;
				}
				m_SceneInfo.m_bSceneInfo = true;
				JsonFile* jsonGeoreferenceOrigin = nullptr;
				jsonSceneInfo->GetValue(FString("GeoreferenceOrigin"), jsonGeoreferenceOrigin);
				Gamedouble x = 0,y =0, z =0;
				jsonGeoreferenceOrigin->GetValue(FString("X"), x);
				jsonGeoreferenceOrigin->GetValue(FString("Y"), y);
				jsonGeoreferenceOrigin->GetValue(FString("Z"), z);
				m_SceneInfo.m_vGeoreferenceOrigin = Vector3d(x,y,z);
				Gameint bWeather = 0;
				jsonSceneInfo->GetValue(FString("Weather"), bWeather);
				m_SceneInfo.m_bIsWeather = (bWeather == 1);
				JsonFile* jsonCameraLocation = nullptr;
				jsonSceneInfo->GetValue(FString("CameraLocation"), jsonCameraLocation);
				Gamedouble x1 = 0, y1 = 0, z1 = 0;
				jsonCameraLocation->GetValue(FString("X"), x1);
				jsonCameraLocation->GetValue(FString("Y"), y1);
				jsonCameraLocation->GetValue(FString("Z"), z1);
				m_SceneInfo.m_vCameraLocation = FVector(x1, y1, z1);

				JsonFile* jsonCameraRotator = nullptr;
				jsonSceneInfo->GetValue(FString("CameraRotator"), jsonCameraRotator);
				Gamedouble x2 = 0, y2 = 0, z2 = 0;
				jsonCameraRotator->GetValue(FString("Pitch"), x2);
				jsonCameraRotator->GetValue(FString("Yaw"), y2);
				jsonCameraRotator->GetValue(FString("Roll"), z2);
				m_SceneInfo.m_vCameraRotator = FRotator(x2, y2, z2);

				jsonSceneInfo->GetValue(FString("CameraFov"), m_SceneInfo.m_fFov);
				
				FString strSunTime;
				jsonSceneInfo->GetValue(FString("SunTime"), strSunTime);
				if (!strSunTime.IsEmpty())
				{
					TArray<FString> times;
					strSunTime.ParseIntoArray(times, TEXT("-"), true);
					FDateTime sTime = FDateTime(FCString::Atoi(*times[0]), FCString::Atoi(*times[1]), FCString::Atoi(*times[2]), FCString::Atoi(*times[3]), FCString::Atoi(*times[4]), FCString::Atoi(*times[5]));
					m_SceneInfo.m_tSunTime = sTime;
				}
				jsonSceneInfo->GetValue(FString("SunTimeZone"), m_SceneInfo.m_fTimeZone);
				delete jsonGeoreferenceOrigin;
				jsonGeoreferenceOrigin = nullptr;
				delete jsonCameraLocation;
				jsonCameraLocation = nullptr;
				delete jsonCameraRotator;
				jsonCameraRotator = nullptr;
				delete jsonSceneInfo;
				jsonSceneInfo = nullptr;

				if (m_SceneInfo.m_vCameraLocation == FVector(0,0,0) && m_SceneInfo.m_vGeoreferenceOrigin == Vector3d(0,0,0))
				{
					m_SceneInfo.m_bSceneInfo = false;
				}
			}

	void UnrealWorkspaceManager::WeatherInfoFromJson(JsonFile* jsonFile)
			{
				if (!m_SceneInfo.m_bIsWeather)
				{
					return;
				}
				JsonFile* jsonWeatherInfo = nullptr;
				jsonFile->GetValue(FString("WeatherInfo"), jsonWeatherInfo);
				if (jsonWeatherInfo == nullptr)
				{
					return;
				}
				jsonWeatherInfo->GetValue(FString("Cloudiness"), m_WeatherInfo.m_fCloudiness);
				jsonWeatherInfo->GetValue(FString("SnowCoverage"), m_WeatherInfo.m_fSnowCoverage);
				jsonWeatherInfo->GetValue(FString("SpawnRate"), m_WeatherInfo.m_fSpawnRate);
				jsonWeatherInfo->GetValue(FString("WeatherType"), m_WeatherInfo.m_nWeatherType);
				jsonWeatherInfo->GetValue(FString("Wetness"), m_WeatherInfo.m_fWetness);
				JsonFile* jsonWeatherPsition = nullptr;
				jsonWeatherInfo->GetValue(FString("WeatherPsition"), jsonWeatherPsition);
				Gamedouble x = 0, y = 0, z = 0;
				jsonWeatherPsition->GetValue(FString("X"), x);
				jsonWeatherPsition->GetValue(FString("Y"), y);
				jsonWeatherPsition->GetValue(FString("Z"), z);
				m_WeatherInfo.m_vWeatherPsition = Vector3d(x, y, z);

				delete jsonWeatherPsition;
				jsonWeatherPsition = nullptr;
				delete jsonWeatherInfo;
				jsonWeatherInfo = nullptr;
			}

	void UnrealWorkspaceManager::PostProcessingInfoFromJson(JsonFile* jsonFile)
			{
				JsonFile* jsonPostProcessingInfo = nullptr;
				Gamebool result = jsonFile->GetValue(FString("PostProcessingInfo"), jsonPostProcessingInfo);
				if (!result)
				{
					m_PostProcessingInfo.m_bPostProcessingInfo = false;
					return;
				}
				m_PostProcessingInfo.m_bPostProcessingInfo = true;
				JsonFile* jsonAmbientOcclusion = nullptr;
				jsonPostProcessingInfo->GetValue(FString("AmbientOcclusion"), jsonAmbientOcclusion);
				jsonAmbientOcclusion->GetValue(FString("AOIntensity"), m_PostProcessingInfo.m_AmbientOcclusion.m_fAOIntensity);
				jsonAmbientOcclusion->GetValue(FString("AORadius"), m_PostProcessingInfo.m_AmbientOcclusion.m_fAORadius);
				delete jsonAmbientOcclusion;
				jsonAmbientOcclusion = nullptr;

				JsonFile* jsonBloom = nullptr;
				jsonPostProcessingInfo->GetValue(FString("Bloom"), jsonBloom);
				jsonBloom->GetValue(FString("BloomIntensity"), m_PostProcessingInfo.m_Bloom.m_fBloomIntensity);
				jsonBloom->GetValue(FString("BloomThreshold"), m_PostProcessingInfo.m_Bloom.m_fBloomThreshold);
				delete jsonBloom;
				jsonBloom = nullptr;

				JsonFile* jsonDepthOfField = nullptr;
				jsonPostProcessingInfo->GetValue(FString("DepthOfField"), jsonDepthOfField);
				jsonDepthOfField->GetValue(FString("DepthBlurKm"), m_PostProcessingInfo.m_DepthOfField.m_fDepthBlurKm);
				jsonDepthOfField->GetValue(FString("DepthBlurRadius"), m_PostProcessingInfo.m_DepthOfField.m_fDepthBlurRadius);
				jsonDepthOfField->GetValue(FString("FocalDistance"), m_PostProcessingInfo.m_DepthOfField.m_fFocalDistance);
				delete jsonDepthOfField;
				jsonDepthOfField = nullptr;

				JsonFile* jsonMotionBlur = nullptr;
				jsonPostProcessingInfo->GetValue(FString("MotionBlur"), jsonMotionBlur);
				jsonMotionBlur->GetValue(FString("DFAmount"), m_PostProcessingInfo.m_MotionBlur.m_fDFAmount);
				jsonMotionBlur->GetValue(FString("DFMax"), m_PostProcessingInfo.m_MotionBlur.m_fDFMax);
				delete jsonMotionBlur;
				jsonMotionBlur = nullptr;

				JsonFile* jsonScreenSpaceReflection = nullptr;
				jsonPostProcessingInfo->GetValue(FString("ScreenSpaceReflection"), jsonScreenSpaceReflection);
				jsonScreenSpaceReflection->GetValue(FString("SSRIntensity"), m_PostProcessingInfo.m_ScreenSpaceReflection.m_fSSRIntensity);
				jsonScreenSpaceReflection->GetValue(FString("SSRMaxRoughness"), m_PostProcessingInfo.m_ScreenSpaceReflection.m_fSSRMaxRoughness);
				jsonScreenSpaceReflection->GetValue(FString("SSRQuality"), m_PostProcessingInfo.m_ScreenSpaceReflection.m_fSSRQuality);
				delete jsonScreenSpaceReflection;
				jsonScreenSpaceReflection = nullptr;

				delete jsonPostProcessingInfo;
				jsonPostProcessingInfo = nullptr;

			}

	void UnrealWorkspaceManager::ActorInfoFromJson(JsonFile* jsonFile)
			{
				//TODO
			}

	void UnrealWorkspaceManager::CallFunc_UnrealWorkspaceManager(void* pActor, UnrealWorkspaceEvent dataEvent)
			{
				m_UnrealWorkspaceEvent.m_pActor = pActor;
				m_UnrealWorkspaceEvent.Event = dataEvent;
			}

}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif