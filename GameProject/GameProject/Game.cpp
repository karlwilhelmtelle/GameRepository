#include "Game.h"

Game::Game() :
	window(sf::VideoMode::getDesktopMode())
{
	level = 1;
	bool gameover = false;
	
	window.hideMenu();

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
						case sf::Keyboard::Escape:
							window.close();
							break;

						default:
							window.keyAction(event.key.code);
							break;
					}
					break;

				default:
					break;
			}
		}

		if (gameover)
		{
			window.showMenu();
		}

		window.render();
		window.update(&gameover);
	}
}


int main() 
{
	Game game;

	return 0;
}