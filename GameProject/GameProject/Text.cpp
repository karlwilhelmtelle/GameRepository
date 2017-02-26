#include "Text.h"
#include <sstream>
#include <iostream>
#include <iomanip>

Text::Text(const unsigned int resHeight) :
	isEnabled(true),
	isSelected(false)
{
	if (!font.loadFromFile("Fonts/OpenSans-Bold.ttf"))
	{
		//Fehler beheben
	}
	setFont(font);
	setCharacterSize((int)(30.0f * resHeight / 1080.0f));
	setFillColor(sf::Color::White);
}


void Text::setStringToTime(const sf::Int32 milliseconds)
{
	setString(std::to_string(milliseconds / 1000) + "," + 
		std::to_string(milliseconds % 1000) + " s");
}

void Text::setStringToMilli(const sf::Int32 milliseconds)
{
	std::string s = std::to_string(milliseconds);
	setString(s);
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
		setFillColor(sf::Color::Red);
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
