#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

#include "../../Engine/GUI/container.h"
#include "../../Engine/State/state.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class PauseState : public State
{
public:
						PauseState(StateStack& stack, Context context);
						~PauseState();

	virtual void		draw();
	virtual bool		update(sf::Time dt);
	virtual bool		handleEvent(const sf::Event& event);


private:
	sf::Sprite			mBackgroundSprite;
	sf::Text			mPausedText;
	GUI::Container		mGUIContainer;
};

#endif
