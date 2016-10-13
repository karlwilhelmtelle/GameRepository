#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Window.h"
#include "MainItem.h"

class Game
{
	public:
		/*	starting the game */
		Game();

		/*	saving information when game is closed */
		~Game();
	private:
		/*	window of the game */
		Window window;
		
		/*	current level */
		int level;
};

