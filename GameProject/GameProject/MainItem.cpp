#include "MainItem.h"
#include "Window.h"

MainItem::MainItem(sf::VideoMode resolution) : 
	sf::CircleShape(),
	resolution(resolution),
	radius(40),
	position(sf::Vector2f(	resolution.width / 2 - radius,
							resolution.height / 2 - radius))
{
	setRadius(radius);
	setPosition(position);
	setFillColor(sf::Color::Cyan);
}


void MainItem::keyEvent(sf::Keyboard::Key key, float camera_speed)
{
	if (key == sf::Keyboard::Up || key == sf::Keyboard::Down)
	{
		float dy = 100*camera_speed;
		// go up
		if (key == sf::Keyboard::Up &&
			position.y > 0 + radius / 4)
		{
			position.y -= dy;
		}
		// go down
		else if (key == sf::Keyboard::Down &&
			position.y < resolution.height - 9 * radius / 4)
		{
			position.y += dy;
		}

		setPosition(position);
	}
}