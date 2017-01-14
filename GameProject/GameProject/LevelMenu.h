#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

#define MAX_LEVEL_MENU_POINTS 4

class Window;

class LevelMenu
{
public:
	LevelMenu(sf::VideoMode &resolution);

	void draw(Window &window);

	void keyEvent(sf::Keyboard::Key key, Window &window);
	
	int getSelectedIndex();

	void disableIndex(int index);
	void enableIndex(int index);
private:
	int selected_index;
	Text text[MAX_LEVEL_MENU_POINTS];
};

