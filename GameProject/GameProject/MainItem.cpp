#include "MainItem.h"
#include "Window.h"

MainItem::MainItem(sf::VideoMode resolution) : 
	sf::CircleShape(),
	resolution(resolution),
	radius(40),
	position(sf::Vector2f(
		resolution.width / 2 - radius,
		resolution.height / 2 - radius))
{
	setRadius(radius);
	setPosition(position);
	setFillColor(sf::Color::Cyan);
}


void MainItem::keyEvent(sf::Keyboard::Key key, Window &window)
{
	float velocity = 50;
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

	setPosition(position);

	window.render();
}