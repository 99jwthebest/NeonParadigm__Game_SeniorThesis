// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NeonParadigm_Game : ModuleRules
{
	public NeonParadigm_Game(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "AIModule", "FMODStudio" });
	}
}
