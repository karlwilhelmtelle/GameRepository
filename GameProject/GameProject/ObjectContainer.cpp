#include "ObjectContainer.h"
#include <string>

void ObjectContainer::load(const sf::VideoMode &res)
{
	v.clear();

	const int max_objects = 4;
	for (int i = 0; i < max_objects; ++i)
	{
		v.push_back(Object(res, 60, i * (float)(res.width) / (float)max_objects, color));
	}
}


void ObjectContainer::update(const sf::Vector2f item_position, const float item_radius, 
	const float camera_speed, bool *collision)
{
	for (auto object = v.begin(); object != v.end();)
	{
		if (!object->notDrawable())
		{
			// if collision: return
			if (object->collision(item_position, item_radius))
			{
				*collision = true;
				return;
			}

			object->move(-1 * camera_speed);

			++object; // go to next object
		}
		else // object is not drawable: delete it
		{
			object->refresh();
		}
	}
}

void ObjectContainer::updateSettings(const sf::Color newColor)
{
	if (newColor != color)
	{
		color = newColor;
		for (auto &e : v)
		{
			e.setFillColor(newColor);
		}
	}
}
