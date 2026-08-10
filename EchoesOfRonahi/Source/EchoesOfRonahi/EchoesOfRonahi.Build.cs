// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.

using UnrealBuildTool;

public class EchoesOfRonahi : ModuleRules
{
	public EchoesOfRonahi(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject",
			"Engine", 
			"InputCore",
            "EnhancedInput",
			"UMG",
            "CommonInput",
            "GameplayTags",
            "GameplayAbilities",
            "GameplayTasks",


        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[]
		{ 
			"Slate",
			"SlateCore",
			"AnimGraphRuntime",

        });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
