#ifndef WORLD_H
#define WORLD_H

#include "../SceneNode/aircraft.h"

#include "../../Engine/Command/commandQueue.h"
//#include "../../Engine/Graphics/bloomEffect.h"
#include "../../Engine/SceneNode/sceneNode.h"

#include "Trambo/Resources/resourceHolder.h"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/NonCopyable.hpp>

#include <array>
#include <queue>


namespace sf
{
	class RenderTarget;
	class Time;
}

namespace trmb
{
	class SoundPlayer;
}

class World : private sf::NonCopyable
{
public:
										World(sf::RenderTarget& outputTarget, trmb::FontHolder& fonts,  trmb::SoundPlayer& sounds);

	void								update(sf::Time dt);
	void								draw();

	CommandQueue&						getCommandQueue();

	bool								hasAlivePlayer() const;
	bool								hasPlayerReachedEnd() const;


private:
	void								loadTextures();
	void								adaptPlayerPosition();
	void								adaptPlayerVelocity();
	void								handleCollisions();
	void								updateSounds();

	void								buildScene();
	void								addEnemies();
	void								addEnemy(Aircraft::Type type, float relX, float relY);
	void								spawnEnemies();
	void								destroyEntitiesOutsideView();
	void								guideMissiles();
	sf::FloatRect						getViewBounds() const;
	sf::FloatRect						getBattlefieldBounds() const;


private:
	enum Layer
	{
		Background,
		LowerAir,
		UpperAir,
		LayerCount
	};

	struct SpawnPoint
	{
		SpawnPoint(Aircraft::Type type, float x, float y)
		: type(type)
		, x(x)
		, y(y)
		{
		}

		Aircraft::Type type;
		float x;
		float y;
	};


private:
	sf::RenderTarget&					mTarget;
	sf::RenderTexture					mSceneTexture;
	sf::View							mWorldView;
	trmb::TextureHolder					mTextures;
	trmb::FontHolder&					mFonts;
	trmb::SoundPlayer&					mSounds;
	
	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;
	CommandQueue						mCommandQueue;

	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	float								mScrollSpeed;
	Aircraft*							mPlayerAircraft;

	std::vector<SpawnPoint>				mEnemySpawnPoints;
	std::vector<Aircraft*>				mActiveEnemies;
};

#endif
