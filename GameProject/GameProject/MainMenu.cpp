#include "MainMenu.h"
#include "Window.h"

MainMenu::MainMenu(sf::VideoMode resolution) :
	selectedIndex(0)
{
	if (!fontMainMenu.loadFromFile("OpenSans-Bold.ttf"))
	{
		//Fehler beheben
	}

	const sf::String text[] = {"Play", "Options", "Exit"};
	for (int i = 0; i < MAX_QUANTITY; i++)
	{
		textMainMenu[i].setFont(fontMainMenu);
		textMainMenu[i].setFillColor(sf::Color::White);
		textMainMenu[i].setString(text[i]);
		textMainMenu[i].setPosition(sf::Vector2f((float)resolution.width / 2.5f,
			(float)resolution.height / (MAX_QUANTITY + 1) * (i+1)));
	}
	textMainMenu[0].setFillColor(sf::Color::Yellow);
}


MainMenu::~MainMenu()
{

}


void MainMenu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_QUANTITY; i++)
	{
		window.draw(textMainMenu[i]);
	}
}


void MainMenu::keyEvent(sf::Keyboard::Key key, Window &window)
{
	// move up
	if (key == sf::Keyboard::Up && selectedIndex - 1 >= 0)
	{
		textMainMenu[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex--;
		textMainMenu[selectedIndex].setFillColor(sf::Color::Yellow);
	}
	// move down
	else if (key == sf::Keyboard::Down && selectedIndex + 1 < MAX_QUANTITY)
	{
		textMainMenu[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex++;
		textMainMenu[selectedIndex].setFillColor(sf::Color::Yellow);
	}

	//enter
	if (key == sf::Keyboard::Return)
	{
		switch (selectedIndex)
		{
			case 0:
				window.showLevelMenu();
				break;
			case 1:
				window.showOptions();
				break;
			case 2:
				window.close();
				break;
		}
	}
}

int MainMenu::getSelectedIndex()
{
	return selectedIndex;
}