#include "Window.h"

Window::Window() : 
	sf::RenderWindow(sf::VideoMode::getDesktopMode(), 
		"Game", sf::Style::Fullscreen)
{
}


Window::~Window()
{

}