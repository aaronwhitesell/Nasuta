#ifndef PLAYER_H
#define PLAYER_H

#include "../Engine/Command/command.h"
#include "../Engine/Input/input.h"

#include <SFML/Window/Event.hpp>

#include <map>


class CommandQueue;

class Player
{
public:
	enum Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		Fire,
		LaunchMissile,
		ActionCount
	};

	enum MissionStatus
	{
		MissionRunning,
		MissionSuccess,
		MissionFailure
	};


public:
							Player();

	void					handleEvent(const sf::Event& event, CommandQueue& commands);
	void					handleRealtimeInput(CommandQueue& commands);

	void					assignKey(Action action, Input::KeyboardAndMouse key);
	Input::KeyboardAndMouse getAssignedKey(Action action) const;

	void					setMissionStatus(MissionStatus status);
	MissionStatus			getMissionStatus() const;


private:
	void					initializeActions();
	static bool				isRealtimeAction(Action action);


private:
	std::map<Input::KeyboardAndMouse, Action> mKeyBinding;
	std::map<Action, Command>				  mActionBinding;
	MissionStatus							  mCurrentMissionStatus;
};

#endif
