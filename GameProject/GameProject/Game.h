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
		Game();
		~Game();
	private:
		Window window;
		int level;
};

