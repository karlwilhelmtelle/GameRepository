#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MainItem.h"
#include "ObjectContainer.h"
#include "Sound.h"
#include "MainItem_Level2.h"
#include "LevelController.h"
#include "Settings.h"

enum class GameState { PLAY, MENU };

class View : public sf::RenderWindow
{
	public:
		View(const sf::VideoMode &resolution);

		void renderGraphics();

		void updateGame(bool *collision);

		void keyAction(const sf::Keyboard::Key key);

		void gameOver();

		void setGameState(const GameState state);

		void setLevelIndex(const int selectedLevelIndex);

		void playSound(const SoundName sound_name);

		void updateSettings(const std::vector < size_t > settings);
	private:
		void initSettings();

		const sf::VideoMode &resolution;

		GameState gameState;

		LevelController levels;

		Settings settings;
		Sound sound;
		
		Menu menu;

		/*MainMenu mainMenu;
		LevelMenu levelMenu;
		HighscoreMenu highscoreMenu;
		OptionsMenu optionsMenu;*/
};