#pragma once
#include "Text.h"

class View;

class MainMenu
{
	public:
		MainMenu(const sf::VideoMode &resolution);

		void draw(View &window) const;

		void keyEvent(const sf::Keyboard::Key key, View &window);
	private:
		size_t selectedLineIndex;
		std::vector < Text > items;
};

