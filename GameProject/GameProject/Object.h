#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::CircleShape
{
public:
	Object(sf::VideoMode resolution, sf::Vector2f position, float radius);

	~Object();

	void move(float dx);

	void update();

	bool notDrawable();

	bool collision(sf::Vector2f item_position, float item_radius);
private:
	sf::Vector2f position;

	float radius;
};

