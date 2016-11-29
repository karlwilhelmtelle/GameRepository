#include "LevelMenu.h"
#include "Window.h"

LevelMenu::LevelMenu(sf::VideoMode resolution):
	selectedLevelIndex(0)
{
	if (!fontLevelMenu.loadFromFile("OpenSans-Bold.ttf"))
	{
		//Fehler beheben
	}

	for (int i = 0; i < MAX_LEVEL_MENU_POINTS; i++)
	{
		textLevelMenu[i].setFont(fontLevelMenu);
		textLevelMenu[i].setFillColor(sf::Color::White);
		textLevelMenu[i].setString("Level " + std::to_string(i+1));
		textLevelMenu[i].setPosition(sf::Vector2f((float)resolution.width / 2.5,
			(float)resolution.height / (MAX_LEVEL_MENU_POINTS + 1) * (i+1)));
	}
	textLevelMenu[0].setFillColor(sf::Color::Yellow);
}


LevelMenu::~LevelMenu()
{
}

void LevelMenu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_LEVEL_MENU_POINTS; i++)
	{
		window.draw(textLevelMenu[i]);
	}
}

void LevelMenu::keyEvent(sf::Keyboard::Key key, Window & window)
{
	// move up
	if (key == sf::Keyboard::Up && selectedLevelIndex - 1 >= 0)
	{
		textLevelMenu[selectedLevelIndex].setFillColor(sf::Color::White);
		selectedLevelIndex--;
		textLevelMenu[selectedLevelIndex].setFillColor(sf::Color::Yellow);
	}
	// move down
	else if (key == sf::Keyboard::Down && selectedLevelIndex + 1 < MAX_LEVEL_MENU_POINTS)
	{
		textLevelMenu[selectedLevelIndex].setFillColor(sf::Color::White);
		selectedLevelIndex++;
		textLevelMenu[selectedLevelIndex].setFillColor(sf::Color::Yellow);
	}

	//enter
	if (key == sf::Keyboard::Return)
	{
		window.playLevel(selectedLevelIndex);
	}
	else if (key == sf::Keyboard::Escape)
	{
		window.showMenu();
	}
}

int LevelMenu::getSelectedLevelIndex()
{
	return selectedLevelIndex;
}
