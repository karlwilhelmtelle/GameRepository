#include "Object.h"


Object::Object(sf::VideoMode resolution, sf::Vector2f position, float radius) :
	sf::CircleShape(),
	position(sf::Vector2f(resolution.width + position.x, position.y)),
	radius(radius)
{
	setRadius(radius);
	setFillColor(sf::Color::Red);
	update();
}


void Object::move(float dx)
{
	position.x += dx;
}


void Object::update()
{
	setPosition(position);
}


bool Object::notDrawable()
{
	return (position.x < -2*radius);
}


bool Object::collision(sf::Vector2f item_position, float item_radius)
{
	return (sqrt(
		pow((position.x + radius) - (item_position.x + item_radius), 2) +
		pow((position.y + radius) - (item_position.y + item_radius), 2))
		// Abstand zweier Mittelpunkte kleiner als (radius1 + radius2)
		< radius + item_radius);
}