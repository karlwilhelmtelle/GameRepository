#pragma once
#include <SFML/Graphics.hpp>

class Window;

class MainItem_Level2 : public sf::CircleShape
{
public:
	/*	sets radius, position, fillColor */
	MainItem_Level2(sf::VideoMode resolution);

	void keyEvent(sf::Keyboard::Key key, float camera_speed);
private:
	sf::VideoMode resolution;

	/*  radius */
	float radius;

	/*  x and y coordinates */
	sf::Vector2f position;
};