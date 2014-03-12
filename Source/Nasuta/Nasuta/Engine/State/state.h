#ifndef STATE_H
#define STATE_H

#include "stateIdentifiers.h"

#include "Trambo/Resources/resourceHolder.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>


namespace sf
{
	class RenderWindow;
}

class MusicPlayer;
class Player;
class SoundPlayer;
class StateStack;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context
	{
							Context(sf::RenderWindow& window, trmb::TextureHolder& textures, trmb::FontHolder& fonts,
								Player& player, MusicPlayer& music, SoundPlayer& sounds);

		sf::RenderWindow*		window;
		trmb::TextureHolder*	textures;
		trmb::FontHolder*		fonts;
		Player*					player;
		MusicPlayer*			music;
		SoundPlayer*			sounds;
	};


public:
						State(StateStack& stack, Context context);
	virtual				~State();

	virtual void		draw() = 0;
	virtual bool		update(sf::Time dt) = 0;
	virtual bool		handleEvent(const sf::Event& event) = 0;


protected:
	void				requestStackPush(States::ID stateID);
	void				requestStackPop();
	void				requestStateClear();

	Context				getContext() const;


private:
	StateStack*			mStack;
	Context				mContext;
};

#endif