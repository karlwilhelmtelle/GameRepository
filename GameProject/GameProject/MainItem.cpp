#include "MainItem.h"

MainItem::MainItem(sf::VideoMode resolution) : 
	radius(40.f),
	position(sf::Vector2f(
		resolution.width / 2 - radius,
		resolution.height / 2 - radius))
{
}


void MainItem::move(float dy)
{
	position.y += dy;
}


void MainItem::update()
{
	setRadius(radius);
	setPosition(position);
	setFillColor(sf::Color::Cyan);
}