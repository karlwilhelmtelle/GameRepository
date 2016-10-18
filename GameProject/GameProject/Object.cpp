#include "Object.h"


Object::Object(sf::VideoMode resolution, sf::Vector2f pos, float radius) :
	sf::CircleShape(),
	position_start(sf::Vector2f(resolution.width + pos.x, pos.y)),
	radius(radius)
{
	refresh();
	setRadius(radius);
	setFillColor(sf::Color::Red);
}


void Object::move(float dx)
{
	position.x += dx;
	setPosition(position);
}


bool Object::notDrawable()
{
	return (position.x < -2*radius);
}


bool Object::collision(sf::Vector2f item_position, float item_radius)
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


void Object::refresh()
{
	position = position_start;
	setPosition(position);
}