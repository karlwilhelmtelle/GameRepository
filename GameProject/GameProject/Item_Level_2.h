#pragma once
#include <SFML/Graphics.hpp>

class Window;

class Item_Level_2 : public sf::CircleShape
{
public:
	/*	sets radius, position, fillColor */
	Item_Level_2(sf::VideoMode resolution);

	void keyEvent(sf::Keyboard::Key key, float camera_speed);
private:
	sf::VideoMode resolution;

	/*  radius */
	float radius;

	/*  x and y coordinates */
	sf::Vector2f position;
};