#pragma once
#include "Text.h"

#define MAX_QUANTITY 3

class Window;

class MainMenu
{
public:
	MainMenu(sf::VideoMode resolution);
	~MainMenu();

	void draw(sf::RenderWindow &window);

	void keyEvent(sf::Keyboard::Key key, Window &window);

	int getSelectedIndex();
private:
		/* oben = 0, mitte = 1, unten = 2 */
		int selectedIndex;
		Text textMainMenu[MAX_QUANTITY];
};

