#include "MainItem.h"

MainItem::MainItem(sf::VideoMode resolution) : 
	sf::CircleShape(),
	resolution(resolution),
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


void MainItem::keyEvent(sf::Keyboard::Key key)
{
	float velocity = 10;
	// go up
	if (key == sf::Keyboard::Up &&
		position.y > 0)
	{
		position.y -= velocity;
	}
	// go down
	else if (key == sf::Keyboard::Down &&
		position.y < resolution.height - 2 * radius)
	{
		position.y += velocity;
	}
}