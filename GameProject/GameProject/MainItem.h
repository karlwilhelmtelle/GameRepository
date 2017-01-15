#pragma once
#include <SFML/Graphics.hpp>

class View;

class MainItem : public sf::CircleShape
{
	public:
		/*	sets radius, position, fillColor */
		MainItem(const sf::VideoMode &resolution);

		void keyEvent(sf::Keyboard::Key key, float camera_speed);

		void init();
	private:
		const sf::VideoMode &resolution;

		/*  radius */
		float radius;
		
		/*  x and y coordinates */
		sf::Vector2f position;
};