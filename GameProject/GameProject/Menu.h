#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

class View;

enum MenuState
{
	MainMenu = 0,
	LevelMenu = 1,
	OptionsMenu = 2,
	HighscoreMenu = 3
};

class Menu
{
	public:
		Menu(const sf::VideoMode &resolution, const std::vector<size_t> settings);

		void draw(View &window) const;

		void keyEvent(const sf::Keyboard::Key key, View &window);

		void updateHighscore(const sf::Int32 highscore, const sf::Int32 lastScore);

		void setMenu(const MenuState type);

		sf::Vector2f getPosition(const MenuState menu, const sf::VideoMode res, 
			const size_t maxRows, const size_t maxCols,
			const size_t row, const size_t col) const;

		Text * getSelectedElement(const MenuState menu);
private:
	MenuState currentMenu;
	// item [menu] [row] [col]
	std::vector < std::vector < std::vector < Text > > > items;
	//selected row [Menu]
	std::vector < size_t > selectedRow;
	//selected col [Menu] [Row]
	std::vector < std::vector < size_t > > selectedCol;
};