#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::RectangleShape
{
public:
	Object(sf::VideoMode resolution);

	~Object();

	void move(float dx);

	void update();
private:
	sf::Vector2f position;
	sf::Vector2f size;
};

