#include "Text.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Text::Text() :
	isEnabled(true),
	isSelected(false)
{
	if (!font.loadFromFile("Fonts/OpenSans-Bold.ttf"))
	{
		//Fehler beheben
	}
	setFont(font);

	setFillColor(sf::Color::White);
}


void Text::setStringToTime(const sf::Int32 milliseconds)
{
	std::stringstream os;
	os << std::setfill('0') << std::setw(2) << milliseconds / (1000 * 60);
	os << ":";
	os << std::setfill('0') << std::setw(2) << (milliseconds % (1000 * 60)) / 1000;
	os << ":";
	os << std::setfill('0') << std::setw(3) << milliseconds % 1000;

	setString(os.str());
}

void Text::setStringToMilliseconds(const sf::Int32 milliseconds)
{
	std::stringstream os;
	os << milliseconds;

	setString(os.str());
}

void Text::enable()
{
	if (!isEnabled)
	{
		isEnabled = true;
		setFillColor(sf::Color::White);
	}
}

void Text::disable()
{
	if (isEnabled)
	{
		isEnabled = false;
		deselect();
		setFillColor(sf::Color::Red);
	}
}

bool Text::enabled() const
{
	return isEnabled;
}

void Text::select()
{
	if (!isSelected)
	{
		isSelected = true;
		setFillColor(sf::Color::Yellow);
	}
}

void Text::deselect()
{
	if (isSelected)
	{
		isSelected = false;
		setFillColor(sf::Color::White);
	}
}
