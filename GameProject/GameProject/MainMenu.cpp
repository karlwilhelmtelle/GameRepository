#include "MainMenu.h"
#include "Window.h"

MainMenu::MainMenu(sf::VideoMode resolution) :
	selectedIndex(0)
{
	if (!fontMainMenu.loadFromFile("OpenSans-Bold.ttf"))
	{
		//Fehler beheben
	}

	textMainMenu[0].setFont(fontMainMenu);
	textMainMenu[0].setFillColor(sf::Color::Yellow);
	textMainMenu[0].setString("Ready To Play");
	textMainMenu[0].setPosition(sf::Vector2f((float)resolution.width / 2.5, 
		(float)resolution.height / (MAX_QUANTITY + 1) * 1));

	textMainMenu[1].setFont(fontMainMenu);
	textMainMenu[1].setFillColor(sf::Color::White);
	textMainMenu[1].setString("Options");
	textMainMenu[1].setPosition(sf::Vector2f((float)resolution.width / 2.5,
		(float)resolution.height / (MAX_QUANTITY + 1) * 2));

	textMainMenu[2].setFont(fontMainMenu);
	textMainMenu[2].setFillColor(sf::Color::White);
	textMainMenu[2].setString("Exit Game?");
	textMainMenu[2].setPosition(sf::Vector2f((float)resolution.width /2.5,
		(float)resolution.height / (MAX_QUANTITY + 1) * 3));
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
				window.showGame();
			case 1:
				window.showOptions();
			case 2:
				window.close();
		}
	}
}

int MainMenu::getSelectedIndex()
{
	return selectedIndex;
}