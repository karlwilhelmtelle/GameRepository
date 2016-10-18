#include "ObjectContainer.h"
#include <string>
#include "Window.h"

void ObjectContainer::load(std::string filename, sf::VideoMode resolution)
{
	v.push_back(Object(resolution, sf::Vector2f(20, 600), 60.f));
}


void ObjectContainer::update(sf::Vector2f item_position, float item_radius, 
	float camera_speed, bool *collision, Window &window)
{
	for (auto object = v.begin(); object != v.end();)
	{
		if (!object->notDrawable())
		{
			// if collision: return
			// check if x-coordinates are close
			if (object->collision(item_position, item_radius))
			{
				*collision = true;
				return;
			}

			object->move(camera_speed * -1);
			object->update();

			++object; // go to next object
		}
		else // object is not drawable: delete it
		{
			object = v.erase(object);
		}
	}

	window.render();
}