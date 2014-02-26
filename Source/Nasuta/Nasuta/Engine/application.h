#ifndef APPLICATION_H
#define APPLICATION_H

#include "Resource/resourceHolder.h"
#include "Resource/resourceIdentifiers.h"
#include "Sound/musicPlayer.h"
#include "Sound/soundPlayer.h"
#include "State/stateStack.h"

#include "../Game/player.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>


class Application
{
public:
							Application();
	void					run();


private:
	void					processInput();
	void					update(sf::Time dt);
	void					render();

	void					updateStatistics(sf::Time dt);
	void					registerStates();


private:
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	TextureHolder			mTextures;
	FontHolder				mFonts;
	Player					mPlayer;

	MusicPlayer				mMusic;
	SoundPlayer				mSounds;
	StateStack				mStateStack;

	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	std::size_t				mStatisticsNumFrames;
};

#endif
