#pragma once
#include "Text.h"

#define MAX_QUANTITY 4

class Window;

class MainMenu
{
public:
	MainMenu(sf::VideoMode resolution);

	void draw(sf::RenderWindow &window);

	void keyEvent(sf::Keyboard::Key key, Window &window);

	int getSelectedIndex();
private:
	int selected_index;
	Text text[MAX_QUANTITY];
};

