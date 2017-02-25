#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "MainItem.h"
#include "ObjectContainer.h"
#include "LevelMenu.h"
#include "Sound.h"
#include "MainItem_Level2.h"
#include "HighscoreMenu.h"
#include "OptionsMenu.h"
#include "LevelController.h"
#include "Settings.h"

enum class GameState { MAIN_MENU, LEVEL_MENU, PLAY, OPTIONS, HIGHSCORE };

class View : public sf::RenderWindow
{
	public:
		View(const sf::VideoMode &resolution);

		void renderGraphics();

		void updateGame(bool *collision);

		void keyAction(sf::Keyboard::Key key);

		void gameOver();

		void setGameState(GameState state);

		void setLevelIndex(int selected_level_index);

		void playSound(SoundName sound_name);

		void updateSettings(std::vector < size_t > settings);
	private:
		void initSettings();

		const sf::VideoMode &resolution;

		GameState gameState;

		LevelController levels;

		Settings settings;
		Sound sound;
		
		MainMenu mainMenu;
		LevelMenu levelMenu;
		HighscoreMenu highscoreMenu;
		OptionsMenu optionsMenu;
};