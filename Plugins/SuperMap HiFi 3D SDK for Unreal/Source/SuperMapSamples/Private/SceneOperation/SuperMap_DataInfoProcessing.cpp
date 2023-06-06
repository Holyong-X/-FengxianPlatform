// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneOperation/SuperMap_DataInfoProcessing.h"
#include "Data/UnrealWorkspaceManager.h"
#include "GameFramework/PlayerController.h"
#include "ControlUE/RealspaceView.h"
#include "Core/Georeference.h"
#include "Algorithm3D/MathEngine.h"

using namespace SuperMapSDK::UnrealEngine::Data;

ASuperMap_DataInfoProcessing::ASuperMap_DataInfoProcessing()
{

}

ASuperMap_DataInfoProcessing::~ASuperMap_DataInfoProcessing()
{

}

void ASuperMap_DataInfoProcessing::SetPostProcessingInfo(FPostProcessingInfo postProcessingInfo)
{
	UnrealWorkspaceManager::PostProcessingInfo& info = UnrealWorkspaceManager::GetSingleton()->GetPostProcessingInfo();
	info.m_ScreenSpaceReflection.m_fSSRIntensity = postProcessingInfo.SSRIntensity;
	info.m_ScreenSpaceReflection.m_fSSRQuality = postProcessingInfo.SSRQuality;
	info.m_ScreenSpaceReflection.m_fSSRMaxRoughness = postProcessingInfo.SSRMaxRoughness;
	info.m_AmbientOcclusion.m_fAOIntensity = postProcessingInfo.AOIntensity;
	info.m_AmbientOcclusion.m_fAORadius = postProcessingInfo.AORadius;
	info.m_MotionBlur.m_fDFAmount = postProcessingInfo.DFAmount;
	info.m_MotionBlur.m_fDFMax = postProcessingInfo.DFMax;
	info.m_DepthOfField.m_fFocalDistance = postProcessingInfo.FocalDistance;
	info.m_DepthOfField.m_fDepthBlurKm = postProcessingInfo.DepthBlurKm;
	info.m_DepthOfField.m_fDepthBlurRadius = postProcessingInfo.DepthBlurRadius;
	info.m_Bloom.m_fBloomIntensity = postProcessingInfo.BloomIntensity;
	info.m_Bloom.m_fBloomThreshold = postProcessingInfo.BloomThreshold;
}

FPostProcessingInfo ASuperMap_DataInfoProcessing::GetPostProcessingInfo()
{
	UnrealWorkspaceManager::PostProcessingInfo& info = UnrealWorkspaceManager::GetSingleton()->GetPostProcessingInfo();
	FPostProcessingInfo postProcessingInfo;
	postProcessingInfo.IsPostProcessingInfo = info.m_bPostProcessingInfo;
	postProcessingInfo.SSRIntensity = info.m_ScreenSpaceReflection.m_fSSRIntensity;
	postProcessingInfo.SSRQuality = info.m_ScreenSpaceReflection.m_fSSRQuality;
	postProcessingInfo.SSRMaxRoughness = info.m_ScreenSpaceReflection.m_fSSRMaxRoughness;
	postProcessingInfo.AOIntensity = info.m_AmbientOcclusion.m_fAOIntensity;
	postProcessingInfo.AORadius = info.m_AmbientOcclusion.m_fAORadius;
	postProcessingInfo.DFAmount = info.m_MotionBlur.m_fDFAmount;
	postProcessingInfo.DFMax = info.m_MotionBlur.m_fDFMax;
	postProcessingInfo.FocalDistance = info.m_DepthOfField.m_fFocalDistance;
	postProcessingInfo.DepthBlurKm = info.m_DepthOfField.m_fDepthBlurKm;
	postProcessingInfo.DepthBlurRadius = info.m_DepthOfField.m_fDepthBlurRadius;
	postProcessingInfo.BloomIntensity = info.m_Bloom.m_fBloomIntensity;
	postProcessingInfo.BloomThreshold = info.m_Bloom.m_fBloomThreshold;
	return postProcessingInfo;
}

