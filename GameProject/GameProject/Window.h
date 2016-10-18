#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "MainItem.h"
#include "ObjectContainer.h"

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
		void update(bool* collision);

		void keyAction(sf::Keyboard::Key key);

		void showMenu();

		void hideMenu();
	private:
		/*	resolution of the display */
		sf::VideoMode resolution;

		MainMenu menu;

		/*	main item in the middle of the screen */
		MainItem item;

		/*  current speed of the background, moving left */
		float camera_speed;

		/*  vector of objects */
		ObjectContainer map;

		bool show_menu;
};