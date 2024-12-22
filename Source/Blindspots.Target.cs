// Copyright Y.M. Bilge

using UnrealBuildTool;
using System.Collections.Generic;

public class BlindspotsTarget : TargetRules
{
	public BlindspotsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Blindspots" } );
	}
}
