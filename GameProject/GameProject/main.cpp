#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>

int main() {

	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Game", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false);

	sf::CircleShape shape;
	shape.setRadius(40.f);
	shape.setPosition(600, 600);
	shape.setFillColor(sf::Color::Cyan);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

}