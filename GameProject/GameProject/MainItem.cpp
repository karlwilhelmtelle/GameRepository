#include "MainItem.h"

MainItem::MainItem(sf::VideoMode resolution) : 
	sf::CircleShape(),
	radius(40),
	position(sf::Vector2f(
		resolution.width / 2 - radius,
		resolution.height / 2 - radius))
{
	setRadius(radius);
	update();
}


void MainItem::move(float dy)
{
	position.y += 0.2f*dy;
}


void MainItem::update()
{
	setPosition(position);
	setFillColor(sf::Color::Cyan);
}