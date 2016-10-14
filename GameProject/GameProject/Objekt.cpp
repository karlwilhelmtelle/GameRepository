#include "Objekt.h"
#include "Game.h"
#include "Window.h"


Objekt::Objekt() :
	position(sf::Vector2f(600, 600)),
	size(sf::Vector2f(20, 20)),
	sf::RectangleShape(size)
{
	update();
	setFillColor(sf::Color::Red);
}


Objekt::~Objekt()
{
	
}


void Objekt::move(float dx)
{
	position.x += dx;
}


void Objekt::update()
{
	setPosition(size);
}