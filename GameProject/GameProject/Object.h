#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::CircleShape
{
public:
	/*	initializes sf::CircleShape
		sets position, radius, fillColor
	*/
	Object(sf::VideoMode resolution, sf::Vector2f position, float radius);

	/*  changes x-coordinate */
	void move(float dx);

	/*  checks if the x-coordinate is smaller than the diameter */
	bool notDrawable();

	/*  checks if the distance between two circle centers is less than the sum of both radii */
	bool collision(sf::Vector2f item_position, float item_radius);

	void refresh();
private:
	/*  x and y coordinates */
	sf::Vector2f position;
	sf::Vector2f position_start;

	/*  radius*/
	float radius;
};

