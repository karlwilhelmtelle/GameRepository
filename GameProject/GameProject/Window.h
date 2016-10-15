#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "MainItem.h"
#include "ObjectContainer.h"

class Window : public sf::RenderWindow
{
	public:
		/*	initializing	sf::RenderWindow,
							sf::VideoMode resolution,
							MainItem item
		*/
		Window();
		
		~Window();

		/*	clear window using a black background
			draw Window.item
			display the new frame
		*/
		void render();

		/*	move Window.item depending on events
			if no collision: Window.item.update()
			if collision
		*/
		void update(bool* collision);
	private:
		/*	resolution of the display */
		sf::VideoMode resolution;

		/*	main item, in the middle of the screen */
		MainItem item;

		/*  current speed of the background, moving left */
		float camera_speed;

		/*  vector of objects */
		ObjectContainer map;
};