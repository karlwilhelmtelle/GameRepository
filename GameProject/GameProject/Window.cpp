#include "Window.h"

Window::Window() :
	resolution(sf::VideoMode::getDesktopMode()),
	sf::RenderWindow(resolution, 
		"Game", sf::Style::Fullscreen),
	item(resolution),
	circle(resolution),
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
	draw(circle);
	display();
}


bool Window::update() // depending on events
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

	circle.move(camera_speed * -1);

	// check collision
	// if circle is on the right
	if (!item.collision(circle.getPosition(), circle.getRadius()))
	{
		item.update();
		circle.update();
	}
	else
	{
		return true;
		//collision
	}
	return false;
}