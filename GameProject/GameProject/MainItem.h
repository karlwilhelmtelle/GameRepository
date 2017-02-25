#pragma once
#include <SFML/Graphics.hpp>

class View;

class MainItem : public sf::CircleShape
{
	public:
		/*	sets radius, position, fillColor */
		MainItem(const sf::VideoMode &resolution);

		void keyEvent(const sf::Keyboard::Key key, float camera_speed);

		void init();
		void updateSettings(const sf::Color color);
		void updatePhysics();
	private:
		const sf::VideoMode &resolution;

		/*  radius */
		float radius;
		sf::Clock clock;
		
		/*  x and y coordinates */
		sf::Vector2f position;
		float yVelocity;
		float yAcceleration;
};