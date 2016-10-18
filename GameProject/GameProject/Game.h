#pragma once
#include "Window.h"

class Game
{
	public:
		/*	starts the game */
		Game();

		/*	saves information when game is closed */
		//~Game();
	private:
		/*	window of the game */
		Window window;
		
		/*	current level */
		int level;
};

