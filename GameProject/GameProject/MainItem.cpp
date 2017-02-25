#include "MainItem.h"
#include "View.h"

MainItem::MainItem(const sf::VideoMode &resolution) : 
	sf::CircleShape(),
	resolution(resolution),
	radius(40.0f)
{
	resetAcceleration();
	setRadius(radius);
	init();
	setPosition(position);
	setFillColor(sf::Color::Cyan);
}


void MainItem::keyEvent(const sf::Keyboard::Key key, float camera_speed)
{
	if (key == sf::Keyboard::Up || key == sf::Keyboard::Down)
	{
		yVelocity = yAcceleration * camera_speed;
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

		/*if (yAcceleration > 200)
		{
			yAcceleration -= 5;
		}*/
	}
}

void MainItem::init()
{
	position = sf::Vector2f(resolution.width / 2 - radius,
		resolution.height / 2 - radius);
	setPosition(position);
}

void MainItem::updateSettings(const sf::Color color)
{
	setFillColor(color);
}

void MainItem::resetAcceleration()
{
	yAcceleration = 300.0f;
}
