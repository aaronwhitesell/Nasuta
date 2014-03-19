#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H


namespace Textures
{
	enum ID : unsigned int
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
	enum ID : unsigned int
	{
		Main,
	};
}

namespace Shaders
{
	enum ID : unsigned int
	{
		BrightnessPass,
		DownSamplePass,
		GaussianBlurPass,
		AddPass,
	};
}

namespace SoundEffect
{
	enum ID : unsigned int
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
	enum ID : unsigned int
	{
		MenuTheme,
		MissionTheme,
	};
}

#endif
