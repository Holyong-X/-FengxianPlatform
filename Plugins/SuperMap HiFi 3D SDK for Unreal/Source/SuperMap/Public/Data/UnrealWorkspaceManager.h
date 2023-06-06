#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Data/Vector3d.h"
#include "XmlParser/Public/XmlParser.h"
#include "Interfaces/IPluginManager.h"
#include "Data/JsonFile.h"
namespace SuperMapSDK
{
	
	typedef void(*UnrealWorkspaceEvent) (void* pActor);

	struct SUPERMAP_API UnrealWorkspaceEventCallBack
	{
	public:
		void* m_pActor;
		//触发事件
		UnrealWorkspaceEvent Event;
	public:
		UnrealWorkspaceEventCallBack()
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

	struct SUPERMAP_API ScreenSpaceReflection
	{
		//屏幕空间反射 强度
		Gamefloat m_fSSRIntensity;
		//屏幕空间反射 质量
		Gamefloat m_fSSRQuality;
		//屏幕空间反射 最大粗糙度
		Gamefloat m_fSSRMaxRoughness;
	};

	struct SUPERMAP_API AmbientOcclusion
	{
		//环境光遮挡 强度
		Gamefloat m_fAOIntensity;
		//环境光遮挡 半径
		Gamefloat m_fAORadius;
	};

	struct SUPERMAP_API MotionBlur
	{
		//动态模糊 强度
		Gamefloat m_fDFAmount;
		//动态模糊 最大
		Gamefloat m_fDFMax;
	};

	struct SUPERMAP_API DepthOfField
	{
		//景深 焦距
		Gamefloat m_fFocalDistance;
		//景深 深度模糊
		Gamefloat m_fDepthBlurKm;
		//景深 深度模糊半径
		Gamefloat m_fDepthBlurRadius;
	};

	struct SUPERMAP_API Bloom
	{
		//泛光 强度
		Gamefloat m_fBloomIntensity;
		//泛光 阈值
		Gamefloat m_fBloomThreshold;
	};

	class SUPERMAP_API UnrealWorkspaceManager
	{
	public:
		struct SUPERMAP_API ActorInfo
		{
			//索引号
			Gameint m_nActorIndex;
			//位置、旋转、缩放
			FTransform m_tTransform;
		};

		struct SUPERMAP_API WeatherInfo
		{
			//天气Actor放置点
			Vector3d m_vWeatherPsition;
			//天气(0:Sun 1:Cloudly 2:Rain 3:Snow)
			Gameint m_nWeatherType;
			//材质湿度
			Gamefloat m_fWetness;
			//积雪覆盖
			Gamefloat m_fSnowCoverage;
			//体积云覆盖
			Gamefloat m_fCloudiness;
			//雨雪粒子量
			Gamefloat m_fSpawnRate;
		public:
			WeatherInfo()
			{
				m_vWeatherPsition = Vector3d(0.0, 0.0, 0.0);
				m_nWeatherType = 0;
				m_fWetness = 0;
				m_fSnowCoverage = 0;
				m_fCloudiness = 0;
				m_fSpawnRate = 0;
			}
		};

		struct SUPERMAP_API SceneInfo
		{
			Gamebool m_bSceneInfo;
			//地理原点
			Vector3d m_vGeoreferenceOrigin;
			//是否开启雨雪
			Gamebool m_bIsWeather;
			//时间
			FDateTime m_tSunTime;
			//时区
			Gamefloat m_fTimeZone;
			//相机的位置及旋转角
			FVector m_vCameraLocation;
			FRotator m_vCameraRotator;
			//相机的FOV
			Gamefloat m_fFov;
		public:
			SceneInfo()
			{
				m_bSceneInfo = false;
				m_vGeoreferenceOrigin = Vector3d(0.0, 0.0, 0.0);
				m_bIsWeather = false;
				m_tSunTime = FDateTime::Now();
				m_fTimeZone = 0;
				m_vCameraLocation = FVector(0, 0, 0);
				m_vCameraRotator = FRotator(0, 0, 0);
				m_fFov = 60;
			}
		};

		struct SUPERMAP_API PostProcessingInfo
		{
			Gamebool m_bPostProcessingInfo;

			ScreenSpaceReflection  m_ScreenSpaceReflection;

			AmbientOcclusion  m_AmbientOcclusion;

			MotionBlur  m_MotionBlur;
			
			DepthOfField  m_DepthOfField;

			Bloom m_Bloom;
		public:
			PostProcessingInfo()
			{
				m_bPostProcessingInfo = false;
				m_ScreenSpaceReflection.m_fSSRIntensity = 100;
				m_ScreenSpaceReflection.m_fSSRQuality = 50;
				m_ScreenSpaceReflection.m_fSSRMaxRoughness = 0.8;
				m_AmbientOcclusion.m_fAOIntensity = 0.5;
				m_AmbientOcclusion.m_fAORadius = 200;
				m_MotionBlur.m_fDFAmount = 0.5;
				m_MotionBlur.m_fDFMax = 5;
				m_DepthOfField.m_fFocalDistance = 0;
				m_DepthOfField.m_fDepthBlurKm = 0;
				m_DepthOfField.m_fDepthBlurRadius = 0;
				m_Bloom.m_fBloomIntensity = 0;
				m_Bloom.m_fBloomThreshold = -1;
			}
		};

	public:
		UnrealWorkspaceManager();
		~UnrealWorkspaceManager();
	public:
		//! \brief 获取单例类
		static UnrealWorkspaceManager* GetSingleton();

		//! \brief 销毁单例类
		static void DestorySingleton();

		TArray<UnrealWorkspaceManager::ActorInfo>& GetArrActorInfo();

		UnrealWorkspaceManager::WeatherInfo& GetWeatherInfo();

		UnrealWorkspaceManager::SceneInfo& GetSceneInfo();

		UnrealWorkspaceManager::PostProcessingInfo& GetPostProcessingInfo();

		void ToJson(FString path);

		void FromJson(FString path);

		void CallFunc_UnrealWorkspaceManager(void* pActor, UnrealWorkspaceEvent dataEvent);

	private:
		JsonFile* SceneInfoToJson();

		JsonFile* WeatherInfoToJson();

		JsonFile* PostProcessingInfoToJson();

		JsonFile* ActorInfoToJson();

		void SceneInfoFromJson(JsonFile* jsonFile);

		void WeatherInfoFromJson(JsonFile* jsonFile);

		void PostProcessingInfoFromJson(JsonFile* jsonFile);

		void ActorInfoFromJson(JsonFile* jsonFile);
	private:

		UnrealWorkspaceEventCallBack m_UnrealWorkspaceEvent;

		//! \brief 游戏对象管理器
		static UnrealWorkspaceManager* m_pUnrealWorkspaceManager;

		TArray<UnrealWorkspaceManager::ActorInfo> m_arrActorInfo;

		UnrealWorkspaceManager::WeatherInfo m_WeatherInfo;

		UnrealWorkspaceManager::SceneInfo m_SceneInfo;

		UnrealWorkspaceManager::PostProcessingInfo m_PostProcessingInfo;
	};
}