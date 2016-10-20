#include "Game.h"

Game::Game() :
	window(sf::VideoMode::getDesktopMode())
{
	//d.h. man startet im Menü
	level = 1;
	bool gameover = false;
	
	//window.hideMenu();

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
			gameover = false;
			window.refresh();
		}
		
		window.update(&gameover);
		window.render();
	}
}


int main() 
{
	Game game;

	return 0;
}