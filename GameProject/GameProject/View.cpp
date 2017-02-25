#include "View.h"
#include "Object.h"

View::View(const sf::VideoMode &res) :
	sf::RenderWindow(res,
		"Game", sf::Style::Fullscreen),
	resolution(res),
	levels(res),
	game_state(GameState::MAIN_MENU),
	main_menu(res),
	level_menu(res),
	highscore_menu(res),
	options_menu(res, settings.getSettings())
{
	setMouseCursorVisible(false);
	initSettings();
}

void View::initSettings()
{
	levels.getCurrentLevel()->updateSettings(settings.getMainItemColor(),
		settings.getObjectsColor());
	sound.updateSettings(settings.audioEnabled());
}

void View::setLevelIndex(int selected_level_index)
{
	setGameState(GameState::PLAY);
	levels.setLevelIndex(selected_level_index);
}


// TODO: improve rendering performance
void View::renderGraphics()
{
	clear(sf::Color::Black);

	switch (game_state)
	{
		case GameState::PLAY:
		{
			levels.getCurrentLevel()->draw(*this);
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


void View::updateGame(bool *game_over)
{
	if (game_state == GameState::PLAY)
	{
		levels.getCurrentLevel()->update(game_over);
	}
}


void View::keyAction(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Escape)
	{
		setGameState(GameState::MAIN_MENU);
	}
	else
	{
		switch (game_state)
		{
			case GameState::PLAY:
			{
				levels.getCurrentLevel()->keyEvent(key);
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

void View::setGameState(GameState state)
{
	game_state = state;
}

void View::gameOver()
{
	Level* level = levels.getCurrentLevel();
	highscore_menu.updateTimeValues(level->getHighscore(), level->getLastScore());
	level->init();
	playSound(SoundName::GAME_OVER);
	setGameState(GameState::HIGHSCORE);
}


void View::playSound(SoundName sound_name)
{
	sound.playSound(sound_name);
}

void View::updateSettings(std::vector<size_t> newSettings)
{
	settings.update(newSettings);
	initSettings();
}