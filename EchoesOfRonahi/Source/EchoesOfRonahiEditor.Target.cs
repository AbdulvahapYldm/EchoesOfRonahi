// © 2026 Abdulvahap YILDIRIM. All rights reserved. This project and its contents are protected by copyright law.

using UnrealBuildTool;
using System.Collections.Generic;

public class EchoesOfRonahiEditorTarget : TargetRules
{
	public EchoesOfRonahiEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;

        ExtraModuleNames.AddRange( new string[] { "EchoesOfRonahi" } );
	}
}
