// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SuperMap.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "ShaderCore.h"
//#include "SuperMapLibrary/ExampleLibrary.h"

#define LOCTEXT_NAMESPACE "FSuperMapModule"

void FSuperMapModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("SuperMap")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
	FString CloudLicenseLibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SuperMapLibrary/Win64/PluginGameEngine.dll"));
	CloudLicenseLibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SuperMapLibrary/Win64/SuperMap.Data.CloudLicense.dll"));
	const FString BinDir = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SuperMapLibrary/Win64/"));

#elif PLATFORM_MAC
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SuperMapLibrary/Mac/Release/libExampleLibrary.dylib"));

#elif PLATFORM_LINUX
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SuperMapLibrary/Linux_x86_64/libSuPluginGameEngine.so"));
	//CloudLicenseLibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SuperMapLibrary/Win64/SuperMap.Data.CloudLicense.dll"));
	const FString BinDir = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SuperMapLibrary/Linux_x86_64/"));
#endif // PLATFORM_WINDOWS

	FString strShaderDir = FPaths::Combine(*BaseDir, TEXT("Content/Shader/"));
	AddShaderSourceDirectoryMapping(TEXT("/SuperMap"), strShaderDir);

	FPlatformProcess::AddDllDirectory(*BinDir);
	FPlatformProcess::PushDllDirectory(*BinDir);

	m_pSupermapDLLHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
	m_pCloudLicenseDLLHandle = !CloudLicenseLibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*CloudLicenseLibraryPath) : nullptr;

#if PLATFORM_LINUX
	if (m_pSupermapDLLHandle)
#else 
	if (m_pSupermapDLLHandle && m_pCloudLicenseDLLHandle)
#endif
	{
		// Call the test function in the third party library that opens a message box
		//ExampleLibraryFunction();
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
	}
}

void* FSuperMapModule::GetDLLHandle()
{
	return m_pSupermapDLLHandle;
}

void* FSuperMapModule::GetCloudLicenseDLLHandle()
{
	return m_pCloudLicenseDLLHandle;
}

void FSuperMapModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(m_pSupermapDLLHandle);
	m_pSupermapDLLHandle = nullptr;
#if PLATFORM_WINDOWS
	FPlatformProcess::FreeDllHandle(m_pCloudLicenseDLLHandle);
	m_pCloudLicenseDLLHandle = nullptr;
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSuperMapModule, SuperMap)
