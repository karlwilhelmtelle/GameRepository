#include "Object.h"


Object::Object(sf::VideoMode resolution) :
	position(sf::Vector2f((float)resolution.width + 100, (float)resolution.height/2)),
	radius(60),
	sf::CircleShape()
{
	setRadius(radius);
	setFillColor(sf::Color::Red);
	update();
}


Object::~Object()
{
	
}


void Object::move(float dx)
{
	position.x += dx;
}


void Object::update()
{
	setPosition(position);
}