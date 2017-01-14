#include "Text.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Text::Text() :
	is_disabled(false)
{
	if (!font.loadFromFile("OpenSans-Bold.ttf"))
	{
		//Fehler beheben
	}
	setFont(font);
}


void Text::setStringToTime(sf::Int32 milliseconds)
{
	std::stringstream os;
	os << std::setfill('0') << std::setw(2) << milliseconds / (1000 * 60);
	os << ":";
	os << std::setfill('0') << std::setw(2) << (milliseconds % (1000 * 60)) / 1000;
	os << ":";
	os << std::setfill('0') << std::setw(3) << milliseconds % 1000;

	setString(os.str());
}

void Text::setStringToMilliseconds(sf::Int32 milliseconds)
{
	std::stringstream os;
	os << milliseconds;

	setString(os.str());
}

void Text::enable()
{
	is_disabled = false;
	setFillColor(sf::Color::White);
}

void Text::disable()
{
	is_disabled = true;
	setFillColor(sf::Color::Red);
}

bool Text::isDisabled()
{
	return is_disabled;
}
