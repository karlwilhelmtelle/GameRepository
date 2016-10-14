#include "Game.h"

Game::Game()
{
	level = 1;
	
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		window.render();
		window.update();
	}
}


Game::~Game()
{

}


int main() 
{
	Game game;

	return 0;
}