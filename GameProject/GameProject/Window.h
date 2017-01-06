#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "MainItem.h"
#include "ObjectContainer.h"
#include "LevelMenu.h"
#include "Sound.h"
#include "Item_Level_2.h"

enum class GameStates { MAIN_MENU, LEVEL_MENU, PLAY, OPTIONS };
//enum = Aufzählung; zeigt die verschiedenen Zustände im Menü an; wird als Array behandelt
enum class LevelStates { LEVEL1, LEVEL2, LEVEL3, LEVEL4, LEVEL5 };
//Menüpunkte im Level-Menü
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

		void refresh();

		void refresh2();

		void showLevelMenu();

		void playLevel(int selectedLevelIndex);

		void playSound(SoundName sound_name);
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
};