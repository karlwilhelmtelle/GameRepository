#include "Object.h"


Object::Object(sf::VideoMode resolution) :
	position(sf::Vector2f(resolution.width + 100, resolution.height/2)),
	size(sf::Vector2f(60, 60)),
	sf::RectangleShape()
{
	setSize(size);
	update();
	setFillColor(sf::Color::Red);
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