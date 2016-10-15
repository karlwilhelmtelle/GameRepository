#include "MainMenu.h"



MainMenu::MainMenu(sf::VideoMode resolution)
{
	if (!fontMainMenu.loadFromFile("OpenSans-Bold.ttf"))
	{
		//Fehler beheben
	}

	textMainMenu[0].setFont(fontMainMenu);
	textMainMenu[0].setFillColor(sf::Color::Yellow);
	textMainMenu[0].setString("Ready To Play");
	textMainMenu[0].setPosition(sf::Vector2f(resolution.width / 2, 
		1 * (resolution.height / 4)));

	textMainMenu[1].setFont(fontMainMenu);
	textMainMenu[1].setFillColor(sf::Color::White);
	textMainMenu[1].setString("Options");
	textMainMenu[1].setPosition(sf::Vector2f(resolution.width / 2, 
		2 * (resolution.height / 4)));

	textMainMenu[2].setFont(fontMainMenu);
	textMainMenu[2].setFillColor(sf::Color::White);
	textMainMenu[2].setString("Exit Game?");
	textMainMenu[2].setPosition(sf::Vector2f(resolution.width / 2, 
		3 * (resolution.height / 4)));
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

void MainMenu::MoveUp()
{
	if (selectedIndex - 1 >= 0)
	{
		textMainMenu[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex--;
		textMainMenu[selectedIndex].setFillColor(sf::Color::Yellow);
	}
}

void MainMenu::MoveDown()
{
	if (selectedIndex + 1 < MAX_QUANTITY)
	{
		textMainMenu[selectedIndex].setFillColor(sf::Color::White);
		selectedIndex ++;
		textMainMenu[selectedIndex].setFillColor(sf::Color::Yellow);
	}
}