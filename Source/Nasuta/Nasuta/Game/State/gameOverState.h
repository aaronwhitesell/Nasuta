#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include "../../Engine/GUI/container.h"

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

class GameOverState : public trmb::State
{
public:
						GameOverState(trmb::StateStack& stack, trmb::State::Context context);

	virtual void		draw();
	virtual bool		update(sf::Time dt);
	virtual bool		handleEvent(const sf::Event& event);


private:
	sf::Text			mGameOverText;
	sf::Time			mElapsedTime;
};

#endif // BOOK_GAMEOVERSTATE_HPP