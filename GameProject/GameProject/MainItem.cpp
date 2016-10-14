#include "MainItem.h"

MainItem::MainItem(int resolution_x, int resolution_y) : 
	radius(40.f),
	x(resolution_x / 2 - (int)radius),
	y(resolution_y / 2 - radius)
{
	update();
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