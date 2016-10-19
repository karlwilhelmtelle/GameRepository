#include "Game.h"

enum class GameStates { MAIN_MENU, PLAY, OPTIONS, EXIT };
//enum = Aufzählung; zeigt die verschiedenen Zustände im Menü an; wird als Array behandelt

Game::Game() :
	window(sf::VideoMode::getDesktopMode())
{
	GameStates gameStates = GameStates::MAIN_MENU;
	//d.h. man startet im Menü
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
//wenn der jeweilige Menüpunkt gelb hinterlegt ist und Enter gedrückt wird
// soll jeweils das passieren was in den cases aufgelistet ist
			switch (GameStates())
			{
				case(GameStates::MAIN_MENU):
				{
					bool show_menu(true);
				}
				case(GameStates::PLAY):
				{
					sf::Keyboard::Tab;
					bool show_menu(false);
					break;
				}
				case(GameStates::OPTIONS):
				{
					//sf::Keyboard::Return;
					//open options
					break;
				}
				case(GameStates::EXIT):
				{
					//sf::Keyboard::Return;
					//window.close();
					break;
				}
				default:
					break;
			}
		}

		if (gameover)
		{
			window.showMenu();
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