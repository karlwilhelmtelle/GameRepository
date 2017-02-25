#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

class View;

class LevelMenu
{
public:
	LevelMenu(const sf::VideoMode &resolution);

	void draw(View &window);

	void keyEvent(sf::Keyboard::Key key, View &window);
	
	size_t getSelectedIndex();
private:
	size_t selectedIndex;
	std::vector<Text> items;
};

