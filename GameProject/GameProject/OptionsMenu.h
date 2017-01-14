#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

#define SOUND_OPTION_QUANTITY 2
#define SOUND_MENU_QUANTITY 3
#define COLOUR_QUANTITY 8
#define COLOUR_QUANTITY_2 8

class Window;
class OptionsMenu
{
public:
	OptionsMenu(sf::VideoMode &resolution);

	void draw(Window &window);

	void keyEvent(sf::Keyboard::Key key, Window &window);

	int getLine();

	int getColumn();

private:
	Text s_o_Menu[SOUND_OPTION_QUANTITY];
	Text s_o_Points[SOUND_MENU_QUANTITY];
	Text s_o_Colours[COLOUR_QUANTITY];
	Text s_o_Colours2[COLOUR_QUANTITY_2];
	int line;
	int column;
};

