#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "MainItem.h"
#include "ObjectContainer.h"

enum class GameStates { MAIN_MENU, PLAY, OPTIONS, EXIT };
//enum = Aufz�hlung; zeigt die verschiedenen Zust�nde im Men� an; wird als Array behandelt
enum class LevelStates { MAIN_LEVEL_MENU, LEVEL1, LEVEL2, LEVEL3, LEVEL4, LEVEL5 };
//Men�punkte im Level-Men�
class Window : public sf::RenderWindow
{
	public:
		/*	initiales	sf::RenderWindow,
						sf::VideoMode resolution,
						MainItem item
		*/
		Window(sf::VideoMode resolution);

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

		void win();

		void showMenu();

		void showGame();

		void showOptions();

		void refresh();

		void showMainLevelMenu();

		void showLevel1();

		void showLevel2();

		void showLevel3();

		void showLevel4();

		void showLevel5();
	private:
		GameStates game_states;

		LevelStates level_states;

		MainMenu menu;

		/*	main item in the middle of the screen */
		MainItem item;

		/*  current speed of the background, moving left */
		float camera_speed;

		/*  vector of objects */
		ObjectContainer map;

		sf::Clock clock;
};