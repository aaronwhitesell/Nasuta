#include "player.h"
#include "SceneNode/aircraft.h"

#include "../Engine/Command/commandQueue.h"

#include <algorithm>
#include <map>
#include <string>

using namespace std::placeholders;


struct AircraftMover
{
	AircraftMover(float vx, float vy)
	: velocity(vx, vy)
	{
	}

	void operator() (Aircraft& aircraft, sf::Time) const
	{
		aircraft.accelerate(velocity * aircraft.getMaxSpeed());
	}

	sf::Vector2f velocity;
};

Player::Player()
: mCurrentMissionStatus(MissionRunning)
{
	// Set initial key bindings
	mKeyBinding[Input::KeyboardAndMouse::A] = MoveLeft;
	mKeyBinding[Input::KeyboardAndMouse::D] = MoveRight;
	mKeyBinding[Input::KeyboardAndMouse::W] = MoveUp;
	mKeyBinding[Input::KeyboardAndMouse::S] = MoveDown;
	mKeyBinding[Input::KeyboardAndMouse::LeftMouse] = Fire;
	mKeyBinding[Input::KeyboardAndMouse::RightMouse] = LaunchMissile;

	// Set initial action bindings
	initializeActions();

	// Assign all categories to player's aircraft
	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	std::map<Input::KeyboardAndMouse, Action>::const_iterator found = mKeyBinding.end();

	if (Input::isKeyboardEnabled() && event.type == sf::Event::KeyPressed)
		found = mKeyBinding.find(Input::toKeyboardAndMouse(event.key.code));
	else if (Input::isMouseEnabled() && event.type == sf::Event::MouseButtonPressed)
		found = mKeyBinding.find(Input::toKeyboardAndMouse(event.mouseButton.button));
	else if (Input::isJoystickEnabled())
	{
		// ALW - TODO Joystick
	}

	// ALW - If pressed key appears in key binding and is real time action then trigger command
	if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
		commands.push(mActionBinding[found->second]);
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	// Traverse all assigned keys and check if they are pressed
	for (auto pair : mKeyBinding)
	{
		bool isKeyPressed = false;
		if (Input::isKeyboardEnabled() && Input::isKeyboard(pair.first))
		{
			// If key is pressed, lookup action and trigger corresponding command
			if (sf::Keyboard::isKeyPressed(Input::toKeyboard(pair.first)) && isRealtimeAction(pair.second))
				isKeyPressed = true;
		}
		else if (Input::isMouseEnabled() && Input::isMouse(pair.first))
		{
			if (sf::Mouse::isButtonPressed(Input::toMouse(pair.first)) && isRealtimeAction(pair.second))
				isKeyPressed = true;
		}
		else if (Input::isJoystickEnabled())
		{
			// ALW - TODO Joystick
		}

		if (isKeyPressed)
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, Input::KeyboardAndMouse key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}
	
Input::KeyboardAndMouse Player::getAssignedKey(Action action) const
{
	for (auto pair : mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return Input::KeyboardAndMouse::Unknown;
}

void Player::setMissionStatus(MissionStatus status)
{
	mCurrentMissionStatus = status;
}

Player::MissionStatus Player::getMissionStatus() const
{
	return mCurrentMissionStatus;
}

void Player::initializeActions()
{
	mActionBinding[MoveLeft].action		 = derivedAction<Aircraft>(AircraftMover(-1, 0.f));
	mActionBinding[MoveRight].action	 = derivedAction<Aircraft>(AircraftMover(+1, 0.f));
	mActionBinding[MoveUp].action		 = derivedAction<Aircraft>(AircraftMover(0.f, -1));
	mActionBinding[MoveDown].action		 = derivedAction<Aircraft>(AircraftMover(0.f, +1));
	mActionBinding[Fire].action			 = derivedAction<Aircraft>([] (Aircraft& a, sf::Time){ a.fire(); });
	mActionBinding[LaunchMissile].action = derivedAction<Aircraft>([] (Aircraft& a, sf::Time){ a.launchMissile(); });
}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
		case MoveLeft:
		case MoveRight:
		case MoveDown:
		case MoveUp:
		case Fire:
			return true;

	default:
		return false;
	}
}
