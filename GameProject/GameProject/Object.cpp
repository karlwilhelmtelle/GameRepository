#include "Object.h"
#include <random>

Object::Object(const sf::VideoMode &resolution, const float radius, 
	const float x_offset, const sf::Color color) :
		sf::CircleShape(),
		radius(radius),
		resolution(resolution),
		x_offset(x_offset)
{
	refresh();
	setRadius(radius);
	setFillColor(color);
}


void Object::refresh()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0, (int)(resolution.height - 2 * radius));

	position = sf::Vector2f(resolution.width + x_offset, (float)uni(rng));
	setPosition(position);
}


void Object::move(const float dx)
{
	position.x += dx;
	setPosition(position);
}


bool Object::notDrawable() const
{
	return (position.x < -2*radius);
}

// TODO: fix collision bugs
bool Object::collision(const sf::Vector2f item_position, const float item_radius)
{
	if (abs(position.x - item_position.x) < radius + item_radius &&
		abs(position.y - item_position.y) < radius + item_radius)
	{
		if (sqrt(
			pow((position.x + radius) - (item_position.x + item_radius), 2) +
			pow((position.y + radius) - (item_position.y + item_radius), 2))
			// Abstand zweier Mittelpunkte kleiner als (radius1 + radius2)
			< radius + item_radius)
		{
			return true;
		}
	}
	return false;
}