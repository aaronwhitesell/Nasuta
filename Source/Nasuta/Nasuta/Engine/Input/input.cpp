#include "input.h"

#include <cassert>


bool Input::KeyboardEnabled = true;
bool Input::MouseEnabled = true;
bool Input::JoystickEnabled = false;

const int Input::LowerKeyboardBound = -1;
const int Input::UpperKeyboardBound = 100;
const int Input::LowerMouseBound = 101;
const int Input::UpperMouseBound = 105;

bool Input::isKeyboard(KeyboardAndMouse key)
{
	if (LowerKeyboardBound <= key && key <= UpperKeyboardBound)
		return true;
	else
		return false;
}

bool Input::isMouse(KeyboardAndMouse key)
{
	if (LowerMouseBound <= key && key <= UpperMouseBound)
		return true;
	else
		return false;
}

Input::KeyboardAndMouse Input::toKeyboardAndMouse(sf::Mouse::Button button)
{
	switch (button)
	{
		case sf::Mouse::Left:
			return KeyboardAndMouse::LeftMouse;     ///< The left mouse button
		case sf::Mouse::Right:
			return KeyboardAndMouse::RightMouse;    ///< The right mouse button
		case sf::Mouse::Middle:
			return KeyboardAndMouse::MiddleMouse;   ///< The middle (wheel) mouse button
		case sf::Mouse::XButton1:
			return KeyboardAndMouse::XButton1Mouse; ///< The first extra mouse button
		case sf::Mouse::XButton2:
			return KeyboardAndMouse::XButton2Mouse; ///< The second extra mouse button
		default:
			assert(false);
			return KeyboardAndMouse::LeftMouse;     ///< The left mouse button
	}
}

