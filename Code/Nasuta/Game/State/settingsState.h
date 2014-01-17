#ifndef SETTINGS_STATE_H
#define SETTINGS_STATE_H

#include "../player.h"

#include "../../Engine/GUI/button.h"
#include "../../Engine/GUI/container.h"
#include "../../Engine/GUI/label.h"
#include "../../Engine/State/state.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>


class SettingsState : public State
{
public:
							SettingsState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);


private:
	void					updateLabels();
	void					addButtonLabel(Player::Action action, float y, const std::string& text, Context context);


private:
	sf::Sprite											mBackgroundSprite;
	GUI::Container										mGUIContainer;
	std::array<GUI::Button::Ptr, Player::ActionCount>	mBindingButtons;
	std::array<GUI::Label::Ptr, Player::ActionCount>	mBindingLabels;
};

#endif
