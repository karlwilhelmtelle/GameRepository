#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class MainItem : public sf::CircleShape
{
	public:
		/*	sets radius and coordinates of MainItem */
		MainItem(sf::VideoMode resolution);

		/*	changing y-coordinate of MainItem */
		void move(float dy);
		
		/*  sets radius, position and color */
		void update();
	private:
		/*  radius of MainItem */
		float radius;
		
		/*  x and y coordinates of MainItem */
		sf::Vector2f position;
};