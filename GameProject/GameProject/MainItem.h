#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class MainItem : public sf::CircleShape
{
	public:
		/*	sets radius and coordinates */
		MainItem(sf::VideoMode resolution);

		/*	changes y-coordinate */
		void move(float dy);
		
		/*  sets radius, position, fillColor */
		void update();
	private:
		/*  radius */
		float radius;
		
		/*  x and y coordinates */
		sf::Vector2f position;
};