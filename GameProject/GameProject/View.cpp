#include "View.h"
#include "Object.h"

View::View(const sf::VideoMode &res) :
	sf::RenderWindow(res,
		"Game", sf::Style::Fullscreen),
	resolution(res),
	levels(res),
	gameState(GameState::MAIN_MENU),
	mainMenu(res),
	levelMenu(res),
	highscoreMenu(res),
	optionsMenu(res, settings.getSettings())
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

	switch (gameState)
	{
		case GameState::PLAY:
		{
			levels.getCurrentLevel()->draw(*this);
			break;
		}
		
		case GameState::MAIN_MENU:
		{
			mainMenu.draw(*this);
			break;
		}

		case GameState::LEVEL_MENU:
		{
			levelMenu.draw(*this);
			break;
		}

		case GameState::OPTIONS:
		{
			optionsMenu.draw(*this);
			break;
		}
		case GameState::HIGHSCORE:
		{
			highscoreMenu.draw(*this);
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
	if (gameState == GameState::PLAY)
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
		switch (gameState)
		{
			case GameState::PLAY:
			{
				levels.getCurrentLevel()->keyEvent(key);
				break;
			}

			case GameState::MAIN_MENU:
			{
				mainMenu.keyEvent(key, *this);
				break;
			}

			case GameState::LEVEL_MENU:
			{
				levelMenu.keyEvent(key, *this);
				break;
			}

			case GameState::OPTIONS:
			{
				optionsMenu.keyEvent(key, *this);
				break;
			}
			case GameState::HIGHSCORE:
			{
				highscoreMenu.keyEvent(key, *this);
				break;
			}
			default:
				break;
		}
	}
}

void View::setGameState(GameState state)
{
	gameState = state;
}

void View::gameOver()
{
	Level* level = levels.getCurrentLevel();
	highscoreMenu.updateTimeValues(level->getHighscore(), level->getLastScore());
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