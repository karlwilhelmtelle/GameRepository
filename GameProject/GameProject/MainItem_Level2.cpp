#include "MainItem_Level2.h"
#include "Window.h"

MainItem_Level2::MainItem_Level2(sf::VideoMode resolution):
	sf::CircleShape(),
	resolution(resolution),
	radius(40),
	position(sf::Vector2f(	resolution.width / 2 - radius,
							resolution.height / 2 - radius))
{
	setRadius(radius);
	setPosition(position);
	setFillColor(sf::Color::Green);
}

void MainItem_Level2::keyEvent(sf::Keyboard::Key key, float camera_speed)
{
	//wenn keine Taste gedrückt wird fällt das Objekt
	//wird 'Up' gedrückt geht das Objekt kurz nach oben

	float dy = 100 * camera_speed;
	float gravity = 0.1f;
	float upForce = 10;
	bool a = 0;
	if (a == 0)
	{
		position.y -= gravity;
		if (key == sf::Keyboard::Up)
		{
			a = 1;
			position.y += upForce;
			a = 0;
		}
		setPosition(position);
	}

		
}




