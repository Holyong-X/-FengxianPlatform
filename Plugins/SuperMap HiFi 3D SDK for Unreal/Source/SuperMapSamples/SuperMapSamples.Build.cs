// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class SuperMapSamples : ModuleRules
{
    private string ModulePath
    {
        get
        {
            return ModuleDirectory;
        }
    }
    private string ColorTablePath
    {
        get
        {
            return Path.GetFullPath(Path.Combine(ModulePath, "../../Content/ColorTable/"));
        }
    }
    private string WinThirdPartyResource
    {
        get
        {
            return Path.GetFullPath(Path.Combine(ModulePath, "../../Source/ThirdParty/SuperMapLibrary/Win64/Resource/"));
        }
    }

    private string LinuxThirdPartyResource
    {
        get
        {
            return Path.GetFullPath(Path.Combine(ModulePath, "../../Source/ThirdParty/SuperMapLibrary/Linux_x86_64/Resource/"));
        }
    }

    public SuperMapSamples(ReadOnlyTargetRules Target) : base(Target)
    {
        ReadOnlyBuildVersion Version = ReadOnlyBuildVersion.Current;
        if (Version.MajorVersion == 5)
        {
            PublicDefinitions.Add("SM_FOR_UE_FIVE= 1");
        }
        else if (Version.MajorVersion == 4)
        {
            PublicDefinitions.Add("SM_FOR_UE_FIVE = 0");
        }

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        string strPath = EngineDirectory + "/Shaders/Shared";

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            var files = System.IO.Directory.GetFiles(ColorTablePath, "*.*", System.IO.SearchOption.AllDirectories);
            for (int i = 0; i < files.Length; i++)
            {
                var file = files[i];
                RuntimeDependencies.Add(file);
            }
            var resources = System.IO.Directory.GetFiles(WinThirdPartyResource, "*.*", System.IO.SearchOption.AllDirectories);
            for (int i = 0; i < resources.Length; i++)
            {
                var resource = resources[i];
                RuntimeDependencies.Add(resource);
            }
        }
        else if(Target.Platform == UnrealTargetPlatform.Linux)
        {
            var files = System.IO.Directory.GetFiles(ColorTablePath, "*.*", System.IO.SearchOption.AllDirectories);
            for (int i = 0; i < files.Length; i++)
            {
                var file = files[i];
                RuntimeDependencies.Add(file);
            }
            var resources = System.IO.Directory.GetFiles(LinuxThirdPartyResource, "*.*", System.IO.SearchOption.AllDirectories);
            for (int i = 0; i < resources.Length; i++)
            {
                var resource = resources[i];
                RuntimeDependencies.Add(resource);
            }
        }

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "SuperMap",
                "Core",
                "Projects",
                "Engine",
                "Renderer",
                "RHI",
                "RenderCore",
                "CoreUObject",
                "SlateCore",
                "InputCore",
                "XmlParser",
                "Json",
                "JsonUtilities",
				// ... add other public dependencies that you statically link with here ...
			}
            );
        if(Target.bBuildEditor == true)
        {
            if (Version.MajorVersion == 5)
            {
                PublicDependencyModuleNames.AddRange(
                new string[]{
                    "UnrealEd",
                    "EditorFramework"
                });
            }
            else if (Version.MajorVersion == 4)
            {
                PublicDependencyModuleNames.AddRange(
                new string[]{
                    "UnrealEd"
                });
            }
        }
		if(Target.Platform == UnrealTargetPlatform.Linux)
		{
			ShadowVariableWarningLevel = WarningLevel.Warning;
		}
    }
}
