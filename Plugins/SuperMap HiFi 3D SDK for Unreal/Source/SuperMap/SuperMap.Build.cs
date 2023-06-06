// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class SuperMap : ModuleRules
{
    private string ModulePath
    {
        get
        {
            return ModuleDirectory;
        }
    }
    private string DLLPath
    {
        get
        {
            return Path.GetFullPath(Path.Combine(ModulePath, "../../Source/ThirdParty/SuperMapLibrary/Win64/"));
        }
    }

	private string SoPath
	{
		get
		{
			return Path.GetFullPath(Path.Combine(ModulePath, "../../Source/ThirdParty/SuperMapLibrary/Linux_x86_64/"));
		}
	}
	
    public SuperMap(ReadOnlyTargetRules Target) : base(Target)
	{
		ReadOnlyBuildVersion Version = ReadOnlyBuildVersion.Current;
		if(Version.MajorVersion == 5)
        {
            PublicDefinitions.Add("SM_FOR_UE_FIVE= 1");
		}
		else if(Version.MajorVersion == 4)
        {
			PublicDefinitions.Add("SM_FOR_UE_FIVE = 0");
		}

        if (Version.MajorVersion == 5 && Version.MinorVersion == 1)
        {
            PublicDefinitions.Add("SM_FOR_UE_FIVE_1= 1");
        }
        else
        {
            PublicDefinitions.Add("SM_FOR_UE_FIVE_1= 0");
        }


        if (Version.MinorVersion == 25)
        {
            PublicDefinitions.Add("SM_FOR_UE_25 = 1");
        }
        else
        {
            PublicDefinitions.Add("SM_FOR_UE_25 = 0");
        }

        if (Version.MinorVersion == 26)
        {
            PublicDefinitions.Add("SM_FOR_UE_26 = 1");
        }
        else
        {
            PublicDefinitions.Add("SM_FOR_UE_26 = 0");
        }

        // 需要调试时打开
        //PublicDefinitions.Add("SUPERMAP_DEVELOPER_DEBUG = 1");

        // 使用自定义顶点时打开
        //PublicDefinitions.Add("SUPERMAP_USE_LOCAL_VERTEX_FACTORY = 1");

        // STAT 性能埋点分析 默认关闭
        PublicDefinitions.Add("SM_ENABLE_STATS = 0");
    
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        string strPath = EngineDirectory + "/Shaders/Shared";

        // Windows
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            var files = System.IO.Directory.GetFiles(DLLPath, "*.*", System.IO.SearchOption.AllDirectories);
            for (int i = 0; i < files.Length; i++)
            {
                var file = files[i];
                RuntimeDependencies.Add(file);
            }
        }
		//linux
		else if (Target.Platform == UnrealTargetPlatform.Linux) 
		{
			var files = System.IO.Directory.GetFiles(SoPath, "*.*", System.IO.SearchOption.AllDirectories);
			for (int i = 0; i < files.Length; i++)
			{
				var file = files[i];
				RuntimeDependencies.Add(file);
			}
		}
		
        PublicIncludePaths.AddRange(
			new string[] {
                strPath
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Projects",
				"Engine",
				"ProceduralMeshComponent",
				"Renderer",
				"RHI",
				"RenderCore",
				"CoreUObject",
                "SlateCore",
                "XmlParser",
				"MESHDESCRIPTION",
				"STATICMESHDESCRIPTION",
                "MikkTSpace",
                "Json",
                "JsonUtilities",
                "Http",
                // ... add other public dependencies that you statically link with here ...
			}
			);
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Json",
                "JsonUtilities",
                "Http"
            }
            );
        if (Target.bBuildEditor == true)
        {
            PublicDependencyModuleNames.AddRange(
                new string[]{
                    "UnrealEd",
                    "MaterialEditor",
                    "MeshMergeUtilities",
                    "MtlAnalyzer",
                    "MtlBaking",
            });

            PublicDefinitions.Add("BUILD_EDITOR = 1");
        }

        PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);

		if (Target.bCompilePhysX && !Target.bUseChaos)
		{
			PrivateDependencyModuleNames.Add("PhysXCooking");
			PrivateDependencyModuleNames.Add("PhysicsCore");
		}
		else
		{
			PrivateDependencyModuleNames.Add("Chaos");
		}


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
					
		if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            ShadowVariableWarningLevel = WarningLevel.Warning;
        }
	}
}
