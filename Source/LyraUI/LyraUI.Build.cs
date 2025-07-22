// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LyraUI : ModuleRules
{
	public LyraUI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
		{
            "Core",
            "CoreOnline",
            "CoreUObject",
            "ApplicationCore",
            "Engine",
            "PhysicsCore",
            "GameplayTags",
            "GameplayTasks",
            "DataRegistry",
            "ControlFlows",
            "PropertyPath",
            "ModularGameplay",
            "ModularGameplayActors",
            "UIExtension",
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "RHI",
            "UMG",
            "Slate",
            "SlateCore",
            "AsyncMixin",
            "InputCore",
            "RenderCore",
            "DeveloperSettings",
            "EnhancedInput",
            "Projects",
            "CommonGame",
            "CommonUser",
            "CommonUI",
            "CommonInput",
            "CommonLoadingScreen",
            "GameplayMessageRuntime",
            "GameSettings",
            "GameSubtitles",
            "EngineSettings",
            "AudioModulation",
            "AudioMixer",
            "Json",
        });

    }
}
