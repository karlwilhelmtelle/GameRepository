#pragma once
#include <SFML/Graphics.hpp>

class Window;

class MainItem : public sf::CircleShape
{
	public:
		/*	sets radius, position, fillColor */
		MainItem(sf::VideoMode &resolution);

		void keyEvent(sf::Keyboard::Key key, float camera_speed);

		void init();
	private:
		sf::VideoMode &resolution;

		/*  radius */
		float radius;
		
		/*  x and y coordinates */
		sf::Vector2f position;
};