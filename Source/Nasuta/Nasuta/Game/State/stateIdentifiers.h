#ifndef STATE_IDENTIFIERS_H
#define STATE_IDENTIFIERS_H


namespace States
{
	enum ID : unsigned int
	{
		None,
		Title,
		Menu,
		Game,
		Loading,
		Pause,
		Settings,
		GameOver
	};
}

#endif
