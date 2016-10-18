#pragma once
#include <SFML/Graphics.hpp>

class Window;

class MainItem : public sf::CircleShape
{
	public:
		/*	sets radius, position, fillColor */
		MainItem(sf::VideoMode resolution);

		void keyEvent(sf::Keyboard::Key key, Window &window);
	private:
		sf::VideoMode resolution;

		/*  radius */
		float radius;
		
		/*  x and y coordinates */
		sf::Vector2f position;
};