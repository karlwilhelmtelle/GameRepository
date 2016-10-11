#include "Window.h"

Window::Window() :
	resolution(sf::VideoMode::getDesktopMode()),
	sf::RenderWindow(resolution, 
		"Game", sf::Style::Fullscreen),
	item(resolution.width, resolution.height)
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
	display();
}


void Window::update() // depending on events
{
	item.move(0);

	if (true) // if no collision then update the main item
	{
		item.update();
	}
}