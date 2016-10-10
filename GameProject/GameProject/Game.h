#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Viewport.h"

class Game
{
	public:
		Game();
		~Game();
	private:
		Viewport viewport;
		sf::RenderWindow window;
		sf::CircleShape shape;
};

