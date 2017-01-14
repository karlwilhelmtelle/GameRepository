#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

#define MAX_QUANTITY_HIGHSCORE 3


class Window;

class HighscoreMenu
{
public:
	HighscoreMenu(sf::VideoMode resolution);

	void draw(sf::RenderWindow &window);

	void keyEvent(sf::Keyboard::Key key, Window &window);

	int getSelectedIndex();
	
private:
	Text text[MAX_QUANTITY_HIGHSCORE];
	
	int selected_index;
};

