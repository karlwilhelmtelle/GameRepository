#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::CircleShape
{
public:
	/*	initializes sf::CircleShape
		sets position, radius, fillColor
	*/
	Object(const sf::VideoMode &resolution, float radius, float x_offset, sf::Color color);

	/*  random y-coordinate */
	void refresh();

	/*  changes x-coordinate */
	void move(float dx);

	/*  checks if the x-coordinate is smaller than the diameter */
	bool notDrawable();

	/*  checks if the distance between two circle centers is less than the sum of both radii */
	bool collision(sf::Vector2f item_position, float item_radius);
private:
	/*  x and y coordinates */
	sf::Vector2f position;

	/*  radius*/
	float radius;

	float x_offset;

	const sf::VideoMode &resolution;
};

