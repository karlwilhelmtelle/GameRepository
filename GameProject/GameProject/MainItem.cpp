#include "MainItem.h"
#include "View.h"

MainItem::MainItem(const sf::VideoMode &resolution) : 
	sf::CircleShape(),
	resolution(resolution),
	radius(40.0f)
{
	updatePhysics();
	setRadius(radius);
	init();
	setFillColor(sf::Color::Cyan);
	clock.restart();
}


void MainItem::keyEvent(const sf::Keyboard::Key key, float cameraSpeed)
{
	if (key == sf::Keyboard::Up || key == sf::Keyboard::Down)
	{
		yVelocity = yAcceleration * cameraSpeed;
		// go up
		if (key == sf::Keyboard::Up)
		{
			position.y = std::max(0.0f, position.y - yVelocity);
		}
		// go down
		else if (key == sf::Keyboard::Down)
		{
			position.y = std::min(position.y + yVelocity, resolution.height - 2*radius);
		}
		setPosition(position);

		if (yAcceleration > 200)
		{
			yAcceleration -= 50;
		}

		clock.restart();
	}
}

void MainItem::init()
{
	position = sf::Vector2f(resolution.width / 4 - radius,
		resolution.height / 2 - radius);
	setPosition(position);
}

void MainItem::updateSettings(const sf::Color color)
{
	setFillColor(color);
}

void MainItem::updatePhysics()
{
	if (clock.getElapsedTime().asMilliseconds() >= 100) //if time difference is over 100 ms
	{
		yAcceleration = 400.0f;
	}
}
