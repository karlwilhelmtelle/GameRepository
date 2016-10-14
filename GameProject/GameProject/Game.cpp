#include "Game.h"

Game::Game()
{
	level = 1;
	bool gameover = false;
	
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

		if (!gameover)
		{
			window.render();
			if (window.update()) // if collision -> gameover
			{
				gameover = true;
			}
		}
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