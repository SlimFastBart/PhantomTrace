// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PhantomTrace : ModuleRules
{
	public PhantomTrace(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] { "PhantomTrace/Public" });
		PrivateIncludePaths.AddRange(new string[] { "PhantomTrace/Private" });

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayTags" });
	}
}
