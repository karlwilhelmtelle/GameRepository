#include "Game.h"

Game::Game()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Game", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false);
	Viewport viewport;
	
	sf::CircleShape shape;
	shape.setRadius(40);
	shape.setPosition(600, 600);
	shape.setFillColor(sf::Color::Cyan);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}


Game::~Game()
{

}


int main() 
{
	Game game;

	return 0;
}