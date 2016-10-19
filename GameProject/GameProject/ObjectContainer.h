#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"

struct ObjectContainer
{
	public:
		/*  vector of objects */
		std::vector<Object> v;
		
		/*  loads all objects with position and radius from a file*/
		void load(sf::VideoMode resolution);

		/*  deletes if Object::notDrawable()
			checks for collision
			moves and updates all objects
		*/
		void update(sf::Vector2f item_position, float item_radius, 
			float camera_speed, bool *collision);
};