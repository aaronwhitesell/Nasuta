#include "settingsState.h"
#include "../Resources/resourceIdentifiers.h"

#include "../../Engine/utility.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


SettingsState::SettingsState(trmb::StateStack& stack, trmb::State::Context context)
: State(stack, context)
, mGUIContainer(context.window)
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	// Build key binding buttons and labels
	addButtonAndLabel(Player::MoveLeft,		 200.f, "Move Left",  context);
	addButtonAndLabel(Player::MoveRight,	 250.f, "Move Right", context);
	addButtonAndLabel(Player::MoveUp,		 300.f, "Move Up",    context);
	addButtonAndLabel(Player::MoveDown,		 350.f, "Move Down",  context);
	addButtonAndLabel(Player::Fire,			 400.f, "Fire",       context);
	addButtonAndLabel(Player::LaunchMissile, 450.f, "Missile",    context);

	updateLabels();

	auto backButton = std::make_shared<GUI::Button>(context, 200, 50);
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
	bool isUpdateLabel = false;

	// Iterate through all key binding buttons to see if they are being pressed, waiting for the user to enter a key
	for (std::size_t action = 0; action < Player::ActionCount; ++action)
	{
		if (mBindingButtons[action]->isActive())
		{
			isKeyBinding = true;
			bool isDeactivateButton = false;
			if (Input::isKeyboardEnabled() && event.type == sf::Event::KeyReleased)
			{
				getContext().player->assignKeyboardKey(static_cast<Player::Action>(action), event.key.code);
				isUpdateLabel = true;
				isDeactivateButton = true;
			}
			else if (Input::isMouseEnabled() && event.type == sf::Event::MouseButtonReleased)
			{
				getContext().player->assignMouseButton(static_cast<Player::Action>(action), event.mouseButton.button);
				isUpdateLabel = true;
				isDeactivateButton = true;
			}

			// ALW - TODO - Joystick binding

			if (isDeactivateButton)
			{
				mBindingButtons[action]->deactivate();
				// ALW - Hack - Fake a MouseMoved event to force an update. The cursor may be over a button, but hasn't moved.
				sf::Event event;
				event.type = sf::Event::EventType::MouseMoved;
				mGUIContainer.handleEvent(event);
			}

			break;
		}
	}

	// If pressed button changed key bindings, update labels; otherwise consider other buttons in container
	if (isUpdateLabel)
		updateLabels();
	else if (!isKeyBinding)
		mGUIContainer.handleEvent(event);
//	else if (isKeyBinding && !isUpdateLabel)
//		doNothing;

	return false;
}

void SettingsState::updateLabels()
{
	Player& player = *getContext().player;

	typedef std::pair<bool, sf::Keyboard::Key> KeyboardKeyBindState;
	std::vector<KeyboardKeyBindState> keyboardBindState(Player::ActionCount, KeyboardKeyBindState(false, sf::Keyboard::Key::Unknown));

	typedef std::pair<bool, sf::Mouse::Button> MouseButtonBindState;
	std::vector<MouseButtonBindState> mouseBindState(Player::ActionCount, MouseButtonBindState(false, sf::Mouse::ButtonCount));

	if (Input::isKeyboardEnabled())
	{
		for (std::size_t i = 0; i < Player::ActionCount; ++i)
		{
			sf::Keyboard::Key key = player.getAssignedKeyboardKey(static_cast<Player::Action>(i));
			if (key == sf::Keyboard::Key::Unknown)
				keyboardBindState[i] = KeyboardKeyBindState(false, sf::Keyboard::Key::Unknown);
			else
				keyboardBindState[i] = KeyboardKeyBindState(true, key);
		}
	}

	if (Input::isMouseEnabled())
	{
		for (std::size_t i = 0; i < Player::ActionCount; ++i)
		{
			sf::Mouse::Button button = player.getAssignedMouseButton(static_cast<Player::Action>(i));
			if (button == sf::Mouse::Button::ButtonCount)
				mouseBindState[i] = MouseButtonBindState(false, sf::Mouse::Button::ButtonCount);
			else
				mouseBindState[i] = MouseButtonBindState(true, button);
		}
	}

	// ALW - TODO - Joystick binding

	for (std::size_t i = 0; i < Player::ActionCount; ++i)
	{
		if (keyboardBindState[i].first && !mouseBindState[i].first)
			mBindingLabels[i]->setText(toString(keyboardBindState[i].second));
		else if (!keyboardBindState[i].first && mouseBindState[i].first)
			mBindingLabels[i]->setText(toString(mouseBindState[i].second));
		else if (!keyboardBindState[i].first && !mouseBindState[i].first)
			mBindingLabels[i]->setText("Unbound");
		else
			assert(false);

	}
}

void SettingsState::addButtonAndLabel(Player::Action action, float y, const std::string& text, trmb::State::Context context)
{
	mBindingButtons[action] = std::make_shared<GUI::Button>(context, 200, 50);
	mBindingButtons[action]->setPosition(20.f, y);
	mBindingButtons[action]->setText(text);
	mBindingButtons[action]->setToggle(true);

	mBindingLabels[action] = std::make_shared<GUI::Label>("", *context.fonts);
	mBindingLabels[action]->setPosition(240.f, y + 15.f);

	mGUIContainer.pack(mBindingButtons[action]);
	mGUIContainer.pack(mBindingLabels[action]);
}
