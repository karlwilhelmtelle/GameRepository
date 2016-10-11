#include "Game.h"

Game::Game()
{
	Window window;
	window.setMouseCursorVisible(false);
	Viewport viewport;
	level = 1;
	

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


void Game::start()
{
	
}


int main() 
{
	Game game;
	game.start();

	return 0;
}