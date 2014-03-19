#include "pauseState.h"
#include "stateIdentifiers.h"
#include "../Resources/resourceIdentifiers.h"

#include "../../Engine/utility.h"
#include "../../Engine/GUI/button.h"
#include "../../Engine/Sound/musicPlayer.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>


PauseState::PauseState(trmb::StateStack& stack, trmb::State::Context context)
: trmb::State(stack, context)
, mBackgroundSprite()
, mPausedText()
, mGUIContainer(context.window)
{
	sf::Font& font = context.fonts->get(Fonts::Main);
	sf::Vector2f windowSize(context.window->getSize());

	mPausedText.setFont(font);
	mPausedText.setString("Game Paused");
	mPausedText.setCharacterSize(70);
	centerOrigin(mPausedText);
	mPausedText.setPosition(0.5f * windowSize.x, 0.4f * windowSize.y);

	auto returnButton = std::make_shared<GUI::Button>(context, 200, 50);
	returnButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 75);
	returnButton->setText("Return");
	returnButton->setCallback([this] ()
	{
		requestStackPop();
	});

	auto backToMenuButton = std::make_shared<GUI::Button>(context, 200, 50);
	backToMenuButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 125);
	backToMenuButton->setText("Back to menu");
	backToMenuButton->setCallback([this] ()
	{
		requestStateClear();
		requestStackPush(States::Menu);
	});

	mGUIContainer.pack(returnButton);
	mGUIContainer.pack(backToMenuButton);

	getContext().music->setPaused(true);
}

PauseState::~PauseState()
{
	getContext().music->setPaused(false);
}

void PauseState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);
	window.draw(mPausedText);
	window.draw(mGUIContainer);
}

bool PauseState::update(sf::Time)
{
	return false;
}

bool PauseState::handleEvent(const sf::Event& event)
{
	mGUIContainer.handleEvent(event);
	return false;
}
