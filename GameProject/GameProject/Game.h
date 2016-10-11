#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Window.h"
#include "Viewport.h"

class Game
{
	public:
		Game();
		~Game();
		void start();
	private:
		Viewport viewport;
		sf::RenderWindow window;
		sf::CircleShape shape;
		int level;
};

