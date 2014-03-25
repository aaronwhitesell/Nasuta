#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include "Trambo/GUI/container.h"
#include "Trambo/States/state.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


namespace sf
{
	class Event;
	class Time;
}

namespace trmb
{
	class StateStack;
}

class PauseState : public trmb::State
{
public:
						PauseState(trmb::StateStack& stack, trmb::State::Context context);
						~PauseState();

	virtual void		draw();
	virtual bool		update(sf::Time dt);
	virtual bool		handleEvent(const sf::Event& event);


private:
	sf::Sprite			mBackgroundSprite;
	sf::Text			mPausedText;
	trmb::Container		mGUIContainer;
};

#endif
