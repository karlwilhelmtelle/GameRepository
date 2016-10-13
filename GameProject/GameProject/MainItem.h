#pragma once
#include <SFML/Graphics.hpp>

class MainItem : public sf::CircleShape
{
	public:
		/*	sets radius and coordinates of MainItem */
		MainItem(int resolution_x, int resolution_y);

		/*	changing y-coordinate of MainItem */
		void move(float dy);
		
		/*  sets radius, position and color */
		void update();
	private:
		/*  radius of MainItem */
		float radius;

		/*  x-coordinate of MainItem */
		int x;

		/*  y-coordinate of MainItem */
		float y;
};