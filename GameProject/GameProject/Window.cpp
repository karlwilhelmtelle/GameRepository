#include "Window.h"
#include "Object.h"

Window::Window(sf::VideoMode res) :
	sf::RenderWindow(res,
		"Game", sf::Style::Fullscreen),
	game_state(GameState::MAIN_MENU),
	main_menu(res),
	level_index(0),
	level_menu(res),
	item(res),
	item_2(res),
	highscore_milliseconds(0),
	highscore_menu(res),
	options_menu(res),
	pause(false)
{
	setMouseCursorVisible(false);
	init(res);

	time_text.setFillColor(sf::Color::White);
	time_text.setString("00:00:000");
	time_text.setPosition(sf::Vector2f((float)res.width / 50,
		(float)res.height / 50));

	highscore_text.setFillColor(sf::Color::White);
	highscore_text.setStringToTime(0);
	highscore_text.setPosition(sf::Vector2f((float) 9 * res.width / 10,
		 (float)res.height / 50));
}


void Window::init(sf::VideoMode res)
{
	camera_speed = 0.2f;
	map.load(res);
}


// TODO: improve rendering performance
void Window::renderGraphics()
{
	clear(sf::Color::Black);

	switch (game_state)
	{
		case GameState::PLAY:
		{
			switch (level_index)
			{
				case 0:
				{
					draw(item);
					draw(highscore_text);
					draw(time_text);

					for (auto e = map.v.begin(); e != map.v.end(); ++e)
					{
						draw(*e);
					}
					/*
					// TODO: Ausgabe der Zeit im Spiel und Ausgabe der Gesamtzeit fehlt
					float game_time = clock.getElapsedTime().asMilliseconds() / 1000.f;
					int score = (int) game_time / 1000;*/
					break;
				}
				case 1:
				{
					draw(item_2);
					draw(highscore_text);
					draw(time_text);

					for (auto e = map.v.begin(); e != map.v.end(); ++e)
					{
						draw(*e);
					}
					break;
				}
			}

			break;
		}
		
		case GameState::MAIN_MENU:
		{
			main_menu.draw(*this);
			break;
		}

		case GameState::LEVEL_MENU:
		{
			level_menu.draw(*this);
			break;
		}

		case GameState::OPTIONS:
		{
			options_menu.draw(*this);
			break;
		}
		case GameState::HIGHSCORE:
		{
			highscore_menu.draw(*this);
			//score();
			break;
		}
		default:
			break;
	}
	display();
}


void Window::updateGame(bool *game_over)
{
	if (game_state == GameState::PLAY && level_index == 0)
	{
		camera_speed *= 1.00001f;
		map.update(item.getPosition(), item.getRadius(), camera_speed, game_over);
		updateElapsedTime();
		updateHighscore();
	}
	if (game_state == GameState::PLAY && level_index == 1)
	{
		camera_speed *= 1.00001f;
		map.update(item_2.getPosition(), item_2.getRadius(), camera_speed, game_over);
		updateElapsedTime();
		updateHighscore();
	}
}


void Window::keyAction(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Escape)
	{
		if (game_state == GameState::PLAY)
		{
			pauseGame();
		}
		setGameState(GameState::MAIN_MENU);
	}
	else
	{
		switch (game_state)
		{
			case GameState::PLAY:
			{
				if (level_index == 0)
				{
					item.keyEvent(key, camera_speed);
				}
				if (level_index == 1)
				{
					item_2.keyEvent(key, camera_speed);
				}

				break;
			}

			case GameState::MAIN_MENU:
			{
				main_menu.keyEvent(key, *this);
				break;
			}

			case GameState::LEVEL_MENU:
			{
				level_menu.keyEvent(key, *this);
				break;
			}

			case GameState::OPTIONS:
			{
				options_menu.keyEvent(key, *this);
				break;
			}
			case GameState::HIGHSCORE:
			{
				highscore_menu.keyEvent(key, *this);
				break;
			}
			default:
				break;
		}
	}
}

void Window::setGameState(GameState state)
{
	game_state = state;
}

void Window::restartClock()
{
	clock.restart();
}

int Window::getLevelIndex()
{
	return level_index;
}


void Window::gameOver()
{
	sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
	item = MainItem(resolution);
	init(resolution);
	playSound(SoundName::GAME_OVER);
	setGameState(GameState::HIGHSCORE);
}


void Window::setLevelIndex(int selected_level_index)
{
	setGameState(GameState::PLAY);
	unpauseGame();

	if (level_index != selected_level_index)
	{
		restartClock();
		level_index = selected_level_index;
	}
}


void Window::playSound(SoundName sound_name)
{
	sound.playSound(sound_name);
}


void Window::updateElapsedTime()
{
	time_milliseconds = clock.getElapsedTime().asMilliseconds();
	
	time_text.setStringToTime(time_milliseconds);
}

void Window::updateHighscore()
{
	if (time_milliseconds > highscore_milliseconds)
	{
		highscore_milliseconds = time_milliseconds;
		highscore_text.setStringToMilliseconds(highscore_milliseconds);
	}
}

void Window::pauseGame()
{
	pause = true;
	level_menu.disableSelection(level_index);
}

void Window::unpauseGame()
{
	pause = false;
	level_menu.enableSelection();
}

/*
void Window::score()
{
	sf::VideoMode resolution = sf::VideoMode::getDesktopMode();
	time_text.timeToString(time_milliseconds);
	time_text.setPosition(sf::Vector2f((float)resolution.width / 2.0f,
		(float)resolution.height / 3 ));
	draw(time_text);
}*/