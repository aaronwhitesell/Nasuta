#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include "../../Engine/GUI/container.h"
#include "../../Engine/State/state.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class GameOverState : public State
{
public:
						GameOverState(StateStack& stack, Context context);

	virtual void		draw();
	virtual bool		update(sf::Time dt);
	virtual bool		handleEvent(const sf::Event& event);


private:
	sf::Text			mGameOverText;
	sf::Time			mElapsedTime;
};

#endif // BOOK_GAMEOVERSTATE_HPP