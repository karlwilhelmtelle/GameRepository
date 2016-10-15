#pragma once
#include "Object.h"

struct ObjectContainer
{
	std::vector<Object> v;
		
	/*  loading all objects with position and radius from a file*/
	void load(std::string filename, sf::VideoMode resolution);

	/*  deleting if Object::notDrawable()
		check collision
		move and update all objects
	*/
	void update(sf::Vector2f item_position, float item_radius, float camera_speed, bool* collision);
};