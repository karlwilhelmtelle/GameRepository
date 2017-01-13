#include "HighscoreMenu.h"
#include "Window.h"
#include <SFML/Audio.hpp>

HighscoreMenu::HighscoreMenu(sf::VideoMode resolution):
	selected_index(0)
{
	const sf::String strings[] = { "Last Score: ", "Highscore: "};

	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		text[i].setFillColor(sf::Color::White);
		text[i].setString(strings[i]);
		text[i].setPosition(sf::Vector2f((float)resolution.width / 3.5f,
			(float)resolution.height / (MAX_QUANTITY_HIGHSCORE + 1) * (i + 1)));
	}
}

void HighscoreMenu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		window.draw(text[i]);
	}

}

void HighscoreMenu::keyEvent(sf::Keyboard::Key key, Window & window)
{

}

int HighscoreMenu::getSelectedIndex()
{
	return 0;
}

