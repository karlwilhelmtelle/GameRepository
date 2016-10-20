#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "MainItem.h"
#include "ObjectContainer.h"

enum class GameStates { MAIN_MENU, PLAY, OPTIONS, EXIT };
//enum = Aufzählung; zeigt die verschiedenen Zustände im Menü an; wird als Array behandelt

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

		void showMenu();

		void showGame();

		void showOptions();

		void refresh();
	private:
		GameStates game_states;

		MainMenu menu;

		/*	main item in the middle of the screen */
		MainItem item;

		/*  current speed of the background, moving left */
		float camera_speed;

		/*  vector of objects */
		ObjectContainer map;

		sf::Clock clock;
};