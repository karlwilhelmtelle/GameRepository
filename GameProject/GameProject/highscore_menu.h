#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

#define MAX_QUANTITY_HIGHSCORE 3
#define SOUND_OPTION_QUANTITY 2

class Window;

class highscore_menu
{
public:
	~highscore_menu();
	highscore_menu(sf::VideoMode resolution);

	void draw(sf::RenderWindow &window);

	void keyEvent(sf::Keyboard::Key key, Window &window);

	int getSelectedIndex();
	
private:
	Text textHighscore_menu[MAX_QUANTITY_HIGHSCORE];
	Text s_o_Highscore_menu[SOUND_OPTION_QUANTITY];

	int selectedIndexHighscore;
};

