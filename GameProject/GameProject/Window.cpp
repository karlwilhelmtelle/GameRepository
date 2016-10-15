#include "Window.h"

Window::Window() :
	sf::RenderWindow(resolution,
		"Game", sf::Style::Fullscreen),
	resolution(sf::VideoMode::getDesktopMode()),
	item(resolution),
	camera_speed(0.3f)
{
	setMouseCursorVisible(false);
	map.load("", resolution);
}


Window::~Window()
{

}


void Window::render()
{
	clear(sf::Color::Black);
	draw(item);
	
	for (auto e = map.v.begin(); e != map.v.end(); ++e)
	{
		draw(*e);
	}

	display();
}


void Window::update(bool* collision) // depending on events
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