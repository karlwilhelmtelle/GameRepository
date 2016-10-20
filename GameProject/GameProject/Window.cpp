#include "Window.h"
#include "Object.h"

Window::Window(sf::VideoMode res) :
	sf::RenderWindow(res,
		"Game", sf::Style::Fullscreen),
	game_states(GameStates::MAIN_MENU),
	menu(res),
	item(res),
	camera_speed(0.2f)
{
	setMouseCursorVisible(false);
	map.load(res);
} 


void Window::render()
{
	clear(sf::Color::Black);

	switch (game_states)
	{
		case GameStates::MAIN_MENU:
		{
			menu.draw(*this);
			break;
		}
		case GameStates::PLAY:
		{
			draw(item);

			for (auto e = map.v.begin(); e != map.v.end(); ++e)
			{
				draw(*e);
			}

			float game_time = clock.getElapsedTime().asMilliseconds() / 1000;
			//Ausgabe der Zeit im Spiel und Ausgabe der Gesamtzeit fehlt

			break;
		}
		case GameStates::OPTIONS:
		{
			//sf::Keyboard::Return;
			//open options
			break;
		}
		case GameStates::EXIT:
		{
			//sf::Keyboard::Return;
			//window.close();
			break;
		}
		default:
			break;
	}
	display();
}


void Window::update(bool *collision)
{
	camera_speed *= 1.00001f;
	map.update(item.getPosition(), item.getRadius(), camera_speed, collision);
}


void Window::keyAction(sf::Keyboard::Key key)
{
	switch (game_states)
	{
		case(GameStates::MAIN_MENU):
		{
			menu.keyEvent(key, *this);
			break;
		}
		case(GameStates::PLAY):
		{
			item.keyEvent(key, camera_speed);
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


void Window::showMenu()
{
	game_states = GameStates::MAIN_MENU;
}


void Window::showGame()
{
	game_states = GameStates::PLAY;
	clock.restart();
}


void Window::showOptions()
{
	game_states = GameStates::OPTIONS;
}