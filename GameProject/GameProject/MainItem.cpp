#include "MainItem.h"

MainItem::MainItem(sf::VideoMode resolution) : 
	sf::CircleShape(),
	radius(40),
	position(sf::Vector2f(
		resolution.width / 2 - radius,
		resolution.height / 2 - radius))
{
	setRadius(radius);
	update();
}


void MainItem::move(float dy)
{
	position.y += dy;
}


void MainItem::update()
{
	setPosition(position);
	setFillColor(sf::Color::Cyan);
}


bool MainItem::collision(sf::Vector2f obj_position, float obj_radius)
{
	/*			// if rectangle is on the right
	if	(position.x + 2 * radius < circle_position.x ||
				// if rectangle is on the left
			position.x > rect_position.x + circle_radius
				// too close
		)
	{
		/*float m_x = position.x + radius;
		float m_y = position.y + radius;

		//A(rect_position.x, rect_position.y)
		//B(rect_position.x, rect_position.y + rect_size.y)
		//C(rect_position.x + rect_size.x, rect_position.y + rect_size.y)
		//D(rect_position.x + rect_size.x, rect_position.y)

		std::vector<float> distances;
		//MA, MB, MC, MD
		distances.push_back(sqrt(pow(rect_position.x - m_x, 2) + pow(rect_position.y - m_y, 2)));
		distances.push_back(sqrt(pow(rect_position.x - m_x, 2) + pow(rect_position.y + rect_size.y - m_y, 2)));
		distances.push_back(sqrt(pow(rect_position.x + rect_size.x - m_x, 2) + pow(rect_position.y + rect_size.y - m_y, 2)));
		distances.push_back(sqrt(pow(rect_position.x + rect_size.x - m_x, 2) + pow(rect_position.y - m_y, 2)));
		int min = *std::min_element(distances.begin(), distances.end());
		if (min <= (int)radius)
		{ 
			return true;
		}
		/*if ()
		{
			return true;
		}
	}
	return false;*/
	// M1(position.x + radius, position.y + radius)
	// M2(obj_position.x + obj_radius, obj_position.y + obj_radius)
	// M2 - M1
	return (sqrt(
		pow((obj_position.x + obj_radius) - (position.x + radius), 2) +
		pow((obj_position.y + obj_radius) - (position.y + radius), 2))
		< radius + obj_radius); // Abstand zweier Mittelpunkte kleiner als (radius1 + radius2)
}