#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

#define MAX_LEVEL_MENU_POINTS 4

class View;

class LevelMenu
{
public:
	LevelMenu(const sf::VideoMode &resolution);

	void draw(View &window);

	void keyEvent(sf::Keyboard::Key key, View &window);
	
	int getSelectedIndex();

	void disableIndex(int index);
	void enableIndex(int index);
private:
	int selectedIndex;
	Text text[MAX_LEVEL_MENU_POINTS];
};

