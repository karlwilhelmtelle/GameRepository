#pragma once
#include <SFML/Graphics.hpp>

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

		sf::Vector2f position;
};