Input::KeyboardAndMouse Input::toKeyboardAndMouse(sf::Keyboard::Key code)
{
	switch (code)
	{
		case sf::Keyboard::A:
			return KeyboardAndMouse::A;         ///< The A key
		case sf::Keyboard::B:
			return KeyboardAndMouse::B;         ///< The B key
		case sf::Keyboard::C:
			return KeyboardAndMouse::C;         ///< The C key
		case sf::Keyboard::D:
			return KeyboardAndMouse::D;         ///< The D key
		case sf::Keyboard::E:
			return KeyboardAndMouse::E;         ///< The E key
		case sf::Keyboard::F:
			return KeyboardAndMouse::F;         ///< The F key
		case sf::Keyboard::G:
			return KeyboardAndMouse::G;         ///< The G key
		case sf::Keyboard::H:
			return KeyboardAndMouse::H;         ///< The H key
		case sf::Keyboard::I:
			return KeyboardAndMouse::I;         ///< The I key
		case sf::Keyboard::J:
			return KeyboardAndMouse::J;         ///< The J key
		case sf::Keyboard::K:
			return KeyboardAndMouse::K;         ///< The K key
		case sf::Keyboard::L:
			return KeyboardAndMouse::L;         ///< The L key
		case sf::Keyboard::M:
			return KeyboardAndMouse::M;         ///< The M key
		case sf::Keyboard::N:
			return KeyboardAndMouse::N;         ///< The N key
		case sf::Keyboard::O:
			return KeyboardAndMouse::O;         ///< The O key
		case sf::Keyboard::P:
			return KeyboardAndMouse::P;         ///< The P key
		case sf::Keyboard::Q:
			return KeyboardAndMouse::Q;         ///< The Q key
		case sf::Keyboard::R:
			return KeyboardAndMouse::R;         ///< The R key
		case sf::Keyboard::S:
			return KeyboardAndMouse::S;         ///< The S key
		case sf::Keyboard::T:
			return KeyboardAndMouse::T;         ///< The T key
		case sf::Keyboard::U:
			return KeyboardAndMouse::U;         ///< The U key
		case sf::Keyboard::V:
			return KeyboardAndMouse::V;         ///< The V key
		case sf::Keyboard::W:
			return KeyboardAndMouse::W;         ///< The W key
		case sf::Keyboard::X:
			return KeyboardAndMouse::X;         ///< The X key
		case sf::Keyboard::Y:
			return KeyboardAndMouse::Y;         ///< The Y key
		case sf::Keyboard::Z:
			return KeyboardAndMouse::Z;         ///< The Z key
		case sf::Keyboard::Num0:
			return KeyboardAndMouse::Num0;      ///< The 0 key
		case sf::Keyboard::Num1:
			return KeyboardAndMouse::Num1;      ///< The 1 key
		case sf::Keyboard::Num2:
			return KeyboardAndMouse::Num2;      ///< The 2 key
		case sf::Keyboard::Num3:
			return KeyboardAndMouse::Num3;      ///< The 3 key
		case sf::Keyboard::Num4:
			return KeyboardAndMouse::Num4;      ///< The 4 key
		case sf::Keyboard::Num5:
			return KeyboardAndMouse::Num5;      ///< The 5 key
		case sf::Keyboard::Num6:
			return KeyboardAndMouse::Num6;      ///< The 6 key
		case sf::Keyboard::Num7:
			return KeyboardAndMouse::Num7;      ///< The 7 key
		case sf::Keyboard::Num8:
			return KeyboardAndMouse::Num8;      ///< The 8 key
		case sf::Keyboard::Num9:
			return KeyboardAndMouse::Num9;      ///< The 9 key
		case sf::Keyboard::Escape:
			return KeyboardAndMouse::Escape;    ///< The Escape key
		case sf::Keyboard::LControl:
			return KeyboardAndMouse::LControl;  ///< The LControl key
		case sf::Keyboard::LShift:
			return KeyboardAndMouse::LShift;    ///< The LShift key
		case sf::Keyboard::LAlt:
			return KeyboardAndMouse::LAlt;      ///< The LAlt key
		case sf::Keyboard::LSystem:
			return KeyboardAndMouse::LSystem;   ///< The LSystem key
		case sf::Keyboard::RControl:
			return KeyboardAndMouse::RControl;  ///< The RControl key
		case sf::Keyboard::RShift:
			return KeyboardAndMouse::RShift;    ///< The RShift key
		case sf::Keyboard::RAlt:
			return KeyboardAndMouse::RAlt;      ///< The RAlt key
		case sf::Keyboard::RSystem:
			return KeyboardAndMouse::RSystem;   ///< The RSystem key
		case sf::Keyboard::Menu:
			return KeyboardAndMouse::Menu;      ///< The Menu key
		case sf::Keyboard::LBracket:
			return KeyboardAndMouse::LBracket;  ///< The LBracket key
		case sf::Keyboard::RBracket:
			return KeyboardAndMouse::RBracket;  ///< The RBracket key
		case sf::Keyboard::SemiColon:
			return KeyboardAndMouse::SemiColon; ///< The SemiColon key
		case sf::Keyboard::Comma:
			return KeyboardAndMouse::Comma;     ///< The Comma key
		case sf::Keyboard::Period:
			return KeyboardAndMouse::Period;    ///< The Period key
		case sf::Keyboard::Quote:
			return KeyboardAndMouse::Quote;     ///< The Quote key
		case sf::Keyboard::Slash:
			return KeyboardAndMouse::Slash;     ///< The Slash key
		case sf::Keyboard::BackSlash:
			return KeyboardAndMouse::BackSlash; ///< The BackSlash key
		case sf::Keyboard::Tilde:
			return KeyboardAndMouse::Tilde;     ///< The Tilde key
		case sf::Keyboard::Equal:
			return KeyboardAndMouse::Equal;     ///< The Equal key
		case sf::Keyboard::Dash:
			return KeyboardAndMouse::Dash;      ///< The Dash key
		case sf::Keyboard::Space:
			return KeyboardAndMouse::Space;     ///< The Space key
		case sf::Keyboard::Return:
			return KeyboardAndMouse::Return;    ///< The Return key
		case sf::Keyboard::BackSpace:
			return KeyboardAndMouse::BackSpace; ///< The BackSpace key
		case sf::Keyboard::Tab:
			return KeyboardAndMouse::Tab;       ///< The Tab key
		case sf::Keyboard::PageUp:
			return KeyboardAndMouse::PageUp;    ///< The PageUp key
		case sf::Keyboard::PageDown:
			return KeyboardAndMouse::PageDown;  ///< The PageDown key
		case sf::Keyboard::End:
			return KeyboardAndMouse::End;       ///< The End key
		case sf::Keyboard::Home:
			return KeyboardAndMouse::Home;      ///< The Home key
		case sf::Keyboard::Insert:
			return KeyboardAndMouse::Insert;    ///< The Insert key
		case sf::Keyboard::Delete:
			return KeyboardAndMouse::Delete;    ///< The Delete key
		case sf::Keyboard::Add:
			return KeyboardAndMouse::Add;       ///< The Add key
		case sf::Keyboard::Subtract:
			return KeyboardAndMouse::Subtract;  ///< The Subtract key
		case sf::Keyboard::Multiply:
			return KeyboardAndMouse::Multiply;  ///< The Multiply key
		case sf::Keyboard::Divide:
			return KeyboardAndMouse::Divide;    ///< The Divide key
		case sf::Keyboard::Left:
			return KeyboardAndMouse::Left;      ///< The Left key
		case sf::Keyboard::Right:
			return KeyboardAndMouse::Right;     ///< The Right key
		case sf::Keyboard::Up:
			return KeyboardAndMouse::Up;        ///< The Up key
		case sf::Keyboard::Down:
			return KeyboardAndMouse::Down;      ///< The Down key
		case sf::Keyboard::Numpad0:
			return KeyboardAndMouse::Numpad0;   ///< The numpad 0 key
		case sf::Keyboard::Numpad1:
			return KeyboardAndMouse::Numpad1;   ///< The numpad 1 key
		case sf::Keyboard::Numpad2:
			return KeyboardAndMouse::Numpad2;   ///< The numpad 2 key
		case sf::Keyboard::Numpad3:
			return KeyboardAndMouse::Numpad3;   ///< The numpad 3 key
		case sf::Keyboard::Numpad4:
			return KeyboardAndMouse::Numpad4;   ///< The numpad 4 key
		case sf::Keyboard::Numpad5:
			return KeyboardAndMouse::Numpad5;   ///< The numpad 5 key
		case sf::Keyboard::Numpad6:
			return KeyboardAndMouse::Numpad6;   ///< The numpad 6 key
		case sf::Keyboard::Numpad7:
			return KeyboardAndMouse::Numpad7;   ///< The numpad 7 key
		case sf::Keyboard::Numpad8:
			return KeyboardAndMouse::Numpad8;   ///< The numpad 8 key
		case sf::Keyboard::Numpad9:
			return KeyboardAndMouse::Numpad9;   ///< The numpad 9 key
		case sf::Keyboard::F1:
			return KeyboardAndMouse::F1;        ///< The F1 key
		case sf::Keyboard::F2:
			return KeyboardAndMouse::F2;        ///< The F2 key
		case sf::Keyboard::F3:
			return KeyboardAndMouse::F3;        ///< The F3 key
		case sf::Keyboard::F4:
			return KeyboardAndMouse::F4;        ///< The F4 key
		case sf::Keyboard::F5:
			return KeyboardAndMouse::F5;        ///< The F5 key
		case sf::Keyboard::F6:
			return KeyboardAndMouse::F6;        ///< The F6 key
		case sf::Keyboard::F7:
			return KeyboardAndMouse::F7;        ///< The F7 key
		case sf::Keyboard::F8:
			return KeyboardAndMouse::F8;        ///< The F8 key
		case sf::Keyboard::F9:
			return KeyboardAndMouse::F9;        ///< The F9 key
		case sf::Keyboard::F10:
			return KeyboardAndMouse::F10;       ///< The F10 key
		case sf::Keyboard::F11:
			return KeyboardAndMouse::F11;       ///< The F11 key
		case sf::Keyboard::F12:
			return KeyboardAndMouse::F12;       ///< The F12 key
		case sf::Keyboard::F13:
			return KeyboardAndMouse::F13;       ///< The F13 key
		case sf::Keyboard::F14:
			return KeyboardAndMouse::F14;       ///< The F14 key
		case sf::Keyboard::F15:
			return KeyboardAndMouse::F15;       ///< TheF15 key
		case sf::Keyboard::Pause:
			return KeyboardAndMouse::Pause;     ///< The Pause key
		default:
			return KeyboardAndMouse::Unknown;   ///< Unhandled key
	}
}

