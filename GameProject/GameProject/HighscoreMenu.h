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

	void updateElapsedTime();

	void updateHighscore();
	
private:
	Text highscore_menu_text;
	Text time_menu_text;
	Text text[MAX_QUANTITY_HIGHSCORE];
	
	int selected_index;

	sf::Int32 highscore_milliseconds;

	sf::Int32 time_milliseconds;

	sf::Clock clock;
};

