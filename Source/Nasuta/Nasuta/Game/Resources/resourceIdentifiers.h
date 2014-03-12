#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H


namespace Textures
{
	enum ID
	{
		Entities,
		Grass,
		TitleScreen,
		Buttons,
		Explosion,
		Particle,
		FinishLine,
		TestGrass,
		TestTree,
	};
}

namespace Fonts
{
	enum ID
	{
		Main,
	};
}

namespace Shaders
{
	enum ID
	{
		BrightnessPass,
		DownSamplePass,
		GaussianBlurPass,
		AddPass,
	};
}

namespace SoundEffect
{
	enum ID
	{
		AlliedGunfire,
		EnemyGunfire,
		Explosion1,
		Explosion2,
		LaunchMissile,
		CollectPickup,
		Button,
	};
}

namespace Music
{
	enum ID
	{
		MenuTheme,
		MissionTheme,
	};
}

#endif
