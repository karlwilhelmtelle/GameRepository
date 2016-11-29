#pragma once
#include <SFML/Graphics.hpp>

#define MAX_LEVEL_MENU_POINTS 5

class Window;

class LevelMenu
{
public:
	LevelMenu(sf::VideoMode resolution);
	~LevelMenu();

	void draw(sf::RenderWindow &window);

	void keyEvent(sf::Keyboard::Key key, Window &window);

	int getSelectedLevelIndex();
private:
	int selectedLevelIndex;
	sf::Font fontLevelMenu;
	sf::Text textLevelMenu[MAX_LEVEL_MENU_POINTS];
};

