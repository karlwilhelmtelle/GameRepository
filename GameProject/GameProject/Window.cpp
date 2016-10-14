#include "Window.h"

Window::Window() :
	resolution(sf::VideoMode::getDesktopMode()),
	sf::RenderWindow(resolution, 
		"Game", sf::Style::Fullscreen),
	item(resolution),
	rect(resolution),
	camera_speed(0.3f)
{
	setMouseCursorVisible(false);
}


Window::~Window()
{
}


void Window::render()
{
	clear(sf::Color::Black);
	draw(item);
	draw(rect);
	display();
}


void Window::update() // depending on events
{
	float y = item.getPosition().y;

	// go up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
		y > 0)	// top of screen
	{
		item.move(-1);
	}

	// go down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
		// bottom of screen
		y < resolution.height - 2* item.getRadius())
	{
		item.move(+1);
	}
	
	rect.move(camera_speed * -1);
	rect.update();

	if (true) // if no collision then update the main item
	{
		item.update();
	}
}