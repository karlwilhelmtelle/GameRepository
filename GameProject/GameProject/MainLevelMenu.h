#pragma once
#include <SFML/Graphics.hpp>

#define MAX_LEVEL_MENU_POINTS 5

class Window;

class MainLevelMenu
{
public:
	MainLevelMenu(sf::VideoMode resolution);
	~MainLevelMenu();

	void draw(sf::RenderWindow &window);

	void keyEvent(sf::Keyboard::Key key, Window &window);

	int getSelectedLevelIndex();
private:
	int selectedLevelIndex;
	sf::Font fontMainLevelMenu;
	sf::Text textMainLevelMenu[MAX_LEVEL_MENU_POINTS];
};

