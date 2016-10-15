#pragma once
#include "SFML/Graphics.hpp"

#define MAX_QUANTITY 3

class MainMenu
{
public:
	MainMenu(float width, float heigth);
	~MainMenu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();

private:
		/* oben = 0, mitte = 1, unten = 2 */
		int selectedIndex;
		sf::Font fontMainMenu;
		sf::Text textMainMenu[MAX_QUANTITY];
};

