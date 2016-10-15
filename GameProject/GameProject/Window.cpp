#include "Window.h"

Window::Window() :
	sf::RenderWindow(resolution,
		"Game", sf::Style::Fullscreen),
	resolution(sf::VideoMode::getDesktopMode()),
	menu(resolution),
	item(resolution),
	camera_speed(0.3f),
	show_menu(true)
{
	setMouseCursorVisible(false);
	map.load("", resolution);
}


void Window::render()
{
	clear(sf::Color::Black);

	if (show_menu)
	{
		menu.draw(*this);
	}
	else
	{
		draw(item);

		for (auto e = map.v.begin(); e != map.v.end(); ++e)
		{
			draw(*e);
		}
	}

	display();
}


void Window::update(bool* collision)
{
	sf::Vector2f item_position = item.getPosition();
	float item_radius = item.getRadius();

	// go up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		item_position.y > 0)	// top of screen
	{
		item.move(-1);
	}

	// go down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		// bottom of screen
		item_position.y < resolution.height - 2*item_radius)
	{
		item.move(+1);
	}

	map.update(item.getPosition(), item.getRadius(), camera_speed, collision);
	item.update();
}