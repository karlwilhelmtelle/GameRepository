#pragma once
#include "Text.h"

#define MAX_QUANTITY 4

class View;

class MainMenu
{
public:
	MainMenu(const sf::VideoMode &resolution);

	void draw(View &window);

	void keyEvent(sf::Keyboard::Key key, View &window);

	int getSelectedIndex();
private:
	size_t selectedIndex;
	std::vector < Text > items;
};

