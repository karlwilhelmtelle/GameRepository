#include "HighscoreMenu.h"
#include "Level.h"
#include "View.h"
#include <SFML/Audio.hpp>

HighscoreMenu::HighscoreMenu(const sf::VideoMode &resolution):
	selectedIndex(MAX_QUANTITY_HIGHSCORE - 1)
{
	const sf::String strings[] = { "Last Score: ", "Highscore: ", "Back"};

	last_score_value.setStringToTime(0);
	last_score_value.setPosition(sf::Vector2f((float)resolution.width / 2,
		(float)resolution.height / 4));

	highscore_value.setStringToMilliseconds(0);
	highscore_value.setPosition(sf::Vector2f((float)resolution.width / 2,
		(float)resolution.height * 2 / 4));

	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		text[i].setString(strings[i]);
		text[i].setPosition(sf::Vector2f((float)resolution.width / 3.5f,
			(float)resolution.height / (MAX_QUANTITY_HIGHSCORE + 1) * (i + 1)));
	}
	text[selectedIndex].select();
}

void HighscoreMenu::draw(View & window)
{
	for (int i = 0; i < MAX_QUANTITY_HIGHSCORE; i++)
	{
		window.draw(text[i]);
	}
	window.draw(last_score_value);
	window.draw(highscore_value);
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

void HighscoreMenu::updateTimeValues(sf::Int32 highscore, sf::Int32 last_score)
{
	highscore_milliseconds = highscore;
	last_score_milliseconds = last_score;
	last_score_value.setStringToTime(last_score_milliseconds);
	highscore_value.setStringToMilliseconds(highscore_milliseconds);
}

