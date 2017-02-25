#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

class View;

class LevelMenu
{
public:
	LevelMenu(const sf::VideoMode &resolution);

	void draw(View &window) const;

	void keyEvent(const sf::Keyboard::Key key, View &window);
private:
	size_t selectedLineIndex;
	std::vector<Text> items;
};