void ASuperMap_DataInfoProcessing::SetWeatherInfo(FWeatherInfo weatherInfo)
{
	UnrealWorkspaceManager::WeatherInfo& info = UnrealWorkspaceManager::GetSingleton()->GetWeatherInfo();
	UnrealWorkspaceManager::SceneInfo& sceneinfo = UnrealWorkspaceManager::GetSingleton()->GetSceneInfo();
	info.m_nWeatherType = weatherInfo.WeatherType;
	info.m_fWetness = weatherInfo.Wetness;
	info.m_fSnowCoverage = weatherInfo.SnowCoverage;
	info.m_fCloudiness = weatherInfo.Cloudiness;
	info.m_fSpawnRate = weatherInfo.SpawnRate;
	info.m_vWeatherPsition = Vector3d(weatherInfo.m_vWeatherPsition);
	sceneinfo.m_bIsWeather = weatherInfo.IsWeather;
}

FWeatherInfo ASuperMap_DataInfoProcessing::GetWeatherInfo()
{
	UnrealWorkspaceManager::WeatherInfo& info = UnrealWorkspaceManager::GetSingleton()->GetWeatherInfo();
	UnrealWorkspaceManager::SceneInfo& sceneinfo = UnrealWorkspaceManager::GetSingleton()->GetSceneInfo();
	FWeatherInfo weatherInfo;
	weatherInfo.WeatherType = info.m_nWeatherType;
	weatherInfo.Wetness = info.m_fWetness;
	weatherInfo.SnowCoverage = info.m_fSnowCoverage;
	weatherInfo.Cloudiness = info.m_fCloudiness;
	weatherInfo.SpawnRate = info.m_fSpawnRate;
	weatherInfo.m_vWeatherPsition = FVector(info.m_vWeatherPsition.X, info.m_vWeatherPsition.Y, info.m_vWeatherPsition.Z);
	weatherInfo.IsWeather = sceneinfo.m_bIsWeather;
	return weatherInfo;
}

void ASuperMap_DataInfoProcessing::SetSceneInfo(FDateTime dateTime, float dateTimeZone)
{
	UnrealWorkspaceManager::SceneInfo& sceneinfo = UnrealWorkspaceManager::GetSingleton()->GetSceneInfo();
	sceneinfo.m_tSunTime = dateTime;
	sceneinfo.m_fTimeZone = dateTimeZone;
	FVector cameraLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	Vector3d point = Georeference::TransformUERelativeToOriginECEF(cameraLocation);
	sceneinfo.m_vCameraLocation = point.ToFVector();
	sceneinfo.m_vCameraRotator = GetWorld()->GetFirstPlayerController()->GetControlRotation();
	sceneinfo.m_fFov = RealspaceView::GetSingleton()->GetCameraControl()->GetFov();
	sceneinfo.m_vGeoreferenceOrigin = RealspaceView::GetSingleton()->GetGeoreferenceOrigin();
}

FSceneInfo ASuperMap_DataInfoProcessing::GetSceneInfo()
{
	UnrealWorkspaceManager::SceneInfo& info = UnrealWorkspaceManager::GetSingleton()->GetSceneInfo();
	FSceneInfo sceneInfo;
	sceneInfo.m_bIsScene = info.m_bSceneInfo;
	sceneInfo.m_tSunTime = info.m_tSunTime;
	sceneInfo.m_fTimeZone = info.m_fTimeZone;
	RealspaceView::GetSingleton()->SetGeoreferenceOrigin(info.m_vGeoreferenceOrigin.X, info.m_vGeoreferenceOrigin.Y, info.m_vGeoreferenceOrigin.Z);
	Vector3d cameraLocation = Georeference::TransformOriginECEFToUEReative(info.m_vCameraLocation);
	GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(cameraLocation.ToFVector());
	GetWorld()->GetFirstPlayerController()->SetControlRotation(info.m_vCameraRotator);
	RealspaceView::GetSingleton()->GetSceneControl()->GetScene()->SetCameraFov(info.m_fFov);
	return sceneInfo;
}

void ASuperMap_DataInfoProcessing::ExecuteBroadcast()
{
	if (CallEvent.IsBound())
	{
		CallEvent.Broadcast();
	}
}

void OnDataInfoProcessingCallBack(void* pActor)
{
	if (pActor == nullptr)
	{
		return;
	}
	ASuperMap_DataInfoProcessing* dataInfoActor = (ASuperMap_DataInfoProcessing*)pActor;
	dataInfoActor->ExecuteBroadcast();
}