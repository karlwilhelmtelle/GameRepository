#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"

struct ObjectContainer
{
	public:
		/*  vector of objects */
		std::vector<Object> v;

		void init(const sf::Color color);
		
		/*  loads all objects with position and radius from a file*/
		void load(const sf::VideoMode &resolution);

		/*  deletes if Object::notDrawable()
			checks for collision
			moves and updates all objects
		*/
		void update(sf::Vector2f item_position, float item_radius, 
			float camera_speed, bool *collision);

		void updateSettings(sf::Color color);
private:
	sf::Color color;
};