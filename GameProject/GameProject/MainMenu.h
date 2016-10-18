#pragma once
#include <SFML/Graphics.hpp>

#define MAX_QUANTITY 3

class Window;

class MainMenu
{
public:
	MainMenu(sf::VideoMode resolution);
	~MainMenu();

	void draw(sf::RenderWindow &window);

	void keyEvent(sf::Keyboard::Key key);
private:
		/* oben = 0, mitte = 1, unten = 2 */
		int selectedIndex;
		sf::Font fontMainMenu;
		sf::Text textMainMenu[MAX_QUANTITY];
};

