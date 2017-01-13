#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

#define MAX_LEVEL_MENU_POINTS 5

class Window;

class LevelMenu
{
public:
	LevelMenu(sf::VideoMode resolution);

	void draw(sf::RenderWindow &window);

	void keyEvent(sf::Keyboard::Key key, Window &window);

	int getSelectedIndex();
private:
	int selected_index;
	Text text[MAX_LEVEL_MENU_POINTS];
};

