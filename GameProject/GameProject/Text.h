#pragma once
#include <SFML/Graphics.hpp>


class Text : public sf::Text
{
	public:
		Text();

		void setStringToTime(sf::Int32 milliseconds);
	private:
		sf::Font font;
};