#include "Text.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Text::Text() :
	enabled(true),
	selected(false)
{
	if (!font.loadFromFile("Fonts/OpenSans-Bold.ttf"))
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
	if (!enabled)
	{
		enabled = true;
		setFillColor(sf::Color::White);
	}
}

void Text::disable()
{
	if (enabled)
	{
		enabled = false;
		deselect();
		setFillColor(sf::Color::Red);
	}
}

bool Text::isEnabled()
{
	return enabled;
}

void Text::select()
{
	if (!selected)
	{
		selected = true;
		setFillColor(sf::Color::Yellow);
	}
}

void Text::deselect()
{
	if (selected)
	{
		selected = false;
		setFillColor(sf::Color::White);
	}
}
