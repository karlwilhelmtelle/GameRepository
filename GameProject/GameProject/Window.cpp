#include "Window.h"
#include "Object.h"

Window::Window(sf::VideoMode res) :
	sf::RenderWindow(res,
		"Game", sf::Style::Fullscreen),
	game_state(GameStates::MAIN_MENU),
	menu(res),
	level_menu(res),
	item(res),
	camera_speed(0.2f)
{
	setMouseCursorVisible(false);
	map.load(res);
} 

// TODO: improve rendering performance
void Window::render()
{
	clear(sf::Color::Black);

	switch (game_state)
	{
		case GameStates::PLAY:
		{
			switch (level_state)
			{
				case LevelStates::LEVEL1:
				{
					draw(item);

					for (auto e = map.v.begin(); e != map.v.end(); ++e)
					{
						draw(*e);
					}

					// TODO: Ausgabe der Zeit im Spiel und Ausgabe der Gesamtzeit fehlt
					float game_time = clock.getElapsedTime().asMilliseconds() / 1000;
					break;
				}
				// TODO: add further levels and graphics
			}

			break;
		}
		
		case GameStates::MAIN_MENU:
		{
			menu.draw(*this);
			break;
		}

		case GameStates::LEVEL_MENU:
		{
			level_menu.draw(*this);
			break;
		}

		case GameStates::OPTIONS:
		{
			// TODO: add options
			//sf::Keyboard::Return;
			//open options
			break;
		}
		default:
			break;
	}
	display();
}


void Window::update(bool *collision)
{
	if (game_state == GameStates::PLAY)
	{
		camera_speed *= 1.00001f;
		map.update(item.getPosition(), item.getRadius(), camera_speed, collision);
	}
}


void Window::keyAction(sf::Keyboard::Key key)
{
	switch (game_state)
	{
		case GameStates::PLAY:
		{
			item.keyEvent(key, camera_speed);
			break;
		}

		case GameStates::MAIN_MENU:
		{
			menu.keyEvent(key, *this);
			break;
		}

		case GameStates::LEVEL_MENU:
		{
			level_menu.keyEvent(key, *this);
			break;
		}

		case GameStates::OPTIONS:
		{
			//sf::Keyboard::Return;
			//open options
			break;
		}
		default:
			break;
	}
	
}

void Window::showMenu()
{
	game_state = GameStates::MAIN_MENU;
}

void Window::showGame()
{
	game_state = GameStates::PLAY;
	//level_state = LevelStates::LEVEL1;
	clock.restart();
}


void Window::showOptions()
{
	game_state = GameStates::OPTIONS;
}


void Window::refresh()
{
	showMenu();
	sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
	item = MainItem(resolution);
	map.load(resolution);
}

void Window::showLevelMenu()
{
	game_state = GameStates::LEVEL_MENU;
}


void Window::playLevel(int selectedLevelIndex)
{
	game_state = GameStates::PLAY;

	switch (selectedLevelIndex)
	{
	case 0:
		level_state = LevelStates::LEVEL1;
		break;
	case 1:
		level_state = LevelStates::LEVEL2;
		break;
	case 2:
		level_state = LevelStates::LEVEL3;
		break;
	case 3:
		level_state = LevelStates::LEVEL4;
		break;
	case 4:
		level_state = LevelStates::LEVEL5;
		break;
	}
}