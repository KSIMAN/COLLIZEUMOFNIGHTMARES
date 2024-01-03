// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ColiseumOfSouls : ModuleRules
{
	public ColiseumOfSouls(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
