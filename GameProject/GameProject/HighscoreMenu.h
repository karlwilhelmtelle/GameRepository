#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Level.h"

#define MAX_QUANTITY_HIGHSCORE 3

class View;

class HighscoreMenu
{
public:
	HighscoreMenu(const sf::VideoMode &resolution);

	void draw(View &window);

	void keyEvent(sf::Keyboard::Key key, View &window);

	int getSelectedIndex();

	void updateTimeValues(sf::Int32 highscore, sf::Int32 last_score);
	
private:
	Text last_score_value;
	Text highscore_value;
	Text text[MAX_QUANTITY_HIGHSCORE];
	
	int selected_index;

	sf::Int32 highscore_milliseconds;

	sf::Int32 last_score_milliseconds;
};

