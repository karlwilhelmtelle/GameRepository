#include "Window.h"
#include "Object.h"

Window::Window(sf::VideoMode resolution) :
	sf::RenderWindow(resolution,
		"Game", sf::Style::Fullscreen),
	resolution(resolution),
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


void Window::update(bool *collision)
{
	sf::Vector2f item_position = item.getPosition();
	float item_radius = item.getRadius();

	map.update(item.getPosition(), item.getRadius(), camera_speed, collision, *this);
}


void Window::keyAction(sf::Keyboard::Key key)
{
	if (show_menu)
	{
		menu.keyEvent(key, *this);
	}
	else
	{
		item.keyEvent(key, *this);
	}
}


void Window::showMenu()
{
	show_menu = true;
}


void Window::hideMenu()
{
	show_menu = false;
}