#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
#include <vector>

#define SOUND_OPTION_QUANTITY 2
#define SOUND_MENU_QUANTITY 4
#define COLOUR_QUANTITY 8
#define COLOUR_QUANTITY_2 8

class View;

class OptionsMenu
{
public:
	OptionsMenu(const sf::VideoMode &resolution);

	void draw(View &window);

	void keyEvent(sf::Keyboard::Key key, View &window);

private:
	std::vector< std::vector < Text > > items;
	size_t line;
	std::vector < size_t > settings;
};

