#pragma once
#include <SFML/Graphics.hpp>

class View;

class MainItem_Level2 : public sf::CircleShape
{
public:
	/*	sets radius, position, fillColor */
	MainItem_Level2(const sf::VideoMode &resolution);

	void keyEvent(const sf::Keyboard::Key key, const float camera_speed);
private:
	const sf::VideoMode &resolution;

	/*  radius */
	float radius;

	/*  x and y coordinates */
	sf::Vector2f position;
};