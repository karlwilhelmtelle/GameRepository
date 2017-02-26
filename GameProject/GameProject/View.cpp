#include "View.h"
#include "Object.h"

View::View(const sf::VideoMode &res) :
	sf::RenderWindow(res,
		"Game", sf::Style::Fullscreen),
	resolution(res),
	level(res),
	gameState(GameState::MENU),
	menu(res, settings.getSettings())
{
	setMouseCursorVisible(false);
	initSettings();
}

void View::initSettings()
{
	level.updateSettings(settings.getMainItemColor(),
		settings.getObjectsColor());
	sound.updateSettings(settings.audioEnabled());
}

void View::setLevelIndex(const int selectedLevelIndex)
{
	setGameState(GameState::PLAY);
	level.setLevelIndex(selectedLevelIndex);
}


// TODO: improve rendering performance
void View::renderGraphics()
{
	clear(sf::Color::Black);
	
	if (gameState == GameState::PLAY)
	{
		level.draw(*this);
	}
	else
	{
		menu.draw(*this);
	}

	display();
}


void View::updateGame(bool *gameOver)
{
	if (gameState == GameState::PLAY)
	{
		level.update(gameOver);
	}
}


void View::keyAction(const sf::Keyboard::Key key)
{
	if (gameState == GameState::PLAY)
	{
		if (key != sf::Keyboard::Escape)
		{
			level.keyEvent(key);
		}
		else
		{
			setGameState(GameState::MENU);
		}
	}
	else
	{
		menu.keyEvent(key, *this);
	}
}

void View::setGameState(const GameState state)
{
	if (gameState != state)
	{
		gameState = state;
	}
}

void View::gameOver()
{
	menu.updateHighscore(level.getHighscore(), level.getLastScore());
	level.init();
	playSound(SoundName::GAME_OVER);
	setGameState(GameState::MENU);
	menu.setMenu(MenuState::HighscoreMenu);
}


void View::playSound(const SoundName sound_name)
{
	sound.playSound(sound_name);
}

void View::updateSettings(const std::vector<size_t> newSettings)
{
	settings.update(newSettings);
	initSettings();
}