#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"
#include <vector>

class View;

class OptionsMenu
{
public:
	OptionsMenu(const sf::VideoMode &resolution, const std::vector<size_t> settings);

	void draw(View &window) const;

	void keyEvent(const sf::Keyboard::Key key, View &window);

private:
	std::vector< std::vector < Text > > items;
	size_t selectedLineIndex;
	std::vector < size_t > settings;
};

