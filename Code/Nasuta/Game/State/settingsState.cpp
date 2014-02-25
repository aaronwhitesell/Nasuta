#include "settingsState.h"

#include "../../Engine/utility.h"
#include "../../Engine/Resource/resourceHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>


SettingsState::SettingsState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer(context.window)
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	// Build key binding buttons and labels
	addButtonLabel(Player::MoveLeft,		200.f, "Move Left",  context);
	addButtonLabel(Player::MoveRight,		250.f, "Move Right", context);
	addButtonLabel(Player::MoveUp,			300.f, "Move Up",    context);
	addButtonLabel(Player::MoveDown,		350.f, "Move Down",  context);
	addButtonLabel(Player::Fire,			400.f, "Fire",       context);
	addButtonLabel(Player::LaunchMissile,	450.f, "Missile",    context);

	updateLabels();

	auto backButton = std::make_shared<GUI::Button>(context);
	backButton->setPosition(20.f, 520.f);
	backButton->setText("Back");
	backButton->setCallback(std::bind(&SettingsState::requestStackPop, this));

	mGUIContainer.pack(backButton);
}

void SettingsState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool SettingsState::update(sf::Time)
{
	return true;
}

bool SettingsState::handleEvent(const sf::Event& event)
{
	bool isKeyBinding = false;

	// Iterate through all key binding buttons to see if they are being pressed, waiting for the user to enter a key
	for (std::size_t action = 0; action < Player::ActionCount; ++action)
	{
		if (mBindingButtons[action]->isActive())
		{
			isKeyBinding = true;
			bool isDeactivateButton = false;
			if (Input::isKeyboardEnabled() && event.type == sf::Event::KeyReleased)
			{
				getContext().player->assignKey(static_cast<Player::Action>(action), Input::toKeyboardAndMouse(event.key.code));
				isDeactivateButton = true;
			}
			else if (Input::isMouseEnabled() && event.type == sf::Event::MouseButtonReleased)
			{
				getContext().player->assignKey(static_cast<Player::Action>(action), Input::toKeyboardAndMouse(event.mouseButton.button));
				isDeactivateButton = true;
			}
			else if (Input::isJoystickEnabled())
			{
				// ALW - TODO Joystick
			}

			if (isDeactivateButton)
				mBindingButtons[action]->deactivate();

			break;
		}
	}

	// If pressed button changed key bindings, update labels; otherwise consider other buttons in container
	if (isKeyBinding)
		updateLabels();
	else
		mGUIContainer.handleEvent(event);

	return false;
}

void SettingsState::updateLabels()
{
	Player& player = *getContext().player;

	for (std::size_t i = 0; i < Player::ActionCount; ++i)
	{
		Input::KeyboardAndMouse key = player.getAssignedKey(static_cast<Player::Action>(i));
		mBindingLabels[i]->setText(toString(key));
	}
}

void SettingsState::addButtonLabel(Player::Action action, float y, const std::string& text, Context context)
{
	mBindingButtons[action] = std::make_shared<GUI::Button>(context);
	mBindingButtons[action]->setPosition(20.f, y);
	mBindingButtons[action]->setText(text);
	mBindingButtons[action]->setToggle(true);

	mBindingLabels[action] = std::make_shared<GUI::Label>("", *context.fonts);
	mBindingLabels[action]->setPosition(240.f, y + 15.f);

	mGUIContainer.pack(mBindingButtons[action]);
	mGUIContainer.pack(mBindingLabels[action]);
}
