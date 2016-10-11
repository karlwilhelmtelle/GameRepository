#pragma once
#include <SFML/Graphics.hpp>
#include "MainItem.h"

class Window : public sf::RenderWindow
{
	public:
		Window();
		~Window();
		void render();
		void update();
	private:
		sf::VideoMode resolution;
		MainItem item;
		float camera_speed;
};