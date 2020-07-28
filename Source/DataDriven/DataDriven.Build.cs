// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DataDriven : ModuleRules
{
	public DataDriven(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","UMG","Json", "SQLiteSupport" });


		PublicIncludePaths.AddRange(
			 new string[] {
				// ... add public include paths required here ...
				ModuleDirectory,
			 }
			 );
	}
}
