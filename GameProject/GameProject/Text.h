#pragma once
#include <SFML/Graphics.hpp>


class Text : public sf::Text
{
	public:
		Text();

	private:
		sf::Font font;
};