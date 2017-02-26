#include "MainItem.h"
#include "View.h"

MainItem::MainItem(const sf::VideoMode &resolution) : 
	sf::CircleShape(),
	resolution(resolution),
	radius(40.0f * 1080.0f / resolution.height)
{
	updatePhysics();
	setRadius(radius);
	init();
	setFillColor(sf::Color::Cyan);
	clock.restart();
}


void MainItem::keyEvent(const sf::Keyboard::Key key, float cameraSpeed)
{
	bool up		= (key == sf::Keyboard::Up || key == sf::Keyboard::W);
	bool down	= (key == sf::Keyboard::Down || key == sf::Keyboard::S);

	if (up || down)
	{
		yVelocity = yAcceleration * cameraSpeed;
		// go up
		if (up)
		{
			position.y = std::max(0.0f, position.y - yVelocity);
		}
		// go down
		else if (down)
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
