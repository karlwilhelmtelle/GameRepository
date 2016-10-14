#pragma once
#include <SFML/Graphics.hpp>
class Objekt : public sf::RectangleShape
{
public:
	Objekt();

	~Objekt();

	void move(float dx);
private:
	float x;
	float y;
};

