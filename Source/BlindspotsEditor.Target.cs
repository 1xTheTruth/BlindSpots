// Copyright Y.M. Bilge

using UnrealBuildTool;
using System.Collections.Generic;

public class BlindspotsEditorTarget : TargetRules
{
	public BlindspotsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Blindspots" } );
	}
}
