#pragma once
#include <SFML/Graphics.hpp>


class Text : public sf::Text
{
public:
	Text();

	void setStringToTime(sf::Int32 milliseconds);
	
	void setStringToMilliseconds(sf::Int32 milliseconds);

	void enable();
	void disable();
	bool isDisabled();
private:
	sf::Font font;
	bool is_disabled;
};