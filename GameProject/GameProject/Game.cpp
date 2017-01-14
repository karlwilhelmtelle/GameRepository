#include "Game.h"

Game::Game() :
	window(sf::VideoMode::getDesktopMode())
{
	//d.h. man startet im Menü
	level = 1;
	bool game_over = false;
	
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
					window.keyAction(event.key.code);
					break;
					
				default:
					break;
			}
		}
		
		if (game_over)
		{
			game_over = false;
			window.gameOver();
		}
		
		window.updateGame(&game_over);
		window.renderGraphics();
	}
}


int main() 
{
	Game game;

	return 0;
}