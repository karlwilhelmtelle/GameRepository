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

	void updateTimeValues(sf::Int32 highscore, sf::Int32 last_score);
	
private:
	std::vector < std::vector < Text > > items;
	
	size_t selectedLineIndex;

	sf::Int32 highscoreMilli;
	sf::Int32 lastScoreMilli;
};

