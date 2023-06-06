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
		//�����¼�
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
		//��Ļ�ռ䷴�� ǿ��
		Gamefloat m_fSSRIntensity;
		//��Ļ�ռ䷴�� ����
		Gamefloat m_fSSRQuality;
		//��Ļ�ռ䷴�� ���ֲڶ�
		Gamefloat m_fSSRMaxRoughness;
	};

	struct SUPERMAP_API AmbientOcclusion
	{
		//�������ڵ� ǿ��
		Gamefloat m_fAOIntensity;
		//�������ڵ� �뾶
		Gamefloat m_fAORadius;
	};

	struct SUPERMAP_API MotionBlur
	{
		//��̬ģ�� ǿ��
		Gamefloat m_fDFAmount;
		//��̬ģ�� ���
		Gamefloat m_fDFMax;
	};

	struct SUPERMAP_API DepthOfField
	{
		//���� ����
		Gamefloat m_fFocalDistance;
		//���� ���ģ��
		Gamefloat m_fDepthBlurKm;
		//���� ���ģ���뾶
		Gamefloat m_fDepthBlurRadius;
	};

	struct SUPERMAP_API Bloom
	{
		//���� ǿ��
		Gamefloat m_fBloomIntensity;
		//���� ��ֵ
		Gamefloat m_fBloomThreshold;
	};

	class SUPERMAP_API UnrealWorkspaceManager
	{
	public:
		struct SUPERMAP_API ActorInfo
		{
			//������
			Gameint m_nActorIndex;
			//λ�á���ת������
			FTransform m_tTransform;
		};

		struct SUPERMAP_API WeatherInfo
		{
			//����Actor���õ�
			Vector3d m_vWeatherPsition;
			//����(0:Sun 1:Cloudly 2:Rain 3:Snow)
			Gameint m_nWeatherType;
			//����ʪ��
			Gamefloat m_fWetness;
			//��ѩ����
			Gamefloat m_fSnowCoverage;
			//����Ƹ���
			Gamefloat m_fCloudiness;
			//��ѩ������
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
			//����ԭ��
			Vector3d m_vGeoreferenceOrigin;
			//�Ƿ�����ѩ
			Gamebool m_bIsWeather;
			//ʱ��
			FDateTime m_tSunTime;
			//ʱ��
			Gamefloat m_fTimeZone;
			//�����λ�ü���ת��
			FVector m_vCameraLocation;
			FRotator m_vCameraRotator;
			//�����FOV
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
		//! \brief ��ȡ������
		static UnrealWorkspaceManager* GetSingleton();

		//! \brief ���ٵ�����
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

		//! \brief ��Ϸ���������
		static UnrealWorkspaceManager* m_pUnrealWorkspaceManager;

		TArray<UnrealWorkspaceManager::ActorInfo> m_arrActorInfo;

		UnrealWorkspaceManager::WeatherInfo m_WeatherInfo;

		UnrealWorkspaceManager::SceneInfo m_SceneInfo;

		UnrealWorkspaceManager::PostProcessingInfo m_PostProcessingInfo;
	};
}