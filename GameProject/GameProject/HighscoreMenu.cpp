#include "HighscoreMenu.h"
#include "Level.h"
#include "View.h"
#include <SFML/Audio.hpp>

HighscoreMenu::HighscoreMenu(const sf::VideoMode &resolution):
	selected_index(MAX_QUANTITY_HIGHSCORE - 1)
{
	const sf::String strings[] = { "Last Score: ", "Highscore: ", "Back"};

	highscore_menu_text.setFillColor(sf::Color::White);
	highscore_menu_text.setStringToTime(0);
	highscore_menu_text.setPosition(sf::Vector2f((float)resolution.width / 2,
		(float)resolution.height / 4));

	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		text[i].setFillColor(sf::Color::White);
		text[i].setString(strings[i]);
		text[i].setPosition(sf::Vector2f((float)resolution.width / 3.5f,
			(float)resolution.height / (MAX_QUANTITY_HIGHSCORE + 1) * (i + 1)));
	}
	text[selected_index].setFillColor(sf::Color::Yellow);
}

void HighscoreMenu::draw(View & window)
{
	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		window.draw(text[i]);
	}
	window.draw(highscore_menu_text);
}

void HighscoreMenu::keyEvent(sf::Keyboard::Key key, View & window)
{
	if (key == sf::Keyboard::Return)
	{
		window.setGameState(GameState::MAIN_MENU);
	}
}

int HighscoreMenu::getSelectedIndex()
{
	return 0;
}

void HighscoreMenu::updateElapsedTime()
{
	time_milliseconds = clock.getElapsedTime().asMilliseconds();

	time_menu_text.setStringToTime(time_milliseconds);
}

void HighscoreMenu::updateHighscore()
{
	if (time_milliseconds > highscore_milliseconds)
	{
		highscore_milliseconds = time_milliseconds;
		highscore_menu_text.setStringToMilliseconds(highscore_milliseconds);
	}
}
