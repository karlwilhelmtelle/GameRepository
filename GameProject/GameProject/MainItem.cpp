#include "MainItem.h"

MainItem::MainItem(int resolution_x, int resolution_y) : 
	radius(40),
	x(resolution_x / 2 - radius),
	y(resolution_y / 2 - radius)
{
}


void MainItem::move(float dy)
{
	y = y + dy;
}


void MainItem::update()
{
	setRadius(radius);
	setPosition(x, y);
	setFillColor(sf::Color::Cyan);
}