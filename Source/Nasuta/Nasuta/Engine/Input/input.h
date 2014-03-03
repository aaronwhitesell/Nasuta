#ifndef INPUT_H
#define INPUT_H

#include <SFML/Window/Event.hpp>


class Input
{
public:
	static bool isKeyboardEnabled() {return KeyboardEnabled;}
	static bool isMouseEnabled()    {return MouseEnabled;}
	static bool isJoystickEnabled() {return JoystickEnabled;}
	

private:
	static bool KeyboardEnabled;
	static bool MouseEnabled;
	static bool JoystickEnabled;
};

#endif
