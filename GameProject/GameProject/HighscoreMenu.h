#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

#define MAX_QUANTITY_HIGHSCORE 3


class View;

class HighscoreMenu
{
public:
	HighscoreMenu(const sf::VideoMode &resolution);

	void draw(View &window);

	void keyEvent(sf::Keyboard::Key key, View &window);

	int getSelectedIndex();
	
private:
	Text text[MAX_QUANTITY_HIGHSCORE];
	
	int selected_index;
};

