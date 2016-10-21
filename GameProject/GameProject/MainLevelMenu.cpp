#include "MainLevelMenu.h"
#include "Window.h"

MainLevelMenu::MainLevelMenu(sf::VideoMode resolution):
	selectedLevelIndex(0)
{
	if (!fontMainLevelMenu.loadFromFile("OpenSans-Bold.ttf"))
	{
		//Fehler beheben
	}
	textMainLevelMenu[0].setFont(fontMainLevelMenu);
	textMainLevelMenu[0].setFillColor(sf::Color::Yellow);
	textMainLevelMenu[0].setString("Levl 1");
	textMainLevelMenu[0].setPosition(sf::Vector2f((float)resolution.width / 2.5,
		(float)resolution.height / (MAX_LEVEL_MENU_POINTS + 1) * 1));

	textMainLevelMenu[1].setFont(fontMainLevelMenu);
	textMainLevelMenu[1].setFillColor(sf::Color::White);
	textMainLevelMenu[1].setString("Level 2");
	textMainLevelMenu[1].setPosition(sf::Vector2f((float)resolution.width / 2.5,
		(float)resolution.height / (MAX_LEVEL_MENU_POINTS + 1) * 2));

	textMainLevelMenu[2].setFont(fontMainLevelMenu);
	textMainLevelMenu[2].setFillColor(sf::Color::White);
	textMainLevelMenu[2].setString("Level 3");
	textMainLevelMenu[2].setPosition(sf::Vector2f((float)resolution.width / 2.5,
		(float)resolution.height / (MAX_LEVEL_MENU_POINTS + 1) * 3));

	textMainLevelMenu[3].setFont(fontMainLevelMenu);
	textMainLevelMenu[3].setFillColor(sf::Color::White);
	textMainLevelMenu[3].setString("Level 4");
	textMainLevelMenu[3].setPosition(sf::Vector2f((float)resolution.width / 2.5,
		(float)resolution.height / (MAX_LEVEL_MENU_POINTS + 1) * 4));

	textMainLevelMenu[4].setFont(fontMainLevelMenu);
	textMainLevelMenu[4].setFillColor(sf::Color::White);
	textMainLevelMenu[4].setString("Level 5");
	textMainLevelMenu[4].setPosition(sf::Vector2f((float)resolution.width / 2.5,
		(float)resolution.height / (MAX_LEVEL_MENU_POINTS + 1) * 5));
}


MainLevelMenu::~MainLevelMenu()
{
}

void MainLevelMenu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_LEVEL_MENU_POINTS; i++)
	{
		window.draw(textMainLevelMenu[i]);
	}
}

void MainLevelMenu::keyEvent(sf::Keyboard::Key key, Window & window)
{
	// move up
	if (key == sf::Keyboard::Up && selectedLevelIndex - 1 >= 0)
	{
		textMainLevelMenu[selectedLevelIndex].setFillColor(sf::Color::White);
		selectedLevelIndex--;
		textMainLevelMenu[selectedLevelIndex].setFillColor(sf::Color::Yellow);
	}
	// move down
	else if (key == sf::Keyboard::Down && selectedLevelIndex + 1 < MAX_LEVEL_MENU_POINTS)
	{
		textMainLevelMenu[selectedLevelIndex].setFillColor(sf::Color::White);
		selectedLevelIndex++;
		textMainLevelMenu[selectedLevelIndex].setFillColor(sf::Color::Yellow);
	}

	//enter
	if (key == sf::Keyboard::Return)
	{
		switch (selectedLevelIndex)
		{
		case 0:
			window.showGame();
			//window.showLevel1();
			break;
		case 1:
			window.showLevel2();
			break;
		case 2:
			window.showLevel3();
			break;
		case 3:
			window.showLevel4();
			break;
		case 4:
			window.showLevel5();
			break;
		}
	}
}

int MainLevelMenu::getSelectedLevelIndex()
{
	return selectedLevelIndex;
}
