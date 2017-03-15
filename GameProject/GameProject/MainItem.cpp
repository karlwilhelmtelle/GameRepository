#include "MainItem.h"
#include "View.h"

MainItem::MainItem(const sf::VideoMode &resolution) : 
	sf::CircleShape(),
	resolution(resolution),
	radius(40.0f * resolution.height / 1080.0f),
	yVelocity(180.0f * resolution.height / 1080.0f)
{
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