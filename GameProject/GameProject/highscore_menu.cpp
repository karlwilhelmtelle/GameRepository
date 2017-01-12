#include "highscore_menu.h"
#include "Window.h"
#include <SFML/Audio.hpp>

highscore_menu::~highscore_menu()
{
}

highscore_menu::highscore_menu(sf::VideoMode resolution):
	selectedIndexHighscore(0)
{
	const sf::String text[] = { "Last Score: ", "Highscore: "};

	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		textHighscore_menu[i].setFillColor(sf::Color::White);
		textHighscore_menu[i].setString(text[i]);
		textHighscore_menu[i].setPosition(sf::Vector2f((float)resolution.width / 3.5f,
			(float)resolution.height / (MAX_QUANTITY_HIGHSCORE + 1) * (i + 1)));
	}

}

void highscore_menu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		window.draw(textHighscore_menu[i]);
	}

}

void highscore_menu::keyEvent(sf::Keyboard::Key key, Window & window)
{

}

int highscore_menu::getSelectedIndex()
{
	return 0;
}

