#include "Objekt.h"
#include "Game.h"
#include "Window.h"


Objekt::Objekt() :
	x(600),
	y(600),
	sf::RectangleShape(sf::Vector2f(x, y))
{
	setFillColor(sf::Color::Red);
}


Objekt::~Objekt()
{
	
}


void Objekt::move(float dx)
{
	setPosition(x + dx, y);
}