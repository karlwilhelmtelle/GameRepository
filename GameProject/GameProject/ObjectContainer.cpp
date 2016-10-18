#include "ObjectContainer.h"
#include <string>

void ObjectContainer::load(std::string filename, sf::VideoMode res)
{
	resolution = res;
	v.push_back(Object(resolution, sf::Vector2f(20 + 1000, 600), 60.f));
}


void ObjectContainer::update(sf::Vector2f item_position, float item_radius, 
	float camera_speed, bool *collision)
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