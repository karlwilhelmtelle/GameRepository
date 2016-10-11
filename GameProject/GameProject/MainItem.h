#pragma once
#include <SFML/Graphics.hpp>

class MainItem : public sf::CircleShape
{
	public:
		MainItem(int resolution_x, int resolution_y);
		void move(float dy);
		void update();
	private:
		float radius;
		int x;
		float y;
};