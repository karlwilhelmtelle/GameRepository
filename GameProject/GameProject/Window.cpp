#include "Window.h"
#include "Object.h"

Window::Window(sf::VideoMode res) :
	sf::RenderWindow(res,
		"Game", sf::Style::Fullscreen),
	menu(res),
	item(res),
	camera_speed(0.1f),
	show_menu(true)
{
	setMouseCursorVisible(false);
	map.load("", res);
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
	camera_speed *= 1.00001f;
	map.update(item.getPosition(), item.getRadius(), camera_speed, collision);
}


void Window::keyAction(sf::Keyboard::Key key)
{
	if (show_menu)
	{
		menu.keyEvent(key);
	}
	else
	{
		item.keyEvent(key, camera_speed);
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