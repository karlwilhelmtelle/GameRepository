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

enum class GameState { MAIN_MENU, LEVEL_MENU, PLAY, OPTIONS, HIGHSCORE };

class Window : public sf::RenderWindow
{
	public:
		Window(sf::VideoMode resolution);

		void init(sf::VideoMode resolution);

		void renderGraphics();

		void updateGame(bool *collision);

		void keyAction(sf::Keyboard::Key key);

		void gameOver();

		void setGameState(GameState state);

		void restartClock();

		int getLevelIndex();

		void setLevelIndex(int selected_level_index);

		void playSound(SoundName sound_name);

		void updateElapsedTime();

		void updateHighscore();

		void pauseGame();

		void unpauseGame();

		//void score();
	private:
		GameState game_state;

		int level_index;

		bool pause;

		MainItem item;
		MainItem_Level2 item_2;

		float camera_speed;

		ObjectContainer map;

		Sound sound;

		sf::Clock clock;
		Text time_text;
		Text highscore_text;
		sf::Int32 time_milliseconds;
		sf::Int32 highscore_milliseconds;

		MainMenu main_menu;
		LevelMenu level_menu;
		HighscoreMenu highscore_menu;
		OptionsMenu options_menu;
};