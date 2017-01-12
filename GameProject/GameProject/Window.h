#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "MainItem.h"
#include "ObjectContainer.h"
#include "LevelMenu.h"
#include "Sound.h"
#include "Item_Level_2.h"
#include "highscore_menu.h"
#include "OptionMenu.h"

enum class GameStates { MAIN_MENU, LEVEL_MENU, PLAY, OPTIONS, HIGHSCORE };
//enum = Aufz�hlung; zeigt die verschiedenen Zust�nde im Men� an; wird als Array behandelt
enum class LevelStates { LEVEL1, LEVEL2, LEVEL3, LEVEL4, LEVEL5 };
//Men�punkte im Level-Men�
class Window : public sf::RenderWindow
{
	public:
		/*	initiales	sf::RenderWindow,
						sf::VideoMode resolution,
						MainItem item
		*/
		Window(sf::VideoMode resolution);

		void init(sf::VideoMode resolution);

		/*	clears window using a black background
			draws Window.item
			displays the new frame
		*/
		void render();

		/*	moves and updates item depending on events
			updates map
		*/
		void update(bool *collision);

		void keyAction(sf::Keyboard::Key key);

		void showMenu();

		void showGame();

		void showOptions();

		void showHighscore();

		void restart();

		void showLevelMenu();

		void playLevel(int selectedLevelIndex);

		void playSound(SoundName sound_name);

		void updateElapsedTime();

		void updateHighscore();

		void score();

		std::string timeToString(sf::Int32 time);

	private:
		GameStates game_state;

		LevelStates level_state;

		MainMenu menu;

		LevelMenu level_menu;

		/*	main item in the middle of the screen */
		MainItem item;

		Item_Level_2 item_2;

		/*  current speed of the background, moving left */
		float camera_speed;

		/*  vector of objects */
		ObjectContainer map;

		sf::Clock clock;

		Sound sound;

		sf::Int32 timeMilliseconds;
		Text time;

		sf::Int32 highscoreMilliseconds;
		Text highscore;

		highscore_menu HighscoreMenu;

		OptionMenu option_menu;
};