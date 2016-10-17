#include "Window.h"

enum class GameStates { MAIN_MENU, PLAY, OPTIONS, EXIT };
//enum = Aufzählung; wird wie ein Array behandelt

Window::Window() :
	sf::RenderWindow(resolution,
		"Game", sf::Style::Fullscreen),
	resolution(sf::VideoMode::getDesktopMode()),
	menu(resolution),
	item(resolution),
	camera_speed(0.3f),
	show_menu(true)
{
	setMouseCursorVisible(false);
	map.load("", resolution);
}


void Window::render()
{
	// Gamestate wird auf 0, d.h. auf MAIN_MENU gesetzt
	//dadurch ist der Start nach dem Öffnen immer das Menü
	GameStates gamestates = GameStates::MAIN_MENU;

	clear(sf::Color::Black);

	if (show_menu)
	{
		sf::Event event;

		while (pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					close();
					break;

				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;

						case sf::Keyboard::Down:
							menu.MoveDown();
							break;
					}
					break;

				default:
					break;
			}
//wenn z.B. Play im Menü gelb hinterlegt ist
//und Tab gedrückt wird, soll das Spiel starten
			switch (GameStates())
			{
					case GameStates::PLAY:
					{
//Tab, da ich Enter für die Fehlermeldung manchmal brauche
					sf::Keyboard::Tab;
					bool menu_show(false);
					break;
				}
				case GameStates::OPTIONS:
				{
					//open options
					break;
				}
				case GameStates::EXIT:
				{
					//sf::Keyboard::Return;
					//Fenster wird geschlossen
					break;
				}
				default:
					break;
			}
		}

		menu.draw(*this);
	}
	else
	{
		draw(item);

		for (auto e = map.v.begin(); e != map.v.end(); ++e)
		{
			draw(*e);
		}
	}

	display();
}


void Window::update(bool* collision)
{
	sf::Vector2f item_position = item.getPosition();
	float item_radius = item.getRadius();

	// go up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		item_position.y > 0)	// top of screen
	{
		item.move(-1);
	}

	// go down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		// bottom of screen
		item_position.y < resolution.height - 2*item_radius)
	{
		item.move(+1);
	}

	map.update(item.getPosition(), item.getRadius(), camera_speed, collision);
	item.update();
}