#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H


namespace Textures
{
	enum class ID
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
	enum class ID
	{
		Main,
	};
}

namespace Shaders
{
	enum class ID
	{
		BrightnessPass,
		DownSamplePass,
		GaussianBlurPass,
		AddPass,
	};
}

namespace SoundEffects
{
	enum class ID
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
	enum class ID
	{
		MenuTheme,
		MissionTheme,
	};
}

#endif
