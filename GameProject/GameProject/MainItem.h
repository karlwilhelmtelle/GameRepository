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

		bool collision(sf::Vector2f obj_position, float obj_radius);
	private:
		/*  radius of MainItem */
		float radius;

		sf::Vector2f position;
};