sf::Mouse::Button Input::toMouse(KeyboardAndMouse keyboardAndMouse)
{
	switch (keyboardAndMouse)
	{
		case KeyboardAndMouse::LeftMouse:
			return sf::Mouse::Left;			  ///< The left mouse button
		case KeyboardAndMouse::RightMouse:
			return sf::Mouse::Right;          ///< The right mouse button
		case KeyboardAndMouse::MiddleMouse: 
			return sf::Mouse::Middle;         ///< The middle (wheel) mouse button
		case KeyboardAndMouse::XButton1Mouse:
			return sf::Mouse::XButton1;       ///< The first extra mouse button
		case KeyboardAndMouse::XButton2Mouse:
			return sf::Mouse::XButton2;       ///< The second extra mouse button
		default:
			assert(false);
			return sf::Mouse::Left;			  ///< The left mouse button
	}
}

sf::Keyboard::Key Input::toKeyboard(KeyboardAndMouse keyboardAndMouse)
{
	switch (keyboardAndMouse)
	{
		case KeyboardAndMouse::A:
			return sf::Keyboard::A;         ///< The A key
		case KeyboardAndMouse::B:
			return sf::Keyboard::B;         ///< The B key
		case KeyboardAndMouse::C:
			return sf::Keyboard::C;         ///< The C key
		case KeyboardAndMouse::D:
			return sf::Keyboard::D;         ///< The D key
		case KeyboardAndMouse::E:
			return sf::Keyboard::E;         ///< The E key
		case KeyboardAndMouse::F:
			return sf::Keyboard::F;         ///< The F key
		case KeyboardAndMouse::G:
			return sf::Keyboard::G;         ///< The G key
		case KeyboardAndMouse::H:
			return sf::Keyboard::H;         ///< The H key
		case KeyboardAndMouse::I:
			return sf::Keyboard::I;         ///< The I key
		case KeyboardAndMouse::J:
			return sf::Keyboard::J;         ///< The J key
		case KeyboardAndMouse::K:
			return sf::Keyboard::K;         ///< The K key
		case KeyboardAndMouse::L:
			return sf::Keyboard::L;         ///< The L key
		case KeyboardAndMouse::M:
			return sf::Keyboard::M;         ///< The M key
		case KeyboardAndMouse::N:
			return sf::Keyboard::N;         ///< The N key
		case KeyboardAndMouse::O:
			return sf::Keyboard::O;         ///< The O key
		case KeyboardAndMouse::P:
			return sf::Keyboard::P;         ///< The P key
		case KeyboardAndMouse::Q:
			return sf::Keyboard::Q;         ///< The Q key
		case KeyboardAndMouse::R:
			return sf::Keyboard::R;         ///< The R key
		case KeyboardAndMouse::S:
			return sf::Keyboard::S;         ///< The S key
		case KeyboardAndMouse::T:
			return sf::Keyboard::T;         ///< The T key
		case KeyboardAndMouse::U:
			return sf::Keyboard::U;         ///< The U key
		case KeyboardAndMouse::V:
			return sf::Keyboard::V;         ///< The V key
		case KeyboardAndMouse::W:
			return sf::Keyboard::W;         ///< The W key
		case KeyboardAndMouse::X:
			return sf::Keyboard::X;         ///< The X key
		case KeyboardAndMouse::Y:
			return sf::Keyboard::Y;         ///< The Y key
		case KeyboardAndMouse::Z:
			return sf::Keyboard::Z;         ///< The Z key
		case KeyboardAndMouse::Num0:
			return sf::Keyboard::Num0;      ///< The 0 key
		case KeyboardAndMouse::Num1:
			return sf::Keyboard::Num1;      ///< The 1 key
		case KeyboardAndMouse::Num2:
			return sf::Keyboard::Num2;      ///< The 2 key
		case KeyboardAndMouse::Num3:
			return sf::Keyboard::Num3;      ///< The 3 key
		case KeyboardAndMouse::Num4:
			return sf::Keyboard::Num4;      ///< The 4 key
		case KeyboardAndMouse::Num5:
			return sf::Keyboard::Num5;      ///< The 5 key
		case KeyboardAndMouse::Num6:
			return sf::Keyboard::Num6;      ///< The 6 key
		case KeyboardAndMouse::Num7:
			return sf::Keyboard::Num7;      ///< The 7 key
		case KeyboardAndMouse::Num8:
			return sf::Keyboard::Num8;      ///< The 8 key
		case KeyboardAndMouse::Num9:
			return sf::Keyboard::Num9;      ///< The 9 key
		case KeyboardAndMouse::Escape:
			return sf::Keyboard::Escape;    ///< The Escape key
		case KeyboardAndMouse::LControl:
			return sf::Keyboard::LControl;  ///< The LControl key
		case KeyboardAndMouse::LShift:
			return sf::Keyboard::LShift;    ///< The LShift key
		case KeyboardAndMouse::LAlt:
			return sf::Keyboard::LAlt;      ///< The LAlt key
		case KeyboardAndMouse::LSystem:
			return sf::Keyboard::LSystem;   ///< The LSystem key
		case KeyboardAndMouse::RControl:
			return sf::Keyboard::RControl;  ///< The RControl key
		case KeyboardAndMouse::RShift:
			return sf::Keyboard::RShift;    ///< The RShift key
		case KeyboardAndMouse::RAlt:
			return sf::Keyboard::RAlt;      ///< The RAlt key
		case KeyboardAndMouse::RSystem:
			return sf::Keyboard::RSystem;   ///< The RSystem key
		case KeyboardAndMouse::Menu:
			return sf::Keyboard::Menu;      ///< The Menu key
		case KeyboardAndMouse::LBracket:
			return sf::Keyboard::LBracket;  ///< The LBracket key
		case KeyboardAndMouse::RBracket:
			return sf::Keyboard::RBracket;  ///< The RBracket key
		case KeyboardAndMouse::SemiColon:
			return sf::Keyboard::SemiColon; ///< The SemiColon key
		case KeyboardAndMouse::Comma:
			return sf::Keyboard::Comma;     ///< The Comma key
		case KeyboardAndMouse::Period:
			return sf::Keyboard::Period;    ///< The Period key
		case KeyboardAndMouse::Quote:
			return sf::Keyboard::Quote;     ///< The Quote key
		case KeyboardAndMouse::Slash:
			return sf::Keyboard::Slash;     ///< The Slash key
		case KeyboardAndMouse::BackSlash:
			return sf::Keyboard::BackSlash; ///< The BackSlash key
		case KeyboardAndMouse::Tilde:
			return sf::Keyboard::Tilde;     ///< The Tilde key
		case KeyboardAndMouse::Equal:
			return sf::Keyboard::Equal;     ///< The Equal key
		case KeyboardAndMouse::Dash:
			return sf::Keyboard::Dash;      ///< The Dash key
		case KeyboardAndMouse::Space:
			return sf::Keyboard::Space;     ///< The Space key
		case KeyboardAndMouse::Return:
			return sf::Keyboard::Return;    ///< The Return key
		case KeyboardAndMouse::BackSpace:
			return sf::Keyboard::BackSpace; ///< The BackSpace key
		case KeyboardAndMouse::Tab:
			return sf::Keyboard::Tab;       ///< The Tab key
		case KeyboardAndMouse::PageUp:
			return sf::Keyboard::PageUp;    ///< The PageUp key
		case KeyboardAndMouse::PageDown:
			return sf::Keyboard::PageDown;  ///< The PageDown key
		case KeyboardAndMouse::End:
			return sf::Keyboard::End;       ///< The End key
		case KeyboardAndMouse::Home:
			return sf::Keyboard::Home;      ///< The Home key
		case KeyboardAndMouse::Insert:
			return sf::Keyboard::Insert;    ///< The Insert key
		case KeyboardAndMouse::Delete:
			return sf::Keyboard::Delete;    ///< The Delete key
		case KeyboardAndMouse::Add:
			return sf::Keyboard::Add;       ///< The Add key
		case KeyboardAndMouse::Subtract:
			return sf::Keyboard::Subtract;  ///< The Subtract key
		case KeyboardAndMouse::Multiply:
			return sf::Keyboard::Multiply;  ///< The Multiply key
		case KeyboardAndMouse::Divide:
			return sf::Keyboard::Divide;    ///< The Divide key
		case KeyboardAndMouse::Left:
			return sf::Keyboard::Left;      ///< The Left key
		case KeyboardAndMouse::Right:
			return sf::Keyboard::Right;     ///< The Right key
		case KeyboardAndMouse::Up:
			return sf::Keyboard::Up;        ///< The Up key
		case KeyboardAndMouse::Down:
			return sf::Keyboard::Down;      ///< The Down key
		case KeyboardAndMouse::Numpad0:
			return sf::Keyboard::Numpad0;   ///< The numpad 0 key
		case KeyboardAndMouse::Numpad1:
			return sf::Keyboard::Numpad1;   ///< The numpad 1 key
		case KeyboardAndMouse::Numpad2:
			return sf::Keyboard::Numpad2;   ///< The numpad 2 key
		case KeyboardAndMouse::Numpad3:
			return sf::Keyboard::Numpad3;   ///< The numpad 3 key
		case KeyboardAndMouse::Numpad4:
			return sf::Keyboard::Numpad4;   ///< The numpad 4 key
		case KeyboardAndMouse::Numpad5:
			return sf::Keyboard::Numpad5;   ///< The numpad 5 key
		case KeyboardAndMouse::Numpad6:
			return sf::Keyboard::Numpad6;   ///< The numpad 6 key
		case KeyboardAndMouse::Numpad7:
			return sf::Keyboard::Numpad7;   ///< The numpad 7 key
		case KeyboardAndMouse::Numpad8:
			return sf::Keyboard::Numpad8;   ///< The numpad 8 key
		case KeyboardAndMouse::Numpad9:
			return sf::Keyboard::Numpad9;   ///< The numpad 9 key
		case KeyboardAndMouse::F1:
			return sf::Keyboard::F1;        ///< The F1 key
		case KeyboardAndMouse::F2:
			return sf::Keyboard::F2;        ///< The F2 key
		case KeyboardAndMouse::F3:
			return sf::Keyboard::F3;        ///< The F3 key
		case KeyboardAndMouse::F4:
			return sf::Keyboard::F4;        ///< The F4 key
		case KeyboardAndMouse::F5:
			return sf::Keyboard::F5;        ///< The F5 key
		case KeyboardAndMouse::F6:
			return sf::Keyboard::F6;        ///< The F6 key
		case KeyboardAndMouse::F7:
			return sf::Keyboard::F7;        ///< The F7 key
		case KeyboardAndMouse::F8:
			return sf::Keyboard::F8;        ///< The F8 key
		case KeyboardAndMouse::F9:
			return sf::Keyboard::F9;        ///< The F9 key
		case KeyboardAndMouse::F10:
			return sf::Keyboard::F10;       ///< The F10 key
		case KeyboardAndMouse::F11:
			return sf::Keyboard::F11;       ///< The F11 key
		case KeyboardAndMouse::F12:
			return sf::Keyboard::F12;       ///< The F12 key
		case KeyboardAndMouse::F13:
			return sf::Keyboard::F13;       ///< The F13 key
		case KeyboardAndMouse::F14:
			return sf::Keyboard::F14;       ///< The F14 key
		case KeyboardAndMouse::F15:
			return sf::Keyboard::F15;       ///< TheF15 key
		case KeyboardAndMouse::Pause:
			return sf::Keyboard::Pause;     ///< The Pause key
		default:
			return sf::Keyboard::Unknown;   ///< Unhandled key
	}
}