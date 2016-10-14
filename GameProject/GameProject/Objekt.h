#pragma once
#include <SFML/Graphics.hpp>
class Objekt : public sf::RectangleShape
{
public:
	Objekt();

	~Objekt();

	void move(float dx);

	void update();
private:
	sf::Vector2f position;
	sf::Vector2f size;
};

