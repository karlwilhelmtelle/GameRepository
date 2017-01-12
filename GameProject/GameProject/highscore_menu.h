#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

#define MAX_QUANTITY_HIGHSCORE 2


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
	
	int selectedIndexHighscore;
};

