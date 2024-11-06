// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Rookiss : ModuleRules
{
	public Rookiss(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		//R1폴더를 기준으로 다시 찾기
		//추가적으로 찾을 경로를 미리 설정해둠
        PublicIncludePaths.AddRange(new string[]
		{
			"Rookiss"
		});

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" ,"EnhancedInput"  });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
